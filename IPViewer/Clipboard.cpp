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