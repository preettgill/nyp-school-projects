// PV320_DisplayDoc.cpp : implementation of the CPV320_DisplayDoc class
//
//#define WIN32_LEAN_AND_MEAN	  // Exclude rarely-used stuff from Windows headers
//#include <windows.h>
//#include <stdio.h>
//#include <stdlib.h>

#include "stdafx.h"
#include "PV320_Display.h"
#include "EditCDlg.h"//added
#include "Threshold.h"
#include "BinFile.h"
#include "PV320_DisplayDoc.h"
#include "PV320_DisplayView.h"

//#define PVCONNECTDLL_EXPORTS
#include "PVConnectDLL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static char* initerrs[] = {
	"Succeeded\n",
	"No camera detected:  not plugged in, or drivers not loaded\n",
	"Velocity not licensed for this camera\n",
	"Failed to connect to command channel, try again\n" } ;

unsigned char pixval[320*240];
extern value;
extern y1,x1;
int temp ;
//int v=35;
/////////////////////////////////////////////////////////////////////////////
// CPV320_DisplayDoc

IMPLEMENT_DYNCREATE(CPV320_DisplayDoc, CDocument)

BEGIN_MESSAGE_MAP(CPV320_DisplayDoc, CDocument)
	//{{AFX_MSG_MAP(CPV320_DisplayDoc)
	ON_COMMAND(ID_FILE_START, OnStart)
	ON_COMMAND(ID_CAPTURE, OnCapture)
	ON_COMMAND(ID_APP_EXIT, OnAppExit)
	ON_COMMAND(ID_LIVE, OnLive)
	ON_COMMAND(ID_SAVE, OnSave)
	ON_COMMAND(ID_TEMP, OnTemp)
	ON_COMMAND(ID__PROGRAM_STARTCAMERA, OnStart)
	ON_COMMAND(ID__PROGRAM_LIVEDISPLAY, OnLive)
	ON_COMMAND(ID__PROGRAM_CAPTUREIMAGE, OnCapture)
	ON_COMMAND(ID__PROGRAM_READTEMPERATURE, OnSave)
	ON_COMMAND(ID__PROGRAM_SAVEIMAGE, OnTemp)
	ON_COMMAND(ID__PROGRAM_EXIT, OnAppExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPV320_DisplayDoc construction/destruction

CPV320_DisplayDoc::CPV320_DisplayDoc()
{
	// TODO: add one-time construction code here
	bDataValid = FALSE;
}

CPV320_DisplayDoc::~CPV320_DisplayDoc()
{
}

BOOL CPV320_DisplayDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPV320_DisplayDoc serialization

void CPV320_DisplayDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPV320_DisplayDoc diagnostics

#ifdef _DEBUG
void CPV320_DisplayDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPV320_DisplayDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPV320_DisplayDoc commands

void CPV320_DisplayDoc::OnStart() 
{
	// TODO: Add your command handler code here
	Init_PV320();	
}

int CPV320_DisplayDoc::Init_PV320()
{
	int i ;
	int nchars = 0 ;
	char cmdResp[100] ;

	// Put your Toolkit activation key string here to enable connection
	// to a specific PV320 camera.
	if( IR_SetLicenseInfo( "KHC4CXYXZZY" ) == FALSE )
	{
		AfxMessageBox("IR_SetLicenseInfo failed.\n");
		return(1) ;
	}		
	// Open the USB Driver and command channel
	// When this is successful, the camera's analog video output should
	// say "REMOTE" in the lower right corner.
	int err ;
	if( (err=IR_InitBulkTransferUSB()) != IR_INIT_RTN_OK )
	{
		AfxMessageBox("IR_InitBulkTransferUSB failed.\n");
		AfxMessageBox( initerrs[err] ) ;
		return(2) ;
	}

	// Verify that USB drivers are loaded
	if( IR_CheckDriverStatusUSB() == FALSE )
	{
		AfxMessageBox("IR_CheckDriverStatusUSB failed!\n" ) ;
		return(3) ;
	}
	AfxMessageBox( "Successfully connected to camera.\n" ) ;
	CEditCDlg *dlg = new CEditCDlg ;
	dlg->Create(IDD_DIALOG2);
	dlg->ShowWindow(SW_SHOW);

	// Get and display the USB driver, hardware, and software version numbers
	int dr_vmin, dr_vmax ;
	if( IR_GetDriverRevision( dr_vmin, dr_vmax ) == FALSE )
	{
		AfxMessageBox("IR_GetDriverRevision failed!\n" ) ;
		return(4) ;
	}

	int sw_vmin, sw_vmax ;
	char sw_vstr[3] ;
	if( IR_GetSoftwareRevision( sw_vmin, sw_vmax, sw_vstr ) == FALSE )
	{
		AfxMessageBox("IR_GetSoftwareRevision failed!\n" ) ;
		return(5) ;
	}

	int hw_vmin, hw_vmax ;
	if( IR_GetHardwareRevision( hw_vmin, hw_vmax ) == FALSE )
	{
		AfxMessageBox("IR_GetHardwareRevision failed!\n" ) ;
		return(6) ;
	}
	//printf( "Version info: Driver %d.%.2d, SW %d.%.2d%s, HW %d.%.2d\n",
	//	dr_vmax, dr_vmin, sw_vmax, sw_vmin, sw_vstr, hw_vmax, hw_vmin ) ;

	// Interrogate the camera for key identity information
	int sn = IR_GetSerialNumber() ;
	char modelno[10], modelid[10], fwver[10]  ;
	IR_GetModelNumber( modelno ) ;
	IR_GetModelId( modelid ) ;
	IR_GetFWVersion( fwver ) ;
	//printf( "Camera identification: sn %d, model %s %s, version %s\n",
	//	sn, modelid, modelno, fwver ) ;

	// If this is a radiometric camera (a PV320T model), then we will need
	// to download some calibration data from the camera to allow us to
	// convert raw pixel values to temperatures.
	//
	// At present, the radiometric models will have a model id string
	// that starts with "320T";  non-radiometric models (PV320L, PV320A)
	// will have model ids that start with "320L".
	BOOL isRadiometric ;
	if( strncmp( modelid, "320T", 4 ) == 0 )
			isRadiometric = TRUE ;
	else 	isRadiometric = FALSE ;

	if( isRadiometric )
	{
		unsigned char encCoef[385], encD2U[65] ;
		int iris ;

		// Get the static calibration data from the camera
		// This data is referred to as "static" because it will not change
		// while the camera remains in the current range.  If you change the
		// range using the IR_CmdSetRange function), you will need to
		// download new calibration data for the new camera range.
		if( IR_CmdGetCalibrationData( iris, (char*)encCoef, (char*)encD2U )
			== FALSE )
		{
			AfxMessageBox("IR_SetCalibrationData returned FALSE\n" ) ;
			// Setting IR_VIDEO_EXIT here ensures that the camera is
			// taken out of REMOTE mode before we exit.
			IR_EnableVideoStreaming( IR_VIDEO_EXIT ) ;
			return(7) ;
		}
		
		char strg[50];

		sprintf(strg, "Current operating range is %d \n",
				iris ) ;
		//	AfxMessageBox(strg);
		
		
		//printf( "Range is %d\n", iris ) ;
		//printf( "Encoded coefficient string <%s>\n", encCoef ) ;
		//printf( "Encoded d2u string <%s>\n", encD2U ) ;

		// Now load the static calibration data into the DLL so later
		// calls to IR_ConvertRawToTemp can successfully translate
		if( IR_SetCalibrationData( iris, encCoef, encD2U ) == FALSE )
		{
			AfxMessageBox("IR_SetCalibrationData returned FALSE\n" ) ;
			IR_EnableVideoStreaming( IR_VIDEO_EXIT ) ;
			return(8) ;
		}
//		printf( "Static calibration data loaded successfully\n\n\n" ) ;
	}
	
	return (0);
}

int CPV320_DisplayDoc::OnCapture() 
{
        POSITION pos;
        CPV320_DisplayView *pView;

        HWND hWindow;

	// TODO: Add your command handler code here
	// Now let's try to get some image data from the camera
	struct IR_PixelEP *pix ;
	int i,raw, sizeX, sizeY ;
	BOOL isRadiometric ;
	char cmdResp[100] ;
	char strg[50];

	// We know the image is always 320x240, but it doesn't hurt to generalize
	IR_GetVideoSize( sizeX, sizeY ) ;
	
	m_SizeX = sizeX;
	m_SizeY = sizeY;

	// Grab an image (one video frame) from the camera, and look at the pixel values

		// Setting IR_VIDEO_RUN tells the DLL to begin grabbing frames
		// so they will be available when we ask for them.
		if( IR_EnableVideoStreaming(IR_VIDEO_RUN) == FALSE )
		{
			AfxMessageBox( "IR_EnableVideoStreaming returned FALSE\n" ) ;
			IR_EnableVideoStreaming( IR_VIDEO_EXIT ) ;
			return(9);
		}
		// Wait a little for the DLL to fill it's input buffer
		Sleep(100);

		// In case the DLL does not have a frame ready for us when we ask,
		// we'll retry up to 10 times, with a delay, to get image data
		int frame ;
		for( frame=0 ; frame < 10 ; frame++ )
		{
			// A NULL return indicates that a frame is not available
			if( (pix = IR_GetPixelFramePointer()) != NULL )
				break ;
			Sleep(100) ;
		}
		if( pix == NULL )
		{
			fprintf( stderr, "IR_GetPixelFramePointer returned NULL\n" ) ;	
			IR_EnableVideoStreaming( IR_VIDEO_EXIT ) ;
			AfxMessageBox("No frames ready");
			return(10);
		}

		// Find image greyscale min, max, and mean
		// The raw pixel values are 14 bit values, so they will be in
		// the range 0 to 16383
		int min = 18000 ;
		int max = -1 ;
		double mean = 0.0 ;
		i = 0 ;
		int x, y ;

		// Since we are going to make a pass through all the pixel values
		// to find the min, max, and mean, we'll convert the linear list
		// of pixels into a two dimensional array to provide easier
		// direct access to the values based on x and y coordinates.
		unsigned short pixdata[320][240] ;
		for( y=0 ; y<sizeY ; y++ )
		{
			for( x=0 ; x<sizeX ; x++ )
			{
				pixdata[x][y] = pix->Data[i] ;
				
				pixval[i] = (pixdata[x][y] * 255.0F/16383.0F);
#ifdef GET_STATS
				if( pix->Data[i] < min )	min = pix->Data[i] ;
				if( pix->Data[i] > max )	max = pix->Data[i] ;
				mean += (double)pix->Data[i] ;
#endif
				i++ ;
			}
		}
		bDataValid = TRUE;
        pos = GetFirstViewPosition();
        pView = (CPV320_DisplayView *)GetNextView(pos);

        hWindow = pView->GetSafeHwnd();

        InvalidateRect(hWindow,NULL,FALSE);


return 0;
	
}

void CPV320_DisplayDoc::OnAppExit() 
{
	// TODO: Add your command handler code here
	// Release the camera from REMOTE mode
	IR_EnableVideoStreaming( IR_VIDEO_EXIT );
}

void CPV320_DisplayDoc::OnLive() 
{
	// TODO: Add your command handler code here	 

	int palette;
	char strg[50];


	//if(IR_CmdGetPalette(palette))
	//{
	//	sprintf(strg, "The palette is %d \n",
	//			palette ) ;
		
	//	AfxMessageBox(strg);
		
	//}
	//else
	//{
	//	AfxMessageBox("Getpalette false");
	//}

	if(IR_CmdSetPalette(3))
	{
	//	sprintf(strg,"The palette is 3");
	//	AfxMessageBox(strg);
	}
	else
	{
//		AfxMessageBox("Getpalette false");
	}
	bStopFlag = FALSE;
	AfxMessageBox("Display live image, Hit <ESC> or <Alt+S> to stop");
	while (!bStopFlag)
	{
		OnCapture();
		DoEvent();
	}
	AfxMessageBox("Live completed");
	
}

void CPV320_DisplayDoc::DoEvent()
{
MSG mesg;
/********* Check for window messages *************/
while (PeekMessage (&mesg, NULL, 0, 0, PM_REMOVE)) 
    {
//#ifdef OLD
//	   if (mesg.message == WM_SYSCHAR)
//	      {
//
//		     // Abort key Alt-X
//             if (mesg.wParam==120) 
//                {
//                *StopFlag = 88;
//                }
//	      }
    if (mesg.message >= WM_KEYFIRST && mesg.message <= WM_KEYLAST) 
       {
       /********** Check for ESC key or ALT-S key to stop loop *************/
       if (bStopFlag==FALSE && (mesg.wParam == 27 || mesg.wParam == 83)) // ESC or Alt-S
          {          
             bStopFlag=TRUE;
	      }
	   }
//#endif
     TranslateMessage(&mesg);
     DispatchMessage(&mesg);  
	   
	}   

}
//on temp
int CPV320_DisplayDoc::OnSave()
{	
	/*CDib Dib;
	BOOL bRet;
	bRet = Dib.Save("infra.bmp");
	if (bRet)
		AfxMessageBox("The Save() Function succeeded.");
	else
		AfxMessageBox("The Save() Function failed."); */

	POSITION pos;
        CPV320_DisplayView *pView;

        HWND hWindow;

	// TODO: Add your command handler code here
	// Now let's try to get some image data from the camera
	struct IR_PixelEP *pix ;
	int i,raw, sizeX, sizeY ;
	BOOL isRadiometric ;
	char cmdResp[100] ;
	char strg[50];

	// We know the image is always 320x240, but it doesn't hurt to generalize
	IR_GetVideoSize( sizeX, sizeY ) ;
	
	m_SizeX = sizeX;
	m_SizeY = sizeY;

	// Grab an image (one video frame) from the camera, and look at the pixel values

		// Setting IR_VIDEO_RUN tells the DLL to begin grabbing frames
		// so they will be available when we ask for them.
		if( IR_EnableVideoStreaming(IR_VIDEO_RUN) == FALSE )
		{
			AfxMessageBox( "IR_EnableVideoStreaming returned FALSE\n" ) ;
			IR_EnableVideoStreaming( IR_VIDEO_EXIT ) ;
			return(9);
		}
		// Wait a little for the DLL to fill it's input buffer
		Sleep(100);

		// In case the DLL does not have a frame ready for us when we ask,
		// we'll retry up to 10 times, with a delay, to get image data
		int frame ;
		for( frame=0 ; frame < 10 ; frame++ )
		{
			// A NULL return indicates that a frame is not available
			if( (pix = IR_GetPixelFramePointer()) != NULL )
				break ;
			Sleep(100) ;
		}
		if( pix == NULL )
		{
			fprintf( stderr, "IR_GetPixelFramePointer returned NULL\n" ) ;	
			IR_EnableVideoStreaming( IR_VIDEO_EXIT ) ;
			AfxMessageBox("No frames ready");
			return(10);
		}
		int min = 18000 ;
		int max = -1 ;
		double mean = 0.0 ;
		i = 0 ;
		int x, y ;
		unsigned short pixdata[320][240] ;
		for( y=0 ; y<sizeY ; y++ )
		{
			for( x=0 ; x<sizeX ; x++ )
			{
				pixdata[x][y] = pix->Data[i] ;
				
				pixval[i] = (pixdata[x][y] * 255.0F/16383.0F);
#ifdef GET_STATS
				if( pix->Data[i] < min )	min = pix->Data[i] ;
				if( pix->Data[i] > max )	max = pix->Data[i] ;
				mean += (double)pix->Data[i] ;
#endif
				i++ ;
			}
		}
		bDataValid = TRUE;
        pos = GetFirstViewPosition();
        pView = (CPV320_DisplayView *)GetNextView(pos);

        hWindow = pView->GetSafeHwnd();

        InvalidateRect(hWindow,NULL,FALSE);

		mean /= (double)(sizeX*sizeY) ;
		/*raw =  pixdata[158][118] + pixdata[159][118] + pixdata[160][118] ;
		raw += pixdata[158][119] + pixdata[159][119] + pixdata[160][119] ;
		raw += pixdata[158][120] + pixdata[159][120] + pixdata[160][120] ;*/

		raw =  pixdata[x1-2][y1-2] + pixdata[y1-1][y1-2] + pixdata[x1][y1-2] ;
		raw += pixdata[x1-2][y1-1] + pixdata[y1-1][y1-1] + pixdata[x1][y1-1] ;
		raw += pixdata[x1-2][y1] + pixdata[x1-1][y1] + pixdata[x1][y1] ; 
		raw /= 9 ;
		IR_ClearPixelFramePointer(pix) ;
		IR_EnableVideoStreaming( IR_VIDEO_PAUSE ) ;

		if( isRadiometric )
		{
			double cTop, cBot, tExt, tInt, tPlate ;
			BOOL fit ;
			if( IR_CmdGetCurrentData(cTop,cBot,tExt,tInt,tPlate,fit) == FALSE )
			{
				fprintf( stderr, "IR_CmdGetCurrentData failed\n" ) ;
				IR_EnableVideoStreaming( IR_VIDEO_EXIT ) ;
				return(11);
			}

			if(x1<320 && y1<240)
			{
			IR_ConvertRawToTemp( temp, raw,
				cTop, cBot, tExt, tInt, tPlate, fit, 1.0, 0) ;
			temp = ( 5.0 / 9.0 ) * ( temp - 32.0);
			sprintf(strg, "The targetted temperature reading is %d deg C\n",
				temp ) ;
			AfxMessageBox(strg);
			}
			if(x1>320 || y1 > 240)
			{
			sprintf(strg, "The CrossHair is out of measure range!") ;
			AfxMessageBox(strg);
			}

		//	CThreshold ThresholdDlg;
		//	ThresholdDlg.m_iTValue = 35;
		//	v = ThresholdDlg.m_iTValue;
		if(temp >= value){
			CString t = "Fever Detected";
			AfxMessageBox(t);
			}		
			else{
			CString s = "Fever NOT Detected";
			AfxMessageBox(s);
			}
		
		}

return temp;
}
 
//on save
void CPV320_DisplayDoc::OnTemp()
{
	/*CDib Dib;
	BOOL bRet;
	bRet = Dib.Save("saveimage.bmp");
	if (bRet)
		AfxMessageBox("The Save() function is OK");
	else
		AfxMessageBox("The Save() function failed");*/

// this code only works with dialog box//

	CColourChangerDlg *ccdlg = new 	CColourChangerDlg;
	ccdlg->Create(IDD_DIALOG3);
	ccdlg->ShowWindow(SW_SHOW);	

}
