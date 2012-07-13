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

// IPData.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "IPData.h"

#include <memory>

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
	// determine if we're running windowsXP or higher
		OSVERSIONINFO osvi;
		BOOL bIsWindowsXPorLater;

		ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

		GetVersionEx(&osvi);

		m_bIsXPorHigher = 
			( (osvi.dwMajorVersion > 5) ||
			( (osvi.dwMajorVersion == 5) && (osvi.dwMinorVersion >= 1) ));

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
	m_strExternalIp = TEXT( "Unavailable" );

	try
	{	
		/*

		to make the UrlDownloadToFile call you need the following defined

		#include <urlmon.h>, you also have to link to the urlmon.lib library in the linker options

		*/

		// holds the url to check and the name of the file to write the data to
		TCHAR url[47] = TEXT("http://checkip.dyndns.org/Current IP Check.htm");
		TCHAR file[7] = TEXT("ip.txt");

		// here is the urlmon.dll method call, include 
		if( URLDownloadToFile( 0, url, file, 0, 0) == S_OK )
		{
			CStdioFile file;

			m_strExternalIp = TEXT("");

			// open the file for reading
			if( file.Open( TEXT("ip.txt"), CFile::modeRead | CFile::modeNoTruncate ) )
			{
				file.ReadString( m_strExternalIp );

				// file if successful is in format
				// <html><head><title>Current IP Check</title></head><body>Current IP Address: 174.52.71.72</body></html>
#ifdef DEBUG
				m_strExternalIp = TEXT("<html><head><title>Current IP Check</title></head><body>Current IP Address: 174.52.71.72</body></html>");
#endif
				if( UINT index = m_strExternalIp.Find(TEXT("</html>") ) == -1 )
				{
					m_strExternalIp = TEXT( "Unable to access IP check site" );
				}
				else
				{
					std::auto_ptr<INT> startIndex( new INT() );
					std::auto_ptr<INT> endIndex( new INT() );
					
					// this should get us the index of the first digit in the address
					*startIndex = m_strExternalIp.Find( TEXT(": ") ) + 2;

					// this should get us the index of the last digit in the address
					*endIndex = m_strExternalIp.Find( TEXT("</body>") );

					// the ip address should be the length between the first index and the last index
					m_strExternalIp = m_strExternalIp.Mid( *startIndex, *endIndex - *startIndex );

				}

				// always close the file
				file.Close();

			}
		}
		else
		{
			m_strExternalIp = TEXT( "Unable to access IP check site" );
		}
	}
	catch( CException* ex )
	{
		CLogger::LogError( ex );
		delete ex;
	}
}

// IPData.cpp : Defines the initialization routines for the DLL.
void CIPData::LoadIpAddress( void )
{
	try
	{
		//// let's try this GetAdaptersAddress function instead, this is only valid for windowsXP and higher
		//if( m_bIsXPorHigher )
		//{
		//	DWORD dwSize = 0;
		//	DWORD dwRetVal = 0;

		//	unsigned int i = 0;

		//	// Set the flags to pass to GetAdaptersAddresses
		//	ULONG flags = GAA_FLAG_INCLUDE_PREFIX;

		//	// default to unspecified address family (both)
		//	ULONG family = AF_UNSPEC;

		//	LPVOID lpMsgBuf = NULL;

		//	PIP_ADAPTER_ADDRESSES pAddresses = NULL;
		//	ULONG outBufLen = 0;
		//	ULONG Iterations = 0;

		//	outBufLen = WORKING_BUFFER_SIZE;

		//	pAddresses = (IP_ADAPTER_ADDRESSES *) MALLOC(outBufLen);
  //      
		//	if (pAddresses == NULL) 
		//	{
		//		AfxMessageBox( TEXT("Memory allocation failed for IP_ADAPTER_ADDRESSES struct"));
		//	}

		//	dwRetVal = GetAdaptersAddresses(family, flags, NULL, pAddresses, &outBufLen);

		//	if (dwRetVal == ERROR_BUFFER_OVERFLOW)
		//	{
		//		FREE(pAddresses);
		//		pAddresses = NULL;
		//	}
		//}
		//// anything less than windows XP gets the ola WSA method
		//else
		//{
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
		//}
	}
	catch( CException *ex )
	{
		CLogger::LogError( ex );
		delete ex;
		// TODO: load some default values from the string table
		m_strInternalIp = TEXT("127.0.0.1");
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
			swscanf_s((wchar_t *)pwkti[i].wkti0_transport_address, TEXT("%2hx%2hx%2hx%2hx%2hx%2hx"), 
				&MACData[0], &MACData[1], &MACData[2], &MACData[3], &MACData[4], &MACData[5]);
		}

		// Release pbBuffer allocated by above function
		dwStatus = NetApiBufferFree(pbBuffer);
		ASSERT( dwStatus == NERR_Success );

		m_strMacAddress.Format( TEXT("%02X-%02X-%02X-%02X-%02X-%02X"), MACData[0], MACData[1], MACData[2], MACData[3], MACData[4], MACData[5]);

	}
	catch( CException* ex )
	{
		CLogger::LogError( ex );
		delete ex;
		m_strMacAddress = TEXT( "00-0-00-00-00-00" );
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
	catch( CException* ex )
	{
		CLogger::LogError(ex);
		delete ex;
		// TODO: load some default values from the string table
		m_strHostName = TEXT("Localhost");
	}
}

// load the subnet for the default adapter
void CIPData::LoadSubnet( void )
{
	m_strSubnet = TEXT("255.255.255.0");

	try
	{
		PIP_ADAPTER_INFO FixedInfo;

		ULONG ulOutBufLen = 0;

		DWORD result;

		//get the first result should be an overflow, this is expected to get the correct length
		result = GetAdaptersInfo( 0, &ulOutBufLen );

		if( result == ERROR_BUFFER_OVERFLOW )
		{
			BYTE* pNewBuffer = new BYTE[ulOutBufLen];
			
			FixedInfo = reinterpret_cast<PIP_ADAPTER_INFO>( pNewBuffer );
			
			result = GetAdaptersInfo( FixedInfo, &ulOutBufLen );

			if ( result != NO_ERROR )
			{
				CLogger::Log( TEXT("Cound not get the adapter information!") );
			}
			else
			{
				m_strSubnet = FixedInfo->IpAddressList.IpMask.String;
			}
		}
	}
	catch( CException* ex )
	{
		CLogger::LogError(ex);
		delete ex;
		m_strSubnet = TEXT("255.255.255.0");
	}
}