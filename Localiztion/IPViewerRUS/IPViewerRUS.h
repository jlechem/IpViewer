// IPViewerRUS.h : main header file for the IPViewerRUS DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CIPViewerRUSApp
// See IPViewerRUS.cpp for the implementation of this class
//

class CIPViewerRUSApp : public CWinApp
{
public:
	CIPViewerRUSApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
