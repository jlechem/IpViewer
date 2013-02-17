/*
	Copyright 2012 Justin LeCheminant

	This file is part of IP Viewer.

    IP Viewer is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    IP Viewer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with IP Viewer.  If not, see <http://www.gnu.org/licenses/>.
*/


// IPViewerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "IPViewerDlg.h"
#include "..\Logger\Logger.h"

#define MAX_TOOLTIP_SIZE 64

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()

// CIPViewerDlg dialog


CIPViewerDlg::CIPViewerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIPViewerDlg::IDD, pParent)
	, m_strHost(TEXT(""))
	, m_strExternalIP(TEXT(""))
	, m_bVisible(FALSE)
	, m_strMAC(TEXT("00:00:00:00:00:00"))
	, m_bIpV4Enabled(false)
	, m_bIpV6Enabled(false)
	, m_strStatus(TEXT(""))
	, m_strDescription(TEXT(""))
{
}

CIPViewerDlg::~CIPViewerDlg()
{
	delete m_pSettings;
	delete m_pIpData;
	delete m_pAdapterInformation;
	delete  m_pToolTip;
}

void CIPViewerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TEXT_HOST, m_strHost);
	DDX_Text(pDX, IDC_TEXT_EXTERNAL, m_strExternalIP);
	DDX_Text(pDX, IDC_TEXT_MAC, m_strMAC );
	DDX_Text(pDX, IDC_STATIC_STATUS, m_strStatus );
	DDX_Text(pDX, IDC_STATIC_DESCRIPTION, m_strDescription );
	DDX_Check(pDX, IDC_CHECK_V4, m_bIpV4Enabled);
	DDX_Check(pDX, IDC_CHECK_V6, m_bIpV6Enabled);
	DDX_Control(pDX, IDC_COMBO_ADAPTERS, m_cboAdapters);
	DDX_Control(pDX, IDC_COMBO_ADDRESSES, m_cboAddresses);
}

BEGIN_MESSAGE_MAP(CIPViewerDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_WM_CLOSE()
	ON_WM_WINDOWPOSCHANGING()
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_HELP_ABOUT, &CIPViewerDlg::OnHelpAbout)
	ON_COMMAND(ID_FILE_REFRESH, &CIPViewerDlg::OnFileRefresh)
	ON_COMMAND(ID_FILE_EXIT, &CIPViewerDlg::OnFileExit)
	ON_COMMAND(ID_EDIT_SETTINGS, &CIPViewerDlg::OnEditSettings)
	ON_COMMAND(ID_EDIT_COPYIPADDRESS, &CIPViewerDlg::OnEditCopyipaddress)
	ON_COMMAND(ID_EDIT_COPYMACADDRESS, &CIPViewerDlg::OnEditCopymac)
	ON_COMMAND(ID_EDIT_COPYHOSTNAME, &CIPViewerDlg::OnEditCopyhostname)
	ON_COMMAND(ID_POPUP_COPYIPADDRESS, &CIPViewerDlg::OnPopupCopyipaddress)
	ON_COMMAND(ID_POPUP_COPYHOSTNAME, &CIPViewerDlg::OnPopupCopyhostname)
	ON_COMMAND(ID_POPUP_COPYMACADDRESS, &CIPViewerDlg::OnPopupCopymac)
	ON_COMMAND(ID_POPUP_EDITSETTINGS, &CIPViewerDlg::OnPopupEditsettings)
	ON_COMMAND(ID_POPUP_REFRESHIPINFORMATION, &CIPViewerDlg::OnPopupRefreshipinformation)
	ON_COMMAND(ID_POPUP_EXIT, &CIPViewerDlg::OnPopupExit)
	ON_MESSAGE( MY_WM_NOTIFYICON, &CIPViewerDlg::OnTrayNotification)
	ON_COMMAND(ID_POPUP_COPYEXTERNALIPADDRESS, &CIPViewerDlg::OnPopupCopyexternalipaddress)
	ON_COMMAND(ID_EDIT_COPYEXTERNALIPADDRESS, &CIPViewerDlg::OnEditCopyexternalipaddress)
	ON_COMMAND(ID_EDIT_COPYEXTERNALIPADDRESS, &CIPViewerDlg::OnEditCopyexternalipaddress)
	ON_CBN_SELCHANGE(IDC_COMBO_ADAPTERS, &CIPViewerDlg::OnCbnSelchangeComboAdapters)
	ON_CBN_SELCHANGE(IDC_COMBO_ADDRESSES, &CIPViewerDlg::OnCbnSelchangeComboAddresses)
END_MESSAGE_MAP()


// CIPViewerDlg message handlers

BOOL CIPViewerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_IPVIEWER);
	m_pSettings = new CIPSettings();
	m_pIpData = new CIPData();
	m_bVisible = !m_pSettings->GetStartMinimized();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main winBdow is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	this->RefreshIpInfo();

	// start the timer with the number of MS from the settings class
	SetTimer( IDT_TIMER, this->m_pSettings->GetTick() * 60000, NULL );
	SetTimer( IDT_TIMER_LOGGER, this->m_pSettings->GetLoggingInterval() * 1000, NULL );

	this->SetTopMost();

	// check if we should start minimized
	if( m_pSettings->GetStartMinimized() )
	{
		this->TrayMessage( NIM_ADD );
	}

	m_pToolTip = new CToolTipCtrl;

	this->LoadTooltips();

	return TRUE;  // return TRUE  unless you set the focus to a control

}

void CIPViewerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CIPViewerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CIPViewerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CIPViewerDlg::OnHelpAbout()
{
	// show the about dlg box
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CIPViewerDlg::OnFileRefresh()
{
	// manually refresh the ip data
	this->RefreshIpInfo();
}

void CIPViewerDlg::OnFileExit()
{
	// call the end dialog message
	this->EndDialog(0);	
}

void CIPViewerDlg::OnEditSettings()
{
	this->EditSettings();
}

void CIPViewerDlg::OnTimer( UINT_PTR TimerVal )
{
	switch( TimerVal )
	{
		case IDT_TIMER:

			this->RefreshIpInfo();

			// if we're not visibile we need to reset the tray message
			if( !this->IsWindowVisible() )
			{
				this->TrayMessage( NIM_MODIFY );
			}

			break;

		case IDT_TIMER_LOGGER:
			
			// write out the data to the log files
			this->LogData();
			
			break;

	}

	
}

void CIPViewerDlg::RefreshIpInfo()
{
	CWaitCursor wait;

	// get the adapter data
	m_ipAdapterInfo = m_pIpData->GetAdapterInformation();

	this->LoadAdapters();

	this->LoadAddresses();

	this->m_strHost = m_pIpData->GetHostName();
	this->m_strExternalIP = m_pSettings->GetCheckExternalIp() ?
		m_pIpData->GetExternalIpAddress():
		TEXT("Not set to check for external ip");

	// refresh the dialog controls
	UpdateData( FALSE );
	
}

#pragma region Menu Event Handles

void CIPViewerDlg::OnEditCopyipaddress()
{
	CString temp;
	this->m_cboAddresses.GetWindowTextW(temp);
	CClipboard::SetData( temp, m_hWnd );
}

void CIPViewerDlg::OnEditCopymac()
{
	CClipboard::SetData( m_strMAC, m_hWnd );
}

void CIPViewerDlg::OnEditCopyhostname()
{
	CClipboard::SetData( m_strHost, m_hWnd );
}

void CIPViewerDlg::OnEditCopyexternalipaddress()
{
	CClipboard::SetData( m_strExternalIP, m_hWnd );
}

#pragma endregion

BOOL CIPViewerDlg::TrayMessage( DWORD dwMessage )
{
	CString sTip;

	// based on the index we show different things
	// 0 is ip address
	// 1 is the external ip address
	// 2 is host name
	// 3 is the MAC address
	switch( m_pSettings->GetShowItemIndex() )
	{
		default:
		case 0:
			this->m_cboAddresses.GetWindowTextW(sTip);
			break;
		
		case 1:
			sTip = m_strExternalIP;
			break;

		case 2:
			sTip = m_strHost;
			break;
		
		case 3:
			// TODO: insert the mac address control here
			sTip = m_strMAC;
			break;
	}
	
	// check to make sure we only have 64 characters in length
	// since that's all we can fit in a tooltip
	if( sTip.GetLength() > MAX_TOOLTIP_SIZE )
	{
		sTip.LoadString( IDS_TOOLTIP_SIZE_ERROR );
	}

	NOTIFYICONDATA tnd;
  
	tnd.cbSize = sizeof(NOTIFYICONDATA);
	tnd.hWnd = m_hWnd;
	tnd.uID = IDI_ICON_IPVIEWER;
	tnd.uFlags = NIF_MESSAGE|NIF_ICON;
	tnd.uCallbackMessage = MY_WM_NOTIFYICON;
	tnd.uFlags = NIF_MESSAGE|NIF_ICON|NIF_TIP;
	
	VERIFY( tnd.hIcon = LoadIcon(AfxGetInstanceHandle(),
                               MAKEINTRESOURCE (IDI_ICON_IPVIEWER)) );

	lstrcpyn(tnd.szTip, (LPCTSTR)sTip, sizeof(tnd.szTip));

	return Shell_NotifyIcon(dwMessage, &tnd);

}

// override the OnSize method
void CIPViewerDlg::OnSize( UINT nType, int cx, int cy )
{
	CDialog::OnSize(nType, cx, cy);

	// if we're minimizing the app and we have the settings
	// doing minimize to tray remove the main window
	if( nType == SIZE_MINIMIZED && 
		m_pSettings->GetMinimizeToTray() )
	{
		this->TrayMessage(NIM_ADD);
		ShowWindow( SW_HIDE );
	}
}

// handle the on close event
void CIPViewerDlg::OnClose()
{
	if( m_pSettings->GetCloseToTray() )
	{
		this->TrayMessage(NIM_ADD);
		ShowWindow( SW_HIDE );
	}
	else
	{
		m_pSettings->Save();
		this->TrayMessage(NIM_DELETE);
		CDialog::OnClose();
	}
}

// handles events for the tray icon we put in place
LRESULT CIPViewerDlg::OnTrayNotification( WPARAM wParam, LPARAM lParam )
{
	switch( lParam )
	{
		// they've double clicked our icon with the left mouse button
		case WM_LBUTTONDBLCLK:

			switch( wParam )
			{
				case IDI_ICON_IPVIEWER:
					m_bVisible = TRUE;
					ShowWindow( SW_NORMAL );
					SetForegroundWindow();
					SetFocus();
					
					this->TrayMessage( NIM_DELETE );
					
					return TRUE;
			}

			break;

		// they've click the right mouse button over our icon
		case WM_RBUTTONDOWN:

			switch( wParam )
			{
				case IDI_ICON_IPVIEWER:
					
					POINT curPoint;
					GetCursorPos( &curPoint );

					CMenu menu;
					menu.LoadMenuW( IDR_CONTEXT_MENU );
					CMenu* subMenu = menu.GetSubMenu(0);\
					ASSERT( subMenu );

					UINT clicked = subMenu->TrackPopupMenu( TPM_RIGHTBUTTON, curPoint.x, curPoint.y, this, NULL );
					
					return TRUE;

			}
		
			break;
	}

	return TRUE;

}

#pragma region Context_Menu_Methods

void CIPViewerDlg::OnPopupCopyexternalipaddress()
{
	CClipboard::SetData( m_strExternalIP, m_hWnd );
}

void CIPViewerDlg::OnPopupCopyipaddress()
{
	CString temp;
	this->m_cboAddresses.GetWindowTextW( temp );
	CClipboard::SetData( temp, m_hWnd );
}

void CIPViewerDlg::OnPopupCopyhostname()
{
	CClipboard::SetData( m_strHost, m_hWnd );
}

void CIPViewerDlg::OnPopupCopymac()
{
	// TODO: insert the code for the MAC address here
	CClipboard::SetData( m_strMAC, m_hWnd );
}

void CIPViewerDlg::OnPopupEditsettings()
{
	this->EditSettings();

	this->TrayMessage( NIM_MODIFY );
}

void CIPViewerDlg::OnPopupRefreshipinformation()
{
	this->RefreshIpInfo();

	// since we're the context menu that means we're minimized
	this->TrayMessage( NIM_MODIFY );

}

#pragma endregion

void CIPViewerDlg::EditSettings()
{
	// show the settings dialog
	CIPViewerSettings frmSettings( NULL, m_pSettings );
	frmSettings.DoModal();

	this->SetTopMost();  

	// reset the timer based on the new tick settings
	KillTimer( IDT_TIMER );
	KillTimer( IDT_TIMER_LOGGER );

	this->RefreshIpInfo();

	// convert the minutes to milliseconds for the timer
	SetTimer( IDT_TIMER, m_pSettings->GetTick() * 60000, NULL );
	SetTimer( IDT_TIMER_LOGGER, this->m_pSettings->GetLoggingInterval() * 1000, NULL );

}

void CIPViewerDlg::OnPopupExit()
{
	this->EndDialog(0);
}

void CIPViewerDlg::SetTopMost()
{
	if( m_pSettings->GetOnTop() )
	{ 
		::SetWindowPos( m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE );
	}//end if
	else
	{
		::SetWindowPos( m_hWnd, HWND_NOTOPMOST, 0, 0, 0, 0,SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE );
	}
}

void CIPViewerDlg::OnWindowPosChanging( WINDOWPOS FAR* lpWindowPosition )
{
	if( !m_bVisible ) 
	{
		lpWindowPosition->flags &= ~SWP_SHOWWINDOW;
	}

	CDialog::OnWindowPosChanging( lpWindowPosition );

}

// Logs the data
void CIPViewerDlg::LogData()
{
	if( m_pSettings->GetLoggingEnabled() )
	{
		// we write to the text file
		CString line;

		/*if( m_pSettings->GetLogInternalIp() )
		{
			line.Format( TEXT("Internal IP Address: %s"), m_pIpData->GetIpAddress() );
		}*/
				
		if( m_pSettings->GetLogExternalIp() )
		{
			line += TEXT(", External IP Address: ");
			line += m_pIpData->GetExternalIpAddress();
		}

		/*if( m_pSettings->GetLogMacAddress() )
		{
			line += TEXT(", MAC Address: ");
			line += m_pIpData->GetMacAddress();
		}*/

		if( m_pSettings->GetLogHostName() )
		{
			line += TEXT(", Host Name: ");
			line += m_pIpData->GetHostName();
		}

		CLogger::Log( line, m_pSettings->GetLogFileName() );

	}
}

void CIPViewerDlg::OnCbnSelchangeComboAdapters()
{
	// get the selected index
	m_pSettings->SetAdapterIndex( this->m_cboAdapters.GetCurSel() );

	this->GetSelectedAdapter();

	this->LoadAdapterControlValues();
	this->LoadAddresses();
	
	UpdateData( FALSE );
}

void CIPViewerDlg::OnCbnSelchangeComboAddresses()
{
	// get the selected index
	m_pSettings->SetAddressIndex( this->m_cboAddresses.GetCurSel() );
}

void CIPViewerDlg::LoadAdapters()
{
	this->m_cboAdapters.ResetContent();

	if( m_ipAdapterInfo.size() > 0 )
	{
		this->m_cboAdapters.ShowWindow( TRUE );
		this->m_cboAddresses.ShowWindow( TRUE );

		// loop through the vector to load the combo box
		std::vector<CIpInformation*>::iterator itr;
		for ( itr = m_ipAdapterInfo.begin(); itr != m_ipAdapterInfo.end(); ++itr )
		{
			this->m_cboAdapters.AddString( (*itr)->GetAdapterName() );
		}

		// if we have a previously selected index use it
		// if the index is invalid then load the default
		if( this->m_cboAdapters.GetCount() >= m_pSettings->GetAdapterIndex() )
		{
			this->m_cboAdapters.SetCurSel( m_pSettings->GetAdapterIndex() );

			this->GetSelectedAdapter();
		}	
		else
		{
			this->m_cboAdapters.SetCurSel( 0 );
			m_pAdapterInformation = this->m_ipAdapterInfo[0];
		}

		this->LoadAdapterControlValues();

	}
	else
	{
		this->m_cboAdapters.ShowWindow( FALSE );
		this->m_cboAddresses.ShowWindow( FALSE );
	}
}

void CIPViewerDlg::LoadAddresses()
{
	CWaitCursor wait;

	this->m_cboAddresses.ResetContent();

	vector<CString*> addresses = m_pAdapterInformation->GetIpAddresses();

	if( addresses.size() > 0 )
	{
		this->m_cboAddresses.ShowWindow( TRUE );

		std::vector<CString*>::iterator itr2;
			
		for ( itr2 = addresses.begin(); itr2 != addresses.end(); ++itr2 )
		{
			this->m_cboAddresses.AddString( (**itr2) );
		}

		if( this->m_cboAddresses.GetCount() >= m_pSettings->GetAddressIndex() )
		{
			this->m_cboAddresses.SetCurSel( m_pSettings->GetAddressIndex() );
		}
		else
		{
			this->m_cboAddresses.SetCurSel(0);
		}
	}
	else
	{
		this->m_cboAddresses.ShowWindow( FALSE );
	}
}

void CIPViewerDlg::LoadAdapterControlValues()
{
	this->m_strMAC = m_pAdapterInformation->GetMac();
	this->m_bIpV4Enabled = m_pAdapterInformation->GetIpV4Enabled();
	this->m_bIpV6Enabled = m_pAdapterInformation->GetIpV6Enabled();
	this->m_strStatus = m_pAdapterInformation->GetStatus();
	this->m_strDescription = m_pAdapterInformation->GetAdapterDescription();

}

void CIPViewerDlg::GetSelectedAdapter()
{
	CIpInformation* returnData = NULL;

	CString adapterName; 
	this->m_cboAdapters.GetWindowText(adapterName);

	std::vector<CIpInformation*>::iterator itr;
	
	for ( itr = m_ipAdapterInfo.begin(); itr != m_ipAdapterInfo.end(); ++itr )
	{
		if( (*itr)->GetAdapterName() == adapterName )
		{
			m_pAdapterInformation = (*itr);
		}
	}
}

void CIPViewerDlg::LoadTooltips()
{
	if( !m_pToolTip->Create(this) )
    {
        TRACE("Unable To create ToolTip\n");
        return;
    }

	if( m_pToolTip->AddTool( &this->m_cboAdapters, TEXT("A list of all the adapters on this system.") ) )
    {
        TRACE( TEXT("Unable to add the adapters combo box to the tooltip\n") );
    }

	if( m_pToolTip->AddTool( &this->m_cboAddresses, TEXT("A list of all the IP Addresses for the selected adapter.") ) )
    {
        TRACE( TEXT("Unable to add the addresses combo box to the tooltip\n") );
	}

    m_pToolTip->Activate(TRUE);

}

BOOL CIPViewerDlg::PreTranslateMessage(MSG* pMsg)
{
	 if( m_pToolTip )
	 {
        m_pToolTip->RelayEvent(pMsg);
	 }

    return CDialog::PreTranslateMessage(pMsg);

}

void CAboutDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	this->EndDialog(0);
}
