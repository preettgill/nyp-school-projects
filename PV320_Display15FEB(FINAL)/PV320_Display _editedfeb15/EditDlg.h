#if !defined(AFX_EDITDLG_H__5477A426_91C7_40AE_A3BF_421D9E1DC4B0__INCLUDED_)
#define AFX_EDITDLG_H__5477A426_91C7_40AE_A3BF_421D9E1DC4B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditDlg.h : header file
//
extern int START;
/////////////////////////////////////////////////////////////////////////////
// CEditDlg dialog

class CEditDlg : public CDialog
{
// Construction
public:
	CEditDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditDlg)
	enum { IDD = IDD_DIALOG1 };
//	int		m_iEValue;
	int		m_iSValue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITDLG_H__5477A426_91C7_40AE_A3BF_421D9E1DC4B0__INCLUDED_)
