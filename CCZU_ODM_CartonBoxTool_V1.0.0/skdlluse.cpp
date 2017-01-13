
#include "stdafx.h"

#pragma hdrstop

#define _SKRTL_DLL_
#include "skapi.h"

#ifndef _SKRTL_DLL_
#pragma message("now use sk static lib to link")
#pragma comment(lib, "skbcblib.lib")
#endif

#ifdef _SKRTL_DLL_
#pragma message("now use sk dynamic lib to link")
static SKDLL_FUNCTIONS gThunk = {0};

static BOOL CheckDll()
{
	static bool rc = false;
	
	if(!rc)
	{
		gThunk.cbSize = sizeof(SKDLL_FUNCTIONS);
		HINSTANCE hLib = LoadLibrary("skrtl.dll");
	
		if(hLib)
		{
			fpDllGetClassObject fnDllGetClassObject;
			fnDllGetClassObject = (fpDllGetClassObject)GetProcAddress(hLib, "DllGetClassObject");
		
			if(fnDllGetClassObject)
				if(true == fnDllGetClassObject(&gThunk))
					rc = true;
		}
	}
	return rc;	
}

BOOL WINAPI SK_Init(PSKI pInitData)
{
	if(CheckDll())
		return gThunk.SK_Init(pInitData);
	return false;		
}

HANDLE WINAPI SK_Open(unsigned short UserID, char *szPath)
{
	if(CheckDll())
		return gThunk.SK_Open(UserID, szPath);
	return INVALID_HANDLE_VALUE;		
}

HANDLE  WINAPI SK_OpenByPath(char * szPath)
{
	if(CheckDll())
		return gThunk.SK_OpenByPath(szPath);
	return INVALID_HANDLE_VALUE;		
}

void   WINAPI SK_Close(HANDLE hKey)
{
	if(CheckDll())
		gThunk.SK_Close(hKey);
}

BOOL   WINAPI SK_Query(HANDLE hKey, DWORD Size, char * Input, char * Output)
{
	if(CheckDll())
		return gThunk.SK_Query(hKey, Size, Input, Output);
	return false;		
}

BOOL   WINAPI SK_CheckSum(HANDLE hKey, char * Buffer, int Length, DWORD* CheckSum32)
{
	if(CheckDll())
		return gThunk.SK_CheckSum(hKey, Buffer,Length, CheckSum32);
	return false;			
}

BOOL   WINAPI SK_GetRandom32(HANDLE hKey, DWORD * dwRandom)
{
	if(CheckDll())
		return gThunk.SK_GetRandom32(hKey, dwRandom);
	return false;			
}

BOOL   	WINAPI SK_GetSerial(HANDLE hKey, char *Buffer, int BufferSize)
{
	if(CheckDll())
		return gThunk.SK_GetSerial( hKey, Buffer, BufferSize);
	return false;			

}

BOOL   	WINAPI SK_GetPublicSize(HANDLE hKey,  DWORD *ZoneSize)
{
	if(CheckDll())
		return gThunk.SK_GetPublicSize( hKey,  ZoneSize);
	return false;			

}

BOOL   	WINAPI SK_GetProtectSize(HANDLE hKey,  DWORD *ZoneSize)
{
	if(CheckDll())
		return gThunk.SK_GetProtectSize( hKey,  ZoneSize);
	return false;			
	
}

BOOL   	WINAPI SK_ReadPublicMemory(HANDLE hKey, int Index, char *Buffer, int BufferSize)
{
	if(CheckDll())
		return gThunk.SK_ReadPublicMemory( hKey, Index, Buffer, BufferSize);
	return false;	
}

BOOL   	WINAPI SK_WritePublicMemory(HANDLE hKey, int Index, char *Buffer, int BufferSize)
{
	if(CheckDll())
		return gThunk.SK_WritePublicMemory( hKey, Index, Buffer, BufferSize);
	return false;	
}

BOOL   	WINAPI SK_ReadProtectMemory(HANDLE hKey, DWORD Password, int Index, char *Buffer, int BufferSize)
{
	if(CheckDll())
		return gThunk.SK_ReadProtectMemory( hKey, Password, Index, Buffer, BufferSize);
	return false;	
}
BOOL   	WINAPI SK_WriteProtectMemory(HANDLE hKey, DWORD Password, int Index, char *Buffer, int BufferSize)
{
	if(CheckDll())
		return gThunk.SK_WriteProtectMemory( hKey, Password, Index, Buffer, BufferSize);
	return false;	
}

BOOL    WINAPI SK_ChangeLED(HANDLE hKey, DWORD LED_State)
{
	if(CheckDll())
		return gThunk.SK_ChangeLED( hKey, LED_State);
	return false;	
}

BOOL   	WINAPI SK_ChangeMode(HANDLE hKey, int KeyMode)
{
	if(CheckDll())
		return gThunk.SK_ChangeMode( hKey, KeyMode);
	return false;	
}

BOOL   	WINAPI SK_ChangePassword(HANDLE hKey, DWORD Password,  DWORD NewPassword, DWORD PasswordType)
{
	if(CheckDll())
		return gThunk.SK_ChangePassword( hKey,  Password,   NewPassword,  PasswordType);
	return false;	
	
}

BOOL    WINAPI SK_GetDriverMemorySize(HANDLE hKey, DWORD * cbMaxSize)
{
	if(CheckDll())
		return gThunk.SK_GetDriverMemorySize( hKey, cbMaxSize);
	return false;	
	
}

BOOL    WINAPI SK_ReadDriverMemory(HANDLE hKey, int Index, char * Buffer, int cbLength )
{
	if(CheckDll())
		return gThunk.SK_ReadDriverMemory( hKey, Index,  Buffer, cbLength );
	return false;	
	
}
BOOL    WINAPI SK_WriteDriverMemory(HANDLE hKey, int Index, char * Buffer, int cbLength )
{
	if(CheckDll())
		return gThunk.SK_WriteDriverMemory( hKey, Index,  Buffer, cbLength );
	return false;	
	
}

HANDLE WINAPI SK_RegisterPnpMessage(HANDLE hRecipient, unsigned short  UserID)
{
	if(CheckDll())
		return gThunk.SK_RegisterPnpMessage(hRecipient, UserID);
	return INVALID_HANDLE_VALUE;	
}

BOOL WINAPI SK_UnregisterPnpNotification(HANDLE hNotify)
{
	if(CheckDll())
		return gThunk.SK_UnregisterPnpNotification(hNotify);
	return false;	
}

BOOL WINAPI SK_IsMyDevice(LPCTSTR szDevicePath, WORD UserId)
{
	if(CheckDll())
		return gThunk.SK_IsMyDevice( szDevicePath, UserId);
	return false;		
}


DWORD    WINAPI SK_GetLastError()
{
	if(CheckDll())
		return gThunk.SK_GetLastError();
	return GetLastError();
}

BOOL WINAPI SK_InstallDriver(LPCTSTR InfFileName, WORD UserId)
{
	if(CheckDll())
		return gThunk.SK_InstallDriver(InfFileName, UserId);
	return false;
}
#endif
