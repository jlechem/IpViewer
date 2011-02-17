/*
	Copyright 2011 Justin LeCheminant

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

// IPData.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "IPData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CIPData
// CIPData construction

CIPData::CIPData()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CIPData object

CIPData theApp;


// CIPData initialization

BOOL CIPData::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	return TRUE;
}

void CIPData::LoadExternalIpAddress()
{
	m_strExternalIp = _T( "Unavailable" );

	try
	{	
		/*

		to make the UrlDownloadToFile call you need the following defined

		#include <urlmon.h>

		#pragma comment(lib, "urlmon.lib")

		*/

		// holds the url to check and the name of the file to write the data to
		TCHAR url[47] = _T("http://checkip.dyndns.org/Current IP Check.htm");
		TCHAR file[7] = _T("ip.txt");

		// here is the urlmon.dll method call, include 
		if( URLDownloadToFile( 0, url, file, 0, 0) == S_OK )
		{
			CStdioFile file;

			// open the file for reading
			if( file.Open( _T("ip.txt"), CFile::modeRead | CFile::modeNoTruncate ) )
			{
				file.ReadString( m_strExternalIp );

				// file if successful is in format
				// <html><head><title>Current IP Check</title></head><body>Current IP Address: 174.52.71.72</body></html>
				if( m_strExternalIp.Find(_T("</HTML>") < 0 ) )
				{
					m_strExternalIp = _T( "Unable to access IP check site" );
				}
				else
				{
					m_strExternalIp = m_strExternalIp.Mid( m_strExternalIp.Find( _T(": ") ) + 1, m_strExternalIp.GetLength() - m_strExternalIp.Find( _T("</body>") ) - 1 );
				}

				// always close the file
				file.Close();

			}
		}
		else
		{
			m_strExternalIp = _T( "Unable to access IP check site" );
		}
	}
	catch( CException* ex )
	{
		// write any errors to a log file
		TCHAR   szCause[255];
		CString strFormatted;

		ex->GetErrorMessage(szCause, 255);

		strFormatted = _T("The following error occurred: ");
	    strFormatted += szCause;

		CStdioFile file(_T("error_log.txt"), CFile::modeWrite | CFile::modeNoTruncate );

		if( file )
		{
			file.WriteString( strFormatted );
		}

		file.Close();

		delete ex;

	}
}

// IPData.cpp : Defines the initialization routines for the DLL.
void CIPData::LoadIpAddress( void )
{
	try
	{
		WORD wVersionRequested;
		WSADATA wsaData;
		char name[512];
		PHOSTENT hostinfo;
		wVersionRequested = MAKEWORD( 2, 0 );

		if ( WSAStartup( wVersionRequested, &wsaData ) == 0 )
		{
            if( gethostname ( name, sizeof(name)) == 0)
            {
				if( (hostinfo = gethostbyname(name)) != NULL )
				{
					m_strInternalIp = inet_ntoa(*(struct in_addr *)hostinfo->h_addr_list[0]);
				}
            }

			WSACleanup();
		}
	}
	catch( ... )
	{
		// load some default values from the string table
		m_strInternalIp = _T("127.0.0.1");
	}

}

// loads the mac address of the default adapter
void CIPData::LoadMacAddress( void )
{
	try
	{
		unsigned char MACData[8];						// Allocate data structure for MAC (6 bytes needed)

		WKSTA_TRANSPORT_INFO_0 *pwkti;					// Allocate data structure for Netbios
		DWORD dwEntriesRead;
		DWORD dwTotalEntries;
		BYTE *pbBuffer;
	    
		// Get MAC address via NetBios's enumerate function
		NET_API_STATUS dwStatus = NetWkstaTransportEnum(
			NULL,						// [in]  server name
			0,							// [in]  data structure to return
			&pbBuffer,					// [out] pointer to buffer
			MAX_PREFERRED_LENGTH,		// [in]  maximum length
			&dwEntriesRead,				// [out] counter of elements actually enumerated
			&dwTotalEntries,			// [out] total number of elements that could be enumerated
			NULL);						// [in/out] resume handle

		ASSERT( dwStatus == NERR_Success ); 

		pwkti = (WKSTA_TRANSPORT_INFO_0 *)pbBuffer;		// type cast the buffer

		for(DWORD i=1; i< dwEntriesRead; i++)			// first address is 00000000, skip it
		{												// enumerate MACs and print
			swscanf_s((wchar_t *)pwkti[i].wkti0_transport_address, _T("%2hx%2hx%2hx%2hx%2hx%2hx"), 
				&MACData[0], &MACData[1], &MACData[2], &MACData[3], &MACData[4], &MACData[5]);
		}

		// Release pbBuffer allocated by above function
		dwStatus = NetApiBufferFree(pbBuffer);
		ASSERT( dwStatus == NERR_Success );

		m_strMacAddress.Format( _T("%02X-%02X-%02X-%02X-%02X-%02X"), MACData[0], MACData[1], MACData[2], MACData[3], MACData[4], MACData[5]);

	}
	catch( CException* ex )
	{
		// TODO: do somethign with the exception
		delete ex;
		m_strMacAddress = _T( "00-0-00-00-00-00" );
	}
}

// loads the host name of the machine
void CIPData::LoadHostName( void )
{
	try
	{
		WORD wVersionRequested;
		WSADATA wsaData;
		char name[512];
		wVersionRequested = MAKEWORD( 2, 0 );

		if ( WSAStartup( wVersionRequested, &wsaData ) == 0 )
		{
            if( gethostname ( name, sizeof(name)) == 0)
            {
				m_strHostName = name;
            }

			WSACleanup();
		}
	}
	catch( ... )
	{
		// TODO: load some default values from the string table
		m_strHostName = _T("Localhost");
	}
}

// load the subnet for the default adapter
void CIPData::LoadSubnet( void )
{
	// TODO: get the subnet for the default adapter
	m_strSubnet = _T("255.255.255.0");
}