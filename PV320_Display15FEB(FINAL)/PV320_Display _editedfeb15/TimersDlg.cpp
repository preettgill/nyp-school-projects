// TimersDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PV320_Display.h"
#include "TimersDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimersDlg dialog


CTimersDlg::CTimersDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimersDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTimersDlg)
	m_sTime = _T("");
	m_mCount = _T("");
	m_hCount = _T("");
	m_sCount = _T("");
	m_text = _T("");
	m_text1 = _T("");
	m_st = _T("");
	//}}AFX_DATA_INIT
}


void CTimersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTimersDlg)
	DDX_Control(pDX, IDC_STOPTIMER, m_cStopTime);
	DDX_Control(pDX, IDC_STARTTIME, m_cStartTime);
	DDX_Text(pDX, IDC_STATICTIME, m_sTime);
	DDX_Text(pDX, IDC_STATICM, m_mCount);
	DDX_Text(pDX, IDC_STATICH, m_hCount);
	DDX_Text(pDX, IDC_STATICS, m_sCount);
	DDX_Text(pDX, IDC_STATICT, m_text);
	DDX_Text(pDX, IDC_STATICTH, m_text1);
	DDX_Text(pDX, IDC_STATICST, m_st);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTimersDlg, CDialog)
	//{{AFX_MSG_MAP(CTimersDlg)
	ON_BN_CLICKED(IDC_STOPTIMER, OnStoptimer)
	ON_BN_CLICKED(IDC_STARTTIME, OnStarttime)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimersDlg message handlers

void CTimersDlg::OnStoptimer() 
{

m_text = m_stext;
m_text1 = m_htext;

	//stop the timer 
KillTimer(ID_COUNT_TIMER);

// stop the clock timer
KillTimer(ID_CLOCK_TIMER);

//Reset the clock timer with 1 second interval
SetTimer(ID_CLOCK_TIMER,1000,NULL);

//Diable the stop timer button
m_cStopTime.EnableWindow(FALSE);
//enable the start timer button
m_cStartTime.EnableWindow(TRUE);

m_cStopTime.EnableWindow(FALSE);
m_cStartTime.EnableWindow(TRUE);	
}

void CTimersDlg::OnStarttime() 
{
	UpdateData(TRUE);

	//initialize the count
	m_iCount = 0;
	m_text = "";
	m_text1 = "";
	m_mCount = "0";
	m_hCount = "0";
	//format the count
	m_sCount.Format("%d",m_iCount);

	//update the dialog
	UpdateData(FALSE);
	//start the timer
	SetTimer(ID_COUNT_TIMER, 1000,NULL);

	//stop the clock timer
	KillTimer(ID_CLOCK_TIMER);
	//restart the clock timer with the counter interval
	SetTimer(ID_CLOCK_TIMER, 1000, NULL);

	//Enable the stop button
	m_cStopTime.EnableWindow(TRUE);
	//Disable the start timer button
	m_cStartTime.EnableWindow(FALSE);
	
}

void CTimersDlg::OnExit() 
{

OnOK();
	
}

BOOL CTimersDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	UpdateData(FALSE);

	//start the clock timer
	SetTimer(ID_CLOCK_TIMER, 1000, NULL);
	OnStarttime();

	return TRUE; 
}

void CTimersDlg::OnTimer(UINT nIDEvent) 
{
	CTime curTime = CTime::GetCurrentTime();

		//which timer triggered this event
	switch (nIDEvent)
	{
		//the clock timer
	case ID_CLOCK_TIMER:
		//Display the current time
	m_sTime.Format("%d:%d:%d", curTime.GetHour(),curTime.GetMinute(),curTime.GetSecond());
	break;
	//the count timer
	case ID_COUNT_TIMER:
		//increment the count
		m_iCount++;
	
		//format and display 
		m_sCount.Format("%d",m_iCount);
		m_mCount.Format("%d",m_iCount/60);
		m_hCount.Format("%d",m_iCount/60/60);
		m_stext.Format("Total time of usage in Minutes: %d", m_iCount/60);
		m_htext.Format("Total time of usage in Hours: %d", m_iCount/60/60);
		break;
	}

		int sec = m_iCount;
		if( sec == 2400)
		{
		AfxMessageBox("Camera has warmed up and is ready for usage.\n");
		}
		
	//update the dialog
	UpdateData(FALSE);
	CDialog::OnTimer(nIDEvent);
}
