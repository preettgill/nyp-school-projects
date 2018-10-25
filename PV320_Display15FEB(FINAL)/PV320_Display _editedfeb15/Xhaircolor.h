#if !defined(AFX_XHAIRCOLOR_H__63DFBDF8_85DC_4407_8023_112A22D5879B__INCLUDED_)
#define AFX_XHAIRCOLOR_H__63DFBDF8_85DC_4407_8023_112A22D5879B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Xhaircolor.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CXhaircolor dialog

class CXhaircolor : public CDialog
{
// Construction
public:
	CXhaircolor(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CXhaircolor)
	enum { IDD = IDD_DIALOG5 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXhaircolor)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CXhaircolor)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XHAIRCOLOR_H__63DFBDF8_85DC_4407_8023_112A22D5879B__INCLUDED_)
