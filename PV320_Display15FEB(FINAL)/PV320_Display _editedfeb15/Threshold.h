#if !defined(AFX_THRESHOLD_H__243F337E_171E_4538_8C31_C4F63271DD15__INCLUDED_)
#define AFX_THRESHOLD_H__243F337E_171E_4538_8C31_C4F63271DD15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Threshold.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CThreshold dialog

class CThreshold : public CDialog
{
// Construction
public:
	CThreshold(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CThreshold)
	enum { IDD = IDD_DIALOG4 };
	int		m_iTValue;
	CString	m_text1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreshold)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CThreshold)
	virtual void OnCancel();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THRESHOLD_H__243F337E_171E_4538_8C31_C4F63271DD15__INCLUDED_)
