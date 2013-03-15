// Logger.h : main header file for the Logger DLL
//

#pragma once

#include "StdAfx.h"
#include <iostream>
#include <fstream>

#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/NDC.hh>

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

using namespace std;

#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)

 class DLLEXPORT CLogger
{
public:
	static void LogError( CString, CException* );
	static void LogError( CException* );
	static void LogError( CString );
	static void Log( CString );
	static void Log( CString, CString );

private:
	CLogger(void);
	~CLogger(void);

	static CString MESSAGE_LOG_FILE;
	static CString ERROR_LOG_FILE;

	static void Log( bool isError, CString message, CString file = NULL );

};
