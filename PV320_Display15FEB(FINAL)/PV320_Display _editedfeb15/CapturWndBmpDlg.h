// CapturWndBmpDlg.h : header file
//

#if !defined(AFX_CAPTURWNDBMPDLG_H__820474AE_1EBA_4371_A671_638A124E0CEA__INCLUDED_)
#define AFX_CAPTURWNDBMPDLG_H__820474AE_1EBA_4371_A671_638A124E0CEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCapturWndBmpDlg dialog

class CPV320_DisplayDoc : public CDialog
{
// Construction
public:
	HANDLE DDBToDIB(CBitmap &bitmap, DWORD dwCompression, CPalette *pPal);
	BOOL WndToBmp(CDC *pDC, CString szFile);
	CCapturWndBmpDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCapturWndBmpDlg)
	enum { IDD = IDD_CAPTURWNDBMP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCapturWndBmpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCapturWndBmpDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonCapture();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAPTURWNDBMPDLG_H__820474AE_1EBA_4371_A671_638A124E0CEA__INCLUDED_)
