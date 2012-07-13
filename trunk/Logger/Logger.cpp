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

void CLogger::LogError( CString message, CException* exception )
{
	TCHAR   szCause[255];
    CString strFormatted;

	exception->GetErrorMessage( szCause, 255 );
	strFormatted = TEXT("The following error occured - ");
	strFormatted += szCause;
	strFormatted += TEXT("\n, Message - ");
	strFormatted += message;

	CLogger::Log( true, strFormatted );	
}

void CLogger::LogError(CException* exception)
{
	TCHAR   szCause[255];
    CString strFormatted;

	exception->GetErrorMessage( szCause, 255 );
	strFormatted = TEXT("The following error occured - ");
	strFormatted += szCause;

	CLogger::Log( true, strFormatted);

}


void CLogger::LogError(CString error)
{
	CLogger::Log(true,error);
}


void CLogger::Log(CString message)
{
	CLogger::Log( false, message);
}

void CLogger::Log( CString message, CString file )
{
	CLogger::Log( false, message, file );
}

void::CLogger::Log( bool isError, CString message, CString file )
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
		// open the user specified file or the default file for appending
		if( file &&
			file.GetLength() > 0 )
		{
			fout.open( file, ios::app );
		}
		else
		{
			fout.open( MESSAGE_LOG_FILE, ios::app );
		}
	}

	CTime theTime = CTime::GetCurrentTime();
	CString s;
	s += theTime.Format( "%m/%d/%Y %X - " );

	fout << (LPCTSTR)s << (LPCTSTR)message << endl;
	fout.flush();
}