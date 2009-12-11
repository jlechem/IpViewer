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

class CIPSettings
{
public:
	CIPSettings(void);
	~CIPSettings(void);

	int GetShowItemIndex() { return _selectedIndex; }
	int GetTick() { return _tick; }
	bool GetMinimizeToTray() { return _minToTray; }
	bool GetCloseToTray() { return _closeToTray; }
	bool GetOnTop() { return _onTop; }
	bool GetStartMinimized() { return _startToTray; }

	void SetOnTOp( bool value ) { _onTop = value; }
	void SetTick( int value ) { _tick = value; }
	void SetMinimizeToTray( bool value ) { _minToTray = value; }
	void SetCloseToTray( bool value ) { _closeToTray = value; }
	void SetShowItemIndex( int value ) { _selectedIndex = value; }
	void SetStartInTray( bool value ) { _startToTray = value; }

	bool Save();

private:
	int _tick;
	int _selectedIndex;
	bool _minToTray;
	bool _closeToTray;
	bool _onTop;
	bool _startToTray;

	CSettingsStore* m_pRegistry;

	void Load();
	void Reset();
	
};
