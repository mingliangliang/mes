
#ifndef _SP_BROM_H_
#define _SP_BROM_H_

#ifdef  __cplusplus
extern "C" {
#endif

#define META_SPEC_OUTPUT

#if defined(META_SPEC_OUTPUT)
    #define LIBEXPORT __declspec(dllexport)
#else
    #define LIBEXPORT
#endif

// The magic value to stop boot process 
#define SP_BOOT_STOP   9876

// boot infinitely
#define SP_BOOT_INFINITE   0xFFFFFFF

// default start cmd retry count 
#define SP_DEFAULT_BROM_START_CMD_RETRY_COUNT  1

//------------------------------------------------------------------------------
// AUTH_HANDLE: Exported Functions                                              
//------------------------------------------------------------------------------

typedef struct {
    unsigned int        m_version;
    char                m_filepath[512];
    unsigned char       m_secure_custom_name[32];
    unsigned char       m_description[512];
} SP_AUTH_INFO;

struct SP_AUTH_HANDLE;
typedef struct SP_AUTH_HANDLE *    SP_AUTH_HANDLE_T;
LIBEXPORT int __stdcall SP_AUTH_Create(SP_AUTH_HANDLE_T  *p_auth_handle);
LIBEXPORT int __stdcall SP_AUTH_Destroy(SP_AUTH_HANDLE_T  *p_auth_handle);
LIBEXPORT int __stdcall SP_AUTH_IsReady(SP_AUTH_HANDLE_T  auth_handle, SP_AUTH_INFO  *p_auth_info, bool  bCheckIfUpdated);
LIBEXPORT int __stdcall SP_AUTH_Load(SP_AUTH_HANDLE_T  auth_handle, const char *auth_filepath);
LIBEXPORT int __stdcall SP_AUTH_Unload(SP_AUTH_HANDLE_T  auth_handle);

//------------------------------------------------------------------------------
// SCERT_HANDLE: Exported Functions                                              
//------------------------------------------------------------------------------

typedef struct {
    unsigned int        m_version;
    char                m_filepath[512];
    unsigned char       m_secure_custom_name[32];
    unsigned char       m_description[512];
} SP_SCERT_INFO;

struct SP_SCERT_HANDLE;
typedef struct SP_SCERT_HANDLE *   SP_SCERT_HANDLE_T;
LIBEXPORT int __stdcall SP_SCERT_Create(SP_SCERT_HANDLE_T  *p_scert_handle);
LIBEXPORT int __stdcall SP_SCERT_Destroy(SP_SCERT_HANDLE_T  *p_scert_handle);
LIBEXPORT int __stdcall SP_SCERT_IsReady(SP_SCERT_HANDLE_T  scert_handle, SP_SCERT_INFO  *p_scert_info, bool  bCheckIfUpdated);
LIBEXPORT int __stdcall SP_SCERT_Load(SP_SCERT_HANDLE_T  cert_handle, const char *cert_filepath);
LIBEXPORT int __stdcall SP_SCERT_Unload(SP_SCERT_HANDLE_T  cert_handle);

                                    
                                    
//------------------------------------------------------------------------------
// prototype of Serial-Link-Authentication challenge callback                   
//------------------------------------------------------------------------------
typedef int (__stdcall *SP_CALLBACK_SLA_CHALLENGE)(void *usr_arg, const unsigned char  *p_challenge_in, unsigned int  challenge_in_len, unsigned char  **pp_challenge_out, unsigned int  *p_challenge_out_len);
typedef int (__stdcall *SP_CALLBACK_SLA_CHALLENGE_END)(void *usr_arg, unsigned char  *p_challenge_out);

//------------------------------------------------------------------------------
// runtime debug trace                                                          
//------------------------------------------------------------------------------
LIBEXPORT int __stdcall SP_Brom_Debug_SetLogFilename(const char *filename);
LIBEXPORT int __stdcall SP_Brom_DebugOn(void);
LIBEXPORT int __stdcall SP_Brom_DebugOff(void);
LIBEXPORT int __stdcall SP_Brom_DebugClear(void);
LIBEXPORT int __stdcall SP_Brom_Debug_SetLogPrefix(const char *prefix);

//------------------------------------------------------------------------------
// Boot mode type                                                               
//------------------------------------------------------------------------------
typedef enum 
{
    SP_NORMAL_BOOT         = 0,
    SP_META_BOOT           = 1,
    SP_RECOVERY_BOOT       = 2,    
    SP_SW_REBOOT           = 3,
    SP_FACTORY_BOOT        = 4,
    SP_ADVMETA_BOOT        = 5,
    SP_ATE_FACTORY_BOOT    = 6,
    SP_ALARM_BOOT          = 7,
    SP_DUALTALK_SWITCH          = 8,
    
    SP_DOWNLOAD_BOOT       = 100,
    SP_UNKNOWN_BOOT
    
} SP_BOOT_MODE;

typedef enum {
	SP_EXT_13M = 1,
	SP_EXT_26M = 2,
	SP_EXT_39M = 3,
	SP_EXT_52M = 4,
	SP_EXT_CLOCK_END,
	SP_AUTO_DETECT_EXT_CLOCK = 254,
	SP_UNKNOWN_EXT_CLOCK = 255
} SP_EXT_CLOCK;

typedef	enum {
	SP_MT6205	= 0,
	SP_MT6205B	= 1,
	SP_MT6218	= 2,
	SP_MT6218B	= 4,
	SP_MT6219  = 5,
	SP_MT6217  = 6,
	SP_MT6228  = 7,
	SP_MT6227  = 8,
	SP_MT6229  = 9,
	SP_MT6226  = 10,
	SP_MT6226M  = 11,
	SP_MT6230  = 12,
	SP_MT6225  = 13,
	SP_MT6268T  = 14,
	SP_MT6223  = 15,
	SP_MT6227D  = 16,
	SP_MT6226D  = 17,
	SP_MT6223P  = 18,
	SP_MT6238	= 19,
	SP_MT6235	= 20,
	SP_MT6235B	= 21,
	SP_TK6516_MD  = 22,
	SP_TK6516_AP  = 23,
	SP_MT6268A	= 24,
	SP_MT6516_MD  = 25,
	SP_MT6516_AP  = 26,
	SP_MT6239	= 27,
	SP_MT6251T	= 28,
	SP_MT6253T  = 29,
	SP_MT6268B  = 30,
	SP_MT6253  = 32,
	SP_MT6253D  = 33,
	SP_MT6236  = 34,
	SP_MT6270A  = 35,

	SP_MT6276  = 128,
	SP_MT6251  = 129,
	SP_MT6255  = 130,
	SP_MT6573  = 131,
	SP_MT6575  = 132,
	SP_BBCHIP_TYPE_END,
	SP_AUTO_DETECT_BBCHIP = 254,
	SP_UNKNOWN_BBCHIP_TYPE = 255
	
} SP_BBCHIP_TYPE;

typedef enum {

    SP_S_DONE = 0

    // private random error code (1~999) 

    // common error code (1000~1999) 
    ,SP_S_COMMON_ERROR_BEGIN = 1000
    ,SP_S_STOP = SP_S_COMMON_ERROR_BEGIN
    ,SP_S_UNDEFINED_ERROR
    ,SP_S_INVALID_ARGUMENTS
    ,SP_S_INVALID_BBCHIP_TYPE
    ,SP_S_INVALID_EXT_CLOCK
    ,SP_S_INVALID_BMTSIZE
    ,SP_S_GET_DLL_VER_FAIL
    ,SP_S_INVALID_BUF
    ,SP_S_BUF_IS_NULL
    ,SP_S_BUF_LEN_IS_ZERO
    ,SP_S_BUF_SIZE_TOO_SMALL
    ,SP_S_NOT_ENOUGH_STORAGE_SPACE
    ,SP_S_NOT_ENOUGH_MEMORY
    ,SP_S_COM_PORT_OPEN_FAIL
    ,SP_S_COM_PORT_SET_TIMEOUT_FAIL
    ,SP_S_COM_PORT_SET_STATE_FAIL
    ,SP_S_COM_PORT_PURGE_FAIL
    ,SP_S_FILEPATH_NOT_SPECIFIED_YET
    ,SP_S_UNKNOWN_TARGET_BBCHIP
    ,SP_S_SKIP_BBCHIP_HW_VER_CHECK
    ,SP_S_UNSUPPORTED_VER_OF_BOOT_ROM
    ,SP_S_UNSUPPORTED_VER_OF_BOOTLOADER
    ,SP_S_UNSUPPORTED_VER_OF_DA
    ,SP_S_UNSUPPORTED_VER_OF_SEC_INFO
    ,SP_S_UNSUPPORTED_VER_OF_ROM_INFO
    ,SP_S_SEC_INFO_NOT_FOUND
    ,SP_S_ROM_INFO_NOT_FOUND
    ,SP_S_CUST_PARA_NOT_SUPPORTED
    ,SP_S_CUST_PARA_WRITE_LEN_INCONSISTENT
    ,SP_S_SEC_RO_NOT_SUPPORTED
    ,SP_S_SEC_RO_WRITE_LEN_INCONSISTENT
    ,SP_S_ADDR_N_LEN_NOT_32BITS_ALIGNMENT
    ,SP_S_UART_CHKSUM_ERROR
    ,SP_S_EMMC_FLASH_BOOT
    ,SP_S_NOR_FLASH_BOOT
    ,SP_S_NAND_FLASH_BOOT
    ,SP_S_UNSUPPORTED_VER_OF_EMI_INFO
    ,SP_S_PART_NO_VALID_TABLE
    ,SP_S_PART_NO_SPACE_FOUND

    /* SV5 ANDROID { */
    ,SP_S_UNSUPPORTED_VER_OF_SEC_CFG
    /* SV5 ANDROID } */
    ,SP_S_UNSUPPORTED_OPERATION
    ,SP_S_CHKSUM_ERROR
    ,SP_S_TIMEOUT

    ,SP_S_COMMON_ERROR_END // END 

    //For Preloader command
    ,SP_S_PL_MODE_UNSUPPORTED = 10001
    ,SP_S_PL_MODE_FORBIDDEN
    ,SP_S_PL_MODE_INVALID_ARGUMETS
    ,SP_S_PL_READ_FAIL
    ,SP_S_PL_WRITE_FAIL
    ,SP_S_PL_READ_TIMEOUT
    ,SP_S_PL_WRITE_TIMEOUT
    ,SP_S_PL_DISC_CMD_NEEDED
    
    // expand to 32bits width 
    ,SP_S_MAX_STATUS_WIDTH = 0x7FFFFFFF

} SP_STATUS_E;


//------------------------------------------------------------------------------
// New boot mode for SP                                                               
//------------------------------------------------------------------------------
typedef struct 
{
    //Old parameters
    SP_BBCHIP_TYPE m_bbchip_type;
    SP_EXT_CLOCK m_ext_clock;
    unsigned int m_ms_boot_timeout;
    unsigned int m_max_start_cmd_retry_count;

    //New parameters
    unsigned int m_uTimeout;
    unsigned int m_uRetryTime;
    unsigned int m_uInterval;
    unsigned int m_uBaudrate;
    int * m_pStopFlag;
    
    bool m_bIsUSBEnable;
    bool m_bIsSymbolicEnable;
    bool m_bIsCompositeDeviceEnable;
    bool m_bDisableMobileLogService;
    SP_BOOT_MODE m_euBootMode;
    unsigned short m_uMDMode;
    unsigned int m_uPortNumber;
    char m_szPortSymbolic[256];

    // Serial Link Authentication 
    SP_AUTH_HANDLE_T  m_auth_handle;
    SP_SCERT_HANDLE_T m_scert_handle;
    SP_CALLBACK_SLA_CHALLENGE  m_cb_sla_challenge;
    void *  m_cb_sla_challenge_arg;
    SP_CALLBACK_SLA_CHALLENGE_END  m_cb_sla_challenge_end;
    void *  m_cb_sla_challenge_end_arg;
    
} SP_BOOT_ARG_S;

LIBEXPORT int __stdcall SP_BootROM_BootMode(SP_BOOT_ARG_S * pArg);
LIBEXPORT int __stdcall SP_Preloader_BootMode(SP_BOOT_ARG_S * pArg);


//COM port enumeration

typedef enum {
    SP_WHITE_LIST = 0,
    SP_BLACK_LIST,
} SP_FILTER_TYPE_E;

typedef struct 
{
    unsigned int m_uCount;
    SP_FILTER_TYPE_E m_eType;
    char ** m_ppFilterID;
} SP_COM_FILTER_LIST_S;

typedef struct
{
    int m_iFilterIndex;
    unsigned int m_uNumber;
    char m_rFriendly[512];
    char m_rInstanceID[512];
    char m_rSymbolic[512];
    
} SP_COM_PROPERTY_S;


LIBEXPORT int __stdcall SP_ComPortEnumerate(unsigned short *p_com_port_array, unsigned short *p_com_port_count);
LIBEXPORT int __stdcall SP_GetIncrementCOMPortWithFilter(SP_COM_FILTER_LIST_S * pCOMFilter, SP_COM_PROPERTY_S * pCOMPorperty, const void * pGuid, bool bDeviceInterface, int * pStopFlag, double dTimeout);
LIBEXPORT void __stdcall SP_GetAllInterfaceInfo(const void * pGuid, bool bEnableDriverInfo);
LIBEXPORT int __stdcall SP_GetCurrentCOMPortNumberWithFilter(SP_COM_FILTER_LIST_S * pCOMFilter, const void * pGuid, bool bDeviceInterface, int * pNum);
LIBEXPORT int __stdcall SP_GetCurrentCOMPortInfoWithFilter(SP_COM_FILTER_LIST_S * pCOMFilter, const void * pGuid, bool bDeviceInterface, SP_COM_PROPERTY_S * pCOMPorperty, int * pNum);


#ifdef  __cplusplus
}
#endif

#endif
