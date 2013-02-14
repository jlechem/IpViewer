// IPViewerJPN.h : main header file for the IPViewerJPN DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CIPViewerJPNApp
// See IPViewerJPN.cpp for the implementation of this class
//

class CIPViewerJPNApp : public CWinApp
{
public:
	CIPViewerJPNApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
