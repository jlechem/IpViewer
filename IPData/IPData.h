// IPData.h : main header file for the IPData DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols

#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)

// CIPDataApp
// See IPData.cpp for the implementation of this class
//

class DLLEXPORT CIPData : public CWinApp
{
public:
	CIPData();

// Overrides
public:
	virtual BOOL InitInstance();

	static CString LoadIpAddress();
	static CString LoadMacAddress();
	static CString LoadHostName();
	static CString LoadSubnet();

	DECLARE_MESSAGE_MAP()
};
