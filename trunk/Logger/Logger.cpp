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

#include "StdAfx.h"
#include "Logger.h"

// declare our static variables
std::mutex CLogger::m_mutexFile;
CFile CLogger::file;

/*

	Info:			Default Constructor
	Created By:		Justin LeCheminant
	Created Date:	2013.3.4

	Parameters:		N/A
	Return Values:	N/A

*/
CLogger::CLogger(void)
{
}

/*
	Info:			Default Desructor
	Created By:		Justin LeCheminant
	Created Date:	2013.3.4

	Parameters:		N/A
	Return Values:	N/A

*/
CLogger::~CLogger(void)
{
}

/*
	Info:			Logs an error message to the error log file specified in the log4cpp.properties file
	Created By:		Justin LeCheminant
	Created Date:	2013.3.4

	Parameters:		
		CStringmessage -		The message to log
		CException* exception -	The exception object to log

	Return Values:	N/A

*/
void CLogger::LogError( CString message, CException* exception )
{
	TCHAR   szCause[255];
    CString strFormatted;

	exception->GetErrorMessage( szCause, 255 );
	strFormatted += TEXT("Message - ");
	strFormatted += message;
	strFormatted = TEXT("\nException - ");
	strFormatted += szCause;
	
	CLogger::Log( true, strFormatted );
}

/*
	Info:			Logs an error message to the error log file specified in the log4cpp.properties file
	Created By:		Justin LeCheminant
	Created Date:	2013.3.4

	Parameters:		
		CException* exception -	The exception object to log

	Return Values:	N/A

*/
void CLogger::LogError( CException* exception )
{
	TCHAR   szCause[255];
    CString strFormatted;

	exception->GetErrorMessage( szCause, 255 );
	strFormatted += szCause;

	CLogger::Log( TRUE, strFormatted );
}

/*
	Info:			Logs an error message to the error log file specified in the log4cpp.properties file
	Created By:		Justin LeCheminant
	Created Date:	2013.3.4

	Parameters:		
		CString message -	The message to log

	Return Values:	N/A

*/
void CLogger::LogError( CString error )
{
	CLogger::Log( TRUE, error );
}

/*
	Info:			Logs a message to the generic log file specified in the log4cpp.properties file
	Created By:		Justin LeCheminant
	Created Date:	2013.3.4

	Parameters:		
		CString message -	The message to log

	Return Values:	N/A

*/
void CLogger::Log( CString message )
{
	CLogger::Log( FALSE, message );
}

/*
	Info:			Logs a message to the generic log file or the error log file specified in the log4cpp.properties file
	Created By:		Justin LeCheminant
	Created Date:	2013.3.4

	Parameters:
		BOOL isError -		A boolean that states if this is an error or generic application log message
		CString message -	The message to log

	Return Values:	N/A

*/
void::CLogger::Log( BOOL isError, CString message )
{	
	// set a lock so we can write and not allow a change to the filename
	std::lock_guard<std::mutex> lock(m_mutexFile);

	CTime time = CTime::GetCurrentTime();
	
	CString line = time.Format("%m/%d/%Y - ") + message + TEXT("\r\n");

	// if it's an error write to the error log
	// otherwise write it to the output log	
	BOOL isOpen = true;

	if (isError)
	{
		isOpen = file.Open(TEXT("error.log"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite | CFile::shareDenyNone);
	}
	else
	{
		isOpen = file.Open(TEXT("output.log"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite | CFile::shareDenyNone);
	}

	if (isOpen)
	{
		CW2A ansiText(line, CP_UTF8);
		file.SeekToEnd();
		file.Write(ansiText, ::strlen(ansiText));
		file.Close();
	}
}