// EditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PV320_Display.h"
#include "EditDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//extern int START;

int start = 80;
//int end = 176;
/////////////////////////////////////////////////////////////////////////////
// CEditDlg dialog


CEditDlg::CEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditDlg)
//	m_iEValue = 0;
	m_iSValue = 0;
	//}}AFX_DATA_INIT
}


void CEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditDlg)
//	DDX_Text(pDX, IDC_EVALUE, m_iEValue);
//	DDV_MinMaxInt(pDX, m_iEValue, 176, 255);
	DDX_Text(pDX, IDC_SVALUE, m_iSValue);
	DDV_MinMaxInt(pDX, m_iSValue, 0, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditDlg, CDialog)
	//{{AFX_MSG_MAP(CEditDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditDlg message handlers


void CEditDlg::OnOK() 
{
start = GetDlgItemInt(IDC_SVALUE);

//end = GetDlgItemInt(IDC_EVALUE);
 	

	CDialog::OnOK();
	
}

BOOL CEditDlg::OnInitDialog() 
{
//	CDialog::OnInitDialog();

SetDlgItemInt(IDC_SVALUE,start);
//	SetDlgItemInt(IDC_EVALUE, end);

// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
