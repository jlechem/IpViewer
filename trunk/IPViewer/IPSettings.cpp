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

#include "stdafx.h"
#include "IPSettings.h"
#include "IPViewer.h"

CIPSettings::CIPSettings(void)
{
	this->Reset();
	this->Load();
}

CIPSettings::~CIPSettings(void)
{
}

// Loads the IP Settings
void CIPSettings::Load()
{
	DWORD newWord;
	
	try
	{
		if( !m_pRegistry )
		{
			m_pRegistry = new CSettingsStore( FALSE, FALSE );
		}

		if( m_pRegistry )
		{
			CString key;

			key.LoadStringW( IDS_REG_PATH );

			// this opens the main root key or creates it if it doesn't exist
			if( m_pRegistry->CreateKey( key ))
			{
				key.LoadStringW( IDS_TICK_KEY );

				// try and read the values, if it's not there then we need to write it
				if( !m_pRegistry->Read( key, (int)_tick ) )
				{
					m_pRegistry->Write( key, (int)_tick );
				}

				key.LoadStringW( IDS_MINTRAY_KEY );
	
				newWord = _minToTray;

				if( !m_pRegistry->Read( key,  newWord) )
				{
					m_pRegistry->Write( key, (BOOL)_minToTray );
				}

				_minToTray = newWord;

				key.LoadStringW( IDS_CLOSETRAY_KEY);

				newWord = _closeToTray;

				if( !m_pRegistry->Read( key, newWord ) )
				{
					m_pRegistry->Write( key, (BOOL)_closeToTray );
				}

				_closeToTray = newWord;

				key.LoadStringW( IDS_ONTOP_KEY  );

				newWord = _onTop;

				if( !m_pRegistry->Read( key, newWord ) )
				{
					m_pRegistry->Write( key, (BOOL)_onTop );
				}

				_onTop = newWord;

				key.LoadStringW( IDS_SELECTED_INDEX_KEY );

				if( !m_pRegistry->Read( key, (int)_selectedIndex ) )
				{
					m_pRegistry->Write( key, (int)_selectedIndex );
				}

				newWord = _startToTray;

				key.LoadStringW( IDS_START_MIN_KEY );

				if( !m_pRegistry->Read( key, newWord ) )
				{
					m_pRegistry->Write( key, (BOOL)_startToTray );
				}
				
				_startToTray = newWord;

				key.LoadStringW( IDS_CHECK_EXTERNAL_KEY );

				if( !m_pRegistry->Read( key, newWord ) )
				{
					m_pRegistry->Write( key, (BOOL)_checkExternalIp );
				}
				
				_checkExternalIp = newWord;

				key.LoadStringW( IDS_ENABLE_LOGGING );

				newWord = _loggingEnabled;

				if( !m_pRegistry->Read( key, (BOOL)_loggingEnabled ) )
				{
					m_pRegistry->Write( key, (BOOL)_loggingEnabled );	
				}

				_loggingEnabled = newWord;

				key.LoadStringW( IDS_LOG_INTERNAL );

				newWord = _logInternalIp;

				if( !m_pRegistry->Read( key, (BOOL)_logInternalIp ) )
				{
					m_pRegistry->Write( key, (BOOL)_logInternalIp );
				}

				_logInternalIp = newWord;

				key.LoadStringW( IDS_LOG_EXTERNAL );

				newWord = _logExternalIp;

				if( !m_pRegistry->Read( key, (BOOL)_logExternalIp ) )
				{
					m_pRegistry->Write( key, (BOOL)_logExternalIp );
				}

				_logExternalIp = newWord;

				key.LoadStringW( IDS_LOG_MAC );

				newWord = _logMacAddress;

				if( !m_pRegistry->Read( key, (BOOL)_logMacAddress ) )
				{
					m_pRegistry->Write( key, (BOOL)_logMacAddress );
				}

				_logMacAddress = newWord;

				key.LoadStringW( IDS_LOG_HOST );

				newWord = _logHostName;

				if( !m_pRegistry->Read( key, (BOOL)_logHostName ) )
				{
					m_pRegistry->Write( key, (BOOL)_logHostName );
				}

				_logHostName = newWord;

				key.LoadStringW( IDS_LOG_INTERVAL );

				newWord = _loggingInterval;

				if( !m_pRegistry->Read( key, (INT)_loggingInterval ) )
				{
					m_pRegistry->Write( key, (INT)_loggingInterval );
				}

				_loggingInterval = newWord;

				key.LoadStringW( IDS_LOG_FILENAME );

				newWord = atol((char*)(LPCTSTR)_logFileName);

				if( !m_pRegistry->Read( key, _logFileName ) )
				{
					m_pRegistry->Write( key, _logFileName );
				}

				_logFileName.Format( TEXT("%s"), newWord );

				key.LoadStringW( IDS_LOG_EXTENSION );

				newWord = atol((char*)(LPCTSTR)_logFileExtension);
				
				if( !m_pRegistry->Read( key, _logFileExtension ) )
				{
					m_pRegistry->Write( key, _logFileExtension );
				}

				_logFileExtension.Format( TEXT("%s"), newWord );

			}
			else
			{
				throw new CInvalidArgException( FALSE, IDS_REG_ERROR );
			}//end else
		}//end if
		else
		{
			throw new CInvalidArgException( FALSE, IDS_REG_ERROR );
		}//end else
	}//end if
	catch( CException* ex )
	{
		CLogger::LogError( ex );
		
		delete ex;

		this->Reset();
		
		delete m_pRegistry;

	}
}

// Resets the IP Settings
void CIPSettings::Reset()
{
	// set some default values and set our pointer to NULL so
	// we don't leak
	_tick = 30;
	_onTop = false;
	_minToTray = true;
	_closeToTray = true;
	_selectedIndex = 0;
	_loggingEnabled = false;
	_logInternalIp = false;
	_logExternalIp = false;
	_logHostName = false;
	_logMacAddress = false;
	_loggingInterval = 360;
	_logFileName = TEXT("IP_LOGS");
	_logFileExtension = TEXT("Text");

	m_pRegistry = NULL;

}

// Saves the IP Settings
BOOL CIPSettings::Save()
{
	BOOL result = false;

	CString key;

	try
	{
		// if we're null we need to open a new pointer to the write area
		if( !m_pRegistry )
		{
			m_pRegistry = new CSettingsStore( FALSE, FALSE );
			key.LoadStringW( IDS_REG_PATH );
			m_pRegistry->CreateKey( key );
		}

		// this opens the main root key or creates it if it doesn't exist
		key.LoadStringW( IDS_TICK_KEY );
		m_pRegistry->Write( key, (int)_tick );
		
		// we then move on and write our settings to the registry
		key.LoadStringW( IDS_MINTRAY_KEY );
		m_pRegistry->Write( key, (BOOL)_minToTray );
		
		key.LoadStringW( IDS_CLOSETRAY_KEY);
		m_pRegistry->Write( key, (BOOL)_closeToTray );
		
		key.LoadStringW( IDS_SELECTED_INDEX_KEY );
		m_pRegistry->Write( key, (INT)_selectedIndex );
		
		key.LoadStringW( IDS_ONTOP_KEY  );
		m_pRegistry->Write( key, (BOOL)_onTop );
		
		key.LoadStringW( IDS_START_MIN_KEY );
		m_pRegistry->Write( key, (BOOL)_startToTray );	

		key.LoadStringW( IDS_CHECK_EXTERNAL_KEY );
		m_pRegistry->Write( key, (BOOL)_checkExternalIp );	

		key.LoadStringW( IDS_ENABLE_LOGGING );
		m_pRegistry->Write( key, (BOOL)_loggingEnabled );	

		key.LoadStringW( IDS_LOG_INTERNAL );
		m_pRegistry->Write( key, (BOOL)_logInternalIp );

		key.LoadStringW( IDS_LOG_EXTERNAL );
		m_pRegistry->Write( key, (BOOL)_logExternalIp );

		key.LoadStringW( IDS_LOG_MAC );
		m_pRegistry->Write( key, (BOOL)_logMacAddress );

		key.LoadStringW( IDS_LOG_HOST );
		m_pRegistry->Write( key, (BOOL)_logHostName );

		key.LoadStringW( IDS_LOG_INTERVAL );
		m_pRegistry->Write( key, (INT)_loggingInterval );

		key.LoadStringW( IDS_LOG_FILENAME );
		DWORD word = _wtoi(_logFileName);
		m_pRegistry->Write( key, word );

		key.LoadStringW( IDS_LOG_EXTENSION );
		word = _wtoi(_logFileExtension);
		m_pRegistry->Write( key, word );

		result = true;

	}
	catch( CException* ex )
	{
		CLogger::LogError( ex );
		delete ex;
	}

	return result;

}