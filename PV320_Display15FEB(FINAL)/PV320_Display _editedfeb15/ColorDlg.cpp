// ColorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PV320_Display.h"
#include "ColorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int r=128;
int b=128;
int g=128;
/////////////////////////////////////////////////////////////////////////////
// CColorDlg dialog


CColorDlg::CColorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CColorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CColorDlg)
	m_iBlue = 0;
	m_iGreen = 0;
	m_iRed = 0;
	//}}AFX_DATA_INIT
}


void CColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CColorDlg)
	DDX_Text(pDX, IDC_EDITB, m_iBlue);
	DDV_MinMaxInt(pDX, m_iBlue, 0, 255);
	DDX_Text(pDX, IDC_EDITG, m_iGreen);
	DDV_MinMaxInt(pDX, m_iGreen, 0, 255);
	DDX_Text(pDX, IDC_EDITR, m_iRed);
	DDV_MinMaxInt(pDX, m_iRed, 0, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CColorDlg, CDialog)
	//{{AFX_MSG_MAP(CColorDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorDlg message handlers

BOOL CColorDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//r=128;
	//g=128;
	//b=128;
		
	// TODO: Add extra initialization here
	SetDlgItemInt(IDC_EDITR,r);
	SetDlgItemInt(IDC_EDITG,g);
	SetDlgItemInt(IDC_EDITB,b);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CColorDlg::OnOK() 
{
	// TODO: Add extra validation here
	r = GetDlgItemInt(IDC_EDITR);
	g = GetDlgItemInt(IDC_EDITG);
	b = GetDlgItemInt(IDC_EDITB);
	CDialog::OnOK();
}
