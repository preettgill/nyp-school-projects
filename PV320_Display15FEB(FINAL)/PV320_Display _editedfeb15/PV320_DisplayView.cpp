// PV320_DisplayView.cpp : implementation of the CPV320_DisplayView class
//

#include "stdafx.h"
#include "PV320_Display.h"

#include "PV320_DisplayDoc.h"
#include "PV320_DisplayView.h"
#include "PVConnectDLL.h"
#include "EditDlg.h"
#include "Threshold.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern unsigned char pixval[];
//int START;
int START1=80;
int value=35;
int x1=160;
int y1=120;
int red = 128,blue = 128,green = 128;
//void OnEditAdjust() ;
/////////////////////////////////////////////////////////////////////////////
// CPV320_DisplayView

IMPLEMENT_DYNCREATE(CPV320_DisplayView, CView)

BEGIN_MESSAGE_MAP(CPV320_DisplayView, CView)
	//{{AFX_MSG_MAP(CPV320_DisplayView)
	ON_COMMAND(ID_EDIT_ADJUST, OnEditAdjust)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID__ADJUSTTHRESHOLDSETTINGS, OnAdjustAdjustthresholdsetting)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_ADJUST_CROSSHAIRCOLORCHANGER, OnAdjustCrosshaircolorchanger)
	ON_COMMAND(ID__ADJUST_ADJUSTRANGE, OnEditAdjust)
	ON_COMMAND(ID_ADJUST_ADJUSTTHRESHOLDSETTING, OnAdjustAdjustthresholdsetting)
	ON_COMMAND(ID__ADJUST_ADJUSTTHRESHOLDSETTINGS, OnAdjustAdjustthresholdsetting)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPV320_DisplayView construction/destruction

CPV320_DisplayView::CPV320_DisplayView()
{


	// DIALOG BOX PLACED HERE//

		CEditDlg Dlg;
	if(Dlg.DoModal()==IDOK)
	{
	
		START1=Dlg.m_iSValue;
	}
	

	START1 = START1;
			// TODO: add construction code here
    // Build RGB24 bitmap info
//	START1=80;
    m_pBitmapInfo = (BITMAPINFO *) new BYTE[sizeof(BITMAPINFO) + 255*sizeof(RGBQUAD)];
    m_pBitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    m_pBitmapInfo->bmiHeader.biPlanes = 1;
    m_pBitmapInfo->bmiHeader.biBitCount = 8;
    m_pBitmapInfo->bmiHeader.biCompression = BI_RGB;
    m_pBitmapInfo->bmiHeader.biSizeImage = 0;
    m_pBitmapInfo->bmiHeader.biXPelsPerMeter = 0;
    m_pBitmapInfo->bmiHeader.biYPelsPerMeter = 0;
    m_pBitmapInfo->bmiHeader.biClrUsed = 0;
    m_pBitmapInfo->bmiHeader.biClrImportant = 0;
    //for (int i = 0 ; i < 256 ; i++) {
    //m_pBitmapInfo->bmiColors[i].rgbBlue = (BYTE)i;
    //m_pBitmapInfo->bmiColors[i].rgbGreen = (BYTE)i;
    //m_pBitmapInfo->bmiColors[i].rgbRed = (BYTE)i;
    //m_pBitmapInfo->bmiColors[i].rgbReserved = 0;
    //}
    for (int i = 0 ; i < 256 ; i++) {
	//int x = 0;
	//int z = 255;
//	int y = 108;
//	int u = 1;
//	int m = 0;

		//Added the following colours B
		//Black(0,0,0)
		//Blue(0,0,255)
		//Dark blue(0,0,128)
		//Green(0,255,0)
		//DarkGreen(0,128,0)
		//Cyan(0,255,255)
		//Dark cyan(0,128,128)
		//Red(255,0,0)
		//Dark red(128,0,0)
		//Magenta(255,0,255)
		//Dark magenta(128,0,128)
		//Yellow(255,255,0)
		//Dark Yellow(128,128,0)
		//Dark Gray(128,128,128)
		//Light gray(192,192,192)
		//White(255,255,255)


	if(i>=0&&i<=(START1-1))//black
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 0;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 0;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 0;
	}
	//range human color
	//green
	if(i>= START1&&i<=(START1+1))
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 34;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 139;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 34;
	}

	if(i>=(START1+2)&&i<=(START1+3))
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 46;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 139;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 87;
	}
	if(i>=(START1+4)&&i<=(START1+5))
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 0;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 128;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 0;
	}
	if(i>=(START1+6)&&i<=(START1+7))
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 154;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 205;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 50;
	}
	//blue
	if(i>=(START1+8)&&i<=(START1+9))
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 0;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 255;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 255;
	}
	if(i>=(START1+10)&&i<=(START1+11))
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 0;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 0;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 205;
	}
	if(i>=(START1+12)&&i<=(START1+13))
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 100;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 149;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 237;
	}
	if(i>=(START1+14)&&i<=(START1+15))
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 0;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 0;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 128;
	}
	//yellow
	if(i>=(START1+16)&&i<=(START1+17))
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 255;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 255;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 0;
	}
	if(i>=(START1+18)&&i<=(START1+19))
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 255;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 215;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 0;
	}
	if(i>=(START1+20)&&i<=(START1+21))
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 255;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 165;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 0;
	}
	if(i>=(START1+22)&&i<=(START1+23))
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 255;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 140;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 0;
	}
	//red
	if(i>=(START1+24)&&i<=(START1+25))
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 255;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 69;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 0;
	}
	if(i>=(START1+26)&&i<=(START1+27))
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 220;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 20;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 60;
	}
	if(i>=(START1+28)&&i<=(START1+29))
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 255;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 0;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 0;
	}
	if(i>=(START1+30)&&i<=(START1+31))
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 240;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 128;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 128;
	}
	//purple
	if(i>=(START1+32)&&i<=(START1+33))
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 147;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 112;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 219;
	}
	if(i>=(START1+34)&&i<=(START1+35))
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 148;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 0;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 211;
	}
	if(i>=(START1+36)&&i<=(START1+37))
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 221;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 160;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 221;
	}
	if(i>=(START1+38)&&i<=(START1+39))
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 128;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 0;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 128;
	}
	
	if(i>=(START1+40)&&i<=255)//black
	{
		m_pBitmapInfo->bmiColors[i].rgbRed = 0;
	    m_pBitmapInfo->bmiColors[i].rgbGreen = 0;
	    m_pBitmapInfo->bmiColors[i].rgbBlue = 0;
	}

	m_pBitmapInfo->bmiColors[i].rgbReserved = 0;

    }
    m_pBitmapInfo->bmiHeader.biWidth = 0;
    m_pBitmapInfo->bmiHeader.biHeight = 0;

}

CPV320_DisplayView::~CPV320_DisplayView()
{
  // Delete bitmap info
  if (m_pBitmapInfo) delete m_pBitmapInfo;

}

BOOL CPV320_DisplayView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPV320_DisplayView drawing

void CPV320_DisplayView::OnDraw(CDC* pDC)
{
	CPV320_DisplayDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

    // Protection
    if (pDoc->m_pCurrent==NULL) return;

    // Retrieve image size in the document
    int SizeX = pDoc->m_SizeX;
    int SizeY = pDoc->m_SizeY;

    // Configure the bitmap info according to the image size
	if (pDoc->bDataValid)
	{

    m_pBitmapInfo->bmiHeader.biWidth = SizeX;  
    m_pBitmapInfo->bmiHeader.biHeight = -SizeY ;
    // Display
    SetDIBitsToDevice (pDC->GetSafeHdc(), 0, 0, SizeX, SizeY,
                                  0, 0, 0, SizeY,
                                  pixval, m_pBitmapInfo, DIB_RGB_COLORS);
	}

	CDib Dib;
	Dib.Load("001.bmp");
//	Dib.Draw(pDC,320,0);
//	pDC->TextOut(10,250,"The temperature is: ");




//Color Bar
//green
	RECT Bar0;
	Bar0.left = 320;
	Bar0.right = 350;
	Bar0.top = 0;
	Bar0.bottom = 20;

	CBrush Color0( RGB (34,139,34));	
	pDC->FillRect(&Bar0,&Color0);	


	RECT Bar1;
	Bar1.left = 320;
	Bar1.right = 350;
	Bar1.top = 20; 
	Bar1.bottom = 40;

	CBrush Color1( RGB (46,139,87));	
	pDC->FillRect(&Bar1,&Color1);
	pDC->TextOut(353 , 20, "30 degrees C");



	RECT Bar2;
	Bar2.left = 320;
	Bar2.right = 350;
	Bar2.top = 40; 
	Bar2.bottom = 60;

	CBrush Color2( RGB (0,128,0));
	pDC->FillRect(&Bar2,&Color2);


	RECT Bar3;
	Bar3.left = 320;
	Bar3.right = 350;
	Bar3.top = 60; 
	Bar3.bottom = 80;

	CBrush Color3( RGB (154,205,50));	
	pDC->FillRect(&Bar3,&Color3);

//blue
	RECT Bar4;
	Bar4.left = 320;
	Bar4.right = 350;
	Bar4.top = 80; 
	Bar4.bottom = 100;

	CBrush Color4( RGB (0,255,255));	
	pDC->FillRect(&Bar4,&Color4);
	pDC->TextOut(353 , 80, "31 degrees C");


	RECT Bar5;
	Bar5.left = 320;
	Bar5.right = 350;
	Bar5.top = 100; 
	Bar5.bottom = 120;

	CBrush Color5( RGB (0,0,205));	
	pDC->FillRect(&Bar5,&Color5);
	pDC->TextOut(353 , 100, "32 degrees C");

	RECT Bar6;
	Bar6.left = 320;
	Bar6.right = 350;
	Bar6.top = 120; 
	Bar6.bottom = 140;

	CBrush Color6( RGB (100,149,237));	
	pDC->FillRect(&Bar6,&Color6);


	RECT Bar7;
	Bar7.left = 320;
	Bar7.right = 350;
	Bar7.top = 140; 
	Bar7.bottom = 160;

	CBrush Color7( RGB (0,0,128));	
	pDC->FillRect(&Bar7,&Color7);

//yellow
	RECT Bar8;
	Bar8.left = 320;
	Bar8.right = 350;
	Bar8.top = 160; 
	Bar8.bottom = 180;

	CBrush Color8( RGB (255,255,0));	
	pDC->FillRect(&Bar8,&Color8);
	pDC->TextOut(353 , 160, "33 degrees C");


	RECT Bar9;
	Bar9.left = 320;
	Bar9.right = 350;
	Bar9.top = 180; 
	Bar9.bottom = 200;

	CBrush Color9( RGB (255,215,0));
	pDC->FillRect(&Bar9,&Color9);


	RECT Bar10;
	Bar10.left = 320;
	Bar10.right = 350;
	Bar10.top = 200; 
	Bar10.bottom = 220;

	CBrush Color10( RGB (255,165,0));	
	pDC->FillRect(&Bar10,&Color10);


	RECT Bar11;
	Bar11.left = 320;
	Bar11.right = 350;
	Bar11.top = 220; 
	Bar11.bottom = 240;

	CBrush Color11( RGB (255,140,0));	
	pDC->FillRect(&Bar11,&Color11);

//red
	RECT Bar12;
	Bar12.left = 320;
	Bar12.right = 350;
	Bar12.top = 240; 
	Bar12.bottom = 260;

	CBrush Color12( RGB (255,69,0));
	pDC->FillRect(&Bar12,&Color12);
	pDC->TextOut(353 , 240 , "35 degrees C");
	
	RECT Bar13;
	Bar13.left = 320;
	Bar13.right = 350;
	Bar13.top = 260; 
	Bar13.bottom = 280;

	CBrush Color13( RGB (220,20,60));	
	pDC->FillRect(&Bar13,&Color13);


	RECT Bar14;
	Bar14.left = 320;
	Bar14.right = 350;
	Bar14.top = 280; 
	Bar14.bottom = 300;

	CBrush Color14( RGB (255,0,0));	
	pDC->FillRect(&Bar14,&Color14);
	pDC->TextOut(353 , 280 , "FEVER LABEL MARKER");


	RECT Bar15;
	Bar15.left = 320;
	Bar15.right = 350;
	Bar15.top = 300; 
	Bar15.bottom = 320;

	CBrush Color15( RGB (240,128,128));	
	pDC->FillRect(&Bar15,&Color15);

//purple
	RECT Bar16;
	Bar16.left = 320;
	Bar16.right = 350;
	Bar16.top = 320; 
	Bar16.bottom = 340;

	CBrush Color16( RGB (147,112,219));	
	pDC->FillRect(&Bar16,&Color16);
	pDC->TextOut(353 , 320, "36 degrees C");


	RECT Bar17;
	Bar17.left = 320;
	Bar17.right = 350;
	Bar17.top = 340; 
	Bar17.bottom = 360;

	CBrush Color17( RGB (148,0,211));	
	pDC->FillRect(&Bar17,&Color17);


	RECT Bar18;
	Bar18.left = 320;
	Bar18.right = 350;
	Bar18.top = 360; 
	Bar18.bottom = 380;

	CBrush Color18( RGB (221,160,221));	
	pDC->FillRect(&Bar18,&Color18);

	RECT Bar19;
	Bar19.left = 320;
	Bar19.right = 350;
	Bar19.top = 380; 
	Bar19.bottom = 400;

	CBrush Color19( RGB (128,0,128));	
	pDC->FillRect(&Bar19,&Color19);




/*
	RECT Bar0;
	Bar0.left = 320;
	Bar0.right = 350;
	Bar0.top = 0;
	Bar0.bottom = 10;

	CBrush Color0( RGB (0,0,0));	//black
	pDC->FillRect(&Bar0,&Color0);	


	RECT Bar1;
	Bar1.left = 320;
	Bar1.right = 350;
	Bar1.top = 10; 
	Bar1.bottom = 20;

	CBrush Color1( RGB (255,255,205));	//blanched almond
	pDC->FillRect(&Bar1,&Color1);



	RECT Bar2;
	Bar2.left = 320;
	Bar2.right = 350;
	Bar2.top = 20; 
	Bar2.bottom = 30;

	CBrush Color2( RGB (0,0,255));	//blue
	pDC->FillRect(&Bar2,&Color2);


	RECT Bar3;
	Bar3.left = 320;
	Bar3.right = 350;
	Bar3.top = 30; 
	Bar3.bottom = 40;

	CBrush Color3( RGB (138,43,226));	//blueviolet
	pDC->FillRect(&Bar3,&Color3);


	RECT Bar4;
	Bar4.left = 320;
	Bar4.right = 350;
	Bar4.top = 40; 
	Bar4.bottom = 50;

	CBrush Color4( RGB (165,42,42));	//brown
	pDC->FillRect(&Bar4,&Color4);


	RECT Bar5;
	Bar5.left = 320;
	Bar5.right = 350;
	Bar5.top = 50; 
	Bar5.bottom = 60;

	CBrush Color5( RGB (255,184,135));	//burlywood
	pDC->FillRect(&Bar5,&Color5);

	RECT Bar6;
	Bar6.left = 320;
	Bar6.right = 350;
	Bar6.top = 60; 
	Bar6.bottom = 70;

	CBrush Color6( RGB (95,158,160));	//cadetblue
	pDC->FillRect(&Bar6,&Color6);


	RECT Bar7;
	Bar7.left = 320;
	Bar7.right = 350;
	Bar7.top = 70; 
	Bar7.bottom = 80;

	CBrush Color7( RGB (127,255,0));	//Chartreuse
	pDC->FillRect(&Bar7,&Color7);


	RECT Bar8;
	Bar8.left = 320;
	Bar8.right = 350;
	Bar8.top = 80; 
	Bar8.bottom = 90;

	CBrush Color8( RGB (210,105,30));	//chocolate
	pDC->FillRect(&Bar8,&Color8);


	RECT Bar9;
	Bar9.left = 320;
	Bar9.right = 350;
	Bar9.top = 90; 
	Bar9.bottom = 100;

	CBrush Color9( RGB (255,127,80));	//coral
	pDC->FillRect(&Bar9,&Color9);


	RECT Bar10;
	Bar10.left = 320;
	Bar10.right = 350;
	Bar10.top = 100; 
	Bar10.bottom = 110;

	CBrush Color10( RGB (100,149,237));	//cornflowerblue
	pDC->FillRect(&Bar10,&Color10);


	RECT Bar11;
	Bar11.left = 320;
	Bar11.right = 350;
	Bar11.top = 110; 
	Bar11.bottom = 120;

	CBrush Color11( RGB (255,248,220));	//cornsilk
	pDC->FillRect(&Bar11,&Color11);


	RECT Bar12;
	Bar12.left = 320;
	Bar12.right = 350;
	Bar12.top = 120; 
	Bar12.bottom = 130;

	CBrush Color12( RGB (220,20,60));	//crimson
	pDC->FillRect(&Bar12,&Color12);


	RECT Bar13;
	Bar13.left = 320;
	Bar13.right = 350;
	Bar13.top = 130; 
	Bar13.bottom = 140;

	CBrush Color13( RGB (0,255,255));	//cyan
	pDC->FillRect(&Bar13,&Color13);


	RECT Bar14;
	Bar14.left = 320;
	Bar14.right = 350;
	Bar14.top = 140; 
	Bar14.bottom = 150;

	CBrush Color14( RGB (0,0,139));	//dark blue
	pDC->FillRect(&Bar14,&Color14);


	RECT Bar15;
	Bar15.left = 320;
	Bar15.right = 350;
	Bar15.top = 150; 
	Bar15.bottom = 160;

	CBrush Color15( RGB (0,139,139));	//dark cyan
	pDC->FillRect(&Bar15,&Color15);


	RECT Bar16;
	Bar16.left = 320;
	Bar16.right = 350;
	Bar16.top = 160; 
	Bar16.bottom = 170;

	CBrush Color16( RGB (184,134,11));	//dark golden rod
	pDC->FillRect(&Bar16,&Color16);


	RECT Bar17;
	Bar17.left = 320;
	Bar17.right = 350;
	Bar17.top = 170; 
	Bar17.bottom = 180;

	CBrush Color17( RGB (169,169,169));	//dark gray
	pDC->FillRect(&Bar17,&Color17);


	RECT Bar18;
	Bar18.left = 320;
	Bar18.right = 350;
	Bar18.top = 180; 
	Bar18.bottom = 190;

	CBrush Color18( RGB (0,100,0));	//dark green
	pDC->FillRect(&Bar18,&Color18);

	RECT Bar19;
	Bar19.left = 320;
	Bar19.right = 350;
	Bar19.top = 190; 
	Bar19.bottom = 200;

	CBrush Color19( RGB (139,0,139));	//dark khaki
	pDC->FillRect(&Bar19,&Color19);


	RECT Bar20;
	Bar20.left = 320;
	Bar20.right = 350;
	Bar20.top = 200; 
	Bar20.bottom = 210;

	CBrush Color20( RGB (85,107,47));	//dark olive green
	pDC->FillRect(&Bar20,&Color20);



	RECT Bar21;
	Bar21.left = 320;
	Bar21.right = 350;
	Bar21.top = 210; 
	Bar21.bottom = 220;

	CBrush Color21( RGB (255,140,0));	//dark orange
	pDC->FillRect(&Bar21,&Color21);


	RECT Bar22;
	Bar22.left = 320;
	Bar22.right = 350;
	Bar22.top = 220; 
	Bar22.bottom = 230;

	CBrush Color22( RGB (153,50,204));	//dark orchid
	pDC->FillRect(&Bar22,&Color22);


	RECT Bar23;
	Bar23.left = 320;
	Bar23.right = 350;
	Bar23.top = 230; 
	Bar23.bottom = 240;

	CBrush Color23( RGB (139,0,0));	//dark red
	pDC->FillRect(&Bar23,&Color23);


	RECT Bar24;
	Bar24.left = 320;
	Bar24.right = 350;
	Bar24.top = 240; 
	Bar24.bottom = 250;

	CBrush Color24( RGB (233,150,122));	//dark salmon
	pDC->FillRect(&Bar24,&Color24);


	RECT Bar25;
	Bar25.left = 320;
	Bar25.right = 350;
	Bar25.top = 250; 
	Bar25.bottom = 260;

	CBrush Color25( RGB (143,188,143));	//dark sea green
	pDC->FillRect(&Bar25,&Color25);


	RECT Bar26;
	Bar26.left = 320;
	Bar26.right = 350;
	Bar26.top = 260; 
	Bar26.bottom = 270;

	CBrush Color26( RGB (72,61,139));	//dark slate blue
	pDC->FillRect(&Bar26,&Color26);


	RECT Bar27;
	Bar27.left = 320;
	Bar27.right = 350;
	Bar27.top = 270; 
	Bar27.bottom = 280;

	CBrush Color27( RGB (40,79,79));	//dark slate gray
	pDC->FillRect(&Bar27,&Color27);


	RECT Bar28;
	Bar28.left=320;
	Bar28.right=350;
	Bar28.top=280;
	Bar28.bottom=290;


	RECT Bar29;
	Bar29.left = 320;
	Bar29.right = 350;
	Bar29.top = 290; 
	Bar29.bottom = 300;

	CBrush Color29( RGB (0,206,209));	//dark turquoise
	pDC->FillRect(&Bar29,&Color29);


	RECT Bar30;
	Bar30.left = 320;
	Bar30.right = 350;
	Bar30.top = 300; 
	Bar30.bottom = 310;

	CBrush Color30( RGB (148,0,211));	//violet
	pDC->FillRect(&Bar30,&Color30);


	RECT Bar31;
	Bar31.left = 320;
	Bar31.right = 350;
	Bar31.top = 310; 
	Bar31.bottom = 320;

	CBrush Color31( RGB (255,20,147));	//deep pink
	pDC->FillRect(&Bar31,&Color31);


	RECT Bar32;
	Bar32.left = 320;
	Bar32.right = 350;
	Bar32.top = 320; 
	Bar32.bottom = 330;

	CBrush Color32( RGB (0,191,255));	//sky blue
	pDC->FillRect(&Bar32,&Color32);



	RECT Bar33;
	Bar33.left = 320;
	Bar33.right = 350;
	Bar33.top = 330; 
	Bar33.bottom = 340;

	CBrush Color33( RGB (105,105,105));	//dim gray
	pDC->FillRect(&Bar33,&Color33);


	RECT Bar34;
	Bar34.left = 320;
	Bar34.right = 350;
	Bar34.top = 340; 
	Bar34.bottom = 350;

	CBrush Color34( RGB (30,144,255));	//dodger blue
	pDC->FillRect(&Bar34,&Color34);



	RECT Bar35;
	Bar35.left = 320;
	Bar35.right = 350;
	Bar35.top = 350; 
	Bar35.bottom = 360;

	CBrush Color35( RGB (178,34,34));	//fire brick
	pDC->FillRect(&Bar35,&Color35);


	RECT Bar36;
	Bar36.left = 320;
	Bar36.right = 350;
	Bar36.top = 360; 
	Bar36.bottom = 370;

	CBrush Color36( RGB (255,250,240));	//floral white
	pDC->FillRect(&Bar36,&Color36);


	RECT Bar37;
	Bar37.left = 320;
	Bar37.right = 350;
	Bar37.top = 370; 
	Bar37.bottom = 380;

	CBrush Color37(RGB (34,139,34));	//forest green
	pDC->FillRect(&Bar37,&Color37);


	RECT Bar38;
	Bar38.left = 320;
	Bar38.right = 350;
	Bar38.top = 380; 
	Bar38.bottom = 390;

	CBrush Color38( RGB (255,0,255));	//fushia
	pDC->FillRect(&Bar38,&Color38);


	RECT Bar39;
	Bar39.left = 320;
	Bar39.right = 350;
	Bar39.top = 390; 
	Bar39.bottom = 400;

	CBrush Color39( RGB (220,220,220));	//gainsboro
	pDC->FillRect(&Bar39,&Color39);



	RECT Bar40;
	Bar40.left = 350;
	Bar40.right = 380;
	Bar40.top = 0; 
	Bar40.bottom = 10;

	CBrush Color40( RGB (248,248,255));	//ghost white
	pDC->FillRect(&Bar40,&Color40);

	RECT Bar41;
	Bar41.left = 350;
	Bar41.right = 380;
	Bar41.top = 10; 
	Bar41.bottom = 20;

	CBrush Color41( RGB (255,215,0));	//gold
	pDC->FillRect(&Bar41,&Color41);




	RECT Bar42;
	Bar42.left = 350;
	Bar42.right = 380;
	Bar42.top = 20; 
	Bar42.bottom = 30;

	CBrush Color42( RGB (218,165,32));	//golden rod
	pDC->FillRect(&Bar42,&Color42);


	RECT Bar43;
	Bar43.left = 350;
	Bar43.right = 380;
	Bar43.top = 30; 
	Bar43.bottom = 40;

	CBrush Color43( RGB (128,128,128));	//gray
	pDC->FillRect(&Bar43,&Color43);



	RECT Bar44;
	Bar44.left = 350;
	Bar44.right = 380;
	Bar44.top = 40; 
	Bar44.bottom = 50;

	CBrush Color44( RGB (0,128,0));	//green
	pDC->FillRect(&Bar44,&Color44);



	RECT Bar45;
	Bar45.left = 350;
	Bar45.right = 380;
	Bar45.top = 50; 
	Bar45.bottom = 60;

	CBrush Color45( RGB (173,255,47));	//green yellow
	pDC->FillRect(&Bar45,&Color45);


	RECT Bar46;
	Bar46.left = 350;
	Bar46.right = 380;
	Bar46.top = 60; 
	Bar46.bottom = 70;

	CBrush Color46( RGB (240,255,240));	//honey dew
	pDC->FillRect(&Bar46,&Color46);


	RECT Bar47;
	Bar47.left = 350;
	Bar47.right = 380;
	Bar47.top = 70; 
	Bar47.bottom = 80;

	CBrush Color47( RGB (255,105,180));	//hotpink
	pDC->FillRect(&Bar47,&Color47);


	RECT Bar48;
	Bar48.left = 350;
	Bar48.right = 380;
	Bar48.top = 80; 
	Bar48.bottom = 90;

	CBrush Color48( RGB (205,92,92));	//indian red
	pDC->FillRect(&Bar48,&Color48);

	RECT Bar49;
	Bar49.left = 350;
	Bar49.right = 380;
	Bar49.top = 90; 
	Bar49.bottom = 100;

	CBrush Color49( RGB(75,0,130));	//indigo
	pDC->FillRect(&Bar49,&Color49);

*/
/*
	RECT Bar50;
	Bar50.left = 350;
	Bar50.right = 380;
	Bar50.top = 100; 
	Bar50.bottom = 110;

	CBrush Color50( RGB (255,240,240));	//ivory
	pDC->FillRect(&Bar50,&Color50);


	RECT Bar51;
	Bar51.left = 350;
	Bar51.right = 380;
	Bar51.top = 110; 
	Bar51.bottom = 120;

	CBrush Color51( RGB (240,230,140));	//khaki
	pDC->FillRect(&Bar51,&Color51);


	RECT Bar52;
	Bar52.left = 350;
	Bar52.right = 380;
	Bar52.top = 120; 
	Bar52.bottom = 130;

	CBrush Color52( RGB (230,230,245));	//lavendar
	pDC->FillRect(&Bar52,&Color52);

	RECT Bar53;
	Bar53.left = 350;
	Bar53.right = 380;
	Bar53.top = 130; 
	Bar53.bottom = 140;

	CBrush Color53( RGB (255,240,245));	//lavendar blush
	pDC->FillRect(&Bar53,&Color53);


	RECT Bar54;
	Bar54.left = 350;
	Bar54.right = 380;
	Bar54.top = 140; 
	Bar54.bottom = 150;

	CBrush Color54( RGB (124,252,0));	//lawngreen
	pDC->FillRect(&Bar54,&Color45);

	RECT Bar55;
	Bar55.left = 350;
	Bar55.right = 380;
	Bar55.top = 150; 
	Bar55.bottom = 160;

	CBrush Color55( RGB (255,250,205));	//lemonchiffon
	pDC->FillRect(&Bar55,&Color55);


	RECT Bar56;
	Bar56.left = 350;
	Bar56.right = 380;
	Bar56.top = 160; 
	Bar56.bottom = 170;

	CBrush Color56( RGB (173,216,230));	//lightblue
	pDC->FillRect(&Bar56,&Color56);


	RECT Bar57;
	Bar57.left = 350;
	Bar57.right = 380;
	Bar57.top = 170; 
	Bar57.bottom = 180;

	CBrush Color57( RGB (240,128,128));	//light coral
	pDC->FillRect(&Bar57,&Color57);


	RECT Bar58;
	Bar58.left = 350;
	Bar58.right = 380;
	Bar58.top = 180; 
	Bar58.bottom = 190;

	CBrush Color58( RGB (224,255,255));	//light cyan
	pDC->FillRect(&Bar58,&Color58);



	RECT Bar59;
	Bar59.left = 350;
	Bar59.right = 380;
	Bar59.top = 190; 
	Bar59.bottom = 200;

	CBrush Color59( RGB (250,250,210));	//light golden yellow
	pDC->FillRect(&Bar59,&Color59);

	RECT Bar60;
	Bar60.left = 350;
	Bar60.right = 380;
	Bar60.top = 200; 
	Bar60.bottom = 210;

	CBrush Color60( RGB (144,238,144));	//lightgreen
	pDC->FillRect(&Bar60,&Color60);


	RECT Bar61;
	Bar61.left = 350;
	Bar61.right = 380;
	Bar61.top = 210; 
	Bar61.bottom = 220;

	CBrush Color61( RGB (211,211,211));	//light gray
	pDC->FillRect(&Bar61,&Color61);


	RECT Bar62;
	Bar62.left = 350;
	Bar62.right = 380;
	Bar62.top = 220; 
	Bar62.bottom = 230;

	CBrush Color62( RGB (255,182,193));	//light pink
	pDC->FillRect(&Bar62,&Color62);


	RECT Bar63;
	Bar63.left = 350;
	Bar63.right = 380;
	Bar63.top = 230; 
	Bar63.bottom = 240;

	CBrush Color63( RGB (255,160,122));	//light salmon
	pDC->FillRect(&Bar63,&Color63);


	RECT Bar64;
	Bar64.left = 350;
	Bar64.right = 380;
	Bar64.top = 240; 
	Bar64.bottom = 250;

	CBrush Color64( RGB (32,178,170));	//lightseagreen
	pDC->FillRect(&Bar64,&Color64);


	RECT Bar65;
	Bar65.left = 350;
	Bar65.right = 380;
	Bar65.top = 250; 
	Bar65.bottom = 260;

	CBrush Color65( RGB (135,206,250));	//lightskyblue
	pDC->FillRect(&Bar65,&Color65);

	RECT Bar66;
	Bar66.left = 350;
	Bar66.right = 380;
	Bar66.top = 260; 
	Bar66.bottom = 270;

	CBrush Color66( RGB (119,136,153));	//light slate gray
	pDC->FillRect(&Bar66,&Color66);

	RECT Bar67;
	Bar67.left = 350;
	Bar67.right = 380;
	Bar67.top = 270; 
	Bar67.bottom = 280;

	CBrush Color67( RGB (176,196,222));	//light steel blue
	pDC->FillRect(&Bar67,&Color67);


	RECT Bar68;
	Bar68.left = 350;
	Bar68.right = 380;
	Bar68.top = 280; 
	Bar68.bottom = 290;

	CBrush Color68( RGB (255,255,224));	//light yellow
	pDC->FillRect(&Bar68,&Color68);


	RECT Bar69;
	Bar69.left = 350;
	Bar69.right = 380;
	Bar69.top = 290; 
	Bar69.bottom = 300;

	CBrush Color69( RGB (0,255,0));	//lime
	pDC->FillRect(&Bar69,&Color69);


	RECT Bar70;
	Bar70.left = 350;
	Bar70.right = 380;
	Bar70.top = 300; 
	Bar70.bottom = 310;

	CBrush Color70( RGB (50,205,50));	//lime green
	pDC->FillRect(&Bar70,&Color70);

	RECT Bar71;
	Bar71.left = 350;
	Bar71.right = 380;
	Bar71.top = 310; 
	Bar71.bottom = 320;

	CBrush Color71( RGB (250,240,230));	//linen
	pDC->FillRect(&Bar71,&Color71);


	RECT Bar72;
	Bar72.left = 350;
	Bar72.right = 380;
	Bar72.top = 320; 
	Bar72.bottom = 330;

	CBrush Color72( RGB (255,0,255));	//magenta
	pDC->FillRect(&Bar72,&Color72);


	RECT Bar73;
	Bar73.left = 350;
	Bar73.right = 380;
	Bar73.top = 330; 
	Bar73.bottom = 340;

	CBrush Color73( RGB (128,0,0));	//maroon
	pDC->FillRect(&Bar73,&Color73);


	RECT Bar74;
	Bar74.left = 350;
	Bar74.right = 380;
	Bar74.top = 340; 
	Bar74.bottom = 350;

	CBrush Color74( RGB (102,205,170));	//medium aquamarine
	pDC->FillRect(&Bar74,&Color74);



	RECT Bar75;
	Bar75.left = 350;
	Bar75.right = 380;
	Bar75.top = 350; 
	Bar75.bottom = 360;

	CBrush Color75( RGB (0,0,205));	//medium blue
	pDC->FillRect(&Bar75,&Color75);


	RECT Bar76;
	Bar76.left = 350;
	Bar76.right = 380;
	Bar76.top = 360; 
	Bar76.bottom = 370;

	CBrush Color76( RGB (186,85,211)); //medium orchid
	pDC->FillRect(&Bar76,&Color76);


	RECT Bar77;
	Bar77.left = 350;
	Bar77.right = 380;
	Bar77.top = 370; 
	Bar77.bottom = 380;

	CBrush Color77( RGB (147,112,219));	//medium purple
	pDC->FillRect(&Bar77,&Color77);


	RECT Bar78;
	Bar78.left = 350;
	Bar78.right = 380;
	Bar78.top = 380; 
	Bar78.bottom = 390;

	CBrush Color78( RGB (60,179,113));	//mediumseagreen
	pDC->FillRect(&Bar78,&Color78);


	RECT Bar79;
	Bar79.left = 350;
	Bar79.right = 380;
	Bar79.top = 390; 
	Bar79.bottom = 400;

	CBrush Color79( RGB (123,104,238));	//medium slate blue
	pDC->FillRect(&Bar79,&Color79);


	RECT Bar80;
	Bar80.left = 380;
	Bar80.right = 410;
	Bar80.top = 0; 
	Bar80.bottom = 10;

	CBrush Color80( RGB (0,250,154));	//medium spring green
	pDC->FillRect(&Bar80,&Color80);

	RECT Bar81;
	Bar81.left = 380;
	Bar81.right = 410;
	Bar81.top = 10; 
	Bar81.bottom = 20;

	CBrush Color81( RGB (72,209,204));	//mediumturquoise
	pDC->FillRect(&Bar81,&Color81);


	RECT Bar82;
	Bar82.left = 380;
	Bar82.right = 410;
	Bar82.top = 20; 
	Bar82.bottom = 30;

	CBrush Color82( RGB (199,21,112));	//mediumvioletred
	pDC->FillRect(&Bar82,&Color82);


	RECT Bar83;
	Bar83.left = 380;
	Bar83.right = 410;
	Bar83.top = 30; 
	Bar83.bottom = 40;

	CBrush Color83( RGB (25,25,112));	//midnightblue
	pDC->FillRect(&Bar83,&Color83);


	RECT Bar84;
	Bar84.left = 380;
	Bar84.right = 410;
	Bar84.top = 40; 
	Bar84.bottom = 50;

	CBrush Color84( RGB (245,255,250));	//mintcream
	pDC->FillRect(&Bar84,&Color84);


	RECT Bar85;
	Bar85.left = 380;
	Bar85.right = 410;
	Bar85.top = 50; 
	Bar85.bottom = 60;

	CBrush Color85( RGB (255,228,225));	//mistyrose
	pDC->FillRect(&Bar85,&Color85);


	RECT Bar86;
	Bar86.left = 380;
	Bar86.right = 410;
	Bar86.top = 60; 
	Bar86.bottom = 70;

	CBrush Color86( RGB (255,228,181));	//moccasin
	pDC->FillRect(&Bar86,&Color86);


	RECT Bar87;
	Bar87.left = 380;
	Bar87.right = 410;
	Bar87.top = 70; 
	Bar87.bottom = 80;

	CBrush Color87( RGB (255,222,173));	//navajowhite
	pDC->FillRect(&Bar87,&Color87);


	RECT Bar88;
	Bar88.left = 380;
	Bar88.right = 410;
	Bar88.top = 80; 
	Bar88.bottom = 90;

	CBrush Color88( RGB (0,0,128));	//navy
	pDC->FillRect(&Bar88,&Color88);


	RECT Bar89;
	Bar89.left = 380;
	Bar89.right = 410;
	Bar89.top = 90; 
	Bar89.bottom = 100;

	CBrush Color89( RGB (253,245,230));	//oldlace
	pDC->FillRect(&Bar89,&Color89);


	RECT Bar90;
	Bar90.left = 380;
	Bar90.right = 410;
	Bar90.top = 100; 
	Bar90.bottom = 110;

	CBrush Color90( RGB (128,128,0));	//olive
	pDC->FillRect(&Bar90,&Color90);


	RECT Bar91;
	Bar91.left = 380;
	Bar91.right = 410;
	Bar91.top = 110; 
	Bar91.bottom = 120;

	CBrush Color91( RGB (107,142,45));	//olivedrab
	pDC->FillRect(&Bar91,&Color91);


	RECT Bar92;
	Bar92.left = 380;
	Bar92.right = 410;
	Bar92.top = 120; 
	Bar92.bottom = 130;

	CBrush Color92( RGB (255,165,0));	//orange
	pDC->FillRect(&Bar92,&Color92);


	RECT Bar93;
	Bar93.left = 380;
	Bar93.right = 410;
	Bar93.top = 130; 
	Bar93.bottom = 140;

	CBrush Color93( RGB (255,69,0));	//orangered
	pDC->FillRect(&Bar93,&Color93);


	RECT Bar94;
	Bar94.left = 380;
	Bar94.right = 410;
	Bar94.top = 140; 
	Bar94.bottom = 150;

	CBrush Color94( RGB (218,112,214));	//orchid
	pDC->FillRect(&Bar94,&Color94);


	RECT Bar95;
	Bar95.left = 380;
	Bar95.right = 410;
	Bar95.top = 150; 
	Bar95.bottom = 160;

	CBrush Color95( RGB (238,232,170));	//palegoldenrod
	pDC->FillRect(&Bar95,&Color95);


	RECT Bar96;
	Bar96.left = 380;
	Bar96.right = 410;
	Bar96.top = 160; 
	Bar96.bottom = 170;

	CBrush Color96( RGB (152,251,152));	//palegreen
	pDC->FillRect(&Bar96,&Color96);


	RECT Bar97;
	Bar97.left = 380;
	Bar97.right = 410;
	Bar97.top = 170; 
	Bar97.bottom = 180;

	CBrush Color97( RGB (175,238,238));	//paleturquoise
	pDC->FillRect(&Bar97,&Color97);


	RECT Bar98;
	Bar98.left = 380;
	Bar98.right = 410;
	Bar98.top = 180; 
	Bar98.bottom = 190;

	CBrush Color98( RGB (219,112,147));	//palevioletred
	pDC->FillRect(&Bar98,&Color98);


	RECT Bar99;
	Bar99.left = 380;
	Bar99.right = 410;
	Bar99.top = 190; 
	Bar99.bottom = 200;

	CBrush Color99( RGB (255,239,213));	//papayawhip
	pDC->FillRect(&Bar99,&Color99);

	RECT Bar100;
	Bar100.left = 380;
	Bar100.right = 410;
	Bar100.top = 200; 
	Bar100.bottom = 210;

	CBrush Color100( RGB (255,218,155));	//peachpuff
	pDC->FillRect(&Bar100,&Color100);


	RECT Bar101;
	Bar101.left = 380;
	Bar101.right = 410;
	Bar101.top = 210; 
	Bar101.bottom = 220;

	CBrush Color101( RGB (205,133,63));	//peru
	pDC->FillRect(&Bar101,&Color101);


	RECT Bar102;
	Bar102.left = 380;
	Bar102.right = 410;
	Bar102.top = 220; 
	Bar102.bottom = 230;

	CBrush Color102( RGB (255,192,203));	//pink
	pDC->FillRect(&Bar102,&Color102);


	RECT Bar103;
	Bar103.left = 380;
	Bar103.right = 410;
	Bar103.top = 230; 
	Bar103.bottom = 240;

	CBrush Color103( RGB (221,160,221));	//plum
	pDC->FillRect(&Bar103,&Color103);


	RECT Bar104;
	Bar104.left = 380;
	Bar104.right = 410;
	Bar104.top = 240; 
	Bar104.bottom = 250;

	CBrush Color104( RGB (176,224,230));	//powder blue
	pDC->FillRect(&Bar104,&Color104);


	RECT Bar105;
	Bar105.left = 380;
	Bar105.right = 410;
	Bar105.top = 250; 
	Bar105.bottom = 260;

	CBrush Color105( RGB (128,0,128));	//purple
	pDC->FillRect(&Bar105,&Color105);


	RECT Bar106;
	Bar106.left = 380;
	Bar106.right = 410;
	Bar106.top = 260; 
	Bar106.bottom = 270;

	CBrush Color106( RGB (255,0,0));	//red
	pDC->FillRect(&Bar106,&Color106);

	RECT Bar107;
	Bar107.left = 380;
	Bar107.right = 410;
	Bar107.top = 270; 
	Bar107.bottom = 280;

	CBrush Color107( RGB (188,143,143));	//rosybrown
	pDC->FillRect(&Bar107,&Color107);


	RECT Bar108;
	Bar108.left = 380;
	Bar108.right = 410;
	Bar108.top = 280; 
	Bar108.bottom = 290;

	CBrush Color108( RGB (65,105,225));	//royalblue
	pDC->FillRect(&Bar108,&Color108);


	RECT Bar109;
	Bar109.left = 380;
	Bar109.right = 410;
	Bar109.top = 290; 
	Bar109.bottom = 300;

	CBrush Color109( RGB (139,69,19));	//saddlebrown
	pDC->FillRect(&Bar109,&Color109);


	RECT Bar110;
	Bar110.left = 380;
	Bar110.right = 410;
	Bar110.top = 300; 
	Bar110.bottom = 310;

	CBrush Color110( RGB (250,128,114));	//salmon
	pDC->FillRect(&Bar110,&Color110);



	RECT Bar111;
	Bar111.left = 380;
	Bar111.right = 410;
	Bar111.top = 310; 
	Bar111.bottom = 320;

	CBrush Color111( RGB (244,164,96));	//sandybrown
	pDC->FillRect(&Bar111,&Color111);



	RECT Bar112;
	Bar112.left = 380;
	Bar112.right = 410;
	Bar112.top = 320; 
	Bar112.bottom = 330;

	CBrush Color112( RGB (46,139,87));	//sea green
	pDC->FillRect(&Bar112,&Color112);



	RECT Bar113;
	Bar113.left = 380;
	Bar113.right = 410;
	Bar113.top = 330; 
	Bar113.bottom = 340;

	CBrush Color113( RGB (255,245,238));	//seashell
	pDC->FillRect(&Bar113,&Color113);


	RECT Bar114;
	Bar114.left = 380;
	Bar114.right = 410;
	Bar114.top = 340; 
	Bar114.bottom = 350;

	CBrush Color114( RGB (160,82,45));	//sienna
	pDC->FillRect(&Bar114,&Color114);



	RECT Bar115;
	Bar115.left = 380;
	Bar115.right = 410;
	Bar115.top = 350; 
	Bar115.bottom = 360;

	CBrush Color115( RGB (192,192,192));	//silver
	pDC->FillRect(&Bar115,&Color115);

	RECT Bar116;
	Bar116.left = 380;
	Bar116.right = 410;
	Bar116.top = 360; 
	Bar116.bottom = 370;

	CBrush Color116( RGB (135,206,235));	//sky blue
	pDC->FillRect(&Bar116,&Color116);


	RECT Bar117;
	Bar117.left = 380;
	Bar117.right = 410;
	Bar117.top = 370; 
	Bar117.bottom = 380;

	CBrush Color117( RGB (106,90,205));	// slate blue
	pDC->FillRect(&Bar117,&Color117);


	RECT Bar118;
	Bar118.left = 380;
	Bar118.right = 410;
	Bar118.top = 380; 
	Bar118.bottom = 390;

	CBrush Color118( RGB (112,128,144));	//slate gray
	pDC->FillRect(&Bar118,&Color118);


	RECT Bar119;
	Bar119.left = 380;
	Bar119.right = 410;
	Bar119.top = 390; 
	Bar119.bottom = 400;

	CBrush Color119( RGB (255,250,250));	//snow
	pDC->FillRect(&Bar119,&Color119);



	RECT Bar120;
	Bar120.left = 410;
	Bar120.right = 440;
	Bar120.top = 0; 
	Bar120.bottom = 10;

	CBrush Color120( RGB (0,255,127));	//springgreen
	pDC->FillRect(&Bar120,&Color120);





	RECT Bar121;
	Bar121.left = 410;
	Bar121.right = 440;
	Bar121.top = 10; 
	Bar121.bottom = 20;

	CBrush Color121( RGB (70,130,180));	//steel blue
	pDC->FillRect(&Bar121,&Color121);



	RECT Bar122;
	Bar122.left = 410;
	Bar122.right = 440;
	Bar122.top = 20; 
	Bar122.bottom = 30;

	CBrush Color122( RGB (210,180,140));	//tan
	pDC->FillRect(&Bar122,&Color122);


	RECT Bar123;
	Bar123.left = 410;
	Bar123.right = 440;
	Bar123.top = 30; 
	Bar123.bottom = 40;

	CBrush Color123( RGB (0,128,128));	//teal
	pDC->FillRect(&Bar123,&Color123);



	RECT Bar124;
	Bar124.left = 410;
	Bar124.right = 440;
	Bar124.top = 40; 
	Bar124.bottom = 50;

	CBrush Color124( RGB (216,191,216));	//thistle
	pDC->FillRect(&Bar124,&Color124);


	RECT Bar125;
	Bar125.left = 410;
	Bar125.right = 440;
	Bar125.top = 50; 
	Bar125.bottom = 60;

	CBrush Color125( RGB (253,99,71));	//tomato
	pDC->FillRect(&Bar125,&Color125);

	RECT Bar126;
	Bar126.left = 410;
	Bar126.right = 440;
	Bar126.top = 60; 
	Bar126.bottom = 70;

	CBrush Color126( RGB (64,224,208));	//turquoise 
	pDC->FillRect(&Bar126,&Color126);


	RECT Bar127;
	Bar127.left = 410;
	Bar127.right = 440;
	Bar127.top = 70; 
	Bar127.bottom = 80;

	CBrush Color127( RGB (238,130,238));	//violet
	pDC->FillRect(&Bar127,&Color127);



	RECT Bar128;
	Bar128.left = 410;
	Bar128.right = 440;
	Bar128.top = 80; 
	Bar128.bottom =90;

	CBrush Color128( RGB (245,222,179));	//wheat
	pDC->FillRect(&Bar128,&Color128);
*/

	// Cross hairs
/*
	RECT Rect;
	Rect.left = 159;
	Rect.right = 161;
	Rect.top = 85;
	Rect.bottom = 115;

	CBrush Brush( RGB (255,255,255));
	pDC->FillRect(&Rect,&Brush);
	
	RECT Rect1;
	Rect1.left = 159;
	Rect1.right = 161;
	Rect1.top = 125;
	Rect1.bottom = 155;

	CBrush Brush1( RGB (255,255,255));
	pDC->FillRect(&Rect1,&Brush1);

	RECT Rect2;
	Rect2.left = 125;
	Rect2.right = 155;
	Rect2.top = 119;
	Rect2.bottom = 121;

	CBrush Brush2( RGB (255,255,255));
	pDC->FillRect(&Rect2,&Brush2);


	RECT Rect3;
	Rect3.left = 165;
	Rect3.right = 195;
	Rect3.top = 119;
	Rect3.bottom = 121;

	CBrush Brush3( RGB (255,255,255));
	pDC->FillRect(&Rect3,&Brush3);*/
	CClientDC dc(this);
	CString a;
		a.Format("Press 'A' to move the Crosshair.         " );
		dc.TextOut(500,160,a);
	//	UpdateData(TRUE);
		UpdateData(FALSE);
	if(x1<=320 && y1 <=240)
	{

	RECT Rect;
	
	Rect.left = x1-1;
	Rect.right = x1+1;
	Rect.top = y1-35;
	Rect.bottom = y1-5;


	//CBrush Brush( RGB (0,255,255));
	//pDC->FillRect(&Rect,&Brush);
	CBrush Brush( RGB (red,green,blue));
	pDC->FillRect(&Rect,&Brush);
	

	RECT Rect1;
	Rect1.left = x1-1;
	Rect1.right = x1+1;	
	Rect1.top = y1+5;
	Rect1.bottom = y1+35;

	//CBrush Brush1( RGB (0,255,255));
	//pDC->FillRect(&Rect1,&Brush1);
	CBrush Brush1( RGB (red,green,blue));
	pDC->FillRect(&Rect1,&Brush1);

	RECT Rect2;
	
	Rect2.left = x1-35;
	Rect2.right = x1-5;
	Rect2.top = y1-1;
	Rect2.bottom = y1+1;

	//CBrush Brush2( RGB (255,0,255));
	//pDC->FillRect(&Rect2,&Brush2);
	CBrush Brush2( RGB (red,green,blue));
	pDC->FillRect(&Rect2,&Brush2);


	RECT Rect3;
	
	Rect3.left = x1+5;
	Rect3.right = x1+35;
	Rect3.top = y1-1;
	Rect3.bottom = y1+1;

	//CBrush Brush3( RGB (255,0,255));
	//pDC->FillRect(&Rect3,&Brush3);
	CBrush Brush3( RGB (red,green,blue));
	pDC->FillRect(&Rect3,&Brush3);

		if((x1!=160 && y1!=120)&&(x1<=320 && y1 <=240))
		{
		CString p;
		p.Format("x : %d , y : %d                                 ",x1,y1        );
		dc.TextOut(500,200,p);
	//	UpdateData(TRUE);
		UpdateData(FALSE);
		}
	}
	if(x1>320 || y1>240)
	{
		CString t;
		t.Format("The crosshair is out of range!                         ");
		dc.TextOut(500,200,t);
	//	UpdateData(TRUE);
		UpdateData(FALSE);
	}


	/*	CClientDC dc(this);
		CString s;
		s.Format("the start value is %d",START1);
		dc.TextOut(500,0,s); 
	CClientDC dc(this);
	CPV320_DisplayDoc::OnSave;
	CString s;
	s.Format("The targetted temperature reading is %d deg C",temp);
	dc.TextOut(500,0,s);*/
/*
	//CEditDlg Dlg(this);	
	CEditDlg Dlg;
	if(Dlg.DoModal()==IDOK)
	{
		UpdateData();
	
	START1=Dlg.m_iSValue;
	UpdateData(FALSE);	
	 
	CClientDC dc(this);
		CString s;
		s.Format("the start value is %3d",START1);
		dc.TextOut(500,0,s);
	}
	*/
	
		//CClientDC dc(this);
		CString s;
		s.Format("Current Start Value: %3d ",START1);
		dc.TextOut(500,0,s);
		UpdateData(FALSE);
		
	/*	CString t;
		t.Format("Default Threshold Value:  35");
		dc.TextOut(500,20,t); */
		
		CString h;
		h.Format("Current Threshold Value: %3d ",value);
		dc.TextOut(500,20,h); 

		}

/////////////////////////////////////////////////////////////////////////////
// CPV320_DisplayView diagnostics

#ifdef _DEBUG
void CPV320_DisplayView::AssertValid() const
{
	CView::AssertValid();
}

void CPV320_DisplayView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPV320_DisplayDoc* CPV320_DisplayView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPV320_DisplayDoc)));
	return (CPV320_DisplayDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPV320_DisplayView message handlers
BOOL CPV320_DisplayView::OnEditAdjust() 
{
		
/*	// TODO: Add your command handler code here
	CClientDC dc(this);
	
//	int start;
	CEditDlg Dlg(this);
//Dlg.m_iSValue = 80;

	if(Dlg.DoModal()==IDOK)
	{
		UpdateData();
	
		START1=Dlg.m_iSValue;
		//start = Dlg.m_iSValue;
	//START1= start;
	//start = GetDlgItemInt(START1);
	/*	CString s;
		s.Format("the start value is %3d",START1);
		dc.TextOut(500,0,s); 
	//	UpdateData(TRUE);
		UpdateData(FALSE); 

		//START1=start;
	Invalidate();
	}
	else{

		dc.TextOut(500,0,"   You pressed CANCEL");
	}
*/
return START1;	//START1=start;
}

void CPV320_DisplayView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CMenu menu;

	menu.LoadMenu(IDR_CONTEXTMENU);
	CMenu *pContextMenu = menu.GetSubMenu(0);
	pContextMenu ->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_RIGHTBUTTON, point.x, point.y,AfxGetMainWnd());
}

void CPV320_DisplayView::OnAdjustAdjustthresholdsetting() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	CThreshold tDlg(this);

	if(tDlg.DoModal()==IDOK)
	{
		UpdateData();
		
		value=tDlg.m_iTValue;
	/*	CString h;
		h.Format("Current Threshold Value: %3d",value);
		dc.TextOut(500,40,h); */
	
		UpdateData(FALSE); 
	}
}

void CPV320_DisplayView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	char lsChar;
	CClientDC dc(this);

	HCURSOR lhCursor;
	lsChar= char(nChar);
	POINT cursorPos;
//	CPoint m_pPoint;
	if(lsChar == 'A')
	{
		lhCursor =AfxGetApp()->LoadStandardCursor(IDC_WAIT);
		SetCursor(lhCursor);
		 GetCursorPos(&cursorPos);
        float x=0;
        x1 = cursorPos.x; 
        float y=0;
        y1 = cursorPos.y;
		y1=y1-40;
	//	x1=m_pPoint.x;
	//	y1=m_pPoint.y;
		Invalidate();
		//UpdateData(False);
			
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);	
}

void CPV320_DisplayView::OnAdjustCrosshaircolorchanger() 
{
	// TODO: Add your command handler code here
	CColorDlg Dlg(this);

	if(Dlg.DoModal()==IDOK)
	{
		
		red=Dlg.m_iRed;
		blue=Dlg.m_iBlue;
		green=Dlg.m_iGreen;
		Invalidate();
		//UpdateData(FALSE); 
	}
}
