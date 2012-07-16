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

#include "StdAfx.h"
#include "Clipboard.h"

CClipboard::CClipboard(void)
{
}

CClipboard::~CClipboard(void)
{
}

void CClipboard::Clear( HWND hWnd )
{
	if ( !OpenClipboard( hWnd  ) )
	{
		return;
	}
	// Remove the current Clipboard contents
	if( !EmptyClipboard() )
	{
		CloseClipboard();
		return;
	}
	
	// close it
	CloseClipboard();


}

BOOL CClipboard::SetData( CString data, HWND hWnd )
{
	CClipboard::Clear();

	if( !OpenClipboard( hWnd ) )
	{
		return FALSE;
	}
	
	// Remove the current Clipboard contents
	if( !EmptyClipboard() )
	{
		CloseClipboard();
		return FALSE;
	}

	SIZE_T copySize = (data.GetLength() + 1) * sizeof(TCHAR);
	HGLOBAL hResult = GlobalAlloc( GMEM_MOVEABLE, copySize );

	if( hResult == NULL )
	{
		CloseClipboard();
		return FALSE;
	}

	LPTSTR lptstrCopy = (LPTSTR)GlobalLock(hResult);
	wcscpy_s( lptstrCopy, copySize, data );
	GlobalUnlock( hResult ); 

	// set the clipboard data
	if ( SetClipboardData( CF_UNICODETEXT, hResult ) == NULL )
	{
		CloseClipboard();
		return FALSE;
	}
	
	// close it
	CloseClipboard();

	return TRUE;

}