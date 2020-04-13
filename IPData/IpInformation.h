#pragma once

#include "stdafx.h"
#include <vector>

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

using namespace std;

class DLLEXPORT CIpInformation
{
private:
	CString m_strAdapterName;
	CString m_strAdapterDescription;
	CString m_strMAC;
	CString m_strSubnet;
	CString m_strDefaultGateway;
	CString m_strType;
	CString m_strStatus;

	BOOL m_isEnabled;

	BOOL m_isIpV4;
	BOOL m_isIpV6;

	vector<CString*> m_pIpAddresses; 

public:

	CString GetAdapterName() { return m_strAdapterName; }
	CString GetAdapterDescription() { return m_strAdapterDescription; }
	vector<CString*> GetIpAddresses() { return m_pIpAddresses; }
	CString GetMac() { return m_strMAC; }
	CString GetSubnet() { return m_strSubnet; }
	CString GetDefaultGateway() { return m_strDefaultGateway; }
	CString GetAdapterType() { return m_strType; }
	CString GetStatus() { return m_strStatus; }
	
	BOOL GetIpV4Enabled() { return m_isIpV4; }
	BOOL GetIpV6Enabled() { return m_isIpV6; }

	BOOL GetAdapterEnabled() { return m_isEnabled; }

	void SetAdapterName( CString value ) { m_strAdapterName = value; }
	void SetAdapterDescription( CString value ) { m_strAdapterDescription = value; }
	void AddIpAddress( CString* value );
	void ClearIpAddresses();
	void SetMAC( CString value ) { m_strMAC = value; }
	void SetSubnet( CString value ) { m_strSubnet = value; }
	void SetDefaultGateway( CString value ) { m_strDefaultGateway = value; }
	void SetAdapterType( CString value ) { m_strType = value; }
	void SetStatus( CString value ) {m_strStatus = value; }

	void SetEnabled( BOOL isEnabled ) { m_isEnabled = isEnabled; }

	void SetIpV4Enabled( BOOL isEnabled ) { m_isIpV4 = isEnabled; }
	void SetIpV6Enabled( BOOL isEnabled ) { m_isIpV6 = isEnabled; }

	CIpInformation(void);
	~CIpInformation(void);

};