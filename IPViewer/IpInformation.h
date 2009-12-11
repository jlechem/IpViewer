#pragma once

#include "StdAfx.h"
#include "..\IPData\IPData.h"

__declspec(dllimport) CIPData;

class CIpInformation
{
public:
	CIpInformation(void);
	
	
	~CIpInformation(void);

	CString GetMask() { return m_strMask; };
	CString GetIpAddress() { return m_strIpAddress; };
	CString GetHostName() { return m_strHostName; };
	CString GetMacAddress() { return m_strMacAddress; };
	CString GetAdapterDescription() { return m_strAdapterDescription; }
	CString GetExternalIpAddress() { return m_strExternalIpAddress; }

	void Update();

private:
	CString m_strIpAddress;
	CString m_strHostName;
	CString m_strMacAddress;
	CString m_strExternalIpAddress;
	CString m_strAdapterDescription;
	CString m_strMask;
	
	// Loads the ip information for the machine into the class
	void LoadIpInformation( void );
	void LoadMAC( void );

};
