/*
	Copyright 2011 Justin LeCheminant

	This file is part of IP Viewer.

    filesort is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    filesort is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with filesort.  If not, see <http://www.gnu.org/licenses/>.
*/


// IPViewerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "IPViewerDlg.h"

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
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// CIPViewerDlg dialog


CIPViewerDlg::CIPViewerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIPViewerDlg::IDD, pParent)
	, m_strMac(_T(""))
	, m_strHost(_T(""))
	, m_strIP(_T(""))
	, m_strExternalIP(_T(""))
	, m_bVisible(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_IPVIEWER);
	m_pSettings = new CIPSettings();
	m_pIpData = new CIPData();
	m_bVisible = !m_pSettings->GetStartMinimized();

}

void CIPViewerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TEXT_IP, m_strIP);
	DDX_Text(pDX, IDC_TEXT_HOST, m_strHost);
	DDX_Text(pDX, IDC_TEXT_MAC, m_strMac);
	DDX_Text(pDX, IDC_TEXT_EXTERNAL, m_strExternalIP);
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
END_MESSAGE_MAP()


// CIPViewerDlg message handlers

BOOL CIPViewerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

	this->SetTopMost();

	// check if we should start minimized
	if( m_pSettings->GetStartMinimized() )
	{
		this->TrayMessage( NIM_ADD );
	}
	
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
	this->RefreshIpInfo();

	// if we're not visibile we need to reset the tray message
	if( !this->IsWindowVisible() )
	{
		this->TrayMessage( NIM_MODIFY );
	}
}

void CIPViewerDlg::RefreshIpInfo()
{
	// get our ip data
	this->m_strIP = m_pIpData->GetIpAddress();
	this->m_strHost = m_pIpData->GetHostName();
	this->m_strMac = m_pIpData->GetMacAddress();
	this->m_strExternalIP = m_pSettings->GetCheckExternalIp() ?
		m_pIpData->GetExternalIpAddress():
		_T("Not set to check for external ip");

	// refresh the dialog controls
	UpdateData( FALSE );
	
}

#pragma region Menu Event Handles

void CIPViewerDlg::OnEditCopyipaddress()
{
	CClipboard::SetData( m_strIP, m_hWnd );
}

void CIPViewerDlg::OnEditCopymac()
{
	CClipboard::SetData( m_strMac, m_hWnd );
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
			sTip = m_strIP;				//  m_pIpData->GetIpAddress();
			break;
		
		case 1:
			sTip = m_strExternalIP;		//m_pIpData->GetExternalIpAddress();
			break;

		case 2:
			sTip = m_strHost;		//m_pIpData->GetHostName();
			break;
		
		case 3:
			sTip = m_strMac;		//m_pIpData->GetMacAddress();
			break;
	}
	
	// check to make sure we only have 64 characters in length
	// since that's all we can fit in a tooltip
	if( sTip.GetLength() > MAX_TOOLTIP_SIZE )
	{
		sTip.LoadStringW( IDS_TOOLTIP_SIZE_ERROR );
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
}

#pragma region Context_Menu_Methods

void CIPViewerDlg::OnPopupCopyexternalipaddress()
{
	CClipboard::SetData( m_strExternalIP, m_hWnd );
}

void CIPViewerDlg::OnPopupCopyipaddress()
{
	CClipboard::SetData( m_strIP, m_hWnd );
}

void CIPViewerDlg::OnPopupCopyhostname()
{
	CClipboard::SetData( m_strHost, m_hWnd );
}

void CIPViewerDlg::OnPopupCopymac()
{
	CClipboard::SetData( m_strMac, m_hWnd );
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
	// convert the minutes to milliseconds for the timer
	SetTimer( IDT_TIMER, m_pSettings->GetTick() * 60000, NULL );

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