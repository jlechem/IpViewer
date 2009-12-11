#pragma once

#include "StdAfx.h"

class CClipboard
{
public:
	CClipboard(void);
	~CClipboard(void);

	static void Clear( HWND = NULL );
	static BOOL SetData( CString, HWND = NULL );
	
};
