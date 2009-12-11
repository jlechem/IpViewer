// IPViewerDlg.h : header file
#pragma once

#define IDT_TIMER WM_USER + 200

#include "IPSettings.h"
#include "IpInformation.h"
#include "afxcmn.h"
#include "Clipboard.h"
#include "afxwin.h"

// CIPViewerDlg dialog
class CIPViewerDlg : public CDialog
{
// Construction
public:
	CIPViewerDlg(CWnd* pParent = NULL);	// standard constructor

	// Dialog Data
	enum { IDD = IDD_IPVIEWER_DIALOG };

	// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHelpAbout();
	afx_msg void OnFileRefresh();
	afx_msg void OnFileExit();
	afx_msg void OnEditSettings();
	afx_msg void OnTimer( UINT nID );
	afx_msg void OnEditCopyipaddress();
	afx_msg void OnEditCopymac();
	afx_msg void OnEditCopyhostname();
	afx_msg void OnPopupCopyipaddress();
	afx_msg void OnPopupCopyhostname();
	afx_msg void OnPopupCopymac();
	afx_msg void OnPopupEditsettings();
	afx_msg void OnPopupRefreshipinformation();
	afx_msg LRESULT OnTrayNotification( WPARAM, LPARAM );
	afx_msg void OnSize( UINT, int, int );
	afx_msg void OnClose();
	afx_msg void OnPopupExit();
	afx_msg void OnWindowPosChanging( WINDOWPOS FAR* );
	afx_msg void OnPopupCopyall();
	DECLARE_MESSAGE_MAP()

private:
	HICON m_hIcon;
	
	CIPSettings* m_pSettings;
	CIpInformation* m_pIpInfo;
	
	CString m_strMac;
	CString m_strHost;
	CString m_strIP;

	BOOL m_bVisible;

	void CopyAll();
	void SetTopMost();
	void RefreshIpInfo();
	void EditSettings();
	BOOL TrayMessage( DWORD );
	
	CStatic m_staticIP;
	CStatic m_staticHost;
	CStatic m_staticMac;
	CStatic m_staticMacCaption;
};
