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
		// TODO: do something with the exception
		/*CString error;
		ex->GetErrorMessage( error.GetBuffer(0), 255);*/
		delete ex;
		this->Reset();
		delete m_pRegistry;
	}
}

void CIPSettings::Reset()
{
	// set some default values and set our pointer to NULL so
	// we don't leak
	_tick = 30;
	_onTop = false;
	_minToTray = true;
	_closeToTray = true;
	_selectedIndex = 0;
	m_pRegistry = NULL;

}

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
		}//end if


		// this opens the main root key or creates it if it doesn't exist
		key.LoadStringW( IDS_TICK_KEY );
		m_pRegistry->Write( key, (int)_tick );
		
		key.LoadStringW( IDS_MINTRAY_KEY );
		m_pRegistry->Write( key, (BOOL)_minToTray );
		
		key.LoadStringW( IDS_CLOSETRAY_KEY);
		m_pRegistry->Write( key, (BOOL)_closeToTray );
		
		key.LoadStringW( IDS_SELECTED_INDEX_KEY );
		m_pRegistry->Write( key, (int)_selectedIndex );
		
		key.LoadStringW( IDS_ONTOP_KEY  );
		m_pRegistry->Write( key, (BOOL)_onTop );
		
		key.LoadStringW( IDS_START_MIN_KEY );
		m_pRegistry->Write( key, (BOOL)_startToTray );	

		key.LoadStringW( IDS_CHECK_EXTERNAL_KEY );
		m_pRegistry->Write( key, (BOOL)_checkExternalIp );	

		result = true;

	}
	catch( CException* ex )
	{
		// TODO: do something with the exception
		/*CString error;
		ex->GetErrorMessage( error.GetBuffer(0), 255);*/
		delete ex;
	}

	return result;

}