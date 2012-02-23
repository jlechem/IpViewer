#include "StdAfx.h"
#include "Logger.h"

CString CLogger::ERROR_LOG_FILE = TEXT("error_log.txt");
CString CLogger::MESSAGE_LOG_FILE = TEXT("message_log.txt");

CLogger::CLogger(void)
{
}


CLogger::~CLogger(void)
{
}


void CLogger::LogError(CException* exception)
{
	// TODO: get the error, then log it
	CString error;

	exception->GetErrorMessage( error.GetBuffer(0), 255 );
	error.ReleaseBuffer();

	CLogger::Log( true, error);

}


void CLogger::LogError(CString error)
{
	CLogger::Log(true,error);
}


void CLogger::Log(CString message)
{
	CLogger::Log( false, message);
}


void::CLogger::Log( bool isError, CString message )
{
	// our output stream
	 wofstream fout;

	if( isError )
	{
		// open file for appending
		fout.open( ERROR_LOG_FILE, ios::app );
	}
	else
	{
		// open file for appending
		fout.open( MESSAGE_LOG_FILE, ios::app );
	}

	CTime theTime = CTime::GetCurrentTime();
	CString s;
	s += theTime.Format( "%m/%d/%Y %X - " );

	fout << (LPCTSTR)s << (LPCTSTR)message << endl;
	fout.flush();
}