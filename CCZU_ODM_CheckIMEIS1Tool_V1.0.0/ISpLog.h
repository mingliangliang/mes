// ISpLog.h: interface for the ISpLog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ISPLOG_H__0403ADC7_05F6_4A7D_9B43_CCF38A8B2FAF__INCLUDED_)
#define AFX_ISPLOG_H__0403ADC7_05F6_4A7D_9B43_CCF38A8B2FAF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include <stdio.h>

//lint ++flb

// --------------------------------------------------------------------------------
//  Maximum number of bytes stored in a string, for characters as follows:
//  ansi    :  MAX_STRING_IN_BYTES 
//  unicode :  MAX_STRING_IN_BYTES / 2 
//
//  Remarks:
//  If the number of bytes store in string exceed MAX_STRING_IN_BYTES, 
//  the exceed bytes in string would be ignored.
#define MAX_STRING_IN_BYTES             ( 8192 )


//  Maximum bytes in a line 
#define MAX_LINE_HEX_BYTES              ( 16 )              


// --------------------------------------------------------------------------------
//  Attribute:
enum LOG_ATTRIBUTE
{
    ATTR_LOGFILE_PATH,              // directory path of log file
    ATTR_LOGFILE_NAME,              // log file name 
    ATTR_MAX_LINEBYTES,             // maximum bytes in a line
    ATTR_LOG_LOCALTIME,             // [%04d-%02d-%02d %02d:%02d:%02d:%04d]
    ATTR_LOG_DATAINDEX,             // 00000000h:
    ATTR_LOG_DATAASCII,             // ; ................
    ATTR_CONSOLE_WINDOW,            // console window
    ATTR_BIN_LOG_EXT,               // binary log file name extension
    ATTR_MAX_LOGFILE_SIZE           // maximum log file size, unit: MB, 0: infinite.
};

//  Log file path attribute:
//      PATH_CURRENT:  Current work directory
//      PATH_WINTEMP:  Windows temp directory
#define PATH_CURRENT                    ( 1 )       
#define PATH_WINTEMP                    ( 2 )
#define PATH_USERDFN                    ( 3 )


#define INFINITE_LOGFILE_SIZE           ( 0 )

enum 
{
    FREE_CONSOLE_WINDOW = 0,
    SHOW_CONSOLE_WINDOW = 1,
    HIDE_CONSOLW_WINDOW = 2
};

enum
{
    LOG_READ  = 0,
    LOG_WRITE = 1,
    LOG_ASYNC_READ =2
};

// --------------------------------------------------------------------------------
//  Log level:
//      
typedef enum
{
    SPLOGLV_NONE      = 0,       
    SPLOGLV_ERROR     = 1,       
    SPLOGLV_WARN      = 2,        
    SPLOGLV_INFO      = 3,
	SPLOGLV_DATA      = 4, //exclusive, only output data
    SPLOGLV_VERBOSE   = 5
        
}SPLOG_LEVEL;

// --------------------------------------------------------------------------------
//  Function macros 
#ifdef  UNICODE  
#define LogRawStr       LogRawStrW
#define LogFmtStr       LogFmtStrW
#else
#define LogRawStr       LogRawStrA
#define LogFmtStr       LogFmtStrA
#endif // !UNICODE

// --------------------------------------------------------------------------------
//
class ISpLog  
{
public:
    
    enum OpenFlags 
    {
        modeTimeSuffix  =      0x0001,  //  Append time suffix to a file, like: xxx_2009_06_01_12_39_50.log
        modeDateSuffix  =      0x0002,  //  Append date suffix to a file, like: xxx_2009_06_12.log
        modeCreate      =      0x1000,  //  Directs the constructor to create a new file. 
                                        //  If the file exists already, it is truncated to 0 length. 
		modeNoTruncate  =      0x2000,  //  Combine this value with modeCreate. 
                                        //  If the file being created already exists, it is not truncated to 0 length.
		
        typeText        =      0x4000,  //  Sets text mode.   Default file extension is *.log     
		typeBinary      = (int)0x8000,  //  Sets binary mode. Default file extension is *.bin
        
        // typeBinary only --------- [
        modeBinNone     =      0x0000,  // Log none  bin data
        modeBinRead     =      0x0100,  // Log read  bin data
        modeBinWrite    =      0x0200,  // Log write bin data
        modeBinReadWrite=      0x0300,  // Log read & Write bin data
        //  ------------------------]

        defaultTextFlag    =   modeCreate|modeDateSuffix|typeText,
        defaultBinaryFlag  =   modeCreate|modeDateSuffix|typeBinary|modeBinRead,
        defaultDualFlag    =   modeCreate|modeDateSuffix|typeText|typeBinary|modeBinRead
    };
    
    virtual ~ISpLog(void)   {   } ;

    // ----------------------------------------------------------------------------
    //  Open
    //      Open log file
    //
    //  Parameter
    //      lpszLogPath         : A string that is the path to the desired file. The path can be relative or absolute.
    //                            There is a default string size limit of _MAX_PATH characters
    //      uFlags              : Specifies the action to take when opening the file. 
    //                            You can combine options listed below by using the bitwise-OR (|) operator.
    //                            See the ILog::OpenFlags enum for a list of mode options.
    //      uLogLevel           : Specifies the log level. Only available for 'typeText'. see SPLOG_LEVEL.                    
    //      uMaxFileSizeInMB    : Max. log file size in unit of MB. Note: 0, infinite file size.
    //
    //  Return
    //      If the function succeeds, the return value is nonzero.
    //      If the function fails, the return value is zero. 
    //
    //  Remarks
    //      None
    virtual BOOL    Open(LPCTSTR lpszLogPath, 
                         UINT uFlags=ISpLog::defaultTextFlag, 
                         UINT uLogLevel=SPLOGLV_INFO,
                         UINT uMaxFileSizeInMB = INFINITE_LOGFILE_SIZE 
                         ) = 0;

    // ----------------------------------------------------------------------------
    //  Close
    //      Close log file
    //
    //  Parameter
    //      None.   
    //
    //  Return
    //      If the function succeeds, the return value is nonzero.
    //      If the function fails, the return value is zero. 
    //
    //  Remarks
    //      None
    virtual BOOL    Close(void) = 0;


    // ----------------------------------------------------------------------------
    //  Release
    //      Delete object
    //
    //  Parameter
    //      None.   
    //
    //  Return
    //      None. 
    //
    //  Remarks
    //      None
    virtual void    Release(void) = 0;
    
    
    // ----------------------------------------------------------------------------
    //  LogHexData
    //      Log binary data. 
    //      Example :   4D 5A 90 00 03 00 00 00 04 00 00 00 FF FF 00 00
    //                  B8 00 00 00 00 00 00 00 40 00 00 00 00 00 00 00 
    //      uFlag   :   LOG_READ ,  specifies that the 'pHexData' is 'read  data'.
    //                  LOG_WRITE,  specifies that the 'pHexData' is 'write data'.
    //
    //  Parameter
    //      pHexData    : Binary data. 
    //      dwHexSize   : The number of bytes to write to the log file.
    //
    //  Return
    //      If the function succeeds, the return value is nonzero.
    //      If the function fails, the return value is zero. 
    //
    //  Remarks
    //      None
    virtual BOOL    LogHexData(const BYTE *pHexData, DWORD dwHexSize, UINT uFlag = LOG_READ) = 0;

    // ----------------------------------------------------------------------------
    //  LogRawStrA (ANSI)
    //  LogRawStrW (UNICODE)
    //      Log a string.
    //      Example:    [2009-06-04 16:54:47:500] This is a test.  
    //
    //  Parameter
    //      uLogLevel  : Specifies the level of the 'lpszString'. 
    //      lpszString : A string to write to log file. 
    //
    //  Return
    //      If the function succeeds, the return value is nonzero.
    //      If the function fails, the return value is zero. 
    //
    //  Remarks
    //      None
    virtual BOOL    LogRawStrA(UINT uLogLevel, LPCSTR  lpszString)   = 0;
    virtual BOOL    LogRawStrW(UINT uLogLevel, LPCWSTR lpszString)   = 0;

    // ----------------------------------------------------------------------------
    //  LogFmtStrA (ANSI)
    //  LogFmtStrW (UNICODE)
    //      Log a formatted string.
    //
    //  Parameter
    //      uLogLevel  : Specifies the level of the 'lpszString'. 
    //      lpszFmt : Format control. 
    //      argument: Optional arguments.
    //
    //  Return
    //      If the function succeeds, the return value is nonzero.
    //      If the function fails, the return value is zero. 
    //
    //  Remarks
    //      None
    virtual BOOL    LogFmtStrA(UINT uLogLevel, LPCSTR  lpszFmt, ...) = 0;
    virtual BOOL    LogFmtStrW(UINT uLogLevel, LPCWSTR lpszFmt, ...) = 0;

    // ----------------------------------------------------------------------------
    //  LogBufData 
    //      Log a buffer. Example :
    //      [2009-06-04 16:54:47:500] --> 114756(0x0001c044) Bytes
    //                                00000000h: 4D 5A 90 00 03 00 00 00 04 00 00 00 FF FF 00 00 ; MZ..............
    //                                00000010h: B8 00 00 00 00 00 00 00 40 00 00 00 00 00 00 00 ; ........@.......
    //                                00000020h: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ; ................
    //
    //  Parameter
	//      uLogLevel: Specifies the level of the 'pBufData'
    //      pBufData : A buffer to write to log file. 
    //      dwBufSize: The number of bytes of the buffer.
    //      uFlag    : LOG_WRITE      specifies '-->'   
    //                 LOG_READ       specifies '<--'
    //		           LOG_ASYNC_READ specifies '<<-'
    //      pUserNeedSize: this size is that user want to Read/Write buffer size
    //                     use this parameter user can see the different between real Read/Write size (dwBufSize) 
    //                     and expired size (*pUserNeedSize)
    //                     if this point is not null,log will like bellow
    //                     [2009-06-04 16:54:47:0500] --> 114756(0x0001c044)/114757(0x0001c045)  Bytes
    //
    //
    //  Return
    //      If the function succeeds, the return value is nonzero.
    //      If the function fails, the return value is zero. 
    //
    //  Remarks
    //      None
    virtual BOOL    LogBufData(UINT uLogLevel, const BYTE *pBufData, DWORD dwBufSize, UINT uFlag=LOG_WRITE, const DWORD * pUserNeedSize =NULL) = 0;
    
    // ----------------------------------------------------------------------------
    //  SetProperty/GetProperty 
    //      Set/Get property
    //  Parameter
    //      lAttr   : Attributes, see enum LOG_ATTRIBUTE.
    //      lFlags  : 
    //      lpValue : Values to be set/get.         
    //
    //  Return
    //      If the function succeeds, the return value is nonzero.
    //      If the function fails, the return value is zero. 
    //
    //  Remarks
    //      None
    virtual BOOL    SetProperty(LONG lAttr, LONG lFlags, LPCVOID lpValue) = 0;
    virtual BOOL    GetProperty(LONG lAttr, LONG lFlags, LPVOID  lpValue) = 0; 
};

//lint --flb

#endif // !defined(AFX_ISPLOG_H__0403ADC7_05F6_4A7D_9B43_CCF38A8B2FAF__INCLUDED_)
