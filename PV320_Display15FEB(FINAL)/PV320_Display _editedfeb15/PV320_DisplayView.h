// PV320_DisplayView.h : interface of the CPV320_DisplayView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PV320_DISPLAYVIEW_H__C3880EC6_1F66_4FD3_A1A2_CC4EF00557C9__INCLUDED_)
#define AFX_PV320_DISPLAYVIEW_H__C3880EC6_1F66_4FD3_A1A2_CC4EF00557C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DIB.h"


class CPV320_DisplayView : public CView
{
protected: // create from serialization only
	CPV320_DisplayView();
	DECLARE_DYNCREATE(CPV320_DisplayView)

// Attributes
public:
	CPV320_DisplayDoc* GetDocument();
	//CPV320_DisplayView* GetOnEditAdjust();
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPV320_DisplayView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPV320_DisplayView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
    BITMAPINFO * m_pBitmapInfo;

// Generated message map functions
protected:
	//{{AFX_MSG(CPV320_DisplayView)
	afx_msg BOOL OnEditAdjust();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnAdjustAdjustthresholdsetting();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnAdjustCrosshaircolorchanger();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

#ifndef _DEBUG  // debug version in PV320_DisplayView.cpp
inline CPV320_DisplayDoc* CPV320_DisplayView::GetDocument()
   { return (CPV320_DisplayDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PV320_DISPLAYVIEW_H__C3880EC6_1F66_4FD3_A1A2_CC4EF00557C9__INCLUDED_)
