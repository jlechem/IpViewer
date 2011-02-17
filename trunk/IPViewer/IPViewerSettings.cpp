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

	// refresh the Dialog
	UpdateData( FALSE );

	return TRUE;

}

BEGIN_MESSAGE_MAP(CIPViewerSettings, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CIPViewerSettings::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &CIPViewerSettings::OnBnClickedButtonCancel)
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

	// save our changes to the registry
	CString result = m_pSettings->Save() ? 
		_T("Settings were saved successfully.") : 
		_T("An error occured saving settings.");

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