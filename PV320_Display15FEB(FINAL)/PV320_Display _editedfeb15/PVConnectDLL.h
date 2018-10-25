/*********************************************************************/
/* This source code is the unpublished, proprietary property of      */
/* Electrophysics Corporation, and is protected by trade secret,     */
/* copyright, and other relevant international law.  It cannot be    */
/* disclosed, modified, or reused for any reason without the         */
/* expressed permission of Electrophysics.                           */
/*                                                                   */
/* Copyright (c)2004, Electrophysics Corp., All rights reserved      */
/*                                                                   */
/* Portions copyright (c)2001-2003 by Scharf Engineering Inc.        */
/*********************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#include "oaidl.h"

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the PVCONNECTDLL_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// PVCONNECTDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef PVCONNECTDLL_EXPORTS
#define PVCONNECTDLL_API __declspec(dllexport)
#else
#define PVCONNECTDLL_API __declspec(dllimport)
#endif

// These Functions Are For Application Use
PVCONNECTDLL_API int               IR_GrabFrame              (int& FrameNo,
                                                              SAFEARRAY** sa);
PVCONNECTDLL_API int               IR_InitBulkTransferUSB    (void);

PVCONNECTDLL_API int               IR_CopyNewPixelFrameBuffer(struct IR_PixelEP *Pix,
                                                              unsigned short *dstPtr,
                                                              int sizeX,
                                                              int sizeY,
                                                              int lineWidth);
PVCONNECTDLL_API int               IR_ClearPixelFramePointer (struct IR_PixelEP *Pix);
PVCONNECTDLL_API struct IR_PixelEP *IR_GetNewPixelFrameBuffer(void);

PVCONNECTDLL_API int               IR_EnableVideoStreaming   (int Mode);
PVCONNECTDLL_API BOOL              IR_CheckDriverStatusUSB   (void);
PVCONNECTDLL_API int               IR_ResetErrorCounters     (void);
PVCONNECTDLL_API int               IR_GetOperatingMode       (void);
PVCONNECTDLL_API int               IR_GetDriverRevision      (int &min,
                                                              int &max);
PVCONNECTDLL_API int               IR_GetHardwareRevision    (int &min,
                                                              int &max);
PVCONNECTDLL_API int               IR_GetSoftwareRevision    (int &min,
                                                              int &max,
                                                              LPTSTR dev);
PVCONNECTDLL_API int               IR_GetCurrentPixelCount   (void);
PVCONNECTDLL_API int               IR_GetPixelCount          (void);
PVCONNECTDLL_API int               IR_GetOffsetX             (void);
PVCONNECTDLL_API int               IR_GetOffsetY             (void);
PVCONNECTDLL_API int               IR_GetVideoSize           (int &sizeX,
                                                              int &sizeY);
PVCONNECTDLL_API int               IR_SetPixelCount          (int Value);
PVCONNECTDLL_API int               IR_SetOffsetX             (int Value);
PVCONNECTDLL_API int               IR_SetOffsetY             (int Value);
PVCONNECTDLL_API int               IR_SetVideoMode           (int Mode);
PVCONNECTDLL_API int               IR_GetSerialData          (BYTE *szSerial);
PVCONNECTDLL_API int               IR_SendSerialData         (BYTE *szSerial,
                                                              int ByteCnt);
PVCONNECTDLL_API int               IR_SetVideoModeFast       (int Mode);
PVCONNECTDLL_API int               IR_GetVideoModeFast       (void);
PVCONNECTDLL_API struct IR_PixelEP *IR_GetPixelFramePointer  (void);

PVCONNECTDLL_API int               IR_GetSerialNumber        (void);
PVCONNECTDLL_API int               IR_GetLensSerialNumber    (void);
PVCONNECTDLL_API void              IR_GetModelNumber         (LPTSTR modelno);
PVCONNECTDLL_API void              IR_GetModelId             (LPTSTR modelid);
PVCONNECTDLL_API void              IR_GetFWVersion           (LPTSTR fwver);
PVCONNECTDLL_API BOOL              IR_SetCalibrationData     (int iris,
                                                              BYTE* encodedCoef,
                                                              BYTE* encodedD2U);
PVCONNECTDLL_API BOOL              IR_ConvertRawToTemp       (int &rtn,
                                                              int gray,
                                                              double convTop,
                                                              double convBottom,
                                                              double tempExt,
                                                              double tempInt,
                                                              double tempPlate,
                                                              BOOL accurateFit,
                                                              double emiss,
                                                              int bc_val ) ;
PVCONNECTDLL_API BOOL              IR_ConvertDiffToTemp      (int &rtn,
                                                              double diffin,
                                                              double tempExt,
                                                              double tempInt,
                                                              double tempPlate,
                                                              BOOL accurateFit,
                                                              double emiss,
                                                              int bc_val ) ;
PVCONNECTDLL_API void              IR_GetDiff                (int gray,
                                                              double &diff,
                                                              double &udiff);
PVCONNECTDLL_API BOOL              IR_SetLicenseFile         (LPTSTR filename);
PVCONNECTDLL_API BOOL              IR_SetLicenseInfo         (LPTSTR keystring);
PVCONNECTDLL_API void              IR_SerialLog              (BOOL enable);

// Camera commands:
// These apply only to the PV320L and PV320A models (non-radiometric):
PVCONNECTDLL_API BOOL              IR_CmdGetSensitivity      (int &sensitivity);
PVCONNECTDLL_API BOOL              IR_CmdSetSensitivity      (int sensitivity);
PVCONNECTDLL_API BOOL              IR_CmdGetAutoExposure     (BOOL &autoexp);
PVCONNECTDLL_API BOOL              IR_CmdSetAutoExposure     (BOOL autoexp);

// These apply only to the PV320T models (radiometric):
PVCONNECTDLL_API BOOL              IR_CmdOptimizeImage       (void);
PVCONNECTDLL_API BOOL              IR_CmdRestoreImage        (void);
PVCONNECTDLL_API BOOL              IR_CmdGetRange            (int &range);
PVCONNECTDLL_API BOOL              IR_CmdSetRange            (int range);
PVCONNECTDLL_API BOOL              IR_CmdGetCameraSpot       (LPTSTR spotStr);
PVCONNECTDLL_API BOOL              IR_CmdGetEncodedCoef      (LPTSTR coef);
PVCONNECTDLL_API BOOL              IR_CmdGetEncodedD2U       (LPTSTR d2u);
PVCONNECTDLL_API BOOL              IR_CmdGetCalibrationData  (int &iris,
                                                              LPTSTR coef,
                                                              LPTSTR d2u);
PVCONNECTDLL_API BOOL              IR_CmdGetCurrentData      (double &cTop,
                                                              double &cBot,
                                                              double &tExt,
                                                              double &tInt,
                                                              double &tPlate,
                                                              BOOL &fit);

// These apply to all models:
PVCONNECTDLL_API BOOL              IR_CmdSetFactoryDefaults  (void);
PVCONNECTDLL_API BOOL              IR_CmdGetPalette          (int &palette);
PVCONNECTDLL_API BOOL              IR_CmdSetPalette          (int palette);
PVCONNECTDLL_API BOOL              IR_CmdGetFrameAveraging   (int &averaging);
PVCONNECTDLL_API BOOL              IR_CmdSetFrameAveraging   (int averaging);
PVCONNECTDLL_API BOOL              IR_CmdGetZoom             (int &zoom);
PVCONNECTDLL_API BOOL              IR_CmdSetZoom             (int zoom);
PVCONNECTDLL_API BOOL              IR_CmdGetLevel            (int &level);
PVCONNECTDLL_API BOOL              IR_CmdSetLevel            (int level) ;
PVCONNECTDLL_API BOOL              IR_CmdGetGain             (int &gain);
PVCONNECTDLL_API BOOL              IR_CmdSetGain             (int gain);
PVCONNECTDLL_API BOOL			   IR_CmdNUCStart			 (LPTSTR retStr);
PVCONNECTDLL_API BOOL			   IR_CmdNUCStatus			 (LPTSTR retStr);
PVCONNECTDLL_API BOOL			   IR_CmdNUCSceneLevel	     (int &level);
PVCONNECTDLL_API BOOL			   IR_CmdNUCAbort			 (void);
PVCONNECTDLL_API BOOL			   IR_CmdNUCContinue		 (LPTSTR retStr);

// Utility routines 
PVCONNECTDLL_API void PVApplyColorLUT(unsigned short *pix16Ptr, int width, int height, int lineWidth, unsigned int *pixRGBPtr, int lineWidthRGB, unsigned int *colorLUT);
PVCONNECTDLL_API int PVCopyTextToClipboard(char *text);
PVCONNECTDLL_API int PVCopyMem(char *srcPtr, char *dstPtr, int count);
PVCONNECTDLL_API BOOL IR_SetPrinter (
  HANDLE hPrinter,  // handle to printer object
  DWORD Level,      // information level
  LPBYTE pPrinter,  // printer data buffer
  DWORD Command     // printer-state command
);

// Return codes for IR_InitBulkTransferUSB
#define IR_INIT_RTN_OK			0
#define IR_INIT_RTN_NOCAMERA	1
#define IR_INIT_RTN_NOLICENSE	2
#define IR_INIT_RTN_NOSERIAL	3

// Palettes:
#define IR_PALETTE_WHITEHOT  0
#define IR_PALETTE_BLACKHOT  1
#define IR_PALETTE_IRONBOW   2
#define IR_PALETTE_SPECTRUM  3
#define IR_PALETTE_MAX_VALUE	3

// Operating Modes
#define MODE_NTSC            0
#define MODE_PAL             1

// CPLD Video Modes
#define IR_VIDEO_NORMAL      0
#define IR_VIDEO_CHECKER     1
#define IR_VIDEO_VERTICAL    2
#define IR_VIDEO_GRADIENT    3

// Operating Modes
#define IR_VIDEO_PAUSE       0
#define IR_VIDEO_RUN         1
#define IR_VIDEO_EXIT        2

// Frame Size
#define EP_FRAME_SIZE_X    320
#define EP_FRAME_SIZE_Y    240

#define IR_MAX_SERIAL       17      // Max Bytes Returned From USB Serial
                                    // (16 bytes of payload + space for the
                                    // string terminator, if needed)

// Number of characters in a license key
#define IR_LICENSE_KEY_LEN	11

// Structure For Frame Processing
struct IR_PixelEP
{
                  // Raw Pixel Data
unsigned short    Data[EP_FRAME_SIZE_X * EP_FRAME_SIZE_Y];
                                            
int               BadScanlines;             // Number Of Bad Scan Lines
int               BufferID;                 // Flag For Tracking
DWORD             FrameNumber;              // Frame Number
int               Ready;                    // Flag Indicating If Frame Ready
};

// Structure For Error Statistics
struct IR_StatsEP
{
int     ScanLines;
int     ScanLinesErr;
int     PixelFrames;
int     PixelFramesErr;
int     BulkBuffers;
int     BulkBuffersDropped;
short   PixelCnt[64];
};

#ifdef __cplusplus
}
#endif
