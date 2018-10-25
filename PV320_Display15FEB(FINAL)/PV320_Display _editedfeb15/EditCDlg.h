#include <afxwin.h>
//added

#if !defined(AFX_EDITCDLG_H__8CD19F91_595B_46CE_9920_48F8E622042D__INCLUDED_)
#define AFX_EDITCDLG_H__8CD19F91_595B_46CE_9920_48F8E622042D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditCDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditCDlg dialog

class CEditCDlg : public CDialog
{
// Construction
public:
	CEditCDlg(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CEditCDlg)
	enum { IDD = IDD_DIALOG2 };
	CButton	m_cStopTime;
	CButton	m_cStartTime;
	CString	m_sTime;
	CString	m_mCount;
	CString	m_hCount;
	CString	m_sCount;
	CString	m_stext;
	CString m_htext;
	CString	m_text;
	CString	m_text1;
	CString m_st;
	CString m_et;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnExit();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStarttime();
	afx_msg void OnStoptimer();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_iCount;
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITCDLG_H__8CD19F91_595B_46CE_9920_48F8E622042D__INCLUDED_)
