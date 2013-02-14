// IPViewerENU.h : main header file for the IPViewerENU DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CIPViewerENUApp
// See IPViewerENU.cpp for the implementation of this class
//

class CIPViewerENUApp : public CWinApp
{
public:
	CIPViewerENUApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
