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

// IPViewerSettings.cpp : implementation file
//

#include "stdafx.h"
#include "IPViewer.h"
#include "IPViewerSettings.h"
#include "IPSettings.h"

// CIPViewerSettings dialog

IMPLEMENT_DYNAMIC(CIPViewerSettings, CDialog)

CIPViewerSettings::CIPViewerSettings(CWnd* pParent /*=NULL*/)
	: CDialog(CIPViewerSettings::IDD, pParent)
	, m_bMinToTray(FALSE)
	, m_bCloseTray(FALSE)
	, m_nTick(0)
	, m_nSelectedIndex(0)
	, m_bOnTop(FALSE)
	, m_bStartMinimized(FALSE)
	, m_bCheckExternalIp(FALSE)
	, m_bEnableLogging(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_IPVIEWER);
}

CIPViewerSettings::CIPViewerSettings( CWnd* pParent /*=NULL*/, CIPSettings* settings)
	: CDialog( CIPViewerSettings::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_IPVIEWER);
	m_pSettings = settings;

}

CIPViewerSettings::~CIPViewerSettings()
{
}

void CIPViewerSettings::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_MINTRAY, m_bMinToTray);
	DDX_Check(pDX, IDC_CHECK_CLOSETRAY, m_bCloseTray);
	DDX_Check(pDX, IDC_CHECK1, m_bOnTop);
	DDX_Text(pDX, IDC_EDIT_RATE, m_nTick);
	DDX_Radio(pDX, IDC_RADIO_IP, m_nSelectedIndex);	
	DDX_Check(pDX, IDC_CHECK2, m_bStartMinimized);
	DDX_Check(pDX, IDC_CHECK_EXTERNAL, m_bCheckExternalIp);
	DDX_Control(pDX, IDC_CHECK4, m_CheckInternalIp);
	DDX_Control(pDX, IDC_CHECK5, m_CheckExternalIp);
	DDX_Control(pDX, IDC_CHECK6, m_CheckHostName);
	DDX_Control(pDX, IDC_CHECK7, m_CheckMacAddress);
	DDX_Control(pDX, IDC_EDIT_LOGINTERVAL, m_LogInterval);
	DDX_Control(pDX, IDC_EDIT_FILENAME, m_LogFileName);
	DDX_Control(pDX, IDC_COMBO_FILETYPE, m_LogFileExtension);
}


BOOL CIPViewerSettings::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: init dialog here
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// load our dialog data
	m_bMinToTray = m_pSettings->GetMinimizeToTray();
	m_bCloseTray = m_pSettings->GetCloseToTray();
	m_nTick = m_pSettings->GetTick();
	m_nSelectedIndex = m_pSettings->GetShowItemIndex();
	m_bOnTop = m_pSettings->GetOnTop();
	m_bStartMinimized = m_pSettings->GetStartMinimized();
	m_bCheckExternalIp = m_pSettings->GetCheckExternalIp();
	m_bEnableLogging = m_pSettings->GetLoggingEnabled();

	if( m_bEnableLogging )
	{
		m_CheckInternalIp.EnableWindow( TRUE );
		m_CheckExternalIp.EnableWindow( TRUE );
		m_CheckHostName.EnableWindow( TRUE );
		m_CheckMacAddress.EnableWindow( TRUE );
		m_LogInterval.EnableWindow( TRUE );
		m_LogFileName.EnableWindow( TRUE );
		m_LogFileExtension.EnableWindow( TRUE );
	}
	else
	{
		m_CheckInternalIp.EnableWindow( FALSE );
		m_CheckExternalIp.EnableWindow( FALSE );
		m_CheckHostName.EnableWindow( FALSE );
		m_CheckMacAddress.EnableWindow( FALSE );
		m_LogInterval.EnableWindow( FALSE );
		m_LogFileName.EnableWindow( FALSE );
		m_LogFileExtension.EnableWindow( FALSE );
	}

	// get if we're going to check the individual parts
	m_CheckInternalIp.SetCheck( m_pSettings->GetLogInternalIp() );
	m_CheckExternalIp.SetCheck( m_pSettings->GetLogExternalIp() );
	m_CheckHostName.SetCheck( m_pSettings->GetLogHostName() );
	m_CheckMacAddress.SetCheck( m_pSettings->GetLogMacAddress() );

	CString text;
	text.Format( TEXT("%d"),m_pSettings->GetLoggingInterval() );
	m_LogInterval.SetWindowTextW( text );
	m_LogFileName.SetWindowTextW( m_pSettings->GetLogFileName() );
	m_LogFileExtension.SetWindowTextW( m_pSettings->GetLogFileExtension() );
	
	CButton* b = (CButton*)GetDlgItem(IDC_CHECK_ENABLE_LOGGING);
	b->SetCheck( m_bEnableLogging );

	// refresh the Dialog
	UpdateData( FALSE );

	return TRUE;

}

BEGIN_MESSAGE_MAP(CIPViewerSettings, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CIPViewerSettings::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &CIPViewerSettings::OnBnClickedButtonCancel)
	ON_BN_CLICKED(IDC_CHECK_ENABLE_LOGGING, &CIPViewerSettings::OnBnClickedCheckEnableLogging)
END_MESSAGE_MAP()


// CIPViewerSettings message handlers

void CIPViewerSettings::OnBnClickedButtonSave()
{
	// turn on wait cursor
	CDialog::BeginWaitCursor();
	
	// get data back from the dialog
	UpdateData( TRUE );

	// set our values
	m_pSettings->SetMinimizeToTray( m_bMinToTray );
	m_pSettings->SetCloseToTray( m_bCloseTray );
	m_pSettings->SetTick( m_nTick );
	m_pSettings->SetShowItemIndex( m_nSelectedIndex );
	m_pSettings->SetOnTOp( m_bOnTop );
	m_pSettings->SetStartInTray( m_bStartMinimized );
	m_pSettings->SetCheckExternalIp( m_bCheckExternalIp );
	m_pSettings->SetLoggingEnabled( m_bEnableLogging );
	m_pSettings->SetLogInternalIp( m_CheckInternalIp.GetCheck() );
	m_pSettings->SetLogExternalIp( m_CheckExternalIp.GetCheck() );
	m_pSettings->SetLogHostName( m_CheckHostName.GetCheck() );
	m_pSettings->SetLogMacAddress( m_CheckMacAddress.GetCheck() );

	CString temp;

	m_LogInterval.GetWindowTextW( temp );
	m_pSettings->SetLoggingInterval( _wtoi( temp ) );
	
	m_LogFileName.GetWindowTextW( temp );
	m_pSettings->SetLogFileName( temp );

	m_LogFileExtension.GetWindowTextW( temp );
	m_pSettings->SetLogFileExtension( temp );

	// save our changes to the registry
	CString result = m_pSettings->Save() ? 
		TEXT("Settings were saved successfully.") : 
		TEXT("An error occured saving settings.");

	AfxMessageBox( result, MB_OKCANCEL );
		
	// turn on normal cursor
	CDialog::EndWaitCursor();
	
	// then kill the dialog
	this->EndDialog(0);
}

void CIPViewerSettings::OnBnClickedButtonCancel()
{
	CDialog::EndDialog(0);

	// kill this dialog
	this->EndDialog(0);
}

void CIPViewerSettings::OnBnClickedCheckEnableLogging()
{
	// TODO: Add your control notification handler code here
	CButton* a = (CButton*)GetDlgItem( IDC_CHECK_ENABLE_LOGGING );
	BOOL checked = a->GetCheck();
	
	m_bEnableLogging = checked;

	if( checked )
	{
		m_CheckInternalIp.EnableWindow( TRUE );
		m_CheckExternalIp.EnableWindow( TRUE );
		m_CheckHostName.EnableWindow( TRUE );
		m_CheckMacAddress.EnableWindow( TRUE );
		m_LogInterval.EnableWindow( TRUE );
		m_LogFileName.EnableWindow( TRUE );
		m_LogFileExtension.EnableWindow( TRUE );
	}
	else
	{
		m_CheckInternalIp.EnableWindow( FALSE );
		m_CheckExternalIp.EnableWindow( FALSE );
		m_CheckHostName.EnableWindow( FALSE );
		m_CheckMacAddress.EnableWindow( FALSE );
		m_LogInterval.EnableWindow( FALSE );
		m_LogFileName.EnableWindow( FALSE );
		m_LogFileExtension.EnableWindow( FALSE );
	}
}
