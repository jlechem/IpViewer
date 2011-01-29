/*
	Copyright 2010 Justin LeCheminant

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

	static CString LoadIpAddress();						// gets the default adapter internal IP address
	static CString LoadIpAddress( CString adapter );	// gets the ip address for the specified adapter

	static CString LoadMacAddress();					// gets the default adaper MAC address
	static CString LoadMacAddress( CString adapter );	// gets the MAC address for the specified adapter
	
	static CString LoadSubnet();						// gets the default adapter subnet address
	static CString LoadSubnet( CString adapter );		// gets the subnet address for the specified adapter

	static CString LoadHostName();						// gets the computers host name
	static CStringArray* LoadAdapters();				// gets a string array of all the adapters on this system
	
	static CString LoadExternalIpAddress();				// gets the external ip address of the default adapter
	static CString LoadExternalIpAddress( CString );	// gets the external ip address for the specified adapter
	
	DECLARE_MESSAGE_MAP()

private:

protected:


};
