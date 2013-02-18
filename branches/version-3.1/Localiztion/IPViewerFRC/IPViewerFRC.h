// IPViewerFRC.h : main header file for the IPViewerFRC DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CIPViewerFRCApp
// See IPViewerFRC.cpp for the implementation of this class
//

class CIPViewerFRCApp : public CWinApp
{
public:
	CIPViewerFRCApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
