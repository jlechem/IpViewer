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

#pragma once

#include "..\Logger\Logger.h"

class CIPSettings
{
public:
	CIPSettings(void);
	~CIPSettings(void);

	// get methods for internal members
	INT GetShowItemIndex() { return _selectedIndex; }
	INT GetTick() { return _tick; }
	INT GetLoggingInterval() { return _loggingInterval; }

	BOOL GetMinimizeToTray() { return _minToTray; }
	BOOL GetCloseToTray() { return _closeToTray; }
	BOOL GetOnTop() { return _onTop; }
	BOOL GetStartMinimized() { return _startToTray; }
	BOOL GetCheckExternalIp() { return _checkExternalIp; }
	BOOL GetLoggingEnabled() { return _loggingEnabled; }
	BOOL GetLogInternalIp() { return _logInternalIp; }
	BOOL GetLogExternalIp() { return _logExternalIp; }
	BOOL GetLogMacAddress() { return _logMacAddress; }
	BOOL GetLogHostName() { return _logHostName; }
	
	INT GetAdapterIndex() { return _selectedAdapterIndex; }
	INT GetAddressIndex() { return _selectedAddressIndex; }

	CString GetLogFileName() { return _logFileName; }
	
	// set methods for internal memebers
	void SetTick( INT value ) { _tick = value; }
	void SetShowItemIndex( INT value ) { _selectedIndex = value; }
	void SetLoggingInterval( INT value ) { _loggingInterval = value; }

	void SetMinimizeToTray( BOOL value ) { _minToTray = value; }
	void SetCloseToTray( BOOL value ) { _closeToTray = value; }
	void SetOnTOp( BOOL value ) { _onTop = value; }
	void SetStartInTray( BOOL value ) { _startToTray = value; }
	void SetCheckExternalIp( BOOL value ) { _checkExternalIp = value; }
	
	void SetLogFileName( CString value ) { _logFileName = value; }

	void SetLoggingEnabled( BOOL value ) { _loggingEnabled = value; }
	void SetLogInternalIp( BOOL value ) { _logInternalIp = value; }
	void SetLogExternalIp( BOOL value ) { _logExternalIp = value; }
	void SetLogMacAddress( BOOL value ) { _logMacAddress = value; }
	void SetLogHostName( BOOL value ) { _logHostName = value; }
	void SetAdapterIndex( INT value ) { _selectedAdapterIndex = value; }
	void SetAddressIndex( INT value ) { _selectedAddressIndex = value; }

	BOOL Save();

private:
	INT _tick;
	INT _selectedIndex;
	INT _loggingInterval;
	INT _selectedAdapterIndex;
	INT _selectedAddressIndex;

	BOOL _minToTray;
	BOOL _closeToTray;
	BOOL _onTop;
	BOOL _startToTray;
	BOOL _checkExternalIp;
	BOOL _loggingEnabled;
	BOOL _logInternalIp;
	BOOL _logExternalIp;
	BOOL _logMacAddress;
	BOOL _logHostName;

	CString _logFileName;
	
	CSettingsStore* m_pRegistry;

	void Load();
	void Reset();
	
};
