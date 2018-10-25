; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPV320_DisplayDoc
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PV320_Display.h"
LastPage=0

ClassCount=10
Class1=CPV320_DisplayApp
Class2=CPV320_DisplayDoc
Class3=CPV320_DisplayView
Class4=CMainFrame

ResourceCount=18
Resource1=IDD_ADJUSTBOX
Class5=CAboutDlg
Resource2=IDD_DIALOG4 (English (U.S.))
Class6=CAdjustDialog
Resource3=IDD_DIALOG2
Resource4=IDR_MAINFRAME
Resource5=IDR_CONTEXTMENU (English (U.S.))
Class7=CColourChangerDlg
Resource6=IDD_DIALOG1
Resource7=IDR_MAINFRAME (English (U.S.))
Resource8=IDD_DIALOG1 (English (U.S.))
Resource9=IDD_DIALOG2 (English (U.S.))
Resource10=IDD_ABOUTBOX (English (U.S.))
Resource11=IDD_DIALOG3 (English (U.S.))
Resource12=IDD_DIALOG3
Class8=CTimersDlg
Resource13=IDD_ADJUSTBOX (English (U.S.))
Resource14=IDD_ABOUTBOX
Class9=CThreshold
Resource15=IDR_CONTEXTMENU
Resource16=IDD_DIALOG4
Class10=CColorDlg
Resource17=IDD_DIALOG5
Resource18=IDD_DIALOG5 (English (U.S.))

[CLS:CPV320_DisplayApp]
Type=0
HeaderFile=PV320_Display.h
ImplementationFile=PV320_Display.cpp
Filter=N
LastObject=ID__ADJUST_CROSSHAIRCOLORCHANGER
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CPV320_DisplayDoc]
Type=0
HeaderFile=PV320_DisplayDoc.h
ImplementationFile=PV320_DisplayDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=ID__PROGRAM_STARTCAMERA

[CLS:CPV320_DisplayView]
Type=0
HeaderFile=PV320_DisplayView.h
ImplementationFile=PV320_DisplayView.cpp
Filter=C
LastObject=CPV320_DisplayView
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_LIVE
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=PV320_Display.cpp
ImplementationFile=PV320_Display.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_OPEN
Command2=ID_FILE_START
Command3=ID_CAPTURE
Command4=ID_LIVE
Command5=ID_SAVE
Command6=ID_TEMP
Command7=ID_APP_EXIT
Command8=ID_ADJUST_ADJUSTTHRESHOLDSETTING
Command9=ID_ADJUST_CROSSHAIRCOLORCHANGER
Command10=ID_TIMER_CAMERAUSAGETIMER
Command11=ID_VIEW_STATUS_BAR
Command12=ID_APP_ABOUT
CommandCount=12

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[CLS:CAdjustDialog]
Type=0
HeaderFile=AdjustDialog.h
ImplementationFile=AdjustDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CAdjustDialog

[DLG:IDD_DIALOG1]
Type=1
Class=?
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_SVALUE,edit,1350639744

[DLG:IDD_ADJUSTBOX]
Type=1
Class=CAdjustDialog
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_RED,edit,1350639744
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BLUE,edit,1350639744
Control7=IDC_STATIC,static,1342308352
Control8=IDC_GREEN,edit,1350639744

[DLG:IDD_DIALOG2]
Type=1
Class=CTimersDlg
ControlCount=15
Control1=IDC_STARTTIME,button,1342242817
Control2=IDC_STOPTIMER,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EXIT,button,1342242816
Control8=IDC_STATICTIME,static,1342308352
Control9=IDC_STATICS,static,1342308352
Control10=IDC_STATICM,static,1342308352
Control11=IDC_STATICH,static,1342308352
Control12=IDC_STATICT,static,1342308352
Control13=IDC_STATICTH,static,1342308352
Control14=IDC_STATICST,static,1342308352
Control15=IDC_STATICET,static,1342308352

[DLG:IDD_DIALOG3]
Type=1
Class=CColourChangerDlg
ControlCount=1
Control1=IDOK,button,1342242816

[CLS:CColourChangerDlg]
Type=0
HeaderFile=ColourChangerDlg.h
ImplementationFile=ColourChangerDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CColourChangerDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG1 (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_SVALUE,edit,1350639744

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_FILE_OPEN
Command2=ID_FILE_START
Command3=ID_CAPTURE
Command4=ID_LIVE
Command5=ID_SAVE
Command6=ID_TEMP
Command7=ID_APP_EXIT
Command8=ID_ADJUST_ADJUSTTHRESHOLDSETTING
Command9=ID_ADJUST_CROSSHAIRCOLORCHANGER
Command10=ID_TIMER_CAMERAUSAGETIMER
Command11=ID_VIEW_STATUS_BAR
Command12=ID_APP_ABOUT
CommandCount=12

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ADJUSTBOX (English (U.S.))]
Type=1
Class=CAdjustDialog
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_RED,edit,1350639744
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BLUE,edit,1350639744
Control7=IDC_STATIC,static,1342308352
Control8=IDC_GREEN,edit,1350639744

[DLG:IDD_DIALOG2 (English (U.S.))]
Type=1
Class=CTimersDlg
ControlCount=15
Control1=IDC_STARTTIME,button,1342242817
Control2=IDC_STOPTIMER,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EXIT,button,1342242816
Control8=IDC_STATICTIME,static,1342308352
Control9=IDC_STATICS,static,1342308352
Control10=IDC_STATICM,static,1342308352
Control11=IDC_STATICH,static,1342308352
Control12=IDC_STATICT,static,1342308352
Control13=IDC_STATICTH,static,1342308352
Control14=IDC_STATICST,static,1342308352
Control15=IDC_STATICET,static,1342308352

[DLG:IDD_DIALOG3 (English (U.S.))]
Type=1
Class=CColourChangerDlg
ControlCount=1
Control1=IDOK,button,1342242816

[MNU:IDR_CONTEXTMENU]
Type=1
Class=CPV320_DisplayDoc
Command1=ID__FILE_OPEN
Command2=ID__PROGRAM_STARTCAMERA
Command3=ID__PROGRAM_CAPTUREIMAGE
Command4=ID__PROGRAM_LIVEDISPLAY
Command5=ID__PROGRAM_READTEMPERATURE
Command6=ID__PROGRAM_SAVEIMAGE
Command7=ID__PROGRAM_EXIT
Command8=ID__ADJUSTTHRESHOLDSETTINGS
Command9=ID__CAMERAUSAGETIMER
CommandCount=9

[MNU:IDR_CONTEXTMENU (English (U.S.))]
Type=1
Class=CPV320_DisplayDoc
Command1=ID__FILE_OPEN
Command2=ID__PROGRAM_STARTCAMERA
Command3=ID__PROGRAM_CAPTUREIMAGE
Command4=ID__PROGRAM_LIVEDISPLAY
Command5=ID__PROGRAM_READTEMPERATURE
Command6=ID__PROGRAM_SAVEIMAGE
Command7=ID__PROGRAM_EXIT
Command8=ID__ADJUST_ADJUSTTHRESHOLDSETTINGS
Command9=ID__ADJUST_CROSSHAIRCOLORCHANGER
Command10=ID__CAMERAUSAGETIMER
CommandCount=10

[CLS:CTimersDlg]
Type=0
HeaderFile=TimersDlg.h
ImplementationFile=TimersDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CTimersDlg

[DLG:IDD_DIALOG4]
Type=1
Class=CThreshold
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TVALUE,edit,1350631552
Control5=IDC_STATICTEXT,static,1342308352

[CLS:CThreshold]
Type=0
HeaderFile=Threshold.h
ImplementationFile=Threshold.cpp
BaseClass=CDialog
Filter=D
LastObject=CThreshold
VirtualFilter=dWC

[DLG:IDD_DIALOG4 (English (U.S.))]
Type=1
Class=CThreshold
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TVALUE,edit,1350631552
Control5=IDC_STATICTEXT,static,1342308352

[DLG:IDD_DIALOG5]
Type=1
Class=CColorDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDITR,edit,1350631552
Control4=IDC_EDITG,edit,1350631552
Control5=IDC_EDITB,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[CLS:CColorDlg]
Type=0
HeaderFile=ColorDlg.h
ImplementationFile=ColorDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CColorDlg

[DLG:IDD_DIALOG5 (English (U.S.))]
Type=1
Class=?
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDITR,edit,1350631552
Control4=IDC_EDITG,edit,1350631552
Control5=IDC_EDITB,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

