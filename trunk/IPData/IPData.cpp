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

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//		If this DLL is dynamically linked against the MFC DLLs,
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
	// Place all significant initialization in InitInstance

	// determine if we're running windowsXP or higher
	OSVERSIONINFO osvi;
	BOOL bIsWindowsXPorLater = FALSE;

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

// load the external ip address
void CIPData::LoadExternalIpAddress()
{
	m_strExternalIp.LoadString( IDS_Unavailable );

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
					m_strExternalIp.LoadString( IDS_Check );
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
			m_strExternalIp.LoadString( IDS_Check );
		}
	}
	catch( CException* ex )
	{
		CLogger::LogError( ex );
		delete ex;
	}
}

// loads the host name of the machine
void CIPData::LoadHostName()
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
		m_strHostName.LoadString( IDS_Localhost );
	}
}

void CIPData::LoadAdapterData()
{
	// based on the OS load the data
	m_bIsXPorHigher ? this->LoadXpOrHigher() : this->LoadLowerThanXp();
}

// loads the data for windowsXP or higher, this calls the GetAdaptersAddress function
void CIPData::LoadXpOrHigher()
{
	try
	{
		DWORD dwSize = 0;
		DWORD dwRetVal = 0;

		unsigned int i = 0;

		// Set the flags to pass to GetAdaptersAddresses
		ULONG flags = GAA_FLAG_INCLUDE_PREFIX;

		// default to unspecified address family (both)
		ULONG family = AF_UNSPEC;

		LPVOID lpMsgBuf = NULL;

		PIP_ADAPTER_ADDRESSES pAdapterList = NULL;
		ULONG outBufLen = 0;

		dwRetVal = GetAdaptersAddresses(family, flags, NULL, 0, &outBufLen);

		// this should happen to get the correct buffer size
		if (dwRetVal == ERROR_BUFFER_OVERFLOW)
		{
			BYTE* pNewBuffer = new BYTE[outBufLen];
			
			pAdapterList = reinterpret_cast<PIP_ADAPTER_ADDRESSES>( pNewBuffer );

			if( pAdapterList )
			{
				dwRetVal = GetAdaptersAddresses(family, flags, NULL, pAdapterList, &outBufLen);

				if ( dwRetVal != NO_ERROR )
				{
					CLogger::Log( TEXT("Cound not get the adapter information!  IPData.cpp line 242. ") );
				}
				else
				{
					// always clear the vector
					m_pAdapterInformation.clear();
					
					// set the adapter to our adapter list
					PIP_ADAPTER_ADDRESSES pCurrentAdapter = pAdapterList;

					if( pCurrentAdapter )
					{
						// create the first item to be added to the vector
						CIpInformation* ipData = new CIpInformation();

						ipData->SetAdapterName( pCurrentAdapter->FriendlyName );
						ipData->SetAdapterDescription( pCurrentAdapter->Description );
						ipData->SetMAC( this->ConvertByteToString(pCurrentAdapter->PhysicalAddress, pCurrentAdapter->PhysicalAddressLength ) );
						ipData->SetStatus( this->ConvertToStatus( pCurrentAdapter->OperStatus) );
						DWORD length = 256;
						TCHAR holder[256];

						WSADATA wsaData = {0};
						WSAStartup( MAKEWORD(2, 2), &wsaData );

						PIP_ADAPTER_UNICAST_ADDRESS pUnicast = NULL;
						pUnicast = pCurrentAdapter->FirstUnicastAddress;

						if( pUnicast )
						{
							WSAAddressToString(
								pUnicast->Address.lpSockaddr,
								pUnicast->Address.iSockaddrLength,
								NULL, 
								holder,
								&length );

							CString* temp = new CString( holder );
							ipData->AddIpAddress( temp );

							pUnicast = pUnicast->Next;

							while( pUnicast )
							{
								WSAAddressToString(
								pUnicast->Address.lpSockaddr,
								pUnicast->Address.iSockaddrLength,
								NULL, 
								holder,
								&length );

								CString* temp = new CString( holder );
								ipData->AddIpAddress( temp );

								pUnicast = pUnicast->Next;
							}
						}

						if( pCurrentAdapter->FirstGatewayAddress )
						{
							WSAAddressToString(
								pCurrentAdapter->FirstGatewayAddress->Address.lpSockaddr,
								pCurrentAdapter->FirstGatewayAddress->Address.iSockaddrLength,
								NULL, 
								holder,
								&length );

							ipData->SetDefaultGateway( holder );
						}

						ipData->SetIpV4Enabled( pCurrentAdapter->Ipv4Enabled );
						ipData->SetIpV6Enabled( pCurrentAdapter->Ipv6Enabled );

						m_pAdapterInformation.push_back( ipData );

						pCurrentAdapter = pCurrentAdapter->Next;
					}

					while( pCurrentAdapter )
					{
						// create the first item to be added to the vector
						CIpInformation* ipData = new CIpInformation();

						ipData->SetAdapterName( pCurrentAdapter->FriendlyName );
						ipData->SetAdapterDescription( pCurrentAdapter->Description );
						ipData->SetMAC( this->ConvertByteToString(pCurrentAdapter->PhysicalAddress, pCurrentAdapter->PhysicalAddressLength ) );
						ipData->SetStatus( this->ConvertToStatus( pCurrentAdapter->OperStatus) );

						DWORD length = 256;
						TCHAR holder[256];
						
						PIP_ADAPTER_UNICAST_ADDRESS pUnicast = NULL;
						pUnicast = pCurrentAdapter->FirstUnicastAddress;

						if( pUnicast )
						{
							WSAAddressToString(
								pUnicast->Address.lpSockaddr,
								pUnicast->Address.iSockaddrLength,
								NULL, 
								holder,
								&length );

							CString* temp = new CString( holder );
							ipData->AddIpAddress( temp );

							pUnicast = pUnicast->Next;

							while( pUnicast )
							{
								WSAAddressToString(
								pUnicast->Address.lpSockaddr,
								pUnicast->Address.iSockaddrLength,
								NULL, 
								holder,
								&length );

								CString* temp = new CString( holder );
								ipData->AddIpAddress( temp );

								pUnicast = pUnicast->Next;
							}
						}

						ipData->SetIpV4Enabled( pCurrentAdapter->Ipv4Enabled );
						ipData->SetIpV6Enabled( pCurrentAdapter->Ipv6Enabled );

						if( pCurrentAdapter->FirstGatewayAddress )
						{
							WSAAddressToString(
								pCurrentAdapter->FirstGatewayAddress->Address.lpSockaddr,
								pCurrentAdapter->FirstGatewayAddress->Address.iSockaddrLength,
								NULL, 
								holder,
								&length );

							ipData->SetDefaultGateway( holder );
						}

						m_pAdapterInformation.push_back( ipData );

						pCurrentAdapter = pCurrentAdapter->Next;

					}
				}
			}
		}

		WSACleanup();

	}
	catch( CException *ex )
	{
		CLogger::LogError( ex );
		delete ex;
	}
}

// loads the data for windowsXP or higher, this calls the GetAdaptersInfo function
void CIPData::LoadLowerThanXp()
{
	try
	{
		ULONG ulOutBufLen = 0;

		//get the first result should be an overflow, this is expected to get the correct length
		DWORD result = GetAdaptersInfo( 0, &ulOutBufLen );

		if( result == ERROR_BUFFER_OVERFLOW )
		{
			PIP_ADAPTER_INFO pAdapterList;

			BYTE* pNewBuffer = new BYTE[ulOutBufLen];
			
			pAdapterList = reinterpret_cast<PIP_ADAPTER_INFO>( pNewBuffer );
			
			if( pAdapterList )
			{
				result = GetAdaptersInfo( pAdapterList, &ulOutBufLen );

				if ( result != NO_ERROR )
				{
					CLogger::LogError( TEXT("Cound not get the adapter information!  IPData.cpp line 418. ") );
				}
				else
				{
					// always clear the vector
					m_pAdapterInformation.clear();

					// set the adapter to our adapter list
					PIP_ADAPTER_INFO pCurrentAdapter = pAdapterList;

					if( pCurrentAdapter )
					{
						// create the first item to be added to the vector
						CIpInformation* ipData = new CIpInformation();

						CString temp;

						temp.Format( TEXT("%S"), pCurrentAdapter->AdapterName );
						ipData->SetAdapterName( temp );

						temp.Format( TEXT("%S"), pCurrentAdapter->Description );
						ipData->SetAdapterDescription( temp );
						
						CString* newTemp = new CString( pCurrentAdapter->IpAddressList.IpAddress.String );
						ipData->AddIpAddress( newTemp );

						temp.Format( TEXT("%S"), pCurrentAdapter->IpAddressList.IpMask.String );
						ipData->SetSubnet( temp );

						temp.Format( TEXT("%S"), pCurrentAdapter->GatewayList.IpAddress.String );
						ipData->SetDefaultGateway( temp );

						ipData->SetIpV4Enabled( TRUE );
						ipData->SetIpV6Enabled( FALSE );

						switch( pCurrentAdapter->Type ) {
							case MIB_IF_TYPE_OTHER:
								ipData->SetAdapterType( TEXT("Other") );
								break;

							case MIB_IF_TYPE_ETHERNET:
								ipData->SetAdapterType( TEXT("Ethernet") );
								break;
							case MIB_IF_TYPE_TOKENRING:
								ipData->SetAdapterType( TEXT("Token Ring") );
								break;

							case MIB_IF_TYPE_FDDI:
								ipData->SetAdapterType( TEXT("FDDI") );
								break;

							case MIB_IF_TYPE_PPP:
								ipData->SetAdapterType( TEXT("PPP") );
								break;

							case MIB_IF_TYPE_LOOPBACK:
								ipData->SetAdapterType( TEXT("Lookback") );
								break;

							case MIB_IF_TYPE_SLIP:
								ipData->SetAdapterType( TEXT("Slip") );
								break;

							default:
								ipData->SetAdapterType( TEXT("Unknown type") );
								break;
						}

						m_pAdapterInformation.push_back( ipData );

						pCurrentAdapter = pCurrentAdapter->Next;

					}

					while( pCurrentAdapter )
					{
						// create the first item to be added to the vector
						CIpInformation* ipData = new CIpInformation();

						CString temp;

						temp.Format( TEXT("%S"), pCurrentAdapter->AdapterName );
						ipData->SetAdapterName( temp );

						temp.Format( TEXT("%S"), pCurrentAdapter->Description );
						ipData->SetAdapterDescription( temp );
						
						CString* newTemp = new CString( pCurrentAdapter->IpAddressList.IpAddress.String );
						ipData->AddIpAddress( newTemp );
						
						temp.Format( TEXT("%S"), pCurrentAdapter->IpAddressList.IpMask.String );
						ipData->SetSubnet( temp );

						temp.Format( TEXT("%S"), pCurrentAdapter->GatewayList.IpAddress.String );
						ipData->SetDefaultGateway( temp );

						ipData->SetIpV4Enabled( TRUE );
						ipData->SetIpV6Enabled( FALSE );

						switch( pCurrentAdapter->Type ) {
							case MIB_IF_TYPE_OTHER:
								ipData->SetAdapterType( TEXT("Other") );
								break;

							case MIB_IF_TYPE_ETHERNET:
								ipData->SetAdapterType( TEXT("Ethernet") );
								break;

							case MIB_IF_TYPE_TOKENRING:
								ipData->SetAdapterType( TEXT("Token Ring") );
								break;

							case MIB_IF_TYPE_FDDI:
								ipData->SetAdapterType( TEXT("FDDI") );
								break;

							case MIB_IF_TYPE_PPP:
								ipData->SetAdapterType( TEXT("PPP") );
								break;

							case MIB_IF_TYPE_LOOPBACK:
								ipData->SetAdapterType( TEXT("Lookback") );
								break;

							case MIB_IF_TYPE_SLIP:
								ipData->SetAdapterType( TEXT("Slip") );
								break;

							default:
								ipData->SetAdapterType( TEXT("Unknown type") );
								break;
						}

						m_pAdapterInformation.push_back( ipData );
												
						pCurrentAdapter = pCurrentAdapter->Next;

					}
				}
			}
		}
	}
	catch( CException *ex )
	{
		CLogger::LogError( ex );
		delete ex;
	}
}

// loads the adapter information for any OS vista or higher, VISTA has all sorts of cool new IP shit so we have to do this in a seperate function
void CIPData::LoadVistaOrHigher()
{
}

CString CIPData::ConvertByteToString( BYTE *byIn, UINT nCount )
{
   CString strReturn, strByte;
   
   for (UINT n = 0; n < nCount; n++)
   {
       strByte.Format (_T("%02x"), byIn [n]);
       strReturn += strByte;

	   if( n != nCount - 1)
	   {
		   strReturn += TEXT(":");
	   }
   }

   return strReturn;

}

CString CIPData::ConvertToStatus( IF_OPER_STATUS status )
{
	AFX_MANAGE_STATE( AfxGetStaticModuleState( ) ); 

	CString returnStatus;
	
	switch( status )
	{
		case IfOperStatusUp:
			returnStatus.LoadString( IDS_Up );
			break;

		case IfOperStatusDown:
			returnStatus.LoadString( IDS_Down ); 
			break;

		case IfOperStatusTesting:
			returnStatus.LoadString( IDS_Testing );
			break;

		case IfOperStatusUnknown:
			returnStatus.LoadString( IDS_Unknown );
			break;

		case IfOperStatusDormant:
			returnStatus.LoadString( IDS_Dormant );
			break;

		case IfOperStatusNotPresent:
			returnStatus.LoadString( IDS_StatusNotPresent );
			break;

		case IfOperStatusLowerLayerDown:
			returnStatus.LoadString( IDS_LowerLayerDown );
			break;

		default:
			returnStatus.LoadString( IDS_Unknown );
			break;
	}


	return returnStatus;
}