// CapturWndBmp.h : main header file for the CAPTURWNDBMP application
//

#if !defined(AFX_CAPTURWNDBMP_H__AC079A03_1D86_438B_9572_3848108B32F0__INCLUDED_)
#define AFX_CAPTURWNDBMP_H__AC079A03_1D86_438B_9572_3848108B32F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCapturWndBmpApp:
// See CapturWndBmp.cpp for the implementation of this class
//

class CPV320_DisplayDoc : public CWinApp
{
public:
	CPV320_DisplayDoc();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCapturWndBmpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCapturWndBmpApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAPTURWNDBMP_H__AC079A03_1D86_438B_9572_3848108B32F0__INCLUDED_)
