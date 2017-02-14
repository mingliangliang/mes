/*******************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2004
 *
 ******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  interface.h
 *
 * Project:
 * --------
 *  Smart Phone Download/Readback/Format Library.
 *
 * Description:
 * ------------
 *  This file is to be included by Smart Phone Download/CCT/Meta Tool
 *
 * Author:
 * -------
 *  Wayne Chen (mtk01370)
 *
 *==============================================================================
 *           HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.0  $
 * $Modtime:   Feb 25 2004 00:08:56  $
 * $Log:   //mtkvs01/vmdata/flash_tool/archives/BootRom/dll_main.cpp-arc  $
 *
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef	_EBOOT_INTERFACE_H_
#define	_EBOOT_INTERFACE_H_

#include  "stdlib.h"
#include  "windows.h"
#include  "android_dl_structure.h"
#include  "USBFinder.h"


//water typedef unsigned char bool;

// Connect result
typedef enum 
{
	CONNECT_SYNC_FAIL,
	CONNECT_FAIL,
	CONNECT_SUCCESS
} CONNECT_RESULT;

typedef struct  {
	unsigned long  read_retry_time;			//     0 means default  (2400 times)
	unsigned long  read_interval_timeout;	// ms, 0 means default  (10 ms)
	int			 * m_p_stopflag;
}Meta_Boot_Arg;

//Errors
typedef enum 
{
	EBOOT_SUCCESS = 10000,
	EBOOT_EXCEPTION,

	//USER
	USER_PRESS_STOP_BUTTON,
	WAIT_FOR_PLATFORM_ERROR,

	// COM PORT ERROR
	OPEN_COM_PORT_ERROR = 11000,
	SETUP_COM_PORT_ERROR,
	GET_COM_STATE_ERROR,
	SET_COM_STATE_ERROR,
	PURGE_COM_PORT_ERROR,
	SET_COMM_TIMEOUTS_ERROR,

	//Boot ERROR
	READ_READY_PATTERN_ERROR = 12000,

	WRITE_META_PATTERN_ERROR,
	READ_META_ACK_PATTERN_ERROR,

	WRITE_ADVMETA_PATTERN_ERROR,
	READ_ADVMETA_ACK_PATTERN_ERROR,

	WRITE_DOWNLOAD_PATTERN_ERROR,
	READ_DOWNLOAD_ACK_PATTERN_ERROR,

	WRITE_FACTORYM_PATTERN_ERROR,
	READ_FACTORYM_ACK_PATTERN_ERROR,

	WRITE_FACTFACT_PATTERN_ERROR,
	READ_FACTFACT_ACK_PATTERN_ERROR,

	WRITE_SWITCHMD_PATTERN_ERROR,
	READ_SWITCHMD_ACK_PATTERN_ERROR,

	WRITE_MPWAIT_PATTERN_ERROR,
	READ_MPWAIT_ACK_PATTERN_ERROR,

	WRITE_MPGOON_PATTERN_ERROR,
	READ_MPGOON_ACK_PATTERN_ERROR,

	WRITE_CLEAN_BOOT_PATTERN_ERROR,
	READ_CLEAN_BOOT_ACK_PATTERN_ERROR,

	//USB PORT ERROR
	OPEN_USB_PORT_ERROR = 13000,
	USB_PORT_READ_FILE_ERROR,
	USB_PORT_READ_FILE_TIMEOUT_ERROR,
	USB_PORT_WRITE_FILE_ERROR,
	USB_PORT_READ_FILE_LEN_ERROR,
	USB_PORT_WRITE_FILE_LEN_ERROR,
	USB_PORT_SET_TIMEOUT_ERROR,
	USB_PORT_TOO_MANY_ERROR,
	USB_PORT_LOAD_WINDEV_DLL_ERROR,

	//ANDROID DOWNLOAD ERROR
	NOT_FLASH_INFO_PKT_ERROR = 14000,
	NOT_PL_INFO_PKT_ERROR,
	NOT_IMAGE_INFO_PKT_ERROR,
	NOT_RESP_INFO_PKT_ERROR,
	NOT_FOUND_INFO_PKT_ERROR,
	OPEN_IMAGE_FILE_ERROR,
	GET_IMAGE_FILE_SIZE_ERROR,
	IMAGE_FILE_PATH_IS_NULL_ERROR,
	READ_IMAGE_FILE_ERROR,
	WRITE_IMAGE_FILE_ERROR,
	SEND_IMAGE_FILE_ERROR,
	UNKNOWN_SEND_IMAGE_CHECK_PACKET_ERROR,
	SEND_PATTERN_ERROR,
	SEND_PATTERN_SIZE_ERROR,
	ANDROID_VERIFY_FAIL_ERROR,

	//Secured download
	CHECK_SECURED_MARK_ERROR,
	GET_ENCRYPT_INFO_ERROR,
	GET_ENCRYPT_DATA_ERROR,
	SET_FILE_POINTER_ERROR,

	//DA download error
	SEND_DA_VERIFY_DATA_ERROR,
	RECEIVE_DA_VERIFY_RESPONSE_ERROR,
	SEND_DA_INFO_ERROR,
	SEND_DA_DATA_ERROR,
	DA_LOCKED_ERROR,

         //Image patch & lock
	INFORM_IMAGE_PACKET_ERROR,
	PATCH_CMD_PACKET_ERROR,
	SEND_SECURITY_PACKET_ERROR,
	IMAGE_LOCK_RESPONSE_ERROR,
	SET_LOCK_RESPONSE_ERROR,
	RECEIVE_CHECKSUM_ERROR,
	META_LOCKED_ERROR,

	//Partition table checking
	SEND_PARTITION_INFO_PACKET_ERROR,
	RECEIVE_PARTITION_RESPONSE_ERROR,

	//Target response error message
	TARGET_NOMEM_ERROR        = 16000,        /* no memory */
	TARGET_NAND_RD_ERROR,
	TARGET_NAND_WR_ERROR,
	TARGET_NAND_ER_ERROR,
	TARGET_WRONG_SEQ_ERROR,
	TARGET_WRONG_ADDR_ERROR,
	TARGET_WRONG_PKT_SZ_ERROR,
	TARGET_EXCEED_BOUNDARY_ERROR,
	TARGET_INVALID_TABLE,
	TARGET_SPACE_NOT_FOUND,
	TARGET_UNKNOWN_ERROR,

	//Other Error
	OPEN_FLASH_BIN_FILE_ERROR    = 20000,
	READ_FLASH_BIN_FILE_ERROR,
	ALLOC_MEMORY_ERROR,

	EBOOT_RESULT_END = 0x7FFFFFFF,

}EBOOT_RESULT;

// Baud rate
#define MTK_CBR_230400 230400
#define MTK_CBR_460800 460800
#define MTK_CBR_921600 921600
#define MTK_CBR_1500000 1500000 

typedef enum COMM_BAUDRATE
{
	BAUD2400 = CBR_2400,
	BAUD4800 = CBR_4800,
	BAUD9600 = CBR_9600,
	BAUD14400 = CBR_14400,
	BAUD19200 = CBR_19200,
	BAUD57600 = CBR_57600,	
    BAUD115200 = CBR_115200,    
	BAUD230400 = MTK_CBR_230400,
	BAUD460800 = MTK_CBR_460800,
	BAUD921600 = MTK_CBR_921600,
	BAUD1500000 = MTK_CBR_1500000
} COMM_BAUDRATE;

//for software flow control 
#define XON_CHAR               0x11
#define XOFF_CHAR              0x13
#define TRY_BOOT_TIMES         240

// The magic value to stop boot process 
#define BOOT_STOP	9876


/************************************************************************/
/* Multiport Downlaod                                                   */
/************************************************************************/
#define  COM_HANDLE	  void * 
#define  USB_HANDLE	  void * 


#ifdef	__cplusplus
extern "C" {
#endif

typedef bool (__stdcall *IS_EXIT_PERMITED)(void *usr_arg);
typedef void (__stdcall *SEND_IMAGE_FINISH)(void *usr_arg);
typedef bool (__stdcall *ENTER_MPDL_MODE_FINISH)(void *usr_arg);
typedef void (__stdcall *APPLY_ENTER_MPDL_MODE)(void *usr_arg);
typedef int  (__stdcall *GET_WCEUSB_PORT)(void *usr_arg);
typedef void (__stdcall *SET_SEND_FLASH_BIN_PERCENTAGE)(void *usr_arg, unsigned int percentage);
typedef void (__stdcall *FT_SET_SEND_FLASH_BIN_PERCENTAGE)(unsigned int percentage);
typedef bool (__stdcall *SET_USB_PROTECTED_FLAG)(void *usr_arg);

typedef void (__stdcall *ANDROID_SET_SEND_FLASH_BIN_PERCENTAGE)(void *usr_arg, unsigned int percentage);
typedef void (__stdcall *SET_SEND_IMAGE_FILES_STATUS)(void *usr_arg, const char * file_type, unsigned int num_send, unsigned int total);

typedef int (__stdcall *ANDROID_SET_DA_PERCENTAGE)(unsigned char percent, unsigned int sent_bytes, unsigned int total_bytes, void *usr_arg);
typedef int ( __stdcall *SET_DA_STATUS)(void *usr_arg);

typedef struct  {

	const char * m_binfile;
	COMM_BAUDRATE m_p_baud;
	int		   * m_p_stopflag;	
	int			 m_p_comport;

	FT_SET_SEND_FLASH_BIN_PERCENTAGE		m_p_ft_send_flash_percentage;

}FT_Download_ARG;


typedef struct  {
	
	const char * m_binfile;
	COMM_BAUDRATE m_p_baud;
	int		   * m_p_stopflag;
	int			 m_ms_wait_after_send_reboot_pattern;
	int			 m_p_comport;
	void	   * m_p_thread;
	USB_HANDLE	 m_usb_handle; // Only SP_MPDownload_Step2  need this arg
	
	//bool	   * m_p_enter_mpdl_mode_permission;	//If FALSH then can't enter mp dl mode	
										
	SET_SEND_FLASH_BIN_PERCENTAGE		m_p_send_flash_percentage;
	//APPLY_ENTER_MPDL_MODE				m_p_apply_enter_mpdl_mode;
    ENTER_MPDL_MODE_FINISH				m_p_enter_mpdl_mode_finish;

	SEND_IMAGE_FINISH					m_p_send_image_finish;
	IS_EXIT_PERMITED					m_p_is_exit_permited;
	SET_USB_PROTECTED_FLAG				m_p_set_usb_protected_flag;

}MP_Download_ARG;


//////////////////////////////////////////////////////////////////////////
//	Android Argument
//////////////////////////////////////////////////////////////////////////

/**************************************************************************
*  Modification History
*  20100728 : Wei add security flags for image lock
*  20100813 : Wei modify the struct
**************************************************************************/
/*
typedef enum
{
    VERIFY_FAIL  = 0,
    VERIFY_OK  = 1,
    VERIFY_NOT_START = 2
} IMAGE_PATCH_TYPE;
*/
typedef enum
{
    VERIFY_FAIL  = 0,
    VERIFY_OK  = 1,
    WITHOUT_VERIFY = 2,
    DOWNLOAD_NOT_START = 3
} IMAGE_PATCH_TYPE;


typedef enum
{
    LOCKED  = 0,
    NOT_LOCKED  = 1,
    LOCK_NOT_START = 2
} IMAGE_LOCK_TYPE;


typedef struct {
         DM_IMG_TYPE  image_type;     // specify which image 
         unsigned int              m_disable_download;    // if this flag is set to 0 ,uboot image will be locked; else, uboot image will be unlocked. 
         
} Image_Lock_Info_T;

#define MAX_IMG_LOCK_COUNT      (13)
#define IMAGE_LOCK_INFORM_MAGIC (0x561C652D)
typedef struct {
    UINT32                                        magic_number;
    unsigned int                                m_lockdown;            // if this flag is set to 0, all image will be locked 
    Image_Lock_Info_T                  img_info[MAX_IMG_LOCK_COUNT];
                                                                                         // u-boot , boot.img, recovery, sec_ro, system, logo, userdata ....
                                                                                         // max support 7 images
         
} SecurityBitCtrl_YuSu_T;


typedef struct {
         DM_IMG_TYPE  image_type;     // specify which image 
         unsigned int              m_verify_OK;    // if this flag is set to 1, image is verified OK; else, image is verified fail. 
         
} ImagePatch_Info_T;

typedef struct {

    ImagePatch_Info_T   img_info[MAX_IMG_LOCK_COUNT];
                                                                                         // u-boot , boot.img, recovery, sec_ro, system, logo, userdata ....
                                                                                         // max support 7 images         
} ImagePatch_Result_T;

#define SWITCH_IMAGEPATCH_STOP 0
#define SWITCH_IMAGELOCK_STOP 0
#define SWITCH_IMAGEPATCH_RESULT 1
#define SWITCH_IMAGELOCK_RESULT 1

//////////////////////////////////////////////////////////////////////////
//	Android Argument2
//////////////////////////////////////////////////////////////////////////

typedef struct  {
	
	COMM_BAUDRATE m_baud_rate;
	int			  m_comport;
	char       * m_p_comsymbol;     
	int		   * m_p_stopflag;
	void	   * m_p_thread;

}Android_Boot_ARG;

typedef struct  {	

	char *	m_path;

	DM_IMG_FORMAT	m_format;
	DM_IMG_TYPE		m_type;
	UINT32          addr_off;
	UINT32          addr_boundary;
	bool			is_download;
	bool                   is_patch;
	
}Android_Image_File;


//Now Android only have 5 file type, the number of this array 
//should associate with type DM_IMG_TYPE
//May be the file to be download is less than 5
//Add RECOVERY image and UBOOT image 
#define		ANDROID_IMAGE_FILE_NUMBER	11

typedef enum REBOOT_MODE
{
	REBOOT,
	AUTOBOOT,	
} REBOOT_MODE;

typedef enum
{
    INPUTMODE_BUFFER = 0,
    INPUTMODE_FILE
} INPUTMODE;

#define MAX_REGION_NAME_LEN     (64)
typedef struct _REGION_INFO_E
{
    char                   region_name[MAX_REGION_NAME_LEN];         /* the name of region */
    UINT32              start_addr;            /* the start address of region  */
    DM_IMG_TYPE    region_type;        /* for visible region, this type is related image type */
                                                                   /* for hidden region, this type is DM_IMG_TYPE_UNKNOWN */
    bool                is_visible;              /* is_visible is 0: this region is hidden and CANNOT download */
                                                                /* is_visible is 1: this region is visible and can download */
    bool                is_selected;           /* is_selected is 0: this partition is NOT selected to download */
                                                                 /* is_selected is 1: this partition is selected to download */
} REGION_INFO_E;


#define MAX_REGION_NUM    (20)
typedef struct  {
		
	Android_Image_File	             m_image_files[ANDROID_IMAGE_FILE_NUMBER];
	
	REGION_INFO_E                  m_region_info[MAX_REGION_NUM];
	unsigned int                            m_region_num;

	int			 usb_com;
	int		   * m_p_stopflag;
	void	   * m_p_thread;
	REBOOT_MODE			 reboot_mode;
	bool         is_verify;        /* Wei Added for Image patch */
	bool         is_boundary_Check;

	ANDROID_SET_SEND_FLASH_BIN_PERCENTAGE		m_p_send_flash_percentage;
	SET_SEND_IMAGE_FILES_STATUS			    m_p_send_image_file_status;

	SecurityBitCtrl_YuSu_T   sec_arg_result;
	ImagePatch_Result_T   patch_result;
	
}Android_Download_ARG;

typedef struct  {
		
	Android_Image_File m_image; 

	REBOOT_MODE			 reboot_mode;
	INPUTMODE                           input_mode;
	char *                      data_buffer;
	unsigned long                data_buffer_length;
	bool         is_boundary_Check;
	
	ANDROID_SET_SEND_FLASH_BIN_PERCENTAGE		m_p_send_flash_percentage;
	SET_SEND_IMAGE_FILES_STATUS			    m_p_send_image_file_status;
	
}Android_Single_Download_ARG;

typedef struct {
	unsigned int start_addr;
	unsigned char * buffer;
	unsigned int buffer_len;
}DA_PARSE_INFO_REGION_E;

typedef struct {
	unsigned short count;
	unsigned int jump_addr;
	DA_PARSE_INFO_REGION_E * da_region_list;
}DA_PARSE_INFO_E;

typedef struct  {		
//	Android_Image_File  m_DA_file;
	DA_PARSE_INFO_E m_DA_info;
	const char *	m_DA_path;

	int		   * m_p_stopflag;
	void	   * m_p_thread;
	bool         is_DA_verify;        /* Wei Added for Image patch */
	bool         is_boundary_Check;

	ANDROID_SET_DA_PERCENTAGE		             m_p_send_da_percentage;
	SET_DA_STATUS			                                        m_p_send_da_status;	
}DA_Download_ARG;


//////////////////////////////////////////////////////////////////////////
// Export  Windows Mobile Download Function
//////////////////////////////////////////////////////////////////////////
extern EBOOT_RESULT __stdcall   SP_Flash_Direct_Download(FT_Download_ARG arg);
extern EBOOT_RESULT __stdcall   SP_Flash_Download(FT_Download_ARG arg);
extern EBOOT_RESULT __stdcall   SP_BootAsMeta(int p_comport, COMM_BAUDRATE p_baud, Meta_Boot_Arg arg);
extern EBOOT_RESULT __stdcall   SP_BootAsMetaByUSB(char * p_comport_symbol, COMM_BAUDRATE p_baud, Meta_Boot_Arg arg);
extern EBOOT_RESULT __stdcall   SP_BootAsFactoryNormalMode(int p_comport, COMM_BAUDRATE p_baud, int * p_stop_flag);
extern EBOOT_RESULT __stdcall   SP_BootAsFactoryNormalModeByUSB(char * p_comport_symbol, COMM_BAUDRATE p_baud, int * p_stop_flag);
extern EBOOT_RESULT	__stdcall  SP_MPDownload(MP_Download_ARG arg);
extern EBOOT_RESULT __stdcall   SP_BootAsAdvmeta(int p_comport, COMM_BAUDRATE p_baud, Meta_Boot_Arg arg);
extern EBOOT_RESULT __stdcall   SP_BootAsAdvmetaByUSB(char * p_comport_symbol, COMM_BAUDRATE p_baud, Meta_Boot_Arg arg);

extern EBOOT_RESULT __stdcall   SP_BootAsFactoryMode(int p_comport, COMM_BAUDRATE p_baud, int * p_stop_flag);
extern EBOOT_RESULT __stdcall   SP_BootAsFactoryModeByUSB(char * p_comport_symbol, COMM_BAUDRATE p_baud, int * p_stop_flag);

extern EBOOT_RESULT __stdcall   SP_SwitchModem(int p_comport, COMM_BAUDRATE p_baud, int * p_stop_flag);
extern EBOOT_RESULT __stdcall   SP_SwitchModemByUSB(char * p_comport_symbol, COMM_BAUDRATE p_baud, int * p_stop_flag);



//////////////////////////////////////////////////////////////////////////
// Export  Android Download Function
//////////////////////////////////////////////////////////////////////////
extern EBOOT_RESULT __stdcall Android_Boot_As_Download(Android_Boot_ARG arg);
extern EBOOT_RESULT __stdcall Android_Flash_Download(Android_Boot_ARG boot_arg,
													 Android_Download_ARG * dl_arg);
extern EBOOT_RESULT __stdcall Android_DA_Download(Android_Boot_ARG boot_arg,
													 DA_Download_ARG * da_dl_arg);
													 
extern EBOOT_RESULT __stdcall Android_Set_Lock(Android_Boot_ARG boot_arg, 
						Android_Download_ARG dl_arg, SecurityBitCtrl_YuSu_T sec_arg);

//////////////////////////////////////////////////////////////////////////
// Export  Android Single Download Function
//////////////////////////////////////////////////////////////////////////
extern EBOOT_RESULT __stdcall Android_Write_Trace(Android_Boot_ARG boot_arg,
													 Android_Single_Download_ARG * dl_arg);


//////////////////////////////////////////////////////////////////////////
// Export  Android "Remote" Download Function
//////////////////////////////////////////////////////////////////////////
struct  ANDROID_DL_HANDLE;
typedef struct  ANDROID_DL_HANDLE * ANDROID_DL_HANDLE_T;

typedef int (__stdcall *CALLBACK_ANDROID_REMOTE_GET_FILE_LEN)(const char *filepath, unsigned long * const p_file_length, void *user_arg);
typedef int (__stdcall *CALLBACK_ANDROID_REMOTE_READ_FILE)(const char *filepath, char * const p_file_content, unsigned long file_length, void *user_arg);
typedef void (__stdcall * CALLBACK_ANDROID_REMOTE_GET_FILE_STATUS)(void *usr_arg, const char * file_type, unsigned int num_send, unsigned int total);

typedef struct  {      

	Android_Download_ARG                                      m_basic_arg;
	CALLBACK_ANDROID_REMOTE_GET_FILE_LEN           m_p_get_remote_file_length;
	CALLBACK_ANDROID_REMOTE_READ_FILE                  m_p_read_remote_file;
	CALLBACK_ANDROID_REMOTE_GET_FILE_STATUS   m_p_get_remote_file_status;

}Android_Remote_Download_ARG;

extern int __stdcall  Android_DL_Create(ANDROID_DL_HANDLE_T  *p_dl_handle);
extern int __stdcall  Android_DL_Destroy(ANDROID_DL_HANDLE_T  *p_dl_handle);
extern int __stdcall  Android_DL_Rom_Load(ANDROID_DL_HANDLE_T  dl_handle, 
												Android_Remote_Download_ARG * dl_arg);
extern int __stdcall  Android_DL_Rom_UnloadAll(ANDROID_DL_HANDLE_T dl_handle);

extern EBOOT_RESULT __stdcall Android_Remote_Download(ANDROID_DL_HANDLE_T  dl_handle,
								Android_Boot_ARG boot_arg, Android_Remote_Download_ARG * dl_arg);

//////////////////////////////////////////////////////////////////////////
// Export  Android "Secured" Download Function
//////////////////////////////////////////////////////////////////////////
typedef int (__stdcall *CALLBACK_ANDROID_GET_SECURED_MARK_LEN)(unsigned long * markLen);
typedef int (__stdcall *CALLBACK_ANDROID_GET_SECURED_MARK)(char * mark, const unsigned long markLen);
typedef int (__stdcall *CALLBACK_ANDROID_GET_ENCRYPT_INFO)(unsigned long * addr, unsigned long * len);
typedef int (__stdcall *CALLBACK_ANDROID_GET_DECRYPT_DATA)(char * data, const unsigned long dataLen);

typedef struct  {      

	Android_Download_ARG           m_basic_arg;
	CALLBACK_ANDROID_GET_SECURED_MARK_LEN           m_p_get_secured_mark_len;
	CALLBACK_ANDROID_GET_SECURED_MARK           m_p_get_secured_mark;
	CALLBACK_ANDROID_GET_ENCRYPT_INFO           m_p_get_encrypt_info;
	CALLBACK_ANDROID_GET_DECRYPT_DATA           m_p_get_decrypt_data;

}Android_Secured_Download_ARG;

extern EBOOT_RESULT __stdcall Android_Secured_Download(Android_Boot_ARG boot_arg,
													 Android_Secured_Download_ARG * sec_dl_arg);

//////////////////////////////////////////////////////////////////////////
// Export  Android "Advanced" Function
//////////////////////////////////////////////////////////////////////////
typedef struct  {

	REGION_INFO_E                  m_region_info[MAX_REGION_NUM];
	unsigned int                            m_region_num;
	bool                                         m_is_verify;
	bool                                         m_is_boundary_Check;


	ANDROID_SET_SEND_FLASH_BIN_PERCENTAGE		m_p_send_flash_percentage;
	SET_SEND_IMAGE_FILES_STATUS			    m_p_send_image_file_status;

	SecurityBitCtrl_YuSu_T   sec_arg_result;
	ImagePatch_Result_T   patch_result;
	
}Android_ADV_Download_ARG;

typedef struct  {

	CALLBACK_ANDROID_REMOTE_GET_FILE_LEN           m_p_get_remote_file_length;
	CALLBACK_ANDROID_REMOTE_READ_FILE                  m_p_read_remote_file;
	CALLBACK_ANDROID_REMOTE_GET_FILE_STATUS   m_p_get_remote_file_status;
	
}Android_ADV_Remote_ARG;


struct  ANDROID_ADV_HANDLE;
typedef struct  ANDROID_ADV_HANDLE * ANDROID_ADV_HANDLE_T;

extern int __stdcall  Android_ADV_Create(ANDROID_ADV_HANDLE_T  *p_dl_handle);
extern int __stdcall  Android_ADV_Destory(ANDROID_ADV_HANDLE_T  *p_dl_handle);
extern void __stdcall  Android_ADV_SetBootArg(ANDROID_ADV_HANDLE_T  dl_handle, Android_Boot_ARG boot_arg);
extern void __stdcall  Android_ADV_SetDownloadArg(ANDROID_ADV_HANDLE_T  dl_handle, Android_ADV_Download_ARG adv_dl_arg);
extern void __stdcall  Android_ADV_SetRemoteArg(ANDROID_ADV_HANDLE_T  dl_handle, Android_ADV_Remote_ARG adv_rm_arg);
extern int __stdcall  Android_ADV_LoadBuffer(ANDROID_ADV_HANDLE_T  dl_handle, Android_Image_File image);
extern int __stdcall  Android_ADV_FreeBuffer(ANDROID_ADV_HANDLE_T  dl_handle);
extern EBOOT_RESULT  __stdcall Android_ADV_SendBuffer(ANDROID_ADV_HANDLE_T  dl_handle);
extern EBOOT_RESULT __stdcall  Android_ADV_Connect(ANDROID_ADV_HANDLE_T  dl_handle);
extern EBOOT_RESULT __stdcall  Android_ADV_SendImage(ANDROID_ADV_HANDLE_T  dl_handle, Android_Image_File image);
extern EBOOT_RESULT __stdcall  Android_ADV_Reboot(ANDROID_ADV_HANDLE_T  dl_handle, REBOOT_MODE reboot_mode);


//////////////////////////////////////////////////////////////////////////
// Export Common Function
//////////////////////////////////////////////////////////////////////////
extern BOOL __stdcall GetPresentDevicePath(GUID guid,
										   const char * pPID,
										   const char * pVID,
										   unsigned long index,
										   char *pPortName,
										   unsigned long portNameLength,
										   unsigned long * portNameRealLength,
										   char *pSymbolicName,
										   unsigned long symbolicLength,
										   unsigned long * symbolicRealLength);

extern unsigned long __stdcall GetDeviceNumber(GUID guid, const char * p_pid, const char * p_vid);

extern BOOL __stdcall GetAllPresentDevicePath(GUID guid,
									   unsigned long index,
									   char *pPortName,
									   unsigned long portNameLength,
									   unsigned long * portNameRealLength,
									   char *pSymbolicName,
									   unsigned long symbolicLength,
									unsigned long * symbolicRealLength);

extern unsigned long __stdcall GetAllDeviceNumber(GUID guid);

extern void __stdcall GetPortsDriverVersion(void);



extern int __stdcall  CloseActiveSync( void );
extern int __stdcall  RestartActiveSync(char * wcescomm_path);
extern int __stdcall  StopServiceT( char  *szSerName );


extern void __stdcall   Eboot_Log( const char * pstr_log );
extern int  __stdcall   Eboot_DebugClear( void );
extern int  __stdcall   Eboot_DebugOn( void );
extern int  __stdcall   Eboot_DebugOff( void );
extern int  __stdcall   Eboot_GetDLLInfo(const char **pp_version, const char **pp_release_type, const char **pp_build_date, const char **pp_load_path);
extern int  __stdcall   Eboot_DebugChangePath(const char * path);

#ifdef	__cplusplus
}
#endif

#endif //_EBOOT_INTERFACE_H_












































