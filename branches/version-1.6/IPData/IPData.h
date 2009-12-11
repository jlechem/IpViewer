/*
	Copyright 2009 Justin LeCheminant
*/

/*
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

	static CString LoadIpAddress();
	static CString LoadMacAddress();
	static CString LoadHostName();
	static CString LoadSubnet();

	DECLARE_MESSAGE_MAP()
};
