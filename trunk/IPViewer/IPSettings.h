/*
	Copyright 2011 Justin LeCheminant

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

class CIPSettings
{
public:
	CIPSettings(void);
	~CIPSettings(void);

	int GetShowItemIndex() { return _selectedIndex; }
	int GetTick() { return _tick; }
	BOOL GetMinimizeToTray() { return _minToTray; }
	BOOL GetCloseToTray() { return _closeToTray; }
	BOOL GetOnTop() { return _onTop; }
	BOOL GetStartMinimized() { return _startToTray; }
	BOOL GetCheckExternalIp() { return _checkExternalIp; }

	void SetOnTOp( BOOL value ) { _onTop = value; }
	void SetTick( int value ) { _tick = value; }
	void SetMinimizeToTray( BOOL value ) { _minToTray = value; }
	void SetCloseToTray( BOOL value ) { _closeToTray = value; }
	void SetShowItemIndex( int value ) { _selectedIndex = value; }
	void SetStartInTray( BOOL value ) { _startToTray = value; }
	void SetCheckExternalIp( BOOL value ) { _checkExternalIp = value; }

	BOOL Save();

private:
	int _tick;
	int _selectedIndex;
	BOOL _minToTray;
	BOOL _closeToTray;
	BOOL _onTop;
	BOOL _startToTray;
	BOOL _checkExternalIp;

	CSettingsStore* m_pRegistry;

	void Load();
	void Reset();
	
};
