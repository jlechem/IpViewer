/*
	Copyright 2011 Justin LeCheminant

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

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)

#include "resource.h"		// main symbols
#include <lm.h>
#include <winsock2.h>
#include <urlmon.h>

#pragma comment(lib, "urlmon.lib")
#pragma comment( lib, "Netapi32.lib" )

// CIPDataApp
// See IPData.cpp for the implementation of this class
//

class DLLEXPORT CIPData
{
public:
	CIPData();

// Overrides
public:
	virtual BOOL InitInstance();

	CString GetIpAddress() 
	{
		this->LoadIpAddress(); 
		return m_strInternalIp; 
	}

	
	CString GetExternalIpAddress()
	{ 
		this->LoadExternalIpAddress();
		return m_strExternalIp; 
	}

	CString GetMacAddress() 
	{
		this->LoadMacAddress();
		return m_strMacAddress; 
	}

	CString GetHostName()
	{
		this->LoadHostName();
		return m_strHostName; 
	}

	CString GetSubNet() 
	{
		this->LoadSubnet();
		return m_strSubnet; 
	}

private:

	CString m_strInternalIp;
	CString m_strExternalIp;
	CString m_strHostName;
	CString m_strMacAddress;
	CString m_strSubnet;

	void LoadIpAddress();			// gets the default adapter internal IP address
	void LoadMacAddress();			// gets the default adaper MAC address
	void LoadSubnet();				// gets the default adapter subnet address
	void LoadHostName();			// gets the computers host name
	void LoadExternalIpAddress();	// gets the external ip address of the default adapter

protected:

};