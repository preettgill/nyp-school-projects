#if !defined(AFX_COLOURCHANGERDLG_H__C9510CE3_5790_4FBA_992F_F5ECE1C6B1C1__INCLUDED_)
#define AFX_COLOURCHANGERDLG_H__C9510CE3_5790_4FBA_992F_F5ECE1C6B1C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColourChangerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColourChangerDlg dialog

class CColourChangerDlg : public CDialog
{
// Construction
public:
	CColourChangerDlg(CWnd* pParent = NULL);   // standard constructor
public:
HANDLE DDBToDIB(CBitmap &bitmap, DWORD dwCompression, CPalette *pPal);
BOOL WndToBmp(CDC *pDC, CString szFile);

// Dialog Data
	//{{AFX_DATA(CColourChangerDlg)
	enum { IDD = IDD_DIALOG3 };

	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColourChangerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CColourChangerDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLOURCHANGERDLG_H__C9510CE3_5790_4FBA_992F_F5ECE1C6B1C1__INCLUDED_)
