
#ifndef _SKAPI_3CEE4EC1_9301_4bb4_9C5C_56997A8B59E2_H
#define _SKAPI_3CEE4EC1_9301_4bb4_9C5C_56997A8B59E2_H

#if WINVER < 0x0500
#undef WINVER
#define WINVER 0x0500
#pragma message( "如果使用了STDAFX.H, 请在STDAFX.H前面定义WINVER为0x0500" )
#endif

#include <Windows.h>

#define KM_DRIVER 0
#define KM_HID 1
#define KM_AUTO -1

#define LED_OFF     0
#define LED_ON      1
//#define LED_BLINK   2  //not support by now

#define SK_DRIVERLESS 0
#define SK_DRIVER     1

#define PASSWORD_TYPE_WRITE 0
#define PASSWORD_TYPE_READ  1

typedef struct _sk_init_data_ {
    UINT cbSize;
	UINT sdkVersion;
	UINT KeyMode;            
	BOOL bUseSessionKey;
	UINT Reserved[4];
}SKI, *PSKI;

#ifdef __cplusplus
extern "C" {
#endif

BOOL    WINAPI SK_Init(PSKI pInitData);
HANDLE  WINAPI SK_Open(unsigned short CustomerId, char *szPath);
HANDLE  WINAPI SK_OpenByPath(char * szPath);
void    WINAPI SK_Close(HANDLE hKey);
/////////////////////////////////////////////
BOOL    WINAPI SK_Query(HANDLE hKey, DWORD Size, char * Input, char * Output);
BOOL    WINAPI SK_CheckSum(HANDLE hKey, char * Buffer, int Length, DWORD* CheckSum32);
BOOL    WINAPI SK_GetRandom32(HANDLE hKey, DWORD * dwRandom);
/////////////////////////////////////////////
BOOL   	WINAPI SK_GetSerial(HANDLE hKey, char *Buffer, int BufferSize);
BOOL   	WINAPI SK_GetPublicSize(HANDLE hKey,  DWORD *ZoneSize);
BOOL   	WINAPI SK_GetProtectSize(HANDLE hKey,  DWORD *ZoneSize);
BOOL    WINAPI SK_GetDriverMemorySize(HANDLE hKey, DWORD * cbMaxSize);
/////////////////////////////////////////////
BOOL   	WINAPI SK_ReadPublicMemory(HANDLE hKey, int Index, char *Buffer, int BufferSize);
BOOL   	WINAPI SK_ReadProtectMemory(HANDLE hKey, DWORD Password, int Index, char *Buffer, int BufferSize);
BOOL    WINAPI SK_ReadDriverMemory(HANDLE hKey, int Index, char * Buffer, int cbLength );
/////////////////////////////////////////////
BOOL   	WINAPI SK_WritePublicMemory(HANDLE hKey, int Index, char *Buffer, int BufferSize);
BOOL   	WINAPI SK_WriteProtectMemory(HANDLE hKey, DWORD Password, int Index, char *Buffer, int BufferSize);
BOOL    WINAPI SK_WriteDriverMemory(HANDLE hKey, int Index, char * Buffer, int cbLength );
/////////////////////////////////////////////
BOOL    WINAPI SK_ChangeLED(HANDLE hKey, DWORD LED_State);
BOOL   	WINAPI SK_ChangeMode(HANDLE hKey, int KeyMode);
BOOL   	WINAPI SK_ChangePassword(HANDLE hKey, DWORD Password,  DWORD NewPassword, DWORD PasswordType);
/////////////////////////////////////////////
HANDLE  WINAPI SK_RegisterPnpMessage(HANDLE hRecipient, unsigned short  UserID);
BOOL    WINAPI SK_UnregisterPnpNotification(HANDLE hNotify);
BOOL    WINAPI SK_IsMyDevice(LPCTSTR szDevicePath, WORD UserId);
BOOL    WINAPI SK_InstallDriver(LPCTSTR InfFileName, WORD UserId);
DWORD   WINAPI SK_GetLastError();

#ifdef __cplusplus
}
#endif

#ifdef _SKRTL_DLL_

typedef BOOL    (WINAPI *pSK_Init) (PSKI pInitData);
typedef HANDLE  (WINAPI *pSK_Open) (unsigned short CustomerId,char *szPath);
typedef HANDLE  (WINAPI *pSK_OpenByPath)(char * szPath);
typedef void    (WINAPI *pSK_Close) (HANDLE hKey);
typedef BOOL    (WINAPI *pSK_Query) (HANDLE hKey, DWORD Size, char * Input, char * Output);
typedef BOOL    (WINAPI *pSK_CheckSum) (HANDLE hKey, char * Buffer, int Length, DWORD* CheckSum32);
typedef BOOL    (WINAPI *pSK_GetRandom32) (HANDLE hKey, DWORD * dwRandom);
typedef BOOL    (WINAPI *pSK_GetSerial) (HANDLE hKey, char *Buffer, int BufferSize);
typedef BOOL    (WINAPI *pSK_GetPublicSize) (HANDLE hKey,  DWORD *ZoneSize);
typedef BOOL    (WINAPI *pSK_GetProtectSize) (HANDLE hKey,  DWORD *ZoneSize);
typedef BOOL    (WINAPI *pSK_ReadPublicMemory) (HANDLE hKey, int Index, char *Buffer, int BufferSize);
typedef BOOL    (WINAPI *pSK_WritePublicMemory) (HANDLE hKey, int Index, char *Buffer, int BufferSize);
typedef BOOL    (WINAPI *pSK_ReadProtectMemory) (HANDLE hKey, DWORD Password, int Index, char *Buffer, int BufferSize);
typedef BOOL    (WINAPI *pSK_WriteProtectMemory) (HANDLE hKey, DWORD Password, int Index, char *Buffer, int BufferSize);
typedef BOOL    (WINAPI *pSK_ChangeLED) (HANDLE hKey, DWORD LED_State);
typedef BOOL    (WINAPI *pSK_ChangeMode) (HANDLE hKey, int KeyMode);
typedef BOOL    (WINAPI *pSK_ChangePassword) (HANDLE hKey, DWORD Password,  DWORD NewPassword, DWORD PasswordType);
typedef BOOL    (WINAPI *pSK_GetDriverMemorySize) (HANDLE hKey, DWORD * cbMaxSize);
typedef BOOL    (WINAPI *pSK_ReadDriverMemory) (HANDLE hKey, int Index, char * Buffer, int cbLength );
typedef BOOL    (WINAPI *pSK_WriteDriverMemory) (HANDLE hKey, int Index, char * Buffer, int cbLength );
typedef HANDLE  (WINAPI *pSK_RegisterPnpMessage) (HANDLE hRecipient, unsigned short  UserID);
typedef BOOL    (WINAPI *pSK_UnregisterPnpNotification) (HANDLE hNotify);
typedef BOOL    (WINAPI *pSK_IsMyDevice) (LPCTSTR szDevicePath, WORD UserId);
typedef DWORD   (WINAPI *pSK_GetLastError) ();
typedef BOOL    (WINAPI *pSK_InstallDriver) (LPCTSTR InfFileName, WORD UserId);

typedef struct
{
	ULONG cbSize;
	pSK_Init SK_Init;
	pSK_Open SK_Open;
	pSK_OpenByPath SK_OpenByPath;
	pSK_Close SK_Close;
	pSK_Query SK_Query;
	pSK_CheckSum SK_CheckSum;
	pSK_GetRandom32 SK_GetRandom32;
	pSK_GetSerial SK_GetSerial;
	pSK_GetPublicSize SK_GetPublicSize;
	pSK_GetProtectSize SK_GetProtectSize;
	pSK_ReadPublicMemory SK_ReadPublicMemory;
	pSK_WritePublicMemory SK_WritePublicMemory;
	pSK_ReadProtectMemory SK_ReadProtectMemory;
	pSK_WriteProtectMemory SK_WriteProtectMemory;
	pSK_ChangeLED SK_ChangeLED;
	pSK_ChangeMode SK_ChangeMode;
	pSK_ChangePassword SK_ChangePassword;
	pSK_GetDriverMemorySize SK_GetDriverMemorySize;
	pSK_ReadDriverMemory SK_ReadDriverMemory;
	pSK_WriteDriverMemory SK_WriteDriverMemory;
	pSK_RegisterPnpMessage SK_RegisterPnpMessage;
	pSK_UnregisterPnpNotification SK_UnregisterPnpNotification;
	pSK_IsMyDevice SK_IsMyDevice;
	pSK_GetLastError SK_GetLastError;
	pSK_InstallDriver SK_InstallDriver;
	
}SKDLL_FUNCTIONS, *PSKDLL_FUNCTIONS;

bool WINAPI DllGetClassObject(PSKDLL_FUNCTIONS p);
typedef bool (WINAPI *fpDllGetClassObject)(PSKDLL_FUNCTIONS p);
#endif

#endif