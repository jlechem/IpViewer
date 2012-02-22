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

#pragma once

#include "IPSettings.h"
#include "afxwin.h"

// CIPViewerSettings dialog
class CIPViewerSettings : public CDialog
{
	DECLARE_DYNAMIC(CIPViewerSettings)

public:
	CIPViewerSettings(CWnd* pParent = NULL);   // standard constructor
	CIPViewerSettings( CWnd* pParent, CIPSettings* settings );

	virtual ~CIPViewerSettings();

	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonCancel();
	afx_msg void OnBnClickedCheckEnableLogging();

	// Dialog Data
	enum { IDD = IDD_DIALOG_SETTINGS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	
	DECLARE_MESSAGE_MAP()

private:
	HICON m_hIcon;

	CIPSettings* m_pSettings;
	
	BOOL m_bMinToTray;
	BOOL m_bCloseTray;
	BOOL m_bOnTop;
	BOOL m_bStartMinimized;
	BOOL m_bCheckExternalIp;
	BOOL m_bEnableLogging;

	int m_nTick;
	int m_nSelectedIndex;
		
	
	CButton m_CheckInternalIp;
	CButton m_CheckExternalIp;
	CButton m_CheckHostName;
	CButton m_CheckMacAddress;
	CEdit m_LogInterval;
	CEdit m_LogFileName;
	CComboBox m_LogFileExtension;
};
