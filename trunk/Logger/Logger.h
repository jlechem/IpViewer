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

// Logger.h : main header file for the Logger DLL
//

#pragma once

#include "StdAfx.h"
#include <iostream>
#include <fstream>
#include <mutex>

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

using namespace std;

#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)

class DLLEXPORT CLogger
{
public:
	static void LogError(CString, CException*);
	static void LogError(CException*);
	static void LogError(CString);
	static void Log(CString);
	static void Log(BOOL isError, CString message);
	static void SetLogFile(CString);

private:
	CLogger(void);
	~CLogger(void);
	
	static CFile file;
	static std::mutex m_mutexFile;  // protects the file during writing

};
