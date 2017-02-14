#ifndef _ICOMMUNICATIONCHANNEL_H__
#define _ICOMMUNICATIONCHANNEL_H__

#include "windef.h"
#include "ISpLog.h"



//only for pc_lint zero warning
//lint ++flb

//////////////////////////////////////////////////////////////////////////
//define events
#define CHE_NO_EVENT			((DWORD)-1)
// define for socket
#define SC_CLIENT_CLOSED		(0)
#define SC_CLIENT_CONNECT		(1)

#define CHE_SC_CLIENT_CLOSED    (0)
#define CHE_SC_CLIENT_CONNECT	(1)
#define CHE_SC_SERVER_CLOSED	(2)
// define for UART
#define CHE_DEVICE_PLUGOUT      (3)
#define CHE_DEVICE_PLUGIN       (4)

// define for File
#define CHE_FILE_READ_OVER      (5) 
#define CHE_FILE_READ_STOP      (6) 
//////////////////////////////////////////////////////////////////////////
#define CH_EVNET_DATA_SIZE      (sizeof(DWORD)*2)

#define SC_TYPE_SERVER     (0)
#define SC_TYPE_CLIENT     (1)

#define INVALID_VALUE      ((DWORD)-1)


typedef enum CHANNEL_TYPE
{
    CHANNEL_TYPE_COM      = 0,
    CHANNEL_TYPE_SOCKET   = 1,
	CHANNEL_TYPE_FILE     = 2,
    CHANNEL_TYPE_USBMON   = 3         // USB monitor
};

typedef enum CHANNEL_PROPERTIES {
	// common property
	CH_PROP_DEBUGMODE = 0,
	CH_PROP_LAST_ERROR,

	// for uart
	CH_PROP_BAUD = 100,
	CH_PROP_WATCH_DEV_CHANGE,
	
	// for socket
	CH_PROP_SOCKET_CLIENTS_COUNT = 200,
	CH_PROP_SOCKET_CLIENTS_INFO,
	CH_PROP_SOCKET_CLIENTS_INFO2,

	// for file	
	CH_PROP_FILE_PACK_SIZE = 300,
	CH_PROP_FILE_PACK_FREQ 
};

// channel attributes
typedef struct _CHANNEL_ATTRIBUTE
{
    CHANNEL_TYPE ChannelType;

    union {
        // ComPort
        struct {
            DWORD  dwPortNum;
            DWORD  dwBaudRate;
        } Com;

        // Socket
        struct {			
			DWORD dwPort;
			DWORD dwIP;
			DWORD dwFlag; //[in]: 0, Server; 1, Client; [out]: client ID.		               
        } Socket;

		// File
        struct {			
			DWORD  dwPackSize;
			DWORD  dwPackFreq;
			WCHAR  *pFilePath;
        } File;
    };

} CHANNEL_ATTRIBUTE, * PCHANNEL_ATTRIBUTE;

typedef const PCHANNEL_ATTRIBUTE PCCHANNEL_ATTRIBUTE;

typedef struct _CHANNEL_INFO
{
	DWORD              dwClientCount;
	PCHANNEL_ATTRIBUTE pClients;
}CHANNEL_INFO,*CHANNEL_INFO_PTR;


class ICommChannel
{
public:  
    virtual~ICommChannel()=0;
/**
 *  InitLog
 *  @param [in] pszLogName: log file name, if it is NULL or _T(""), program will set default
 *  @param [in] uiLogType : log format type
 *  @param [in] uiLogLevel: see LOG_LEVEL enum
 *  @param [in] pLogUtil  : set the sub-class pointer of CLogUtil, to do special log content
 *  @param [in] pszBinLogFileExt: binary log file extension, if you set uiLogType both text 
 *                          and binary,and want to change the binary log file extension,you must
 *							set this param, otherwise ".bin" extension is set default.
 *  
 *  @return: TRUE if init success, FALSE otherwise
 *
 *  @remarks: this method need not be called before Open always, because program will auto to 
 *            log information by configure file settings. "ChannelConfig.ini"
 */
	virtual BOOL	InitLog( LPCWSTR pszLogName, UINT uiLogType, 
			                 UINT uiLogLevel=INVALID_VALUE, ISpLog * pLogUtil=NULL,
							 LPCWSTR pszBinLogFileExt = NULL )=0;   
/**
 *  Set receiver for reading data with async way
 *  @param [in] ulMsgId		: message ID
 *  @param [in] bRcvThread	: TRUE, received by thread, FALSE, by window
 *  @param [in] pReceiver	: receiver based on bRcvThread
 *  
 *  @return TRUE if set success, FALSE otherwise
 *
 *  @remarks: if you call this method after Open, and you set pReceiver to NULL,it will stop
 *            auto-read thread. if set pReceiver to not NULL, and not call this method before
 *            Open, this will start auto-read thread.
 */
	virtual BOOL	SetReceiver( ULONG  ulMsgId, 
				                 BOOL    bRcvThread,
                          	     LPCVOID pReceiver )=0;   
/**
 *  Get receiver
 *  @param [out] ulMsgId	: message ID
 *  @param [out] bRcvThread	: TRUE, received by thread, FALSE, by window
 *  @param [out] pReceiver	: receiver based on bRcvThread
 *  
 *  @return void
 */
	virtual void	GetReceiver( ULONG  &ulMsgId, 
			             BOOL &bRcvThread, 
			             LPVOID &pReceiver )=0;     
/**
 *  Open channel
 *  @param [in] pOpenArgument : channel parameters
 *  
 *  @return TRUE if open success, FALSE otherwise
 */
	virtual BOOL	Open( PCCHANNEL_ATTRIBUTE pOpenArgument )=0; 
/**
 *  Close channel
 *  
 *  @return void
 */
	virtual void	Close()=0;    
/**
 *  clear channel in&out data buffer
 *  
 *  @return TRUE if clear success, FALSE otherwise
 */
	virtual BOOL	Clear()=0;   
/**
 *  Read data from channel with sync way
 *  @param [out] lpData		: store read data
 *  @param [in] dwDataSize	: lpData allocated size by outside
 *  @param [in] dwTimeOut	: time out
 *  @param [in] dwReserved  : reserved, for UART; 
 *                            low word is client ID, high word is reserved for server socket
 *  
 *  @return real read data size
 */
	virtual DWORD	Read( LPVOID lpData, DWORD dwDataSize, 
	                      DWORD dwTimeOut, DWORD dwReserved = 0 )=0;    
/**
 *  Write data to channel
 *  @param [in] lpData		: store writing data
 *  @param [in] dwDataSize	: lpData allocated size by outside
 *  @param [in] dwReserved  : reserved, for UART; 
 *                            low word is client ID, high word is reserved for server socket
 *
 *  @return real written data size
 */
	virtual DWORD	Write( LPVOID lpData, DWORD dwDataSize,DWORD dwReserved = 0  )=0;  
/**
 *  Free memory allocated by program, only used after async read data
 *  @param [in] pMemBlock	: memory pointer
 *  
 *  @return void
 */
	virtual void	FreeMem( LPVOID pMemBlock )=0;  
/**
 *  Get property of this program
 *  @param [in] lFlags		: reserved
 *  @param [in] dwPropertyID: property name
 *  @param [out] pValue		: property value pointer
 *  
 *  @return TRUE if get success,  FALSE otherwise
 */
	virtual BOOL	GetProperty( LONG lFlags, DWORD dwPropertyID, 
		                         LPVOID pValue )=0;    
/**
 *  Get property of this program
 *  @param [in] lFlags		: reserved
 *  @param [in] dwPropertyID: property name
 *  @param [in] pValue		: property value pointer
 *  
 *  @return TRUE if set success,  FALSE otherwise
 */
	virtual BOOL 	SetProperty( LONG lFlags, DWORD dwPropertyID, 
                                 LPCVOID pValue )=0;
};

#ifdef  CHANNEL_EXPORTS
	#define CHANNEL_API extern "C" __declspec(dllexport)
#else
	#define CHANNEL_API extern "C" __declspec(dllimport)
#endif

/**
 *  Create channel object, export function
 *  @param [out] pChannel	: the pointer to hold the implement class object of ICommChannel
 *  @param [in] PortType	: channel type
 *  
 *  @return TRUE if create success,  FALSE otherwise
 */
CHANNEL_API BOOL CreateChannel( ICommChannel ** pChannel, CHANNEL_TYPE PortType );
/**
 *  Release channel object, export function
 *  @param [out] pChannel	: the pointer to hold the implement class of ICommChannel
  *  
 *  @return void
 */
CHANNEL_API void ReleaseChannel( ICommChannel *pChannel);



//error define
#define CH_S_OK                         ((DWORD)0x00000000L)
#define CH_S_FALSE                      ((DWORD)0x00000001L)
#define CH_E_FAILED                     ((DWORD)0x80096002L)
#define CH_E_INVALIDARG                 ((DWORD)0x80096003L)
#define CH_E_OUTOFMEMORY                ((DWORD)0x80096004L)
#define CH_E_TIMEOUT                 	((DWORD)0x80096005L)
#define CH_E_NOT_CONNECT                ((DWORD)0x80096006L)
#define CH_E_CLIENTID_NOT_EXIST         ((DWORD)0x80096007L)
#define CH_E_OPEN_LOG_FAILED            ((DWORD)0x80096008L)
#define CH_E_LOAD_CONFIG_FAILED         ((DWORD)0x80096009L)

//only for pc_lint zero warning
//lint --flb

#endif // _ICOMMUNICATIONCHANNEL_H__
