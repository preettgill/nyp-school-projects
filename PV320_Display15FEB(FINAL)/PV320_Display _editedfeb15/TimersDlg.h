#include <afxwin.h>
#if !defined(AFX_TIMERSDLG_H__685EFA07_D0D9_43D7_81CA_998BB2D653C8__INCLUDED_)
#define AFX_TIMERSDLG_H__685EFA07_D0D9_43D7_81CA_998BB2D653C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TimersDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTimersDlg dialog

class CTimersDlg : public CDialog
{
// Construction
public:
	CTimersDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTimersDlg)
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
	CString	m_st;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimersDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTimersDlg)
	afx_msg void OnStoptimer();
	afx_msg void OnStarttime();
	afx_msg void OnExit();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_iCount;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMERSDLG_H__685EFA07_D0D9_43D7_81CA_998BB2D653C8__INCLUDED_)
