#include "StdAfx.h"
#include "IpInformation.h"


CIpInformation::CIpInformation(void)
{
	 m_isIpV4 = FALSE;
	 m_isIpV6 = FALSE;

	 m_pIpAddresses = new vector<CString*>();

}


CIpInformation::~CIpInformation(void)
{
}


void CIpInformation::AddIpAddress( CString* newIpAddress )
{
	m_pIpAddresses->push_back( newIpAddress );
}

void CIpInformation::ClearIpAddresses()
{
	m_pIpAddresses->clear();
}