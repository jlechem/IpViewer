// IPViewerDEU.h : main header file for the IPViewerDEU DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CIPViewerDEUApp
// See IPViewerDEU.cpp for the implementation of this class
//

class CIPViewerDEUApp : public CWinApp
{
public:
	CIPViewerDEUApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
