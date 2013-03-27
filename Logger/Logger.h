// Logger.h : main header file for the Logger DLL
//

#pragma once

#include "StdAfx.h"
#include <iostream>
#include <fstream>

#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>

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
	static void Init();
	static void Log( BOOL isError, CString message );

private:
	CLogger(void);
	~CLogger(void);
 
};
