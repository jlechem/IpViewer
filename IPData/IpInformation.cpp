#include "StdAfx.h"
#include "IpInformation.h"


CIpInformation::CIpInformation(void)
{
	 m_isIpV4 = FALSE;
	 m_isIpV6 = FALSE;
}


CIpInformation::~CIpInformation(void)
{
}


void CIpInformation::AddIpAddress( CString* newIpAddress )
{
	m_pIpAddresses.push_back( newIpAddress );
}

void CIpInformation::ClearIpAddresses()
{
	m_pIpAddresses.clear();
}