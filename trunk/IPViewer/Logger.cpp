#include "StdAfx.h"
#include "Logger.h"


CLogger::CLogger(void)
	: m_strMessageLogFileName(_T(""))
	, m_strErrorLogFileName(_T(""))
{
}


CLogger::~CLogger(void)
{
}


void CLogger::LogError(CException* exception)
{
}


void CLogger::LogError(CString error)
{
}


void CLogger::Log(CString message)
{
}
