#if !defined(AFX_ADJUSTDIALOG_H__E891FA88_D961_4A62_9CE9_CD3737F8C753__INCLUDED_)
#define AFX_ADJUSTDIALOG_H__E891FA88_D961_4A62_9CE9_CD3737F8C753__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AdjustDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAdjustDialog dialog

class CAdjustDialog : public CDialog
{
// Construction
public:
	CAdjustDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAdjustDialog)
	enum { IDD = IDD_ADJUSTDIALOG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdjustDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAdjustDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADJUSTDIALOG_H__E891FA88_D961_4A62_9CE9_CD3737F8C753__INCLUDED_)
