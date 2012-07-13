#pragma once

#include "stdafx.h"

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

class DLLEXPORT CIpInformation
{
private:
	CString m_strAdapterName;
	CString m_strAdapterDescription;
	CString m_strIpV4Address;
	CString m_strIpV6Address;
	CString m_strMAC;
	CString m_strSubnet;
	CString m_strDefaultGateway;
	CString m_strType;

	BOOL m_isEnabled;

	BOOL m_isIpV4;
	BOOL m_isIpV6;

public:

	CString GetAdapterName() { return m_strAdapterName; }
	CString GetAdapterDescription() { return m_strAdapterDescription; }
	CString GetIpV4Address() { return m_strIpV4Address; }
	CString GetIpV6Address() { return m_strIpV6Address; }
	CString GetMac() { return m_strMAC; }
	CString GetSubnet() { return m_strSubnet; }
	CString GetDefaultGateway() { return m_strDefaultGateway; }
	CString GetAdapterType() { return m_strType; }

	BOOL GetAdapterEnabled() { return m_isEnabled; }

	void SetAdapterName( CString value ) { m_strAdapterName = value; }
	void SetAdapterDescription( CString value ) { m_strAdapterDescription = value; }
	void SetIpV4Address( CString value ) { m_strIpV4Address = value; }
	void SetIpV6Address( CString value ) { m_strIpV6Address = value; }
	void SetMAC( CString value ) { m_strMAC = value; }
	void SetSubnet( CString value ) { m_strSubnet = value; }
	void SetDefaultGateway( CString value ) { m_strDefaultGateway = value; }
	void SetAdapterType( CString value ) { m_strType = value; }
	
	void SetEnabled( BOOL isEnabled ) { m_isEnabled = isEnabled; }

	void SetIpV4Enabled( BOOL isEnabled ) { m_isIpV4 = isEnabled; }
	void SetIpV6Enabled( BOOL isEnabled ) { m_isIpV6 = isEnabled; }

	CIpInformation(void);
	~CIpInformation(void);

};