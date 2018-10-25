// PV320_DisplayDoc.h : interface of the CPV320_DisplayDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PV320_DISPLAYDOC_H__07ECEB52_4190_4361_A74B_7F43F1B3C62D__INCLUDED_)
#define AFX_PV320_DISPLAYDOC_H__07ECEB52_4190_4361_A74B_7F43F1B3C62D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPV320_DisplayDoc : public CDocument
{
protected: // create from serialization only
	CPV320_DisplayDoc();
	DECLARE_DYNCREATE(CPV320_DisplayDoc)

// Attributes
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPV320_DisplayDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL bStopFlag;
	BOOL bLive;
	BOOL bDataValid;
	int m_SizeY;
	int m_SizeX;
	void *m_pCurrent;
	int Init_PV320();
	void DoEvent();
	virtual ~CPV320_DisplayDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;

#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPV320_DisplayDoc)
	afx_msg void OnStart();
	afx_msg int OnCapture();
	afx_msg void OnAppExit();
	afx_msg void OnLive();
	afx_msg int OnSave();
	afx_msg void OnTemp();
	//}}AFX_MSG
/*public:
	afx_msg int OnSave();*/

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PV320_DISPLAYDOC_H__07ECEB52_4190_4361_A74B_7F43F1B3C62D__INCLUDED_)
