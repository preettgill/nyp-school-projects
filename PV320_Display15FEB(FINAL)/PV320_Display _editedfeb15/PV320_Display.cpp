// PV320_Display.cpp : Defines the class behaviors for the application.
//

#include <afxwin.h> //added
#include "Resource.h"//added

#include "AdjustDialog.h"
#include "stdafx.h"
#include "PV320_Display.h"
#include "EditCDlg.h"//added

#include "MainFrm.h"
#include "PV320_DisplayDoc.h"
#include "PV320_DisplayView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

	

/////////////////////////////////////////////////////////////////////////////
// CPV320_DisplayApp

BEGIN_MESSAGE_MAP(CPV320_DisplayApp, CWinApp)
	//{{AFX_MSG_MAP(CPV320_DisplayApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_EDIT_ADJUST, OnEditAdjust)
	ON_COMMAND(ID_EDIT_COLOUR, OnEditColour)
	ON_COMMAND(ID_ADJUST_TEST, OnAdjustTest)
	ON_COMMAND(ID_ADJUST_ADJUSTTHRESHOLDSETTING, OnAdjustAdjustthresholdsetting)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_ADJUST_CROSSHAIRCOLORCHANGER, OnAdjustCrosshaircolorchanger)
	ON_COMMAND(ID__CAMERAUSAGETIMER, OnEditColour)
	ON_COMMAND(ID__ADJUSTTHRESHOLDSETTINGS, OnAdjustAdjustthresholdsetting)
	ON_COMMAND(ID_TIMER_CAMERAUSAGETIMER, OnEditColour)
	ON_COMMAND(ID__FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID__ADJUST_CROSSHAIRCOLORCHANGER, OnAdjustCrosshaircolorchanger)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPV320_DisplayApp construction

CPV320_DisplayApp::CPV320_DisplayApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPV320_DisplayApp object

CPV320_DisplayApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CPV320_DisplayApp initialization

BOOL CPV320_DisplayApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CPV320_DisplayDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CPV320_DisplayView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CPV320_DisplayApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CPV320_DisplayApp message handlers


void CPV320_DisplayApp::OnEditAdjust() 
{
 //CEditDlg editDlg;
//	editDlg.DoModal();	
}

void CPV320_DisplayApp::OnEditColour() 
{

	CEditCDlg *dlg = new CEditCDlg ;
//	editCDlg.DoModal();
//	editCDlg.Create(IDD_DIALOG2);
//	editCDlg.ShowWindow(SW_SHOW);
/*
	CEditCDlg *dlg;//added tutorial 5
	*/
	dlg->Create(IDD_DIALOG2);
	dlg->ShowWindow(SW_SHOW);
}

void CPV320_DisplayApp::OnAdjustTest() 
{
//	CColourChangerDlg colourChangerDlg;
//colourChangerDlg.DoModal();	// TODO: Add your command handler code here
	
}

void CPV320_DisplayApp::OnAdjustAdjustthresholdsetting() 
{
//CThreshold thresholdDlg;
//thresholdDlg.DoModal();	// TODO: Add your command handler code here
	
}


void CPV320_DisplayApp::OnFileOpen() 
{

/*CFileDialog m_ldFile(TRUE);

if(m_ldFile.DoModal() == IDOK)
{
	m_ldFile.GetFileName();
}*/
	
/*	CFile f;

	char strFilter[] = { "BMP Files (*.bmp)|*.bmp|All Files (*.*)|*.*||" };

	CFileDialog FileDlg(TRUE, ".bmp", NULL, 0, strFilter);

	if( FileDlg.DoModal() == IDOK )
	{
		if( f.Open(FileDlg.GetFileName(), CFile::modeRead) == TRUE )
		WinExec("mspaint.exe",SW_SHOW);
			return;
	//	CArchive ar(&f, CArchive::load);
	//	f.Close();
	}
	else
		return;

	f.Close();*/
	WinExec("mspaint.exe",SW_SHOW);
}

void CPV320_DisplayApp::OnAdjustCrosshaircolorchanger() 
{
	// TODO: Add your command handler code here
	CColorDlg *dlg = new CColorDlg ;
//	editCDlg.DoModal();
//	editCDlg.Create(IDD_DIALOG2);
//	editCDlg.ShowWindow(SW_SHOW);
/*
	CEditCDlg *dlg;//added tutorial 5
	*/
	dlg->Create(IDD_DIALOG5);
	dlg->ShowWindow(SW_SHOW);
}
