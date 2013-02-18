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

// IPData.h : main header file for the IPData DLL
//

#pragma once

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

#include <vector>
#include <memory>

#include "resource.h"			// main symbols
#include "..\Logger\Logger.h"
#include "lm.h"
#include "winsock2.h"
#include "urlmon.h"
#include "Iphlpapi.h"
#include "IpInformation.h"
#include "stdafx.h"

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

// CIPDataApp
// See IPData.cpp for the implementation of this class
//
using namespace std;

class DLLEXPORT CIPData
{
public:
	CIPData();

// Overrides
public:
	virtual BOOL InitInstance();

	CString GetExternalIpAddress()
	{ 
		this->LoadExternalIpAddress();
		return m_strExternalIp; 
	}

	CString GetHostName()
	{
		this->LoadHostName();
		return m_strHostName; 
	}

	vector<CIpInformation*> GetAdapterInformation()
	{
		this->LoadAdapterData();
		return m_pAdapterInformation; 
	}

private:

	CString m_strExternalIp;							// holds the external ip address
	CString m_strHostName;								// holds the host name

	BOOL m_bIsXPorHigher;								// is the host OS windows XP or higher

	vector<CIpInformation*> m_pAdapterInformation;		// holds our adapter information

	void LoadHostName();								// gets the computers host name
	void LoadExternalIpAddress();						// gets the external ip address of the default adapter
	void LoadAdapterData();								// loads the vector list and all the ip information for all the adapters
	void LoadXpOrHigher();								// loads data for OS windowsXP or higher
	void LoadLowerThanXp();								// loads data for any OS before windowsXP
	void LoadVistaOrHigher();							// loads tehe data for any OS windows Vista orh higher
	CString ConvertByteToString( BYTE *, UINT );		//converts a byte array into a human readable hex string
	CString ConvertToStatus( IF_OPER_STATUS status );	// converts a oper status to a cstring

};