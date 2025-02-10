// 사용자 정의 FUNCTION
#pragma once

#include "stdAfx.h"
#include "DefineStructCode.h"

// FTDI USB Device Header
#include "ftd2xx.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// USB FT232H DEVICE CONTROL FUNCTION DEFINED
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H DLL 라이브러리 LOAD 및 해제
///////////////////////////////////////////////////////////////////////////////////////////
HWND      m_hOwnerWnd                   = NULL;                                // Owner Window Handle
HWND      m_hMainControlWnd             = NULL;                                // Child Window Handle #1 : Main Control
HWND      m_hHWSetupControlWnd          = NULL;                                // Child Window Handle #2 : H/W Setup & Control
HWND      m_hStageSetupControlWnd       = NULL;                                // Child Window Handle #3 : Stage Setup & Control
HWND      m_hPopupHWSetupControlWnd     = NULL;                                // Popup Window Handle #4 : H/W Setup & Control
HWND      m_hChild5Wnd                  = NULL;                                // Child Window Handle #5 : Etc Control
HWND      m_hChild6Wnd                  = NULL;                                // Child Window Handle #6 : Etc Control
HWND      m_hChild7Wnd                  = NULL;                                // Child Window Handle #7 : Etc Control
HWND      m_hChild8Wnd                  = NULL;                                // Child Window Handle #8 : Etc Control
HWND      m_hChild9Wnd                  = NULL;                                // Child Window Handle #9 : Etc Control
HMODULE   m_hDLLModule                  = NULL;                                // USB FT232 DLL Lib Handle
FT_HANDLE m_hFT232HDevice[MAX_FT232H_HANDLE];                                  // USB FT232 Handle Array
HANDLE    m_hEventHandle[MAX_FT232H_HANDLE];                                   // USE FT232 Event Handle
int       m_nFT232HIndex                = 0;                                   // USB FT232 Handle Index
int       m_nFT232HDeviceUse            = 0;                                   // USB FT232 Device Use?
BOOL      m_bSemImageConnected          = FALSE;                               // USB FT232 SE Image Scan Board Connected Flag
BOOL      m_bBseImageConnected          = FALSE;                               // USB FT232 BSE Image Scan Board Connected Flag
BOOL      m_bScanBridgeConnected        = FALSE;                               // USB FT232 Scan Bridge Board Connected Flag
BOOL      m_bSEImageScanPortErrorFlag   = FALSE;                               // USB FT232 SE Image Scan Board Error Flag
BOOL      m_bBSEImageScanPortErrorFlag  = FALSE;                               // USB FT232 BSE Image Scan Board Error Flag
BOOL      m_bDeviceControlPortErrorFlag = FALSE;                               // USB FT232 SE/BSE Image Scan Control & SEM Device Control Error Flag
DWORD     m_dwFirstTickCount            = 0;                                   // 프로그램 계산 시간 Check를 위한 Tick Count
DWORD     m_dwSecondTickCount           = 0;                                   // 프로그램 계산 시간 Check를 위한 Tick Count
char      m_szErrorMessage[MAX_FT232H_HANDLE][255 + 1];                        // Error Message 저장

CString   m_strMainServerPath   = _T("");                                      // MAIN   SERVER 실행파일 경로
CString   m_strDeviceServerPath = _T("");                                      // DEVICE SERVER 실행파일 경로

///////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H DLL 라이브러리 LOAD 및 해제
///////////////////////////////////////////////////////////////////////////////////////////
FT_HANDLE m_hUSBFT232H_SEImageScan      = NULL;                                // SEM SE     Image Scan FT232H Handle
FT_HANDLE m_hUSBFT232H_BSEImageScan     = NULL;                                // SEM BSE    Image Scan FT232H Handle
FT_HANDLE m_hUSBFT232H_DeviceControl    = NULL;                                // SEM Device Control    FT232H Handle

///////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H DATA COMMAND 버퍼
///////////////////////////////////////////////////////////////////////////////////////////
char m_szFT232H_SbrRxBuffer[MAX_FT232H_READ_BUFFER + 1];  // Scan Bridge Read Buffer
char m_szFT232H_CmdBuffer[MAX_FT232H_COMMAND_BUFFER + 1]; // Scan Bridge Read Buffer
char m_szFT232H_XStrBuffer[MAX_FT232H_XYDSStr_BUFFER + 1];// Scan Bridge XStr Buffer 
char m_szFT232H_YStrBuffer[MAX_FT232H_XYDSStr_BUFFER + 1];// Scan Bridge YStr Buffer
char m_szFT232H_DStrBuffer[MAX_FT232H_XYDSStr_BUFFER + 1];// Scan Bridge DStr Buffer
char m_szFT232H_SStrBuffer[MAX_FT232H_XYDSStr_BUFFER + 1];// Scan Bridge SStr Buffer
char m_szFT232H_EchoCmdStr[MAX_FT232H_COMMAND_BUFFER + 1];// Scan Bridge Echo Command Str  
int  m_nFT232H_CmdCount   = 0;                            // Scan Bridge Command Count
int  m_nFT232H_XStrCount  = 0;                            // Scan Bridge XStr Count
int  m_nFT232H_YStrCount  = 0;                            // Scan Bridge YStr Count
int  m_nFT232H_DStrCount  = 0;                            // Scan Bridge DStr Count
int  m_nFT232H_SStrCount  = 0;                            // Scan Bridge SStr Count
int  m_nFT232H_CommaCount = 0;                            // Scan Bridge Comma Count
int  m_nFT232H_XYDState   = 0;                            // Scan Bridge XYD State Flag
int  m_nFT232H_CommandViewFlag   = 0;                     // Scan Bridge Command View Falg
int  m_nFT232H_EchoCommandEnable = 0;                     // Scan Bridge Echo Command Enable
int  m_nFT232H_EchoCommandFlag   = 0;                     // Scan Bridge Echo Command Flag


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// COM Port 10 or higher port open
// CreateFile("\\\\.\\COM10", ...)
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// OWNER 윈도우 설정 & Main Control, H/W Control, Stagge Control, Etc Control...
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void AfxUSBFT232HSetOwnerWindow(HWND hOwner);
HWND AfxUSBFT232HGetOwnerWindow(void);
void AfxUSBFT232HSetMainControlWindow(HWND hChild);
void AfxUSBFT232HSetHWSetupControlWindow(HWND hChild);
void AfxUSBFT232HSetStageSetupControlWindow(HWND hChild);
void AfxUSBFT232HSetPopupHWSetupControlWindow(HWND hChild);
void AfxUSBFT232HSetChild5Window(HWND hChild);
DWORD AfxGetFirstTickCount(void);                                              // 프로그램 루틴 소요시간 계산을 위한값
DWORD AfxGetSecondTickCount(void);                                             // 프로그램 루틴 소요시간 계산을 위한값


///////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H DLL 라이브러리 LOAD 및 해제
///////////////////////////////////////////////////////////////////////////////////////////

int AfxUSBFT232HLoadDLL();                                                     // USB FT232H DLL 파일을 로드한다
int AfxUSBFT232HFreeDLL();													   // USB FT232H DLL 파일을 메모리에서 제거 한다


///////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H DLL 파일에서 필요한 함수만 설정한다
///////////////////////////////////////////////////////////////////////////////////////////

// USB FT232H DLL 파일의 함수:FT_CreateDeviceInfoList 의 포인터 변수
typedef FT_STATUS(WINAPI *PtrToCreateDeviceInfoList)(LPDWORD);
PtrToCreateDeviceInfoList m_pCreateDeviceInfoList;

// USB FT232H DLL 파일의 함수:FT_GetDeviceInfoList 의 포인터 변수
typedef FT_STATUS(WINAPI *PtrToGetDeviceInfoList)(FT_DEVICE_LIST_INFO_NODE *, LPDWORD);
PtrToGetDeviceInfoList m_pGetDeviceInfoList;

// USB FT232H DLL 파일의 함수:FT_Open 의 포인터 변수
typedef FT_STATUS(WINAPI *PtrToOpen)(PVOID, FT_HANDLE *);
PtrToOpen m_pOpen;

// USB FT232H DLL 파일의 함수:FT_OpenEx 의 포인터 변수
typedef FT_STATUS(WINAPI *PtrToOpenEx)(PVOID, DWORD, FT_HANDLE *);
PtrToOpenEx m_pOpenEx;

// USB FT232H DLL 파일의 함수:FT_ListDevices 의 포인터 변수
typedef FT_STATUS(WINAPI *PtrToListDevices)(PVOID, PVOID, DWORD);
PtrToListDevices m_pListDevices;

// USB FT232H DLL 파일의 함수:FT_Close 의 포인터 변수
typedef FT_STATUS(WINAPI *PtrToClose)(FT_HANDLE);
PtrToClose m_pClose;

// USB FT232H DLL 파일의 함수:FT_Read 의 포인터 변수
typedef FT_STATUS(WINAPI *PtrToRead)(FT_HANDLE, LPVOID, DWORD, LPDWORD);
PtrToRead m_pRead;

// USB FT232H DLL 파일의 함수:FT_Write 의 포인터 변수
typedef FT_STATUS(WINAPI *PtrToWrite)(FT_HANDLE, LPVOID, DWORD, LPDWORD);
PtrToWrite m_pWrite;

// USB FT232H DLL 파일의 함수:FT_ResetDevice 의 포인터 변수
typedef FT_STATUS(WINAPI *PtrToResetDevice)(FT_HANDLE);
PtrToResetDevice m_pResetDevice;

// USB FT232H DLL 파일의 함수:FT_Purge 의 포인터 변수
typedef FT_STATUS(WINAPI *PtrToPurge)(FT_HANDLE, ULONG);
PtrToPurge m_pPurge;

// USB FT232H DLL 파일의 함수:FT_SetTimeouts 의 포인터 변수
typedef FT_STATUS(WINAPI *PtrToSetTimeouts)(FT_HANDLE, ULONG, ULONG);
PtrToSetTimeouts m_pSetTimeouts;

// USB FT232H DLL 파일의 함수:FT_GetStatus 의 포인터 변수
typedef FT_STATUS(WINAPI *PtrToGetStatus)(FT_HANDLE, LPDWORD, LPDWORD, LPDWORD);
PtrToGetStatus m_pGetStatus;

// USB FT232H DLL 파일의 함수:FT_GetQueueStatus 의 포인터 변수
typedef FT_STATUS(WINAPI *PtrToGetQueueStatus)(FT_HANDLE, LPDWORD);
PtrToGetQueueStatus m_pGetQueueStatus;

// USB FT232H DLL 파일의 함수:FT_SetBitMode 의 포인터 변수
typedef FT_STATUS(WINAPI *PtrToSetBitMode)(FT_HANDLE, UCHAR, UCHAR);
PtrToSetBitMode m_pSetBitMode;

// USB FT232H DLL 파일의 함수:FT_SetLatencyTimer 의 포인터 변수
typedef FT_STATUS(WINAPI *PtrToSetLatencyTimer)(FT_HANDLE, UCHAR);
PtrToSetLatencyTimer m_pSetLatencyTimer;

// USB FT232H DLL 파일의 함수:FT_SetUSBParameters 의 포인터 변수
typedef FT_STATUS(WINAPI *PtrToSetUSBParameters)(FT_HANDLE, ULONG, ULONG);
PtrToSetUSBParameters m_pSetUSBParameters;

// USB FT232H DLL 파일의 함수:FT_SetFlowControl 의 포인터 변수
typedef FT_STATUS(WINAPI *PtrToSetFlowControl)(FT_HANDLE, USHORT, UCHAR, UCHAR);
PtrToSetFlowControl m_pSetFlowControl;

// USB FT232H DLL 파일의 함수:FT_SetEventNotification 의 포인터 변수
typedef FT_STATUS(WINAPI *PtrToSetEventNotification)(FT_HANDLE, DWORD, PVOID);
PtrToSetEventNotification m_pSetEventNotification;


FT_STATUS AfxFT232HCreateDeviceInfoList(LPDWORD);                              // DLL 파일의 함수:FT_CreateDeviceInfoList 의 글로벌 함수 명칭
FT_STATUS AfxFT232HGetDeviceInfoList(FT_DEVICE_LIST_INFO_NODE *, LPDWORD);     // DLL 파일의 함수:FT_GetDeviceInfoList 의 글로벌 함수 명칭
FT_STATUS AfxFT232HOpen(PVOID, int);                                           // DLL 파일의 함수:FT_Open 의 글로벌 함수 명칭
FT_STATUS AfxFT232HOpenEx(PVOID, DWORD, int);                                  // DLL 파일의 함수:FT_OpenEx 의 글로벌 함수 명칭
FT_STATUS AfxFT232HListDevices(PVOID, PVOID, DWORD);                           // DLL 파일의 함수:FT_ListDevices 의 글로벌 함수 명칭
FT_STATUS AfxFT232HClose(int);                                                 // DLL 파일의 함수:FT_Close 의 글로벌 함수 명칭
FT_STATUS AfxFT232HRead(int, LPVOID, DWORD, LPDWORD);                          // DLL 파일의 함수:FT_Read 의 글로벌 함수 명칭
FT_STATUS AfxFT232HWrite(int, LPVOID, DWORD, LPDWORD);                         // DLL 파일의 함수:FT_Write 의 글로벌 함수 명칭
FT_STATUS AfxFT232HResetDevice(int);                                           // DLL 파일의 함수:FT_ResetDevice 의 글로벌 함수 명칭
FT_STATUS AfxFT232HPurge(int, ULONG);                                          // DLL 파일의 함수:FT_Purge 의 글로벌 함수 명칭
FT_STATUS AfxFT232HSetTimeouts(int, ULONG, ULONG);                             // DLL 파일의 함수:FT_SetTimeouts 의 글로벌 함수 명칭
FT_STATUS AfxFT232HGetStatus(int, LPDWORD, LPDWORD, LPDWORD);                  // DLL 파일의 함수:FT_GetStatus 의 글로벌 함수 명칭
FT_STATUS AfxFT232HGetQueueStatus(int, LPDWORD);                               // DLL 파일의 함수:FT_GetQueueStatus 의 글로벌 함수 명칭
FT_STATUS AfxFT232HSetBitMode(int, UCHAR, UCHAR);                              // DLL 파일의 함수:FT_SetBitMode 의 글로벌 함수 명칭
FT_STATUS AfxFT232HSetLatencyTimer(int, UCHAR);                                // DLL 파일의 함수:FT_SetLatencyTimer 의 글로벌 함수 명칭
FT_STATUS AfxFT232HSetUSBParameters(int, ULONG, ULONG);                        // DLL 파일의 함수:FT_SetUSBParameters 의 글로벌 함수 명칭
FT_STATUS AfxFT232HSetFlowControl(int, USHORT, UCHAR, UCHAR);                  // DLL 파일의 함수:FT_SetFlowControl 의 글로벌 함수 명칭
FT_STATUS AfxFT232HSetEventNotification(int, DWORD, PVOID);                    // DLL 파일의 함수:FT_SetEventNotification 의 글로벌 함수 명칭




//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H PORT 관련 데이터 전송 및 데이터 획득 함수 설정
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxFT232HPortOpen(int nDevicePort);										   // FT232H USB Port 연결 장치 열기
int AfxFT232HPortClose(int nDevicePort);									   // FT232H USB Port 연결 장치 닫기
int AfxFT232HPortSendCommand(int nPort, WORD wCommand, int nPara);      	   // FT232H Port : 단일 WORD 데이터 전송
int AfxFT232HPortSendMultiCommand(int nPort, WORD *pwScanBuf, int nWords);     // FT232H Port : 멀티 데이터 전송
int AfxFT232HPortSendAvrCommand(int nPort, char *pszCommand, int nVal);		   // FT232H Port : AVR 데이터 전송
int AfxFT232HPortSendAvrCommand(int nPort, char *pszCommand);				   // FT232H : AVR 데이터 전송 (명령어전송)
int AfxFT232HDeviceUse(int nUse);										       // USB FT232H Device 사용여부 설정하기


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H Device Command Control Data
//////////////////////////////////////////////////////////////////////////////////////////////////////////
LPINTEGRATED_COMMAND_STRUCT  m_pIntegrated = NULL;              // Integrated Command & Data

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// SEM SCAN ROTATION CALIBRATION DATA
//////////////////////////////////////////////////////////////////////////////////////////////////////////
LPSEM_SCAN_ROTATION_CALIBRATION_DATA  m_pScanRotCaliData = NULL;   // Scan Rotation Calibration Data



//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------

// GUN HV 설정값 리스트
int m_nGunHVTable[MAX_GUN_HV_TABLE] = { 30000, 25000, 20000, 15000, 10000, 5000, 3000, 2900, 2800, 2700, 2600, 2500, 2400, 2300, 2200,
2100, 2000, 1900, 1800, 1700, 1600, 1500, 1400, 1300, 1200, 1100, 1000, 900, 800, 700, 600, 500 };

// 고압(HV)에 따른 OL 조정(설정)값
int m_nHvOLRatioTable[MAX_OL_RATIO_TABLE] = { 1400, 1200, 1000, 950, 900, 850, 800, 750, 700, 650, 600, 550, 500, 450, 400, 350, 300, 290, 280, 270,
260, 250, 240, 230, 220, 210, 200, 190, 180, 170, 160, 150 };

// 고압(HV)에 따른 SRot 조정(설정)값
int m_nHvSRotRatioTable[MAX_SROT_RATIO_TABLE] = { 1400, 1200, 1000, 950, 900, 850, 800, 750, 700, 650, 600, 550, 500, 450, 400, 350, 300, 290, 280, 270,
260, 250, 240, 230, 220, 210, 200, 190, 180, 170, 160, 150 };

// 고압(HV)에 따른 배율 조정(설정)값
int m_nHvZoomingTable[MAX_HV_ZOOM_TABLE] = { 1400, 1200, 1000, 950, 900, 850, 800, 750, 700, 650, 600, 550, 500, 450, 400, 350, 300, 290, 280, 270,
260, 250, 240, 230, 220, 210, 200, 190, 180, 170, 160, 150 };

// 이미지 스캔 주파수(Freq) 설정값
int m_nSyncFreqTable[MAX_SYNC_FREQ_TABLE] = { 375, 750, 1500, 3000, 6000, 12000, 24000, 48000, 96000, 192000, 384000 };

// Magification (배율)에 릴레이 설정값 
WORD m_MagRelay[MAX_MAG_RELAY_ITEM] = { 0x01, 0x02, 0x04, 0x08 };  // Mx100k 사용 안함

// Mag. Relay 선택시 저항오차에 의한 배율교정
//int m_nZoomXMaxValue[MAX_ZOOM_VALUE_ITEM] = { 4095, 4095, 4095, 4095, 4095 };
//int m_nZoomYMaxValue[MAX_ZOOM_VALUE_ITEM] = { 4095, 4095, 4095, 4095, 4095 };
// 2020.05.25 
// Mag. Relay 선택시 저항오차에 의한 배율교정 : MAX 4095 --> 3509
//int m_nZoomXMaxValue[MAX_ZOOM_VALUE_ITEM] = { 3509, 3509, 3509, 3509, 3509 };
//int m_nZoomYMaxValue[MAX_ZOOM_VALUE_ITEM] = { 3509, 3509, 3509, 3509, 3509 };
// 2020.05.26 
// Mag. Relay 선택시 저항오차에 의한 배율교정 : MAX 3509 --> 3071
//int m_nZoomXMaxValue[MAX_ZOOM_VALUE_ITEM] = { 3071, 3071, 3071, 3071, 3071 };
//int m_nZoomYMaxValue[MAX_ZOOM_VALUE_ITEM] = { 3071, 3071, 3071, 3071, 3071 };
// 2020.05.28 
// Mag. Relay 선택시 저항오차에 의한 배율교정 : MAX 3071 --> 2900
int m_nZoomXMaxValue[MAX_ZOOM_VALUE_ITEM] = { 2900, 2900, 2900, 2900, 2900 };
int m_nZoomYMaxValue[MAX_ZOOM_VALUE_ITEM] = { 2900, 2900, 2900, 2900, 2900 };

// 배율
int m_nMagStepValue[MAX_MAG_STEP] = { 20, 30, 35, 40, 45, 50, 60, 70, 80, 90, 100,	110, 120, 130, 150, 180, 200, 220, 250, 300, 350,
                                      400, 450, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1500, 1800, 2000, 2200, 2500, 3000, 3500, 4000, 4500,
                                      5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 15000, 18000, 20000, 22000, 25000, 30000, 35000, 40000,
                                      45000, 50000, 60000, 70000, 80000, 90000, 100000, 110000, 120000, 130000, 150000, 180000, 200000, 220000, 250000, 300000 };

// WOBBLE TABLE
double m_dSinTable[8] = { 0.0, 0.7, 1.0, 0.7, 0.0, -0.7, -1.0, -0.7 };
int m_nWobblerTable[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

//---------------------------------------------------------------
// SM300 SpotSize에 따라 CL1, CL2에 흐르는 전류값 ( at 30kV )
//---------------------------------------------------------------
// OL_MaxA => 1.18A x [3.3ohm] => [3.9k] ( OL Amp 저항 )
// CL_MaxA => 1.18A x [3.3ohm] => [3.9k] ( CL Amp 저항 )
// 3V/2 = 1.5A (max)
//---------------------------------------------------------------
double I_SM300_CL1[MAX_SM300_SM200_CL12_ITEM] = { 1.0241, 0.9608, 0.8163, 0.7560, 0.6837,
0.6265, 0.5211, 0.4488, 0.3976, 0.3614, 0.3404, 0.3133, 0.3102, 0.3042, 0.2922, 0.2831 };

double I_SM300_CL2[MAX_SM300_SM200_CL12_ITEM] = { 1.0602, 1.0602, 1.0602, 1.0602, 1.0632,
1.0632, 1.0663, 1.0693, 1.0753, 1.0843, 1.0934, 1.1205, 0.9307, 0.8515, 0.8524, 0.8584 };
//---------------------------------------------------------------

//---------------------------------------------------------------
// SM200 SpotSize에 따라 CL1, CL2 전류값 ( at 30kV )
//---------------------------------------------------------------
// OL_MaxA => 1.8A x [2ohm] =         [3.6k] ( OL Amp 저항 )
// CL_MaxA => 1.4A x [2ohm] = 2.8k => [3k]   ( CL Amp 저항 )
// 3V/2 = 1.5A (max)
//---------------------------------------------------------------
double I_SM200_CL1[MAX_SM300_SM200_CL12_ITEM] = { 1.368, 1.240, 1.124, 1.018, 0.917,
0.822, 0.737, 0.662, 0.594, 0.530, 0.477, 0.435, 0.397, 0.371, 0.350, 0.339 };

double I_SM200_CL2[MAX_SM300_SM200_CL12_ITEM] = { 1.137, 1.141, 1.146, 1.145, 1.149,
1.154, 1.154, 1.158, 1.168, 1.189, 1.225, 1.172, 1.141, 1.130, 1.130, 1.130 };
//---------------------------------------------------------------
int m_nDA_CL1[MAX_SM300_SM200_CL12_ITEM];
int m_nDA_CL2[MAX_SM300_SM200_CL12_ITEM];
//double m_dDV_CL1[MAX_SM300_SM200_CL12_ITEM];
//double m_dDV_CL2[MAX_SM300_SM200_CL12_ITEM];
//double m_dV_CL1[MAX_SM300_SM200_CL12_ITEM];
//double m_dV_CL2[MAX_SM300_SM200_CL12_ITEM];
//---------------------------------------------------------------
WORD m_wFilter[MAX_SCAN_FILTER_ITEM] = { 0x0008, 0x0010, 0x0020, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000 };
//---------------------------------------------------------------
//double m_dAmpRk=2.4; // SEM 모델에 따라 기본값을 설정한다 (SM-300A CL:3.9, SM-300B CL:2.4, SM-200A CL:3.0, BK-200:2.4, S-2500히타치:4.4, 200CL USER:3.0, 300CL USER:2.4)
//double m_dRefR=2.0;  // SEM 모델에 따라 기본값을 설정한다 (SM-300A CL:3.3, SM-300B CL:2.0, SM-200A CL:2.0, BK-200:2.0, S-2500히타치:2.0, 200CL USER:2.0, 300CL USER:2.0)
//---------------------------------------------------------------
BYTE m_btSEScanImageData[SCAN_IMAGE_PACKET_SIZE+1];
/*
// Image Buffer는 1280x960 Size이고,
// Weighted Average의 Buffer는 640x480이다.
BYTE m_btImgBufA[MAX_IMG_BUF_HEIGHT * MAX_IMG_BUF_FRAME][MAX_IMG_BUF_WIDTH * MAX_IMG_BUF_FRAME];
BYTE m_btImgBufB[MAX_IMG_BUF_HEIGHT * MAX_IMG_BUF_FRAME][MAX_IMG_BUF_WIDTH * MAX_IMG_BUF_FRAME];
BYTE m_btImgBufC[MAX_IMG_BUF_HEIGHT * MAX_IMG_BUF_FRAME][MAX_IMG_BUF_WIDTH * MAX_IMG_BUF_FRAME];
// Weighted Average
BYTE m_btWAImgBufA[MAX_IMG_BUF_WEIGHT][MAX_IMG_BUF_HEIGHT * MAX_IMG_BUF_FRAME][MAX_IMG_BUF_WIDTH * MAX_IMG_BUF_FRAME];
BYTE m_btWAImgBufB[MAX_IMG_BUF_WEIGHT][MAX_IMG_BUF_HEIGHT * MAX_IMG_BUF_FRAME][MAX_IMG_BUF_WIDTH * MAX_IMG_BUF_FRAME];
BYTE m_btWAImgBufC[MAX_IMG_BUF_WEIGHT][MAX_IMG_BUF_HEIGHT * MAX_IMG_BUF_FRAME][MAX_IMG_BUF_WIDTH * MAX_IMG_BUF_FRAME];
BYTE m_btWAFactor[MAX_IMG_BUF_WEIGHT];
// Image & Bitmap Buffer Pointer
BYTE *m_pBFPtr  = NULL;
BYTE *m_pBFPtrB = NULL;
BYTE *m_pBFPtrC = NULL;
BYTE *m_pBMPtr  = NULL;
BYTE *m_pBMPtrB = NULL;
BYTE *m_pBMPtrC = NULL;
*/
//---------------------------------------------------------------

DWORD m_dwVaccumInfoFirstTime  = 0;
DWORD m_dwVaccumInfoSecondTime = 0;
DWORD m_dwVaccumInfoSendCount  = 0;

// SendMessage 이벤트를 사용하지 않고 Function을 이용하여 직접 USB DATA를 전송할 것인지 선택한다
// TRUE  -> Function을 이용하여 직접 USB DATA를 전송한다
// FALSE -> SendMessage 이벤트를 사용하여 USB DATA를 전송한다
BOOL  m_bDirectUSBSending = FALSE;// TRUE;// FALSE;

// SE SCAN DATA 를 이용한 AUTO MODE EXECUTE
int m_nSEScanDataAutoModeExecute = SE_SCAN_DATA_NORMAL_EXECUTE;

// 배율에 따른 HV 보정값
double m_dOptionMagHVRatio[MAX_GUN_HV_TABLE] = { DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO,
                                                 DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO,
	                                             DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO, DEFAULT_MAG_HV_RATIO };

// 배율 x35k 이상 ZOOM 값 보정율
double m_dOptionMagx35kZoomRatio = 1.0;

// 샘플높이
double m_dSampleHeight = 0.0;
// 샘플넓이
double m_dSampleWidth  = 0.0;

// dWDZoomRatio 백업
double m_dWDZoomRatioBackup = 1.0;

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

/*
#include "..\NanoFlashDevice\SemDataProcess.h"

// SEM Data Process Class
CSemDataProcess * m_pSemDataProcessClass = NULL;
// 연결된 CLIENT SOCKET INDEX 정보
int m_nClientSocketIndexList[MAX_CLIENT_CONNECT + 1];
*/

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////


//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Tools Thread (다용도 순차적 기능처리 쓰레드) Function...
//////////////////////////////////////////////////////////////////////////////////////////////////////////
CWinThread *m_pPublicToolsThread[MAX_PUBLIC_THREAD];         // Public Tools 쓰레드 핸들
LPPUBLICTOOLSPARAMS m_pPublicToolsParams[MAX_PUBLIC_THREAD]; // Array Public Tools 쓰레드 사용변수
int m_nPublicToolsIndex = -1;                                // Public Tools 사용변수 인덱스 


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge Thread Function...
//////////////////////////////////////////////////////////////////////////////////////////////////////////
CWinThread *m_pScanBridgeThread = NULL;                      // Scan Bridge 쓰레드 핸들
LPSCANBRIDGETHREADPARAMS m_pScanBridgeThreadParams = NULL;   // Scan Bridge 쓰레드 사용변수


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// CNC Send Thread Function...(CNC 명령어 순차적 전송 처리 쓰레드)
//////////////////////////////////////////////////////////////////////////////////////////////////////////
CWinThread *m_pCNCSendThread = NULL;                         // CNC Send 쓰레드 핸들
LPSCANBRIDGETHREADPARAMS m_pCNCSendThreadParams = NULL;      // CNC Send 쓰레드 사용변수


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// SEM SE Scan Image Data Thread Function...
//////////////////////////////////////////////////////////////////////////////////////////////////////////
CWinThread *m_pSEImageDataThread = NULL;                     // SE Image Data 쓰레드 핸들
LPSEIMAGEDATATHREADPARAMS m_pSEImageDataThreadParams = NULL; // SEM SE Image Data 쓰레드 사용변수


// 2021.06.15
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Focus Degaussing Thread Function...(포커스 디가우징 명령어 처리 쓰레드)
//////////////////////////////////////////////////////////////////////////////////////////////////////////
CWinThread *m_pFocusDegaussingThread = NULL;                         // Focus Degaussing 쓰레드 핸들
LPFOCUSDEGAUSSINGTHREADPARAMS m_pFocusDegaussingThreadParams = NULL; // Focus Degaussing 쓰레드 사용변수


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void AfxSetMainServerPath(CString strPath);                                     // MAIN   SERVER 실행파일 경로 설정
void AfxSetDeviceServerPath(CString strPath);                                   // DEVICE SERVER 실행파일 경로 설정
CString AfxGetMainServerPath(void);                                             // MAIN   SERVER 실행파일 경로 가져오기
CString AfxGetDeviceServerPath(void);                                           // DEVICE SERVER 실행파일 경로 가져오기

int AfxGetIntegratedDataFromFile(void);											// Integrated : INTEGRATED 파일 불러오기
int AfxSetIntegratedDataToFile(void);                                           // Integrated : INTEGRATED 파일 저장하기
int AfxCheckIntegratedDataError(void);                                          // Integrated : INTEGRATED 데이터 오류 확인

int AfxGetScanRotationCalibrationDataFromFile(void);                            // Integrated : SCAN ROTATION CALIBRATION DATA 파일 불러오기
int AfxSetScanRotationCalibrationDataToFile(void);                              // Integrated : SCAN ROTATION CALIBRATION DATA 파일 저장하기
int AfxScanRotationCalibrationDataInitialize(SEM_SCAN_ROTATION_CALIBRATION_DATA *pSRotCaliData); // Integrated : SCAN ROTATION CALIBRATION DATA 초기화


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
// m_SemVacState
//---------------------------------------------------------------------------
/*
#define  POWER_OFF_STATE     0   // SEM Power Off 상태
#define  AIR_ON_STATE        1   // Air On  상태
#define  VAC_EVAC_STATE      2   // Evacuation Working 상태
#define  VAC_OK_STATE        3   // 진공 OK 상태
#define  HV_ON_STATE         4   // 진공 상태가 HV 사용 가능 상태에 도달함

#define  CNC5_GO_SAM_LOAD    5   // Go to Sample Load Position
#define  CNC5_GO_SAM_UNLOAD  6   // Go to Sample Unload Position

#define  HV_VAC_OK_STATE     7   // GUN 진공OK 및 챔버 진공OK 상태
#define  HV_AIR_ON_STATE     8   // GUN 진공OK 및 챔버 AIR ON 상태
#define  HV_EVAC_STATE       9   // GUN 진공OK 및 챔버 진공진행 상태
*/
//---------------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

//int AfxSystemWaitTime(int nMillisecond);                                      // Utility : Wait 함수 -> [ms] 단위로 작업을 기다린 후, 다음 작업을 실행한다.
int AfxCreateSeImageCommand(void);                                              // Se Command : Command Create & Initilize (SEM Image Command 변수 초기화)
int AfxCreateIntegratedCommand(void);                                           // Integrated : Command Create & Initilize (공용변수 초기화)
int AfxReleaseIntegratedCommand(void);                                          // Integrated : Release Command (공용변수 제거)
INTEGRATED_COMMAND_STRUCT* AfxGetIntegratedPointer(void);                       // Integrated : Get Pointer (공용변수 포인터)
SEM_SCAN_ROTATION_CALIBRATION_DATA * AfxGetScanRotationCalibrationDataPointer(void); // Integrated : Get Pointer (SCAN ROTATION CALIBRATION DATA 포인터)

int AfxSEMSystemInitilize(void);                                                // System Control : SEM System Initilized (시스템 초기화)
int AfxSEMSystemInitilizeHVOff(void);                                           // System Control : SEM System Initilized (시스템 초기화)
int AfxSemModelCLInitialize(int nSemModel, double dAmp, double dRef);           // System Control : SEM CL Model Initilized (CL MODEL 시스템 초기화)
int AfxSEMSystemThreadClose(void);                                              // System Control : SEM System Close (시스템 종료)

//int AfxSetSEMDataProcessClass(CSemDataProcess *pSemDataProcess);              // System Control : SEM DATA PROCESS CLASS 포인터 설정


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Utility : Public Function & Parameters
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxInitilizePublicParameters(void);                                         // Integrated Utility : Public Function & Parameters Initilize (공용함수 및 변수 초기화)
int AfxReleasePublicParameters(void);											// Integrated Utility : Public Function & Parameters Release (공용함수 및 변수 삭제)
int AfxSetSemModel(int nModel);                                                 // Integrated Utility : SEM MODEL 선택
int AfxSetSemModel(int nModel, double dAmp, double dRef);                       // Integrated Utility : SEM MODEL 선택 및 AMP, REF 설정

BOOL AfxGetSEMHVAllUpDownProcessFlag(void);                                     // Integrated Control : Get SEM HV ALL 쓰레드 Process Flag


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge Device Command Control...
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------------------------------------------------------------
// Scan Bridge 쓰레드
int  AfxCreateScanBridgeThread(void);                                           // Scan Bridge : 명령어 및 데이터 수신 처리 쓰레드 생성
UINT AfxThreadScanBridgeProcessing(LPVOID pParam);                              // Scan Bridge : 명령어 및 데이터 처리 쓰레드 함수
int  AfxScanBridgeDataRead(void);                                               // Scan Bridge : 명령어 데이터 수신하기
//--------------------------------------------------------------------------------------------------------
// CNC 초기화 처리 쓰레드
int AfxCreateCNCSendThread(void);                                               // Scan Bridge : CNC 명령어의 순차적 전송 처리 쓰레드 생성
UINT AfxThreadCNCSendProcessing(LPVOID pParam);                                 // Scan Bridge : CNC 명령어 및 데이터 처리 쓰레드 함수
//--------------------------------------------------------------------------------------------------------
// FOCUS DEGAUSSING 처리 쓰레드 : 2021.06.15
int  AfxCreateFocusDegaussingThread(int nWD, int nCoar, int nFine, int nTime);  // FOCUS DEGAUSSING 처리 쓰레드 생성
UINT AfxThreadFocusDegaussingProcessing(LPVOID pParam);                         // FOCUS DEGAUSSING 처리 쓰레드 함수
int  AfxIntegratedFocusDegaussing(int nWDPos=40, int nRunTime=500);             // Z-AXIS(WD)에 따른 FOCUS DEGAUSSING 실행 : 0~500 , 0~50.0[mm] / 실행(소요)시간 [ms]
//--------------------------------------------------------------------------------------------------------
int AfxSetSEMVacuumState(int nState);                                           // Integrated Control : SEM VACUUM STATE 설정
int AfxScanBridgeSetSemStandbyMode(void);                                       // Scan Bridge : SEM StandBy(대기모드) 설정
int AfxSbrCheckSumCommand(void);                                                // Scan Bridge : 수신된 명령어 이상 유무 확인 (Check Sum)
int AfxSbrAssembleCommand(char *pStrBuf);                                       // Scan Bridge : 수신된 명령어 조합
int AfxScanBridgePDCommand(void);												// Scan Bridge : Power Down 상태 자료수신
int AfxScanBridgeARCommand(void);												// Scan Bridge : SEM Air ON/OFF 자료수신 : ON->챔버 진공해제상태, OFF->진공중 또는 진공완료상태
int AfxScanBridgeEVCommand(void);												// Scan Bridge : SEM 현재 진공값 자료수신 : 예) 3.564-E5
int AfxScanBridgeVSCommand(void);												// Scan Bridge : SEM 진공 및 고압상태 자료수신 : 0 ~ 9 까지 상태가 있음(위의 SemVacState 참조)
int AfxScanBridgeVLCommand(void);												// Scan Bridge : SEM Valve 상태정보 수신
int AfxScanBridgeVLCommand(int nWriteFlag, int nValve, char *pszData);          // Scan Bridge : "VL", "AR" -> Valve On/Off State , Valve On/Of 명령 실행
int AfxScanBridgeEMCommand(void);												// Scan Bridge : SEM Emission Current 값 Read(수신)
int AfxScanBridgeRNCommand(void);												// Scan Bridge : MOTOR Read mm per step(1Pulse당 이동거리[mm]) 값 수신 (CNC Board 명령어 자료)
int AfxScanBridgeRNCommand(int nWriteFlag, int nAxis, char *pszData);           // Scan Bridge : "RN" -> Read or Write  mm per step(1Pulse당 이동거리[mm]) 값 수신 (CNC Board 명령어 자료)
int AfxScanBridgeRACommand(void);												// Scan Bridge : MOTOR Read Axis Accelation (각 축의 Accelation 값 수신 및 적용) (CNC Board 명령어 자료)
int AfxScanBridgeRACommand(int nWriteFlag, int nAxis, char *pszData);           // Scan Bridge : "RA","SA" -> Axis Accelation 읽기 또는 쓰기
int AfxScanBridgeRPCommand(void);											    // Scan Bridge : Motor(Valve) 위치 정보 수신
int AfxScanBridgeRPCommand(int nWriteFlag, int nAxis, char *pszData);           // Scan Bridge : "RP","SP" -> Motor 또는 Valve Current Position 읽기 또는 쓰기 (모터 또는 밸브 현 위치값 수신 및 적용)
int AfxScanBridgeRMCommand(void);												// Scan Bridge : "RM" -> Read Maximum Width (모터 축 최대 이동거리[mm] 또는 이동각도[deg])
int AfxScanBridgeRMCommand(int nWriteFlag, int nAxis, char *pszData);           // Scan Bridge : "RM","SM" -> Read or Write  Max Width([mm],[deg]) 값 수신 또는 송신
int AfxScanBridgeSMCommand(int nAxis);                                          // Scan Bridge : "SM" -> Axis Max Width([mm],[deg]) & Home 이동
int AfxScanBridgeMHCommand(int nAxis);                                          // Scan Bridge : "MH" -> Axis Home Move
int AfxScanBridgeMMCommand(int nAxis, int nPM, char *pszData, int nEcho);       // Scan Bridge : "MM" -> Axis Motion Move
int AfxScanBridgeMMCommand(int nAxis, int nPM, char *pszData);                  // Scan Bridge : "MM" -> Axis Motion Move
int AfxScanBridgeXYAxisCenterMoveCommand(void);                                 // Scan Bridge : "MC" -> X-Y Beam Center Position Move
int AfxScanBridgeMCCommand(void);												// Scan Bridge : "MC" -> Read Beam Center Pos (X,Y축의 빔 센터 위치 값 읽기 및 적용한다
int AfxScanBridgeMCCommand(int nWriteFlag, char *pszXData, char *pszYData);     // Scan Bridge : "MC" -> X,Y Beam Center Read or Write
int AfxScanBridgeGetRotaryAreaPulseCommand();                                   // Scan Bridge : "BF" -> Read Rotary Area Pulse 값 요청
int AfxScanBridgeBFCommand(void);												// Scan Bridge : "BF" -> Read Rotary Area Pulse 값 읽기
int AfxScanBridgeBFCommand(int nWriteFlag, char *pszData);                      // Scan Bridge : "BF" -> Set  Rotary Area Pulse 값 설정
int AfxScanBridgeTSCommand(void);												// Scan Bridge : "TS" -> Read TrackBall State (트랙볼의 현재 상태값 읽기 및 적용한다)
int AfxScanBridgeTSCommand(int nWriteFlag, int nCommand, char *pszData);        // Scan Bridge : "TS" -> TrackBall (트랙볼의 관련 명령어 실행한다)
int AfxScanBridgeTCCommand(void);												// Scan Bridge : "TC" -> Read TrackBall Command State (트랙볼의 현재 명령어 상태값 읽기 및 적용한다)
int AfxScanBridgeTBCommand(void);												// Scan Bridge : "TB" -> Read TrackBall Command
int AfxScanBridgeBTCommand(void);												// Scan Bridge : "BT" -> Read BlueTooth Command
int AfxScanBridgeLTCommand(void);												// Scan Bridge : "LT" -> Read Limit SW Status (모터 각 축의 Limit 스위치 상태값을 읽기 및 적용한다
int AfxScanBridgeRBCommand(void);												// Scan Bridge : "RB" -> Read Backlash Pulse 값 읽기 및 적용
int AfxScanBridgeZTCommand(void);												// Scan Bridge : "ZT" -> Z Top Limit Sw Pulse 값 읽기 및 적용
int AfxScanBridgeZTCommand(int nWriteFlag, char *pszData);                      // Scan Bridge : "ZT" -> Z Top Limit Sw Pulse 값 읽기 및 적용
int AfxScanBridgeSBCommand(void);												// Scan Bridge : "SB" -> Sampler Exchange Position Pulse 값 읽기 및 적용 (X, Y, Z, R_Load, R_Unload)
int AfxScanBridgeSBCommand(int nWriteFlag, int nCommand, char *pszData1=NULL, char *pszData2=NULL, char *pszData3=NULL); // Scan Bridge : "SB" -> Sample Position 관련 명령어 적용
int AfxScanBridgeLSCommand(void);												// Scan Bridge : "LS" -> Read Limit SW Stop Status 값 읽기 및 적용
int AfxScanBridgeECCommand(void);                                               // Scan Bridge : Echo Command ( STAGE COMMAND ECHO ) 값 읽기
int AfxScanBridgeVRCommand(void);                                               // Scan Bridge : H/W Version 값 읽기
int AfxScanBridgeULCommand(void);                                               // Scan Bridge : Sample Load / Unload State 값 읽기
int AfxScanBridgeASCommand(void);                                               // Scan Bridge : Axis All Stop 적용
int AfxScanBridgePowerOff(int nMode);                                           // Scan Bridge : Power Off Command 전송 (명령어전송)
int AfxScanBridgeLRMirror(int nMode);                                           // Scan Bridge : Left<->Right Mirro 이미지 좌우 반전
int AfxScanBridgeTBMirror(int nMode);                                           // Scan Bridge : Top<->Bottom Mirro 이미지 상하 반전
int AfxScanBridgeSetXImageAmp(void);                                            // Scan Bridge : XY Magnification Image Calibration -> X(Hor)-Amp 값 설정
int AfxScanBridgeSetXImageAmp(int nXImageAmp);                                  // Scan Bridge : XY Magnification Image Calibration -> X(Hor)-Amp 값 설정
int AfxScanBridgeSetXImageAmpApply(int nAmp);                                   // Scan Bridge : XY Magnification Image Calibration -> X(Hor)-Amp 값 적용
int AfxScanBridgeSetXImageOffset(void);                                         // Scan Bridge : XY Magnification Image Calibration -> X(Hor)-Offset 값 설정
int AfxScanBridgeSetXImageOffset(int nXImageOffset);                            // Scan Bridge : XY Magnification Image Calibration -> X(Hor)-Offset 값 설정
int AfxScanBridgeSetXImageOffsetApply(int nOffset);                             // Scan Bridge : XY Magnification Image Calibration -> X(Hor)-Offset 값 적용
int AfxScanBridgeSetYImageAmp(void);                                            // Scan Bridge : XY Magnification Image Calibration -> Y(Hor)-Amp 값 설정
int AfxScanBridgeSetYImageAmp(int nYImageAmp);                                  // Scan Bridge : XY Magnification Image Calibration -> Y(Hor)-Amp 값 설정
int AfxScanBridgeSetYImageAmpApply(int nAmp);                                   // Scan Bridge : XY Magnification Image Calibration -> Y(Hor)-Amp 값 적용
int AfxScanBridgeSetYImageOffset(void);                                         // Scan Bridge : XY Magnification Image Calibration -> Y(Hor)-Offset 값 설정
int AfxScanBridgeSetYImageOffset(int nYImageOffset);                            // Scan Bridge : XY Magnification Image Calibration -> Y(Hor)-Offset 값 설정
int AfxScanBridgeSetYImageOffsetApply(int nOffset);                             // Scan Bridge : XY Magnification Image Calibration -> Y(Hor)-Offset 값 적용
int AfxScanBridgeSetScanClockAndWaveform(void);    							    // Scan Bridge : Scan Clock(주파수) 변경 및 X,YScan 기본파형 발생
int AfxScanBridgeSetScanClockFramePerSec(void);								    // Scan Bridge : Frame/sec 값에 따라 ScanClk의 주파수만 바꾼다.
int AfxScanBridgeGunHvSMPSOn(void);												// Scan Bridge : GUN HV SMPS ON
int AfxScanBridgeGunHvSMPSOff(void);											// Scan Bridge : GUN HV SMPS OFF
int AfxScanBridgeGunHVOn(void);												    // Scan Bridge : GUN HV ON  (30kV, 3.5kV, 4V)
int AfxScanBridgeGunHVOff(void);												// Scan Bridge : GUN HV OFF (30kV, 3.5kV, 4V)
int AfxScanBridgeSpellmanGunHVOn(void);										    // Scan Bridge : Spellman GUN HV ON  (30kV, 3.5kV, 4V)
int AfxScanBridgeSpellmanGunHVOff(void);										// Scan Bridge : Spellman GUN HV OFF (30kV, 3.5kV, 4V)
int AfxScanBridgeSetGunHVIndex(int nIndex);										// Scan Bridge : Set GUN HV Index (GUN HV 인덱스를 이용한 고압(HV)값 설정하기)
int AfxScanBridgeSetGunHVIndexExecute(int nIndex);								// Scan Bridge : Set GUN HV Index (GUN HV 인덱스를 이용한 고압(HV)값 설정하기)
int AfxScanBridgeSetGunHVValue(int nValue);										// Scan Bridge : Set GUN HV Value (GUN HV 고압(HV)값 설정하기)
int AfxScanBridgeSetGunHVValue(double dValue, BOOL bCalc=FALSE);				// Scan Bridge : Set GUN HV Value (GUN HV 고압(HV)값 설정하기)
int AfxScanBridgeSetGunHVValueVoltage(int nVoltageValue=0);                     // Scan Bridge : Set GUN HV Voltage Value (GUN HV 전압(HV)값 실행)
int AfxScanBridgeGunValveOpen(void);                                            // Scan Bridge : GUN VALVE OPEN
int AfxScanBridgeGunValveClose(void);                                           // Scan Bridge : GUN VALVE CLOSE
int AfxScanBridgeFilamentImageScanStart(void);                                  // Scan Bridge : FILAMENT IMAGE SCAN START
int AfxScanBridgeFilamentImageScanStop(void);                                   // Scan Bridge : FILAMENT IMAGE SCAN STOP
int AfxScanBridgeSetBiasValue(void);										    // Scan Bridge : Set BIAS Value (BIAS 값 설정하기)
int AfxScanBridgeSetBiasValueExecute(void);									    // Scan Bridge : Set BIAS Value (BIAS 값 설정하기)
int AfxScanBridgeSetBiasValue(int nValue);   									// Scan Bridge : Set BIAS Value (BIAS 값 설정하기)
int AfxScanBridgeSetBiasVoltageValue(double dVoltage=0);                        // Scan Bridge : Set BIAS Value (BIAS [V]값 설정하기)
int AfxScanBridgeGetBiasValue(void);										    // Scan Bridge : Set BIAS Value (BIAS 값 가져오기)
int AfxScanBridgeSetFilamentValue(void);									    // Scan Bridge : Set Filament Value (필라멘트 값 설정하기)
int AfxScanBridgeSetFilamentValueExecute(void);								    // Scan Bridge : Set Filament Value (필라멘트 값 설정하기)
int AfxScanBridgeSetFilamentValue(int nValue);									// Scan Bridge : Set Filament Value (필라멘트 값 설정하기)
int AfxScanBridgeSetFilamentVoltageValue(double dVoltage=0.0);                  // Scan Bridge : Set Filament Voltage Value (필라멘트 [V]값 설정하기)
int AfxScanBridgeGetFilamentValue(void);									    // Scan Bridge : Set Filament Value (필라멘트 값 가져오기)
int AfxScanBridgeCollectorOn(void);											    // Scan Bridge : SpellMan Collector ON
int AfxScanBridgeCollectorOff(void);											// Scan Bridge : SpellMan Collector OFF
int AfxScanBridgeSetZoomXControl(void);							                // Scan Bridge : Manification Relay Calibration -> Zoom X Control
int AfxScanBridgeSetZoomYControl(void);							                // Scan Bridge : Manification Relay Calibration -> Zoom Y Control
int AfxScanBridgeSetZoomXControl(int nZoomXValue);							    // Scan Bridge : Manification Relay Calibration -> Zoom X Control
int AfxScanBridgeSetZoomYControl(int nZoomYValue);							    // Scan Bridge : Manification Relay Calibration -> Zoom Y Control
int AfxScanBridgeGetZoomXControl(void);							                // Scan Bridge : Manification Relay Calibration -> Zoom X Control
int AfxScanBridgeGetZoomYControl(void);							                // Scan Bridge : Manification Relay Calibration -> Zoom Y Control
int AfxScanBridgeSetDynamicFocusAB(int nFocusValue);							// Scan Bridge : Dynamic Focus A, B
int AfxScanBridgeSetSyncOn(void);											    // Scan Bridge : Set Sync On/Off
int AfxScanBridgeSetSyncOn(BOOL bAcSyncOn);										// Scan Bridge : Set Sync On/Off
BOOL AfxScanBridgeGetSyncOn(void);											    // Scan Bridge : Get Sync On/Off Flag
int AfxScanBridgeSetOrthogonal(void);								            // Scan Bridge : Orthogonal value set (직교도)
int AfxScanBridgeSetOrthogonal(int nOrthogonal);								// Scan Bridge : Orthogonal value set (직교도)
int AfxScanBridgeGetOrthogonal(void);								            // Scan Bridge : Get Orthogonal value (직교도)
int AfxScanBridgeSetGunScanRelay(BOOL bGunScanCheck);						    // Scan Bridge : Scan Relay -> Gun Scan (Filament Scan) (Filament 이미지 얻기)
BOOL AfxScanBridgeGetGunScanRelay(void);                                        // Scan Bridge : Scan Relay -> Gun Scan (Filament Scan) (Filament 이미지 얻기)
int AfxScanBridgeSetScanRotationValue(int nScanRotValue);					    // Scan Bridge : Set Scan Rotation Value
int AfxSRotCaliGetZoomRelayRatio(int nMagValue);                                // Scan Bridge : Scan Rotation에 따른 Orthogonal, Zoom X-Y 보정값 적용을 위한 Ratio Zoom
int AfxScanBridgeResetScanRotationValue(int nScanRotValue);					    // Scan Bridge : Reset Scan Rotation Value
int AfxScanBridgeSetScanRotation(int nDegreex10);	    					    // Scan Bridge : Scan Rotation (degree x 10)
int AfxScanBridgeSetSRot45XAmpValue(int nValue);                                // Scan Bridge : Scan Rotation 45[deg] X-Amp Value
int AfxScanBridgeSetSRot90XAmpValue(int nValue);                                // Scan Bridge : Scan Rotation 90[deg] X-Amp Value
int AfxScanBridgeSetSRot45YAmpValue(int nValue);                                // Scan Bridge : Scan Rotation 45[deg] Y-Amp Value
int AfxScanBridgeSetSRot90YAmpValue(int nValue);                                // Scan Bridge : Scan Rotation 90[deg] Y-Amp Value
int AfxScanBridgeGetVaccumState(void);										    // Scan Bridge : Get Vaccum State Read 명령어 전송 (진공상태 확인)
int AfxScanBridgeProgramExitAxisPosition(void);								    // Scan Bridge : Program Exit 실행 -> Stage Board Axis Position 만 저장 후 프로그램 종료
int AfxScanBridgeProgramExitPowerOff(void);									    // Scan Bridge : Program Exit 실행 -> Sem PowerOff & Axis Position Saved 실행
int AfxScanBridgeProgramExitDeviceError(void);								    // Scan Bridge : Program Exit 실행 -> 장치오류시 Sem PowerOff 모드로 종료
double AfxScanBridgeAxisMotion(int nAxis, double dDistance, int nEchoFlag);	    // Scan Bridge : Motor Axis Motion
int AfxScanBridgeXmmMotion(double dMM, int nEchoFlag);						    // Scan Bridge : X-Axis [mm] 이동
int AfxScanBridgeYmmMotion(double dMM, int nEchoFlag);						    // Scan Bridge : Y-Axis [mm] 이동
int AfxScanBridgeZmmMotion(double dMM, int nEchoFlag);						    // Scan Bridge : Z-Axis [mm] 이동
int AfxScanBridgeRdegMotion(double dDeg, int nEchoFlag);						// Scan Bridge : R-Axis [deg:상대각도] 이동
int AfxScanBridgeRabsMotion(double dAbsDeg, int nEchoFlag);					    // Scan Bridge : R-Axis [abs_deg:절대각도] 이동
int AfxScanBridgeTdegMotion(double dDeg, int nEchoFlag);						// Scan Bridge : T-Axis [deg:상대각도] 이동
int AfxScanBridgeTmmMotion(double dMM, int nEchoFlag);						    // Scan Bridge : T-Axis [mm] 이동
int AfxScanBridgeSetAxisLimitMotion(int nAxis);                                 // Scan Bridge : Axis Limit 이동 명령
int AfxScanBridgeSetAxisLimitStateSending(int nSending);                        // Scan Bridge : Limit Switch 상태 정보 전송 기능 활성화 설정
int AfxScanBridgeGotoXYZRTSampleLoadPosition(void);							    // Scan Bridge : Go to XTZRT-Sample Loading Position
int AfxScanBridgeGotoXYZRTSampleUnloadPosition(void);						    // Scan Bridge : Go to XTZRT-Sample UnLoading Position
int AfxScanBridgeStageAxisEmergencyStopExecute(void);						    // Scan Bridge : Stage Axis 긴급정지 실행
int AfxScanBridgeStageAxisResetControlExecute(void);						    // Scan Bridge : Stage Reset Control 실행
int AfxScanBridgeSetSEMAirOnOff(void);								            // Scan Bridge : Set SEM Air ON/OFF : ON->챔버 진공해제상태, OFF->진공중 또는 진공완료상태
int AfxScanBridgeSetSEMAirOnExecute(void);                                      // Scan Bridge : Set SEM AIR ON  ( CHAMBER OPEN  )
int AfxScanBridgeSetSEMAirOffExecute(void);                                     // Scan Bridge : Set SEM AIR OFF ( CHAMBER CLOSE )
int AfxScanBridgeSetSEMDirectVentExecute(void);                                 // Scan Bridge : Set SEM VENT ( 강제 VENT, SEM SHUTDOWN 상태에서 사용 )




//////////////////////////////////////////////////////////////////////////////////////////////////////////
// SEM SE Image Device Command Control...
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------------------------------------------------------------
// SE Image 쓰레드
int AfxCreateSEImageDataThread(void);                                           // SE Image Data : SEM SE Image Data 처리 쓰레드 생성
UINT AfxThreadSEImageDataProcessing(LPVOID pParam);                             // SE Image Data : SEM SE Image Data 처리 쓰레드 함수
int AfxSEScanDataImageProcess(LPSEIMAGEDATATHREADPARAMS pThreadParams);         // SE Image Data : 데이터 수신 및 이미지 데이터 생성, 처리 하기

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// BSE Image Device Command Control...
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxBseImageInitilized();													// BSE Control : BSE Image Device Initilized (BSE 시스템 초기화)


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge, Sem SE-Image, BSE Image Device Command Integrated(통합) Control...
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedScintilatorHVOn(void);										    // Integrated Control : Scintillator HV ON : 10kV
int AfxIntegratedScintilatorHVOff(void);									    // Integrated Control : Scintillator HV OFF : 10kV
int AfxIntegratedSpellmanScintilatorHVOn(void);									// Integrated Control : Spellman Scintillator HV ON : 10kV
int AfxIntegratedSpellmanScintilatorHVOff(void);								// Integrated Control : Spellman Scintillator HV OFF : 10kV
int AfxIntegratedPMTHVOn(void);												    // Integrated Control : PMT HV ON
int AfxIntegratedPMTHVOff(void);												// Integrated Control : PMT HV OFF
int AfxIntegratedSpellmanPMTHVOn(void);											// Integrated Control : Spellman PMT HV ON
int AfxIntegratedSpellmanPMTHVOff(void);										// Integrated Control : Spellman PMT HV OFF
int AfxIntegratedSetPMTHVRelayOn(void);    										// Integrated Control : PMT HV Relay ON
int AfxIntegratedSetPMTHVRelayOff(void);   										// Integrated Control : PMT HV Relay OFF
int AfxIntegratedSetDETHVRelayOn(void);    										// Integrated Control : DET HV Relay ON
int AfxIntegratedSetDETHVRelayOff(void);   										// Integrated Control : DET HV Relay OFF
int AfxIntegratedBSEImageOn(void);                                              // Integrated Control : IMAGE CH2 ON ( BSE IMAGE )
int AfxIntegratedBSEImageOff(void);                                             // Integrated Control : IMAGE CH2 OFF( SE  IMAGE )
int AfxIntegratedDETHVOn(void);     											// Integrated Control : DET(Detection) HV ON
int AfxIntegratedDETHVOff(void);     											// Integrated Control : DET(Detection) HV OFF
int AfxIntegratedSetEmissionReceive(void);										// Integrated Control : Emission Current 자동 수신 인터벌 타임 설정
int AfxIntegratedSetEmissionReceiveStop(void);									// Integrated Control : Emission Current 자동 수신 종료
int AfxIntegratedSetSM2500Hv10k(int nIndex);									// Integrated Control : Hitachi SM-2500 HV 10K 설정
int AfxIntegratedSetScanRotationValue(int nValue);								// Integrated Control : Scan Rotation Value 설정
int AfxIntegratedSetSeCommandStartValue(void);                                  // Integrated Control : Program Start SeCommand Value Set
int AfxIntegratedSetScreenMode(int nValue);										// Integrated Control : Screen Mode 설정
int AfxIntegratedSetScanMode(int nScanMode);                                    // Integrated Control : Scan   Mode 설정
int AfxIntegratedScanImageDataCaptureStart(int nScanMode);						// Integrated Control : Scan Image Data Capture 작업 시작
int AfxIntegratedScanImageDataCaptureStart();									// Integrated Control : Scan Image Data Capture 작업 시작
//int AfxIntegratedSlow12ScanImageDataCaptureStart(int nScanMode);				// Integrated Control : Scan Image Data Capture 작업 시작 ( SLOW1/2 )
//int AfxIntegratedSlow12ScanImageDataCaptureStart();							// Integrated Control : Scan Image Data Capture 작업 시작 ( SLOW1/2 )
int AfxIntegratedScanImageDataCaptureStop();									// Integrated Control : Scan Image Data Capture 작업 중지
int AfxIntegratedInitializeParameters(int nSemType);        					// Integrated Control : Initialize Parameters (파라메터 초기화)
int AfxIntegratedSetScanGeneration(int nSM);									// Integrated Control : Scan Generation (이미지 스캔을 위한 신호 생성)
int AfxIntegratedResetScanGeneration(void);									    // Integrated Control : Scan Generation 초기화 (스캔신호 OFF)
int AfxIntegratedSetMagnification(int nMag, int nWD10);							// Integrated Control : 배율 설정 작업
int AfxIntegratedSetZoomValue(int nXData, int nYData, double dZoomRatio);    	// Integrated Control : Zoom 설정하기
double AfxIntegratedFindMagRelayRatio(int nMag);		    					// Integrated Control : 배율에 따른 릴레이 동작(설정)과 비율값 계산
int AfxIntegratedSetCL1(void);													// Integrated Control : CL1 값을 설정
int AfxIntegratedSetCL2(void);													// Integrated Control : CL2 값을 설정
int AfxIntegratedSetCL1(int nCL1);												// Integrated Control : CL1 값을 설정
int AfxIntegratedSetCL2(int nCL2);												// Integrated Control : CL2 값을 설정
int AfxIntegratedSetCL1(int nSpotSize, int nCL1);								// Integrated Control : CL2 값을 설정
int AfxIntegratedSetCL2(int nSpotSize, int nCL2);								// Integrated Control : CL2 값을 설정
int AfxIntegratedGetCL1(void);													// Integrated Control : CL1 값을 설정
int AfxIntegratedGetCL2(void);													// Integrated Control : CL2 값을 설정
int AfxIntegratedGetCL1(int nSpotSize);											// Integrated Control : CL1 값 읽기
int AfxIntegratedGetCL2(int nSpotSize);											// Integrated Control : CL2 값 읽기
int AfxIntegratedSetOL(int nCoarse, int nFine);									// Integrated Control : OL 값을 설정
int AfxIntegratedSetFocusCoarse(int nCoarse);                                   // Integrated Control : Focus Coarse 설정 및 실행
int AfxIntegratedSetWDAutoAdjustFocusCoarse(int nWDPos);                        // Integrated Control : WD 변화에 따른 Focus Coarse 자동설정
//int AfxIntegratedSetWDAutoAdjustFocusCoarse(double dZCurPos);                 // Integrated Control : WD 변화에 따른 Focus Coarse 자동설정
int AfxIntegratedSetWobblerOLC(int nWobbblerCoarse);                            // Integrated Control : WOBBLER 를 위한 OLC 값을 설정
int AfxIntegratedSetWobblerSTX(int nWobbblerStigX);                             // Integrated Control : WOBBLER 를 위한 STX 값을 설정
int AfxIntegratedSetWobblerSTY(int nWobbblerStigY);                             // Integrated Control : WOBBLER 를 위한 STY 값을 설정
int AfxIntegratedGetCLSpotSize();                                               // Integrated Control : CL 교정용 Spot Size
int AfxIntegratedSetCLSpotSize(int nSpotSize);                                  // Integrated Control : CL 교정용 Spot Size Setting
int AfxIntegratedSetSpotSize();                                                 // Integrated Control : Spot Size Setting (장비설정)
int AfxIntegratedSetSpotSize(int nSpotSize);                                    // Integrated Control : Spot Size Setting
int AfxIntegratedGetSpotSize();                                                 // Integrated Control : Spot Size Setting (가져오기)
int AfxIntegratedSetWobble();                                                   // Integrated Control : Wobble 장비값 설정
int AfxIntegratedSetWobble(int nSpotSize);                                      // Integrated Control : Wobble 값 Setting
void AfxIntegratedRunWobble(BOOL bRun=FALSE);                                   // Integrated Control : Wobble 실행
int AfxIntegratedGetWobble(void);                                               // Integrated Control : Wobble 값   
int AfxIntegratedSetImageShiftInitilize();                                      // Integrated Control : Image Shift Initilize (장비설정)
int AfxIntegratedSetImageShiftX();                                              // Integrated Control : Image Shift X Setting (장비설정)
int AfxIntegratedSetImageShiftX(int nISX);                                      // Integrated Control : Image Shift X Setting
int AfxIntegratedGetImageShiftX();                                              // Integrated Control : Image Shift X Setting (가져오기)
int AfxIntegratedSetImageShiftY();                                              // Integrated Control : Image Shift Y Setting (장비설정)
int AfxIntegratedSetImageShiftY(int nISY);                                      // Integrated Control : Image Shift Y Setting
int AfxIntegratedGetImageShiftY();                                              // Integrated Control : Image Shift Y Setting (가져오기)
int AfxIntegratedSetGunAlignX(void);											// Integrated Control : Gun Align X 값을 설정 (장비설정)
int AfxIntegratedSetGunAlignX(int nGAX);		    							// Integrated Control : Gun Align X 값을 설정
int AfxIntegratedGetGunAlignX(void);											// Integrated Control : Gun Align X 값을 설정 (가져오기)
int AfxIntegratedSetGunAlignY(void);											// Integrated Control : Gun Align Y 값을 설정 (장비설정)
int AfxIntegratedSetGunAlignY(int nGAY);										// Integrated Control : Gun Align Y 값을 설정
int AfxIntegratedGetGunAlignY(void);											// Integrated Control : Gun Align Y 값을 설정 (가져오기)
int AfxIntegratedSetBeamAlignX(void);											// Integrated Control : Beam Align X 값을 설정 (장비설정)
int AfxIntegratedSetBeamAlignX(int nBAX);		    							// Integrated Control : Beam Align X 값을 설정
int AfxIntegratedGetBeamAlignX(void);											// Integrated Control : Beam Align X 값을 설정 (가져오기)
int AfxIntegratedSetBeamAlignY(void);											// Integrated Control : Beam Align Y 값을 설정 (장비설정)
int AfxIntegratedSetBeamAlignY(int nBAY);										// Integrated Control : Beam Align Y 값을 설정
int AfxIntegratedGetBeamAlignY(void);											// Integrated Control : Beam Align Y 값을 설정 (가져오기)
int AfxIntegratedSetStigX();                                                    // Integrated Control : Stig X Setting (장비설정)
int AfxIntegratedSetStigX(int nStigX);                                          // Integrated Control : Stig X Setting
int AfxIntegratedGetStigX();                                                    // Integrated Control : Stig X Setting (가져오기)
int AfxIntegratedSetStigY();                                                    // Integrated Control : Stig Y Setting (장비설정)
int AfxIntegratedSetStigY(int nStigY);                                          // Integrated Control : Stig Y Setting
int AfxIntegratedGetStigY();                                                    // Integrated Control : Stig Y Setting (가져오기)
int AfxIntegratedSetContrast(void);									            // Integrated Control : Contrast Value 설정 (장비설정)
int AfxIntegratedSetContrastZero(void);									        // Integrated Control : Contrast Value Zero 설정 (장비설정)
int AfxIntegratedSetContrast(int nValue);									    // Integrated Control : Contrast Value 설정
int AfxIntegratedGetContrast(void);									            // Integrated Control : Contrast Value 설정 (가져오기)
int AfxIntegratedSetBrightness(void);                                           // Integrated Control : Brightness Value 설정 (장비설정)
int AfxIntegratedSetBrightness(int nValue);                                     // Integrated Control : Brightness Value 설정
int AfxIntegratedGetBrightness(void);                                           // Integrated Control : Brightness Value 설정 (가져오기)
int AfxIntegratedSetWDCompensation(void);										// Integrated Control : WD에 따른 OL_Coarse, ScanRotation, Zooming, MinMag 보정값 설정
int AfxIntegratedSetWDOLSrotZoomingLinearize(void);								// Integrated Control : WD에 따른 OL_Coarse, ScanRotation, Zooming, MinMag 보정값 10등분 선형화 작업
int AfxIntegratedFindWDValue(int nDAVal);    									// Integrated Control : Focus Coarse에 따른 OL_WD 값 찾기
int AfxIntegratedLensCoilCurrentMinimum(void);                                  // Integrated Control : Lens Coil에 흐르는 전류 최소화
int AfxSetSEMGunHvIndex(int nIndex=0, BOOL bReset=FALSE);                       // Integrated Control : SEM Gun HV Index 설정
int AfxGetSEMGunHvIndex(void);                                                  // Integrated Control : SEM Gun HV Index 가져오기
double AfxGetSEMGunHvVoltage(void);                                             // Integrated Control : Get SEM Gun HV Voltage
double AfxGetSEMGunHvBackupVoltage(void);                                       // Integrated Control : Get SEM Gun HV Backup Current Voltage 
int AfxSetSEMFilamentValue(int nTarget = 0, BOOL bReset = FALSE);               // Integrated Control : Filament Value 설정
double AfxGetSEMFilamentVoltage(void);                                          // Integrated Control : Get SEM Filament Voltage
double AfxGetSEMFilamentBackupVoltage(void);                                    // Integrated Control : Get SEM Filament Backup Current Voltage 
double AfxGetSEMFilamentStartVoltage(void);                                     // Integrated Control : Get SEM Filament Start Voltage
double AfxGetSEMFilamentStopVoltage(void);                                      // Integrated Control : Get SEM Filament Stop Voltage
int AfxSetSEMBiasValue(int nTarget = 0, BOOL bReset = FALSE);                   // Integrated Control : Bias Value 설정
double AfxGetSEMBiasVoltage(void);                                              // Integrated Control : Get SEM Bias Voltage
double AfxGetSEMBiasBackupVoltage(void);                                        // Integrated Control : Get SEM Bias Backup Current Voltage 
double AfxGetSEMBiasStartVoltage(void);                                         // Integrated Control : Get SEM Bias Start Voltage
double AfxGetSEMBiasStopVoltage(void);                                          // Integrated Control : Get SEM Bias Stop Voltage
int AfxSetSEMMagnificationIndex(int nIndex);                                    // Integrated Control : SEM Magnification 설정
int AfxGetSEMMagnificationIndex(void);                                          // Integrated Control : SEM Magnification Index 가져오기
int AfxSetSEMOLWDValue(int nOLWD);                                              // Integrated Control : SEM OL WD 설정
int AfxSetSEMFocusCoarse(int nCoarse);                                          // Integrated Control : SEM Focus Coarse 설정
int AfxSetSEMFocusFine(int nFine);                                              // Integrated Control : SEM Focus Fine 설정
int AfxGetSEMFocusCoarse(void);                                                 // Integrated Control : SEM Focus Coarse 값
int AfxGetSEMFocusFine(void);                                                   // Integrated Control : SEM Focus Fine 값
int AfxGetSEMEmissionCurrent(void);                                             // Integrated Control : SEM Emission Current 300[ms] 단위로 자동 받기

int AfxSetSEMGunHVTimeDelayData(BOOL bTimeDelay, double dUpVoltage, double dDownVoltage, double dMaxVoltage, double dMinVoltage, double dCurVoltage, double dStartVoltage, double dStopVoltage, double dStepVoltage);    // Integrated Control : SEM Gun Hv Up/Down Time Delay 변수 설정
int AfxSetSEMFilamentTimeDelayData(BOOL bTimeDelay, double dUpVoltage, double dDownVoltage, double dMaxVoltage, double dMinVoltage, double dCurVoltage, double dStartVoltage, double dStopVoltage, double dStepVoltage); // Integrated Control : SEM Filament Up/Down Time Delay 변수 설정
int AfxSetSEMBiasTimeDelayData(BOOL bTimeDelay, double dUpVoltage, double dDownVoltage, double dMaxVoltage, double dMinVoltage, double dCurVoltage, double dStartVoltage, double dStopVoltage, double dStepVoltage);     // Integrated Control : SEM Bias Up/Down Time Delay 변수 설정

int AfxGetSEMStigXLowLimit(void);                                               // Integrated Control : Get Stig-X Low  Limit 값 
int AfxGetSEMStigXHighLimit(void);                                              // Integrated Control : Get Stig-X High Limit 값 
int AfxGetSEMStigYLowLimit(void);                                               // Integrated Control : Get Stig-Y Low  Limit 값 
int AfxGetSEMStigYHighLimit(void);                                              // Integrated Control : Get Stig-Y High Limit 값 
int AfxGetSEMStigXReference(void);                                              // Integrated Control : Get Stig-X Reference  값 
int AfxGetSEMStigYReference(void);                                              // Integrated Control : Get Stig-Y Reference  값 
int AfxGetSEMStigXValue(void);                                                  // Integrated Control : Get Stig-X Value 값 
int AfxGetSEMStigYValue(void);                                                  // Integrated Control : Get Stig-Y Value 값 
int AfxSetSEMStigXLowLimit(int nLimit);                                         // Integrated Control : Set Stig-X Low  Limit 값 
int AfxSetSEMStigXHighLimit(int nLimit);                                        // Integrated Control : Set Stig-X High Limit 값 
int AfxSetSEMStigYLowLimit(int nLimit);                                         // Integrated Control : Set Stig-Y Low  Limit 값 
int AfxSetSEMStigYHighLimit(int nLimit);                                        // Integrated Control : Set Stig-Y High Limit 값 
int AfxSetSEMStigXReference(int nRef);                                          // Integrated Control : Set Stig-X Reference  값 
int AfxSetSEMStigYReference(int nRef);                                          // Integrated Control : Set Stig-Y Reference  값 
int AfxGetSEMZoomXMax(void);                                                    // Integrated Control : Get Zoom X-Max 값 
int AfxGetSEMZoomYMax(void);                                                    // Integrated Control : Get Zoom Y-Max 값 
int AfxGetSEMZoomXValue(void);                                                  // Integrated Control : Get Zoom X-Value 값 
int AfxGetSEMZoomYValue(void);                                                  // Integrated Control : Get Zoom Y-Value 값 
int AfxGetSEMXScanAmp(void);                                                    // Integrated Control : Scan Mode 에 따른 X Image Amp
int AfxGetSEMXScanOffset(void);                                                 // Integrated Control : Scan Mode 에 따른 X Image Offset
int AfxGetSEMYScanAmp(void);                                                    // Integrated Control : Scan Mode 에 따른 Y Image Amp
int AfxGetSEMYScanOffset(void);                                                 // Integrated Control : Scan Mode 에 따른 Y Image Offset
int AfxGetSEMSpotSizeCL1(void);                                                 // Integrated Control : Spot Size에 따른 CL1 값
int AfxGetSEMSpotSizeCL2(void);                                                 // Integrated Control : Spot Size에 따른 CL2 값
int AfxGetSEMSkipPixelCount(void);                                              // Integrated Control : Scan Mode에 따른 Skip Pixel 갯수 값
int AfxGetSEMOverSampleCount(void);                                             // Integrated Control : Scan Mode에 따른 Over Sample 갯수 값
int AfxGetSEMFrameFreqCount(void);                                              // Integrated Control : Scan Mode에 따른 Frame / [Sec] 1초당 프레임 갯수 값
int AfxGetSEMXScanUpValue(void);                                                // Integrated Control : Scan Mode에 따른 X Scan Up 값
int AfxGetSEMYScanUpValue(void);                                                // Integrated Control : Scan Mode에 따른 Y Scan Up 값
int AfxGetSEMXScanDownValue(void);                                              // Integrated Control : Scan Mode에 따른 X Scan Down 값
int AfxGetSEMYScanDownValue(void);                                              // Integrated Control : Scan Mode에 따른 Y Scan Down 값
int AfxGetSEMXScanRot45DegValue(void);                                          // Integrated Control : Scan Mode에 따른 X Scan Rotation 45 Deg 값
int AfxGetSEMXScanRot90DegValue(void);                                          // Integrated Control : Scan Mode에 따른 X Scan Rotation 90 Deg 값
int AfxGetSEMYScanRot45DegValue(void);                                          // Integrated Control : Scan Mode에 따른 Y Scan Rotation 45 Deg 값
int AfxGetSEMYScanRot90DegValue(void);                                          // Integrated Control : Scan Mode에 따른 Y Scan Rotation 90 Deg 값
int AfxSetSEMXScanRot45DegValue(int nValue);                                    // Integrated Control : Scan Mode에 따른 X Scan Rotation 45 Deg 값 설정
int AfxSetSEMXScanRot90DegValue(int nValue);                                    // Integrated Control : Scan Mode에 따른 X Scan Rotation 90 Deg 값 설정
int AfxSetSEMYScanRot45DegValue(int nValue);                                    // Integrated Control : Scan Mode에 따른 Y Scan Rotation 45 Deg 값 설정
int AfxSetSEMYScanRot90DegValue(int nValue);                                    // Integrated Control : Scan Mode에 따른 Y Scan Rotation 90 Deg 값 설정
int AfxGetSEMREDScanFilterFactorValue(void);                                    // Integrated Control : RED   Scan Mode의 Filer Factor 값
int AfxGetSEMFASTScanFilterFactorValue(void);                                   // Integrated Control : FAST  Scan Mode의 Filer Factor 값
int AfxGetSEMSLOW1ScanFilterFactorValue(void);                                  // Integrated Control : SLOW1 Scan Mode의 Filer Factor 값
int AfxGetSEMSLOW2ScanFilterFactorValue(void);                                  // Integrated Control : SLOW2 Scan Mode의 Filer Factor 값
int AfxGetSEMPHOTOScanFilterFactorValue(void);                                  // Integrated Control : PHOTO Scan Mode의 Filer Factor 값
int AfxSetSEMREDScanFilterFactorValue(int nValue);                              // Integrated Control : RED   Scan Mode의 Filer Factor 값
int AfxSetSEMFASTScanFilterFactorValue(int nValue);                             // Integrated Control : FAST  Scan Mode의 Filer Factor 값
int AfxSetSEMSLOW1ScanFilterFactorValue(int nValue);                            // Integrated Control : SLOW1 Scan Mode의 Filer Factor 값
int AfxSetSEMSLOW2ScanFilterFactorValue(int nValue);                            // Integrated Control : SLOW2 Scan Mode의 Filer Factor 값
int AfxSetSEMPHOTOScanFilterFactorValue(int nValue);                            // Integrated Control : PHOTO Scan Mode의 Filer Factor 값
int AfxGetSEMCorrectionWDMaxValue(void);                                        // Integrated Control : WD에 따른 보정(Correction) -> WD Max 값
int AfxSetSEMCorrectionWDMaxValue(int nValue);                                  // Integrated Control : WD에 따른 보정(Correction) -> WD Max 값
int AfxGetSEMOLWDx10Value(void);                                                // Integrated Control : WD 현재 위치값 (x10)
int AfxGetSEMCorrectionWDZAxisValue(void);                                      // Integrated Control : WD에 따른 보정(Correction) -> WD Z-Axis 값
int AfxSetSEMCorrectionWDZAxisValue(int nWD);                                   // Integrated Control : WD에 따른 보정(Correction) -> WD Z-Axis 값
int AfxGetSEMCorrectionWDOLCValue(void);                                        // Integrated Control : WD에 따른 보정(Correction) -> WD OLC 값
int AfxSetSEMCorrectionWDOLCValue(int nValue);                                  // Integrated Control : WD에 따른 보정(Correction) -> WD OLC 값
int AfxGetSEMCorrectionWDSRotation(void);                                       // Integrated Control : WD에 따른 보정(Correction) -> WD S-Rot 값
int AfxSetSEMCorrectionWDSRotation(int nValue);                                 // Integrated Control : WD에 따른 보정(Correction) -> WD S-Rot 값
int AfxGetSEMSRotationValue(void);                                              // Integrated Control : Scan Rotation 값
int AfxSetSEMSRotationValue(int nValue);                                        // Integrated Control : Scan Rotation 값
int AfxGetSEMCorrectionWDZoomValue(void);                                       // Integrated Control : WD에 따른 보정(Correction) -> WD Zoom 값
int AfxSetSEMCorrectionWDZoomValue(int nValue);                                 // Integrated Control : WD에 따른 보정(Correction) -> WD Zoom 값
int AfxGetSEMCorrectionWDMinMagValue(void);                                     // Integrated Control : WD에 따른 보정(Correction) -> WD Min Mag 값
int AfxSetSEMCorrectionWDMinMagValue(int nValue);                               // Integrated Control : WD에 따른 보정(Correction) -> WD Min Mag 값
int AfxGetSEMCorrectionWDMinMag(int nWD, BOOL bOrig = FALSE);                   // Integrated Control : WD에 따른 보정(Correction) -> WD Min-Mag 값 찾기
int AfxGetSEMSpotSizeValue(void);                                               // Integrated Control : Spot Size 값
int AfxGetSEMStageHorzAlignValue(void);                                         // Integrated Control : Stage Horizental Align 값
int AfxSetSEMStageHorzAlignValue(int nValue);                                   // Integrated Control : Stage Horizental Align 값
int AfxSetSEMXMagStepRelayRatio(int nPos);                                      // Integrated Control : Set X Mag Step Relay Ratio 값
int AfxSetSEMYMagStepRelayRatio(int nPos);                                      // Integrated Control : Set Y Mag Step Relay Ratio 값
int AfxSetSEMMagnificationStepIndex(int nIndex = 0, BOOL bSet = FALSE);         // Integrated Control : Set Magnification Step Index 값
int AfxSetSEMOrthogonalValue(int nValue);                                       // Integrated Control : Set(Save) Orthogonal Control Value 값
int AfxGetSEMOrthogonalValue(void);                                             // Integrated Control : GetOrthogonal Control Value 값
double AfxGetSEMHVRatioValue(void);                                             // Integrated Control : Get HV Ratio 값
double AfxGetSEMCLVRefValue(int nCLValue);                                      // Integrated Control : Get CL1,2 Vref Value 값
double AfxGetSEMCLARefValue(int nCLValue);                                      // Integrated Control : Get CL1,2 Aref Value 값
double AfxGetSEMAmpRkValue(void);                                               // Integrated Control : Get CL1,CL2 Amp Rk Value 값
double AfxGetSEMRefRValue(void);                                                // Integrated Control : Get CL1,CL2 Ref R Value 값
int AfxGetSEMSyncTypeValue(void);                                               // Integrated Control : Get Sync Type Value 값
double AfxGetSEMSyncFreqValue(void);                                            // Integrated Control : Get Sync Freq Value 값
int AfxSetSEMOLWDAutoSave(void);                                                // Integrated Control : OL WD Auto Save
int AfxSetSEMWDSetupZAxis(int nWDZAxis);                                        // Integrated Control : W.D Setup Z-Axis 위치 값
int AfxIntegratedSetWDSetupFlag(BOOL bWDSetup);                                 // Integrated Control : W.D 값에 따른 OL전압, Scan Rotation, 배율보정을 적용할 것인지 여부 Flag
BOOL AfxIntegratedGetWDSetupFlag(void);                                         // Integrated Control : W.D 값에 따른 OL전압, Scan Rotation, 배율보정을 적용할 것인지 여부 Flag
int AfxIntegratedSetWDDataDisplayFlag(BOOL bWDSetup);                           // Integrated Control : W.D 교정값 DISPLAY 여부 Flag
BOOL AfxIntegratedGetWDDataDisplayFlag(void);                                   // Integrated Control : W.D 교정값 DISPLAY 여부 Flag
int AfxIntegratedSetStageHorAlign(BOOL bStageHorAlign);                         // Integrated Control : Set Stage 수평값 적용 Check
BOOL AfxIntegratedGetStageHorAlign(void);                                       // Integrated Control : Get Stage 수평값 적용 Check
int AfxIntegratedSetWDSRotationAdjust(BOOL bWDSRotationAdjust);                 // Integrated Control : Set WD S-Rotation 보정값 적용 Check
BOOL AfxIntegratedGetWDSRotationAdjust(void);                                   // Integrated Control : Get WD S-Rotation 보정값 적용 Check
int AfxIntegratedSetWDScaleZoomAdjust(BOOL bWDScaleZoomAdjust);                 // Integrated Control : WD Scale Zooming 보정값 적용 Check
BOOL AfxIntegratedGetWDScaleZoomAdjust(void);                                   // Integrated Control : WD Scale Zooming 보정값 적용 Check
double AfxGetSEMCurrentZAxisPosition(void);                                     // Integrated Control : 현재 WD (Z-Axis) 위치 값
int AfxSetSEMCurrentZAxisPosition(double dCurZPos);                             // Integrated Control : 현재 WD (Z-Axis) 위치 값
int AfxSetWDOLCoarseToFocusCoarse(void);                                        // Integrated Control : WD에 따른 OL-Coarse 값을 Focus Coarse 값에 적용
int AfxSetWDSRotToSRotation(void);                                              // Integrated Control : WD에 따른 S-Rotation 값을 Scan-Rotation 값에 적용
BOOL AfxGetChangeEbableFlag(void);                                              // Integrated Control : Change Enable Flag 값
int AfxSetChangeEbableFlag(BOOL bEnable);                                       // Integrated Control : Change Enable Flag 값
BOOL AfxGetSEMOrthogonalCheckFlag(void);                                        // Integrated Control : 직교도 교정값 보정기능 사용 Flag
int AfxSetSEMOrthogonalCheckFlag(BOOL bEnable);                                 // Integrated Control : 직교도 교정값 보정기능 사용 Flag
BOOL AfxGetSEMPhotoNoneStopFlag(void);                                          // Integrated Control : Photo Noe-Stop Scan 기능 사용 Flag
int AfxSetSEMPhotoNoneStopFlag(BOOL bEnable);                                   // Integrated Control : Photo Noe-Stop Scan 기능 사용 Flag
BOOL AfxGetHVCalibrationCheckFlag(void);                                        // Integrated Control : HV에 따른 Scale 보정 사용 Flag
int AfxSetHVCalibrationCheckFlag(BOOL bEnable);                                 // Integrated Control : HV에 따른 Scale 보정 사용 Flag
int AfxGetSEMMagStepValue(int nIndex);                                          // Integrated Control : Mag Step Value
BOOL AfxGetSEMNegativeImageCheckFlag(void);                                     // Integrated Control : 음양반전 기능 사용 Flag
int AfxSetSEMNegativeImageCheckFlag(BOOL bEnable, BOOL bApply = TRUE);          // Integrated Control : 음양반전 기능 사용 Flag
BOOL AfxGetSEMLRMirrorImageCheckFlag(void);                                     // Integrated Control : 좌우반전 기능 사용 Flag
int AfxSetSEMLRMirrorImageCheckFlag(BOOL bEnable, BOOL bApply = TRUE);          // Integrated Control : 좌우반전 기능 사용 Flag
BOOL AfxGetSEMTBMirrorImageCheckFlag(void);                                     // Integrated Control : 상하반전 기능 사용 Flag
int AfxSetSEMTBMirrorImageCheckFlag(BOOL bEnable, BOOL bApply = TRUE);          // Integrated Control : 상하반전 기능 사용 Flag
int AfxGetSEMDACL1Value(int nSpotSize);                                         // Integrated Control : CL1 전류에 따른 12bit DA
int AfxSetSEMDACL1Value(int nSpotSize, int nValue);                             // Integrated Control : CL1 전류에 따른 12bit DA
int AfxGetSEMDACL2Value(int nSpotSize);                                         // Integrated Control : CL2 전류에 따른 12bit DA
int AfxSetSEMDACL2Value(int nSpotSize, int nValue);                             // Integrated Control : CL2 전류에 따른 12bit DA
int AfxGetSEMOLCompensation(void);                                              // Integrated Control : 배율에 따른 OL 보정 방식
int AfxSetSEMOLCompensation(int nOLCompensation);                               // Integrated Control : 배율에 따른 OL 보정 방식
int AfxIntegratedSetSkipPixelNum(int nSkipPixel);                               // Integrated Control : Skip Pixel 값 설정 및 하드웨어 적용
int AfxIntegratedGetSkipPixelNum(void);                                         // Integrated Control : Skip Pixel 값 가져오기
int AfxIntegratedSetOverSampleNum(int nOverSample);                             // Integrated Control : Over Sample 값 설정 및 하드웨어 적용
int AfxIntegratedCalcAndExecuteFrameFreq(void);                                 // Integrated Control : Frame Freq 계산 및 하드웨어 적용
int AfxIntegratedSetFrameFreq(int nFrameFreq);                                  // Integrated Control : Frame Freq 값 설정 및 하드웨어 적용
int AfxIntegratedSetXScanUp(int nValue);                                        // Integrated Control : X Scan Up 값 설정 및 하드웨어 적용
int AfxIntegratedSetYScanUp(int nValue);                                        // Integrated Control : Y Scan Up 값 설정 및 하드웨어 적용
int AfxIntegratedSetXScanDown(int nValue);                                      // Integrated Control : X Scan Down 값 설정 및 하드웨어 적용
int AfxIntegratedSetYScanDown(int nValue);                                      // Integrated Control : Y Scan Down 값 설정 및 하드웨어 적용
int AfxIntegratedSetImageCaptureChange(int nOSSclk, int nImgSkip);              // Integrated Control : Image Capture Change 하드웨어 적용
int AfxIntegratedSetFPGANormalScreenMode(void);                                 // Integrated Control : Set FPAGE : Normal Screen Mode 하드웨어 적용
int AfxIntegratedSetGunHVECValue(WORD wECVal);                                  // Integrated Control : GUN HV EC VALUE Setting
int AfxIntegratedSetAutoProcessMode(int nAutoProcessMode);                      // Integrated Control : AUTO PROCESS MODE
void AfxIntegratedSetThreadAllStopFlag(void);                                   // Integrated Control : 쓰레드 강제 종료 설정 
void AfxIntegratedSetSampleHeight(double dSampleHeight);                        // Integrated Control : 샘플 높이 설정
void AfxIntegratedSetSampleWidth(double dSampleHeight);                         // Integrated Control : 샘플 넓이 설정
void AfxIntegratedSetSampleName(char *pSampleName);                             // Integrated Control : 샘플 명칭 설정
double AfxIntegratedGetSampleHeight(void);                                      // Integrated Control : 샘플 높이 리턴
double AfxIntegratedGetSampleWidth(void);                                       // Integrated Control : 샘플 넓이 리턴
double AfxIntegratedGetWDZoomRatioValue(void);                                  // Integrated Control : 현재 배율 보정 비율 값

// 2021.07.22
BOOL AfxGetSEMBseNegativeImageCheckFlag(void);                                  // Integrated Control : BSE 음양반전 기능 사용 Flag
int  AfxSetSEMBseNegativeImageCheckFlag(BOOL bEnable, BOOL bApply = TRUE);      // Integrated Control : BSE 음양반전 기능 사용 Flag
BOOL AfxGetSEMBseLRMirrorImageCheckFlag(void);                                  // Integrated Control : BSE 좌우반전 기능 사용 Flag
int  AfxSetSEMBseLRMirrorImageCheckFlag(BOOL bEnable, BOOL bApply = TRUE);      // Integrated Control : BSE 좌우반전 기능 사용 Flag
BOOL AfxGetSEMBseTBMirrorImageCheckFlag(void);                                  // Integrated Control : BSE 상하반전 기능 사용 Flag
int  AfxSetSEMBseTBMirrorImageCheckFlag(BOOL bEnable, BOOL bApply = TRUE);      // Integrated Control : BSE 상하반전 기능 사용 Flag

// 2021.09.09
int AfxSetAngleValveOff(void);                                                  // Scan Bridge : ANGLE VALVE OFF
int AfxSetAngleValveOn(void);                                                   // Scan Bridge : ANGLE VALVE ON



//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

// Integrated Control : SCAN HW SETUP OPTION DATA 설정
int AfxIntegratedSetScanHWSetupOptionFlag(int nPhotoNoneStop, int nISXReverse, int nISYReverse, int nOrthogonal, int nStageHorz, int nZFocusLink, int nWDSRot, int nWDZoom, int nHVCorrect, int nHVDegaussing, int nScanClk48);

// Integrated Control : SET STAGE OPTION DATA
int AfxIntegratedSetStageOptionData(int nType, int nIndex, BOOL bFlag, BYTE btData, int nData, DWORD dwData, double dData);

// Integrated Control : 배율에 따른 HV 보정값 사용자 설정
void AfxIntegratedSetMagHVRatio(double *pdMagHVRatio);
// Integrated Control : 배율 x35k 이상 ZOOM 값 보정율 설정
void AfxIntegratedSetMagx35kZoomRatio(double dMagx35kZoomRatio); 


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

















//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// OWNER 윈도우 설정
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void AfxUSBFT232HSetOwnerWindow(HWND hOwner)
{
	m_hOwnerWnd = hOwner;
}
HWND AfxUSBFT232HGetOwnerWindow(void)
{
	return m_hOwnerWnd;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main Control Child 윈도우 설정
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void AfxUSBFT232HSetMainControlWindow(HWND hChild)
{
	m_hMainControlWnd = hChild;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// H/W Setup & Control Child 윈도우 설정
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void AfxUSBFT232HSetHWSetupControlWindow(HWND hChild)
{
	m_hHWSetupControlWnd = hChild;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Stage Setup & Control Child 윈도우 설정
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void AfxUSBFT232HSetStageSetupControlWindow(HWND hChild)
{
	m_hStageSetupControlWnd = hChild;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Device Etc Setup & Control Child 윈도우 설정
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void AfxUSBFT232HSetPopupHWSetupControlWindow(HWND hChild)
{
	m_hPopupHWSetupControlWnd = hChild;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Device Etc Setup & Control Child 윈도우 설정
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void AfxUSBFT232HSetChild5Window(HWND hChild)
{
	m_hChild5Wnd = hChild;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// MAIN SERVER 실행파일 경로 설정 및 가져오기
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void AfxSetMainServerPath(CString strPath)
{
	m_strMainServerPath = strPath;
}
CString AfxGetMainServerPath(void)
{
	return m_strMainServerPath;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// DEVICE SERVER 실행파일 경로 설정 및 가져오기
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void AfxSetDeviceServerPath(CString strPath)
{
	m_strDeviceServerPath = strPath;
}
CString AfxGetDeviceServerPath(void)
{
	return m_strDeviceServerPath;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// 프로그램 루틴 소요시간 계산을 위한값
//////////////////////////////////////////////////////////////////////////////////////////////////////////
DWORD AfxGetFirstTickCount(void)
{
	return m_dwFirstTickCount;
}
DWORD AfxGetSecondTickCount(void)
{
	return m_dwSecondTickCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H DLL 파일을 로드한다
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxUSBFT232HLoadDLL()
{
	// USB FT232H DLL 파일 로드
	m_hDLLModule = ::LoadLibrary(FT232H_DLL_FILE);
	if (m_hDLLModule == NULL)
	{
		::MessageBox(NULL, _T("Error: Can't Load FT232H.dll"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return RET_ERROR_FT232H_LIB_LOAD;
	}

	// 아래 DLL 파일의 함수 포인터는 프로그램에서 사용하는 것만 설정한다.

	// DLL 파일의 함수:FT_CreateDeviceInfoList 의 포인터를 설정한다
	m_pCreateDeviceInfoList = (PtrToCreateDeviceInfoList)GetProcAddress(m_hDLLModule, "FT_CreateDeviceInfoList");
	if (m_pCreateDeviceInfoList == NULL)
	{
		::MessageBox(NULL, _T("Error: Can't Find FT_CreateDeviceInfoList"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return RET_ERROR_FT232H_LIB_LOAD;
	}

	// DLL 파일의 함수:FT_GetDeviceInfoList 의 포인터를 설정한다
	m_pGetDeviceInfoList = (PtrToGetDeviceInfoList)GetProcAddress(m_hDLLModule, "FT_GetDeviceInfoList");
	if (m_pGetDeviceInfoList == NULL)
	{
		::MessageBox(NULL, _T("Error: Can't Find FT_GetDeviceInfoList"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return RET_ERROR_FT232H_LIB_LOAD;
	}

	// DLL 파일의 함수:FT_Open 의 포인터를 설정한다
	m_pOpen = (PtrToOpen)GetProcAddress(m_hDLLModule, "FT_Open");
	if (m_pOpen == NULL)
	{
		::MessageBox(NULL, _T("Error: Can't Find FT_Open"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return RET_ERROR_FT232H_LIB_LOAD;
	}

	// DLL 파일의 함수:FT_OpenEx 의 포인터를 설정한다
	m_pOpenEx = (PtrToOpenEx)GetProcAddress(m_hDLLModule, "FT_OpenEx");
	if (m_pOpenEx == NULL)
	{
		::MessageBox(NULL, _T("Error: Can't Find FT_OpenEx"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return RET_ERROR_FT232H_LIB_LOAD;
	}

	// DLL 파일의 함수:FT_ListDevices 의 포인터를 설정한다
	m_pListDevices = (PtrToListDevices)GetProcAddress(m_hDLLModule, "FT_ListDevices");
	if (m_pListDevices == NULL)
	{
		::MessageBox(NULL, _T("Error: Can't Find FT_ListDevices"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return RET_ERROR_FT232H_LIB_LOAD;
	}

	// DLL 파일의 함수:FT_Close 의 포인터를 설정한다
	m_pClose = (PtrToClose)GetProcAddress(m_hDLLModule, "FT_Close");
	if (m_pClose == NULL)
	{
		::MessageBox(NULL, _T("Error: Can't Find FT_Close"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return RET_ERROR_FT232H_LIB_LOAD;
	}

	// DLL 파일의 함수:FT_Write 의 포인터를 설정한다
	m_pWrite = (PtrToWrite)GetProcAddress(m_hDLLModule, "FT_Write");
	if (m_pWrite == NULL)
	{
		::MessageBox(NULL, _T("Error: Can't Find FT_Write"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return RET_ERROR_FT232H_LIB_LOAD;
	}

	// DLL 파일의 함수:FT_Read 의 포인터를 설정한다
	m_pRead = (PtrToRead)GetProcAddress(m_hDLLModule, "FT_Read");
	if (m_pRead == NULL)
	{
		::MessageBox(NULL, _T("Error: Can't Find FT_Read"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return RET_ERROR_FT232H_LIB_LOAD;
	}

	// DLL 파일의 함수:FT_ResetDevice 의 포인터를 설정한다
	m_pResetDevice = (PtrToResetDevice)GetProcAddress(m_hDLLModule, "FT_ResetDevice");
	if (m_pResetDevice == NULL)
	{
		::MessageBox(NULL, _T("Error: Can't Find FT_ResetDevice"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return RET_ERROR_FT232H_LIB_LOAD;
	}

	// DLL 파일의 함수:FT_Purge 의 포인터를 설정한다
	m_pPurge = (PtrToPurge)GetProcAddress(m_hDLLModule, "FT_Purge");
	if (m_pPurge == NULL)
	{
		::MessageBox(NULL, _T("Error: Can't Find FT_Purge"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return RET_ERROR_FT232H_LIB_LOAD;
	}

	// DLL 파일의 함수:FT_SetTimeouts 의 포인터를 설정한다
	m_pSetTimeouts = (PtrToSetTimeouts)GetProcAddress(m_hDLLModule, "FT_SetTimeouts");
	if (m_pSetTimeouts == NULL)
	{
		::MessageBox(NULL, _T("Error: Can't Find FT_SetTimeouts"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return RET_ERROR_FT232H_LIB_LOAD;
	}

	// DLL 파일의 함수:FT_GetStatus 의 포인터를 설정한다
	m_pGetStatus = (PtrToGetStatus)GetProcAddress(m_hDLLModule, "FT_GetStatus");
	if (m_pGetStatus == NULL)
	{
		::MessageBox(NULL, _T("Error: Can't Find FT_GetStatus"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return RET_ERROR_FT232H_LIB_LOAD;
	}

	// DLL 파일의 함수:FT_GetQueueStatus 의 포인터를 설정한다
	m_pGetQueueStatus = (PtrToGetQueueStatus)GetProcAddress(m_hDLLModule, "FT_GetQueueStatus");
	if (m_pGetQueueStatus == NULL)
	{
		::MessageBox(NULL, _T("Error: Can't Find FT_GetQueueStatus"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return RET_ERROR_FT232H_LIB_LOAD;
	}

	// DLL 파일의 함수:FT_SetBitMode 의 포인터를 설정한다
	m_pSetBitMode = (PtrToSetBitMode)GetProcAddress(m_hDLLModule, "FT_SetBitMode");
	if (m_pSetBitMode == NULL)
	{
		::MessageBox(NULL, _T("Error: Can't Find FT_SetBitMode"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return RET_ERROR_FT232H_LIB_LOAD;
	}

	// DLL 파일의 함수:FT_SetLatencyTimer 의 포인터를 설정한다
	m_pSetLatencyTimer = (PtrToSetLatencyTimer)GetProcAddress(m_hDLLModule, "FT_SetLatencyTimer");
	if (m_pSetLatencyTimer == NULL)
	{
		::MessageBox(NULL, _T("Error: Can't Find FT_SetLatencyTimer"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return RET_ERROR_FT232H_LIB_LOAD;
	}

	// DLL 파일의 함수:FT_SetUSBParameters 의 포인터를 설정한다
	m_pSetUSBParameters = (PtrToSetUSBParameters)GetProcAddress(m_hDLLModule, "FT_SetUSBParameters");
	if (m_pSetUSBParameters == NULL)
	{
		::MessageBox(NULL, _T("Error: Can't Find FT_SetUSBParameters"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return RET_ERROR_FT232H_LIB_LOAD;
	}

	// DLL 파일의 함수:FT_SetFlowControl 의 포인터를 설정한다
	m_pSetFlowControl = (PtrToSetFlowControl)GetProcAddress(m_hDLLModule, "FT_SetFlowControl");
	if (m_pSetFlowControl == NULL)
	{
		::MessageBox(NULL, _T("Error: Can't Find FT_SetFlowControl"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return RET_ERROR_FT232H_LIB_LOAD;
	}

	// DLL 파일의 함수:FT_SetEventNotification 의 포인터를 설정한다
	m_pSetEventNotification = (PtrToSetEventNotification)GetProcAddress(m_hDLLModule, "FT_SetEventNotification");
	if (m_pSetEventNotification == NULL)
	{
		::MessageBox(NULL, _T("Error: Can't Find FT_SetEventNotification"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return RET_ERROR_FT232H_LIB_LOAD;
	}

	return RET_SUCCESS_OK;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H DLL 파일을 메모리에서 제거 한다
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxUSBFT232HFreeDLL()
{
	if (m_hDLLModule != NULL)
	{
		BOOL bRet = ::FreeLibrary(m_hDLLModule);
		if (bRet == FALSE)
		{
			::MessageBox(NULL, _T("Error: Can't Free Load ft232h.dll"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
			return RET_ERROR_FT232H_LIB_FREE;
		}
		m_hDLLModule = NULL;
	}

	return RET_SUCCESS_OK;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// USB FT232H DLL 파일의 함수 정의
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H 의 연결된 장치목록을 생성한다
//////////////////////////////////////////////////////////////////////////////////////////////////////////
FT_STATUS AfxFT232HCreateDeviceInfoList(LPDWORD lpdwListCount)
{
	if (!m_pCreateDeviceInfoList)
	{
		::MessageBox(NULL, _T("Error: FT_CreateDeviceInfoList is not valid!"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return FT_INVALID_HANDLE;
	}

	return (*m_pCreateDeviceInfoList)(lpdwListCount);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H 의 연결된 장치목록을 가져온다
//////////////////////////////////////////////////////////////////////////////////////////////////////////
FT_STATUS AfxFT232HGetDeviceInfoList(FT_DEVICE_LIST_INFO_NODE *pDest, LPDWORD lpdwNumDevs)
{
	if (!m_pGetDeviceInfoList)
	{
		::MessageBox(NULL, _T("Error: FT_GetDeviceInfoList is not valid!"), _T("FT232H ERROR"), MB_ICONERROR | MB_OK);
		return FT_INVALID_HANDLE;
	}

	return (*m_pGetDeviceInfoList)(pDest, lpdwNumDevs);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H 의 연결된 장치 핸들을 가져온다
//////////////////////////////////////////////////////////////////////////////////////////////////////////
FT_HANDLE AfxFT232HGetHandle(int nIndex)
{
	if (nIndex < 0)
	{
		return NULL;
	}

	return m_hFT232HDevice[nIndex];
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H 의 연결된 장치를 사용할 수 있도록 설정한다
//////////////////////////////////////////////////////////////////////////////////////////////////////////
FT_STATUS AfxFT232HOpen(PVOID pvDevice, int nIndex)
{
	if (!m_pOpen)
	{
		::MessageBox(NULL, _T("Error: FT_Open is not valid!"), _T("FT232H ERROR"), MB_OK);
		return FT_INVALID_HANDLE;
	}

	return (*m_pOpen)(pvDevice, &m_hFT232HDevice[nIndex]);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H 의 연결된 장치를 사용할 수 있도록 설정한다 (자세히 설정)
//////////////////////////////////////////////////////////////////////////////////////////////////////////
FT_STATUS AfxFT232HOpenEx(PVOID pArg1, DWORD dwFlags, int nIndex)
{
	if (!m_pOpenEx)
	{
		::MessageBox(NULL, _T("Error: FT_OpenEx is not valid!"), _T("FT232H ERROR"), MB_OK);
		return FT_INVALID_HANDLE;
	}
	if (nIndex < 0) return FT_INVALID_HANDLE;

	return (*m_pOpenEx)(pArg1, dwFlags, &m_hFT232HDevice[nIndex]);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H 의 연결하여 사용하는 장치를 사용 종료한다
//////////////////////////////////////////////////////////////////////////////////////////////////////////
FT_STATUS AfxFT232HClose(int nIndex)
{
	//if (m_hFT232HDevice[nIndex] == NULL) return FT_INVALID_HANDLE;
	//if (m_nFT232HDeviceUse < 1) return FT_INVALID_HANDLE;

	if (!m_pClose)
	{
		::MessageBox(NULL, _T("Error: FT_Close is not valid!"), _T("FT232H ERROR"), MB_OK);
		return FT_INVALID_HANDLE;
	}

	return (*m_pClose)(m_hFT232HDevice[nIndex]);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H 의 연결하여 사용하는 장치에서 수신한 데이터를 읽어온다
//////////////////////////////////////////////////////////////////////////////////////////////////////////
FT_STATUS AfxFT232HRead(int nIndex, LPVOID lpvBuffer, DWORD dwBuffSize, LPDWORD lpdwBytesRead)
{
	//if (m_hFT232HDevice[nIndex] == NULL) return FT_INVALID_HANDLE;
	//if (m_nFT232HDeviceUse < 1) return FT_INVALID_HANDLE;

	if (!m_pRead)
	{
		::MessageBox(NULL, _T("Error: FT_Read is not valid!"), _T("FT232H ERROR"), MB_OK);
		return FT_INVALID_HANDLE;
	}

	return (*m_pRead)(m_hFT232HDevice[nIndex], lpvBuffer, dwBuffSize, lpdwBytesRead);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H 의 연결하여 사용하는 장치에 전송할 수 있는 데이터를 설정한다
//////////////////////////////////////////////////////////////////////////////////////////////////////////
FT_STATUS AfxFT232HWrite(int nIndex, LPVOID lpvBuffer, DWORD dwBuffSize, LPDWORD lpdwBytes)
{
	//if (m_hFT232HDevice[nIndex] == NULL) return FT_INVALID_HANDLE;
	//if (m_nFT232HDeviceUse < 1) return FT_INVALID_HANDLE;

	if (!m_pWrite)
	{
		::MessageBox(NULL, _T("Error: FT_Write is not valid!"), _T("FT232H ERROR"), MB_OK);
		return FT_INVALID_HANDLE;
	}

	return (*m_pWrite)(m_hFT232HDevice[nIndex], lpvBuffer, dwBuffSize, lpdwBytes);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H 의 연결하여 사용하는 장치목록을 가져온다
//////////////////////////////////////////////////////////////////////////////////////////////////////////
FT_STATUS AfxFT232HListDevices(PVOID pArg1, PVOID pArg2, DWORD dwFlags)
{
	if (!m_pListDevices)
	{
		::MessageBox(NULL, _T("Error: FT_ListDevices is not valid!"), _T("FT232H ERROR"), MB_OK);
		return FT_INVALID_HANDLE;
	}

	return (*m_pListDevices)(pArg1, pArg2, dwFlags);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H 의 연결하여 사용하는 장치를 초기화한다
//////////////////////////////////////////////////////////////////////////////////////////////////////////
FT_STATUS AfxFT232HResetDevice(int nIndex)
{
	//if (m_hFT232HDevice[nIndex] == NULL) return FT_INVALID_HANDLE;
	//if (m_nFT232HDeviceUse < 1) return FT_INVALID_HANDLE;

	if (!m_pResetDevice)
	{
		::MessageBox(NULL, _T("Error: FT_ResetDevice is not valid!"), _T("FT232H ERROR"), MB_OK);
		return FT_INVALID_HANDLE;
	}

	return (*m_pResetDevice)(m_hFT232HDevice[nIndex]);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H 의 연결하여 사용하는 장치 송/수신버퍼를 초기화한다
//////////////////////////////////////////////////////////////////////////////////////////////////////////
FT_STATUS AfxFT232HPurge(int nIndex, ULONG dwMask)
{
	//if (m_hFT232HDevice[nIndex] == NULL) return FT_INVALID_HANDLE;
	//if (m_nFT232HDeviceUse < 1) return FT_INVALID_HANDLE;

	if (!m_pPurge)
	{
		::MessageBox(NULL, _T("Error: FT_Purge is not valid!"), _T("FT232H ERROR"), MB_OK);
		return FT_INVALID_HANDLE;
	}

	return (*m_pPurge)(m_hFT232HDevice[nIndex], dwMask);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H 의 연결하여 사용하는 장치 송/수신 대기시간을 설정한다
//////////////////////////////////////////////////////////////////////////////////////////////////////////
FT_STATUS AfxFT232HSetTimeouts(int nIndex, ULONG dwReadTimeout, ULONG dwWriteTimeout)
{
	//if (m_hFT232HDevice[nIndex] == NULL) return FT_INVALID_HANDLE;
	//if (m_nFT232HDeviceUse < 1) return FT_INVALID_HANDLE;

	if (!m_pSetTimeouts)
	{
		::MessageBox(NULL, _T("Error: FT_SetTimeouts is not valid!"), _T("FT232H ERROR"), MB_OK);
		return FT_INVALID_HANDLE;
	}

	return (*m_pSetTimeouts)(m_hFT232HDevice[nIndex], dwReadTimeout, dwWriteTimeout);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H 의 연결하여 사용하는 장치 상태를 가져온다
//////////////////////////////////////////////////////////////////////////////////////////////////////////
FT_STATUS AfxFT232HGetStatus(int nIndex, LPDWORD lpdwRxBytes, LPDWORD lpdwTxBytes, LPDWORD lpdwEventDWord)
{
	//if (m_hFT232HDevice[nIndex] == NULL) return FT_INVALID_HANDLE;
	//if (m_nFT232HDeviceUse < 1) return FT_INVALID_HANDLE;

	if (!m_pGetStatus)
	{
		::MessageBox(NULL, _T("Error: FT_GetStatus is not valid!"), _T("FT232H ERROR"), MB_OK);
		return FT_INVALID_HANDLE;
	}

	return (*m_pGetStatus)(m_hFT232HDevice[nIndex], lpdwRxBytes, lpdwTxBytes, lpdwEventDWord);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H 의 연결하여 사용하는 장치 송/수신 버퍼 상태를 가져온다
//////////////////////////////////////////////////////////////////////////////////////////////////////////
FT_STATUS AfxFT232HGetQueueStatus(int nIndex, LPDWORD lpdwAmountInRxQueue)
{
	//if (m_hFT232HDevice[nIndex] == NULL) return FT_INVALID_HANDLE;
	//if (m_nFT232HDeviceUse < 1) return FT_INVALID_HANDLE;

	if (!m_pGetQueueStatus)
	{
		::MessageBox(NULL, _T("Error: FT_GetQueueStatus is not valid!"), _T("FT232H ERROR"), MB_OK);
		return FT_INVALID_HANDLE;
	}

	return (*m_pGetQueueStatus)(m_hFT232HDevice[nIndex], lpdwAmountInRxQueue);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H 의 연결하여 사용하는 장치 통신방식을 설정한다
//////////////////////////////////////////////////////////////////////////////////////////////////////////
FT_STATUS AfxFT232HSetBitMode(int nIndex, UCHAR ucMask, UCHAR ucEnable)
{
	//if (m_hFT232HDevice[nIndex] == NULL) return FT_INVALID_HANDLE;
	//if (m_nFT232HDeviceUse < 1) return FT_INVALID_HANDLE;

	if (!m_pSetBitMode)
	{
		::MessageBox(NULL, _T("Error: FT_SetBitMode is not valid!"), _T("FT232H ERROR"), MB_OK);
		return FT_INVALID_HANDLE;
	}

	return (*m_pSetBitMode)(m_hFT232HDevice[nIndex], ucMask, ucEnable);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H 의 연결하여 사용하는 장치 송/수신 버퍼 갱신시간을 설정한다
//////////////////////////////////////////////////////////////////////////////////////////////////////////
FT_STATUS AfxFT232HSetLatencyTimer(int nIndex, UCHAR ucLatency)
{
	//if (m_hFT232HDevice[nIndex] == NULL) return FT_INVALID_HANDLE;
	//if (m_nFT232HDeviceUse < 1) return FT_INVALID_HANDLE;

	if (!m_pSetLatencyTimer)
	{
		::MessageBox(NULL, _T("Error: FT_SetLatencyTimer is not valid!"), _T("FT232H ERROR"), MB_OK);
		return FT_INVALID_HANDLE;
	}

	return (*m_pSetLatencyTimer)(m_hFT232HDevice[nIndex], ucLatency);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H 의 연결하여 사용하는 장치 송/수신 버퍼의 크기를 설정한다
//////////////////////////////////////////////////////////////////////////////////////////////////////////
FT_STATUS AfxFT232HSetUSBParameters(int nIndex, ULONG ulInTransferSize, ULONG ulOutTransferSize)
{
	//if (m_hFT232HDevice[nIndex] == NULL) return FT_INVALID_HANDLE;
	//if (m_nFT232HDeviceUse < 1) return FT_INVALID_HANDLE;

	if (!m_pSetUSBParameters)
	{
		::MessageBox(NULL, _T("Error: FT_SetUSBParameters is not valid!"), _T("FT232H ERROR"), MB_OK);
		return FT_INVALID_HANDLE;
	}

	return (*m_pSetUSBParameters)(m_hFT232HDevice[nIndex], ulInTransferSize, ulOutTransferSize);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H 의 연결하여 사용하는 장치간 통신 흐름제어를 설정한다
//////////////////////////////////////////////////////////////////////////////////////////////////////////
FT_STATUS AfxFT232HSetFlowControl(int nIndex, USHORT FlowControl, UCHAR XonChar, UCHAR XoffChar)
{
	//if (m_hFT232HDevice[nIndex] == NULL) return FT_INVALID_HANDLE;
	//if (m_nFT232HDeviceUse < 1) return FT_INVALID_HANDLE;

	if (!m_pSetFlowControl)
	{
		::MessageBox(NULL, _T("Error: FT_AfxFT232HSetFlowControl is not valid!"), _T("FT232H ERROR"), MB_OK);
		return FT_INVALID_HANDLE;
	}

	return (*m_pSetFlowControl)(m_hFT232HDevice[nIndex], FlowControl, XonChar, XoffChar);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H 의 연결하여 사용하는 장치의 이벤트를 설정하고 해당 이벤트를 이용한 자료처리를 실행한다
//////////////////////////////////////////////////////////////////////////////////////////////////////////
FT_STATUS AfxFT232HSetEventNotification(int nIndex, DWORD dwEventMask, PVOID pvArg)
{
	//if (m_hFT232HDevice[nIndex] == NULL) return FT_INVALID_HANDLE;
	//if (m_nFT232HDeviceUse < 1) return FT_INVALID_HANDLE;

	if (!m_pSetEventNotification)
	{
		::MessageBox(NULL, _T("Error: FT_SetEventNotification is not valid!"), _T("FT232H ERROR"), MB_OK);
		return FT_INVALID_HANDLE;
	}
	
	// Event Mask : FT_EVENT_RXCHAR = 1, FT_EVENT_MODEM_STATUS = 2, FT_EVENT_LINE_STATUS = 4

	return (*m_pSetEventNotification)(m_hFT232HDevice[nIndex], dwEventMask, pvArg);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// FT232H Device Control...
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// USB FT232H 의 연결하여 사용할 장치(포트) 설정하기
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxFT232HPortOpen(int nDevicePort)
{
	FT_STATUS ft232hStatus = FT_OK;
	FT_DEVICE_LIST_INFO_NODE *lpft232hDeviceInfo = NULL;
	DWORD dwft232hDeviceCount = 0;
	UCHAR ucMode = 0;
	UCHAR ucMask = 0;

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// USB FT232H를 이용한 장치 연결정보 생성
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	ft232hStatus = AfxFT232HCreateDeviceInfoList(&dwft232hDeviceCount);
	if (ft232hStatus != FT_OK)
	{
		if (nDevicePort == IDX_FT232H_SCAN_BRIDGE_DEVICE)
		{
			//::MessageBox(NULL, _T("Error: Can't Create FT232H Scan Bridge Device List!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: Can't Create FT232H Scan Bridge Device List!");
		}
		else if (nDevicePort == IDX_FT232H_SEM_IMAGE_DEVICE)
		{
			//::MessageBox(NULL, _T("Error: Can't Create FT232H Sem Image Device List!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: Can't Create FT232H Sem Image Device List!");
		}
		else if (nDevicePort == IDX_FT232H_BSE_IMAGE_DEVICE)
		{
			//::MessageBox(NULL, _T("Error: Can't Create FT232H Bse Image Device List!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: Can't Create FT232H Bse Image Device List!");
		}
		else
		{
			//::MessageBox(NULL, _T("Error: Can't Create FT232H Device List!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: Can't Create FT232H Device List!");
			memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: Can't Create FT232H Device List!");
			memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: Can't Create FT232H Device List!");
		}
		return RET_ERROR_FT232H_DEV_CREATE;
	}
	if (dwft232hDeviceCount < 1)
	{
		if (nDevicePort == IDX_FT232H_SCAN_BRIDGE_DEVICE)
		{
			//::MessageBox(NULL, _T("Error: FT232H Scan Bridge Device Info List Count!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: FT232H Scan Bridge Device Info List Count!");
		}
		else if (nDevicePort == IDX_FT232H_SEM_IMAGE_DEVICE)
		{
			//::MessageBox(NULL, _T("Error: FT232H Sem Image Device Info List Count!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: FT232H Sem Image Device Info List Count!");
		}
		else if (nDevicePort == IDX_FT232H_BSE_IMAGE_DEVICE)
		{
			//::MessageBox(NULL, _T("Error: FT232H Bse Image Device Info List Count!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: FT232H Bse Image Device Info List Count!");
		}
		else
		{
			//::MessageBox(NULL, _T("Error: FT232H Device Info List Count!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: FT232H Device Info List Count!");
			memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: FT232H Device Info List Count!");
			memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: FT232H Device Info List Count!");
		}
		return RET_ERROR_FT232H_DEV_COUNT;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// FT232H 장치 연결정보를 위한 메모리 생성
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	lpft232hDeviceInfo = (FT_DEVICE_LIST_INFO_NODE*)malloc(sizeof(FT_DEVICE_LIST_INFO_NODE)*dwft232hDeviceCount);
	if (lpft232hDeviceInfo == NULL)
	{
		if (nDevicePort == IDX_FT232H_SCAN_BRIDGE_DEVICE)
		{
			//::MessageBox(NULL, _T("Error: Can't Create FT232H Scan Bridge Device Info Memory!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: Can't Create FT232H Scan Bridge Device Info Memory!");
		}
		else if (nDevicePort == IDX_FT232H_SEM_IMAGE_DEVICE)
		{
			//::MessageBox(NULL, _T("Error: Can't Create FT232H Sem Image Device Info Memory!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: Can't Create FT232H Sem Image Device Info Memory!");
		}
		else if (nDevicePort == IDX_FT232H_BSE_IMAGE_DEVICE)
		{
			//::MessageBox(NULL, _T("Error: Can't Create FT232H Bse Image Device Info Memory!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: Can't Create FT232H Bse Image Device Info Memory!");
		}
		else
		{
			//::MessageBox(NULL, _T("Error: Can't Create FT232H Device Info Memory!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: Can't Create FT232H Device Info Memory!");
			memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: Can't Create FT232H Device Info Memory!");
			memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: Can't Create FT232H Device Info Memory!");
		}
		return RET_ERROR_FT232H_DEV_INFO;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// FT232H 장치 연결 정보 가져오기
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	ft232hStatus = AfxFT232HGetDeviceInfoList(lpft232hDeviceInfo, &dwft232hDeviceCount);
	if (ft232hStatus != FT_OK)
	{
		free(lpft232hDeviceInfo);
		if (nDevicePort == IDX_FT232H_SCAN_BRIDGE_DEVICE)
		{
			//::MessageBox(NULL, _T("Error: Can't Get FT232H Scan Bridge Device List Info!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: Can't Get FT232H Scan Bridge Device List Info!");
		}
		else if (nDevicePort == IDX_FT232H_SEM_IMAGE_DEVICE)
		{
			//::MessageBox(NULL, _T("Error: Can't Get FT232H Sem Image Device List Info!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: Can't Get FT232H Sem Image Device List Info!");
		}
		else if (nDevicePort == IDX_FT232H_BSE_IMAGE_DEVICE)
		{
			//::MessageBox(NULL, _T("Error: Can't Get FT232H Bse Image Device List Info!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: Can't Get FT232H Bse Image Device List Info!");
		}
		else
		{
			//::MessageBox(NULL, _T("Error: Can't Get FT232H Device List Info!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: Can't Get FT232H Device List Info!");
			memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: Can't Get FT232H Device List Info!");
			memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: Can't Get FT232H Device List Info!");
		}
		return RET_ERROR_FT232H_DEV_LIST;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// FT232H SEM SE 이미지 스캔 및 캡처 장치 연결
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	if (nDevicePort == IDX_FT232H_SEM_IMAGE_DEVICE)
	{
		m_bSemImageConnected = FALSE;
		m_nFT232HIndex = nDevicePort;// SEM SE Image Scan Device Port
		ft232hStatus = AfxFT232HOpenEx(DEV_FT232H_SEM_IMAGE_DEVICE, FT_OPEN_BY_SERIAL_NUMBER, m_nFT232HIndex);

		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			m_hFT232HDevice[m_nFT232HIndex] = NULL;
			//::MessageBox(NULL, _T("Error: Can't Connect FT232H SE-Image Capture Board!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: Can't Connect FT232H SE-Image Capture Board!");
			return RET_ERROR_FT232H_SEM_CONNECT;
		}

		ucMode = 0x00; // reset mode
		ucMask = 0xFF;
		ft232hStatus = AfxFT232HSetBitMode(m_nFT232HIndex, ucMask, ucMode);
		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			//::MessageBox(NULL, _T("Error: FT232H SE-Image Reset Bit Mode!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: FT232H SE-Image Reset Bit Mode!");
			return RET_ERROR_FT232H_SEM_RESET;
		}

		::Sleep(10);

		ucMode = 0x40; // sync FIFO mode
		ucMask = 0xFF;
		ft232hStatus = AfxFT232HSetBitMode(m_nFT232HIndex, ucMask, ucMode);
		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			//::MessageBox(NULL, _T("Error: FT232H SE-Image Sync FIFO Mode!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: FT232H SE-Image Sync FIFO Mode!");
			return RET_ERROR_FT232H_SEM_SYNC;
		}

		// 송/수신 버퍼 갱신시간 [ms]
		ft232hStatus = AfxFT232HSetLatencyTimer(m_nFT232HIndex, FT232H_LATENCY_TIME);
		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			//::MessageBox(NULL, _T("Error: FT232H SE-Image Latency Time!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: FT232H SE-Image Latency Time!");
			return RET_ERROR_FT232H_SEM_LATENCY;
		}

		// 송/수신 버퍼 크기 설정 65536[byte]
		ft232hStatus = AfxFT232HSetUSBParameters(m_nFT232HIndex, 0x10000, 0x10000);
		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			//::MessageBox(NULL, _T("Error: FT232H SE-Image USB Parameters!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: FT232H SE-Image USB Parameters!");
			return RET_ERROR_FT232H_SEM_PARAMETERS;
		}

		// USB FT232H Port 통신 흐름제어 설정
		ft232hStatus = AfxFT232HSetFlowControl(m_nFT232HIndex, FT_FLOW_RTS_CTS, NULL, NULL);
		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			//::MessageBox(NULL, _T("Error: FT232H SE-Image Flow Control!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: FT232H SE-Image Flow Control!");
			return RET_ERROR_FT232H_SEM_FLOW;
		}

		// 송/수신 버퍼 초기화
		ft232hStatus = AfxFT232HPurge(m_nFT232HIndex, FT_PURGE_RX | FT_PURGE_TX);
		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			//::MessageBox(NULL, _T("Error: FT232H SE-Image Purge RX and TX!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: FT232H SE-Image Purge RX and TX!");
			return RET_ERROR_FT232H_SEM_PURGE;
		}
		// SEM Se Image Board OK
		m_bSemImageConnected = TRUE;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// FT232H SEM BSE 이미지 스캔 및 캡처 장치 연결
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	else if (nDevicePort == IDX_FT232H_BSE_IMAGE_DEVICE)
	{
		m_bBseImageConnected = FALSE;
		m_nFT232HIndex = nDevicePort;// SEM BSE Image Scan Device Port
		ft232hStatus = AfxFT232HOpenEx(DEV_FT232H_BSE_IMAGE_DEVICE, FT_OPEN_BY_SERIAL_NUMBER, m_nFT232HIndex);
		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			m_hFT232HDevice[m_nFT232HIndex] = NULL;
			//::MessageBox(NULL, _T("Error: Can't Connect FT232H BSE-Image Capture Board!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: Can't Connect FT232H BSE-Image Capture Board!");
			return RET_ERROR_FT232H_BSE_CONNECT;
		}

		ucMode = 0x00; // reset mode
		ucMask = 0xFF;
		ft232hStatus = AfxFT232HSetBitMode(m_nFT232HIndex, ucMask, ucMode);
		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			//::MessageBox(NULL, _T("Error: FT232H BSE-Image Reset Bit Mode!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: FT232H BSE-Image Reset Bit Mode!");
			return RET_ERROR_FT232H_BSE_RESET;
		}

		::Sleep(10);

		ucMode = 0x40; // sync FIFO mode
		ucMask = 0xFF;
		ft232hStatus = AfxFT232HSetBitMode(m_nFT232HIndex, ucMask, ucMode);
		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			//::MessageBox(NULL, _T("Error: FT232H BSE-Image Sync FIFO Mode!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: FT232H BSE-Image Sync FIFO Mode!");
			return RET_ERROR_FT232H_BSE_SYNC;
		}

		// 송/수신 버퍼 갱신시간 [ms]
		ft232hStatus = AfxFT232HSetLatencyTimer(m_nFT232HIndex, FT232H_LATENCY_TIME);
		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			//::MessageBox(NULL, _T("Error: FT232H BSE-Image Latency Time!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: FT232H BSE-Image Latency Time!");
			return RET_ERROR_FT232H_BSE_LATENCY;
		}

		// 송/수신 버퍼 크기 설정 65536[byte]
		ft232hStatus = AfxFT232HSetUSBParameters(m_nFT232HIndex, 0x10000, 0x10000);
		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			//::MessageBox(NULL, _T("Error: FT232H BSE-Image USB Parameters!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: FT232H BSE-Image USB Parameters!");
			return RET_ERROR_FT232H_BSE_PARAMETERS;
		}

		// USB FT232H Port 통신 흐름제어 설정
		ft232hStatus = AfxFT232HSetFlowControl(m_nFT232HIndex, FT_FLOW_RTS_CTS, NULL, NULL);
		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			//::MessageBox(NULL, _T("Error: FT232H BSE-Image Flow Control!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: FT232H BSE-Image Flow Control!");
			return RET_ERROR_FT232H_BSE_FLOW;
		}

		// 송/수신 버퍼 초기화
		ft232hStatus = AfxFT232HPurge(m_nFT232HIndex, FT_PURGE_RX | FT_PURGE_TX);
		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			//::MessageBox(NULL, _T("Error: FT232H BSE-Image Purge RX and TX!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: FT232H BSE-Image Purge RX and TX!");
			return RET_ERROR_FT232H_BSE_PURGE;
		}
		// BSE Image Board OK
		m_bBseImageConnected = TRUE;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// FT232H Scan Bridge Device 장치 연결
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	else if (nDevicePort == IDX_FT232H_SCAN_BRIDGE_DEVICE)
	{
	    m_bScanBridgeConnected = FALSE;
	    m_nFT232HIndex = nDevicePort;// SEM Device Control (Scan Bridge)
		ft232hStatus = AfxFT232HOpenEx(DEV_FT232H_SCAN_BRIDGE_DEVICE, FT_OPEN_BY_SERIAL_NUMBER, m_nFT232HIndex);
		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			m_hFT232HDevice[m_nFT232HIndex] = NULL;
			//::MessageBox(NULL, _T("Error: Can't Connect FT232H SCAN Bridge Board!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: Can't Connect FT232H SCAN Bridge Board!");
			return RET_ERROR_FT232H_SBR_CONNECT;
		}

		ucMode = 0x00; // reset mode
		ucMask = 0xFF;
		ft232hStatus = AfxFT232HSetBitMode(m_nFT232HIndex, ucMask, ucMode);
		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			//::MessageBox(NULL, _T("Error: FT232H SCAN Bridge Reset Bit Mode!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: FT232H SCAN Bridge Reset Bit Mode!");
			return RET_ERROR_FT232H_SBR_RESET;
		}

		::Sleep(10);

		ucMode = 0x40; // sync FIFO mode
		ucMask = 0xFF;
		ft232hStatus = AfxFT232HSetBitMode(m_nFT232HIndex, ucMask, ucMode);
		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			//::MessageBox(NULL, _T("Error: FT232H SCAN Bridge Sync FIFO Mode!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: FT232H SCAN Bridge Sync FIFO Mode!");
			return RET_ERROR_FT232H_SBR_SYNC;
		}

		// 송/수신 버퍼 갱신시간 [ms]
		ft232hStatus = AfxFT232HSetLatencyTimer(m_nFT232HIndex, FT232H_LATENCY_TIME);
		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			//::MessageBox(NULL, _T("Error: FT232H SCAN Bridge Latency Time!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: FT232H SCAN Bridge Latency Time!");
			return RET_ERROR_FT232H_SBR_LATENCY;
		}

		// 송/수신 버퍼 크기 설정 65536[byte]
		ft232hStatus = AfxFT232HSetUSBParameters(m_nFT232HIndex, 0x10000, 0x10000);
		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			//::MessageBox(NULL, _T("Error: FT232H SCAN Bridge USB Parameters!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: FT232H SCAN Bridge USB Parameters!");
			return RET_ERROR_FT232H_SBR_PARAMETERS;
		}

		// USB FT232H Port 통신 흐름제어 설정
		ft232hStatus = AfxFT232HSetFlowControl(m_nFT232HIndex, FT_FLOW_RTS_CTS, NULL, NULL);
		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			//::MessageBox(NULL, _T("Error: FT232H SCAN Bridge Flow Control!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: FT232H SCAN Bridge Flow Control!");
			return RET_ERROR_FT232H_SBR_FLOW;
		}

		// 송/수신 버퍼 초기화
		ft232hStatus = AfxFT232HPurge(m_nFT232HIndex, FT_PURGE_RX | FT_PURGE_TX);
		if (ft232hStatus != FT_OK)
		{
			free(lpft232hDeviceInfo);
			//::MessageBox(NULL, _T("Error: FT232H SCAN Bridge Purge RX and TX!"), _T("FT232H ERROR"), MB_OK);
			memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
			strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: FT232H SCAN Bridge Purge RX and TX!");
			return RET_ERROR_FT232H_SBR_PURGE;
		}
		// SEM Scan Bridge Board OK
		m_bScanBridgeConnected = TRUE;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	// 할당된 메모리 삭제
	free(lpft232hDeviceInfo);

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// FT232H USB Port 연결 장치 닫기
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxFT232HPortClose(int nDevicePort)
{
	FT_HANDLE ft232hHandle = AfxFT232HGetHandle(nDevicePort);
	if (ft232hHandle == NULL) return RET_ERROR_FT232H_DEV_HANDLE;

	// FT232H USB Port Close
	FT_STATUS nStatus = AfxFT232HClose(nDevicePort);
	//if (nStatus != FT_INVALID_HANDLE)
	{
		// Close Port Handle Clear
		m_hFT232HDevice[nDevicePort] = NULL;
	}

	return RET_SUCCESS_OK;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////
// FT232H Port : 단일 WORD 데이터 전송
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxFT232HPortSendCommand(int nPort, WORD wCommand, int nPara)
{
	////////////////////////////////////////////////////////////////////////////////////
	// SE 이미지 스캔 및 캡처 장치 데이터 전송 : 단일 WORD 데이터 전송
	////////////////////////////////////////////////////////////////////////////////////
	if (nPort == IDX_FT232H_SEM_IMAGE_DEVICE)
	{
		// SE Image Scan Handle Index
		m_nFT232HIndex = nPort;// IDX_FT232H_SE_IMAGE_SCAN;

		FT_HANDLE ft232hHandle = AfxFT232HGetHandle(m_nFT232HIndex);
		if (ft232hHandle == NULL) return RET_ERROR_FT232H_SEM_HANDLE;

		ULONG btWrite = 0;
		WORD wTemp = 0;
		WORD wComBuf[4] = { 0,0,0,0 };
		int nNum = 4;

		BYTE *pData = (BYTE*)wComBuf;
		wTemp = nPara >> 16;
		wComBuf[0] = (wTemp << 8) | wCommand;
		wComBuf[1] = (WORD)nPara;

		// 전송
		AfxFT232HWrite(m_nFT232HIndex, pData, nNum, &btWrite);

		// 전송할 데이터갯수 와 실제 전송한 데이터갯수가 다르다면
		if (nNum != (int)btWrite)
		{
			// 에러 메시지를 한번만 나타낸다
			if (m_bSEImageScanPortErrorFlag == FALSE)
			{
				m_bSEImageScanPortErrorFlag = TRUE;
				//::MessageBox(NULL, _T("Error: FT232H Image Port Sending Data!"), _T("FT232H ERROR"), MB_OK);
				memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
				strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: FT232H Image Port Sending Data!");
			}
			return RET_ERROR_FT232H_SEM_SEND;
		}
	}
	////////////////////////////////////////////////////////////////////////////////////
	// BSE 이미지 스캔 및 캡처 장치 데이터 전송 : 단일 WORD 데이터 전송
	////////////////////////////////////////////////////////////////////////////////////
	else if (nPort == IDX_FT232H_BSE_IMAGE_DEVICE)
	{
		// BSE Image Scan Handle Index
		m_nFT232HIndex = nPort;// IDX_FT232H_BSE_IMAGE_SCAN;

		FT_HANDLE ft232hHandle = AfxFT232HGetHandle(m_nFT232HIndex);
		if (ft232hHandle == NULL) return RET_ERROR_FT232H_BSE_HANDLE;

		ULONG btWrite = 0;
		WORD wTemp = 0;
		WORD wComBuf[4] = { 0, 0, 0, 0 };
		BYTE *pData = NULL;
		int nNum = 4;

		pData = (BYTE *)wComBuf;
		wTemp = nPara >> 16;

		wComBuf[0] = (wTemp << 8) | wCommand;
		wComBuf[1] = (WORD)nPara;

		// 전송
		AfxFT232HWrite(m_nFT232HIndex, pData, nNum, &btWrite);

		// 전송할 데이터갯수 와 실제 전송한 데이터갯수가 다르다면
		if (nNum != (int)btWrite)
		{
			// 에러 메시지를 한번만 나타낸다
			if (m_bBSEImageScanPortErrorFlag == FALSE)
			{
				m_bBSEImageScanPortErrorFlag = TRUE;
				//::MessageBox(NULL, _T("Error: FT232H BSE Image Scan Data Sending!"), _T("FT232H ERROR"), MB_OK);
				memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
				strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: FT232H BSE Image Scan Data Sending!");
			}
			return RET_ERROR_FT232H_BSE_SEND;
		}
	}
	////////////////////////////////////////////////////////////////////////////////////
	// SEM 장치 제어 및 스캔 장치(Scan Bridge) 데이터 전송 : 단일 WORD 데이터 전송
	////////////////////////////////////////////////////////////////////////////////////
	else if (nPort == IDX_FT232H_SCAN_BRIDGE_DEVICE)
	{
		// SEM Device Control (Scan Bridge) Handle Index
		m_nFT232HIndex = nPort;// IDX_FT232H_SEM_DEVICE_CONTROL;

		FT_HANDLE ft232hHandle = AfxFT232HGetHandle(m_nFT232HIndex);
		if (ft232hHandle == NULL) return RET_ERROR_FT232H_SBR_HANDLE;

		ULONG btWrite = 0;
		WORD wTemp = 0;
		WORD wComBuf[4] = { 0, 0, 0, 0 };
		BYTE *pData = NULL;
		int nNum = 4;

		// 2018.06.12
		// (원본C++Builder코드) 아래의 코드는 흐름상 실행의 의미가 없는 코드임,
		// WTemp 값을 설정하지만 다음 흐름에서 WTemp를 재설정 하므로 실행의 의미가 없음
		if (wCommand == cWR_OUTPORT)
		{
			if (nPara & XSCAN_INVERSE_HIGH)
			{
				wTemp = wCommand;
			}
		}

		pData = (BYTE *)wComBuf;
		wTemp = nPara >> 16;      // wTemp 를 재설정함

		wComBuf[0] = (wTemp << 8) | wCommand;
		wComBuf[1] = (WORD)nPara;

		// 전송
		AfxFT232HWrite(m_nFT232HIndex, pData, nNum, &btWrite);

		// 전송할 데이터갯수 와 실제전송한 데이터갯수가 다르다면
		if (nNum != (int)btWrite)
		{
			// 에러 메시지를 한번만 나타낸다
			if (m_bDeviceControlPortErrorFlag == FALSE)
			{
				m_bDeviceControlPortErrorFlag = TRUE;
				//::MessageBox(NULL, _T("Error: FT232H SEM Device(Scan Bridge) Control Port Sending Data!"), _T("FT232H ERROR"), MB_OK);
				memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
				strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: FT232H SEM Device(Scan Bridge) Control Port Sending Data!");
			}
			return RET_ERROR_FT232H_SBR_SEND;
		}
	}
	////////////////////////////////////////////////////////////////////////////////////
	// 오류
	////////////////////////////////////////////////////////////////////////////////////
	else
	{
		//::MessageBox(NULL, _T("Error: FT232H SendCommand <Port index value>!"), _T("FT232H ERROR"), MB_OK);
		memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
		strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: FT232H SendCommand <Port index value>!");
		memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
		strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: FT232H SendCommand <Port index value>!");
		memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
		strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: FT232H SendCommand <Port index value>!");
		return RET_ERROR_FT232H_DEV_INDEX;
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// FT232H : 멀티 데이터 전송
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxFT232HPortSendMultiCommand(int nPort, WORD *pwScanBuf, int nWords)
{
	////////////////////////////////////////////////////////////////////////////////////
	// SE 이미지 스캔 및 캡처 장치 데이터 전송 : 멀티 WORD 데이터 전송
	////////////////////////////////////////////////////////////////////////////////////
	if (nPort == IDX_FT232H_SEM_IMAGE_DEVICE)
	{
		// SE Image Scan Handle Index
		m_nFT232HIndex = nPort;// IDX_FT232H_SEM_IMAGE_DEVICE;

		FT_HANDLE ft232hHandle = AfxFT232HGetHandle(m_nFT232HIndex);
		if (ft232hHandle == NULL) return RET_ERROR_FT232H_SEM_HANDLE;

		ULONG btWrite = 0;
		int nNum = 2 * nWords;

		// 전송
		AfxFT232HWrite(m_nFT232HIndex, pwScanBuf, nNum, &btWrite);

		// 전송할 데이터갯수 와 실제전송한 데이터갯수가 다르다면
		if (nNum != (int)btWrite)
		{
			// 에러 메시지를 한번만 나타낸다
			if (m_bSEImageScanPortErrorFlag == FALSE)
			{
				m_bSEImageScanPortErrorFlag = TRUE;
				//::MessageBox(NULL, _T("Error: FT232H Image Scan Port Sending Multi Data!"), _T("FT232H ERROR"), MB_OK);
				memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
				strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: FT232H Image Scan Port Sending Multi Data!");
			}
			return RET_ERROR_FT232H_SEM_MSEND;
		}
	}
	////////////////////////////////////////////////////////////////////////////////////
	// BSE 이미지 스캔 및 캡처 장치 데이터 전송 : 멀티 WORD 데이터 전송
	////////////////////////////////////////////////////////////////////////////////////
	else if (nPort == IDX_FT232H_BSE_IMAGE_DEVICE)
	{
		// BSE Image Scan Handle Index
		m_nFT232HIndex = nPort;// IDX_FT232H_BSE_IMAGE_DEVICE;

		FT_HANDLE ft232hHandle = AfxFT232HGetHandle(m_nFT232HIndex);
		if (ft232hHandle == NULL) return RET_ERROR_FT232H_BSE_HANDLE;

		ULONG btWrite;
		int nNum = 2 * nWords;

		// 전송
		AfxFT232HWrite(m_nFT232HIndex, pwScanBuf, nNum, &btWrite);

		// 전송할 데이터갯수 와 실제전송한 데이터갯수가 다르다면
		if (nNum != (int)btWrite)
		{
			// 에러 메시지를 한번만 나타낸다
			if (m_bBSEImageScanPortErrorFlag == FALSE)
			{
				m_bBSEImageScanPortErrorFlag = TRUE;
				//::MessageBox(NULL, _T("Error: FT232H BSE Image Scan Multi Data Sending!"), _T("FT232H ERROR"), MB_OK);
				memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
				strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: FT232H BSE Image Scan Multi Data Sending!");
			}
			return RET_ERROR_FT232H_BSE_MSEND;
		}
	}
	////////////////////////////////////////////////////////////////////////////////////
	// SEM 장치 제어 및 스캔 장치(Scan Bridge) 데이터 전송 : 멀티 WORD 데이터 전송
	////////////////////////////////////////////////////////////////////////////////////
	else if (nPort == IDX_FT232H_SCAN_BRIDGE_DEVICE)
	{
		// SEM Device Control (Scan Bridge) Handle Index
		m_nFT232HIndex = nPort;// IDX_FT232H_SCAN_BRIDGE_DEVICE;

		FT_HANDLE ft232hHandle = AfxFT232HGetHandle(m_nFT232HIndex);
		if (ft232hHandle == NULL) return RET_ERROR_FT232H_SBR_HANDLE;

		ULONG btWrite;
		int nNum = 2 * nWords;

		// 전송
		AfxFT232HWrite(m_nFT232HIndex, pwScanBuf, nNum, &btWrite);

		// 전송할 데이터갯수 와 실제전송한 데이터갯수가 다르다면
		if (nNum != (int)btWrite)
		{
			// 에러 메시지를 한번만 나타낸다
			if (m_bDeviceControlPortErrorFlag == FALSE)
			{
				m_bDeviceControlPortErrorFlag = TRUE;
				//::MessageBox(NULL, _T("Error: FT232H SEM Device(Scan Bridge) Control Port Sending Multi Data!"), _T("FT232H ERROR"), MB_OK);
				memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
				strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: FT232H SEM Device(Scan Bridge) Control Port Sending Multi Data!");
			}
			return RET_ERROR_FT232H_SBR_MSEND;
		}
	}
	////////////////////////////////////////////////////////////////////////////////////
	// 오류
	////////////////////////////////////////////////////////////////////////////////////
	else
	{
		//::MessageBox(NULL, _T("Error: FT232H SendMultiCommand <Port index value>!"), _T("FT232H ERROR"), MB_OK);
		memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
		strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: FT232H SendMultiCommand <Port index value>!");
		memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
		strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: FT232H SendMultiCommand <Port index value>!");
		memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
		strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: FT232H SendMultiCommand <Port index value>!");
		return RET_ERROR_FT232H_DEV_INDEX;
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// FT232H : AVR 데이터 전송
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxFT232HPortSendAvrCommand(int nPort, char *pszCommand, int nVal)
{
	////////////////////////////////////////////////////////////////////////////////////
	// SE 이미지 스캔 및 캡처 장치 데이터 전송 : AVR 데이터 전송
	////////////////////////////////////////////////////////////////////////////////////
	if (nPort == IDX_FT232H_SEM_IMAGE_DEVICE)
	{
		// SE Image Scan Handle Index
		m_nFT232HIndex = nPort; //IDX_FT232H_SEM_IMAGE_DEVICE;

		FT_HANDLE ft232hHandle = AfxFT232HGetHandle(m_nFT232HIndex);
		if (ft232hHandle == NULL) return RET_ERROR_FT232H_SEM_HANDLE;

		char szData[255+1];
		char szVal[255+1];
		char *pszData = NULL;

		ULONG btWrite = 0;
		int nCheckSum = 0;
		int nNum      = 0;

		memset(szData, 0x00, sizeof(szData));
		memset(szVal , 0x00, sizeof(szVal));

		// AVR Command 설정
		szData[0] = (char)sAVR_COM_FIFO;   // AVR Command
		szData[1] = (char)0x30;            // Not Used in FPGA  
		szData[2] = (char)0x30;            // Not Used in FPGA  
		szData[3] = (char)0x30;            // Not Used in FPGA  

		// 복사 위치 설정
		pszData = szData + 4;
		// Command Data 설정
		strcat(pszData, pszCommand);

		// Parameter 설정
		_itoa(nVal, szVal, 10);
		nNum = strlen(szVal);
		strcat(szData, szVal);

		// Check Sum 설정
		// AVR Command 4Byte는 FPGA에서 사용 후 사라짐, Command Data 및 Parameter 만 Check Sum으로 사용
		while (*pszData != NULL)
		{
			nCheckSum += *pszData;
			pszData++;
		}
		// CheckSum 문자 설정
		*pszData = '?';
		// CheckSum 계산
		memset(szVal, 0x00, sizeof(szVal));
		nCheckSum = nCheckSum % 100;
		// CheckSum 자료 설정 및 종료문자 설정
		_itoa(nCheckSum, szVal, 10);
		strcat(szData, szVal);
		strcat(szData, ";");

		// FPGA에서 사용할 종료 식별자 추가
		nNum = strlen(szData);
		szData[nNum] = (char)0xFF; // 종료 식별자
		nNum++;
		szData[nNum] = NULL; // NULL 문자

							 // 전송
		AfxFT232HWrite(m_nFT232HIndex, szData, nNum, &btWrite);

		// 실제전송한 데이터갯수
		return btWrite;
	}
	////////////////////////////////////////////////////////////////////////////////////
	// BSE 이미지 스캔 및 캡처 장치 데이터 전송 : AVR 데이터 전송
	////////////////////////////////////////////////////////////////////////////////////
	else if (nPort == IDX_FT232H_BSE_IMAGE_DEVICE)
	{
		// BSE Image Device Handle Index
		m_nFT232HIndex = nPort; //IDX_FT232H_BSE_IMAGE_DEVICE;

		FT_HANDLE ft232hHandle = AfxFT232HGetHandle(m_nFT232HIndex);
		if (ft232hHandle == NULL) return RET_ERROR_FT232H_BSE_HANDLE;

		char szData[255+1];
		char szVal[255+1];

		char *pszData = NULL;
		ULONG btWrite = 0;
		int nCheckSum = 0;
		int nNum = 0;

		memset(szData, 0x00, sizeof(szData));
		memset(szVal, 0x00, sizeof(szVal));

		// AVR Command 설정
		szData[0] = (char)bAVR_UART_TX;    // AVR Command
		szData[1] = (char)0x30;            // Not Used in FPGA  
		szData[2] = (char)0x30;            // Not Used in FPGA  
		szData[3] = (char)0x30;            // Not Used in FPGA  

		// 복사 위치 설정
		pszData = szData + 4;
		// Command Data 설정
		strcat(pszData, pszCommand);

		// Parameter 설정
		_itoa(nVal, szVal, 10);
		nNum = strlen(szVal);
		strcat(szData, szVal);

		// Check Sum 설정
		// AVR Command 4Byte는 FPGA에서 사용 후 사라짐, Command Data 및 Parameter 만 Check Sum으로 사용
		while (*pszData != NULL)
		{
			nCheckSum += *pszData;
			pszData++;
		}
		// CheckSum 문자 설정
		*pszData = '?';
		// CheckSum 계산
		memset(szVal, 0x00, sizeof(szVal));
		nCheckSum = nCheckSum % 100;
		// CheckSum 자료 설정 및 종료문자 설정
		_itoa(nCheckSum, szVal, 10);
		strcat(szData, szVal);
		strcat(szData, ";");

		// FPGA에서 사용할 종료 식별자 추가
		nNum = strlen(szData);
		szData[nNum] = (char)0xFF; // 종료 식별자
		nNum++;
		szData[nNum] = NULL; // NULL 문자

							 // 전송
		AfxFT232HWrite(m_nFT232HIndex, szData, nNum, &btWrite);

		// 실제전송한 데이터갯수
		return btWrite;
	}
	////////////////////////////////////////////////////////////////////////////////////
	// SEM 장치 제어 및 스캔 장치(Scan Bridge) 데이터 전송 : AVR 데이터 전송
	////////////////////////////////////////////////////////////////////////////////////
	else if (nPort == IDX_FT232H_SCAN_BRIDGE_DEVICE)
	{
		// SEM Device Control (Scan Bridge) Handle Index
		m_nFT232HIndex = nPort; //IDX_FT232H_SCAN_BRIDGE_DEVICE;

		FT_HANDLE ft232hHandle = AfxFT232HGetHandle(m_nFT232HIndex);
		if (ft232hHandle == NULL) return RET_ERROR_FT232H_SBR_HANDLE;
		
		char szData[255+1];
		char szVal[255+1];
		char *pszData = NULL;

		ULONG btWrite = 0;
		int nCheckSum = 0;
		int nNum      = 0;

		memset(szData, 0x00, sizeof(szData));
		memset(szVal, 0x00, sizeof(szVal));

		// AVR Command 설정
		szData[0] = (char)sAVR_COM_FIFO;   // AVR Command
		szData[1] = (char)0x30;            // Not Used in FPGA  
		szData[2] = (char)0x30;            // Not Used in FPGA  
		szData[3] = (char)0x30;            // Not Used in FPGA  

		// 복사 위치 설정
		pszData = szData + 4;
		// Command Data 설정
		strcat(pszData, pszCommand);

		// Parameter 설정
		_itoa(nVal, szVal, 10);
		nNum = strlen(szVal);
		strcat(szData, szVal);

		// Check Sum 설정
		// AVR Command 4Byte는 FPGA에서 사용 후 사라짐, Command Data 및 Parameter 만 Check Sum으로 사용
		while (*pszData != NULL)
		{
			nCheckSum += *pszData;
			pszData++;
		}
		// CheckSum 문자 설정
		*pszData = '?';
		// CheckSum 계산
		memset(szVal, 0x00, sizeof(szVal));
		nCheckSum = nCheckSum % 100;
		// CheckSum 자료 설정 및 종료문자 설정
		_itoa(nCheckSum, szVal, 10);
		strcat(szData, szVal);
		strcat(szData, ";");

		// FPGA에서 사용할 종료 식별자 추가
		nNum = strlen(szData);
		szData[nNum] = (char)0xFF; // 종료 식별자
		nNum++;
		szData[nNum] = NULL; // NULL 문자

							 // 전송
		AfxFT232HWrite(m_nFT232HIndex, szData, nNum, &btWrite);

		// 실제전송한 데이터갯수
		return btWrite;
		
	}
	////////////////////////////////////////////////////////////////////////////////////
	// 오류
	////////////////////////////////////////////////////////////////////////////////////
	else
	{
		//::MessageBox(NULL, _T("Error: FT232H SendAvrCommand <Port index value>!"), _T("FT232H ERROR"), MB_OK);
		memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
		strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: FT232H SendAvrCommand <Port index value>!");
		memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
		strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: FT232H SendAvrCommand <Port index value>!");
		memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
		strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: FT232H SendAvrCommand <Port index value>!");
		return RET_ERROR_FT232H_DEV_INDEX;
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// FT232H : AVR 데이터 전송 (명령어전송)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxFT232HPortSendAvrCommand(int nPort, char *pszCommand)
{
	////////////////////////////////////////////////////////////////////////////////////
	// SE 이미지 스캔 및 캡처 장치 데이터 전송 : AVR 데이터 전송
	////////////////////////////////////////////////////////////////////////////////////
	if (nPort == IDX_FT232H_SEM_IMAGE_DEVICE)
	{
		// SE Image Scan Handle Index
		m_nFT232HIndex = nPort; //IDX_FT232H_SEM_IMAGE_DEVICE;

		FT_HANDLE ft232hHandle = AfxFT232HGetHandle(m_nFT232HIndex);
		if (ft232hHandle == NULL) return RET_ERROR_FT232H_SEM_HANDLE;

		char szData[255+1];
		char szVal[255+1];

		char *pszData = NULL;
		ULONG btWrite = 0;
		int nCheckSum = 0;
		int nNum = 0;

		memset(szData, 0x00, sizeof(szData));
		memset(szVal, 0x00, sizeof(szVal));

		// AVR Command 설정
		szData[0] = (char)sAVR_COM_FIFO;   // AVR Command
		szData[1] = (char)0x30;            // Not Used in FPGA  
		szData[2] = (char)0x30;            // Not Used in FPGA  
		szData[3] = (char)0x30;            // Not Used in FPGA  

		// 복사 위치 설정
		pszData = szData + 4;
		// Command Data 설정
		strcpy(pszData, pszCommand);

		// Check Sum 설정
		// AVR Command 4Byte는 FPGA에서 사용 후 사라짐, Command Data 만 Check Sum으로 사용
		while (*pszData != ';')
		{
			nCheckSum += *pszData;
			pszData++;
		}
		// CheckSum 문자 설정
		*pszData = '?';
		// CheckSum 계산
		memset(szVal, 0x00, sizeof(szVal));
		nCheckSum = nCheckSum % 100;
		// CheckSum 자료 설정 및 종료문자 설정
		_itoa(nCheckSum, szVal, 10);
		strcat(szData, szVal);
		strcat(szData, ";");

		// FPGA에서 사용할 종료 식별자 추가
		nNum = strlen(szData);
		szData[nNum] = (char)0xFF; // 종료 식별자
		nNum++;
		szData[nNum] = NULL; // NULL 문자

		// 전송
		AfxFT232HWrite(m_nFT232HIndex, szData, nNum, &btWrite);

		// 실제전송한 데이터갯수
		return btWrite;
	}
	////////////////////////////////////////////////////////////////////////////////////
	// BSE 이미지 스캔 및 캡처 장치 데이터 전송 : AVR 데이터 전송
	////////////////////////////////////////////////////////////////////////////////////
	else if (nPort == IDX_FT232H_BSE_IMAGE_DEVICE)
	{
		// BSE Image Scan Handle Index
		m_nFT232HIndex = nPort; //IDX_FT232H_BSE_IMAGE_DEVICE;

		FT_HANDLE ft232hHandle = AfxFT232HGetHandle(m_nFT232HIndex);
		if (ft232hHandle == NULL) return RET_ERROR_FT232H_BSE_HANDLE;

		char szData[255+1];
		char szVal[255+1];

		char *pszData = NULL;
		ULONG btWrite = 0;
		int nCheckSum = 0;
		int nNum = 0;

		memset(szData, 0x00, sizeof(szData));
		memset(szVal , 0x00, sizeof(szVal));

		// AVR Command 설정
		szData[0] = (char)bAVR_UART_TX;    // AVR Command
		szData[1] = (char)0x30;            // Not Used in FPGA  
		szData[2] = (char)0x30;            // Not Used in FPGA  
		szData[3] = (char)0x30;            // Not Used in FPGA  

	    // 복사 위치 설정
		pszData = szData + 4;
		// Command Data 설정
		strcat(pszData, pszCommand);

		// Check Sum 설정
		// AVR Command 4Byte는 FPGA에서 사용 후 사라짐, Command Data 만 Check Sum으로 사용
		while (*pszData != ';')
		{
			nCheckSum += *pszData;
			pszData++;
		}
		// CheckSum 문자 설정
		*pszData = '?';
		// CheckSum 계산
		memset(szVal, 0x00, sizeof(szVal));
		nCheckSum = nCheckSum % 100;
		// CheckSum 자료 설정 및 종료문자 설정
		_itoa(nCheckSum, szVal, 10);
		strcat(szData, szVal);
		strcat(szData, ";");

		// FPGA에서 사용할 종료 식별자 추가
		nNum = strlen(szData);
		szData[nNum] = (char)0xFF; // 종료 식별자
		nNum++;
		szData[nNum] = NULL; // NULL 문자

		// 전송
		AfxFT232HWrite(m_nFT232HIndex, szData, nNum, &btWrite);

		// 실제전송한 데이터갯수
		return btWrite;
	}
	////////////////////////////////////////////////////////////////////////////////////
	// SEM 장치 제어 및 스캔 장치(Scan Bridge) 데이터 전송 : AVR 데이터 전송
	////////////////////////////////////////////////////////////////////////////////////
	else if (nPort == IDX_FT232H_SCAN_BRIDGE_DEVICE)
	{
		// SEM Device Control (Scan Bridge) Handle Index
		m_nFT232HIndex = nPort; //IDX_FT232H_SCAN_BRIDGE_DEVICE;

		FT_HANDLE ft232hHandle = AfxFT232HGetHandle(m_nFT232HIndex);
		if (ft232hHandle == NULL) return RET_ERROR_FT232H_SBR_HANDLE;
		
		char szData[255+1];
		char szVal[255+1];

		char *pszData = NULL;
		ULONG btWrite = 0;
		int nCheckSum = 0;
		int nNum = 0;

		memset(szData, 0x00, sizeof(szData));
		memset(szVal , 0x00, sizeof(szVal));

		// AVR Command 설정
		szData[0] = (char)sAVR_COM_FIFO;   // AVR Command
		szData[1] = (char)0x30;            // Not Used in FPGA  
		szData[2] = (char)0x30;            // Not Used in FPGA  
		szData[3] = (char)0x30;            // Not Used in FPGA  

	    // 복사 위치 설정
		pszData = szData + 4;
		// Command Data 설정
		strcpy((char*)pszData, pszCommand);

		// Check Sum 설정
		// AVR Command 4Byte는 FPGA에서 사용 후 사라짐, Command Data 만 Check Sum으로 사용
		while (*pszData != ';')
		{
			nCheckSum += *pszData;
			pszData++;
		}
		// CheckSum 문자 설정
		*pszData = '?';
		// CheckSum 계산
		memset(szVal, 0x00, sizeof(szVal));
		nCheckSum = nCheckSum % 100;
		// CheckSum 자료 설정 및 종료문자 설정
		_itoa(nCheckSum, szVal, 10);
		strcat((char*)szData, szVal);
		strcat((char*)szData, ";");

		// FPGA에서 사용할 종료 식별자 추가
		nNum = strlen((char*)szData);
		szData[nNum] = (char)0xFF; // 종료 식별자
		nNum++;
		szData[nNum] = NULL; // NULL 문자

		// 전송
		AfxFT232HWrite(m_nFT232HIndex, szData, nNum, &btWrite);

		// 실제전송한 데이터갯수
		return btWrite;
		
	}
	////////////////////////////////////////////////////////////////////////////////////
	// 오류
	////////////////////////////////////////////////////////////////////////////////////
	else
	{
		//::MessageBox(NULL, _T("Error: FT232H SendAvrCommand[cmd] <Port index value>!"), _T("FT232H ERROR"), MB_OK);
		memset(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], 0x00, 256);
		strcpy_s(m_szErrorMessage[IDX_FT232H_SEM_IMAGE_DEVICE], "Error: FT232H SendAvrCommand[cmd] <Port index value>!");
		memset(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], 0x00, 256);
		strcpy_s(m_szErrorMessage[IDX_FT232H_BSE_IMAGE_DEVICE], "Error: FT232H SendAvrCommand[cmd] <Port index value>!");
		memset(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], 0x00, 256);
		strcpy_s(m_szErrorMessage[IDX_FT232H_SCAN_BRIDGE_DEVICE], "Error: FT232H SendAvrCommand[cmd] <Port index value>!");
		return RET_ERROR_FT232H_DEV_INDEX;
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// FT232H : USB Device 사용여부 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxFT232HDeviceUse(int nUse)
{
	m_nFT232HDeviceUse = nUse;

	return RET_SUCCESS_OK;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Utility Function...
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Se Command : Command Create & Initilize (SEM Image Command 변수 초기화)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxCreateSeImageCommand(void)
{
	/*
	if (m_pSeCommand != NULL)
	{
		delete m_pSeCommand;
		m_pSeCommand = NULL;
	}

	// 공용 명령어에 필요한 변수 생성
	m_pSeCommand = new SEM_IMAGE_COMMAND_STRUCT;
	// 초기화
	memset(m_pSeCommand, 0x00, sizeof(SEM_IMAGE_COMMAND_STRUCT));

	// 초기값 설정
	m_pIntegrated->btImageAvrBPort = 0;
	*/

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated : Command Create & Initilize (공용변수 초기화)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxCreateIntegratedCommand(void)
{
	if (m_pIntegrated != NULL)
	{
		delete m_pIntegrated;
		m_pIntegrated = NULL;
	}

	// 공용 명령어에 필요한 변수 생성
	m_pIntegrated = new INTEGRATED_COMMAND_STRUCT;
	// 초기화
	memset(m_pIntegrated, 0x00, sizeof(INTEGRATED_COMMAND_STRUCT));
	// VERSION 설정 : ??20190722 (앞의 두자리는 프로그램 종류에 따른 설정, 10이면 범용 버전) 
	m_pIntegrated->dwVersion         = 1020190722;     // 10->범용, 20->NanoFlash 계열, 30->BioFlash 계열 ...
	// 장치연결 Flag
	m_pIntegrated->bSemConnectedFlag = m_bSemImageConnected;  // SE Image 장치
	m_pIntegrated->bBseConnectedFlag = m_bBseImageConnected;  // BSE Image 장치
	m_pIntegrated->bSbrConnectedFlag = m_bScanBridgeConnected;// Scan Bridge 장치
	// SEM MODEL
	m_pIntegrated->nSemModel      = 1;                 // SEM Model : SM-300B CL 기본값
	// GUN HV 초기값 설정
	m_pIntegrated->nGunHVIndex    = 0;                 // GUN HV 목표값 인덱스
	m_pIntegrated->nGunHVValue    = 0;                 // GUN HV 목표값 (전압)
	m_pIntegrated->nGunHVCurIndex = 0;                 // GUN HV 현재값 인덱스
	m_pIntegrated->nGunHVCurValue = 0;                 // GUN HV 현재값 (전압)
	m_pIntegrated->nGunHVExeIndex = 0;                 // GUN HV 처리중 인덱스
	m_pIntegrated->nGunHVExeValue = 0;                 // GUN HV 처리중 (전압)
	// 필라멘트
	m_pIntegrated->nFilamentValue    = 0;              // Filament 목표값
	m_pIntegrated->nFilamentCurValue = 0;              // Filament 현재값
	m_pIntegrated->nFilamentExeValue = 0;              // Filament 실행중인값
	m_pIntegrated->nFilamentOldValue = 0;              // Filament 목표 및 현재값 보관
	// BIAS
	m_pIntegrated->nBiasValue    = 0;                  // Bias 목표값
	m_pIntegrated->nBiasCurValue = 0;                  // Bias 현재값
	m_pIntegrated->nBiasExeValue = 0;                  // Bias 실행중인값
	m_pIntegrated->nBiasOldValue = 0;                  // Bias 목표 및 현재값 보관
	//
	m_pIntegrated->dAmpRk=2.4;                         // SEM 모델에 따라 기본값을 설정한다 (SM-300A CL:3.9, SM-300B CL:2.4, SM-200A CL:3.0, BK-200:2.4, S-2500히타치:4.4, 200CL USER:3.0, 300CL USER:2.4)
	m_pIntegrated->dRefR=2.0;                          // SEM 모델에 따라 기본값을 설정한다 (SM-300A CL:3.3, SM-300B CL:2.0, SM-200A CL:2.0, BK-200:2.0, S-2500히타치:2.0, 200CL USER:2.0, 300CL USER:2.0)
	// HV Power On Flag
	m_pIntegrated->bGunHVPowerOnFlag      = FALSE;     // GUN HV Power On Flag
	m_pIntegrated->bFilamentPowerOnFlag   = FALSE;     // Filament HV Power On Flag
	m_pIntegrated->bBiasPowerOnFlag       = FALSE;     // Bias HV Power On Flag
	m_pIntegrated->bPMTPowerOnFlag        = FALSE;     // PMT HV Power On Flag
	m_pIntegrated->bDETPowerOnFlag        = FALSE;     // Detector HV Power On Flag
	m_pIntegrated->bSM2500PowerOnFlag     = FALSE;     // Hitachi SM-2500 HV Power On Flag
	m_pIntegrated->bContrastOnFlag        = FALSE;     // HV 설정시 Contrast 처음 실행 Flag
	m_pIntegrated->bScanRotationOnFlag    = FALSE;     // HV 설정시 Scan Rotation 처음 실행 Flag
	m_pIntegrated->bScreenModeOnFlag      = FALSE;     // HV 설정시 Screen Mode 처음 실행 Flag
	m_pIntegrated->bHVUpEndProcessFlag    = FALSE;     // HV ALL 실행시 Up   Ending 처음 실행 Flag
	m_pIntegrated->bHVDownEndProcessFlag  = FALSE;     // HV ALL 실행시 Down Ending 처음 실행 Flag
	m_pIntegrated->nHVStandbyProcess      = 0;         // HV Standby Mode Up/Down Process Status : 1->Standby, 0->Normal
	m_pIntegrated->nGunHVUpDownProcess    = 0;         // Gun HV   Up/Down Process Status : 10->Start, 20->Process, 99->End
	m_pIntegrated->nFilamentUpDownProcess = 0;         // Filament Up/Down Process Status : 10->Start, 20->Process, 99->End
	m_pIntegrated->nBiasUpDownProcess     = 0;         // Bias     Up/Down Process Status : 10->Start, 20->Process, 99->End
	m_pIntegrated->bHVStartProcessFlag    = FALSE;     // HV Start Process Execute Flag
	m_pIntegrated->bHVAllStartProcessFlag = FALSE;     // HV All Start Process Execute Flag
	m_pIntegrated->bHVAllStopProcessFlag  = FALSE;     // HV All Stop  Process Execute Flag
	// GUN HV Voltage 초기화
	m_pIntegrated->dGunHVCurVoltage    = 0.0;          // GUN HV 현재 설정된 Voltage
	m_pIntegrated->dGunHVUpVoltage     = 0.0;          // GUN HV 현재 설정된 Up Voltage
	m_pIntegrated->dGunHVDownVoltage   = 0.0;          // GUN HV 현재 설정된 Down Voltage
	m_pIntegrated->dGunHVStartVoltage  = 0.0;          // GUN HV 현재 설정된 Start Voltage
	m_pIntegrated->dGunHVStopVoltage   = 0.0;          // GUN HV 현재 설정된 Stop  Voltage
	m_pIntegrated->dGunHVStepVoltage   = 0.0;          // GUN HV 현재 설정된 Step  Voltage
	m_pIntegrated->dGunHVMaxVoltage    = 0.0;          // GUN HV 현재 설정된 Max   Voltage
	m_pIntegrated->dGunHVMinVoltage    = 0.0;          // GUN HV 현재 설정된 Min   Voltage
	m_pIntegrated->dGunHVBackupVoltage = 0.0;          // GUN HV 현재 설정된 Voltage Backup
	// FILAMENT Voltage 초기화
	m_pIntegrated->dFilamentCurVoltage    = 0.0;       // FILAMENT 현재 설정된 Voltage
	m_pIntegrated->dFilamentUpVoltage     = 0.0;       // FILAMENT 현재 설정된 Up Voltage
	m_pIntegrated->dFilamentDownVoltage   = 0.0;       // FILAMENT 현재 설정된 Down Voltage
	m_pIntegrated->dFilamentStartVoltage  = 0.0;       // FILAMENT 현재 설정된 Start Voltage
	m_pIntegrated->dFilamentStopVoltage   = 0.0;       // FILAMENT 현재 설정된 Stop  Voltage
	m_pIntegrated->dFilamentStepVoltage   = 0.0;       // FILAMENT 현재 설정된 Step  Voltage
	m_pIntegrated->dFilamentMaxVoltage    = 0.0;       // FILAMENT 현재 설정된 Max   Voltage
	m_pIntegrated->dFilamentMinVoltage    = 0.0;       // FILAMENT 현재 설정된 Min   Voltage
	m_pIntegrated->dFilamentBackupVoltage = 0.0;       // FILAMENT 현재 설정된 Voltage Backup
	// BIAS Voltage 초기화
	m_pIntegrated->dBiasCurVoltage    = 0.0;           // BIAS 현재 설정된 Voltage
	m_pIntegrated->dBiasUpVoltage     = 0.0;           // BIAS 현재 설정된 Up Voltage
	m_pIntegrated->dBiasDownVoltage   = 0.0;           // BIAS 현재 설정된 Down Voltage
	m_pIntegrated->dBiasStartVoltage  = 0.0;           // BIAS 현재 설정된 Start Voltage
	m_pIntegrated->dBiasStopVoltage   = 0.0;           // BIAS 현재 설정된 Stop  Voltage
	m_pIntegrated->dBiasStepVoltage   = 0.0;           // BIAS 현재 설정된 Step  Voltage
	m_pIntegrated->dBiasMaxVoltage    = 0.0;           // BIAS 현재 설정된 Max   Voltage
	m_pIntegrated->dBiasMinVoltage    = 0.0;           // BIAS 현재 설정된 Min   Voltage
	m_pIntegrated->dBiasBackupVoltage = 0.0;           // BIAS 현재 설정된 Voltage Backup

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated : Release Command (공용변수 제거)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxReleaseIntegratedCommand(void)
{
	// 공용 명령어 변수 제거
	if (m_pIntegrated != NULL)
	{
		delete m_pIntegrated;
		m_pIntegrated = NULL;
	}

	// SCAN ROTATION CALIBRATION DATA 삭제
	if (m_pScanRotCaliData != NULL)
	{
		delete m_pScanRotCaliData;
		m_pScanRotCaliData = NULL;
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated : Get Pointer (공용변수 포인터)
/////////////////////////////////////////////////////////////////////////////////////////////////////
INTEGRATED_COMMAND_STRUCT* AfxGetIntegratedPointer(void)
{
	// 공용 명령어 변수
	if (m_pIntegrated != NULL)
	{
		return m_pIntegrated;
	}

	return NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated : Get Pointer (SCAN ROTATION CALIBRATION DATA 포인터)
/////////////////////////////////////////////////////////////////////////////////////////////////////
SEM_SCAN_ROTATION_CALIBRATION_DATA * AfxGetScanRotationCalibrationDataPointer(void)
{
	// 공용 명령어 변수
	if (m_pScanRotCaliData != NULL)
	{
		return m_pScanRotCaliData;
	}

	return NULL;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated : INTEGRATED 파일 불러오기
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetIntegratedDataFromFile(void)
{
	// 공용 명령어 변수
	if (m_pIntegrated == NULL) return -1;

	// 공용 변수 생성
	INTEGRATED_COMMAND_STRUCT *pIntegrated = new INTEGRATED_COMMAND_STRUCT;

	// 초기화
	memset(pIntegrated, 0x00, sizeof(INTEGRATED_COMMAND_STRUCT));
	// 초기화 데이터 복사
	memcpy(pIntegrated, m_pIntegrated, sizeof(INTEGRATED_COMMAND_STRUCT));

	UINT nDataSize = sizeof(INTEGRATED_COMMAND_STRUCT);
	CString strFileName = _T("");
	strFileName = m_strDeviceServerPath + _T("\\") + _T(DEVICE_INTEGRATED_FILE_NAME);

	CFile IntegratedFile;

	// Integrated Data File Load
	if (!IntegratedFile.Open(strFileName, CFile::modeRead))
	{
		// Open or Read Error
		if (!IntegratedFile.Open(strFileName, CFile::modeCreate))
		{
			// File Create Error
			return -1;
		}
		IntegratedFile.Close();

		// Initilize Integrated Data To File
		if (!IntegratedFile.Open(strFileName, CFile::modeWrite))
		{
			return -1;
		}

		////////////////////////////////////////////////////////
		// DATA 초기화
		////////////////////////////////////////////////////////
		// CL 모델에 따른 변수 초기화
		AfxSemModelCLInitialize(m_pIntegrated->nSemModel, m_pIntegrated->dSemModelAmp, m_pIntegrated->dSemModelRef);
		// 초기화
		memset(pIntegrated, 0x00, sizeof(INTEGRATED_COMMAND_STRUCT));
		// 초기화 데이터 복사
		memcpy(pIntegrated, m_pIntegrated, sizeof(INTEGRATED_COMMAND_STRUCT));
		////////////////////////////////////////////////////////

		// 데이터 저장
		IntegratedFile.Write(pIntegrated, nDataSize);
		IntegratedFile.Close();

		// 파일 오픈 : read mode
		if (!IntegratedFile.Open(strFileName, CFile::modeRead))
		{
			return -1;
		}
	}

	// 데이터 크기
	UINT nFileSize = (UINT)IntegratedFile.GetLength();
	// 데이터 크기 비교
	if (nDataSize > nFileSize)
	{
		//IntegratedFile.Close();
		//return -1;
	}

	// 데이터 읽기
	IntegratedFile.Read(pIntegrated, nFileSize);// nDataSize);

	// 파일 닫기
	IntegratedFile.Close();

	// 데이터 복사
	memcpy(m_pIntegrated, pIntegrated, sizeof(INTEGRATED_COMMAND_STRUCT));

	///////////////////////////////////////////////////////////////////////////////////
	// 데이터 오류 확인?
	///////////////////////////////////////////////////////////////////////////////////
	AfxCheckIntegratedDataError();
	///////////////////////////////////////////////////////////////////////////////////

	// 버퍼 삭제
	delete pIntegrated;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated : INTEGRATED 데이터 오류 확인
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxCheckIntegratedDataError(void)
{
	// 공용 명령어 변수
	if (m_pIntegrated == NULL) return -1;

	///////////////////////////////////////////////////////////////////////////////////
	// 데이터 오류 확인?
	///////////////////////////////////////////////////////////////////////////////////
	if (m_pIntegrated->dScanOptionData[IDX_HWSETUP_OPTION_DOUBLE_MONITOR_SIZE] < 1.0)
	{
		// 모니터크기 기본 24인치로 재설정
		m_pIntegrated->dScanOptionData[IDX_HWSETUP_OPTION_DOUBLE_MONITOR_SIZE] = 24.0;
	}
	if (m_pIntegrated->dScanOptionData[IDX_HWSETUP_OPTION_DOUBLE_MONITOR_RATIO] < 1.0)
	{
		// 모니터크기 실제 적용율 98.5%로 재설정
		m_pIntegrated->dScanOptionData[IDX_HWSETUP_OPTION_DOUBLE_MONITOR_RATIO] = 98.5;
	}
	if ((int)strlen(m_pIntegrated->szScanOption32Text1) < 1)
	{
		// SEM DEVICE COMPANY 재설정
		strcpy_s(m_pIntegrated->szScanOption32Text1, SEM_DEVICE_COMPANY);
	}
	if ((int)strlen(m_pIntegrated->szScanOption32Text2) < 1)
	{
		// SEM DEVICE MODEL 재설정
		strcpy_s(m_pIntegrated->szScanOption32Text2, SEM_DEVICE_MODEL);
	}
	///////////////////////////////////////////////////////////////////////////////////
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_FOCUS_SCANMODE] < 1)
	{
		// AUTO FOCUS : SCAN MODE 재설정 --> FAST_SCAN_MODE
		m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_FOCUS_SCANMODE] = FAST_SCAN_MODE;
	}
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_FOCUS_UP_NUMBER] < 1)
	{
		// AUTO FOCUS : UP SCAN 갯수 재설정 --> 20
		m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_FOCUS_UP_NUMBER] = 20;
	}
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_FOCUS_DOWN_NUMBER] < 1)
	{
		// AUTO FOCUS : DOWN SCAN 갯수 재설정 --> 10
		m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_FOCUS_DOWN_NUMBER] = 10;
	}
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_FOCUS_STEP_VALUE] < 1)
	{
		// AUTO FOCUS : SCAN STEP VALUE 재설정 --> 5
		m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_FOCUS_STEP_VALUE] = 5;
	}
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_FOCUS_YPOS_VALUE] < 1)
	{
		// AUTO FOCUS : FOCUS CHANGE Y-POS 재설정 --> 450
		m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_FOCUS_YPOS_VALUE] = 450;
	}
	///////////////////////////////////////////////////////////////////////////////////
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_CONTRAST_VALUE] < 1)
	{
		// AUTO CONTRAST : CONTRAST VALUE 재설정 --> 40 (CONTRAST 목표값)
		m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_CONTRAST_VALUE] = 40;
	}
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_CONTRAST_100JUMP] < 1)
	{
		// AUTO CONTRAST : CONTRAST 100 JUMP 재설정 --> 50 (CONTRAST값 검색 100 JUMP STEP)
		m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_CONTRAST_100JUMP] = 50;
	}
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_CONTRAST_10JUMP] < 1)
	{
		// AUTO CONTRAST : CONTRAST 10 JUMP STEP 재설정 --> 20 (CONTRAST 10 JUMP STEP 증가값)
		m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_CONTRAST_10JUMP] = 20;
	}
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_BRIGHT_VALUE] < 1)
	{
		// AUTO CONTRAST : BRIGHTNESS VALUE 재설정 --> 50 (BRIGHTNESS 목표값)
		m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_BRIGHT_VALUE] = 50;
	}
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_BRIGHT_100JUMP] < 1)
	{
		// AUTO CONTRAST : BRIGHTNESS 100 JUMP 재설정 --> 50 (BRIGHTNESS값 검색 100 JUMP STEP)
		m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_BRIGHT_100JUMP] = 50;
	}
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_BRIGHT_10JUMP] < 1)
	{
		// AUTO CONTRAST : BRIGHTNESS 10 JUMP STEP 재설정 --> 20 (BRIGHTNESS 10 JUMP STEP 증가값)
		m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_AUTO_BRIGHT_10JUMP] = 20;
	}
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	// 샘플높이
	m_dSampleHeight = m_pIntegrated->dScanOptionData[IDX_HWSETUP_OPTION_DOUBLE_SAMPLE_HEIGHT];
	// 샘플넓이
	m_dSampleWidth  = m_pIntegrated->dScanOptionData[IDX_HWSETUP_OPTION_DOUBLE_SAMPLE_WIDTH];
	// 샘플명칭
	if (strlen(m_pIntegrated->szScanOption128Text1) < 1)
	{
		// 샘플명칭 초기화
		strcpy(m_pIntegrated->szScanOption128Text1, "UnnameSample");
	}

	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////
	// 초기값 설정하기
	///////////////////////////////////
    // FOCUS COARSE/FINE OLD값
	m_pIntegrated->nFocusOldCoarse = SEM_FOCUS_COARSE_MAX;
	m_pIntegrated->nFocusOldFine   = SEM_FOCUS_FINE_MAX;

	// IMAGE INVERSE FLAG
	//m_pIntegrated->bNEGImageFlag = FALSE; // 음영반전
	//m_pIntegrated->bLRMirrorFlag = FALSE; // 좌우반전
	//m_pIntegrated->bTBMirrorFlag = FALSE; // 상하반전

	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	// 2021.06.30
	// SEM START TIME 설정 CHECK

	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_HV_TIME_VALUE] < 0)
	{
		// SEM START HV UP/DOWN TIME VALUE 인덱스 값 : 5[sec]
		m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_HV_TIME_VALUE] = 4;
	}
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_HV_TIME_UNIT] < 0)
	{
		// SEM START HV UP/DOWN TIME UNIT 인덱스 값 : [sec]
		m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_HV_TIME_UNIT] = 0;
	}
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_FI_TIME_VALUE] < 0)
	{
		// SEM START FILAMENT UP/DOWN TIME VALUE 인덱스 값 : 5[sec]
		m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_FI_TIME_VALUE] = 4;
	}
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_FI_TIME_UNIT] < 0)
	{
		// SEM START FILAMENT UP/DOWN TIME UNIT 인덱스 값 : [sec]
		m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_FI_TIME_UNIT] = 0;
	}
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_BI_TIME_VALUE] < 0)
	{
		// SEM START BIAS UP/DOWN TIME VALUE 인덱스 값 : 5[sec]
		m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_BI_TIME_VALUE] = 4;
	}
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_BI_TIME_UNIT] < 0)
	{
		// SEM START BIAS UP/DOWN TIME UNIT 인덱스 값 : [sec]
		m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_BI_TIME_UNIT] = 0;
	}


	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////


	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	// 2021.07.07
	// STAGE OPTION ERROR CHECK?
	if (m_pIntegrated->dStageOptionData[IDX_STAGE_OPTION_DOUBLE_BSE_POSITION] < 0.0 || m_pIntegrated->dStageOptionData[IDX_STAGE_OPTION_DOUBLE_BSE_POSITION] > 100.0)
	{
		// BSE SET SCAN POSITION
		m_pIntegrated->dStageOptionData[IDX_STAGE_OPTION_DOUBLE_BSE_POSITION] = 0.0;
	}

	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////


	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated : INTEGRATED 파일 저장하기
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetIntegratedDataToFile(void)
{
	// 공용 명령어 변수
	if (m_pIntegrated == NULL) return -1;

	// 공용 변수 생성
	INTEGRATED_COMMAND_STRUCT *pIntegrated = new INTEGRATED_COMMAND_STRUCT;

	// 초기화
	memset(pIntegrated, 0x00, sizeof(INTEGRATED_COMMAND_STRUCT));
	// 초기화 데이터 복사
	memcpy(pIntegrated, m_pIntegrated, sizeof(INTEGRATED_COMMAND_STRUCT));

	int nDataSize = sizeof(INTEGRATED_COMMAND_STRUCT);
	CString strFileName = _T("");
	strFileName = m_strDeviceServerPath + _T("\\") + _T(DEVICE_INTEGRATED_FILE_NAME);

	CFile IntegratedFile;

	// INI 파일이 있는지 확인한다.
	// Integrated Data File Load
	if (!IntegratedFile.Open(strFileName, CFile::modeRead))
	{
		// Open Error
		return -1;
	}
	// 닫기
	IntegratedFile.Close();

	// INI 파일이 존재 하면 저장한다
	// 파일 오픈 : write mdoe
	if (!IntegratedFile.Open(strFileName, CFile::modeWrite))
	{
		return -1;
	}

	// 데이터 저장
	IntegratedFile.Write(pIntegrated, nDataSize);

	// 파일 닫기
	IntegratedFile.Close();

	// 버퍼 삭제
	delete pIntegrated;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Utility : Public Function & Parameters Initilize (공용함수 및 변수 초기화)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxInitilizePublicParameters(void)
{
	int n = 0;

	// 파라메터 인덱스 초기값
	m_nPublicToolsIndex = -1;

	// Public Tools Process 쓰레드 & 파라메터
	for (n = 0; n < MAX_PUBLIC_THREAD; n++)
	{
		m_pPublicToolsThread[n] = NULL; // 쓰레드
		m_pPublicToolsParams[n] = NULL; // 파라메터
	}

	// 쓰레드가 종료 될 때 까지 기다림
	// 아래의 함수는 예를 들어 Gun HV Up 기능을 쓰레드로 실행하고 
	// Gun HV Up 기능이 종료될 때 까지 기다릴수 있다(쓰레드 종료) <-방법1
	// WaitForSingleObject(m_pThread->m_hThread, INFINITE);
	// 방법2->파라메터에 쓰레드 실행상태 관련 변수를 이용하여 쓰레드가 자동삭제 되었는지 확인

	///////////////////////////////////////////////////////////////////////////////////////////
	m_pIntegrated->bSemConnectedFlag = m_bSemImageConnected;   // USB FT232 SE Image Scan Board Connected Flag
	m_pIntegrated->bBseConnectedFlag = m_bBseImageConnected;   // USB FT232 BSE Image Scan Board Connected Flag
	m_pIntegrated->bSbrConnectedFlag = m_bScanBridgeConnected; // USB FT232 Scan Bridge Board Connected Flag
	///////////////////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////////////////
	// 시스템 변수 초기화
	///////////////////////////////////////////////////////////////////////////////////////////
	// SEM Model 초기화 및 사용 변수 초기화
	AfxIntegratedInitializeParameters(m_pIntegrated->nSemModel);// SEM_SM_300B_CL_MODEL);
	// Integrated Control : WD에 따른 OL_Coarse, ScanRotation, Zooming, MinMag 보정값 설정
	AfxIntegratedSetWDCompensation();
	// Integrated Control : WD에 따른 OL_Coarse, ScanRotation, Zooming, MinMag 보정값 10등분 선형화 작업
	AfxIntegratedSetWDOLSrotZoomingLinearize();								
	///////////////////////////////////////////////////////////////////////////////////////////

	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated : SCAN ROTATION CALIBRATION DATA 파일 불러오기
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetScanRotationCalibrationDataFromFile(void)
{
	// SCAN ROTATION CALIBRATION DATA 삭제
	if (m_pScanRotCaliData != NULL)
	{
		delete m_pScanRotCaliData;
		m_pScanRotCaliData = NULL;
	}

	// SCAN ROTATION CALIBRATION DATA 생성
	m_pScanRotCaliData = new SEM_SCAN_ROTATION_CALIBRATION_DATA;

	// 초기화
	memset(m_pScanRotCaliData, 0x00, sizeof(SEM_SCAN_ROTATION_CALIBRATION_DATA));

	UINT nDataSize = sizeof(SEM_SCAN_ROTATION_CALIBRATION_DATA);
	CString strFileName = _T("");
	strFileName = m_strDeviceServerPath + _T("\\") + _T(SEM_SROT_CALIBRATION_FILE_NAME);

	CFile fileSRotCaliData;

	// SCAN ROTATION CALIBRATION DATA FILE LOAD
	if (!fileSRotCaliData.Open(strFileName, CFile::modeRead))
	{
		// Open or Read Error
		if (!fileSRotCaliData.Open(strFileName, CFile::modeCreate))
		{
			// File Create Error
			return -1;
		}
		fileSRotCaliData.Close();

		// Initilize Integrated Data To File
		if (!fileSRotCaliData.Open(strFileName, CFile::modeWrite))
		{
			return -1;
		}

		////////////////////////////////////////////////////////
		// DATA 초기화
		////////////////////////////////////////////////////////
		// 초기화
		AfxScanRotationCalibrationDataInitialize(m_pScanRotCaliData);
		////////////////////////////////////////////////////////

		// 데이터 저장
		fileSRotCaliData.Write(m_pScanRotCaliData, nDataSize);
		fileSRotCaliData.Close();

		// 파일 오픈 : read mode
		if (!fileSRotCaliData.Open(strFileName, CFile::modeRead))
		{
			return -1;
		}
	}

	// 데이터 크기
	UINT nFileSize = (UINT)fileSRotCaliData.GetLength();
	// 데이터 크기 비교
	if (nFileSize != sizeof(SEM_SCAN_ROTATION_CALIBRATION_DATA))
	{
		// 파일 닫기
		fileSRotCaliData.Close();
		return -1;
	}

	// 데이터 읽기
	fileSRotCaliData.Read(m_pScanRotCaliData, nFileSize);// nDataSize);

	// 파일 닫기
	fileSRotCaliData.Close();


	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated : SCAN ROTATION CALIBRATION DATA 파일 저장하기
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetScanRotationCalibrationDataToFile(void)
{
	// SCAN ROTATION CALIBRATION DATA 변수
	if (m_pScanRotCaliData == NULL) return -1;

	// SCAN ROTATION CALIBRATION DATA 생성
	SEM_SCAN_ROTATION_CALIBRATION_DATA *pSRotCaliData = new SEM_SCAN_ROTATION_CALIBRATION_DATA;

	// 초기화
	memset(pSRotCaliData, 0x00, sizeof(SEM_SCAN_ROTATION_CALIBRATION_DATA));
	// 초기화 데이터 복사
	memcpy(pSRotCaliData, m_pScanRotCaliData, sizeof(SEM_SCAN_ROTATION_CALIBRATION_DATA));

	int nDataSize = sizeof(SEM_SCAN_ROTATION_CALIBRATION_DATA);
	CString strFileName = _T("");
	strFileName = m_strDeviceServerPath + _T("\\") + _T(SEM_SROT_CALIBRATION_FILE_NAME);

	CFile fileSRotCaliData;

	// INI 파일이 있는지 확인한다.
	// fileSRotCaliData Data File Load
	if (!fileSRotCaliData.Open(strFileName, CFile::modeRead))
	{
		// Open Error
		return -1;
	}
	// 닫기
	fileSRotCaliData.Close();

	// INI 파일이 존재 하면 저장한다
	// 파일 오픈 : write mdoe
	if (!fileSRotCaliData.Open(strFileName, CFile::modeWrite))
	{
		return -1;
	}

	// 데이터 저장
	fileSRotCaliData.Write(pSRotCaliData, nDataSize);

	// 파일 닫기
	fileSRotCaliData.Close();

	// 버퍼 삭제
	delete pSRotCaliData;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated : SCAN ROTATION CALIBRATION DATA 초기화
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanRotationCalibrationDataInitialize(SEM_SCAN_ROTATION_CALIBRATION_DATA *pSRotCaliData)
{
	// Scan Rotation Calibration Data Initilize
	// Scan Rotation에 따른 Orthogonal, Zoom X-Y 보정값
	memset(pSRotCaliData, 0x00, sizeof(SEM_SCAN_ROTATION_CALIBRATION_DATA));

	////////////////////////////////////////////////////////////////////////
	// 초기값 설정
	////////////////////////////////////////////////////////////////////////
	// Flag
	for (int k = 0; k < MAX_SROT_CALIBRATION_ANGLE; k++)
	{
		pSRotCaliData->bSRotCaliFlag[k] = FALSE;
	}
	////////////////////////////////////////////////////////////////////////
	// Orthogonal 보정값
	pSRotCaliData->nSRotOrthogonalInput[0]  = m_pIntegrated->nARAngle[0]; // 입력값 (0도)
	pSRotCaliData->nSRotOrthogonalInput[15] = m_pIntegrated->nARAngle[0]; // 입력값 (15도)
	pSRotCaliData->nSRotOrthogonalInput[30] = m_pIntegrated->nARAngle[0]; // 입력값 (30도)
	pSRotCaliData->nSRotOrthogonalInput[45] = m_pIntegrated->nARAngle[0]; // 입력값 (45도)
	pSRotCaliData->nSRotOrthogonalInput[60] = m_pIntegrated->nARAngle[0]; // 입력값 (60도)
	pSRotCaliData->nSRotOrthogonalInput[75] = m_pIntegrated->nARAngle[0]; // 입력값 (75도)
	pSRotCaliData->nSRotOrthogonalInput[90] = m_pIntegrated->nARAngle[0]; // 입력값 (90도)
	////////////////////////////////////////////////////////////////////////

	// Orthogonal 보정값 : 계산값 (0.1도씩)
	int nDivRot = 0;
	for (int k = 0; k < MAX_SROT_CALIBRATION_ANGLE; k++)
	{
		for (int i = 0; i < 10; i++) // 10등분
		{
			nDivRot = k * 10;
			pSRotCaliData->nSRotOrthogonalData[nDivRot + i] = m_pIntegrated->nARAngle[0];
		}
	}

	////////////////////////////////////////////////////////////////////////
	// IniPar.ZoomXMaxValue[0]~[4] = 4095 값으로 설정 되어 있음
	// IniPar.ZoomYMaxValue[0]~[4] = 4095 값으로 설정 되어 있음
	// Magnification Relay는 4단계로 구성됨
	// Relay 0 : x20    ~ x250       --> ratio = 배율/30
	// Relay 1 : x300   ~ x2,500     --> ratio = 배율/300
	// Relay 2 : x3000  ~ x30,000    --> ratio = 배율/3000
	// Relay 3 : x30000 ~ x300,000   --> ratio = 배율/30000
	////////////////////////////////////////////////////////////////////////
	// Magnification Table
	// Relay 0     :     20,     30,     35,     40,     45,     50,     60,     70,     80,     90,    100,    110,    120,    130,    150,    180,    200,    220,    250,
	// Relay 1     :            300,    350,    400,    450,    500,    600,    700,    800,    900,   1000,   1100,   1200,   1300,   1500,   1800,   2000,   2200,   2500,
	// Relay 2     :           3000,   3500,   4000,   4500,   5000,   6000,   7000,   8000,   9000,  10000,  11000,  12000,  13000,  15000,  18000,  20000,  22000,  25000,
	// Relay 3     :          30000,  35000,  40000,  45000,  50000,  60000,  70000,  80000,  90000, 100000, 110000, 120000, 130000, 150000, 180000, 200000, 220000, 250000, 300000
	// ratio(20개) : 0.6667,    1.0, 1.1667, 1.3334,    1.5, 1.6667,    2.0, 2.3334, 2.6667,    3.0, 3.3334, 3.6667,    4.0, 4.3334,    5.0,    6.0, 6.6667, 7.3334, 8.3334,   10.0
	////////////////////////////////////////////////////////////////////////
	WORD wZoom = 0;
	double dZoomXYMax = m_nZoomXMaxValue[0];
	if (m_nZoomXMaxValue[0] < m_nZoomYMaxValue[0]) dZoomXYMax = m_nZoomYMaxValue[0];
	////////////////////////////////////////////////////////////////////////
	// Mag Relay Zoom X, Y 보정값 : Input 값
	for (int i = 0; i < MAX_SROT_CALIBRATION_ZOOM; i++)
	{
		switch (i)
		{
		case  0: { wZoom = (WORD)(dZoomXYMax / 1.0     ); break; } // x20
		case  1: { wZoom = (WORD)(dZoomXYMax / 1.0     ); break; } // x30,x300,x3000,x30000
		case  2: { wZoom = (WORD)(dZoomXYMax / 1.166667); break; } // x35,x350,x3500,x35000
		case  3: { wZoom = (WORD)(dZoomXYMax / 1.333334); break; } // x40,x400,x4000,x40000
		case  4: { wZoom = (WORD)(dZoomXYMax / 1.5     ); break; } // x45,x450,x4500,x45000
		case  5: { wZoom = (WORD)(dZoomXYMax / 1.666667); break; } // x50,x500,x5000,x50000
		case  6: { wZoom = (WORD)(dZoomXYMax / 2.0     ); break; } // x60,x600,x6000,x60000
		case  7: { wZoom = (WORD)(dZoomXYMax / 2.333334); break; } // x70,x700,x7000,x70000
		case  8: { wZoom = (WORD)(dZoomXYMax / 2.666667); break; } // x80,x800,x8000,x80000
		case  9: { wZoom = (WORD)(dZoomXYMax / 3.0     ); break; } // x90,x900,x9000,x90000
		case 10: { wZoom = (WORD)(dZoomXYMax / 3.333334); break; } // x100,x1000,x10000,x100000
		case 11: { wZoom = (WORD)(dZoomXYMax / 3.666667); break; } // x110,x1100,x11000,x110000
		case 12: { wZoom = (WORD)(dZoomXYMax / 4.0     ); break; } // x120,x1200,x12000,x120000
		case 13: { wZoom = (WORD)(dZoomXYMax / 4.333334); break; } // x130,x1300,x13000,x130000
		case 14: { wZoom = (WORD)(dZoomXYMax / 5.0     ); break; } // x150,x1500,x15000,x150000
		case 15: { wZoom = (WORD)(dZoomXYMax / 6.0     ); break; } // x180,x1800,x18000,x180000
		case 16: { wZoom = (WORD)(dZoomXYMax / 6.666667); break; } // x200,x2000,x20000,x200000
		case 17: { wZoom = (WORD)(dZoomXYMax / 7.333334); break; } // x220,x2200,x22000,x220000
		case 18: { wZoom = (WORD)(dZoomXYMax / 8.333334); break; } // x250,x2500,x25000,x250000
		case 19: { wZoom = (WORD)(dZoomXYMax / 10.0    ); break; } // x300000
		default: { wZoom = (WORD)(dZoomXYMax / 1.0     ); break; } //
		}

		pSRotCaliData->nSRotRelayZoomXInput[i][0]   = pSRotCaliData->nSRotRelayZoomYInput[i][0]   = wZoom; // 입력값 : 0도
		pSRotCaliData->nSRotRelayZoomXInput[i][15]  = pSRotCaliData->nSRotRelayZoomYInput[i][15]  = wZoom; // 입력값 : 15도
		pSRotCaliData->nSRotRelayZoomXInput[i][30]  = pSRotCaliData->nSRotRelayZoomYInput[i][30]  = wZoom; // 입력값 : 30도
		pSRotCaliData->nSRotRelayZoomXInput[i][45]  = pSRotCaliData->nSRotRelayZoomYInput[i][45]  = wZoom; // 입력값 : 45도
		pSRotCaliData->nSRotRelayZoomXInput[i][60]  = pSRotCaliData->nSRotRelayZoomYInput[i][60]  = wZoom; // 입력값 : 60도
		pSRotCaliData->nSRotRelayZoomXInput[i][75]  = pSRotCaliData->nSRotRelayZoomYInput[i][75]  = wZoom; // 입력값 : 75도
		pSRotCaliData->nSRotRelayZoomXInput[i][90]  = pSRotCaliData->nSRotRelayZoomYInput[i][90]  = wZoom; // 입력값 : 90도
		pSRotCaliData->nSRotRelayZoomXInput[i][105] = pSRotCaliData->nSRotRelayZoomYInput[i][105] = wZoom; // 입력값 : 105도
		pSRotCaliData->nSRotRelayZoomXInput[i][120] = pSRotCaliData->nSRotRelayZoomYInput[i][120] = wZoom; // 입력값 : 120도
		pSRotCaliData->nSRotRelayZoomXInput[i][135] = pSRotCaliData->nSRotRelayZoomYInput[i][135] = wZoom; // 입력값 : 135도
		pSRotCaliData->nSRotRelayZoomXInput[i][150] = pSRotCaliData->nSRotRelayZoomYInput[i][150] = wZoom; // 입력값 : 150도
		pSRotCaliData->nSRotRelayZoomXInput[i][165] = pSRotCaliData->nSRotRelayZoomYInput[i][165] = wZoom; // 입력값 : 165도
		pSRotCaliData->nSRotRelayZoomXInput[i][180] = pSRotCaliData->nSRotRelayZoomYInput[i][180] = wZoom; // 입력값 : 180도
		pSRotCaliData->nSRotRelayZoomXInput[i][195] = pSRotCaliData->nSRotRelayZoomYInput[i][195] = wZoom; // 입력값 : 195도
		pSRotCaliData->nSRotRelayZoomXInput[i][210] = pSRotCaliData->nSRotRelayZoomYInput[i][210] = wZoom; // 입력값 : 210도
		pSRotCaliData->nSRotRelayZoomXInput[i][225] = pSRotCaliData->nSRotRelayZoomYInput[i][225] = wZoom; // 입력값 : 225도
		pSRotCaliData->nSRotRelayZoomXInput[i][240] = pSRotCaliData->nSRotRelayZoomYInput[i][240] = wZoom; // 입력값 : 240도
		pSRotCaliData->nSRotRelayZoomXInput[i][255] = pSRotCaliData->nSRotRelayZoomYInput[i][255] = wZoom; // 입력값 : 255도
		pSRotCaliData->nSRotRelayZoomXInput[i][270] = pSRotCaliData->nSRotRelayZoomYInput[i][270] = wZoom; // 입력값 : 270도
		pSRotCaliData->nSRotRelayZoomXInput[i][285] = pSRotCaliData->nSRotRelayZoomYInput[i][285] = wZoom; // 입력값 : 285도
		pSRotCaliData->nSRotRelayZoomXInput[i][300] = pSRotCaliData->nSRotRelayZoomYInput[i][300] = wZoom; // 입력값 : 300도
		pSRotCaliData->nSRotRelayZoomXInput[i][315] = pSRotCaliData->nSRotRelayZoomYInput[i][315] = wZoom; // 입력값 : 315도
		pSRotCaliData->nSRotRelayZoomXInput[i][330] = pSRotCaliData->nSRotRelayZoomYInput[i][330] = wZoom; // 입력값 : 330도
		pSRotCaliData->nSRotRelayZoomXInput[i][345] = pSRotCaliData->nSRotRelayZoomYInput[i][345] = wZoom; // 입력값 : 345도

		// Mag Relay Zoom X, Y 보정값 : Calc 값
		for (int k = 0; k < MAX_SROT_CALIBRATION_ANGLE; k++)
		{
			pSRotCaliData->nSRotRelayZoomXData[i][k] = wZoom;
			pSRotCaliData->nSRotRelayZoomYData[i][k] = wZoom;
		}
	}
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	/*
	// S-ROT CALIBRATION DATA 복사
	for (int k = 0; k < MAX_SROT_CALIBRATION_ANGLE; k++)
	{
		// Flag
		m_SRotCal_Flag[k] = pSRotCaliData->bSRotCaliFlag[k];

		// Orthogonal 보정값 : 입력값 (1도씩)
		m_SRotCal_OrthogonalInput[k] = pSRotCaliData->nSRotOrthogonalInput[k];

		// Orthogonal 보정값
		for (int i = 0; i < 10; i++) // 10 등분
		{
			nDivRot = k * 10;
			// Orthogonal 보정값 : 계산값 (0.1도씩)
			m_SRotCal_OrthogonalData[nDivRot + i] = pSRotCaliData->nSRotOrthogonalData[nDivRot + i];
		}

		// Relay Zoom X-Y 보정값
		for (int i = 0; i < MAX_SROT_CALIBRATION_ZOOM; i++)
		{
			// Mag Relay Zoom X, Y 보정값 : Input 값
			m_SRotCal_InputZoomX[i][k] = pSRotCaliData->nSRotRelayZoomXInput[i][k];
			m_SRotCal_InputZoomY[i][k] = pSRotCaliData->nSRotRelayZoomYInput[i][k];

			// Mag Relay Zoom X, Y 보정값 : Calc 값
			m_SRotCal_CalcZoomX[i][k]  = pSRotCaliData->nSRotRelayZoomXData[i][k];
			m_SRotCal_CalcZoomY[i][k]  = pSRotCaliData->nSRotRelayZoomYData[i][k];
		}
	}
	*/
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////

	return 0;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Utility : SEM MODEL 선택
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSemModel(int nModel)
{
	// SEM Model 선택
	m_pIntegrated->nSemModel = nModel;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Utility : SEM MODEL 선택 및 AMP, REF 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSemModel(int nModel, double dAmp, double dRef)
{
	// SEM Model 선택
	m_pIntegrated->nSemModel = nModel;
	// SEM Model AMP
	m_pIntegrated->dSemModelAmp = dAmp;
	// SEM Model REF
	m_pIntegrated->dSemModelRef = dRef;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Utility : Public Function & Parameters Release (공용함수 및 변수 삭제)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxReleasePublicParameters(void)
{
	if (m_pPublicToolsParams != NULL)
	{
		int n = 0;
		// 파라메터 인덱스 초기값
		m_nPublicToolsIndex = -1;

		// Public Tools Process 쓰레드 & 파라메터
		for (n = 0; n < MAX_PUBLIC_THREAD; n++)
		{
			// Public Tools Process 쓰레드 파라메터 중복 확인
			if (m_pPublicToolsParams[n] != NULL)
			{
				// Public Tools Process 쓰레드에서 사용한 파라메터 삭제
				delete m_pPublicToolsParams[n];
				m_pPublicToolsParams[n] = NULL;
			}
		}
		// 파라메터 Array 삭제
		//delete[] & m_pPublicToolsParams;
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : SEM VACUUM STATE 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMVacuumState(int nState)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// SEM 상태 설정
	m_pIntegrated->nSemVacState = nState;

	return RET_SUCCESS_OK;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Scan Bridge Device Command Control...
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : 명령어 및 데이터 획득 쓰레드 생성
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxCreateScanBridgeThread(void)
{
	// Scan Bridge 가 사용 중이면...
	if (m_pScanBridgeThread != NULL) return RET_SUCCESS_OK;
	// Scan Bridge 쓰레드 파라메터 중복 확인
	if (m_pScanBridgeThreadParams != NULL)
	{
		// Scan Bridge 쓰레드에서 사용한 파라메터 삭제
		delete m_pScanBridgeThreadParams;
		m_pScanBridgeThreadParams = NULL;
	}

	// Scan Bridge 쓰레드에서 사용할 파라메터를 생성한다
	m_pScanBridgeThreadParams = new SCANBRIDGETHREADPARAMS;
	if (m_pScanBridgeThreadParams == NULL) return RET_ERROR_SBR_THREAD_PARAMS;
	memset(m_pScanBridgeThreadParams, 0x00, sizeof(SCANBRIDGETHREADPARAMS));
	// Scan Bridge 쓰레드에서 사용할 파라메터 기본값 설정
	m_pScanBridgeThreadParams->bThreadDone = FALSE;         // 쓰레드 종료 설정
	m_pScanBridgeThreadParams->bThreadStop = FALSE;         // 쓰레드 강제 종료 설정
	//m_pScanBridgeThreadParams->pSbrCommand = m_pSbrCommand; // Scan Bridge Command Data
	m_pScanBridgeThreadParams->nFT232HIndex = IDX_FT232H_SCAN_BRIDGE_DEVICE; // Scan Bridge 장치 인덱스
	m_pScanBridgeThreadParams->hFT232Handle = NULL;         // Scan Bridge 장치 핸들
	m_pScanBridgeThreadParams->hEventHandle = NULL;         // Scan Bridge 이벤트 핸들
	////////////////////////////////////////////////////////////////////////////////////////////////////
	// 202005.13
	memset(m_szFT232H_SbrRxBuffer, 0x00, MAX_FT232H_READ_BUFFER   ); // Scan Bridge Read Buffer
	memset(m_szFT232H_CmdBuffer  , 0x00, MAX_FT232H_COMMAND_BUFFER); // Scan Bridge Command Buffer
	memset(m_szFT232H_XStrBuffer , 0x00, MAX_FT232H_XYDSStr_BUFFER); // Scan Bridge XStr Buffer
	memset(m_szFT232H_YStrBuffer , 0x00, MAX_FT232H_XYDSStr_BUFFER); // Scan Bridge YStr Buffer
	memset(m_szFT232H_DStrBuffer , 0x00, MAX_FT232H_XYDSStr_BUFFER); // Scan Bridge DStr Buffer
	memset(m_szFT232H_SStrBuffer , 0x00, MAX_FT232H_XYDSStr_BUFFER); // Scan Bridge SStr Buffer
	memset(m_szFT232H_EchoCmdStr , 0x00, MAX_FT232H_COMMAND_BUFFER); // Scan Bridge Echo Command Str  
	m_nFT232H_CmdCount   = 0;                                        // Scan Bridge Command Count
	m_nFT232H_XStrCount  = 0;                                        // Scan Bridge XStr Count
	m_nFT232H_YStrCount  = 0;                                        // Scan Bridge YStr Count
	m_nFT232H_DStrCount  = 0;                                        // Scan Bridge DStr Count
	m_nFT232H_SStrCount  = 0;                                        // Scan Bridge SStr Count
	m_nFT232H_CommaCount = 0;                                        // Scan Bridge Comma Count
	m_nFT232H_XYDState   = 'x';                                      // Scan Bridge XYD State Flag
	m_nFT232H_CommandViewFlag   = 0;                                 // Scan Bridge Command View Falg
	m_nFT232H_EchoCommandEnable = 0;                                 // Scan Bridge Echo Command Enable
	m_nFT232H_EchoCommandFlag   = 0;                                 // Scan Bridge Echo Command Flag
	////////////////////////////////////////////////////////////////////////////////////////////////////

	// 핸들 설정
	FT_HANDLE ft232hHandle = AfxFT232HGetHandle(m_pScanBridgeThreadParams->nFT232HIndex);
	if (ft232hHandle == NULL) return RET_ERROR_FT232H_SBR_HANDLE;
	m_pScanBridgeThreadParams->hFT232Handle = ft232hHandle; // Scan Bridge 장치 핸들
	
	// Scan Bridge 이벤트 마스크
	FT_STATUS ftStatus = NULL;
	DWORD     dwEventMask = NULL;

	// CreateEvent
	// CreateEvent( SECURITY_ATTRIBUTES, (대부분 NULL로 사용)
	//	            bMaunalReset,        (TRUE이면 수동리셋, FALSE이면 자동리셋 이벤트 생성)
	//              bInitialState,       (TRUE이면 신호 상태, FALSE이면 비신호 상태로 시작)
	//              lpName               (이벤트를 서로 다른 프로세스에 속한 스레드가 사용할 수 있도록, 이름을 줄 수 있다.NULL을 사용하면 이름없는 이벤트 생성)
	// )

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Scan Bridge 쓰레드에서 사용할 이벤트 항목 : 읽기완료 이벤트로 설정
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	m_pScanBridgeThreadParams->hEventHandle = CreateEvent(NULL, FALSE, FALSE, _T(""));              // Scan Bridge 쓰레드에서 사용할 이벤트 생성
	if (m_pScanBridgeThreadParams->hEventHandle == NULL) return RET_ERROR_SBR_EVENT_HANDLE;         // 이벤트 생성 오류 확인
	dwEventMask = FT_EVENT_RXCHAR;                                                                  // Scan Bridge 장치에서 사용할 이벤트 항목 설정
	ftStatus = AfxFT232HSetEventNotification(m_pScanBridgeThreadParams->nFT232HIndex, dwEventMask, m_pScanBridgeThreadParams->hEventHandle); // Scan Bridge 쓰레드에서 사용할 이벤트 설정
	if (ftStatus != FT_OK) return RET_ERROR_SBR_EVENT_MASK;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Scan Bridge 쓰레드 생성 및 시작...
	m_pScanBridgeThread = AfxBeginThread(AfxThreadScanBridgeProcessing, m_pScanBridgeThreadParams); // , THREAD_PRIORITY_NORMAL);
	if (m_pScanBridgeThread == NULL) return RET_ERROR_SBR_THREAD_HANDLE;

	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : 명령어 및 데이터 획득 처리(작업) 쓰레드
/////////////////////////////////////////////////////////////////////////////////////////////////////
UINT AfxThreadScanBridgeProcessing(LPVOID pParams)
{
	LPSCANBRIDGETHREADPARAMS pThreadParams = (LPSCANBRIDGETHREADPARAMS)pParams;

	// 쓰레드 작업 상태 설정
	pThreadParams->bThreadDone = FALSE;

	BOOL  bLoop = TRUE;
	DWORD dwRet = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Scan Bridge 쓰레드 프로세싱
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while (bLoop == TRUE)
	{
		
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Scan Bridge 장치 이벤트 발생 확인...타임아웃 1000[ms]
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		dwRet = WaitForSingleObject(pThreadParams->hEventHandle, FT232H_EVENT_TIMEOUT);

		if (m_nFT232HDeviceUse < 1)
		{
			// 쓰레드 강제 종료
			pThreadParams->bThreadStop = TRUE;
		}
		else
		{
			switch (dwRet)
			{
			    case WAIT_OBJECT_0:  // 해당 이벤트 발생 : 처리작업 실행 
			    {
				    // Scan Bridge : 수신된 명령어 데이터 처리(실행) 하기
				    AfxScanBridgeDataRead();
				    break;
			    }
			    case WAIT_TIMEOUT:   // 이벤트 대기시간 경과 : Loop 순환
			    {
				    // 쓰레드 순환
				    pThreadParams->bThreadDone = FALSE;
				    break;
			    }
			    case WAIT_FAILED:    // 이벤트 함수 오류 : 쓰레드 종료
			    {
				    // 쓰레드 종료 확인 및 쓰레드 종료
				    bLoop = FALSE;
				    break;
			    }
			}
		}

		// Scan Bridge : 수신된 명령어 데이터 처리(실행) 하기
		//AfxScanBridgeDataRead();

		// 쓰레드 강제 종료 확인
		if (pThreadParams->bThreadStop == TRUE)
		{
			bLoop = FALSE;
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// 쓰레드 종료 확인
	pThreadParams->bThreadDone = TRUE;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : 수신된 명령어 데이터 처리(실행) 하기
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeDataRead(void)
{
	if (m_pScanBridgeThreadParams == NULL) return RET_ERROR_SBR_THREAD_PARAMS;               // Scan Bridge 쓰레드 파라메터
	if (m_pScanBridgeThreadParams->hFT232Handle == NULL) return RET_ERROR_FT232H_SBR_HANDLE; // Scan Bridge 장치 핸들

	int   n  = 0;
	BYTE  bt = 0;

	DWORD dwBytesRead = 0;
	DWORD dwRXBytes   = 0;
	DWORD dwTXBytes   = 0;
	DWORD dwEvent     = 0;

	FT_STATUS ftStatus = 0;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Scan Bridge USB Data Read and Command Execute...
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	AfxFT232HGetStatus(m_pScanBridgeThreadParams->nFT232HIndex, &dwRXBytes, &dwTXBytes, &dwEvent);

	// 받은 데이터 확인
	if (dwRXBytes > 0)
	{
		// 2020.05.13
		// RECEIVE BUFFER CLEAR
		memset(m_szFT232H_SbrRxBuffer, 0x00, MAX_FT232H_READ_BUFFER); // Scan Bridge Read Buffer

		// 2020.05.13
		// 자료갯수 확인
		if (dwRXBytes > MAX_FT232H_READ_BUFFER)
		{
			// 설정한 버퍼 크기 보다 큰 경우
			dwRXBytes = MAX_FT232H_READ_BUFFER;
		}

		// 2020.05.13
		// USB Data Read
		ftStatus = AfxFT232HRead(m_pScanBridgeThreadParams->nFT232HIndex, m_szFT232H_SbrRxBuffer, dwRXBytes, &dwBytesRead);
		if (ftStatus != FT_OK) return RET_ERROR_FT232H_SBR_READ;

		// 2020.05.13
		// 자료갯수 확인
		if (dwBytesRead > MAX_FT232H_READ_BUFFER)
		{
			// 설정한 버퍼 크기 보다 큰 경우
			dwBytesRead = MAX_FT232H_READ_BUFFER;
		}

		// USB 장치로 부터 읽은 자료 수 만큼 처리한다
		for (n = 0; n<(int)dwBytesRead; n++)
		{
			//---------------------------------------------------
			// TX, TY, TW, TS 다음에 오는 Data는 Ascii 가아니므로
			//( ComStr[0] == 'T' && CC == 2 && XC == 0 )
			//  XStr[0] = bt;
			//  XC = 1;
			//---------------------------------------------------
			// 2020.05.13
			//if (n > MAX_FT232H_READ_BUFFER - 1) break;

			// 2020.05.13
			bt = (BYTE)m_szFT232H_SbrRxBuffer[n];

			// 2020.05.13
			// 명령어 자료 : 'A' 부터 'Z' 문자를 조합하여 사용한다
			if ('A' <= bt && bt <= 'Z')
			{
				// Scan Bridge Command(명령어)는 2개의 문자로 구성 되어 있다
				if (m_nFT232H_CmdCount < MAX_SBR_COMMAND_LENGTH)
				{
					// 명령어를 보관한다
					m_szFT232H_CmdBuffer[m_nFT232H_CmdCount] = bt;
					m_nFT232H_CmdCount++;
				}
				else
				{
					// TS 명령어 확인
					if (!strcmp("TS", m_szFT232H_CmdBuffer) && m_szFT232H_XStrBuffer[0] == '0')
					{
						m_szFT232H_YStrBuffer[m_nFT232H_YStrCount] = bt;
						m_nFT232H_YStrCount++;
						if (m_nFT232H_YStrCount > MAX_FT232H_XYDSStr_BUFFER-1)
						{
							// Y Buffer 초과 : 데이터 오류
							m_nFT232H_YStrCount = 0;
							memset(m_szFT232H_YStrBuffer, 0x00, MAX_FT232H_XYDSStr_BUFFER);
						}
					}
				}
			}
			else
			// 명령어 다음 처리할 버퍼에 따라 자료를 보관한다(X, Y, D, S Str Buffer)
			if ('0' <= bt && bt <= '9' || bt == '.' || bt == '-')
			{
				switch (m_nFT232H_XYDState)
				{
				    case 'x':
					{
						m_szFT232H_XStrBuffer[m_nFT232H_XStrCount] = bt; // X Str 자료 보관
						m_nFT232H_XStrCount++;
						if (m_nFT232H_XStrCount > MAX_FT232H_XYDSStr_BUFFER-1)
						{
							// X Buffer 초과 : 데이터 오류
							m_nFT232H_XStrCount = 0;
							memset(m_szFT232H_XStrBuffer, 0x00, MAX_FT232H_XYDSStr_BUFFER);
						}
						break;
					}
				    case 'y':
					{
						m_szFT232H_YStrBuffer[m_nFT232H_YStrCount] = bt; // Y Str 자료 보관
						m_nFT232H_YStrCount++;
						if (m_nFT232H_YStrCount >= MAX_FT232H_XYDSStr_BUFFER-1)
						{
							// Y Buffer 초과 : 데이터 오류
							m_nFT232H_YStrCount = 0;
							memset(m_szFT232H_YStrBuffer, 0x00, MAX_FT232H_XYDSStr_BUFFER);
						}
						break;
					}
				    case 'd':
					{
						m_szFT232H_DStrBuffer[m_nFT232H_DStrCount] = bt; // D Str 자료 보관
						m_nFT232H_DStrCount++;
						if (m_nFT232H_DStrCount > MAX_FT232H_XYDSStr_BUFFER-1)
						{
							// D Buffer 초과 : 데이터 오류
							m_nFT232H_DStrCount = 0;
							memset(m_szFT232H_DStrBuffer, 0x00, MAX_FT232H_XYDSStr_BUFFER);
						}
						break;
					}
				    case 's':
					{
						m_szFT232H_SStrBuffer[m_nFT232H_SStrCount] = bt; // S Str 자료 보관
						m_nFT232H_SStrCount++;
						if (m_nFT232H_SStrCount >= MAX_FT232H_XYDSStr_BUFFER)
						{
							// S Buffer 초과 : 데이터 오류
							m_nFT232H_SStrCount = 0;
							memset(m_szFT232H_SStrBuffer, 0x00, MAX_FT232H_XYDSStr_BUFFER);
						}
						break;
					}
				}
			}
			else
			// 명령어와 X,Y,D,S Str 간의 ',' 데이터를 확인하여 카운트 한다
			if (bt == ',')
			{
				// 명령어및데이터 예: "AAxxxxx,yyyyy,dddddd;"
				// 명령어와 xxxx 데이터 사이에는 ',' 가 없다
				// 기본(처음)은 X Str Buffer 를 사용할 순서 설정
				m_nFT232H_CommaCount++;
				switch (m_nFT232H_CommaCount)
				{
				    case 1:
					{
						m_nFT232H_XYDState = 'y'; // Y Str Buffer 를 사용할 순서 설정
						break;
					}
				    case 2:
					{
						m_nFT232H_XYDState = 'd'; // D Str Buffer 를 사용할 순서 설정
						break;
					}
				}
			}
			else
			// 수신된 문자 중 '?' 확인하고 처리한다
			if (bt == '?')
			{
				m_nFT232H_XYDState = 's';
			}
			else
			// 수신된 문자 중 ';' 확인하고 처리한다
			// 수신된 명령어 및 데이터 조합이 완료 되었음
			if (bt == ';')
			{
				m_szFT232H_CmdBuffer[m_nFT232H_CmdCount]   = '\0'; // Command Buffer 완료
				m_szFT232H_XStrBuffer[m_nFT232H_XStrCount] = '\0'; // X Str   Buffer 완료
				m_szFT232H_YStrBuffer[m_nFT232H_YStrCount] = '\0'; // Y Str   Buffer 완료
				m_szFT232H_DStrBuffer[m_nFT232H_DStrCount] = '\0'; // D Str   Buffer 완료
				m_szFT232H_SStrBuffer[m_nFT232H_SStrCount] = '\0'; // S Str   Buffer 완료

				// 명령어를 표시할 것인지 확인한다...
				if (m_nFT232H_EchoCommandEnable > 0)
				{
					m_nFT232H_EchoCommandEnable = 0; // 한번만 사용하도록,
					m_nFT232H_EchoCommandFlag   = 1;
					// Echo Command Buffer 초기화 및 복사
					memset(m_szFT232H_EchoCmdStr, 0x00, MAX_FT232H_COMMAND_BUFFER);
					strcpy_s(m_szFT232H_EchoCmdStr, m_szFT232H_CmdBuffer);
				}
				else
				{
					// 수신된 Sbr 명령어 자료 이상 유무 확인(CheckSum)
					if (AfxSbrCheckSumCommand() > 0)
					{
						int nCmd  = -1;
						int nIdx  = 0;
						for (nIdx = 0; n < MAX_SBR_COMMAND_NUMBER; nIdx++)
						{
							// Sbr 명령어 문자 확인 및 명령어 인덱스 구하기
							if (strncmp(m_szSbrCommandList[nIdx], m_szFT232H_CmdBuffer, 2) == 0)
							{
								nCmd = nIdx;
								break;
							}
						}

						if (nCmd > -1)
						{
							// Data Buffer Clear
							memset(m_pIntegrated->szComStr, 0x00, sizeof(m_pIntegrated->szComStr));
							memset(m_pIntegrated->szXStr  , 0x00, sizeof(m_pIntegrated->szXStr));
							memset(m_pIntegrated->szYStr  , 0x00, sizeof(m_pIntegrated->szYStr));
							memset(m_pIntegrated->szDStr  , 0x00, sizeof(m_pIntegrated->szDStr));
							memset(m_pIntegrated->szSStr  , 0x00, sizeof(m_pIntegrated->szSStr));

							// Command
							strcpy_s(m_pIntegrated->szComStr, m_szFT232H_CmdBuffer);
							// X Str Data
							strcpy_s(m_pIntegrated->szXStr  , m_szFT232H_XStrBuffer);
							// Y Str Data
							strcpy_s(m_pIntegrated->szYStr  , m_szFT232H_YStrBuffer);
							// D Str Data
							strcpy_s(m_pIntegrated->szDStr  , m_szFT232H_DStrBuffer);
							// S Str Data
							strcpy_s(m_pIntegrated->szSStr  , m_szFT232H_SStrBuffer);
						}

						//------------------------------------------------
						// Scan Bridge (Sbr) 수신 명령어 실행
						//------------------------------------------------
						switch (nCmd)
						{
							//*
						    //--------------------------------------------
						    // All Control Board
						    //--------------------------------------------
						    case SBR_CMD_PD: // Power Down 상태정보 수신
						    {
							    AfxScanBridgePDCommand();
							    break;
						    }
							//--------------------------------------------
						    // Vac Control Board
						    //--------------------------------------------
						    case SBR_CMD_AR: // Air On/Off 상태정보 수신
							{
								AfxScanBridgeARCommand();
								break;
							}
							// 2020.01.17 오류가 확인되어 디버깅함
							case SBR_CMD_EV: // Evacation 상태정보 수신
							{
								AfxScanBridgeEVCommand();
								break;
							}
							case SBR_CMD_VS: // Vacuum State 상태정보 수신
							{
								AfxScanBridgeVSCommand();
								break;
							}
							case SBR_CMD_VL: // Valve On-Off 상태정보 수신
							{
								AfxScanBridgeVLCommand();
								break;
							}
							//--------------------------------------------
							// HV Control Board
							//--------------------------------------------
							case SBR_CMD_EM: // Emission Current
							{
								AfxScanBridgeEMCommand();
								break;
							}
							//--------------------------------------------
							// CNC Board
							//--------------------------------------------
							case SBR_CMD_RN: // Read  mm per step
							{
								AfxScanBridgeRNCommand();
								break;
							}
							case SBR_CMD_RA: // Read Accelation Table
							{
								AfxScanBridgeRACommand();
								break;
							}
							case SBR_CMD_RP: // Read Position
							{
								AfxScanBridgeRPCommand();
								break;
							}
							case SBR_CMD_RM: // Read Maximum Width
							{
								AfxScanBridgeRMCommand();
								break;
							}
							case SBR_CMD_MC: // Read BeamCenter
							{
								AfxScanBridgeMCCommand();
								break;
							}
							case SBR_CMD_TS: // TrackBall State
							{
								AfxScanBridgeTSCommand();
								break;
							}
							case SBR_CMD_LT: // Limit SW Test
							{
								AfxScanBridgeLTCommand();
								break;
							}
							case SBR_CMD_RB: // Read Backlash 값
							{
								AfxScanBridgeRBCommand();
								break;
							}
							case SBR_CMD_ZT: // Read ZTopLimitSwPulse 값
							{
								AfxScanBridgeZTCommand();
								break;
							}
							case SBR_CMD_SB: // Read BacklashMovingFlag 값
							{
								AfxScanBridgeSBCommand();
								break;
							}
							case SBR_CMD_TC: // Read TrackBall Count
							{
								AfxScanBridgeTCCommand();
								break;
							}
							case SBR_CMD_LS: //  Limit SW Test
							{
								AfxScanBridgeLSCommand();
								break;
							}
							//--------------------------------------------
							// TrackBall Board
							//--------------------------------------------
							case SBR_CMD_TB: //  TrackBall Command
							{
								AfxScanBridgeTBCommand();
								break;
							}
							//--------------------------------------------
							// BlueTooth Board
							//--------------------------------------------
							case SBR_CMD_BT: //  BlueTooth Command
							{
								AfxScanBridgeBTCommand();
								break;
							}
							//------------------------------------------------
							//------------------------------------------------
							//------------------------------------------------
							case SBR_CMD_EC: //  Echo Command : Stage Command Echo
							{
								AfxScanBridgeECCommand();
								break;
							}
							case SBR_CMD_VR: //  H/W Version String
							{
								AfxScanBridgeVRCommand();
								break;
							}
							case SBR_CMD_UL: //  Sample Load / Unload State
							{
								AfxScanBridgeULCommand();
								break;
							}
							case SBR_CMD_BF: //  Rotary Area Pulse
							{
								// 2021.03.31
								AfxScanBridgeBFCommand();
								break;
							}
							//------------------------------------------------
							//------------------------------------------------
							//------------------------------------------------
							//*/
						} // Sbr Command 처리(실행)
					}
				}

				//-----------------------------------
				//  다음 Command를 위한 변수 초기화
				//-----------------------------------
				m_nFT232H_CmdCount   = 0;            // Scan Bridge Command Count
				m_nFT232H_XStrCount  = 0;            // Scan Bridge XStr Count
				m_nFT232H_YStrCount  = 0;            // Scan Bridge YStr Count
				m_nFT232H_DStrCount  = 0;            // Scan Bridge DStr Count
				m_nFT232H_SStrCount  = 0;            // Scan Bridge SStr Count
				m_nFT232H_CommaCount = 0;            // Scan Bridge Comma Count
				m_nFT232H_XYDState   = 'x';          // Scan Bridge XYD State Flag
				memset(m_szFT232H_CmdBuffer , 0x00, MAX_FT232H_COMMAND_BUFFER); // X Str 자료 보관
				memset(m_szFT232H_XStrBuffer, 0x00, MAX_FT232H_XYDSStr_BUFFER); // X Str 자료 보관
				memset(m_szFT232H_YStrBuffer, 0x00, MAX_FT232H_XYDSStr_BUFFER); // Y Str 자료 보관
				memset(m_szFT232H_DStrBuffer, 0x00, MAX_FT232H_XYDSStr_BUFFER); // D Str 자료 보관
				memset(m_szFT232H_SStrBuffer, 0x00, MAX_FT232H_XYDSStr_BUFFER); // S Str 자료 보관
			}
		} // 받은자료 수 만큼 처리 for 문장
	} // 받은자료 상태확인 if 문장

	return RET_SUCCESS_OK;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : CNC 명령어 전송 처리 쓰레드 생성
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxCreateCNCSendThread(void)
{
	// CNC Send 쓰레드 사용 중이면...
	if (m_pCNCSendThread != NULL)
	{
		// CNC Send 쓰레드 파라메터 사용 중인지 확인
		if (m_pCNCSendThreadParams != NULL)
		{
			// CNC Send 쓰레드 종료 확인
			if (m_pCNCSendThreadParams->bThreadDone == TRUE)
			{
				// 2021.05.31
				// 쓰레드 종료 됨, 삭제
				// Scan Bridge 쓰레드에서 사용한 파라메터 삭제
				delete m_pCNCSendThreadParams;
				m_pCNCSendThreadParams = NULL;
			}
			else
			{
				// 쓰레드 동작 중, 리턴
				return RET_SUCCESS_OK;
			}
		}
		//return RET_SUCCESS_OK;
	}

	// CNC Send 쓰레드 파라메터 중복 확인
	if (m_pCNCSendThreadParams != NULL)
	{
		// Scan Bridge 쓰레드에서 사용한 파라메터 삭제
		delete m_pCNCSendThreadParams;
		m_pCNCSendThreadParams = NULL;
	}

	// Scan Bridge 쓰레드에서 사용할 파라메터를 생성한다
	m_pCNCSendThreadParams = new SCANBRIDGETHREADPARAMS;
	if (m_pCNCSendThreadParams == NULL) return RET_ERROR_SBR_THREAD_PARAMS;
	memset(m_pCNCSendThreadParams, 0x00, sizeof(SCANBRIDGETHREADPARAMS));
	// Scan Bridge 쓰레드에서 사용할 파라메터 기본값 설정
	m_pCNCSendThreadParams->bThreadDone  = FALSE;        // 쓰레드 종료 설정
	m_pCNCSendThreadParams->bThreadStop  = FALSE;        // 쓰레드 강제 종료
	m_pCNCSendThreadParams->nFT232HIndex = IDX_FT232H_SCAN_BRIDGE_DEVICE; // Scan Bridge 장치 인덱스
	m_pCNCSendThreadParams->hFT232Handle = NULL;         // Scan Bridge 장치 핸들
	m_pCNCSendThreadParams->hEventHandle = NULL;         // Scan Bridge 이벤트 핸들
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	memset(m_pCNCSendThreadParams->szSbrRxBuffer, 0x00, sizeof(m_pCNCSendThreadParams->szSbrRxBuffer)); // Scan Bridge Read Buffer
	memset(m_pCNCSendThreadParams->szCmdBuffer  , 0x00, sizeof(m_pCNCSendThreadParams->szCmdBuffer  )); // Scan Bridge Command Buffer
	memset(m_pCNCSendThreadParams->szXStrBuffer , 0x00, sizeof(m_pCNCSendThreadParams->szXStrBuffer )); // Scan Bridge XStr Buffer
	memset(m_pCNCSendThreadParams->szYStrBuffer , 0x00, sizeof(m_pCNCSendThreadParams->szYStrBuffer )); // Scan Bridge YStr Buffer
	memset(m_pCNCSendThreadParams->szDStrBuffer , 0x00, sizeof(m_pCNCSendThreadParams->szDStrBuffer )); // Scan Bridge DStr Buffer
	memset(m_pCNCSendThreadParams->szSStrBuffer , 0x00, sizeof(m_pCNCSendThreadParams->szSStrBuffer )); // Scan Bridge SStr Buffer
	m_pCNCSendThreadParams->nCmdCount   = 0;            // Scan Bridge Command Count
	m_pCNCSendThreadParams->nXStrCount  = 0;            // Scan Bridge XStr Count
	m_pCNCSendThreadParams->nYStrCount  = 0;            // Scan Bridge YStr Count
	m_pCNCSendThreadParams->nDStrCount  = 0;            // Scan Bridge DStr Count
	m_pCNCSendThreadParams->nSStrCount  = 0;            // Scan Bridge SStr Count
	m_pCNCSendThreadParams->nCommaCount = 0;            // Scan Bridge Comma Count
	m_pCNCSendThreadParams->nXYDState   = 'x';          // Scan Bridge XYD State Flag
	m_pCNCSendThreadParams->nCommandViewFlag = 0;       // Scan Bridge Command View Falg
	memset(m_pCNCSendThreadParams->szEchoCmdStr, 0x00, sizeof(m_pCNCSendThreadParams->szEchoCmdStr)); // Scan Bridge Echo Command Str
	m_pCNCSendThreadParams->nEchoCommandEnable = 0;     // Scan Bridge Echo Command Enable
	m_pCNCSendThreadParams->nEchoCommandFlag   = 0;     // Scan Bridge Echo Command Flag
	*/
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	// 2020.05.13
	memset(m_szFT232H_SbrRxBuffer, 0x00, MAX_FT232H_READ_BUFFER   ); // Scan Bridge Read Buffer
	memset(m_szFT232H_CmdBuffer  , 0x00, MAX_FT232H_COMMAND_BUFFER); // Scan Bridge Command Buffer
	memset(m_szFT232H_XStrBuffer , 0x00, MAX_FT232H_XYDSStr_BUFFER); // Scan Bridge XStr Buffer
	memset(m_szFT232H_YStrBuffer , 0x00, MAX_FT232H_XYDSStr_BUFFER); // Scan Bridge YStr Buffer
	memset(m_szFT232H_DStrBuffer , 0x00, MAX_FT232H_XYDSStr_BUFFER); // Scan Bridge DStr Buffer
	memset(m_szFT232H_SStrBuffer , 0x00, MAX_FT232H_XYDSStr_BUFFER); // Scan Bridge SStr Buffer
	memset(m_szFT232H_EchoCmdStr , 0x00, MAX_FT232H_COMMAND_BUFFER); // Scan Bridge Echo Command Str  
	////////////////////////////////////////////////////////////////////////////////////////////////////
	m_nFT232H_CmdCount   = 0;                                        // Scan Bridge Command Count
	m_nFT232H_XStrCount  = 0;                                        // Scan Bridge XStr Count
	m_nFT232H_YStrCount  = 0;                                        // Scan Bridge YStr Count
	m_nFT232H_DStrCount  = 0;                                        // Scan Bridge DStr Count
	m_nFT232H_SStrCount  = 0;                                        // Scan Bridge SStr Count
	m_nFT232H_CommaCount = 0;                                        // Scan Bridge Comma Count
	m_nFT232H_XYDState   = 'x';                                      // Scan Bridge XYD State Flag
	m_nFT232H_CommandViewFlag   = 0;                                 // Scan Bridge Command View Falg
	m_nFT232H_EchoCommandEnable = 0;                                 // Scan Bridge Echo Command Enable
	m_nFT232H_EchoCommandFlag   = 0;                                 // Scan Bridge Echo Command Flag
	*/
	////////////////////////////////////////////////////////////////////////////////////////////////////

	// 핸들 설정
	FT_HANDLE ft232hHandle = AfxFT232HGetHandle(m_pCNCSendThreadParams->nFT232HIndex);
	if (ft232hHandle == NULL) return RET_ERROR_FT232H_SBR_HANDLE;
	m_pCNCSendThreadParams->hFT232Handle = ft232hHandle; // CNC 장치 핸들

	// Scan Bridge 쓰레드 생성 및 시작...
	m_pCNCSendThread = AfxBeginThread(AfxThreadCNCSendProcessing, m_pCNCSendThreadParams); // , THREAD_PRIORITY_NORMAL);
	if (m_pCNCSendThread == NULL) return RET_ERROR_SBR_THREAD_HANDLE;

	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : CNC 명령어 처리(작업) 쓰레드
/////////////////////////////////////////////////////////////////////////////////////////////////////
UINT AfxThreadCNCSendProcessing(LPVOID pParams)
{
	LPSCANBRIDGETHREADPARAMS pThreadParams = (LPSCANBRIDGETHREADPARAMS)pParams;

	int  nCncCount    = 0;
	BOOL bbThreadDone = FALSE;
	if (pThreadParams != NULL)
	{
		nCncCount = m_nFT232H_CmdCount;
		// 쓰레드 작업 상태 설정
		pThreadParams->bThreadDone = FALSE;
		pThreadParams->bThreadStop = FALSE;
		bbThreadDone = pThreadParams->bThreadDone;
	}


	BOOL  bLoop  = TRUE;
	DWORD dwRet  = 0;
	int   nSeqNo = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Scan Bridge 쓰레드 프로세싱
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while (bLoop == TRUE)
	{
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// CNC 명령어 순차적 전송 처리
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		switch (nCncCount)// pThreadParams->nCmdCount)
		{
		    case 0:  // "LS1"
		    {
			    // LIMIT SW STATE 읽기
			    AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "LS1;");
			    break;
		    }
		    case 1:  // "RN0"
			{
				//Sbr_StrAvrSend("RN0;"); break;  // X축 1Step 당 ??mm 값 읽기(Read mm per step(mm/step))
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RN0;");
				break;
			}
			case 2:  // "RN1"
			{
				//Sbr_StrAvrSend("RN1;"); break;  // Y축 1Step 당 ??mm 값 읽기(Read mm per step(mm/step))
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RN1;");
				break;
			}
			case 3:  // "RN2"
			{
				//Sbr_StrAvrSend("RN2;"); break;  // Z축 1Step 당 ??mm 값 읽기(Read mm per step(mm/step))
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RN2;");
				break;
			}
			case 4:  // "RN3"
			{
				//Sbr_StrAvrSend("RN3;"); break;  // R축 1Step 당 ??mm 값 읽기(Read mm per step(mm/step))
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RN3;");
				break;
			}
			case 5:  // "RN4"
			{
				//Sbr_StrAvrSend("RN4;"); break;  // T축 1Step 당 ??mm 값 읽기(Read mm per step(mm/step))
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RN4;");
				break;
			}
			case 6:  // "RM0"
			{
				//Sbr_StrAvrSend("RM0;"); break;  // X축 이동가능거리 최대값 (Read Maximum Width)
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RM0;");
				break;
			}
			case 7:  // "RM1"
			{
				//Sbr_StrAvrSend("RM1;"); break;  // Y축 이동가능거리 최대값 (Read Maximum Width)
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RM1;");
				break;
			}
			case 8:  // "RM2"
			{
				//Sbr_StrAvrSend("RM2;"); break;  // Z축 이동가능거리 최대값 (Read Maximum Width)
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RM2;");
				break;
			}
			case 9:  // "RM3"
			{
				//Sbr_StrAvrSend("RM3;"); break;  // R축 이동가능거리 최대값 (Read Maximum Width) -> 실제 사용하지 않는 것으로 추정됨
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RM3;");
				break;
			}
			case 10:  // "RM4"
			{
				//Sbr_StrAvrSend("RM4;"); break;  // T축 최대값 읽기 (Read Tilt Max)
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RM4;");
				break;
			}
			case 11:  // "RM5"
			{
				//Sbr_StrAvrSend("RM5;"); break;  // T축 0각도의 위치값 읽기 (Read  TiltZeroAnglePulsePos)
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RM5;");
				break;
			}
			case 12:  // "RA0"
			{
				// X Axis Accelation 데이터 가져오기
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RA0;");
				break;
			}
			case 13:  // "RA1"
			{
				// Y Axis Accelation 데이터 가져오기
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RA1;");
				break;
			}
			case 14:  // "RA2"
			{
				// Z Axis Accelation 데이터 가져오기
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RA2;");
				break;
			}
			case 15:  // "RA3"
			{
				// R Axis Accelation 데이터 가져오기
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RA3;");
				break;
			}
			case 16:  // "RA4"
			{
				// T Axis Accelation 데이터 가져오기
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RA4;");
				break;
			}
			case 17:  // "ZT1"
			{
				//Sbr_StrAvrSend("ZT1;"); break;  // Z축 TOP Limit 값 읽기
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "ZT1;");
				break;
			}
			case 18:  // "MC2"
			{
				//Sbr_StrAvrSend("MC2;"); break;  // 빔 센터를 위한 X,Y축 위치값 읽기 (Read BeamCenter)
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "MC2;");
				break;
			}
			case 19:  // "RP0"
			{
				//Sbr_StrAvrSend("RP0;"); break;  // X축 위치값 읽기 (Read Position)
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RP0;");
				break;
			}
			case 20:  // "RP1"
			{
				//Sbr_StrAvrSend("RP1;"); break;  // Y축 위치값 읽기 (Read Position)
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RP1;");
				break;
			}
			case 21:  // "RP2"
			{
				//Sbr_StrAvrSend("RP2;"); break;  // Z축 위치값 읽기 (Read Position)
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RP2;");
				break;
			}
			case 22:  // "RP3"
			{
				//Sbr_StrAvrSend("RP3;"); break;  // R축 위치값 읽기 (Read Position)
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RP3;");
				break;
			}
			case 23:  // "RP4"
			{
				//Sbr_StrAvrSend("RP4;"); break;  // T축 위치값 읽기 (Read Position)
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RP4;");
				break;
			}
			case 24:  // "VL8"
			{
				//Sbr_StrAvrSend("TS0;");         // TrackBall Moving State
				//Sbr_StrAvrSend("VL8;");         // Read 현재상태 ( Home or Fixed Position )
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "TS0;");
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "VL8;");
				break;
			}
			case 25:  // Eg : Extra Gate
			{
				//Sbr_StrAvrSend("VL1,0;"); break;  // Extra gate valve 모터의 1Step 당 이동거리[mm] (Read mm per step(mm/step)) 데이터 가져오기
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "VL1,0;");
				break;
			}
			case 26:  // St
			{
				//Sbr_StrAvrSend("VL1,1;"); break;  // Steel tape 모터의 1Step 당 이동거리[mm] (Read mm per step(mm/step)) 데이터 가져오기
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "VL1,1;");
				break;
			}
			case 27:  // Dm
			{
				//Sbr_StrAvrSend("VL1,2;"); break;  // Damper 모터의 1Step 당 이동거리[mm] (Read mm per step(mm/step)) 데이터 가져오기
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "VL1,2;");
				break;
			}
			case 28:  // Mg
			{
				//Sbr_StrAvrSend("VL1,3;"); break;  // Main gate value 모터의 1Step 당 이동거리[mm] (Read mm per step(mm/step)) 데이터 가져오기
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "VL1,3;");
				break;
			}
			case 29:  // Mg
			{
				//Sbr_StrAvrSend("VL1,4;"); break;  // AVR 에서는 사용하지 않는 것으로 판단됨. (Read mm per step(mm/step))
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "VL1,4;");
				break;
			}
			case 30:  // Eg
			{
				//Sbr_StrAvrSend("VL5,0;"); break;  // Eatra gate 모터의 지정된 위치 이동을 위한 Pulse 갯수 (Read FixedPosition) 데이터 가져오기
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "VL5,0;");
				break;
			}
			case 31:  // St
			{
				//Sbr_StrAvrSend("VL5,1;"); break;  // Steel tape 모터의 지정된 위치 이동을 위한 Pulse 갯수 (Read FixedPosition) 데이터 가져오기
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "VL5,1;");
				break;
			}
			case 32:  // Dm
			{
				//Sbr_StrAvrSend("VL5,2;"); break;  // Damper 모터의 지정된 위치 이동을 위한 Pulse 갯수 (Read FixedPosition) 데이터 가져오기
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "VL5,2;");
				break;
			}
			case 33:  // Mg
			{
				//Sbr_StrAvrSend("VL5,3;"); break;  // Main gate 모터의 지정된 위치 이동을 위한 Pulse 갯수 (Read FixedPosition) 데이터 가져오기
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "VL5,3;");
				break;
			}
			case 34:  // Mg
			{
				//Sbr_StrAvrSend("VL5,4;");         // Extra gate valve 모터의 이동을 위한 Pulse 값 설정, Pulse 값을 설정하지 않으면 현재위치값 가져오기 (Send MovingPulse ( Current Motor Position ))
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "VL5,4;");
				break;
			}
			case 35:  // "BF1"
			{
				// 2021.03.31
				//Sbr_StrAvrSend("BF1;");           // Rotary Area Pulse 값 가져오기
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "BF1;");
				// CNC COMMAND SEND 종료
				bLoop = FALSE;
				break;
			}
			case 36:  // "VR0"
			{
				// H/W #0 Version
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "VR0;");
				break;
			}
			case 37:  // "VR1"
			{
				// H/W #1 Version
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "VR1;");
				break;
			}
			case 38:  // "VR2"
			{
				// H/W #2 Version
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "VR2;");
				break;
			}
			case 39:  // "VR3"
			{
				// H/W #3 Version
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "VR3;");
				break;
			}
			case 40:  // "VR4"
			{
				// H/W #4 Version
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "VR4;");
				break;
			}
			case 41:  // CNC COMMAND SEND 종료
			{
				bLoop = FALSE;
				break;
			}
		}

		if (bLoop == TRUE)
		{
			nCncCount++;
			if (pThreadParams != NULL)
			{
				// 강제종료 CHECK?
				if (pThreadParams->bThreadStop == TRUE)
				{
					// 쓰레드 종료
					bLoop = FALSE;
				}
				else
				{
					// 100[ms] 대기
					Sleep(PUB_CNC_SEND_MIN_INTERVAL);
				}
			}
			else
			{
				// 200[ms] 대기
				Sleep(200);
			}
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// 쓰레드 종료 확인
	if (pThreadParams != NULL)
	{
		pThreadParams->bThreadDone = TRUE;
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : 수신된 명령어 이상 유무 확인 (Check Sum)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSbrCheckSumCommand(void)
{
	if (m_pScanBridgeThreadParams == NULL) return RET_ERROR_SBR_THREAD_PARAMS;               // Scan Bridge 쓰레드 파라메터

	int nRet = 0;
	int nSum = 0;
	int nCheckSum = 0;
	char szStrBuf[MAX_FT232H_ASSEMBLE_BUFFER  + 1];
	char *pBuf;

	memset(szStrBuf, 0x00, MAX_FT232H_ASSEMBLE_BUFFER);

	if (m_nFT232H_SStrCount > 0)
	{
		nRet = 0;
		nSum = 0;
		nCheckSum = 0;

		//------------------------------------------------------------
		// Assemble Command
		//------------------------------------------------------------
		nCheckSum = atoi(m_szFT232H_SStrBuffer);

		// Command
		strcpy_s(szStrBuf, m_szFT232H_CmdBuffer);
		if (m_nFT232H_XStrCount)
		{
			// X Str Buffer
			strcat(szStrBuf, m_szFT232H_XStrBuffer);
		}
		if (m_nFT232H_YStrCount)
		{
			// Y Str Buffer
			strcat(szStrBuf, ",");
			strcat(szStrBuf, m_szFT232H_YStrBuffer);
		}
		if (m_nFT232H_DStrCount)
		{
			// D Str Buffer
			strcat(szStrBuf, ",");
			strcat(szStrBuf, m_szFT232H_DStrBuffer);
		}
		// Sbr 데이터 조합 완성
		strcat(szStrBuf, ";");
		//------------------------------------------------------------
		// Check Sum
		//------------------------------------------------------------
		pBuf = szStrBuf;
		while (*pBuf != ';')
		{
			nSum += *pBuf++;
		}
		nSum = nSum % 100;
		if (nCheckSum == nSum) nRet = 1;
		//------------------------------------------------------------
	}
	else
	{
		// S Str Buffer 자료가 없다면...
		nRet = 1;
	}

	return nRet;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : 수신된 명령어 조합하기
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSbrAssembleCommand(char *pStrBuf)
{
	if (m_pScanBridgeThreadParams == NULL) return RET_ERROR_SBR_THREAD_PARAMS;               // Scan Bridge 쓰레드 파라메터
	if (pStrBuf == NULL) return 0;

	//---------------------------------------------------------------
	// Assemble Command
	//---------------------------------------------------------------
	// Command
	strcpy(pStrBuf, m_szFT232H_CmdBuffer);
	if (m_nFT232H_XStrCount)
	{
		// X Str Buffer
		strcat(pStrBuf, m_szFT232H_XStrBuffer);
	}
	if (m_nFT232H_YStrCount)
	{
		// Y Str Buffer
		strcat(pStrBuf, ",");
		strcat(pStrBuf, m_szFT232H_YStrBuffer);
	}
	if (m_nFT232H_DStrCount)
	{
		// D Str Buffer
		strcat(pStrBuf, ",");
		strcat(pStrBuf, m_szFT232H_DStrBuffer);
	}
	if (m_nFT232H_SStrCount)
	{
		// S Str Buffer
		strcat(pStrBuf, "?");
		strcat(pStrBuf, m_szFT232H_SStrBuffer);
	}
	// Sbr 데이터 조합 완성
	strcat(pStrBuf, ";");
	//---------------------------------------------------------------

	return RET_SUCCESS_OK;
}

//---------------------------------------------------------------------------
// m_SemVacState
//---------------------------------------------------------------------------
/*
#define  POWER_OFF_STATE     0   // SEM Power Off 상태
#define  AIR_ON_STATE        1   // Air On  상태
#define  VAC_EVAC_STATE      2   // Evacuation Working 상태
#define  VAC_OK_STATE        3   // 진공 OK 상태
#define  HV_ON_STATE         4   // 진공 상태가 HV 사용 가능 상태에 도달함

#define  CNC5_GO_SAM_LOAD    5   // Go to Sample Load Position
#define  CNC5_GO_SAM_UNLOAD  6   // Go to Sample Unload Position

#define  HV_VAC_OK_STATE     7   // GUN 진공OK 및 챔버 진공OK 상태
#define  HV_AIR_ON_STATE     8   // GUN 진공OK 및 챔버 AIR ON 상태
#define  HV_EVAC_STATE       9   // GUN 진공OK 및 챔버 진공진행 상태
*/
//---------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : SEM Power Down 상태정보 수신
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgePDCommand(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));

	// 전송자료
	UsbDeviceDataInfo.nState   = 1; // VACUUM 상태값
	UsbDeviceDataInfo.nData[0] = m_pIntegrated->nSemVacState;

	if (m_hOwnerWnd != NULL)
	{
		// DEVICE MAIN SERVER
		// 현재 SEM상태(진공,POWER) 정보 메시지 보내기
		// 2020.05.04
		SendMessage(m_hOwnerWnd, UM_USB_SBR_VACUUM_DATA, NULL, (LPARAM)&UsbDeviceDataInfo);
	}

	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : SEM 챔버 Air On/Off 상태정보 수신
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeARCommand(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));

	m_pIntegrated->nSemAirState = (int)(m_pIntegrated->szXStr[0] - '0');

	if (m_pIntegrated->nSemAirState > 0)  // Air On Mode 설정
	{
		// SEM 상태 값이 HV(고압) 사용중인 상태이면 -> SEM 대기 상태로 전환한다
		if (m_pIntegrated->nSemVacState == HV_ON_STATE)
		{
			// 2018.09.28
			// HV On 상태이면, 대기상태로 전환한다...
			//AfxScanBridgeSemStandBy(); // 2020.05.11

			// SEM 상태값을 -> Air On 상태로 설정한다
			m_pIntegrated->nSemVacState = AIR_ON_STATE;
		}
	}
	else // Air Off Mode 설정
	{
		// SEM 상태값을 -> 진공 진행중 상태로 설정한다
		m_pIntegrated->nSemVacState = VAC_EVAC_STATE;
	}

	// 전송자료
	UsbDeviceDataInfo.nState   = 1; // VACUUM 상태값
	UsbDeviceDataInfo.nData[0] = m_pIntegrated->nSemVacState;

	if (m_hOwnerWnd != NULL)
	{
		// DEVICE MAIN SERVER
		// 현재 SEM상태(진공,POWER) 정보 메시지 보내기
		// 2020.05.04
		SendMessage(m_hOwnerWnd, UM_USB_SBR_VACUUM_DATA, NULL, (LPARAM)&UsbDeviceDataInfo);
	}

	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : SEM Evaccum(진공율) 상태정보 수신 -> 진공센서 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeEVCommand(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// VACUUM GAUGE 값은 클라이언트 연결 후 받을 준비가 되었다는 설정값이 있을때까지 보내지 않는다
	BOOL bSendFlag = FALSE;
	BOOL bMessage  = FALSE;

	// 진공상태정보
	int nXStr = m_pIntegrated->szXStr[0] - '0';

	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));

	char   szCalc[MAX_FT232H_XYDSStr_BUFFER + 1];
	int    nEvacValue = 0;
	double dEvacValue = 0.0;
	double dCalcValue = 0.0;

	memset(szCalc, 0x00, MAX_FT232H_XYDSStr_BUFFER);

	// 전송자료
	UsbDeviceDataInfo.nState = 2; // VACUUM GAUGE 값

	if (nXStr == 0)
	{
		szCalc[0] = m_pIntegrated->szYStr[0];
		szCalc[1] = m_pIntegrated->szYStr[1];
		szCalc[2] = m_pIntegrated->szYStr[2];
		szCalc[3] = m_pIntegrated->szYStr[3];
		szCalc[4] = NULL;

		// Evac 계산 (현재 진공값 계산)
		nEvacValue = atoi(szCalc);
		dEvacValue = (double)nEvacValue;// atof(szCalc);
		dCalcValue = ((dEvacValue / 102.3) - 6.143) / 1.286;
		dEvacValue = pow(10.0, dCalcValue);

		// 진공상태 데이터 MESSAGE 보내기
		bSendFlag = TRUE;
		bMessage  = TRUE;
		UsbDeviceDataInfo.nState   = 2; // (1:Vacuum State, 2 : 진공게이지값, 3 : Emission값)
		UsbDeviceDataInfo.nData[1] = nEvacValue;
		UsbDeviceDataInfo.dData[1] = dEvacValue;
		// 챔버 진공값
		m_pIntegrated->nSemVacValue  = nEvacValue; // 0~1023
		m_pIntegrated->dSemVacValue1 = dEvacValue; // 계산값
	}
	else
	{
        //
	}


	// 진공상태 데이터 MESSAGE 보내기
	if (bSendFlag == TRUE)
	{
		if (bMessage == TRUE)
		{
			if (m_hOwnerWnd != NULL)
			{
				// DEVICE MAIN SERVER
				// 진공상태 정보 메시지 보내기 (진공값 포함)
				if (m_dwVaccumInfoSendCount > 0)
				{
					m_dwVaccumInfoSecondTime = GetTickCount();
					// VACUUM 값 전송을 1초당 2번 이하로 전송한다
					if (abs((int)(m_dwVaccumInfoSecondTime - m_dwVaccumInfoFirstTime)) > 500) // 시간차 500[ms]
					{
						// 2020.05.04
						SendMessage(m_hOwnerWnd, UM_USB_SBR_VACUUM_DATA, NULL, (LPARAM)&UsbDeviceDataInfo);
						// VACUUM 값 전송을 1초당 5번 이하로 전송한다
						m_dwVaccumInfoFirstTime = m_dwVaccumInfoSecondTime;
					}
				}
				else
				{
					// 2020.05.04
					SendMessage(m_hOwnerWnd, UM_USB_SBR_VACUUM_DATA, NULL, (LPARAM)&UsbDeviceDataInfo);
					// VACUUM 값 전송을 1초당 5번 이하로 전송한다
					m_dwVaccumInfoFirstTime  = GetTickCount();
					m_dwVaccumInfoSecondTime = m_dwVaccumInfoFirstTime;
					m_dwVaccumInfoSendCount++;
				}
			}
		}
	}

	return RET_SUCCESS_OK;
}


//---------------------------------------------------------------------------
//#define  POWER_OFF_STATE    0   // SEM Power Off 상태
//#define  AIR_ON_STATE       1   // Air On  상태
//#define  VAC_EVAC_STATE     2   // Evacuation Working 상태
//#define  VAC_OK_STATE       3   // 진공 OK 상태
//#define  HV_ON_STATE        4   // 진공 상태가 HV 사용 가능 상태에 도달함
//#define  HV_VAC_OK_STATE    7   // GUN 진공OK 및 챔버 진공OK 상태
//#define  HV_AIR_ON_STATE    8   // GUN 진공OK 및 챔버 AIR ON 상태
//#define  HV_EVAC_STATE      9   // GUN 진공OK 및 챔버 진공진행 상태
//---------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : SEM Vaccum(진공) 상태정보 수신 (위의 상태정보 설명 참조)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeVSCommand(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// 진공상태정보
	int nXStr = m_pIntegrated->szXStr[0] - '0';

	BOOL bMessage = FALSE;
	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));

	switch (nXStr)
	{
		case POWER_OFF_STATE:  // 0 : SEM Power Off 상태
		{
			// SEM 상태를 Power Off 상태로 설정
			m_pIntegrated->nSemVacState = POWER_OFF_STATE;
				
			// 진공상태 데이터 MESSAGE 보내기
			bMessage = TRUE;
			UsbDeviceDataInfo.nState   = 1; // (1:Vacuum State, 2 : 진공게이지값, 3 : Emission값)
			UsbDeviceDataInfo.nData[0] = m_pIntegrated->nSemVacState;

			break;
		}
		case AIR_ON_STATE:     // 1 : Air On  상태
		{
			// SEM 상태를 Air On 상태로 설정
			m_pIntegrated->nSemVacState = AIR_ON_STATE;

			// 진공상태 데이터 MESSAGE 보내기
			bMessage = TRUE;
			UsbDeviceDataInfo.nState   = 1; // (1:Vacuum State, 2 : 진공게이지값, 3 : Emission값)
			UsbDeviceDataInfo.nData[0] = m_pIntegrated->nSemVacState;

			break;
		}
		case VAC_EVAC_STATE: // 2 : Evacuation Working 상태
		{
			// SEM 상태를 Evacuation Working(진공진행중) 상태로 설정
			m_pIntegrated->nSemVacState = VAC_EVAC_STATE;

			// 진공상태 데이터 MESSAGE 보내기
			bMessage = TRUE;
			UsbDeviceDataInfo.nState   = 1; // (1:Vacuum State, 2 : 진공게이지값, 3 : Emission값)
			UsbDeviceDataInfo.nData[0] = m_pIntegrated->nSemVacState;

			break;
		}
		case VAC_OK_STATE:     // 3 : 진공 OK(완료) 상태
		{
			// SEM 상태를 진공 OK(완료) 상태로 설정
			m_pIntegrated->nSemVacState = VAC_OK_STATE;

			// 진공상태 데이터 MESSAGE 보내기
			bMessage = TRUE;
			UsbDeviceDataInfo.nState   = 1; // (1:Vacuum State, 2 : 진공게이지값, 3 : Emission값)
			UsbDeviceDataInfo.nData[0] = m_pIntegrated->nSemVacState;

			break;
		}
		// 프로그램 버그로 인하여 Power Off Sequence가 진행되지 않고, 갑자기 중단된 경우는 HV ON 상태에 있다.
		// 이런 경우 진공OK(완료)상태로(VAC_OK_STATE) 전환한다. -->> 기존 프로그램에서 "VS" 상태정보 요청은
		// 프로그램 시작시 한번 요청하였다. SEM 상태가 HV_ON_STATE 상태가 되려면, SemStart 버튼을 눌러 스캔작업을 실행해야한다.
		case HV_ON_STATE:     // 4 : 진공 상태가 HV 사용 가능 상태에 도달함
		{
			//----------------------------------------------------------
			// 2018.10.01
			// 아래의 작업은 기존 프로그램에서 프로그램 시작시
			// VS명령을 1번 요청하는 방식이므로 해당되는 내용이다
			//----------------------------------------------------------
			// SEM 상태를 진공 OK(완료) 상태로 설정
			m_pIntegrated->nSemVacState = VAC_OK_STATE;
			//----------------------------------------------------------

			// 진공상태 데이터 MESSAGE 보내기
			bMessage = TRUE;
			UsbDeviceDataInfo.nState   = 1; // (1:Vacuum State, 2 : 진공게이지값, 3 : Emission값)
			UsbDeviceDataInfo.nData[0] = m_pIntegrated->nSemVacState;

			break;
		}
		case HV_VAC_OK_STATE:     // 7 : GUN진공OK 및 챔버진공OK
		{
			// SEM 상태를 GUN진공OK 및 챔버진공OK 상태로 설정
			m_pIntegrated->nSemVacState = VAC_OK_STATE;// HV_VAC_OK_STATE;

			// 진공상태 데이터 MESSAGE 보내기
			bMessage = TRUE;
			UsbDeviceDataInfo.nState   = 1; // (1:Vacuum State, 2 : 진공게이지값, 3 : Emission값)
			UsbDeviceDataInfo.nData[0] = m_pIntegrated->nSemVacState;

			break;
		}
		case HV_AIR_ON_STATE:     // 8 : GUN진공OK 및 챔버AIR-ON 상태
		{
			// SEM 상태를 GUN진공OK 및 챔버AIR-ON 상태 상태로 설정
			m_pIntegrated->nSemVacState = AIR_ON_STATE;// HV_AIR_ON_STATE;

			// 진공상태 데이터 MESSAGE 보내기
			bMessage = TRUE;
			UsbDeviceDataInfo.nState   = 1; // (1:Vacuum State, 2 : 진공게이지값, 3 : Emission값)
			UsbDeviceDataInfo.nData[0] = m_pIntegrated->nSemVacState;

			break;
		}
		case HV_EVAC_STATE: // 9 : GUN 진공OK 및 챔버 진공진행 상태
		{
			// SEM 상태를 GUN진공OK 및 챔버 진공진행 상태 상태로 설정
			m_pIntegrated->nSemVacState = VAC_EVAC_STATE;// HV_EVAC_STATE;

			// 진공상태 데이터 MESSAGE 보내기
			bMessage = TRUE;
			UsbDeviceDataInfo.nState   = 1; // (1:Vacuum State, 2 : 진공게이지값, 3 : Emission값)
			UsbDeviceDataInfo.nData[0] = m_pIntegrated->nSemVacState;

			break;
		}
		case CNC5_GO_SAM_LOAD:    // 5 : X,Y,Z,T축 샘플로드(샘플장착됨) 위치로 이동하기
		{
			// 아래 변수의 시작값이다
			//int SampleLoadState = 2;   // 0:Unload,  1:Loaded,      2:No response
			//int LodMovingState = 0;

			// Go to XTZRT-Sample Loading Position
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SB20;"); // VacBoard -> PC -> To CncBoard

			// 이동 위치값 Clear
			m_pIntegrated->nLodCount = 0;
			m_pIntegrated->nLodPixHistory[m_pIntegrated->nLodCount++] = 0;
			// 이동상태 설정
			m_pIntegrated->nLodDirChangedFlag  = 0;
			m_pIntegrated->nLodMovingState     = 1;
			m_pIntegrated->nSampleLoadStateOld = m_pIntegrated->nSampleLoadState;

			// 진공상태 데이터 MESSAGE 보내기
			//bMessage = TRUE;
			UsbDeviceDataInfo.nState   = 1; // (1:Vacuum State, 2 : 진공게이지값, 3 : Emission값)
			UsbDeviceDataInfo.nData[0] = m_pIntegrated->nSemVacState;

			break;
		}
		case CNC5_GO_SAM_UNLOAD:  // 6 : X,Y,Z,T축 샘플로드 위치에서 -> 샘플제거위치로 이동하기
		{
			// Go to XTZRT-Sample UnLoading Position
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SB21;"); // VacBoard -> PC -> To CncBoard

		    // 이동 위치값 Clear
			m_pIntegrated->nLodCount = 0;
			m_pIntegrated->nLodPixHistory[m_pIntegrated->nLodCount++] = 0;
			// 이동상태 설정
			m_pIntegrated->nLodDirChangedFlag  = 0;
			m_pIntegrated->nLodMovingState     = 1;
			m_pIntegrated->nSampleLoadStateOld = m_pIntegrated->nSampleLoadState;

			// 진공상태 데이터 MESSAGE 보내기
			//bMessage = TRUE;
			UsbDeviceDataInfo.nState   = 1; // (1:Vacuum State, 2 : 진공게이지값, 3 : Emission값)
			UsbDeviceDataInfo.nData[0] = m_pIntegrated->nSemVacState;

			break;
		}
	}

	// 진공상태 데이터 MESSAGE 보내기
	if (bMessage == TRUE)
	{
		if (m_hOwnerWnd != NULL)
		{
			// DEVICE MAIN SERVER
			// 진공상태 정보 메시지 보내기
			// 2020.05.04
			SendMessage(m_hOwnerWnd, UM_USB_SBR_VACUUM_DATA, NULL, (LPARAM)&UsbDeviceDataInfo);
		}
	}

	return RET_SUCCESS_OK;
}


//----------------------------------------------------------------------------------------------------------
//  0) SN : Set mm per pulse (mm/step)   <- PC  ==>  VALVE MOTOR mm/step 설정
//----------------------------------------------------------------------------------------------------------
// VL0,0,3200;  // Extra Gate Valve Motor
// VL0,1,3200;  // Steel Tape Motor
// VL0,2,3200;  // Damper Motor
// VL0,3,3200;  // Main Gate Valve Motor
//----------------------------------------------------------------------------------------------------------
//  1) RN : Read mm per pulse (mm/step)  -> PC  ==>  VALVE MOTOR mm/step 읽기
//----------------------------------------------------------------------------------------------------------
// VL1,0;  // Extra Gate Valve Motor
// VL1,1;  // Steel Tape Motor
// VL1,2;  // Damper Motor
// VL1,3;  // Main Gate Valve Motor
//----------------------------------------------------------------------------------------------------------
//  2) SA : Set Accelation table         <- PC  ==>  VALVE MOTOR accel 설정
//----------------------------------------------------------------------------------------------------------
// VL2,0,8000;  // Extra Gate Valve Motor
// VL2,1,8000;  // Steel Tape Motor
// VL2,2,8000;  // Damper Motor
// VL2,3,8000;  // Main Gate Valve Motor
//----------------------------------------------------------------------------------------------------------
//  3)  RA : Read Accelation table      -> PC  ==>  VALVE MOTOR accel 읽기
//----------------------------------------------------------------------------------------------------------
// VL3,0;  // Extra Gate Valve Motor
// VL3,1;  // Steel Tape Motor
// VL3,2;  // Damper Motor
// VL3,3;  // Main Gate Valve Motor
//----------------------------------------------------------------------------------------------------------
//  4) SP :  Set Fixed Pulse            <- PC  ==>  VALVE MOTOR 고정위치step값 설정
//----------------------------------------------------------------------------------------------------------
// VL4,0,1000;  // Extra Gate Valve Motor
// VL4,1,500;   // Steel Tape Motor
// VL4,2,4000;  // Damper Motor
// VL4,3,2000;  // Main Gate Valve Motor
//----------------------------------------------------------------------------------------------------------
//  5) Send FixedPositionPulse & Read MovingPulse -> PC
//----------------------------------------------------------------------------------------------------------
// Send FixedPositionPulse  ==>  VALVE MOTOR 고정위치step값 읽기
//----------------------------------------------------------------------------------------------------------
// VL5,0;  // Extra Gate Valve FixedPositionPulse 
// VL5,1;  // Steel Tape FixedPositionPulse
// VL5,2;  // Damper FixedPositionPulse 
// VL5,3;  // Main Gate Valve FixedPositionPulse
//----------------------------------------------------------------------------------------------------------
// Send MovingPulse ( Current Motor Position )  ==>  VALVE MOTOR 현재위치step값 읽기
//----------------------------------------------------------------------------------------------------------
// VL5,5;  // Extra Gate Valve MovingPulse 
// VL5,6;  // Steel Tape MovingPulse
// VL5,7;  // Damper MovingPulse 
// VL5,8;  // Main Gate Valve MovingPulse
//----------------------------------------------------------------------------------------------------------
//  6)  Motion mm 이동 명령어          <- PC  ==>  VALVE MOTOR 이동위치??mm값 설정
//----------------------------------------------------------------------------------------------------------
// VL6,0,21;   // Extra Gate Valve Motor
// VL6,1,2.12; // Steel Tape Motor
// VL6,2,12;   // Damper Motor
// VL6,3,34;   // Main Gate Valve Motor
//----------------------------------------------------------------------------------------------------------
//  7)  Motion Home & Fixed Position 이동 명령어 ( From PC )  ==>  VALVE MOTOR Home & Position 상태값 설정
//----------------------------------------------------------------------------------------------------------
// VL7,0,0;  // Extra Gate Valve Close Home
// VL7,0,1;  // Extra Gate Valve Fixed Open Position  
// VL7,0,2;  // EGV, Home <-> Open Position  ( Home Switch Checking에 의한 Toggling Move )
// VL7,0,3;  // EGV, Home <-> Open Position  ( 현재 위치값에 의한 Toggling Move )
// VL7,1,0;  // Steel Tape, Go Home
// VL7,1,1;  // Steel Tape, Go Sample Position  
// VL7,1,2;  // SAL, Home <-> Go Sample Loading Position ( Home Switch Checking에 의한 Toggling Move ) 
// VL7,1,3;  // SAL, Home <-> Go Sample Loading Position ( 현재 위치값에 의한 Toggling Move )  
// VL7,2,0;  // Damper Go Home
// VL7,2,1;  // Damper Fixed Damping Position
// VL7,2,2;  // DAM, Home <-> Go Damping Position ( Home Switch Checking에 의한 Toggling Move ) 
// VL7,2,3;  // DAM, Home <-> Go Damping Position ( 현재 위치값에 의한 Toggling Move ) 
// VL7,3,0;  // Main Gate Valve Home
// VL7,3,1;  // Main Gate Valve Fixed Open Position 
// VL7,3,2;  // MGV, Home <-> Open Position  
// VL7,3,3;  // MGV, Home <-> Open Position  
//----------------------------------------------------------------------------------------------------------
//  8)  Valve State ( Home or Fixed Position ) 상태 읽기 명령어 ( From PC )  ==>  VALVE MOTOR Home & Position 상태값 읽기
//----------------------------------------------------------------------------------------------------------
// "VL8,????,????;"
//----------------------------------------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : SEM Valve 상태정보 수신
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeVLCommand(void)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;         // Scan Bridge  Command & Data Handle
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// CNC 상태 및 제어용 윈도우 핸들 확인
	if (m_hStageSetupControlWnd == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 메시지 처리 전달용 USB Data
	BOOL bMessage = FALSE;
	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));

	// Value 상태정보값
	int nValve = atoi(m_pIntegrated->szXStr); // VALVE 상태 명령(숫자)
	int nAxis  = atoi(m_pIntegrated->szYStr); // 선택 VALVE AXIS(숫자)

	double dFixed_mm = 0.0;
	double dMore_mm  = 0.0;

	// CNC Command 설정 : 'VL' Command
	UsbDeviceDataInfo.nCommand = SBR_CMD_VL;
	// Valve 설정
	UsbDeviceDataInfo.nState = nValve;

	// Valve 상태 명령어
	switch (nValve)
	{
		case 8: // Valve State : Valve, Steel Tape, Sampler ( Home or Fixed Position ) 상태 읽기 명령어
		{
			if (m_pIntegrated->nExtraLimState != nAxis)
			{
				m_pIntegrated->nExtraLimState = nAxis;

				//------------------------------------------------------------------
				// Extra Gate Valve(EGV) Top Close Home Position
				//------------------------------------------------------------------
				if (nAxis & 0x0001)
				{
					// X,Y,Z,T 축이 정지해 있거나 Home & Limit 상태를 Check 한다면...
					if (m_pIntegrated->bMotorStageHomeCheckFlag == TRUE || m_pIntegrated->nLodMovingState == 0)
					{
						// EGV 고정위치값 Clear
						m_pIntegrated->nEgvPixPosOld = 0;
					}
					m_pIntegrated->nExtraCloseState = 1;
					bMessage = TRUE;
				}
				//------------------------------------------------------------------
				// Extra Gate Valve(EGV) Open Position
				//------------------------------------------------------------------
				else
				{
					// X,Y,Z,T 축이 정지해 있거나 Home & Limit 상태를 Check 한다면...
					if (m_pIntegrated->bMotorStageHomeCheckFlag == TRUE || m_pIntegrated->nLodMovingState == 0)
					{
						// EGV 고정위치값 재설정
						m_pIntegrated->nEgvPixPosOld = EGV_WIDTH_PIX / 2;
					}
					m_pIntegrated->nExtraCloseState = 0;
					bMessage = TRUE;
				}
				//------------------------------------------------------------------
				// Extra Gate Valve(EGV) Bot Open Home Position
				//------------------------------------------------------------------
				if (nAxis & 0x0020)
				{
					// X,Y,Z,T 축이 정지해 있거나 Home & Limit 상태를 Check 한다면...
					if (m_pIntegrated->bMotorStageHomeCheckFlag == TRUE || m_pIntegrated->nLodMovingState == 0)
					{
						// EGV 고정위치값 재설정
						m_pIntegrated->nEgvPixPosOld = EGV_WIDTH_PIX;
					}
					m_pIntegrated->nExtraCloseState = 0;
					bMessage = TRUE;
				}
				else
				{
					// X,Y,Z,T 축이 정지해 있거나 Home & Limit 상태를 Check 한다면...
					if (m_pIntegrated->bMotorStageHomeCheckFlag == TRUE || m_pIntegrated->nLodMovingState == 0)
					{
						// EGV 고정위치값 재설정
						m_pIntegrated->nEgvPixPosOld = EGV_WIDTH_PIX / 2;
					}
					m_pIntegrated->nExtraCloseState = 0;
					bMessage = TRUE;
				}

				//------------------------------------------------------------------
				// Lod (Close) Home Position
				//------------------------------------------------------------------
				if (nAxis & 0x0002)
				{
					// X,Y,Z,T 축 Home & Limit 상태를 Check 한다면...
					if (m_pIntegrated->bMotorStageHomeCheckFlag == TRUE)
					{
						// clear In Lod Position
						// Home Lod

						// Sample 고정위치값 재설정
						m_pIntegrated->nSamLodPixPosOld = SL_WIDTH_PIX;
					}
					// Sample Load Home 위치상태값 설정
					m_pIntegrated->nLodHomeState = 1;
					bMessage = TRUE;
				}
				else             // Lod Moving State
				{
					// X,Y,Z,T 축 Home & Limit 상태를 Check 한다면...
					if (m_pIntegrated->bMotorStageHomeCheckFlag == TRUE)
					{
						// clear Home Lod
						// view In Lod

						// Sample 고정위치값 재설정
						m_pIntegrated->nSamLodPixPosOld = 0;
					}
					m_pIntegrated->nLodHomeState = 0;
					bMessage = TRUE;
				}

				//------------------------------------------------------------------
				// Clamp (Off) Home Position
				//------------------------------------------------------------------
				if (nAxis & 0x0004)
				{
					// X,Y,Z,T 축이 정지해 있거나 Home & Limit 상태를 Check 한다면...
					if (m_pIntegrated->bMotorStageHomeCheckFlag == TRUE || m_pIntegrated->nLodMovingState == 0)
					{
					}
					// Damper On/Off -> Off 상태설정
					m_pIntegrated->nDamperOnState = 0;
					bMessage = TRUE;
				}
				//------------------------------------------------------------------
				// Clamp (on)  Fixed Position
				//------------------------------------------------------------------
				else            
				{
					// X,Y,Z,T 축이 정지해 있거나 Home & Limit 상태를 Check 한다면...
					if (m_pIntegrated->bMotorStageHomeCheckFlag == TRUE || m_pIntegrated->nLodMovingState == 0)
					{
					}
					// Damper On/Off -> On 상태설정
					m_pIntegrated->nDamperOnState = 1;
					bMessage = TRUE;
				}

				//------------------------------------------------------------------
				// MGV Home Position       [ MainChamber || Turbo Vacuum ]
				//------------------------------------------------------------------
				if (nAxis & 0x0008) 
				{
					// X,Y,Z,T 축 Home & Limit 상태를 Check 한다면...
					if (m_pIntegrated->bMotorStageHomeCheckFlag == TRUE)
					{
						bMessage = TRUE;
					}
				}
				//------------------------------------------------------------------
				// MGV (on) Fixed Position [ MainChamber <-> Turbo Vacuum ]
				//------------------------------------------------------------------
				else             
				{
					// X,Y,Z,T 축 Home & Limit 상태를 Check 한다면...
					if (m_pIntegrated->bMotorStageHomeCheckFlag == TRUE)
					{
						bMessage = TRUE;
					}
				}

				//------------------------------------------------------------------
				//  Extra Door          (not used ) BSE Home Position
				//------------------------------------------------------------------
				if (nAxis & 0x0040) 
				{
					//if (LodMovingState == 0)
					// X,Y,Z,T 축이 정지해 있다면...
					if (m_pIntegrated->nLodMovingState == 0)
					{
						//------------------------------------------------
						// Sample + Lod + ExtraWall ==> Out Side => Clear
						//------------------------------------------------

						//------------------------------------------------
						// Sample + Lod + ExtraWall ==> Home Pos
						//------------------------------------------------
						if (m_pIntegrated->nSampleLoadState == 0)
						{
						}
						//------------------------------------------------

						bMessage = TRUE;
					}
				}
				else
				{
					//------------------------------------------------------
					//  Limit Home Bmp Update의 CheckBox에 무관한게 동작함
					//------------------------------------------------------
					// X,Y,Z,T 축이 정지해 있다면...
					if (m_pIntegrated->nLodMovingState == 0)
					{
						//------------------------------------------------
						// Sample + Lod + ExtraWall ==> Home Pos => Clear
						//------------------------------------------------

						//----------------------------------------
						// Sample + Lod + ExtraWall ==> Out Side
						//----------------------------------------
						if (m_pIntegrated->nSampleLoadState == 0)
						{
						}
						//----------------------------------------

						bMessage = TRUE;
					}
				}
				//------------------------------------------------------------------

				////////////////////////////////////////////////////////////////////
				//PaintBox_SST->Canvas->Draw(0, 0, m_pBitmap_SST);
				////////////////////////////////////////////////////////////////////

				//------------------------------------------------------------------
				// Sample Loaded State
				//------------------------------------------------------------------
				if (nAxis & 0x0080) 
				{
					// X,Y,Z,T 축 Home & Limit 상태를 Check 한다면...
					if (m_pIntegrated->bMotorStageHomeCheckFlag == TRUE)
					{
						// In Sample
						// Home Sample
					}
					m_pIntegrated->nSampleLoadState = 1;
					bMessage = TRUE;
				}
				else             // Sample Unload State
				{
					// X,Y,Z,T 축 Home & Limit 상태를 Check 한다면...
					if (m_pIntegrated->bMotorStageHomeCheckFlag == TRUE)
					{
						// In Sample
						// Home Sample
					}
					m_pIntegrated->nSampleLoadState = 0;
					bMessage = TRUE;
				}
				//------------------------------------------------------------------

				if (nAxis & 0x0010) // Extra Evac SW
				{
					// X,Y,Z,T 축 Home & Limit 상태를 Check 한다면...
					if (m_pIntegrated->bMotorStageHomeCheckFlag == TRUE)
					{
						bMessage = TRUE;
					}
				}
				else
				{
					// X,Y,Z,T 축 Home & Limit 상태를 Check 한다면...
					if (m_pIntegrated->bMotorStageHomeCheckFlag == TRUE)
					{
						bMessage = TRUE;
					}
				}
				//------------------------------------------------------------------
			}
			break;
		}


		//------------------------------------------------------------------
		//  Read 1mm per pulse (mm/step) <= String
		//------------------------------------------------------------------
		case 1: 
		case 2:
		{
			// 모터축(Axis) 1Pulse 당 [mm] 이동거리
			m_pIntegrated->dAxisMMPerPulse[nAxis + 5] = atof(m_pIntegrated->szDStr);
			bMessage = TRUE;
			break;
		}

		//------------------------------------------------------------------
		// Read Accelation table <= String
		//------------------------------------------------------------------
		case 3: 
		case 4:
		{
			// 모터축(Axis) Acc(가속) 값
			bMessage = TRUE;
			break;
		}

		//------------------------------------------------------------------
		// Read FixedPosition pulse <= pulse
		//------------------------------------------------------------------
		case 5: 
		case 6:
		case 7:
		case 9:
		{
			// 모터축(Axis) 고정위치값 [mm] 계산 및 설정
			m_pIntegrated->nFixedPositionPulse[nAxis] = atoi(m_pIntegrated->szDStr);
			dFixed_mm = (double)(m_pIntegrated->nFixedPositionPulse[nAxis] * m_pIntegrated->dAxisMMPerPulse[nAxis + 5]);
			bMessage = TRUE;
			break;
		}

		//------------------------------------------------------------------
		// Read Position pulse <= pulse
		//------------------------------------------------------------------
		case 10:
		case 11:
		{
			// 모터축(Axis) 현재위치값 [mm] 계산 및 설정
			m_pIntegrated->nMorePositionPulse[nAxis] = atoi(m_pIntegrated->szDStr);
			dMore_mm = (double)(m_pIntegrated->nMorePositionPulse[nAxis] * m_pIntegrated->dAxisMMPerPulse[nAxis + 5]);
			bMessage = TRUE;
			break;
		}

		//------------------------------------------------------------------
		// Main & Extra 챔버 Air 상태 표시,
		// Low Vac Sol Valve / TP NW16 Angle Valve /
		// Extra NW16 Angle Valve ==> On/Off 상태표시
		//------------------------------------------------------------------
		case 12:
		case 13:
		{
			if (nAxis & 0x0001) // Main Extra Chamber Air Valve On/Off
			{
				// Main Chamber Air Valve On
				m_pIntegrated->nMainChamberAirFlag = 1;

				// 숫자 Data : Valve Index
				UsbDeviceDataInfo.nData[0] = 1;
				// 숫자 Data : On/Off 값
				UsbDeviceDataInfo.nData[1] = m_pIntegrated->nMainChamberAirFlag;

				// Main Chamber Air Valve On 상태정보 표시하기 
				SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
			}
			else
			{
				//MotorStageSetupForm->McAirSpeedButton->Glyph->LoadFromFile(m_strAppDir + "\\Tool_Image\\red_ledon.bmp");

				// Main Chamber Air Valve Off
				m_pIntegrated->nMainChamberAirFlag = 0;

				// 숫자 Data : Valve Index
				UsbDeviceDataInfo.nData[0] = 1;
				// 숫자 Data : On/Off 값
				UsbDeviceDataInfo.nData[1] = m_pIntegrated->nMainChamberAirFlag;

				// Main Chamber Air Valve On 상태정보 표시하기 
				SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
			}

			if (nAxis & 0x0002) // ExtraChamber Air Valve On/Off
			{
				//MotorStageSetupForm->ExAirSpeedButton->Glyph->LoadFromFile(m_strAppDir + "\\Tool_Image\\green_ledon.bmp");

				// Extra Chamber Air Valve On
				m_pIntegrated->nExtraChamberAirFlag = 1;

				// 숫자 Data : Valve Index
				UsbDeviceDataInfo.nData[0] = 2;
				// 숫자 Data : On/Off 값
				UsbDeviceDataInfo.nData[1] = m_pIntegrated->nExtraChamberAirFlag;

				// Main Chamber Air Valve On 상태정보 표시하기 
				SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
			}
			else
			{
				//MotorStageSetupForm->ExAirSpeedButton->Glyph->LoadFromFile(m_strAppDir + "\\Tool_Image\\red_ledon.bmp");

				// Extra Chamber Air Valve Off
				m_pIntegrated->nExtraChamberAirFlag = 0;

				// 숫자 Data : Valve Index
				UsbDeviceDataInfo.nData[0] = 2;
				// 숫자 Data : On/Off 값
				UsbDeviceDataInfo.nData[1] = m_pIntegrated->nExtraChamberAirFlag;

				// Main Chamber Air Valve On 상태정보 표시하기 
				SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
			}

			if (nAxis & 0x0004) // Low Vacuum Sol Valve On/Off
			{
				//MotorStageSetupForm->LVacSolVSpeedButton->Glyph->LoadFromFile(m_strAppDir + "\\Tool_Image\\green_ledon.bmp");

				// Low Vacuum Sol Valve Air On
				m_pIntegrated->nLowVacSolAirFlag = 1;

				// 숫자 Data : Valve Index
				UsbDeviceDataInfo.nData[0] = 3;
				// 숫자 Data : On/Off 값
				UsbDeviceDataInfo.nData[1] = m_pIntegrated->nLowVacSolAirFlag;

				// Main Chamber Air Valve On 상태정보 표시하기 
				SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
			}
			else
			{
				//MotorStageSetupForm->LVacSolVSpeedButton->Glyph->LoadFromFile(m_strAppDir + "\\Tool_Image\\red_ledon.bmp");

				// Low Vacuum Sol Valve Air Off
				m_pIntegrated->nLowVacSolAirFlag = 0;

				// 숫자 Data : Valve Index
				UsbDeviceDataInfo.nData[0] = 3;
				// 숫자 Data : On/Off 값
				UsbDeviceDataInfo.nData[1] = m_pIntegrated->nLowVacSolAirFlag;

				// Main Chamber Air Valve On 상태정보 표시하기 
				SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
			}


			if (nAxis & 0x0008) // TP NW16 Angle Valve On/Off
			{
				//MotorStageSetupForm->TpVLSpeedButton->Glyph->LoadFromFile(m_strAppDir + "\\Tool_Image\\red_ledon.bmp");

				// TP NW16 Angle Valve On -> Closed
				m_pIntegrated->nTpVL_CloseFlag = 1;

				// 숫자 Data : Valve Index
				UsbDeviceDataInfo.nData[0] = 4;
				// 숫자 Data : On/Off 값
				UsbDeviceDataInfo.nData[1] = m_pIntegrated->nTpVL_CloseFlag;

				// Main Chamber Air Valve On 상태정보 표시하기 
				SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
			}
			else
			{
				//MotorStageSetupForm->TpVLSpeedButton->Glyph->LoadFromFile(m_strAppDir + "\\Tool_Image\\green_ledon.bmp");

				// TP NW16 Angle Valve Off -> Opened
				m_pIntegrated->nTpVL_CloseFlag = 0;

				// 숫자 Data : Valve Index
				UsbDeviceDataInfo.nData[0] = 4;
				// 숫자 Data : On/Off 값
				UsbDeviceDataInfo.nData[1] = m_pIntegrated->nTpVL_CloseFlag;

				// Main Chamber Air Valve On 상태정보 표시하기 
				SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
			}

			if (nAxis & 0x0010) // Extra NW16 Angle Valve On/Off
			{
				//MotorStageSetupForm->ExVLSpeedButton->Glyph->LoadFromFile(m_strAppDir + "\\Tool_Image\\red_ledon.bmp");

				// Extra NW16 Angle Valve On -> Closed
				m_pIntegrated->nExVL_CloseFlag = 1;

				// 숫자 Data : Valve Index
				UsbDeviceDataInfo.nData[0] = 5;
				// 숫자 Data : On/Off 값
				UsbDeviceDataInfo.nData[1] = m_pIntegrated->nExVL_CloseFlag;

				// Main Chamber Air Valve On 상태정보 표시하기 
				SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
			}
			else
			{
				//MotorStageSetupForm->ExVLSpeedButton->Glyph->LoadFromFile(m_strAppDir + "\\Tool_Image\\green_ledon.bmp");

				// Extra NW16 Angle Valve Off -> Opened
				m_pIntegrated->nExVL_CloseFlag = 0;

				// 숫자 Data : Valve Index
				UsbDeviceDataInfo.nData[0] = 5;
				// 숫자 Data : On/Off 값
				UsbDeviceDataInfo.nData[1] = m_pIntegrated->nExVL_CloseFlag;

				// Main Chamber Air Valve On 상태정보 표시하기 
				SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
			}
			break;
		}

	}

	// VALVE 상태 데이터 MESSAGE 보내기
	if (bMessage == TRUE)
	{
		if (m_hOwnerWnd != NULL)
		{
			// 2020.05.04
			// VALVE 상태 정보 메시지 보내기
			//SendMessage(m_hOwnerWnd, UM_USB_SBR_VAL_STATE, NULL, (LPARAM)&UsbDeviceDataInfo);
		}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "VL", "AR" -> Valve On/Off State , Valve On/Of 명령 실행
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeVLCommand(int nWriteFlag, int nValve, char *pszData)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Axis Accelation Pulse 설정
	char szCNCData[255 + 1];
	memset(szCNCData, 0x00, sizeof(szCNCData));

	// 위치값
	int nOnOffValue = 0;

	// 정보값 저장하기 
	if (nWriteFlag == 1)
	{
		// VL, RA ??? 값
		if (pszData != NULL) nOnOffValue = atoi(pszData);

		// VL, RA Command
		switch (nValve)
		{
		case 13:
		{
			// X축 Accelation값 설정하기
			sprintf(szCNCData, "RA%d,%d;", nValve, nOnOffValue);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		}
	}
	else
	{
		// VL, RA ??? 값
		//if (pszData != NULL) nValue = atoi(pszData);

		// RA Command
		switch (nValve)
		{
		case 0:
		{
			// Main Chamber Air Value On/Off 설정 및 실행하기
			nOnOffValue = m_pIntegrated->nMainChamberAirFlag;
			sprintf(szCNCData, "RA%d,%d;", nValve, nOnOffValue);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case 1:
		{
			// Extra Chamber Air Value On/Off 설정 및 실행하기
			nOnOffValue = m_pIntegrated->nExtraChamberAirFlag;
			sprintf(szCNCData, "RA%d,%d;", nValve, nOnOffValue);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case 2:
		{
			// Low Vacuum Sol Value On/Off 설정 및 실행하기
			nOnOffValue = m_pIntegrated->nLowVacSolAirFlag;
			sprintf(szCNCData, "RA%d,%d;", nValve, nOnOffValue);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case 3:
		{
			// TP NW16 Angle Value On/Off 설정 및 실행하기
			nOnOffValue = m_pIntegrated->nTpVL_CloseFlag;
			sprintf(szCNCData, "RA%d,%d;", nValve, nOnOffValue);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case 4:
		{
			// Extra NW16 Angle Value On/Off 설정 및 실행하기
			nOnOffValue = m_pIntegrated->nExVL_CloseFlag;
			sprintf(szCNCData, "RA%d,%d;", nValve, nOnOffValue);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case 13:
		{
			if (pszData != NULL) nOnOffValue = atoi(pszData);
			// Air Valve Check On/Off 설정 및 실행하기
			sprintf(szCNCData, "VL%d,%d;", nValve, nOnOffValue);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "EM" -> Emission Current 값 Read(수신)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeEMCommand(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle
																			
	// 수신된 Emission Current 값 보관 및 표시
	m_pIntegrated->nEmCurrentLevel = atoi(m_pIntegrated->szXStr);

	BOOL bMessage = FALSE;
	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));

	bMessage = TRUE;
	// Emission Level
	UsbDeviceDataInfo.nState   = 3; // Emission 처리 (1:Vacuum State, 2:진공게이지값, 3:Emission값)
	UsbDeviceDataInfo.nData[2] = m_pIntegrated->nEmCurrentLevel;

	// Emission Current 값 MESSAGE 보내기
	if (bMessage == TRUE)
	{
		if (m_hOwnerWnd != NULL)
		{
			// DEVICE MAIN SERVER
			// Emission Current 값 정보 메시지 보내기 (진공 데이터에 포함되어 있음)
			// 2020.05.04
			SendMessage(m_hOwnerWnd, UM_USB_SBR_VACUUM_DATA, NULL, (LPARAM)&UsbDeviceDataInfo);
		}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "RN" -> Read  mm per step(1Pulse당 이동거리[mm]) 값 수신 (CNC Board 명령어 자료)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeRNCommand(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// 모터 축 정보
	int nAxis = (int)(m_pIntegrated->szXStr[0] - '0');

	if (nAxis >= IDX_X_AXIS && nAxis <= IDX_T_AXIS)
	{
		// 수신된 1[mm]당 Pulse갯수 보관(적용)
		m_pIntegrated->dAxisPulsePerUnit[nAxis] = atof(m_pIntegrated->szYStr);
	}
	else
	{
		return RET_SUCCESS_OK;
	}

	// 각 축(Axis)별 Unit 당 Pulse 갯수 계산 및 보관(적용)
	if (m_pIntegrated->dAxisPulsePerUnit[nAxis] == 0)
	{
		// 수신된 1Pulse 당 이동거리[mm] 보관(적용) : 소숫점 7자리
		m_pIntegrated->dAxisMMPerPulse[nAxis] = 0.0;
	}
	else
	{
		// 수신된 1Pulse 당 이동거리[mm] 보관(적용) : 소숫점 7자리
		m_pIntegrated->dAxisMMPerPulse[nAxis] = 1.0 / m_pIntegrated->dAxisPulsePerUnit[nAxis];
	}

	// CNC 상태 및 제어용 윈도우 핸들 확인
	if (m_hStageSetupControlWnd == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 메시지 처리 전달용 USB Data
	BOOL bMessage = FALSE;
	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));
	bMessage = TRUE;

	// CNC Command 설정 : 'RN' Command
	UsbDeviceDataInfo.nCommand = SBR_CMD_RN;
	// Axis 설정
	UsbDeviceDataInfo.nState = nAxis;
	// 수신된 Data String : 1Pulse 당 이동거리[mm]
	strcpy_s(UsbDeviceDataInfo.szData, m_pIntegrated->szYStr);
	// 숫자 Data : 1Pulse 당 이동거리[mm]
	UsbDeviceDataInfo.dData[0] = m_pIntegrated->dAxisMMPerPulse[nAxis];
	// 숫자 Data : 1[mm] 당 Pulse 갯수
	UsbDeviceDataInfo.dData[1] = m_pIntegrated->dAxisPulsePerUnit[nAxis];

	// 2020.04.28
	/*
	// mm/step 계산된 값 자료 전송
	switch (nAxis)
	{
	    case IDX_X_AXIS: // X축 1[mm]이동거리 당 Pulse 값 표시하기 
	    case IDX_Y_AXIS: // Y축 1[mm]이동거리 당 Pulse 값 표시하기 
	    case IDX_Z_AXIS: // Z축 1[mm]이동거리 당 Pulse 값 표시하기 
	    case IDX_R_AXIS: // R축 1[deg]이동거리 당 Pulse 값 표시하기 
	    case IDX_T_AXIS: // T축 1[deg]이동거리 당 Pulse 값 표시하기 
		{
			bMessage = TRUE;
			if (m_hOwnerWnd != NULL)
			{
				// DEVICE MAIN SERVER
				// pulse/1mm 값 정보 메시지 보내기
				SendMessage(m_hOwnerWnd, UM_USB_SBR_STAGE_AXIS_MM_STEP, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
			}
			break;
		}
	}
	*/

	// pulse/1mm 계산된 값 표시하기
	switch (nAxis)
	{
		case IDX_X_AXIS:
		{
			// X축 1[mm]이동거리 당 Pulse 값 표시하기 
			SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
			break;
		}
		case IDX_Y_AXIS:
		{
			// Y축 1[mm]이동거리 당 Pulse 값 표시하기 
			SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
			break;
		}
		case IDX_Z_AXIS:
		{
			// Z축 1[mm]이동거리 당 Pulse 값 표시하기 
			SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
			break;
		}
		case IDX_R_AXIS:
		{
			// R축 1[deg]이동거리 당 Pulse 값 표시하기 
			SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
			break;
		}
		case IDX_T_AXIS:
		{
			// T축 1[deg]이동거리 당 Pulse 값 표시하기 
			SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);

			// 3축 STAGE
			if (m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_ALL_DATA_VIEW] == FALSE)
			{
				// 2021.07.07
				// T축을 이용하여 BSE축 정보를 얻는다
				m_pIntegrated->dAxisMMPerPulse[IDX_B_AXIS]   = m_pIntegrated->dAxisMMPerPulse[IDX_T_AXIS];
				m_pIntegrated->dAxisPulsePerUnit[IDX_B_AXIS] = m_pIntegrated->dAxisPulsePerUnit[IDX_T_AXIS];
				UsbDeviceDataInfo.nState = IDX_B_AXIS;
				SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
			}

			break;
		}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "RN" -> Read or Write  mm per step(1Pulse당 이동거리[mm]) 값 수신 (CNC Board 명령어 자료)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeRNCommand(int nWriteFlag, int nAxis, char *pszData)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// 모터 축 RN 정보
	char szCNCData[255 + 1];
	char szAxis[5 + 1];
	memset(szCNCData, 0x00, sizeof(szCNCData));
	memset(szAxis, 0x00, sizeof(szAxis));

	// 정보값 저장하기 
	if (nWriteFlag == 1)
	{
		// SN Command
		strcpy_s(szCNCData, "SN");

		// 계산된 값 표시하기
		switch (nAxis)
		{
		    case IDX_X_AXIS:
			{
				// X축 1[mm]이동거리 당 Pulse 값 저장하기 
				//strcat(szCNCData, "0,");
				sprintf(szAxis, "%d,", nAxis);
				strcat(szCNCData, szAxis);
				strcat(szCNCData, pszData);
				strcat(szCNCData, ";");
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
				break;
			}
		    case IDX_Y_AXIS:
			{
				// Y축 1[mm]이동거리 당 Pulse 값 저장하기 
				//strcat(szCNCData, "1,");
				sprintf(szAxis, "%d,", nAxis);
				strcat(szCNCData, szAxis);
				strcat(szCNCData, pszData);
				strcat(szCNCData, ";");
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
				break;
			}
		    case IDX_Z_AXIS:
			{
				// Z축 1[mm]이동거리 당 Pulse 값 저장하기 
				//strcat(szCNCData, "2,");
				sprintf(szAxis, "%d,", nAxis);
				strcat(szCNCData, szAxis);
				strcat(szCNCData, pszData);
				strcat(szCNCData, ";");
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
				break;
			}
		    case IDX_R_AXIS:
			{
				// R축 1[deg]이동거리 당 Pulse 값 저장하기 
				//strcat(szCNCData, "3,");
				sprintf(szAxis, "%d,", nAxis);
				strcat(szCNCData, szAxis);
				strcat(szCNCData, pszData);
				strcat(szCNCData, ";");
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
				break;
			}
		    case IDX_T_AXIS:
			{
				// T축 1[deg]이동거리 당 Pulse 값 저장하기 
				//strcat(szCNCData, "4,");
				sprintf(szAxis, "%d,", nAxis);
				strcat(szCNCData, szAxis);
				strcat(szCNCData, pszData);
				strcat(szCNCData, ";");
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
				break;
			}
			case IDX_B_AXIS:
			{
				// 3축 STAGE
				if (m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_ALL_DATA_VIEW] == FALSE)
				{
					// 2021.07.07
					// T축을 이용하여 BSE축 정보를 얻는다
					// BSE축 1[mm]이동거리 당 Pulse 값 저장하기 
					int nBseAxis = IDX_T_AXIS;
					sprintf(szAxis, "%d,", nBseAxis);
					strcat(szCNCData, szAxis);
					strcat(szCNCData, pszData);
					strcat(szCNCData, ";");
					// VacBoard -> PC -> To CncBoard
					AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
				}
				break;
			}
		}
	}
	else
	{
		// RN Command (예 Z축 : "RN2;" )
		strcpy_s(szCNCData, "RN");

		// 계산된 값 표시하기
		switch (nAxis)
		{
		    case IDX_X_AXIS:
			{
				// X축 1[mm]이동거리 당 Pulse 값 표시하기 
				//strcat(szCNCData, "0,");
				sprintf(szAxis, "%d", nAxis);
				strcat(szCNCData, szAxis);
				strcat(szCNCData, ";");
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
				break;
			}
		    case IDX_Y_AXIS:
			{
				// Y축 1[mm]이동거리 당 Pulse 값 표시하기 
				//strcat(szCNCData, "1,");
				sprintf(szAxis, "%d", nAxis);
				strcat(szCNCData, szAxis);
				strcat(szCNCData, ";");
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
				break;
			}
		    case IDX_Z_AXIS:
			{
				// Z축 1[mm]이동거리 당 Pulse 값 표시하기 
				//strcat(szCNCData, "2,");
				sprintf(szAxis, "%d", nAxis);
				strcat(szCNCData, szAxis);
				strcat(szCNCData, ";");
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
				break;
			}
		    case IDX_R_AXIS:
			{
				// R축 1[deg]이동거리 당 Pulse 값 표시하기 
				//strcat(szCNCData, "3,");
				sprintf(szAxis, "%d", nAxis);
				strcat(szCNCData, szAxis);
				strcat(szCNCData, ";");
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
				break;
			}
		    case IDX_T_AXIS:
			{
				// T축 1[deg]이동거리 당 Pulse 값 표시하기 
				//strcat(szCNCData, "4,");
				sprintf(szAxis, "%d", nAxis);
				strcat(szCNCData, szAxis);
				strcat(szCNCData, ";");
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
				break;
			}
			case IDX_B_AXIS:
			{
				// 3축 STAGE
				if (m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_ALL_DATA_VIEW] == FALSE)
				{
					// 2021.07.07
					// T축을 이용하여 BSE축 정보를 얻는다
					// BSE축 1[mm]이동거리 당 Pulse 값 표시하기 
					int nBseAxis = IDX_T_AXIS;
					sprintf(szAxis, "%d", nBseAxis);
					strcat(szCNCData, szAxis);
					strcat(szCNCData, ";");
					// VacBoard -> PC -> To CncBoard
					AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
				}
				break;
			}
		}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "RA" -> Read Axis Accelation (각 축의 Accelation 값 수신 및 적용) (CNC Board 명령어 자료)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeRACommand(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

    // CNC 상태 및 제어용 윈도우 핸들 확인
	if (m_hStageSetupControlWnd == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 메시지 처리 전달용 USB Data
	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));
	BOOL bMessage = FALSE;

	// CNC Command 설정 : 'RA' Command
	UsbDeviceDataInfo.nCommand = SBR_CMD_RA;

	// 모터 축(Axis)
	int nAxis = (int)(m_pIntegrated->szXStr[0] - '0');
	char szData[255+1];

	// 수신된 값 표시하기
	switch (nAxis)
	{
		case IDX_X_AXIS:
		{
			// 수신된 모터 축(Axis) Accelation(가속) 값 보관 및 적용
			m_pIntegrated->nAxisAccCalVal[nAxis] = atoi(m_pIntegrated->szYStr);
			bMessage = TRUE;

			memset(szData, 0x00, sizeof(szData));
			sprintf(szData, "%d", m_pIntegrated->nAxisAccCalVal[nAxis]);

			// X축 Accelation 값 표시하기 
			UsbDeviceDataInfo.nState = nAxis;
			strcpy_s(UsbDeviceDataInfo.szData, szData);
			break;
		}
		case IDX_Y_AXIS:
		{
			// 수신된 모터 축(Axis) Accelation(가속) 값 보관 및 적용
			m_pIntegrated->nAxisAccCalVal[nAxis] = atoi(m_pIntegrated->szYStr);
			bMessage = TRUE;

			memset(szData, 0x00, sizeof(szData));
			sprintf(szData, "%d", m_pIntegrated->nAxisAccCalVal[nAxis]);

			// Y축 Accelation 값 표시하기 
			UsbDeviceDataInfo.nState = nAxis;
			strcpy_s(UsbDeviceDataInfo.szData, szData);
			break;
		}
		case IDX_Z_AXIS:
		{
			// 수신된 모터 축(Axis) Accelation(가속) 값 보관 및 적용
			m_pIntegrated->nAxisAccCalVal[nAxis] = atoi(m_pIntegrated->szYStr);
			bMessage = TRUE;

			memset(szData, 0x00, sizeof(szData));
			sprintf(szData, "%d", m_pIntegrated->nAxisAccCalVal[nAxis]);

			// Z축 Accelation 값 표시하기 
			UsbDeviceDataInfo.nState = nAxis;
			strcpy_s(UsbDeviceDataInfo.szData, szData);
			break;
		}
		case IDX_R_AXIS:
		{
			// 수신된 모터 축(Axis) Accelation(가속) 값 보관 및 적용
			m_pIntegrated->nAxisAccCalVal[nAxis] = atoi(m_pIntegrated->szYStr);
			bMessage = TRUE;

			memset(szData, 0x00, sizeof(szData));
			sprintf(szData, "%d", m_pIntegrated->nAxisAccCalVal[nAxis]);

			// R축 Accelation 값 표시하기 
			UsbDeviceDataInfo.nState = nAxis;
			strcpy_s(UsbDeviceDataInfo.szData, szData);
			break;
		}
		case IDX_T_AXIS:
		{
			// 수신된 모터 축(Axis) Accelation(가속) 값 보관 및 적용
			m_pIntegrated->nAxisAccCalVal[nAxis] = atoi(m_pIntegrated->szYStr);
			bMessage = TRUE;

			memset(szData, 0x00, sizeof(szData));
			sprintf(szData, "%d", m_pIntegrated->nAxisAccCalVal[nAxis]);

			// T축 Accelation 값 표시하기 
			UsbDeviceDataInfo.nState = nAxis;
			strcpy_s(UsbDeviceDataInfo.szData, szData);
			break;
		}
	}

	/*
	// axis accel 값 자료 전송
	switch (nAxis)
	{
	    case IDX_X_AXIS: // X축 accel 값 표시하기 
	    case IDX_Y_AXIS: // Y축 accel 값 표시하기 
	    case IDX_Z_AXIS: // Z축 accel 값 표시하기 
	    case IDX_R_AXIS: // R축 accel 값 표시하기 
	    case IDX_T_AXIS: // T축 accel 값 표시하기 
	    {
		    if (bMessage == TRUE)
		    {
			    if (m_hOwnerWnd != NULL)
			    {
				    // DEVICE MAIN SERVER
				    // axis accel 값 정보 메시지 보내기
					SendMessage(m_hOwnerWnd, UM_USB_SBR_STAGE_AXIS_ACCEL, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
			    }
		    }
		    break;
	    }
	}
	*/

	// 수신된 값 표시하기
	switch (nAxis)
	{
	case IDX_X_AXIS:
	{
		// 수신된 모터 축(Axis) Accelation(가속) 값 보관 및 적용
		// X축 Accelation 값 표시하기 
		SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
		break;
	}
	case IDX_Y_AXIS:
	{
		// 수신된 모터 축(Axis) Accelation(가속) 값 보관 및 적용
		// Y축 Accelation 값 표시하기 
		SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
		break;
	}
	case IDX_Z_AXIS:
	{
		// 수신된 모터 축(Axis) Accelation(가속) 값 보관 및 적용
		// Z축 Accelation 값 표시하기 
		SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
		break;
	}
	case IDX_R_AXIS:
	{
		// 수신된 모터 축(Axis) Accelation(가속) 값 보관 및 적용
		// R축 Accelation 값 표시하기 
		SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
		break;
	}
	case IDX_T_AXIS:
	{
		// 수신된 모터 축(Axis) Accelation(가속) 값 보관 및 적용
		// T축 Accelation 값 표시하기 
		SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);

		// 3축 STAGE
		if (m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_ALL_DATA_VIEW] == FALSE)
		{
			// 2021.07.07
			// BSE축 Accelation 값 표시하기 
			m_pIntegrated->nAxisAccCalVal[IDX_B_AXIS] = m_pIntegrated->nAxisAccCalVal[IDX_T_AXIS];
			UsbDeviceDataInfo.nState = IDX_B_AXIS;
			SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
		}

		break;
	}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "RA","SA" -> Axis Accelation 읽기 또는 쓰기
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeRACommand(int nWriteFlag, int nAxis, char *pszData)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Axis Accelation Pulse 설정
	char szCNCData[255 + 1];
	memset(szCNCData, 0x00, sizeof(szCNCData));

	// 위치값
	int nPulse = 0;

	// 정보값 저장하기 
	if (nWriteFlag == 1)
	{
		// Axis Accelation Pulse 값
		if (pszData != NULL) nPulse = atoi(pszData);

		// SA Command
		switch (nAxis)
		{
		case IDX_X_AXIS:
		{
			// X축 Accelation값 설정하기
			sprintf(szCNCData, "SA%d,%d;", nAxis, nPulse);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_Y_AXIS:
		{
			// Y축 Accelation값 설정하기
			sprintf(szCNCData, "SA%d,%d;", nAxis, nPulse);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_Z_AXIS:
		{
			// Z축 Accelation값 설정하기
			sprintf(szCNCData, "SA%d,%d;", nAxis, nPulse);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_R_AXIS:
		{
			// R축 Accelation값 설정하기
			sprintf(szCNCData, "SA%d,%d;", nAxis, nPulse);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_T_AXIS:
		{
			// T축 Accelation값 설정하기
			sprintf(szCNCData, "SA%d,%d;", nAxis, nPulse);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_B_AXIS:
		{
			// 3축 STAGE
			if (m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_ALL_DATA_VIEW] == FALSE)
			{
				// 2021.07.07
				// BSE축 Accelation값 설정하기
				int nBseAxis = IDX_T_AXIS;
				sprintf(szCNCData, "SA%d,%d;", nBseAxis, nPulse);
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			}
			break;
		}
		}
	}
	else
	{
		// RA Command
		switch (nAxis)
		{
		case IDX_X_AXIS:
		{
			// X축 Accelation값 표시하기 
			sprintf(szCNCData, "RA%d;", nAxis);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_Y_AXIS:
		{
			// Y축 Accelation값 표시하기 
			sprintf(szCNCData, "RA%d;", nAxis);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_Z_AXIS:
		{
			// Z축 Accelation값 표시하기 
			sprintf(szCNCData, "RA%d;", nAxis);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_R_AXIS:
		{
			// R축 Accelation값 표시하기 
			sprintf(szCNCData, "RA%d;", nAxis);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_T_AXIS:
		{
			// T축 Accelation값 표시하기 
			sprintf(szCNCData, "RA%d;", nAxis);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_B_AXIS:
		{
			// 3축 STAGE
			if (m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_ALL_DATA_VIEW] == FALSE)
			{
				// 2021.07.07
				// BSE축 Accelation값 표시하기 
				int nBseAxis = IDX_T_AXIS;
				sprintf(szCNCData, "RA%d;", nBseAxis);
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			}
			break;
		}
		}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "RP" -> Motor 또는 Valve Current Read Position (모터 또는 밸브 현 위치값 수신 및 적용)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeRPCommand(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// CNC 상태 및 제어용 윈도우 핸들 확인
	if (m_hStageSetupControlWnd == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 메시지 처리 전달용 USB Data
	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));
	BOOL bMessage = FALSE;

	// CNC Command 설정 : 'RP' Command
	UsbDeviceDataInfo.nCommand = SBR_CMD_RP;
	
	int nXpix     = 0;
	int nYpix     = 0;
	int nAngle    = 0;
	int nTilt_deg = 0;
	char szCom[255+1];
	char szData[255+1];

	// Motor 축(X,Y,Z,R,T,EG,LOD,CLAMP,MGV,BSE)을 설정한다
	int nAxis = atoi(m_pIntegrated->szXStr);

	// 일반적 오류 코드
	if (nAxis < 0 || nAxis > 10) return RET_ERROR_STATUS;

	// Bitmap에 표시 Flag
	m_pIntegrated->nBmpMovingFlag[nAxis] = m_pIntegrated->szDStr[0] - '0';

	// X Axis <--> Y Axis 반전
	if (m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_XY_REVERSE] == TRUE)
	{
		// X축 위치값을 Y축에 적용한다
		if (nAxis == IDX_X_AXIS) nAxis = IDX_Y_AXIS;
		// Y축 위치값을 X축에 적용한다
		else if (nAxis == IDX_Y_AXIS) nAxis = IDX_X_AXIS;
	}

	// 위치정보 전송
	switch (nAxis)
	{
		case IDX_X_AXIS: // X
		{
			// Motor 축(X,Y,Z,R,T,EG,LOD,CLAMP,MGV,BSE)의 현 위치값(Pulse)을 설정한다
			m_pIntegrated->nAxisPosition[nAxis] = atoi(m_pIntegrated->szYStr);
			// 현재 위치값을 [mm] 단위로 계산 한다
			m_pIntegrated->dCurAxisPos[nAxis] = (double)(m_pIntegrated->nAxisPosition[nAxis]) * m_pIntegrated->dAxisMMPerPulse[nAxis];
			m_pIntegrated->dCurXPos = m_pIntegrated->dCurAxisPos[nAxis];
			bMessage = TRUE;

			memset(szData, 0x00, sizeof(szData));
			if (m_pIntegrated->dCurAxisPos[nAxis] == 0)
			{
				strcpy_s(szData, "0");
			}
			else
			{
				sprintf(szData, "%g", m_pIntegrated->dCurAxisPos[nAxis]);
			}
			// X축 현재 위치값[mm] 를 표시한다
			UsbDeviceDataInfo.nState = nAxis;
			strcpy_s(UsbDeviceDataInfo.szData, szData);
			break;
		}

		case IDX_Y_AXIS: // Y
		{
			// Motor 축(X,Y,Z,R,T,EG,LOD,CLAMP,MGV,BSE)의 현 위치값(Pulse)을 설정한다
			m_pIntegrated->nAxisPosition[nAxis] = atoi(m_pIntegrated->szYStr);
			// 현재 위치값을 [mm] 단위로 계산 한다
			m_pIntegrated->dCurAxisPos[nAxis] = (double)(m_pIntegrated->nAxisPosition[nAxis]) * m_pIntegrated->dAxisMMPerPulse[nAxis];
			m_pIntegrated->dCurYPos = m_pIntegrated->dCurAxisPos[nAxis];
			bMessage = TRUE;

			memset(szData, 0x00, sizeof(szData));
			if (m_pIntegrated->dCurAxisPos[nAxis] == 0)
			{
				strcpy_s(szData, "0");
			}
			else
			{
				sprintf(szData, "%g", m_pIntegrated->dCurAxisPos[nAxis]);
			}
			// Y축 현재 위치값[mm] 를 표시한다
			UsbDeviceDataInfo.nState = nAxis;
			strcpy_s(UsbDeviceDataInfo.szData, szData);
			break;
		}

		case IDX_Z_AXIS: // Z
		{
			// Z축 이전값 보관
			double dOldZPos = m_pIntegrated->dCurZPos;       // Z축 이전값 보관 
			double dZPosP   = m_pIntegrated->dCurZPos + 0.1; // 0.1[mm] 더하기
			double dZPosM   = m_pIntegrated->dCurZPos - 0.1; // 0.1[mm] 빼기
			double dZPosPM  = 0.0;                           // Z축 차이값 ( 현재 - 이전 )

			// Motor 축(X,Y,Z,R,T,EG,LOD,CLAMP,MGV,BSE)의 현 위치값(Pulse)을 설정한다
			m_pIntegrated->nAxisPosition[nAxis] = atoi(m_pIntegrated->szYStr);

			// Z축 현재 위치값을 [mm] 단위로 계산 한다
			m_pIntegrated->dCurAxisPos[nAxis] = (double)(m_pIntegrated->nAxisPosition[nAxis]) * m_pIntegrated->dAxisMMPerPulse[nAxis];
			m_pIntegrated->dCurZPos = m_pIntegrated->dCurAxisPos[nAxis];
			bMessage = TRUE;

			// Z축 현재 위치값[mm] 를 표시한다
			memset(szData, 0x00, sizeof(szData));
			sprintf(szData, "%g", m_pIntegrated->dCurAxisPos[nAxis]);
			UsbDeviceDataInfo.nState = nAxis;
			strcpy_s(UsbDeviceDataInfo.szData, szData);

			// Z-AXIS MOVING or STOP 상태 확인
			// Z축 이동에 따른 FOCUS 변경은 STOP 상태에서만 실행한다
			if (m_pIntegrated->nBmpMovingFlag[nAxis] == 0)
			{
				// 2021.06.15 : Z축 위치에 따른 FOCUS DEGAUSSING 및 FOCUS COARSE 실행
				// OPTION : Z AXIS FOCUS LINK ( Z축 이동에 따른 FOCUS 변경 실행 )
				if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_Z_AXIS_FOCUS_LINK] == 1)
				{
					// WD 계산 : (현재 Z축 위치값 - 샘플높이) x 10
					double dNewWD = (m_pIntegrated->dCurZPos - m_dSampleHeight) * 10.0;                      // 0~500 , 0 ~ 50.0mm
					int    nNewWD = (int)dNewWD;
					if (nNewWD <= 500 && m_pIntegrated->nOLWD != nNewWD)
					{
						m_pIntegrated->nOLWD = nNewWD;
						UsbDeviceDataInfo.nData[0] = m_pIntegrated->nOLWD;                                   // WD에 따른 배율조정을 위한 Z축 위치값 0~500 (0~50mm)
						UsbDeviceDataInfo.nData[1] = m_pIntegrated->nWDOLCoarseLinear[m_pIntegrated->nOLWD]; // WD에 따른 배율조정을 위한 Focus Coarse
						UsbDeviceDataInfo.nData[2] = 1;                                                      // WD에 따른 배율조정을 실행한다

						// 2021.08.03 : 아래의 값 nWDPosition의 범위는 0~50 이므로 nOLWD의 범위 0~500와는 호환되지 않는다
						// WD POSITION 설정
						//m_pIntegrated->nWDPosition = m_pIntegrated->nOLWD;

						// FOCUS COARSE 설정
						m_pIntegrated->nFocusCoarse = m_pIntegrated->nWDOLCoarseLinear[m_pIntegrated->nOLWD];;

						// WD 값이 변동이 있으면 WD에 따른 FOCUS DEGAUSSING 및 FOCUS COARSE 실행한다
						AfxIntegratedFocusDegaussing(nNewWD);
					}
				}
				/*
				// 2021.04.21 : Z축 STOP 상태
				// OPTION : Z AXIS FOCUS LINK ( Z축 이동에 따른 FOCUS 변경 실행 )
				if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_Z_AXIS_FOCUS_LINK] == 1)
				{
					// 2021.02.25
					// 디가우징을 위한 OL값 RESET : WD에 따른 ZOOM 값이 적용되지 않아 실행 한다.
					AfxIntegratedSetOL(SEM_FOCUS_COARSE_STR, SEM_FOCUS_FINE_STR);

					// WD 계산 : (현재 Z축 위치값 - 샘플높이) x 10
					int nNewWD = (int)(m_pIntegrated->dCurZPos - m_dSampleHeight) * 10;                  // 0~500 , 0 ~ 50.0mm

					// WD 값이 0.1[mm] 이상 변동이 있으면 WD에 따른 FOCUS COARSE 실행한다
					AfxIntegratedSetWDAutoAdjustFocusCoarse(nNewWD);                                     // 새로운 WD 적용
					UsbDeviceDataInfo.nData[0] = m_pIntegrated->nOLWD;                                   // WD에 따른 배율조정을 위한 Z축 위치값 0~500 (0~50mm)
					UsbDeviceDataInfo.nData[1] = m_pIntegrated->nWDOLCoarseLinear[m_pIntegrated->nOLWD]; // WD에 따른 배율조정을 위한 Focus Coarse
					UsbDeviceDataInfo.nData[2] = 1;                                                      // WD에 따른 배율조정을 실행한다
					AfxScanBridgeSetScanRotation(m_pIntegrated->nOLWD);                                  // WD에 따른 배율조정을 위한 Scan Rotation 실행

					// 2021.02.25
					// FOCUS COARSE, FINE 재설정 : WD에 따른 ZOOM 값이 적용되지 않아 재실행 한다.
					m_pIntegrated->nFocusOldCoarse = SEM_FOCUS_COARSE_STR;
					m_pIntegrated->nFocusOldFine = 1;
					AfxIntegratedSetOL(m_pIntegrated->nWDOLCoarseLinear[m_pIntegrated->nOLWD], SEM_FOCUS_FINE_STR);
				}
				*/
			}
			break;
		}

		case IDX_R_AXIS: // R
		{
			// Motor 축(X,Y,Z,R,T,EG,LOD,CLAMP,MGV,BSE)의 현 위치값(Pulse)을 설정한다
			m_pIntegrated->nAxisPosition[nAxis] = atoi(m_pIntegrated->szYStr);
			// 현재 위치값 각도(deg) 계산 : 1step 당 회전각도 x 현재 이동Pulse(step) 갯수
			m_pIntegrated->dCurAxisPos[nAxis] = (double)(m_pIntegrated->nAxisPosition[nAxis]) * m_pIntegrated->dAxisMMPerPulse[nAxis];
			// 이동한 상대 각도
			nAngle = abs((int)(m_pIntegrated->dCurAxisPosOld[nAxis] - m_pIntegrated->dCurAxisPos[nAxis]));
			bMessage = TRUE;

			memset(szData, 0x00, sizeof(szData));
			if (m_pIntegrated->dCurAxisPos[nAxis] == 0 || m_pIntegrated->dCurAxisPos[nAxis] == 360.0)
			{
				strcpy_s(szData, "0");
			}
			else
			{
				sprintf(szData, "%g", m_pIntegrated->dCurAxisPos[nAxis]);
			}
			// R축 현재 위치값[mm] 를 표시한다
			UsbDeviceDataInfo.nState = nAxis;
			strcpy_s(UsbDeviceDataInfo.szData, szData);
			break;
		}

		case IDX_T_AXIS: // T
		{
			// Motor 축(X,Y,Z,R,T,EG,LOD,CLAMP,MGV,BSE)의 현 위치값(Pulse)을 설정한다
			m_pIntegrated->nAxisPosition[nAxis] = atoi(m_pIntegrated->szYStr);
			// 현재 기울기 각도(deg) 계산 : 1step 당 회전각도 x (현재 이동Pulse(step) 갯수 - 0각도 Pulse 갯수)
			m_pIntegrated->dCurAxisPos[nAxis] = (double)(m_pIntegrated->nAxisPosition[nAxis] - m_pIntegrated->nTiltZeroAnglePulsePos) * m_pIntegrated->dAxisMMPerPulse[nAxis];
			bMessage = TRUE;

			memset(szData, 0x00, sizeof(szData));
			if (m_pIntegrated->dCurAxisPos[nAxis] == 0)
			{
				strcpy_s(szData, "0");
			}
			else
			{
				sprintf(szData, "%g", m_pIntegrated->dCurAxisPos[nAxis]);
			}
			// T축 현재 위치값[mm] 를 표시한다
			UsbDeviceDataInfo.nState = nAxis;
			strcpy_s(UsbDeviceDataInfo.szData, szData);
			break;
		}

		//-------------------------------------------------------------------------------------
		//-------------------------------------------------------------------------------------
		//-------------------------------------------------------------------------------------

		case IDX_EG_AXIS: // EG (Extra gate valve)
		{
			// Motor 축(X,Y,Z,R,T,EG,LOD,CLAMP,MGV,BSE)의 현 위치값(Pulse)을 설정한다
			m_pIntegrated->nAxisPosition[nAxis] = atoi(m_pIntegrated->szYStr);
			// Sample 고정 위치 확인 : Extra gate valve Sample고정위치 + Extra gate valve Home 위치
			if (m_pIntegrated->nFixedPositionPulse[nAxis - MAX_MOTOR_COUNT] + m_pIntegrated->nMorePositionPulse[nAxis - MAX_MOTOR_COUNT])
			{
				nYpix = (int)(EGV_WIDTH_PIX * (double)m_pIntegrated->nAxisPosition[nAxis] / (double)(m_pIntegrated->nFixedPositionPulse[nAxis - MAX_MOTOR_COUNT] + m_pIntegrated->nMorePositionPulse[nAxis - MAX_MOTOR_COUNT]));
			}

			//최하로 내려가지 않도록 제한
			if (nYpix > EGV_WIDTH_PIX - 10) nYpix = EGV_WIDTH_PIX - 10;
			/*
			if (nYpix != m_pIntegrated->nValvePositionPulseOld[nAxis - MAX_MOTOR_COUNT])
			{
				ExtraGV_BmpUpdate(nYpix);
			}
			*/
			break;
		}

		case IDX_LOD_AXIS: // LOD     125
		{
			// Motor 축(X,Y,Z,R,T,EG,LOD,CLAMP,MGV,BSE)의 현 위치값(Pulse)을 설정한다
			m_pIntegrated->nAxisPosition[nAxis] = atoi(m_pIntegrated->szYStr);
			// Sample 고정 위치 확인 : Sample Load 고정위치 + Sample Load Home 위치
			if (m_pIntegrated->nFixedPositionPulse[nAxis - MAX_MOTOR_COUNT] + m_pIntegrated->nMorePositionPulse[nAxis - MAX_MOTOR_COUNT])
			{
				nXpix = (int)(SL_WIDTH_PIX * (double)m_pIntegrated->nAxisPosition[nAxis] / (double)(m_pIntegrated->nFixedPositionPulse[nAxis - MAX_MOTOR_COUNT] + m_pIntegrated->nMorePositionPulse[nAxis - MAX_MOTOR_COUNT]));
			}

			if (nXpix > SL_WIDTH_PIX) nXpix = SL_WIDTH_PIX;
			break;
	    }

		//---------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------

		case IDX_CLAMP_AXIS: // CLAMP
		{
			break;
		}

		case IDX_MGV_AXIS: // MGV
		{
			break;
		}

		case IDX_BSE_AXIS: // BSE
		{
			break;
		}

		case IDX_EXPOS_AXIS:  // Exchange Pos으로 이동 완료했다는 Command를 CNC5 Board가 PC로 보냄
		{
			// 그려면, PC는 VacExtraChamber Board로 다음 아래의 Command 를 보냄
			memset(szCom, 0x00, sizeof(szCom));
			strcpy_s(szCom, "VL12,1;");
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom); // Sbr Command
			break;
		}

		default:
		{
			break;
		}
	}

	// Axis Current Position 자료 전송
	switch (nAxis)
	{
	case IDX_X_AXIS: // X축 position 값 표시하기 
	case IDX_Y_AXIS: // Y축 position 값 표시하기 
	case IDX_Z_AXIS: // Z축 position 값 표시하기 
	case IDX_R_AXIS: // R축 position 값 표시하기 
	case IDX_T_AXIS: // T축 position 값 표시하기 
	{
		if (bMessage == TRUE)
		{
			if (m_hOwnerWnd != NULL)
			{
				// DEVICE MAIN SERVER
				// axis current position 값 정보 메시지 보내기
				// 2020.04.28
				REQUEST_USB_DEVICE_DATA RequestSetUsbDeviceData;
				// 초기화
				memset(&RequestSetUsbDeviceData, 0x00, sizeof(REQUEST_USB_DEVICE_DATA));
				// 데이터 설정
				if      (nAxis == IDX_X_AXIS)RequestSetUsbDeviceData.nRequestID = REQIDX_GET_USB_DEVICE_STAGE_POS_X_AXIS;
				else if (nAxis == IDX_Y_AXIS)RequestSetUsbDeviceData.nRequestID = REQIDX_GET_USB_DEVICE_STAGE_POS_Y_AXIS;
				else if (nAxis == IDX_Z_AXIS)RequestSetUsbDeviceData.nRequestID = REQIDX_GET_USB_DEVICE_STAGE_POS_Z_AXIS;
				else if (nAxis == IDX_R_AXIS)RequestSetUsbDeviceData.nRequestID = REQIDX_GET_USB_DEVICE_STAGE_POS_R_AXIS;
				else if (nAxis == IDX_T_AXIS)RequestSetUsbDeviceData.nRequestID = REQIDX_GET_USB_DEVICE_STAGE_POS_T_AXIS;
				RequestSetUsbDeviceData.nRequestData[0] = m_pIntegrated->nAxisPosition[nAxis]; // PULSE값
				RequestSetUsbDeviceData.dRequestData[0] = m_pIntegrated->dCurAxisPos[nAxis];   // 위치값(mm,deg)
				// 데이터 전송
				SendMessage(m_hOwnerWnd, UM_REQUEST_GET_USB_DATA, (WPARAM)nAxis, (LPARAM)&RequestSetUsbDeviceData);

				// 2021.07.07
				// BSE AXIS DATA
				if (nAxis == IDX_T_AXIS)
				{
					// 3축 STAGE
					if (m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_ALL_DATA_VIEW] == FALSE)
					{
						// T-AXIS 데이터를 이용하여 BSE-AXIS 데이터로 활용한다
						int nBseAxis = IDX_B_AXIS;
						m_pIntegrated->nAxisPosition[nBseAxis]  = m_pIntegrated->nAxisPosition[IDX_T_AXIS];
						m_pIntegrated->dCurAxisPos[nBseAxis]    = m_pIntegrated->dCurAxisPos[IDX_T_AXIS];
						RequestSetUsbDeviceData.nRequestID      = REQIDX_GET_USB_DEVICE_STAGE_POS_B_AXIS;
						RequestSetUsbDeviceData.nRequestData[0] = m_pIntegrated->nAxisPosition[nBseAxis]; // PULSE값
						RequestSetUsbDeviceData.dRequestData[0] = m_pIntegrated->dCurAxisPos[nBseAxis];   // 위치값(mm,deg)
						// 데이터 전송
						SendMessage(m_hOwnerWnd, UM_REQUEST_GET_USB_DATA, (WPARAM)nBseAxis, (LPARAM)&RequestSetUsbDeviceData);
					}
				}

			}
		}
		break;
	}
	}

	// 위치정보 표시
	switch (nAxis)
	{
	case IDX_X_AXIS: // X
	{
		// X축 현재 위치값[mm] 를 표시한다
		SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
		break;
	}

	case IDX_Y_AXIS: // Y
	{
		// Y축 현재 위치값[mm] 를 표시한다
		SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
		break;
	}

	case IDX_Z_AXIS: // Z
	{
		// Z축 현재 위치값[mm] 를 표시한다
		SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
		break;
	}

	case IDX_R_AXIS: // R
	{
		// R축 현재 위치값[mm] 를 표시한다
		SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
		break;
	}

	case IDX_T_AXIS: // T
	{
		// T축 현재 위치값[mm] 를 표시한다
		SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);

		// 3축 STAGE
		if (m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_ALL_DATA_VIEW] == FALSE)
		{
			// 2021.07.07
			// BSE축 현재 위치값[mm] 를 표시한다
			// T-AXIS 데이터를 이용하여 BSE-AXIS 데이터로 활용한다
			int nBseAxis = IDX_B_AXIS;
			m_pIntegrated->nAxisPosition[nBseAxis] = m_pIntegrated->nAxisPosition[IDX_T_AXIS];
			m_pIntegrated->dCurAxisPos[nBseAxis]   = m_pIntegrated->dCurAxisPos[IDX_T_AXIS];
			UsbDeviceDataInfo.nState = IDX_B_AXIS;
			SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
		}

		break;
	}

	//-------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------

	case IDX_EG_AXIS: // EG (Extra gate valve)
	{
		break;
	}

	case IDX_LOD_AXIS: // LOD     125
	{
		break;
	}

	//---------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------

	case IDX_CLAMP_AXIS: // CLAMP
	{
		break;
	}

	case IDX_MGV_AXIS: // MGV
	{
		break;
	}

	case IDX_BSE_AXIS: // BSE
	{
		break;
	}

	case IDX_EXPOS_AXIS:  // Exchange Pos으로 이동 완료했다는 Command를 CNC5 Board가 PC로 보냄
	{
		break;
	}

	default:
	{
		break;
	}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "RP","SP" -> Motor 또는 Valve Current Position 읽기 또는 쓰기 (모터 또는 밸브 현 위치값 수신 및 적용)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeRPCommand(int nWriteFlag, int nAxis, char *pszData)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Axis Position 설정 [mm],[deg]
	char szCNCData[255 + 1];
	memset(szCNCData, 0x00, sizeof(szCNCData));

	// 위치값
	double dPos_mm = 0.0;
	int nPulse = 0;

	// 정보값 저장하기 
	if (nWriteFlag == 1)
	{
		dPos_mm = atof(pszData);

		// SP Command
		switch (nAxis)
		{
		case IDX_X_AXIS:
		{
			// X축 위치값[mm] 설정하기
			int nPulse = (int)(dPos_mm * m_pIntegrated->dAxisPulsePerUnit[nAxis]);
			sprintf(szCNCData, "SP%d,%d;", nAxis, nPulse);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_Y_AXIS:
		{
			// Y축 위치값[mm] 설정하기
			int nPulse = (int)(dPos_mm * m_pIntegrated->dAxisPulsePerUnit[nAxis]);
			sprintf(szCNCData, "SP%d,%d;", nAxis, nPulse);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_Z_AXIS:
		{
			// Z축 위치값[mm] 설정하기
			int nPulse = (int)(dPos_mm * m_pIntegrated->dAxisPulsePerUnit[nAxis]);
			sprintf(szCNCData, "SP%d,%d;", nAxis, nPulse);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_R_AXIS:
		{
			// R축 위치값[mm] 설정하기
			int nPulse = (int)(dPos_mm * m_pIntegrated->dAxisPulsePerUnit[nAxis]);
			sprintf(szCNCData, "SP%d,%d;", nAxis, nPulse);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_T_AXIS:
		{
			// T축 위치값[mm] 설정하기
			int nPulse = (int)(dPos_mm * m_pIntegrated->dAxisPulsePerUnit[nAxis]);
			sprintf(szCNCData, "SP%d,%d;", nAxis, nPulse);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_B_AXIS:
		{
			// 3축 STAGE
			if (m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_ALL_DATA_VIEW] == FALSE)
			{
				// 2021.07.07
				// BSE축 위치값[mm] 설정하기
				int nBseAxis = IDX_T_AXIS;
				int nPulse = (int)(dPos_mm * m_pIntegrated->dAxisPulsePerUnit[nBseAxis]);
				sprintf(szCNCData, "SP%d,%d;", nBseAxis, nPulse);
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			}
			break;
		}
		}
	}
	else
	{
		// RP Command
		switch (nAxis)
		{
		case IDX_X_AXIS:
		{
			// X축 위치값[mm] 표시하기 
			sprintf(szCNCData, "RP%d;", nAxis);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_Y_AXIS:
		{
			// Y축 위치값[mm] 표시하기 
			sprintf(szCNCData, "RP%d;", nAxis);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_Z_AXIS:
		{
			// Z축 위치값[mm] 표시하기 
			sprintf(szCNCData, "RP%d;", nAxis);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_R_AXIS:
		{
			// R축 위치값[mm] 표시하기 
			sprintf(szCNCData, "RP%d;", nAxis);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_T_AXIS:
		{
			// T축 위치값[mm] 표시하기 
			sprintf(szCNCData, "RP%d;", nAxis);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_B_AXIS:
		{
			// 3축 STAGE
			if (m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_ALL_DATA_VIEW] == FALSE)
			{
				// 2021.07.07
				// BSE축 위치값[mm] 표시하기 
				int nBseAxis = IDX_T_AXIS;
				sprintf(szCNCData, "RP%d;", nBseAxis);
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			}
			break;
		}
		}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "RM" -> Read Maximum Width (모터 축 최대 이동거리[mm] 또는 이동각도[deg])
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeRMCommand(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// 모터 축(Axis) 계산
	int nAxis = (int)(m_pIntegrated->szXStr[0] - '0');

	if (nAxis == IDX_T_AXIS+1)
	{
		// Tilt 0도 의 실제 각도 값을 별도로 저장한다
		m_pIntegrated->nTiltZeroAnglePulsePos = atoi(m_pIntegrated->szYStr);
	}
	else
	{
		if (nAxis >= IDX_X_AXIS && nAxis <= IDX_T_AXIS)
		{
			// 모터 각 축의 최대이동거리를 Pulse 갯수 값으로 받는다
			m_pIntegrated->nAxisMaxWidthPulse[nAxis] = atoi(m_pIntegrated->szYStr);
			// 모터 각 축의 최대이동거리를 [mm] 또는 각도[deg]로 환산한다
			m_pIntegrated->dAxisMaxWidthMM[nAxis] = (double)m_pIntegrated->nAxisMaxWidthPulse[nAxis] * (double)m_pIntegrated->dAxisMMPerPulse[nAxis];
		}
		else
		{
			return RET_SUCCESS_OK;
		}
	}

	char szStr[MAX_AXIS_STR_DISPLAY_BUFFER + 1];
	char szDisplay[MAX_AXIS_STR_DISPLAY_BUFFER + 1];

	memset(szStr, 0x00, sizeof(szStr));
	memset(szDisplay, 0x00, sizeof(szDisplay));

	int nDisplay = 0;
	double dDisplay = 0.0;

	// 메시지 처리 전달용 USB Data
	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));
	BOOL bMessage = FALSE;

	// 모터 최대이동거리 또는 각도 표시형식(소수점자리수) 설정
	sprintf(szStr, "%3.1f", m_pIntegrated->dAxisMaxWidthMM[nAxis]);

	// 모터 최대 이동거리 또는 각도 표시
	switch (nAxis)
	{
		case IDX_X_AXIS:
		{
			// X축 최대이동거리[mm] 표시
			memset(szDisplay, 0x00, sizeof(szDisplay));
			sprintf(szDisplay, "%s", szStr);
			bMessage = TRUE;
			break;
		}
		case IDX_Y_AXIS:
		{
			// Y축 최대이동거리[mm] 표시
			memset(szDisplay, 0x00, sizeof(szDisplay));
			sprintf(szDisplay, "%s", szStr);
			bMessage = TRUE;
			break;
		}
		case IDX_Z_AXIS:
		{
			// Z축(WD) 최대이동거리[mm] 표시
			memset(szDisplay, 0x00, sizeof(szDisplay));
			sprintf(szDisplay, "%s", szStr);
			bMessage = TRUE;
			break;
		}
		case IDX_R_AXIS:
		{
			// R축은 최대이동거리 [각도] 값을 적용하지 않는다 (360도 회전 하기 때문)
			bMessage = FALSE;
			break;
		}
		case IDX_T_AXIS: // Read Tilt Max
		{
			// T축 최대이동거리 [각도] 표시
			// T축의 실제 최대이동거리 [각도]는 T축의 최대각도일때[Pulse]값  - 0각도일때[Pulse]값 의 이동거리[각도] 환산값이다
			memset(szDisplay, 0x00, sizeof(szDisplay));
			sprintf(szDisplay, "%s", szStr);
			bMessage = TRUE;
			break;
		}
		case IDX_T_AXIS+1: // Read Tilt TiltZeroAnglePulsePos
		{
			// Tilt 각도가 0도 일 경우 실제위치값 (예: 틸트0도 -> 실제틸트값-1.5도)
			// Tilt 0각도 실제각도 계산 및 표시
			memset(szDisplay, 0x00, sizeof(szDisplay));
			dDisplay = (double)((double)m_pIntegrated->nTiltZeroAnglePulsePos * (double)m_pIntegrated->dAxisMMPerPulse[IDX_T_AXIS]);
			m_pIntegrated->dTiltZeroAnglePosMM = dDisplay;
			sprintf(szDisplay, "%g", dDisplay);
			bMessage = TRUE;
			break;
		}
	}

	// CNC 상태 및 제어용 윈도우 핸들 확인
	if (m_hStageSetupControlWnd == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// CNC Command 설정 : 'RM' Command
	UsbDeviceDataInfo.nCommand = SBR_CMD_RM;
	// Axis 설정
	UsbDeviceDataInfo.nState = nAxis;
	// 수신된 Data String : Axis Max 이동거리[mm] 또는 각도[deg]
	strcpy_s(UsbDeviceDataInfo.szData, szDisplay);

	// 2020.04.28
	// Axis Max Width 정보 전송
	if (bMessage == TRUE)
	{
		if (m_hOwnerWnd != NULL)
		{
			// DEVICE MAIN SERVER
			// axis max mm/step 값 정보 메시지 보내기
			SendMessage(m_hOwnerWnd, UM_USB_SBR_STAGE_MAX_MM_STEP, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
		}
	}

	// 계산된 값 표시하기
	switch (nAxis)
	{
	    case IDX_X_AXIS:
	    {
	    	// X축 최대 이동거리[mm] 값 표시하기 
	    	SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
	    	break;
	    }
	    case IDX_Y_AXIS:
	    {
	    	// Y축 최대 이동거리[mm] 값 표시하기 
	    	SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
	    	break;
	    }
	    case IDX_Z_AXIS:
	    {
	    	// Z축 최대 이동거리[mm] 값 표시하기 
	    	SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
	    	break;
	    }
	    case IDX_R_AXIS:
	    {
	    	// R축은 최대이동거리 [각도] 값을 적용하지 않는다 (360도 회전 하기 때문)
	    	break;
	    }
	    case IDX_T_AXIS:
	    {
	    	// T축 최대 이동각도[deg] 값 표시하기 
	    	SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
	    	break;
	    }
	    case IDX_T_AXIS+1:
	    {
	    	// Tilt 0각도 실제각도 계산 및 표시
	    	SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)nAxis, (LPARAM)&UsbDeviceDataInfo);
	    	break;
	    }
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "RM","SM" -> Read or Write  Max Width([mm],[deg]) 값 수신 또는 송신
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeRMCommand(int nWriteFlag, int nAxis, char *pszData)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// 모터 축 RM 정보
	char szCNCData[255 + 1];
	char szCommand[20 + 1];
	memset(szCNCData, 0x00, sizeof(szCNCData));
	memset(szCommand, 0x00, sizeof(szCommand));

	// 정보값 저장하기 
	if (nWriteFlag == 1)
	{
		// SM Command
		strcpy_s(szCommand, "SM");

		// 계산된 값 표시하기
		switch (nAxis)
		{
		case IDX_X_AXIS:
		{
			// X축 최대 이동거리[mm] 값 저장하기 
			double dMax = atof(pszData);
			int nPulse = (int)(dMax * m_pIntegrated->dAxisPulsePerUnit[nAxis]);
			m_pIntegrated->nAxisMaxWidthPulse[nAxis] = nPulse;
			sprintf(szCNCData, "%s%d,%d;", szCommand, nAxis, nPulse);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_Y_AXIS:
		{
			// Y축 최대 이동거리[mm] 값 저장하기 
			double dMax = atof(pszData);
			int nPulse = (int)(dMax * m_pIntegrated->dAxisPulsePerUnit[nAxis]);
			m_pIntegrated->nAxisMaxWidthPulse[nAxis] = nPulse;
			sprintf(szCNCData, "%s%d,%d;", szCommand, nAxis, nPulse);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_Z_AXIS:
		{
			// Z축 최대 이동거리[mm] 값 저장하기 
			double dMax = atof(pszData);
			int nPulse = (int)(dMax * m_pIntegrated->dAxisPulsePerUnit[nAxis]);
			m_pIntegrated->nAxisMaxWidthPulse[nAxis] = nPulse;
			sprintf(szCNCData, "%s%d,%d;", szCommand, nAxis, nPulse);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_T_AXIS:
		{
			// T축 최대 이동각도[deg] 값 저장하기 
			double dMax = atof(pszData);
			int nPulse = (int)(dMax * m_pIntegrated->dAxisPulsePerUnit[nAxis]);
			m_pIntegrated->nAxisMaxWidthPulse[nAxis] = nPulse;
			sprintf(szCNCData, "%s%d,%d;", szCommand, nAxis, nPulse);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_T_AXIS+1:
		{
			// T축 0도 각도[deg] 값 저장하기 
			double dZero = atof(pszData);
			int nPulse = (int)(dZero * m_pIntegrated->dAxisPulsePerUnit[IDX_T_AXIS]);
			m_pIntegrated->nTiltZeroAnglePulsePos = nPulse;
			m_pIntegrated->dTiltZeroAnglePosMM    = dZero;
			sprintf(szCNCData, "%s%d,%d;", szCommand, nAxis, nPulse);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		}
	}
	else
	{
		// RM Command
		strcpy_s(szCommand, "RM");

		// 계산된 값 표시하기
		switch (nAxis)
		{
		case IDX_X_AXIS:
		{
			// X축 최대 이동거리[mm] 값 표시하기 
			sprintf(szCNCData, "%s%d;", szCommand, nAxis);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_Y_AXIS:
		{
			// Y축 최대 이동거리[mm] 값 표시하기 
			sprintf(szCNCData, "%s%d;", szCommand, nAxis);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_Z_AXIS:
		{
			// Z축 최대 이동거리[mm] 값 표시하기 
			sprintf(szCNCData, "%s%d;", szCommand, nAxis);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_T_AXIS:
		{
			// T축 최대 이동각도[deg] 값 표시하기 
			sprintf(szCNCData, "%s%d;", szCommand, nAxis);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case IDX_T_AXIS+1:
		{
			// T축 0도 각도[deg] 값 표시하기 
			sprintf(szCNCData, "%s%d;", szCommand, nAxis);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "SM" -> Axis Max Width([mm],[deg]) & Home 이동
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSMCommand(int nAxis)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// 모터 축 RM 정보
	char szCNCData[255 + 1];
	char szCommand[20 + 1];
	memset(szCNCData, 0x00, sizeof(szCNCData));
	memset(szCommand, 0x00, sizeof(szCommand));

	// SM Command
	strcpy_s(szCommand, "SM");

	// 계산된 값 표시하기
	switch (nAxis)
	{
	case IDX_X_AXIS:
	{
		// X축 최대 이동거리[mm] 값 위치이동 
		sprintf(szCNCData, "%s%d;", szCommand, nAxis);
		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		break;
	}
	case IDX_Y_AXIS:
	{
		// Y축 최대 이동거리[mm] 값 위치이동 
		sprintf(szCNCData, "%s%d;", szCommand, nAxis);
		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		break;
	}
	case IDX_Z_AXIS:
	{
		// Z축 최대 이동거리[mm] 값 위치이동 
		sprintf(szCNCData, "%s%d;", szCommand, nAxis);
		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		break;
	}
	case IDX_T_AXIS:
	{
		// T축 최대 이동각도[deg] 값 위치이동 
		sprintf(szCNCData, "%s%d;", szCommand, nAxis);
		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		break;
	}
	case IDX_T_AXIS + 1:
	{
		// T축 0도 각도[deg] 값 위치이동 
		sprintf(szCNCData, "%s%d;", szCommand, nAxis);
		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		break;
	}
	case IDX_T_AXIS + 2:
	{
		//int nRem = m_pIntegrated->dCurAxisPos[IDX_Z_AXIS];
		int zmm = (int)m_pIntegrated->dCurAxisPos[IDX_Z_AXIS];
		if (zmm == 10.0)
		{
			// Z Axis Top Limit Switch Pulse 및 Z-Backlash 값 설정
			memset(szCNCData, 0x00, sizeof(szCNCData));
			strcpy_s(szCNCData, "ZT2;");
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);

			// 설정한 Z Axis Top Limit Switch Pulse 값 읽기
			memset(szCNCData, 0x00, sizeof(szCNCData));
			strcpy_s(szCNCData, "ZT1;");
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);

			// Z Axis Backlash 값 읽기
			memset(szCNCData, 0x00, sizeof(szCNCData));
			strcpy_s(szCNCData, "RB2;");
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		}
		else
		{
			// Z 축을 10[mm]로 설정하세요 -> 메시지박스
		}
		break;
	}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "MH" -> Axis Home Move
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeMHCommand(int nAxis)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Axis Home Move
	char szCNCData[255 + 1];
	memset(szCNCData, 0x00, sizeof(szCNCData));

	// 계산된 값 표시하기
	switch (nAxis)
	{
	case IDX_X_AXIS:
	{
		// X축 Home 이동 
		sprintf(szCNCData, "MH%d,1;", nAxis);
		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		break;
	}
	case IDX_Y_AXIS:
	{
		// Y축 Home 이동 
		sprintf(szCNCData, "MH%d,1;", nAxis);
		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		break;
	}
	case IDX_Z_AXIS:
	{
		// Z축 Home 이동 
		sprintf(szCNCData, "MH%d,1;", nAxis);
		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		break;
	}
	case IDX_R_AXIS:
	{
		// R축 Home 이동 
		sprintf(szCNCData, "MH%d,1;", nAxis);
		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		break;
	}
	case IDX_T_AXIS:
	{
		// T축 Home 이동 
		sprintf(szCNCData, "MH%d,1;", nAxis);
		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		break;
	}
	case IDX_B_AXIS:
	{
		// 3축 STAGE
		if (m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_ALL_DATA_VIEW] == FALSE)
		{
			// 2021.07.07
			// BSE축 Home 이동
			int nBseAxis = 5; // HOME일 경우 5를 사용한다.
			sprintf(szCNCData, "MH%d,1;", nBseAxis);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		}
		break;
	}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "MM" -> Axis Motion Move
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeMMCommand(int nAxis, int nPM, char *pszData, int nEcho)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Axis Motion Move
	char szCNCData[255 + 1];
	memset(szCNCData, 0x00, sizeof(szCNCData));

	// Axis Move
	switch (nAxis)
	{
	case IDX_X_AXIS:
	{
		// X축 Motion Move 
		if (nPM < 0) sprintf(szCNCData, "MM%d,-%s,%d;", nAxis, pszData, nEcho);
		else sprintf(szCNCData, "MM%d,%s,%d;", nAxis, pszData, nEcho);
		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		break;
	}
	case IDX_Y_AXIS:
	{
		// Y축 Motion Move 
		if (nPM < 0) sprintf(szCNCData, "MM%d,-%s,%d;", nAxis, pszData, nEcho);
		else sprintf(szCNCData, "MM%d,%s,%d;", nAxis, pszData, nEcho);
		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		break;
	}
	case IDX_Z_AXIS:
	{
		// Z MOVING ECHO ON/OFF
		int nZEcho = (m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_Z_MOVE_ECHO] == FALSE) ? 1 : 2;
		// Z축 Motion Move 
		if (nPM < 0) sprintf(szCNCData, "MM%d,-%s,%d;", nAxis, pszData, nZEcho);// nEcho);
		else sprintf(szCNCData, "MM%d,%s,%d;", nAxis, pszData, nZEcho);// nEcho);
		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		break;
	}
	case IDX_R_AXIS:
	{
		// R축 Motion Move 
		if (nPM < 0) sprintf(szCNCData, "MM%d,-%s,%d;", nAxis, pszData, nEcho);
		else sprintf(szCNCData, "MM%d,%s,%d;", nAxis, pszData, nEcho);
		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		break;
	}
	case IDX_T_AXIS:
	{
		// T축 Motion Move 
		if (nPM < 0) sprintf(szCNCData, "MM%d,-%s,%d;", nAxis, pszData, nEcho);
		else sprintf(szCNCData, "MM%d,%s,%d;", nAxis, pszData, nEcho);
		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		break;
	}
	case IDX_B_AXIS:
	{
		// 3축 STAGE
		if (m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_ALL_DATA_VIEW] == FALSE)
		{
			// 2021.07.07
			// BSE축 Motion Move : T-AXIS를 이용한다
			int nBseAxis = IDX_T_AXIS;
			if (nPM < 0) sprintf(szCNCData, "MM%d,-%s,%d;", nBseAxis, pszData, nEcho);
			else sprintf(szCNCData, "MM%d,%s,%d;", nBseAxis, pszData, nEcho);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		}
		break;
	}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "MM" -> Axis Motion Move
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeMMCommand(int nAxis, int nPM, char *pszData)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Axis Motion Move
	char szCNCData[255 + 1];
	memset(szCNCData, 0x00, sizeof(szCNCData));

	//int nPM = 0;
	//if (pszData != NULL)
	//{
	//	nPM = atoi(pszData);
	//}

	// Axis Move
	switch (nAxis)
	{
	case IDX_X_AXIS:
	{
		// X축 Motion Move 
		if (nPM < 0) sprintf(szCNCData, "MM%d,-%s,1;", nAxis, pszData);
		else sprintf(szCNCData, "MM%d,%s,1;", nAxis, pszData);
		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		break;
	}
	case IDX_Y_AXIS:
	{
		// Y축 Motion Move 
		if (nPM < 0) sprintf(szCNCData, "MM%d,-%s,1;", nAxis, pszData);
		else sprintf(szCNCData, "MM%d,%s,1;", nAxis, pszData);
		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		break;
	}
	case IDX_Z_AXIS:
	{
		// Z MOVING ECHO ON/OFF
		int nZEcho = (m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_Z_MOVE_ECHO] == FALSE) ? 1 : 2;
		// Z축 Motion Move 
		if (nPM < 0) sprintf(szCNCData, "MM%d,-%s,%d;", nAxis, pszData, nZEcho);
		else sprintf(szCNCData, "MM%d,%s,%d;", nAxis, pszData, nZEcho);
		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		break;
	}
	case IDX_R_AXIS:
	{
		// R축 Motion Move 
		if (nPM < 0) sprintf(szCNCData, "MM%d,-%s,1;", nAxis, pszData);
		else sprintf(szCNCData, "MM%d,%s,1;", nAxis, pszData);
		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		break;
	}
	case IDX_T_AXIS:
	{
		// T축 Motion Move 
		if (nPM < 0) sprintf(szCNCData, "MM%d,-%s,1;", nAxis, pszData);
		else sprintf(szCNCData, "MM%d,%s,1;", nAxis, pszData);
		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		break;
	}
	case IDX_B_AXIS:
	{
		// 3축 STAGE
		if (m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_ALL_DATA_VIEW] == FALSE)
		{
			// 2021.07.07
			// BSE축 Motion Move : MOVING ECHO
			int nBseAxis = IDX_T_AXIS;
			if (nPM < 0) sprintf(szCNCData, "MM%d,-%s,2;", nBseAxis, pszData);
			else sprintf(szCNCData, "MM%d,%s,2;", nBseAxis, pszData);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		}
		break;
	}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "MC" -> X-Y Beam Center Position Move
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeXYAxisCenterMoveCommand(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Axis Motion Move
	char szCNCData[255 + 1];
	memset(szCNCData, 0x00, sizeof(szCNCData));
	
	// X-Y Beam Center Position Move
	strcpy_s(szCNCData, "MC0;");

	// X-Y Beam Center Position Move
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "MC" -> Read Beam Center Pos (X,Y축의 빔 센터 위치 값 읽기 및 적용한다
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeMCCommand(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// 2021.03.31
	// MC 명령어 체계 변경 : X,Y,Z,R,T 센터값 읽기
	// "MC2,a,bbbb" : a->X('0'),Y('1'),Z('2'),R('3'),T('4'), b->위치펄스값

	// CNC 상태 및 제어용 윈도우 핸들 확인
	if (m_hStageSetupControlWnd == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 메시지 처리 전달용 USB Data
	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));

	// CNC Command 설정 : 'MC' Command
	UsbDeviceDataInfo.nCommand = SBR_CMD_MC;

	double dCentermm = 0.0;

	// "MC2" COMMAND 인지 확인한다
	int nMC2Cmd = atoi(m_pIntegrated->szXStr);
	if (nMC2Cmd != 2) return RET_SUCCESS_OK;

	// AXIS 값 적용 한다
	int nAxis = atoi(m_pIntegrated->szYStr);
	if (nAxis<IDX_X_AXIS || nAxis>IDX_T_AXIS) return RET_SUCCESS_OK;

	// AXIS 의 Beam Center Position을 Pulse 값으로 보관(적용) 한다
	int nPulse = atoi(m_pIntegrated->szDStr);

	// AXIS BEAM CENTER 값 계산 및 적용
	// Axis 설정
	UsbDeviceDataInfo.nState = nAxis;
	// AXIS Beam Center Position 의 Pulse 값 저장
	if      (nAxis == IDX_X_AXIS) m_pIntegrated->nBeamCenterXPos = nPulse;
	else if (nAxis == IDX_Y_AXIS) m_pIntegrated->nBeamCenterYPos = nPulse;
	// AXIS Beam Center Position 의 거리[mm]를 계산 한다
	dCentermm = (double)nPulse * m_pIntegrated->dAxisMMPerPulse[nAxis];
	sprintf(UsbDeviceDataInfo.szData, "%g", dCentermm);
	// AXIS Beam Center Position 의 거리[mm]를 적용 한다
	if      (nAxis == IDX_X_AXIS) m_pIntegrated->dBeamCenterXPos = dCentermm;
	else if (nAxis == IDX_Y_AXIS) m_pIntegrated->dBeamCenterYPos = dCentermm;
	// X축의 Beam Center Position의 거리[mm] 값을 표시 한다
	SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)UsbDeviceDataInfo.nState, (LPARAM)&UsbDeviceDataInfo);

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "MC" -> X,Y Beam Center Read or Write
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeMCCommand(int nWriteFlag, char *pszXData, char *pszYData)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Beam Center 정보
	char szCNCData[255 + 1];

	int nPulse = 0;
	int nAxis  = 0;
	double dCenter = 0.0;

	// 정보값 저장하기 
	if (nWriteFlag == 1)
	{
		// MC Command
		if (pszXData == NULL) return RET_SUCCESS_OK;
		if (pszYData == NULL) return RET_SUCCESS_OK;

		nAxis   = atoi(pszXData); // AXIS
		dCenter = atof(pszYData); // CENTER VALUE

		memset(szCNCData, 0x00, sizeof(szCNCData));

		if (nAxis == IDX_X_AXIS)
		{
			// X축 Beam Center
			nPulse = (int)(dCenter / m_pIntegrated->dAxisMMPerPulse[IDX_X_AXIS]);
			m_pIntegrated->nBeamCenterXPos = nPulse;
			m_pIntegrated->dBeamCenterXPos = dCenter;
		}
		else if (nAxis == IDX_Y_AXIS)
		{
			// Y축 Beam Center
			nPulse = (int)(dCenter / m_pIntegrated->dAxisMMPerPulse[IDX_Y_AXIS]);
			m_pIntegrated->nBeamCenterYPos = nPulse;
			m_pIntegrated->dBeamCenterYPos = dCenter;
		}
		else
		{
			return RET_SUCCESS_OK;
		}

		if (nAxis == 0 && dCenter == 0.0)
		{
			// H/W 현재위치를 X,Y Beam Center 값 설정
			strcpy_s(szCNCData, "MC1;");
			// PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		}
		else
		{
			// 2021.03.31
			// X,Y Beam Center 값 설정
			sprintf(szCNCData, "MC3,%d,%d;", nAxis, nPulse);
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		}
	}
	else
	{
		// 2021.03.31
		// X Beam Center 값 읽기 COMMAND 전송
		strcpy_s(szCNCData, "MC2,0;");
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
		// Y Beam Center 값 읽기 COMMAND 전송
		strcpy_s(szCNCData, "MC2,1;");
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "BF" -> Rotary Area Pulse 요청
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeGetRotaryAreaPulseCommand(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// 2021.03.31
	// Rotary Area Pulse 요청
	char szCNCData[255 + 1];
	memset(szCNCData, 0x00, sizeof(szCNCData));

	// Rotary Area Pulse 요청 COMMAND
	strcpy_s(szCNCData, "BF1;");

	// Rotary Area Pulse 요청 COMMAND 전송
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "BF" -> Rotary Area Pulse 요청
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeBFCommand(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// CNC 상태 및 제어용 윈도우 핸들 확인
	if (m_hStageSetupControlWnd == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 메시지 처리 전달용 USB Data
	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));

	// 2021.03.31
	// CNC Command 설정 : 'BF' Command
	UsbDeviceDataInfo.nCommand = SBR_CMD_BF;

	// Rotary Area Pulse Command Value
	int nCmd = atoi(m_pIntegrated->szXStr);
	// Rotary Area Pulse 값
	int nPulse = atoi(m_pIntegrated->szYStr);

	// Rotary Area Pulse 설정
	UsbDeviceDataInfo.nState = nCmd;
	sprintf(UsbDeviceDataInfo.szData, "%d", nPulse);
	// Rotary Area Pulse 값을 표시 한다
	SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)UsbDeviceDataInfo.nState, (LPARAM)&UsbDeviceDataInfo);

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "BF" -> Rotary Area Pulse 값 Write
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeBFCommand(int nWriteFlag, char *pszData)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// 2021.03.31
	// Rotary Area Pulse 설정
	char szCNCData[255 + 1];

	int nPulse = 0;

	// Rotary Area Pulse 값 설정하기 
	if (nWriteFlag == 1)
	{
		// BF Command

		if (pszData != NULL) nPulse = atoi(pszData);

		memset(szCNCData, 0x00, sizeof(szCNCData));

		// X,Y Beam Center 값 설정
		sprintf(szCNCData, "BF0,%d;", nPulse);
		// 명령어 전송
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "TS" -> Read TrackBall State (트랙볼의 현재 상태값 읽기 및 적용한다)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeTSCommand(void)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;         // Scan Bridge  Command & Data Handle
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	int nTS = atoi(m_pIntegrated->szXStr);

	switch (nTS)
	{
		case CNC_COMMAND:
		{
			// 트랙볼 명령어 (스텝모터 명령어) 표시한다
			break;
		}
		case XY_MOVING_ST:
		{
			// 트랙볼 상태 : X,Y 이동중 상태 표시한다
			m_pIntegrated->nTrackBallState = XY_MOVING_ST;
			if (m_pIntegrated->nTBControlState)
			{
				m_pIntegrated->nTBControlState = 0;
			}
			break;
		}
		case X_MOVING_ST:
		{
			// 트랙볼 상태 : X 이동중 상태 표시한다
			m_pIntegrated->nTrackBallState = X_MOVING_ST;
			if (m_pIntegrated->nTBControlState)
			{
				m_pIntegrated->nTBControlState = 0;
			}
			break;
		}
		case Y_MOVING_ST:
		{
			// 트랙볼 상태 : Y 이동중 상태 표시한다
			m_pIntegrated->nTrackBallState = Y_MOVING_ST;
			if (m_pIntegrated->nTBControlState)
			{
				m_pIntegrated->nTBControlState = 0;
			}
			break;
		}
		case TRACK_COUNT:
		{
			// 트랙볼 상태 : Image Shift 상태 표시한다
			if (m_pIntegrated->nTrackBallState != TRACK_COUNT)
			{
				m_pIntegrated->nTrackBallState = TRACK_COUNT;
				m_pIntegrated->nTBControlState = TB_IS_ACTION_STATE;
			}
			break;
		}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "TS" -> TrackBall (트랙볼의 관련 명령어 실행한다)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeTSCommand(int nWriteFlag, int nCommand, char *pszData)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// "TS" -> Trackball 관련 명령어 적용
	char szCNCData[255 + 1];
	memset(szCNCData, 0x00, sizeof(szCNCData));

	// 정보값 저장하기 
	if (nWriteFlag == 1)
	{
		// TS Command
		switch (nCommand)
		{
		case 3:
		{
			// 트랙볼
			//double dZTop_mm = atof(pszData);
			//int nPulse = (int)(dZTop_mm * m_pIntegrated->dAxisPulsePerUnit[IDX_Z_AXIS]);
			//sprintf(szCNCData, "TS0,%d;", nPulse);
			// VacBoard -> PC -> To CncBoard
			//AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		}
	}
	else
	{
		// TS Command
		switch (nCommand)
		{
		case 3: // Trackball X Direction Change
		{
			// 트랙볼 X축 방향전환(토글)
			strcpy_s(szCNCData, "TS3;");
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case 5: // Trackball X Direction Change
		{
			// 트랙볼 Y축 방향전환(토글)
			strcpy_s(szCNCData, "TS5;");
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "TC" -> Read TrackBall Command State (트랙볼의 현재 명령어 상태값 읽기 및 적용한다)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeTCCommand(void)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;         // Scan Bridge  Command & Data Handle
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	int nST = atoi(m_pIntegrated->szXStr);
	int nTCount = atoi(m_pIntegrated->szYStr);
	int nValue = 0;

	if (abs(nTCount) > 126)
	{
		nTCount = 0;
		return RET_SUCCESS_OK;
	}

	if (m_pIntegrated->nTBControlState == TB_IS_ACTION_STATE)
	{
		switch (nST)
		{
			case 0:
			{
				//----------------------------------------------------------------------------
				m_pIntegrated->nTCXBuf[m_pIntegrated->nTCXCount++] = nTCount;
				if (m_pIntegrated->nTCXCount >= MAX_TC_BUFFER) m_pIntegrated->nTCXCount = 0;
				//----------------------------------------------------------------------------
				// Image Shift X 현재 제어값 설정
				//----------------------------------------------------------------------------
				nValue = m_pIntegrated->nISXValue + nTCount;
				if (nValue > m_pIntegrated->nISXMaxValue)
				{
					nValue = m_pIntegrated->nISXMaxValue;
				}
				if (nValue < m_pIntegrated->nISXMinValue)
				{
					nValue = m_pIntegrated->nISXMinValue;
				}
				m_pIntegrated->nISXValue = nValue;
				//----------------------------------------------------------------------------
				break;
			}
			case 1:
			{
				//----------------------------------------------------------------------------
				m_pIntegrated->nTCYBuf[m_pIntegrated->nTCYCount++] = nTCount;
				if (m_pIntegrated->nTCYCount >= MAX_TC_BUFFER) m_pIntegrated->nTCYCount = 0;
				//----------------------------------------------------------------------------
				// Image Shift Y 현재 제어값 설정
				//----------------------------------------------------------------------------
				nValue = m_pIntegrated->nISYValue + nTCount;
				if (nValue > m_pIntegrated->nISYMaxValue)
				{
					nValue = m_pIntegrated->nISYMaxValue;
				}
				if (nValue < m_pIntegrated->nISYMinValue)
				{
					nValue = m_pIntegrated->nISYMinValue;
				}
				m_pIntegrated->nISYValue = nValue;
				//----------------------------------------------------------------------------
				break;
			}
		}
	}
	else
	if (m_pIntegrated->nTBControlState == TB_GA_ACTION_STATE)
	{
		switch (nST)
		{
			case 0:
			{
				//----------------------------------------------------------------------------
				// Gun Align X 현재 제어값 설정
				//----------------------------------------------------------------------------
				nValue = m_pIntegrated->nGAXValue + nTCount;
				if (nValue > m_pIntegrated->nGAXMaxValue)
				{
					nValue = m_pIntegrated->nGAXMaxValue;
				}
				if (nValue < m_pIntegrated->nGAXMinValue)
				{
					nValue = m_pIntegrated->nGAXMinValue;
				}
				m_pIntegrated->nGAXValue = nValue;
				//----------------------------------------------------------------------------
				break;
			}
			case 1:
			{
				//----------------------------------------------------------------------------
				// Gun Align Y 현재 제어값 설정
				//----------------------------------------------------------------------------
				nValue = m_pIntegrated->nGAYValue + nTCount;
				if (nValue > m_pIntegrated->nGAYMaxValue)
				{
					nValue = m_pIntegrated->nGAYMaxValue;
				}
				if (nValue < m_pIntegrated->nGAYMinValue)
				{
					nValue = m_pIntegrated->nGAYMinValue;
				}
				m_pIntegrated->nGAYValue = nValue;
				//----------------------------------------------------------------------------
				break;
			}
		}
	}
	else
	if (m_pIntegrated->nTBControlState == TB_ST_ACTION_STATE)
	{
		switch (nST)
		{
			case 0:
			{
				//----------------------------------------------------------------------------
				// Stig X 현재 제어값 설정
				//----------------------------------------------------------------------------
				m_pIntegrated->nStigXValue += nTCount;
				if (m_pIntegrated->nStigXValue > m_pIntegrated->nStigXMaxValue)
				{
					m_pIntegrated->nStigXValue = m_pIntegrated->nStigXMaxValue;
				}
				if (m_pIntegrated->nStigXValue < m_pIntegrated->nStigXMinValue)
				{
					m_pIntegrated->nStigXValue = m_pIntegrated->nStigXMinValue;
				}
				//MainScrollBarUpdate(STIGXY_BAR_MODE);
				//----------------------------------------------------------------------------
				break;
			}
			case 1:
			{
				//----------------------------------------------------------------------------
				// Stig Y 현재 제어값 설정
				//----------------------------------------------------------------------------
				m_pIntegrated->nStigYValue += nTCount;
				if (m_pIntegrated->nStigYValue > m_pIntegrated->nStigYMaxValue)
				{
					m_pIntegrated->nStigYValue = m_pIntegrated->nStigYMaxValue;
				}
				if (m_pIntegrated->nStigYValue < m_pIntegrated->nStigYMinValue)
				{
					m_pIntegrated->nStigYValue = m_pIntegrated->nStigYMinValue;
				}
				//MainScrollBarUpdate(STIGXY_BAR_MODE);
				//----------------------------------------------------------------------------
				break;
			}
		}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "TB" -> Read TrackBall Command
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeTBCommand(void)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;         // Scan Bridge  Command & Data Handle
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "BT" -> Read BlueTooth Command
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeBTCommand(void)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;         // Scan Bridge  Command & Data Handle
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Bluetooth Command Mode
	int nMode = atoi(m_pIntegrated->szXStr);
	// Bluetooth Command State (Select)
	int nST = atoi(m_pIntegrated->szYStr);

	switch (nMode)
	{
		case 1: // Scan Change
		{
			if (nST == 1)
			{
				// RED Scan
				//RedScanSpeedButtonClick(this);   // "BT,1,1;"

			}
			else if (nST == 2)
			{
				// FAST Scan
				//FastScanSpeedButtonClick(this);  // "BT,1,2;"

			}
			else if (nST == 3)
			{
				// SLOW Scan
				//SlowScanSpeedButtonClick(this);  // "BT,1,3;"

			}
			else if (nST == 4)
			{
				// PHOTO Scan
				//PhotoScanSpeedButtonClick(this); // "BT,1,4;"

			}
			else if (nST == 5)
			{
				// STOP Scan
				//FreezeSpeedButtonClick(this);    // "BT,1,5;"
			}
			break;
		}
		case 2: // Mag Change
		{
			if (nST == 1)
			{
				// 배율 높이기
				//MagnitudeCSpinButtonUpClick(this);   // "BT,2,1;"
			}
			else if (nST == 2)
			{
				// 배율 낮추기
				//MagnitudeCSpinButtonDownClick(this); // "BT,2,2;"
			}
			break;
		}
		case 3: // Focus Change
		{
			break;
		}
		case 4: // Stage Moving
		{
			break;
		}
	}

	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "LT" -> Read Limit SW Status (모터 각 축의 Limit 스위치 상태값을 읽기 및 적용한다
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeLTCommand(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// CNC 상태 및 제어용 윈도우 핸들 확인
	if (m_hStageSetupControlWnd == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 메시지 처리 전달용 USB Data
	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));
	BOOL bMessage = FALSE;

	// CNC Command 설정 : 'LT' Command
	UsbDeviceDataInfo.nCommand = SBR_CMD_LT;

	int nLimitSW = 0;
	int nLimitTYPE = 0;

	char szStr[MAX_AXIS_STR_DISPLAY_BUFFER + 1];
	memset(szStr, 0x00, sizeof(szStr));

	nLimitTYPE = (int)(m_pIntegrated->szXStr[0] - '0');

	// Home Limit Switch Check (Limit스위치를 Home스위치와 겸용으로 사용한다
	if (nLimitTYPE == 1)
	{
		nLimitSW = atoi(m_pIntegrated->szYStr);
		// 1->Limit SW 상태, 2->Home SW 상태
		UsbDeviceDataInfo.nData[10] = 1;

		// X축 Limit & Home
		if (nLimitSW & 0x01)
		{
			// X축 Limit & Home = On 상태
			m_pIntegrated->nAxisLimitHomeStatus[IDX_X_AXIS] = 1;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_X_AXIS;
			// X축 Limit & Home = On 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitHomeStatus[UsbDeviceDataInfo.nState];
		}
		else
		{
			// X축 Limit & Home = Off 상태
			m_pIntegrated->nAxisLimitHomeStatus[IDX_X_AXIS] = 0;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_X_AXIS;
			// X축 Limit & Home = Off 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitHomeStatus[UsbDeviceDataInfo.nState];
		}

		// Y축 Limit & Home
		if (nLimitSW & 0x02)
		{
			// Y축 Limit & Home = On 상태
			m_pIntegrated->nAxisLimitHomeStatus[IDX_Y_AXIS] = 1;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_Y_AXIS;
			// X축 Limit & Home = On 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitHomeStatus[UsbDeviceDataInfo.nState];
		}
		else
		{
			// Y축 Limit & Home = Off 상태
			m_pIntegrated->nAxisLimitHomeStatus[IDX_Y_AXIS] = 0;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_Y_AXIS;
			// Y축 Limit & Home = Off 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitHomeStatus[UsbDeviceDataInfo.nState];
		}

		// Z축 Limit & Home
		if (nLimitSW & 0x04)
		{
			// Z축 Limit & Home = On 상태
			m_pIntegrated->nAxisLimitHomeStatus[IDX_Z_AXIS] = 1;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_Z_AXIS;
			// Z축 Limit & Home = On 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitHomeStatus[UsbDeviceDataInfo.nState];
		}
		else
		{
			// Z축 Limit & Home = Off 상태
			m_pIntegrated->nAxisLimitHomeStatus[IDX_Z_AXIS] = 0;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_Z_AXIS;
			// Z축 Limit & Home = Off 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitHomeStatus[UsbDeviceDataInfo.nState];
		}

		// R축 Limit & Home
		if (nLimitSW & 0x08)
		{
			// R축 Limit & Home = On 상태
			m_pIntegrated->nAxisLimitHomeStatus[IDX_R_AXIS] = 1;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_R_AXIS;
			// R축 Limit & Home = On 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitHomeStatus[UsbDeviceDataInfo.nState];
		}
		else
		{
			// R축 Limit & Home = Off 상태
			m_pIntegrated->nAxisLimitHomeStatus[IDX_R_AXIS] = 0;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_R_AXIS;
			// R축 Limit & Home = Off 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitHomeStatus[UsbDeviceDataInfo.nState];
		}

		// T축 Limit & Home
		if (nLimitSW & 0x10)
		{
			// T축 Limit & Home = On 상태
			m_pIntegrated->nAxisLimitHomeStatus[IDX_T_AXIS] = 1;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_T_AXIS;
			// T축 Limit & Home = On 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitHomeStatus[UsbDeviceDataInfo.nState];
		}
		else
		{
			// T축 Limit & Home = Off 상태
			m_pIntegrated->nAxisLimitHomeStatus[IDX_T_AXIS] = 0;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_T_AXIS;
			// T축 Limit & Home = Off 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitHomeStatus[UsbDeviceDataInfo.nState];
		}

		// 2021.07.07
		// B축 Home S/W
		if (nLimitSW & 0x20)
		{
			// BSE축 Home = On 상태
			m_pIntegrated->nAxisLimitSWStatus[IDX_B_AXIS] = 1;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_B_AXIS;
			// BSE축 Home = On 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitSWStatus[UsbDeviceDataInfo.nState];
		}
		// B축 Limit S/W
		else if (nLimitSW & 0x40)
		{
			// BSE축 Limit = On 상태
			m_pIntegrated->nAxisLimitSWStatus[IDX_B_AXIS] = 10;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_B_AXIS;
			// BSE축 Limit = On 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitSWStatus[UsbDeviceDataInfo.nState];
		}
		else
		{
			// BSE축 Home & Limit = Off 상태
			m_pIntegrated->nAxisLimitSWStatus[IDX_B_AXIS] = 0;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_B_AXIS;
			// BSE축 Home = Off 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitSWStatus[UsbDeviceDataInfo.nState];
		}

		// Axis Limit & Home Switch 정보 전송
		if (bMessage == TRUE)
		{
			if (m_hOwnerWnd != NULL)
			{
				// DEVICE MAIN SERVER
				// Axis Limit & Home Switch 값 정보 메시지 보내기
				// 2020.05.04
				SendMessage(m_hOwnerWnd, UM_USB_SBR_STAGE_LIMIT_STATUS, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
			}
		}

		// Axis Limit State 표시하기 
		SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
	}

	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "RB" -> Read Backlash Pulse 값 읽기 및 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeRBCommand(void)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;         // Scan Bridge  Command & Data Handle
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// 모터 축(Axis) 설정
	int nAxis = (int)(m_pIntegrated->szXStr[0] - '0');

	switch (nAxis)
	{
		case IDX_X_AXIS:
		{
			// X축 Backlash 표시
			//MotorStageSetupForm->XBacklashEdit->Text = m_pIntegrated->szYStr;
			//MotorStageSetupForm->XBacklashEdit->Font->Color = clYellow;
			break;
		}
		case IDX_Y_AXIS:
		{
			// Y축 Backlash 표시
			//MotorStageSetupForm->YBacklashEdit->Text = m_pIntegrated->szYStr;
			//MotorStageSetupForm->YBacklashEdit->Font->Color = clYellow;
			break;
		}
		case IDX_Z_AXIS:
		{
			// Z축 Backlash 표시
			//MotorStageSetupForm->ZBacklashEdit->Text = m_pIntegrated->szYStr;
			//MotorStageSetupForm->ZBacklashEdit->Font->Color = clYellow;
			break;
		}
		case IDX_R_AXIS:
		{
			// R축 Backlash 표시
			//MotorStageSetupForm->RBacklashEdit->Text = m_pIntegrated->szYStr;
			//MotorStageSetupForm->RBacklashEdit->Font->Color = clYellow;
			break;
		}
		case IDX_T_AXIS:
		{
			// T축 Backlash 표시
			//MotorStageSetupForm->TBacklashEdit->Text = m_pIntegrated->szYStr;
			//MotorStageSetupForm->TBacklashEdit->Font->Color = clYellow;
			break;
		}
	}

	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "ZT" -> Z Top Limit Sw Pulse 값 읽기 및 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeZTCommand(void)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;         // Scan Bridge  Command & Data Handle
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// CNC 상태 및 제어용 윈도우 핸들 확인
	if (m_hStageSetupControlWnd == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 메시지 처리 전달용 USB Data
	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));
	BOOL bMessage = FALSE;

	// CNC Command 설정 : 'ZT' Command
	UsbDeviceDataInfo.nCommand = SBR_CMD_ZT;

	char szStr[MAX_AXIS_STR_DISPLAY_BUFFER + 1];
	memset(szStr, 0x00, sizeof(szStr));

	// Z Top Limit SW 상태값 읽기
	int nVal = (int)(m_pIntegrated->szXStr[0] - '0');
	double dZTtop_mm = 0.0;

	// Z축 Top Limit SW -> On 상태일 경우 
	if (nVal == 1)
	{
		// Z축 Top Limit SW -> On 상태의 위치 Pulse 값
		m_pIntegrated->nZTopLimitSwPulse = atoi(m_pIntegrated->szYStr);
		bMessage = TRUE;

		// 축(Axis)의 1[mm] 또는 1[각도] 당 이동Pulse 갯수 확인
		if (m_pIntegrated->dAxisPulsePerUnit[IDX_Z_AXIS] == 0)
		{
			dZTtop_mm = 0;
		}
		else
		{
			// 축(Axis)의 1[mm] 또는 1[각도] 당 이동Pulse 갯수 확인하여 -> Z축의 Top 위치를 [mm]로 환산한다
			dZTtop_mm = (double)m_pIntegrated->nZTopLimitSwPulse / m_pIntegrated->dAxisPulsePerUnit[IDX_Z_AXIS];
		}

		m_pIntegrated->dZTopLimitPosMM = dZTtop_mm;
		memset(szStr, 0x00, sizeof(szStr));
		sprintf(szStr, "%3.1f", dZTtop_mm);

		// Z축 Top(또는 Bottom) 위치값[mm] 를 표시한다
	    strcpy_s(UsbDeviceDataInfo.szData, szStr);

		// Z-Axis Top(또는 Bottom) 위치값[mm] 정보 전송
		if (bMessage == TRUE)
		{
			if (m_hOwnerWnd != NULL)
			{
				// DEVICE MAIN SERVER
				// Axis Limit & Home Switch 값 정보 메시지 보내기
				UsbDeviceDataInfo.nState = IDX_Z_AXIS + 1;
				// 2020.05.04
				//SendMessage(m_hOwnerWnd, UM_USB_SBR_STAGE_Z_AXIS_LIMIT, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
			}
		}

        // Z축 Top 위치값[mm] 를 표시한다
        SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
	}

	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "ZT" -> Z Top Limit Sw Pulse 값 읽기 및 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeZTCommand(int nWriteFlag, char *pszData)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;         // Scan Bridge  Command & Data Handle
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Z축 Top Limit 위치값[mm]
	char szCNCData[255 + 1];
	memset(szCNCData, 0x00, sizeof(szCNCData));

	// 정보값 저장하기 
	if (nWriteFlag == 1)
	{
		// ZT Command
		// Z축 Top Limit 위치값[mm] 저장하기
		double dZTop_mm = atof(pszData);
		int nPulse = (int)(dZTop_mm * m_pIntegrated->dAxisPulsePerUnit[IDX_Z_AXIS]);
		m_pIntegrated->dTiltZeroAnglePosMM = dZTop_mm;
		sprintf(szCNCData, "ZT0,%d;", nPulse);

		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
	}
	else
	{
		// ZT Command
		// Z축 Top Limit 위치값[mm] 표시하기 
		strcpy_s(szCNCData, "ZT1;");

		// VacBoard -> PC -> To CncBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
	}

	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "SB" -> Sampler Exchange Position Pulse 값 읽기 및 적용 (X, Y, Z, R_Load, R_Unload)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSBCommand(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// CNC 상태 및 제어용 윈도우 핸들 확인
	if (m_hStageSetupControlWnd == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 메시지 처리 전달용 USB Data
	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));
	BOOL bMessage = FALSE;

	// CNC Command 설정 : 'SB' Command
	UsbDeviceDataInfo.nCommand = SBR_CMD_SB;

	int nNum = 0;
    int nExc_sam_pul = 0;
	double dExc_sam_mm = 0.0;

	// 샘플 교환 모터 축(Axis) 
	nNum = atoi(m_pIntegrated->szXStr);
	// 샘플 교환 위치 값(Pulse)
	nExc_sam_pul = atoi(m_pIntegrated->szYStr);

	// 모터 축(Axis)
	switch (nNum)
	{
		// X
		case IDX_X_AXIS:
		{
			// X축 샘플교환 위치값[mm] 계산 = (X축 샘플교환위치[Pulse]) x (X축 1Pulse당 이동거리[mm])
			dExc_sam_mm = (double)nExc_sam_pul * m_pIntegrated->dAxisMMPerPulse[nNum];
			// X축 샘플교환 위치값[mm] 표시
			m_pIntegrated->dFixExtraSamPos[nNum] = dExc_sam_mm;
			UsbDeviceDataInfo.nState      = nNum;
			UsbDeviceDataInfo.dData[nNum] = dExc_sam_mm;
			bMessage = TRUE;
			break;
		}
		// Y
		case IDX_Y_AXIS:
		{
			UsbDeviceDataInfo.nState = nNum;
			// Y축 샘플교환 위치값[mm] 계산 = (Y축 샘플교환위치[Pulse]) x (Y축 1Pulse당 이동거리[mm])
			dExc_sam_mm = (double)nExc_sam_pul * m_pIntegrated->dAxisMMPerPulse[nNum];
			// Y축 샘플교환 위치값[mm] 표시
			m_pIntegrated->dFixExtraSamPos[nNum] = dExc_sam_mm;
			UsbDeviceDataInfo.nState      = nNum;
			UsbDeviceDataInfo.dData[nNum] = dExc_sam_mm;
			bMessage = TRUE;
			break;
		}
		// Z
		case IDX_Z_AXIS:
		{
			UsbDeviceDataInfo.nState = nNum;
			// Z축 샘플교환 위치값[mm] 계산 = (Z축 샘플교환위치[Pulse]) x (Z축 1Pulse당 이동거리[mm])
			dExc_sam_mm = (double)nExc_sam_pul * m_pIntegrated->dAxisMMPerPulse[nNum];
			// Z축 샘플교환 위치값[mm] 표시
			m_pIntegrated->dFixExtraSamPos[nNum] = dExc_sam_mm;
			UsbDeviceDataInfo.nState      = nNum;
			UsbDeviceDataInfo.dData[nNum] = dExc_sam_mm;
			bMessage = TRUE;
			break;
		}
		// R Load
		case IDX_R_AXIS:
		{
			UsbDeviceDataInfo.nState = nNum;
			// R축 샘플Load 위치값[mm] 계산 = (R축 샘플Load위치[Pulse]) x (R축 1Pulse당 이동거리[mm])
			dExc_sam_mm = (double)nExc_sam_pul * m_pIntegrated->dAxisMMPerPulse[nNum];
			// R축 샘플Load 위치값[mm] 표시
			m_pIntegrated->dFixExtraSamPos[nNum] = dExc_sam_mm;
			UsbDeviceDataInfo.nState      = nNum;
			UsbDeviceDataInfo.dData[nNum] = dExc_sam_mm;
			bMessage = TRUE;
			break;
		}
		// R Unload
		case IDX_R_AXIS+1:
		{
			UsbDeviceDataInfo.nState = nNum;
			// R축 샘플Unload 위치값[mm] 계산 = (R축 샘플Unload위치[Pulse]) x (R축 1Pulse당 이동거리[mm])
			dExc_sam_mm = (double)nExc_sam_pul * m_pIntegrated->dAxisMMPerPulse[IDX_R_AXIS];
			// R축 샘플Unload 위치값[mm] 표시
			m_pIntegrated->dFixExtraSamPos[nNum] = dExc_sam_mm;
			UsbDeviceDataInfo.nState      = nNum;
			UsbDeviceDataInfo.dData[nNum] = dExc_sam_mm;
			bMessage = TRUE;
			break;
		}
	}

	// 샘플 교환 위치 값 정보 전송
	if (bMessage == TRUE)
	{
		if (m_hOwnerWnd != NULL)
		{
			// DEVICE MAIN SERVER
			// 샘플 교환 위치 값 정보 메시지 보내기
			// 2020.05.04
			SendMessage(m_hOwnerWnd, UM_USB_SBR_STAGE_FIX_POSITION, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
		}
	}

	// 모터 축(Axis)
	switch (nNum)
	{
	// X
	case IDX_X_AXIS:
	{
		// X축 샘플교환 위치값[mm] 표시
		UsbDeviceDataInfo.nState = nNum;
		// X축 샘플교환 위치값[mm] 표시
		UsbDeviceDataInfo.dData[UsbDeviceDataInfo.nState] = m_pIntegrated->dFixExtraSamPos[UsbDeviceDataInfo.nState];
		sprintf(UsbDeviceDataInfo.szData, "%g", UsbDeviceDataInfo.dData[UsbDeviceDataInfo.nState]);
		// X축 샘플교환 위치값[mm] 표시
		SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
		break;
	}
	// Y
	case IDX_Y_AXIS:
	{
		// Y축 샘플교환 위치값[mm] 표시
		UsbDeviceDataInfo.nState = nNum;
		// Y축 샘플교환 위치값[mm] 표시
		UsbDeviceDataInfo.dData[UsbDeviceDataInfo.nState] = m_pIntegrated->dFixExtraSamPos[UsbDeviceDataInfo.nState];
		sprintf(UsbDeviceDataInfo.szData, "%g", UsbDeviceDataInfo.dData[UsbDeviceDataInfo.nState]);
		// Y축 샘플교환 위치값[mm] 표시
		SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
		break;
	}
	// Z
	case IDX_Z_AXIS:
	{
		// Z축 샘플교환 위치값[mm] 표시
		UsbDeviceDataInfo.nState = nNum;
		// Z축 샘플교환 위치값[mm] 표시
		UsbDeviceDataInfo.dData[UsbDeviceDataInfo.nState] = m_pIntegrated->dFixExtraSamPos[UsbDeviceDataInfo.nState];
		sprintf(UsbDeviceDataInfo.szData, "%g", UsbDeviceDataInfo.dData[UsbDeviceDataInfo.nState]);
		// Z축 샘플교환 위치값[mm] 표시
		SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
		break;
	}
	// R Load
	case IDX_R_AXIS:
	{
		// R축 샘플Load 위치값[mm] 표시
		UsbDeviceDataInfo.nState = nNum;
		// R축 샘플Load 위치값[mm] 표시
		UsbDeviceDataInfo.dData[UsbDeviceDataInfo.nState] = m_pIntegrated->dFixExtraSamPos[UsbDeviceDataInfo.nState];
		sprintf(UsbDeviceDataInfo.szData, "%g", UsbDeviceDataInfo.dData[UsbDeviceDataInfo.nState]);
		// R축 샘플Load 위치값[mm] 표시
		SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
		break;
	}
	// R Unload
	case IDX_R_AXIS + 1:
	{
		// R축 샘플Unload 위치값[mm] 표시
		UsbDeviceDataInfo.nState = nNum;
		// R축 샘플Unload 위치값[mm] 표시
		UsbDeviceDataInfo.dData[UsbDeviceDataInfo.nState] = m_pIntegrated->dFixExtraSamPos[UsbDeviceDataInfo.nState];
		sprintf(UsbDeviceDataInfo.szData, "%g", UsbDeviceDataInfo.dData[UsbDeviceDataInfo.nState]);
		// R축 샘플Unload 위치값[mm] 표시
		SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
		break;
	}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "SB" -> Sample Position 관련 명령어 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSBCommand(int nWriteFlag, int nCommand, char *pszData1, char *pszData2, char *pszData3)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// "SB" -> Sample Position 관련 명령어 적용
	char szCNCData[255 + 1];
	memset(szCNCData, 0x00, sizeof(szCNCData));

	// 정보값 저장하기 
	if (nWriteFlag == 1)
	{
		// SB Command
		switch (nCommand)
		{
		case 15:
		case 16:
		case 17:
		{
			double dXExtra_mm = 0.0;
			double dYExtra_mm = 0.0;
			double dZExtra_mm = 0.0;
			double dRLExtra_mm = 0.0;
			double dRUExtra_mm = 0.0;
			long lPulse = 0L;

			// X,Y,Z-Axis Fix Extra Sample Position 값 설정
			if (pszData1 != NULL) dXExtra_mm = atof(pszData1);
			if (pszData2 != NULL) dYExtra_mm = atof(pszData2);
			if (pszData3 != NULL) dZExtra_mm = atof(pszData3);

			// Position 값 확인
			if (dXExtra_mm == 0.0 || dYExtra_mm == 0 || dZExtra_mm == 0)
			{
				// 현재 위치를 X,Y,Z Fix Extra Sample Position 으로 설정
				strcpy_s(szCNCData, "SB6;");
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			} 
			else
			{
				// X-Axis Fix Extra Sample Position 설정
				lPulse = (long)(dXExtra_mm / m_pIntegrated->dAxisMMPerPulse[IDX_X_AXIS]);
				sprintf(szCNCData, "SB15,%d;", lPulse);
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);

				// Y-Axis Fix Extra Sample Position 설정
				lPulse = (long)(dYExtra_mm / m_pIntegrated->dAxisMMPerPulse[IDX_Y_AXIS]);
				sprintf(szCNCData, "SB16,%d;", lPulse);
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);

				// Z-Axis Fix Extra Sample Position 설정
				lPulse = (long)(dZExtra_mm / m_pIntegrated->dAxisMMPerPulse[IDX_Z_AXIS]);
				sprintf(szCNCData, "SB16,%d;", lPulse);
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			}
			break;
		}
		case 18:
		{
			double dRExtra_mm = 0.0;
			long lPulse = 0L;

			// R-Axis Fix Extra Load Sample Position 값 설정
			if (pszData1 != NULL) dRExtra_mm = atof(pszData1);

			// Position 값 확인
			if (dRExtra_mm == 0.0)
			{
				// 현재 위치를 R-Axis Fix Extra Load Sample Position 으로 설정
				strcpy_s(szCNCData, "SB9;");
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			}
			else
			{
				// R-Axis Fix Extra Load Sample Position 설정
				lPulse = (long)((double)(dRExtra_mm+360.0) / m_pIntegrated->dAxisMMPerPulse[IDX_R_AXIS]);
				sprintf(szCNCData, "SB18,%d;", lPulse);
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			}
			break;
		}
		case 19:
		{
			double dRExtra_mm = 0.0;
			long lPulse = 0L;

			// R-Axis Fix Extra Unload Sample Position 값 설정
			if (pszData1 != NULL) dRExtra_mm = atof(pszData1);

			// Position 값 확인
			if (dRExtra_mm == 0.0)
			{
				// 현재 위치를 R-Axis Fix Extra Unload Sample Position 으로 설정
				strcpy_s(szCNCData, "SB10;");
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			}
			else
			{
				// R-Axis Fix Extra Unload Sample Position 설정
				lPulse = (long)((double)(dRExtra_mm+360.0) / m_pIntegrated->dAxisMMPerPulse[IDX_R_AXIS]);
				sprintf(szCNCData, "SB19,%d;", lPulse);
				// VacBoard -> PC -> To CncBoard
				AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			}
			break;
		}
		}
	}
	else
	{
		// SB Command
		switch (nCommand)
		{
		case 7: // Go Exchange Position
		{
			// Exchange Sample Position 으로 이동
			strcpy_s(szCNCData, "SB7;");
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case 13: // Go R-Axis Load Sample Position
		{
			// R-Axis Load Sample Position 으로 이동
			strcpy_s(szCNCData, "SB13;");
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case 14: // Go R-Axis Unload Sample Position
		{
			// R-Axis Unload Sample Position 으로 이동
			strcpy_s(szCNCData, "SB14;");
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case 8: // X,Y,Z Axis Fix Extra Sample Positon 값 읽기 명령
		{
			// X,Y,Z Fix Extra Sample Position
			strcpy_s(szCNCData, "SB8;");
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case 11: // R-Axis Fix Extra Load Sample Positon 값 읽기 명령
		{
			// R-Axis Fix Extra Load Sample Position
			strcpy_s(szCNCData, "SB11;");
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		case 12: // R-Axis Fix Extra Unload Sample Positon 값 읽기 명령
		{
			// R-Axis Fix Extra Unload Sample Position
			strcpy_s(szCNCData, "SB12;");
			// VacBoard -> PC -> To CncBoard
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData);
			break;
		}
		}
	}

	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "LS" -> Read Limit SW Stop Status 값 읽기 및 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeLSCommand(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// CNC 상태 및 제어용 윈도우 핸들 확인
	if (m_hStageSetupControlWnd == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 메시지 처리 전달용 USB Data
	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));
	BOOL bMessage = FALSE;

	// CNC Command 설정 : 'LS' Command
	UsbDeviceDataInfo.nCommand = SBR_CMD_LS;

	int nEmergency_val = 0;
	int nLimit_type = 0;

	// Limit SW Stop ?
	nLimit_type = (int)(m_pIntegrated->szXStr[0] - '0');

	// Limit SW Stop ?
	if (nLimit_type == 0)
	{
		// 모터 Stop 상태 값 읽기 및 확인
		nEmergency_val = atoi(m_pIntegrated->szYStr);

		// X축 Limit & Home
		if (nEmergency_val & 0x01)
		{
			// X축 Limit & Home = On 상태
			m_pIntegrated->nAxisLimitSWStatus[IDX_X_AXIS] = 1;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_X_AXIS;
			// X축 Limit & Home = On 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitSWStatus[UsbDeviceDataInfo.nState];
		}
		else
		{
			// X축 Limit & Home = Off 상태
			m_pIntegrated->nAxisLimitSWStatus[IDX_X_AXIS] = 0;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_X_AXIS;
			// X축 Limit & Home = Off 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitSWStatus[UsbDeviceDataInfo.nState];
		}

		// Y축 Limit & Home
		if (nEmergency_val & 0x02)
		{
			// Y축 Limit & Home = On 상태
			m_pIntegrated->nAxisLimitSWStatus[IDX_Y_AXIS] = 1;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_Y_AXIS;
			// X축 Limit & Home = On 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitSWStatus[UsbDeviceDataInfo.nState];
		}
		else
		{
			// Y축 Limit & Home = Off 상태
			m_pIntegrated->nAxisLimitSWStatus[IDX_Y_AXIS] = 0;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_Y_AXIS;
			// Y축 Limit & Home = Off 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitSWStatus[UsbDeviceDataInfo.nState];
		}

		// Z축 Limit & Home
		if (nEmergency_val & 0x04)
		{
			// Z축 Limit & Home = On 상태
			m_pIntegrated->nAxisLimitSWStatus[IDX_Z_AXIS] = 1;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_Z_AXIS;
			// Z축 Limit & Home = On 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitSWStatus[UsbDeviceDataInfo.nState];
		}
		else
		{
			// Z축 Limit & Home = Off 상태
			m_pIntegrated->nAxisLimitSWStatus[IDX_Z_AXIS] = 0;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_Z_AXIS;
			// Z축 Limit & Home = Off 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitSWStatus[UsbDeviceDataInfo.nState];
		}

		// R축 Limit & Home
		if (nEmergency_val & 0x08)
		{
			// R축 Limit & Home = On 상태
			m_pIntegrated->nAxisLimitSWStatus[IDX_R_AXIS] = 1;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_R_AXIS;
			// R축 Limit & Home = On 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitSWStatus[UsbDeviceDataInfo.nState];
		}
		else
		{
			// R축 Limit & Home = Off 상태
			m_pIntegrated->nAxisLimitSWStatus[IDX_R_AXIS] = 0;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_R_AXIS;
			// R축 Limit & Home = Off 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitSWStatus[UsbDeviceDataInfo.nState];
		}

		// T축 Limit & Home
		if (nEmergency_val & 0x10)
		{
			// T축 Limit & Home = On 상태
			m_pIntegrated->nAxisLimitSWStatus[IDX_T_AXIS] = 1;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_T_AXIS;
			// T축 Limit & Home = On 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitSWStatus[UsbDeviceDataInfo.nState];
		}
		else
		{
			// T축 Limit & Home = Off 상태
			m_pIntegrated->nAxisLimitSWStatus[IDX_T_AXIS] = 0;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_T_AXIS;
			// T축 Limit & Home = Off 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitSWStatus[UsbDeviceDataInfo.nState];
		}

		// 2021.07.07
		// B축 Home S/W
		if (nEmergency_val & 0x20)
		{
			// BSE축 Home = On 상태
			m_pIntegrated->nAxisLimitSWStatus[IDX_B_AXIS] = 1;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_B_AXIS;
			// BSE축 Home = On 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitSWStatus[UsbDeviceDataInfo.nState];
		}
		// B축 Limit S/W
		else if (nEmergency_val & 0x40)
		{
			// BSE축 Limit = On 상태
			m_pIntegrated->nAxisLimitSWStatus[IDX_B_AXIS] = 10;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_B_AXIS;
			// BSE축 Limit = On 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitSWStatus[UsbDeviceDataInfo.nState];
		}
		else
		{
			// BSE축 Home = Off 상태
			m_pIntegrated->nAxisLimitSWStatus[IDX_B_AXIS] = 0;
			bMessage = TRUE;
			// Axis 설정
			UsbDeviceDataInfo.nState = IDX_B_AXIS;
			// BSE축 Home = Off 상태
			UsbDeviceDataInfo.nData[UsbDeviceDataInfo.nState] = m_pIntegrated->nAxisLimitSWStatus[UsbDeviceDataInfo.nState];
		}


		// Limit & Home Switch 값 정보 전송
		if (bMessage == TRUE)
		{
			if (m_hOwnerWnd != NULL)
			{
				// DEVICE MAIN SERVER
				// Limit & Home Switch 값 정보 메시지 보내기
				// 2020.05.04
				SendMessage(m_hOwnerWnd, UM_USB_SBR_STAGE_LIMIT_STATUS, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
			}
		}

		// Axis Limit State 표시하기 
		SendMessage(m_hStageSetupControlWnd, UM_USB_SBR_CNC_STATE, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "EC" -> Echo Command ( STAGE COMMAND ECHO ) 값 읽기 및 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeECCommand(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// CNC 상태 및 제어용 윈도우 핸들 확인
	if (m_hStageSetupControlWnd == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 메시지 처리 전달용 USB Data
	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));
	BOOL bMessage = FALSE;

	// Command 설정 : 'EC' Command
	bMessage = TRUE;
	UsbDeviceDataInfo.nCommand = SBR_CMD_EC;
	strcpy_s(UsbDeviceDataInfo.szData, m_pIntegrated->szXStr);

	// Echo Command 값 정보 전송
	if (bMessage == TRUE)
	{
		if (m_hOwnerWnd != NULL)
		{
			// DEVICE MAIN SERVER
			// Echo Command값 정보 메시지 보내기
			// 2020.05.04
			//SendMessage(m_hOwnerWnd, UM_USB_SBR_STAGE_ECHO_COMMAND, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
		}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "VR" -> H/W Version String 값 읽기 및 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeVRCommand(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// 메시지 처리 전달용 USB Data
	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));
	BOOL bMessage = FALSE;

	// Command 설정 : 'VR' Command
	bMessage = TRUE;
	UsbDeviceDataInfo.nCommand = SBR_CMD_VR;
	strcpy_s(UsbDeviceDataInfo.szData, m_pIntegrated->szXStr);

	// H/W Version 값 정보 전송
	if (bMessage == TRUE)
	{
		if (m_hOwnerWnd != NULL)
		{
			// DEVICE MAIN SERVER
			// H/W Version 값 정보 메시지 보내기
			// 2020.05.04
			//SendMessage(m_hOwnerWnd, UM_USB_SBR_HW_VERSION_DATA, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
		}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : "UL" -> Sample Load / Unload String 값 읽기 및 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
// "UL0,00" --> WAIT STEP
// "UL0,01" --> IN  CHECK STEP
// "UL0,02" --> OUT CHECK STEP
// "UL0,03" --> IN_STEP0
// "UL0,04" --> IN_STEP1
// "UL0,05" --> IN_STEP2
// "UL0,06" --> IN_STEP3
// "UL0,07" --> TIME_STEP
// "UL0,08" --> OUT_STEP0
// "UL0,09" --> OUT_STEP1
// "UL0,10" --> OUT_STEP2
// "UL0,11" --> OUT_STEP3
// "UL0,12" --> OUT_STEP4
//------------------------------------
// "UL1,00" --> UL_WAIT
// "UL1,01" --> UL_LOADING
// "UL1,02" --> UL_UNLOADING
// "UL1,03" --> UL_LOADED
// "UL1,04" --> UL_UNLOADED
// "UL1,05" --> UL_FAIL_IN_STEP0
// "UL1,06" --> UL_FAIL_IN_STEP1
// "UL1,07" --> UL_FAIL_IN_STEP2
// "UL1,08" --> UL_FAIL_IN_STEP3
// "UL1,09" --> UL_FAIL_OUT_STEP0
// "UL1,10" --> UL_FAIL_OUT_STEP1
// "UL1,11" --> UL_FAIL_OUT_STEP2
// "UL1,12" --> UL_FAIL_OUT_STEP3
// "UL1,13" --> UL_FAIL_OUT_STEP4
//------------------------------------
// "UL2,00" --> REQUEST from PC : STEP  REQUEST
// "UL2,01" --> REQUEST from PC : STATE REQUEST
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeULCommand(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// 메시지 처리 전달용 USB Data
	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));
	BOOL bMessage = FALSE;

	// Command 설정 : 'UL' Command
	bMessage = TRUE;
	UsbDeviceDataInfo.nCommand = SBR_CMD_UL;

	// Command
	strcpy_s(UsbDeviceDataInfo.szData, m_pIntegrated->szComStr);
	// X Str Data
	if ((int)strlen(m_pIntegrated->szXStr) > 0)
	{
		strcat_s(UsbDeviceDataInfo.szData, ",");
		strcat_s(UsbDeviceDataInfo.szData, m_pIntegrated->szXStr);
	}
	// Y Str Data
	if ((int)strlen(m_pIntegrated->szYStr) > 0)
	{
		strcat_s(UsbDeviceDataInfo.szData, ",");
		strcat_s(UsbDeviceDataInfo.szData, m_pIntegrated->szYStr);
	}
	// D Str Data
	if ((int)strlen(m_pIntegrated->szDStr) > 0)
	{
		strcat_s(UsbDeviceDataInfo.szData, ",");
		strcat_s(UsbDeviceDataInfo.szData, m_pIntegrated->szDStr);
	}
	// S Str Data
	if ((int)strlen(m_pIntegrated->szSStr) > 0)
	{
		strcat_s(UsbDeviceDataInfo.szData, ",");
		strcat_s(UsbDeviceDataInfo.szData, m_pIntegrated->szSStr);
	}
	strcat_s(UsbDeviceDataInfo.szData, ";");

	// H/W Version 값 정보 전송
	if (bMessage == TRUE)
	{
		if (m_hOwnerWnd != NULL)
		{
			// DEVICE MAIN SERVER
			// Sample Load / Unload 값 정보 메시지 보내기
			// 2021.03.10
			SendMessage(m_hOwnerWnd, UM_USB_SBR_STAGE_BMP_POSITION, (WPARAM)0, (LPARAM)&UsbDeviceDataInfo);
		}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Axis All Stop 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeASCommand(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// X, Y, Z, R, T 축 이동 중지
	char szCNCData[255 + 1];
	memset(szCNCData, 0x00, sizeof(szCNCData));

	strcpy_s(szCNCData, "ST");

	// VacBoard -> PC -> To CncBoard
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData, 0x1F);

	// VacBoard -> PC -> To CncBoard
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCNCData, 0x00);

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Power Off Command 전송 (명령어전송)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgePowerOff(int nMode)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// PS : Position Save to Eeprom
	// SB : Set Backlash Pulse / Set Exchange Sample Position Pulse 으로 변경   
	//      "SB0,111;"
	//      "SB1,222;"
	//      "SB2,333;"
	//      "SB3,444;"
	//      "SB6;" 을 PC에서 보내면, 현재의 X,Y,Z 위치를 Exchange Sample Position으로 저장  
	switch (nMode)
	{
	    case DEF_PROGRAM_EXIT_CANCEL:
	    {
		    // 프로그램 종료 취소
		    break;
	    }
	    case DEF_PROGRAM_EXIT_AXIS:
		{
			//-------------------------------------------------------------------
			// HV DISABLED
			//-------------------------------------------------------------------
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RG0,1;"); // GUN  HV DISABLED
			Sleep(100);
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RG1,1;"); // PMT  HV DISABLED
			Sleep(100);
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RG2,1;"); // SCIN HV DISABLED
			Sleep(100);
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RG3,1;"); // COLL HV DISABLED
			Sleep(100);

			//-------------------------------------------------------------------
			// Scan Bridge 장치가 연결되어 있다면
			// StageBoard : axis position 만 저장
			//-------------------------------------------------------------------
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "PS1;");
			Sleep(100);
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SB0;");
			Sleep(100);
			break;
		}
		case DEF_PROGRAM_EXIT_POWEROFF:
		{
			//-------------------------------------------------------------------
			// HV DISABLED
			//-------------------------------------------------------------------
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RG0,1;"); // GUN  HV DISABLED
			Sleep(100);
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RG1,1;"); // PMT  HV DISABLED
			Sleep(100);
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RG2,1;"); // SCIN HV DISABLED
			Sleep(100);
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RG3,1;"); // COLL HV DISABLED
			Sleep(100);

			//-------------------------------------------------------------------
			// Scan Bridge 장치가 연결되어 있다면
			// Save axis position & SEM Power Off
			//-------------------------------------------------------------------
			// Stage Board : Save axis position
			//-------------------------------------------------------------------
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "PS1;"); // Sbr Command
			Sleep(100);
			//-------------------------------------------------------------------
			// SEM Power Off ( Shutdown )
			//-------------------------------------------------------------------
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "PD;");  // Sbr Command
			Sleep(100);
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SB0;"); // Sbr Command
			Sleep(100);
			//-------------------------------------------------------------------
			break;
		}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Left<->Right Mirro 이미지 (좌우 반전)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeLRMirror(int nMode)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	m_pIntegrated->nLRMirror = nMode;

	if (m_pIntegrated->nLRMirror == 0)
	{
		m_pIntegrated->nSbrCommand |= XSCAN_INVERSE_LOW;
	}
	else
	{
		m_pIntegrated->nSbrCommand |= XSCAN_INVERSE_HIGH;
	}

	// 단일 명령어 및 데이터 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSbrCommand); // Sbr Command

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Top<->Bottom Mirro 이미지 (상하 반전)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeTBMirror(int nMode)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	m_pIntegrated->nTBMirror = nMode;

	if (m_pIntegrated->nTBMirror == 0)
	{
		m_pIntegrated->nSbrCommand |= YSCAN_INVERSE_LOW;
	}
	else
	{
		m_pIntegrated->nSbrCommand |= YSCAN_INVERSE_HIGH;
	}

	// 단일 명령어 및 데이터 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSbrCommand); // Sbr Command

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : XY Magnification Image Calibration -> X(Hor)-Amp 값 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetXImageAmp(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// X Image Amp
	// 문자 명령어 및 데이터 전송
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SR6,", m_pIntegrated->nXScanAmpVal[m_pIntegrated->nScanMode]); // X Scan Amp

	return RET_SUCCESS_OK;
}
int AfxScanBridgeSetXImageAmpApply(int nAmp)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// X Image Amp
	// 문자 명령어 및 데이터 전송
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SR6,", nAmp); // X Scan Amp

	return RET_SUCCESS_OK;
}
int AfxScanBridgeSetXImageAmp(int nXImageAmp)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// X Image Amp
	m_pIntegrated->nXImageAmp = nXImageAmp;
	m_pIntegrated->nXScanAmpVal[m_pIntegrated->nScanMode] = m_pIntegrated->nXImageAmp;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : XY Magnification Image Calibration -> X(Hor)-Offset 값 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetXImageOffset(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// X Image Offset
	// 문자 명령어 및 데이터 전송
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SR7,", m_pIntegrated->nXScanOffset[m_pIntegrated->nScanMode]); // X Scan Offset

	return RET_SUCCESS_OK;
}
int AfxScanBridgeSetXImageOffsetApply(int nOffset)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// X Image Offset
	// 문자 명령어 및 데이터 전송
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SR7,", nOffset); // X Scan Offset

	return RET_SUCCESS_OK;
}
int AfxScanBridgeSetXImageOffset(int nXImageOffset)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// X Image Offset
	m_pIntegrated->nXImageOffset = nXImageOffset;
	m_pIntegrated->nXScanOffset[m_pIntegrated->nScanMode] = m_pIntegrated->nXImageOffset;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : XY Magnification Image Calibration -> Y(Ver)-Amp 값 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetYImageAmp(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Y Image Amp
	// 문자 명령어 및 데이터 전송
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SR8,", m_pIntegrated->nYScanAmpVal[m_pIntegrated->nScanMode]); // Y Scan Amp

	return RET_SUCCESS_OK;
}
int AfxScanBridgeSetYImageAmpApply(int nAmp)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Y Image Amp
	// 문자 명령어 및 데이터 전송
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SR8,", nAmp); // Y Scan Amp

	return RET_SUCCESS_OK;
}
int AfxScanBridgeSetYImageAmp(int nYImageAmp)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Y Image Amp
	m_pIntegrated->nYImageAmp = nYImageAmp;
	m_pIntegrated->nYScanAmpVal[m_pIntegrated->nScanMode] = m_pIntegrated->nYImageAmp;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : XY Magnification Image Calibration -> Y(Ver)-Offset 값 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetYImageOffset(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Y Image Offset
	// 문자 명령어 및 데이터 전송
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SR9,", m_pIntegrated->nYScanOffset[m_pIntegrated->nScanMode]); // Y Scan Offset

	return RET_SUCCESS_OK;
}
int AfxScanBridgeSetYImageOffsetApply(int nOffset)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Y Image Offset
	// 문자 명령어 및 데이터 전송
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SR9,", nOffset); // Y Scan Offset

	return RET_SUCCESS_OK;
}
int AfxScanBridgeSetYImageOffset(int nYImageOffset)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Y Image Offset
	m_pIntegrated->nYImageOffset = nYImageOffset;
	m_pIntegrated->nYScanOffset[m_pIntegrated->nScanMode] = m_pIntegrated->nYImageOffset;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge :  Frame/sec 값에 따라 ScanClk의 주파수만 바꾼다.
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetScanClockFramePerSec(void)
{
	// Scan Clock(주파수) 변경 및 X,YScan 기본파형 발생
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	int nSM = m_pIntegrated->nScanMode; // Scan Mode

	//m_pIntegrated->nFrameSecVal[nSM]  = m_pIntegrated->nFrameSec[nSM];  // Frame/sec
	//m_pIntegrated->nXScanUpNum[nSM]   = m_pIntegrated->nXScanUp;        // X Scan Up
	//m_pIntegrated->nXScanDownNum[nSM] = m_pIntegrated->nXBlankWidth;    // X Scan Down
	//m_pIntegrated->nYScanUpNum[nSM]   = m_pIntegrated->nYScanUp;        // Y Scan Up
	//m_pIntegrated->nYScanDownNum[nSM] = m_pIntegrated->nYBlankWidth;    // Y Scan Down

	WORD wCom_Buf[TMP_STRING_LENGTH+1];
	memset(wCom_Buf, 0x00, sizeof(wCom_Buf));

	double dFrame  = 0.0;
	int nPhase_inc = 0;
	int nScan_clk  = 0;

	__int64 nPhase_inc64 = 0;

	//--------------------------------------------------------------------------
	// Scan Clock 변경
	//--------------------------------------------------------------------------
	dFrame = (double)(m_pIntegrated->nFrameSecVal[nSM]) * 0.001;
	dFrame = (double)(m_pIntegrated->nXScanUpNum[nSM] + m_pIntegrated->nXScanDownNum[nSM]) * (double)(m_pIntegrated->nYScanUpNum[nSM] + m_pIntegrated->nYScanDownNum[nSM]) * dFrame;
	nScan_clk = (int)dFrame;

	///////////////////////////////////////////////////////////////////////////////////
	// 2021.07.29
	// SCAN CLOCK  ( 32Bits, 48MHz ) --> ( 48Bits, 100MHz) 로 변경하여 계산 적용
	///////////////////////////////////////////////////////////////////////////////////
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_SCAN_CLOCK_48] == 1)
	{
		// SCAN CLOCK 48Bits, 100MHz
	    //--------------------------------------------------------------------------
	    // 2021.07.29
	    // 추가옵션사항 : ( ScanClk * 2^32 / 48[MHz] ) --> ( ScanClk * 2^48 / 100[MHz] )
	    //--------------------------------------------------------------------------
	    nPhase_inc64 = (__int64)(nScan_clk * (Exp2E48 / 100000000));
	    wCom_Buf[0]  = cWR_FDDS_LOW;	   wCom_Buf[1] = (WORD)(nPhase_inc64 & 0x000000000000FFFF); nPhase_inc64 = nPhase_inc64 >> 16;
	    wCom_Buf[2]  = cWR_FDDS_HIGH;      wCom_Buf[3] = (WORD)(nPhase_inc64 & 0x000000000000FFFF); nPhase_inc64 = nPhase_inc64 >> 16;
	    wCom_Buf[4]  = cWR_FDDS_HIGH48;    wCom_Buf[5] = (WORD)(nPhase_inc64 & 0x000000000000FFFF);
	    //--------------------------------------------------------------------------
	    AfxFT232HPortSendMultiCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, wCom_Buf, 6); // Sbr Scan Clock Data 전송
	    //--------------------------------------------------------------------------
	}
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	else
	{
		// SCAN CLOCK 32Bits, 48MHz
		nPhase_inc64 = (__int64)(nScan_clk * Exp2E32 / 48000000);
		nPhase_inc   = (__int32)(nPhase_inc64);
		//--------------------------------------------------------------------------
		wCom_Buf[0] = cWR_FDDS_LOW;	 wCom_Buf[1] = nPhase_inc & 0x0000FFFF;
		wCom_Buf[2] = cWR_FDDS_HIGH; wCom_Buf[3] = nPhase_inc >> 16;
		//--------------------------------------------------------------------------
		AfxFT232HPortSendMultiCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, wCom_Buf, 4); // Sbr Scan Clock Data 전송
		//--------------------------------------------------------------------------
	}
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	// Display
	//ScanClkEdit->Text = IntToStr(scan_clk);
	//LineFreqEdit->Text = IntToStr((YScanUpNum[sm] + YScanDownNum[sm]) *  FrameSec[sm] / 1000);

	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : GUN HV SMPS ON
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeGunHvSMPSOn(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// HV SMPS ON
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "HV1;");   // Sbr Data 전송
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SB5,1;"); // ScanBridgeBoard -> CncVacBoard (EM40)

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : GUN HV SMPS OFF
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeGunHvSMPSOff(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

    // HV SMPS OFF
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "HV0;");   // Sbr Data 전송
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SB5,0;"); // ScanBridgeBoard -> CncVacBoard (EM40)

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : GUN HV ON (30kV, 3.5kV, 4V)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeGunHVOn(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// GUN VALVE : OPEN
	//AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "HV1;");   // Sbr Data 전송

	// SpellMan GUN HV ON
	AfxScanBridgeSpellmanGunHVOn();

	return RET_SUCCESS_OK;
}
int AfxScanBridgeSpellmanGunHVOn(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// SpellMan GUN HV ON
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RG0,0;"); // Sbr Data 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : GUN HV OFF (30kV, 3.5kV, 4V)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeGunHVOff(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// GUN VALVE : CLOSE
	//AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "HV0;");   // Sbr Data 전송

	// SpellMan GUN HV OFF
	AfxScanBridgeSpellmanGunHVOff();

	return RET_SUCCESS_OK;
}
int AfxScanBridgeSpellmanGunHVOff(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// SpellMan GUN HV OFF
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RG0,1;"); // Sbr Data 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Set GUN HV Index Value (GUN HV 인덱스를 이용한 전압(HV)값 설정하기)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetGunHVIndex(int nIndex)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// GUN HV 값 설정하기
	// GUN HV : 32개, 30[kV] ~ 0.5[kV]
	// "AV"에 값을 설정하기 위해서는 원하는 GunHV에 나누기 10을 사용하여 설정한다.
	// 예) 30kV -> 3000, 20kV -> 2000, 1000V -> 100, 500 -> 50 으로 설정.
	int    nValue   = m_nGunHVTable[nIndex];
	double dVoltage = (double)(nValue / 10);
	int    nVoltage = (int)(dVoltage);
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "AV", nVoltage);

	// DEVICE SERVER 윈도우
	if (m_hOwnerWnd != NULL)
	{
		USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
		memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));
		UsbDeviceDataInfo.nState = 1;       // Gun HV Index 사용
		UsbDeviceDataInfo.nData[0] = nIndex;// m_pIntegrated->dGunHVCurVoltage;
		UsbDeviceDataInfo.nData[1] = nValue;// m_pIntegrated->dGunHVCurVoltage;
		// GUN HV Up/Down Process 메시지 보내기
		// 2020.05.04
		//SendMessage(m_hOwnerWnd, UM_USB_SBR_GUN_HV_DATA, NULL, (LPARAM)&UsbDeviceDataInfo);
	}

	// Emission current[µA] Setting
	double dMaxGunHV = (double)m_nGunHVTable[0];
	double dGunHV    = (double)nVoltage;
	double dRatio    = sqrt(dGunHV / dMaxGunHV);          // 실행할(목표값) Gun HV Voltage / MAX GUN HV Voltage -> 비율
	WORD   wECVal    = 0;

	// Emission current[µA] 계산
	m_pIntegrated->dHVRatio = dRatio;
	wECVal = (WORD)((double)(4095 * m_pIntegrated->dHVRatio));
	wECVal /= 2;

	// Emission current[µA] 실행
	AfxIntegratedSetGunHVECValue(wECVal);

	// GUN HV 배율 비율 계산
	m_pIntegrated->dMagHVRatio = sqrt(dGunHV / (double)dMaxGunHV) / 0.8165;
	// 2020.06.03
	// 사용자 MAG HV RATIO : STAGE 수평 옵션을 임시로 사용한다.
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_STAGE_HORZ_ALIGN] == 1)
	{
		// GUN HV : 20KV
		if ((int)dGunHV == 20000)
		{
			m_pIntegrated->dMagHVRatio = sqrt(dGunHV / dMaxGunHV) / DEFAULT_MAG_HV_RATIO;
		}
		else
		{
			// 사용자 설정 배율 HV RATIO 보정값 설정
			m_pIntegrated->dMagHVRatio = m_dOptionMagHVRatio[m_pIntegrated->nGunHVIndex]; //sqrt(dGunHV / dMaxGunHV) / m_dOptionMagHVRatio[m_pIntegrated->nGunHVIndex];// OPTION_MAG_HV_RATIO;
		}
	}

	return RET_SUCCESS_OK;
}
int AfxScanBridgeSetGunHVIndexExecute(int nIndex)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// GUN HV 값 설정하기
	// GUN HV : 32개, 30[kV] ~ 0.5[kV]
	// "AV"에 값을 설정하기 위해서는 원하는 GunHV에 나누기 10을 사용하여 설정한다.
	// 예) 30kV -> 3000, 20kV -> 2000, 1000V -> 100, 500 -> 50 으로 설정.
	int    nValue   = m_nGunHVTable[nIndex];
	double dVoltage = (double)(nValue / 10);
	int    nVoltage = (int)(dVoltage);
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "AV", nVoltage);

	// Emission current[µA] Setting
	double dMaxGunHV = (double)m_nGunHVTable[0];
	double dGunHV    = (double)nVoltage;
	double dRatio    = sqrt(dGunHV / dMaxGunHV);          // 실행할(목표값) Gun HV Voltage / MAX GUN HV Voltage -> 비율
	WORD   wECVal    = 0;

	// Emission current[µA] 계산
	m_pIntegrated->dHVRatio = dRatio;
	wECVal = (WORD)((double)(4095 * m_pIntegrated->dHVRatio));
	wECVal /= 2;

	// Emission current[µA] 실행
	AfxIntegratedSetGunHVECValue(wECVal);

	// GUN HV 배율 비율 계산
	m_pIntegrated->dMagHVRatio = sqrt(dGunHV / (double)dMaxGunHV) / 0.8165;
	// 2020.06.03
	// 사용자 MAG HV RATIO : STAGE 수평 옵션을 임시로 사용한다.
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_STAGE_HORZ_ALIGN] == 1)
	{
		// GUN HV : 20KV
		if ((int)dGunHV == 20000)
		{
			m_pIntegrated->dMagHVRatio = sqrt(dGunHV / dMaxGunHV) / DEFAULT_MAG_HV_RATIO;
		}
		else
		{
			// 사용자 설정 배율 HV RATIO 보정값 설정
			m_pIntegrated->dMagHVRatio = m_dOptionMagHVRatio[m_pIntegrated->nGunHVIndex]; //sqrt(dGunHV / dMaxGunHV) / m_dOptionMagHVRatio[m_pIntegrated->nGunHVIndex];// OPTION_MAG_HV_RATIO;
		}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Set GUN HV Value (GUN HV 값 설정하기)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetGunHVValue(int nValue)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// GUN HV 값 설정하기
	// GUN HV : 32개, 30[kV] ~ 0.5[kV]
	// "AV"에 값을 설정하기 위해서는 원하는 GunHV에 나누기 10을 사용하여 설정한다.
	// 예) 30kV -> 3000, 20kV -> 2000, 1000V -> 100, 500 -> 50 으로 설정.
	double dVoltage = (double)(nValue / 10);
	int    nVoltage = (int)(dVoltage);
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "AV", nVoltage);

	// Emission current[µA] Setting
	double dMaxGunHV = (double)m_nGunHVTable[0];
	double dGunHV    = (double)nVoltage;
	double dRatio    = sqrt(dGunHV / dMaxGunHV);          // 실행할(목표값) Gun HV Voltage / MAX GUN HV Voltage -> 비율
	WORD   wECVal    = 0;

	// Emission current[µA] 계산
	m_pIntegrated->dHVRatio = dRatio;
	wECVal = (WORD)((double)(4095 * m_pIntegrated->dHVRatio));
	wECVal /= 2;

	// Emission current[µA] 실행
	AfxIntegratedSetGunHVECValue(wECVal);

	// GUN HV 배율 비율 계산
	m_pIntegrated->dMagHVRatio = sqrt(dGunHV / (double)dMaxGunHV) / DEFAULT_MAG_HV_RATIO;
	// 2020.06.03
	// 사용자 MAG HV RATIO : STAGE 수평 옵션을 임시로 사용한다.
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_STAGE_HORZ_ALIGN] == 1)
	{
		// GUN HV : 20KV
		if ((int)dGunHV == 20000)
		{
			m_pIntegrated->dMagHVRatio = sqrt(dGunHV / dMaxGunHV) / DEFAULT_MAG_HV_RATIO;
		}
		else
		{
			// 사용자 설정 배율 HV RATIO 보정값 설정
			m_pIntegrated->dMagHVRatio = m_dOptionMagHVRatio[m_pIntegrated->nGunHVIndex]; //sqrt(dGunHV / dMaxGunHV) / m_dOptionMagHVRatio[m_pIntegrated->nGunHVIndex];// OPTION_MAG_HV_RATIO;
		}
	}

	// DEVICE SERVER 윈도우
	if (m_hOwnerWnd != NULL)
	{
		USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
		memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));
		UsbDeviceDataInfo.nState   = 2;     // Gun HV Voltage 사용
		UsbDeviceDataInfo.nData[0] = -1;    // m_pIntegrated->dGunHVCurVoltage;
		UsbDeviceDataInfo.nData[1] = nValue;// m_pIntegrated->dGunHVCurVoltage;
		// GUN HV Up/Down Process 메시지 보내기
		// 2020.05.04
		//SendMessage(m_hOwnerWnd, UM_USB_SBR_GUN_HV_DATA, NULL, (LPARAM)&UsbDeviceDataInfo);
	}

	return RET_SUCCESS_OK;
}
int AfxScanBridgeSetGunHVValue(double dValue, BOOL bCalc)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// GUN HV 값 설정하기
	// GUN HV : 32개, 30[kV] ~ 0.5[kV]
	// "AV"에 값을 설정하기 위해서는 원하는 GunHV에 나누기 10을 사용하여 설정한다.
	// 예) 30kV -> 3000, 20kV -> 2000, 1000V -> 100, 500 -> 50 으로 설정.
	double dVoltage = (double)(dValue / 10.0);
	int    nVoltage = (int)(dVoltage);
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "AV", nVoltage);

	//------------------------------------------------------------------
	// GUN HV Ratio 계산값
	//------------------------------------------------------------------
	if (bCalc == TRUE)
	{
		if (nVoltage < 1) return RET_SUCCESS_OK;      // 0[v] 이면 리턴
		double dMaxGunHV = m_nGunHVTable[0];          // MAX GUN HV VOLTAGE : m_nGunHVTable[0];
		double dGunHV    = dValue;                    // Gun HV Voltage
		double dRatio    = sqrt(dGunHV / dMaxGunHV);  // Gun HV Voltage / MAX GUN HV Voltage -> 비율
		// GUN HV Index 설정
		int nGunHV = (int)dGunHV;
		int nIndex = -1;
		for (int n = 0; n < MAX_GUN_HV_TABLE; n++)
		{
			if (nGunHV == m_nGunHVTable[n])
			{
				nIndex = n;
				break;
			}
		}
		// GUN HV Index 찾음
		if (nIndex > -1)
		{
			m_pIntegrated->nGunHVIndex    = nIndex;
			m_pIntegrated->nGunHVValue    = nGunHV;
			m_pIntegrated->nGunHVCurIndex = nIndex;
			m_pIntegrated->nGunHVCurValue = nGunHV;
			m_pIntegrated->nGunHVExeIndex = nIndex;
			m_pIntegrated->nGunHVExeValue = nIndex;
		}

		// Emission current[µA] Setting
		WORD   wECVal = 0;

		// Emission current[µA] 계산
		m_pIntegrated->dHVRatio = dRatio;
		wECVal = (WORD)((double)(4095 * m_pIntegrated->dHVRatio));
		wECVal /= 2;

		// Emission current[µA] 실행
		AfxIntegratedSetGunHVECValue(wECVal);

		// GUN HV 배율 비율 계산
		m_pIntegrated->dMagHVRatio = sqrt(dGunHV / dMaxGunHV) / DEFAULT_MAG_HV_RATIO;
		// 2020.06.03
		// 사용자 MAG HV RATIO : STAGE 수평 옵션을 임시로 사용한다.
		if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_STAGE_HORZ_ALIGN] == 1)
		{
			// GUN HV : 20KV
			if (nGunHV == 20000)
			{
				m_pIntegrated->dMagHVRatio = sqrt(dGunHV / dMaxGunHV) / DEFAULT_MAG_HV_RATIO;
			}
			else
			{
				// 사용자 설정 배율 HV RATIO 보정값 설정
				m_pIntegrated->dMagHVRatio = m_dOptionMagHVRatio[m_pIntegrated->nGunHVIndex]; //sqrt(dGunHV / dMaxGunHV) / m_dOptionMagHVRatio[m_pIntegrated->nGunHVIndex];// OPTION_MAG_HV_RATIO;
			}
		}
	}
	//------------------------------------------------------------------

	return RET_SUCCESS_OK;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Set GUN HV Voltage Value (GUN HV 전압(HV)값 실행)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetGunHVValueVoltage(int nVoltageValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// GUN HV 값 설정하기
	// GUN HV : 32개, 30[kV] ~ 0.5[kV]
	// "AV"에 값을 설정하기 위해서는 원하는 GunHV에 나누기 10을 사용하여 설정한다.
	// 예) 30kV -> 3000, 20kV -> 2000, 1000V -> 100, 500 -> 50 으로 설정.
	int    nValue = nVoltageValue;
	double dVoltage = (double)(nValue / 10);
	int    nVoltage = (int)(dVoltage);
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "AV", nVoltage);

	// Emission current[µA] Setting
	double dMaxGunHV = (double)m_nGunHVTable[0];
	double dGunHV    = (double)nVoltage;
	double dRatio    = sqrt(dGunHV / dMaxGunHV);          // 실행할(목표값) Gun HV Voltage / MAX GUN HV Voltage -> 비율
	WORD   wECVal    = 0;

	// Emission current[µA] 계산
	m_pIntegrated->dHVRatio = dRatio;
	wECVal = (WORD)((double)(4095 * m_pIntegrated->dHVRatio));
	wECVal /= 2;

	// Emission current[µA] 실행
	AfxIntegratedSetGunHVECValue(wECVal);

	// GUN HV 배율 비율 계산
	m_pIntegrated->dMagHVRatio = sqrt(dGunHV / (double)dMaxGunHV) / DEFAULT_MAG_HV_RATIO;
	// 2020.06.03
	// 사용자 MAG HV RATIO : STAGE 수평 옵션을 임시로 사용한다.
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_STAGE_HORZ_ALIGN] == 1)
	{
		// GUN HV : 20KV
		if ((int)dGunHV == 20000)
		{
			m_pIntegrated->dMagHVRatio = sqrt(dGunHV / dMaxGunHV) / DEFAULT_MAG_HV_RATIO;
		}
		else
		{
			// 사용자 설정 배율 HV RATIO 보정값 설정
			m_pIntegrated->dMagHVRatio = m_dOptionMagHVRatio[m_pIntegrated->nGunHVIndex]; //sqrt(dGunHV / dMaxGunHV) / m_dOptionMagHVRatio[m_pIntegrated->nGunHVIndex];// OPTION_MAG_HV_RATIO;
		}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : GUN VALVE OPEN
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeGunValveOpen(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// GUN VALVE OPEN
	m_pIntegrated->nGunValveState = 1;
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "HV1;");   // Sbr Data 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : GUN VALVE CLOSE
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeGunValveClose(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// GUN VALVE CLOSE
	m_pIntegrated->nGunValveState = 0;
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "HV0;");   // Sbr Data 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : FILAMENT IMAGE SCAN START
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeFilamentImageScanStart(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// FILAMENT IMAGE SCAN START
	//m_pIntegrated->nFilamentImageScanState = 1;
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "FL0,1;");   // Sbr Data 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : FILAMENT IMAGE SCAN STOP
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeFilamentImageScanStop(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// FILAMENT IMAGE SCAN STOP
	//m_pIntegrated->nFilamentImageScanState = 0;
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "FL0,0;");   // Sbr Data 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Set BIAS Value (BIAS 값 설정하기)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetBiasValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// BIAS 값 설정하기
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "BV", m_pIntegrated->nBiasExeValue);

	// DEVICE SERVER 윈도우
	if (m_hOwnerWnd != NULL)
	{
		// BIAS DATA 메시지 보내기
		// 2020.05.04
		//SendMessage(m_hOwnerWnd, UM_USB_SBR_BIAS_DATA, NULL, (LPARAM)NULL);
	}

	return RET_SUCCESS_OK;
}
int AfxScanBridgeSetBiasValueExecute(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// BIAS 값 설정하기
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "BV", m_pIntegrated->nBiasExeValue);

	return RET_SUCCESS_OK;
}
int AfxScanBridgeSetBiasValue(int nBias)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// BIAS 값 설정하기
	m_pIntegrated->nBiasValue    = nBias;
	m_pIntegrated->nBiasCurValue = nBias;
	m_pIntegrated->nBiasExeValue = nBias;

	return RET_SUCCESS_OK;
}
// Scan Bridge : Set BIAS Value (BIAS [V]값 설정하기)
int AfxScanBridgeSetBiasVoltageValue(double dVoltage)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// 범위 : 0[v] ~ 3.5[v] -> 0 ~ 4095
	double dVUnit  = (double)(SEM_BIAS_MAX+1) / SEM_BIAS_PROG_MAX;
	double d1Point  = dVUnit / 1.0;
	double dBVCount = dVoltage / d1Point;
	int    nBVCount = (int)dBVCount;

	if (nBVCount < SEM_BIAS_MIN) nBVCount = SEM_BIAS_MIN;
	if (nBVCount > SEM_BIAS_MAX) nBVCount = SEM_BIAS_MAX;

	// BIAS 값 설정하기
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "BV", nBVCount);

	return RET_SUCCESS_OK;
}
int AfxScanBridgeGetBiasValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// BIAS 값 리턴
	return m_pIntegrated->nBiasValue;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Set Filament Value (필라멘트 값 설정하기)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetFilamentValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Filament 값 설정하기
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "FV", m_pIntegrated->nFilamentExeValue);

	// DEVICE SERVER 윈도우
	if (m_hOwnerWnd != NULL)
	{
		// FILAMENT DATA 메시지 보내기
		// 2020.05.04
		//SendMessage(m_hOwnerWnd, UM_USB_SBR_FILAMENT_DATA, NULL, (LPARAM)NULL);
	}

	return RET_SUCCESS_OK;
}
int AfxScanBridgeSetFilamentValueExecute(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Filament 값 적용하기
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "FV", m_pIntegrated->nFilamentExeValue);

	return RET_SUCCESS_OK;
}
int AfxScanBridgeSetFilamentValue(int nFilament)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Filament 값 설정하기
	m_pIntegrated->nFilamentValue    = nFilament;
	m_pIntegrated->nFilamentCurValue = nFilament;
	m_pIntegrated->nFilamentExeValue = nFilament;

	return RET_SUCCESS_OK;
}
// Scan Bridge : Set Filament Voltage Value (필라멘트 [V]값 설정하기)
int AfxScanBridgeSetFilamentVoltageValue(double dVoltage)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// 범위 : 0[v] ~ 4[v] -> 0 ~ 4095
	double dVUnit   = (double)(SEM_FILAMENT_MAX+1) / SEM_FILAMENT_PROG_MAX;
	double d1Point  = dVUnit / 1.0;
	double dFVCount = dVoltage / d1Point;
	int    nFVCount = (int)dFVCount;

	if (nFVCount < SEM_FILAMENT_MIN) nFVCount = SEM_FILAMENT_MIN;
	if (nFVCount > SEM_FILAMENT_MAX) nFVCount = SEM_FILAMENT_MAX;

	// Filament 값 설정하기
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "FV", nFVCount);

	return RET_SUCCESS_OK;
}
int AfxScanBridgeGetFilamentValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Filament 값 리턴
	return m_pIntegrated->nFilamentValue;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : SpellMan Collector ON
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeCollectorOn(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// SpellMan Collector On
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RG3,0;"); // Sbr Data 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : SpellMan Collector OFF
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeCollectorOff(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// SpellMan Collector On
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RG3,1;"); // Sbr Data 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Manification Relay Calibration -> Zoom X Control
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetZoomXControl(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

    // Zoom X Control	
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "ZM0,", m_pIntegrated->nZoomXValue); // Sbr Data 전송
																		  
	return RET_SUCCESS_OK;
}
int AfxScanBridgeSetZoomXControl(int nZoomXValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Zoom X Control Value
	m_pIntegrated->nZoomXValue = nZoomXValue;

	return RET_SUCCESS_OK;
}
int AfxScanBridgeGetZoomXControl(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Zoom X Control Value
	return m_pIntegrated->nZoomXValue;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Manification Relay Calibration -> Zoom Y Control
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetZoomYControl(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Zoom Y Control
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "ZM1,", m_pIntegrated->nZoomYValue); // Sbr Data 전송

	return RET_SUCCESS_OK;
}
int AfxScanBridgeSetZoomYControl(int nZoomYValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Zoom Y Control Value
	m_pIntegrated->nZoomYValue = nZoomYValue;

	return RET_SUCCESS_OK;
}
int AfxScanBridgeGetZoomYControl(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Zoom Y Control Value
	return m_pIntegrated->nZoomYValue;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge :  Dynamic Focus A, B
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetDynamicFocusAB(int nFocusValue)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Device 설정(수정)이 가능한지 확인...
	//if (m_pIntegrated->bHWChangeEnableFlag == false) return RET_ERROR_STATUS; // 일반적 오류 코드

	// Dynamic Focus A
	m_pIntegrated->nDynamicFocusA = nFocusValue;
    AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "DF0,", m_pIntegrated->nDynamicFocusA); // Sbr Data 전송

    // Dynamic Focus B
	m_pIntegrated->nDynamicFocusB = nFocusValue;
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "DF1,", m_pIntegrated->nDynamicFocusB); // Sbr Data 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge :  Sync On
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetSyncOn(void)
{
	//==================================================================
	// AC Sync Mode
	//==================================================================
	// AC sync_scan_on을 off로 설정하므로,
	// AC 전원 Sync 신호가 인가되지 않아도 scan을 진행하게 된다.
	//==================================================================
	// AC sync_scan_on을 on으로 설정하면
	// AC 전원 Sync 신호가 인가되어야 scan을 진행하게 된다.
	//==================================================================
	// Frame Sync 또는 Line Sync 기능과 AC Sync Freq 정보를 설정하는
	// 파라미터 값은 m_pIntegrated->nSyncVal[sm] 초기 변수값에 저장되어 있으므로
	// ScanMode가 변경될 때마다, m_CommandState 값에 설정된다.
	//------------------------------------------------------------------

	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	if (m_pIntegrated->bAcSyncOn == TRUE)
	{
		// Sync On
		m_pIntegrated->nSbrCommand |= SYNC_SCAN_ON_HIGH;
	}
	else
	{
		// Sync Off
		m_pIntegrated->nSbrCommand &= SYNC_SCAN_ON_LOW;
	}

	// 단일 명령어 및 데이터 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSbrCommand); // Sbr Command

	return RET_SUCCESS_OK;
}
int AfxScanBridgeSetSyncOn(BOOL bAcSyncOn)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// AC Sync On/Off
	m_pIntegrated->bAcSyncOn = bAcSyncOn;

	return RET_SUCCESS_OK;
}
BOOL AfxScanBridgeGetSyncOn(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// AC Sync On/Off Flag
	return m_pIntegrated->bAcSyncOn;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge :  Orthogonal value set (직교도)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetOrthogonal(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Orthogonal(직교도) 설정
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SR5,", m_pIntegrated->nOrthogonal); // Sbr Data 전송

	// Orthogonal(직교도) 설정
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SR4,", m_pIntegrated->nOrthogonal); // Sbr Data 전송

	return RET_SUCCESS_OK;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge :  Orthogonal value set (직교도)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetOrthogonal(int nOrthogonal)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Orthogonal(직교도) 설정
	m_pIntegrated->nOrthogonal = nOrthogonal;
	m_pIntegrated->nARAngle[0] = m_pIntegrated->nOrthogonal;

	return RET_SUCCESS_OK;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge :  Get Orthogonal Value (직교도)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeGetOrthogonal(void)
{
	if (m_pIntegrated == NULL) return 0;  // Integrated Command & Data Handle

	// Orthogonal(직교도)
	return m_pIntegrated->nARAngle[0];// m_pIntegrated->nOrthogonal;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Scan Relay -> Gun Scan (Filament Scan)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetGunScanRelay(BOOL bGunScanCheck)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	m_pIntegrated->bGunScanCheck = bGunScanCheck;

	if (m_pIntegrated->bGunScanCheck == TRUE)
	{
		// Gun Scan Check : TRUE
		m_pIntegrated->nGunScanRelay = 1;
	}
	else
	{
		// Gun Scan Check : FALSE
		m_pIntegrated->nGunScanRelay = 0;
	}

	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SR10,", m_pIntegrated->nGunScanRelay); // Sbr Data 전송

	return RET_SUCCESS_OK;
}
BOOL AfxScanBridgeGetGunScanRelay(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	return m_pIntegrated->bGunScanCheck;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Scan Rotation (degree x 10) : 입력범위 0 ~ 3599, 0도~360도 10등분
/////////////////////////////////////////////////////////////////////////////////////////////////////
// 2020.05.18
int AfxScanBridgeSetScanRotation(int nDegreex10)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	//--------------------------------------------------------------------------
	// 1) Scan Rotation 값 ( SRotationValue )
	//--------------------------------------------------------------------------
	// deg x 10
	//--------------------------------------------------------------------------
	int nNewDegreex10 = nDegreex10;

	//--------------------------------------------------------------------------
	// 2) Stage 수평값 적용(Stage와 Scan 방향을 일치시키기 위한 값)
	//--------------------------------------------------------------------------
	//if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_STAGE_HORZ_ALIGN] == 1)
	//{
	//	nNewDegreex10 += m_pIntegrated->nStageHorAlign;
	//}
	//--------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	// 3) Focus OL 값 변경에 따른 SCAN ROTATION(영상회전) 값 보정
	//--------------------------------------------------------------------------
	if(m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_WD_SCAN_ROTATION] == 1)
	{
		// WD에 따른 SCAN ROTATION 보정값 : -3600 ~ 0 ~ +3600
		m_pIntegrated->nWDSRotationValue = m_pIntegrated->nWDSRotationLinear[m_pIntegrated->nOLWD];
		// 2020.05.15
		nNewDegreex10 += m_pIntegrated->nWDSRotationValue;
	}
	//--------------------------------------------------------------------------
	if (nNewDegreex10 >= 3600)
	{
		nNewDegreex10 -= 3600;
	}
	else if (nNewDegreex10 < 0)
	{
		nNewDegreex10 += 3600;
	}
	if (nNewDegreex10 == 3600)  nNewDegreex10 = 0;
	//--------------------------------------------------------------------------


	int nSRotHX = 0;
	int nSRotVX = 0;
	int nSRotHY = 0;
	int nSRotVY = 0;

	double dRAD = 0.0;

	dRAD = PI_CONST * (double)((double)nNewDegreex10 / 1800.0);

	//--------------------------------------------------------------------------
	// 0       90      180      270
	//--------------------------------------------------------------------------
	// 4096(1) 2048      0     2048
	// 2048(0) 4096    2048       0
	// 2048(0) 4096    2048       0
	// 0   (1) 2048    4096    2048
	//--------------------------------------------------------------------------

	nSRotHX = (int)(2048 * (1.0 + cos(dRAD)));
	nSRotVX = (int)(2048 * (1.0 + cos(dRAD)));

	nSRotHY = (int)(2048 * (1.0 + sin(dRAD)));
	nSRotVY = (int)(2048 * (1.0 - sin(dRAD)));

	if (nSRotHX < 0) nSRotHX = 0;
	if (nSRotVX < 0) nSRotVX = 0;
	if (nSRotHY < 0) nSRotHY = 0;
	if (nSRotVY < 0) nSRotVY = 0;

	if (nSRotHX > 4095) nSRotHX = 4095;
	if (nSRotVX > 4095) nSRotVX = 4095;
	if (nSRotHY > 4095) nSRotHY = 4095;
	if (nSRotVY > 4095) nSRotVY = 4095;

	//--------------------------------------------------------------------------
	// Scan Rotation 보정값 설정
	//--------------------------------------------------------------------------
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SR0,", nSRotHX); // Sbr Data 전송
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SR1,", nSRotVX); // Sbr Data 전송
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SR2,", nSRotHY); // Sbr Data 전송
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SR3,", nSRotVY); // Sbr Data 전송
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    // x : X(5V) x cos + Y(4V) x sin
    // y : Y(4V) x cos + X(5V) x sin
    //--------------------------------------------------------------------------
	// 
	//if (abs(m_pIntegrated->nSRotationValue - m_pIntegrated->nSRotationValueOld) >= 5)

	double dWDZoomRatio = 1.0; // ZOOM 배율 보정값
	int    nWD10 = m_pIntegrated->nOLWD; // 현재 WD x 10 값 (FOCUS에 의한 WD값)

	// 배율보정 작업중이면
	if (m_pIntegrated->bWDSetupFlag == TRUE)
	{
		// 현재 WD Setup에 선택된 Z축 값 x 10
		nWD10 = m_pIntegrated->nWDStepNumber * 10;
	}

	// 2020.05.15
	/////////////////////////////////////////////////////////////////////////////////////////
	// SCAN ROTATION CALIBRATION DATA 적용
	/////////////////////////////////////////////////////////////////////////////////////////
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_ORTHOGONAL_CORRRECTION] == 1)
	{
		// 2020.07.06
		if (m_pScanRotCaliData == NULL) return RET_SUCCESS_OK;
		// 2020.05.15
		// SCAN ROTATION 값 변화 확인
		if (m_pIntegrated->nSRotationValue != m_pIntegrated->nSRotationValueOld)
		{
			////////////////////////////////////////////////////////////////////////
			// Scan Rotation에 따른 Orthogonal, Zoom X-Y 보정값 적용
			////////////////////////////////////////////////////////////////////////
			// Orthogonal 보정값 적용 : 각도(0~360, 0~3600, 10등분)
			int nOrtho = m_pScanRotCaliData->nSRotOrthogonalData[nNewDegreex10];
			AfxScanBridgeSetOrthogonal(nOrtho);
			// Orthogonal 보정값 실행
			AfxScanBridgeSetOrthogonal();

			////////////////////////////////////////////////////////////////////////
			// Zoom X-Y 보정값 적용 ( 0 ~ 360도 )
			////////////////////////////////////////////////////////////////////////
			int nMagValue = m_nMagStepValue[m_pIntegrated->nMagStepIndex]; // 배율
			int nZoom     = AfxSRotCaliGetZoomRelayRatio(nMagValue);       // 배율에 따른 Zoom Index
			int nZoomX    = m_pScanRotCaliData->nSRotRelayZoomXData[nZoom][nNewDegreex10 /10];
			int nZoomY    = m_pScanRotCaliData->nSRotRelayZoomYData[nZoom][nNewDegreex10 /10];

			double dZoomX = (double)nZoomX;
			double dZoomY = (double)nZoomY;

			// 2020.06.15
			// 배율 x35k 이상 ZOOM 값 재보정 적용
			if (nMagValue > 30000)
			{
				if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_IMAGE_SHIFT_Y_REVERSE] == 1)
				{
					dZoomX = dZoomX * m_dOptionMagx35kZoomRatio;
					dZoomY = dZoomY * m_dOptionMagx35kZoomRatio;
					nZoomX = (int)dZoomX;
					nZoomY = (int)dZoomY;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////
			// 2020.05.29
			// ZOOM 보정
			/////////////////////////////////////////////////////////////////////////////////
			// 1) WD 변화에 따른 Zoom 보정
			if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_WD_SCALE_ZOOM] == 1)
			{
				// WD SCALE ZOOM CORRECTION
				dWDZoomRatio = (double)(m_pIntegrated->nWDZoomingLinear[nWD10]) / 1000.0;
			}
			// 2) HV보정을 선택 했을 경우
			if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_HV_CORRECTION] == 1)
			{
				dWDZoomRatio = dWDZoomRatio * m_pIntegrated->dMagHVRatio;
			}
			/////////////////////////////////////////////////////////////////////////////////
			// 2020.05.29 Zoom 설정
			/////////////////////////////////////////////////////////////////////////////////
			m_pIntegrated->wZoomXValue = nZoomX;
			m_pIntegrated->wZoomYValue = nZoomY;
			AfxIntegratedSetZoomValue(m_pIntegrated->wZoomXValue, m_pIntegrated->wZoomYValue, dWDZoomRatio);
			////////////////////////////////////////////////////////////////////////
			////////////////////////////////////////////////////////////////////////
			////////////////////////////////////////////////////////////////////////

			m_pIntegrated->nSRotationValueOld = m_pIntegrated->nSRotationValue;

			// DISPLAY MESSAGE : ORTHOGONAL, ZOOM X-Y 값
			USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
			memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));
			UsbDeviceDataInfo.nState   = PUB_SROT_ORTHO_ZOOM_CALI_DATA;
			UsbDeviceDataInfo.nData[0] = nOrtho; // ORTHOGONAL
			UsbDeviceDataInfo.nData[1] = nZoomX; // ZOOM X
			UsbDeviceDataInfo.nData[2] = nZoomY; // ZOOM Y
			// GUN HV Up/Down Process 종료 메시지 보내기
			SendMessage(m_hOwnerWnd, UM_HW_SETUP_SROT_CALI_DATA, NULL, (LPARAM)&UsbDeviceDataInfo);

			////////////////////////////////////////////////////////////////////////
			////////////////////////////////////////////////////////////////////////
			////////////////////////////////////////////////////////////////////////
		}
	}

	// 백업
	m_dWDZoomRatioBackup = dWDZoomRatio;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge :  Scan Rotation에 따른 Orthogonal, Zoom X-Y 보정값 적용을 위한 Ratio Zoom
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSRotCaliGetZoomRelayRatio(int nMagValue)
{
	int nZoom = 0;

	// SCAN ROTATION CALIBRATION DATA INDEX 구하기
	// Zoom
	if      (nMagValue == 20    ) nZoom = 0;  else if (nMagValue == 30    ) nZoom = 1;  else if (nMagValue == 35    ) nZoom = 2;  else if (nMagValue == 40    ) nZoom = 3;  else if (nMagValue == 45    ) nZoom = 4;
	else if (nMagValue == 50    ) nZoom = 5;  else if (nMagValue == 60    ) nZoom = 6;  else if (nMagValue == 70    ) nZoom = 7;  else if (nMagValue == 80    ) nZoom = 8;  else if (nMagValue == 90    ) nZoom = 9;
	else if (nMagValue == 100   ) nZoom = 10; else if (nMagValue == 110   ) nZoom = 11; else if (nMagValue == 120   ) nZoom = 12; else if (nMagValue == 130   ) nZoom = 13; else if (nMagValue == 150   ) nZoom = 14;
	else if (nMagValue == 180   ) nZoom = 15; else if (nMagValue == 200   ) nZoom = 16; else if (nMagValue == 220   ) nZoom = 17; else if (nMagValue == 250   ) nZoom = 18; else if (nMagValue == 300   ) nZoom = 1;// 19;
	//
	else if (nMagValue == 350   ) nZoom = 2;  else if (nMagValue == 400   ) nZoom = 3;  else if (nMagValue == 450   ) nZoom = 4;  else if (nMagValue == 500   ) nZoom = 5;  else if (nMagValue == 600   ) nZoom = 6;
	else if (nMagValue == 700   ) nZoom = 7;  else if (nMagValue == 800   ) nZoom = 8;  else if (nMagValue == 900   ) nZoom = 9;  else if (nMagValue == 1000  ) nZoom = 10; else if (nMagValue == 1100  ) nZoom = 11;
	else if (nMagValue == 1200  ) nZoom = 12; else if (nMagValue == 1300  ) nZoom = 13; else if (nMagValue == 1500  ) nZoom = 14; else if (nMagValue == 1800  ) nZoom = 15; else if (nMagValue == 2000  ) nZoom = 16;
	else if (nMagValue == 2200  ) nZoom = 17; else if (nMagValue == 2500  ) nZoom = 18; else if (nMagValue == 3000  ) nZoom = 1;// 19;
	//
	else if (nMagValue == 3500  ) nZoom = 2;  else if (nMagValue == 4000  ) nZoom = 3;  else if (nMagValue == 4500  ) nZoom = 4;  else if (nMagValue == 5000  ) nZoom = 5;  else if (nMagValue == 6000  ) nZoom = 6;
	else if (nMagValue == 7000  ) nZoom = 7;  else if (nMagValue == 8000  ) nZoom = 8;  else if (nMagValue == 9000  ) nZoom = 9;  else if (nMagValue == 10000 ) nZoom = 10; else if (nMagValue == 11000 ) nZoom = 11;
	else if (nMagValue == 12000 ) nZoom = 12; else if (nMagValue == 13000 ) nZoom = 13; else if (nMagValue == 15000 ) nZoom = 14; else if (nMagValue == 18000 ) nZoom = 15; else if (nMagValue == 20000 ) nZoom = 16;
	else if (nMagValue == 22000 ) nZoom = 17; else if (nMagValue == 25000 ) nZoom = 18; else if (nMagValue == 30000 ) nZoom = 19;// 1;// 19;
	//
	else if (nMagValue == 35000 ) nZoom = 2;  else if (nMagValue == 40000 ) nZoom = 3;  else if (nMagValue == 45000 ) nZoom = 4;  else if (nMagValue == 50000 ) nZoom = 5;  else if (nMagValue == 60000 ) nZoom = 6;
	else if (nMagValue == 70000 ) nZoom = 7;  else if (nMagValue == 80000 ) nZoom = 8;  else if (nMagValue == 90000 ) nZoom = 9;  else if (nMagValue == 100000) nZoom = 10; else if (nMagValue == 110000) nZoom = 11;
	else if (nMagValue == 120000) nZoom = 12; else if (nMagValue == 130000) nZoom = 13; else if (nMagValue == 150000) nZoom = 14; else if (nMagValue == 180000) nZoom = 15; else if (nMagValue == 200000) nZoom = 16;
	else if (nMagValue == 220000) nZoom = 17; else if (nMagValue == 250000) nZoom = 18; else if (nMagValue == 300000) nZoom = 19;

	return nZoom;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge :  Set Scan Rotation Value
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetScanRotationValue(int nScanRotValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Set Scan Rotation Value
	m_pIntegrated->nSRotationValue = nScanRotValue;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge :  Reset Scan Rotation Value
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeResetScanRotationValue(int nScanRotValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Set Scan Rotation Value
	m_pIntegrated->nSRotationValue = 0;
	m_pIntegrated->nSRotationValueOld = m_pIntegrated->nSRotationValue;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge :  Scan Rotation 45[deg] X-Amp Value
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetSRot45XAmpValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Set Scan Rotation 45[deg] X-Amp Value
	m_pIntegrated->nXSR45Value = nValue;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge :  Scan Rotation 90[deg] X-Amp Value
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetSRot90XAmpValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Set Scan Rotation 90[deg] X-Amp Value
	m_pIntegrated->nXSR90Value = nValue;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge :  Scan Rotation 45[deg] Y-Amp Value
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetSRot45YAmpValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Set Scan Rotation 45[deg] Y-Amp Value
	m_pIntegrated->nYSR45Value = nValue;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge :  Scan Rotation 90[deg] Y-Amp Value
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetSRot90YAmpValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Set Scan Rotation 90[deg] Y-Amp Value
	m_pIntegrated->nYSR90Value = nValue;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Get Vaccum State Read 명령어 전송 (진공상태 확인)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeGetVaccumState(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	//------------------------------------------------------------------------
	// Evac Board의 FT245와 USB 연결
	//------------------------------------------------------------------------
	// 1) 먼저, [ Evac ] Button -> Enable
	//          [ Air  ] Button -> Disable
	// 2) Avr 진공 Controller에게, 진공상태를 확인하는 "VS;" Command를 보낸다.
	//
	// 3) 진공상태 Command 응답이 있으면, Windows 화면에 진공상태 표시
	//
	// 4) 응답이 없으면, [ Evac ] Button Push를 기다림
	//        [ Evac ] Button Push --> "EV;" Command 보냄 ( FT245-Avr )
	//------------------------------------------------------------------------

	// Evac Command
    //AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "ES;");   // Sbr Data 전송

	// Get Vauum State
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "VS;");   // Sbr Data 전송

    // ScanBridgeBoard -> CncVacBoard (EM40) ==> Motor Backlash Read???(알수없는 내용)
	//AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SB4;"); // Sbr Data 전송

	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Program Exit 실행 -> Stage Board Axis Position 만 저장 후 프로그램 종료
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeProgramExitAxisPosition(void)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// 프로그램 종료시 Stage Board 의 Axis Position 만 저장 한 후, 프로그램을 종료한다.
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "PS0;"); // Sbr Data 전송
	Sleep(100);

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Program Exit 실행 -> Sem PowerOff & Axis Position Saved 실행
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeProgramExitPowerOff(void)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	//-------------------------------------------------------------------
	// Scan Bridge 장치가 연결되어 있다면
	// Save axis position & SEM Power Off
	//-------------------------------------------------------------------
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "PS;");  // Sbr Command
	Sleep(100);
	//-------------------------------------------------------------------
	// Stage Board : Save axis position and power off code
	//-------------------------------------------------------------------
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "PS1;"); // Sbr Command
	Sleep(100);
	//-------------------------------------------------------------------
	// SEM Power Off (ShutDown)
	//-------------------------------------------------------------------
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "PD;");  // Sbr Command
	Sleep(100);
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SB0;"); // Sbr Command
	Sleep(100);
	//-------------------------------------------------------------------

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Program Exit 실행 -> 장치오류시 Sem PowerOff 모드로 종료
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeProgramExitDeviceError(void)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	//-------------------------------------------------------------------
	// Scan Bridge 장치가 연결되어 있다면
	// SEM Power Off
	//-------------------------------------------------------------------
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "PS;");  // Sbr Command
	Sleep(100);
	//-------------------------------------------------------------------
	// Stage Board : Save axis position and power off code
	//-------------------------------------------------------------------
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "PS1;"); // Sbr Command
	Sleep(100);
	//-------------------------------------------------------------------
	// SEM Power Off (Shutdown)
	//-------------------------------------------------------------------
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "PD;");  // Sbr Command
	Sleep(100);
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "SB0;"); // Sbr Command
	Sleep(100);
	//-------------------------------------------------------------------

	return RET_SUCCESS_OK;
}

//---------------------------------------------------------------------------------
// MM : Motor Move            Ex) [MM0,1234,56788;]
//                                 XStr,YStr,DStr
//---------------------------------------------------------------------------------
//      XStr[] : Axis  [ '0', '1', '2', '3', '4' ]
//                        X    Y    Z    R    T    
//      YStr[] : Accel [ 16 bit ]
//      DStr[] : Time  [ 32 bit ]
//---------------------------------------------------------------------------------
// X, Y, Z, R, T Axis Motion
//---------------------------------------------------------------------------------
//#define  NO_MOVING_ECHO  0
//#define  ENDING_ECHO     1
//#define  MOVING_ECHO     2
//---------------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Motor Axis Motion
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxScanBridgeAxisMotion(int nAxis, double dDistance, int nEchoFlag)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	char szBuf[20+1];
	char szCom[25+1];

	memset(szBuf, 0x00, sizeof(szBuf));
	memset(szCom, 0x00, sizeof(szCom));

	switch (nAxis)
	{
		case X_AXIS:
		{
			strcpy_s(szCom, "MM0,");
			break;
		}
		case Y_AXIS:
		{
			strcpy_s(szCom, "MM1,");
			break;
		}
		case Z_AXIS:
		{
			strcpy_s(szCom, "MM2,");
			break;
		}
		case R_AXIS:
		{
			strcpy_s(szCom, "MM3,");
			break;
		}
		case T_AXIS:
		{
			strcpy_s(szCom, "MM4,");
			break;
		}
	}

	sprintf( szBuf, "%.5f", dDistance);
	strcat(szCom, szBuf);

	if (nEchoFlag == 1)
	{
		strcat(szCom, ",1");
	}
	else
	if (nEchoFlag == 2)
	{
		strcat(szCom, ",2");
	}

	strcat(szCom, ";");

	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom); // Sbr Command

	return atof(szBuf);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : X-Axis [mm] 이동
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeXmmMotion(double dMM, int nEchoFlag)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	char szBuf[20+1];
	char szCom[25+1];

	memset(szBuf, 0x00, sizeof(szBuf));
	memset(szCom, 0x00, sizeof(szCom));

	strcpy_s(szCom, "MM0,");
	sprintf(szBuf, "%.5f", dMM); // 이동거리[mm]
	strcat(szCom, szBuf);

	if (nEchoFlag == 1)
	{
		strcat(szCom, ",1");
	}
	else
	if (nEchoFlag == 2)
	{
		strcat(szCom, ",2");
	}

	strcat(szCom, ";");

	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom); // Sbr Command

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Y-Axis [mm] 이동
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeYmmMotion(double dMM, int nEchoFlag)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	char szBuf[20 + 1];
	char szCom[25 + 1];

	memset(szBuf, 0x00, sizeof(szBuf));
	memset(szCom, 0x00, sizeof(szCom));

	strcpy_s(szCom, "MM1,");
	sprintf(szBuf, "%.5f", dMM); // 이동거리[mm]
	strcat(szCom, szBuf);

	if (nEchoFlag == 1)
	{
		strcat(szCom, ",1");
	}
	else
	if (nEchoFlag == 2)
	{
		strcat(szCom, ",2");
	}

	strcat(szCom, ";");

	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom); // Sbr Command

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Z-Axis [mm] 이동
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeZmmMotion(double dMM, int nEchoFlag)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	char szBuf[20 + 1];
	char szCom[25 + 1];

	memset(szBuf, 0x00, sizeof(szBuf));
	memset(szCom, 0x00, sizeof(szCom));

	strcpy_s(szCom, "MM2,");
	sprintf(szBuf, "%.5f", dMM); // 이동거리[mm]
	strcat(szCom, szBuf);

	if (nEchoFlag == 1)
	{
		strcat(szCom, ",1");
	}
	else
		if (nEchoFlag == 2)
		{
			strcat(szCom, ",2");
		}

	strcat(szCom, ";");

	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom); // Sbr Command

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : R-Axis [deg:상대각도] 이동
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeRdegMotion(double dDeg, int nEchoFlag)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	char szBuf[20 + 1];
	char szCom[25 + 1];

	memset(szBuf, 0x00, sizeof(szBuf));
	memset(szCom, 0x00, sizeof(szCom));

	strcpy_s(szCom, "MM3,");
	sprintf(szBuf, "%3.1f", dDeg); // 상대적 이동 각도
	strcat(szCom, szBuf);

	if (nEchoFlag == 1)
	{
		strcat(szCom, ",1");
	}
	else
	if (nEchoFlag == 2)
	{
		strcat(szCom, ",2");
	}

	strcat(szCom, ";");

	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom); // Sbr Command

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : R-Axis [abs_deg:절대각도] 이동
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeRabsMotion(double dAbsDeg, int nEchoFlag)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	char szBuf[20 + 1];
	char szCom[25 + 1];

	memset(szBuf, 0x00, sizeof(szBuf));
	memset(szCom, 0x00, sizeof(szCom));

	strcpy_s(szCom, "MM3,");
	sprintf(szBuf, "%3.1f", dAbsDeg); // 절대적 이동 각도 (0~359)
	strcat(szCom, szBuf);

	if (nEchoFlag == 1)
	{
		strcat(szCom, ",1");
	}
	else
	if (nEchoFlag == 2)
	{
		strcat(szCom, ",2");
	}

	strcat(szCom, ";");

	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom); // Sbr Command

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : T-Axis [deg:상대각도] 이동
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeTdegMotion(double dDeg, int nEchoFlag)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	char szBuf[20 + 1];
	char szCom[25 + 1];

	double dDegx10 = dDeg; // 상대적 이동 각도 (x10)
	m_pIntegrated->dTAxisDegree += dDegx10;
	m_pIntegrated->nTAxisDegree = (int)m_pIntegrated->dTAxisDegree;

	if (m_pIntegrated->nTAxisDegree < 0)
	{
		m_pIntegrated->nTAxisDegree += 3600;
		m_pIntegrated->dTAxisDegree = (double)m_pIntegrated->nTAxisDegree;
	}
	else
	if (m_pIntegrated->nTAxisDegree >= 3600)
	{
		m_pIntegrated->nTAxisDegree -= 3600;
		m_pIntegrated->dTAxisDegree = (double)m_pIntegrated->nTAxisDegree;
	}

	memset(szBuf, 0x00, sizeof(szBuf));
	memset(szCom, 0x00, sizeof(szCom));

	strcpy_s(szCom, "MM4,");
	sprintf(szBuf, "%3.1f", dDegx10); // 상대적 이동 각도 (x10)
	strcat(szCom, szBuf);

	if (nEchoFlag == 1)
	{
		strcat(szCom, ",1");
	}
	else
	if (nEchoFlag == 2)
	{
		strcat(szCom, ",2");
	}

	strcat(szCom, ";");

	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom); // Sbr Command

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : T-Axis [mm] 이동
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeTmmMotion(double dMM, int nEchoFlag)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	char szBuf[20 + 1];
	char szCom[25 + 1];

	memset(szBuf, 0x00, sizeof(szBuf));
	memset(szCom, 0x00, sizeof(szCom));

	strcpy_s(szCom, "MM4,");
	sprintf(szBuf, "%3.1f", dMM); // 틸트 거리[mm] 이동
	strcat(szCom, szBuf);

	if (nEchoFlag == 1)
	{
		strcat(szCom, ",1");
	}
	else
	if (nEchoFlag == 2)
	{
		strcat(szCom, ",2");
	}

	strcat(szCom, ";");

	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom); // Sbr Command

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Axis Limit 이동 명령
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetAxisLimitMotion(int nAxis)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Axis Check?
	if (nAxis < IDX_X_AXIS || nAxis > IDX_T_AXIS) return RET_ERROR_STATUS;

	char szCom[25 + 1];
	memset(szCom, 0x00, sizeof(szCom));

	// Axis Set Limit Command
	sprintf(szCom, "MH%d,1;", nAxis);

	// Sbr Command 전송
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom); 

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Limit Switch 상태 정보 전송 기능 활성화 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetAxisLimitStateSending(int nSending)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Sending Check?

	char szCom[25 + 1];
	memset(szCom, 0x00, sizeof(szCom));

	if (nSending == 1)
	{
		// Limit Switch State Sending On
		sprintf(szCom, "LS1;");
	}
	else
	{
		// Limit Switch State Sending Off
		sprintf(szCom, "LS0;");
	}

	// Sbr Command 전송
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom);

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Go to XTZRT-Sample Loading Position --> Scan Position (스캔 위치로 이동)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeGotoXYZRTSampleLoadPosition(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	char szCom[255 + 1];

	// VacBoard -> PC -> To CncBoard
	memset(szCom, 0x00, sizeof(szCom));
	strcpy_s(szCom, "SB20;");
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom); // Sbr Command

	// SAMPLE SCAN POSITION MOVE
	memset(szCom, 0x00, sizeof(szCom));
	strcpy_s(szCom, "VL9,1;");
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom); // Sbr Command

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Go to XTZRT-Sample UnLoading Position --> Exchange Position (교환 위치로 이동)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeGotoXYZRTSampleUnloadPosition(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	char szCom[255 + 1];
	memset(szCom, 0x00, sizeof(szCom));

	// VacBoard -> PC -> To CncBoard
	memset(szCom, 0x00, sizeof(szCom));
	strcpy_s(szCom, "SB21;");
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom); // Sbr Command

	// SAMPLE EXCHANGE POSITION MOVE
	memset(szCom, 0x00, sizeof(szCom));
	strcpy_s(szCom, "VL9,0;");
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom); // Sbr Command

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Stage Axis Emergency Stop Execute ( STAGE AXIS 긴급정지 실행)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeStageAxisEmergencyStopExecute(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// 2021.03.25
	// AXIS ALL STOP 으로 대체
	AfxScanBridgeASCommand();

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Stage Axis Reset Control Execute ( STAGE RESET CONTROL 실행)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeStageAxisResetControlExecute(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// 2021.04.02
	// STAGE RESET CONTROL

	// X-AXIS HOME 실행
	AfxScanBridgeMHCommand(IDX_X_AXIS);

	// Y-AXIS HOME 실행
	AfxScanBridgeMHCommand(IDX_Y_AXIS);

	// Z-AXIS HOME 실행
	AfxScanBridgeMHCommand(IDX_Z_AXIS);

	// STAGE AXIS 정보 읽기
	//AfxThreadCNCSendProcessing(NULL);

	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : SEM StandBy(대기모드) 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetSemStandbyMode(void)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// SEM 고압사용(HV_ON_STATE) 중 일 경우에만, 실행한다...
	if (m_pIntegrated->nSemVacState != HV_ON_STATE) return RET_SUCCESS_OK;

	//---------------------------------------------------------------------------------------------
	// Freeze Mode(일시정지 모드)
	//---------------------------------------------------------------------------------------------
	// 스캔 중인 이미지를 정지 시킨다 (SE Image Scan, Photo Image Scan, BSE Image Scan 등)
	m_pIntegrated->bScanDataReceive = FALSE; // SEM SE Image Scan 허용 Flag
	m_pIntegrated->bPhotoGoOnFlag   = FALSE; // SEM SE Image Photo Scan 허용 Flag
    
	// 기존 C++Builder 프로그램에서는 Image Update를 타이머로 처리하였음...
	//PhotoViewTimer->Enabled = false;       // SE Image Photo Scan 처리 타이머 : Interval 10[ms]
	//ImageViewTimer->Enabled = false;		 // SE Image Scan 처리 타이머: Interval 50[ms]
	// 프레임 ImgBuf_A에 입력된 영상을 Frame Average 값을 구한 후, m_pBitmap_A 에 저장하는 과정을
	// Thread에서 연속적인 작업과정을 진행하고,
	// ImageViewTimer에서는 Thread와 무관하게 Screen에 영상을 50ms 마다 반복적으로 표시한다.
	//---------------------------------------------------------------------------------------------

	// Gun HV 및 Bias HV 전압 등을 다운시킨다...
	m_pIntegrated->nGunHVCount   = 0;
	m_pIntegrated->nProcessValue = m_pIntegrated->nFilamentValue;
	m_pIntegrated->nGunHVProcess = FIL_HV_DOWN_PROC;
	// BSE 활성화 처리 설정
	m_pIntegrated->bBseActiveFlag = FALSE;

	return RET_SUCCESS_OK;
}
//---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Set SEM Air ON/OFF : ON->챔버 진공해제상태, OFF->진공중 또는 진공완료상태
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetSEMAirOnOff(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	char szCom[255 + 1];

	if (m_pIntegrated->nSemVacState == AIR_ON_STATE)
	{
		// Air-Off ( Evac ) -> (상태 : 진공 진행중...)
		// SB : Set Exchange Sample Position Pulse 으로 변경

		memset(szCom, 0x00, sizeof(szCom));
		strcpy_s(szCom, "AR0,0;"); // ScanBridgeBoard -> VacBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom);

		memset(szCom, 0x00, sizeof(szCom));
		strcpy_s(szCom, "SB1,0;"); // ScanBridgeBoard -> CncVacBoard (EM40)
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom);
	}
	else
	{
		// VAC_EVAC_STATE : 진공 진행중
		// VAC_OK_STATE   : 진공 상태
		// HV_ON_STATE    : 진공 상태가 HV 사용 가능 상태에 도달함
		// 챔버 진공(EVAC,VAC,HV)상태에서 -> 진공해제 상태로 전환...

		if (m_pIntegrated->nSemVacState == HV_ON_STATE)
		{
			// 진공상태 및 고압사용 상태이면...
			// HV On 상태이면, AIR ON 상태로 전환할 수 없다
			return RET_SUCCESS_OK;
		}

	    // Air-On -> (상태 : SEM 대기상태...)
	    // SB : Set Exchange Sample Position Pulse 으로 변경

		memset(szCom, 0x00, sizeof(szCom));
		strcpy_s(szCom, "AR0,1;"); // ScanBridgeBoard -> VacBoard
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom);

		memset(szCom, 0x00, sizeof(szCom));
		strcpy_s(szCom, "SB1,1;"); // ScanBridgeBoard -> CncVacBoard (EM40)
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom);
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Set SEM AIR ON ( CHAMBER OPEN )
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetSEMAirOnExecute(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	char szCom[255 + 1];

	if (m_pIntegrated->nSemVacState == HV_ON_STATE)
	{
		// HV On 상태이면, AIR ON 상태로 전환할 수 없다
		return RET_SUCCESS_OK;
	}

	// AIR-ON 상태 실행
	memset(szCom, 0x00, sizeof(szCom));
	strcpy_s(szCom, "AR0,1;"); // ScanBridgeBoard -> VacBoard
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom);

	// 대기
	//AfxSystemWaitTime(100);

	memset(szCom, 0x00, sizeof(szCom));
	strcpy_s(szCom, "SB1,1;"); // ScanBridgeBoard -> CncVacBoard (EM40)
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom);

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Set SEM AIR OFF ( CHAMBER CLOSE )
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetSEMAirOffExecute(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	char szCom[255 + 1];

	if (m_pIntegrated->nSemVacState == HV_ON_STATE)
	{
		// HV On 상태이면, AIR OFF 상태로 전환할 수 없다
		return RET_SUCCESS_OK;
	}

	// AIR-OFF (EVAC:진공 진행중) 상태 실행
	memset(szCom, 0x00, sizeof(szCom));
	strcpy_s(szCom, "AR0,0;"); // ScanBridgeBoard -> VacBoard
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom);

	// 대기
	//AfxSystemWaitTime(100);

	memset(szCom, 0x00, sizeof(szCom));
	strcpy_s(szCom, "SB1,0;"); // ScanBridgeBoard -> CncVacBoard (EM40)
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom);

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Set SEM VENT ( 강제 VENT, SEM SHUTDOWN 상태에서 사용 )
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetSEMDirectVentExecute(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	char szCom[255 + 1];

	// 2022.01.07
	// 강제 VENT 실행 ( 생산/기구팀 요청으로 실행 )
	memset(szCom, 0x00, sizeof(szCom));
	strcpy_s(szCom, "AR0,2;"); // ScanBridgeBoard -> VacBoard
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom);

	return RET_SUCCESS_OK;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Scan Bridge, Sem SE-Image, BSE Image Device Command Integrated(통합) Control...
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scintillator HV ON : 10kV
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedScintilatorHVOn(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// a) Scan Image Board에서
	m_pIntegrated->btImageAvrBPort |= NEW_DET_HV_ON;
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SEM_IMAGE_DEVICE, "MA5,", m_pIntegrated->btImageAvrBPort); // SE-Image Command 전송

	// b) SpellMan Scintillator ON
	//AfxIntegratedSpellmanScintilatorHVOn();

	return RET_SUCCESS_OK;
}
int AfxIntegratedSpellmanScintilatorHVOn(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// b) SpellMan Scintillator ON
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RG2,0;"); // Sbr Data 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scintillator HV OFF : 10kV
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedScintilatorHVOff(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// a) Scan Image Board에서
	m_pIntegrated->btImageAvrBPort &= NEW_DET_HV_OFF;
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SEM_IMAGE_DEVICE, "MA5,", m_pIntegrated->btImageAvrBPort); // SE-Image Command 전송

    // b) SpellMan Scintillator OFF
	//AfxIntegratedSpellmanScintilatorHVOff();

	return RET_SUCCESS_OK;
}
int AfxIntegratedSpellmanScintilatorHVOff(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// b) SpellMan Scintillator OFF
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RG2,1;"); // Sbr Data 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : PMT HV ON
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedPMTHVOn(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// a) Scan Image Board에서
	m_pIntegrated->btImageAvrBPort |= NEW_PMT_HV_ON;
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SEM_IMAGE_DEVICE, "MA5,", m_pIntegrated->btImageAvrBPort); // SE-Image Command 전송

    // b) SpellMan PMT ON
	//AfxIntegratedSpellmanPMTHVOn();

	return RET_SUCCESS_OK;
}
int AfxIntegratedSpellmanPMTHVOn(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// b) SpellMan PMT ON
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RG1,0;"); // Sbr Data 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : PMT HV OFF
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedPMTHVOff(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// a) Scan Image Board에서
	m_pIntegrated->btImageAvrBPort &= NEW_PMT_HV_OFF;
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SEM_IMAGE_DEVICE, "MA5,", m_pIntegrated->btImageAvrBPort); // SE-Image Command 전송

    // b) SpellMan PMT OFF
	//AfxIntegratedSpellmanPMTHVOff();

	return RET_SUCCESS_OK;
}
int AfxIntegratedSpellmanPMTHVOff(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// b) SpellMan PMT OFF
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RG1,1;"); // Sbr Data 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : PMT HV Relay ON
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetPMTHVRelayOn(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

    // a) Gnd 통합 Board에서
	m_pIntegrated->wRelayState |= PMT_HV_ON;
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_RelayCntl, m_pIntegrated->wRelayState); // SE-Image Command 전송

	// b) Gnd 분리 Board에서
	m_pIntegrated->btImgRelayState |= NEW_PMT_HV_ON;
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SEM_IMAGE_DEVICE, "MA5,", m_pIntegrated->btImgRelayState); // SE-Image Command 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : PMT HV Relay OFF
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetPMTHVRelayOff(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// a) Gnd 통합 Board에서
	m_pIntegrated->wRelayState &= PMT_HV_OFF;
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_RelayCntl, m_pIntegrated->wRelayState); // SE-Image Command 전송

    // b) Gnd 분리 Board에서
	m_pIntegrated->btImgRelayState &= NEW_PMT_HV_OFF;
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SEM_IMAGE_DEVICE, "MA5,", m_pIntegrated->btImgRelayState); // SE-Image Command 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : DET(Detection) HV ON
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedDETHVOn(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Detection HV ON

	// a) Scan Image Board에서
	m_pIntegrated->btImageAvrBPort |= NEW_DET_HV_ON;
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SEM_IMAGE_DEVICE, "MA5,", m_pIntegrated->btImageAvrBPort); // SE-Image Command 전송

    // b) SpellMan DET ON - Scintilator
	//AfxIntegratedSpellmanScintilatorHVOn();

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : DET(Detection) HV OFF
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedDETHVOff(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Detection HV OFF

	// a) Scan Image Board에서
	m_pIntegrated->btImageAvrBPort &= NEW_DET_HV_OFF;
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SEM_IMAGE_DEVICE, "MA5,", m_pIntegrated->btImageAvrBPort); // SE-Image Command 전송

	// b) SpellMan DET OFF
	//AfxIntegratedSpellmanScintilatorHVOff();

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : DET HV Relay ON
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetDETHVRelayOn(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// a) Gnd 통합 Board에서
	m_pIntegrated->wRelayState |= DET_HV_ON;
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_RelayCntl, m_pIntegrated->wRelayState); // SE-Image Command 전송

	// b) Gnd 분리 Board에서
	m_pIntegrated->btImgRelayState |= NEW_DET_HV_ON;
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SEM_IMAGE_DEVICE, "MA5,", m_pIntegrated->btImgRelayState); // SE-Image Command 전송

    // c) Image Scan Base All Board에서
	m_pIntegrated->btImgRelayState |= NEW_IR_LED_ON;
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SEM_IMAGE_DEVICE, "MA5,", m_pIntegrated->btImgRelayState); // SE-Image Command 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : DET HV Relay OFF
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetDETHVRelayOff(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// a) Gnd 통합 Board에서
	m_pIntegrated->wRelayState &= DET_HV_OFF;
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_RelayCntl, m_pIntegrated->wRelayState); // SE-Image Command 전송

	// b) Gnd 분리 Board에서
	m_pIntegrated->btImgRelayState &= NEW_DET_HV_OFF;
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SEM_IMAGE_DEVICE, "MA5,", m_pIntegrated->btImgRelayState); // SE-Image Command 전송

	// c) Image Scan Base All Board에서
	m_pIntegrated->btImgRelayState &= NEW_IR_LED_OFF;
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SEM_IMAGE_DEVICE, "MA5,", m_pIntegrated->btImgRelayState); // SE-Image Command 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : IMAGE CH2 ON ( BSE IMAGE )
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedBSEImageOn(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// IMAGE CH2 ON : BSE IMAGE

	// a) Scan Image Board에서
	m_pIntegrated->btImageAvrBPort |= NEW_IMG_CH2_ON;
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SEM_IMAGE_DEVICE, "MA5,", m_pIntegrated->btImageAvrBPort); // SE-Image Command 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : IMAGE CH2 OFF ( SE IMAGE )
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedBSEImageOff(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// IMAGE CH2 OFF : SE IMAGE

	// a) Scan Image Board에서
	m_pIntegrated->btImageAvrBPort &= NEW_IMG_CH2_OFF;
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SEM_IMAGE_DEVICE, "MA5,", m_pIntegrated->btImageAvrBPort); // SE-Image Command 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Emission Current 자동 수신 인터벌 타임 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetEmissionReceive(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// 1초 간격으로 Emission Current 자동 수신 설정
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "AE10;"); // Sbr Data 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Emission Current 자동 수신 인터벌 타임 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetEmissionReceiveStop(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Emission Current 자동 수신 설정 종료
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "AE0;"); // Sbr Data 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Contrast Value 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetContrast(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// 1) Image Board 에서 제어할 경우
	m_pIntegrated->nAD5361ContrastValue = AD5361_PMT + ((m_pIntegrated->nContrastValue + 4096) << 3);
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, m_pIntegrated->nAD5361ContrastValue); // SE-Image Command 전송

	// 2) Spellman 고압에서 제어할 경우
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RF", m_pIntegrated->nContrastValue); // Sbr Data 전송

	return RET_SUCCESS_OK;
}
int AfxIntegratedSetContrastZero(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// CONTRAST ZERO ( PMT HV ZERO )
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_PMT + (4096 << 3)); // SE-Image Command 전송

	return RET_SUCCESS_OK;
}
int AfxIntegratedSetContrast(int nContrast)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Contrast 설정
	m_pIntegrated->nContrastValue = nContrast;

	return RET_SUCCESS_OK;
}
int AfxIntegratedGetContrast(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Contrast 설정
	return m_pIntegrated->nContrastValue;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Brightness Value 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetBrightness(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Brightness 설정
	m_pIntegrated->nAD5361BrightnessValue = AD5361_BRT + (m_pIntegrated->nBrightValue << 4);
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, m_pIntegrated->nAD5361BrightnessValue); // SE-Image Command 전송

	return RET_SUCCESS_OK;
}
int AfxIntegratedSetBrightness(int nBright)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Brightness 설정
	m_pIntegrated->nBrightValue = nBright;

	return RET_SUCCESS_OK;
}
int AfxIntegratedGetBrightness(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Brightness 설정
	return m_pIntegrated->nBrightValue;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : W.D 값에 따른 OL전압, Scan Rotation, 배율보정을 적용할 것인지 여부 Flag
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetWDSetupFlag(BOOL bWDSetup)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Set W.D 값에 따른 OL전압, Scan Rotation, 배율보정
	m_pIntegrated->bWDSetupFlag = bWDSetup;

	return RET_SUCCESS_OK;
}
BOOL AfxIntegratedGetWDSetupFlag(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Get W.D 값에 따른 OL전압, Scan Rotation, 배율보정
	return m_pIntegrated->bWDSetupFlag;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : W.D 교정값 DISPLAY 여부 Flag
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetWDDataDisplayFlag(BOOL bWDSetup)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Set W.D 교정값 DISPLAY 여부 Flag
	m_pIntegrated->bWDDataDisplayFlag = bWDSetup;

	return RET_SUCCESS_OK;
}
BOOL AfxIntegratedGetWDDataDisplayFlag(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Get W.D 교정값 DISPLAY 여부 Flag
	return m_pIntegrated->bWDDataDisplayFlag;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Stage 수평값 적용 Check
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetStageHorAlign(BOOL bStageHorAlign)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 하드웨어 설정 기능은 사용하지 않으며, Check 여부에 따라 다른 Sub 기능에서 참조 하여 기능을 사용함.
	// Set Stage Hor Align Check
	m_pIntegrated->bStageHorAlignCheck = bStageHorAlign;

	return RET_SUCCESS_OK;
}
BOOL AfxIntegratedGetStageHorAlign(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Get Stage Hor Align Check
	return m_pIntegrated->bStageHorAlignCheck;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : WD S-Rotation 보정값 적용 Check
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetWDSRotationAdjust(BOOL bWDSRotationAdjust)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 하드웨어 설정 기능은 사용하지 않으며, Check 여부에 따라 다른 Sub 기능에서 참조 하여 기능을 사용함.
	// Set WD S-Rotation Adjust Check
	m_pIntegrated->bWDSRotationAdjustFlag = bWDSRotationAdjust;

	return RET_SUCCESS_OK;
}
BOOL AfxIntegratedGetWDSRotationAdjust(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Get WD S-Rotation Adjust Check
	return m_pIntegrated->bWDSRotationAdjustFlag;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : WD Scale Zooming 보정값 적용 Check
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetWDScaleZoomAdjust(BOOL bWDScaleZoomAdjust)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 하드웨어 설정 기능은 사용하지 않으며, Check 여부에 따라 다른 Sub 기능에서 참조 하여 기능을 사용함.
	// Set WD Scale Zooming Adjust Check
	m_pIntegrated->bWDScaleAdjustFlag = bWDScaleZoomAdjust;

	return RET_SUCCESS_OK;
}
BOOL AfxIntegratedGetWDScaleZoomAdjust(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Get WD Scale Zooming Adjust Check
	return m_pIntegrated->bWDScaleAdjustFlag;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Hitachi SM-2500 HV 10K 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetSM2500Hv10k(int nIndex)
{
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	// Hitachi SM-2500 HV 10K 설정
	switch (nIndex)
	{
		case  0: // All Off
		{
			//Sbr_StrAvrSend("PO0;"); 
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "PO0;"); // Sbr Data 전송
			break;
		}
		case  1: // Lower - POST1 - ON
		{
			//Sbr_StrAvrSend("PO1;"); 
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "PO1;"); // Sbr Data 전송
			break;
		}
		case  2: // Upper - POST2 - ON
		{
			//Sbr_StrAvrSend("PO2;"); 
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "PO2;"); // Sbr Data 전송
			break;
		}
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Rotation Value 설정 -> W.D 값에 따른 OL전압, Scan Rotation, 배율보정을 적용할 것인지 여부
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetScanRotationValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// W.D 값에 따른 보정값(사용자입력값)을 적용할 것인지 여부
	// 보정값 종류 : OLC(ObjectLensCoarse), Scan Rotation, 배율보정
	if (m_pIntegrated->bWDSetupFlag == TRUE)
	{
		// 이전 프로그램 작업한 내용
		// ScanRotation() 자동적으로 수행됨
		//HwSetupForm->WD_SRotCSpinEdit->Value = SRotationValue;

		// 2018.10.11
		// 니중에 작업을 추가한다
	}
	else
	{
		// Scan Rotation 설정 및 실행하기 
		//ScanRotation(SRotationValue);
		// Rotation 범위 : 0 ~ 3599 -> 0.0도~359.9도
		AfxScanBridgeSetScanRotation(nValue);
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Program Start SeCommand Value Set
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetSeCommandStartValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 스캔모드 설정
	m_pIntegrated->nScanMode = FAST_SCAN_MODE;

	// 프로그램 처음 시작시 SeCommand 값을 설정한다
	// 기존 프로그램에서는 필터값을 적용하여 0x0010(16) 이었다
	m_pIntegrated->nSeCommandValue &= SEL_FILT_MASK;
	m_pIntegrated->nSeCommandValue |= m_wFilter[m_pIntegrated->nFilterNum[m_pIntegrated->nScanMode]];
	// Se Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSeCommandValue);

	//AfxSystemWaitTime(100);

	// 프로그램 처음 시작시 CommandState 값을 설정한다
	// 기존 프로그램에서는 필터값을 적용하여 0 이었다
	m_pIntegrated->nSbrCommandState = 0;
	// Sbr Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSbrCommandState);

	//AfxSystemWaitTime(100);

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Screen Mode 설정 및 스캔 이미지 데이터 수집(쓰레드생성)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetScreenMode(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	//--------------------------------------------------------
	// SE + BSE 모드일 때,
	// Dual Screen Mode 또는 Full Screen Mode로 변경하려고 하는 경우,
	// 이를 금지시킨다.
	//--------------------------------------------------------

	//--------------------------------------------------------
	// 이미지 데이터 스캔(캡처) 작업 중지...
	//--------------------------------------------------------
	AfxIntegratedScanImageDataCaptureStop();
	//--------------------------------------------------------

	// 새로 설정된 스캔모드와 작업중인 스캔모드가 다를 경우
	if (m_pIntegrated->nScreenMode != m_pIntegrated->nWorkingScreenMode)
	{
		// 스캔모드 재설정 
		m_pIntegrated->nScreenMode = m_pIntegrated->nWorkingScreenMode;
		// Freeze 된 상태로 만들어야, 같은 Scan Mode 상태라도 Scan을 진행
		m_pIntegrated->bFreezeModeFlag = true;

		switch (m_pIntegrated->nScreenMode)
		{
			// Normal Mode
			case NORMAL_SCREEN:
			{
				// 웬캠 사용(실행) 여부
				if (m_pIntegrated->bWebCamRunFlag == TRUE)
				{
					// 이전 프로그램 : 웹캠 Stop/Start
				}
				else
				{
					// 이전 프로그램
					// 포토 스캔이미지 표시창 활성화
				}

				// 2020.05.11
				// 배율 설정하기
				AfxIntegratedSetMagnification(m_nMagStepValue[m_pIntegrated->nMagStepIndex], m_pIntegrated->nOLWD);

				//-------------------------------------------
				// 화면에 Box가 그려진 Dual Screen Mode에서
				// Normal Mode로 되돌아 올 경우
				// 화면에 그려진 Layer가 있으면 모두 지운다.
				//-------------------------------------------
				// 이전 프로그램
				// Dual Screen Mode에서 Normal Mode로 왔으므로
				//-------------------------------------------

				// Set FPGA
				m_pIntegrated->nSeCommandValue &= DUAL_SCREEN_LOW;
				AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSeCommandValue); // SE-Image Command 전송
				m_pIntegrated->nSbrCommandState &= DUAL_SCREEN_LOW;
				AfxFT232HPortSendCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSbrCommandState); // Sbr Data 전송

				// Fast Scan Run...
				//AfxIntegratedSetFastScanRun();

				break;
			}

			//------------------------------------------------
			// Dual Screen Mode
			//------------------------------------------------
			case DUAL_SCREEN:
			{
				break;
			}

			//------------------------------------------------
			// Full Screen Mode
			//------------------------------------------------
			case FULL_SCREEN:
			{
				break;
			}
		}

		// 이전 프로그램 : 관련자료 표시하기
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Image Data Capture 작업 시작
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetScanMode(int nScanMode)
{
	// 스캔모드
	m_pIntegrated->nScanMode = nScanMode;

	return RET_SUCCESS_OK;
}
int AfxIntegratedScanImageDataCaptureStart(int nScanMode)
{
	// 스캔모드
	m_pIntegrated->nScanMode = nScanMode;

	// Image Capture Start
	AfxIntegratedScanImageDataCaptureStart();

	return RET_SUCCESS_OK;
}
int AfxIntegratedScanImageDataCaptureStart(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;
	if (m_pSEImageDataThreadParams == NULL)return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// SE Image Data 스캔 허용 Flag 설정 ( STOP )
	m_pIntegrated->bScanDataReceive = FALSE;
	// SE Image Data Read Buffer Clear
	memset(m_pSEImageDataThreadParams->szFTReadBuf, 0x00, SCAN_IMAGE_PACKET_SIZE);

	// 스캔모드
	int nSM = m_pIntegrated->nScanMode;

	// Avr에서 Afc 종료가 입력되지 않는 경우 때문에 
	m_pIntegrated->nAutoAvrActionState = AUTO_HALT_ST;
	// X,Y Image Pixel 갯수
	m_pIntegrated->nXBmpPixelVal   = m_pIntegrated->nXBmpPixel[nSM];
	m_pIntegrated->nYBmpPixelVal   = m_pIntegrated->nYBmpPixel[nSM];
	// X,Y Bitmap Offset
	m_pIntegrated->nXBmpOffsetVal  = m_pIntegrated->nXBmpOffset[nSM];
	m_pIntegrated->nYBmpOffsetVal  = m_pIntegrated->nYBmpOffset[nSM];
	// Bitmap 이미지 Average - Data 갯수
	m_pIntegrated->nWAverageNumVal = m_pIntegrated->nWAverageNum[nSM];

	// Weighted Average : Scan 이미지 Average 사용시 프레임당 비율설정
	// 사용예: 1번프레임의Pixel값을 1/3만사용, 2번프레임의Pixel값을 2/3만사용 하여 합산
	// WAFrameNum = 2 : 1,2     (1+2)     (1/3, 2/3)
	//              3 : 1,2,3   (1+2+3)   (1/6, 2/6, 3/6)
	//              4 : 1,2,3,4 (1+2+3+4) (1/10, 2/10,3/10,4/10)
	m_pIntegrated->nWAFrameNumA        = 0;
	m_pIntegrated->nWAFrameNumB        = 0;
	m_pIntegrated->bLineNumberFlag     = false;
	m_pIntegrated->bFirstButtonPressed = true;

	/////////////////////////////////////////////////////////////////////////////////////////////
	// Image Capture Start : Se Command 설정
	/////////////////////////////////////////////////////////////////////////////////////////////

	// 2020.12.10
	// 초기화
	m_pIntegrated->nSeCommandValue = 0;

	// Capture Start/Stop Bit : D0 -> 1                                        // D7~D4  D3~D0
	m_pIntegrated->nSeCommandValue |= IMG_CAP_START_HIGH;                      // 0000   0001

	// Scan Mode 에 따른 SeCommand를 설정하여 적용한다
	if      (nSM == RED_SCAN_MODE   ) m_pIntegrated->nSeCommandValue |= 0x10;  // 0001   0000
	else if (nSM == FAST_SCAN_MODE  ) m_pIntegrated->nSeCommandValue |= 0x50;  // 0101   0000
	else if (nSM == SLOW1_SCAN_MODE ) m_pIntegrated->nSeCommandValue |= 0x50;  // 0101   0000
	else if (nSM == SLOW2_SCAN_MODE ) m_pIntegrated->nSeCommandValue |= 0x50;  // 0101   0000
	else if (nSM == PHOTO1_SCAN_MODE) m_pIntegrated->nSeCommandValue |= 0x50;  // 0101   0000
	else if (nSM == PHOTO2_SCAN_MODE) m_pIntegrated->nSeCommandValue |= 0x50;  // 0101   0000
	else if (nSM == PHOTO3_SCAN_MODE) m_pIntegrated->nSeCommandValue |= 0x90;  // 1001   0000
	else if (nSM == PHOTO4_SCAN_MODE) m_pIntegrated->nSeCommandValue |= 0x90;  // 1001   0000
	else if (nSM == PHOTO5_SCAN_MODE) m_pIntegrated->nSeCommandValue |= 0x90;  // 1001   0000
	else if (nSM == PHOTO6_SCAN_MODE) m_pIntegrated->nSeCommandValue |= 0xD0;  // 1101   0000

	// Se Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSeCommandValue); // m_SeCommand : 실행

	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////////
	// Image Capture Start : Sbr Command 설정
	/////////////////////////////////////////////////////////////////////////////////////////////

	// 2020.12.10
	// 초기화
	m_pIntegrated->nSbrCommandState = 0;

	// Capture Start/Stop Bit : D0 -> 1                             // D19~16  D15~12  D11~8   D7~4   D3~0
	m_pIntegrated->nSbrCommandState |= IMG_CAP_START_HIGH;          // 0000    0000    0000    0000   0001

	// Ac Sync : Off 설정
	m_pIntegrated->nSbrCommandState &= SYNC_SCAN_ON_LOW;

	if (nSM == RED_SCAN_MODE || nSM == FAST_SCAN_MODE)
	{
		// FRAME SYNC                                               // D19~16  D15~12  D11~8   D7~4   D3~0
		m_pIntegrated->nSbrCommandState |= 0x1000;                  // 0000    0001    0000    0000   0000     <-- FRAME SYNC
	}
	else
	{
		// LINE  SYNC                                               // D19~16  D15~12  D11~8   D7~4   D3~0
		m_pIntegrated->nSbrCommandState &= 0x0FFF;                  // 0000    0000    0000    0000   0000     <-- LINE  SYNC
	}

	// AC SYNC OFF
	// 스캔모드에 따른 SeCommand를 설정하여 적용한다
	if      (nSM == RED_SCAN_MODE   ) m_pIntegrated->nSbrCommandState |= 0x020000; // CommandState 값 설정 -> RED    : ( 0x00020001 )
	else if (nSM == FAST_SCAN_MODE  ) m_pIntegrated->nSbrCommandState |= 0x010000; // CommandState 값 설정 -> FAST   : ( 0x00010001 )
	else if (nSM == SLOW1_SCAN_MODE ) m_pIntegrated->nSbrCommandState |= 0x060000; // CommandState 값 설정 -> SLOW1  : ( 0x00060001 )
	else if (nSM == SLOW2_SCAN_MODE ) m_pIntegrated->nSbrCommandState |= 0x040000; // CommandState 값 설정 -> SLOW2  : ( 0x00040001 )
	else if (nSM == PHOTO1_SCAN_MODE) m_pIntegrated->nSbrCommandState |= 0x030000; // CommandState 값 설정 -> PHOTO1 : ( 0x00030001 )
	else if (nSM == PHOTO2_SCAN_MODE) m_pIntegrated->nSbrCommandState |= 0x020000; // CommandState 값 설정 -> PHOTO2 : ( 0x00020001 )
	else if (nSM == PHOTO3_SCAN_MODE) m_pIntegrated->nSbrCommandState |= 0x030000; // CommandState 값 설정 -> PHOTO3 : ( 0x00030001 )
	else if (nSM == PHOTO4_SCAN_MODE) m_pIntegrated->nSbrCommandState |= 0x020000; // CommandState 값 설정 -> PHOTO4 : ( 0x00020001 )
	else if (nSM == PHOTO5_SCAN_MODE) m_pIntegrated->nSbrCommandState |= 0x010000; // CommandState 값 설정 -> PHOTO5 : ( 0x00010001 )
	else if (nSM == PHOTO6_SCAN_MODE) m_pIntegrated->nSbrCommandState |= 0x020000; // CommandState 값 설정 -> PHOTO6 : ( 0x00020001 )
	else                              m_pIntegrated->nSbrCommandState |= 0x010000; // CommandState 값 설정 -> FAST   : ( 0x00010001 )

	// Sbr Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSbrCommandState);  // m_CommandState : 실행

	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////

	// SE Image Data Read Buffer Clear
	memset(m_pSEImageDataThreadParams->szFTReadBuf, 0x00, SCAN_IMAGE_PACKET_SIZE);
	// SE Image Data 스캔 허용 Flag 설정 ( START )
	m_pIntegrated->bScanDataReceive = TRUE;

	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////

	//------------------------------------------------------------------------------------------
	// BSE Board가 연결된 경우
	//------------------------------------------------------------------------------------------
	if (m_pIntegrated->bBseActiveFlag == TRUE)
	{
		// BSE BITMAP DISPLAY 포인터
		// 1) Bse OUTPORT 설정
		m_pIntegrated->nBseCommandValue |= IMG_CAP_START_HIGH;
		m_pIntegrated->nBseCommandValue &= SEL_SCAN_MASK;
		m_pIntegrated->nBseCommandValue |= m_pIntegrated->nFPGABmpSize[nSM] << 6;

		// 2) Filtering 값 설정 ( Avr에서 제어함 )
		m_pIntegrated->nBseCommandValue &= SEL_FILT_MASK;
		m_pIntegrated->nBseCommandValue |= m_wFilter[m_pIntegrated->nBseFilterIndex];

		// Bse Command 전송
		AfxFT232HPortSendCommand(IDX_FT232H_BSE_IMAGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nBseCommandValue);
	}
	//------------------------------------------------------------------------------------------

	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////

	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_IMAGE_SHIFT_X_REVERSE] == TRUE)
	{
		// 음영반전
		AfxSetSEMNegativeImageCheckFlag(m_pIntegrated->bNEGImageFlag, TRUE);
		// 좌우반전
		AfxSetSEMLRMirrorImageCheckFlag(m_pIntegrated->bLRMirrorFlag, TRUE);
		// 상하반전
		AfxSetSEMTBMirrorImageCheckFlag(m_pIntegrated->bTBMirrorFlag, TRUE);
	}

	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////

	return RET_SUCCESS_OK;
}
/*
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : SLOW1/2 Scan Image Data Capture 작업 시작
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSlow12ScanImageDataCaptureStart(int nScanMode)
{
	// 스캔모드
	m_pIntegrated->nScanMode = nScanMode;

	// Slow1/2 Scan Mode Image Capture Start
	AfxIntegratedSlow12ScanImageDataCaptureStart();

	return RET_SUCCESS_OK;
}
int AfxIntegratedSlow12ScanImageDataCaptureStart(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;
	if (m_pSEImageDataThreadParams == NULL)return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 스캔모드
	int nSM = m_pIntegrated->nScanMode;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Set   : Scan Mode, Filtering
	// Start : Scan
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/////////////////////////////////////////////////////////////////////////////////////////////
	// Image Capture Start : Se Command 설정
	/////////////////////////////////////////////////////////////////////////////////////////////

	// 2020.12.10
	// 초기화
	m_pIntegrated->nSeCommandValue = 0;

	// Capture Start/Stop Bit : D0 -> 1                                        // D7~D4  D3~D0
	m_pIntegrated->nSeCommandValue |= IMG_CAP_START_HIGH;                      // 0000   0001

	// Scan Mode 에 따른 SeCommand를 설정하여 적용한다
	if      (nSM == RED_SCAN_MODE   ) m_pIntegrated->nSeCommandValue |= 0x10;  // 0001   0000
	else if (nSM == FAST_SCAN_MODE  ) m_pIntegrated->nSeCommandValue |= 0x50;  // 0101   0000
	else if (nSM == SLOW1_SCAN_MODE ) m_pIntegrated->nSeCommandValue |= 0x50;  // 0101   0000
	else if (nSM == SLOW2_SCAN_MODE ) m_pIntegrated->nSeCommandValue |= 0x50;  // 0101   0000
	else if (nSM == PHOTO1_SCAN_MODE) m_pIntegrated->nSeCommandValue |= 0x50;  // 0101   0000
	else if (nSM == PHOTO2_SCAN_MODE) m_pIntegrated->nSeCommandValue |= 0x50;  // 0101   0000
	else if (nSM == PHOTO3_SCAN_MODE) m_pIntegrated->nSeCommandValue |= 0x90;  // 1001   0000
	else if (nSM == PHOTO4_SCAN_MODE) m_pIntegrated->nSeCommandValue |= 0x90;  // 1001   0000
	else if (nSM == PHOTO5_SCAN_MODE) m_pIntegrated->nSeCommandValue |= 0x90;  // 1001   0000
	else if (nSM == PHOTO6_SCAN_MODE) m_pIntegrated->nSeCommandValue |= 0xD0;  // 1101   0000

	// Se Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSeCommandValue); // m_SeCommand : 실행

	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////////
	// Image Capture Start : Sbr Command 설정
	/////////////////////////////////////////////////////////////////////////////////////////////

	// 2020.12.10
	// 초기화
	m_pIntegrated->nSbrCommandState = 0;

	// Capture Start/Stop Bit : D0 -> 1                             // D19~16  D15~12  D11~8   D7~4   D3~0
	m_pIntegrated->nSbrCommandState |= IMG_CAP_START_HIGH;          // 0000    0000    0000    0000   0001

	// Ac Sync : Off 설정
	m_pIntegrated->nSbrCommandState &= SYNC_SCAN_ON_LOW;

	if (nSM == RED_SCAN_MODE || nSM == FAST_SCAN_MODE)
	{
		// FRAME SYNC                                               // D19~16  D15~12  D11~8   D7~4   D3~0
		m_pIntegrated->nSbrCommandState |= 0x1000;                  // 0000    0001    0000    0000   0000     <-- FRAME SYNC
	}
	else
	{
		// LINE  SYNC                                               // D19~16  D15~12  D11~8   D7~4   D3~0
		m_pIntegrated->nSbrCommandState &= 0x0FFF;                  // 0000    0000    0000    0000   0000     <-- LINE  SYNC
	}

	// AC SYNC OFF
	// 스캔모드에 따른 SeCommand를 설정하여 적용한다
	if      (nSM == RED_SCAN_MODE   ) m_pIntegrated->nSbrCommandState |= 0x020000; // CommandState 값 설정 -> RED    : ( 0x00021001 )
	else if (nSM == FAST_SCAN_MODE  ) m_pIntegrated->nSbrCommandState |= 0x010000; // CommandState 값 설정 -> FAST   : ( 0x00011001 )
	else if (nSM == SLOW1_SCAN_MODE ) m_pIntegrated->nSbrCommandState |= 0x060000; // CommandState 값 설정 -> SLOW1  : ( 0x00060001 )
	else if (nSM == SLOW2_SCAN_MODE ) m_pIntegrated->nSbrCommandState |= 0x040000; // CommandState 값 설정 -> SLOW2  : ( 0x00040001 )
	else if (nSM == PHOTO1_SCAN_MODE) m_pIntegrated->nSbrCommandState |= 0x030000; // CommandState 값 설정 -> PHOTO1 : ( 0x00030001 )
	else if (nSM == PHOTO2_SCAN_MODE) m_pIntegrated->nSbrCommandState |= 0x020000; // CommandState 값 설정 -> PHOTO2 : ( 0x00020001 )
	else if (nSM == PHOTO3_SCAN_MODE) m_pIntegrated->nSbrCommandState |= 0x030000; // CommandState 값 설정 -> PHOTO3 : ( 0x00030001 )
	else if (nSM == PHOTO4_SCAN_MODE) m_pIntegrated->nSbrCommandState |= 0x020000; // CommandState 값 설정 -> PHOTO4 : ( 0x00020001 )
	else if (nSM == PHOTO5_SCAN_MODE) m_pIntegrated->nSbrCommandState |= 0x010000; // CommandState 값 설정 -> PHOTO5 : ( 0x00010001 )
	else if (nSM == PHOTO6_SCAN_MODE) m_pIntegrated->nSbrCommandState |= 0x020000; // CommandState 값 설정 -> PHOTO6 : ( 0x00020001 )
	else                              m_pIntegrated->nSbrCommandState |= 0x010000; // CommandState 값 설정 -> FAST   : ( 0x00011001 )

	// Sbr Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSbrCommandState);  // m_CommandState : 실행

	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////

	//------------------------------------------------------------------------------------------
	// BSE Board가 연결된 경우
	//------------------------------------------------------------------------------------------
	if (m_pIntegrated->bBseActiveFlag == TRUE)
	{
		// BSE BITMAP DISPLAY 포인터
		// 1) Bse OUTPORT 설정
		m_pIntegrated->nBseCommandValue |= IMG_CAP_START_HIGH;
		m_pIntegrated->nBseCommandValue &= SEL_SCAN_MASK;
		m_pIntegrated->nBseCommandValue |= m_pIntegrated->nFPGABmpSize[nSM] << 6;

		// 2) Filtering 값 설정 ( Avr에서 제어함 )
		m_pIntegrated->nBseCommandValue &= SEL_FILT_MASK;
		m_pIntegrated->nBseCommandValue |= m_wFilter[m_pIntegrated->nBseFilterIndex];

		// Bse Command 전송
		AfxFT232HPortSendCommand(IDX_FT232H_BSE_IMAGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nBseCommandValue);
	}
	//------------------------------------------------------------------------------------------

	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////

	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_IMAGE_SHIFT_X_REVERSE] == TRUE)
	{
		// 음영반전
		AfxSetSEMNegativeImageCheckFlag(m_pIntegrated->bNEGImageFlag, TRUE);
		// 좌우반전
		AfxSetSEMLRMirrorImageCheckFlag(m_pIntegrated->bLRMirrorFlag, TRUE);
		// 상하반전
		AfxSetSEMTBMirrorImageCheckFlag(m_pIntegrated->bTBMirrorFlag, TRUE);
	}

	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////

	return RET_SUCCESS_OK;
}
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Image Data Capture 작업 중지
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedScanImageDataCaptureStop()
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// SE Image Data 스캔 허용 Flag 설정 ( STOP )
	m_pIntegrated->bScanDataReceive = FALSE;

	//---------------------------------------
	// SE Image Sampling Capture Stop
	//---------------------------------------
	m_pIntegrated->nSeCommandValue &= IMG_CAP_START_LOW;
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSeCommandValue); // SE-Image Command 전송

	m_pIntegrated->nSbrCommandState &= IMG_CAP_START_LOW;
	AfxFT232HPortSendCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSbrCommandState); // Sbr Command 전송

	//---------------------------------------
	// BSE Image Sampling Capture Stop
	//---------------------------------------
	// BSE Thread가 종료될 때 까지
	if (m_pIntegrated->nBseDetectorValue == SE_BSE_DETECTOR)
	{
		m_pIntegrated->nBseCommandValue &= IMG_CAP_START_LOW;
		AfxFT232HPortSendCommand(IDX_FT232H_BSE_IMAGE_DEVICE, bWR_OUTPORT, m_pIntegrated->nBseCommandValue); // BSE-Image Command 전송
	}
	//---------------------------------------

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Initialize Parameters (파라메터 초기화)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedInitializeParameters(int nSemType)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	//------------------------------------------------------
	// 4 x 4.8MHz = 19,200,000 => 38,400,000 => 57,600,000
	//------------------------------------------------------
	// 4 x  640 x  250 x 30  =>  320x240
	// 2 x 1280 x  500 x 15  =>  640x480
	// 1 x 2560 x 1000 x 7.5 => 1280x960
	//------------------------------------------------------
	//------------------------------------------------------
	// 4 x 4.5MHz = 18,000,000 => 36,000,000 => 54,000,000
	//------------------------------------------------------
	// 4 x  600 x  250 x 30  =>  320x240
	// 2 x 1200 x  500 x 15  =>  640x480
	// 1 x 2400 x 1000 x 7.5 => 1280x960
	//------------------------------------------------------
    //------------------------------------------------------
	// 4 x 4.125MHz = 16,500,000 => 33,000,000 => 49,500,000
	//------------------------------------------------------
	// 4 x  550 x  250 x 30  =>  320x240
	// 2 x 1000 x  500 x 15  =>  640x480
	// 1 x 2000 x 1000 x 7.5 => 1280x960
	//------------------------------------------------------
	//------------------------------------------------------
	// 500 x 250 x 30 = 3.75MHz
	// 4 x 3.75MHz = 15MHz => 30MHz
	//------------------------------------------------------
	//  8 x  500(x) x  250(y) x 30  = 30MHz
	//  4 x 1000(x) x  500(y) x 15  = 30MHz
	//  2 x 2000(x) x 1000(y) x 7.5 = 30MHz
	//------------------------------------------------------
	//------------------------------------------------------
	// 500 x 250 x 30frame = 3750000 = 3.75MHz
	//------------------------------------------------------

	////////////////////////////////////////////////////////////////////////////////////////////
	// 초기화 화일이 없을 때 초기화 데이터
	////////////////////////////////////////////////////////////////////////////////////////////
	//------------------------------------------------------------------------------------------
	// SyncFreqNum :  0       1      2     3     4     5     6      7        8     9       10
	//               /16     /8     /4    /2    x1    x2     x4     x8     x16    x32     x64
	// Sync Freq   : 3.75Hz, 7.5Hz, 15Hz, 30Hz, 60Hz, 120Hz, 240Hz, 480Hz, 960Hz, 1920Hz, 3840Hz
	//------------------------------------------------------------------------------------------
	// Frame Sync  :   0      0      0     0     x      x      x      x      x      x      x
	// Line  Sync  :   x      0      0     0     0      0      0      0      0      0      0
	//------------------------------------------------------------------------------------------

	//------------------------------------------------------
	// FT2_BridgeScan VHDL CommandPort의 m_CommandState 값
	//------------------------------------------------------
	//ReScanStart  => image_cap_start,  -- D0 : img_scan_reset 발생
	//MultiFrame   => auto_focus_start, -- D1 : Auto Focus 시작, 반복실행
	//NormalScan   => auto_focus_mode,  -- D2 :
	//SelFilter    => open,             -- D5, D4, D3
	//SelScan      => open,             -- D9, D8, D7, D6
	//FrameSync    => frame_sync_flag,  -- D10
	//DualScreenOn => dual_screen_on,   -- D11
	//ScanOnFlag   => pll_60hz_flag,    -- D12 : scan_active,
	//XScanInverse => xscan_inverse,    -- D13
	//YScanInverse => yscan_inverse,    -- D14
	//SyncScanOn   => sync_scan_on,     -- D15
	//SelSyncFreq  => sync_freq_mode    -- D19, D18, D17, D16
	//------------------------------------------------------
	//------------------------------------------------------
	// Frame Sync,  30Hz => 0011 0000 0100 0000 0000
	//                      ^  ^       ^
	//                      D..D       D
	//                      1..1       1
	//                      9..6       0
	//------------------------------------------------------
	// Line  Sync, 480Hz => 0111 0000 0000 0000 0000
	//                      ^  ^       ^
	//                      D..D       D
	//                      1..1       1
	//                      9..6       0
	//------------------------------------------------------

	m_pIntegrated->nPLLClk = PLL_SCAN_CLOCK;

	//--------------------------------------------------------------------------
	// Half Red Scan Mode : 320x240 ( 500x250 = 125,000 Hz)
	// Frame Sync Freq    : 30Hz, 15Hz, 7.5Hz
	//--------------------------------------------------------------------------
	m_pIntegrated->nScanClk[0] = 3750000; // (125kHz x 30)   // HalfRed 1 - < 30  Frame/sec >
	m_pIntegrated->nSyncVal[0] = 0x31000; // ( 30Hz, Frame Sync )
	m_pIntegrated->nScanClk[1] = 1875000; // (125kHz x 15)   // HalfRed 2 - < 15  Frame/sec >
	m_pIntegrated->nSyncVal[1] = 0x21000; // ( 15Hz, Frame Sync )
	m_pIntegrated->nScanClk[2] = 937500;  // (125kHz x 7.5)  // HalfRed 3 - < 7.5 Frame/sec >
	m_pIntegrated->nSyncVal[2] = 0x11000; // ( 7.5Hz, Frame Sync )
    //--------------------------------------------------------------------------
	// Full Red Scan Mode : 640x480 ( 1000x500 = 500,000 Hz)
	// Frame Sync Freq    : 15Hz, 7.5Hz, 3.75Hz
	//--------------------------------------------------------------------------
	m_pIntegrated->nScanClk[3] = 7500000; // (500kHz x 15)   // FullRed 1 - < 15   Frame/sec >
	m_pIntegrated->nSyncVal[3] = 0x21000; // ( 15Hz, Frame Sync )
	m_pIntegrated->nScanClk[4] = 3750000; // (500kHz x 7.5)  // FullRed 2 - < 7.5  Frame/sec >
	m_pIntegrated->nSyncVal[4] = 0x11000; // ( 7.5Hz, Frame Sync )
	m_pIntegrated->nScanClk[5] = 1875000; // (500kHz x 3.75) // FullRed 3 - < 3.75 Frame/sec >
	m_pIntegrated->nSyncVal[5] = 0x01000; // ( 3.75Hz, Frame Sync )
    //--------------------------------------------------------------------------
    // Half Fast Scan Mode : 640x480 ( 1000x500 = 500,000 Hz)
    // Frame Sync Freq     : 15Hz, 7.5Hz, 3.75Hz
    //--------------------------------------------------------------------------
	m_pIntegrated->nScanClk[6] = 7500000; // (500kHz x 15)   // HalfFast 1 - < 15   Frame/sec >
	m_pIntegrated->nSyncVal[6] = 0x21000; // ( 15Hz, Frame Sync )
	m_pIntegrated->nScanClk[7] = 3750000; // (500kHz x 7.5)  // HalfFast 2 - < 7.5  Frame/sec >
	m_pIntegrated->nSyncVal[7] = 0x11000; // ( 7.5Hz, Frame Sync )
	m_pIntegrated->nScanClk[8] = 1875000; // (500kHz x 3.75) // HalfFast 3 - < 3.75 Frame/sec >
	m_pIntegrated->nSyncVal[8] = 0x01000; // ( 3.75Hz, Frame Sync )
	//----------------------------------------------
	// Half Slow Scan Mode : 640x480 ( 1000 x 500 )
	// Line Sync Freq      : 240Hz, 120Hz, 60Hz
	//----------------------------------------------
	// 1 frame = (1/240) x  500(line) = 2.08 sec  <= 240Hz LineSyncFreq
	// 1 frame = (1/120) x  500(line) = 4.16 sec  <= 120Hz LineSyncFreq
	// 1 frame = (1/60)  x  500(line) = 8.33 sec  <=  60Hz LineSyncFreq
	m_pIntegrated->nScanClk[9]  = 240000;  // (240Hz x 1000) // HalfSlow 1 - < 2.08 sec/frame = 0.48 Frame/sec >
	m_pIntegrated->nSyncVal[9]  = 0x60000; // (240Hz, Line Sync)
	m_pIntegrated->nScanClk[10] = 120000;  // (120Hz x 1000) // HalfSlow 2 - < 4.16 sec/frame = 0.24 Frame/sec >
	m_pIntegrated->nSyncVal[10] = 0x50000; // (120Hz, Line Sync)
	m_pIntegrated->nScanClk[11] = 60000;   // ( 60Hz x 1000) // HalfSlow 3 - < 8.33 sec/frame = 0.12 Frame/sec >
	m_pIntegrated->nSyncVal[11] = 0x40000; // ( 60Hz, Line Sync)
	//--------------------------------------------------------------------------
	// Full Fast Scan Mode : 1280 x 960 ( 2000 x 1000 )
	// Line Sync Freq      : 3840Hz, 1920Hz, 960Hz
	//--------------------------------------------------------------------------
	// 1 frame = (1/3840) x 1000(line) =  3.84 fr/sec
	// 1 frame = (1/1920) x 1000(line) =  1.92 fr/sec
	// 1 frame = (1/960)  x 1000(line) =   0.96 fr/sec = 1.04 sec/fr
	m_pIntegrated->nScanClk[12] = 7500000; // (3840Hz x 1954pix) // Full Fast1   - <  3.8 Frame/sec >
	m_pIntegrated->nSyncVal[12] = 0xA0000; // (3840Hz, Line Sync)
	m_pIntegrated->nScanClk[13] = 3750000; // (1920Hz x 1954pix) // Full Fast2   - <  1.9 Frame/sec >
	m_pIntegrated->nSyncVal[13] = 0x90000; // (1920Hz, Line Sync)
	m_pIntegrated->nScanClk[14] = 1875000; // ( 960Hz x 1954pix) // Full Fast3   - <  0.9 Frame/sec >
	m_pIntegrated->nSyncVal[14] = 0x80000; // ( 960Hz, Line Sync)
	//--------------------------------------------------------------------------
	// Full Slow Scan Mode : 1280 x 960 ( 2000 x 1000 )
	// Line Sync Freq      : 480Hz, 240Hz, 120Hz
	//--------------------------------------------------------------------------
	// 1 frame = (1/480) x  1000(line) =  2.08 sec/fr
	// 1 frame = (1/240) x  1000(line) =  4.16 sec/fr
	// 1 frame = (1/120) x  1000(line) =  8.33 sec/fr
	// 1 frame = (1/60)  x  1000(line) =  16.6 sec/fr
	m_pIntegrated->nScanClk[15] = 1000000;  // (480Hz x 2084pix) // Full Slow1 - <  2.08 sec/frame >
	m_pIntegrated->nSyncVal[15] = 0x70000;  // (480Hz, Line Sync)
	m_pIntegrated->nScanClk[16] = 500000;   // (240Hz x 2084pix) // Full Slow2 - <  4.16 sec/frame >
	m_pIntegrated->nSyncVal[16] = 0x60000;  // (240Hz, Line Sync)
	m_pIntegrated->nScanClk[17] = 240000;   // (120Hz x 2000pix) // Full Slow3 - <  8.33 sec/frame >
	m_pIntegrated->nSyncVal[17] = 0x50000;  // (120Hz, Line Sync)
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	// Photo Scan Mode
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	//  640 x 480
	// 1200 x 500 x (1/15 sec) = 40000 = 40kHz
	// 1 line = 60Hz x 1920 = 57.6kHz
	//---------------------------------
	// Photo : 640 x 480
	// Line Sync Freq    : 30Hz, 15Hz
	//---------------------------------
	// 1 frame = (1/30) x 480(line) = 16 sec
	// 1 frame = (1/15) x 480(line) = 32 sec
	m_pIntegrated->nScanClk[18] = 30000;   // ( 30Hz x 1000pix ) // Photo1 < 16 sec/frame >
	m_pIntegrated->nSyncVal[18] = 0x30000; // ( 30Hz, Line Sync)
	m_pIntegrated->nScanClk[19] = 15000;   // ( 15Hz x 1000pix ) // Photo2 < 32 sec/frame >
	m_pIntegrated->nSyncVal[19] = 0x20000; // ( 15Hz, Line Sync)
	//---------------------------------------
	// Photo : 1280 x 960
	// Line Sync Freq    : 30Hz, 15Hz, 7.5Hz
	//---------------------------------------
	// 1 frame = (1/30)  x 960(line) =  32 sec
	// 1 frame = (1/15)  x 960(line) =  64 sec
	// 1 frame = (1/7.5) x 960(line) = 128 sec
	m_pIntegrated->nScanClk[20] = 60000;    // ( 30Hz x 2000pix ) // Photo3 <  32 sec/frame >
	m_pIntegrated->nSyncVal[20] = 0x30000;  // ( 30Hz, Line Sync)
	m_pIntegrated->nScanClk[21] = 30000;    // ( 15Hz x 2000pix ) // Photo4 <  64 sec/frame >
	m_pIntegrated->nSyncVal[21] = 0x20000;  // ( 15Hz, Line Sync)
	m_pIntegrated->nScanClk[22] = 15000;    // ( 7.5Hz x 2000pix ) // Photo5 < 128 sec/frame >
	m_pIntegrated->nSyncVal[22] = 0x10000;  // ( 7.5Hz, Line Sync)
	//--------------------------------------
	// Photo : 2560 x 1920  => 5120 x 3840
	//--------------------------------------
	// 1 frame = (1/30) x  1920(line) =  64 sec // not used
	// 1 frame = (1/15) x  1920(line) = 128 sec
	m_pIntegrated->nScanClk[23] = 60000;    // ( 15Hz x 4000pix ) // Photo6 < 128 sec/frame >
	m_pIntegrated->nSyncVal[23] = 0x20000;  // ( 15Hz, Line Sync)
	//-------------------
	// WFM Mode
	//-------------------
	m_pIntegrated->nScanClk[24] = 120000;      // WFM
	//-------------------
	// Auto Focus Mode
	//-------------------
	// 36,000,000/480,000 = 75
	// OverSampling   = 150;
	m_pIntegrated->nScanClk[25] = 450000;      // Auto Focus - Slow1 Speed
	//--------------------------------------------------------------------------
	// Half Red Scan Mode : 320x240
	//  30 x 250 x 640
	//--------------------------------------------------------------------------
	// 0 : Half Red  1  -  < 30 Frame/sec >
	m_pIntegrated->nFPGABmpSize[0]   = 0;        // 320x240
	m_pIntegrated->nScanCodeA[0]     = 0xA0FF;
	m_pIntegrated->nScanCodeB[0]     = 0xB0FF;
	m_pIntegrated->nXScanUpNum[0]    = 1024;     // 550
	m_pIntegrated->nXScanDownNum[0]  = 256;      //  50
	m_pIntegrated->nYScanUpNum[0]    = 244;      // 244
	m_pIntegrated->nYScanDownNum[0]  = 4;        //   6
	m_pIntegrated->nXBmpPixel[0]     = 320;
	m_pIntegrated->nYBmpPixel[0]     = 240;
	m_pIntegrated->nXBmpOffset[0]    = 160;
	m_pIntegrated->nYBmpOffset[0]    = 120;
	m_pIntegrated->nWAverageNum[0]   = 1;
	m_pIntegrated->nFilterNum[0]     = 1;
	m_pIntegrated->nXScanAmpVal[0]   = 1057;     // 417;
	m_pIntegrated->nXScanOffset[0]   = 160;      // 30;
	m_pIntegrated->nYScanAmpVal[0]   = 539;
	m_pIntegrated->nYScanOffset[0]   = 0;
	m_pIntegrated->nSkipPixNum[0]    = 115;      // 0 - 499
	m_pIntegrated->nFrameSec[0]      = 30000;    // 30 f/s
	m_pIntegrated->nOverSampleNum[0] = 10;
	//--------------------------------------------------------------------------
	// 1 : Half Red  2  -  <  15 Frame/sec >     <<<<< RED SCAN MODE >>>>>
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[1]   = 0;        // 320x240
	m_pIntegrated->nScanCodeA[1]     = 0xA0FF;   // Default
	m_pIntegrated->nScanCodeB[1]     = 0xB0FF;   // Default
	m_pIntegrated->nXScanUpNum[1]    = 1024;     // X Scan Up   Value
	m_pIntegrated->nXScanDownNum[1]  = 128;      // X Scan Down Value
	m_pIntegrated->nYScanUpNum[1]    = 243;      // Y Scan Up   Value
	m_pIntegrated->nYScanDownNum[1]  = 28;       // Y Scan Down Value
	m_pIntegrated->nXBmpPixel[1]     = 320;      // X PIXEL WIDTH
	m_pIntegrated->nYBmpPixel[1]     = 240;      // Y PIXEL HEIGHT 
	m_pIntegrated->nXBmpOffset[1]    = 160;      // X PIXEL OFFSET
	m_pIntegrated->nYBmpOffset[1]    = 120;      // Y PIXEL OFFSET
	m_pIntegrated->nWAverageNum[1]   = 6;        // Frame Average : 6
	m_pIntegrated->nFilterNum[1]     = 1;        // Filter ( 0->0x0008, 1->0x0010, 2->0x0020, 3->0x8000 )
	m_pIntegrated->nXScanAmpVal[1]   = 1586;     // 1586,  3.87[v] : X축 배율보정 (크기)
	m_pIntegrated->nXScanOffset[1]   = 1565;     // 1565, -1.18[v] : X축 위치보정 (센터)
	m_pIntegrated->nYScanAmpVal[1]   = 747;      //  747,  1.82[v] : Y축 배율보정 (크기)
	m_pIntegrated->nYScanOffset[1]   = 2030;     // 2030, -0.04[v] : Y축 위치보정 (센터)
	m_pIntegrated->nSkipPixNum[1]    = 258;      // 0 - 499 -> SCAN SKIP PIXEL COUNT ( 일그러진 SCAN 이미지 SKIP )
	m_pIntegrated->nFrameSec[1]      = 15000;    // 15[f/s]
	m_pIntegrated->nOverSampleNum[1] = 17;       // Over Sampling Value
	//--------------------------------------------------------------------------
	// 2 : Half Red  3  -  <  7.5 Frame/sec >
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[2]   = 0;        // 320x240
	m_pIntegrated->nScanCodeA[2]     = 0xA0FF;   // 0xFF01;
	m_pIntegrated->nScanCodeB[2]     = 0xB0FF;   // 0xFFB1;
	m_pIntegrated->nXScanUpNum[2]    = 1024;     // 600
	m_pIntegrated->nXScanDownNum[2]  = 64;       //
	m_pIntegrated->nYScanUpNum[2]    = 244;      // 250
	m_pIntegrated->nYScanDownNum[2]  = 4;
	m_pIntegrated->nXBmpPixel[2]     = 320;
	m_pIntegrated->nYBmpPixel[2]     = 240;
	m_pIntegrated->nXBmpOffset[2]    = 160;
	m_pIntegrated->nYBmpOffset[2]    = 120;
	m_pIntegrated->nWAverageNum[2]   = 1;
	m_pIntegrated->nFilterNum[2]     = 1;
	m_pIntegrated->nXScanAmpVal[2]   = 741;
	m_pIntegrated->nXScanOffset[2]   = 178;      // 34;
	m_pIntegrated->nYScanAmpVal[2]   = 541;
	m_pIntegrated->nYScanOffset[2]   = 0;
	m_pIntegrated->nSkipPixNum[2]    = 13;       // 0 - 499
	m_pIntegrated->nFrameSec[2]      = 7500;     // 7.5frame
	m_pIntegrated->nOverSampleNum[2] = 53;       // XScan Freq. => 1.8kHz
	//--------------------------------------------------------------------------
	// Full Red Scan Mode : 640x480
	//--------------------------------------------------------------------------
	// 3 : Full Red  1  -  < 15 Frame/sec >
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[3]   = 1;        // 640x480
	m_pIntegrated->nScanCodeA[3]     = 0xA1FF;   //
	m_pIntegrated->nScanCodeB[3]     = 0xB1FF;   //
	m_pIntegrated->nXScanUpNum[3]    = 2048;     // 1200
	m_pIntegrated->nXScanDownNum[3]  = 256;      //
	m_pIntegrated->nYScanUpNum[3]    = 484;      //  500
	m_pIntegrated->nYScanDownNum[3]  = 4;        //
	m_pIntegrated->nXBmpPixel[3]     = 640;
	m_pIntegrated->nYBmpPixel[3]     = 480;
	m_pIntegrated->nXBmpOffset[3]    = 320;
	m_pIntegrated->nYBmpOffset[3]    = 240;
	m_pIntegrated->nWAverageNum[3]   = 6;
	m_pIntegrated->nFilterNum[3]     = 1;
	m_pIntegrated->nXScanAmpVal[3]   = 1077;
	m_pIntegrated->nXScanOffset[3]   = 30;
	m_pIntegrated->nYScanAmpVal[3]   = 547;
	m_pIntegrated->nYScanOffset[3]   = 0;
	m_pIntegrated->nSkipPixNum[3]    = 269;      // 0 - 499
	m_pIntegrated->nFrameSec[3]      = 15000;    // 15f/s
	m_pIntegrated->nOverSampleNum[3] = 5;        // XScan Freq. => 3.6kHz
	//--------------------------------------------------------------------------
	// 4 : Full Red  2  -   <  7.5 Frame/sec >
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[4]   = 1;        // 640x480
	m_pIntegrated->nScanCodeA[4]     = 0xA1FF;   //
	m_pIntegrated->nScanCodeB[4]     = 0xB1FF;   //
	m_pIntegrated->nXScanUpNum[4]    = 2048;     // 1200
	m_pIntegrated->nXScanDownNum[4]  = 128;      //
	m_pIntegrated->nYScanUpNum[4]    = 484;      // 500
	m_pIntegrated->nYScanDownNum[4]  = 4;        //
	m_pIntegrated->nXBmpPixel[4]     = 640;
	m_pIntegrated->nYBmpPixel[4]     = 480;
	m_pIntegrated->nXBmpOffset[4]    = 320;
	m_pIntegrated->nYBmpOffset[4]    = 240;
	m_pIntegrated->nWAverageNum[4]   = 1;
	m_pIntegrated->nFilterNum[4]     = 1;
	m_pIntegrated->nXScanAmpVal[4]   = 864;
	m_pIntegrated->nXScanOffset[4]   = 136;
	m_pIntegrated->nYScanAmpVal[4]   = 544;
	m_pIntegrated->nYScanOffset[4]   = 0;
	m_pIntegrated->nSkipPixNum[4]    = 86;       // 0 - 499
	m_pIntegrated->nFrameSec[4]      = 7500;     // 7.5f/s
	m_pIntegrated->nOverSampleNum[4] = 12;
	//--------------------------------------------------------------------------
	// 5 : Full Red  3  -   <  3.8 Frame/sec >
	// 5 : Full Red  3  -   <  3.25 Frame/sec >
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[5]   = 1;        // 640x480
	m_pIntegrated->nScanCodeA[5]     = 0xA1FF;   //
	m_pIntegrated->nScanCodeB[5]     = 0xB1FF;   //
	m_pIntegrated->nXScanUpNum[5]    = 2048;     // 1200
	m_pIntegrated->nXScanDownNum[5]  = 64;       //
	m_pIntegrated->nYScanUpNum[5]    = 484;      //  500
	m_pIntegrated->nYScanDownNum[5]  = 4;        //
	m_pIntegrated->nXBmpPixel[5]     = 640;
	m_pIntegrated->nYBmpPixel[5]     = 480;
	m_pIntegrated->nXBmpOffset[5]    = 320;
	m_pIntegrated->nYBmpOffset[5]    = 240;
	m_pIntegrated->nWAverageNum[5]   = 1;
	m_pIntegrated->nFilterNum[5]     = 1;
	m_pIntegrated->nXScanAmpVal[5]   = 774;
	m_pIntegrated->nXScanOffset[5]   = 115;
	m_pIntegrated->nYScanAmpVal[5]   = 544;
	m_pIntegrated->nYScanOffset[5]   = 0;
	m_pIntegrated->nSkipPixNum[5]    = 38;       // 0 - 499
	m_pIntegrated->nFrameSec[5]      = 3750;     // 3.75f/s
	m_pIntegrated->nOverSampleNum[5] = 26;       // XScan Freq. => 1.8kHz
	//--------------------------------------------------------------------------
	// Half Fast Scan Mode
	//--------------------------------------------------------------------------
	// 6 : Half Fast High   -  < 15 Frame/sec >
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[6]   = 1;        // 640x480
	m_pIntegrated->nScanCodeA[6]     = 0xA1FF;
	m_pIntegrated->nScanCodeB[6]     = 0xB1FF;
	m_pIntegrated->nXScanUpNum[6]    = 2048;     // 1200
	m_pIntegrated->nXScanDownNum[6]  = 256;      //
	m_pIntegrated->nYScanUpNum[6]    = 484;      //  500
	m_pIntegrated->nYScanDownNum[6]  = 4;        //
	m_pIntegrated->nXBmpPixel[6]     = 640;
	m_pIntegrated->nYBmpPixel[6]     = 480;
	m_pIntegrated->nXBmpOffset[6]    = 0;
	m_pIntegrated->nYBmpOffset[6]    = 0;
	m_pIntegrated->nWAverageNum[6]   = 1;
	m_pIntegrated->nFilterNum[6]     = 1;
	m_pIntegrated->nXScanAmpVal[6]   = 2047;     //1823;
	m_pIntegrated->nXScanOffset[6]   = 0;
	m_pIntegrated->nYScanAmpVal[6]   = 1045;
	m_pIntegrated->nYScanOffset[6]   = 0;
	m_pIntegrated->nSkipPixNum[6]    = 273;      // 0 - 719                             1
	m_pIntegrated->nFrameSec[6]      = 15000;    // 15f/s
	m_pIntegrated->nOverSampleNum[6] = 5;        // XScan Freq. => 3.6kHz
	//--------------------------------------------------------------------------
	// 7 : Half Fast Middle - <  7.5 Frame/sec > <<<<< FAST SCAN MODE >>>>>
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[7]   = 1;        // 640x480
	m_pIntegrated->nScanCodeA[7]     = 0xA1FF;   // Default
	m_pIntegrated->nScanCodeB[7]     = 0xB1FF;   // Default
	m_pIntegrated->nXScanUpNum[7]    = 2048;     // X Scan Up   Value
	m_pIntegrated->nXScanDownNum[7]  = 128;      // X Scan Down Value
	m_pIntegrated->nYScanUpNum[7]    = 481;      // Y Scan Up   Value
	m_pIntegrated->nYScanDownNum[7]  = 22;       // Y Scan Down Value
	m_pIntegrated->nXBmpPixel[7]     = 640;      // X PIXEL WIDTH
	m_pIntegrated->nYBmpPixel[7]     = 480;      // Y PIXEL HEIGHT 
	m_pIntegrated->nXBmpOffset[7]    = 0;        // X PIXEL OFFSET
	m_pIntegrated->nYBmpOffset[7]    = 0;        // Y PIXEL OFFSET
	m_pIntegrated->nWAverageNum[7]   = 6;        // Frame Average : 6
	m_pIntegrated->nFilterNum[7]     = 1;        // Filter ( 0->0x0008, 1->0x0010, 2->0x0020, 3->0x8000 )
	m_pIntegrated->nXScanAmpVal[7]   = 3381;     // 3381,  8.26[v] : X축 배율보정 (크기)
	m_pIntegrated->nXScanOffset[7]   = 1413;     // 1413, -1.55[v] : X축 위치보정 (센터)
	m_pIntegrated->nYScanAmpVal[7]   = 1447;     // 1447,  3.53[v] : Y축 배율보정 (크기) 
	m_pIntegrated->nYScanOffset[7]   = 2070;     // 2070,  0.06[v] : Y축 위치보정 (센터)
	m_pIntegrated->nSkipPixNum[7]    = 500;      // 0 - 999 -> SCAN SKIP PIXEL COUNT ( 일그러진 SCAN 이미지 SKIP )
	m_pIntegrated->nFrameSec[7]      = 7474;     // 7.5[f/s]
	m_pIntegrated->nOverSampleNum[7] = 8;        // Over Sampling Value
    //--------------------------------------------------------------------------
	// 8 : Half Fast Slow  -   <  3.8 Frame/sec >
	// 8 : Half Fast Slow  -   <  3.25 Frame/sec >
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[8]   = 1;        // 640x480
	m_pIntegrated->nScanCodeA[8]     = 0xA1FF;   //
	m_pIntegrated->nScanCodeB[8]     = 0xB1FF;   //
	m_pIntegrated->nXScanUpNum[8]    = 2048;     // 1200
	m_pIntegrated->nXScanDownNum[8]  = 64;       //
	m_pIntegrated->nYScanUpNum[8]    = 484;      //  500
	m_pIntegrated->nYScanDownNum[8]  = 4;        //
	m_pIntegrated->nXBmpPixel[8]     = 640;
	m_pIntegrated->nYBmpPixel[8]     = 480;
	m_pIntegrated->nXBmpOffset[8]    = 0;
	m_pIntegrated->nYBmpOffset[8]    = 0;
	m_pIntegrated->nWAverageNum[8]   = 1;
	m_pIntegrated->nFilterNum[8]     = 1;
	m_pIntegrated->nXScanAmpVal[8]   = 1483;
	m_pIntegrated->nXScanOffset[8]   = 190;
	m_pIntegrated->nYScanAmpVal[8]   = 1062;
	m_pIntegrated->nYScanOffset[8]   = 10;
	m_pIntegrated->nSkipPixNum[8]    = 37;       // 0 - 499
	m_pIntegrated->nFrameSec[8]      = 3750;     // 3.75f/s
	m_pIntegrated->nOverSampleNum[8] = 26;       // XScan Freq. => 1.8kHz
	//--------------------------------------------------------------------------
	// Half Slow Scan Mode
	//--------------------------------------------------------------------------
	// 9 : Half Slow 1   -  < 0.6 Frame/sec >    <<<<< SLOW1 SCAN MODE >>>>>
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[9]   = 1;        // 640x480
	m_pIntegrated->nScanCodeA[9]     = 0xA1FF;   // Default
	m_pIntegrated->nScanCodeB[9]     = 0xB1FF;   // Default 
	m_pIntegrated->nXScanUpNum[9]    = 2048;     // X Scan Up   Value
	m_pIntegrated->nXScanDownNum[9]  = 32;       // X Scan Down Value
	m_pIntegrated->nYScanUpNum[9]    = 484;      // Y Scan Up   Value
	m_pIntegrated->nYScanDownNum[9]  = 41;       // Y Scan Down Value
	m_pIntegrated->nXBmpPixel[9]     = 640;      // X PIXEL WIDTH
	m_pIntegrated->nYBmpPixel[9]     = 480;      // Y PIXEL HEIGHT 
	m_pIntegrated->nXBmpOffset[9]    = 0;        // X PIXEL OFFSET
	m_pIntegrated->nYBmpOffset[9]    = 0;        // Y PIXEL OFFSET
	m_pIntegrated->nWAverageNum[9]   = 1;        // Frame Average : 1
	m_pIntegrated->nFilterNum[9]     = 1;        // Filter ( 0->0x0008, 1->0x0010, 2->0x0020, 3->0x8000 )
	m_pIntegrated->nXScanAmpVal[9]   = 2766;     // 2766,  6.75[v] : X축 배율보정 (크기)
	m_pIntegrated->nXScanOffset[9]   = 2203;     // 2203, -1.18[v] : X축 위치보정 (센터)
	m_pIntegrated->nYScanAmpVal[9]   = 1446;     // 1446,  3.53[v] : Y축 배율보정 (크기) 
	m_pIntegrated->nYScanOffset[9]   = 2050;     // 2050,  0.01[v] : Y축 위치보정 (센터)
	m_pIntegrated->nSkipPixNum[9]    = 190;      // 0 - 999 -> SCAN SKIP PIXEL COUNT ( 일그러진 SCAN 이미지 SKIP )
	m_pIntegrated->nFrameSec[9]      = 234;      // 0.23[f/s]
	m_pIntegrated->nOverSampleNum[9] = 362;      // Over Sampling Value
	//--------------------------------------------------------------------------
	// 10 : Half Slow 2  -  <  0.3 Frame/sec >
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[10]   = 1;       // 640x480
	m_pIntegrated->nScanCodeA[10]     = 0xA1FF;
	m_pIntegrated->nScanCodeB[10]     = 0xB1FF;
	m_pIntegrated->nXScanUpNum[10]    = 2048;    // 1200
	m_pIntegrated->nXScanDownNum[10]  = 16;      //
	m_pIntegrated->nYScanUpNum[10]    = 484;     //  500
	m_pIntegrated->nYScanDownNum[10]  = 4;
	m_pIntegrated->nXBmpPixel[10]     = 640;
	m_pIntegrated->nYBmpPixel[10]     = 480;
	m_pIntegrated->nXBmpOffset[10]    = 0;
	m_pIntegrated->nYBmpOffset[10]    = 0;
	m_pIntegrated->nWAverageNum[10]   = 1;
	m_pIntegrated->nFilterNum[10]     = 1;
	m_pIntegrated->nXScanAmpVal[10]   = 1385;    //1752;
	m_pIntegrated->nXScanOffset[10]   = 155;
	m_pIntegrated->nYScanAmpVal[10]   = 1072;
	m_pIntegrated->nYScanOffset[10]   = 6;
	m_pIntegrated->nSkipPixNum[10]    = 10;      // 0 - 999
	m_pIntegrated->nFrameSec[10]      = 340;     // 0.34 f/s
	m_pIntegrated->nOverSampleNum[10] = 414;     // XScan Freq. => 1.8kHz
	//--------------------------------------------------------------------------
	// 11 : Half Slow 3  -  <  0.15 Frame/sec >  <<<<< SLOW2 SCAN MODE >>>>>
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[11]   = 1;       // 640x480
	m_pIntegrated->nScanCodeA[11]     = 0xA1FF;  // Default
	m_pIntegrated->nScanCodeB[11]     = 0xB1FF;  // Default 
	m_pIntegrated->nXScanUpNum[11]    = 2048;    // X Scan Up   Value
	m_pIntegrated->nXScanDownNum[11]  = 8;       // X Scan Down Value
	m_pIntegrated->nYScanUpNum[11]    = 484;     // Y Scan Up   Value
	m_pIntegrated->nYScanDownNum[11]  = 4;       // Y Scan Down Value
	m_pIntegrated->nXBmpPixel[11]     = 640;     // X PIXEL WIDTH
	m_pIntegrated->nYBmpPixel[11]     = 480;     // Y PIXEL HEIGHT 
	m_pIntegrated->nXBmpOffset[11]    = 0;       // X PIXEL OFFSET
	m_pIntegrated->nYBmpOffset[11]    = 0;       // Y PIXEL OFFSET
	m_pIntegrated->nWAverageNum[11]   = 1;       // Frame Average : 1
	m_pIntegrated->nFilterNum[11]     = 1;       // Filter ( 0->0x0008, 1->0x0010, 2->0x0020, 3->0x8000 )
	m_pIntegrated->nXScanAmpVal[11]   = 2305;    // 2305,  5.63[v] : X축 배율보정 (크기)
	m_pIntegrated->nXScanOffset[11]   = 1744;    // 1744, -0.74[v] : X축 위치보정 (센터)
	m_pIntegrated->nYScanAmpVal[11]   = 1450;    // 1450,  3.54[v] : Y축 배율보정 (크기) 
	m_pIntegrated->nYScanOffset[11]   = 2040;    // 2040, -0.02[v] : Y축 위치보정 (센터)
	m_pIntegrated->nSkipPixNum[11]    = 190;     // 0 - 999 -> SCAN SKIP PIXEL COUNT ( 일그러진 SCAN 이미지 SKIP )
	m_pIntegrated->nFrameSec[11]      = 123;     // 0.12[f/s]
	m_pIntegrated->nOverSampleNum[11] = 900;     // Over Sampling Value
	//--------------------------------------------------------------------------
	// Full Fast Scan Mode
	//--------------------------------------------------------------------------
	// 12 : Full Fast1 < 1280x960 : 3.8 frame/sec >
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[12]   = 2;        // 1280x960
	m_pIntegrated->nScanCodeA[12]     = 0xA2FF;
	m_pIntegrated->nScanCodeB[12]     = 0xB2FF;
	m_pIntegrated->nXScanUpNum[12]    = 2048;     // 2400
	m_pIntegrated->nXScanDownNum[12]  = 128;
	m_pIntegrated->nYScanUpNum[12]    = 964;      // 1000
	m_pIntegrated->nYScanDownNum[12]  = 4;
	m_pIntegrated->nXBmpPixel[12]     = 1280;
	m_pIntegrated->nYBmpPixel[12]     = 960;
	m_pIntegrated->nXBmpOffset[12]    = 0;
	m_pIntegrated->nYBmpOffset[12]    = 0;
	m_pIntegrated->nWAverageNum[12]   = 1;
	m_pIntegrated->nFilterNum[12]     = 1;
	m_pIntegrated->nXScanAmpVal[12]   = 1694;
	m_pIntegrated->nXScanOffset[12]   = 100;
	m_pIntegrated->nYScanAmpVal[12]   = 1084;
	m_pIntegrated->nYScanOffset[12]   = 7;
	m_pIntegrated->nSkipPixNum[12]    = 204;      // 0 - 1999
	m_pIntegrated->nFrameSec[12]      = 3800;     // 3.8f/s
	m_pIntegrated->nOverSampleNum[12] = 6;        // XScan Freq. => 1.8kHz
	//--------------------------------------------------------------------------
	// 13: Full Fast2 < 1280x960 : 1.9 frame/sec >
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[13]   = 2;        // 1280x960
	m_pIntegrated->nScanCodeA[13]     = 0xA2FF;
	m_pIntegrated->nScanCodeB[13]     = 0xB2FF;
	m_pIntegrated->nXScanUpNum[13]    = 2048;     // 2400
	m_pIntegrated->nXScanDownNum[13]  = 64;
	m_pIntegrated->nYScanUpNum[13]    = 964;      // 1000
	m_pIntegrated->nYScanDownNum[13]  = 4;
	m_pIntegrated->nXBmpPixel[13]     = 1280;
	m_pIntegrated->nYBmpPixel[13]     = 960;
	m_pIntegrated->nXBmpOffset[13]    = 0;
	m_pIntegrated->nYBmpOffset[13]    = 0;
	m_pIntegrated->nWAverageNum[13]   = 1;
	m_pIntegrated->nFilterNum[13]     = 1;
	m_pIntegrated->nXScanAmpVal[13]   = 1652;
	m_pIntegrated->nXScanOffset[13]   = 270;
	m_pIntegrated->nYScanAmpVal[13]   = 1075;
	m_pIntegrated->nYScanOffset[13]   = 10;
	m_pIntegrated->nSkipPixNum[13]    = 78;       // 0 - 1999
	m_pIntegrated->nFrameSec[13]      = 1900;     // 1.9f/s
	m_pIntegrated->nOverSampleNum[13] = 12;       // XScan Freq. =>  900Hz
	//--------------------------------------------------------------------------
	// 14: Full Fast3 < 1280x960 : 0.9 frame/sec >
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[14]   = 2;        // 1280x960
	m_pIntegrated->nScanCodeA[14]     = 0xA2FF;
	m_pIntegrated->nScanCodeB[14]     = 0xB2FF;
	m_pIntegrated->nXScanUpNum[14]    = 1800;     // 2000
	m_pIntegrated->nXScanDownNum[14]  = 200;
	m_pIntegrated->nYScanUpNum[14]    = 976;      // 1000
	m_pIntegrated->nYScanDownNum[14]  = 24;
	m_pIntegrated->nXBmpPixel[14]     = 1280;
	m_pIntegrated->nYBmpPixel[14]     = 960;
	m_pIntegrated->nXBmpOffset[14]    = 0;
	m_pIntegrated->nYBmpOffset[14]    = 0;
	m_pIntegrated->nWAverageNum[14]   = 1;
	m_pIntegrated->nFilterNum[14]     = 1;
	m_pIntegrated->nXScanAmpVal[14]   = 1476;
	m_pIntegrated->nXScanOffset[14]   = 120;
	m_pIntegrated->nYScanAmpVal[14]   = 1085;
	m_pIntegrated->nYScanOffset[14]   = 10;
	m_pIntegrated->nSkipPixNum[14]    = 39;       // 0 - 1999
	m_pIntegrated->nFrameSec[14]      = 900;      // 0.9f/s
	m_pIntegrated->nOverSampleNum[14] = 49;       // XScan Freq. =>  900Hz
	//--------------------------------------------------------------------------
	// Full Slow Scan Mode
	//--------------------------------------------------------------------------
	// 15 : Full Slow1 < 1280x960 : 2.5 sec/frame > 0.4 f/s
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[15]   = 2;        // 1280x960
	m_pIntegrated->nScanCodeA[15]     = 0xA2FF;
	m_pIntegrated->nScanCodeB[15]     = 0xB2FF;
	m_pIntegrated->nXScanUpNum[15]    = 2048;     // 2000
	m_pIntegrated->nXScanDownNum[15]  = 64;
	m_pIntegrated->nYScanUpNum[15]    = 964;      // 1000
	m_pIntegrated->nYScanDownNum[15]  = 4;
	m_pIntegrated->nXBmpPixel[15]     = 1280;
	m_pIntegrated->nYBmpPixel[15]     = 960;
	m_pIntegrated->nXBmpOffset[15]    = 0;
	m_pIntegrated->nYBmpOffset[15]    = 0;
	m_pIntegrated->nWAverageNum[15]   = 1;
	m_pIntegrated->nFilterNum[15]     = 1;
	m_pIntegrated->nXScanAmpVal[15]   = 1476;
	m_pIntegrated->nXScanOffset[15]   = 120;
	m_pIntegrated->nYScanAmpVal[15]   = 1085;
	m_pIntegrated->nYScanOffset[15]   = 0;
	m_pIntegrated->nSkipPixNum[15]    = 39;       // 0 - 1999
	m_pIntegrated->nFrameSec[15]      = 400;      // 0.4 f/s
	m_pIntegrated->nOverSampleNum[15] = 49;       // XScan Freq. => 1.44MHz / 2000 = 720Hz /2 = 360Hz
	//--------------------------------------------------------------------------
	// 16 : Full Slow2 < 1280x960 : 5 sec/frame > 0.2 f/s
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[16]   = 2;        // 1280x960
	m_pIntegrated->nScanCodeA[16]     = 0xA2FF;
	m_pIntegrated->nScanCodeB[16]     = 0xB2FF;
	m_pIntegrated->nXScanUpNum[16]    = 2048;     // 2000
	m_pIntegrated->nXScanDownNum[16]  = 32;
	m_pIntegrated->nYScanUpNum[16]    = 964;      // 1000
	m_pIntegrated->nYScanDownNum[16]  = 4;
	m_pIntegrated->nXBmpPixel[16]     = 1280;
	m_pIntegrated->nYBmpPixel[16]     = 960;
	m_pIntegrated->nXBmpOffset[16]    = 0;
	m_pIntegrated->nYBmpOffset[16]    = 0;
	m_pIntegrated->nWAverageNum[16]   = 1;
	m_pIntegrated->nFilterNum[16]     = 1;
	m_pIntegrated->nXScanAmpVal[16]   = 1476;
	m_pIntegrated->nXScanOffset[16]   = 120;
	m_pIntegrated->nYScanAmpVal[16]   = 1085;
	m_pIntegrated->nYScanOffset[16]   = 10;
	m_pIntegrated->nSkipPixNum[16]    = 39;       // 0 - 1999
	m_pIntegrated->nFrameSec[16]      = 200;      // 0.2 f/s
	m_pIntegrated->nOverSampleNum[16] = 97;       // XScan Freq. => 1.44MHz / 2000 = 720Hz /2 = 360Hz
	//--------------------------------------------------------------------------
	// 17 : Full Slow3 < 1280x960 : 10 sec/frame >  0.1 f/s
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[17]   = 2;        // 1280x960
	m_pIntegrated->nScanCodeA[17]     = 0xA2FF;
	m_pIntegrated->nScanCodeB[17]     = 0xB2FF;
	m_pIntegrated->nXScanUpNum[17]    = 2048;     // 2000
	m_pIntegrated->nXScanDownNum[17]  = 16;
	m_pIntegrated->nYScanUpNum[17]    = 964;      // 1000
	m_pIntegrated->nYScanDownNum[17]  = 4;
	m_pIntegrated->nXBmpPixel[17]     = 640 * 2;
	m_pIntegrated->nYBmpPixel[17]     = 480 * 2;
	m_pIntegrated->nXBmpOffset[17]    = 0;
	m_pIntegrated->nYBmpOffset[17]    = 0;
	m_pIntegrated->nWAverageNum[17]   = 1;
	m_pIntegrated->nFilterNum[17]     = 1;
	m_pIntegrated->nXScanAmpVal[17]   = 1476;
	m_pIntegrated->nXScanOffset[17]   = 120;
	m_pIntegrated->nYScanAmpVal[17]   = 1085;
	m_pIntegrated->nYScanOffset[17]   = 10;
	m_pIntegrated->nSkipPixNum[17]    = 39;       // 0 - 1999
	m_pIntegrated->nFrameSec[17]      = 100;      // 0.1f/s
	m_pIntegrated->nOverSampleNum[17] = 200;      // XScan Freq. => 4.8MHz / 2000 = 240Hz /2 = 120Hz
	//--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	// Photo Scan Mode
	//--------------------------------------------------------------------------
	// 18 : Photo 1 < 640x480 : 16 sec/frame > 0.0625f/s <<<<< PHOTO1 SCAN MODE >>>>>
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[18]   = 1;        // 640x480
	m_pIntegrated->nScanCodeA[18]     = 0xA1FF;   // Default
	m_pIntegrated->nScanCodeB[18]     = 0xB1FF;   // Default 
	m_pIntegrated->nXScanUpNum[18]    = 2048;     // X Scan Up   Value
	m_pIntegrated->nXScanDownNum[18]  = 8;        // X Scan Down Value
	m_pIntegrated->nYScanUpNum[18]    = 484;      // Y Scan Up   Value
	m_pIntegrated->nYScanDownNum[18]  = 4;        // Y Scan Down Value
	m_pIntegrated->nXBmpPixel[18]     = 640;      // X PIXEL WIDTH
	m_pIntegrated->nYBmpPixel[18]     = 480;      // Y PIXEL HEIGHT 
	m_pIntegrated->nXBmpOffset[18]    = 0;        // X PIXEL OFFSET
	m_pIntegrated->nYBmpOffset[18]    = 0;        // Y PIXEL OFFSET
	m_pIntegrated->nWAverageNum[18]   = 1;        // Frame Average : 1
	m_pIntegrated->nFilterNum[18]     = 1;        // Filter ( 0->0x0008, 1->0x0010, 2->0x0020, 3->0x8000 )
	m_pIntegrated->nXScanAmpVal[18]   = 2448;     // 2448,  5.98[v] : X축 배율보정 (크기)
	m_pIntegrated->nXScanOffset[18]   = 2453;     // 2453,  0.99[v] : X축 위치보정 (센터)
	m_pIntegrated->nYScanAmpVal[18]   = 1455;     // 1455,  3.55[v] : Y축 배율보정 (크기) 
	m_pIntegrated->nYScanOffset[18]   = 2052;     // 2052,  0.01[v] : Y축 위치보정 (센터)
	m_pIntegrated->nSkipPixNum[18]    = 84;       // 0 - 999 -> SCAN SKIP PIXEL COUNT ( 일그러진 SCAN 이미지 SKIP )
	m_pIntegrated->nFrameSec[18]      = 62;       // 0.062[f/s]
	m_pIntegrated->nOverSampleNum[18] = 1675;     // Over Sampling Value
	//--------------------------------------------------------------------------
	// 19 : Photo 2 < 640x480 : 33.3 sec/frame > 0.031f/s <<<<< PHOTO2 SCAN MODE >>>>>
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[19]   = 1;        // 640x480
	m_pIntegrated->nScanCodeA[19]     = 0xA1FF;   // Default
	m_pIntegrated->nScanCodeB[19]     = 0xB1FF;   // Default 
	m_pIntegrated->nXScanUpNum[19]    = 2048;     // X Scan Up   Value
	m_pIntegrated->nXScanDownNum[19]  = 8;        // X Scan Down Value
	m_pIntegrated->nYScanUpNum[19]    = 484;      // Y Scan Up   Value
	m_pIntegrated->nYScanDownNum[19]  = 4;        // Y Scan Down Value
	m_pIntegrated->nXBmpPixel[19]     = 640;      // X PIXEL WIDTH
	m_pIntegrated->nYBmpPixel[19]     = 480;      // Y PIXEL HEIGHT 
	m_pIntegrated->nXBmpOffset[19]    = 0;        // X PIXEL OFFSET
	m_pIntegrated->nYBmpOffset[19]    = 0;        // Y PIXEL OFFSET
	m_pIntegrated->nWAverageNum[19]   = 1;        // Frame Average : 1
	m_pIntegrated->nFilterNum[19]     = 1;        // Filter ( 0->0x0008, 1->0x0010, 2->0x0020, 3->0x8000 )
	m_pIntegrated->nXScanAmpVal[19]   = 2168;     // 2168,  5.29[v] : X축 배율보정 (크기)
	m_pIntegrated->nXScanOffset[19]   = 2355;     // 2355,  0.75[v] : X축 위치보정 (센터)
	m_pIntegrated->nYScanAmpVal[19]   = 1452;     // 1452,  3.55[v] : Y축 배율보정 (크기)  
	m_pIntegrated->nYScanOffset[19]   = 2062;     // 2062,  0.04[v] : Y축 위치보정 (센터)
	m_pIntegrated->nSkipPixNum[19]    = 38;       // 0 - 999 -> SCAN SKIP PIXEL COUNT ( 일그러진 SCAN 이미지 SKIP )
	m_pIntegrated->nFrameSec[19]      = 41;       // 0.031[f/s]
	m_pIntegrated->nOverSampleNum[19] = 2838;     // Over Sampling Value
	//--------------------------------------------------------------------------
	// 20 : Photo 3 < 1280x960 : 33.3 sec/frame = 0.031 f/s > <<<<< PHOTO3 SCAN MODE >>>>>
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[20]   = 2;        // 1280x960
	m_pIntegrated->nScanCodeA[20]     = 0xA2FF;   // Default
	m_pIntegrated->nScanCodeB[20]     = 0xB2FF;   // Default 
	m_pIntegrated->nXScanUpNum[20]    = 2048;     // X Scan Up   Value
	m_pIntegrated->nXScanDownNum[20]  = 4;        // X Scan Down Value
	m_pIntegrated->nYScanUpNum[20]    = 964;      // Y Scan Up   Value
	m_pIntegrated->nYScanDownNum[20]  = 4;        // Y Scan Down Value
	m_pIntegrated->nXBmpPixel[20]     = 1280;     // X PIXEL WIDTH
	m_pIntegrated->nYBmpPixel[20]     = 960;      // Y PIXEL HEIGHT 
	m_pIntegrated->nXBmpOffset[20]    = 0;        // X PIXEL OFFSET
	m_pIntegrated->nYBmpOffset[20]    = 0;        // Y PIXEL OFFSET
	m_pIntegrated->nWAverageNum[20]   = 1;        // Frame Average : 1
	m_pIntegrated->nFilterNum[20]     = 1;        // Filter ( 0->0x0008, 1->0x0010, 2->0x0020, 3->0x8000 )
	m_pIntegrated->nXScanAmpVal[20]   = 1733;     // 1733,  4.23[v] : X축 배율보정 (크기)
	m_pIntegrated->nXScanOffset[20]   = 1993;     // 1993, -0.13[v] : X축 위치보정 (센터)
	m_pIntegrated->nYScanAmpVal[20]   = 1445;     // 1445,  3.53[v] : Y축 배율보정 (크기)  
	m_pIntegrated->nYScanOffset[20]   = 2045;     // 2045, -0.01[v] : Y축 위치보정 (센터)
	m_pIntegrated->nSkipPixNum[20]    = 69;       // 0 - 1999 -> SCAN SKIP PIXEL COUNT ( 일그러진 SCAN 이미지 SKIP )
	m_pIntegrated->nFrameSec[20]      = 31;       // 0.031[f/s]
	m_pIntegrated->nOverSampleNum[20] = 1186;     // Over Sampling Value
	//--------------------------------------------------------------------------
	// 21 : Photo 4 < 1280x960 : 66.6 sec/frame = 0.015 f/s > <<<<< PHOTO4 SCAN MODE >>>>>
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[21]   = 2;        // 1280x960
	m_pIntegrated->nScanCodeA[21]     = 0xA2FF;   // Default
	m_pIntegrated->nScanCodeB[21]     = 0xB2FF;   // Default 
	m_pIntegrated->nXScanUpNum[21]    = 3000;     // X Scan Up   Value
	m_pIntegrated->nXScanDownNum[21]  = 4;        // X Scan Down Value
	m_pIntegrated->nYScanUpNum[21]    = 964;      // Y Scan Up   Value
	m_pIntegrated->nYScanDownNum[21]  = 4;        // Y Scan Down Value
	m_pIntegrated->nXBmpPixel[21]     = 1280;     // X PIXEL WIDTH
	m_pIntegrated->nYBmpPixel[21]     = 960;      // Y PIXEL HEIGHT 
	m_pIntegrated->nXBmpOffset[21]    = 0;        // X PIXEL OFFSET
	m_pIntegrated->nYBmpOffset[21]    = 0;        // Y PIXEL OFFSET
	m_pIntegrated->nWAverageNum[21]   = 1;        // Frame Average : 1
	m_pIntegrated->nFilterNum[21]     = 1;        // Filter ( 0->0x0008, 1->0x0010, 2->0x0020, 3->0x8000 )
	m_pIntegrated->nXScanAmpVal[21]   = 3058;     // 3058,  7.47[v] : X축 배율보정 (크기) 
	m_pIntegrated->nXScanOffset[21]   = 2330;     // 2330,  0.69[v] : X축 위치보정 (센터)
	m_pIntegrated->nYScanAmpVal[21]   = 1438;     // 1438,  3.51[v] : Y축 배율보정 (크기)  
	m_pIntegrated->nYScanOffset[21]   = 2050;     // 2050,  0.01[v] : Y축 위치보정 (센터)
	m_pIntegrated->nSkipPixNum[21]    = 122;      // 0 - 1999 -> SCAN SKIP PIXEL COUNT ( 일그러진 SCAN 이미지 SKIP )
	m_pIntegrated->nFrameSec[21]      = 25;       // 0.025[f/s]
	m_pIntegrated->nOverSampleNum[21] = 1137;     // Over Sampling Value
	//--------------------------------------------------------------------------
	// 22 : Photo 5 < 1280x960 : 133.3 sec/frame = 0.0075 f/s > <<<<< PHOTO5 SCAN MODE >>>>>
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[22]   = 2;        // 1280x960
	m_pIntegrated->nScanCodeA[22]     = 0xA2FF;   // Default
	m_pIntegrated->nScanCodeB[22]     = 0xB2FF;   // Default 
	m_pIntegrated->nXScanUpNum[22]    = 2946;     // X Scan Up   Value
	m_pIntegrated->nXScanDownNum[22]  = 4;        // X Scan Down Value
	m_pIntegrated->nYScanUpNum[22]    = 964;      // Y Scan Up   Value
	m_pIntegrated->nYScanDownNum[22]  = 4;        // Y Scan Down Value
	m_pIntegrated->nXBmpPixel[22]     = 1280;     // X PIXEL WIDTH
	m_pIntegrated->nYBmpPixel[22]     = 960;      // Y PIXEL HEIGHT 
	m_pIntegrated->nXBmpOffset[22]    = 0;        // X PIXEL OFFSET
	m_pIntegrated->nYBmpOffset[22]    = 0;        // Y PIXEL OFFSET
	m_pIntegrated->nWAverageNum[22]   = 1;        // Frame Average : 1
	m_pIntegrated->nFilterNum[22]     = 1;        // Filter ( 0->0x0008, 1->0x0010, 2->0x0020, 3->0x8000 )
	m_pIntegrated->nXScanAmpVal[22]   = 3900;     // 3900,  9.52[v] : X축 배율보정 (크기) 
	m_pIntegrated->nXScanOffset[22]   = 3048;     // 3048,  2.45[v] : X축 위치보정 (센터)
	m_pIntegrated->nYScanAmpVal[22]   = 1453;     // 1453,  3.55[v] : Y축 배율보정 (크기)  
	m_pIntegrated->nYScanOffset[22]   = 2020;     // 2020, -0.07[v] : Y축 위치보정 (센터)
	m_pIntegrated->nSkipPixNum[22]    = 58;       // 0 - 1999 -> SCAN SKIP PIXEL COUNT ( 일그러진 SCAN 이미지 SKIP )
	m_pIntegrated->nFrameSec[22]      = 6;        // 0.006[f/s]
	m_pIntegrated->nOverSampleNum[22] = 3800;     // Over Sampling Value
	//--------------------------------------------------------------------------
	// 23 : Photo 6 < 2560x1920 : 133.3 sec/frame = 0.0075 f/s > <<<<< PHOTO6 SCAN MODE >>>>>
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[23]   = 3;        // 2560x1920
	m_pIntegrated->nScanCodeA[23]     = 0xA3FF;   // Default
	m_pIntegrated->nScanCodeB[23]     = 0xB3FF;   // Default 
	m_pIntegrated->nXScanUpNum[23]    = 3000;     // X Scan Up   Value
	m_pIntegrated->nXScanDownNum[23]  = 4;        // X Scan Down Value
	m_pIntegrated->nYScanUpNum[23]    = 1924;     // Y Scan Up   Value
	m_pIntegrated->nYScanDownNum[23]  = 4;        // Y Scan Down Value
	m_pIntegrated->nXBmpPixel[23]     = 2560;     // X PIXEL WIDTH
	m_pIntegrated->nYBmpPixel[23]     = 1920;     // Y PIXEL HEIGHT 
	m_pIntegrated->nXBmpOffset[23]    = 0;        // X PIXEL OFFSET
	m_pIntegrated->nYBmpOffset[23]    = 0;        // Y PIXEL OFFSET
	m_pIntegrated->nWAverageNum[23]   = 1;        // Frame Average : 1
	m_pIntegrated->nFilterNum[23]     = 1;        // Filter ( 0->0x0008, 1->0x0010, 2->0x0020, 3->0x8000 )
	m_pIntegrated->nXScanAmpVal[23]   = 2730;     // 2730,  6.67[v] : X축 배율보정 (크기) 
	m_pIntegrated->nXScanOffset[23]   = 2260;     // 2260,  0.52[v] : X축 위치보정 (센터)
	m_pIntegrated->nYScanAmpVal[23]   = 1445;     // 1445,  3.53[v] : Y축 배율보정 (크기)  
	m_pIntegrated->nYScanOffset[23]   = 2045;     // 2020, -0.01[v] : Y축 위치보정 (센터)
	m_pIntegrated->nSkipPixNum[23]    = 139;      // 0 - 3999 -> SCAN SKIP PIXEL COUNT ( 일그러진 SCAN 이미지 SKIP )
	m_pIntegrated->nFrameSec[23]      = 6;        // 0.006[f/s]
	m_pIntegrated->nOverSampleNum[23] = 1338;     // Over Sampling Value
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	// WFM Mode
	//--------------------------------------------------------------------------
	// 24 : WFM
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[24]   = 5;
	m_pIntegrated->nScanCodeA[24]     = 0xA5FF;
	m_pIntegrated->nScanCodeB[24]     = 0xB5FF;
	m_pIntegrated->nXScanUpNum[24]    = 899;
	m_pIntegrated->nXScanDownNum[24]  = 100;
	m_pIntegrated->nYScanUpNum[24]    = 480;
	m_pIntegrated->nYScanDownNum[24]  = 20;
	m_pIntegrated->nXBmpPixel[24]     = 640;
	m_pIntegrated->nYBmpPixel[24]     = 1;
	m_pIntegrated->nXBmpOffset[24]    = 0;
	m_pIntegrated->nYBmpOffset[24]    = 0;
	m_pIntegrated->nWAverageNum[24]   = 1;
	m_pIntegrated->nFilterNum[24]     = 6;
	m_pIntegrated->nXScanAmpVal[24]   = 590;
	m_pIntegrated->nXScanOffset[24]   = 23;
	m_pIntegrated->nYScanAmpVal[24]   = 441;
	m_pIntegrated->nYScanOffset[24]   = 30;
	m_pIntegrated->nSkipPixNum[24]    = 10;       // 0 - 719
	m_pIntegrated->nFrameSec[24]      = 1;        // 0 - 499
	m_pIntegrated->nOverSampleNum[24] = 862;
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	// Auto Focus Mode
	//--------------------------------------------------------------------------
	// 25 : AutoFocus
	//--------------------------------------------------------------------------
	m_pIntegrated->nFPGABmpSize[25]   = 6;
	m_pIntegrated->nScanCodeA[25]     = 0xA6FF;
	m_pIntegrated->nXScanAmpVal[25]   = 0;       // not used
	m_pIntegrated->nXScanOffset[25]   = 0;       // not used
	m_pIntegrated->nYScanAmpVal[25]   = 0;       // not used
	m_pIntegrated->nYScanOffset[25]   = 0;       // not used
	m_pIntegrated->nXScanUpNum[25]    = 0;       // not used
	m_pIntegrated->nXScanDownNum[25]  = 0;       // not used
	m_pIntegrated->nYScanUpNum[25]    = 0;       // not used
	m_pIntegrated->nYScanDownNum[25]  = 0;       // not used
	m_pIntegrated->nSkipPixNum[25]    = 0;       // not used
	m_pIntegrated->nFrameSec[25]      = 0;       // not used
	m_pIntegrated->nWAverageNum[25]   = 1;
	m_pIntegrated->nFilterNum[25]     = 6;
	m_pIntegrated->nOverSampleNum[25] = 150;
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	// Half Red Scan Mode : 320x240
	//--------------------------------------------------------------------------
	// 0 : Half Red  1  - over: 28     < 14.4 Frame/sec >
	// 1 : Half Red  2  - over: 56     <  7.2 Frame/sec >
	//--------------------------------------------------------------------------
	// Full Red Scan Mode : 640x480
	//--------------------------------------------------------------------------
	// 2 : Full Red  1  - over: 56     < 7.2 Frame/sec >
	// 3 : Full Red  2  - over: 56     <  3.6 Frame/sec >
	//--------------------------------------------------------------------------
	// Half Fast Scan Mode
	//--------------------------------------------------------------------------
	// 4 : Half Fast High 1
	// 5 : Half Fast Low 2
	//--------------------------------------------------------------------------
	// Half Slow Scan Mode
	//--------------------------------------------------------------------------
	// 6 : Half Slow 1  - over: 256    < 2.08 sec/frame = 0.48 Frame/sec >
	// 7 : Half Slow 2  - over: 512   < 4.16 sec/frame = 0.24 Frame/sec >
	// 8 : Half Slow 3  - over: 1024   < 8.32 sec/frame = 0.12 Frame/sec  >
	//--------------------------------------------------------------------------
	// Photo Scan Mode
	//--------------------------------------------------------------------------
	// 9:   Photo 1 < 640x480 : 16.7 sec/frame = 0.06 Frame/sec >
	// 10 : Photo 2 < 640x480 : 33.3 sec/frame = 0.03 Frame/sec >
	// 20 : Photo 3 < 1280x960 : 33.3 sec/frame = 0.03 Frame/sec >
	// 11 : Photo 4 < 1280x960 : 66.6 sec/frame = 0.015 Frame/sec >
	// 12 : Photo 5 < 2560x1920 : 133.3 sec/frame = 0.0075 Frame/sec >
	//--------------------------------------------------------------------------
	// Full Screen Mode
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	// Full Fast Scan Mode
	//--------------------------------------------------------------------------
	// 13 : Full Fast1 < 1280x960 : 1.8 frame/sec >
	// 14 : Full Fast2 < 1280x960 : 0.9 frame/sec >
	//--------------------------------------------------------------------------
	// Full Slow Scan Mode
	//--------------------------------------------------------------------------
	// 15 : Full Slow1 < 1280x960 : 2.22 sec/frame >
	// 16 : Full Slow2 < 1280x960 : 8.88 sec/frame >
	// 17 : Full Slow3 < 1280x960 : 17.6 sec/frame >
	//--------------------------------------------------------------------------
	// WFM Mode
	//--------------------------------------------------------------------------
	// 18 : WFM
	//--------------------------------------------------------------------------


	//---------------------------------------------------------------------------
	//   DM = 4개 항목
	//
	//                               80              320                560
	//                          DM_XMoveLeft    DM_XMoveCenter      DM_XMoveRight
	//                        -------------------------------------------------
	//                        | 0                    320                   640|
	//     DM_YMoveTop      60|                                               |
	//                        |                                               |
	//     DM_YMoveCenter  240|240                                            |
	//                        |                                               |
	//     DM_YMoveBottom  420|                                               |
	//                        |480                                            |
	//                        -------------------------------------------------
	//
	//               2120             200
	//   a  = ( DM_XMoveRight - DM_XMoveLeft ) / (560 - 80)
	//
	//  da  = a * cx + ( DM_XMoveLeft * 7 - DM_XMoveRight ) / 6
	//
	//---------------------------------------------------------------------------


	//--------------------------------------------------------------------------
	m_pIntegrated->nScreenMode      = NORMAL_SCREEN;
	//--------------------------------------------------------------------------
	// (1) Half Scan
	m_pIntegrated->nHalfRedScan     = RED_SCAN_MODE;        // 0, 1, 2
	m_pIntegrated->nHalfFastScan    = FAST_SCAN_MODE;       // 6, 7, 8
	m_pIntegrated->nHalfSlow1Scan   = SLOW1_SCAN_MODE;      // 9, 10, 11
	m_pIntegrated->nHalfSlow2Scan   = SLOW2_SCAN_MODE;      // 9, 10, 11
	// (2) Full Scan
	m_pIntegrated->nFullRedScan     = 3;                    // 3, 4, 5
	m_pIntegrated->nFullFastScan    = 12;                   // 12, 13, 14
	m_pIntegrated->nFullSlow1Scan   = 15;                   // 15, 16, 17
	m_pIntegrated->nFullSlow2Scan   = 17;                   // 15, 16, 17
	// (3) Photo Scan
	m_pIntegrated->nPhotoScan       = PHOTO1_SCAN_MODE;     // 18, 19, 20, 21, 22, 23
	//--------------------------------------------------------------------------
	m_pIntegrated->nXScanMoveLeft   = -654;
	m_pIntegrated->nXScanMoveRight  = 700;
	m_pIntegrated->nYScanMoveTop    = -538;
	m_pIntegrated->nYScanMoveBottom = 404;
	//--------------------------------------------------------------------------
	m_pIntegrated->nDMXMoveLeft     = 1125;
	m_pIntegrated->nDMXMoveRight    = 3040;
	m_pIntegrated->nDMYMoveTop      = 1245;
	m_pIntegrated->nDMYMoveBottom   = 2864;
	//--------------------------------------------------------------------------
	m_pIntegrated->nStageHorAlign   = -190;                 // SM-300 DP
	//-----------------------------------------------------------------------------------
    //  30인치 LCD 모니터 기준
	//-----------------------------------------------------------------------------------
	m_pIntegrated->nImageScreenSize = 160;                  // ( 160mm -> 640Pixel )
	m_pIntegrated->nMicronBarMag    = 100;                  // x100   x100   x100    |  x200    Magnification
	m_pIntegrated->dMicronBarSize   = 300.0;                // 300um  200um  100um   |  100um   Mircon Bar Size

    //--------------------------------------------------------------------------
    // 위 세가지 정보에 의해 결정됨
    //--------------------------------------------------------------------------
    //                                  0.64 => ( 640 Pixel,  200um-> 0.2mm )
	//
	m_pIntegrated->nMicronBarPixelNum = (int)(0.64 * m_pIntegrated->nMicronBarMag * m_pIntegrated->dMicronBarSize / m_pIntegrated->nImageScreenSize);
	//--------------------------------------------------------------------------

	m_pIntegrated->nMotorSpeed    = 1; // Mid
	m_pIntegrated->nWDTopLimit    = 4;
	m_pIntegrated->nWDBottomLimit = 51;

	m_pIntegrated->dCurXPos       = 0.0;
	m_pIntegrated->dCurYPos       = 0.0;
	m_pIntegrated->dCurZPos       = 15.0;
	m_pIntegrated->nCurRDeg       = 0; // 0 - 3600
	m_pIntegrated->nCurTDeg       = 0; // 0 -   70

	m_pIntegrated->nPhotoNum          = 1234;
	m_pIntegrated->bViewParameterFlag = true;

	memset(m_pIntegrated->szUserText, 0x00, sizeof(m_pIntegrated->szUserText));
	strcpy_s(m_pIntegrated->szUserText, "ModuleSci ");

	//-----------------------------------------------
	m_pIntegrated->bUserTextViewFlag     = true;
	m_pIntegrated->bGunHViewFlag         = true;
	m_pIntegrated->bMagViewFlag          = true;
	m_pIntegrated->bSpotSizeViewFlag     = true;
	m_pIntegrated->bWorkDistViewFlag     = true;
	m_pIntegrated->bMicroBarViewFlag     = true;
	m_pIntegrated->bPhotoNumViewFlag     = false;
	m_pIntegrated->bDateTimeViewFlag     = false;
	//-----------------------------------------------
	m_pIntegrated->bAutoZoomMicroBarFlag = false;
	m_pIntegrated->bMedianFilterFlag     = false;
	m_pIntegrated->bMovingAverageFlag    = false;
	m_pIntegrated->bRedBottomClearFlag   = false;
	m_pIntegrated->bPhotoBottomClearFlag = false;
	m_pIntegrated->bEucentricRotFlag     = true;
	m_pIntegrated->bZFocusLinkFlag       = true;
	//-----------------------------------------------
	m_pIntegrated->bAFBaseOnWDFlag       = false;
	m_pIntegrated->nOLCompensation       = OL_IMAGE_ZOOM_CHANGE;
	m_pIntegrated->nSemInfoType          = 0;

	//-----------------------------------------------
	// Mag. Relay 선택시 저항오차에 의한 배율교정
	//-----------------------------------------------
	m_pIntegrated->nZoomXMaxValue[0]  = 3799;
	m_pIntegrated->nZoomYMaxValue[0]  = 3399;
	m_pIntegrated->nZoomXMaxValue[1]  = 3817;
	m_pIntegrated->nZoomYMaxValue[1]  = 3327;
	m_pIntegrated->nZoomXMaxValue[2]  = 3615;
	m_pIntegrated->nZoomYMaxValue[2]  = 3195;
	m_pIntegrated->nZoomXMaxValue[3]  = 3110;
	m_pIntegrated->nZoomYMaxValue[3]  = 2923;
	m_pIntegrated->nZoomXMaxValue[4]  = 4095;
	m_pIntegrated->nZoomYMaxValue[4]  = 4095;
	//-----------------------------------------------
	m_pIntegrated->nBrightLowLimit    = 513;
	m_pIntegrated->nBrightHighLimit   = 2017;
	m_pIntegrated->nContrastLowLimit  = 1298;
	m_pIntegrated->nContrastHighLimit = 2505;
	m_pIntegrated->nStigXLowLimit     = 1000;
	m_pIntegrated->nStigXHighLimit    = 3000;
	m_pIntegrated->nStigYLowLimit     = 1000;
	m_pIntegrated->nStigYHighLimit    = 3000;
	//-----------------------------------------------

	//-----------------------------------------------
	//----   직교도 보상 ----------------------------
	//-----------------------------------------------
	m_pIntegrated->nARAngle[0] = 0;    m_pIntegrated->nBRAngle[0] = 0;    m_pIntegrated->nCRAngle[0] = 90;    m_pIntegrated->nDRAngle[0] = 0;
	m_pIntegrated->nARAngle[1] = 0;    m_pIntegrated->nBRAngle[1] = -30;  m_pIntegrated->nCRAngle[1] = 120;   m_pIntegrated->nDRAngle[1] = 0;
	m_pIntegrated->nARAngle[2] = 0;    m_pIntegrated->nBRAngle[2] = 20;   m_pIntegrated->nCRAngle[2] = 170;   m_pIntegrated->nDRAngle[2] = -40;
	m_pIntegrated->nARAngle[3] = 10;   m_pIntegrated->nBRAngle[3] = 0;    m_pIntegrated->nCRAngle[3] = 150;   m_pIntegrated->nDRAngle[3] = 0;
	m_pIntegrated->nARAngle[4] = 0;    m_pIntegrated->nBRAngle[4] = -10;  m_pIntegrated->nCRAngle[4] = 130;   m_pIntegrated->nDRAngle[4] = 70;
	m_pIntegrated->nARAngle[5] = -50;  m_pIntegrated->nBRAngle[5] = 50;   m_pIntegrated->nCRAngle[5] = 70;    m_pIntegrated->nDRAngle[5] = 80;
	m_pIntegrated->nARAngle[6] = 10;   m_pIntegrated->nBRAngle[6] = 0;    m_pIntegrated->nCRAngle[6] = 0;     m_pIntegrated->nDRAngle[6] = 100;
	m_pIntegrated->nARAngle[7] = 50;   m_pIntegrated->nBRAngle[7] = 40;   m_pIntegrated->nCRAngle[7] = 150;   m_pIntegrated->nDRAngle[7] = 100;
	m_pIntegrated->nARAngle[8] = 80;   m_pIntegrated->nBRAngle[8] = 70;   m_pIntegrated->nCRAngle[8] = 70;    m_pIntegrated->nDRAngle[8] = 180;
	m_pIntegrated->nARAngle[9] = 60;   m_pIntegrated->nBRAngle[9] = -40;  m_pIntegrated->nCRAngle[9] = 120;   m_pIntegrated->nDRAngle[9] = 30;
	m_pIntegrated->nARAngle[10] = 0;   m_pIntegrated->nBRAngle[10] = 0;   m_pIntegrated->nCRAngle[10] = 90;   m_pIntegrated->nDRAngle[10] = 110;
	m_pIntegrated->nARAngle[11] = 40;  m_pIntegrated->nBRAngle[11] = -30; m_pIntegrated->nCRAngle[11] = 30;   m_pIntegrated->nDRAngle[11] = 40;
	m_pIntegrated->nARAngle[12] = 40;  m_pIntegrated->nBRAngle[12] = 20;  m_pIntegrated->nCRAngle[12] = -10;  m_pIntegrated->nDRAngle[12] = 0;
	m_pIntegrated->nARAngle[13] = 20;  m_pIntegrated->nBRAngle[13] = 60;  m_pIntegrated->nCRAngle[13] = -100; m_pIntegrated->nDRAngle[13] = 50;
	m_pIntegrated->nARAngle[14] = -40; m_pIntegrated->nBRAngle[14] = 50;  m_pIntegrated->nCRAngle[14] = -120; m_pIntegrated->nDRAngle[14] = 60;
	m_pIntegrated->nARAngle[15] = 50;  m_pIntegrated->nBRAngle[15] = 90;  m_pIntegrated->nCRAngle[15] = -60;  m_pIntegrated->nDRAngle[15] = -10;
	m_pIntegrated->nARAngle[16] = 20;  m_pIntegrated->nBRAngle[16] = 70;  m_pIntegrated->nCRAngle[16] = -120; m_pIntegrated->nDRAngle[16] = -30;
	m_pIntegrated->nARAngle[17] = 40;  m_pIntegrated->nBRAngle[17] = -10; m_pIntegrated->nCRAngle[17] = -70;  m_pIntegrated->nDRAngle[17] = -50;
	m_pIntegrated->nARAngle[18] = -20; m_pIntegrated->nBRAngle[18] = 50;  m_pIntegrated->nCRAngle[18] = 0;    m_pIntegrated->nDRAngle[18] = -30;
	m_pIntegrated->nARAngle[19] = -70; m_pIntegrated->nBRAngle[19] = -60; m_pIntegrated->nCRAngle[19] = -40;  m_pIntegrated->nDRAngle[19] = -60;
	m_pIntegrated->nARAngle[20] = -40; m_pIntegrated->nBRAngle[20] = -20; m_pIntegrated->nCRAngle[20] = -80;  m_pIntegrated->nDRAngle[20] = -80;
	m_pIntegrated->nARAngle[21] = -30; m_pIntegrated->nBRAngle[21] = 10;  m_pIntegrated->nCRAngle[21] = -70;  m_pIntegrated->nDRAngle[21] = -50;
	m_pIntegrated->nARAngle[22] = 0;   m_pIntegrated->nBRAngle[22] = 40;  m_pIntegrated->nCRAngle[22] = -20;  m_pIntegrated->nDRAngle[22] = -40;
	m_pIntegrated->nARAngle[23] = 0;   m_pIntegrated->nBRAngle[23] = -10; m_pIntegrated->nCRAngle[23] = 0;    m_pIntegrated->nDRAngle[23] = -60;
	//-----------------------------------------------
	m_pIntegrated->nRightAngle = 64;
	//-----------------------------------------------
	//----   직교도 보상 -끝- -----------------------
	//-----------------------------------------------

	//-----------------------------------------------
	// 화일 초기화 변수와 Global 변수를 따로 사용
	//-----------------------------------------------
	m_pIntegrated->bNEGImageFlag      = false;  // 음영반전 Flag
	m_pIntegrated->bLRMirrorFlag      = false;  // 좌우반전 Flag
	m_pIntegrated->bTBMirrorFlag      = false;  // 상하반전 Flag
	m_pIntegrated->bRED1FileScanFlag  = false;  // RED1 File Scan Flag
	m_pIntegrated->bRED2FileScanFlag  = false;  // RED2 File Scan Flag
	m_pIntegrated->bFULL1FileScanFlag = false;  // FULL1 File Scan Flag
	m_pIntegrated->bFULL2FileScanFlag = false;  // FULL2 File Scan Flag

    //-----------------------------------------------
	// 스캔모드 :
	//-----------------------------------------------
	// (1) Half Scan 모드 종류
	//     HalfRedScan   -> 0, 1, 2     >> 기본값 0
    //     HalfFastScan  -> 6, 7, 8     >> 기본값 6
	//     HalfSlow1Scan -> 9, 10, 11   >> 기본값 9
    //     HalfSlow2Scan -> 9, 10, 11   >> 기본값 11
    // (2) Full Scan 모드 종류
    //     FullRedScan   -> 3, 4, 5     >> 기본값 3
    //     FullFastScan  -> 12, 13, 14  >> 기본값 12
    //     FullSlow1Scan -> 15, 16, 17  >> 기본값 15
    //     FullSlow2Scan -> 15, 16, 17  >> 기본값 17
	//-----------------------------------------------
	// 초기스캔모드 : Half Fast Scan 설정 640x480, 1초당 7.5 프레임
    m_pIntegrated->nScanMode          = FAST_SCAN_MODE;
	//-----------------------------------------------
	// System 처음 시작시, 100배로
	m_pIntegrated->nMagStepIndex      = 10;  // mag x100
    //-----------------------------------------------
	m_pIntegrated->nFilamentValue     = 2008;
	m_pIntegrated->nBiasValue         = 2000;
	m_pIntegrated->nGunHVIndex        = 2;
	m_pIntegrated->nSpotSize          = 16;
	m_pIntegrated->nCLSpotSize        = 16;
	//-----------------------------------------------
	m_pIntegrated->nGAXValue          = 2048;
	m_pIntegrated->nGAYValue          = 2048;
	m_pIntegrated->nStigXValue        = 2048;
	m_pIntegrated->nStigYValue        = 2048;
	m_pIntegrated->nISXValue          = 2048;
	m_pIntegrated->nISYValue          = 2048;
	//-----------------------------------------------
	m_pIntegrated->nBrightValue       = 1660;
	m_pIntegrated->nBrightLowLimit    = 513;
	m_pIntegrated->nBrightHighLimit   = 2017;
	//-----------------------------------------------
	m_pIntegrated->nContrastValue     = 1822;
	m_pIntegrated->nContrastLowLimit  = 0;
	m_pIntegrated->nContrastHighLimit = 4095;
	//-----------------------------------------------
	m_pIntegrated->nBrightReference   = 1817;
	m_pIntegrated->nContrastReference = 1753;
	m_pIntegrated->nStigXReference    = 2388;
	m_pIntegrated->nStigYReference    = 2124;
	//-----------------------------------------------
	m_pIntegrated->nFocusCoarse       = 4095;
	m_pIntegrated->nFocusFine         = 0;
	//-----------------------------------------------
	m_pIntegrated->wAutoBrightLevel   = 127;     // (0 - 255) set by user
	m_pIntegrated->wAutoContrastLevel = 127;     // (0 - 255) set by user
	//-----------------------------------------------

	//-----------------------------------------------
	//-----------------------------------------------
	//-----------------------------------------------

	m_pIntegrated->nXSR45Value = 0;
	m_pIntegrated->nYSR45Value = 0;
	m_pIntegrated->nXSR90Value = 0;
	m_pIntegrated->nYSR90Value = 0;

	//-----------------------------------------------
	//-----------------------------------------------
	//-----------------------------------------------

	//------------------------------------------------------------------------------
	// WD에 따른 WD_OL_Coarse, WD_SRotation, WD_Zooming 값을 설정하는 방법
	//------------------------------------------------------------------------------
	// 1) 처음에는  IniPar.WD_OL_Coarse[] 값을 Board에서 측정한 전압값을 발생시키는
	//    Cal_WD_OL_Value_From_SM300_OL_Voltage() 함수에서 만들려고 하였으나.
	//
	// 2) WD=5mm (IniPar.WD_TopLimit)에서 AutoFocus를 수행하고 얻은 OL값을 IniPar.WD_OL_Coarse[]에
	//    저장하고, 1mm씩 이동한 후 반복 시행을 WD=40mm(IniPar.WD_BottomLimit)까지 진행한다.
	//
	// 3) 이 때 얻은 IniPar.WD_OL_Coarse[] 값이 정확한지 WD 위치에서 확인하면서,
	//    IniPar.WD_SRotation[], IniPar.WD_Zooming[] 값을 저장한다.
	//
	// 4) 1mm 간격으로 측정값을 얻으므로, 분해능을 0.1mm 까지 얻기위해
	//    1mm 간격의 Data를 10등분으로 선형화 작업을 프로그램 시작시 진행한다.
	//------------------------------------------------------------------------------
	AfxIntegratedSetWDCompensation();

	//------------------------------------------------------
	// CL1, CL2 전류를 출력시키기 위한 D/A 변환기 값...
	//------------------------------------------------------
	// m_dRefR, m_dAmpRk 값은 SEM 모델에 따라 다르다.
	// 기본은 SM-300B CL Type 모델, 값은 Ref:2.0, Amp:2.4
	//------------------------------------------------------
	double dFT = 0.0;

	for (int n=0; n<MAX_SM300_SM200_CL12_ITEM; n++)
	{
		switch (nSemType)
		{
			case 0:
			case 1:
			{
				//--------------------------------------------------
				// SM-300A 전류에 따른 12bit DA
				//--------------------------------------------------
				// 3.9k / 3.3ohm = 1.18A (Max) 10V -> 4096 -> 3.9V
				// 2.4k / 2.0ohm = 1.2A  (Max) 10V -> 4096 -> 2.4V
				//--------------------------------------------------
				dFT = I_SM300_CL1[n] * m_pIntegrated->dRefR * 4096.0 / m_pIntegrated->dAmpRk;
				m_nDA_CL1[n] = (int)dFT;
				//--------------------------------------------------
				dFT = I_SM300_CL2[n] * m_pIntegrated->dRefR * 4096.0 / m_pIntegrated->dAmpRk;
				m_nDA_CL2[n] = (int)dFT;
				//--------------------------------------------------
				//m_dV_CL1[n] = I_SM300_CL1[n] * m_pIntegrated->dRefR;
				//m_dV_CL2[n] = I_SM300_CL2[n] * m_pIntegrated->dRefR;
				break;
				//--------------------------------------------------
			}
			case 2:
			{
				//--------------------------------------------------
				// SM-200A 전류에 따른 12bit DA 인가 Code로 변경
				//--------------------------------------------------
				// 3k / 2ohm = 1.5A (Max)   10V -> 4096
				//--------------------------------------------------
				// 4096 => 10V => 3V
				dFT = I_SM200_CL1[n] * m_pIntegrated->dRefR * 4096.0 / m_pIntegrated->dAmpRk;
				m_nDA_CL1[n] = (int)dFT;
				//--------------------------------------------------
				dFT = I_SM200_CL2[n] * m_pIntegrated->dRefR * 4096.0 / m_pIntegrated->dAmpRk;
				m_nDA_CL2[n] = (int)dFT;
				//--------------------------------------------------
				//m_dV_CL1[n] = I_SM200_CL1[n] * m_pIntegrated->dRefR;
				//m_dV_CL2[n] = I_SM200_CL2[n] * m_pIntegrated->dRefR;
				break;
				//--------------------------------------------------
			}
			case 3:
			case 4:
			case 5:
			{
				//--------------------------------------------------
				// SM-300의 저항값으로 SM-200에서 Test할 경우
				//--------------------------------------------------
				// 2.4k / 2.0 ohm = 1.2A  (Max) 10V -> 4096
				//--------------------------------------------------
				// 4096 => 10V => 3V
				dFT = I_SM200_CL1[n] * m_pIntegrated->dRefR * 4096.0 / m_pIntegrated->dAmpRk;
				m_nDA_CL1[n] = (int)dFT;
				if (m_nDA_CL1[n] > 4095)
				{
					m_nDA_CL1[n] = 4095;
				}
				//--------------------------------------------------
				dFT = I_SM200_CL2[n] * m_pIntegrated->dRefR * 4096.0 / m_pIntegrated->dAmpRk;
				m_nDA_CL2[n] = (int)dFT;
				if (m_nDA_CL2[n] > 4095)
				{
					m_nDA_CL2[n] = 4095;
				}
				//--------------------------------------------------
				//m_dV_CL1[n] = I_SM200_CL1[n] * m_pIntegrated->dRefR;
				//m_dV_CL2[n] = I_SM200_CL2[n] * m_pIntegrated->dRefR;
				//--------------------------------------------------
				break;
			}
			case 6:
			{
				//--------------------------------------------------
				// SM-200의 저항값으로 SM-300에서 Test할 경우
				//--------------------------------------------------
				// 3k / 2.0 ohm = 1.5A     (Max) 10V -> 4096
				//--------------------------------------------------
				// 4096 => 10V => 3V
				dFT = I_SM300_CL1[n] * m_pIntegrated->dRefR * 4096.0 / m_pIntegrated->dAmpRk;
				m_nDA_CL1[n] = (int)dFT;
				if (m_nDA_CL1[n] > 4095)
				{
					m_nDA_CL1[n] = 4095;
				}
				//--------------------------------------------------
				dFT = I_SM300_CL2[n] * m_pIntegrated->dRefR * 4096.0 / m_pIntegrated->dAmpRk;
				m_nDA_CL2[n] = (int)dFT;
				if (m_nDA_CL2[n] > 4095)
				{
					m_nDA_CL2[n] = 4095;
				}
				//--------------------------------------------------
				//m_dV_CL1[n] = I_SM200_CL1[n] * m_pIntegrated->dRefR;
				//m_dV_CL2[n] = I_SM200_CL2[n] * m_pIntegrated->dRefR;
				//--------------------------------------------------
				break;
			}
		}
	}
	//---------------------------------------------------------
	// CL1, CL2값 보관
	for (int n = 0; n<MAX_SM300_SM200_CL12_ITEM; n++)
	{
		m_pIntegrated->wCL1List[n] = (WORD)m_nDA_CL1[n];
		m_pIntegrated->wCL2List[n] = (WORD)m_nDA_CL2[n];
	}
	//---------------------------------------------------------
	m_pIntegrated->nWobblerWidth = 4;
	//---------------------------------------------------------
	m_pIntegrated->nTiltZeroAnglePulsePos = 4000;
	//---------------------------------------------------------
	// Step Motor (X,Y,Z,R,T) Micro Step Index -> (0=Full, 1=1/2, 2=1/4, 3=1/8)
	m_pIntegrated->nMicroStep[0] = 3;
	m_pIntegrated->nMicroStep[1] = 3;
	m_pIntegrated->nMicroStep[2] = 2;
	m_pIntegrated->nMicroStep[3] = 2;
	m_pIntegrated->nMicroStep[4] = 2;
	//---------------------------------------------------------
	m_pIntegrated->nRightAngleStepIndex = 0; // 15 deg or 18 deg
    //---------------------------------------------------------

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Generation (이미지 스캔을 위한 신호 생성)
/////////////////////////////////////////////////////////////////////////////////////////////////////
/*
scan_high_val   ---------------->     /|                   /|
/   |                /   |
/      |             /      |             /
/         |          /         |          /
/            |       /            |       /
scan_low_val    -----> /               |____/               |____/

+----+               +----+
|    |               |    |
xBlank                 ________________|    |_______________|    |__________
|    ^
|    |
skipnum  <---->

+----------+         +----------+         +-----
|          |         |          |         |
ImgCapOn              ______|          |_________|          |_________|
^          ^
|          |
XScanUpNum[sm] - xBmpPixel[sm]  <---------->

*/
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Generation (스캔모드에 따라 이미지 스캔을 위한 신호 생성)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetScanGeneration(int nSM)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	WORD wComBuf[TMP_STRING_LENGTH+1];
	memset(wComBuf, 0x00, sizeof(wComBuf));

	//-------------------------
	// DDS에 의한 ScanClk 발생
	//-------------------------
	int nScanClock = 0;
	int nPhaseInc  = 0;
	double dFrame  = 0.0;

	dFrame = (double)m_pIntegrated->nFrameSec[nSM] * 0.001;
	dFrame = (double)(m_pIntegrated->nXScanUpNum[nSM] + m_pIntegrated->nXScanDownNum[nSM]) * (double)(m_pIntegrated->nYScanUpNum[nSM] + m_pIntegrated->nYScanDownNum[nSM]) * dFrame;
	nScanClock = (int)dFrame;

	///////////////////////////////////////////////////////////////////////////////////
	// 2021.07.29
	// SCAN CLOCK  ( 32Bits, 48MHz ) --> ( 48Bits, 100MHz) 로 변경하여 계산 적용
	///////////////////////////////////////////////////////////////////////////////////
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_SCAN_CLOCK_48] == 1)
	{
		// SCAN CLOCK 48Bits, 100MHz
	    //--------------------------------------------------------------------------
	    // 2021.07.29
	    // 추가옵션사항 : ( ScanClk * 2^32 / 48[MHz] ) --> ( ScanClk * 2^48 / 100[MHz] )
	    //--------------------------------------------------------------------------
		__int64 nPhase_inc64 = 0;
	    nPhase_inc64 = (__int64)(nScanClock * (Exp2E48 / 100000000));
		wComBuf[0]  = cWR_FDDS_LOW;	      wComBuf[1] = (WORD)(nPhase_inc64 & 0x000000000000FFFF); nPhase_inc64 = nPhase_inc64 >> 16;
		wComBuf[2]  = cWR_FDDS_HIGH;      wComBuf[3] = (WORD)(nPhase_inc64 & 0x000000000000FFFF); nPhase_inc64 = nPhase_inc64 >> 16;
		wComBuf[4]  = cWR_FDDS_HIGH48;    wComBuf[5] = (WORD)(nPhase_inc64 & 0x000000000000FFFF);
	    //--------------------------------------------------------------------------
	    AfxFT232HPortSendMultiCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, wComBuf, 6); // Sbr Scan Clock Data 전송
	    //--------------------------------------------------------------------------
	}
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	else
	{
		// SCAN CLOCK 32Bits, 48MHz
		nPhaseInc = (int)(nScanClock * Exp2E32 / PLL_SCAN_CLOCK); //(int)((double)(nScanClock * Exp2E32 / PLL_SCAN_CLOCK));
		memset(wComBuf, 0x00, sizeof(wComBuf));
		//--------------------------------------------------------------------------
		wComBuf[0] = cWR_FDDS_LOW;      wComBuf[1] = nPhaseInc & 0x0000FFFF;
		wComBuf[2] = cWR_FDDS_HIGH;     wComBuf[3] = nPhaseInc >> 16;
		//--------------------------------------------------------------------------
		// SBR 명령 전송
		AfxFT232HPortSendMultiCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, wComBuf, 4);
		//--------------------------------------------------------------------------
	}
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	// 잠시대기
	//Sleep(100);

	memset(wComBuf, 0x00, sizeof(wComBuf));
	//--------------------------------------------------------------------------
	wComBuf[0] = cOS_NUM_LOAD;      wComBuf[1] = m_pIntegrated->nOverSampleNum[nSM];
	wComBuf[2] = cSKIP_NUM_LOAD;    wComBuf[3] = m_pIntegrated->nSkipPixNum[nSM];
	// Smg 명령 전송
	AfxFT232HPortSendMultiCommand(IDX_FT232H_SEM_IMAGE_DEVICE, wComBuf, 4);
	//--------------------------------------------------------------------------

	// 잠시대기
	//Sleep(100);

	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------

	int nIncVal    = 0;
	int nIncHeight = 0;
	int nLowVal    = 0;
	int nHighVal   = 0;
	int nDecVal    = 0;

	memset(wComBuf, 0x00, sizeof(wComBuf));

	//--------------------------------------------------------------------------
	// XScan 기본파형 발생
	//--------------------------------------------------------------------------
	if (m_pIntegrated->nXScanUpNum[nSM] > 0 && m_pIntegrated->nXScanDownNum[nSM] > 0)
	{
		nIncVal    = 4096 / m_pIntegrated->nXScanUpNum[nSM];
		nIncHeight = nIncVal * m_pIntegrated->nXScanUpNum[nSM];
		nLowVal    = (4096 - nIncHeight) / 2;
		nHighVal   = 4096 - nLowVal;
		nDecVal    = nIncHeight / m_pIntegrated->nXScanDownNum[nSM];
	}

	wComBuf[0]  = cWR_XSCAN_LOW;       wComBuf[1]  = nLowVal;
	wComBuf[2]  = cWR_XSCAN_HIGH;      wComBuf[3]  = nHighVal;
	wComBuf[4]  = cWR_XSCAN_INC_VAL;   wComBuf[5]  = nIncVal;
	wComBuf[6]  = cWR_XSCAN_DEC_VAL;   wComBuf[7]  = nDecVal;
	wComBuf[8]  = cWR_XSCAN_INC_PIX;   wComBuf[9]  = m_pIntegrated->nXScanUpNum[nSM];
	wComBuf[10] = cWR_XSCAN_DEC_PIX;   wComBuf[11] = m_pIntegrated->nXScanDownNum[nSM];
	//--------------------------------------------------------------------------

	nIncVal    = 0;
	nIncHeight = 0;
	nLowVal    = 0;
	nHighVal   = 0;
	nDecVal    = 0;
	//--------------------------------------------------------------------------
	// YScan 기본파형 발생
	//--------------------------------------------------------------------------
	if (m_pIntegrated->nYScanUpNum[nSM] > 0 && m_pIntegrated->nYScanDownNum[nSM] > 0)
	{
		nIncVal    = 4096 / m_pIntegrated->nYScanUpNum[nSM];
		nIncHeight = nIncVal * m_pIntegrated->nYScanUpNum[nSM];
		nLowVal    = (4096 - nIncHeight) / 2;
		nHighVal   = 4096 - nLowVal;
		nDecVal    = nIncHeight / m_pIntegrated->nYScanDownNum[nSM];
	}

	wComBuf[12] = cWR_YSCAN_LOW;       wComBuf[13] = nLowVal;
	wComBuf[14] = cWR_YSCAN_HIGH;      wComBuf[15] = nHighVal;
	wComBuf[16] = cWR_YSCAN_INC_VAL;   wComBuf[17] = nIncVal;
	wComBuf[18] = cWR_YSCAN_DEC_VAL;   wComBuf[19] = nDecVal;
	wComBuf[20] = cWR_YSCAN_INC_PIX;   wComBuf[21] = m_pIntegrated->nYScanUpNum[nSM];    // 2048
	wComBuf[22] = cWR_YSCAN_DEC_PIX;   wComBuf[23] = m_pIntegrated->nYScanDownNum[nSM];  //  128
	//--------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	// SBR 명령 전송
	AfxFT232HPortSendMultiCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, wComBuf, 24);
	//--------------------------------------------------------------------------

	////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////
	// 2021.07.26
	// SCAN CALIBRATION 작업 후, 스캔모드에 따른 X-AMP, X-OFF, Y-AMP, Y-OFF 값이
	// 적용되지 않아, SLEEP 설정 후, 재설정을 실행한다.
	////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////

	// 잠시대기
	Sleep(50);

	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	// X, YScan의 Amplitude 와 Offset 설정 ( "SR6","SR7","SR8","SR9" )
	//--------------------------------------------------------------------------
	AfxScanBridgeSetXImageAmpApply(m_pIntegrated->nXScanAmpVal[nSM]);     // XScanAmp
	AfxScanBridgeSetXImageOffsetApply(m_pIntegrated->nXScanOffset[nSM]);  // XScanOffset
	AfxScanBridgeSetYImageAmpApply(m_pIntegrated->nYScanAmpVal[nSM]);     // YScanAmp
	AfxScanBridgeSetYImageOffsetApply(m_pIntegrated->nYScanOffset[nSM]);  // YScanOffset
	//--------------------------------------------------------------------------

	// 잠시대기
	//Sleep(50);

	// 2021.09.24 : X-AMP, X-OFFSET, Y-AMP, Y-OFFSET 의 설정기능이 두번 실행
	//              되어 제거한다.
	//--------------------------------------------------------------------------
	// X, YScan의 Amplitude 와 Offset 설정 ( "SR6","SR7","SR8","SR9" )
	//--------------------------------------------------------------------------
	//AfxScanBridgeSetXImageAmpApply(m_pIntegrated->nXScanAmpVal[nSM]);     // XScanAmp
	//AfxScanBridgeSetXImageOffsetApply(m_pIntegrated->nXScanOffset[nSM]);  // XScanOffset
	//AfxScanBridgeSetYImageAmpApply(m_pIntegrated->nYScanAmpVal[nSM]);     // YScanAmp
	//AfxScanBridgeSetYImageOffsetApply(m_pIntegrated->nYScanOffset[nSM]);  // YScanOffset
	//--------------------------------------------------------------------------

	////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////

	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------

	// 잠시대기
	//Sleep(50);

	//--------------------------------------------------------------------------
	// BSE Board가 연결된 경우
	//--------------------------------------------------------------------------
	if (m_pIntegrated->bBseActiveFlag == TRUE)
	{
		WORD wBseBuf[CMD_STRING_LENGTH+1];

		wBseBuf[0] = bOS_NUM_LOAD;    wBseBuf[1] = m_pIntegrated->nOverSampleNum[nSM];   // not use
		wBseBuf[2] = bSKIP_NUM_LOAD;  wBseBuf[3] = m_pIntegrated->nSkipPixNum[nSM];
		AfxFT232HPortSendMultiCommand(IDX_FT232H_BSE_IMAGE_DEVICE, wBseBuf, 4);
	}
	//--------------------------------------------------------------------------


	return RET_SUCCESS_OK;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Generation 초기화 (스캔신호 OFF)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedResetScanGeneration(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	WORD wComBuf[TMP_STRING_LENGTH + 1];

	memset(wComBuf, 0x00, sizeof(wComBuf));
	//--------------------------------------------------------------------------
	wComBuf[0] = cWR_FDDS_LOW;      wComBuf[1] = 0;
	wComBuf[2] = cWR_FDDS_HIGH;     wComBuf[3] = 0;
	//--------------------------------------------------------------------------
	// SBR 명령 전송
	AfxFT232HPortSendMultiCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, wComBuf, 4);
	//--------------------------------------------------------------------------

	// 잠시대기
	//AfxSystemWaitTime(100);

	memset(wComBuf, 0x00, sizeof(wComBuf));
	//--------------------------------------------------------------------------
	wComBuf[0] = cOS_NUM_LOAD;      wComBuf[1] = 0;
	wComBuf[2] = cSKIP_NUM_LOAD;    wComBuf[3] = 0;
	// Smg 명령 전송
	AfxFT232HPortSendMultiCommand(IDX_FT232H_SEM_IMAGE_DEVICE, wComBuf, 4);
	//--------------------------------------------------------------------------

	// 잠시대기
	//AfxSystemWaitTime(100);

	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------

	memset(wComBuf, 0x00, sizeof(wComBuf));

	//--------------------------------------------------------------------------
	// XScan 기본파형 발생
	//--------------------------------------------------------------------------
	wComBuf[0]  = cWR_XSCAN_LOW;       wComBuf[1]  = 0;
	wComBuf[2]  = cWR_XSCAN_HIGH;      wComBuf[3]  = 0;
	wComBuf[4]  = cWR_XSCAN_INC_VAL;   wComBuf[5]  = 0;
	wComBuf[6]  = cWR_XSCAN_DEC_VAL;   wComBuf[7]  = 0;
	wComBuf[8]  = cWR_XSCAN_INC_PIX;   wComBuf[9]  = 0;
	wComBuf[10] = cWR_XSCAN_DEC_PIX;   wComBuf[11] = 0;
	//--------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	// YScan 기본파형 발생
	//--------------------------------------------------------------------------
	wComBuf[12] = cWR_YSCAN_LOW;       wComBuf[13] = 0;
	wComBuf[14] = cWR_YSCAN_HIGH;      wComBuf[15] = 0;
	wComBuf[16] = cWR_YSCAN_INC_VAL;   wComBuf[17] = 0;
	wComBuf[18] = cWR_YSCAN_DEC_VAL;   wComBuf[19] = 0;
	wComBuf[20] = cWR_YSCAN_INC_PIX;   wComBuf[21] = 0;
	wComBuf[22] = cWR_YSCAN_DEC_PIX;   wComBuf[23] = 0;
	//--------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	// SBR 명령 전송
	AfxFT232HPortSendMultiCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, wComBuf, 24);
	//--------------------------------------------------------------------------

	// 잠시대기
	//AfxSystemWaitTime(100);

	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	// X, YScan의 Amplitude 와 Offset 설정 ( "SR6","SR7","SR8","SR9" )
	//--------------------------------------------------------------------------
	AfxScanBridgeSetXImageAmpApply(0);        // "SR6" : XScanAmp
	AfxScanBridgeSetXImageOffsetApply(2048);  // "SR7" : XScanOffset
	AfxScanBridgeSetYImageAmpApply(0);        // "SR8" : YScanAmp
	AfxScanBridgeSetYImageOffsetApply(2048);  // "SR9" : YScanOffset
	//--------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------


	return RET_SUCCESS_OK;
}

//---------------------------------------------------------------------------
// IniPar.MicronBarMag   IniPar.dMicronBarSize    IniPar.MicronBarPixelNum
//---------------------------------------------------------------------------
//           x100            100 um                      100 Pixel
//           x500             20 um
//           x1.0k            10 um
//           x2.0k             5 um
//           x10k              1 um
//           x20k            0.5 um  (500 nm)
//           x50k            0.2 um  (200 nm)
//           x100k           0.1 um  (100 nm)
//---------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Image Data Capture 작업 중지
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetMagnification(int nMag, int nWD10)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 배율확인
	if (nMag == 0) return RET_ERROR_STATUS;

	/////////////////////////////////////////////////////////////////////////////////
    // 2021.06.10
    // 사용자 MAG HV RATIO : STAGE 수평 옵션을 임시로 사용한다.
    /////////////////////////////////////////////////////////////////////////////////
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_STAGE_HORZ_ALIGN] == 1)
	{
		double dMaxGunHV = m_nGunHVTable[0];                           // MAX GUN HV VOLTAGE : m_nGunHVTable[0];
		double dGunHV    = m_nGunHVTable[m_pIntegrated->nGunHVIndex];  // Gun HV Voltage
		// GUN HV : 20KV
		if (m_nGunHVTable[m_pIntegrated->nGunHVIndex] == 20000)
		{
			m_pIntegrated->dMagHVRatio = sqrt(dGunHV / dMaxGunHV) / DEFAULT_MAG_HV_RATIO;
		}
		else
		{
			// 사용자 설정 배율 HV RATIO 보정값 설정
			m_pIntegrated->dMagHVRatio = m_dOptionMagHVRatio[m_pIntegrated->nGunHVIndex];
		}
	}
	/////////////////////////////////////////////////////////////////////////////////

	double dRatio = 0.0;

	// 배율에 따른 릴레이 동작(설정)과 비율값 계산
	dRatio = AfxIntegratedFindMagRelayRatio(nMag);

	// Zoom Value 계산 및 동작
	m_pIntegrated->wZoomXValue = (WORD)((double)m_nZoomXMaxValue[m_pIntegrated->wMagRelayNumber] / dRatio);
	m_pIntegrated->wZoomYValue = (WORD)((double)m_nZoomYMaxValue[m_pIntegrated->wMagRelayNumber] / dRatio);
	// 2020.05.27
	// SCAN ROTATION CALIBRATION DATA 적용
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_ORTHOGONAL_CORRRECTION] == 1)
	{
		// 2020.05.26
		// SCAN ROTATION 보정값 적용시 최대값은 4095이다
		if (m_pIntegrated->wZoomXValue > 4095) m_pIntegrated->wZoomXValue = 4095;
		if (m_pIntegrated->wZoomYValue > 4095) m_pIntegrated->wZoomYValue = 4095;
	}
	else
	{
		// 2020.05.26
		// ZOOM X-Y MAX값 설정
		if (m_pIntegrated->wZoomXValue > m_nZoomXMaxValue[m_pIntegrated->wMagRelayNumber]) m_pIntegrated->wZoomXValue = m_nZoomXMaxValue[m_pIntegrated->wMagRelayNumber];
		if (m_pIntegrated->wZoomYValue > m_nZoomYMaxValue[m_pIntegrated->wMagRelayNumber]) m_pIntegrated->wZoomYValue = m_nZoomYMaxValue[m_pIntegrated->wMagRelayNumber];
	}

	/////////////////////////////////////////////////////////////////////////////////
	// 2020.05.26
	// SCAN ROTATION : ORTHOGONAL, S-ROT 보정, ZOOM X-Y 보정
	/////////////////////////////////////////////////////////////////////////////////
	// ORTHOGONAL, ZOOM 보정이 선택 되었다면 --> SCAN ROTATION CALIBRATION DATA 적용
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_ORTHOGONAL_CORRRECTION] == 1)
	{
		/////////////////////////////////////////////////////////////////////////////////
		// SCAN ROTATION 보정을 사용하는 경우
		/////////////////////////////////////////////////////////////////////////////////

		// SCAN ROTATION 실행을 위해 OLD값 변경
		m_pIntegrated->nSRotationValueOld = m_pIntegrated->nSRotationValue + 1;
		// SCAN ROTATION
		AfxScanBridgeSetScanRotation(m_pIntegrated->nSRotationValue);

	}
	else
	{
		/////////////////////////////////////////////////////////////////////////////////
		// SCAN ROTATION 보정을 사용하지 않는 경우
		/////////////////////////////////////////////////////////////////////////////////
	    // ZOOM SCALE 보정값
		double dWDZoomRatio = 1.0;

		/////////////////////////////////////////////////////////////////////////////////
		// 2020.01.17
		// ZOOM 보정
		/////////////////////////////////////////////////////////////////////////////////
		// 1) WD 변화에 따른 Zoom 보정
		if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_WD_SCALE_ZOOM] == 1)
		{
			// WD SCALE ZOOM CORRECTION
			dWDZoomRatio = m_pIntegrated->nWDZoomingLinear[nWD10] / 1000.0;
		}

		// 2) HV보정을 선택 했을 경우
		// MagHV_Ratio 값은 GUN HV 변경시 배율 보정을 위해 재계산 하는 값이다
		// 계산 : MagHV_Ratio = sqrt(GunHV_Table[GunHVIndex] / 30000.0) / 0.8165;
		// HV CORRECTION
		if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_HV_CORRECTION] == 1)
		{
			dWDZoomRatio = dWDZoomRatio * m_pIntegrated->dMagHVRatio;
		}

		// Zoom 설정
		AfxIntegratedSetZoomValue(m_pIntegrated->wZoomXValue, m_pIntegrated->wZoomYValue, dWDZoomRatio);
	}

	// 배율값 적용
	// Avr에 Mag Scale 값을 알려줌 -> Motor 이동 Scale로 사용
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "MG", nMag); // Sbr Data 전송

	// 2020.12.09
	// S-ROT ZOOM X-Y 값 적용 재실행
	// Zoom X-Y 보정값 적용 ( 0 ~ 360도 )
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_ORTHOGONAL_CORRRECTION] == 1)
	{
		// Zoom X-Y MESSAGE 보내기
		if (m_hOwnerWnd != NULL)
		{
			// Zoom X-Y 정보 메시지 보내기
			// 2020.05.04
			SendMessage(m_hOwnerWnd, UM_USB_SBR_ZOOM_XY_RE_EXEC_DATA, NULL, (LPARAM)NULL);
		}
	}

	return RET_SUCCESS_OK;
}

//------------------------------------------------------------------------------
// CommandSend( cWR_XZOOM, mag )를 수행한 후, CommandSend( cWR_YZOOM, mag )를
// 수행하면, FX2 를 통해 FPGA에서 CommandSend 사이의 응답 시간은 약 100 usec 걸린다.
// Interval 간격을 줄이기 위해 한꺼번에 Bundle로 보낸다.
//------------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Zoom 설정하기
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetZoomValue(int nXData, int nYData, double dZoomRatio)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	int nXMag = 0;
	int nYMag = 0;

	double dFXData = 0.0;
	double dFYData = 0.0;

	dFXData = (double)(dZoomRatio * nXData);
	dFYData = (double)(dZoomRatio * nYData);

	// 2020.05.22
	nXMag = (int)(dFXData); //(int)(dFXData+0.5);
	nYMag = (int)(dFYData); //(int)(dFYData+0.5);

	// Zoom X-Y Value Check : 0 ~ 4095
	if (nXMag < 0) nXMag = 0; if (nXMag > 4095) nXMag = 4095;
	if (nYMag < 0) nYMag = 0; if (nYMag > 4095) nYMag = 4095;

	// Zoom 설정
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "ZM0,", nXMag); // Sbr Data 전송
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "ZM1,", nYMag); // Sbr Data 전송

	///////////////////////////////////////////////////////////////////
	// Zoom X-Y 설정 및 실행값 CLIENT 전송
	///////////////////////////////////////////////////////////////////
	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));
	
	// 2020.05.22
	m_pIntegrated->nZoomXValue = nXData;
	m_pIntegrated->nZoomYValue = nYData;

	// Zoom X-Y Value 처리
	UsbDeviceDataInfo.nState = 0;
	UsbDeviceDataInfo.nData[0] = m_pIntegrated->nZoomXValue;     // Zoom X
	UsbDeviceDataInfo.nData[1] = m_pIntegrated->nZoomYValue;     // Zoom Y
	UsbDeviceDataInfo.nData[2] = m_pIntegrated->wMagRelayNumber; // Zoom Relay Number

	// Zoom X-Y MESSAGE 보내기
	if (m_hOwnerWnd != NULL)
	{
		// Zoom X-Y 정보 메시지 보내기
		// 2020.05.04
		SendMessage(m_hOwnerWnd, UM_USB_SBR_ZOOM_XY_VALUE_DATA, NULL, (LPARAM)&UsbDeviceDataInfo);
	}
	///////////////////////////////////////////////////////////////////

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 배율에 따른 릴레이 동작 및 비율 계산
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxIntegratedFindMagRelayRatio(int nMag)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	double dRatio = 0.0;
	WORD   wMask  = 0xFFE0;

	//-----------------------
	// Mx100k Relay 사용금지
	//-----------------------
	m_pIntegrated->wMagRelayNumber = 0;

	// D3 : Mx10k -> 배율이 3만 보다 클 경우 #3 릴레이 동작
	if (nMag > 30000)
	{
		dRatio = (double)nMag / 30000.0;
		m_pIntegrated->wMagRelayNumber = 3;
	}
	// D2 : Mx1k -> 배율이 3천 보다 같거나 클 경우 #2 릴레이 동작
	else if (nMag >= 3000)
	{
		dRatio = (double)nMag / 3000.0;
		m_pIntegrated->wMagRelayNumber = 2;
	}
	// D1 : Mx100 -> 배율이 3백 보다 같거나 클 경우 #1 릴레이 동작
	else if (nMag >= 300)
	{
		dRatio = (double)nMag / 300.0;
		m_pIntegrated->wMagRelayNumber = 1;
	}
	// D0 : Mx10 -> 배율이 20 보다 같거나 클 경우 #0 릴레이 동작
	else if (nMag >= 20)
	{
		dRatio = (double)nMag / 30.0;
		m_pIntegrated->wMagRelayNumber = 0;
	}
	
	// 2019.11.12
	if (m_pIntegrated->wMagRelayNumber != m_pIntegrated->wMagRelayNumberOld)
	{
		//--------------------------------------------------------
		// Mag Relay (배율 릴레이) 동작
		//--------------------------------------------------------
		// 릴레이 동작
		m_pIntegrated->wRelayState &= wMask;
		m_pIntegrated->wRelayState |= m_MagRelay[m_pIntegrated->wMagRelayNumber];
		AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "ZM2,", m_pIntegrated->wRelayState); // Sbr Data 전송

		m_pIntegrated->wMagRelayNumberOld = m_pIntegrated->wMagRelayNumber;
	}

	// 배율에 따른비율값 리턴
	return dRatio;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : CL1 값을 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetCL1(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// CL1 값
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_CL1 + (4095 - m_pIntegrated->wCL1 << 3));

	return RET_SUCCESS_OK;
}
int AfxIntegratedSetCL1(int nCL1)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// CL1 값
	m_pIntegrated->wCL1 = (WORD)nCL1;

	return RET_SUCCESS_OK;
}
int AfxIntegratedSetCL1(int nSpotSize, int nCL1)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// CL1 값
	m_pIntegrated->wCL1 = (WORD)nCL1;
	m_pIntegrated->wCL1List[nSpotSize-1] = m_pIntegrated->wCL1;
	m_nDA_CL1[nSpotSize-1] = m_pIntegrated->wCL1List[nSpotSize-1];

	return RET_SUCCESS_OK;
}
int AfxIntegratedGetCL1(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// CL1 값
	return m_pIntegrated->wCL1;
}
int AfxIntegratedGetCL1(int nSpotSize)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// CL1 값
	return m_pIntegrated->wCL1List[nSpotSize-1];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : CL2 값을 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetCL2(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// CL2 값
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_CL2 + (4095 - m_pIntegrated->wCL2 << 3));

	return RET_SUCCESS_OK;
}
int AfxIntegratedSetCL2(int nCL2)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// CL2 값
	m_pIntegrated->wCL2 = (WORD)nCL2;

	return RET_SUCCESS_OK;
}
int AfxIntegratedSetCL2(int nSpotSize, int nCL2)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// CL2 값
	m_pIntegrated->wCL2 = (WORD)nCL2;
	m_pIntegrated->wCL2List[nSpotSize-1] = m_pIntegrated->wCL2;
	m_nDA_CL2[nSpotSize-1] = m_pIntegrated->wCL2List[nSpotSize-1];

	return RET_SUCCESS_OK;
}
int AfxIntegratedGetCL2(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// CL2 값
	return m_pIntegrated->wCL2;
}
int AfxIntegratedGetCL2(int nSpotSize)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// CL2 값
	return m_pIntegrated->wCL2List[nSpotSize-1];
}

//---------------------------------------------------------------------------------------------------
//   OL 전압이 변화될 때 교정해야할 사항
//---------------------------------------------------------------------------------------------------
// 1) 최소 배율값 변경
// 2) Image 축소되는 현상 --> 배율확대
// 3) Scan Rotation 보정  --> 직교도 보정
// 4) 변화된 WD 값 표시
//---------------------------------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : OL 값을 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetOL(int nCoarse, int nFine)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Coarse 값 설정
	// FOCUS FINE 값이 변경 되었는지 확인한다.
	if (m_pIntegrated->nFocusOldCoarse != nCoarse)
	{
		m_pIntegrated->nFocusCoarse = nCoarse;
		if (m_pIntegrated->nFocusCoarse < SEM_FOCUS_COARSE_MIN) m_pIntegrated->nFocusCoarse = SEM_FOCUS_COARSE_MIN;
		if (m_pIntegrated->nFocusCoarse > SEM_FOCUS_COARSE_MAX) m_pIntegrated->nFocusCoarse = SEM_FOCUS_COARSE_MAX;

		// Smg Command 전송
		AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_OLC + (m_pIntegrated->nFocusCoarse + 4096 << 3)); // 2020.02.18 계산식 오류 발견 --> ((m_pIntegrated->nFocusCoarse + 4096) << 3)
		m_pIntegrated->nFocusOldCoarse = m_pIntegrated->nFocusCoarse;
	}

	//---------------------------------------------------------------
	//  FocusFine 값의 변화 범위가 0 - 128 이므로, 최하의
	//  0 값 근처에서, OP-Amp의 오프셋 때문에 변화가 없을 수 있으므로
	//  중간값에서 변화되도록 변화시킴
	//---------------------------------------------------------------
	// Fine 값은 2048 +/- 128 이다
	//---------------------------------------------------------------
	// Fine 값 설정
	if (nFine > 0) // 2020.02.13 추가
	{
		// FOCUS FINE 값이 변경 되었는지 확인한다.
		if (m_pIntegrated->nFocusOldFine != nFine)
		{
			m_pIntegrated->nFocusFine = nFine;
			if (m_pIntegrated->nFocusFine < SEM_FOCUS_FINE_MIN) m_pIntegrated->nFocusFine = SEM_FOCUS_FINE_MIN;
			if (m_pIntegrated->nFocusFine > SEM_FOCUS_FINE_MAX) m_pIntegrated->nFocusFine = SEM_FOCUS_FINE_MAX;
			// Smg Command 전송
			AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_OLF + (2048 - 128 + m_pIntegrated->nFocusFine << 4)); // 2020.02.18 계산식 오류 발견 --> ((2048 - (128 + m_pIntegrated->nFocusFine)) << 4));
			m_pIntegrated->nFocusOldFine = m_pIntegrated->nFocusFine;
		}
	}


	///////////////////////////////////////////////////////////////////////////////////////
	// 2020.05.11
	// FOCUS COARSE(OL)에 따른 WD값 얻기 (0.1mm단위)
	///////////////////////////////////////////////////////////////////////////////////////
	m_pIntegrated->nOLWD = AfxIntegratedFindWDValue(m_pIntegrated->nFocusCoarse);
	// WD 배율보정 작업중이면
	if (m_pIntegrated->bWDSetupFlag == TRUE)
	{
		// WD SETUP 에 선택된 Z축 위치값 x 10
		m_pIntegrated->nOLWD = m_pIntegrated->nWDStepNumber * 10;
		m_pIntegrated->nOLWDOld = 30; // 3.0[mm]
	}
	// MAX WD-OL 위치값 확인 (MAX : 50.0mm, 500), 버퍼는 최대 60.0mm, 600개 까지 준비됨
	if (m_pIntegrated->nOLWD > 500) m_pIntegrated->nOLWD = 500;

	// 2021.08.03 : 아래의 값 nWDPosition의 범위는 0~50 이므로 nOLWD의 범위 0~500와는 호환되지 않는다
    // WD POSITION 재설정
	//m_pIntegrated->nWDPosition = m_pIntegrated->nOLWD;

	//------------------------------------------------------------------------------------
	// WD에 따른 보정은 필요성 여부를 확인 한 후, 실행한다
	// OL에 따른 WD 위치값이 변화되었으면 WD에 따른 OL, ZOOM, S-ROT를 적용한다
	//------------------------------------------------------------------------------------
	// 0.1mm 이상 OL 값이 변화되었을 경우 ( OL값에 따른 WD값 )
	//------------------------------------------------------------------------------------
	if (m_pIntegrated->nOLWD != m_pIntegrated->nOLWDOld)
	{
		// WD값 보관
		m_pIntegrated->nOLWDOld = m_pIntegrated->nOLWD;

		//------------------------------------------------------
		// OPTION : WD 값 변경에 따른 Zoom Scale, Scan Rotation 적용
		//------------------------------------------------------
		if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_WD_SCALE_ZOOM] == 1 || m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_WD_SCAN_ROTATION] == 1)
		{
			// 2020.06.01 : SCAN ROTATION 보정은 SetMagnification 에 포함되어 있다
			// 2020.06.01 : ZOOM SCALE    보정은 SetMagnification 에 포함되어 있다
			AfxIntegratedSetMagnification(m_nMagStepValue[m_pIntegrated->nMagStepIndex], m_pIntegrated->nOLWD);
		}
		else
		{
			//------------------------------------------------------
			// OPTION : WD 값 변경에 따른 Scan-Rotation 적용
			//------------------------------------------------------
			if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_WD_SCAN_ROTATION] == 1)
			{
				// 2020.05.15
				// WD에 따른 SCAN ROTATION 보정값 : -3600 ~ 0 ~ +3600
				m_pIntegrated->nWDSRotationValue = m_pIntegrated->nWDSRotationLinear[m_pIntegrated->nOLWD];
				// 2020.05.15
				// 현재 선택된 SCAN ROTATION 각도 재실행
				AfxScanBridgeSetScanRotation(m_pIntegrated->nSRotationValue);
			}
			//------------------------------------------------------
			// OPTION : WD 값 변경에 따른 Zoom Scale 적용
			//------------------------------------------------------
			if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_WD_SCALE_ZOOM] == 1)
			{
				AfxIntegratedSetMagnification(m_nMagStepValue[m_pIntegrated->nMagStepIndex], m_pIntegrated->nOLWD);
			}
		}
	}
	///////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////


	return RET_SUCCESS_OK;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Focus Coarse 설정 및 실행
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetFocusCoarse(int nCoarse)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Coarse 값 설정
	// Smg Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_OLC + (nCoarse + 4096 << 3)); // 2020.02.18 계산식 오류 발견 --> ((m_pIntegrated->nFocusCoarse + 4096) << 3)

	return RET_SUCCESS_OK;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : WD 변화에 따른 Focus Coarse 자동설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetWDAutoAdjustFocusCoarse(int nWDPos)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 2020.05.11
	// WD 값에 따른 FOCUS 재설정
	m_pIntegrated->nOLWD = nWDPos;
	if (m_pIntegrated->nOLWD < 0)   m_pIntegrated->nOLWD = 0;   // 0mm
	if (m_pIntegrated->nOLWD > 500) m_pIntegrated->nOLWD = 500; // 50mm

	// FOCUS COARSE 설정
	int nFocusCoarse = m_pIntegrated->nWDOLCoarseLinear[m_pIntegrated->nOLWD];
	AfxIntegratedSetFocusCoarse(nFocusCoarse);

	// 2021.08.03 : 아래의 값 nWDPosition의 범위는 0~50 이므로 nOLWD의 범위 0~500와는 호환되지 않는다
    // WD POSITION 재설정
	//m_pIntegrated->nWDPosition  = m_pIntegrated->nOLWD;

	// FOCUS COARSE 재설정
	m_pIntegrated->nFocusCoarse = nFocusCoarse;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : WOBBLER 를 위한 OLC 값을 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetWobblerOLC(int nWobbblerCoarse)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Smg Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_OLC + nWobbblerCoarse);// ((nWobbblerCoarse + 4096) << 3));

	return RET_SUCCESS_OK;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : WOBBLER 를 위한 STIG-X 값을 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetWobblerSTX(int nWobbblerStigX)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Smg Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_STX + nWobbblerStigX);// ((nWobbblerStigX) << 4));

	return RET_SUCCESS_OK;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : WOBBLER 를 위한 STIG-Y 값을 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetWobblerSTY(int nWobbblerStigY)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Smg Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_STY + nWobbblerStigY);// ((nWobbblerStigY) << 4));

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Spot Size Setting
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetSpotSize()
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Smg Command 전송
	//--------------------------------
	// Spot Size ( CL1, CL2 ) Setting
	//--------------------------------
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_CL1 + (4095 - m_nDA_CL1[m_pIntegrated->nSpotSize - 1] << 3));
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_CL2 + (4095 - m_nDA_CL2[m_pIntegrated->nSpotSize - 1] << 3));

	return RET_SUCCESS_OK;
}
int AfxIntegratedSetSpotSize(int nSpotSize)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	m_pIntegrated->nSpotSize = nSpotSize;

	return RET_SUCCESS_OK;
}
int AfxIntegratedGetSpotSize(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	return m_pIntegrated->nSpotSize;
}
int AfxIntegratedGetCLSpotSize()
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// CL 교정용 SPOT-SIZE
	return m_pIntegrated->nCLSpotSize;
}
int AfxIntegratedSetCLSpotSize(int nSpotSize)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// CL 교정용 SPOT-SIZE
	m_pIntegrated->nCLSpotSize = nSpotSize;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Wobble Setting
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetWobble()
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Smg Command 전송
	//--------------------------------
	// Wobble Setting
	//--------------------------------
	BOOL bLoop = TRUE;
	{
		AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_OLC + (m_nWobblerTable[m_pIntegrated->nWobbleCount] + m_pIntegrated->nFocusCoarse + 4096 << 3));
		m_pIntegrated->nWobbleCount++;
		if (m_pIntegrated->nWobbleCount > 7) m_pIntegrated->nWobbleCount = 0;

		// Run Check ?
		bLoop = m_pIntegrated->bWobbleRunFlag;
		if (bLoop == TRUE)
		{
			//AfxSystemWaitTime(130); // wait 130[ms]
			Sleep(130);
		}
	}

	return RET_SUCCESS_OK;
}
int AfxIntegratedSetWobble(int nWob)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	m_pIntegrated->nWobble = nWob;

	// WOBBLE TABLE 설정
	m_pIntegrated->nWobbleCount = 0;
	double dWobbler = (double)m_pIntegrated->nWobble / 10.0;
	int nMagIndex = m_pIntegrated->nMagStepIndex;
	if (nMagIndex < 10) nMagIndex = 10;
	if (nMagIndex > 63) nMagIndex = 63;
	nMagIndex = 64 - nMagIndex;
	m_nWobblerTable[0] = (int)((m_dSinTable[0] * dWobbler) * (double)nMagIndex);
	m_nWobblerTable[1] = (int)((m_dSinTable[1] * dWobbler) * (double)nMagIndex);
	m_nWobblerTable[2] = (int)((m_dSinTable[2] * dWobbler) * (double)nMagIndex);
	m_nWobblerTable[3] = (int)((m_dSinTable[3] * dWobbler) * (double)nMagIndex);
	m_nWobblerTable[4] = (int)((m_dSinTable[4] * dWobbler) * (double)nMagIndex);
	m_nWobblerTable[5] = (int)((m_dSinTable[5] * dWobbler) * (double)nMagIndex);
	m_nWobblerTable[6] = (int)((m_dSinTable[6] * dWobbler) * (double)nMagIndex);
	m_nWobblerTable[7] = (int)((m_dSinTable[7] * dWobbler) * (double)nMagIndex);


	return RET_SUCCESS_OK;
}
void AfxIntegratedRunWobble(BOOL bRun)
{
	if (bRun == TRUE)
	{
		m_pIntegrated->nWobbleCount = 0;
		m_pIntegrated->bWobbleRunFlag = bRun;
		AfxIntegratedSetWobble();
	}
	else
	{
		m_pIntegrated->bWobbleRunFlag = bRun;
	}
}
int AfxIntegratedGetWobble(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// WOBBLE 값
	return m_pIntegrated->nWobble;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Image Shift XY Initilize Setting
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetImageShiftInitilize()
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Smg Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_EC + 0xC0000);

	return RET_SUCCESS_OK;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Image Shift X Setting
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetImageShiftX()
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Smg Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_ISX + (m_pIntegrated->nISXValue << 4));

	// DEVICE SERVER 윈도우
	if (m_hOwnerWnd != NULL)
	{
		// Image Shift Data 메시지 보내기
		// 2020.05.04
		//SendMessage(m_hOwnerWnd, UM_USB_SBR_IMAGESHIFT_DATA, NULL, NULL);
	}

	return RET_SUCCESS_OK;
}
int AfxIntegratedSetImageShiftX(int nISX)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Image Shift X
	m_pIntegrated->nISXValue = nISX;

	return RET_SUCCESS_OK;
}
int AfxIntegratedGetImageShiftX(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Image Shift X
	return m_pIntegrated->nISXValue;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Image Shift Y Setting
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetImageShiftY()
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Smg Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_ISY + (m_pIntegrated->nISYValue << 4));

	// DEVICE SERVER 윈도우
	if (m_hOwnerWnd != NULL)
	{
		// Image Shift Data 메시지 보내기
		// 2020.05.04
		//SendMessage(m_hOwnerWnd, UM_USB_SBR_IMAGESHIFT_DATA, NULL, NULL);
	}

	return RET_SUCCESS_OK;
}
int AfxIntegratedSetImageShiftY(int nISY)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Image Shift Y
	m_pIntegrated->nISYValue = nISY;

	return RET_SUCCESS_OK;
}
int AfxIntegratedGetImageShiftY(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Image Shift Y
	return m_pIntegrated->nISYValue;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Gun Align X 값을 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetGunAlignX(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Smg Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_GAX + (m_pIntegrated->nGAXValue << 4));

	// DEVICE SERVER 윈도우
	if (m_hOwnerWnd != NULL)
	{
		// Gun Align Data 메시지 보내기
		// 2020.05.04
		//SendMessage(m_hOwnerWnd, UM_USB_SBR_GUNALIGN_DATA, NULL, NULL);
	}

	return RET_SUCCESS_OK;
}
int AfxIntegratedSetGunAlignX(int nGAX)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	m_pIntegrated->nGAXValue = nGAX;

	return RET_SUCCESS_OK;
}
int AfxIntegratedGetGunAlignX(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	return m_pIntegrated->nGAXValue;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Gun Align Y 값을 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetGunAlignY(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Smg Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_GAY + (m_pIntegrated->nGAYValue << 4));

	// DEVICE SERVER 윈도우
	if (m_hOwnerWnd != NULL)
	{
		// Gun Align Data 메시지 보내기
		// 2020.05.04
		//SendMessage(m_hOwnerWnd, UM_USB_SBR_GUNALIGN_DATA, NULL, NULL);
	}

	return RET_SUCCESS_OK;
}
int AfxIntegratedSetGunAlignY(int nGAY)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	m_pIntegrated->nGAYValue = nGAY;

	return RET_SUCCESS_OK;
}
int AfxIntegratedGetGunAlignY(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	return m_pIntegrated->nGAYValue;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Beam Align X 값을 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetBeamAlignX(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Smg Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_BAX + (m_pIntegrated->nBAXValue << 4));

	// DEVICE SERVER 윈도우
	if (m_hOwnerWnd != NULL)
	{
		// Beam Align Data 메시지 보내기
		// 2020.05.04
		//SendMessage(m_hOwnerWnd, UM_USB_SBR_BEAMALIGN_DATA, NULL, NULL);
	}

	return RET_SUCCESS_OK;
}
int AfxIntegratedSetBeamAlignX(int nGAX)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	m_pIntegrated->nBAXValue = nGAX;

	return RET_SUCCESS_OK;
}
int AfxIntegratedGetBeamAlignX(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	return m_pIntegrated->nBAXValue;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Beam Align Y 값을 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetBeamAlignY(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Smg Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_BAY + (m_pIntegrated->nBAYValue << 4));

	// DEVICE SERVER 윈도우
	if (m_hOwnerWnd != NULL)
	{
		// Beam Align Data 메시지 보내기
		// 2020.05.04
		//SendMessage(m_hOwnerWnd, UM_USB_SBR_BEAMALIGN_DATA, NULL, NULL);
	}

	return RET_SUCCESS_OK;
}
int AfxIntegratedSetBeamAlignY(int nGAY)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	m_pIntegrated->nBAYValue = nGAY;

	return RET_SUCCESS_OK;
}
int AfxIntegratedGetBeamAlignY(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	return m_pIntegrated->nBAYValue;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Stig X Setting
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetStigX()
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Smg Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_STX + (m_pIntegrated->nStigXValue << 4));

	// DEVICE SERVER 윈도우
	if (m_hOwnerWnd != NULL)
	{
		// Stig Data 메시지 보내기
		// 2020.05.04
		//SendMessage(m_hOwnerWnd, UM_USB_SBR_STIG_DATA, NULL, NULL);
	}

	return RET_SUCCESS_OK;
}
int AfxIntegratedSetStigX(int nStigX)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stig X
	m_pIntegrated->nStigXValue = nStigX;

	return RET_SUCCESS_OK;
}
int AfxIntegratedGetStigX(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stig X
	return m_pIntegrated->nStigXValue;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Stig Y Setting
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetStigY()
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Smg Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_STY + (m_pIntegrated->nStigYValue << 4));

	// DEVICE SERVER 윈도우
	if (m_hOwnerWnd != NULL)
	{
		// Stig Data 메시지 보내기
		// 2020.05.04
		//SendMessage(m_hOwnerWnd, UM_USB_SBR_STIG_DATA, NULL, NULL);
	}

	return RET_SUCCESS_OK;
}
int AfxIntegratedSetStigY(int nStigY)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stig Y
	m_pIntegrated->nStigYValue = nStigY;

	return RET_SUCCESS_OK;
}
int AfxIntegratedGetStigY(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stig Y
	return m_pIntegrated->nStigYValue;
}

//------------------------------------------------------------------------------
// WD에 따른 WD_OL_Coarse, WD_SRotation, WD_Zooming 값을 설정하는 방법
//------------------------------------------------------------------------------
// 1) 처음에는  m_pIntegrated->nWDOLCoarse[] 값을 Board에서 측정한 전압값을 발생시키는
//    Cal_WD_OL_Value_From_SM300_OL_Voltage() 함수에서 만들려고 하였으나.
//
// 2) WD=5mm (IniPar.WD_TopLimit)에서 AutoFocus를 수행하고 얻은 OL값을 m_pIntegrated->nWDOLCoarse[]에
//    저장하고, 1mm씩 이동한 후 반복 시행을 WD=40mm(IniPar.WD_BottomLimit)까지 진행한다.
//
// 3) 이 때 얻은 m_pIntegrated->nWDOLCoarse[] 값이 정확한지 WD 위치에서 확인하면서,
//    m_pIntegrated->nWDSRotation[], m_pIntegrated->nWDZooming[] 값을 저장한다.
//
// 4) 1mm 간격으로 측정값을 얻으므로, 분해능을 0.1mm 까지 얻기위해
//    1mm 간격의 Data를 10등분으로 선형화 작업을 프로그램 시작시 진행한다.
//------------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : WD에 따른 OL_Coarse, ScanRotation, Zooming, MinMag 보정값 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetWDCompensation(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// WD 최대 항목 갯수 : 50 Item (최대 60개)
	m_pIntegrated->nWDMaxValue = 50;

	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	// WD = 5mm                                                                                        // 길이변화의 정확도를  올리기 위해 1000 배율로
	// 100을 기준으로하였을 때 축소되는 배율
	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	m_pIntegrated->nWDOLCoarse[0] = 3800;    m_pIntegrated->nWDSRotation[0] = -36;      m_pIntegrated->nWDZooming[0] = 1000;     m_pIntegrated->nWDMinMag[0] = 70;
	m_pIntegrated->nWDOLCoarse[1] = 3800;    m_pIntegrated->nWDSRotation[1] = -20;      m_pIntegrated->nWDZooming[1] = 1000;     m_pIntegrated->nWDMinMag[1] = 70;
	m_pIntegrated->nWDOLCoarse[2] = 3800;    m_pIntegrated->nWDSRotation[2] = -14;      m_pIntegrated->nWDZooming[2] = 1000;     m_pIntegrated->nWDMinMag[2] = 70;
	m_pIntegrated->nWDOLCoarse[3] = 3800;    m_pIntegrated->nWDSRotation[3] = -10;      m_pIntegrated->nWDZooming[3] = 1000;     m_pIntegrated->nWDMinMag[3] = 70;
	m_pIntegrated->nWDOLCoarse[4] = 3800;    m_pIntegrated->nWDSRotation[4] = -5;       m_pIntegrated->nWDZooming[4] = 1000;     m_pIntegrated->nWDMinMag[4] = 70;
	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	// WD = 5mm    TP14    -7.047V
	m_pIntegrated->nWDOLCoarse[5] = 3505;    m_pIntegrated->nWDSRotation[5] = 0;        m_pIntegrated->nWDZooming[5] = 1000;     m_pIntegrated->nWDMinMag[5] = 70;
	// WD = 6mm            -6.722V
	m_pIntegrated->nWDOLCoarse[6] = 3341;    m_pIntegrated->nWDSRotation[6] = 32;       m_pIntegrated->nWDZooming[6] = 940;      m_pIntegrated->nWDMinMag[6] = 70;
	// WD = 7mm            -6.438V
	m_pIntegrated->nWDOLCoarse[7] = 3200;    m_pIntegrated->nWDSRotation[7] = 57;       m_pIntegrated->nWDZooming[7] = 860;      m_pIntegrated->nWDMinMag[7] = 50;
	// WD = 8mm            -6.183V
	m_pIntegrated->nWDOLCoarse[8] = 3072;    m_pIntegrated->nWDSRotation[8] = 83;       m_pIntegrated->nWDZooming[8] = 810;      m_pIntegrated->nWDMinMag[8] = 50;
	// WD = 9mm            -5.953V
	m_pIntegrated->nWDOLCoarse[9] = 2958;    m_pIntegrated->nWDSRotation[9] = 104;      m_pIntegrated->nWDZooming[9] = 760;      m_pIntegrated->nWDMinMag[9] = 50;
	// WD = 10mm           -5.787V
	m_pIntegrated->nWDOLCoarse[10] = 2874;   m_pIntegrated->nWDSRotation[10] = 124;     m_pIntegrated->nWDZooming[10] = 720;     m_pIntegrated->nWDMinMag[10] = 50;
	// WD = 11mm               67
	m_pIntegrated->nWDOLCoarse[11] = 2886;   m_pIntegrated->nWDSRotation[11] = 143;     m_pIntegrated->nWDZooming[11] = 680;     m_pIntegrated->nWDMinMag[11] = 50;
	// WD = 12mm               80
	m_pIntegrated->nWDOLCoarse[12] = 2806;   m_pIntegrated->nWDSRotation[12] = 162;     m_pIntegrated->nWDZooming[12] = 650;     m_pIntegrated->nWDMinMag[12] = 50;
	// WD = 13mm               85
	m_pIntegrated->nWDOLCoarse[13] = 2721;   m_pIntegrated->nWDSRotation[13] = 176;     m_pIntegrated->nWDZooming[13] = 610;     m_pIntegrated->nWDMinMag[13] = 50;
	// WD = 14mm               68
	m_pIntegrated->nWDOLCoarse[14] = 2658;   m_pIntegrated->nWDSRotation[14] = 187;     m_pIntegrated->nWDZooming[14] = 580;     m_pIntegrated->nWDMinMag[14] = 50;
	// WD = 15mm               48
	m_pIntegrated->nWDOLCoarse[15] = 2610;   m_pIntegrated->nWDSRotation[15] = 200;     m_pIntegrated->nWDZooming[15] = 560;     m_pIntegrated->nWDMinMag[15] = 50;
	// WD = 16mm               79
	m_pIntegrated->nWDOLCoarse[16] = 2531;   m_pIntegrated->nWDSRotation[16] = 214;     m_pIntegrated->nWDZooming[16] = 540;     m_pIntegrated->nWDMinMag[16] = 50;
	// WD = 17mm               47
	m_pIntegrated->nWDOLCoarse[17] = 2484;   m_pIntegrated->nWDSRotation[17] = 225;     m_pIntegrated->nWDZooming[17] = 520;     m_pIntegrated->nWDMinMag[17] = 30;
	// WD = 18mm               36
	m_pIntegrated->nWDOLCoarse[18] = 2448;   m_pIntegrated->nWDSRotation[18] = 235;     m_pIntegrated->nWDZooming[18] = 490;     m_pIntegrated->nWDMinMag[18] = 30;
	// WD = 19mm               56
	m_pIntegrated->nWDOLCoarse[19] = 2392;   m_pIntegrated->nWDSRotation[19] = 248;     m_pIntegrated->nWDZooming[19] = 480;     m_pIntegrated->nWDMinMag[19] = 30;
	// WD = 20mm               45
	m_pIntegrated->nWDOLCoarse[20] = 2347;   m_pIntegrated->nWDSRotation[20] = 255;     m_pIntegrated->nWDZooming[20] = 460;     m_pIntegrated->nWDMinMag[20] = 30;
	// WD = 21mm               40
	m_pIntegrated->nWDOLCoarse[21] = 2307;   m_pIntegrated->nWDSRotation[21] = 265;     m_pIntegrated->nWDZooming[21] = 440;     m_pIntegrated->nWDMinMag[21] = 30;
    // WD = 22mm               41
	m_pIntegrated->nWDOLCoarse[22] = 2266;   m_pIntegrated->nWDSRotation[22] = 269;     m_pIntegrated->nWDZooming[22] = 430;     m_pIntegrated->nWDMinMag[22] = 30;
	// WD = 23mm               35
	m_pIntegrated->nWDOLCoarse[23] = 2231;   m_pIntegrated->nWDSRotation[23] = 281;     m_pIntegrated->nWDZooming[23] = 420;     m_pIntegrated->nWDMinMag[23] = 30;
	// WD = 24mm               45
	m_pIntegrated->nWDOLCoarse[24] = 2186;   m_pIntegrated->nWDSRotation[24] = 288;     m_pIntegrated->nWDZooming[24] = 400;     m_pIntegrated->nWDMinMag[24] = 30;
	// WD = 25mm               25
	m_pIntegrated->nWDOLCoarse[25] = 2161;   m_pIntegrated->nWDSRotation[25] = 294;     m_pIntegrated->nWDZooming[25] = 390;     m_pIntegrated->nWDMinMag[25] = 30;
	// WD = 26mm               33
	m_pIntegrated->nWDOLCoarse[26] = 2128;   m_pIntegrated->nWDSRotation[26] = 300;     m_pIntegrated->nWDZooming[26] = 380;     m_pIntegrated->nWDMinMag[26] = 30;
	// WD = 27mm               21
	m_pIntegrated->nWDOLCoarse[27] = 2107;   m_pIntegrated->nWDSRotation[27] = 308;     m_pIntegrated->nWDZooming[27] = 370;     m_pIntegrated->nWDMinMag[27] = 30;
	// WD = 28mm               31
	m_pIntegrated->nWDOLCoarse[28] = 2076;   m_pIntegrated->nWDSRotation[28] = 313;     m_pIntegrated->nWDZooming[28] = 360;     m_pIntegrated->nWDMinMag[28] = 30;
	// WD = 29mm               20
	m_pIntegrated->nWDOLCoarse[29] = 2056;   m_pIntegrated->nWDSRotation[29] = 318;     m_pIntegrated->nWDZooming[29] = 350;     m_pIntegrated->nWDMinMag[29] = 30;
	// WD = 30mm               36
	m_pIntegrated->nWDOLCoarse[30] = 2020;   m_pIntegrated->nWDSRotation[30] = 323;     m_pIntegrated->nWDZooming[30] = 340;     m_pIntegrated->nWDMinMag[30] = 30;
	// WD = 31mm               39
	m_pIntegrated->nWDOLCoarse[31] = 1981;   m_pIntegrated->nWDSRotation[31] = 327;     m_pIntegrated->nWDZooming[31] = 330;     m_pIntegrated->nWDMinMag[31] = 20;
	// WD = 32mm               16
	m_pIntegrated->nWDOLCoarse[32] = 1965;   m_pIntegrated->nWDSRotation[32] = 332;     m_pIntegrated->nWDZooming[32] = 320;     m_pIntegrated->nWDMinMag[32] = 20;
	// WD = 33mm               20
	m_pIntegrated->nWDOLCoarse[33] = 1945;   m_pIntegrated->nWDSRotation[33] = 337;     m_pIntegrated->nWDZooming[33] = 310;     m_pIntegrated->nWDMinMag[33] = 20;
	// WD = 34mm               29
	m_pIntegrated->nWDOLCoarse[34] = 1916;   m_pIntegrated->nWDSRotation[34] = 345;     m_pIntegrated->nWDZooming[34] = 310;     m_pIntegrated->nWDMinMag[34] = 20;
	// WD = 35mm               17
	m_pIntegrated->nWDOLCoarse[35] = 1899;   m_pIntegrated->nWDSRotation[35] = 346;     m_pIntegrated->nWDZooming[35] = 300;     m_pIntegrated->nWDMinMag[35] = 20;
	// WD = 36mm               16
	m_pIntegrated->nWDOLCoarse[36] = 1883;   m_pIntegrated->nWDSRotation[36] = 351;     m_pIntegrated->nWDZooming[36] = 290;     m_pIntegrated->nWDMinMag[36] = 20;
	// WD = 37mm               23
	m_pIntegrated->nWDOLCoarse[37] = 1860;   m_pIntegrated->nWDSRotation[37] = 353;     m_pIntegrated->nWDZooming[37] = 290;     m_pIntegrated->nWDMinMag[37] = 20;
	// WD = 38mm               20
	m_pIntegrated->nWDOLCoarse[38] = 1840;   m_pIntegrated->nWDSRotation[38] = 356;     m_pIntegrated->nWDZooming[38] = 280;     m_pIntegrated->nWDMinMag[38] = 20;
	// WD = 39mm               19
	m_pIntegrated->nWDOLCoarse[39] = 1821;   m_pIntegrated->nWDSRotation[39] = 360;     m_pIntegrated->nWDZooming[39] = 270;     m_pIntegrated->nWDMinMag[39] = 20;
	// WD = 40mm               36
	m_pIntegrated->nWDOLCoarse[40] = 1790;   m_pIntegrated->nWDSRotation[40] = 362;     m_pIntegrated->nWDZooming[40] = 269;     m_pIntegrated->nWDMinMag[40] = 30;
	// WD = 41mm               39
	m_pIntegrated->nWDOLCoarse[41] = 1780;   m_pIntegrated->nWDSRotation[41] = 363;     m_pIntegrated->nWDZooming[41] = 268;     m_pIntegrated->nWDMinMag[41] = 20;
	// WD = 42mm               16
	m_pIntegrated->nWDOLCoarse[42] = 1760;   m_pIntegrated->nWDSRotation[42] = 364;     m_pIntegrated->nWDZooming[42] = 267;     m_pIntegrated->nWDMinMag[42] = 20;
	// WD = 43mm               20
	m_pIntegrated->nWDOLCoarse[43] = 1750;   m_pIntegrated->nWDSRotation[43] = 365;     m_pIntegrated->nWDZooming[43] = 266;     m_pIntegrated->nWDMinMag[43] = 20;
	// WD = 44mm               29
	m_pIntegrated->nWDOLCoarse[44] = 1740;   m_pIntegrated->nWDSRotation[44] = 366;     m_pIntegrated->nWDZooming[44] = 265;     m_pIntegrated->nWDMinMag[44] = 20;
	// WD = 45mm               17
	m_pIntegrated->nWDOLCoarse[45] = 1730;   m_pIntegrated->nWDSRotation[45] = 367;     m_pIntegrated->nWDZooming[45] = 264;     m_pIntegrated->nWDMinMag[45] = 20;
	// WD = 46mm               16
	m_pIntegrated->nWDOLCoarse[46] = 1720;   m_pIntegrated->nWDSRotation[46] = 368;     m_pIntegrated->nWDZooming[46] = 263;     m_pIntegrated->nWDMinMag[46] = 20;
	// WD = 47mm               23
	m_pIntegrated->nWDOLCoarse[47] = 1710;   m_pIntegrated->nWDSRotation[47] = 369;     m_pIntegrated->nWDZooming[47] = 262;     m_pIntegrated->nWDMinMag[47] = 20;
	// WD = 48mm               20
	m_pIntegrated->nWDOLCoarse[48] = 1700;   m_pIntegrated->nWDSRotation[48] = 370;     m_pIntegrated->nWDZooming[48] = 261;     m_pIntegrated->nWDMinMag[48] = 20;
	// WD = 49mm               19
	m_pIntegrated->nWDOLCoarse[49] = 1690;   m_pIntegrated->nWDSRotation[49] = 371;     m_pIntegrated->nWDZooming[49] = 260;     m_pIntegrated->nWDMinMag[49] = 20;
	// WD = 49mm               19
	m_pIntegrated->nWDOLCoarse[50] = 1690;   m_pIntegrated->nWDSRotation[50] = 371;     m_pIntegrated->nWDZooming[50] = 260;     m_pIntegrated->nWDMinMag[50] = 20;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : WD에 따른 OL_Coarse, ScanRotation, Zooming, MinMag 보정값 10등분 선형화 작업
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetWDOLSrotZoomingLinearize(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// WD 최대 항목 갯수 : 50 Item (최대 60개)
	int    nWD = 0;
	int    n   = 0;
	double dOffset   = 0.0;
	double dBase_off = 0.0;

	// 2021.08.02
	int nMaxWD = 60; //m_pIntegrated->nWDMaxValue;

	//--------------------------------------------------------------------------
	// 10등분 선형화 작업 : m_pIntegrated->nWDOLCoarse[] ==> WD_OL_coarse[]
	//--------------------------------------------------------------------------
	for (nWD = 0; nWD < nMaxWD; nWD++)
	{
		// Focus Coarse 값은 점점 감소한다
		dOffset   = (m_pIntegrated->nWDOLCoarse[nWD] - m_pIntegrated->nWDOLCoarse[nWD + 1]) / 10.0;
		dBase_off = (double)m_pIntegrated->nWDOLCoarse[nWD];
		// 10 등분 선형화 작업
		for (n = 0; n<10; n++)
		{
			// 2021.08.02 : 기본설정값 수정됨, 아래 내용은 사용하지 않음.
			// 2021.06.03
			// WD 4.0[mm] 미만 CHECK?
			//if (nWD < 4)
			//{
			//	// WD 4.0[mm] 미만 일 경우 기본값으로 설정 한다
			//	m_pIntegrated->nWDOLCoarseLinear[(nWD * 10) + n] = 4095;
			//	continue;
			//}
			if (n == 0)
			{
				m_pIntegrated->nWDOLCoarseLinear[(nWD * 10) + n] = m_pIntegrated->nWDOLCoarse[nWD];
			}
			else
			{
				m_pIntegrated->nWDOLCoarseLinear[(nWD * 10) + n] = (int)dBase_off;
			}
			dBase_off -= dOffset;
		}
	}

	//--------------------------------------------------------------------------
	// 10등분 선형화 작업 : m_pIntegrated->nWDZooming[] ==> WD_zooming[]
	//--------------------------------------------------------------------------
	for (nWD = 0; nWD < nMaxWD; nWD++)
	{
		// Zoom 값은 점점 감소한다
		dOffset   = (m_pIntegrated->nWDZooming[nWD] - m_pIntegrated->nWDZooming[nWD + 1]) / 10.0;
		dBase_off = (double)m_pIntegrated->nWDZooming[nWD];
		// 10 등분 선형화 작업
		for (n = 0; n<10; n++)
		{
			// 2021.08.02 : 기본설정값 수정됨, 아래 내용은 사용하지 않음.
			// 2021.06.03
			// WD 4.0[mm] 미만 CHECK?
			//if (nWD < 4)
			//{
			//	// WD 4.0[mm] 미만 일 경우 기본값으로 설정 한다
			//	m_pIntegrated->nWDZoomingLinear[(nWD * 10) + n] = 1000;
			//	continue;
			//}
			if (n == 0)
			{
				m_pIntegrated->nWDZoomingLinear[(nWD * 10) + n] = m_pIntegrated->nWDZooming[nWD];
			}
			else
			{
				m_pIntegrated->nWDZoomingLinear[(nWD * 10) + n] = (int)dBase_off;
			}
			dBase_off -= dOffset;
		}
	}

	//--------------------------------------------------------------------------
	// 10등분 선형화 작업 : m_pIntegrated->nWDSRotation[] ==> WD_srotation[]
	//--------------------------------------------------------------------------
	for (nWD = 0; nWD < nMaxWD; nWD++)
	{
		// S-Rot 값은 점점 증가한다
		dOffset   = (m_pIntegrated->nWDSRotation[nWD + 1] - m_pIntegrated->nWDSRotation[nWD]) / 10.0;
		dBase_off = (double)m_pIntegrated->nWDSRotation[nWD];
		// 10 등분 선형화 작업
		for (n = 0; n<10; n++)
		{
			// 2021.08.02 : 기본설정값 수정됨, 아래 내용은 사용하지 않음.
			// 2021.06.03
			// WD 4.0[mm] 미만 CHECK?
			//if (nWD < 4)
			//{
			//	// WD 4.0[mm] 미만 일 경우 기본값으로 설정 한다
			//	m_pIntegrated->nWDSRotationLinear[(nWD * 10) + n] = 0;
			//	continue;
			//}
			if (n == 0)
			{
				m_pIntegrated->nWDSRotationLinear[(nWD * 10) + n] = m_pIntegrated->nWDSRotation[nWD];
			}
			else
			{
				m_pIntegrated->nWDSRotationLinear[nWD * 10 + n] = (int)dBase_off;
			}
			dBase_off += dOffset;
		}
	}
	//--------------------------------------------------------------------------

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Focus Coarse (OL값) 에 따른 WDx10 값 찾기
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedFindWDValue(int nCoarse)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	int nWDx10 = 0;

	// Focus Coarse를 Linear 한 배열을 검색한다
	int nWDMax10 = m_pIntegrated->nWDMaxValue * 10;

	// 시작은 3.0mm 부터 검색
	for (nWDx10 = 30; nWDx10 < nWDMax10; nWDx10++)
	{
		if (m_pIntegrated->nWDOLCoarseLinear[nWDx10] <= nCoarse)  break;
	}

	return nWDx10;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Lens Coil에 흐르는 전류 최소화
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedLensCoilCurrentMinimum(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	//--------------------------------------------
	// Lens Coil에 흐르는 전류 최소화
	//--------------------------------------------
	// GAX, GAY
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_GAX + (2048 << 4));
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_GAY + (2048 << 4));
	// BAX, BAY
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_BAX + (2048 << 4));
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_BAY + (2048 << 4));
	// CL1, CL2
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_CL1 + (4095 << 3));
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_CL2 + (4095 << 3));
	// OL
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_OLC + (4095 << 3));
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_OLF + (2048 << 4));
	// StigX, StigY
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_STX + (2048 << 4));
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_STY + (2048 << 4));
	// ImgShiftX, ImgShiftY
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_ISX + (2048 << 4));
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_ISY + (2048 << 4));

	return RET_SUCCESS_OK;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// SEM SE Image Data Device Command Control...
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////
// SE Image Data : SEM SE Image Data 획득 쓰레드 생성
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxCreateSEImageDataThread(void)
{
	// SE Image Data 쓰레드 사용 중이면...
	if (m_pSEImageDataThread != NULL) return RET_SUCCESS_OK;
	// SE Image Data 쓰레드 파라메터 중복 확인
	if (m_pSEImageDataThreadParams != NULL)
	{
		// Scan Bridge 쓰레드에서 사용한 파라메터 삭제
		delete m_pSEImageDataThreadParams;
		m_pSEImageDataThreadParams = NULL;
	}

	// SE Image Scan 쓰레드 강제종료 : 비활성
	m_pIntegrated->bScanThreadStop = FALSE;

	// Scan Bridge 쓰레드에서 사용할 파라메터를 생성한다
	m_pSEImageDataThreadParams = new SEIMAGEDATATHREADPARAMS;
	if (m_pSEImageDataThreadParams == NULL) return RET_ERROR_SEM_THREAD_PARAMS;
	memset(m_pSEImageDataThreadParams, 0x00, sizeof(SEIMAGEDATATHREADPARAMS));
	// Scan Bridge 쓰레드에서 사용할 파라메터 기본값 설정
	m_pSEImageDataThreadParams->bThreadDone  = FALSE;          // 쓰레드 종료 설정
	m_pSEImageDataThreadParams->nFT232HIndex = IDX_FT232H_SEM_IMAGE_DEVICE; // SE Image Scan 장치 인덱스
	m_pSEImageDataThreadParams->hFT232Handle = NULL;           // SE Image Scan 장치 핸들
	m_pSEImageDataThreadParams->hEventHandle = NULL;           // SE Image Scan 이벤트 핸들
	////////////////////////////////////////////////////////////////////////////////////////////////////
	memset(m_pSEImageDataThreadParams->szFTReadBuf    , 0x00, sizeof(m_pSEImageDataThreadParams->szFTReadBuf)); // SE Image Data Read Buffer
	memset(m_pSEImageDataThreadParams->wXPixNumPerLine, 0x00, sizeof(WORD) * 1000                            ); // SE Image Data Debug 용 Line 당 Pixel Count
	memset(m_pSEImageDataThreadParams->wAvrAutoValue  , 0x00, sizeof(WORD) * 2                               ); // SE Image Data Auto Value Buffer
	m_pSEImageDataThreadParams->bFirstButtonPressed = m_pIntegrated->bFirstButtonPressed;                       // SE Image Data Frame Start Flag
	m_pSEImageDataThreadParams->bScanDataClear      = FALSE;   // SE Image Data All Clear Flag
	m_pSEImageDataThreadParams->bScanDataReceive    = FALSE;   // SE Image Data Scan & Read Flag
	m_pSEImageDataThreadParams->bFirstButtonPressed = FALSE;   // SE Image Data Frame Start Flag
	m_pSEImageDataThreadParams->bErrorFlag          = FALSE;   // SE Image Data Error Flag
	m_pSEImageDataThreadParams->pbfPtr              = NULL;    // SE Image Data Frame Buffer X,Y Position Pointer
	m_pSEImageDataThreadParams->pbmPtr              = NULL;    // SE Image Data Bitmap Buffer X,Y Position Pointer
	m_pSEImageDataThreadParams->pbfPtrB             = NULL;    // SE Image Data Frame Buffer X,Y Position Pointer B
	m_pSEImageDataThreadParams->pbmPtrB             = NULL;    // SE Image Data Bitmap Buffer X,Y Position Pointer B
	m_pSEImageDataThreadParams->nABCCount           = 0;       // SE Image Data ABC Count (Data -> Avr Bright, Contrast Count ???)
	m_pSEImageDataThreadParams->nFrameCount         = 0;       // SE Image Data Frame Count
	m_pSEImageDataThreadParams->nXDrawPosition      = 0;       // SE Image Data Bitmap X Draw Position
	m_pSEImageDataThreadParams->nXBmpOffset         = 0;       // SE Image Data Bitmap X Draw Offset Position
	m_pSEImageDataThreadParams->nYDrawPosition      = 0;       // SE Image Data Bitmap Y Draw Position
	m_pSEImageDataThreadParams->nYBmpOffset         = 0;       // SE Image Data Bitmap Y Draw Offset Position
	m_pSEImageDataThreadParams->nXDrawPositionB     = 0;       // SE Image Data Bitmap X Draw Position B
	m_pSEImageDataThreadParams->nYDrawPositionB     = 0;       // SE Image Data Bitmap Y Draw Position B
	m_pSEImageDataThreadParams->nFrameBrightLevel   = 0;       // SE Image Data Frame Brightness Level
	m_pSEImageDataThreadParams->nPixelLevelSum      = 0;       // SE Image Data Pixel Sum
	m_pSEImageDataThreadParams->nPixelCount         = 0;       // SE Image Data Pixel Count
	m_pSEImageDataThreadParams->nWAverageNum        = 0;       // SE Image Data Average Number
	m_pSEImageDataThreadParams->nWAFrameNumA        = 0;       // SE Image Data A Frame Average Count
	m_pSEImageDataThreadParams->nWAFrameNumB        = 0;       // SE Image Data B Frame Average Count
	m_pSEImageDataThreadParams->nXBmpPixel          = 0;       // SE Image Data Max X Pixel Count
	m_pSEImageDataThreadParams->nYBmpPixel          = 0;       // SE Image Data Max Y Pixel Count
	m_pSEImageDataThreadParams->nAvrContrast        = 0;       // SE Image Data Avr Contrast   
	m_pSEImageDataThreadParams->nAvrBright          = 0;       // SE Image Data Avr Brightness
	m_pSEImageDataThreadParams->nAfcAvrOL           = 0;       // SE Image Data AFC Avr OL
	m_pSEImageDataThreadParams->nDMag               = 0;       // SE Image Data Debug 용 Line 당 Pixel Count
	////////////////////////////////////////////////////////////////////////////////////////////////////

	// 핸들 설정
	FT_HANDLE ft232hHandle = AfxFT232HGetHandle(m_pSEImageDataThreadParams->nFT232HIndex);
	if (ft232hHandle == NULL) return RET_ERROR_FT232H_SEM_HANDLE;
	m_pSEImageDataThreadParams->hFT232Handle = ft232hHandle; // SE Image Data 장치 핸들

	// SE Image Data 이벤트 마스크
	FT_STATUS ftStatus = NULL;
	DWORD     dwEventMask = NULL;

	// CreateEvent
	// CreateEvent( SECURITY_ATTRIBUTES, (대부분 NULL로 사용)
	//	            bMaunalReset,        (TRUE이면 수동리셋, FALSE이면 자동리셋 이벤트 생성)
	//              bInitialState,       (TRUE이면 신호 상태, FALSE이면 비신호 상태로 시작)
	//              lpName               (이벤트를 서로 다른 프로세스에 속한 스레드가 사용할 수 있도록, 이름을 줄 수 있다.NULL을 사용하면 이름없는 이벤트 생성)
	// )

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Scan Bridge 쓰레드에서 사용할 이벤트 항목 : 읽기완료 이벤트로 설정
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	m_pSEImageDataThreadParams->hEventHandle = CreateEvent(NULL, FALSE, FALSE, _T(""));              // SE Scan Image Data 쓰레드에서 사용할 이벤트 생성
	if (m_pSEImageDataThreadParams->hEventHandle == NULL) return RET_ERROR_SEM_EVENT_HANDLE;         // 이벤트 생성 오류 확인
	dwEventMask = FT_EVENT_RXCHAR;                                                                   // SE Image Data 장치에서 사용할 이벤트 항목 설정
	ftStatus = AfxFT232HSetEventNotification(m_pSEImageDataThreadParams->nFT232HIndex, dwEventMask, m_pSEImageDataThreadParams->hEventHandle); // SE Image Scan 쓰레드에서 사용할 이벤트 설정
	if (ftStatus != FT_OK) return RET_ERROR_SBR_EVENT_MASK;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// SE Image Data 쓰레드 생성 및 시작...
	m_pSEImageDataThread = AfxBeginThread(AfxThreadSEImageDataProcessing, m_pSEImageDataThreadParams); // , THREAD_PRIORITY_NORMAL);
	if (m_pSEImageDataThread == NULL) return RET_ERROR_SEM_THREAD_HANDLE;

	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// SE Image Data : 수신 데이터 획득 처리(작업) 및 이미지 데이터 처리 쓰레드
/////////////////////////////////////////////////////////////////////////////////////////////////////
UINT AfxThreadSEImageDataProcessing(LPVOID pParams)
{
	LPSEIMAGEDATATHREADPARAMS pThreadParams = (LPSEIMAGEDATATHREADPARAMS)pParams;

	// 쓰레드 작업 상태 설정
	pThreadParams->bThreadDone = FALSE;

	BOOL  bLoop = TRUE;
	DWORD dwRet = 0;
	int   nScanMode = 0;
	int   nReceiveCount = 0;

	// 쓰레드 종료 (강제)결정
	pThreadParams->bThreadStop = FALSE;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// SE Image Data 쓰레드 프로세싱
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while (bLoop == TRUE)
	{
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// SE Image Data 장치 이벤트 발생 확인...타임아웃 1000[ms]
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		dwRet = WaitForSingleObject(pThreadParams->hEventHandle, FT232H_EVENT_TIMEOUT);

		if (m_nFT232HDeviceUse < 1)
		{
			// 쓰레드 강제 종료
			pThreadParams->bThreadStop = TRUE;
		}
		else
		{
			switch (dwRet)
			{
			    case WAIT_OBJECT_0:  // 해당 이벤트 발생 : 처리작업 실행 
			    {
				    // SE Image Data 스캔 허용 Flag 설정
				    pThreadParams->bScanDataReceive = m_pIntegrated->bScanDataReceive;

					// 2021.06.09
					// PHOTO SCAN MODE 에 따른 이미지 업데이트 딜레이
					// PHOTO3/4/6 스캔모드시 이미지 업데이트를 매번 할 경우, 컨트롤 및 화면 업데이트가 매우 느려짐.
					// 위의 현상을 제거하기 위해 이벤트 발생시 이미지 업데이트를 일정 횟수 간격으로 딜레이 업데이트 한다.
					nScanMode = m_pIntegrated->nScanMode;
					if (nScanMode == PHOTO4_SCAN_MODE)
					{
						// PHOTO SCAN MODE (4) : 1280x960 MIDDLE SPEED
						nReceiveCount++;
						if (nReceiveCount < 5)
						{
							break;
						}
					}
					else if (nScanMode == PHOTO6_SCAN_MODE)
					{
						// PHOTO SCAN MODE (6) : 2560x1920 LOW SPEED
						nReceiveCount++;
						if (nReceiveCount < 10)
						{
							break;
						}
					}
					else if (nScanMode == PHOTO3_SCAN_MODE)
					{
						// PHOTO SCAN MODE (3) : 1280x960 HIGH SPEED
						nReceiveCount++;
						if (nReceiveCount < 3)
						{
							break;
						}
					}
					nReceiveCount = 0;

				    // SE Image Data : 수신된 명령어 데이터 처리(실행) 하기
				    AfxSEScanDataImageProcess(pThreadParams);
			    }
			    case WAIT_TIMEOUT:   // 이벤트 대기시간 경과 : Loop 순환
			    {
				    // 쓰레드 LOOP 순환
				    pThreadParams->bThreadDone = FALSE;
				    break;
			    }
			    case WAIT_FAILED:    // 이벤트 함수 오류 : 쓰레드 종료
			    {
				    // 쓰레드 종료 확인 및 쓰레드 종료
				    bLoop = FALSE;
				    break;
			    }
			}
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// 쓰레드 종료 (강제)결정 확인하기
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if (pThreadParams->bThreadStop == TRUE)
		{
			// 쓰레드 종료 확인 및 쓰레드 종료
			bLoop = FALSE;
		}
		else
		{
			// 쓰레드 종료 (강제)결정 확인하기
			if (m_pIntegrated->bScanThreadStop == TRUE)
			{
				// 쓰레드 종료 확인 및 쓰레드 종료
				bLoop = FALSE;
			}
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// 쓰레드 종료 확인
	pThreadParams->bThreadDone = TRUE;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	return RET_SUCCESS_OK;
}


__int64 m_nMaxSEScanDataSize  = 10000000000; // 100억Byte
__int64 m_nSendSEScanDataSize = 0;
/////////////////////////////////////////////////////////////////////////////////////////////////////
// SE Image Data : 수신 데이터 처리(실행) 및 이미지 데이터 생성, 처리하기
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSEScanDataImageProcess(LPSEIMAGEDATATHREADPARAMS pThreadParams)
{
	if (pThreadParams == NULL) return RET_ERROR_SEM_THREAD_PARAMS;               // SE Image Data 쓰레드 파라메터
	if (pThreadParams->hFT232Handle == NULL) return RET_ERROR_FT232H_SEM_HANDLE; // SE Image Data 장치 핸들

	int   n  = 0;
	BYTE  bt = 0;
	//MSG   msg;

	DWORD dwBytesRead = 0;
	DWORD dwRXBytes   = 0;
	DWORD dwTXBytes   = 0;
	DWORD dwEvent     = 0;
	DWORD dwRXCount   = 0;

	FT_STATUS ftStatus = 0;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// SE Image Data 스캔을 종료할 경우
	// 수신 버퍼에 있는 잔류 데이터를 읽은 후, 종료한다.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (pThreadParams->bScanDataReceive == FALSE || pThreadParams->bThreadStop == TRUE)
	{
		// CAPTURE STOP

		dwBytesRead = 0;
		dwRXBytes   = 0;
		dwTXBytes   = 0;
		dwEvent     = 0;

		BOOL bStopLoop = FALSE;

		while (bStopLoop == FALSE)
		{
			// SE Image Data Read and Process...
			AfxFT232HGetStatus(pThreadParams->nFT232HIndex, &dwRXBytes, &dwTXBytes, &dwEvent);

			// 받은 데이터 확인
			if (dwRXBytes < 1)
			{
				//return RET_SUCCESS_OK;
				bStopLoop = TRUE;
				continue; // LOOP 종료
			}

			// 수신된 자료가 모두 처리될 때 까지 작업한다
			while (dwRXBytes > 0)
			{
				// 남은 자료갯수 확인
				if (dwRXBytes < SCAN_IMAGE_PACKET_SIZE)
				{
					// 설정한 패킷 크기 보다 작은 경우
					dwRXCount = dwRXBytes;
				}
				else
				{
					// 설정한 패킷 크기 보다 같거나 큰 경우 
					dwRXCount = SCAN_IMAGE_PACKET_SIZE;
				}

				// Read Buffer Clear
				memset(pThreadParams->szFTReadBuf, 0x00, sizeof(pThreadParams->szFTReadBuf));

				// USB Data Read
				ftStatus = AfxFT232HRead(pThreadParams->nFT232HIndex, pThreadParams->szFTReadBuf, dwRXCount, &dwBytesRead);
				if (ftStatus != FT_OK)
				{
					// 쓰레드를 (강제)종료한다...
					//pThreadParams->bThreadStop = TRUE;
					return RET_ERROR_FT232H_SBR_READ;
				}

				// 읽은 자료 갯수 만큼 남은 자료 갯수를 차감한다
				dwRXBytes -= dwBytesRead;
			}
		}

		// 쓰레드 강제 종료...
		if (m_pIntegrated->bScanThreadStop == TRUE)
		{
			// 수신된 자료를 모두 처리 하였다면
			// 쓰레드를 (강제)종료한다...
			pThreadParams->bThreadStop = TRUE;
		}

		return RET_SUCCESS_OK;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	dwBytesRead = 0;
	dwRXBytes   = 0;
	dwTXBytes   = 0;
	dwEvent     = 0;
	n = 0;

	// SE Image Data Read and Process...
	AfxFT232HGetStatus(pThreadParams->nFT232HIndex, &dwRXBytes, &dwTXBytes, &dwEvent);

	// 받은 데이터 확인
	if (dwRXBytes < 1)
	{
		return RET_SUCCESS_OK;
	}

	// 수신된 자료가 모두 처리될 때 까지 작업한다
	while (dwRXBytes > 0)
	{
		// 2020.05.01
		// 최대 수신 버퍼 크기 조정

		// 남은 자료갯수 확인
		if (dwRXBytes < SCAN_IMAGE_PACKET_SIZE)
		{
			// 설정한 패킷 크기 보다 작은 경우
			dwRXCount = dwRXBytes;
		}
		else
		{
			// 설정한 패킷 크기 보다 같거나 큰 경우 
			dwRXCount = SCAN_IMAGE_PACKET_SIZE;
		}

		// Read Buffer Clear
		memset(pThreadParams->szFTReadBuf, 0x00, SCAN_IMAGE_PACKET_SIZE);

		// USB Data Read
		ftStatus = AfxFT232HRead(pThreadParams->nFT232HIndex, pThreadParams->szFTReadBuf, dwRXCount, &dwBytesRead);
		if (ftStatus != FT_OK)
		{
			//continue;

			// 2020.05.12
			// 쓰레드 계속 사용한다...
			pThreadParams->bThreadStop = FALSE;
			return RET_SUCCESS_OK;
		}
		if (dwBytesRead < 1)
		{
			//continue;

			// 2020.05.12
			// 쓰레드 계속 사용한다...
			pThreadParams->bThreadStop = FALSE;
			return RET_SUCCESS_OK;
		}

		///////////////////////////////////////////////////////////////////////////////////////
		// AUTO CONTROL MODE EXECUTE CHECK?
		///////////////////////////////////////////////////////////////////////////////////////

		// SE SCAN DATA CLIENT 전송 ( NORMAL MODE )
		if (m_nSEScanDataAutoModeExecute == SE_SCAN_DATA_NORMAL_EXECUTE)
		{
			///////////////////////////////////////////////////////////////////////////////////////
			// 수신된 SCAN IMAGE DATA 클라이언트 전송 메시지를 보낸다.
			///////////////////////////////////////////////////////////////////////////////////////
			if (m_hOwnerWnd != NULL)
			{
				// 2020.05.04
				// SE SCAN IMAGE DATA 전송 메시지 보내기 (카운트 DATA)
				SendMessage(m_hOwnerWnd, UM_SEM_SE_SCAN_IMAGE_DATA, dwBytesRead, (LPARAM)pThreadParams->szFTReadBuf);
			}
		}
		// SE SCAN DATA 를 이용한 AUTO FOCUS EXECUTE
		else if (m_nSEScanDataAutoModeExecute == SE_SCAN_DATA_AUTO_FOCUS_EXECUTE)
		{
			///////////////////////////////////////////////////////////////////////////////////////
			// 수신된 SCAN IMAGE DATA 분석을 위해 Owner 윈도우에 전송 메시지를 보낸다.
			///////////////////////////////////////////////////////////////////////////////////////
			if (m_hOwnerWnd != NULL)
			{
				// 2020.05.04
				// SE SCAN IMAGE DATA 전송 메시지 보내기 (카운트 DATA)
				SendMessage(m_hOwnerWnd, UM_SEM_SE_SCAN_IMAGE_DATA_AUTO_FOCUS, dwBytesRead, (LPARAM)pThreadParams->szFTReadBuf);
			}
		}
		// SE SCAN DATA 를 이용한 AUTO CONTRAST EXECUTE
		else if (m_nSEScanDataAutoModeExecute == SE_SCAN_DATA_AUTO_CONTRAST_EXECUTE)
		{
			///////////////////////////////////////////////////////////////////////////////////////
			// 수신된 SCAN IMAGE DATA 분석을 위해 Owner 윈도우에 전송 메시지를 보낸다.
			///////////////////////////////////////////////////////////////////////////////////////
			if (m_hOwnerWnd != NULL)
			{
				// 2020.05.04
				// SE SCAN IMAGE DATA 전송 메시지 보내기 (카운트 DATA)
				SendMessage(m_hOwnerWnd, UM_SEM_SE_SCAN_IMAGE_DATA_AUTO_CONTRAST, dwBytesRead, (LPARAM)pThreadParams->szFTReadBuf);
			}
		}
		// SE SCAN DATA 를 이용한 AUTO BRIGHTNESS EXECUTE
		else if (m_nSEScanDataAutoModeExecute == SE_SCAN_DATA_AUTO_BRIGHTNESS_EXECUTE)
		{
			///////////////////////////////////////////////////////////////////////////////////////
			// 수신된 SCAN IMAGE DATA 분석을 위해 Owner 윈도우에 전송 메시지를 보낸다.
			///////////////////////////////////////////////////////////////////////////////////////
			if (m_hOwnerWnd != NULL)
			{
				// 2020.05.04
				// SE SCAN IMAGE DATA 전송 메시지 보내기 (카운트 DATA)
				SendMessage(m_hOwnerWnd, UM_SEM_SE_SCAN_IMAGE_DATA_AUTO_BRIGHTNESS, dwBytesRead, (LPARAM)pThreadParams->szFTReadBuf);
			}
		}
		// SE SCAN DATA 를 이용한 AUTO CONTRAST+BRIGHTNESS EXECUTE
		else if (m_nSEScanDataAutoModeExecute == SE_SCAN_DATA_AUTO_CONTRAST_BRIGHT_EXECUTE)
		{
			///////////////////////////////////////////////////////////////////////////////////////
			// 수신된 SCAN IMAGE DATA 분석을 위해 Owner 윈도우에 전송 메시지를 보낸다.
			///////////////////////////////////////////////////////////////////////////////////////
			if (m_hOwnerWnd != NULL)
			{
				// 2020.05.04
				// SE SCAN IMAGE DATA 전송 메시지 보내기 (카운트 DATA)
				SendMessage(m_hOwnerWnd, UM_SEM_SE_SCAN_IMAGE_DATA_AUTO_CONT_BRIG, dwBytesRead, (LPARAM)pThreadParams->szFTReadBuf);
			}
		}
		// SE SCAN DATA 를 이용한 AUTO GUN ALIGNMENT EXECUTE
		else if (m_nSEScanDataAutoModeExecute == SE_SCAN_DATA_AUTO_GUN_ALIGN_EXECUTE)
		{
			///////////////////////////////////////////////////////////////////////////////////////
			// 수신된 SCAN IMAGE DATA 분석을 위해 Owner 윈도우에 전송 메시지를 보낸다.
			///////////////////////////////////////////////////////////////////////////////////////
			if (m_hOwnerWnd != NULL)
			{
				// 2020.05.04
				// SE SCAN IMAGE DATA 전송 메시지 보내기 (카운트 DATA)
				SendMessage(m_hOwnerWnd, UM_SEM_SE_SCAN_IMAGE_DATA_AUTO_GUN_ALIGN, dwBytesRead, (LPARAM)pThreadParams->szFTReadBuf);
			}
		}


		// 읽은 자료 갯수 만큼 남은 자료 갯수를 차감한다
		dwRXBytes -= dwBytesRead;

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	} // 수신된 자료가 모두 처리될 때 까지 작업한다 while()문 처리

	// 쓰레드 계속 사용한다...
	pThreadParams->bThreadStop = FALSE;

	return RET_SUCCESS_OK;

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// BSE-Image Device Command Control...
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////
// BSE Control : BSE Image Device Initilized (BSE 시스템 초기화)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxBseImageInitilized()
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// BSE Board가 연결 되지 않은 경우
	if (m_pIntegrated->bBseActiveFlag != TRUE) return RET_ERROR_FT232H_BSE_CONNECT;

	// BSE Offset AD5724 초기화

	// Power Control Register : Bse Command 전송 -> DAC0, DAC1, DAC2, DAC3 => Normal Mode
	AfxFT232HPortSendCommand(IDX_FT232H_BSE_IMAGE_DEVICE, bWR_AD5724, 0x10000F);
	// Output Range Select Register : Bse Command 전송 -> DAC A, +-10V
	AfxFT232HPortSendCommand(IDX_FT232H_BSE_IMAGE_DEVICE, bWR_AD5724, 0x080004);
	AfxFT232HPortSendCommand(IDX_FT232H_BSE_IMAGE_DEVICE, bWR_AD5724, 0x090004);
	AfxFT232HPortSendCommand(IDX_FT232H_BSE_IMAGE_DEVICE, bWR_AD5724, 0x0A0004);
	AfxFT232HPortSendCommand(IDX_FT232H_BSE_IMAGE_DEVICE, bWR_AD5724, 0x0B0004);

	return RET_SUCCESS_OK;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// SEM System Control...
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////
// System Control : SEM System Initilized (시스템 초기화, USB 장치 연결시 1번만 실행한다)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSEMSystemInitilize(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	//==============================================================================================
	// HV POWER ON/OFF FLAG : OFF 설정
	//==============================================================================================
	m_pIntegrated->bGunHVPowerOnFlag      = FALSE;                  // GUN HV Power On Flag
	m_pIntegrated->bFilamentPowerOnFlag   = FALSE;                  // Filament HV Power On Flag
	m_pIntegrated->bBiasPowerOnFlag       = FALSE;                  // Bias HV Power On Flag
	m_pIntegrated->bPMTPowerOnFlag        = FALSE;                  // PMT HV Power On Flag
	m_pIntegrated->bDETPowerOnFlag        = FALSE;                  // Detector HV Power On Flag
	m_pIntegrated->bSM2500PowerOnFlag     = FALSE;                  // Hitachi SM-2500 HV Power On Flag
	m_pIntegrated->bContrastOnFlag        = FALSE;                  // HV 설정시 Contrast 처음 실행 Flag
	m_pIntegrated->bScanRotationOnFlag    = FALSE;                  // HV 설정시 Scan Rotation 처음 실행 Flag
	m_pIntegrated->bScreenModeOnFlag      = FALSE;                  // HV 설정시 Screen Mode 처음 실행 Flag
	m_pIntegrated->bHVUpEndProcessFlag    = FALSE;                  // HV ALL 실행시 Up   Ending 처음 실행 Flag
	m_pIntegrated->bHVDownEndProcessFlag  = FALSE;                  // HV ALL 실행시 Down Ending 처음 실행 Flag
	m_pIntegrated->nHVStandbyProcess      = 0;                      // HV Standby Mode Up/Down Process Status : 1->Standby, 0->Normal
	m_pIntegrated->nGunHVUpDownProcess    = 0;                      // Gun HV   Up/Down Process Status : 10->Start, 20->Process, 99->End
	m_pIntegrated->nFilamentUpDownProcess = 0;                      // Filament Up/Down Process Status : 10->Start, 20->Process, 99->End
	m_pIntegrated->nBiasUpDownProcess     = 0;                      // Bias     Up/Down Process Status : 10->Start, 20->Process, 99->End
	m_pIntegrated->bHVStartProcessFlag    = FALSE;                  // HV Start Process Execute Flag
	m_pIntegrated->bHVAllStartProcessFlag = FALSE;                  // HV All Start Process Execute Flag
	m_pIntegrated->bHVAllStopProcessFlag  = FALSE;                  // HV All Stop  Process Execute Flag
	//==============================================================================================
	m_pIntegrated->nMagRelayOldNo         = 9;                      // Mag Relay No : 0 ~ 4, 배율 초기값을 실행 시키기 위해 Old Relay NO를 9로 설정
	m_pIntegrated->wMagRelayNumberOld     = 9;                      // Mag Relay No : 0 ~ 4, 배율 초기값을 실행 시키기 위해 Old Relay NO를 9로 설정
	//==============================================================================================
	m_pIntegrated->nZoomXMaxValue[0]      = m_nZoomXMaxValue[0];
	m_pIntegrated->nZoomXMaxValue[1]      = m_nZoomXMaxValue[1];
	m_pIntegrated->nZoomXMaxValue[2]      = m_nZoomXMaxValue[2];
	m_pIntegrated->nZoomXMaxValue[3]      = m_nZoomXMaxValue[3];
	m_pIntegrated->nZoomXMaxValue[4]      = m_nZoomXMaxValue[4];
	m_pIntegrated->nZoomYMaxValue[0]      = m_nZoomYMaxValue[0];
	m_pIntegrated->nZoomYMaxValue[1]      = m_nZoomYMaxValue[1];
	m_pIntegrated->nZoomYMaxValue[2]      = m_nZoomYMaxValue[2];
	m_pIntegrated->nZoomYMaxValue[3]      = m_nZoomYMaxValue[3];
	m_pIntegrated->nZoomYMaxValue[4]      = m_nZoomYMaxValue[4];
	//==============================================================================================
	m_pIntegrated->bWDHVCompensationFlag  = TRUE;                   // GUN HV에 따른 배율(Zoom) 보정은 필수 선택 사항이다
	m_pIntegrated->bWDScaleAdjustFlag     = TRUE;                   // WD    에 따른 배율(Zoom) 보정은 필수 선택 사항이다
	//==============================================================================================
	m_pIntegrated->nOLCompensation        = OL_IMAGE_ZOOM_CHANGE;   // WD에 따른 배율(Zoom) 보정 방식
	//==============================================================================================

	//==============================================================================================
	//==============================================================================================
	//==============================================================================================

	// CL 모델 선택 : 작업 필요함
	double dAmp = m_pIntegrated->dSemModelAmp; // kohm
	double dRef = m_pIntegrated->dSemModelRef; // ohm
	//==================================================================
	// CL1, CL2값 보관
	//==================================================================
	for (int n = 0; n < MAX_SM300_SM200_CL12_ITEM; n++)
	{
		m_nDA_CL1[n] = (int)m_pIntegrated->wCL1List[n];
		m_nDA_CL2[n] = (int)m_pIntegrated->wCL2List[n];
	}
	//==================================================================

	//==================================================================
	// GUN VALVE CLOSE
	//==================================================================
	AfxScanBridgeGunValveClose();
	//AfxSystemWaitTime(100);
	Sleep(100);
	//==================================================================

	//==================================================================
	// SEM SPELLMAN HV DISABLED
	//==================================================================
	// SpellMan GUN HV OFF
	AfxScanBridgeSpellmanGunHVOff();
	//AfxSystemWaitTime(100);
	Sleep(100);
	// SpellMan PMT OFF
	AfxIntegratedSpellmanPMTHVOff();
	//AfxSystemWaitTime(100);
	Sleep(100);
	// SpellMan Scintillator OFF
	AfxIntegratedSpellmanScintilatorHVOff();
	//AfxSystemWaitTime(100);
	Sleep(100);
	// SpellMan Collector OFF
	AfxScanBridgeCollectorOff();
	//AfxSystemWaitTime(100);
	Sleep(100);
	//==================================================================

	//==================================================================
	// SE SCAN IMAGE CAPTURE OFF
	//==================================================================
	AfxIntegratedScanImageDataCaptureStop();
	//==================================================================

	//------------------------------------------------------------------
	// SEM MODEL에 따른 CL값 초기화 (변수 초기화)
	//------------------------------------------------------------------
	// 2019.11.01
	//AfxSemModelCLInitialize(m_pIntegrated->nSemModel, dAmp, dRef);
	//------------------------------------------------------------------

	// Photo Mode Mag 초기값 설정
	memset(m_pIntegrated->nPhotoImageMag, 0x00, sizeof(int) * MAX_PHOTO_MAG_COUNT);
	m_pIntegrated->nPhotoImageNum = 10;
	// Full Photo Mode 초기값 설정
	memset(m_pIntegrated->nFullPhotoImageMag, 0x00, sizeof(int) * MAX_PHOTO_MAG_COUNT);
	m_pIntegrated->nFullPhotoImageNum = 10; 

	//------------------------------------------------------------------
	// BSE 시스템 초기화
	//------------------------------------------------------------------
	AfxBseImageInitilized();
	//------------------------------------------------------------------

	//------------------------------------------------------------------
	// Track Ball 초기화
	//------------------------------------------------------------------
	m_pIntegrated->nXYMovingState    = 0;
	m_pIntegrated->nTrackButtonState = TB_MOTOR_BUTTON;
	//------------------------------------------------------------------

	//------------------------------------------------------------------
	// GUN HV Ratio 계산값
	//------------------------------------------------------------------
	double dMaxGunHV = m_nGunHVTable[0];                           // MAX GUN HV VOLTAGE : m_nGunHVTable[0];
	double dGunHV    = m_nGunHVTable[m_pIntegrated->nGunHVIndex];  // Gun HV Voltage
	double dRatio    = sqrt(dGunHV / dMaxGunHV);                   // Gun HV Voltage / MAX GUN HV Voltage -> 비율
	// Emission current[µA] Setting
	WORD   wECVal    = 0;

	// Emission current[µA] 계산
	m_pIntegrated->dHVRatio = dRatio;
	wECVal = (WORD)((double)(4095 * m_pIntegrated->dHVRatio));
	wECVal /= 2;
	// Emission current[µA] 실행
	AfxIntegratedSetGunHVECValue(wECVal);

	// GUN HV 배율 비율 계산
	m_pIntegrated->dMagHVRatio = sqrt(dGunHV / dMaxGunHV) / DEFAULT_MAG_HV_RATIO;
	// 2020.06.03
	// 사용자 MAG HV RATIO : STAGE 수평 옵션을 임시로 사용한다.
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_STAGE_HORZ_ALIGN] == 1)
	{
		// GUN HV : 20KV
		if (m_nGunHVTable[m_pIntegrated->nGunHVIndex] == 20000)
		{
			m_pIntegrated->dMagHVRatio = sqrt(dGunHV / dMaxGunHV) / DEFAULT_MAG_HV_RATIO;
		}
		else
		{
			// 사용자 설정 배율 HV RATIO 보정값 설정
			m_pIntegrated->dMagHVRatio = m_dOptionMagHVRatio[m_pIntegrated->nGunHVIndex]; //sqrt(dGunHV / dMaxGunHV) / m_dOptionMagHVRatio[m_pIntegrated->nGunHVIndex];// OPTION_MAG_HV_RATIO;
		}
	}
	//------------------------------------------------------------------

	// 변수 초기화
	m_pIntegrated->nXYPosCount  = 0;
	m_pIntegrated->nCurRDeg     = 0;
	m_pIntegrated->nSemVacState = POWER_OFF_STATE;

	//------------------------------------------------------------------
	// Lens Coil에 흐르는 전류 최소화 ( USB DEVICE 실행 )
	//------------------------------------------------------------------
	AfxIntegratedLensCoilCurrentMinimum();

	//==================================================================
	// SCAN 신호 초기화 ( 신호 OFF )
	//==================================================================
	AfxIntegratedResetScanGeneration();

	// Scan Mode 설정
	m_pIntegrated->nOldSlowScanMode = m_pIntegrated->nHalfSlow1Scan;

	//------------------------------------------------------------------
	// Filament ( 변수초기화 )
	//------------------------------------------------------------------
	m_pIntegrated->nFilamentOldValue = m_pIntegrated->nFilamentValue;
	AfxScanBridgeSetFilamentValue(m_pIntegrated->nFilamentValue);

	//------------------------------------------------------------------
	// Bias ( 변수초기화)
	//------------------------------------------------------------------
	m_pIntegrated->nBiasOldValue = m_pIntegrated->nBiasValue;
	AfxScanBridgeSetBiasValue(m_pIntegrated->nBiasValue);

	//------------------------------------------------------------------
	// Contrast
	//--------------------------------------------
	m_pIntegrated->nContrastOldValue = m_pIntegrated->nContrastValue;

	//------------------------------------------------------------------
	// Bright
	//------------------------------------------------------------------
	m_pIntegrated->nBrightOldValue = m_pIntegrated->nBrightValue;

	//------------------------------------------------------------------
	// Stig X,Y
	//------------------------------------------------------------------
	m_pIntegrated->nStigXOldValue = m_pIntegrated->nStigXValue;
	m_pIntegrated->nStigYOldValue = m_pIntegrated->nStigYValue;

	//------------------------------------------------------------------
	// ImgShift X,Y : 클라이언트에서 초기화 설정 한다 ( 2019.08.12 )
	//------------------------------------------------------------------
	m_pIntegrated->nISXOldValue = m_pIntegrated->nISXValue;
	m_pIntegrated->nISYOldValue = m_pIntegrated->nISYValue;
	//AfxIntegratedSetImageShiftX();
	//AfxIntegratedSetImageShiftY();

	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------

	// WFM Line
	m_pIntegrated->nWFMLineNum = 240;
	// Main Scrollbar Update Enable Falg
	m_pIntegrated->bMainScrollBarUpdateEnable = TRUE;

	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------

	// divide zero 방지
	if (m_pIntegrated->dAxisPulsePerUnit[0] == 0)  m_pIntegrated->dAxisPulsePerUnit[0] = 20000.0;
	if (m_pIntegrated->dAxisPulsePerUnit[1] == 0)  m_pIntegrated->dAxisPulsePerUnit[1] = 20000.0;
	if (m_pIntegrated->dAxisPulsePerUnit[2] == 0)  m_pIntegrated->dAxisPulsePerUnit[2] = 4000.0;
	if (m_pIntegrated->dAxisPulsePerUnit[3] == 0)  m_pIntegrated->dAxisPulsePerUnit[3] = 80000.0;
	if (m_pIntegrated->dAxisPulsePerUnit[4] == 0)  m_pIntegrated->dAxisPulsePerUnit[4] = 4000.0;

	if (m_pIntegrated->dAxisMaxWidthMM[0] == 0)  m_pIntegrated->dAxisMaxWidthMM[0] = 20.0;
	if (m_pIntegrated->dAxisMaxWidthMM[1] == 0)  m_pIntegrated->dAxisMaxWidthMM[1] = 20.0;
	if (m_pIntegrated->dAxisMaxWidthMM[2] == 0)  m_pIntegrated->dAxisMaxWidthMM[2] = 20.0;
	if (m_pIntegrated->dAxisMaxWidthMM[3] == 0)  m_pIntegrated->dAxisMaxWidthMM[3] = 20.0;
	if (m_pIntegrated->dAxisMaxWidthMM[4] == 0)  m_pIntegrated->dAxisMaxWidthMM[4] = 20.0;

	//--------------------------------------------------------------
	// 실제 X, Y Stage 폭에 비례한 m_pBitmap_XYR 크기 결정
	//--------------------------------------------------------------
	// AxisMaxWidthMM[] 값은 초기의 ini File에 저장된 값으로 표시함.
	// 즉, Motor Board의 EEProm에 저장된 값과 같아야 됨.
	//--------------------------------------------------------------
	// 시료의 Bmp 위치
	m_pIntegrated->nXStagePos = 0;// 이전프로그램 -> m_pBitmap_XYR->Width / 2;
	m_pIntegrated->nYStagePos = 0;// 이전프로그램 -> m_pBitmap_XYR->Height / 2;

	// 시료의 Diameter
	m_pIntegrated->nSDpix = 0; //이전 프로그램 ->  m_pBitmap_XYR->Height * SDmm / AxisMaxWidthMM[1];

	// 시료의 Radius
	m_pIntegrated->nSRpix = m_pIntegrated->nSDpix / 2;

	//--------------------------------------------------------------
	// 시료 위치
	//--------------------------------------------------------------

	// 시료 Rotation Point 그리기
	m_pIntegrated->nRotAngLeft   = m_pIntegrated->nXStagePos - 6;
	m_pIntegrated->nRotAngRight  = m_pIntegrated->nXStagePos + 6;
	m_pIntegrated->nRotAngTop    = m_pIntegrated->nYStagePos - m_pIntegrated->nSRpix + 12 + 2;
	m_pIntegrated->nRotAngBottom = m_pIntegrated->nYStagePos - m_pIntegrated->nSRpix + 2;

	m_pIntegrated->nXBeamCenterPosPix = 0; // 이전프로그램 -> m_pBitmap_XYR->Width / 2;
	m_pIntegrated->nYBeamCenterPosPix = 0; // 이전프로그램 -> m_pBitmap_XYR->Height / 2;

	//--------------------------------------------------------------
	//--------------------------------------------------------------
	//--------------------------------------------------------------

	//--------------------------------------------------------------------------
	// Scan Mode 설정
	//--------------------------------------------------------------------------
    // Freeze 설정
    m_pIntegrated->bFreezeModeFlag = FALSE; // FreezeButtonFlag = FALSE;


	//--------------------------------------------------------------------------
	// SEM ON 이 눌려질 때, SEM의 모든 초기과정을 설정하고,
	// 전에 종료되었던 ScreenMode 및 Scan 모드로 복귀하고 영상을 관찰한다.
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	// 전에 종료되었던 ScreenMode 및 Scan 모드에 무관하게
	// 무조건 Normal Mode로 시작
	//--------------------------------------------------------------------------
	m_pIntegrated->nScreenMode = NORMAL_SCREEN;

	//-------------------------------------------------------
	// SCAN ROTATION 각도 초기 설정
	//-------------------------------------------------------
	// SRotationValue 값은 각도 단위 값이며, 0~3599(3600) 범위이다(분해능을 높이기 위해 본래 값에 x10을 사용하였다)
	m_pIntegrated->nSRotationValue = 0;
	AfxScanBridgeSetScanRotation(m_pIntegrated->nSRotationValue);

	//-------------------------------------------------------
	// 직교도...( 변수초기화 )
	//-------------------------------------------------------
	if (m_pIntegrated->nOrthogonal < 0   ) m_pIntegrated->nOrthogonal = 0;
	if (m_pIntegrated->nOrthogonal > 4095) m_pIntegrated->nOrthogonal = 4095;
	AfxScanBridgeSetOrthogonal(m_pIntegrated->nOrthogonal); // Orthogonal 설정 (m_pIntegrated->nARAngle[0]);
	AfxScanBridgeSetOrthogonal();                           // Orthogonal 실행 

	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	// 이전 프로그램 아래의 처리를 타이머를 이용하여 실행하였으나
	// 아래의 프로그램은 쓰레드로 처리하기 때문에 마지막 문장에서
	// 처리할 기능들을 실행한다. 타이머의 경우 Function의 루틴이
	// 종료 된 후, 이벤트가 발생하므로 쓰레드는 타이머와 다르게 처리한다.
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	// Scan Bridge Device 상태 정보 읽기 쓰레드 생성 및 실행
	//------------------------------------------------------------------------
	// Scan Bridge 상태정보 읽기 쓰레드 생성하기
	AfxCreateScanBridgeThread();
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	// SEM SE Scan Image Data 쓰레드 생성 및 실행
	//------------------------------------------------------------------------
	// SE Image Processing Thread 생성 및 시작 (SEM Image Scan 쓰레드 생성)
	AfxCreateSEImageDataThread();
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------

	//--------------------------------------------
	// X, Y, Z, R, T Stage ( Read )
	//--------------------------------------------
	// CNC 명령어 전송: 각 축에 설정된 설정값 및 상태정보를 읽어온다. 쓰레드를 생성한다
	m_pIntegrated->nCncSendTimerCount = 0;

	//==================================================================
	// Scan Bridge -> Vacuum State ( Read ) 실행
	//==================================================================
	//AfxScanBridgeGetVaccumState();
	//AfxSystemWaitTime(100);
	//==================================================================


	return RET_SUCCESS_OK;
}
int AfxSEMSystemInitilizeHVOff(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// HV Power On Flag
	m_pIntegrated->bGunHVPowerOnFlag      = FALSE;     // GUN HV Power On Flag
	m_pIntegrated->bFilamentPowerOnFlag   = FALSE;     // Filament HV Power On Flag
	m_pIntegrated->bBiasPowerOnFlag       = FALSE;     // Bias HV Power On Flag
	m_pIntegrated->bPMTPowerOnFlag        = FALSE;     // PMT HV Power On Flag
	m_pIntegrated->bDETPowerOnFlag        = FALSE;     // Detector HV Power On Flag
	m_pIntegrated->bSM2500PowerOnFlag     = FALSE;     // Hitachi SM-2500 HV Power On Flag
	m_pIntegrated->bContrastOnFlag        = FALSE;     // HV 설정시 Contrast 처음 실행 Flag
	m_pIntegrated->bScanRotationOnFlag    = FALSE;     // HV 설정시 Scan Rotation 처음 실행 Flag
	m_pIntegrated->bScreenModeOnFlag      = FALSE;     // HV 설정시 Screen Mode 처음 실행 Flag
	m_pIntegrated->bHVUpEndProcessFlag    = FALSE;     // HV ALL 실행시 Up   Ending 처음 실행 Flag
	m_pIntegrated->bHVDownEndProcessFlag  = FALSE;     // HV ALL 실행시 Down Ending 처음 실행 Flag
	m_pIntegrated->nHVStandbyProcess      = 0;         // HV Standby Mode Up/Down Process Status : 1->Standby, 0->Normal
	m_pIntegrated->nGunHVUpDownProcess    = 0;         // Gun HV   Up/Down Process Status : 10->Start, 20->Process, 99->End
	m_pIntegrated->nFilamentUpDownProcess = 0;         // Filament Up/Down Process Status : 10->Start, 20->Process, 99->End
	m_pIntegrated->nBiasUpDownProcess     = 0;         // Bias     Up/Down Process Status : 10->Start, 20->Process, 99->End
	m_pIntegrated->bHVStartProcessFlag    = FALSE;     // HV Start Process Execute Flag
	m_pIntegrated->bHVAllStartProcessFlag = FALSE;     // HV All Start Process Execute Flag
	m_pIntegrated->bHVAllStopProcessFlag  = FALSE;     // HV All Stop  Process Execute Flag

	//==================================================================
	// GUN VALVE CLOSE
	//==================================================================
	AfxScanBridgeGunValveClose();
	//AfxSystemWaitTime(100);
	//==================================================================

	//==================================================================
	// SEM SPELLMAN HV DISABLED
	//==================================================================
	// SpellMan GUN HV OFF
	AfxScanBridgeSpellmanGunHVOff();
	//AfxSystemWaitTime(100);
	// SpellMan PMT OFF
	AfxIntegratedSpellmanPMTHVOff();
	//AfxSystemWaitTime(100);
	// SpellMan Scintillator OFF
	AfxIntegratedSpellmanScintilatorHVOff();
	//AfxSystemWaitTime(100);
	// SpellMan Collector OFF
	AfxScanBridgeCollectorOff();
	//AfxSystemWaitTime(100);
	//==================================================================

	//==================================================================
	// Scan Bridge -> Vacuum State ( Read ) 실행
	//==================================================================
	//AfxScanBridgeGetVaccumState();
	//AfxSystemWaitTime(100);
	//==================================================================

	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
	/*
	//------------------------------------------------------------------------
	// 이전 프로그램 아래의 처리를 타이머를 이용하여 실행하였으나
	// 아래의 프로그램은 쓰레드로 처리하기 때문에 마지막 문장에서
	// 처리할 기능들을 실행한다. 타이머의 경우 Function의 루틴이
	// 종료 된 후, 이벤트가 발생하므로 쓰레드는 타이머와 다르게 처리한다.
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	// Scan Bridge Device 상태 정보 읽기 쓰레드 생성 및 실행
	//------------------------------------------------------------------------
	// Scan Bridge 상태정보 읽기 쓰레드 생성하기
	AfxCreateScanBridgeThread();
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	// SEM SE Scan Image Data 쓰레드 생성 및 실행
	//------------------------------------------------------------------------
	// SE Image Processing Thread 생성 및 시작 (SEM Image Scan 쓰레드 생성)
	AfxCreateSEImageDataThread();
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------

	//--------------------------------------------
	// X, Y, Z, R, T Stage ( Read )
	//--------------------------------------------
	// CNC 명령어 전송: 각 축에 설정된 설정값 및 상태정보를 읽어온다. 쓰레드를 생성한다
	m_pIntegrated->nCncSendTimerCount = 0;
	*/

	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// System Control : SEM CL Model Initilized (CL MODEL 시스템 초기화)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSemModelCLInitialize(int nSemModel, double dAmp, double dRef)
{
	// SEM Model 초기화 및 사용 변수 초기화
	AfxIntegratedInitializeParameters(nSemModel);

	m_pIntegrated->dAmpRk = dAmp;
	m_pIntegrated->dRefR  = dRef;
	strcpy_s(m_pIntegrated->szUserText, "ModuleSci ");

	/*
	m_pIntegrated->nZoomXMaxValue[0]    = 4095;
	m_pIntegrated->nZoomYMaxValue[0]    = 4095;
	m_pIntegrated->nZoomXMaxValue[1]    = 4095;
	m_pIntegrated->nZoomYMaxValue[1]    = 4095;
	m_pIntegrated->nZoomXMaxValue[2]    = 4095;
	m_pIntegrated->nZoomYMaxValue[2]    = 4095;
	m_pIntegrated->nZoomXMaxValue[3]    = 4095;
	m_pIntegrated->nZoomYMaxValue[3]    = 4095;
	m_pIntegrated->nZoomXMaxValue[4]    = 4095;
	m_pIntegrated->nZoomYMaxValue[4]    = 4095;

	m_pIntegrated->nWDOLCoarse[0]       = 4095;
	m_pIntegrated->nWDOLCoarse[1]       = 4092;
	m_pIntegrated->nWDOLCoarse[2]       = 4087;
	m_pIntegrated->nWDOLCoarse[3]       = 4085;
	m_pIntegrated->nWDOLCoarse[4]       = 4080;
	*/

	if (m_pIntegrated->nWDMaxValue == 0) m_pIntegrated->nWDMaxValue = 50;

	AfxIntegratedSetWDOLSrotZoomingLinearize();

	m_pIntegrated->nXScanMoveLeft       = -654;
	m_pIntegrated->nXScanMoveRight      = 700;
	m_pIntegrated->nYScanMoveTop        = -538;
	m_pIntegrated->nYScanMoveBottom     = 404;

	m_pIntegrated->nDImagXResetPos      = 20;
	m_pIntegrated->nDImagYResetPos      = -40;

	m_pIntegrated->nDMXMoveLeft         = 1125;  // 1392;
	m_pIntegrated->nDMXMoveRight        = 3040;  // 3025;
	m_pIntegrated->nDMYMoveTop          = 1245;
	m_pIntegrated->nDMYMoveBottom       = 2864;

	m_pIntegrated->bFirstClearBitmap    = TRUE;
	m_pIntegrated->bFirstBMouseDown     = FALSE;
	m_pIntegrated->bMagMouseWheelActive = TRUE;
	m_pIntegrated->nMainScrollBarMode   = 0;

	m_pIntegrated->dCurZPos             = 15;

	//-----------------------------------------------------------------------
	// 대기 상태의 Menu 상태값 표시
	//-----------------------------------------------------------------------
	// 1) 프로그램 시작시, 과거에 설정되었던 값을 windows에 표시하고,
	// 2) 사용자가 설정하고 싶은 값으로 변경하고, Start Radio button을 누르면
	// 3) 현재 설정값으로, SEM 조정을 하고, Image 관찰을 시작한다.
	//-----------------------------------------------------------------------

	//-----------------------------------------------------------------------
	// Mag에 관련된 설정부
	//-----------------------------------------------------------------------
	m_pIntegrated->nWDZoomingRatio    = 1;
	m_pIntegrated->wMagRelayNumber    = 0;      // nMagRelayNo = 0;
	m_pIntegrated->wMagRelayNumberOld = 999;    // nMagRelayOldNo = 999;  // 같으면 초기진입시 Relay가 Off됨
	m_pIntegrated->bMainScrollBarUpdateEnable = FALSE;

	//-----------------------------------------------------------------------
	// GHV Setting...
	//-----------------------------------------------------------------------
	double dHVMax = (double)m_nGunHVTable[0];
	m_pIntegrated->nGunHVValue = m_nGunHVTable[m_pIntegrated->nGunHVIndex];
	// Emission current[µA] Setting
	WORD   wECVal = 0;
	// Emission current[µA] 계산
	m_pIntegrated->dHVRatio = sqrt((double)m_pIntegrated->nGunHVValue / dHVMax);
	wECVal = (WORD)((double)(4095 * m_pIntegrated->dHVRatio));
	wECVal /= 2;
	// Emission current[µA] 실행
	AfxIntegratedSetGunHVECValue(wECVal);

	m_pIntegrated->dMagHVRatio = sqrt((double)m_pIntegrated->nGunHVValue / dHVMax) / DEFAULT_MAG_HV_RATIO; //30000.0) / 0.8165;
	// 2020.06.03
	// 사용자 MAG HV RATIO : STAGE 수평 옵션을 임시로 사용한다.
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_STAGE_HORZ_ALIGN] == 1)
	{
		// GUN HV : 20KV
		if (m_nGunHVTable[m_pIntegrated->nGunHVIndex] == 20000)
		{
			m_pIntegrated->dMagHVRatio = sqrt((double)m_pIntegrated->nGunHVValue / dHVMax) / DEFAULT_MAG_HV_RATIO;
		}
		else
		{
			// 사용자 설정 배율 HV RATIO 보정값 설정
			m_pIntegrated->dMagHVRatio = m_dOptionMagHVRatio[m_pIntegrated->nGunHVIndex]; //sqrt((double)m_pIntegrated->nGunHVValue / dHVMax) / m_dOptionMagHVRatio[m_pIntegrated->nGunHVIndex];// OPTION_MAG_HV_RATIO;
		}
	}

	//-----------------------------------------------------------------------
	// SpotSize Setting... (변수 초기화)
	//-----------------------------------------------------------------------
	AfxIntegratedSetSpotSize();

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// System Control : SEM CL Model Initilized (CL MODEL 시스템 초기화)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSEMSystemThreadClose(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	BOOL bLoop = TRUE;

	////////////////////////////////////////////////////////////////////////////////////
	// 사용중인 쓰레드 종료
	////////////////////////////////////////////////////////////////////////////////////
	for (int n = 0; n < MAX_PUBLIC_THREAD; n++)
	{
		CWinThread *pThread = m_pPublicToolsThread[n];         // Public Tools 쓰레드 핸들
		LPPUBLICTOOLSPARAMS pParam = m_pPublicToolsParams[n];  // Array Public Tools 쓰레드 사용변수

		if (pThread == NULL) continue;
		if (pParam  == NULL) continue;

		// 쓰레드 종료
		pParam->bThreadStop = TRUE;
		bLoop = TRUE;

		// 쓰레드가 종료 될 때 까지 기다린다.
	    // 잠시 대기
		Sleep(100);
	}
	////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////////////
	// FOCUS DEGAUSSING 쓰레드 사용 중이면...
	////////////////////////////////////////////////////////////////////////////////////
	// 2021.06.15
	if (m_pFocusDegaussingThread != NULL)
	{
		// FOCUS DEGAUSSING 쓰레드 파라메터 중복 확인
		if (m_pFocusDegaussingThreadParams != NULL)
		{
			// FOCUS DEGAUSSING 쓰레드 종료 설정
			m_pFocusDegaussingThreadParams->bThreadStop = TRUE;

			bLoop = TRUE;

			// 쓰레드가 종료 될 때 까지 기다린다.
			// 잠시대기
			Sleep(100);

			// FOCUS DEGAUSSING 쓰레드에서 사용한 파라메터 삭제
			delete m_pFocusDegaussingThreadParams;
			m_pFocusDegaussingThreadParams = NULL;
		}
	}
	////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////////////
	// CNC STAGE 쓰레드 사용 중이면...
	////////////////////////////////////////////////////////////////////////////////////
	// 2021.05.31
	if (m_pCNCSendThread != NULL)
	{
		// SE Image Data 쓰레드 파라메터 중복 확인
		if (m_pCNCSendThreadParams != NULL)
		{
			// SE Image Data 쓰레드 종료 설정
			m_pCNCSendThreadParams->bThreadStop = TRUE;

			bLoop = TRUE;

			// 쓰레드가 종료 될 때 까지 기다린다.
			// 잠시대기
			Sleep(100);

			// CNC STAGE 쓰레드에서 사용한 파라메터 삭제
			delete m_pCNCSendThreadParams;
			m_pCNCSendThreadParams = NULL;
		}
	}
	////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////////////
	// SE Scan Image Data 쓰레드 사용 중이면...
	////////////////////////////////////////////////////////////////////////////////////
	if (m_pSEImageDataThread != NULL)
	{
		// SE Image Data 쓰레드 파라메터 중복 확인
		if (m_pSEImageDataThreadParams != NULL)
		{
			// SE Image Data 쓰레드 종료 설정
			m_pSEImageDataThreadParams->bThreadStop = TRUE;
			m_pIntegrated->bScanThreadStop = TRUE;

			bLoop = TRUE;

			// 쓰레드가 종료 될 때 까지 기다린다.
			// 잠시 대기
			Sleep(100);

			// SE Image Data 쓰레드에서 사용한 파라메터 삭제
			delete m_pSEImageDataThreadParams;
			m_pSEImageDataThreadParams = NULL;
		}
	}
	////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////////////
	// Scan Bridge 쓰레드 사용 중이면...
	////////////////////////////////////////////////////////////////////////////////////
	if (m_pScanBridgeThread != NULL)
	{
		// Scan Bridge 쓰레드 파라메터 중복 확인
		if (m_pScanBridgeThreadParams != NULL)
		{
			// Scan Bridge 쓰레드 종료
			m_pScanBridgeThreadParams->bThreadStop = TRUE;

			bLoop = TRUE;

			// 쓰레드가 종료 될 때 까지 기다린다.
			// 잠시 대기
			Sleep(100);

			// Scan Bridge 쓰레드에서 사용한 파라메터 삭제
			delete m_pScanBridgeThreadParams;
			m_pScanBridgeThreadParams = NULL;
		}
	}
	////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////


	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : SEM Gun HV Index 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMGunHvIndex(int nIndex, BOOL bReset)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 사용자가 선택한 GUN HV Index -> 현재 작업중인 GUN HV Index로 설정
	m_pIntegrated->nGunHVIndex = nIndex;

	//------------------------------------------------------------------
	// GUN HV Ratio 계산값
	//------------------------------------------------------------------
	double dMaxGunHV = m_nGunHVTable[0];                           // MAX GUN HV VOLTAGE : m_nGunHVTable[0];
	double dGunHV    = m_nGunHVTable[m_pIntegrated->nGunHVIndex];  // Gun HV Voltage
	double dRatio    = sqrt(dGunHV / dMaxGunHV);                   // Gun HV Voltage / MAX GUN HV Voltage -> 비율
	// Emission current[µA] Setting
	WORD   wECVal = 0;
	// Emission current[µA] 계산
	m_pIntegrated->dHVRatio = dRatio;
	wECVal = (WORD)((double)(4095 * m_pIntegrated->dHVRatio));
	wECVal /= 2;
	// Emission current[µA] 실행
	AfxIntegratedSetGunHVECValue(wECVal);
	// GUN HV 배율 비율 계산
	m_pIntegrated->dMagHVRatio = sqrt(dGunHV / dMaxGunHV) / DEFAULT_MAG_HV_RATIO;
	// 2020.06.03
	// 사용자 MAG HV RATIO : STAGE 수평 옵션을 임시로 사용한다.
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_STAGE_HORZ_ALIGN] == 1)
	{
		// GUN HV : 20KV
		if (m_nGunHVTable[m_pIntegrated->nGunHVIndex] == 20000)
		{
			m_pIntegrated->dMagHVRatio = sqrt(dGunHV / dMaxGunHV) / DEFAULT_MAG_HV_RATIO;
		}
		else
		{
			// 사용자 설정 배율 HV RATIO 보정값 설정
			m_pIntegrated->dMagHVRatio = m_dOptionMagHVRatio[m_pIntegrated->nGunHVIndex]; // sqrt(dGunHV / dMaxGunHV) / m_dOptionMagHVRatio[m_pIntegrated->nGunHVIndex];// OPTION_MAG_HV_RATIO;
		}
	}
	//------------------------------------------------------------------

	if (bReset == TRUE)
	{
		m_pIntegrated->bGunHVResetFlag = TRUE;    // GUN HV Reset Flag
		m_pIntegrated->nGunHVCurIndex  = -1;      // 사용자가 선택한 GUN HV 인덱스
		m_pIntegrated->nGunHVExeIndex  = -1;      // GUN HV 실행 인덱스
		m_pIntegrated->nGunHVValue     = 0;       // GUN HV 실행 인덱스에 해당하는 GUN HV 값
		m_pIntegrated->nGunHVCurValue  = 0;       // GUN HV 현재 설정값
		m_pIntegrated->nGunHVExeValue  = 0;       // GUN HV 현재 실행값
		m_pIntegrated->dGunHVCurVoltage   = 0.0;  // GUN HV 현재 설정된 Voltage
		m_pIntegrated->dGunHVUpVoltage    = 0.0;  // GUN HV 현재 설정된 Up Voltage
		m_pIntegrated->dGunHVDownVoltage  = 0.0;  // GUN HV 현재 설정된 Down Voltage
		m_pIntegrated->dGunHVStartVoltage = 0.0;  // GUN HV 현재 설정된 Start Voltage
		m_pIntegrated->dGunHVStopVoltage  = 0.0;  // GUN HV 현재 설정된 Stop  Voltage
		m_pIntegrated->dGunHVStepVoltage  = 0.0;  // GUN HV 현재 설정된 Step  Voltage
		m_pIntegrated->dGunHVMaxVoltage   = 0.0;  // GUN HV 현재 설정된 Max   Voltage
		m_pIntegrated->dGunHVMinVoltage   = 0.0;  // GUN HV 현재 설정된 Min   Voltage
		m_pIntegrated->dGunHVBackupVoltage= 0.0;  // GUN HV 현재 설정된 Voltage Backup
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get SEM Gun HV Voltage
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMGunHvIndex(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 현재 설정 및 샐행된 GUN HV Voltage Index 값
	return m_pIntegrated->nGunHVIndex;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get SEM Gun HV Voltage
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxGetSEMGunHvVoltage(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 현재 설정 및 샐행된 GUN HV Voltage 값
	return m_pIntegrated->dGunHVCurVoltage;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get SEM Gun HV Backup Current Voltage
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxGetSEMGunHvBackupVoltage(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 현재 설정 및 샐행된 GUN HV Backup Current Voltage 값
	return m_pIntegrated->dGunHVBackupVoltage;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : SEM Filament Voltage 설정 & Reset
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMFilamentValue(int nTarget, BOOL bReset)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 사용자가 선택한 Filament Voltage Position
	m_pIntegrated->nFilamentValue = nTarget;
	if (bReset == TRUE)
	{
		m_pIntegrated->bFilamentResetFlag = TRUE;     // Filament Reset Flag
		m_pIntegrated->nFilamentCurValue  = -1;       // Filament 현재 설정값
		m_pIntegrated->nFilamentExeValue  = -1;       // Filament 실행 설정값
		m_pIntegrated->nFilamentValue     = nTarget;  // 사용자가 선택한 Filament 설정값
		m_pIntegrated->dFilamentCurVoltage    = 0.0;  // Filament 현재 설정된 Voltage
		m_pIntegrated->dFilamentUpVoltage     = 0.0;  // Filament 현재 설정된 Up Voltage
		m_pIntegrated->dFilamentDownVoltage   = 0.0;  // Filament 현재 설정된 Down Voltage
		m_pIntegrated->dFilamentStartVoltage  = 0.0;  // Filament 현재 설정된 Start Voltage
		m_pIntegrated->dFilamentStopVoltage   = 0.0;  // Filament 현재 설정된 Stop  Voltage
		m_pIntegrated->dFilamentStepVoltage   = 0.0;  // Filament 현재 설정된 Step  Voltage
		m_pIntegrated->dFilamentMaxVoltage    = 0.0;  // Filament 현재 설정된 Max   Voltage
		m_pIntegrated->dFilamentMinVoltage    = 0.0;  // Filament 현재 설정된 Min   Voltage
		m_pIntegrated->dFilamentBackupVoltage = 0.0;  // Filament 현재 설정된 Voltage Backup
	}

	/*
	// 전송자료
	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));
	// Filament
	UsbDeviceDataInfo.nState = m_pIntegrated->nFilamentValue;

	if (m_hOwnerWnd != NULL)
	{
		// DEVICE MAIN SERVER
		// 현재 Filament Voltage Position (변경된 Filament Voltage 선택 값) 정보 메시지 보내기
	    SendMessage(m_hOwnerWnd, UM_USB_SBR_FILAMENT_DATA, NULL, (LPARAM)&UsbDeviceDataInfo);
	}
	*/

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get SEM Filament Voltage
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxGetSEMFilamentVoltage(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 현재 설정 및 샐행된 Filament Voltage 값
	return m_pIntegrated->dFilamentCurVoltage;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get SEM Gun HV Backup Current Voltage
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxGetSEMFilamentBackupVoltage(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 현재 설정 및 샐행된 Filament Backup Current Voltage 값
	return m_pIntegrated->dFilamentBackupVoltage;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get SEM Filament Start Voltage
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxGetSEMFilamentStartVoltage(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 현재 설정 및 샐행된 Filament Start Voltage 값
	return m_pIntegrated->dFilamentStartVoltage;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get SEM Filament Stop Voltage
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxGetSEMFilamentStopVoltage(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 현재 설정 및 샐행된 Filament Stop Voltage 값
	return m_pIntegrated->dFilamentStopVoltage;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : SEM Bias Voltage 설정 & Reset
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMBiasValue(int nTarget, BOOL bReset)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 사용자가 선택한 Bias Voltage Position
	m_pIntegrated->nBiasValue = nTarget;
	if (bReset == TRUE)
	{
		m_pIntegrated->bBiasResetFlag = TRUE;     // Bias Reset Flag
		m_pIntegrated->nBiasCurValue  = -1;       // Bias 현재 설정값
		m_pIntegrated->nBiasExeValue  = -1;       // Bias 실행 설정값
		m_pIntegrated->nBiasValue     = nTarget;  // 사용자가 선택한 Bias 설정값
		m_pIntegrated->dBiasCurVoltage    = 0.0;  // Bias 현재 설정된 Voltage
		m_pIntegrated->dBiasUpVoltage     = 0.0;  // Bias 현재 설정된 Up Voltage
		m_pIntegrated->dBiasDownVoltage   = 0.0;  // Bias 현재 설정된 Down Voltage
		m_pIntegrated->dBiasStartVoltage  = 0.0;  // Bias 현재 설정된 Start Voltage
		m_pIntegrated->dBiasStopVoltage   = 0.0;  // Bias 현재 설정된 Stop  Voltage
		m_pIntegrated->dBiasStepVoltage   = 0.0;  // Bias 현재 설정된 Step  Voltage
		m_pIntegrated->dBiasMaxVoltage    = 0.0;  // Bias 현재 설정된 Max   Voltage
		m_pIntegrated->dBiasMinVoltage    = 0.0;  // Bias 현재 설정된 Min   Voltage
		m_pIntegrated->dBiasBackupVoltage = 0.0;  // Bias 현재 설정된 Voltage Backup
	}

	/*
	// 전송자료
	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));
	// Bias
	UsbDeviceDataInfo.nState = m_pIntegrated->nBiasValue;

	if (m_hOwnerWnd != NULL)
	{
		// DEVICE MAIN SERVER
		// 현재 Bias Voltage Position (변경된 Bias Voltage 선택 값) 정보 메시지 보내기
	    SendMessage(m_hOwnerWnd, UM_USB_SBR_BIAS_DATA, NULL, (LPARAM)&UsbDeviceDataInfo);
    }
	*/

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get SEM Bias Voltage
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxGetSEMBiasVoltage(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 현재 설정 및 샐행된 Bias Voltage 값
	return m_pIntegrated->dBiasCurVoltage;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get SEM Bias Backup Current Voltage
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxGetSEMBiasBackupVoltage(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 현재 설정 및 샐행된 Bias Backup Current Voltage 값
	return m_pIntegrated->dBiasBackupVoltage;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get SEM Bias Start Voltage
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxGetSEMBiasStartVoltage(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 현재 설정 및 샐행된 Bias Start Voltage 값
	return m_pIntegrated->dBiasStartVoltage;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get SEM Bias Stop Voltage
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxGetSEMBiasStopVoltage(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 현재 설정 및 샐행된 Bias Stop Voltage 값
	return m_pIntegrated->dBiasStopVoltage;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : SEM Magnification 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMMagnificationIndex(int nIndex)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 사용자가 선택한 Magnification Index -> 현재 작업중인 Index로 설정
	m_pIntegrated->nMagStepIndex = nIndex;

	return RET_SUCCESS_OK;
}
int AfxGetSEMMagnificationIndex(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 사용자가 선택한 Magnification Index -> 현재 작업중인 Index로 설정
	return m_pIntegrated->nMagStepIndex;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : SEM OL WD 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMOLWDValue(int nOLWD)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 사용자가 선택한 OL_WD 값
	m_pIntegrated->nOLWD = nOLWD;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : SEM Focus Coarse 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMFocusCoarse(int nCoarse)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 사용자가 선택한 Focus-Coarse 값 -> 현재 작업중인 값으로 설정
	m_pIntegrated->nFocusCoarse = nCoarse;

	return RET_SUCCESS_OK;
}
int AfxGetSEMFocusCoarse(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Focus-Coarse 값
	return m_pIntegrated->nFocusCoarse;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : SEM Focus Fine 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMFocusFine(int nFine)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 사용자가 선택한 Focus-Fine 값 -> 현재 작업중인 값으로 설정
	m_pIntegrated->nFocusFine = nFine;

	return RET_SUCCESS_OK;
}
int AfxGetSEMFocusFine(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Focus-Fine 값
	return m_pIntegrated->nFocusFine;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : SEM Emission Current 300[ms] 단위로 자동 받기
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMEmissionCurrent(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Emission Current를 자동닫기 위한 명령어 : PC -> Avr
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "AE3;");

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : SEM Gun Hv Up/Down Time Delay 변수 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMGunHVTimeDelayData(BOOL bTimeDelay, double dUpVoltage, double dDownVoltage, double dMaxVoltage, double dMinVoltage, double dCurVoltage, double dStartVoltage, double dStopVoltage, double dStepVoltage)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// GUN HV Up/Down 시 Time Delay 사용여부 설정
	m_pIntegrated->bGunHVTimeDelay    = bTimeDelay;    // 사용여부 설정
	m_pIntegrated->dGunHVUpVoltage    = dUpVoltage;    // Up   Voltage : [V]/[SEC]
	m_pIntegrated->dGunHVDownVoltage  = dDownVoltage;  // Down Voltage : [V]/[SEC] <- Down시에는 Up 일때보다 빠르게 전압을 내린다 
	m_pIntegrated->dGunHVMaxVoltage   = dMaxVoltage;   // Up/Down Max     Voltage : [V]
	m_pIntegrated->dGunHVMinVoltage   = dMinVoltage;   // Up/Down Min     Voltage : [V]
	m_pIntegrated->dGunHVCurVoltage   = dCurVoltage;   // Up/Down Current Voltage : [V]
	m_pIntegrated->dGunHVStartVoltage = dStartVoltage; // Up/Down Start   Voltage : [V]
	m_pIntegrated->dGunHVStopVoltage  = dStopVoltage;  // Up/Down Stop    Voltage : [V]
	m_pIntegrated->dGunHVStepVoltage  = dStepVoltage;  // Up/Down Step    Voltage : [V]

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : SEM Filament Up/Down Time Delay 변수 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMFilamentTimeDelayData(BOOL bTimeDelay, double dUpVoltage, double dDownVoltage, double dMaxVoltage, double dMinVoltage, double dCurVoltage, double dStartVoltage, double dStopVoltage, double dStepVoltage)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Filament Up/Down 시 Time Delay 사용여부 설정
	m_pIntegrated->bFilamentTimeDelay    = bTimeDelay;    // 사용여부 설정
	m_pIntegrated->dFilamentUpVoltage    = dUpVoltage;    // Up   Voltage : [V]/[SEC]
	m_pIntegrated->dFilamentDownVoltage  = dDownVoltage;  // Down Voltage : [V]/[SEC] <- Down시에는 Up 일때보다 빠르게 전압을 내린다 
	m_pIntegrated->dFilamentMaxVoltage   = dMaxVoltage;   // Up/Down Max     Voltage : [V]
	m_pIntegrated->dFilamentMinVoltage   = dMinVoltage;   // Up/Down Min     Voltage : [V]
	m_pIntegrated->dFilamentCurVoltage   = dCurVoltage;   // Up/Down Current Voltage : [V]
	m_pIntegrated->dFilamentStartVoltage = dStartVoltage; // Up/Down Start   Voltage : [V]
	m_pIntegrated->dFilamentStopVoltage  = dStopVoltage;  // Up/Down Stop    Voltage : [V]
	m_pIntegrated->dFilamentStepVoltage  = dStepVoltage;  // Up/Down Step    Voltage : [V]

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : SEM Bias Up/Down Time Delay 변수 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMBiasTimeDelayData(BOOL bTimeDelay, double dUpVoltage, double dDownVoltage, double dMaxVoltage, double dMinVoltage, double dCurVoltage, double dStartVoltage, double dStopVoltage, double dStepVoltage)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Bias Up/Down 시 Time Delay 사용여부 설정
	m_pIntegrated->bBiasTimeDelay    = bTimeDelay;    // 사용여부 설정
	m_pIntegrated->dBiasUpVoltage    = dUpVoltage;    // Up   Voltage : [V]/[SEC]
	m_pIntegrated->dBiasDownVoltage  = dDownVoltage;  // Down Voltage : [V]/[SEC] <- Down시에는 Up 일때보다 빠르게 전압을 내린다 
	m_pIntegrated->dBiasMaxVoltage   = dMaxVoltage;   // Up/Down Max     Voltage : [V]
	m_pIntegrated->dBiasMinVoltage   = dMinVoltage;   // Up/Down Min     Voltage : [V]
	m_pIntegrated->dBiasCurVoltage   = dCurVoltage;   // Up/Down Current Voltage : [V]
	m_pIntegrated->dBiasStartVoltage = dStartVoltage; // Up/Down Start   Voltage : [V]
	m_pIntegrated->dBiasStopVoltage  = dStopVoltage;  // Up/Down Stop    Voltage : [V]
	m_pIntegrated->dBiasStepVoltage  = dStepVoltage;  // Up/Down Step    Voltage : [V]

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get SEM HV ALL 쓰레드 Process Flag
/////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AfxGetSEMHVAllUpDownProcessFlag(void)
{
	if (m_pIntegrated == NULL) return FALSE;

	// HV ALL Process 쓰레드 상태 
	// TRUE : 쓰레드 사용중, FALSE : 쓰레드 종료
	return m_pIntegrated->bHVAllStartProcessFlag;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get Stig-X Low Limit 값 
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMStigXLowLimit(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stig-X Low Limit
	return m_pIntegrated->nStigXLowLimit;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Set Stig-X Low Limit 값 
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMStigXLowLimit(int nLimit)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stig-X Low Limit
	m_pIntegrated->nStigXLowLimit = nLimit;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get Stig-X High Limit 값 
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMStigXHighLimit(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stig-X High Limit
	return m_pIntegrated->nStigXHighLimit;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Set Stig-X High Limit 값 
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMStigXHighLimit(int nLimit)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stig-X High Limit
	m_pIntegrated->nStigXHighLimit = nLimit;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get Stig-Y Low Limit 값 
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMStigYLowLimit(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stig-Y Low Limit
	return m_pIntegrated->nStigYLowLimit;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Set Stig-Y Low Limit 값 
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMStigYLowLimit(int nLimit)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stig-Y Low Limit
	m_pIntegrated->nStigYLowLimit = nLimit;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get Stig-Y High Limit 값 
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMStigYHighLimit(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stig-Y High Limit
	return m_pIntegrated->nStigXHighLimit;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Set Stig-Y High Limit 값 
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMStigYHighLimit(int nLimit)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stig-Y High Limit
	m_pIntegrated->nStigYHighLimit = nLimit;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get Stig-X Reference 값 
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMStigXReference(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stig X
	//m_pIntegrated->nStigXReference = m_pIntegrated->nStigXValue;

	// Stig-X Reference
	return m_pIntegrated->nStigXReference;
}
int AfxGetSEMStigXValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stig X
	return m_pIntegrated->nStigXValue;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Set Stig-X Reference 값 
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMStigXReference(int nRef)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stig-X Reference
	m_pIntegrated->nStigXReference = nRef;

	// Stig X
	//m_pIntegrated->nStigXValue = m_pIntegrated->nStigXReference;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get Stig-Y Reference 값 
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMStigYReference(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stig Y
	//m_pIntegrated->nStigYReference = m_pIntegrated->nStigYValue;

	// Stig-Y Reference
	return m_pIntegrated->nStigYReference;
}
int AfxGetSEMStigYValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stig Y
	return m_pIntegrated->nStigYValue;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Set Stig-Y Reference 값 
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMStigYReference(int nRef)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stig-Y Reference
	m_pIntegrated->nStigYReference = nRef;

	// Stig Y
	//m_pIntegrated->nStigYValue = m_pIntegrated->nStigYReference;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get Zoom X-Max 값 
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMZoomXMax(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Zoom X-Max
	return m_pIntegrated->nZoomXMaxValue[m_pIntegrated->wMagRelayNumber];// nMagRelayNo];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get Zoom Y-Max 값 
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMZoomYMax(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Zoom Y-Max
	return m_pIntegrated->nZoomYMaxValue[m_pIntegrated->wMagRelayNumber];// nMagRelayNo];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get Zoom X-Value 값 
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMZoomXValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Zoom X-Value
	return m_pIntegrated->wZoomXValue;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get Zoom Y-Value 값 
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMZoomYValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Zoom Y-Value
	return m_pIntegrated->wZoomYValue;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Mode 에 따른 X Image Amp
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMXScanAmp(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// X Scan Amp
	return m_pIntegrated->nXScanAmpVal[m_pIntegrated->nScanMode];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Mode 에 따른 X Image Offset
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMXScanOffset(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// X Scan Offset
	return m_pIntegrated->nXScanOffset[m_pIntegrated->nScanMode];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Mode 에 따른 Y Image Amp
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMYScanAmp(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Y Scan Amp
	return m_pIntegrated->nYScanAmpVal[m_pIntegrated->nScanMode];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Mode 에 따른 Y Image Offset
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMYScanOffset(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Y Scan Offset
	return m_pIntegrated->nYScanOffset[m_pIntegrated->nScanMode];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Spot Size에 따른 CL1 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMSpotSizeCL1(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Spot Size에 따른 CL1
	return (int)m_pIntegrated->wCL1List[m_pIntegrated->nSpotSize - 1];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Spot Size에 따른 CL2 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMSpotSizeCL2(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Spot Size에 따른 CL2
	return (int)m_pIntegrated->wCL2List[m_pIntegrated->nSpotSize - 1];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Mode에 따른 Skip Pixel 갯수 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMSkipPixelCount(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Scan Mode에 따른 Skip Pixel 갯수 값
	return m_pIntegrated->nSkipPixNum[m_pIntegrated->nScanMode];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Mode에 따른 Over Sample 갯수 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMOverSampleCount(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Scan Mode에 따른 Over Sample 갯수 값
	return m_pIntegrated->nOverSampleNum[m_pIntegrated->nScanMode];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Mode에 따른 Frame / [Sec] 1초당 프레임 갯수 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMFrameFreqCount(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Scan Mode에 따른 Frame / [sec] 갯수 값
	return m_pIntegrated->nFrameSec[m_pIntegrated->nScanMode];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Mode에 따른 X Scan Up 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMXScanUpValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Scan Mode에 따른 X Scan Up 값
	return m_pIntegrated->nXScanUpNum[m_pIntegrated->nScanMode];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Mode에 따른 Y Scan Up 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMYScanUpValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Scan Mode에 따른 Y Scan Up 값
	return m_pIntegrated->nYScanUpNum[m_pIntegrated->nScanMode];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Mode에 따른 X Scan Down 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMXScanDownValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Scan Mode에 따른 X Scan Down 값
	return m_pIntegrated->nXScanDownNum[m_pIntegrated->nScanMode];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Mode에 따른 Y Scan Down 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMYScanDownValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Scan Mode에 따른 Y Scan Down 값
	return m_pIntegrated->nYScanDownNum[m_pIntegrated->nScanMode];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Mode에 따른 X Scan Rotation 45 Deg 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMXScanRot45DegValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// X Scan Rotation 45 Deg 값
	return m_pIntegrated->nXScanRot45Deg[m_pIntegrated->nScanMode];
}
int AfxSetSEMXScanRot45DegValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// X Scan Rotation 45 Deg 값
	m_pIntegrated->nXScanRot45Deg[m_pIntegrated->nScanMode] = nValue;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Mode에 따른 X Scan Rotation 90 Deg 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMXScanRot90DegValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// X Scan Rotation 90 Deg 값
	return m_pIntegrated->nXScanRot90Deg[m_pIntegrated->nScanMode];
}
int AfxSetSEMXScanRot90DegValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// X Scan Rotation 90 Deg 값
	m_pIntegrated->nXScanRot90Deg[m_pIntegrated->nScanMode] = nValue;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Mode에 따른 Y Scan Rotation 45 Deg 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMYScanRot45DegValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Y Scan Rotation 45 Deg 값
	return m_pIntegrated->nYScanRot45Deg[m_pIntegrated->nScanMode];
}
int AfxSetSEMYScanRot45DegValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Y Scan Rotation 45 Deg 값
	m_pIntegrated->nYScanRot45Deg[m_pIntegrated->nScanMode] = nValue;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Mode에 따른 Y Scan Rotation 90 Deg 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMYScanRot90DegValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Y Scan Rotation 90 Deg 값
	return m_pIntegrated->nYScanRot90Deg[m_pIntegrated->nScanMode];
}
int AfxSetSEMYScanRot90DegValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Y Scan Rotation 90 Deg 값
	m_pIntegrated->nYScanRot90Deg[m_pIntegrated->nScanMode] = nValue;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : RED Scan Mode의 Filer Factor 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMREDScanFilterFactorValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// RED Scan 의 Filter Factor 값

	if (m_pIntegrated->nScanMode == FULL_SCREEN)
	{
		return m_pIntegrated->nFilterNum[m_pIntegrated->nFullRedScan];
	}

	return m_pIntegrated->nFilterNum[m_pIntegrated->nHalfRedScan];
}
int AfxSetSEMREDScanFilterFactorValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	if (m_pIntegrated->bChangeEnableFlag == FALSE) return RET_SUCCESS_OK;

	// RED Scan 의 Filter Factor 값

	if (m_pIntegrated->nScreenMode == FULL_SCREEN)
	{
		m_pIntegrated->nFilterNum[m_pIntegrated->nFullRedScan] = nValue;
		m_pIntegrated->nSeCommandValue &= SEL_FILT_MASK;
		m_pIntegrated->nSeCommandValue |= m_wFilter[m_pIntegrated->nFilterNum[m_pIntegrated->nFullRedScan]];
	}
	else
	{
		m_pIntegrated->nFilterNum[m_pIntegrated->nHalfRedScan] = nValue;
		m_pIntegrated->nSeCommandValue &= SEL_FILT_MASK;
		m_pIntegrated->nSeCommandValue |= m_wFilter[m_pIntegrated->nFilterNum[m_pIntegrated->nHalfRedScan]];
	}

	// Se Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSeCommandValue);

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : FAST Scan Mode의 Filer Factor 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMFASTScanFilterFactorValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// FAST Scan 의 Filter Factor 값

	if (m_pIntegrated->nScanMode == FULL_SCREEN)
	{
		return m_pIntegrated->nFilterNum[m_pIntegrated->nFullFastScan];
	}

	return m_pIntegrated->nFilterNum[m_pIntegrated->nHalfFastScan];
}
int AfxSetSEMFASTScanFilterFactorValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	if (m_pIntegrated->bChangeEnableFlag == FALSE) return RET_SUCCESS_OK;

	// FAST Scan 의 Filter Factor 값

	if (m_pIntegrated->nScreenMode == FULL_SCREEN)
	{
		m_pIntegrated->nFilterNum[m_pIntegrated->nFullFastScan] = nValue;
		m_pIntegrated->nSeCommandValue &= SEL_FILT_MASK;
		m_pIntegrated->nSeCommandValue |= m_wFilter[m_pIntegrated->nFilterNum[m_pIntegrated->nFullFastScan]];
	}
	else
	{
		m_pIntegrated->nFilterNum[m_pIntegrated->nHalfFastScan] = nValue;
		m_pIntegrated->nSeCommandValue &= SEL_FILT_MASK;
		m_pIntegrated->nSeCommandValue |= m_wFilter[m_pIntegrated->nFilterNum[m_pIntegrated->nHalfFastScan]];
	}

	// Se Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSeCommandValue);

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : SLOW1 Scan Mode의 Filer Factor 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMSLOW1ScanFilterFactorValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// SLOW1 Scan 의 Filter Factor 값

	if (m_pIntegrated->nScanMode == FULL_SCREEN)
	{
		return m_pIntegrated->nFilterNum[m_pIntegrated->nFullSlow1Scan];
	}

	return m_pIntegrated->nFilterNum[m_pIntegrated->nHalfSlow1Scan];
}
int AfxSetSEMSLOW1ScanFilterFactorValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	if (m_pIntegrated->bChangeEnableFlag == FALSE) return RET_SUCCESS_OK;

	// SLOW1 Scan 의 Filter Factor 값

	if (m_pIntegrated->nScreenMode == FULL_SCREEN)
	{
		m_pIntegrated->nFilterNum[m_pIntegrated->nFullSlow1Scan] = nValue;
		m_pIntegrated->nSeCommandValue &= SEL_FILT_MASK;
		m_pIntegrated->nSeCommandValue |= m_wFilter[m_pIntegrated->nFilterNum[m_pIntegrated->nFullSlow1Scan]];
	}
	else
	{
		m_pIntegrated->nFilterNum[m_pIntegrated->nHalfSlow1Scan] = nValue;
		m_pIntegrated->nSeCommandValue &= SEL_FILT_MASK;
		m_pIntegrated->nSeCommandValue |= m_wFilter[m_pIntegrated->nFilterNum[m_pIntegrated->nHalfSlow1Scan]];
	}

	// Se Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSeCommandValue);

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : SLOW2 Scan Mode의 Filer Factor 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMSLOW2ScanFilterFactorValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// SLOW2 Scan 의 Filter Factor 값

	if (m_pIntegrated->nScanMode == FULL_SCREEN)
	{
		return m_pIntegrated->nFilterNum[m_pIntegrated->nFullSlow2Scan];
	}

	return m_pIntegrated->nFilterNum[m_pIntegrated->nHalfSlow2Scan];
}
int AfxSetSEMSLOW2ScanFilterFactorValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	if (m_pIntegrated->bChangeEnableFlag == FALSE) return RET_SUCCESS_OK;

	// SLOW2 Scan 의 Filter Factor 값

	if (m_pIntegrated->nScreenMode == FULL_SCREEN)
	{
		m_pIntegrated->nFilterNum[m_pIntegrated->nFullSlow2Scan] = nValue;
		m_pIntegrated->nSeCommandValue &= SEL_FILT_MASK;
		m_pIntegrated->nSeCommandValue |= m_wFilter[m_pIntegrated->nFilterNum[m_pIntegrated->nFullSlow2Scan]];
	}
	else
	{
		m_pIntegrated->nFilterNum[m_pIntegrated->nHalfSlow2Scan] = nValue;
		m_pIntegrated->nSeCommandValue &= SEL_FILT_MASK;
		m_pIntegrated->nSeCommandValue |= m_wFilter[m_pIntegrated->nFilterNum[m_pIntegrated->nHalfSlow2Scan]];
	}

	// Se Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSeCommandValue);

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : PHOTO Scan Mode의 Filer Factor 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMPHOTOScanFilterFactorValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// PHOTO Scan 의 Filter Factor 값
	return m_pIntegrated->nFilterNum[m_pIntegrated->nPhotoScan];
}
int AfxSetSEMPHOTOScanFilterFactorValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	if (m_pIntegrated->bChangeEnableFlag == FALSE) return RET_SUCCESS_OK;

	// PHOTO Scan 의 Filter Factor 값

	m_pIntegrated->nFilterNum[m_pIntegrated->nPhotoScan] = nValue;
	m_pIntegrated->nSeCommandValue &= SEL_FILT_MASK;
	m_pIntegrated->nSeCommandValue |= m_wFilter[m_pIntegrated->nFilterNum[m_pIntegrated->nPhotoScan]];

	// Se Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSeCommandValue);

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : WD에 따른 보정(Correction) -> WD Max 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMCorrectionWDMaxValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	//int  nWDMaxValue;      // Integrated : WD의 단계(아이템 항목) 최대값
	// WD에 따른 보정(Correction) -> WD Max 값
	return m_pIntegrated->nWDMaxValue;
}
int AfxSetSEMCorrectionWDMaxValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// WD에 따른 보정(Correction) -> WD Max 값
	m_pIntegrated->nWDMaxValue = nValue;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : WD에 따른 보정(Correction) -> WD Z-Axis 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMOLWDx10Value(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// WD의 현재 위치값
	// OL에 따른 WD x10 위치값
	return m_pIntegrated->nOLWD;
}
int AfxGetSEMCorrectionWDZAxisValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	//int  nWDPosition;   // Integrated : WD의 현재 위치값
	// WD에 따른 보정(Correction) -> WD Z-Axis 값
	return m_pIntegrated->nWDPosition;
}
int AfxSetSEMCorrectionWDZAxisValue(int nWD)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	//int  nWDPosition;   // Integrated : WD의 현재 위치값
	// WD에 따른 보정(Correction) -> WD Z-Axis 값
	m_pIntegrated->nWDPosition = nWD;

	if (m_pIntegrated->nWDPosition < SEM_WD_CALI_POS_MIN) m_pIntegrated->nWDPosition = SEM_WD_CALI_POS_MIN;
	if (m_pIntegrated->nWDPosition > SEM_WD_CALI_POS_MAX) m_pIntegrated->nWDPosition = SEM_WD_CALI_POS_MAX;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : WD에 따른 보정(Correction) -> WD OLC 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMCorrectionWDOLCValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;
	if (m_pIntegrated->nWDPosition < SEM_WD_CALI_POS_MIN) m_pIntegrated->nWDPosition = SEM_WD_CALI_POS_MIN;
	if (m_pIntegrated->nWDPosition > SEM_WD_CALI_POS_MAX) m_pIntegrated->nWDPosition = SEM_WD_CALI_POS_MAX;

	// WD에 따른 보정(Correction) -> WD OLC 값
	return m_pIntegrated->nWDOLCoarse[m_pIntegrated->nWDPosition];
}
int AfxSetSEMCorrectionWDOLCValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;
	if (m_pIntegrated->nWDPosition < SEM_WD_CALI_POS_MIN) m_pIntegrated->nWDPosition = SEM_WD_CALI_POS_MIN;
	if (m_pIntegrated->nWDPosition > SEM_WD_CALI_POS_MAX) m_pIntegrated->nWDPosition = SEM_WD_CALI_POS_MAX;

	// WD에 따른 보정(Correction) -> WD OLC 값
	m_pIntegrated->nWDOLCoarse[m_pIntegrated->nWDPosition] = nValue;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : WD에 따른 보정(Correction) -> WD S-Rot 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMCorrectionWDSRotation(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;
	if (m_pIntegrated->nWDPosition < SEM_WD_CALI_POS_MIN) m_pIntegrated->nWDPosition = SEM_WD_CALI_POS_MIN;
	if (m_pIntegrated->nWDPosition > SEM_WD_CALI_POS_MAX) m_pIntegrated->nWDPosition = SEM_WD_CALI_POS_MAX;

	// WD에 따른 보정(Correction) -> WD S-Rot 값
	return m_pIntegrated->nWDSRotation[m_pIntegrated->nWDPosition];
}
int AfxSetSEMCorrectionWDSRotation(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;
	if (m_pIntegrated->nWDPosition < SEM_WD_CALI_POS_MIN) m_pIntegrated->nWDPosition = SEM_WD_CALI_POS_MIN;
	if (m_pIntegrated->nWDPosition > SEM_WD_CALI_POS_MAX) m_pIntegrated->nWDPosition = SEM_WD_CALI_POS_MAX;

	// WD에 따른 보정(Correction) -> WD S-Rot 값
	m_pIntegrated->nWDSRotation[m_pIntegrated->nWDPosition] = nValue;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 현재 Scan Rotation 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMSRotationValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 현재 S-Rotation 값
	return m_pIntegrated->nSRotationValue;
}
int AfxSetSEMSRotationValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 현재 S-Rotation 값
	m_pIntegrated->nSRotationValue = nValue;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : WD에 따른 보정(Correction) -> WD Zoom 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMCorrectionWDZoomValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;
	if (m_pIntegrated->nWDPosition < SEM_WD_CALI_POS_MIN) m_pIntegrated->nWDPosition = SEM_WD_CALI_POS_MIN;
	if (m_pIntegrated->nWDPosition > SEM_WD_CALI_POS_MAX) m_pIntegrated->nWDPosition = SEM_WD_CALI_POS_MAX;

	// WD에 따른 보정(Correction) -> WD Zoom 값
	return m_pIntegrated->nWDZooming[m_pIntegrated->nWDPosition];
}
int AfxSetSEMCorrectionWDZoomValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;
	if (m_pIntegrated->nWDPosition < SEM_WD_CALI_POS_MIN) m_pIntegrated->nWDPosition = SEM_WD_CALI_POS_MIN;
	if (m_pIntegrated->nWDPosition > SEM_WD_CALI_POS_MAX) m_pIntegrated->nWDPosition = SEM_WD_CALI_POS_MAX;

	// WD에 따른 보정(Correction) -> WD Zoom 값
	m_pIntegrated->nWDZooming[m_pIntegrated->nWDPosition] = nValue;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : WD에 따른 보정(Correction) -> Min Mag 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMCorrectionWDMinMagValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;
	if (m_pIntegrated->nWDPosition < SEM_WD_CALI_POS_MIN) m_pIntegrated->nWDPosition = SEM_WD_CALI_POS_MIN;
	if (m_pIntegrated->nWDPosition > SEM_WD_CALI_POS_MAX) m_pIntegrated->nWDPosition = SEM_WD_CALI_POS_MAX;

	// WD에 따른 보정(Correction) -> Min Mag 값
	return m_pIntegrated->nWDMinMag[m_pIntegrated->nWDPosition];
}
int AfxSetSEMCorrectionWDMinMagValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;
	if (m_pIntegrated->nWDPosition < SEM_WD_CALI_POS_MIN) m_pIntegrated->nWDPosition = SEM_WD_CALI_POS_MIN;
	if (m_pIntegrated->nWDPosition > SEM_WD_CALI_POS_MAX) m_pIntegrated->nWDPosition = SEM_WD_CALI_POS_MAX;

	// WD에 따른 보정(Correction) -> WD Min Mag 값
	m_pIntegrated->nWDMinMag[m_pIntegrated->nWDPosition] = nValue;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : WD에 따른 보정(Correction) -> WD Min-Mag 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMCorrectionWDMinMag(int nWD, BOOL bOrig)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// WD에 따른 보정(Correction) -> WD Min-Mag 값
	int n = 0;

	while (m_pIntegrated->nWDMinMag[nWD] != m_nMagStepValue[n] && n < 20)
	{
		n++;
	}

	if (bOrig == TRUE)
	{
		return n;
	}

	if (n >= 20)
	{
		return 10;
	}
	else
	{
		return n - 1;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Spot Size 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMSpotSizeValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Spot Size 값
	return m_pIntegrated->nSpotSize;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Stage Horizental Align 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMStageHorzAlignValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stage Horizental Align 값
	return m_pIntegrated->nStageHorAlign;
}
int AfxSetSEMStageHorzAlignValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stage Horizental Align 값
	m_pIntegrated->nStageHorAlign = nValue;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Set X Mag Step Relay Ratio 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMXMagStepRelayRatio(int nPos)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Set X Mag Step Relay Ratio
	// 배율에 따른 Mag-Relay 변경 및 전류구동용 저항값 오차보상을 위한 보정값(Max값)

	double dRatio = 0.0;

	// 현재 선택된 배율값(Magnification)
	int nMag = m_nMagStepValue[m_pIntegrated->nMagStepIndex];

	if (nMag >= SEM_MAG_STEP_X100K)
	{
		dRatio = (double)(nMag / SEM_MAG_STEP_X100K);
		m_pIntegrated->nMagRelayNo = 4;
	}
	else if (nMag >= SEM_MAG_STEP_X10K)
	{
		dRatio = (double)(nMag / SEM_MAG_STEP_X10K);
		m_pIntegrated->nMagRelayNo = 3;
	}
	else if (nMag >= SEM_MAG_STEP_X1K)
	{
		dRatio = (double)(nMag / SEM_MAG_STEP_X1K);
		m_pIntegrated->nMagRelayNo = 2;
	}
	else if (nMag >= SEM_MAG_STEP_X100)
	{
		dRatio = (double)(nMag / SEM_MAG_STEP_X100);
		m_pIntegrated->nMagRelayNo = 1;
	}
	else //if (nMag >= 20)
	{
		dRatio = (double)(nMag / SEM_MAG_STEP_X10);
		m_pIntegrated->nMagRelayNo = 0;
	}

	m_pIntegrated->wMagRelayNumber = (WORD)m_pIntegrated->nMagRelayNo;
	m_pIntegrated->nZoomXMaxValue[m_pIntegrated->wMagRelayNumber] = (int)((double)(nPos * dRatio));

	return m_pIntegrated->nZoomXMaxValue[m_pIntegrated->wMagRelayNumber];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Set Y Mag Step Relay Ratio 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMYMagStepRelayRatio(int nPos)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Set Y Mag Step Relay Ratio
	// 배율에 따른 Mag-Relay 변경 및 전류구동용 저항값 오차보상을 위한 보정값(Max값)

	double dRatio = 0.0;

	// 현재 선택된 배율값(Magnification)
	int nMag = m_nMagStepValue[m_pIntegrated->nMagStepIndex];

	if (nMag >= SEM_MAG_STEP_X100K)
	{
		dRatio = (double)(nMag / SEM_MAG_STEP_X100K);
		m_pIntegrated->nMagRelayNo = 4;
	}
	else if (nMag >= SEM_MAG_STEP_X10K)
	{
		dRatio = (double)(nMag / SEM_MAG_STEP_X10K);
		m_pIntegrated->nMagRelayNo = 3;
	}
	else if (nMag >= SEM_MAG_STEP_X1K)
	{
		dRatio = (double)(nMag / SEM_MAG_STEP_X1K);
		m_pIntegrated->nMagRelayNo = 2;
	}
	else if (nMag >= SEM_MAG_STEP_X100)
	{
		dRatio = (double)(nMag / SEM_MAG_STEP_X100);
		m_pIntegrated->nMagRelayNo = 1;
	}
	else //if (nMag >= 20)
	{
		dRatio = (double)(nMag / SEM_MAG_STEP_X10);
		m_pIntegrated->nMagRelayNo = 0;
	}

	m_pIntegrated->wMagRelayNumber = (WORD)m_pIntegrated->nMagRelayNo;
	m_pIntegrated->nZoomYMaxValue[m_pIntegrated->wMagRelayNumber] = (int)((double)(nPos * dRatio));

	return m_pIntegrated->nZoomYMaxValue[m_pIntegrated->wMagRelayNumber];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Set Magnification Step Index 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMMagnificationStepIndex(int nIndex, BOOL bSet)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Set Magnification Step Index

	m_pIntegrated->nMagStepIndex = nIndex;

	if (m_pIntegrated->nMagStepIndex >= MAX_MAG_STEP) m_pIntegrated->nMagStepIndex = MAX_MAG_STEP - 1;
	if (m_pIntegrated->nMagStepIndex <= MIN_MAG_STEP) m_pIntegrated->nMagStepIndex = MIN_MAG_STEP;

	if (bSet == FALSE) return RET_SUCCESS_OK;

	// 2020.05.11
	// WD 위치값 찾기
	int nWD10 = AfxIntegratedFindWDValue(m_pIntegrated->nFocusCoarse);
	m_pIntegrated->nOLWD = nWD10;

	AfxIntegratedSetMagnification(m_nMagStepValue[m_pIntegrated->nMagStepIndex], m_pIntegrated->nOLWD);

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Set(Save) Orthogonal Control Value 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMOrthogonalValue(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Save Orthogonal Control Value 값
	m_pIntegrated->nOrthogonal = nValue;
	m_pIntegrated->nARAngle[0] = m_pIntegrated->nOrthogonal;

	return RET_SUCCESS_OK;
}
int AfxGetSEMOrthogonalValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Get Orthogonal Control Value 값
	return m_pIntegrated->nARAngle[0];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get HV Ratio 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxGetSEMHVRatioValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// HV Ratio Calc
	double dHVRatio = sqrt((double)((double)(m_nGunHVTable[m_pIntegrated->nGunHVIndex]) / (double)(MAX_GUN_HV_VOLTAGE)));
	m_pIntegrated->dHVRatio = dHVRatio;

	return m_pIntegrated->dHVRatio;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get CL1,2 Vref Value 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxGetSEMCLVRefValue(int nCLValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	AfxGetSEMHVRatioValue();

	// Calc CL Vref
	double dDavCL = (double)((double)(nCLValue) * m_pIntegrated->dHVRatio * 10.0 / (double)(SEM_CL1_CL2_MAX + 1));
	double dVref = (dDavCL * m_pIntegrated->dAmpRk) / 10.0;

	return dVref;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get CL1,2 Aref Value 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxGetSEMCLARefValue(int nCLValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	AfxGetSEMHVRatioValue();

	// Calc CL Aref
	double dDavCL = (double)((double)(nCLValue)* m_pIntegrated->dHVRatio * 10.0 / (double)(SEM_CL1_CL2_MAX + 1));
	double dVref = (dDavCL * m_pIntegrated->dAmpRk) / 10.0;
	double dAref = dVref / m_pIntegrated->dRefR;

	return dAref;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get CL1,CL2 Amp Rk Value 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxGetSEMAmpRkValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// CL,CL2 Amp Rk
	return m_pIntegrated->dAmpRk;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get CL1,CL2 Ref R Value 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxGetSEMRefRValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// CL,CL2 Ref R
	return m_pIntegrated->dRefR;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get Sync Type Value 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMSyncTypeValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Sync Type Value 값
	if (m_pIntegrated->nSyncVal[m_pIntegrated->nScanMode] & SEM_SYNC_TYPE_FRAME_SYNC)
	{
		return SEM_FRAME_SYNC_TYPE;
	}

	return SEM_LINE_SYNC_TYPE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Get Sync Freq Value 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxGetSEMSyncFreqValue(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Sync Freq Value 값
	int nIndex = (m_pIntegrated->nSyncVal[m_pIntegrated->nScanMode] >> 16);
	double dSyncFreq = (double)m_nSyncFreqTable[nIndex] / 100.0;

	return dSyncFreq;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : OL WD Auto Save
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMOLWDAutoSave(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// OL WD Auto Save
	//----------------------------------------
	// WD 5mm (IniPar.WD_TopLimit)에 위치시킴
	//----------------------------------------
	m_pIntegrated->nWDStepNumber = m_pIntegrated->nWDTopLimit;
	m_pIntegrated->nWDStepMax    = m_pIntegrated->nWDBottomLimit;

	// 2020.01.21
	//m_pIntegrated->nWDPosition   = m_pIntegrated->nWDStepNumber;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 현재 WD Setup Z-Axis 위치 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMWDSetupZAxis(int nWDZAxis)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 현재 WD Setup Z-Axis 위치 값
	m_pIntegrated->nWDStepNumber = nWDZAxis;
	m_pIntegrated->nWDPosition   = nWDZAxis;

	if (m_pIntegrated->nWDPosition   < SEM_WD_CALI_POS_MIN) m_pIntegrated->nWDPosition   = SEM_WD_CALI_POS_MIN;
	if (m_pIntegrated->nWDPosition   > SEM_WD_CALI_POS_MAX) m_pIntegrated->nWDPosition   = SEM_WD_CALI_POS_MAX;
	if (m_pIntegrated->nWDStepNumber < SEM_WD_CALI_POS_MIN) m_pIntegrated->nWDStepNumber = SEM_WD_CALI_POS_MIN;
	if (m_pIntegrated->nWDStepNumber > SEM_WD_CALI_POS_MAX) m_pIntegrated->nWDStepNumber = SEM_WD_CALI_POS_MAX;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 현재 WD (Z-Axis) 위치 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxGetSEMCurrentZAxisPosition(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 현재 WD (Z-Axis) 위치 값
	return m_pIntegrated->dCurZPos;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 현재 WD (Z-Axis) 위치 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetSEMCurrentZAxisPosition(double dCurZPos)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 현재 WD (Z-Axis) 위치 값
	m_pIntegrated->dCurZPos = dCurZPos;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : WD에 따른 OL-Coarse 값을 Focus Coarse 값에 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetWDOLCoarseToFocusCoarse(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// WD에 따른 OL-Coarse 값을 Focus Coarse 값에 적용
	m_pIntegrated->nFocusCoarse = m_pIntegrated->nWDOLCoarse[m_pIntegrated->nWDPosition];

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : WD에 따른 S-Rotation 값을 Scan-Rotation 값에 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetWDSRotToSRotation(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// WD에 따른 S-Rotation 값을 Scan-Rotation 값에 적용
	m_pIntegrated->nSRotationValue = m_pIntegrated->nWDSRotation[m_pIntegrated->nWDPosition];

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Change Enable Flag 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AfxGetChangeEbableFlag(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Change Enable Flag
	return m_pIntegrated->bChangeEnableFlag;
}
int AfxSetChangeEbableFlag(BOOL bEnable)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Change Enable Flag
	m_pIntegrated->bChangeEnableFlag = bEnable;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 직교도 교정값 보정기능 사용 Flag
/////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AfxGetSEMOrthogonalCheckFlag(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 직교도 교정값 보정기능 사용 Flag
	return m_pIntegrated->bOrthogonalCheckFlag;
}
int AfxSetSEMOrthogonalCheckFlag(BOOL bEnable)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 직교도 교정값 보정기능 사용 Flag
	m_pIntegrated->bOrthogonalCheckFlag = bEnable;

	return RET_SUCCESS_OK;
}

/*
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Stage 수평값 보정기능 사용 Flag
/////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AfxGetSEMStageHorzAlignCheckFlag(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stage 수평값 보정기능 사용 Flag
	return m_pIntegrated->bStageHorzAlignCheckFlag;
}
int AfxSetSEMStageHorzAlignCheckFlag(BOOL bEnable)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Stage 수평값 보정기능 사용 Flag
	m_pIntegrated->bStageHorzAlignCheckFlag = bEnable;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : WD에 따른 S-Rot 보정기능 사용 Flag
/////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AfxGetSEMWDSRotAdjustCheckFlag(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// WD에 따른 S-Rot 보정기능 사용 Flag
	return m_pIntegrated->bWDSRotAdjustCheckFlag;
}
int AfxSetSEMWDSRotAdjustCheckFlag(BOOL bEnable)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// WD에 따른 S-Rot 보정기능 사용 Flag
	m_pIntegrated->bWDSRotAdjustCheckFlag = bEnable;

	return RET_SUCCESS_OK;
}
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Photo Noe-Stop Scan 기능 사용 Flag
/////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AfxGetSEMPhotoNoneStopFlag(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Photo Noe-Stop Scan 기능 사용 Flag
	return m_pIntegrated->bPhotoNoneStopFlag;
}
int AfxSetSEMPhotoNoneStopFlag(BOOL bEnable)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Photo Noe-Stop Scan 기능 사용 Flag
	m_pIntegrated->bPhotoNoneStopFlag = bEnable;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : HV에 따른 Scale 보정 사용 Flag
/////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AfxGetHVCalibrationCheckFlag(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// HV에 따른 Scale 보정 사용 Flag
	return m_pIntegrated->bWDHVCompensationFlag;
}
int AfxSetHVCalibrationCheckFlag(BOOL bEnable)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// HV에 따른 Scale 보정 사용 Flag
	m_pIntegrated->bWDHVCompensationFlag = bEnable;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Mag Step Value
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMMagStepValue(int nIndex)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	if (nIndex < 0) nIndex = 0;
	if (nIndex > MAX_MAG_STEP - 1)nIndex = MAX_MAG_STEP - 1;

	// Mag Step Value
	return m_nMagStepValue[nIndex];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 음양반전 기능 사용 Flag
/////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AfxGetSEMNegativeImageCheckFlag(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 음양반전 기능 사용 Flag
	return m_pIntegrated->bNEGImageFlag;
}
int AfxSetSEMNegativeImageCheckFlag(BOOL bEnable, BOOL bApply)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 음양반전 기능 사용 Flag
	m_pIntegrated->bNEGImageFlag = bEnable;

	if (bApply == FALSE) return RET_SUCCESS_OK;

	if (m_pIntegrated->bNEGImageFlag == TRUE)
	{
		// 음영반전 사용
		m_pIntegrated->nSeCommandValue |= NEGATIVE_IMG_HIGH;
		// Se Command 전송
		AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSeCommandValue);
	}
	else
	{
		// 음영반전 미사용
		m_pIntegrated->nSeCommandValue &= NEGATIVE_IMG_LOW;
		// Se Command 전송
		AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSeCommandValue);
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 좌우반전 기능 사용 Flag
/////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AfxGetSEMLRMirrorImageCheckFlag(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	//좌우반전 기능 사용 Flag
	return m_pIntegrated->bLRMirrorFlag;
}
int AfxSetSEMLRMirrorImageCheckFlag(BOOL bEnable, BOOL bApply)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 좌우반전 기능 사용 Flag
	m_pIntegrated->bLRMirrorFlag = bEnable;

	if (bApply == FALSE) return RET_SUCCESS_OK;

	if (m_pIntegrated->bLRMirrorFlag == TRUE)
	{
		// 좌우반전 사용
		m_pIntegrated->nSbrCommandState |= XSCAN_INVERSE_HIGH;
		// Sbr Data 전송
		AfxFT232HPortSendCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSbrCommandState); 
	}
	else
	{
		// 좌우반전 미사용
		m_pIntegrated->nSbrCommandState &= XSCAN_INVERSE_LOW;
		// Sbr Data 전송
		AfxFT232HPortSendCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSbrCommandState);
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 상하반전 기능 사용 Flag
/////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AfxGetSEMTBMirrorImageCheckFlag(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	//상하반전 기능 사용 Flag
	return m_pIntegrated->bTBMirrorFlag;
}
int AfxSetSEMTBMirrorImageCheckFlag(BOOL bEnable, BOOL bApply)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 상하반전 기능 사용 Flag
	m_pIntegrated->bTBMirrorFlag = bEnable;

	if (bApply == FALSE) return RET_SUCCESS_OK;

	if (m_pIntegrated->bTBMirrorFlag == TRUE)
	{
		// 상하반전 사용
		m_pIntegrated->nSbrCommandState |= YSCAN_INVERSE_HIGH;
		// Sbr Data 전송
		AfxFT232HPortSendCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSbrCommandState);
	}
	else
	{
		// 상하반전 미사용
		m_pIntegrated->nSbrCommandState &= YSCAN_INVERSE_LOW;
		// Sbr Data 전송
		AfxFT232HPortSendCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSbrCommandState);
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : BSE 음양반전 기능 사용 Flag
/////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AfxGetSEMBseNegativeImageCheckFlag(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 2021.07.22
	// BSE 음양반전 기능 사용 Flag
	return m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_BSE_NEG_IMAGE];
}
int AfxSetSEMBseNegativeImageCheckFlag(BOOL bEnable, BOOL bApply)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 2021.07.22
	// BSE 음양반전 기능 사용 Flag
	m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_BSE_NEG_IMAGE] = bEnable;

	if (bApply == FALSE) return RET_SUCCESS_OK;

	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_BSE_NEG_IMAGE] == TRUE)
	{
		// BSE 음영반전 사용
		m_pIntegrated->nSeCommandValue |= NEGATIVE_IMG_HIGH;
		// Se Command 전송
		AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSeCommandValue);
	}
	else
	{
		// BSE 음영반전 미사용
		m_pIntegrated->nSeCommandValue &= NEGATIVE_IMG_LOW;
		// Se Command 전송
		AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSeCommandValue);
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : BSE 좌우반전 기능 사용 Flag
/////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AfxGetSEMBseLRMirrorImageCheckFlag(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 2021.07.22
	// BSE 좌우반전 기능 사용 Flag
	return m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_BSE_FLIP_HORZ];
}
int AfxSetSEMBseLRMirrorImageCheckFlag(BOOL bEnable, BOOL bApply)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 2021.07.22
	// BSE 좌우반전 기능 사용 Flag
	m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_BSE_FLIP_HORZ] = bEnable;

	if (bApply == FALSE) return RET_SUCCESS_OK;

	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_BSE_FLIP_HORZ] == TRUE)
	{
		// BSE 좌우반전 사용
		m_pIntegrated->nSbrCommandState |= XSCAN_INVERSE_HIGH;
		// Sbr Data 전송
		AfxFT232HPortSendCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSbrCommandState);
	}
	else
	{
		// BSE 좌우반전 미사용
		m_pIntegrated->nSbrCommandState &= XSCAN_INVERSE_LOW;
		// Sbr Data 전송
		AfxFT232HPortSendCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSbrCommandState);
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : BSE 상하반전 기능 사용 Flag
/////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AfxGetSEMBseTBMirrorImageCheckFlag(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 2021.07.22
	// BSE 상하반전 기능 사용 Flag
	return m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_BSE_FLIP_VERT];
}
int AfxSetSEMBseTBMirrorImageCheckFlag(BOOL bEnable, BOOL bApply)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 2021.07.22
	// BSE 상하반전 기능 사용 Flag
	m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_BSE_FLIP_VERT] = bEnable;

	if (bApply == FALSE) return RET_SUCCESS_OK;

	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_BSE_FLIP_VERT] == TRUE)
	{
		// BSE 상하반전 사용
		m_pIntegrated->nSbrCommandState |= YSCAN_INVERSE_HIGH;
		// Sbr Data 전송
		AfxFT232HPortSendCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSbrCommandState);
	}
	else
	{
		// BSE 상하반전 미사용
		m_pIntegrated->nSbrCommandState &= YSCAN_INVERSE_LOW;
		// Sbr Data 전송
		AfxFT232HPortSendCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSbrCommandState);
	}

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : CL1 전류에 따른 12bit DA
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMDACL1Value(int nSpotSize)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// CL1 전류에 따른 12bit DA
	return m_nDA_CL1[nSpotSize-1];
}
int AfxSetSEMDACL1Value(int nSpotSize, int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// CL1 전류에 따른 12bit DA
	m_nDA_CL1[nSpotSize-1] = nValue;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : CL2 전류에 따른 12bit DA
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMDACL2Value(int nSpotSize)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// CL2 전류에 따른 12bit DA
	return m_nDA_CL2[nSpotSize-1];
}
int AfxSetSEMDACL2Value(int nSpotSize, int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// CL2 전류에 따른 12bit DA
	m_nDA_CL2[nSpotSize-1] = nValue;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 배율에 따른 OL 보정 방식
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxGetSEMOLCompensation(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 배율에 따른 OL 보정 방식
	return m_pIntegrated->nOLCompensation;
}
int AfxSetSEMOLCompensation(int nOLCompensation)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 배율에 따른 OL 보정 방식 설정
	m_pIntegrated->nOLCompensation = nOLCompensation;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Skip Pixel 값 설정 및 하드웨어 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetSkipPixelNum(int nSkipPixel)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	m_pIntegrated->nSkipPixNum[m_pIntegrated->nScanMode] = nSkipPixel;

	// Skip Pixel 값
	// Smg Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cSKIP_NUM_LOAD, m_pIntegrated->nSkipPixNum[m_pIntegrated->nScanMode]);

	return RET_SUCCESS_OK;
}
int AfxIntegratedGetSkipPixelNum(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Skip Pixel 값
	return m_pIntegrated->nSkipPixNum[m_pIntegrated->nScanMode];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Over Sample 값 설정 및 하드웨어 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetOverSampleNum(int nOverSample)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	m_pIntegrated->nOverSampleNum[m_pIntegrated->nScanMode] = nOverSample;

	// Over Sample 값
	// Smg Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cOS_NUM_LOAD, m_pIntegrated->nOverSampleNum[m_pIntegrated->nScanMode]);

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Frame Freq 계산 및 하드웨어 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedCalcAndExecuteFrameFreq(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	WORD wCom_Buf[TMP_STRING_LENGTH+1];
	memset(wCom_Buf, 0x00, sizeof(wCom_Buf));

	double dFrame  = 0.0;
	int nPhase_inc = 0;
	int nScan_clk  = 0;
	__int64 nPhase_inc64 = 0;

	//--------------------------------------------------------------------------
	// Scan Clock 변경
	//--------------------------------------------------------------------------
	dFrame = (double)(m_pIntegrated->nFrameSecVal[m_pIntegrated->nScanMode]) * 0.001;
	dFrame = (double)(m_pIntegrated->nXScanUpNum[m_pIntegrated->nScanMode] + m_pIntegrated->nXScanDownNum[m_pIntegrated->nScanMode]) * (double)(m_pIntegrated->nYScanUpNum[m_pIntegrated->nScanMode] + m_pIntegrated->nYScanDownNum[m_pIntegrated->nScanMode]) * dFrame;
	nScan_clk = (int)dFrame;

	///////////////////////////////////////////////////////////////////////////////////
	// 2021.07.29
	// SCAN CLOCK  ( 32Bits, 48MHz ) --> ( 48Bits, 100MHz) 로 변경하여 계산 적용
	///////////////////////////////////////////////////////////////////////////////////
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_SCAN_CLOCK_48] == 1)
	{
		// SCAN CLOCK 48Bits, 100MHz
	    //--------------------------------------------------------------------------
	    // 2021.07.29
	    // 추가옵션사항 : ( ScanClk * 2^32 / 48[MHz] ) --> ( ScanClk * 2^48 / 100[MHz] )
	    //--------------------------------------------------------------------------
	    nPhase_inc64 = (__int64)(nScan_clk * (Exp2E48 / 100000000));
	    wCom_Buf[0]  = cWR_FDDS_LOW;	   wCom_Buf[1] = (WORD)(nPhase_inc64 & 0x000000000000FFFF); nPhase_inc64 = nPhase_inc64 >> 16;
	    wCom_Buf[2]  = cWR_FDDS_HIGH;      wCom_Buf[3] = (WORD)(nPhase_inc64 & 0x000000000000FFFF); nPhase_inc64 = nPhase_inc64 >> 16;
	    wCom_Buf[4]  = cWR_FDDS_HIGH48;    wCom_Buf[5] = (WORD)(nPhase_inc64 & 0x000000000000FFFF);
	    //--------------------------------------------------------------------------
	    AfxFT232HPortSendMultiCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, wCom_Buf, 6); // Sbr Scan Clock Data 전송
	    //--------------------------------------------------------------------------
	}
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	else
	{
		// SCAN CLOCK 32Bits, 48MHz
		nPhase_inc64 = (__int64)(nScan_clk * Exp2E32 / 48000000);
		nPhase_inc   = (__int32)(nPhase_inc64);
		//--------------------------------------------------------------------------
		wCom_Buf[0] = cWR_FDDS_LOW;	 wCom_Buf[1] = nPhase_inc & 0x0000FFFF;
		wCom_Buf[2] = cWR_FDDS_HIGH; wCom_Buf[3] = nPhase_inc >> 16;
		//--------------------------------------------------------------------------
		AfxFT232HPortSendMultiCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, wCom_Buf, 4); // Sbr Scan Clock Data 전송
		//--------------------------------------------------------------------------
	}
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Frame Freq 값 설정 및 하드웨어 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetFrameFreq(int nFrameFreq)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	m_pIntegrated->nFrameSec[m_pIntegrated->nScanMode] = nFrameFreq;
	m_pIntegrated->nFrameSecVal[m_pIntegrated->nScanMode] = m_pIntegrated->nFrameSec[m_pIntegrated->nScanMode];

	// Frame Freq 계산 및 하드웨어 적용
	AfxIntegratedCalcAndExecuteFrameFreq();

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : X Scan Up 값 설정 및 하드웨어 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetXScanUp(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	m_pIntegrated->nXScanUp = nValue;
	m_pIntegrated->nXScanUpNum[m_pIntegrated->nScanMode] = m_pIntegrated->nXScanUp;

	// Frame Freq 계산 및 하드웨어 적용 - X Scan Up 변경
	//AfxScanBridgeSetScanClockAndWaveform();

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Y Scan Up 값 설정 및 하드웨어 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetYScanUp(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	m_pIntegrated->nYScanUp = nValue;
	m_pIntegrated->nYScanUpNum[m_pIntegrated->nScanMode] = m_pIntegrated->nYScanUp;

	// Frame Freq 계산 및 하드웨어 적용 - Y Scan Up 변경
	//AfxScanBridgeSetScanClockAndWaveform();

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : X Scan Down 값 설정 및 하드웨어 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetXScanDown(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	m_pIntegrated->nXBlankWidth = nValue;
	m_pIntegrated->nXScanDownNum[m_pIntegrated->nScanMode] = m_pIntegrated->nXBlankWidth;

	// Frame Freq 계산 및 하드웨어 적용 - X Scan Down 변경
	//AfxScanBridgeSetScanClockAndWaveform();

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Y Scan Down 값 설정 및 하드웨어 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetYScanDown(int nValue)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	m_pIntegrated->nYBlankWidth = nValue;
	m_pIntegrated->nYScanDownNum[m_pIntegrated->nScanMode] = m_pIntegrated->nYBlankWidth;

	// Frame Freq 계산 및 하드웨어 적용 - Y Scan Down 변경
	//AfxScanBridgeSetScanClockAndWaveform();

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : Scan Clock(주파수) 변경 및 X,YScan 기본파형 발생
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxScanBridgeSetScanClockAndWaveform(void)
{
	// Scan Clock(주파수) 변경 및 X,YScan 기본파형 발생
	//if (m_pSbrCommand == NULL) return RET_ERROR_SBR_COMMAND_HANDLE;
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	int nSM = m_pIntegrated->nScanMode; // Scan Mode

	//m_pIntegrated->nFrameSecVal[nSM]  = m_pIntegrated->nFrameSec[nSM];// Frame/sec
	//m_pIntegrated->nXScanUpNum[nSM]   = m_pIntegrated->nXScanUp;      // X Scan Up
	//m_pIntegrated->nXScanDownNum[nSM] = m_pIntegrated->nXBlankWidth;  // X Scan Down
	//m_pIntegrated->nYScanUpNum[nSM]   = m_pIntegrated->nYScanUp;      // Y Scan Up
	//m_pIntegrated->nYScanDownNum[nSM] = m_pIntegrated->nYBlankWidth;  // Y Scan Down

	if (m_pIntegrated->nXScanUpNum[nSM] == 0 || m_pIntegrated->nXScanDownNum[nSM] == 0 ||
		m_pIntegrated->nYScanUpNum[nSM] == 0 || m_pIntegrated->nYScanDownNum[nSM] == 0)
	{
		return RET_SUCCESS_OK;
	}

	//__int8 nSmall;      // Declares 8-bit integer  
	//__int16 nMedium;    // Declares 16-bit integer  
	//__int32 nLarge;     // Declares 32-bit integer  
	//__int64 nHuge;      // Declares 64-bit integer  

	WORD wCom_Buf[TMP_STRING_LENGTH+1];
	memset(wCom_Buf, 0x00, sizeof(wCom_Buf));

	double dFrame   = 0.0;
	int nPhase_inc  = 0;
	int nScan_clk   = 0;
	int nInc_val    = 0;
	int nInc_height = 0;
	int nLow_val    = 0;
	int nHigh_val   = 0;
	int nDec_val    = 0;

	__int64 nPhase_inc64 = 0;

	//--------------------------------------------------------------------------
	// Scan Clock 변경
	//--------------------------------------------------------------------------
	dFrame = (double)(m_pIntegrated->nFrameSecVal[nSM]) * 0.001;
	dFrame = (double)(m_pIntegrated->nXScanUpNum[nSM] + m_pIntegrated->nXScanDownNum[nSM]) * (double)(m_pIntegrated->nYScanUpNum[nSM] + m_pIntegrated->nYScanDownNum[nSM]) * dFrame;
	nScan_clk = (int)dFrame;

	///////////////////////////////////////////////////////////////////////////////////
	// 2021.07.29
	// SCAN CLOCK  ( 32Bits, 48MHz ) --> ( 48Bits, 100MHz) 로 변경하여 계산 적용
	///////////////////////////////////////////////////////////////////////////////////
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_SCAN_CLOCK_48] == 1)
	{
		// SCAN CLOCK 48Bits, 100MHz
	    //--------------------------------------------------------------------------
	    // 2021.07.29
	    // 추가옵션사항 : ( ScanClk * 2^32 / 48[MHz] ) --> ( ScanClk * 2^48 / 100[MHz] )
	    //--------------------------------------------------------------------------
	    nPhase_inc64 = (__int64)(nScan_clk * (Exp2E48 / 100000000));
	    wCom_Buf[0]  = cWR_FDDS_LOW;	   wCom_Buf[1] = (WORD)(nPhase_inc64 & 0x000000000000FFFF); nPhase_inc64 = nPhase_inc64 >> 16;
	    wCom_Buf[2]  = cWR_FDDS_HIGH;      wCom_Buf[3] = (WORD)(nPhase_inc64 & 0x000000000000FFFF); nPhase_inc64 = nPhase_inc64 >> 16;
	    wCom_Buf[4]  = cWR_FDDS_HIGH48;    wCom_Buf[5] = (WORD)(nPhase_inc64 & 0x000000000000FFFF);
	    //--------------------------------------------------------------------------
	    AfxFT232HPortSendMultiCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, wCom_Buf, 6); // Sbr Scan Clock Data 전송
	    //--------------------------------------------------------------------------
	}
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	else
	{
		// SCAN CLOCK 32Bits, 48MHz
		nPhase_inc64 = (__int64)(nScan_clk * Exp2E32 / 48000000);
		nPhase_inc   = (__int32)(nPhase_inc64);
		//--------------------------------------------------------------------------
		wCom_Buf[0] = cWR_FDDS_LOW;	 wCom_Buf[1] = nPhase_inc & 0x0000FFFF;
		wCom_Buf[2] = cWR_FDDS_HIGH; wCom_Buf[3] = nPhase_inc >> 16;
		//--------------------------------------------------------------------------
		AfxFT232HPortSendMultiCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, wCom_Buf, 4); // Sbr Scan Clock Data 전송
		//--------------------------------------------------------------------------
	}
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	//--------------------------------------------------------------------------
	// XScan 기본파형 발생
	//--------------------------------------------------------------------------
	memset(wCom_Buf, 0x00, sizeof(WORD)*(24 + 1));
	nInc_val = 4096 / m_pIntegrated->nXScanUpNum[nSM];
	nInc_height = nInc_val * m_pIntegrated->nXScanUpNum[nSM];
	nLow_val = (4096 - nInc_height) / 2;
	nHigh_val = 4096 - nLow_val;
	nDec_val = nInc_height / m_pIntegrated->nXScanDownNum[nSM];

	wCom_Buf[0] = cWR_XSCAN_LOW;        wCom_Buf[1]  = nLow_val;
	wCom_Buf[2] = cWR_XSCAN_HIGH;       wCom_Buf[3]  = nHigh_val;
	wCom_Buf[4] = cWR_XSCAN_INC_VAL;    wCom_Buf[5]  = nInc_val;
	wCom_Buf[6] = cWR_XSCAN_DEC_VAL;    wCom_Buf[7]  = nDec_val;
	wCom_Buf[8] = cWR_XSCAN_INC_PIX;    wCom_Buf[9]  = m_pIntegrated->nXScanUpNum[nSM];
	wCom_Buf[10] = cWR_XSCAN_DEC_PIX;   wCom_Buf[11] = m_pIntegrated->nXScanDownNum[nSM];
	//--------------------------------------------------------------------------
	// YScan 기본파형 발생
	//--------------------------------------------------------------------------
	memset(wCom_Buf, 0x00, sizeof(WORD)*(24 + 1));
	nInc_val = 4096 / m_pIntegrated->nYScanUpNum[nSM];
	nInc_height = nInc_val * m_pIntegrated->nYScanUpNum[nSM];
	nLow_val = (4096 - nInc_height) / 2;
	nHigh_val = 4096 - nLow_val;
	nDec_val = nInc_height / m_pIntegrated->nYScanDownNum[nSM];

	wCom_Buf[12] = cWR_YSCAN_LOW;       wCom_Buf[13] = nLow_val;
	wCom_Buf[14] = cWR_YSCAN_HIGH;      wCom_Buf[15] = nHigh_val;
	wCom_Buf[16] = cWR_YSCAN_INC_VAL;   wCom_Buf[17] = nInc_val;
	wCom_Buf[18] = cWR_YSCAN_DEC_VAL;   wCom_Buf[19] = nDec_val;
	wCom_Buf[20] = cWR_YSCAN_INC_PIX;   wCom_Buf[21] = m_pIntegrated->nYScanUpNum[nSM];    // 2048
	wCom_Buf[22] = cWR_YSCAN_DEC_PIX;   wCom_Buf[23] = m_pIntegrated->nYScanDownNum[nSM];  //  128
	//--------------------------------------------------------------------------
	AfxFT232HPortSendMultiCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, wCom_Buf, 24); // Sbr X-Y Waveform Data 전송
	//--------------------------------------------------------------------------

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Image Capture Change 하드웨어 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetImageCaptureChange(int nOSSclk, int nImgSkip)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Image Capture Change
	WORD wComBuf[5 + 1];

	memset(&wComBuf, 0x00, sizeof(WORD)*(5 + 1));

	wComBuf[0] = cSCCLK_NUM_LOAD;
	wComBuf[1] = nOSSclk;
	wComBuf[2] = cSKIP_NUM_LOAD;
	wComBuf[3] = nImgSkip;

	// Smg Command 전송
	AfxFT232HPortSendMultiCommand(IDX_FT232H_SEM_IMAGE_DEVICE, wComBuf, 4);

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Normal Screen Mode 하드웨어 적용
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetFPGANormalScreenMode(void)
{
	// Set FPGA

	// Scan Image Board : NORMAL SCREEN MODE
	m_pIntegrated->nSeCommandValue &= DUAL_SCREEN_LOW;
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSeCommandValue); // SE-Image Command 전송

	// Scan Bridge Board : NORMAL SCREEN MODE
	m_pIntegrated->nSbrCommandState &= DUAL_SCREEN_LOW;
	AfxFT232HPortSendCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSbrCommandState); // Sbr Data 전송

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : GUN HV EC VALUE Setting
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetGunHVECValue(WORD wECVal)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// Smg Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_AD5361, AD5361_EC + (wECVal + 4096 << 3));

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : SET STAGE OPTION DATA
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetStageOptionData(int nType, int nIndex, BOOL bFlag, BYTE btData, int nData, DWORD dwData, double dData)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// STAGE OPTION DATA 설정

	if (nType == IDX_STAGE_OPTION_BOOL_TYPE)
	{
		// BOOL 형 Data Type
		if (nIndex == IDX_STAGE_OPTION_BOOL_XY_REVERSE)
		{
			m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_XY_REVERSE] = bFlag;        // X<-->Y 반전

		    // X축 위치값 읽기 (Read Position)
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RP0;");
			// WAIT
			//AfxSystemWaitTime(50);
			Sleep(50);
			// Y축 위치값 읽기 (Read Position)
			AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, "RP1;");
		}
		else if (nIndex == IDX_STAGE_OPTION_BOOL_X_LR_REVERSE)
		{
			m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_X_LR_REVERSE] = bFlag;      // X LR 반전
		}
		else if (nIndex == IDX_STAGE_OPTION_BOOL_Y_TB_REVERSE)
		{
			m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_Y_TB_REVERSE] = bFlag;      // Y TB 반전
		}
		else if (nIndex == IDX_STAGE_OPTION_BOOL_Z_UD_REVERSE)
		{
			m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_Z_UD_REVERSE] = bFlag;      // Z UD 반전
		}
		else if (nIndex == IDX_STAGE_OPTION_BOOL_Z_MOVE_ECHO)
		{
			m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_Z_MOVE_ECHO]  = bFlag;      // Z MOVING ECHO ON/OFF
		}
		else if (nIndex == IDX_STAGE_OPTION_BOOL_ALL_DATA_VIEW)
		{
			m_pIntegrated->bStageOptionFlag[IDX_STAGE_OPTION_BOOL_ALL_DATA_VIEW] = bFlag;     // AXIS ALL DATA VIEW : 5 Axis 사용
		}
	}
	else if (nType == IDX_STAGE_OPTION_BYTE_TYPE)
	{
		// BYTE 형 Data Type
	}
	else if (nType == IDX_STAGE_OPTION_INT_TYPE)
	{
		// INT 형 Data Type
	}
	else if (nType == IDX_STAGE_OPTION_DWORD_TYPE)
	{
		// DWORD 형 Data Type
	}
	else if (nType == IDX_STAGE_OPTION_DOUBLE_TYPE)
	{
		// DOUBLE 형 Data Type
	}


	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : AUTO PROCESS MODE
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetAutoProcessMode(int nAutoProcessMode)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	/////////////////////////////////////////////////
	// Auto Process Mode
	/////////////////////////////////////////////////
	// SE_SCAN_DATA_NORMAL_EXECUTE
	// SE_SCAN_DATA_AUTO_FOCUS_EXECUTE
	// SE_SCAN_DATA_AUTO_CONTRAST_EXECUTE
	// SE_SCAN_DATA_AUTO_BRIGHTNESS_EXECUTE

	m_nSEScanDataAutoModeExecute = nAutoProcessMode;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : SCAN HW SETUP OPTION DATA 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetScanHWSetupOptionFlag(int nPhotoImageFilter, int nISXReverse, int nISYReverse, int nOrthogonal, int nStageHorz, int nZFocusLink, int nWDSRot, int nWDZoom, int nHVCorrect, int nHVDegaussing, int nScanClk48)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// SCAN HW SETUP : OPTION DATA

	// PHOTO NONE STOP --> 2020.05.26 PHOTO IMAGE FILTERING
	if (nPhotoImageFilter >= 0) m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_PHOTO_IMAGE_FILTER] = nPhotoImageFilter;

	// IMAGE SHIFT X REVERSE --> IMAGE EFFECT (음영,좌우,상하) 옵션으로 사용
	if (nISXReverse >= 0) m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_IMAGE_SHIFT_X_REVERSE]    = nISXReverse;

	// IMAGE SHIFT Y REVERSE --> x35k 배율보정 옵션으로 사용
	if (nISYReverse >= 0) m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_IMAGE_SHIFT_Y_REVERSE]    = nISYReverse;

	// ORTHOGONAL CORRECTION
	if (nOrthogonal >= 0) m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_ORTHOGONAL_CORRRECTION]   = nOrthogonal;

	// STAGE HORZ ALIGN
	if (nStageHorz >= 0) m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_STAGE_HORZ_ALIGN]          = nStageHorz;

	// Z AXIS FOCUS LINK
	if (nZFocusLink >= 0) m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_Z_AXIS_FOCUS_LINK]        = nZFocusLink;

	// WD SCAN ROTATION CORRECTION
	if (nWDSRot >= 0) m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_WD_SCAN_ROTATION]             = nWDSRot;

	// WD SCALE ZOOM CORRECTION
	if (nWDZoom >= 0) m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_WD_SCALE_ZOOM]                = nWDZoom;

	// HV CORRECTION
	if (nHVCorrect >= 0) m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_HV_CORRECTION]             = nHVCorrect;

	// 2021.08.23 : HV PROCESSING 완료 후, FOCUS DEGAUSSING
	if (nHVDegaussing >= 0) m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_HV_DEGAUSSING]          = nHVDegaussing;

	// 2021.07.29 : SCAN CLOCK 48BITS
	if (nHVDegaussing >= 0) m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_SCAN_CLOCK_48]          = nScanClk48;

	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 배율에 따른 HV 보정값 사용자 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
void AfxIntegratedSetMagHVRatio(double *pdMagHVRatio)
{
	// 사용자 설정 배율 HV RATIO 보정값 설정
	memcpy(m_dOptionMagHVRatio, pdMagHVRatio, sizeof(double)*MAX_GUN_HV_TABLE);
	
	// 0값 CHECK?
	for (int n = 0; n < MAX_GUN_HV_TABLE; n++)
	{
		if (m_dOptionMagHVRatio[n] == 0.0)
		{
			m_dOptionMagHVRatio[n] = DEFAULT_MAG_HV_RATIO;
		}
	}

	// 2020.06.03
	// 사용자 MAG HV RATIO : STAGE 수평 옵션을 임시로 사용한다.
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_STAGE_HORZ_ALIGN] == 1)
	{
		// 사용자 설정 배율 HV RATIO 보정값 설정
		// GUN HV 배율 비율 계산
		m_pIntegrated->dMagHVRatio = sqrt((double)m_nGunHVTable[m_pIntegrated->nGunHVIndex] / (double)m_nGunHVTable[0]) / m_dOptionMagHVRatio[m_pIntegrated->nGunHVIndex];

		// 배율 설정하기
		AfxIntegratedSetMagnification(m_nMagStepValue[m_pIntegrated->nMagStepIndex], m_pIntegrated->nOLWD);
	}

}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 배율 x35k 이상 ZOOM 값 보정율 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
void AfxIntegratedSetMagx35kZoomRatio(double dMagx35kZoomRatio)
{
	// 배율 x35k 이상 ZOOM 값 보정율 설정
	m_dOptionMagx35kZoomRatio = dMagx35kZoomRatio;

}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 쓰레드 강제 종료 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
void AfxIntegratedSetThreadAllStopFlag(void)
{
	// SEM Scan Bridge Board
	if (m_bScanBridgeConnected == FALSE) return;
	// SEM Se Image Board
	if (m_bSemImageConnected == FALSE) return;

	// Scan Bridge 쓰레드
	m_pScanBridgeThreadParams->bThreadStop  = TRUE;         // 쓰레드 강제 종료 설정
	// SE Image Data 쓰레드
	m_pSEImageDataThreadParams->bThreadStop = TRUE;         // 쓰레드 강제 종료 설정
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 샘플 높이 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
void AfxIntegratedSetSampleHeight(double dSampleHeight)
{
	// 샘플높이
	m_dSampleHeight = dSampleHeight;
	m_pIntegrated->dScanOptionData[IDX_HWSETUP_OPTION_DOUBLE_SAMPLE_HEIGHT] = m_dSampleHeight;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 샘플 넓이 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
void AfxIntegratedSetSampleWidth(double dSampleWidth)
{
	// 샘플높이
	m_dSampleWidth = dSampleWidth;
	m_pIntegrated->dScanOptionData[IDX_HWSETUP_OPTION_DOUBLE_SAMPLE_WIDTH] = m_dSampleWidth;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 샘플 명칭 설정
/////////////////////////////////////////////////////////////////////////////////////////////////////
void AfxIntegratedSetSampleName(char *pSampleName)
{
	// 샘플명칭 : IDX_HWSETUP_OPTION_128TEXT_SAMPLE_NAME
	memset(m_pIntegrated->szScanOption128Text1, 0x00, sizeof(m_pIntegrated->szScanOption128Text1));
	strcpy(m_pIntegrated->szScanOption128Text1, pSampleName);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 샘플 높이 값 리턴
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxIntegratedGetSampleHeight(void)
{
	// 샘플높이
	return m_pIntegrated->dScanOptionData[IDX_HWSETUP_OPTION_DOUBLE_SAMPLE_HEIGHT];
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 샘플 넓이 값 리턴
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxIntegratedGetSampleWidth(void)
{
	// 샘플넓이
	return m_pIntegrated->dScanOptionData[IDX_HWSETUP_OPTION_DOUBLE_SAMPLE_WIDTH];
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 현재 배율값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedGetMagStepValue(void)
{
	// 현재 배율값
	return m_nMagStepValue[m_pIntegrated->nMagStepIndex];
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 현재 ZOOM X 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedGetZoomXValue(int nZoom, int nDegreex10)
{
	// 현재 ZOOM-X 값
	return m_pScanRotCaliData->nSRotRelayZoomXData[nZoom][nDegreex10 / 10];
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 현재 ZOOM Y 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedGetZoomYValue(int nZoom, int nDegreex10)
{
	// 현재 ZOOM-Y 값
	return m_pScanRotCaliData->nSRotRelayZoomYData[nZoom][nDegreex10 / 10];
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : 현재 배율 보정 비율 값
/////////////////////////////////////////////////////////////////////////////////////////////////////
double AfxIntegratedGetWDZoomRatioValue(void)
{
	// 현재 배율값
	return m_dWDZoomRatioBackup;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int AfxIntegratedAcSyncScanImageCaptureStart(int nAcSyncScanMode, BOOL bAcSyncFlag, int nFrameSync, double dFrameFreq, double dLineFreq)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;
	if (m_pSEImageDataThreadParams == NULL)return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 스캔모드
	int nSM = 0;
	if      (nAcSyncScanMode == 0) nSM = RED_SCAN_MODE;
	else if (nAcSyncScanMode == 1) nSM = FAST_SCAN_MODE;
	else if (nAcSyncScanMode == 2) nSM = SLOW1_SCAN_MODE;
	else if (nAcSyncScanMode == 3) nSM = SLOW2_SCAN_MODE;
	else if (nAcSyncScanMode == 4) nSM = PHOTO1_SCAN_MODE;
	else if (nAcSyncScanMode == 5) nSM = PHOTO2_SCAN_MODE;
	else if (nAcSyncScanMode == 6) nSM = PHOTO3_SCAN_MODE;
	else if (nAcSyncScanMode == 7) nSM = PHOTO4_SCAN_MODE;
	else if (nAcSyncScanMode == 8) nSM = PHOTO5_SCAN_MODE;
	else if (nAcSyncScanMode == 9) nSM = PHOTO6_SCAN_MODE;
	else return 0;

	// 스캔모드
	m_pIntegrated->nScanMode = nSM;

	// SE Image Data 스캔 허용 Flag 설정 ( STOP )
	m_pIntegrated->bScanDataReceive = FALSE;
	// SE Image Data Read Buffer Clear
	memset(m_pSEImageDataThreadParams->szFTReadBuf, 0x00, SCAN_IMAGE_PACKET_SIZE);

	// Avr에서 Afc 종료가 입력되지 않는 경우 때문에 
	m_pIntegrated->nAutoAvrActionState = AUTO_HALT_ST;
	// X,Y Image Pixel 갯수
	m_pIntegrated->nXBmpPixelVal   = m_pIntegrated->nXBmpPixel[nSM];
	m_pIntegrated->nYBmpPixelVal   = m_pIntegrated->nYBmpPixel[nSM];
	// X,Y Bitmap Offset
	m_pIntegrated->nXBmpOffsetVal  = m_pIntegrated->nXBmpOffset[nSM];
	m_pIntegrated->nYBmpOffsetVal  = m_pIntegrated->nYBmpOffset[nSM];
	// Bitmap 이미지 Average - Data 갯수
	m_pIntegrated->nWAverageNumVal = m_pIntegrated->nWAverageNum[nSM];

	// Weighted Average : Scan 이미지 Average 사용시 프레임당 비율설정
	// 사용예: 1번프레임의Pixel값을 1/3만사용, 2번프레임의Pixel값을 2/3만사용 하여 합산
	// WAFrameNum = 2 : 1,2     (1+2)     (1/3, 2/3)
	//              3 : 1,2,3   (1+2+3)   (1/6, 2/6, 3/6)
	//              4 : 1,2,3,4 (1+2+3+4) (1/10, 2/10,3/10,4/10)
	m_pIntegrated->nWAFrameNumA = 0;
	m_pIntegrated->nWAFrameNumB = 0;
	m_pIntegrated->bLineNumberFlag     = false;
	m_pIntegrated->bFirstButtonPressed = true;

	/////////////////////////////////////////////////////////////////////////////////////////////
	// Image Capture Start : Se Command 설정
	/////////////////////////////////////////////////////////////////////////////////////////////

	// 스캔모드에 따른 SeCommand를 설정하여 적용한다
	int nAcSyncSECommand = 0;

	// Capture Start/Stop Bit : D0 -> 1                          // D7~D4  D3~D0
	nAcSyncSECommand |= IMG_CAP_START_HIGH;                      // 0000   0001

	// Scan Mode 에 따른 Scan Size 설정
	if      (nSM == RED_SCAN_MODE   ) nAcSyncSECommand |= 0x10;  // 0001   0001
	else if (nSM == FAST_SCAN_MODE  ) nAcSyncSECommand |= 0x50;  // 0101   0001
	else if (nSM == SLOW1_SCAN_MODE ) nAcSyncSECommand |= 0x50;  // 0101   0001
	else if (nSM == SLOW2_SCAN_MODE ) nAcSyncSECommand |= 0x50;  // 0101   0001
	else if (nSM == PHOTO1_SCAN_MODE) nAcSyncSECommand |= 0x50;  // 0101   0001
	else if (nSM == PHOTO2_SCAN_MODE) nAcSyncSECommand |= 0x50;  // 0101   0001
	else if (nSM == PHOTO3_SCAN_MODE) nAcSyncSECommand |= 0x90;  // 1001   0001
	else if (nSM == PHOTO4_SCAN_MODE) nAcSyncSECommand |= 0x90;  // 1001   0001
	else if (nSM == PHOTO5_SCAN_MODE) nAcSyncSECommand |= 0x90;  // 1001   0001
	else if (nSM == PHOTO6_SCAN_MODE) nAcSyncSECommand |= 0xD0;  // 1101   0001

	// Se Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_OUTPORT, nAcSyncSECommand);
	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////////
	// Image Capture Start : Sbr Command 설정
	/////////////////////////////////////////////////////////////////////////////////////////////

	// 스캔모드에 따른 SeCommand를 설정하여 적용한다
	int nAcSyncSBRCommand = 0;

	// Capture Start/Stop Bit : D0 -> 1                             // D19~16  D15~12  D11~8   D7~4   D3~0
	nAcSyncSBRCommand |= IMG_CAP_START_HIGH;                        // 0000    0000    0000    0000   0001

	// FRAME SYNC or LINE SYNC 설정
	/*
	if      (nSM == RED_SCAN_MODE   ) nAcSyncSBRCommand |= 0x1000;  // 0000    0001    0000    0000   0000     <-- FRAME SYNC
	else if (nSM == FAST_SCAN_MODE  ) nAcSyncSBRCommand |= 0x1000;  // 0000    0001    0000    0000   0000     <-- FRAME SYNC
	else if (nSM == SLOW1_SCAN_MODE ) nAcSyncSBRCommand |= 0x0000;  // 0000    0000    0000    0000   0000     <-- LINE  SYNC
	else if (nSM == SLOW2_SCAN_MODE ) nAcSyncSBRCommand |= 0x0000;  // 0000    0000    0000    0000   0000     <-- LINE  SYNC
	else if (nSM == PHOTO1_SCAN_MODE) nAcSyncSBRCommand |= 0x0000;  // 0000    0000    0000    0000   0000     <-- LINE  SYNC
	else if (nSM == PHOTO2_SCAN_MODE) nAcSyncSBRCommand |= 0x0000;  // 0000    0000    0000    0000   0000     <-- LINE  SYNC
	else if (nSM == PHOTO3_SCAN_MODE) nAcSyncSBRCommand |= 0x0000;  // 0000    0000    0000    0000   0000     <-- LINE  SYNC
	else if (nSM == PHOTO4_SCAN_MODE) nAcSyncSBRCommand |= 0x0000;  // 0000    0000    0000    0000   0000     <-- LINE  SYNC
	else if (nSM == PHOTO5_SCAN_MODE) nAcSyncSBRCommand |= 0x0000;  // 0000    0000    0000    0000   0000     <-- LINE  SYNC
	else if (nSM == PHOTO6_SCAN_MODE) nAcSyncSBRCommand |= 0x0000;  // 0000    0000    0000    0000   0000     <-- LINE  SYNC
	*/
	// 2020.10.14
	if (nFrameSync == 1)
	{
		// FRAME SYNC                 // D19~16  D15~12  D11~8   D7~4   D3~0
		nAcSyncSBRCommand |= 0x1000;  // 0000    0001    0000    0000   0000     <-- FRAME SYNC
	}
	else
	{
		// LINE  SYNC                 // D19~16  D15~12  D11~8   D7~4   D3~0
		nAcSyncSBRCommand |= 0x0000;  // 0000    0000    0000    0000   0000     <-- LINE  SYNC
	}

	// 스캠모드에 따른 SYNC FREQ 설정 
    // SYNC_3_75HZ  0x000000   // 0 : 0000  0000 0000  0000 0000
    // SYNC_7_5HZ   0x010000   // 1 : 0001  0000 0000  0000 0000
    // SYNC_15HZ    0x020000   // 2 : 0010  0000 0000  0000 0000
    // SYNC_30HZ    0x030000   // 3 : 0011  0000 0000  0000 0000
    // 
    // SYNC_60HZ    0x040000   // 4 : 0100  0000 0000  0000 0000
    // SYNC_120HZ   0x050000   // 5 : 0101  0000 0000  0000 0000
    // SYNC_240HZ   0x060000   // 6 : 0110  0000 0000  0000 0000
    // SYNC_480HZ   0x070000   // 7 : 0111  0000 0000  0000 0000
    // 
    // SYNC_960HZ   0x080000   // 8 : 1000  0000 0000  0000 0000
    // SYNC_1920HZ  0x090000   // 9 : 1001  0000 0000  0000 0000
    // SYNC_3840HZ  0x0A0000   // A : 1010  0000 0000  0000 0000
	/*
	if      (nSM == RED_SCAN_MODE   ) nAcSyncSBRCommand |= 0x20000;  // 0010    0000    0000    0000   0000     <-- 15  [Hz]
	else if (nSM == FAST_SCAN_MODE  ) nAcSyncSBRCommand |= 0x10000;  // 0001    0000    0000    0000   0000     <-- 7.5 [Hz]
	else if (nSM == SLOW1_SCAN_MODE ) nAcSyncSBRCommand |= 0x60000;  // 0110    0000    0000    0000   0000     <-- 240 [Hz]
	else if (nSM == SLOW2_SCAN_MODE ) nAcSyncSBRCommand |= 0x40000;  // 0100    0000    0000    0000   0000     <-- 60  [Hz]
	else if (nSM == PHOTO1_SCAN_MODE) nAcSyncSBRCommand |= 0x30000;  // 0011    0000    0000    0000   0000     <-- 30  [Hz]
	else if (nSM == PHOTO2_SCAN_MODE) nAcSyncSBRCommand |= 0x20000;  // 0010    0000    0000    0000   0000     <-- 15  [Hz]
	else if (nSM == PHOTO3_SCAN_MODE) nAcSyncSBRCommand |= 0x30000;  // 0011    0000    0000    0000   0000     <-- 30  [Hz]
	else if (nSM == PHOTO4_SCAN_MODE) nAcSyncSBRCommand |= 0x20000;  // 0010    0000    0000    0000   0000     <-- 15  [Hz]
	else if (nSM == PHOTO5_SCAN_MODE) nAcSyncSBRCommand |= 0x10000;  // 0001    0000    0000    0000   0000     <-- 7.5 [Hz]
	else if (nSM == PHOTO6_SCAN_MODE) nAcSyncSBRCommand |= 0x20000;  // 0010    0000    0000    0000   0000     <-- 15  [Hz]
	*/
	// 2020.10.14
	if (nFrameSync == 1)
	{
		double dFrame = dFrameFreq * 100.0;
		int    nFrame = (int)dFrame;

		// FRAME SYNC                                            // D19~16  D15~12  D11~8   D7~4   D3~0
		if      (nFrame == 375 ) nAcSyncSBRCommand |= 0x000000;  // 0000    0000    0000    0000   0000     <-- 3.75 [Hz]
		else if (nFrame == 750 ) nAcSyncSBRCommand |= 0x010000;  // 0001    0000    0000    0000   0000     <-- 7.5  [Hz]
		else if (nFrame == 1500) nAcSyncSBRCommand |= 0x020000;  // 0010    0000    0000    0000   0000     <-- 15   [Hz]
		else if (nFrame == 3000) nAcSyncSBRCommand |= 0x030000;  // 0011    0000    0000    0000   0000     <-- 30   [Hz]
		else if (nFrame == 6000) nAcSyncSBRCommand |= 0x040000;  // 0100    0000    0000    0000   0000     <-- 60   [Hz]
		else                     nAcSyncSBRCommand |= 0x020000;  // 0010    0000    0000    0000   0000     <-- 15   [Hz]

	}
	else
	{
		double dLine = dLineFreq * 100.0;
		int    nLine = (int)dLine;

		// LINE  SYNC                                             // D19~16  D15~12  D11~8   D7~4   D3~0
		if      (nLine == 750   ) nAcSyncSBRCommand |= 0x010000;  // 0001    0000    0000    0000   0000     <-- 7.5  [Hz]
		else if (nLine == 1500  ) nAcSyncSBRCommand |= 0x020000;  // 0010    0000    0000    0000   0000     <-- 15   [Hz]
		else if (nLine == 3000  ) nAcSyncSBRCommand |= 0x030000;  // 0011    0000    0000    0000   0000     <-- 30   [Hz]
		else if (nLine == 6000  ) nAcSyncSBRCommand |= 0x040000;  // 0100    0000    0000    0000   0000     <-- 60   [Hz]
		else if (nLine == 12000 ) nAcSyncSBRCommand |= 0x050000;  // 0101    0000    0000    0000   0000     <-- 120  [Hz]
		else if (nLine == 24000 ) nAcSyncSBRCommand |= 0x060000;  // 0110    0000    0000    0000   0000     <-- 240  [Hz]
		else if (nLine == 48000 ) nAcSyncSBRCommand |= 0x070000;  // 0111    0000    0000    0000   0000     <-- 480  [Hz]
		else if (nLine == 96000 ) nAcSyncSBRCommand |= 0x080000;  // 1000    0000    0000    0000   0000     <-- 960  [Hz]
		else if (nLine == 192000) nAcSyncSBRCommand |= 0x090000;  // 1001    0000    0000    0000   0000     <-- 1920 [Hz]
		else if (nLine == 384000) nAcSyncSBRCommand |= 0x0A0000;  // 1010    0000    0000    0000   0000     <-- 3840 [Hz]
		else                      nAcSyncSBRCommand |= 0x020000;  // 0010    0000    0000    0000   0000     <-- 15   [Hz]
	}

	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////

	// AC SYNC ON/OFF 설정
	if (bAcSyncFlag == TRUE)
	{
		// Ac Sync On
		nAcSyncSBRCommand |= SYNC_SCAN_ON_HIGH;
	}
	else
	{
		// Ac Sync Off
		nAcSyncSBRCommand &= SYNC_SCAN_ON_LOW;
	}

	// Sbr Command 전송
	AfxFT232HPortSendCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, cWR_OUTPORT, nAcSyncSBRCommand);

	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////

	// SE Image Data Read Buffer Clear
	memset(m_pSEImageDataThreadParams->szFTReadBuf, 0x00, SCAN_IMAGE_PACKET_SIZE);
	// SE Image Data 스캔 허용 Flag 설정 ( START )
	m_pIntegrated->bScanDataReceive = TRUE;

	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////


	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Image Data Capture 작업 중지
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedAcSyncScanImageCaptureStop()
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// SE Image Data 스캔 허용 Flag 설정 ( STOP )
	m_pIntegrated->bScanDataReceive = FALSE;

	//---------------------------------------
	// SE Image Sampling Capture Stop
	//---------------------------------------
	m_pIntegrated->nSeCommandValue &= IMG_CAP_START_LOW;
	AfxFT232HPortSendCommand(IDX_FT232H_SEM_IMAGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSeCommandValue); // SE-Image Command 전송

	m_pIntegrated->nSbrCommandState &= IMG_CAP_START_LOW;
	AfxFT232HPortSendCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, cWR_OUTPORT, m_pIntegrated->nSbrCommandState); // Sbr Command 전송


	return RET_SUCCESS_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Generation (스캔모드에 따라 이미지 스캔을 위한 신호 생성)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedSetAcSyncScanGeneration(int nAcSyncScanMode, int nFrameSync, double dFrameFreq, int nScanSkip, int nOverSample, int nXScanUp, int nXScanDown, int nYScanUp, int nYScanDown, int nScanClock)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 스캔모드
	int nSM = 0;
	if      (nAcSyncScanMode == 0) nSM = RED_SCAN_MODE;
	else if (nAcSyncScanMode == 1) nSM = FAST_SCAN_MODE;
	else if (nAcSyncScanMode == 2) nSM = SLOW1_SCAN_MODE;
	else if (nAcSyncScanMode == 3) nSM = SLOW2_SCAN_MODE;
	else if (nAcSyncScanMode == 4) nSM = PHOTO1_SCAN_MODE;
	else if (nAcSyncScanMode == 5) nSM = PHOTO2_SCAN_MODE;
	else if (nAcSyncScanMode == 6) nSM = PHOTO3_SCAN_MODE;
	else if (nAcSyncScanMode == 7) nSM = PHOTO4_SCAN_MODE;
	else if (nAcSyncScanMode == 8) nSM = PHOTO5_SCAN_MODE;
	else if (nAcSyncScanMode == 9) nSM = PHOTO6_SCAN_MODE;
	else return 0;

	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////


	WORD wComBuf[TMP_STRING_LENGTH+1];
	int nAcSyncScanClock = 0;
	int nPhaseInc  = 0;

	// SCAN CLOCK [Hz] 계산
	// FRAME FREQ : 30[Hz], 15[Hz], 7.5[Hz], 3.75[Hz]...
	//double dFrame = (double)(nXScanUp + nXScanDown) * (double)(nYScanUp + nYScanDown) * dFrameFreq;

	// SCAN CLOCK [Hz]
	nAcSyncScanClock = nScanClock;

	///////////////////////////////////////////////////////////////////////////////////
	// 2021.07.29
	// SCAN CLOCK  ( 32Bits, 48MHz ) --> ( 48Bits, 100MHz) 로 변경하여 계산 적용
	///////////////////////////////////////////////////////////////////////////////////
	if (m_pIntegrated->nScanOptionData[IDX_HWSETUP_OPTION_INT_SCAN_CLOCK_48] == 1)
	{
		// SCAN CLOCK 48Bits, 100MHz
	    //--------------------------------------------------------------------------
	    // 2021.07.29
	    // 추가옵션사항 : ( ScanClk * 2^32 / 48[MHz] ) --> ( ScanClk * 2^48 / 100[MHz] )
	    //--------------------------------------------------------------------------
		__int64 nPhase_inc64 = 0;
	    nPhase_inc64 = (__int64)(nAcSyncScanClock * Exp2E48 / 100000000);
		wComBuf[0]  = cWR_FDDS_LOW;	      wComBuf[1] = (WORD)(nPhase_inc64 & 0x000000000000FFFF); nPhase_inc64 = nPhase_inc64 >> 16;
		wComBuf[2]  = cWR_FDDS_HIGH;      wComBuf[3] = (WORD)(nPhase_inc64 & 0x000000000000FFFF); nPhase_inc64 = nPhase_inc64 >> 16;
		wComBuf[4]  = cWR_FDDS_HIGH48;    wComBuf[5] = (WORD)(nPhase_inc64 & 0x000000000000FFFF);
	    //--------------------------------------------------------------------------
	    AfxFT232HPortSendMultiCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, wComBuf, 6); // Sbr Scan Clock Data 전송
	    //--------------------------------------------------------------------------
	}
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	else
	{
		// SCAN CLOCK 32Bits, 48MHz
		nPhaseInc = (int)(nAcSyncScanClock * Exp2E32 / PLL_SCAN_CLOCK);
		memset(wComBuf, 0x00, sizeof(wComBuf));
		//--------------------------------------------------------------------------
		wComBuf[0] = cWR_FDDS_LOW;      wComBuf[1] = nPhaseInc & 0x0000FFFF;
		wComBuf[2] = cWR_FDDS_HIGH;     wComBuf[3] = nPhaseInc >> 16;
		//--------------------------------------------------------------------------
		// SBR 명령 전송
		AfxFT232HPortSendMultiCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, wComBuf, 4);
		//--------------------------------------------------------------------------
	}
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	memset(wComBuf, 0x00, sizeof(wComBuf));
	//--------------------------------------------------------------------------
	wComBuf[0] = cOS_NUM_LOAD;      wComBuf[1] = nOverSample;
	wComBuf[2] = cSKIP_NUM_LOAD;    wComBuf[3] = nScanSkip;
	// Smg 명령 전송
	AfxFT232HPortSendMultiCommand(IDX_FT232H_SEM_IMAGE_DEVICE, wComBuf, 4);
	//--------------------------------------------------------------------------


	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------

	int nIncVal    = 0;
	int nIncHeight = 0;
	int nLowVal    = 0;
	int nHighVal   = 0;
	int nDecVal    = 0;

	memset(wComBuf, 0x00, sizeof(wComBuf));

	//--------------------------------------------------------------------------
	// XScan 기본파형 발생
	//--------------------------------------------------------------------------
	if (nXScanUp > 0 && nXScanDown > 0)
	{
		nIncVal    = (4096   / nXScanUp);
		nIncHeight = nIncVal * nXScanUp;
		nLowVal    = (4096 - nIncHeight) / 2;
		nHighVal   = (4096 - nLowVal);
		nDecVal    = nIncHeight / nXScanDown;
	}

	wComBuf[0]  = cWR_XSCAN_LOW;       wComBuf[1]  = nLowVal;
	wComBuf[2]  = cWR_XSCAN_HIGH;      wComBuf[3]  = nHighVal;
	wComBuf[4]  = cWR_XSCAN_INC_VAL;   wComBuf[5]  = nIncVal;
	wComBuf[6]  = cWR_XSCAN_DEC_VAL;   wComBuf[7]  = nDecVal;
	wComBuf[8]  = cWR_XSCAN_INC_PIX;   wComBuf[9]  = nXScanUp;
	wComBuf[10] = cWR_XSCAN_DEC_PIX;   wComBuf[11] = nXScanDown;
	//--------------------------------------------------------------------------

	nIncVal    = 0;
	nIncHeight = 0;
	nLowVal    = 0;
	nHighVal   = 0;
	nDecVal    = 0;
	//--------------------------------------------------------------------------
	// YScan 기본파형 발생
	//--------------------------------------------------------------------------
	if (nYScanUp > 0 && nYScanDown > 0)
	{
		nIncVal    = (4096   / nYScanUp);
		nIncHeight = nIncVal * nYScanUp;
		nLowVal    = (4096 - nIncHeight) / 2;
		nHighVal   = (4096 - nLowVal);
		nDecVal    = nIncHeight / nYScanDown;
	}

	wComBuf[12] = cWR_YSCAN_LOW;       wComBuf[13] = nLowVal;
	wComBuf[14] = cWR_YSCAN_HIGH;      wComBuf[15] = nHighVal;
	wComBuf[16] = cWR_YSCAN_INC_VAL;   wComBuf[17] = nIncVal;
	wComBuf[18] = cWR_YSCAN_DEC_VAL;   wComBuf[19] = nDecVal;
	wComBuf[20] = cWR_YSCAN_INC_PIX;   wComBuf[21] = nYScanUp;
	wComBuf[22] = cWR_YSCAN_DEC_PIX;   wComBuf[23] = nYScanDown;  //  128
	//--------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	// SBR 명령 전송
	AfxFT232HPortSendMultiCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, wComBuf, 24);
	//--------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	// X, YScan의 Amplitude 와 Offset 설정 ( "SR6","SR7","SR8","SR9" )
	//--------------------------------------------------------------------------
	AfxScanBridgeSetXImageAmpApply(m_pIntegrated->nXScanAmpVal[nSM]);     // XScanAmp
	AfxScanBridgeSetXImageOffsetApply(m_pIntegrated->nXScanOffset[nSM]);  // XScanOffset
	AfxScanBridgeSetYImageAmpApply(m_pIntegrated->nYScanAmpVal[nSM]);     // YScanAmp
	AfxScanBridgeSetYImageOffsetApply(m_pIntegrated->nYScanOffset[nSM]);  // YScanOffset
	//--------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------

	return RET_SUCCESS_OK;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Integrated Control : Scan Generation 초기화 (스캔신호 OFF)
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedResetAcSyncScanGeneration(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	WORD wComBuf[TMP_STRING_LENGTH + 1];

	memset(wComBuf, 0x00, sizeof(wComBuf));
	//--------------------------------------------------------------------------
	wComBuf[0] = cWR_FDDS_LOW;      wComBuf[1] = 0;
	wComBuf[2] = cWR_FDDS_HIGH;     wComBuf[3] = 0;
	//--------------------------------------------------------------------------
	// SBR 명령 전송
	AfxFT232HPortSendMultiCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, wComBuf, 4);
	//--------------------------------------------------------------------------

	memset(wComBuf, 0x00, sizeof(wComBuf));
	//--------------------------------------------------------------------------
	wComBuf[0] = cOS_NUM_LOAD;      wComBuf[1] = 0;
	wComBuf[2] = cSKIP_NUM_LOAD;    wComBuf[3] = 0;
	// Smg 명령 전송
	AfxFT232HPortSendMultiCommand(IDX_FT232H_SEM_IMAGE_DEVICE, wComBuf, 4);
	//--------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------

	memset(wComBuf, 0x00, sizeof(wComBuf));

	//--------------------------------------------------------------------------
	// XScan 기본파형 발생
	//--------------------------------------------------------------------------
	wComBuf[0]  = cWR_XSCAN_LOW;       wComBuf[1]  = 0;
	wComBuf[2]  = cWR_XSCAN_HIGH;      wComBuf[3]  = 0;
	wComBuf[4]  = cWR_XSCAN_INC_VAL;   wComBuf[5]  = 0;
	wComBuf[6]  = cWR_XSCAN_DEC_VAL;   wComBuf[7]  = 0;
	wComBuf[8]  = cWR_XSCAN_INC_PIX;   wComBuf[9]  = 0;
	wComBuf[10] = cWR_XSCAN_DEC_PIX;   wComBuf[11] = 0;
	//--------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	// YScan 기본파형 발생
	//--------------------------------------------------------------------------
	wComBuf[12] = cWR_YSCAN_LOW;       wComBuf[13] = 0;
	wComBuf[14] = cWR_YSCAN_HIGH;      wComBuf[15] = 0;
	wComBuf[16] = cWR_YSCAN_INC_VAL;   wComBuf[17] = 0;
	wComBuf[18] = cWR_YSCAN_DEC_VAL;   wComBuf[19] = 0;
	wComBuf[20] = cWR_YSCAN_INC_PIX;   wComBuf[21] = 0;
	wComBuf[22] = cWR_YSCAN_DEC_PIX;   wComBuf[23] = 0;
	//--------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	// SBR 명령 전송
	AfxFT232HPortSendMultiCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, wComBuf, 24);
	//--------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	// X, YScan의 Amplitude 와 Offset 설정 ( "SR6","SR7","SR8","SR9" )
	//--------------------------------------------------------------------------
	AfxScanBridgeSetXImageAmpApply(0);        // "SR6" : XScanAmp
	AfxScanBridgeSetXImageOffsetApply(2048);  // "SR7" : XScanOffset
	AfxScanBridgeSetYImageAmpApply(0);        // "SR8" : YScanAmp
	AfxScanBridgeSetYImageOffsetApply(2048);  // "SR9" : YScanOffset
	//--------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------

	return RET_SUCCESS_OK;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// 2021.06.15
/////////////////////////////////////////////////////////////////////////////////////////////////////
// FOCUS DEGAUSSING 처리 쓰레드 생성
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxCreateFocusDegaussingThread(int nWDPos, int nCoarse, int nFine, int nProcessTime)
{
	// FOCUS DEGAUSSING 쓰레드 사용 중이면...
	if (m_pFocusDegaussingThread != NULL)
	{
		// FOCUS DEGAUSSING 쓰레드 파라메터 사용 중인지 확인
		if (m_pFocusDegaussingThreadParams != NULL)
		{
			// FOCUS DEGAUSSING 쓰레드 종료 확인
			if (m_pFocusDegaussingThreadParams->bThreadDone == TRUE)
			{
				// 2021.05.31
				// 쓰레드 종료 됨, 삭제
				// FOCUS DEGAUSSING 쓰레드에서 사용한 파라메터 삭제
				delete m_pFocusDegaussingThreadParams;
				m_pFocusDegaussingThreadParams = NULL;
			}
			else
			{
				// 쓰레드 동작 중, 리턴
				return RET_SUCCESS_OK;
			}
		}
		//return RET_SUCCESS_OK;
	}

	// FOCUS DEGAUSSING 쓰레드 파라메터 사용 중인지 확인
	if (m_pFocusDegaussingThreadParams != NULL)
	{
		// FOCUS DEGAUSSING 쓰레드에서 사용한 파라메터 삭제
		delete m_pFocusDegaussingThreadParams;
		m_pFocusDegaussingThreadParams = NULL;
	}

	// FOCUS DEGAUSSING 쓰레드에서 사용할 파라메터를 생성한다
	m_pFocusDegaussingThreadParams = new FOCUSDEGAUSSINGTHREADPARAMS;
	if (m_pFocusDegaussingThreadParams == NULL) return RET_ERROR_SBR_THREAD_PARAMS;
	memset(m_pFocusDegaussingThreadParams, 0x00, sizeof(FOCUSDEGAUSSINGTHREADPARAMS));
	// FOCUS DEGAUSSING 쓰레드에서 사용할 파라메터 기본값 설정
	m_pFocusDegaussingThreadParams->bThreadDone  = FALSE;        // 쓰레드 종료 설정
	m_pFocusDegaussingThreadParams->bThreadStop  = FALSE;        // 쓰레드 강제 종료
	m_pFocusDegaussingThreadParams->nFT232HIndex = IDX_FT232H_SEM_IMAGE_DEVICE; // Scan Image 장치 인덱스
	m_pFocusDegaussingThreadParams->hFT232Handle = NULL;         // Scan Bridge 장치 핸들
	m_pFocusDegaussingThreadParams->hEventHandle = NULL;         // Scan Bridge 이벤트 핸들
	////////////////////////////////////////////////////////////////////////////////////////////////////
	m_pFocusDegaussingThreadParams->nWDPosition  = nWDPos;       // FOCUS DEGAUSSING : Z AXIS WD POSITION
	m_pFocusDegaussingThreadParams->nFocusCoarse = nCoarse;      // FOCUS DEGAUSSING : FOCUS COARSE VALUE
	m_pFocusDegaussingThreadParams->nFocusFine   = nFine;        // FOCUS DEGAUSSING : FOCUS FINE   VALUE
	m_pFocusDegaussingThreadParams->nProcessTime = nProcessTime; // FOCUS DEGAUSSING : PROCESS TIME
	////////////////////////////////////////////////////////////////////////////////////////////////////

	// 핸들 설정
	FT_HANDLE ft232hHandle = AfxFT232HGetHandle(m_pFocusDegaussingThreadParams->nFT232HIndex);
	if (ft232hHandle == NULL) return RET_ERROR_FT232H_SBR_HANDLE;
	m_pFocusDegaussingThreadParams->hFT232Handle = ft232hHandle; // FOCUS DEGAUSSING 장치 핸들

	// FOCUS DEGAUSSING 쓰레드 생성 및 시작...
	m_pFocusDegaussingThread = AfxBeginThread(AfxThreadFocusDegaussingProcessing, m_pFocusDegaussingThreadParams);
	if (m_pFocusDegaussingThread == NULL) return RET_ERROR_SBR_THREAD_HANDLE;

	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// FOCUS DEGAUSSING 처리(작업) 쓰레드
/////////////////////////////////////////////////////////////////////////////////////////////////////
UINT AfxThreadFocusDegaussingProcessing(LPVOID pParams)
{
	LPFOCUSDEGAUSSINGTHREADPARAMS pThreadParams = (LPFOCUSDEGAUSSINGTHREADPARAMS)pParams;

	int  nFocusJumpStep = 10;
	int  nProcessStep   = 0;
	int  nFocusCoarse   = 0;
	int  nFocusFine     = 0;
	int  nIntervalTime  = 0;
	int  nProcessTime   = 0;
	int  nWDPosition    = 0;
	BOOL bbThreadDone   = FALSE;

	if (pThreadParams == NULL) return 0;

	// 쓰레드 작업 상태 설정
	pThreadParams->bThreadDone = FALSE;
	pThreadParams->bThreadStop = FALSE;
	bbThreadDone = pThreadParams->bThreadDone;
	// 작업시간 설정
	nProcessTime  = pThreadParams->nProcessTime;
	nWDPosition   = pThreadParams->nWDPosition;
	nFocusCoarse  = pThreadParams->nFocusCoarse;
	nFocusFine    = pThreadParams->nFocusFine;
	// 처리횟수 = OCUS COARSE / FOCUS 점프스텝
	nProcessStep  = nFocusCoarse / nFocusJumpStep;
	// INTERVAL TIME = 총처리시간 / 총처리횟수
	double dTime  = (double)nProcessTime;
	double dStep  = (double)nProcessStep;
	double dIntv  = (dTime / dStep) + 0.5;
	nIntervalTime = (int)dIntv;
	if (nIntervalTime < 1) nIntervalTime = 1;

	//---------------------------------------------------------------
	//  FocusFine 값의 변화 범위가 0 - 128 이므로, 최하의
	//  0 값 근처에서, OP-Amp의 오프셋 때문에 변화가 없을 수 있으므로
	//  중간값에서 변화되도록 변화시킴
	//---------------------------------------------------------------
	// Fine 값은 2048 +/- 128 이다
	//---------------------------------------------------------------
	// Fine 값 설정
	int nFine = pThreadParams->nFocusFine;
	// FOCUS FINE 값이 변경 되었는지 확인한다.
	if (nFine < SEM_FOCUS_FINE_MIN) nFine = SEM_FOCUS_FINE_MIN;
	if (nFine > SEM_FOCUS_FINE_MAX) nFine = SEM_FOCUS_FINE_MAX;
	// Smg Command 전송
	AfxFT232HPortSendCommand(pThreadParams->nFT232HIndex, cWR_AD5361, AD5361_OLF + (2048 - 128 + nFine << 4));

	/////////////////////////////////////////////////////////////////////////////////////////////////
	// FOCUS DEGAUSSING 쓰레드 프로세싱
	/////////////////////////////////////////////////////////////////////////////////////////////////
	BOOL bLoop = TRUE;
	int  nCoarse = SEM_FOCUS_COARSE_MIN;
	while (bLoop == TRUE)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////
		// FOCUS DEGAUSSING 순차적 처리
		/////////////////////////////////////////////////////////////////////////////////////////////
		// FOCUS COARSE 값 확인한다.
		if (nCoarse >= nFocusCoarse)
		{
			// 마지막 작업설정 및 LOOP 종료
			nCoarse = nFocusCoarse;
			bLoop = FALSE;
		}

		// Focus Coarse 값 USB 설정
		// Smg Command 전송
		AfxFT232HPortSendCommand(pThreadParams->nFT232HIndex, cWR_AD5361, AD5361_OLC + (nCoarse + 4096 << 3));

		// FOCUS COARSE 값 증가
		nCoarse += nFocusJumpStep;

		if (bLoop == TRUE)
		{
			// 강제종료 CHECK?
			if (pThreadParams->bThreadStop == TRUE)
			{
				// 쓰레드 종료
				bLoop = FALSE;
			}
			else
			{
				// 인터벌 타임[ms] 대기
				Sleep(nIntervalTime);
			}
		}
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////
	// 쓰레드 종료 확인
	if (pThreadParams != NULL)
	{
		pThreadParams->bThreadDone = TRUE;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////

	// WD 값이 변동 있으면 WD에 따른 FOCUS COARSE 실행한다
	AfxIntegratedSetWDAutoAdjustFocusCoarse(nWDPosition); // 새로운 WD 적용
	AfxScanBridgeSetScanRotation(nWDPosition);            // WD에 따른 배율조정을 위한 Scan Rotation 실행

	// FOCUS COARSE, FINE 재설정
	m_pIntegrated->nFocusOldCoarse = SEM_FOCUS_COARSE_STR;
	m_pIntegrated->nFocusOldFine   = 1;
	AfxIntegratedSetOL(nFocusCoarse, nFocusFine);

	// 2021.07.22
	// FOCUS CONTROL DIALOG에서 FOCUS COARSE를 실행한다
	USB_DEVICE_DATA_INFO UsbDeviceDataInfo;
	memset(&UsbDeviceDataInfo, 0x00, sizeof(USB_DEVICE_DATA_INFO));

	// 전송자료
	UsbDeviceDataInfo.nState   = 1; // FOCUS COARSE 값
	UsbDeviceDataInfo.nData[0] = nFocusCoarse;
	UsbDeviceDataInfo.nData[1] = nFocusFine;

	if (m_hOwnerWnd != NULL)
	{
		// 2021.07.22
		// FOCUS CONTROL DIALOG에서 FOCUS COARSE를 실행한다
		SendMessage(m_hOwnerWnd, UM_USB_SBR_FOCUS_COARSE_DATA_EXECUTE, NULL, (LPARAM)&UsbDeviceDataInfo);
	}

	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Z-AXIS(WD)에 따른 FOCUS DEGAUSSING 실행 : 0~500 , 0~50.0mm
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxIntegratedFocusDegaussing(int nWDPos, int nRunTime)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;

	// 2021.06.15
	// WD 값에 따른 FOCUS DEGAUSSING 실행
	int nOLWD = nWDPos;
	if (nOLWD < 40)  nOLWD = 40;  // 4 [mm]
	if (nOLWD > 500) nOLWD = 500; // 50[mm]

	// 실행(소요)시간 : 500[ms]
	int nProcessTime = nRunTime;
	if (nProcessTime < 500) nProcessTime = 500;

	// FOCUS COARSE 에 해당 하는 DEGAUSSING 실행
	int nFocusCoarse = m_pIntegrated->nWDOLCoarseLinear[nOLWD];
	// DEGAUSSING : COARSE / FINE / PROCESS TIME[ms]
	AfxCreateFocusDegaussingThread(nOLWD, nFocusCoarse, SEM_FOCUS_FINE_STR, nProcessTime);

	return RET_SUCCESS_OK;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : ANGLE VALVE OFF
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetAngleValveOff(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	char szCom[255 + 1];

	// 2021.09.09 : Angle Valve Off
	memset(szCom, 0x00, sizeof(szCom));
	//strcpy_s(szCom, "VL9,0;");
	strcpy_s(szCom, "VL13,0;");
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom); // Sbr Command


	// Air-Off ( Evac ) -> (상태 : 진공 진행중...)
	// SB : Set Exchange Sample Position Pulse 으로 변경
	//memset(szCom, 0x00, sizeof(szCom));
	//strcpy_s(szCom, "AR0,0;"); // ScanBridgeBoard -> VacBoard
	//AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom);
	//memset(szCom, 0x00, sizeof(szCom));
	//strcpy_s(szCom, "SB1,0;"); // ScanBridgeBoard -> CncVacBoard (EM40)
	//AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom);

	// TP NW16 Angle Value On/Off 설정 및 실행하기
	// VacBoard -> PC -> To CncBoard
	//memset(szCom, 0x00, sizeof(szCom));
	//strcpy_s(szCom, "RA3,0;");
	//AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom);

	// Extra NW16 Angle Value On/Off 설정 및 실행하기
	// VacBoard -> PC -> To CncBoard
	//memset(szCom, 0x00, sizeof(szCom));
	//strcpy_s(szCom, "RA4,0;");
	//AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom);


	return RET_SUCCESS_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scan Bridge : ANGLE VALVE ON
/////////////////////////////////////////////////////////////////////////////////////////////////////
int AfxSetAngleValveOn(void)
{
	if (m_pIntegrated == NULL) return RET_ERROR_INTEGRATED_COMMAND_HANDLE;  // Integrated Command & Data Handle

	char szCom[255 + 1];

	// 2021.09.09 : Angle Valve On
	memset(szCom, 0x00, sizeof(szCom));
	//strcpy_s(szCom, "VL12,0;");
	strcpy_s(szCom, "VL13,1;");
	AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom); // Sbr Command


	// Air-On -> (상태 : SEM 대기상태...)
	// SB : Set Exchange Sample Position Pulse 으로 변경
	//memset(szCom, 0x00, sizeof(szCom));
	//strcpy_s(szCom, "AR0,1;"); // ScanBridgeBoard -> VacBoard
	//AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom);
	//memset(szCom, 0x00, sizeof(szCom));
	//strcpy_s(szCom, "SB1,1;"); // ScanBridgeBoard -> CncVacBoard (EM40)
	//AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom);

	// TP NW16 Angle Value On/Off 설정 및 실행하기
	// VacBoard -> PC -> To CncBoard
	//strcpy_s(szCom, "RA3,1;");
	//AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom);

	// Extra NW16 Angle Value On/Off 설정 및 실행하기
	// VacBoard -> PC -> To CncBoard
	//strcpy_s(szCom, "RA4,1;");
	//AfxFT232HPortSendAvrCommand(IDX_FT232H_SCAN_BRIDGE_DEVICE, szCom);


	return RET_SUCCESS_OK;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



