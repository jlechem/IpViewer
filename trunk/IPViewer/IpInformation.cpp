/*
	Copyright 2009 Justin LeCheminant
*/

/*
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