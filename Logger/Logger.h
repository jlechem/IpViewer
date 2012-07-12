// Logger.h : main header file for the Logger DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "StdAfx.h"
#include <iostream>
#include <fstream>

using namespace std;

#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)

static class DLLEXPORT CLogger
{
public:
	CLogger(void);
	~CLogger(void);
	static void LogError( CException* );
	static void LogError( CString );
	static void Log( CString );
	static void Log( CString, CString );

private:

	static CString MESSAGE_LOG_FILE;
	static CString ERROR_LOG_FILE;

	static void Log( bool isError, CString message, CString file = NULL );

};
