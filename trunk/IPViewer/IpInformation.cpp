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

#pragma once

#include "StdAfx.h"
#include "IpInformation.h"
#include "IPViewer.h"

CIpInformation::CIpInformation(void)
{
	m_pIpData =  new CIPData();
	this->LoadIpInformation();
	this->LoadMAC();
}

CIpInformation::~CIpInformation(void)
{
	delete m_pIpData;
}
// Loads the ip information for the machine into the class
void CIpInformation::LoadIpInformation(void)
{	
	m_strIpAddress = m_pIpData->GetIpAddress();
	m_strHostName = m_pIpData->GetHostName();
	m_strExternalIpAddress = m_pIpData->GetExternalIpAddress();
}

// updates our IP information
void CIpInformation::Update(void)
{
	this->LoadIpInformation();
}

void CIpInformation::LoadMAC( void )
{
	m_strMacAddress = m_pIpData->GetMacAddress();
}

void CIpInformation::LoadSubnet( void )
{
	m_strSubnet = m_pIpData->GetSubNet();
}