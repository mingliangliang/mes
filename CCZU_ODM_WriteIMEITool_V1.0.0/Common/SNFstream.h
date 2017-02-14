#ifndef _SNAPI_H
#define _SNAPI_H

#ifdef DLL_API
#else
#ifdef __cplusplus
#define DLL_API extern "C" _declspec(dllimport)
#else
#define DLL_API _declspec(dllimport)
#endif
#endif

typedef enum
{
    INI_BOOLEAN,
        INI_INTEGER,
        INI_STRING
}E_INI_DATA_TYPE;

typedef struct
{
    const char* pItemKeyWord;
    void* pItemData;
    E_INI_DATA_TYPE dataType;
}IniData_struct;

typedef struct
{
   int  rwFlag;
   char dataBuf[260];
}SeachFile_Req_struct;

typedef enum
{
    INI_RW_SUCCESS = 0,
    INI_RW_ERROR = 1,
    FIELD_NOT_EXIST = 2,   
    INVALID_PARAMETER =3,
    OPEN_FILE_FAIL = 4,
    FIELDNAME_NOT_COINCIDENT = 5
}RW_SetupFile_Status;


DLL_API RW_SetupFile_Status ReadIniItemData(const char* pFilePath, IniData_struct IniData);                                            
DLL_API RW_SetupFile_Status WriteIniItemData(const char* pFilePath, IniData_struct IniData);

DLL_API RW_SetupFile_Status ReadIniData(const char* pFilePath, 
                                        IniData_struct IniData[], 
                                        int IniData_size);

DLL_API RW_SetupFile_Status WriteIniData(const char* pFilePath, 
                                         IniData_struct IniData[], 
                                         int IniData_size);

#endif

