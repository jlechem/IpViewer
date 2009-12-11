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
