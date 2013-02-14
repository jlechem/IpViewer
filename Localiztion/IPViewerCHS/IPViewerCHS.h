// IPViewerCHS.h : main header file for the IPViewerCHS DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CIPViewerCHSApp
// See IPViewerCHS.cpp for the implementation of this class
//

class CIPViewerCHSApp : public CWinApp
{
public:
	CIPViewerCHSApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
