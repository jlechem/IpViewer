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
#include "..\IPData\IPData.h"

class CIpInformation
{
public:
	CIpInformation(void);
	
	
	~CIpInformation(void);

	CString GetMask() { return m_strMask; };
	CString GetIpAddress() { return m_strIpAddress; };
	CString GetHostName() { return m_strHostName; };
	CString GetMacAddress() { return m_strMacAddress; };
	CString GetAdapterDescription() { return m_strAdapterDescription; }
	CString GetExternalIpAddress() { return m_strExternalIpAddress; }

	void Update();

private:
	CString m_strIpAddress;
	CString m_strHostName;
	CString m_strMacAddress;
	CString m_strExternalIpAddress;
	CString m_strAdapterDescription;
	CString m_strMask;
	
	// Loads the ip information for the machine into the class
	void LoadIpInformation( void );
	void LoadMAC( void );

};
