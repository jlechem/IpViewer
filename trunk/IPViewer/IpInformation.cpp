#pragma once

#include "StdAfx.h"
#include "IpInformation.h"
#include "IPViewer.h"

CIpInformation::CIpInformation(void)
{
	this->LoadIpInformation();
	this->LoadMAC();
}

CIpInformation::~CIpInformation(void)
{
}
// Loads the ip information for the machine into the class
void CIpInformation::LoadIpInformation(void)
{	
	m_strIpAddress = CIPData::LoadIpAddress();
	m_strHostName = CIPData::LoadHostName();
}

// updates our IP information
void CIpInformation::Update(void)
{
	this->LoadIpInformation();
}

void CIpInformation::LoadMAC( void )
{
	m_strMacAddress = CIPData::LoadMacAddress();
}