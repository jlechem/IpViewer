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
	try
	{
		if( !m_pRegistry )
		{
			m_pRegistry = new CSettingsStore( FALSE, FALSE );
		}

		if( m_pRegistry )
		{
			CString key;

			key.LoadString( IDS_REG_PATH );

			// this opens the main root key or creates it if it doesn't exist
			if( m_pRegistry->CreateKey( key ))
			{
				key.LoadString( IDS_TICK_KEY );

				// try and read the values, if it's not there then we need to write it
				if( !m_pRegistry->Read( key, _tick ) )
				{
					m_pRegistry->Write( key, _tick );
				}

				key.LoadString( IDS_MINTRAY_KEY );
	
				if( !m_pRegistry->Read( key,  _minToTray) )
				{
					m_pRegistry->Write( key, _minToTray );
				}

				key.LoadString( IDS_CLOSETRAY_KEY);

				if( !m_pRegistry->Read( key, _closeToTray ) )
				{
					m_pRegistry->Write( key, _closeToTray );
				}

				key.LoadString( IDS_ONTOP_KEY  );

				if( !m_pRegistry->Read( key, _onTop ) )
				{
					m_pRegistry->Write( key, _onTop );
				}

				key.LoadString( IDS_SELECTED_INDEX_KEY );

				if( !m_pRegistry->Read( key, _selectedIndex ) )
				{
					m_pRegistry->Write( key, _selectedIndex );
				}

				key.LoadString( IDS_START_MIN_KEY );

				if( !m_pRegistry->Read( key, _startToTray ) )
				{
					m_pRegistry->Write( key, _startToTray );
				}
				
				key.LoadString( IDS_CHECK_EXTERNAL_KEY );

				if( !m_pRegistry->Read( key, _checkExternalIp ) )
				{
					m_pRegistry->Write( key, _checkExternalIp );
				}
				
				key.LoadString( IDS_ENABLE_LOGGING );

				if( !m_pRegistry->Read( key, _loggingEnabled ) )
				{
					m_pRegistry->Write( key, _loggingEnabled );	
				}

				key.LoadString( IDS_LOG_INTERNAL );

				if( !m_pRegistry->Read( key, _logInternalIp ) )
				{
					m_pRegistry->Write( key, _logInternalIp );
				}

				key.LoadString( IDS_LOG_EXTERNAL );

				if( !m_pRegistry->Read( key, _logExternalIp ) )
				{
					m_pRegistry->Write( key, _logExternalIp );
				}

				key.LoadString( IDS_LOG_MAC );

				if( !m_pRegistry->Read( key, _logMacAddress ) )
				{
					m_pRegistry->Write( key, _logMacAddress );
				}

				key.LoadString( IDS_LOG_HOST );

				if( !m_pRegistry->Read( key, _logHostName ) )
				{
					m_pRegistry->Write( key, _logHostName );
				}

				key.LoadString( IDS_LOG_INTERVAL );

				if( !m_pRegistry->Read( key, _loggingInterval ) )
				{
					m_pRegistry->Write( key, _loggingInterval );
				}

				key.LoadString(IDS_ADAPTER_INDEX );

				if( !m_pRegistry->Read( key, _selectedAdapterIndex ) )
				{
					m_pRegistry->Write( key, _selectedAdapterIndex );
				}

				key.LoadString(IDS_ADDRESS_INDEX );

				if( !m_pRegistry->Read( key, _selectedAddressIndex ) )
				{
					m_pRegistry->Write( key, _selectedAddressIndex );
				}

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
	_selectedAdapterIndex = 0;
	_selectedAddressIndex = 0;
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
			key.LoadString( IDS_REG_PATH );
			m_pRegistry->CreateKey( key );
		}

		// this opens the main root key or creates it if it doesn't exist
		key.LoadString( IDS_TICK_KEY );
		m_pRegistry->Write( key, _tick );
		
		// we then move on and write our settings to the registry
		key.LoadString( IDS_MINTRAY_KEY );
		m_pRegistry->Write( key, _minToTray );
		
		key.LoadString( IDS_CLOSETRAY_KEY);
		m_pRegistry->Write( key, _closeToTray );
		
		key.LoadString( IDS_SELECTED_INDEX_KEY );
		m_pRegistry->Write( key, _selectedIndex );
		
		key.LoadString( IDS_ONTOP_KEY  );
		m_pRegistry->Write( key, _onTop );
		
		key.LoadString( IDS_START_MIN_KEY );
		m_pRegistry->Write( key, _startToTray );	

		key.LoadString( IDS_CHECK_EXTERNAL_KEY );
		m_pRegistry->Write( key, _checkExternalIp );	

		key.LoadString( IDS_ENABLE_LOGGING );
		m_pRegistry->Write( key, _loggingEnabled );	

		key.LoadString( IDS_LOG_INTERNAL );
		m_pRegistry->Write( key, _logInternalIp );

		key.LoadString( IDS_LOG_EXTERNAL );
		m_pRegistry->Write( key, _logExternalIp );

		key.LoadString( IDS_LOG_MAC );
		m_pRegistry->Write( key, _logMacAddress );

		key.LoadString( IDS_LOG_HOST );
		m_pRegistry->Write( key, _logHostName );

		key.LoadString( IDS_LOG_INTERVAL );
		m_pRegistry->Write( key, _loggingInterval );

		key.LoadString( IDS_ADAPTER_INDEX );
		m_pRegistry->Write( key, _selectedAdapterIndex );

		key.LoadString( IDS_ADDRESS_INDEX );
		m_pRegistry->Write( key, _selectedAddressIndex );

		result = true;

	}
	catch( CException* ex )
	{
		CLogger::LogError( ex );
		delete ex;
		result = false;
	}

	return result;

}