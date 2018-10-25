// PV320_Display.h : main header file for the PV320_DISPLAY application
//

#if !defined(AFX_PV320_DISPLAY_H__0344F87C_C625_4883_B378_9CABD6D595F5__INCLUDED_)
#define AFX_PV320_DISPLAY_H__0344F87C_C625_4883_B378_9CABD6D595F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "EditDlg.h"	// Added by ClassView
#include "EditCDlg.h"
#include "ColourChangerDlg.h"
#include "Threshold.h"
#include "TimersDlg.h"	// Added by ClassView
#include "ColorDlg.h"	// Added by ClassView
/////////////////////////////////////////////////////////////////////////////
// CPV320_DisplayApp:
// See PV320_Display.cpp for the implementation of this class
//



class CPV320_DisplayApp : public CWinApp
{
public:
	
	CPV320_DisplayApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPV320_DisplayApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPV320_DisplayApp)
	afx_msg void OnAppAbout();
	afx_msg void OnEditAdjust();
	afx_msg void OnEditColour();
	afx_msg void OnAdjustTest();
	afx_msg void OnAdjustAdjustthresholdsetting();
	afx_msg void OnFileOpen();
	afx_msg void OnAdjustCrosshaircolorchanger();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CColorDlg m_dColorDlg;
	CEditDlg m_dEditDlg;
	CEditCDlg m_dEditCDlg;
	CColourChangerDlg m_dColourChangerDlg;
	CThreshold m_dThresholdDlg;
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PV320_DISPLAY_H__0344F87C_C625_4883_B378_9CABD6D595F5__INCLUDED_)
