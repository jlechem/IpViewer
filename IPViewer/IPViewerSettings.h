#pragma once

#include "IPSettings.h"
#include "afxwin.h"

// CIPViewerSettings dialog
class CIPViewerSettings : public CDialog
{
	DECLARE_DYNAMIC(CIPViewerSettings)

public:
	CIPViewerSettings(CWnd* pParent = NULL);   // standard constructor
	CIPViewerSettings( CWnd* pParent = NULL, CIPSettings* settings = NULL );

	virtual ~CIPViewerSettings();

	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonCancel();
	
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

	int m_nTick;
	int m_nSelectedIndex;
	
};
