#ifndef _PHASECHECK_EXPORT_H_BY_JXP_20091102_EA3C3E8A_2D1C_4EF7_9A4D_AF27799B3D0A_
#define _PHASECHECK_EXPORT_H_BY_JXP_20091102_EA3C3E8A_2D1C_4EF7_9A4D_AF27799B3D0A_


// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the PHASECHECKDLL_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// PHASECHECKDLL_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.


#ifdef  PHASECHECKDLL_EXPORTS
    #ifdef __cplusplus
        #define SPPH_EXPORT extern "C" __declspec(dllexport)
    #else
        #define SPPH_EXPORT            __declspec(dllexport)
    #endif
#else
    #ifdef __cplusplus
        #define SPPH_EXPORT extern "C" __declspec(dllimport)
    #else
        #define SPPH_EXPORT            __declspec(dllimport)
    #endif
#endif

//////////////////////////////////////////////////////////////////////////
//
#define SPPH_API  __stdcall
//
typedef void *  SPPH_OBJECT;

//lint ++flb
typedef enum
{
    SPPH_VERSION  = 1


}SPPH_PROPERTY_OPTION;

//
typedef enum
{
    SPPH_AUTO = 0,
    SPPH_SP05,
    SPPH_SP09

}SPPH_VERSION_TYPE;


//
typedef enum
{
    SPPH_SUCC  = 0,                 // 操作成功
    SPPH_FAIL,                      // 操作失败
    SPPH_INVALID_SPPH_OBJECT,       // 无效的句柄: SPPH_OBJECT hObject
    SPPH_INVALID_PRODUCTINFO,       // 无效的PhaseCheck结构
    SPPH_INVALID_STATION_NAME,      // 无效的测试站位名称
    SPPH_STATION_NOT_EXIST,         // 测试站不存在
    SPPH_STATION_NOT_PASSED,        // 测试站未PASS
    SPPH_STATION_NOT_TESTED,        // 测试站未测试
    SPPH_CNST_PHASE_BUFFER_FAIL,    // 创建PhaseCheck缓存失败
    SPPH_WRITE_PRODUCTINFO_FAIL,    // 写入FLASH失败
    SPPH_READ_PRODUCTINFO_FAIL,     // 读取FLASH失败
    SPPH_BUFFER_TOO_SMALL,          // 输入的缓存太小
    SPPH_READ_MAGIC_NUMBER_FAIL,    // 读取PhaseCheck版本失败
    SPPH_INVALID_MAGIC_VERSION      // 无效PhaseCheck版本

}SPPH_ERROR;

/* ========================================================================================================= 
-- Name:
--      CreatePhaseCheckObject
--
-- Function:
--      创建PhaseCheck操作对象，并返回操作句柄
--
-- Parameter:
--  IN
--      hDiagPort: Handle of phone, returned by 'SP_CreateDiagPhone' of PhoneCommand.
--
-- Return:
--      SPPH_OBJECT: 成功返回操作句柄，失败返回NULL.
--   
   ========================================================================================================= */

SPPH_EXPORT 
SPPH_OBJECT SPPH_API CreatePhaseCheckObject
(
    void *hDiagPort
);

/* ========================================================================================================= 
-- Name:
--      ReleasePhaseCheckObject
--
-- Function:
--      释放CreatePhaseCheckObject创建的句柄
--
-- Parameter:
--  IN
--      hObject:    操作句柄
--
-- Return:
--      操作成功返回SPPH_SUCC，错误代码参考SPPH_ERROR定义          
--   
   ========================================================================================================= */

SPPH_EXPORT 
DWORD SPPH_API ReleasePhaseCheckObject
(
    SPPH_OBJECT hObject
);

/* ========================================================================================================= 
-- Name:
--      InitPhase
--
-- Function:
--      根据配置文件的设置，初始化手机FLASH的生产信息区域
--
-- Parameter:
--  IN
--      hObject:        操作句柄
--      sn1:            手机序列号1，若NULL则初始化为0. 最大长度24字节。
--      sn2:            手机序列号2，若NULL则初始化为0. 最大长度24字节。
--      pszStationName: 首站的名称，默认PASS
--  OUT
--      lpData:   初始化完毕的生产信息区域数据指针,
--                若lpData为空指针，则不返回数据。
--      nDataLen: lpData Buffer的长度
--      pnRetLen: 实际返回的lpData Buffer的长度      
--
-- Return:
--      操作成功返回SPPH_SUCC，错误代码参考SPPH_ERROR定义          
--          
   ========================================================================================================= */

SPPH_EXPORT 
DWORD SPPH_API InitPhase
(
     SPPH_OBJECT     hObject,        /*  IN */ 
     const char     *sn1,            /*  IN */ 
     const char     *sn2,            /*  IN */ 
     LPBYTE          lpData,         /* OUT */ 
     int             nDataLen,       /*  IN */
     int            *pnRetLen,       /* OUT */
     const char     *pszStationName  /*  IN */ 
 );

/* ========================================================================================================= 
-- Name:
--      CheckPhase
--
-- Function:
--      检查测试站的测试状态
--     
-- Parameter:
--  IN
--      hObject:                操作句柄
--      pszCurrentStationName:  当前测试站的名称
--      pszCheckStationName:    需要检查的测试站的名称
                                pszCheckStationName = "NULL", 表示首站
--
-- Return:
--      操作成功返回SPPH_SUCC，错误代码参考SPPH_ERROR定义          
--          
   ========================================================================================================= */

SPPH_EXPORT 
DWORD SPPH_API CheckPhase
(
    SPPH_OBJECT hObject,                /*  IN */ 
    const char *pszCurrentStationName,  /*  IN */ 
    const char *pszCheckStationName     /*  IN */ 
 );

/* ========================================================================================================= 
-- Name:
--      UpdatePhase
--
-- Function:
--      更新测试站位信息  
--
-- Parameter:
--  IN
--      hObject:        操作句柄
--      pszCurrentStationName: 需要更新的测试站的名称(通常情况下为当前测试站名)
--      nState:         测试状态，1 表示 PASS; 0 表示 FAIL  
--      pszLastDescription:    测试状态描述，最大不超过32个字节
--      sn1:            SN1, 若指针为空则不更新SN1
--      sn2:            SN2, 若指针为空则不更新SN2
--
-- Return:
--      操作成功返回SPPH_SUCC，错误代码参考SPPH_ERROR定义        
--          
   ========================================================================================================= */

SPPH_EXPORT 
DWORD SPPH_API UpdatePhase
(
    SPPH_OBJECT hObject,                /*  IN */ 
    const char *pszCurrentStationName,  /*  IN */ 
    int         nState,                 /*  IN */ 
    const char *pszLastDescription,     /*  IN */   //Max characters is 32.
    const char *sn1,                    /*  IN */ 
    const char *sn2                     /*  IN */ 
);

/* ========================================================================================================= 
-- Name:
--      PutProperty
--
-- Function:
--      设置属性
--
-- Parameter:
--  IN
--      hObject:    操作句柄 
--      lOption:    属性选项
--      lProperty:  属性值 
--
-- Return:
--      操作成功返回SPPH_SUCC，错误代码参考SPPH_ERROR定义       
--          
   ========================================================================================================= */

SPPH_EXPORT 
DWORD SPPH_API PutProperty
(
    SPPH_OBJECT hObject,    /*  IN */ 
    LONG        lOption,    /*  IN */ 
    LONG        lProperty   /*  IN */ 
);

/* ========================================================================================================= 
-- Name:
--      GetProperty
--
-- Function:
--      获取属性设置
--
-- Parameter:
--  IN
--      hObject:    操作句柄 
--      lOption:    属性选项
--  OUT
--      pProperty:  属性值 
--
-- Return:
--      操作成功返回SPPH_SUCC，错误代码参考SPPH_ERROR定义       
--          
   ========================================================================================================= */

SPPH_EXPORT 
DWORD SPPH_API GetProperty
(
    SPPH_OBJECT hObject,    /*  IN */ 
    LONG        lOption,    /*  IN */ 
    LONG       *pProperty   /* OUT */
);

/* ========================================================================================================= 
-- Name:
--      SPPH_GetLastError/SPPH_GetLastErrorMessage
--
-- Function:
--      获得最近一次的错误代码和错误描述信息 
--
-- Parameter:
--  IN
--      hObject:    操作句柄
--      pMsgBuff:   存储错误描述信息缓存
--      nBuffLen:   缓存大小
--      nLangOption:1, 中文; 0, 英文
--
-- Return:
--      SPPH_GetLastError 操作成功返回最近一次的错误代码
--              
--          
   ========================================================================================================= */
SPPH_EXPORT 
DWORD SPPH_API SPPH_GetLastError
(
    SPPH_OBJECT hObject     /*  IN */
);

SPPH_EXPORT
DWORD SPPH_API SPPH_GetLastErrorMessage
(
    SPPH_OBJECT hObject,    /*  IN */
    char       *pMsgBuff,   /* OUT */
    int         nBuffLen,   /*  IN */
    int         nLangOption /*  IN */
);
//lint --flb
#endif /* _PHASECHECK_EXPORT_H_BY_JXP_20091102_EA3C3E8A_2D1C_4EF7_9A4D_AF27799B3D0A_ */
