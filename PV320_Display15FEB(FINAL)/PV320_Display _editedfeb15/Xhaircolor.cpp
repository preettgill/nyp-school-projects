// Xhaircolor.cpp : implementation file
//

#include "stdafx.h"
#include "PV320_Display.h"
#include "Xhaircolor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXhaircolor dialog


CXhaircolor::CXhaircolor(CWnd* pParent /*=NULL*/)
	: CDialog(CXhaircolor::IDD, pParent)
{
	//{{AFX_DATA_INIT(CXhaircolor)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CXhaircolor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CXhaircolor)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CXhaircolor, CDialog)
	//{{AFX_MSG_MAP(CXhaircolor)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXhaircolor message handlers
