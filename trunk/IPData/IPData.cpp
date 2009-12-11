// IPData.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "IPData.h"

#include <lm.h>
#include <winsock2.h>

#pragma comment( lib, "Netapi32.lib" )

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

BEGIN_MESSAGE_MAP(CIPData, CWinApp)
END_MESSAGE_MAP()


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
	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	return TRUE;
}


// IPData.cpp : Defines the initialization routines for the DLL.
CString CIPData::LoadIpAddress( void )
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
	CString ip("127.0.0.1");
	
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
					ip = inet_ntoa(*(struct in_addr *)hostinfo->h_addr_list[0]);
				}
            }

			WSACleanup();
		}

		return ip;

	}
	catch( ... )
	{
		// load some default values from the string table
		return _T("127.0.0.1");
	}

}

CString CIPData::LoadMacAddress( void )
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
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

		CString mac;
		mac.Format( _T("%02X-%02X-%02X-%02X-%02X-%02X"), MACData[0], MACData[1], MACData[2], MACData[3], MACData[4], MACData[5]);

		return mac.AllocSysString();

	}
	catch( CException* ex )
	{
		// TODO: do somethign with the exception
		delete ex;
		return BSTR( L"00-00-00-00-00-00" );
	}
}

CString CIPData::LoadHostName( void )
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
	CString host("Localhost");

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
				host = name;
            }

			WSACleanup();
		}

		return host;

	}
	catch( ... )
	{
		// load some default values from the string table
		return _T("Localhost");
	}
}

CString CIPData::LoadSubnet( void )
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return _T("255.255.255.0");
}