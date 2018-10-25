// AdjustDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PV320_Display.h"
#include "AdjustDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdjustDialog dialog


CAdjustDialog::CAdjustDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CAdjustDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdjustDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAdjustDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdjustDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAdjustDialog, CDialog)
	//{{AFX_MSG_MAP(CAdjustDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdjustDialog message handlers
