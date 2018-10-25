// Threshold.cpp : implementation file
//

#include "stdafx.h"
#include "PV320_Display.h"
#include "Threshold.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int m = 35;
/////////////////////////////////////////////////////////////////////////////
// CThreshold dialog


CThreshold::CThreshold(CWnd* pParent /*=NULL*/)
	: CDialog(CThreshold::IDD, pParent)
{
	//{{AFX_DATA_INIT(CThreshold)
	m_iTValue = 0;
	//}}AFX_DATA_INIT
}


void CThreshold::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CThreshold)
	DDX_Text(pDX, IDC_TVALUE, m_iTValue);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CThreshold, CDialog)
	//{{AFX_MSG_MAP(CThreshold)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThreshold message handlers

void CThreshold::OnCancel() 
{
// TODO: Add extra cleanup here
	CDialog::OnCancel();
}

void CThreshold::OnOK() 
{
	m = GetDlgItemInt(IDC_TVALUE);
	
	CDialog::OnOK();
}

BOOL CThreshold::OnInitDialog() 
{
	//CDialog::OnInitDialog();
	SetDlgItemInt(IDC_TVALUE,m);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
