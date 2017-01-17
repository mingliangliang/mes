#ifndef SPMETA_DLL_H
#define SPMETA_DLL_H


#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------------------------------//
//  META General                                                            //
//--------------------------------------------------------------------------//

//-----------------------------------------------------//
//  META General: data structure definition            //
//-----------------------------------------------------//
//namespace SPMETA_DLL
//{



#define STATUS_OK_DIRVER		1
#define STATUS_FAIL_DIRVER		0
#define STATUS_OK_DVB			1
#define STATUS_FAIL_DVB			0



#define STATUS_OK_FT			0
#define STATUS_FAIL_FT			1


typedef enum
{
	// META_DLL received a corrupted frame
	META_CNF_FRAME_ERROR = 0,

	// META_DLL received a confirm or indication from target,
	// but there is not corresponding call back function
	// installed for this confirm or indication.
	META_CNF_NO_CALLBACK = 1,

	// META_DLL received a corrupted primitive.
	META_CNF_PRIMITIVE_ERROR = 2,

	// META_DLL received a confirm or indication from
	// target, but there is no sufficient memory to process.
	META_CNF_NO_MEMORY = 3,

	// META_DLL retrieved a callback function, however,
	// the user input arguments are invalid.
	META_CNF_CALLBACK_PARAMETER_ERROR = 4,

	// META_DLL received a confirm with peer msg, however,
	// the peer msg is corrupted.
	META_CNF_PEER_MSG_ERROR = 5,

	// META_DLL received a confirm and successfully executed
	// the callback function.
	META_CNF_OK = 6,
	META_CNF_FT_STATUS_ERROR = 7
} META_CNF_ERR_CODE;

// The magic value to stop usb enumerate process 
#define ENUM_USB_STOP	9876

typedef enum
{
	META_SUCCESS = 0
	,META_FAILED
	,META_COMM_FAIL
	,META_NORESPONSE
	,META_BUFFER_LEN
	,META_FILE_BAD
	,META_LID_INVALID
	,META_INTERNAL_DB_ERR
	,META_NO_MEMORY
	,META_INVALID_ARGUMENTS
	,META_TIMEOUT
	,META_BUSY
	,META_INVALID_HANDLE
	,META_FAT_ERROR
	,META_FAT_DISK_FULL
	,META_FAT_ROOT_DIR_FULL
	,META_FAT_INVALID_FILENAME
	,META_FAT_INVALID_FILE_HANDLE
	,META_FAT_FILE_NOT_FOUND
	,META_FAT_DRIVE_NOT_FOUND
	,META_FAT_PATH_NOT_FOUND
	,META_FAT_ACCESS_DENIED
	,META_FAT_TOO_MANY_FILES
	,META_INCORRECT_TARGET_VER
	,META_COM_ERROR
	,META_BROM_CMD_ERROR
	,META_INCORRECT_BBCHIP_TYPE
	,META_BROM_ERROR
	,META_STOP_BOOTUP_PROCEDURE
	,META_CANCEL
	,META_CCT_NOT_IMPORT_PROFILE
	,META_CCT_INVALID_SENSOR_ID
	,META_CCT_TGT_NO_MEM_FOR_SINGLE_SHOT
	,META_CCT_TGT_NO_MEM_FOR_MULTI_SHOT
	,META_FUNC_NOT_IMPLEMENT_YET
	,META_CCT_NOT_IMPLEMENT_YET = META_FUNC_NOT_IMPLEMENT_YET
	,META_CCT_PREVIEW_ALREADY_STARTED
	,META_CCT_PREVIEW_ALREADY_STOPPED
	,META_CCT_READ_REG_NO_CNF
	,META_CCT_WRITE_REG_NO_CNF
	,META_CCT_TGT_ABORT_IMAGE_SENDING
	,META_CCT_READ_ONLY_REGISTER
	,META_CCT_LOAD_FROM_NVRAM_FAIL
	,META_CCT_SAVE_TO_NVRAM_FAIL
	,META_CCT_AE_INVALID_EC_LEVEL
	,META_CCT_AE_INVALID_EC_STEP
	,META_CCT_AE_ALREADY_ENABLED
	,META_CCT_AE_ALREADY_DISABLED
	,META_CCT_WB_INVALID_INDEX
	,META_CCT_NO_TGT_SENSOR_MATCH_IN_PROFILE
	,META_CCT_IMAGE_SENDING_FAME_NUM_ERROR
	,META_CCT_AE_IS_NOT_DISABLED
	,META_FAT_APP_QUOTA_FULL
	,META_IMEI_CD_ERROR
	,META_RFID_MISMATCH
	,META_NVRAM_DB_IS_NOT_LOADED_YET
	,META_CCT_ERR_CAPTURE_WIDTH_HEIGHT_TOO_SMALL
	,META_WAIT_FOR_TARGET_READY_TIMEOUT
	,META_CCT_ERR_SENSOR_ENG_SET_INVALID_VALUE
	,META_CCT_ERR_SENSOR_ENG_GROUP_NOT_EXIST
	,META_CCT_NO_TGT_ISP_MATCH_IN_PROFILE
	,META_CCT_TGT_ISP_SUPPORT_NOT_DEFINED
	,META_CCT_ERR_SENSOR_ENG_ITEM_NOT_EXIST
	,META_CCT_ERR_INVALID_COMPENSATION_MODE
	,META_CCT_ERR_USB_COM_NOT_READY
	,META_CCT_DEFECTPIXEL_CAL_UNDER_PROCESSING
	,META_CCT_ERR_DEFECTPIXEL_CAL_NO_MEM
	,META_CCT_ERR_TOO_MANY_DEFECT_PIXEL
	,META_CCT_ERR_CAPTURE_JPEG_FAIL
	,META_CCT_ERR_CAPTURE_JPEG_TIMEOUT
	,META_CCT_ERR_AF_FAIL
	,META_CCT_ERR_AF_TIMEOUT
	,META_CCT_ERR_AF_LENS_OFFSET_CAL_FAIL
	,META_CCT_ERR_PREVIEW_MUST_ENABLE
	,META_CCT_ERR_UNSUPPORT_CAPTURE_FORMAT
	,META_CCT_ERR_EXCEED_MAX_DEFECT_PIXEL
	,META_ERR_EXCEED_MAX_PEER_BUF_SIZE
	,META_CCT_ERR_INVALID_WIDTH_FACTOR
	,META_BROM_SECURITY_CHECK_FAIL
	,META_CCT_ERR_PREVIEW_MUST_DISABLE
	,META_MAUI_DB_INCONSISTENT
	,META_FAT_FILEPATH_TOO_LONG
	,META_FAT_RESTRICTED_FILEPATH
	,META_FAT_DIR_NOT_EXIST
	,META_FAT_DISK_SPACE_IS_NOT_ENOUGH
	,META_TDMB_ERR_BAND_NOT_EXIST
	,META_TDMB_ERR_FREQ_NOT_EXIST
	,META_TDMB_ERR_ENSM_NOT_EXIST
	,META_TDMB_ERR_SERV_NOT_EXIST
	,META_TDMB_ERR_SUB_CHAN_NOT_EXIST
	,META_TDMB_ERR_DEMOD_STATE
	,META_PERMISSION_DENIED
	,META_ENUMERATE_USB_FAIL
  ,META_STOP_ENUM_USB_PROCEDURE
   //----------------[TH] for CCT 6238--------------------------
  ,META_CCT_6238_AE_ALREADY_ENABLED
  ,META_CCT_6238_AE_ALREADY_DISABLED
  ,META_CCT_6238_AE_IS_NOT_DISABLED
  ,META_CCT_6238_ISP_FLASHLIGHT_LINEARITY_PRESTROBE_FAIL
  //-----------------------------------------------------------
  ,META_NOT_SUPPORT
  ,META_LAST_RESULT
} META_RESULT;

typedef enum  {
	META_BAUD2400 = 0,
	META_BAUD4800,
	META_BAUD9600,
	META_BAUD14400,
	META_BAUD19200,
	META_BAUD57600,   // 5
	META_BAUD115200,
	META_BAUD230400,
	META_BAUD460800,
	META_BAUD921600,
	META_BAUD1500000,            //10
	META_BAUD_END = 0xFF
} META_COMM_BAUDRATE;

typedef enum {
	META_NO_FLOWCTRL = 0,	// no flow control
	META_SW_FLOWCTRL,		// enable S/W flow control
	META_FLOWCTRL_END
} META_FLOWCTRL;

typedef struct {
	char	BB_CHIP[64];	// BaseBand chip version
	char	ECO_VER[4];		// ECO version
	char	SW_TIME[64];
	char	DSP_FW[64];		// DSP firmware version
	char	DSP_PATCH[64];	// DSP patch version
	char	SW_VER[64];		// S/W version
	char	HW_VER[64];		// H/W board version
	char	MELODY_VER[64];	// Melody version
	unsigned char status;
} VerInfo_Cnf;

typedef struct {
	char	BB_CHIP[64];	// BaseBand chip version
	char	ECO_VER[4];		// ECO version
	char	SW_TIME[64];
	char	DSP_FW[64];		// DSP firmware version
	char	DSP_PATCH[64];	// DSP patch version
	char	SW_VER[64];		// S/W version
	char	HW_VER[64];		// H/W board version
	char	MELODY_VER[64];	// Melody version
	char	BUILD_DISP_ID[64];  //build version
	unsigned char status;
} VerInfo_V2_Cnf;


typedef struct {
	char	code_func[64];	
	char	code_proj[64];		
	char	code_date[64];
	char	code_fab[64];		
	unsigned char status;
} ChipInfo_Cnf;

typedef struct
{
	unsigned short      com_port_list[255];   
	unsigned short      com_port_num;
	unsigned int		ms_connect_timeout; // [META] META enumerate port timeout value 

}META_Enumerate_USB_Req;

typedef struct {
	int 				com_port;
	META_COMM_BAUDRATE  baudrate[12];		// [META] META stage baudrate polling array, it must end with META_BAUD_END. 
	META_FLOWCTRL  		flowctrl;			// [META] META stage uart flow control type. 
	unsigned int		ms_connect_timeout; // [META] META stage sync timeout value (after BootROM negotiation pass) 
} META_Connect_Req;

typedef struct {
	META_COMM_BAUDRATE  final_baudrate;					// [META] Detected META stage baudrate.     
	unsigned int		meta_ver_required_by_target;	// [META] Target required META_DLL version. 
} META_Connect_Report;

typedef struct {
	int 				com_port;
	unsigned int		ms_connect_timeout; // [META] META stage sync timeout value (after BootROM negotiation pass) 
} META_ConnectByUSB_Req;

typedef struct {
	unsigned int		meta_ver_required_by_target;	// [META] Target required META_DLL version. 
} META_ConnectByUSB_Report;

typedef struct {
	int 				com_port;
	META_COMM_BAUDRATE  baudrate[11];		// [META] META stage baudrate polling array, it must end with META_BAUD_END. 
	META_FLOWCTRL  		flowctrl;			// [META] META stage uart flow control type. 
	unsigned int		ms_connect_timeout; // [META] META stage sync timeout value (after BootROM negotiation pass) 
}WM_META_ConnectInMETA_Req;


typedef struct {
	META_COMM_BAUDRATE  final_baudrate;					// [META] Detected META stage baudrate. 
	unsigned int		meta_ver_required_by_target;	// [META] Target required META_DLL version. 
}WM_META_ConnectInMETA_Report;



//-----------------------------------------------------//
//  META General: callback function definition         //
//-----------------------------------------------------//
typedef void (__stdcall *META_Error_CallBack)(const META_CNF_ERR_CODE  mr);
typedef void (__stdcall *META_SysTrace_CallBack)(const char *sys_trace);
typedef void (__stdcall *META_GET_VERSION_INFO_CNF)(const VerInfo_Cnf  *cnf, const short token, void *usrData);
typedef void (__stdcall *META_GET_VERSION_INFO_V2_CNF)(const VerInfo_V2_Cnf  *cnf_v2, const short token, void *usrData);
typedef void (__stdcall *META_GET_CHIP_INFO_CNF)(const ChipInfo_Cnf  *cnf, const short token, void *usrData);

//-----------------------------------------------------//
//  META for CTI                                       //
//-----------------------------------------------------//
typedef enum {
	 CTI_OK = 0
	,CTI_MISSING_HEADER
	,CTI_CORRUPTED_FAME
	,CTI_EXCEED_LEN
} CTI_RET_ENUM;

typedef void (__stdcall *META_CTI_CallBack)(CTI_RET_ENUM  ret, const int size, const unsigned char *data, void *param);

//-----------------------------------------------------//
//  Switch TST message format                          //
//-----------------------------------------------------//
typedef enum {
	META_TST_MSG_2G = 0,
	META_TST_MSG_3G
} META_TST_MSG_FORMAT;

META_RESULT  __stdcall SP_META_SetTstMsgFormat(META_TST_MSG_FORMAT  msg_fmt);
META_RESULT  __stdcall SP_META_SetTstMsgFormat_r(const int meta_handle, META_TST_MSG_FORMAT  msg_fmt);

//-----------------------------------------------------//
//  META Debug: exported debug function definition     //
//-----------------------------------------------------//
META_RESULT  __stdcall SP_META_DebugOn();
META_RESULT  __stdcall SP_META_DebugOn_ex(const int meta_handle);
META_RESULT  __stdcall SP_META_DebugOff();
META_RESULT  __stdcall SP_META_DebugClear();
META_RESULT  __stdcall SP_META_DebugOnThePath(const char * path);

//-----------------------------------------------------//
//  META UnitTest                                      //
//-----------------------------------------------------//

/*
typedef struct {
	unsigned int	m_TestCaseID;
	const char *	m_pDescription;
} META_UT_TestCaseID_T;
*/

//void __stdcall META_QueryTestCase(META_UT_TestCaseID_T  **ppTestCase, unsigned int  *pTestCaseCount);
//void __stdcall META_UnitTest(const unsigned int  *p_TestCaseID_Array, unsigned int  TestCaseCount);

//-----------------------------------------------------//
//  META General: exported function definition         //
//-----------------------------------------------------//

#define     FT_MT_UNKNOWN  0
#define     FT_MT6305  1
#define     FT_MT6318  2 
#define     FT_MT6326  3
typedef struct {
	unsigned char	id;
} PMIC_ID;
typedef struct {
	unsigned int	pcl;
} RF_GetITC_PCL;
// General 

void  __stdcall SP_META_GetDLLVer(unsigned int *major_ver, unsigned int *minor_ver, unsigned int *build_num, unsigned int *patch_num);
void  __stdcall SP_META_GetDLLInfo(const char **pp_version, const char **pp_release_type, const char **pp_build_date, const char **pp_load_path);
void  __stdcall SP_META_Cancel(const short token);
void  __stdcall SP_META_Cancel_r(const int meta_handle, const short token);
void  __stdcall SP_META_CancelAllBlockingCall(void);
void  __stdcall SP_META_CancelAllBlockingCall_r(const int meta_handle);

META_RESULT  __stdcall SP_META_QueryIfFunctionSupportedByTarget(unsigned int ms_timeout, const char *query_func_name);
META_RESULT  __stdcall SP_META_QueryIfFunctionSupportedByTarget_r(const int meta_handle, unsigned int ms_timeout, const char *query_func_name);


META_RESULT  __stdcall SP_META_QuerySpeakerCalibrationSupport(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_QuerySpeakerCalibrationSupport_r(const int meta_handle, unsigned int ms_timeout);

META_RESULT  __stdcall SP_META_QueryIfTargetIsLowCostSingleBankFlash(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_QueryIfTargetIsLowCostSingleBankFlash_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_QueryPMICID(unsigned int  ms_timeout, PMIC_ID  *cnf);
META_RESULT  __stdcall SP_META_QueryPMICID_r(const int meta_handle, unsigned int  ms_timeout, PMIC_ID  *cnf);
META_RESULT  __stdcall SP_META_QueryITC_PCL(unsigned int  ms_timeout, RF_GetITC_PCL  *cnf);
META_RESULT  __stdcall SP_META_QueryITC_PCL_r(const int meta_handle, unsigned int  ms_timeout, RF_GetITC_PCL  *cnf);
META_RESULT  __stdcall SP_META_QueryIfTargetSupportDRC(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_QueryIfTargetSupportDRC_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_QueryIfBTPowerOn(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_QueryIfBTPowerOn_r(const int meta_handle, unsigned int ms_timeout);
// META_RESULT  __stdcall SP_META_BTOpen(unsigned int ms_timeout);
// META_RESULT  __stdcall SP_META_BTOpen(const int meta_handle, unsigned int ms_timeout);

//-----------------------------------------------------//
//  UTILITY--ENABLE WATCHDOG				           //
//-----------------------------------------------------//
#define GPIO_DEV_LED_MAINLCD 0
//#define GPIO_DEV_LED_SUBLCD 1

typedef struct  {
	unsigned char			lcd_light_level;
}LCDLevel_REQ;

typedef struct  {
	int			status;
}LCDLevel_CNF;

typedef struct  {
	int				onoff;
	char					DIV;
	char					DUTY;
}KeypadBK_REQ;

typedef struct  {
	int			status;
}KeypadBK_CNF;

typedef struct{
    unsigned int LedNum;
    int  OFFON;
}NLED_REQ;

typedef struct{
    int ret;
}NLED_CNF;

typedef struct{
   int 	Notused;
}SetCleanBootFlag_REQ;

typedef struct{
   int 	drv_status;
}SetCleanBootFlag_CNF;



typedef struct  {
	unsigned short		interval;
}WatchDog_REQ;

typedef struct  {
	unsigned short		rtc_sec;    
	unsigned short		rtc_min;    
	unsigned short		rtc_hour;   
	unsigned short		rtc_day;    
	unsigned short		rtc_mon;    
	unsigned short		rtc_wday;  
	unsigned short		rtc_year;  
	unsigned short		status;
}WatchDog_CNF;


//META_RESULT  __stdcall META_EnableWatchDogTimer(unsigned int ms_timeout, FtWatchDog *req);
//META_RESULT  __stdcall META_EnableWatchDogTimer_r(const int meta_handle, unsigned int ms_timeout, FtWatchDog *req);


META_RESULT  __stdcall SP_META_SetLEDLightLevelforMT6573(unsigned int ms_timeout, NLED_REQ *req);
META_RESULT  __stdcall SP_META_SetLEDLightLevelforMT6573_r(const int meta_handle, unsigned int ms_timeout, NLED_REQ *req);
META_RESULT  __stdcall SP_META_SetVibratorOnOff(unsigned int ms_timeout, NLED_REQ *req);
META_RESULT  __stdcall SP_META_SetVibratorOnOff_r(const int meta_handle, unsigned int ms_timeout, NLED_REQ *req);
META_RESULT  __stdcall SP_META_SetSignalIndicatorOnOff(unsigned int ms_timeout, NLED_REQ *req);
META_RESULT  __stdcall SP_META_SetSignalIndicatorOnOff_r(const int meta_handle, unsigned int ms_timeout, NLED_REQ *req);
META_RESULT  __stdcall SP_META_QueryLocalTime(unsigned int  ms_timeout, WatchDog_CNF  *cnf);
META_RESULT  __stdcall SP_META_QueryLocalTime_r(const int meta_handle, unsigned int  ms_timeout, WatchDog_CNF  *cnf);
META_RESULT  __stdcall SP_META_SetMainSubLCDLightLevel(unsigned int ms_timeout, LCDLevel_REQ *req);
META_RESULT  __stdcall SP_META_SetMainSubLCDLightLevel_r(const int meta_handle, unsigned int ms_timeout, LCDLevel_REQ *req);
// timer-related APIs
META_RESULT  __stdcall SP_META_StartTimer();
META_RESULT  __stdcall SP_META_StartTimer_r(const int meta_handle);
META_RESULT  __stdcall SP_META_StopTimer();
META_RESULT  __stdcall SP_META_StopTimer_r(const int meta_handle);
META_RESULT  __stdcall SP_META_GetProcessTime(unsigned int  *pProcessTime, unsigned short *pNumAPIs);
META_RESULT  __stdcall SP_META_GetProcessTime_r(const int meta_handle, unsigned int *pProcessTime, unsigned short *pNumAPIs);
const char * __stdcall SP_META_GetErrorString(META_RESULT  ErrCode);
const char * __stdcall SP_META_BaudrateEnumToName(META_COMM_BAUDRATE  baudrate);
// Initialization 
META_RESULT  __stdcall SP_META_GetAvailableHandle(int *p_meta_handle);
META_RESULT  __stdcall SP_META_Init(const META_Error_CallBack  cb);
META_RESULT  __stdcall SP_META_Init_r(const int meta_handle, const META_Error_CallBack  cb);
META_RESULT  __stdcall SP_META_SetSysTraceCallback(const META_SysTrace_CallBack  sys_cb);
META_RESULT  __stdcall SP_META_SetSysTraceCallback_r(const int meta_handle, const META_SysTrace_CallBack  sys_cb);
void  __stdcall SP_META_Deinit(void);
void  __stdcall SP_META_Deinit_r(int *p_meta_handle);


// connect with target 
META_RESULT  __stdcall SP_META_ConnectWithTarget(const META_Connect_Req  *req, int *p_bootstop, META_Connect_Report  *p_report);
META_RESULT  __stdcall SP_META_ConnectWithTarget_r(const int meta_handle, const META_Connect_Req  *req, int *p_bootstop, META_Connect_Report  *p_report);
// disconnect and shutdown target
META_RESULT  __stdcall SP_META_DisconnectWithTarget(void);
META_RESULT  __stdcall SP_META_DisconnectWithTarget_r(const int meta_handle);

// connect with target when target already in meta mode 
META_RESULT  __stdcall SP_META_ConnectInMetaMode(const WM_META_ConnectInMETA_Req  *req, int *p_bootstop, WM_META_ConnectInMETA_Report  *p_report);
META_RESULT  __stdcall SP_META_ConnectInMetaMode_r(const int meta_handle, const WM_META_ConnectInMETA_Req  *req, int *p_bootstop, WM_META_ConnectInMETA_Report  *p_report);

// disconnect without shutdown target
META_RESULT  __stdcall SP_META_DisconnectInMetaMode(void);
META_RESULT  __stdcall SP_META_DisconnectInMetaMode_r(const int meta_handle);

// USB-related connect
META_RESULT  __stdcall SP_META_ConnectInMetaModeByUSB(const META_ConnectByUSB_Req  *req, int *p_bootstop, META_ConnectByUSB_Report  *p_report);
META_RESULT  __stdcall SP_META_ConnectInMetaModeByUSB_r(const int meta_handle, const META_ConnectByUSB_Req  *req, int *p_bootstop, META_ConnectByUSB_Report  *p_report);

META_RESULT  __stdcall SP_META_ConnectWithTargetByUSB(const META_ConnectByUSB_Req  *req, int *p_bootstop, META_ConnectByUSB_Report  *p_report);
META_RESULT  __stdcall SP_META_ConnectWithTargetByUSB_r(const int meta_handle, const META_ConnectByUSB_Req  *req, int *p_bootstop, META_ConnectByUSB_Report  *p_report);
META_RESULT  __stdcall SP_META_GetDynamicUSBComPort(unsigned int ms_scan_timeout, unsigned short *com_port, int *p_scanstop);
META_RESULT  __stdcall SP_META_GetDynamicUSBComPort_r(const int meta_handle, unsigned int ms_scan_timeout, unsigned short *com_port, int *p_scanstop);

// Get target S/W, H/W and Melody version
META_RESULT  __stdcall SP_META_GetTargetVerInfo(const META_GET_VERSION_INFO_CNF  cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_GetTargetVerInfo_r(const int meta_handle, const META_GET_VERSION_INFO_CNF  cb, short *token, void *usrData);


// Get target S/W, H/W, melody and build version
META_RESULT  __stdcall SP_META_GetTargetVerInfoV2(VerInfo_V2_Cnf  *cnf_v2, short *token, void *usrData);
META_RESULT  __stdcall SP_META_GetTargetVerInfoV2_r(const int meta_handle, VerInfo_V2_Cnf  *cnf_v2, short *token, void *usrData);

// Get Chip Info
META_RESULT  __stdcall SP_META_GetTargetChipInfo(const META_GET_CHIP_INFO_CNF  cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_GetTargetChipInfo_r(const int meta_handle, const META_GET_CHIP_INFO_CNF  cb, short *token, void *usrData);

// Get build properity
typedef struct
{
    unsigned char tag[64];
    
} BUILD_PROP_REQ_S;

typedef struct
{
    unsigned char content[128];
    
} BUILD_PROP_CNF_S;

META_RESULT  __stdcall SP_META_GetTargetBuildProp(BUILD_PROP_REQ_S * pReq, BUILD_PROP_CNF_S * pCnf);
META_RESULT  __stdcall SP_META_GetTargetBuildProp_r(const int meta_handle, BUILD_PROP_REQ_S * pReq, BUILD_PROP_CNF_S * pCnf);


// Shutdown target 
META_RESULT  __stdcall SP_META_ShutDownTarget(void);
META_RESULT  __stdcall SP_META_ShutDownTarget_r(const int meta_handle);

// Close Com Port
META_RESULT  __stdcall SP_META_CloseComPort(void);
META_RESULT  __stdcall SP_META_CloseComPort_r(const int meta_handle);

// Close Com Port and reboot
META_RESULT  __stdcall SP_META_CloseComPortReboot(void);
META_RESULT  __stdcall SP_META_CloseComPortReboot_r(const int meta_handle);

META_RESULT  __stdcall SP_META_RebootTarget(unsigned int delay);
META_RESULT  __stdcall SP_META_RebootTarget_r(const int meta_handle,unsigned int delay);

// ***** Expired Functions -- BEGIN ***** //
// these functions are expired, we encourage you to use META_ConnectWithTarget and META_DisconnectWithTarget 
META_RESULT  __stdcall SP_META_COMM_Set_Baudrate(const META_COMM_BAUDRATE  baudrate);
META_RESULT  __stdcall SP_META_COMM_Set_Baudrate_r(const int meta_handle, const META_COMM_BAUDRATE  baudrate);
META_RESULT  __stdcall SP_META_COMM_Start(const int comm_port, const META_FLOWCTRL  flowctrl);
META_RESULT  __stdcall SP_META_COMM_Start_r(const int meta_handle, const int comm_port, const META_FLOWCTRL  flowctrl);
META_RESULT  __stdcall SP_META_COMM_Stop(void);
META_RESULT  __stdcall SP_META_COMM_Stop_r(const int meta_handle);
META_RESULT  __stdcall SP_META_WaitForTargetReady(unsigned int ms_waiting_time, unsigned int request_count);
META_RESULT  __stdcall SP_META_WaitForTargetReady_r(const int meta_handle, unsigned int ms_waiting_time, unsigned int request_count);
META_RESULT  __stdcall SP_META_GetTargetRequiredMetaVer(unsigned int *p_meta_ver_required_by_target);
META_RESULT  __stdcall SP_META_GetTargetRequiredMetaVer_r(const int meta_handle, unsigned int *p_meta_ver_required_by_target);


META_RESULT  __stdcall SP_META_SetVersionInfo(VerInfo_Cnf *vinfo);

META_RESULT  __stdcall SP_META_BackupEFuseToFile( unsigned int ms_timeout, char * path);
META_RESULT  __stdcall SP_META_BackupEFuseToFile_r(const int meta_handle, unsigned int ms_timeout,char * path);


// ***** Expired Functions -- END ***** //

//--------------------------------------------------------------------------//
//  3G RF Testing                                                           //
//--------------------------------------------------------------------------//

//-----------------------------------------------------//
//  3G RF Testing: data structure definition           //
//-----------------------------------------------------//
typedef enum {
	URF_TEST_CMD_TXACCESS = 0
	,URF_TEST_CMD_STOP
	,URF_TEST_CMD_TX_DPCH
	,URF_TEST_CMD_RX_DPCH
	,URF_TEST_CMD_RSSI
	,URF_TEST_CMD_RSCP
	,URF_TEST_CMD_AFC
	,URF_TEST_CMD_TX_PAAPC  // for calling UL1D_RF_SetPaApcDac in FT task
	,URF_TEST_CMD_GET_RFID
	,URF_TEST_CMD_CONFIG_HWTPC
	,URF_TEST_CMD_GET_PWR_DT_STEP
	,URF_TEST_CMD_GET_PWR_DT_DAC
	,URF_TEST_CMD_GET_PWR_DT_DEFAULT_THR
	,URF_TEST_CMD_SET_IMMEDIATE_BSI
	,URF_TEST_CMD_GET_IMMEDIATE_BSI
	,URF_TEST_CMD_END
}URfTestCmdType;

typedef struct {
	unsigned short	uarfcn;			//kal_int16
	short			psc;			//kal_int16
	unsigned short	signature;	    //kal_uint16
	unsigned char	pa_mode;		//unsigned char
	char			init_power;		//kal_int8
	unsigned char   power_step;     //kal_uint8	
	unsigned char	max_retrans;	//kal_uint8
}URfTestCmdTxAccess;
typedef struct
{
	//unsigned short	dl_freq;
	unsigned short	ul_freq;
	short	psc;		/* 0~511. */
	unsigned int	sc_code;	/* Scrambling code #. 0 ~ 16777215 */
	unsigned char   power_ctrl_mode;
	unsigned char 	pa_mode;
	unsigned short 	idx;
	unsigned short	afc_dac;
	unsigned char	dpcch_pwr;
	unsigned char	dpdch_pwr;
	
	/* Below for UL1D_RF_Meta_SetTxInfo. */
	bool 	no_loop_ctrl;
	
	/* Below for setPaApcDac. */	
	unsigned char 	rf_band;
	unsigned char   vm1;
    unsigned char   vm2;
	unsigned short  dc2dc_dac;
    unsigned short  vbias_dac;
	bool            pwr_det;
	unsigned short 	apc_dac;		
} URfTestCmdTxDPCh;	//Anthony  target side is :UL1TSTCmdTxDPCh and  URfTestCmdTxDPCh

typedef struct
{
	unsigned short	dl_freq;
	short	psc;	/* 0~511. */
	unsigned char	ssc;	/* 0~15. */
	short	ovsf;	/* 0~sf-1. */
	unsigned short	afc_dac;
	
	/* Below for RF_SetBBRxParams. */
	bool 	hwAGC;
	unsigned char	mode;		/* 0: mode0, 1: mode1. */
	short	gain;		/* mode0. */
	unsigned char	LNAmode;	 /* mode1. 0: LNA high, 1: LNA mid, 2: LNA low. */
	unsigned short	pga;		/* mode1. */
} URfTestCmdRxDPCh;
#define MAX_FREQ_LIST 36
typedef struct
{
	unsigned char	num_freq;
	unsigned short	dl_freq[ MAX_FREQ_LIST ];
	unsigned char   temperature;
	
	/* Below for RF_SetBBRxParams. */
	bool 	hwAGC;
	unsigned char	mode;		/* 0: mode0, 1: mode1. */
	short	gain;		/* mode0. */
	unsigned char	LNAmode;	/* mode1. 0: LNA high, 1: LNA mid, 2: LNA low. */
	unsigned short	pga;		/* mode1. */
} URfTestCmdRSSI;

typedef struct
{
	bool	pscan_before_cell_search;	/* True if UL1TST needs power scan before cell search/RSCP. */
	unsigned short	dl_freq;	/* Specific dl_freq to do cell search. Valid if pscan_before_cell_search=F. */
	unsigned char	sample_num_per_cell;
	bool	read_sfn;	/* True if we need to do SFN measurement for the found cell. */
	
	/* Below for RF_SetBBRxParams. */
	bool 	hwAGC;
	unsigned char	mode;		/* 0: mode0, 1: mode1. */
	short	gain;		/* mode0. */
	unsigned char	LNAmode;	/* mode1. 0: LNA high, 1: LNA mid, 2: LNA low. */
	unsigned short	pga;		/* mode1. */
} URfTestCmdRSCP;

typedef struct
{
	//kal_bool	pscan_before_cell_search;	/* True if UL1TST needs power scan before cell search/RSCP. */
	short	        dl_freq;	/* Specific dl_freq to do cell search. Valid if pscan_before_cell_search=F. */
	//kal_uint8	sample_num_per_cell;
	//kal_bool	read_sfn;	/* True if we need to do SFN measurement for the found cell. */
	
	short           afc_dac;    //anthony 0514
	
	/* Below for RF_SetBBRxParams. */
	bool 	        hwAGC;
	unsigned char	mode;		/* 0: mode0, 1: mode1. */
	short	        gain;		/* mode0. */
	unsigned char	LNAmode;	/* mode1. 0: LNA high, 1: LNA mid, 2: LNA low. */
	unsigned short	pga;		/* mode1. */

} URfTestCmdAFC;

typedef struct
{
	char            m_cRfBand;    // only 0 ~ 5
    unsigned short  m_u2Idx;
	unsigned char   m_ucPaMode;
//	unsigned short m_u2PaDac;
	unsigned char    m_ucVm1;
	unsigned char    m_ucVm2;
	unsigned short   m_u2DC2DC_Dac;
	unsigned short   m_u2Vbias_Dac;
	unsigned short   m_u2ApcDac;

}UL1D_RF_TX_PA_APC_REQ_T;


typedef struct
{
   // structure of META_HWTPC_FRAME_INFO in target
   unsigned char tpc_step;
   unsigned char itp;
   unsigned char rpp;
   unsigned char fmt_idx;
   unsigned char dl_frame_type;
   unsigned short slot_mask;
   char   tpc_cmd[15];
   unsigned char  beta_c;
   unsigned char  beta_d;

}UL1D_RF_HWTPC_FRAME_INFO;

typedef struct
{
   unsigned char pc_algo;
   unsigned char tpc_used_frame;  // at most 8 so far
   short  p_ini;

   UL1D_RF_HWTPC_FRAME_INFO frame_info[8];
   
}UL1D_RF_HWTPC_CONFIG_REQ_T;


typedef struct
{
	unsigned char rf_band;

}UL1D_RF_GET_PWR_THR_REQ_T;

typedef struct
{
    unsigned int bsi_data;
}UL1D_RF_SET_BSI_DATA_REQ_T;

typedef struct
{
    unsigned int bsi_addr;
}UL1D_RF_GET_BSI_DATA_REQ_T;



typedef union {
	URfTestCmdTxAccess         txaccess;
	URfTestCmdTxDPCh	txdpch;	//Anthony
	URfTestCmdRxDPCh	rxdpch;
	URfTestCmdRSSI		rssi;
	URfTestCmdRSCP		rscp;
	URfTestCmdAFC       afc;
    UL1D_RF_TX_PA_APC_REQ_T    m_rTxPaApc;
	UL1D_RF_HWTPC_CONFIG_REQ_T  m_rHWTPC;
	UL1D_RF_GET_PWR_THR_REQ_T   m_rGetPwrThr;
}URfTestCmdParam;

typedef struct
{
	bool	ok;
	unsigned char	num_freq;
	short	dl_freq[ MAX_FREQ_LIST ];
	int	rssi[ MAX_FREQ_LIST ];	
} URfTestResultRSSI;



typedef struct
{	
	unsigned short	psc;		/* Primary scrambling code */
	int	tm;		/* Cell frame boundary offset to LST */
	short	off;		/* Cell frame number offset to LST */	
	bool	sttd; 		/* True for STTD used. */
	unsigned char	sample_num;
	unsigned char	rscp_sum;
	short freq_error;  // 20070514
} UL1TST_cpich_result_T;

#define MAX_NUM_MEAS_CELL 32
typedef struct
{
	bool		ok;
	unsigned char		num_cell;
	UL1TST_cpich_result_T	cpich_result[ MAX_NUM_MEAS_CELL ];	
} URfTestResultRSCP;

typedef struct
{
	bool	        ok;
	unsigned short	psc;		/* Primary scrambling code */
	int	            tm;		/* Cell frame boundary offset to LST */
	bool	        sttd; 		/* True for STTD used. */
	unsigned char	rscp_sum;
	short           freq_error;	//anthony 0514    

}URfTestResultAFC;

typedef struct
{
	bool	ok;
	unsigned int	ber;	/* Spec requirement=10^-3. We will count 10^5 frames(100 times spec requirement) for BER calculation. Only count for the only TRCh for DPDCh. */
} URfTestResultRxDPCh;

#define  UL1D_RF_ID_SONY_CXA3359    0x00000001
#define  UL1D_RF_ID_MT6159B         0x00000002
#define  UL1D_RF_ID_SMARTI3G        0x00000003
#define  UL1D_RF_ID_MT6159C         0x00000004


typedef struct
{
	unsigned int m_u4Rfid;
	
}URfTestResultRFID;

typedef struct
{
	unsigned char m_u1Result;

}URfTestResultPwrDtStep;

typedef struct
{
	unsigned short m_u2Result;

}URfTestResultPwrDtDac;

typedef struct
{

	unsigned char m_u1Result;

}URfTestResultPwrDtDefaultThr;


typedef union {
	bool	ok;   //kal_bool  // for only request
	URfTestResultRSSI	rssi;
	URfTestResultAFC    afc;
  URfTestResultRSCP	rscp;
  URfTestResultRxDPCh	rx_dpch;
	URfTestResultRFID   rfid;
	URfTestResultPwrDtStep        pwr_dt_step;
	URfTestResultPwrDtDac         pwr_dt_dac;
  URfTestResultPwrDtDefaultThr  pwr_dt_default_thr;
  unsigned int                  bsi_data;
}URfTestResultParam;


//--------------------------------------------------------------------------//
//  RF Testing                                                              //
//--------------------------------------------------------------------------//

//-----------------------------------------------------//
//  RF Testing: data structure definition              //
//-----------------------------------------------------//
typedef short	ARFCN;
typedef short	Gain;
typedef char	BSIC;
typedef short	Power;
typedef unsigned char	TimingAdvance;

// RF ID 
#define  RF_ID_UNKNOWN     0x00000000
#define  RF_ID_BRIGHT2     0x00000001
#define  RF_ID_BRIGHT4     0x00000002
#define  RF_ID_AERO        0x00000004
#define  RF_ID_AERO1PLUS   0x00000008
#define  RF_ID_POLARIS1    0x00000010
#define  RF_ID_POLARIS2    0x00000020
#define  RF_ID_SKY74045    0x00000040
#define  RF_ID_BRIGHT5P    0x00000080
#define  RF_ID_MT6116      0x00000100
#define  RF_ID_MT6119      0x00000200
#define  RF_ID_MT6119C     0x00000400
#define  RF_ID_MT6129A     0x00000800
#define  RF_ID_MT6129B     0x00001000
#define  RF_ID_MT6129C     0x00002000
#define  RF_ID_MT6129D     0x00004000
#define  RF_ID_MT6139B     0x00008000
#define  RF_ID_MT6139C     0x00010000
#define  RF_ID_MT6140A     0x00020000
#define  RF_ID_SKY74117    0x00040000
#define  RF_ID_SKY74400    0x00080000
#define  RF_ID_AERO2       0x00100000
#define  RF_ID_MT6140B     0x00200000
#define  RF_ID_ALICEG2S    0x00400000
#define  RF_ID_MT6139E     0x00800000
#define  RF_ID_SKY74137    0x01000000
#define  RF_ID_MT6140C     0x02000000
#define  RF_ID_GRF6201     0x04000000
#define  RF_ID_IRFS3001    0x08000000
#define  RF_ID_MT6140D     0x10000000
#define  RF_ID_AG2550      0x10000001
#define  RF_ID_AERO2E      0x10000002
#define  RF_ID_AD6548      0x10000005     
#define  RF_ID_AD6546      0x10000006
#define  RF_ID_A60111A     0x10000007

typedef enum
{
   FrequencyBand400=0,				// GSM 450/480 band
   FrequencyBand850,				// GSM 850 band
   FrequencyBand900,				// GSM 900 band
   FrequencyBand1800,				// DCS 1800 band
   FrequencyBand1900,				// PCS 1900 band

   FrequencyBandCount				// count of supported bands
} FrequencyBand;

typedef struct 
{
	ARFCN			arfcn;				// Absolute radio frequency channel number
	char			sampleNoPerFrame;	// number of samples per frame
	Gain			gain;				// Gain that should be used in power management
	short			frames;				// number of frames
} RfPm_Req;

typedef struct {
	unsigned char	valid;				// if valid != zero, it means the extra info is meaningful. 
										// otherwise, the extra info should be ignore. 
   	int				iOffset;
	int				qOffset;
	int				validSamples;
} RfPmExtraInfo_T;

typedef struct
{
	int				power;				// average power
	int				deviation;			// deviation of power measurement
	Gain			usedGain;			// Gain that is used
	unsigned char	ok;					// status
	RfPmExtraInfo_T	extra_info;			// extra info 
} RfPm_Cnf;

typedef struct
{
	ARFCN			arfcn;				// absolute radio frequency channel number
	short			dacValue;			// AFC DAC value
	Gain			gain;				// gain used for AFC testing
	short			testNumber;			// test number
} RfAfc_Req;

typedef struct
{
	short			fcb_ok_number;		// successful number of FCB decoded
	int				freqOffset;			// average frequency error
	int				deviation;			// deviation of frequency error
	unsigned char	ok;					// status
} RfAfc_Cnf;

typedef enum {
	 AB_TX_RANDOM_WITH_SYNC_SEQ
	,NB_TX_ALL_ZEROS_WITHOUT_TSC
	,NB_TX_ALL_ONES_WITHOUT_TSC
	,NB_TX_ALTER_BITS_WITHOUT_TSC
	,NB_TX_RANDOM_WITH_TSC
	,NB_TX_PATTERN_WITHOUT_TSC
	,NB_TX_FIXED_RANDOM_WITH_TSC
	,NB_TX_FIXED_ALL_ZEROS_WITH_TSC
	,NB_TX_FIXED_ALTER_BITS_WITH_TSC
} APCTxPattern;

typedef struct
{
	ARFCN			arfcn;				// Absolute radio frequency channel number
	BSIC			bsic;				// bsic value used in transmission
	Power			power;				// Tx power in the unit of PCL
	short			frames;				// the number of frames NB should transmit
	short			dacValue;			// AFC DAC value
	APCTxPattern	burstTypeNB;
} RfNbtx_Req;

typedef struct
{
	ARFCN			arfcn;				// Absolute radio frequency channel number
	Gain			gain;				// Gain that should be used
	unsigned char	OnOff;				// On or off
} RfCnRx_Req;

typedef enum {
	CONT_TX_ALL_ZEROS
	,CONT_TX_ALL_ONES
	,CONT_TX_ALTERNATE_BITS
	,CONT_TX_PSEUDO_RANDOM
	,CONT_TX_PATTERN_WITHOUT_TSC
} ContTxPattern;

typedef struct
{
	ARFCN			arfcn;				// Absolute radio frequency channel number
	ContTxPattern	pattern;
	unsigned char	OnOff;				// On or off
} RfCnTx_Req;

typedef struct
{
	char	TxTrimI;
	char	TxTrimQ;
	char	TxOffsetI;
	char	TxOffsetQ;
} RfSetBBTXCfg_Req;

typedef struct {
	char	TxTrimI;
	char	TxTrimQ;
	char	TxOffsetI;
	char	TxOffsetQ;
	char	TxCalbias;
	char	TxIQSwap;
	char	TxCMV;
	char	TxGain;
	char	TxCalrcsel;
} RfBBTXCfg2;

typedef struct {
	char	TxTrimI;
	char	TxTrimQ;
	char	TxOffsetI;
	char	TxOffsetQ;
	char	TxCalbias;
	char	TxIQSwap;
	char	TxCMV;
	char	TxGain;
	char	TxCalrcsel;
	char	TxPhasesel;
} RfBBTXCfg3;

typedef struct {
	char    TxTrimI;
	char    TxTrimQ;
	char	TxOffsetI;
	char	TxOffsetQ;
	char	TxCalbias;
	char	TxIQSwap;
	char	TxCMV;
	char	TxGain;
	char	TxCalrcsel;
	char	TxPhasesel;
	char    TxCoarseI;
	char    TxCoarseQ;

}RfBBTXCfg4;  //RfTestCmdSetBBTXCfg4

typedef struct
{
    unsigned char bbtx_common_mode_voltage;
    unsigned char bbtx_gain;
    unsigned char bbtx_calrcsel;
//    unsigned char bbtx_coarseI; // need to set
//   unsigned char bbtx_coarseQ; // need to set
    unsigned char bbtx_trimI;   // need to set
    unsigned char bbtx_trimQ;   // need to set
	unsigned char bbtx_dccoarseI; // need to set
    unsigned char bbtx_dccoarseQ; // need to set
    unsigned char bbtx_offsetI; // need to set
    unsigned char bbtx_offsetQ; // need to set
    unsigned char bbtx_isCalibrated; // need to set
    int           apc_bat_low_voltage;
    int           apc_bat_high_voltage;
    int           apc_bat_low_temperature;
    int           apc_bat_high_temperature;
    unsigned char bbtx_common_mode_voltage_h;
    unsigned char bbtx_gain_h;
    unsigned char bbtx_calrcsel_h;
    unsigned char bbtx_trimI_h;
    unsigned char bbtx_trimQ_h;
//    unsigned char bbtx_coarseI_h;
//    unsigned char bbtx_coarseQ_h;
	unsigned char bbtx_dccoarseI_h;
    unsigned char bbtx_dccoarseQ_h;

    unsigned char bbtx_offsetI_h;
    unsigned char bbtx_offsetQ_h;
    unsigned char bbtx_phsel;
    unsigned char bbtx_phsel_h;
//    unsigned char bbrx_gsm850_gsm900_swap;
 //   unsigned char bbrx_dcs1800_pcs1900_swap;
}BBTXParameters_T;
typedef enum {
	CodingSchemeCS1 = 1,
	CodingSchemeCS2,
	CodingSchemeCS3,
	CodingSchemeCS4,
	CodingSchemePRACh8,
	CodingSchemePRACh11,
	CodingSchemeMCS1,
	CodingSchemeMCS2,
	CodingSchemeMCS3,
	CodingSchemeMCS4,
	CodingSchemeMCS5,
	CodingSchemeMCS6,
	CodingSchemeMCS7,
	CodingSchemeMCS8,
	CodingSchemeMCS9
} CodingScheme;

typedef struct {
	ARFCN			arfcn;			// absolute radio frequency channel number
	BSIC			bsic;			// training sequence
	char			timeSlotmask;	// time slot mask, slot_1: 0x01, slot_2: 0x02, slot_3: 0x04, slot_4: 0x08
	Power			powerLev[4];	// power level for each time slot
	CodingScheme	cs[4];			// coding scheme for each time slot
	TimingAdvance	ta;				// time advance
	int				frames;			// the number of frames should transmit
	short			dacValue;		// AFC DAC value
} RfMultiSlotTX_Req;

typedef struct {
	FrequencyBand	rf_band;
	int				power_level;
	int				apc_dac;
} RfSetRampApcLevel_Req;

typedef struct {
	short			dacValue;		// AFC DAC value
} RfSetAfcDacValue_Req;

typedef struct {
	int				cap_id;
} RfSetCrystalCfg_Req;

typedef struct {
	ARFCN			arfcn;			// absolute radio frequency channel number
	BSIC			bsic;			// training sequence
	char			timeSlotmask;	// time slot mask, slot_1: 0x01, slot_2: 0x02, slot_3: 0x04, slot_4: 0x08
	Power			powerLev[4];	// power level for each time slot
	CodingScheme	cs[4];			// coding scheme for each time slot, MCS1~9 is only valid for EPSK function 
	TimingAdvance	ta;				// time advance
	int				frames;			// the number of frames should transmit
	short			dacValue;		// AFC DAC value
	APCTxPattern	pattern;		// Tx pattern is only valid for EPSK function  
	unsigned short	pattern_data;	// if NB_TX_PATTERN_WITHOUT_TSC==pattern, user can input any 16bits value as pattern. 
} Rf_MultiSlotTXEx_Req;

typedef struct {
	unsigned int	id;				// please refer RF_ID_XXXX 
} RFMod_ID;

typedef enum {
	MS_GSM = 0
	,MS_GPRS
	,MS_EGPRS_RX_ONLY
	,MS_EGPRS_FULL_FUNCTION
} MS_CAPABILITY_E;

typedef struct {
	unsigned int	GSM400;			// Zero: not support, Non-zero: support 
	unsigned int	GSM850;
	unsigned int	GSM900;
	unsigned int	DCS1800;
	unsigned int	PCS1900;
} RFBandSupport_S;

typedef struct {
	MS_CAPABILITY_E		capability;
	RFBandSupport_S		band_support;
} RfMsCapability_S;

typedef struct {
	unsigned int	GSM:1;
	unsigned int	GPRS:1;
	unsigned int	EDGE_RX:1;
	unsigned int	EDGE_8PSK_TX:1;
	unsigned int	Calibration_8PM:1;
} RfMsCapabilityBits;

typedef struct {
	unsigned int	GSM:1;
	unsigned int	GPRS:1;
	unsigned int	EDGE_RX:1;
	unsigned int	EDGE_8PSK_TX:1;
	unsigned int	Calibration_8PM:1;
	unsigned int    Calibration_FDT:1;      // new
	unsigned int    Calibration_33Steps:1;  // new
} RfMsCapabilityBits_2;

typedef struct {
	unsigned int	GSM400:1;
	unsigned int	GSM850:1;
	unsigned int	GSM900:1;
	unsigned int	DCS1800:1;
	unsigned int	PCS1900:1;
} RfMsBandSupportBits;

typedef struct {
	RfMsCapabilityBits		capability;
	RfMsBandSupportBits		band_support;
} RfMsCapabilityEx_S;

typedef struct {
	RfMsCapabilityBits_2		capability;
	RfMsBandSupportBits		band_support;
} RfMsCapabilityEx2_S;



typedef enum {
	AFC_SINWAVE_OFF = 0
	,AFC_SINWAVE_ON
} AFC_SINWAVE_DETECTION_E;

typedef struct {
	ARFCN			arfcn;				// Absolute radio frequency channel number
	ContTxPattern	pattern;
	unsigned short	pattern_data;
	unsigned char	OnOff;				// On or off 
	unsigned short	modtype;			// modulation type: 0->GMSK, 1->EPSK 
} RfCnTxEx_Req;

typedef struct {
	ARFCN			arfcn;				// Absolute radio frequency channel number
	ContTxPattern	pattern;
	unsigned short	pattern_data;
	unsigned char	OnOff;				// On or off 
	unsigned short	modtype;			// modulation type: 0->GMSK, 1->EPSK 
	Power			powerLev;			// power level 
} RfCnTxEx2_Req;

typedef struct {
	short			dacValue;		// AFC DAC value
} RfGetAfcDacValueAtRTXOffsetCal;

//----------  FDT related structure -----------------------

#define MAX_STEP_CNT   50
typedef struct{
   FrequencyBand	  band;
   ARFCN			  arfcn;
   short		      dac_value[33];
   Gain			      gain;
   short		      repeat_cnt;	// repetitive test counts (frames) for each AFC DAC value
   bool			      capid_cal;	// capid calibration ctrl
   bool			      linear_cal;	// 33 stages calibration ctrl
   //char			      capid_min;	// min value for capid range when capid_cal is True; capid when capid_cal is False
   //char			      capid_max;	// max value for capid range
   int			      capid_min;	// min value for capid range when capid_cal is True; capid when capid_cal is False
   int			      capid_max;	// max value for capid range

}Rf_DSSAFC_T;

typedef struct
{
   FrequencyBand 	   band;
   ARFCN			   arfcn;
   Gain				   gain[6];		// gain for rx slot 0/1/2/3/4/5
   short			   repeat_cnt;	// repetitive test counts (frames) for each ARFCN value
//   short			   dac_value;	// Use InitDacValue from AFC calibration when dacValue = 0 (or -1)
} Rf_DSSPL_T;

typedef struct
{
   bool				   afc_cal;
   bool                pl_cal;       // Control whether Path loss calibration is needed or not
   char				   sync_sb_num;	// the SB frame numbers needed for sync process before path loss calibration
   short		       power;               // the power level expected to measure from test set
   Rf_DSSAFC_T 	       AfcDSS;
   char				   step_cnt;
   Rf_DSSPL_T	       PathLossDSS[MAX_STEP_CNT-2]; // because sync process will need 2 steps

}Rf_DTS_REQ_T;

typedef struct
{
   FrequencyBand	    band;
   ARFCN			    arfcn;
   char				    timeslot_per_frame;	
   char				    apc_dac_pcl_sel;				// 1: apc_dac, 0: apc_pcl
   short			    apc_dac_pcl_value[4];
   unsigned char		pa_vbias_val;	
   CodingScheme		    cs[4];
   int			        repeat_cnt;			
   short			    afc_dac_value;
   char				    tsc;
   APCTxPattern			pattern;		
   unsigned short		pattern_data;
} Rf_USSAPC_T;

typedef struct
{
//   bool                pa_vbias_cal;
   char				   step_cnt;
   Rf_USSAPC_T	       ApcUSS[MAX_STEP_CNT];
}Rf_UTS_REQ_T;

typedef struct
{
   int	    power[MAX_STEP_CNT-2];  // because sync process will need 2 steps
   short    valid_sample[MAX_STEP_CNT-2];
   bool		ok;
} Rf_DSSPL_RESULT_T;

typedef struct
{
   int	    freq_offset[33];	// only valid when 33 stage calibration is ON
   int	    deviation[33];		// only valid when 33 stage calibration is ON
   short	fcb_ok_number[33];  // only valid when 33 stage calibration is ON
   //char		capid;			    // only valid when capid calibration is ON
   int		capid;			    // only valid when capid calibration is ON
   short	init_dac_value; 	// only valid when 33 stage calibration is OFF
   int	    slope;              // only valid when 33 stage calibration is OFF
   bool		ok;
} Rf_DSSAFC_RESULT_T;

typedef struct
{
   Rf_DSSPL_RESULT_T	  PLResult;
   Rf_DSSAFC_RESULT_T	  AfcResult;
	
} Rf_DTS_CNF_T;

//-----------------------------------------------------//
//  TX Ramping Table                                   //
//-----------------------------------------------------//
#define PROFILE_NUM             16
#define ARFCN_SECTION_NUM       12
#define ARFCN_SECTION_NUM_Ex       64
typedef  struct
{
   unsigned char   point[2][16];	// ramp up/down profile

} sRAMPAREADATA;

typedef  struct
{
   short			max_arfcn;		// sub-band boundary of this PCL weighting area
   unsigned short   mid_level;		// PCLboundary level to apply high/low weighting
   unsigned short   hi_weight;		// scale factor of PCLs higher than mid_level
   unsigned short   low_weight;		// scale factor of PCLs lower than mid_level

} sARFCN_SECTION;

typedef  struct
{
   int				lowest_power;						// The lower apc power of the indicated band
   unsigned short	power[16];							// The mapping of power level to apc dac value
   sRAMPAREADATA	ramp[ PROFILE_NUM ];				// ramp profile
   sARFCN_SECTION	arfcn_weight[ ARFCN_SECTION_NUM ];	// profile of weighting power level by PCL and sub-band
   unsigned short	battery_compensate[3][3];			// [volt][temp] 
   short			tx_afc_offset;
} sRAMPDATA;

typedef struct
{
   int				lowest_power;						// The lower apc power of the indicated band
   unsigned short	power[16];							// The mapping of power level to apc dac value
   sRAMPAREADATA	ramp[ PROFILE_NUM ];				// ramp profile
   sARFCN_SECTION	arfcn_weight[ ARFCN_SECTION_NUM_Ex ];	// profile of weighting power level by PCL and sub-band
   unsigned short	battery_compensate[3][3];			// [volt][temp] 
   short			tx_afc_offset;
} sRAMPDATA_Ex;

typedef  struct
{
   int				lowest_power;						// The lower apc power of the indicated band
   unsigned short	power[16];							// The mapping of power level to apc dac value
   sRAMPAREADATA	ramp[ PROFILE_NUM ];				// ramp profile
   sARFCN_SECTION	arfcn_weight[ ARFCN_SECTION_NUM ];	// profile of weighting power level by PCL and sub-band
   unsigned short	battery_compensate[3][3];			// [volt][temp] 
   short			tx_afc_offset;
   unsigned char	vbias[16];
} sRAMPDATA_Ex2;

typedef struct
{
   sRAMPDATA          rampData;							// apc ramp profile of all bands
}l1cal_rampTable_T;

typedef struct
{
   sRAMPDATA_Ex          rampData;							// apc ramp profile of all bands
}l1cal_rampTable_T_Ex;

typedef struct
{
   sRAMPDATA_Ex2          rampData;							// apc ramp profile of all bands
}l1cal_rampTable_T_Ex2;

//-----------------------------------------------------//
//  TX Inter Ramping Table                             //
//-----------------------------------------------------//

// interRampData 
typedef struct {   
	unsigned char	interRampData[16];
} l1cal_interRampData_T;

// EPSK interRampData 
typedef struct {
	unsigned char	EPSK_interRampData[4][16];
} l1cal_EPSK_interRampData_T;

//-----------------------------------------------------//
//  3F RF compose/decompose table                      //
//-----------------------------------------------------//
#define  CAL_UARFCN_SECTION  15
#define  U_ARFCN_SECTION_NUM   15
#define  CAL_TEMP_SECTION     8
#define CAL_PWR_DETECTOR_SECTION 32  
typedef  struct
{
   unsigned short  max_uarfcn;
    char   path_loss_H;//loss;
    char   path_loss_M;//gain_diff_HM;
    char   path_loss_L;//gain_diff_HL;
}  U_sAGCGAINOFFSET;

typedef  struct
{
   //char   temp;   
   U_sAGCGAINOFFSET  gain_of_uarfcn[CAL_UARFCN_SECTION];   
}  U_sTEMPAGCOFFSET;

typedef  struct
{
   unsigned short dc2dc_dac;
   unsigned short vbias_dac;
   unsigned char vm1;
   unsigned char vm2;
}  U_sPADATA;

typedef  struct
{
   unsigned short  max_uarfcn;
   short           pwr_offset;
   short           pwr_slope;
} U_sARFCN_SECTION;

typedef struct
{
   unsigned short max_uarfcn;
   short          pwr_offset_dB; /* unit: 1/32 dB, range: -8 ~ +7 dB */ 
   short          pwr_offset_txdac;
}U_sARFCN_SECTION_B;  // for MT6268B later


typedef  struct
{
   //unsigned short  pa_dac;
   U_sPADATA          pa_data;
   unsigned short     vga_dac[90];//vga_dac[81];
   U_sARFCN_SECTION   vga_comp_by_subband[CAL_UARFCN_SECTION];
   short              vga_comp_by_temperature[8][2];  //[0]:slope, [1]:offset
   //short           vga_offset_by_temperature[8]; 
} U_sTXPOWERDATA;

typedef  struct
{
   U_sPADATA           pa_data; 
   unsigned short      vga_dac[90];
   U_sARFCN_SECTION_B  vga_comp_by_subband[ CAL_UARFCN_SECTION ];
   short               vga_comp_by_temperature[8][2];  //[0]:offset in dB (unit: 1/32 dB), [1]:offset in txdac
} U_sTXPOWERDATA_B;  // for MT6268B later

typedef  struct
{
   unsigned short start;
   unsigned short end;
} U_sHYSTERESISDATA;

typedef  struct
{
   unsigned char     pwr_dt_thr;
   unsigned char     pwr_dt_section;   // can not be larger than CAL_PWR_DETECTOR_SECTION
   unsigned short    pwr_dt_dac[CAL_PWR_DETECTOR_SECTION];
   
   short             pwr_dt_value[CAL_PWR_DETECTOR_SECTION]; //bit0~4 is used for fractions
   U_sARFCN_SECTION  pwr_dt_comp_by_subband[CAL_UARFCN_SECTION];   // for compensation, no need calibration, after test, will auto-store
   short             pwr_dt_comp_by_temperature[8][2];  //[0]:slope, [1]:offset
 
}  U_sPWTDTDATA;

typedef  struct
{
   unsigned char       pwr_dt_thr;
   unsigned char       pwr_dt_section;
   unsigned short      pwr_dt_dac[ CAL_PWR_DETECTOR_SECTION ];
   short               pwr_dt_value[ CAL_PWR_DETECTOR_SECTION ]; //bit0~4 is used for fractions
   U_sARFCN_SECTION_B  pwr_dt_comp_by_subband[ CAL_UARFCN_SECTION ];
   short               pwr_dt_comp_by_temperature[8][2];  //[0]:offset in dB (unit: 1/32 dB), [1]:offset in txdac
}  U_sPWTDTDATA_B;   // for MT6268B later



typedef  struct
{
   U_sTXPOWERDATA    power_dac[3];   //0:PA high mode, 1:PA mid mode, 2:PA low mode (use 0&1 if only 2 mode)
   U_sHYSTERESISDATA tx_hysteresis[2];
   U_sPWTDTDATA      pwr_dt_data;
 //  U_sRAMPAREADATA   u_ramp;
 //  U_sARFCN_SECTION  u_arfcn_weight[ U_ARFCN_SECTION_NUM ];
} U_sRAMPDATA;

typedef  struct
{
   U_sTXPOWERDATA_B      power_dac[3];   //0:PA high mode, 1:PA mid mode, 2:PA low mode (use 0&1 if only 2 mode)
   U_sHYSTERESISDATA     tx_hysteresis[2];
   U_sPWTDTDATA_B        pwr_dt_data;

} U_sRAMPDATA_B;   // for MT6268B later


//chliu provide
typedef struct
{
   unsigned char tempdacData[8];
}ul1cal_tempdacData_T; 

typedef struct
{
   U_sTEMPAGCOFFSET  pathlossData[CAL_TEMP_SECTION]; 
}ul1cal_pathlossData_T;

typedef struct
{
   U_sRAMPDATA txdacData; 
}ul1cal_txdacData_T;

typedef struct
{
   U_sRAMPDATA_B txdacData; 
}ul1cal_txdacData_T_B;   // for MT6268B later

/* end of chliu */

//-----------------------------------------------------//
//  RF Module Special Coef                             //
//-----------------------------------------------------//

//mt6140D
typedef struct{
   short		pcl_index;
   unsigned char pa_vbias1;   
}pa_vbias;

typedef struct {
   pa_vbias GSM850_pa_vbias[8];
   pa_vbias GSM900_pa_vbias[8];   
   pa_vbias DCS1800_pa_vbias[8];
   pa_vbias PCS1900_pa_vbias[8];
   //pa_vbias low_band_pa_vbias[8];
   //pa_vbias high_band_pa_vbias[8];
}mt6140tx_pa_vbias;

typedef struct{  
      mt6140tx_pa_vbias data;
}mt6140tx;  
// Skyworks 
typedef struct {
	unsigned int		icorrection;
	unsigned int		qcorrection;
} RF_SKY74045_IP2_Coef;

typedef struct {
	RF_SKY74045_IP2_Coef	coef[5/*band*/];
} RF_SKY74045_RX_Coef;

typedef struct {
	RF_SKY74045_RX_Coef		rx;
} RF_SKY74045_Coef_T;

typedef struct {
	unsigned int			ipol;
	unsigned int			qpol;
} RF_SKY74117_IP2_Pol;

typedef struct {
	RF_SKY74045_IP2_Coef	coef[5/*band*/];
	RF_SKY74117_IP2_Pol		pol[5/*band*/];
} RF_SKY74117_RX_Coef;

typedef struct {
	RF_SKY74117_RX_Coef		rx;
} RF_SKY74117_Coef_T;

// MT6139B 
typedef struct {
	unsigned int		acode;
	unsigned int		amcode;
} RF_MT6139B_IP2_Coef;

typedef struct {  
	RF_MT6139B_IP2_Coef		coef[5/*band*/];
	unsigned int			rxamcalmode;
} RF_MT6139B_RX_Coef;

typedef struct {
	RF_MT6139B_RX_Coef		rx;
} RF_MT6139B_Coef_T;

// Bright5P 
typedef struct {
	unsigned int		word6_4_0;
	unsigned int		word6_5_0;
	unsigned int		word6_6_0;
	unsigned int		word6_7_0;
	unsigned int		bvmode;
	unsigned int		c3mode;
	unsigned int		wordC3;
} RF_BRIGHT5P_TX_Coef;

typedef struct {
	RF_BRIGHT5P_TX_Coef		tx;
} RF_BRIGHT5P_Coef_T;

typedef struct
{
   unsigned char REFDET_SLOPE_SKEW ;
   unsigned char AM_FB_DAC; 
}ad6546txcoef;



typedef  struct
{ 
      ad6546txcoef   CalData[4];

} ad6546tx;   

//-----------------------------------------------------//
//  RF Testing: callback function definition           //
//-----------------------------------------------------//
typedef void (__stdcall *META_RF_PM_CNF)(const RfPm_Cnf *cnf, const short token, void *usrData);
typedef void (__stdcall *META_RF_AFC_CNF)(const RfAfc_Cnf *cnf, const short token, void *usrData);
typedef void (__stdcall *META_RF_NB_TX_CNF)(const unsigned char cnf, const short token, void *usrData);
typedef void (__stdcall *META_RF_CONT_RX_CNF)(const unsigned char cnf, const short token, void *usrData);
typedef void (__stdcall *META_RF_CONT_TX_CNF)(const unsigned char cnf, const short token, void *usrData);
typedef void (__stdcall *META_RF_SETBBTX_CFG_CNF)(const unsigned char cnf, const short token, void *usrData);
typedef void (__stdcall *META_RF_SELBAND_CNF)(const unsigned char cnf, const short token, void *usrData);
typedef void (__stdcall *META_RF_STOP_CNF)(const unsigned char cnf, const short token, void *usrData);
typedef void (__stdcall *META_RF_MULTISLOT_TX_CNF)(const unsigned char cnf, const short token, void *usrData);
typedef void (__stdcall *META_RF_SET_RAMPAPCLEVEL_CNF)(const unsigned char cnf, const short token, void *usrData);
typedef void (__stdcall *META_RF_SET_AFCDACVALUE_CNF)(const unsigned char cnf, const short token, void *usrData);



int __stdcall SP_META_ComPortEnumerate(unsigned short *p_com_port_array, unsigned short *p_com_port_count);
//--------------------------------------------------------------------------//
//  NVRAM                                                                   //
//--------------------------------------------------------------------------//

//-----------------------------------------------------//
//  NVRAM: data structure definition                   //
//-----------------------------------------------------//

// Reset NVRAM
typedef enum 
{
	NVRAM_RESET_ALL,		// Reset all data items in both of user and system category
	NVRAM_RESET_USER,		// Reset data items in user category
	NVRAM_RESET_SYSTEM,		// Reset data items in system category
	NVRAM_RESET_CERTAIN,	// Reset certain data item according to LID
	NVRAM_RESET_FACTORY		// Reset to factory default value, all the LIDs has FACTORY attribute will be reseted 
} ResetCategory;   

typedef struct
{
	ResetCategory	category;	// Reset category

	const char		*LID;		// The name of logical data item ID , it will be used
								// if and only if ResetCategory = NVRAM_RESET_CERTAIN,
								// in other case you can just assign NULL.
} FT_NVRAM_RESET_REQ;

typedef struct
{
	unsigned char   reset_status;
	unsigned char	status;		// The status of Reset
} FT_NVRAM_RESET_CNF;

// Read from NVRAM
typedef struct
{
	const char			*LID;		// The name of logical data item ID
	unsigned short 		RID;		// Record ID (the first record is 1)
} FT_NVRAM_READ_REQ;

typedef struct
{
	unsigned short		LID;		// Logical data item ID of a EF
	unsigned short		RID;		// Record ID (the first record is 1)
	unsigned char		status;		// 0: read ok; others: read failed.

	unsigned int		len;		// [IN] Length of Buffer, [OUT] Length of read data
									// The "len" field indicates the size of "buf" you 
									// allocated. When the data is read back, "len" will
									// be replaced with the actual size of the data.

	unsigned char 		*buf;		// Buffer that will contains the content of record
	unsigned char		read_status;
} FT_NVRAM_READ_CNF;

//Write to NVRAM
typedef struct
{
	const char			*LID;		// The name of logical data item ID
	unsigned short		RID;		// Record ID (the first record is 1)
	unsigned int		len;		// Length of write data
	unsigned char		*buf;		// Buffer that contains the content of record
} FT_NVRAM_WRITE_REQ;

typedef struct
{
	unsigned short		LID;		// Logical data item ID of a EF
	unsigned short		RID;		// Record ID (the first record is 1)
	unsigned char		write_status;
	unsigned char		status;		// 0: write ok; others: write failed.
} FT_NVRAM_WRITE_CNF;

// AGC path loss 
#define  PLTABLE_SIZE  13			// element count of path loss table

typedef  struct
{
   short        max_arfcn;			// The maximum ARFCN of the indicated sub-band
   char			gain_offset;		// The maximum available gain of transceiver of the indicated sub-band
} sAGCGAINOFFSET;

typedef struct
{
   sAGCGAINOFFSET     agcPathLoss[FrequencyBandCount][PLTABLE_SIZE];
}l1cal_agcPathLoss_T;

// Speech Coefficient
typedef struct {
	short		Speech_8k_Input_Coeff[30];		// FIR for input speech (microphone) with 8k sampling rate  
	short		Speech_8k_Output_Coeff[30];		// FIR for output speech (speaker) with 8k sampling rate    
	short		Speech_16k_Input_Coeff[62];		// FIR for input speech (microphone) with 16k sampling rate 
	short		Speech_16k_Output_Coeff[62];	// FIR for output speech (speaker) with 16k sampling rate   

	short		Additional_Speech_8k_Output_Coeff[5][30];	// The additional FIR for output speech (speaker) with 8k sampling rate 

	unsigned short	Speech_8k_Output_Coeff_Index;	// The active FIR index                      
													// 0 -> Speech_8k_Output_Coeff               
													// 1 -> Additional_Speech_8k_Output_Coeff[0] 
													// 2 -> Additional_Speech_8k_Output_Coeff[1] 
													// 3 -> Additional_Speech_8k_Output_Coeff[2] 
													// 4 -> Additional_Speech_8k_Output_Coeff[3] 
													// 5 -> Additional_Speech_8k_Output_Coeff[4] 
}L1_SpeechCoeff_T;

// Melody Coefficient
typedef struct {
	short		Melody_32k_Output_Coeff[45];	// FIR for melody playback with with 32k sampling rate 
}L1_MelodyCoeff_T;

// L1Audio Param
typedef struct{
	L1_SpeechCoeff_T	Speech_FIR[2];	// [0]: normal mode 
										// [1]: headset mode 
										// NOTE: In headset mode, Additional_Speech_8k_Output_Coeff and 
										//       Speech_8k_Output_Coeff_Index are ignored! you can just 
										//       leave them alone.                                      

	L1_MelodyCoeff_T	Melody_FIR[2];	// [0]: loud speaker mode 
										// [1]: stereo speaker mode 
	unsigned short		ES_TimeConst;
	unsigned short		ES_VolConst;
	unsigned short		ES_TimeConst2;
	unsigned short		ES_VolConst2;
	unsigned short		Media_Playback_Maximum_Swing;
}l1audio_param_T;

// L1Audio Param from W0547 

#define SPEECH_NORMAL_MODE			0
#define SPEECH_EARPHONE_MODE		1
#define SPEECH_LOUDSPEAKER_MODE		2
#define SPEECH_BT_ERAPHONE_MODE		3
#define SPEECH_BT_CORDLESS_MODE		4
#define SPEECH_AUX1_MODE			5
#define SPEECH_AUX2_MODE			6
#define SPEECH_AUX3_MODE			7

typedef struct{
	L1_SpeechCoeff_T	Speech_FIR[2];	// [0]: normal mode 
										// [1]: headset mode 
										// NOTE: In headset mode, Additional_Speech_8k_Output_Coeff and 
										//       Speech_8k_Output_Coeff_Index are ignored! you can just 
										//       leave them alone.                                      

	L1_MelodyCoeff_T	Melody_FIR[2];	// [0]: loud speaker mode 
										// [1]: stereo speaker mode 

	unsigned short		Speech_Common_Para[12];

	unsigned short		Speech_ModeDependent_Para[8][8];	// [0]: Normal Mode             
															// [1]: Earphone Mode           
															// [2]: Loud Speaker Mode       
															// [3]: BlueTooth Earphone Mode 
															// [4]: BlueTooth Cordless Mode 
															// [5]: AUX1 Mode               
															// [6]: AUX2 Mode               
															// [7]: AUX3 Mode               
	unsigned short		Media_Playback_Maximum_Swing;
} l1audio_param_W0547_T;


typedef struct{
	short speech_input_FIR_coeffs[6][45];
    short speech_output_FIR_coeffs[6][45];
    unsigned short selected_FIR_output_index;
    unsigned short speech_common_para[12];
    unsigned short speech_normal_mode_para[8];
    unsigned short speech_earphone_mode_para[8];
    unsigned short speech_loudspk_mode_para[8];
    unsigned short speech_bt_earphone_mode_para[8];
    unsigned short speech_bt_cordless_mode_para[8];
    unsigned short speech_aux1_mode_para[8];
    unsigned short speech_aux2_mode_para[8];
    unsigned short speech_aux3_mode_para[8];
    unsigned short Media_Playback_Maximum_Swing;
    short Melody_FIR_Output_Coeff_32k_Tbl1[45];
} l1audio_param_W0547_45_T;

typedef struct{
	short speech_input_FIR_coeffs[6][45];
    short speech_output_FIR_coeffs[6][45];
    unsigned short selected_FIR_output_index;
    unsigned short speech_common_para[12];
    unsigned short speech_normal_mode_para[8];
    unsigned short speech_earphone_mode_para[8];
    unsigned short speech_loudspk_mode_para[8];
    unsigned short speech_bt_earphone_mode_para[8];
    unsigned short speech_bt_cordless_mode_para[8];
    unsigned short speech_aux1_mode_para[8];
    unsigned short speech_aux2_mode_para[8];
    unsigned short speech_aux3_mode_para[8];
    unsigned short Media_Playback_Maximum_Swing;
    short Melody_FIR_Output_Coeff_32k_Tbl1[25];
} l1audio_param_W0712_T;


typedef struct
{
    short          speech_input_FIR_coeffs[6][45];
    short          speech_output_FIR_coeffs[6][45];
    unsigned short selected_FIR_output_index;
    unsigned short speech_common_para[12];
    unsigned short speech_mode_para[8][8];
    unsigned short Media_Playback_Maximum_Swing;
    short          Melody_FIR_Coeff_Tbl[25];
    short          audio_compensation_coeff[2][45];  // new added, so different with others structure

} l1audio_param_W0740_T;



typedef struct
{
	/* volume setting */
	char		   volume[3][7];
	/* speech enhancement */
	unsigned short speech_common_para[12];
	unsigned short speech_mode_para[8][16];
	unsigned short speech_volume_para[4];
	
	unsigned short debug_info[16];
	/* speech input FIR */
	short		   speech_input_FIR_coeffs[6][45];
	/* speech output FIR */
	short		   speech_output_FIR_coeffs[6][45];

	/* digital gain of DL speech */
	unsigned short Digi_DL_Speech;
	/* digital gain of uplink speech */
	unsigned short Digi_Microphone;
	/* FM record volume*/
	unsigned short FM_Record_Volume;	
	/* user mode : normal mode, earphone mode, loud speaker mode */
	unsigned short Bluetooth_Sync_Type;
	unsigned short Bluetooth_Sync_Length;
	unsigned short bt_pcm_in_vol;
	unsigned short bt_pcm_out_vol;
	unsigned short user_mode;
	/* auto VM record setting */
	unsigned short bSupportVM;
	unsigned short bAutoVM;
	unsigned short uMicbiasVolt;

} l1audio_param_W0809_T;


// 6516 add
typedef struct
{
                /* volume setting */
                char                          volume[3][7];
                /* speech input FIR */
                short                        speech_input_FIR_coeffs[6][45];
                /* speech output FIR */
                short                        speech_output_FIR_coeffs[6][45];
                /* speech enhancement */
                unsigned short speech_common_para[12];
                unsigned short speech_mode_para[8][16];
                /* digital gain of DL speech */
                unsigned short Digi_DL_Speech;
                /* digital gain of uplink speech */
                unsigned short Digi_Microphone;
                /* FM record volume*/
                unsigned short FM_Record_Volume;     
                /* user mode : normal mode, earphone mode, loud speaker mode */
                unsigned short Bluetooth_Sync_Type;
                unsigned short Bluetooth_Sync_Length;
                unsigned short bt_pcm_in_vol;
                unsigned short bt_pcm_out_vol;
                unsigned short user_mode;
                /* auto VM record setting */
                unsigned short bSupportVM;
                unsigned short bAutoVM;

                //////////////////////////////////////////////////////////////////////////
                // dummy members, which would be removed some day
                unsigned short selected_FIR_output_index;
                unsigned short speech_volume_para[3][7][4];
                unsigned short Media_Playback_Maximum_Swing;
                short          Melody_FIR_Coeff_Tbl[25];
                short          audio_compensation_coeff[2][45];  // new added, so different with others structure
                //////////////////////////////////////////////////////////////////////////

} l1audio_param_W0809_6516_T;


typedef struct 
{    
    unsigned int bes_loudness_hsf_coeff[9][4];
    unsigned int bes_loudness_bpf_coeff[4][6][3];
    // BesLoudness V3
    unsigned int besloudness_DRC_Forget_Table[9][2];
    unsigned int besloudness_WS_Gain_Max;
    unsigned int besloudness_WS_Gain_Min;
    unsigned int besloudness_Filter_First;
    char         besloudness_Gain_Map_In[5];
    char         besloudness_Gain_Map_Out[5];
    
}l4aud_acf_param;

// 6516 add
typedef struct 
{    
    unsigned int bes_loudness_hsf_coeff[9][4];
    unsigned int bes_loudness_bpf_coeff[4][6][3];
}l4aud_get_acf_param_cnf;

typedef struct 
{ 	
	//Volume: 
	short VOL_CALIBRATION_SUBBAND_SHIFT[8];
	short VOL_CALIBRATION_SUBBAND[8];
	//Delay: 
	short DELAY_CAL_INT;
	short DELAY_CAL_FRAC;
	short DELAY_CAL_SUBBAND[8];
	//Leakage: 
	short POWER_RATIO_SCALE;
	short WIND_INDEX_THRESHOLD;
	short SUBBAND_BMG[8];
	short MOCKUP_LEVEL;
	short SHIELDING_LEVEL;
	//NR_Level
	short NR_Level;
	//Reserve
	short Parameter_Reserve[5];
}l1audio_extra_param_W1105_T;

typedef struct 
{ 	
	//Volume: 
	short VOL_CALIBRATION_SUBBAND_SHIFT[16];
	short VOL_CALIBRATION_SUBBAND[16];
	//Delay: 
	short DELAY_CAL_INT;
	short DELAY_CAL_FRAC;
	short DELAY_CAL_SUBBAND[16];
	//Leakage: 
	short POWER_RATIO_SCALE;
	short WIND_INDEX_THRESHOLD;
	short SUBBAND_BMG[16];
	short MOCKUP_LEVEL;
	short SHIELDING_LEVEL;
	//NR_Level
	short NR_Level;
	//Reserve
	short Parameter_Reserve[5];
}l1audio_extra_param_W1134_T;


// Audio gain table
typedef	struct { 
	char  bEnable;    // return if support gain table 
}l4aud_gaintable_cnf;

typedef	struct { 
	int  gaintablenum;  // return number ogf gain type 
}l4aud_gaintablenum_cnf;


typedef	struct { 
	int gaintabletype;    // query of which gain type 
}l4aud_gaintablelevel_req;


typedef	struct { 
	int gaintabletype;     // return of gain type4
	int gainttablelevel;    // return level of query gain type 
}l4aud_gaintablelevel_cnf;


typedef	struct { 
	int  i4ctrpointnum;        // this get control point number 
}l4aud_ctrpointnum_cnf;


typedef	struct { 
	int  i4ctrpoint;       
	//  this range should depend on amp control pointer number 
}l4aud_ctrpointbits_req;


typedef	struct { 
	int  i4ctrpoint;   //  this range should depend on amp control pointer number 
	
	int  i4ctrpointbits;   // return bits of this control bpoint 
}l4aud_ctrpointbits_cnf;


typedef	struct { 
	int  i4ctrpoint;        //  query control point of table 
}l4aud_ctrpointtable_req;


typedef	struct { 
	int  i4ctrpoint;        //  query control point of table
	char buffer[255];          //   buffer to fill contorl point table 
	int i4bufferlength;  //   length of buffer  filled. 
}l4aud_ctrpointtable_cnf;

// HD Recording
typedef struct
{
	unsigned char bHdRecSupport;
	unsigned char bDualMicSupport;
} l4aud_hdrec_info_cnf;



//#define AUDIO_GAIN_TABLE_LEVEL_PER_PAGE_REAL  20

#define GAIN_TABLE_SUPPORT
#ifdef GAIN_TABLE_SUPPORT
#define GAIN_TABLE_LEVEL (20)
#else
#define GAIN_TABLE_LEVEL (20)
#endif

#define VOICE_GAIN_TABLE_LEVEL (6+1)
#define SYSTEM_GAIN_TABLE_LEVEL (7+1)
#define RING_GAIN_TABLE_LEVEL (7+1)
#define MUSIC_GAIN_TABLE_LEVEL (13+1)
#define ALARM_GAIN_TABLE_LEVEL (7+1)
#define NOTIFICATION_GAIN_TABLE_LEVEL (7+1)
#define BLUETOOTHSCO_GAIN_TABLE_LEVEL (15+1)
#define ENFORCEAUDIBLE_GAIN_TABLE_LEVEL (7+1)
#define DTMF_GAIN_TABLE_LEVEL (15+1)
#define TTS_GAIN_TABLE_LEVEL (15+1)
#define FM_GAIN_TABLE_LEVEL (13+1)
#define MATV_GAIN_TABLE_LEVEL (13+1)

enum AUDIO_GAIN_TYPE {
	AUDIO_GAIN_DEFAULT 		    =-1,
	AUDIO_GAIN_VOICE_CALL		= 0,
	AUDIO_GAIN_SYSTEM			= 1,
	AUDIO_GAIN_RING			    = 2,
	AUDIO_GAIN_MUSIC			= 3,
	AUDIO_GAIN_ALARM			= 4,
	AUDIO_GAIN_NOTIFICATION	    = 5,
	AUDIO_GAIN_BLUETOOTH_SCO	= 6,
	AUDIO_GAIN_ENFORCED_AUDIBLE = 7, // Sounds that cannot be muted by user and must be routed to speaker
	AUDIO_GAIN_DTMF			    = 8,
	AUDIO_GAIN_TTS 			    = 9,
	AUDIO_GAIN_FM				= 10,
	AUDIO_GAIN_MAX_STREAM       = 10, 
	AUDIO_GAIN_MIC              = 11,
	AUDIO_GAIN_SIDETONE         = 12,
	AUDIO_GAIN_SPEECH           = 13,
	AUDIO_GAIN_SPEECH_WB        = 14,
    NUM_AUDIO_GAIN_TYPES              //max index of stream
};

enum MICROPHONE_DEVICEGAIN{
    GAIN_IDLE_RECORD_MIC =0,
	GAIN_IDLE_RECORD_HEADSET ,
	GAIN_INCALL_RECEIVER,
	GAIN_INCALL_HEADSET, 
	GAIN_INCALL_SPEAKER,
	GAIN_VOIP_RECEIVER, 
	GAIN_VOIP_HEADSET,
	GAIN_VOIP_SPEAKER,
	GAIN_FM_RECORDING, 
	GAIN_VOICE_RECOGNITION_RECEIVER,
	GAIN_VOICE_RECOGNITION_HEADSET,
	GAIN_INCALL_WB_RECEIVER,
	GAIN_INCALL_WB_HEADSET, 
	GAIN_INCALL_WB_SPEAKER,
	GAIN_MIC_RESOLVED,
	NUM_OF_MICGAINS //15
};

//---------------------------------------------------------------------------
enum SIDETONE_DEVICEGAIN{
	GAIN_SIDETONE_RECEIVER =0,
    GAIN_SIDETONE_HEADSET,
    GAIN_SIDETONE_SPEAKER,
    NUM_OF_SIDETONEGAINS
};

//---------------------------------------------------------------------------
enum GAIN_SPEECH{
    SPEECH_NORMAL  = 0,
    SPEECH_HEADSET = 1,
    SPEECH_SPEAKER = 2,    
    NUM_OF_SPEECHGAIN,
};

//---------------------------------------------------------------------------

enum GAIN_OUTPUT_DEVICE
{
	GAIN_OUTPUT_RECEIVER = 0,
	GAIN_OUTPUT_HEADSET  = 1,
	GAIN_OUTPUT_SPEAKER  = 2,
	NUM_GAIN_OUTPUT_DEVICES
};

//---------------------------------------------------------------------------
typedef struct _AUDIO_GAIN_CONTROL_STRUCT
{
    unsigned char u8Gain_digital;
    unsigned int u32Gain_PGA_Amp;
} AUDIO_GAIN_CONTROL_STRUCT;

//---------------------------------------------------------------------------
typedef struct _STREAM_GAIN_CONTROL_STRUCT
{
    AUDIO_GAIN_CONTROL_STRUCT streamGain[NUM_GAIN_OUTPUT_DEVICES][GAIN_TABLE_LEVEL];
} STREAM_GAIN_CONTROL_STRUCT;

//---------------------------------------------------------------------------
typedef struct _STREAM_MICROPHONE_GAIN_CONTROL_STRUCT
{
    unsigned char micGain[GAIN_TABLE_LEVEL];
} STREAM_MICROPHONE_GAIN_CONTROL_STRUCT;

//---------------------------------------------------------------------------
typedef struct _STREAM_SIDETONE_GAIN_CONTROL_STRUCT
{
    unsigned char sidetoneGain[GAIN_TABLE_LEVEL];
} STREAM_SIDETONE_GAIN_CONTROL_STRUCT;

//---------------------------------------------------------------------------
typedef struct _STREAM_SPEECH_GAIN_CONTROL_STRUCT
{
    AUDIO_GAIN_CONTROL_STRUCT speechGain[NUM_OF_SPEECHGAIN][GAIN_TABLE_LEVEL];
} STREAM_SPEECH_GAIN_CONTROL_STRUCT;



//---------------------------------------------------------------------------
typedef struct _AUDIO_GAIN_TABLE_STRUCT
{
    STREAM_GAIN_CONTROL_STRUCT voiceCall;	
    STREAM_GAIN_CONTROL_STRUCT system;	
    STREAM_GAIN_CONTROL_STRUCT ring;
	
    STREAM_GAIN_CONTROL_STRUCT music;	
    STREAM_GAIN_CONTROL_STRUCT alarm;
    STREAM_GAIN_CONTROL_STRUCT notification;
    STREAM_GAIN_CONTROL_STRUCT blueToothSco;
    STREAM_GAIN_CONTROL_STRUCT enforceAudible;
    STREAM_GAIN_CONTROL_STRUCT dtmf;
    STREAM_GAIN_CONTROL_STRUCT tts;
    STREAM_GAIN_CONTROL_STRUCT fm;
    // STREAM_GAIN_CONTROL_STRUCT Matv_Gain_table;
	
    STREAM_MICROPHONE_GAIN_CONTROL_STRUCT microphoneGain;
    STREAM_SIDETONE_GAIN_CONTROL_STRUCT sidetoneGain;
    STREAM_SPEECH_GAIN_CONTROL_STRUCT speechGain;
    STREAM_SPEECH_GAIN_CONTROL_STRUCT speechGainWB;
	
} AUDIO_GAIN_TABLE_STRUCT;




/*
#define MAX_SIZE_SCENE_NAME 128 // max length of scene name
#define NUM_RECORD_MODE 	3   // handset+headset+bt
*/
#define MAX_NUM_SCENE 	    6   // for each voice/video rec, max #scene = 6. Total <= 10 (10 * 3 = 30 = max)


#define MAX_HD_REC_SCENES                              10
#define NUM_HD_REC_DEVICE_SOURCE   3

/*
typedef struct 
{
    char          name[MAX_SIZE_SCENE_NAME];    // scene name, ex : "Indoor", "Outdoor"
    unsigned char modes[NUM_RECORD_MODE];       // modes[0] for handset, modes[1] for headset, modes[2] for bt
} HD_REC_SCENE_INFO;
*/

/*
typedef struct  
{
    HD_REC_SCENE_INFO voice_rec_scenes[MAX_NUM_SCENE]; // ex: indoor scene, indoor scene, ...
    unsigned char 	  num_voice_rec_scene;

    HD_REC_SCENE_INFO video_rec_scenes[MAX_NUM_SCENE]; // ex: concert scene, ...
    unsigned char     num_video_rec_scene;
} HD_REC_SCENE_TABLE_STRUCT;
*/

typedef struct  
{
    unsigned char num_voice_rec_scenes;
    unsigned char num_video_rec_scenes;
    unsigned char scene_table[MAX_HD_REC_SCENES][NUM_HD_REC_DEVICE_SOURCE];
} AUDIO_HD_RECORD_SCENE_TABLE_STRUCT;


#define SPC_MAX_NUM_RECORD_SPH_MODE     (30)
#define SPC_MAX_NUM_RECORD_INPUT_FIR    (8)

#define SPEECH_PARA_NUM                 (16)
#define WB_FIR_NUM                      (90)

typedef struct _AUDIO_HD_RECORD_PARAM_STRUCT
{
    /* HD RECORD Mode Num & FIR Num*/
    unsigned short hd_rec_mode_num; // max(hd_rec_fir_num) == 30 
    unsigned short hd_rec_fir_num;  // max(hd_rec_fir_num) == 4 
    
    /* HD RECORD Speech Enhancement */
    unsigned short hd_rec_speech_mode_para[SPC_MAX_NUM_RECORD_SPH_MODE][SPEECH_PARA_NUM]; // the contain only have hd_rec_mode_num effective values
    
    /* HD RECORD FIR */
    short          hd_rec_fir[SPC_MAX_NUM_RECORD_INPUT_FIR][WB_FIR_NUM]; // the contain only have hd_rec_fir_num effective values
    
    /* HD RECORD FIR Mapping (ex, map[sph_mode] = FIR3) */
    unsigned short hd_rec_map_to_fir_for_ch1[SPC_MAX_NUM_RECORD_SPH_MODE];
    unsigned short hd_rec_map_to_fir_for_ch2[SPC_MAX_NUM_RECORD_SPH_MODE];

    /* HD RECORD Device Mode Mapping (ex, map[sph_mode] = SPH_MODE_NORMAL ) */
    unsigned char hd_rec_map_to_dev_mode[SPC_MAX_NUM_RECORD_SPH_MODE];

    /* HD RECORD Input Source Mapping (ex, map[sph_mode] = BT Earphone mic)*/
    unsigned char hd_rec_map_to_input_src[SPC_MAX_NUM_RECORD_SPH_MODE];

    /* HD RECORD mode is stereo or not (ex, map[sph_mode] = 0(mono), 1(stereo) )*/
    unsigned char hd_rec_map_to_stereo_flag[SPC_MAX_NUM_RECORD_SPH_MODE];

} AUDIO_HD_RECORD_PARAM_STRUCT;


// crystalAfcData
#define XO_SlopeArea_Num       33  // change from 8 to 33, 8 is obsolete

typedef struct {
	int		min_freq;
	short	min_dac;
	int		inv_slope;
}XO_SLOPE_AREA_DATA;

typedef struct {  
	XO_SLOPE_AREA_DATA		XO_SlopeAreaData[XO_SlopeArea_Num]; 
}l1cal_crystalAfcData_T;

// IMEISV
typedef struct {
	char			imei[16];
	unsigned char	svn;
	unsigned char	pad;
}IMEISV_struct_T;

// Custom Acoustic Volume
#define MAX_VOL_CATE		3
#define MAX_VOL_TYPE		7
#define MAX_VOL_LEVEL		7
typedef struct {
	unsigned char	volume_gain[MAX_VOL_CATE][MAX_VOL_TYPE][MAX_VOL_LEVEL];
	// Volume Gain:	[Mode (Normal, Headset, LoudSpeaker)]									
	//				[Tone type (CallTone, Keytone, MIC, GMI, Speech, SideTone, Melody) ]	
	//				[Level (1~7)]															

	unsigned char	volume[MAX_VOL_CATE][MAX_VOL_TYPE];
	// Current Volume Level:	[Mode (Normal, Headset, LoudSpeaker)]									
	//							[Tone type (CallTone, Keytone, MIC, GMI, Speech, SideTone, Melody) ]	
	//							value: 0~6 [ Level_1(0) ~ Level_7(6) ]
   	
} CustAcousticVol_T;
typedef struct {
	unsigned char	volume_gain[MAX_VOL_CATE][MAX_VOL_TYPE][MAX_VOL_LEVEL];
	// Volume Gain:	[Mode (Normal, Headset, LoudSpeaker)]									
	//				[Tone type (CallTone, Keytone, MIC, GMI, Speech, SideTone, Melody) ]	
	//				[Level (1~7)]															

	unsigned char	volume[MAX_VOL_CATE][MAX_VOL_TYPE];
	// Current Volume Level:	[Mode (Normal, Headset, LoudSpeaker)]									
	//							[Tone type (CallTone, Keytone, MIC, GMI, Speech, SideTone, Melody) ]	
	//							value: 0~6 [ Level_1(0) ~ Level_7(6) ]
   	unsigned char max_melody_volume_gain[MAX_VOL_CATE + 1];
    unsigned char melody_volume_gain_step[MAX_VOL_CATE + 1];
    unsigned char tv_out_volume_gain[MAX_VOL_LEVEL];
} CustAcousticVol16lvl_T;

// S/W Change 
typedef enum {
	LID_VER_SAME = 0,
	LID_VER_CHANGED
}LID_STATUS;

typedef struct {
	int		OldVer;
	int		NewVer;
	char	LID[64];
}LID_Info;

typedef struct {
   int		target_nvramsize;	// current NVRAM size on target FAT file system
   int		target_freespace;	// current freespace of target FAT file system
   int		target_overhead;	// S/W upgrade operation overhead
   int		newdb_nvramsize;	// new NVRAM size
   unsigned char	status;		// 0 -> [OK] safe to upgrade to new NVRAM
   								// 1 -> [ERROR] can't retrieve info from target
   								// 2 -> [ERROR] freespace is not enough to upgrade to new NVRAM
} NVRAM_GetDiskInfo_Cnf;

// WiFi 
typedef struct {
	unsigned char	mac_addr[6];
} WiFi_MacAddress_S;

typedef struct {
	unsigned char	CCKTxPWR[14]; 
	unsigned char	OFDMTxPWR[14]; 
} WiFi_TxPower_2400M_S;

typedef struct {
	unsigned char	TxPWR[34]; 
} WiFi_TxPower_5000M_S;

typedef struct {
	unsigned char	i_ch_offset;
	unsigned char	q_ch_offset;
} WiFi_DAC_DC_Offset_S;

typedef struct {
	unsigned char txAlcCCK[14];
    unsigned char txOutputPowerDBCCK[14];
    unsigned char txAlcOFDM [8][14];
    unsigned char txOutputPowerDBOFDM[8][14];
} WiFi_ALC_2400M_S;

typedef struct
{
    unsigned char alcSlop1Divider;
    unsigned char alcSlop1Dividend;
    unsigned char alcSlop2Divider;
    unsigned char alcSlop2Dividend;
} WiFi_TxALC_2400M_S;
typedef struct
{
   unsigned char BluetoothAddress[6];
   unsigned char MinEncryptionSize[1];
   unsigned char MaxEncryptionSize[1];
   unsigned char HCITransportLayerParameters[3];
   unsigned char FixedPIN[16];
   unsigned char FixedPINLength[1];
   unsigned char SleepEnableMask[1];
   unsigned char LowPowerClockParameter[8];
   unsigned char PowerControlConfiguration[13];
   unsigned char SleepControlParameters[12];
   unsigned char DebugControl[4];
   unsigned char LCandRMOverrideEnable[4];
   unsigned char RadioRegisterOverride[6];
   unsigned char CodecConfiguration[8];
   unsigned char CVSDGainVolumeSettings[6];
   unsigned char VoiceSettings[2];
   unsigned char UserBaudRate[3];

   unsigned char LowPowerDriftRate[1];
   unsigned char MaxTxPowerLevel[1];
   unsigned char AdaptiveFrequencyHoppingParameters[29];
   unsigned char BufferSize[4];
   unsigned char GpioMapping[16];
   unsigned char GpioPolarity[4];
}  nvram_ef_btradio_rfmd3500_struct;

typedef struct
{
    unsigned char BDAddr[6];
    unsigned char ClassOfDevice[3];
    unsigned char LinkKeyType[1];
    unsigned char UnitKey[16];
    unsigned char Encryption[3];
    unsigned char PinCodeType[1];
    unsigned char Voice[2];
    unsigned char Codec[1];
    unsigned char Radio[30];
    unsigned char Sleep[6];
    unsigned char MainOscillatorInfo[5];
    unsigned char LPOInfo[4];
    unsigned char AFH[9];
    unsigned char PTA[49];
    unsigned char WDT[2];
    unsigned char Debug[1];
    unsigned char UART[2];
}  nvram_ef_btradio_mt6601_struct;

//Deprecated structure
/*
typedef struct
{
	unsigned char addr[6];
	unsigned char CapId[1];
	unsigned char LinkKeyType[1];
	unsigned char UnitKey[16];
	unsigned char Encryption[3];
	unsigned char PinCodeType[1];
	unsigned char Voice[2];
	unsigned char Codec[2];
	unsigned char Radio[6];
	unsigned char Sleep[7];
	unsigned char Reserved[2];
}nvram_ef_btradio_mt6611_struct;
*/

typedef struct
{
    unsigned char addr[6];
    unsigned char CapId[1];
    unsigned char Codec[1];
    
} NVRAM_BTRADIO_MT6611_S;

//delete old struct define
/*
typedef struct
{
    unsigned char addr[6];
    unsigned char Voice[2];
    unsigned char Codec[4];
    unsigned char Radio[6];
    unsigned char Sleep[7];
    unsigned char BtFTR[2];
    unsigned char TxPWOffset[3];
    
} NVRAM_BTRADIO_MT6620_S;
*/

typedef struct
{
    unsigned char addr[6];
    unsigned char Voice[2];
    unsigned char Codec[4];
    unsigned char Radio[6];
    unsigned char Sleep[7];
    unsigned char BtFTR[2];
    unsigned char TxPWOffset[3];
	unsigned char CoexAdjust[6];      // BT/WIFI coexistence performance adjustment
    unsigned char Reserved1[2];       // Reserved
    unsigned char Reserved2[2];       // Reserved
    unsigned char Reserved3[4];       // Reserved
    unsigned char Reserved4[4];       // Reserved
    unsigned char Reserved5[8];       // Reserved
    unsigned char Reserved6[8];       // Reserved
    
} NVRAM_BTRADIO_MT6620_S;

typedef struct
{
    unsigned char addr[6];
    unsigned char CapId[1];
    unsigned char LinkKeyType[1];
    unsigned char UintKey[16];
    unsigned char Encryption[3];
    unsigned char PinCodeType[1];
    unsigned char Voice[2];
    unsigned char Codec[4];
    unsigned char Radio[6];
    unsigned char Sleep[7];
    unsigned char BtFTR[2];
    unsigned char TxPWOffset[3];
    unsigned char ECLK_SEL[1];
    unsigned char Reserved1[1];
    unsigned char Reserved2[2];
    unsigned char Reserved3[4];
    unsigned char Reserved4[4];
    unsigned char Reserved5[16];
    unsigned char Reserved6[16];
    
}NVRAM_BTRADIO_MT6626_S;

//-----------------------------------------------------//
//  NVRAM: callback function definition                //
//-----------------------------------------------------//
typedef void (__stdcall *META_NVRAM_Reset_CNF)(const FT_NVRAM_RESET_CNF *cnf, const short token, void *usrData);
typedef void (__stdcall *META_NVRAM_Read_CNF)(const FT_NVRAM_READ_CNF *cnf, const short token, void *usrData);
typedef void (__stdcall *META_NVRAM_Write_CNF)(const FT_NVRAM_WRITE_CNF *cnf, const short token, void *usrData);
typedef void (__stdcall *CB_META_NVRAM_GET_DISK_INFO_CNF)(const NVRAM_GetDiskInfo_Cnf *cnf, const short token, void *usrData);

//-----------------------------------------------------//
//  NVRAM: exported function definition                //
//-----------------------------------------------------//
META_RESULT  __stdcall SP_META_NVRAM_Init(const char *PathName, unsigned long *p_nvram_CatcherTranAddr);
META_RESULT  __stdcall SP_META_NVRAM_Init_r(const int meta_handle,const char *PathName, unsigned long *p_nvram_CatcherTranAddr);
META_RESULT  __stdcall SP_META_NVRAM_Reset(const FT_NVRAM_RESET_REQ *req, const META_NVRAM_Reset_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_NVRAM_Reset_r(const int meta_handle, const FT_NVRAM_RESET_REQ *req, const META_NVRAM_Reset_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_NVRAM_Read(const FT_NVRAM_READ_REQ *req, FT_NVRAM_READ_CNF *cnf, const META_NVRAM_Read_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_NVRAM_Read_r(const int meta_handle, const FT_NVRAM_READ_REQ *req, FT_NVRAM_READ_CNF *cnf, const META_NVRAM_Read_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_NVRAM_Write(const FT_NVRAM_WRITE_REQ *req, const META_NVRAM_Write_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_NVRAM_Write_r(const int meta_handle, const FT_NVRAM_WRITE_REQ *req, const META_NVRAM_Write_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_NVRAM_GetAllLIDNameLength(int *len);
META_RESULT  __stdcall SP_META_NVRAM_GetAllLIDName(char *buf, const int buf_len, int *NofLID);
META_RESULT  __stdcall SP_META_NVRAM_GetLIDVersion(const char *LID,unsigned short *ver);
META_RESULT  __stdcall SP_META_NVRAM_GetRecStructNameLength(const char *LID, int *len);
META_RESULT  __stdcall SP_META_NVRAM_GetRecStructName(const char *LID, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_GetAllRecFieldNameLength(const char *LID, int *len);
META_RESULT  __stdcall SP_META_NVRAM_GetAllRecFieldName(const char *LID, char *buf, const int buf_len, int *NofField);
META_RESULT  __stdcall SP_META_NVRAM_CheckFieldNameExist(const char *LID, const char *Field, bool *result);
META_RESULT  __stdcall SP_META_NVRAM_GetRecNum(const char *LID, int *num);
META_RESULT  __stdcall SP_META_NVRAM_GetRecLen(const char *LID, int *len);
META_RESULT  __stdcall SP_META_NVRAM_SetRecFieldValue(const char *LID, const char *field, char *buf, const int buf_len, void *value, const int value_len);
META_RESULT  __stdcall SP_META_NVRAM_GetRecFieldValue(const char *LID, const char *field, const char *buf, const int buf_len, void *value, const int value_len);
META_RESULT  __stdcall SP_META_NVRAM_SetRecFieldBitValue(const char *LID, const char *field, const char *bitname, char *buf, const int buf_len, const int bitvalue);
META_RESULT  __stdcall SP_META_NVRAM_GetRecFieldBitValue(const char *LID, const char *field, const char *bitname, const char *buf, const int buf_len, int *bitvalue);
META_RESULT  __stdcall SP_META_NVRAM_QueryIsLIDExist(const char *LID);
META_RESULT  __stdcall SP_META_NVRAM_ResetToFactoryDefault(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_NVRAM_ResetToFactoryDefault_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_NVRAM_LockDown(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_NVRAM_LockDown_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_NVRAM_OTP_LockDown(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_NVRAM_OTP_LockDown_r(const int meta_handle, unsigned int ms_timeout);

// S/W Change
META_RESULT  __stdcall SP_META_NVRAM_SWC_RetrieveChangeList(void);
META_RESULT  __stdcall SP_META_NVRAM_SWC_RetrieveChangeList_r(const int meta_handle);
META_RESULT  __stdcall SP_META_NVRAM_SWC_UpdateChangeList(void);
META_RESULT  __stdcall SP_META_NVRAM_SWC_UpdateChangeList_r(const int meta_handle);
META_RESULT  __stdcall SP_META_NVRAM_SWC_GetAllChangedLIDCount(int *NofLID);
META_RESULT  __stdcall SP_META_NVRAM_SWC_GetAllChangedLIDCount_r(const int meta_handle, int *NofLID);
META_RESULT  __stdcall SP_META_NVRAM_SWC_GetAllChangedLIDName(LID_Info *p_ArrayOfLID, const int NofLID);
META_RESULT  __stdcall SP_META_NVRAM_SWC_GetAllChangedLIDName_r(const int meta_handle, LID_Info *p_ArrayOfLID, const int NofLID);
META_RESULT  __stdcall SP_META_NVRAM_SWC_QueryIfLIDChanged(const char *LID, LID_STATUS  *result);
META_RESULT  __stdcall SP_META_NVRAM_SWC_QueryIfLIDChanged_r(const int meta_handle, const char *LID, LID_STATUS  *result);
META_RESULT  __stdcall SP_META_NVRAM_SWC_ImportData(LID_Info *p_import_multiple_lid, int num_of_import_multiple_lid, int import_1st_sys_record_size );
META_RESULT  __stdcall SP_META_NVRAM_SWC_ImportData_r(const int meta_handle, LID_Info *p_import_multiple_lid, int num_of_import_multiple_lid, int import_1st_sys_record_size );
META_RESULT  __stdcall SP_META_NVRAM_SWC_Database_Compare(const char *PathName, int *p_NumOfNewAddLID, int *p_NumOfModifiedLID, int *p_NumOfDeletedLID);
META_RESULT  __stdcall SP_META_NVRAM_SWC_Database_Compare_r(const int meta_handle, const char *PathName, int *p_NumOfNewAddLID, int *p_NumOfModifiedLID, int *p_NumOfDeletedLID);
META_RESULT  __stdcall SP_META_NVRAM_SWC_Get_Database_Compare_Result(LID_Info *p_ArrayOfNewAddLID, const int NumOfNewAddLID, LID_Info *p_ArrayOfModifiedLID, const int NumOfModifiedLID, LID_Info *p_ArrayOfDeletedLID, const int NumOfDeletedLID);
META_RESULT  __stdcall SP_META_NVRAM_SWC_Get_Database_Compare_Result_r(const int meta_handle, LID_Info *p_ArrayOfNewAddLID, const int NumOfNewAddLID, LID_Info *p_ArrayOfModifiedLID, const int NumOfModifiedLID, LID_Info *p_ArrayOfDeletedLID, const int NumOfDeletedLID);
META_RESULT  __stdcall SP_META_NVRAM_SWC_Check_FAT_FreeSpace(const CB_META_NVRAM_GET_DISK_INFO_CNF  cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_NVRAM_SWC_Check_FAT_FreeSpace_r(const int meta_handle, const CB_META_NVRAM_GET_DISK_INFO_CNF  cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_NVRAM_SWC_Enable_ForceUpgrade(void);
META_RESULT  __stdcall SP_META_NVRAM_SWC_Enable_ForceUpgrade_r(const int meta_handle);
META_RESULT  __stdcall SP_META_NVRAM_SWC_Disable_ForceUpgrade(void);
META_RESULT  __stdcall SP_META_NVRAM_SWC_Disable_ForceUpgrade_r(const int meta_handle);

META_RESULT  __stdcall SP_META_NVRAM_Compose_AudioBesLoudNess(const l4aud_acf_param *param, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_AudioBesLoudNess(l4aud_acf_param *param, const char *buf, const int buf_len);

// 6516 add
META_RESULT  __stdcall SP_META_NVRAM_Compose_AudioBesLoudNess_6516(const l4aud_get_acf_param_cnf *param, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_AudioBesLoudNess_6516(l4aud_get_acf_param_cnf *param, const char *buf, const int buf_len);

// AGC path loss 
META_RESULT  __stdcall SP_META_NVRAM_agcPathLoss_Len(int *len);
META_RESULT  __stdcall SP_META_NVRAM_Compose_agcPathLoss(const l1cal_agcPathLoss_T *loss, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_agcPathLoss(l1cal_agcPathLoss_T *loss, const char *buf, const int buf_len);

META_RESULT  __stdcall SP_META_NVRAM_rampTable_Len(int *len);
META_RESULT  __stdcall SP_META_NVRAM_Compose_rampTable(const l1cal_rampTable_T *tbl, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_rampTable(l1cal_rampTable_T *tbl, const char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_rampTable_Len_Ex(int *len);
META_RESULT  __stdcall SP_META_NVRAM_Compose_rampTable_Ex(const l1cal_rampTable_T_Ex *tbl, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_rampTable_Ex(l1cal_rampTable_T_Ex *tbl, const char *buf, const int buf_len);

// rampTable
META_RESULT  __stdcall SP_META_NVRAM_rampTable_Len_Ex2(int *len);
META_RESULT  __stdcall SP_META_NVRAM_Compose_rampTable_Ex2(const l1cal_rampTable_T_Ex2 *tbl, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_rampTable_Ex2(l1cal_rampTable_T_Ex2 *tbl, const char *buf, const int buf_len);

// L1Audio Param
META_RESULT  __stdcall SP_META_NVRAM_AudioParam_Len(int *len);
META_RESULT  __stdcall SP_META_NVRAM_Compose_AudioParam(const l1audio_param_T *param, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_AudioParam(l1audio_param_T *param, const char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_If_AudioParam_W0547_Support(void);
META_RESULT  __stdcall SP_META_NVRAM_Compose_AudioParam_W0547(const l1audio_param_W0547_T *param, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_AudioParam_W0547(l1audio_param_W0547_T *param, const char *buf, const int buf_len);

META_RESULT  __stdcall SP_META_NVRAM_Compose_AudioParam_W0547_45(const l1audio_param_W0547_45_T *param, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_AudioParam_W0547_45(l1audio_param_W0547_45_T *param, const char *buf, const int buf_len);

META_RESULT  __stdcall SP_META_NVRAM_Compose_AudioParam_W0712(const l1audio_param_W0712_T *param, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_AudioParam_W0712(l1audio_param_W0712_T *param, const char *buf, const int buf_len);
// interRampData
META_RESULT  __stdcall SP_META_NVRAM_interRampData_Len(int *len);
META_RESULT  __stdcall SP_META_NVRAM_Compose_interRampData(const l1cal_interRampData_T *tbl, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_interRampData(l1cal_interRampData_T *tbl, const char *buf, const int buf_len);
// crystalAfcData
META_RESULT  __stdcall SP_META_NVRAM_crystalAfcData_Len(int *len);
META_RESULT  __stdcall SP_META_NVRAM_Compose_crystalAfcData(const l1cal_crystalAfcData_T *xo_afc, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_crystalAfcData(l1cal_crystalAfcData_T *xo_afc, const char *buf, const int buf_len);
// IMEISV
META_RESULT  __stdcall SP_META_NVRAM_Calculate_IMEI_CD(const char *imei, unsigned short *p_cd);
META_RESULT  __stdcall SP_META_NVRAM_IMEISV_Len(int *len);
META_RESULT  __stdcall SP_META_NVRAM_Compose_IMEISV(const IMEISV_struct_T  *p_imeisv, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Compose_IMEISV_NoCheck(const IMEISV_struct_T  *p_imeisv, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Compose_IMEISV_ex(const IMEISV_struct_T  *p_imeisv, char *buf, const int buf_len,bool DoCheckSum);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_IMEISV(IMEISV_struct_T  *p_imeisv, const char *buf, const int buf_len);

// Custom Acoustic Volume
META_RESULT  __stdcall SP_META_NVRAM_CustAcousticVol_Len(int *len);
META_RESULT  __stdcall SP_META_NVRAM_Compose_CustAcousticVol(const CustAcousticVol_T *cust_acoustic_vol, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_CustAcousticVol(CustAcousticVol_T *cust_acoustic_vol, const char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Compose_16lvlCustAcousticVol(const CustAcousticVol16lvl_T *cust_acoustic_vol, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_16lvlCustAcousticVol(CustAcousticVol16lvl_T *cust_acoustic_vol, const char *buf, const int buf_len);
// RF Module Configuration 
META_RESULT  __stdcall SP_META_NVRAM_RFSpecialCoef_Len(int *len);
// Skyworks 
META_RESULT  __stdcall SP_META_NVRAM_Compose_SKY74045_RFSpecialCoef(const RF_SKY74045_Coef_T *rf_mod_coef, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_SKY74045_RFSpecialCoef(RF_SKY74045_Coef_T *rf_mod_coef, const char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Compose_SKY74117_RFSpecialCoef(const RF_SKY74117_Coef_T *rf_mod_coef, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_SKY74117_RFSpecialCoef(RF_SKY74117_Coef_T *rf_mod_coef, const char *buf, const int buf_len);
// MT6139B 
META_RESULT  __stdcall SP_META_NVRAM_Compose_MT6139B_RFSpecialCoef(const RF_MT6139B_Coef_T *rf_mod_coef, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_MT6139B_RFSpecialCoef(RF_MT6139B_Coef_T *rf_mod_coef, const char *buf, const int buf_len);
// MT6140
META_RESULT  __stdcall SP_META_NVRAM_Compose_MT6140tx_RFSpecialCoef(const mt6140tx *rf_mod_coef, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_MT6140tx_RFSpecialCoef(mt6140tx *rf_mod_coef, const char *buf, const int buf_len);

META_RESULT  __stdcall SP_META_NVRAM_Compose_MT6140tx_PaVbias(const mt6140tx *pavbias, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_MT6140tx_PaVbias(mt6140tx *pavbias, const char *buf, const int buf_len);

// Renesas Bright5P 
META_RESULT  __stdcall SP_META_NVRAM_Compose_BRIGHT5P_RFSpecialCoef(const RF_BRIGHT5P_Coef_T *rf_mod_coef, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_BRIGHT5P_RFSpecialCoef(RF_BRIGHT5P_Coef_T *rf_mod_coef, const char *buf, const int buf_len);
// EPSK interRampData 
META_RESULT  __stdcall SP_META_NVRAM_EPSK_interRampData_Len(int *len);
META_RESULT  __stdcall SP_META_NVRAM_Compose_EPSK_interRampData(const l1cal_EPSK_interRampData_T *tbl, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_EPSK_interRampData(l1cal_EPSK_interRampData_T *tbl, const char *buf, const int buf_len);




META_RESULT  __stdcall SP_META_NVRAM_3G_Compose_tempdacData(const ul1cal_tempdacData_T  *dac, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_3G_Decompose_tempdacData(ul1cal_tempdacData_T  *dac, const char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_3G_Compose_pathlossData(const ul1cal_pathlossData_T  *pathloss, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_3G_Decompose_pathlossData(ul1cal_pathlossData_T  *pathloss, const char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_3G_Compose_txdacData(const ul1cal_txdacData_T  *txdac, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_3G_Decompose_txdacData(ul1cal_txdacData_T  *txdac, const char *buf, const int buf_len);


// Gain Table

META_RESULT  __stdcall SP_META_Audio_GainTable(unsigned int ms_timeout, l4aud_gaintable_cnf * pCnf);
META_RESULT  __stdcall SP_META_Audio_GainTable_r(const int meta_handle, unsigned int ms_timeout, l4aud_gaintable_cnf *pCnf);
META_RESULT  __stdcall SP_META_Audio_GainTableNum(unsigned int ms_timeout, l4aud_gaintablenum_cnf *pCnf);
META_RESULT  __stdcall SP_META_Audio_GainTableNum_r(const int meta_handle, unsigned int ms_timeout, l4aud_gaintablenum_cnf *pCnf);
META_RESULT  __stdcall SP_META_Audio_GainTableLevel(unsigned int ms_timeout,l4aud_gaintablelevel_req *pReq, l4aud_gaintablelevel_cnf *pCnf);
META_RESULT  __stdcall SP_META_Audio_GainTableLevel_r(const int meta_handle,unsigned int ms_timeout,l4aud_gaintablelevel_req *pReq, l4aud_gaintablelevel_cnf *pCnf);
META_RESULT  __stdcall SP_META_Audio_CtrpointNum(unsigned int ms_timeout,l4aud_ctrpointnum_cnf *pCnf);
META_RESULT  __stdcall SP_META_Audio_CtrpointNum_r(const int meta_handle,unsigned int ms_timeout,l4aud_ctrpointnum_cnf *pCnf);
META_RESULT  __stdcall SP_META_Audio_CtrpointBits(unsigned int ms_timeout, l4aud_ctrpointbits_req *pReq,l4aud_ctrpointbits_cnf *pCnf);
META_RESULT  __stdcall SP_META_Audio_CtrpointBits_r(const int meta_handle,unsigned int ms_timeout,l4aud_ctrpointbits_req *pReq,l4aud_ctrpointbits_cnf *pCnf);
META_RESULT  __stdcall SP_META_Audio_CtrpointTable(unsigned int ms_timeout, l4aud_ctrpointtable_req *pReq,l4aud_ctrpointtable_cnf *pCnf);
META_RESULT  __stdcall SP_META_Audio_CtrpointTable_r(const int meta_handle,unsigned int ms_timeout, l4aud_ctrpointtable_req *pReq,l4aud_ctrpointtable_cnf *pCnf);
META_RESULT  __stdcall SP_META_NVRAM_Compose_AudioGainTable(const AUDIO_GAIN_TABLE_STRUCT *param, char *buf, const int buf_len, bool isVersionV4);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_AudioGainTable(AUDIO_GAIN_TABLE_STRUCT *param, char *buf, const int buf_len, bool isVersionV4);


// HD Recording

META_RESULT  __stdcall SP_META_Audio_HdRecGetInfo(unsigned int ms_timeout, l4aud_hdrec_info_cnf * pCnf);
META_RESULT  __stdcall SP_META_Audio_HdRecGetInfo_r(const int meta_handle, unsigned int ms_timeout, l4aud_hdrec_info_cnf * pCnf);
META_RESULT  __stdcall SP_META_NVRAM_Compose_AudioHdRecSceneTableStruct(const AUDIO_HD_RECORD_SCENE_TABLE_STRUCT *param, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_AudioHdRecSceneTableStruct(AUDIO_HD_RECORD_SCENE_TABLE_STRUCT *param, const char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Compose_AudioHdRecParamStruct(const AUDIO_HD_RECORD_PARAM_STRUCT *param, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_AudioHdRecParamStruct(AUDIO_HD_RECORD_PARAM_STRUCT *param, const char *buf, const int buf_len);



//BT
typedef enum 
{
  BT_CHIP_ID_MT6611 = 0,
  BT_CHIP_ID_MT6612,
  BT_CHIP_ID_MT6616,
  BT_CHIP_ID_MT6620,
  BT_CHIP_ID_MT6622,
  BT_CHIP_ID_MT6626,
  BT_CHIP_ID_MT6628,
  BT_CHIP_ID_MT6572,
  BT_CHIP_ID_MT6582,
  BT_CHIP_ID_MT6592,
  BT_CHIP_ID_MT6630,
  BT_CHIP_ID_END
  
} BT_CHIP_ID_E;

META_RESULT  __stdcall SP_META_NVRAM_BT_Compose_RFMD3500Radio(const nvram_ef_btradio_rfmd3500_struct  *radio, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_BT_Decompose_RFMD3500Radio(nvram_ef_btradio_rfmd3500_struct  *radio, const char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_BT_Compose_MT6601Radio(const nvram_ef_btradio_mt6601_struct  *radio, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_BT_Decompose_MT6601Radio(nvram_ef_btradio_mt6601_struct  *radio, const char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_BT_Compose_MT6611Radio(const NVRAM_BTRADIO_MT6611_S *radio, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_BT_Decompose_MT6611Radio(NVRAM_BTRADIO_MT6611_S *radio, const char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_BT_Compose_MT6620Radio(const NVRAM_BTRADIO_MT6620_S *radio, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_BT_Decompose_MT6620Radio(NVRAM_BTRADIO_MT6620_S *radio, const char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_BT_Compose_MT6626Radio(const NVRAM_BTRADIO_MT6626_S *radio, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_BT_Decompose_MT6626Radio(NVRAM_BTRADIO_MT6626_S *radio, const char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_BT_QueryChipByStructSize(BT_CHIP_ID_E * chipID);

// sBBTxParameters
META_RESULT  __stdcall SP_META_NVRAM_BBTXParameters_Len(int *len);
META_RESULT  __stdcall SP_META_NVRAM_Compose_BBTXParameters(const BBTXParameters_T *bbtx, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_BBTXParameters(BBTXParameters_T *bbtx, const char *buf, const int buf_len);
//l1audio_param_W0740_T
META_RESULT  __stdcall SP_META_NVRAM_Compose_AudioParam_W0740(const l1audio_param_W0740_T *param, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_AudioParam_W0740(l1audio_param_W0740_T *param, const char *buf, const int buf_len);
// l1audio_param_W0809_T
META_RESULT  __stdcall SP_META_NVRAM_Compose_AudioParam_W0809(const l1audio_param_W0809_T *param, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_AudioParam_W0809(l1audio_param_W0809_T *param, const char *buf, const int buf_len);
// ad6546tx
META_RESULT  __stdcall SP_META_NVRAM_Compose_ad6546tx(const ad6546tx *adtx, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_ad6546tx(ad6546tx *adtx, const char *buf, const int buf_len);
//Dual mic
META_RESULT  __stdcall SP_META_NVRAM_Compose_Extra_AudioParam_W1105(const l1audio_extra_param_W1105_T *param, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_Extra_AudioParam_W1105(l1audio_extra_param_W1105_T *param, const char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Compose_Extra_AudioParam_W1134(const l1audio_extra_param_W1134_T *param, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_Extra_AudioParam_W1134(l1audio_extra_param_W1134_T *param, const char *buf, const int buf_len);
// l1audio_param_W0809_6516_T   (NEW ADD)
META_RESULT  __stdcall SP_META_NVRAM_Compose_AudioParam_W0809_6516(const l1audio_param_W0809_6516_T *param, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_AudioParam_W0809_6516(l1audio_param_W0809_6516_T *param, const char *buf, const int buf_len);


//--------------------------------------------------------------------------//
//  Audio Testing                                                           //
//--------------------------------------------------------------------------//

//-----------------------------------------------------//
//  Audio Testing: data structure definition           //
//-----------------------------------------------------//

// audio testing result
typedef enum  {
	AUD_RES_OK = 0,						// OK 
	AUD_RES_FAIL,						// General Fail 
	AUD_RES_BUSY,						// system busy 
	AUD_RES_DISC_FULL,					// Memory full 
	AUD_RES_OPEN_FILE_FAIL,				// open file fail 
	AUD_RES_END_OF_FILE,				// play finish 
	AUD_ERR_OP_NOT_SUPPORT = 0xFB,       // added by ShuMin, for error handler enhancements// filepath too long
	AUD_ERR_STILL_PLAYING = 0xFC,       // added by ShuMin, because I found target had this error value
	AUD_ERR_PEER_BUF_ERROR = 0xFD,		// peer buf error 
	AUD_ERR_FILEPATH_ERROR = 0xFE,		// filepath error 
	AUD_ERR_FILEPATH_TOO_LONG = 0xFF	// filepath too long 
}AUDIO_RESULT;

// play style enum 
typedef enum {
	FT_L4AUD_AUDIO_PLAY_CRESCENDO = 0,	// Play sound for crescendo. 
	FT_L4AUD_AUDIO_PLAY_INFINITE,		// Play sound for infinite. 
	FT_L4AUD_AUDIO_PLAY_ONCE,			// Play sound for once. 
	FT_L4AUD_AUDIO_PLAY_DESCENDO		// Play sound for descendo. 
}AUDIO_PLAY_STYLE;

// default system embeded audio id query 
typedef struct {
	unsigned short		MinRingTone_ID;
	unsigned short		MaxRingTone_ID;
	unsigned short		MinMIDI_ID;
	unsigned short		MaxMIDI_ID;
	unsigned short		MinSound_ID;
	unsigned short		MaxSound_ID;
	AUDIO_RESULT		status;
}Audio_Query_ID_Cnf;

// play default system embeded audio by the given audio id 
typedef struct {
	unsigned short		audio_id;		// default system embeded audio id 
	AUDIO_PLAY_STYLE	play_style;		// play style 
}Audio_Play_Req;

// play audio from FAT by the given filepath 
typedef struct {
	const char			*fat_filepath;	// filepath on target FAT file system 
	AUDIO_PLAY_STYLE	play_style;		// play style 
}Audio_Play_ByName_Req;

// play imelody by the buffer from PC side 
typedef struct {
	const char			*imy_buf;		// buffer that stores iMelody content 
	unsigned int		imy_buf_len;	// length of buffer 
	unsigned char		imy_instrument;	// instrument id, 1 ~ 128 
	AUDIO_PLAY_STYLE	play_style;		// play style 
}Audio_Play_IMY_ByBuf_Req;

// play mp3 from FAT by the given filepath 
typedef struct {
	const char			*fat_filepath;	// filepath on target FAT file system 
	AUDIO_PLAY_STYLE	play_style;		// play style 
}Audio_MEDIA_Play_Req;

// set volume 
typedef struct {
	unsigned char		volume;			// play volume, 0 ~ 255 
}Audio_Set_Volume_Req;

typedef struct {
	unsigned char		echoflag;			// echofalg true
}Audio_Set_Echo_Req;

typedef struct {
	unsigned char		modeflag;			// modeflag
}Audio_Set_Mode_Req;

typedef struct {
	unsigned char		type;
	unsigned char		gain;
}Audio_Set_Gain_Req;

typedef struct {
	short		in_fir_coeffs[45];
	short		out_fir_coeffs[45];
}Audio_Set_LoudSpk_FIR_Coeffs_Req;

/*
typedef struct
{
	unsigned int     bes_loudness_hsf_coeff[9][4];
	unsigned int     bes_loudness_bpf_coeff[4][6][3];
	// BesLoudness V3
	unsigned int besloudness_DRC_Forget_Table[9][2];
	unsigned int besloudness_WS_Gain_Max;
	unsigned int besloudness_WS_Gain_Min;
	unsigned int besloudness_Filter_First;
	char         besloudness_Gain_Map_In[5];
	char         besloudness_Gain_Map_Out[5];
	
}Audio_Ex_SetACFToTarget_REQ_T;
*/





typedef struct {
	unsigned short speech_common_para[12];  // 8 or 12, so at most 12
}Audio_Set_Speech_Common_Req;

typedef struct {
	unsigned short speech_loudspk_mode_para[16];  // change from 8 to 16, because at most: 16
}Audio_Set_LoudSpk_Mode_Req;

typedef struct {
	unsigned short Media_Playback_Maximum_Swing;
}Audio_Set_Playback_Maximum_Swing_Req;

typedef struct {
	short Melody_FIR_Output_Coeff_32k_Tbl1[25];
}Audio_Set_Melody_FIR_Output_Coeffs_Req;

typedef struct {
	unsigned short speech_common_para[12];
	unsigned short speech_loudspk_mode_para[16];  // change from 8 to 16, because at most: 16
}Audio_Set_Speech_Common_And_Mode_Req;

typedef struct {
	unsigned short		fre;
	unsigned char		spkgain;
	unsigned char		micgain;
	unsigned short      ulgain; 
	unsigned short      dlgain;
	unsigned short      amp;
    
}Audio_Tone_LoopBackRec_Req;

typedef struct {
	unsigned int		buffer[2000];
}Audio_Tone_LoopBackRec_Cnf;

typedef struct {
	unsigned int		buffer[500];
}Audio_Tone_LoopBackRec_Cnf_2K;

typedef struct
{
	unsigned char  m_ucVolume;
	unsigned short m_u2Freq;
}Audio_Set_Freq_Vol_Tone_Req_T;

typedef struct
{
	unsigned char  m_ucMode;
}Audio_Get_Profile_Settings_By_Mode_Req_T;

typedef struct
{
	unsigned char mode;
    unsigned char melody[7];         
    unsigned char sound[7];          
    unsigned char keytone[7];         
    unsigned char speech[7];         
    unsigned char mic[7];           
    unsigned char sidetone;         
    unsigned char max_melody_volume_gain;
    unsigned char melody_volume_gain_step;
    unsigned char tv_out_volume_gain[MAX_VOL_LEVEL];  // 7 here

}Audio_Get_Profile_Settings_By_Mode_Cnf_T;

typedef struct
{
	unsigned char mode;
    unsigned char melody[7];         
    unsigned char sound[7];          
    unsigned char keytone[7];         
    unsigned char speech[7];         
    unsigned char mic[7];           
    unsigned char sidetone;         
    unsigned char max_melody_volume_gain;
    unsigned char melody_volume_gain_step;
    unsigned char tv_out_volume_gain[MAX_VOL_LEVEL];  // 7 here

}Audio_Set_Profile_Settings_By_Mode_Req_T;

typedef struct
{
    
    unsigned short m_u2FailReason;  // possible fail resons

}Audio_Set_Profile_Settings_By_Mode_Cnf_T;


typedef struct
{
    unsigned short m_u2FailReason;  // possible fail resons, (2 means the format is not matched with Target side)
}Audio_Set_Param_Cnf_T;

typedef	struct
{
	char	receiver_test;		// receiver_test true mean enable
}ft_l4aud_receiver_test;

typedef	struct
{
	char	left_channel;		// true mean enable
	char	right_channel;		// true mean enable
}ft_l4aud_loudspk;




//For Dual Mic

typedef enum 
{
    RECORD_ERROR = 0,
    RECORD_START,
    RECORD_END,
    NUM_RECORD_STATES
    
}AUDIO_RECORD_STATES_E;


typedef struct
{
    char fileName[256];
    
}AUDIO_DL_PLAYBACK_FILE_REQ_S;

typedef struct
{
    char fileName[256];
    int duration;	  /* record duration */
    
}AUDIO_DUALMIC_RECORD_REQ_S;

typedef struct
{
    char playbackFileName[256];	
    char recordingFileName[256];
    int recordDuration;
    
}AUDIO_PLAYBACK_DUALMICRECORD_REQ_S;

typedef struct
{
    char pcFileName[256];
    char tgFileName[256];
    
}AUDIO_LOAD_FILE_REQ_S;

typedef struct
{
    int value;
    
}AUDIO_PARAM_VALUE_S;


//-----------------------------------------------------//
//  API function definition for Dual Mic       //
//-----------------------------------------------------//

META_RESULT  __stdcall SP_META_Audio_SetPlaybackFile(unsigned int  ms_timeout, const AUDIO_DL_PLAYBACK_FILE_REQ_S  *req);
META_RESULT  __stdcall SP_META_Audio_SetPlaybackFile_r(const int meta_handle, unsigned int  ms_timeout, const AUDIO_DL_PLAYBACK_FILE_REQ_S  *req);
META_RESULT  __stdcall SP_META_Audio_DualMicRecord(unsigned int  ms_timeout, const AUDIO_DUALMIC_RECORD_REQ_S *req, AUDIO_RECORD_STATES_E * cnf);
META_RESULT  __stdcall SP_META_Audio_DualMicRecord_r(const int meta_handle, unsigned int  ms_timeout, const AUDIO_DUALMIC_RECORD_REQ_S *req, AUDIO_RECORD_STATES_E * cnf);
META_RESULT  __stdcall SP_META_Audio_PlaybackDualMicRecord(unsigned int  ms_timeout, const AUDIO_PLAYBACK_DUALMICRECORD_REQ_S *req, AUDIO_RECORD_STATES_E * cnf);
META_RESULT  __stdcall SP_META_Audio_PlaybackDualMicRecord_r(const int meta_handle, unsigned int  ms_timeout, const AUDIO_PLAYBACK_DUALMICRECORD_REQ_S *req, AUDIO_RECORD_STATES_E * cnf);
META_RESULT  __stdcall SP_META_Audio_PlaybackDualMicRecord_HS(unsigned int  ms_timeout, const AUDIO_PLAYBACK_DUALMICRECORD_REQ_S *req, AUDIO_RECORD_STATES_E * cnf);
META_RESULT  __stdcall SP_META_Audio_PlaybackDualMicRecord_HS_r(const int meta_handle, unsigned int  ms_timeout, const AUDIO_PLAYBACK_DUALMICRECORD_REQ_S *req, AUDIO_RECORD_STATES_E * cnf);
META_RESULT  __stdcall SP_META_Audio_StopDualMicRecord(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_Audio_StopDualMicRecord_r(const int meta_handle, unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_Audio_DownloadFile(unsigned int  ms_timeout, const AUDIO_LOAD_FILE_REQ_S  *req);
META_RESULT  __stdcall SP_META_Audio_DownloadFile_r(const int meta_handle, unsigned int  ms_timeout, const AUDIO_LOAD_FILE_REQ_S  *req);
META_RESULT  __stdcall SP_META_Audio_UploadFile(unsigned int  ms_timeout, const AUDIO_LOAD_FILE_REQ_S  *req);
META_RESULT  __stdcall SP_META_Audio_UploadFile_r(const int meta_handle, unsigned int  ms_timeout, const AUDIO_LOAD_FILE_REQ_S  *req);
META_RESULT  __stdcall SP_META_Audio_GetRecordingGain(unsigned int  ms_timeout, AUDIO_PARAM_VALUE_S * cnf);
META_RESULT  __stdcall SP_META_Audio_GetRecordingGain_r(const int meta_handle, unsigned int  ms_timeout, AUDIO_PARAM_VALUE_S * cnf);
META_RESULT  __stdcall SP_META_Audio_SetRecordingGain(unsigned int  ms_timeout, AUDIO_PARAM_VALUE_S * req);
META_RESULT  __stdcall SP_META_Audio_SetRecordingGain_r(const int meta_handle, unsigned int  ms_timeout, AUDIO_PARAM_VALUE_S * req);
META_RESULT  __stdcall SP_META_Audio_GetPlaybackGain(unsigned int  ms_timeout, AUDIO_PARAM_VALUE_S * cnf);
META_RESULT  __stdcall SP_META_Audio_GetPlaybackGain_r(const int meta_handle, unsigned int  ms_timeout, AUDIO_PARAM_VALUE_S * cnf);
META_RESULT  __stdcall SP_META_Audio_SetPlaybackGain(unsigned int  ms_timeout, AUDIO_PARAM_VALUE_S * req);
META_RESULT  __stdcall SP_META_Audio_SetPlaybackGain_r(const int meta_handle, unsigned int  ms_timeout, AUDIO_PARAM_VALUE_S * req);
META_RESULT  __stdcall SP_META_Audio_GetPlaybackGain_HS(unsigned int  ms_timeout, AUDIO_PARAM_VALUE_S * cnf);
META_RESULT  __stdcall SP_META_Audio_GetPlaybackGain_HS_r(const int meta_handle, unsigned int  ms_timeout, AUDIO_PARAM_VALUE_S * cnf);
META_RESULT  __stdcall SP_META_Audio_SetPlaybackGain_HS(unsigned int  ms_timeout, AUDIO_PARAM_VALUE_S * req);
META_RESULT  __stdcall SP_META_Audio_SetPlaybackGain_HS_r(const int meta_handle, unsigned int  ms_timeout, AUDIO_PARAM_VALUE_S * req);

META_RESULT  __stdcall SP_META_Audio_QueryRecordStatus(AUDIO_RECORD_STATES_E * pStates);
META_RESULT  __stdcall SP_META_Audio_QueryRecordStatus_r(const int meta_handle, AUDIO_RECORD_STATES_E * pStates);

META_RESULT  __stdcall SP_META_Audio_QueryWBSupport(unsigned int  ms_timeout, AUDIO_PARAM_VALUE_S * cnf);
META_RESULT  __stdcall SP_META_Audio_QueryWBSupport_r(const int meta_handle, unsigned int  ms_timeout, AUDIO_PARAM_VALUE_S * cnf);
META_RESULT  __stdcall SP_META_Audio_SetWBMode(unsigned int  ms_timeout, AUDIO_PARAM_VALUE_S * req);
META_RESULT  __stdcall SP_META_Audio_SetWBMode_r(const int meta_handle, unsigned int  ms_timeout, AUDIO_PARAM_VALUE_S * req);


//-----------------------------------------------------//
//  Audio Testing: callback function definition        //
//-----------------------------------------------------//
typedef void (__stdcall *META_AUDIO_QUERY_ID_CNF)(const Audio_Query_ID_Cnf *cnf, const short token, void *usrData);
typedef void (__stdcall *META_AUDIO_PLAY_CNF)(const AUDIO_RESULT status, const short token, void *usrData);
typedef void (__stdcall *META_AUDIO_PLAY_BYNAME_CNF)(const AUDIO_RESULT status, const short token, void *usrData);
typedef void (__stdcall *META_AUDIO_PLAY_IMY_BYBUF_CNF)(const AUDIO_RESULT status, const short token, void *usrData);
typedef void (__stdcall *META_AUDIO_PLAY_OVER_IND)(const AUDIO_RESULT status, const short token, void *usrData);
typedef void (__stdcall *META_AUDIO_STOP_CNF)(const AUDIO_RESULT status, const short token, void *usrData);
typedef void (__stdcall *META_AUDIO_MEDIA_PLAY_CNF)(const AUDIO_RESULT status, const short token, void *usrData);
typedef void (__stdcall *META_AUDIO_MEDIA_PLAY_OVER_IND)(const AUDIO_RESULT status, const short token, void *usrData);
typedef void (__stdcall *META_AUDIO_MEDIA_STOP_CNF)(const AUDIO_RESULT status, const short token, void *usrData);
typedef void (__stdcall *META_AUDIO_SET_VOLUME_CNF)(const AUDIO_RESULT status, const short token, void *usrData);

//-----------------------------------------------------//
//  Audio Testing: exported function definition        //
//-----------------------------------------------------//

META_RESULT  __stdcall SP_META_Audio_Query_ID(const META_AUDIO_QUERY_ID_CNF  cnf_cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Audio_Query_ID_r(const int meta_handle, const META_AUDIO_QUERY_ID_CNF  cnf_cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Audio_Play(const Audio_Play_Req  *req, const META_AUDIO_PLAY_CNF cnf_cb, const META_AUDIO_PLAY_OVER_IND  ind_cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Audio_Play_r(const int meta_handle, const Audio_Play_Req  *req, const META_AUDIO_PLAY_CNF cnf_cb, const META_AUDIO_PLAY_OVER_IND  ind_cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Audio_Play_ByName(const Audio_Play_ByName_Req  *req, const META_AUDIO_PLAY_BYNAME_CNF  cnf_cb, const META_AUDIO_PLAY_OVER_IND  ind_cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Audio_Play_ByName_r(const int meta_handle, const Audio_Play_ByName_Req  *req, const META_AUDIO_PLAY_BYNAME_CNF  cnf_cb, const META_AUDIO_PLAY_OVER_IND  ind_cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Audio_Play_IMY_ByBuf(const Audio_Play_IMY_ByBuf_Req  *req, const META_AUDIO_PLAY_IMY_BYBUF_CNF  cnf_cb, const META_AUDIO_PLAY_OVER_IND  ind_cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Audio_Play_IMY_ByBuf_r(const int meta_handle, const Audio_Play_IMY_ByBuf_Req  *req, const META_AUDIO_PLAY_IMY_BYBUF_CNF  cnf_cb, const META_AUDIO_PLAY_OVER_IND  ind_cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Audio_Stop(const META_AUDIO_STOP_CNF  cnf_cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Audio_Stop_r(const int meta_handle, const META_AUDIO_STOP_CNF  cnf_cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Audio_MEDIA_Play(const Audio_MEDIA_Play_Req  *req, const META_AUDIO_MEDIA_PLAY_CNF  cnf_cb, const META_AUDIO_MEDIA_PLAY_OVER_IND  ind_cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Audio_MEDIA_Play_r(const int meta_handle, const Audio_MEDIA_Play_Req  *req, const META_AUDIO_MEDIA_PLAY_CNF  cnf_cb, const META_AUDIO_MEDIA_PLAY_OVER_IND  ind_cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Audio_MEDIA_Stop(const META_AUDIO_MEDIA_STOP_CNF  cnf_cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Audio_MEDIA_Stop_r(const int meta_handle, const META_AUDIO_MEDIA_STOP_CNF  cnf_cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Audio_Set_Volume(const Audio_Set_Volume_Req  *req, const META_AUDIO_SET_VOLUME_CNF  cnf_cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Audio_Set_Volume_r(const int meta_handle, const Audio_Set_Volume_Req  *req, const META_AUDIO_SET_VOLUME_CNF  cnf_cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Audio_Set_Echo_Loop(unsigned int  ms_timeout,const Audio_Set_Echo_Req  *req);
META_RESULT  __stdcall SP_META_Audio_Set_Echo_Loop_r(const int meta_handle,unsigned int  ms_timeout ,const Audio_Set_Echo_Req  *req);
META_RESULT  __stdcall SP_META_Audio_Set_Mode(unsigned int  ms_timeout,const Audio_Set_Mode_Req  *req);
META_RESULT  __stdcall SP_META_Audio_Set_Mode_r(const int meta_handle,unsigned int  ms_timeout ,const Audio_Set_Mode_Req  *req);
META_RESULT  __stdcall SP_META_Audio_Set_Gain(unsigned int  ms_timeout,const Audio_Set_Gain_Req  *req);
META_RESULT  __stdcall SP_META_Audio_Set_Gain_r(const int meta_handle,unsigned int  ms_timeout ,const Audio_Set_Gain_Req  *req);
META_RESULT  __stdcall SP_META_Audio_Tone_Loop_Back_Rec(unsigned int  ms_timeout, Audio_Tone_LoopBackRec_Req  *req, Audio_Tone_LoopBackRec_Cnf *cnf);
META_RESULT  __stdcall SP_META_Audio_Tone_Loop_Back_Rec_r(const int meta_handle,unsigned int  ms_timeout , Audio_Tone_LoopBackRec_Req  *req, Audio_Tone_LoopBackRec_Cnf *cnf);
//  for loud-speaker mode
META_RESULT  __stdcall SP_META_Audio_Tone_Loop_Back_Rec_2K(unsigned int  ms_timeout, Audio_Tone_LoopBackRec_Req  *req, Audio_Tone_LoopBackRec_Cnf_2K *cnf);
META_RESULT  __stdcall SP_META_Audio_Tone_Loop_Back_Rec_2K_r(const int meta_handle,unsigned int  ms_timeout , Audio_Tone_LoopBackRec_Req  *req, Audio_Tone_LoopBackRec_Cnf_2K *cnf);
// for normal mode
META_RESULT  __stdcall SP_META_Audio_Tone_Loop_Back_Rec_2K_Normal(unsigned int  ms_timeout, Audio_Tone_LoopBackRec_Req  *req, Audio_Tone_LoopBackRec_Cnf_2K *cnf);
META_RESULT  __stdcall SP_META_Audio_Tone_Loop_Back_Rec_2K_Normal_r(const int meta_handle,unsigned int  ms_timeout , Audio_Tone_LoopBackRec_Req  *req, Audio_Tone_LoopBackRec_Cnf_2K *cnf);
META_RESULT  __stdcall SP_META_Audio_Set_LoudSpk_FIR_Coeffs(unsigned int  ms_timeout,const Audio_Set_LoudSpk_FIR_Coeffs_Req  *req);
META_RESULT  __stdcall SP_META_Audio_Set_LoudSpk_FIR_Coeffs_r(const int meta_handle, unsigned int  ms_timeout,const Audio_Set_LoudSpk_FIR_Coeffs_Req  *req);
META_RESULT  __stdcall SP_META_Audio_Set_Speech_Common(unsigned int  ms_timeout,const Audio_Set_Speech_Common_Req  *req);
META_RESULT  __stdcall SP_META_Audio_Set_Speech_Common_r(const int meta_handle, unsigned int  ms_timeout,const Audio_Set_Speech_Common_Req  *req);
META_RESULT  __stdcall SP_META_Audio_Set_LoudSpk_Mode(unsigned int  ms_timeout,const Audio_Set_LoudSpk_Mode_Req  *req);
META_RESULT  __stdcall SP_META_Audio_Set_LoudSpk_Mode_r(const int meta_handle, unsigned int  ms_timeout,const Audio_Set_LoudSpk_Mode_Req  *req);
META_RESULT  __stdcall SP_META_Audio_Set_Playback_Maximum_Swing(unsigned int  ms_timeout,const Audio_Set_Playback_Maximum_Swing_Req  *req);
META_RESULT  __stdcall SP_META_Audio_Set_Playback_Maximum_Swing_r(const int meta_handle, unsigned int  ms_timeout,const Audio_Set_Playback_Maximum_Swing_Req  *req);
META_RESULT  __stdcall SP_META_Audio_Set_Melody_FIR_Output_Coeffs(unsigned int  ms_timeout,const Audio_Set_Melody_FIR_Output_Coeffs_Req  *req);
META_RESULT  __stdcall SP_META_Audio_Set_Melody_FIR_Output_Coeffs_r(const int meta_handle, unsigned int  ms_timeout,const Audio_Set_Melody_FIR_Output_Coeffs_Req  *req);
META_RESULT  __stdcall SP_META_Audio_Set_Speech_Common_And_Mode(unsigned int  ms_timeout,const Audio_Set_Speech_Common_And_Mode_Req  *req);
META_RESULT  __stdcall SP_META_Audio_Set_Speech_Common_And_Mode_r(const int meta_handle, unsigned int  ms_timeout,const Audio_Set_Speech_Common_And_Mode_Req  *req);
META_RESULT  __stdcall SP_META_Audio_Play_Freq_Vol_Tone(unsigned int  ms_timeout,const Audio_Set_Freq_Vol_Tone_Req_T  *req);
META_RESULT  __stdcall SP_META_Audio_Play_Freq_Vol_Tone_r(const int meta_handle, unsigned int  ms_timeout,const Audio_Set_Freq_Vol_Tone_Req_T  *req);
META_RESULT  __stdcall SP_META_Audio_Stop_Freq_Vol_Tone(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_Audio_Stop_Freq_Vol_Tone_r(const int meta_handle, unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_Audio_Get_Audio_Profile_Settings(unsigned int ms_timeout,Audio_Get_Profile_Settings_By_Mode_Req_T *req, Audio_Get_Profile_Settings_By_Mode_Cnf_T *cnf);
META_RESULT  __stdcall SP_META_Audio_Get_Audio_Profile_Settings_r(const int meta_handle, unsigned int  ms_timeout, Audio_Get_Profile_Settings_By_Mode_Req_T *req, Audio_Get_Profile_Settings_By_Mode_Cnf_T *cnf);
META_RESULT  __stdcall SP_META_Audio_Set_Audio_Profile_Settings(unsigned int ms_timeout,Audio_Set_Profile_Settings_By_Mode_Req_T *req, Audio_Set_Profile_Settings_By_Mode_Cnf_T *cnf);
META_RESULT  __stdcall SP_META_Audio_Set_Audio_Profile_Settings_r(const int meta_handle, unsigned int  ms_timeout, Audio_Set_Profile_Settings_By_Mode_Req_T *req, Audio_Set_Profile_Settings_By_Mode_Cnf_T *cnf);
META_RESULT  __stdcall SP_META_Audio_Get_Audio_Param_Settings_0809(unsigned int ms_timeout,l1audio_param_W0809_T *cnf);
META_RESULT  __stdcall SP_META_Audio_Get_Audio_Param_Settings_0809_r(const int meta_handle, unsigned int  ms_timeout,  l1audio_param_W0809_T *cnf);
META_RESULT  __stdcall SP_META_Audio_Set_Audio_Param_Settings_0809(unsigned int ms_timeout,l1audio_param_W0809_T *req,Audio_Set_Param_Cnf_T *cnf);
META_RESULT  __stdcall SP_META_Audio_Set_Audio_Param_Settings_0809_r(const int meta_handle, unsigned int  ms_timeout,  l1audio_param_W0809_T *req,Audio_Set_Param_Cnf_T *cnf);
META_RESULT  __stdcall SP_META_Audio_Receiver_Test(unsigned int ms_timeout, ft_l4aud_receiver_test *req);
META_RESULT  __stdcall SP_META_Audio_Receiver_Test_r(const int meta_handle, unsigned int ms_timeout, ft_l4aud_receiver_test *req);
META_RESULT  __stdcall SP_META_Audio_LoudSpk_Test(unsigned int ms_timeout, ft_l4aud_loudspk *req);
META_RESULT  __stdcall SP_META_Audio_LoudSpk_Test_r(const int meta_handle, unsigned int ms_timeout, ft_l4aud_loudspk *req);
META_RESULT  __stdcall SP_META_Audio_EX_SetACFIIRToTarget(const unsigned int ms_timeout, l4aud_acf_param *req);
META_RESULT  __stdcall SP_META_Audio_EX_SetACFIIRToTarget_r(const int meta_handle, const unsigned int ms_timeout, l4aud_acf_param *req);
// Wei Fang add about HCF
META_RESULT __stdcall SP_META_Audio_EX_SetHCFIIRToTarget(const unsigned int ms_timeout, l4aud_acf_param *req);
META_RESULT __stdcall SP_META_Audio_EX_SetHCFIIRToTarget_r(const int meta_handle, const unsigned int ms_timeout, l4aud_acf_param *req);

//6516 add
META_RESULT  __stdcall SP_META_Audio_EX_SetACFIIRToTarget_6516(const unsigned int ms_timeout, l4aud_get_acf_param_cnf *req);
META_RESULT  __stdcall SP_META_Audio_EX_SetACFIIRToTarget_6516_r(const int meta_handle, const unsigned int ms_timeout, l4aud_get_acf_param_cnf *req);


//New API
META_RESULT  __stdcall SP_META_Audio_LoadVolume(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_Audio_LoadVolume_r(const int meta_handle, unsigned int ms_timeout);

//--------------------------------------------------------------------------//
//  BaseBand Testing                                                        //
//--------------------------------------------------------------------------//

//-----------------------------------------------------//
//  BaseBand Testing: data structure definition        //
//-----------------------------------------------------//

typedef struct{
	unsigned int		addr;
	unsigned char		bytenum;
}CPU_REG_READ_REQ;

typedef struct{
	unsigned int		value;
	unsigned char		status;
}CPU_REG_READ_CNF;

typedef struct{
	unsigned int		addr;
	unsigned int		value;
	unsigned char		bytenum;
}CPU_REG_WRITE_REQ;

typedef struct{
	unsigned char		status;
}CPU_REG_WRITE_CNF;


typedef struct{
	unsigned char 	registernumber;	/// the valid value: 0--96
}WM_CMD_ReadPMICRegister_REQ_T;

typedef struct{
	unsigned char 		value;
	int		status;
}WM_CMD_ReadRegister_CNF_T;

typedef struct{
	unsigned char registernumber;   //the valid value: 20~~ 96
	unsigned char registervalue;
}WM_CMD_WritePMICRegister_REQ_T;

typedef struct{
	int value;   //not used
	int		status;
}WM_CMD_WriteRegister_CNF_T;


//add by dian.wang for MT6573 PMIC
typedef struct{
	unsigned long 	registernumber;	/// the valid value: 0--96
}WM_CMD_ReadPMICRegister_DWORD_REQ_T;

typedef struct{
	unsigned int  value;
	unsigned char status;
}WM_CMD_ReadRegister_DWORD_CNF_T;

typedef struct{
	unsigned long registernumber;   //the valid value: 20~~ 96
	unsigned short registervalue;
}WM_CMD_WritePMICRegister_DWORD_REQ_T;

typedef struct{
	unsigned int    value;   //not used
	unsigned char	status;
}WM_CMD_WriteRegister_DWORD_CNF_T;

////////////////////////////////////////


typedef struct {
    int num;
    int delay;
    int tolerance;
} GS_CMD_CALI;

typedef struct {
    int x;
    int y;
    int z; 
} GS_ACK_CALI;

typedef struct {
    int dummy;
} GS_CMD_READ_RAW;

typedef struct {
    int x;
    int y;
    int z;
} GS_ACK_READ_RAW;

typedef struct {
    int x;
    int y;
    int z;    
} GS_CMD_WRITE_NVRAM;

typedef struct {
    int   dummy;
} GS_ACK_WRITE_NVRAM;

typedef struct {
    int   dummy;
} GS_CMD_READ_NVRAM;

typedef struct {
    int x;
    int y;
    int z;    
} GS_ACK_READ_NVRAM;



META_RESULT  __stdcall SP_META_GS_Perform_Calibration(unsigned int ms_timeout, const  GS_CMD_CALI *req, GS_ACK_CALI *cnf);
META_RESULT  __stdcall SP_META_GS_Perform_Calibration_r(const int meta_handle, unsigned int ms_timeout, const  GS_CMD_CALI *req, GS_ACK_CALI *cnf);

META_RESULT  __stdcall SP_META_GS_Write_NVRAM(unsigned int ms_timeout, const  GS_CMD_WRITE_NVRAM *req, GS_ACK_WRITE_NVRAM *cnf);
META_RESULT  __stdcall SP_META_GS_Write_NVRAM_r(const int meta_handle, unsigned int ms_timeout, const  GS_CMD_WRITE_NVRAM *req, GS_ACK_WRITE_NVRAM *cnf);

META_RESULT  __stdcall SP_META_GS_Read_Raw(unsigned int ms_timeout, const  GS_CMD_READ_RAW *req, GS_ACK_READ_RAW *cnf);
META_RESULT  __stdcall SP_META_GS_Read_Raw_r(const int meta_handle, unsigned int ms_timeout, const  GS_CMD_READ_RAW *req, GS_ACK_READ_RAW *cnf);

typedef struct {
    int num;
    int delay;
    int tolerance;
} GYRO_CMD_CALI;

typedef struct {
    int x;
    int y;
    int z; 
} GYRO_ACK_CALI;

typedef struct {
    int dummy;
} GYRO_CMD_READ_RAW;

typedef struct {
    int x;
    int y;
    int z;
} GYRO_ACK_READ_RAW;

typedef struct {
    int x;
    int y;
    int z;    
} GYRO_CMD_WRITE_NVRAM;

typedef struct {
    int   dummy;
} GYRO_ACK_WRITE_NVRAM;

typedef struct {
    int   dummy;
} GYRO_CMD_READ_NVRAM;

typedef struct {
    int x;
    int y;
    int z;    
} GYRO_ACK_READ_NVRAM;


META_RESULT  __stdcall SP_META_GYRO_Perform_Calibration(unsigned int ms_timeout, const  GYRO_CMD_CALI*req, GYRO_ACK_CALI *cnf);
META_RESULT  __stdcall SP_META_GYRO_Perform_Calibration_r(const int meta_handle, unsigned int ms_timeout, const  GYRO_CMD_CALI*req, GYRO_ACK_CALI *cnf);


META_RESULT  __stdcall SP_META_GYRO_Write_NVRAM(unsigned int ms_timeout, const  GYRO_CMD_WRITE_NVRAM*req, GYRO_ACK_WRITE_NVRAM *cnf);
META_RESULT  __stdcall SP_META_GYRO_Write_NVRAM_r(const int meta_handle, unsigned int ms_timeout, const  GYRO_CMD_WRITE_NVRAM*req, GYRO_ACK_WRITE_NVRAM *cnf);


META_RESULT  __stdcall SP_META_GYRO_Read_Raw(unsigned int ms_timeout, const  GYRO_CMD_READ_RAW *req, GYRO_ACK_READ_RAW *cnf);
META_RESULT  __stdcall SP_META_GYRO_Read_Raw_r(const int meta_handle, unsigned int ms_timeout, const  GYRO_CMD_READ_RAW *req, GYRO_ACK_READ_RAW *cnf);

typedef struct
{
	unsigned char	channel;	// ADC channel number.
	unsigned short	Meacount;	// Number of measure times.
} ADCMeaData_Req;

typedef struct
{
	unsigned int	value;		// ADC value, it a sum value of each measurement data.
	int				drv_status;
	unsigned char	status;		// 0: success, others: get ADC measurement fail.
} ADCMeaData_Cnf;

//-----------------------------------------------------//
//  BaseBand Testing: callback function definition     //
//-----------------------------------------------------//
typedef void (__stdcall *META_BB_READREG_CNF)(const CPU_REG_READ_CNF *result, const short token, void *usrData);
typedef void (__stdcall *META_BB_WRITEREG_CNF)(const CPU_REG_WRITE_CNF *result, const short token, void *usrData);
typedef void (__stdcall *META_BB_ADCGETMEADATA_CNF)(const ADCMeaData_Cnf *result, const short token, void *usrData);

//-----------------------------------------------------//
//  BaseBand Testing: exported function definition     //
//-----------------------------------------------------//

META_RESULT  __stdcall SP_META_BB_RegRead(const CPU_REG_READ_REQ *req, const META_BB_READREG_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_BB_RegRead_r(const int meta_handle, const CPU_REG_READ_REQ *req, const META_BB_READREG_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_BB_RegWrite(const CPU_REG_WRITE_REQ *req, const META_BB_WRITEREG_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_BB_RegWrite_r(const int meta_handle, const CPU_REG_WRITE_REQ *req, const META_BB_WRITEREG_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_BB_ADCGetMeaSumData(const ADCMeaData_Req *req, const META_BB_ADCGETMEADATA_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_BB_ADCGetMeaSumData_r(const int meta_handle, const ADCMeaData_Req *req, const META_BB_ADCGETMEADATA_CNF cb, short *token, void *usrData);

//--------------------------------------------------------------------------//
//  FAT Access                                                              //
//--------------------------------------------------------------------------//

//-----------------------------------------------------//
//  FAT Access: data structure definition              //
//-----------------------------------------------------//
typedef enum {
	FAT_OPEN_READ = 0,
	FAT_OPEN_WRITE
}FAT_OPEN_MODE;

typedef enum {
	FAT_FIND_FILE = 0,
	FAT_FIND_FILE_RECURSIVE,
	FAT_FIND_DIR_RECURSIVE
}FAT_FIND_MODE;

typedef enum {
	FAT12 = 0,
	FAT16,
	FAT32
}FAT_TYPE;

typedef struct {
	FAT_TYPE		Type;
	unsigned int 	SectorsPerCluster;
	unsigned int	TotalSize;
	unsigned int	FreeSpace;
}FAT_DiskInfo_T;

typedef struct 
{
	char m_cDriveLetter;   // Target FAT disk drive letter such as: 'C'
	char *m_pcfilepath;    // File path of the file we intend to write into target FAT

}FAT_FILE_INFO_REQ_T;

//-----------------------------------------------------//
//  FAT Access: callback function definition           //
//-----------------------------------------------------//
typedef int (__stdcall *CALLBACK_META_FAT_PROGRESS)(unsigned char percent, int sent_bytes, int total_bytes, const short token, void *usr_arg);

//-----------------------------------------------------//
//  FAT Access: exported function definition           //
//-----------------------------------------------------//


/*  NOR_DRIVE = 1,
	NAND_DRIVE=2,
	CARD_DRIVE = 3,
	EXTERNAL_DRIVE = 4
*/
META_RESULT  __stdcall SP_META_FAT_GetDriveType(unsigned int ms_timeout, const char DriveLetter, int *p_DriveType);
META_RESULT  __stdcall SP_META_FAT_GetDriveType_r(const int meta_handle, unsigned int ms_timeout, const char DriveLetter, int *p_DriveType);
//--------------------------------------------------------------------------//
//  WiFi Calibration                                                        //
//--------------------------------------------------------------------------//

//-----------------------------------------------------//
//  WiFi Calibration: data structure definition        //
//-----------------------------------------------------//

// WiFi Baseband Chip ID 
#define WIFI_BB_MT5911		0x00000001

// WiFi RF Chip ID 
#define WIFI_RF_AL2236		0x00000001
#define WIFI_RF_MAX2827		0x00000002

typedef enum {
	WIFI_TEST_RATE_1M = 0,     /* 1M          */
	WIFI_TEST_RATE_2M,         /* 2M          */
	WIFI_TEST_RATE_5_5M,       /* 5.5M        */
	WIFI_TEST_RATE_11M,        /* 11M         */
	WIFI_TEST_RATE_6M,         /* 6M          */
	WIFI_TEST_RATE_9M,         /* 9M          */
	WIFI_TEST_RATE_12M,        /* 12M         */
	WIFI_TEST_RATE_18M,        /* 18M         */
	WIFI_TEST_RATE_24M,        /* 24M         */
	WIFI_TEST_RATE_36M,        /* 36M         */
	WIFI_TEST_RATE_48M,        /* 48M         */
	WIFI_TEST_RATE_54M,        /* 54M         */
	WIFI_TEST_RATE_COUNT       /* Total count */
} WiFi_TestRate_E;

typedef enum {
	 WNDRV_HOST_INTERFACE_SDIO = 0
	,WNDRV_HOST_INTERFACE_HPI
	,WNDRV_HOST_INTERFACE_SPI
	,WNDRV_HOST_INTERFACE_CF_MEM
	,WNDRV_HOST_INTERFACE_CF_IO  
} WiFi_HostInterface_E;

typedef enum {
	WIFI_TX_ALL_ZEROS,
	WIFI_TX_ALL_ONES,
	WIFI_TX_ALTERNATE_BITS,
	WIFI_TX_PSEUDO_RANDOM
} WiFi_TestPktTxPattern_E;

typedef enum {
	WIFI_POWER_MODE_NORMAL,
	WIFI_POWER_MODE_IDLE,
	WIFI_POWER_MODE_SLEEP
} WiFi_PowerManagementMode_E;

typedef enum {    
	WIFI_RF_RX_TEST_MODE = 1  /* For RF Test use */
} WiFi_TestPktRxMode_E;

typedef enum {
	WIFI_RX_ANT_DIVERSITY_AGC,  /* AGC based selection */
	WIFI_RX_ANT_DIVERSITY_MPDU, /* MPDU based selection */
	WIFI_RX_ANT_FIXED_0,        /* Always 0 */ 
	WIFI_RX_ANT_FIXED_1         /* Always 1 */
} WiFi_RxAntSel_E;

typedef struct {
	unsigned int	bb_chip_id;
	char			bb_chip_ver[32];
	unsigned int	rf_chip_id;
	char			rf_chip_ver[32];
	unsigned char	support_802_11b;
	unsigned char	support_802_11a;
	unsigned char	support_802_11g;
	bool			eeprom_exist;
	unsigned int	eeprom_size;
	WiFi_HostInterface_E	host_interface;
} WiFi_ChipCapability_S;

typedef struct {
	unsigned int		ch_freq; /* Frq, units are kHz */
	WiFi_TestRate_E		tx_rate;
	int					dbm;
} WiFi_DBM2DAC_Set_S;

typedef struct {
	unsigned short		tx_gain_dac;
} WiFi_DBM2DAC_Query_S;

typedef struct {
	unsigned int		ch_freq;/* Frq, units are kHz */
	WiFi_TestRate_E		tx_rate;
	unsigned char		txAnt; /* 0 for Antenna 0; 1 for Antenna 1 */
	unsigned short		tx_gain_dac;
} WiFi_TestTx_S;

typedef struct {
	unsigned int			ch_freq;			/* Frq, units are kHz */
	WiFi_TestRate_E			tx_rate;
	unsigned short			tx_gain_dac;
	unsigned int			pktCount;
	unsigned int			pktInterval;		/* interval between each Tx Packet */
	unsigned int			pktLength;			/* 24~1500 */
	WiFi_TestPktTxPattern_E	pattern;			/* content of the Tx Packet */
	unsigned char			txAnt;				/* 0 for Antenna 0; 1 for Antenna 1 */
	unsigned char			is_short_preamble;	/* 0 for long preamble and 1 for short preamble */
	unsigned char			mac_header[ 24 ];	/* Frame Ctrl, Duration = 2bytes + 2bytes */
												/* Address 1 = 6 bytes */ 
												/* Address 2 = 6 bytes */ 
												/* Address 3 = 6 bytes */ 
												/* Sequence Ctrl = 2 bytes */
} WiFi_TestPktTx_S;

typedef struct {
	unsigned int			ch_freq;			/* Frq, units are kHz */
	WiFi_TestRate_E			tx_rate;
	unsigned short			tx_gain_dac;
	unsigned int			pktCount;
	unsigned int			pktInterval;		/* interval between each Tx Packet */
	unsigned int			pktLength;			/* 24~1500 */
	WiFi_TestPktTxPattern_E	pattern;			/* content of the Tx Packet */
	unsigned char			txAnt;				/* 0 for Antenna 0; 1 for Antenna 1 */
	unsigned int			txFlags;
	unsigned int			targetAlc;
	unsigned char			is_short_preamble;	/* 0 for long preamble and 1 for short preamble */
	unsigned char			mac_header[ 24 ];	/* Frame Ctrl, Duration = 2bytes + 2bytes */
												/* Address 1 = 6 bytes */ 
												/* Address 2 = 6 bytes */ 
												/* Address 3 = 6 bytes */ 
												/* Sequence Ctrl = 2 bytes */
} WiFi_TestPktTx_Ex_S;

typedef struct {    
	unsigned int		pkt_sent_count;  /* total num sent */
	unsigned int		pkt_sent_acked;  /* acked num */    
} WiFi_TxStatus_S;


typedef struct {    
	unsigned int		pkt_sent_count;  /* total num sent */
	unsigned int		pkt_sent_acked;  /* acked num */    
	unsigned short		avgAlc;
	unsigned char		cckGainControl;
    unsigned char		ofdmGainControl;
} WiFi_TxStatus_Ex_S;

typedef struct {
	unsigned int				ch_freq;  /* Frq, units are kHz */
	WiFi_TestPktRxMode_E		mode;
	WiFi_RxAntSel_E				rxAnt;
} WiFi_TestPktRx_S;

typedef struct {    
	unsigned int		int_rx_ok_num;     /* number of packets that Rx ok from interrupt */
	unsigned int		int_crc_err_num;   /* number of packets that CRC error from interrupt */
	unsigned int		pau_rx_pkt_count;  /* number of packets that Rx ok from PAU */
	unsigned int		pau_crc_err_count; /* number of packets that CRC error from PAU */
	unsigned int		pau_cca_count;     /* CCA rising edge count */
	unsigned int		pau_rx_fifo_full_count; /* number of lost packets due to FiFo full */
	unsigned int		int_long_preamble_num;
	unsigned int		int_short_preamble_num;
	unsigned int		int_rate_ok_num[ WIFI_TEST_RATE_COUNT ];
	unsigned int		int_rate_crc_err_num[ WIFI_TEST_RATE_COUNT ];
	int					int_rssi_max;
	int					int_rssi_min;
	int					int_rssi_mean;
	int					int_rssi_variance;
} WiFi_RxStatus_S;

typedef struct {    
	int  ED;
	int  OSD;
	int  SQ1;
	int  SFD;
	int  CRC16;
} WiFi_RxCounter_S;

typedef struct {    
	unsigned int	channel_num;
	unsigned char	channel_list[64];
} WiFi_ChannelList_S;

typedef struct {    
	unsigned char	country_code[2];
} WiFi_RegDomain_S;

typedef struct {
	unsigned int	index;		// 32bits alignment index, +4 
	unsigned int	mcr_data32;
} WiFi_MACReg32_S;

typedef struct {
	unsigned int	index;		// 16bits alignment index, +2 
	unsigned short	mcr_data16;
} WiFi_MACReg16_S;

typedef struct {
	unsigned int	index;		// 8bits alignment index, +1 
	unsigned char	bbcr_data8;
} WiFi_BBReg8_S;

typedef struct {
	unsigned int	index;		// 16bits alignment index, +2 
	unsigned short	eeprom_data16;
} WiFi_EEPROM_S;


// Wei Fang 2011-12-8
META_RESULT __stdcall SP_META_WiFi_switchAntenna_r(const int meta_handle, unsigned int ms_timeout,unsigned int value);
META_RESULT __stdcall SP_META_WiFi_switchAntenna(unsigned int ms_timeout,unsigned int value);


//--------------------------------------------------------------------------//
//  BT Calibration                                                          //
//--------------------------------------------------------------------------//

//-----------------------------------------------------//
//  BT Calibration: data structure definition          //
//-----------------------------------------------------//

// BT Module ID 
#define BT_NOT_SUPPORT		0x00000000
#define BTMODULE_MT6601		0x00000011
#define BTMODULE_MT6611	    0x00000012
#define BTMODULE_RFMD3500   0x00000021 
#define BTMODULE_RFMD4020	0x00000022

//#define BT_PACKET_LEN       339
#define BT_PACKET_LEN       1021  // because BT2.0 support at most 1021 bytes per packet
#define BT_BUFFER_LEN       1024
#define BT_DATA_LEN           1026
typedef struct {
	unsigned char	id;
} BT_ModuleID_S;

typedef struct {
	unsigned char   m_event;
	char         	m_status;
	unsigned short  m_handle;
	unsigned char	m_len;
	unsigned char	m_parms[256];
} BT_HCI_EVENT;

typedef struct {
	unsigned short	m_opcode;
	unsigned char	m_len;
	unsigned char	m_cmd[256];
} BT_HCI_COMMAND;
typedef struct {
    unsigned short           m_con_hdl;
    unsigned short           m_len;      	
    unsigned char            m_buffer[BT_BUFFER_LEN]; 
} BT_HCI_BUFFER;
typedef struct {
    unsigned short           m_len;
    unsigned char            m_data[BT_DATA_LEN];
} BT_HCI_PACKET;
typedef struct {
    unsigned short           m_con_hdl;
    unsigned short           m_len;      	
    unsigned short           m_total_pks; 
} BT_HCI_TX_PURE_TEST;

typedef struct {
    unsigned int             m_used_time;
    unsigned short           m_len;     
} BT_HCI_TX_PURE_TEST_STAT;

typedef struct {
    unsigned int             m_used_time;
    unsigned short           m_len;     
} BT_HCI_RX_PURE_TEST_STAT;

typedef struct {
    unsigned int             m_u4UsedTime;
    unsigned short           m_u2PktSentNum; 
    
} BT_HCI_TX_PURE_TEST_STAT_V2;


//-----------------------------------------------------//
//  BT Calibration Functions                           //
//-----------------------------------------------------//
META_RESULT  __stdcall SP_META_BT_QueryModuleID(unsigned int  ms_timeout, BT_ModuleID_S  *cnf);
META_RESULT  __stdcall SP_META_BT_QueryModuleID_r(const int meta_handle, unsigned int  ms_timeout, BT_ModuleID_S  *cnf);

typedef void (__stdcall *META_BT_HCI_CNF)(const BT_HCI_EVENT *cnf, const short token, void *usrData);
typedef void (__stdcall *META_BT_HCI_TXDATA_CNF)(const BT_HCI_PACKET *cnf, const short token, void *usrData);
typedef void (__stdcall *META_BT_AUTO_HCI_CNF)(const BT_HCI_EVENT *cnf, const short token, void *usrData);
typedef void (__stdcall *META_BT_HCI_RXDATA_CNF)(const BT_HCI_BUFFER *cnf, const short token, void *usrData);

typedef void (__stdcall *META_BT_HCI_TXTEST_CNF)(const BT_HCI_TX_PURE_TEST_STAT *cnf, const short token, void *usrData);
typedef void (__stdcall *META_BT_HCI_RXTEST_CNF)(const BT_HCI_RX_PURE_TEST_STAT *cnf, const short token, void *usrData);

typedef void (__stdcall *META_BT_HCI_TXTEST_V2_CNF)(const BT_HCI_TX_PURE_TEST_STAT_V2 *cnf, const short token, void *usrData);

typedef struct{
	META_BT_HCI_TXDATA_CNF      m_SendDataCallback;
	META_BT_HCI_RXDATA_CNF		m_RecvDataCallback;
	META_BT_AUTO_HCI_CNF		m_AutoCallback;
	META_BT_HCI_TXTEST_CNF		m_TxTestCallback;
	META_BT_HCI_RXTEST_CNF		m_RxTestCallback;
	META_BT_HCI_TXTEST_V2_CNF   m_TxTestCallback_V2;
} BT_OtherCallBack;

META_RESULT  __stdcall SP_META_BT_SendHCICommand(unsigned int  ms_timeout,BT_HCI_COMMAND *req, META_BT_HCI_CNF  cb, void  *cb_arg, unsigned char Cmpltcode);
META_RESULT  __stdcall SP_META_BT_SendHCICommand_r(const int meta_handle, unsigned int  ms_timeout,BT_HCI_COMMAND *req, META_BT_HCI_CNF  cb, void  *cb_arg, unsigned char Cmpltcode);
META_RESULT  __stdcall SP_META_BT_CancelHCICommand(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_BT_CancelHCICommand_r(const int meta_handle, unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_BT_SendHCIData(unsigned int  ms_timeout,BT_HCI_BUFFER *snd, META_BT_HCI_TXDATA_CNF  cb_tx, void  *cb_arg);
META_RESULT  __stdcall SP_META_BT_SendHCIData_r(const int meta_handle, unsigned int  ms_timeout,BT_HCI_BUFFER *snd, META_BT_HCI_TXDATA_CNF  cb_tx, void  *cb_arg);
META_RESULT  __stdcall SP_META_BT_RegisterAutoCallback(META_BT_AUTO_HCI_CNF cb_auto);
META_RESULT  __stdcall SP_META_BT_RegisterAutoCallback_r(const int meta_handle,META_BT_AUTO_HCI_CNF cb_auto);
META_RESULT  __stdcall SP_META_BT_ReceiveHCIData(META_BT_HCI_RXDATA_CNF cb_rx);
META_RESULT  __stdcall SP_META_BT_ReceiveHCIData_r(const int meta_handle,META_BT_HCI_RXDATA_CNF cb_rx);
META_RESULT  __stdcall SP_META_BT_RemoveAutoCallback();
META_RESULT  __stdcall SP_META_BT_RemoveAutoCallback_r(const int meta_handle);
META_RESULT  __stdcall SP_META_BT_RemoveReceiveHCIDataCallback();
META_RESULT  __stdcall SP_META_BT_RemoveReceiveHCIDataCallback_r(const int meta_handle);

META_RESULT  __stdcall SP_META_BT_GetChipID(unsigned int  ms_timeout, unsigned int * pID);
META_RESULT  __stdcall SP_META_BT_GetChipID_r(const int meta_handle, unsigned int  ms_timeout, unsigned int * pID);




//----------------------------------------------------------------//
//                              MATV                              //
//----------------------------------------------------------------//

typedef struct
{
	unsigned int	freq;
	unsigned char	sndsys;
	unsigned char	colsys;
	unsigned char	flag;
}matv_ch_entry;

typedef struct
{
    unsigned char   m_ucChannel;
    matv_ch_entry   m_rmatv_ch_entry;
}FT_MATV_SET_CHANNEL_PROPERTY_REQ_T;

typedef struct
{
    unsigned char   m_ucProgress;
    unsigned char   m_ucChannels;
    matv_ch_entry   m_rmatv_ch_entry[70];
}FT_MATV_GET_CHANNEL_LIST_CNF_T;

typedef struct
{
    int             m_i4QualityIndex[128];
}FT_MATV_GET_CHANNEL_QUALITY_ALL_CNF_T;

typedef struct
{
    char chipname[20];
}MATV_CHIPNAME_S;


META_RESULT  __stdcall SP_META_MATV_PowerOn(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_MATV_PowerOn_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_MATV_PowerOff(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_MATV_PowerOff_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_MATV_SetRegion(unsigned int ms_timeout, unsigned char region);
META_RESULT  __stdcall SP_META_MATV_SetRegion_r(const int meta_handle, unsigned int ms_timeout, unsigned char region);
META_RESULT  __stdcall SP_META_MATV_StartScan(unsigned int ms_timeout, unsigned int scanmode);
META_RESULT  __stdcall SP_META_MATV_StartScan_r(const int meta_handle, unsigned int ms_timeout, unsigned char scanmode);
META_RESULT  __stdcall SP_META_MATV_StartFullScan(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_MATV_StartFullScan_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_MATV_StopScan(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_MATV_StopScan_r(const int meta_handle, unsigned int ms_timeout);


META_RESULT  __stdcall SP_META_MATV_GetChannelList(unsigned int ms_timeout, FT_MATV_GET_CHANNEL_LIST_CNF_T* cnf);
META_RESULT  __stdcall SP_META_MATV_GetChannelList_r(const int meta_handle, unsigned int ms_timeout, FT_MATV_GET_CHANNEL_LIST_CNF_T* cnf);
META_RESULT  __stdcall SP_META_MATV_ChangeChannel(unsigned int ms_timeout, unsigned char channel);
META_RESULT  __stdcall SP_META_MATV_ChangeChannel_r(const int meta_handle, unsigned int ms_timeout, unsigned char channel);
META_RESULT  __stdcall SP_META_MATV_SetChannelProperty(unsigned int ms_timeout, FT_MATV_SET_CHANNEL_PROPERTY_REQ_T* req);
META_RESULT  __stdcall SP_META_MATV_SetChannelProperty_r(const int meta_handle, unsigned int ms_timeout, FT_MATV_SET_CHANNEL_PROPERTY_REQ_T* req);
META_RESULT  __stdcall SP_META_MATV_GetChannelQuality(unsigned int ms_timeout, unsigned short item, int *qualityindex);
META_RESULT  __stdcall SP_META_MATV_GetChannelQuality_r(const int meta_handle, unsigned int ms_timeout, unsigned short index, int *qualityindex);
META_RESULT  __stdcall SP_META_MATV_GetChannelQualityAll(unsigned int ms_timeout, FT_MATV_GET_CHANNEL_QUALITY_ALL_CNF_T* channel_quality);
META_RESULT  __stdcall SP_META_MATV_GetChannelQualityAll_r(const int meta_handle, unsigned int ms_timeout, FT_MATV_GET_CHANNEL_QUALITY_ALL_CNF_T* channel_quality);
META_RESULT  __stdcall SP_META_MATV_GetChipName(unsigned int ms_timeout, MATV_CHIPNAME_S * pChipName);
META_RESULT  __stdcall SP_META_MATV_GetChipName_r(const int meta_handle, unsigned int ms_timeout, MATV_CHIPNAME_S * pChipName);


//----------------------------------------------------------------//
//                              FM                                //
//----------------------------------------------------------------//

//--------------------------//
//    FM data structures    //
//--------------------------//
/*
typedef enum
{
    FM_CHIP_ID_MT6189AN = 0,
    FM_CHIP_ID_MT6189BN_CN = 1,
    FM_CHIP_ID_MT6188A = 3,
    FM_CHIP_ID_MT6188C = 4,
    FM_CHIP_ID_MT6188D = 5,
    FM_CHIP_ID_MT6616 = 6,
	FM_CHIP_ID_AR1000 = 7,
	FM_CHIP_ID_MT6620 = 8

}FM_CHIP_ID_E;
*/
typedef enum
{
  FM_CHIP_ID_MT6189AN = 0,
  FM_CHIP_ID_MT6189BN_CN = 1,
  FM_CHIP_ID_MT6188A = 3,
  FM_CHIP_ID_MT6188C = 4,
  FM_CHIP_ID_MT6188D = 5,
  FM_CHIP_ID_MT6616 = 6,
  FM_CHIP_ID_AR1000 = 7,
  FM_CHIP_ID_MT6620 = 8,
  FM_CHIP_ID_MT6626 = 9,
  FM_CHIP_ID_MT6628 = 10,
  FM_CHIP_ID_MT6627 = 11,
  FM_CHIP_ID_MT6630 = 12,
  FM_CHIP_ID_MT6580 = 13
}FM_CHIP_ID_E;

typedef struct{
    unsigned char pty;         // 0~31 integer
    unsigned char rds_rbds;    // 0:RDS, 1:RBDS
    unsigned char dyn_pty;     // 0:static, 1:dynamic
    unsigned short pi_code;    // 2-byte hex
    unsigned char ps_buf[8];     // hex buf of PS
    unsigned char ps_len;      // length of PS, must be 0 / 8"
    unsigned char af;          // 0~204, 0:not used, 1~204:(87.5+0.1*af)MHz
    unsigned char ah;          // Artificial head, 0:no, 1:yes
    unsigned char stereo;      // 0:mono, 1:stereo
    unsigned char compress;    // Audio compress, 0:no, 1:yes
    unsigned char tp;          // traffic program, 0:no, 1:yes
    unsigned char ta;          // traffic announcement, 0:no, 1:yes
    unsigned char speech;      // 0:music, 1:speech
}FM_RDS_TX_REQ_T;

typedef struct
{
    unsigned char  m_ucChipId;
}FM_CHIP_ID_CNF_T;

typedef struct
{
	short m_i2CurFreq;  // freq range is [875, 1080]
}FM_FREQ_REQ_T;



typedef struct
{
    //unsigned char m_ucSignalLevel;
	int m_ucSignalLevel;
}FM_RSSI_CNF_T;

typedef struct
{
	//unsigned char m_ucIfCnt;
	unsigned short m_u2IfCnt;
	
}FM_IF_CNT_CNF_T;

typedef struct
{
	unsigned short m_u2MonoOrStereo;  // 0: mono, 1: stereo
	unsigned short m_u2SblendOnOrOff; // 0: sblend off, 1: sblend on
	unsigned int   m_u4ItemValue;  // 0: disable, 1: enable

}FM_MONO_STEREO_BLEND_REQ_T;

typedef struct  // freq range is [875, 1080]
{
   short m_i2StartFreq;    // note: when we try to search next: start freq should <= stop freq 
   short m_i2StopFreq;     // note: when we try to search prev: start freq should >= stop freq

}FM_FREQ_RANGE_REQ_T;

typedef struct
{
	unsigned char m_ucExit;      // 0: don't exist, 1: exist
	short         m_i2ValidFreq; // -1: settings error, 0: invalid freq, others: 875-1080 valid

}FM_VAILD_FREQ_CNF_T;

typedef struct
{
   unsigned int m_u4RssiThreshold;

}FM_RSSI_THRESHOLD_REQ_T;

typedef struct
{
   unsigned int m_u4IfCntDelta;

}FM_IF_CNT_DELTA_REQ_T;


typedef struct
{
	unsigned char m_ucAddr;
	
}FM_READ_BYTE_ADDR_REQ_T;


typedef struct
{
   unsigned short m_u2ReadByte;

}FM_READ_BYTE_CNF_T;


typedef struct
{
	unsigned char m_ucAddr;
	unsigned short m_u2WriteByte;
}FM_WRITE_BYTE_REQ_T;

typedef struct
{
    unsigned char m_bOnOff;  // 0: off, 1: on

}FM_SOFT_MUTE_ONOFF_REQ_T;

typedef struct
{
	unsigned char m_ucStage;  // 1~3
}FM_STAGE_REQ_T;

typedef struct
{
	unsigned char  m_ucHighOrLow;
}FM_HL_Side_CNF_T;

typedef struct
{
	unsigned char m_ucStereoOrMono;

}FM_Stereo_Mono_CNF_T;

// for MT6616 new API
typedef struct
{
    unsigned char m_ucVolume;
    char m_cDigitalGainIndex;
}FM_Volume_Setting_REQ_T;

typedef struct
{
   // unsigned short m_u2Bitmap[16]; for 100KHz
	unsigned short m_u2Bitmap[26]; //for 50KHz
}FM_AutoScan_CNF_T;

typedef struct
{
    unsigned char m_ucRDSOn;
}FM_SetRDS_REQ_T;

typedef struct
{
    unsigned char m_ucRXFilterBW;
}FM_RX_FilterBW_CNF_T;

typedef struct
{
    unsigned char m_ucPAMDLevel;
}FM_PAMD_Level_CNF_T;

typedef struct
{
    unsigned char m_ucMR;
}FM_MR_CNF_T;

typedef struct
{
    unsigned int m_u4DecodeMode;
}FM_Decode_Mode_REQ_T;

typedef struct
{
    unsigned int m_u4HCC;
}FM_HCC_REQ_T;

typedef struct
{
    unsigned int m_u4PAMDThreshold;
}FM_PAMD_Threshold_REQ_T;

typedef struct
{
    unsigned int m_u4SoftmuteEnable;
}FM_Softmute_Enable_REQ_T;

typedef struct
{
    unsigned int m_u4DeemphasisLevel;
}FM_Deemphasis_Level_REQ_T;

typedef struct
{
	unsigned int m_u4HLSide;
}FM_HL_Side_REQ_T;

typedef struct
{
    unsigned int m_u4DemodBandwidth;
}FM_Demod_Bandwidth_REQ_T;

typedef struct
{
    unsigned int m_u4DynamicLimiter;
}FM_DynamicLimiter_REQ_T;

typedef struct
{
    unsigned int m_u4SoftmuteRate;
}FM_Softmute_Rate_REQ_T;

typedef enum
{
    RDS_CMD_NONE = 0,   // No command. This is usually an error.
    RDS_CMD_PI_CODE,
    RDS_CMD_PTY_CODE,
    RDS_CMD_PROGRAMNAME,
    RDS_CMD_LOCDATETIME,
    RDS_CMD_UTCDATETIME,
    RDS_CMD_LAST_RADIOTEXT,
    RDS_CMD_AF,
    RDS_CMD_AF_LIST,  
    RDS_CMD_AFON,
    RDS_CMD_TAON,
    RDS_CMD_TAON_OFF
}RdsCmd;

typedef enum
{
    RDS_FLAG_IS_TP              	              = 0x0001, // Program is a traffic program
    RDS_FLAG_IS_TA                            = 0x0002, // Program currently broadcasts a traffic ann.
    RDS_FLAG_IS_MUSIC                     = 0x0004, // Program currently broadcasts music
    RDS_FLAG_IS_STEREO                  = 0x0008, // Program is transmitted in stereo
    RDS_FLAG_IS_ARTIFICIAL_HEAD = 0x0010, // Program is an artificial head recording
    RDS_FLAG_IS_COMPRESSED       = 0x0020, // Program content is compressed
    RDS_FLAG_IS_DYNAMIC_PTY       = 0x0040, // Program type can change 
    RDS_FLAG_TEXT_AB                      = 0x0080  // If this flag changes state, a new radio text 					 string begins
}RdsFlag;

typedef enum {
   RDS_EVENT_FLAGS          = 0x0001, // One of the RDS flags has changed state
   RDS_EVENT_PI_CODE        = 0x0002, // The program identification code has changed
   RDS_EVENT_PTY_CODE       = 0x0004, // The program type code has changed
   RDS_EVENT_PROGRAMNAME    = 0x0008, // The program name has changed
   RDS_EVENT_UTCDATETIME    = 0x0010, // A new UTC date/time is available
   RDS_EVENT_LOCDATETIME    = 0x0020, // A new local date/time is available
   RDS_EVENT_LAST_RADIOTEXT = 0x0040, // A radio text string was completed
   RDS_EVENT_AF                   = 0x0080, // Current Channel RF signal strength too weak, need do AF switch  
   RDS_EVENT_AF_LIST        = 0x0100, // An alternative frequency list is ready
   RDS_EVENT_AFON_LIST        = 0x0200, // An alternative frequency list is ready
   RDS_EVENT_TAON        = 0x0400,  // Other Network traffic announcement start
   RDS_EVENT_TAON_OFF        = 0x0800 // Other Network traffic announcement finished.
} RdsEvent;

typedef struct
{
    RdsCmd m_eCmd;
}FM_RDS_Info_REQ_T;

typedef struct
{
    unsigned char m_buffer[64];
}FM_RDS_Info_CNF_T;

typedef struct
{
    RdsFlag m_eFlag;
    unsigned char m_buffer[64];
}FM_RDS_Status_CNF_T;

typedef struct  
{
	char TP;
	char TA;
	char Music;
	char Stereo;
	char Artificial_Head;
	char Compressed;
	char Danamic_PTY;
	char Text_AB;
	int falg_status;
}RDSFlag_Struct;

typedef struct
{
        unsigned short Month;
        unsigned short Day;
        unsigned short Year;
        unsigned short Hour;
        unsigned short Minute;
        unsigned char Local_Time_offset_signebit;
        unsigned char Local_Time_offset_half_hour;
}CT_Struct;

typedef struct
{
    unsigned short m_u2GoodBlock;
}FM_RDS_Good_Block_Counter_CNF_T;

typedef struct
{
    unsigned short m_u2BadBlock;
}FM_RDS_Bad_Block_Counter_CNF_T;

/*
typedef struct
{
    unsigned short m_u2GroupCounter[32];
}FM_RDS_Group_Counter_CNF_T;
*/

typedef struct
{
    short m_i2StartFreq;
    unsigned char m_ucDirection;
}FM_HWSeek_REQ_T;

typedef struct
{
    short m_i2EndFreq;
}FM_HWSeek_CNF_T;


typedef struct
{
    unsigned short m_u2StereoBlendControl;
}FM_SetStereoBlend_REQ_T;

/*
typedef struct
{
    unsigned short m_u2Blocks[5];
}FM_RDS_Block_CNF_T;
*/


typedef struct  
{
	unsigned short DECODE_MODE;
	unsigned short STEREO_BLEND;
	unsigned short HCC;
	unsigned short PAMD_THRESHOLD;
	unsigned short RSSI_THRESHOLD;
	unsigned short SOFTMUTE;
	unsigned short COSTAS;
	unsigned short DE_EMPHASIS_LEV;
	unsigned short HL_SIDE;
	unsigned short DEMOD_BANDWIDTH;
	unsigned short DYNAMIC_LIMITER;
	unsigned short SOFTMUTE_RATE;
	unsigned short AFC;
	unsigned short SET_BW;
	unsigned short CAP_ARRAY;
	unsigned short DEMOD_TYPE;
}FM_SETStatus_REQ_T;

typedef struct  
{
	unsigned short RSSI;               //RSSI
	unsigned short RSSI_HEX;           //RSSI(Hex)
	unsigned short RSSI_DBM;            //
	unsigned short STA_BW;              //BW
	unsigned short PAMD;
	unsigned short PAMD_HEX;
	unsigned short PAMD_DBM;
	unsigned short MR;
	unsigned short STEREO_MONO;			//Stereo/Mono
	unsigned short BLEND_GAIN;			//Blend gain
	unsigned short BLEND_FILTER_NUMBER; //Blend filter number
	unsigned short SOFTMUTE_GMS;
	unsigned short SOFTMUTE_GFS;
	unsigned short DYNAMIC_GAIN;
	unsigned short PILOT_LOCKED_FLAG;
	unsigned short SOFTMUTE_SELECTION_FLAG;
	unsigned short RSSI_HCC;
	unsigned short PAMD_HCC;
	unsigned short RSSI_OFF_B;
	unsigned short RSSI_OFF_H;
	unsigned short PAMD_OFF_B;
	unsigned short PAMD_OFF_H;
	unsigned short HCC_FILTER;
	unsigned short SOFTMUTE_STEP;
	unsigned short GAIN_COUNTER;
	unsigned short PGA_GAIN;
	unsigned short LNA_GAIN;
	unsigned short PGA_GAIN_INDEX;
	unsigned short LNA_GAIN_INDEX;
	unsigned short TOTAL_GAIN;
	unsigned short PULSE_RATIO;
	unsigned short FAST_PAMD;
	unsigned short POWER_DETECTOR;
	unsigned short CHIP_ID;
}FM_Status_CNF_T;

//--------------------------//
//      FM Functions        //
//--------------------------//

META_RESULT  __stdcall SP_META_FM_SetRDSTX(unsigned int ms_timeout,FM_RDS_TX_REQ_T req );
META_RESULT  __stdcall SP_META_FM_SetRDSTX_r(const int meta_handle, unsigned int ms_timeout,FM_RDS_TX_REQ_T req);
META_RESULT  __stdcall SP_META_FM_SetStatus(unsigned int ms_timeout, char * fileName,FM_SETStatus_REQ_T req);
META_RESULT  __stdcall SP_META_FM_SetStatus_r(const int meta_handle, unsigned int ms_timeout, char * fileName,FM_SETStatus_REQ_T req);
META_RESULT  __stdcall SP_META_FM_GetStatus( unsigned int ms_timeout, char * fileName,FM_Status_CNF_T* cnf);
META_RESULT  __stdcall SP_META_FM_GetStatus_r(const int meta_handle, unsigned int ms_timeout, char * fileName,FM_Status_CNF_T* cnf);
META_RESULT  __stdcall SP_META_FM_GetChipId(unsigned int ms_timeout, FM_CHIP_ID_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetChipId_r(const int meta_handle, unsigned int ms_timeout, FM_CHIP_ID_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_PowerOn(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_FM_PowerOn_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_FM_TXPowerOn(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_FM_TXPowerOn_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_FM_PowerOff(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_FM_PowerOff_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_FM_TxSetFreq(unsigned int ms_timeout, FM_FREQ_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_TxSetFreq_r(const int meta_handle,unsigned int ms_timeout, FM_FREQ_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetFreq(unsigned int ms_timeout, FM_FREQ_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetFreq_r(const int meta_handle, unsigned int ms_timeout, FM_FREQ_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_GetRSSI(unsigned int ms_timeout, FM_FREQ_REQ_T *req, FM_RSSI_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetRSSI_r(const int meta_handle, unsigned int ms_timeout, FM_FREQ_REQ_T *req, FM_RSSI_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetIfCnt(unsigned int ms_timeout, FM_FREQ_REQ_T *req, FM_IF_CNT_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetIfCnt_r(const int meta_handle, unsigned int ms_timeout, FM_FREQ_REQ_T *req, FM_IF_CNT_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_SearchNextFreq(unsigned int ms_timeout, FM_FREQ_RANGE_REQ_T *req, FM_VAILD_FREQ_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_SearchNextFreq_r(const int meta_handle, unsigned int ms_timeout, FM_FREQ_RANGE_REQ_T *req, FM_VAILD_FREQ_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_SearchPrevFreq(unsigned int ms_timeout, FM_FREQ_RANGE_REQ_T *req, FM_VAILD_FREQ_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_SearchPrevFreq_r(const int meta_handle, unsigned int ms_timeout, FM_FREQ_RANGE_REQ_T *req, FM_VAILD_FREQ_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_SetMonoOrStereo_Blend(unsigned int ms_timeout, FM_MONO_STEREO_BLEND_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetMonoOrStereo_Blend_r(const int meta_handle, unsigned int ms_timeout, FM_MONO_STEREO_BLEND_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetRssiThreold(unsigned int ms_timeout, FM_RSSI_THRESHOLD_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetRssiThreold_r(const int meta_handle, unsigned int ms_timeout, FM_RSSI_THRESHOLD_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetIfCntDelta(unsigned int ms_timeout, FM_IF_CNT_DELTA_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetIfCntDelta_r(const int meta_handle, unsigned int ms_timeout, FM_IF_CNT_DELTA_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_ReadByte(unsigned int ms_timeout, FM_READ_BYTE_ADDR_REQ_T *req, FM_READ_BYTE_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_ReadByte_r(const int meta_handle, unsigned int ms_timeout, FM_READ_BYTE_ADDR_REQ_T *req, FM_READ_BYTE_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_WriteByte(unsigned int ms_timeout, FM_WRITE_BYTE_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_WriteByte_r(const int meta_handle, unsigned int ms_timeout, FM_WRITE_BYTE_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetSoftMute(unsigned int ms_timeout, FM_SOFT_MUTE_ONOFF_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetSoftMute_r(const int meta_handle, unsigned int ms_timeout, FM_SOFT_MUTE_ONOFF_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SelectSoftMuteStage(unsigned int ms_timeout, FM_STAGE_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SelectSoftMuteStage_r(const int meta_handle, unsigned int ms_timeout, FM_STAGE_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SelectSBlendStage(unsigned int ms_timeout, FM_STAGE_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SelectSBlendStage_r(const int meta_handle, unsigned int ms_timeout, FM_STAGE_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_GetHighOrLowSide(unsigned int ms_timeout, FM_FREQ_REQ_T *req, FM_HL_Side_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetHighOrLowSide_r(const int meta_handle, unsigned int ms_timeout, FM_FREQ_REQ_T *req, FM_HL_Side_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetStereoOrMono(unsigned int ms_timeout, FM_Stereo_Mono_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetStereoOrMono_r(const int meta_handle, unsigned int ms_timeout, FM_Stereo_Mono_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_SetVolume(unsigned int ms_timeout, FM_Volume_Setting_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetVolume_r(const int meta_handle, unsigned int ms_timeout, FM_Volume_Setting_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_AutoScan(unsigned int ms_timeout, FM_AutoScan_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_AutoScan_r(const int meta_handle, unsigned int ms_timeout, FM_AutoScan_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_SetRDS(unsigned int ms_timeout, FM_SetRDS_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetRDS_r(const int meta_handle, unsigned int ms_timeout, FM_SetRDS_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_GetRXFilterBW(unsigned int ms_timeout, FM_RX_FilterBW_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetRXFilterBW_r(const int meta_handle, unsigned int ms_timeout, FM_RX_FilterBW_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetPAMDLevel(unsigned int ms_timeout, FM_FREQ_REQ_T *req, FM_PAMD_Level_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetPAMDLevel_r(const int meta_handle, unsigned int ms_timeout, FM_FREQ_REQ_T* req, FM_PAMD_Level_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetMR(unsigned int ms_timeout, FM_MR_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetMR_r(const int meta_handle, unsigned int ms_timeout, FM_MR_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_SetDecodeMode(unsigned int ms_timeout, FM_Decode_Mode_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetDecodeMode_r(const int meta_handle, unsigned int ms_timeout, FM_Decode_Mode_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetHCC(unsigned int ms_timeout, FM_HCC_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetHCC_r(const int meta_handle, unsigned int ms_timeout, FM_HCC_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetPAMDThreshold(unsigned int ms_timeout, FM_PAMD_Threshold_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetPAMDThreshold_r(const int meta_handle, unsigned int ms_timeout, FM_PAMD_Threshold_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_YUSU_SetSoftmute(unsigned int ms_timeout, FM_Softmute_Enable_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_YUSU_SetSoftmute_r(const int meta_handle, unsigned int ms_timeout, FM_Softmute_Enable_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetDeemphasisLevel(unsigned int ms_timeout, FM_Deemphasis_Level_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetDeemphasisLevel_r(const int meta_handle, unsigned int ms_timeout, FM_Deemphasis_Level_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetHLSide(unsigned int ms_timeout, FM_HL_Side_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetHLSide_r(const int meta_handle, unsigned int ms_timeout, FM_HL_Side_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetDemodBW(unsigned int ms_timeout, FM_Demod_Bandwidth_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetDemodBW_r(const int meta_handle, unsigned int ms_timeout, FM_Demod_Bandwidth_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetDynamicLimiter(unsigned int ms_timeout, FM_DynamicLimiter_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetDynamicLimiter_r(const int meta_handle, unsigned int ms_timeout, FM_DynamicLimiter_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetSoftmuteRate(unsigned int ms_timeout, FM_Softmute_Rate_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_SetSoftmuteRate_r(const int meta_handle, unsigned int ms_timeout, FM_Softmute_Rate_REQ_T *req);
META_RESULT  __stdcall SP_META_FM_GetPI(unsigned int ms_timeout, FM_RDS_Info_REQ_T *req, FM_RDS_Info_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetPI_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Info_REQ_T *req, FM_RDS_Info_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetPTY(unsigned int ms_timeout, FM_RDS_Info_REQ_T *req, FM_RDS_Info_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetPTY_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Info_REQ_T *req, FM_RDS_Info_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetPS(unsigned int ms_timeout, FM_RDS_Info_REQ_T *req, FM_RDS_Info_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetPS_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Info_REQ_T *req, FM_RDS_Info_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetAF(unsigned int ms_timeout, FM_RDS_Info_REQ_T *req, FM_RDS_Info_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetAF_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Info_REQ_T *req, FM_RDS_Info_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetRT(unsigned int ms_timeout, FM_RDS_Info_REQ_T *req, FM_RDS_Info_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetRT_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Info_REQ_T *req, FM_RDS_Info_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetTP(unsigned int ms_timeout, FM_RDS_Status_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetTP_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Status_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetTA(unsigned int ms_timeout, FM_RDS_Status_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetTA_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Status_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetMS(unsigned int ms_timeout, FM_RDS_Status_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetMS_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Status_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetGoodBlockCounter(unsigned int ms_timeout, FM_RDS_Good_Block_Counter_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetGoodBlockCounter_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Good_Block_Counter_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetBadBlockCounter(unsigned int ms_timeout, FM_RDS_Bad_Block_Counter_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_GetBadBlockCounter_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Bad_Block_Counter_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_ResetBlockCounter(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_FM_ResetBlockCounter_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_FM_ResetGroupCounter(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_FM_ResetGroupCounter_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_FM_HWSeek(unsigned int ms_timeout, FM_HWSeek_REQ_T *req, FM_HWSeek_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_HWSeek_r(const int meta_handle, unsigned int ms_timeout, FM_HWSeek_REQ_T *req, FM_HWSeek_CNF_T *cnf);
META_RESULT  __stdcall SP_META_FM_HWSearch_Stop(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_FM_HWSearch_Stop_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_FM_SetStereoBlend(unsigned int ms_timeout, FM_SetStereoBlend_REQ_T* req);
META_RESULT  __stdcall SP_META_FM_SetStereoBlend_r(const int meta_handle, unsigned int ms_timeout, FM_SetStereoBlend_REQ_T* req);


//New API using workflow
typedef enum
{
	FMTX_1K_TONE = 1, 
	FMTX_2K_TONE = 2,
	FMTX_3K_TONE = 3,
	FMTX_4K_TONE = 4,
	FMTX_5K_TONE = 5,
	FMTX_6K_TONE = 6,
	FMTX_7K_TONE = 7,
	FMTX_8K_TONE = 8,
	FMTX_9K_TONE = 9,
	FMTX_10K_TONE = 10,
	FMTX_11K_TONE = 11,
	FMTX_12K_TONE = 12,
	FMTX_13K_TONE = 13,
	FMTX_14K_TONE = 14,
	FMTX_15K_TONE = 15,
	FMTX_MAX_TONE
	
}FM_TX_TONE_T;

typedef enum
{
	FM_TX_AUDIO_ANALOG = 0,
	FM_TX_AUDIO_I2S = 1,
	FM_RX_AUDIO_ANALOG = 2,
	FM_RX_AUDIO_I2S = 3,
	FM_AUDIO_MAX
	
}FM_TX_AUDIO_PATH_T;

typedef enum
{
	FM_ANA_LONG = 0,
	FM_ANA_SHORT=1,
	FM_ANA_MAX
	
}FM_ANA_T;


typedef struct
{
	FM_TX_AUDIO_PATH_T m_audioPath;
	
}FM_SetTxAudioPath_REQ_T;

typedef struct
{
	FM_TX_TONE_T m_audioFreq;
	
}FM_SetTxAudioFreq_REQ_T;


#define MAX_RDS_LOGDATA_LEN 256

typedef struct
{
	unsigned int dataLen;
	char data[MAX_RDS_LOGDATA_LEN];
	
} FM_RDS_LOGDATA_T;

typedef struct
{
    unsigned long total;
    unsigned long groupA[16]; //RDS groupA counter
    unsigned long groupB[16]; //RDS groupB counter
    
} FM_RDS_GROUPCOUNTER_T;

typedef struct
{
    int ana;
}FM_SetAntenna_REQ_T;

typedef struct
{
    int m_uCapArray;
}FM_CapArray_CNF_T;


typedef struct
{
	int  m_i4Step;
}FM_STEP_MODE_CNF_T;



META_RESULT  __stdcall SP_META_FM_SetTxAudioPath(unsigned int ms_timeout, FM_SetTxAudioPath_REQ_T path);
META_RESULT  __stdcall SP_META_FM_SetTxAudioPath_r(const int meta_handle, unsigned int ms_timeout, FM_SetTxAudioPath_REQ_T path);
META_RESULT  __stdcall SP_META_FM_SetTxAudioFreq(unsigned int ms_timeout, FM_SetTxAudioFreq_REQ_T freq);
META_RESULT  __stdcall SP_META_FM_SetTxAudioFreq_r(const int meta_handle, unsigned int ms_timeout, FM_SetTxAudioFreq_REQ_T freq);
META_RESULT  __stdcall SP_META_FM_GetRDSLogData(unsigned int ms_timeout, FM_RDS_LOGDATA_T * pCnf);
META_RESULT  __stdcall SP_META_FM_GetRDSLogData_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_LOGDATA_T * pCnf);
META_RESULT  __stdcall SP_META_FM_GetRDSBlerRatio(unsigned int ms_timeout, unsigned short * pBler);
META_RESULT  __stdcall SP_META_FM_GetRDSBlerRatio_r(const int meta_handle, unsigned int ms_timeout, unsigned short * pBler);
META_RESULT  __stdcall SP_META_FM_GetRDSGroupCounter(unsigned int ms_timeout, FM_RDS_GROUPCOUNTER_T * pCnf);
META_RESULT  __stdcall SP_META_FM_GetRDSGroupCounter_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_GROUPCOUNTER_T * pCnf);
META_RESULT  __stdcall SP_META_FM_SetAntenna(unsigned int ms_timeout, FM_SetAntenna_REQ_T * pReq);
META_RESULT  __stdcall SP_META_FM_SetAntenna_r(const int meta_handle, unsigned int ms_timeout, FM_SetAntenna_REQ_T * pReq);
META_RESULT  __stdcall SP_META_FM_GetCapArray(unsigned int ms_timeout, FM_CapArray_CNF_T * pCnf);
META_RESULT  __stdcall SP_META_FM_GetCapArray_r(const int meta_handle, unsigned int ms_timeout, FM_CapArray_CNF_T * pCnf);
META_RESULT  __stdcall SP_META_FM_GetStepMode(unsigned int ms_timeout, FM_STEP_MODE_CNF_T * pCnf);
META_RESULT  __stdcall SP_META_FM_GetStepMode_r(const int meta_handle, unsigned int ms_timeout, FM_STEP_MODE_CNF_T * pCnf);




typedef void (__stdcall *WM_META_FM_RDS_INFO_UPDATE_CNF)(const FM_RDS_Info_CNF_T *cnf, const short token, void *usrData);
typedef void (__stdcall *WM_META_FM_RDS_STATUS_UPDATE_CNF)(const FM_RDS_Status_CNF_T *cnf, const short token, void *usrData);
typedef struct
{
	WM_META_FM_RDS_INFO_UPDATE_CNF m_RDSInfoUpdateCallback;
	WM_META_FM_RDS_STATUS_UPDATE_CNF m_RDSStatusUpdateCallback;
} FM_RDSCallBack;

META_RESULT  __stdcall SP_META_FM_RegisterRDSInfoUpdateCallback(WM_META_FM_RDS_INFO_UPDATE_CNF cb);
META_RESULT  __stdcall SP_META_FM_RegisterRDSInfoUpdateCallback_r(const int meta_handle, WM_META_FM_RDS_INFO_UPDATE_CNF cb);
META_RESULT  __stdcall SP_META_FM_RegisterRDSStatusUpdateCallback(WM_META_FM_RDS_STATUS_UPDATE_CNF cb);
META_RESULT  __stdcall SP_META_FM_RegisterRDSStatusUpdateCallback_r(const int meta_handle, WM_META_FM_RDS_STATUS_UPDATE_CNF cb);
META_RESULT  __stdcall SP_META_FM_RemoveRDSInfoUpdateCallback(void);
META_RESULT  __stdcall SP_META_FM_RemoveRDSInfoUpdateCallback_r(const int meta_handle);
META_RESULT  __stdcall SP_META_FM_RemoveRDSStatusUpdateCallback(void);
META_RESULT  __stdcall SP_META_FM_RemoveRDSStatusUpdateCallback_r(const int meta_handle);

// FM Audio Test
META_RESULT  __stdcall SP_META_FM_AudioTest(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_FM_AudioTest_r(const int meta_handle, unsigned int ms_timeout);


//----------------------------------------------------------------//
//                            TDMB                                //
//----------------------------------------------------------------//

//--------------------------//
//    TDMB data structures  //
//--------------------------//

typedef enum {   // ref from TDMB
   META_TDMB_KOREA_BAND=1,
   META_TDMB_BAND_III,
   META_TDMB_L_BAND,
   META_TDMB_CANADA_BAND,
   META_TDMB_CHINESE_BAND,
   META_TDMB_BAND_II,
   META_TDMB_BAND_IF,
   META_TDMB_UNDEF_BAND
} META_TDMB_BAND_enum;

typedef struct
{
    META_TDMB_BAND_enum  m_rBand;
	
}TDMB_SET_BAND_REQ_T;

typedef struct
{
   unsigned int  m_u4Freq;
}TDMB_SET_FREQ_REQ_T;



typedef struct
{
	unsigned char m_ucFreqNum;
	unsigned int m_u4Freq[10];
   
}TDMB_AUTO_SCAN_CNF_T;

// ========  for Ensemble ========


typedef struct
{
	//TDMB_DBSTATE	   DB;
	unsigned char        m_ucStateNum;
	unsigned int		 m_u4State[10];


	unsigned int		Type;   //DMB,DAB,DATA
	unsigned int		Id;
	unsigned int		BitRate;
	unsigned char		PL; //Protection Level
	unsigned char		Reg[8];
	unsigned short		UserApplType;		// added by KST 2006.07.20

	unsigned int		TMId;
	unsigned int		ASCTy_DSCTy;
	unsigned int		SCId;
	unsigned int		PackAdd;
	unsigned int		DG_MFflag;
	unsigned int		Primary;
	unsigned int		CAflag;
	unsigned int		Language;
	char				SCLabel[16];
 
	//TDMB_SvcComponentInfo	 *pSvcComp;
	unsigned char		SvcComp_Order;			// 4bits
	unsigned char		SvcComp_TMId;			// 2bits	Transport Mechanism Id
	unsigned char		SvcComp_ASCTy_DSCTy;	// 6bits	Audio Service Component Type	
	unsigned char		SvcComp_SubCh_FIDCId;	// 6bits	SubChId or FIDCId in FIG 0/4
	unsigned int		SvcComp_SId;			// 16bit
	unsigned char		SvcComp_CAflag;			// 1bit		CA Flag
	unsigned char		SvcComp_DG_MFflag;		// 1bit		DG Flag or MF flag
	unsigned char		SvcComp_Language;		// 8bit
	unsigned char		SvcComp_SCIdS;			// 4bit		Service component Identifier within ther Service
	unsigned char       SvcComp_SvcCompLabel[16];// 16bytes Service component Label	

	unsigned short		SvcComp_SCId;			// 12bits	Service Component Id
	unsigned short		SvcComp_PackAdd;		// 10bits	Packet Address
	unsigned short		SvcComp_SCCA;			// 16bits	Service Component Conditional Access

	unsigned short      SvcComp_m_encoded_id;   // Only for Frontier
    unsigned char       SvcComp_m_sif;          // Only for Frontier	


	//TDMB_SubChInfo			 *pSubCh;
	unsigned char	    SubChId;		// 6bits	Sub channel Id
	unsigned char	    TblIndex;		// 6bits	TableIndex
	unsigned char	    Form_Opt_Prot;  //[3] : FormFlag   //[2] : Option//[1~0] : protection
	unsigned short	    StrtAdd;		// 10bits	Start Address
	unsigned short	    SubChSize;		// 10bits	Sub channel size

	unsigned int		Tag;

}TDMB_CHANNELDB_T;


typedef struct
{
	// TDMB_DBSTATE
	unsigned char       m_ucStateNum;
	unsigned int		m_u4State[10];

	unsigned int		Id;
	char				Label[20];

	//TDMB_ServiceInfo  *pService;
	unsigned int		SId;			// 32bits	
	unsigned char		SvcLabel[16];	// 16bytes	Service Label(Program service and Data service)
	unsigned short		CharacterFlag;
	unsigned char		CAId;			// 3bit
	unsigned char		NumSvcComp;		// 4bits	Number of Service Component	


	//TDMB_CHANNELDB		*Channel;
    unsigned char     m_ucChannelDBNum;
	TDMB_CHANNELDB_T  m_rChannelDB[10];


	//struct _TDMB_SERVICEDB	*Next;
	unsigned int				Tag;
	unsigned int			ChannelCount;


}TDMB_SERVICEDB_T; 

typedef struct
{
	// TDMB_DBSTATE
	unsigned char        m_ucStateNum;
	unsigned int		 m_u4State[10];

	unsigned int		 Band;
    unsigned int		 Frequency;
    unsigned short		 Id;
    unsigned int		 SvcNum;
    unsigned int		 SvcCompNum;
    unsigned int		 SubChNum;
	char				 Label[20];

	// TDMB_EnsembleInfo
	unsigned char	AlFlag;				// 1bit		Al flag
	unsigned char   NumSubCh;
	unsigned char   NumSvc;
	unsigned char	NumProgram;
	unsigned char   NumSvcComp;
	unsigned char	NumUserApp;
	unsigned char	NumAnn;
	unsigned char	NumProgType;
	unsigned char	EnsemLabel[16];		// 16bytes	Ensemble Label
	unsigned short  CharacterFlag;
	unsigned short	EId;				// 16bits	country Id Ensemble reference

	// TDMB_SERVICEDB[]
	unsigned char   m_ucServiceDBNum;
	TDMB_SERVICEDB_T  m_rServiceDB[10];

	unsigned int     Tag;

}TDMB_ENSEMBLEDB_T;


typedef struct   // for META APP
{
   unsigned char      m_ucEnsembleNum;
   TDMB_ENSEMBLEDB_T  m_rEnsembleDB[10];

}TDMB_GET_ENSM_INFO_BY_AUTO_SCAN_CNF_T;

typedef struct   // for META APP
{
	char m_cResult; // 0: success, 
	                // 1: the band not exist  ==> META_TDMB_ERR_BAND_NOT_EXIST
	                // 2: frequency not exist ==> META_TDMB_ERR_FREQ_NOT_EXIST

	unsigned char      m_ucEnsembleNum;
    TDMB_ENSEMBLEDB_T  m_rEnsembleDB[10];
	TDMB_ENSEMBLEDB_T  m_rCurEnsembleDB;

}TDMB_SET_FREQ_CNF_T;


typedef struct
{
	unsigned short m_u2Snr;
	unsigned char  m_ucBer_a;  // a.b*10^-c
	unsigned char  m_ucBer_b;
	unsigned char  m_ucBer_c;
	short          m_i2RSSI; 

}TDMB_GET_SIGNAL_CNF_T;

typedef struct
{
	unsigned int m_u4ServiceId;
	unsigned int m_u4SubChnId;
	char         *m_pcfilepath; // store the TS stream data to this file 

}TDMB_SEL_SERVICE_REQ_T;

typedef struct  
{
	unsigned int m_u4ServiceId;
	unsigned int m_u4SubChnId;

}TDMB_SEL_SERVICE_ONLY_REQ_T;



typedef struct  //  for Meta APP only
{
	unsigned char      m_ucEnsembleNum;
    TDMB_ENSEMBLEDB_T  m_rEnsembleDB[10];
	TDMB_ENSEMBLEDB_T  m_rCurEnsembleDB;

}TDMB_GET_ENSM_CNF_T;
// --------------------------//
//      TDMB callback        //
// --------------------------//
typedef enum
{
    TDMB_FAT_DISK_FULL = 0
   ,TDMB_FAT_UNKNOWN_WRITE_ERROR
   ,TDMB_MED_MEMORY_FULL
   ,TDMB_MED_MEMORY_NOT_EXIST

}TDMB_SEL_SERV_ERROR_RESULT;

typedef void (__stdcall *META_TDMB_SEL_SERV_CNF)(const TDMB_SEL_SERV_ERROR_RESULT status);


/*
//----------------------------------------------------------------------------------//
//  WM_MetaTest: data structure definition
//-----------------------------------------------------------------------------------//
//  WM_CMD_SUM
#define SIZE_ARRAY_NTEST_WM_CMD_SUM_REQ_T	10
typedef struct 
{
	short	nTest[SIZE_ARRAY_NTEST_WM_CMD_SUM_REQ_T];
}WM_CMD_SUM_REQ_T;

typedef struct 
{
	short	nTestSum;
}WM_CMD_SUM_CNF_T;

//	WM_CMD_Query_If_Target_Support_DVBH
typedef struct 
{
	 short	notUsed;
}WM_CMD_Query_If_Target_Support_DVBH_REQ_T;

typedef struct 
{
	  bool		bSupportDVBH;
}WM_CMD_Query_If_Target_Support_DVBH_CNF_T;

  //WM_CMD_Active_Timer
typedef struct
{
	   unsigned int		nMsTimer;
}WM_CMD_Active_Timer_REQ_T;

typedef struct 
{
	   unsigned int		nRecNum;
	   unsigned int		nMs;
}WM_CMD_Active_Timer_CNF_T;

typedef enum{
	FILE_START = 0,
	FILE_ONGOING,
	FILE_CLOSE,
	FILE_ONCE
}WM_METATEST_FILE_OP_TYPE;

typedef struct{
	unsigned int	nReqWriteFileStatus;
}WM_CMD_WriteFile_REQ_T;

typedef struct{
	unsigned int	nCnfWriteFileStatus;
}WM_CMD_WriteFile_CNF_T;

typedef struct{
	unsigned int	nReqReadFileStatus;
}WM_CMD_ReadFile_REQ_T;

typedef struct{
	unsigned int	nCnfReadFileStatus;
}WM_CMD_ReadFile_CNF_T;


// ---------------------------------------------
//      WM_MetaTest: callback        
// ----------------------------------------------

typedef enum
{
    WM_CMD_SUM_SUCESS = 0
   ,WM_CMD_SUM_FAIL 
}WM_MetaTest_RESULT;
//------------------------------------------
//WM_MetaTest: export function definition
//-----------------------------------------
META_RESULT  __stdcall META_WmMetaTest_Sum(unsigned int  ms_timeout, WM_CMD_SUM_REQ_T *req, WM_CMD_SUM_CNF_T *cnf);
META_RESULT  __stdcall META_WmMetaTest_Sum_r(const int meta_handle,unsigned int  ms_timeout, WM_CMD_SUM_REQ_T *req, WM_CMD_SUM_CNF_T *cnf);
META_RESULT  __stdcall META_WmMetaTest_QueryIfTargetSupportDVBH(unsigned int  ms_timeout, WM_CMD_Query_If_Target_Support_DVBH_REQ_T *req, WM_CMD_Query_If_Target_Support_DVBH_CNF_T *cnf);
META_RESULT  __stdcall META_WmMetaTest_QueryIfTargetSupportDVBH_r(const int meta_handle,unsigned int  ms_timeout, WM_CMD_Query_If_Target_Support_DVBH_REQ_T *req, WM_CMD_Query_If_Target_Support_DVBH_CNF_T *cnf);
META_RESULT  __stdcall META_WmMetaTest_ActiveTimer(unsigned int  ms_timeout, WM_CMD_Active_Timer_REQ_T *req, WM_CMD_Active_Timer_CNF_T *cnf);
META_RESULT  __stdcall META_WmMetaTest_ActiveTimer_r(const int meta_handle,unsigned int  ms_timeout, WM_CMD_Active_Timer_REQ_T *req, WM_CMD_Active_Timer_CNF_T *cnf);
META_RESULT  __stdcall META_WmMetaTest_WriteFile(unsigned int  ms_timeout, WM_CMD_WriteFile_REQ_T *req, WM_CMD_WriteFile_CNF_T *cnf);
META_RESULT  __stdcall META_WmMetaTest_WriteFile_r(const int meta_handle,unsigned int  ms_timeout, WM_CMD_WriteFile_REQ_T *req, WM_CMD_WriteFile_CNF_T *cnf);
META_RESULT  __stdcall META_WmMetaTest_ReadFile(unsigned int  ms_timeout, WM_CMD_ReadFile_REQ_T *req, WM_CMD_ReadFile_CNF_T *cnf);
META_RESULT  __stdcall META_WmMetaTest_ReadFile_r(const int meta_handle,unsigned int  ms_timeout, WM_CMD_ReadFile_REQ_T *req, WM_CMD_ReadFile_CNF_T *cnf);
*/

//-----------------------------------------------------//
//  WM META UnitTest
//-----------------------------------------------------//

typedef struct {
	unsigned int	m_TestCaseID;
	const char *	m_pDescription;
} WM_META_UT_TestCaseID_T;

void __stdcall SP_META_QueryTestCase(WM_META_UT_TestCaseID_T  **ppTestCase, unsigned int  *pTestCaseCount);
void __stdcall SP_META_UnitTest(const unsigned int  *p_TestCaseID_Array, unsigned int  TestCaseCount);


// --------------------------------------------------------------------------------
//      WM_Battery:    data structure definition     addey by yuying 2008-12-18     
// --------------------------------------------------------------------------------
typedef enum{
	FILE_START,
	FILE_ONGOING,
	FILE_CLOSE,
	FILE_ONCE
}WM_Bat_Image_OP_TYPE;

typedef enum{
	FILE_Success,
	FILE_Fail
}WM_Bat_File_Err_TYPE;

 typedef enum{
  WM_BAT_WRITE_DATA=0,
  WM_BAT_COMPARA_DATA,
  WM_BAT_DELAY
}WM_BAT_Upload_OP_TYPE;

typedef struct{
	int				nReqDLImageStatus;
	unsigned int		image_size;  //the size of whole image
	unsigned int		block_size;  //the size of current transfer.
}WM_Bat_DLImage_REQ_T;

typedef struct{
	int	nCnfDLImageStatus;
	int    DL_Status;		//0-success 1-failed
}WM_Bat_DLImage_CNF_T;

typedef struct{
	//int	nReqUPImageStatus;
	WM_Bat_Image_OP_TYPE	nReqStartStatus;
 	WM_BAT_Upload_OP_TYPE 	nReqUpdateOpStatus;
  	char  					StartAddress;		
  	unsigned short 			delaytime;
	unsigned short			nLen;
	char					Buf[96];
}WM_Bat_UPImage_REQ_T;

typedef struct{
	WM_Bat_Image_OP_TYPE	nCnfStartStatus;	//0-first 1-
	int	nCnfUpdateStatus;  //0-success 1-fail
}WM_Bat_UPImage_CNF_T;


//export function

//META_RESULT  __stdcall META_Battery_UploadImage(unsigned int ms_timeout, const WM_Bat_UPImage_REQ_T *req, WM_Bat_UPImage_CNF_T *cnf,char* fileAddress);
//META_RESULT  __stdcall META_Battery_UploadImage_r(const int meta_handle,unsigned int ms_timeout, const WM_Bat_UPImage_REQ_T *req, WM_Bat_UPImage_CNF_T *cnf, char* fileAddress);



// --------------------------------------------------------------------------------
//      WM_Battery:    data structure definition
// --------------------------------------------------------------------------------

// 0  WM_CMD_DVB_Connect

typedef struct
{
	unsigned int Frequency;
	unsigned int BandWidth;
}DVB_CONNECT_REQ;

typedef struct
{
	int           drv_status;
}DVB_CONNECT_CNF;	

// 1  WM_CMD_DVB_Disconnect

typedef struct
{
	unsigned int NotUsed;
}DVB_DISCONNECT_REQ;

typedef struct{
	int           drv_status;
}DVB_DISCONNECT_CNF;

// 2 WM_CMD_DVB_Middleware_Update

typedef struct
{
	int 			FileStatus;
	unsigned int 	ImageSize;
	unsigned int 	BrockSize;
}DVB_MIDDLEWARE_UPDATE_REQ;

typedef struct
{
	int 	FileStatus;
	int		drv_status;
}DVB_MIDDLEWARE_UPDATE_CNF;


// 3 WM_CMD_DVB_Parameter_Calibration
typedef struct
{
	unsigned int NotUsed;
}DVB_PARAMETER_CALIBRATION_REQ;

typedef struct
{
	int           drv_status;
}DVB_PARAMETER_CALIBRATION_CNF;

// 4  WM_CMD_DVB_Get_Signal_Quality

typedef struct
{
	unsigned int NotUsed;
}DVB_GET_SIGNALQUALITY_REQ;

typedef struct
{
	unsigned char	SNRValue;
	char			Strength;
	unsigned int	TSPER;
	unsigned int	PostVBER;
	int				drv_status;
}DVB_GET_SIGNALQUALITY_CNF;

// 5  WM_CMD_DVB_Demodulator_IsAlive

typedef struct
{
	unsigned int NotUsed;
}DVB_DEMODULATOR_ISALIVE_REQ;

typedef struct
{
	int           drv_status;
}DVB_DEMODULATOR_ISALIVE_CNF;

// 6  WM_CMD_DVB_Set_TS_PacketBatch

typedef struct
{
	unsigned int BatchNum;
}DVB_SET_TS_PACKETBATCH_REQ;

typedef struct
{
	int           drv_status;
}DVB_SET_TS_PACKETBATCH_CNF;

// 7  WM_CMD_DVB_Set_TX_PacketTimeout

typedef struct
{
	unsigned int TimeOut;
}DVB_SET_TX_PACKETTIMEOUT_REQ;

typedef struct
{
	int           drv_status;
}DVB_SET_TX_PACKETTIMEOUT_CNF;

// 9  WM_CMD_DVB_Add_TS_PID

typedef struct
{
	unsigned int PIDValue;
}DVB_ADD_TS_PID_REQ;

typedef struct
{
	int           drv_status;
}DVB_ADD_TS_PID_CNF;

// 10  WM_CMD_DVB_Remove_TS_PID

typedef struct
{
	unsigned int PIDValue;
}DVB_REMOVE_TS_PID_REQ;

typedef struct
{
	int           drv_status;
}DVB_REMOVE_TS_PID_CNF;

// 11 WM_CMD_DVB_Disable_AllTS_PIDsFiltering

typedef struct
{
	unsigned int NotUsed;
}DVB_DISABLE_ALLTS_PIDFILTERING_REQ;

typedef struct
{
	int		drv_status;
}DVB_DISABLE_ALLTS_PIDFILTERING_CNF;

// 12 WM_CMD_DVB_Dump_TS_PacketstoSDCard

typedef struct
{
	unsigned int NotUsed;
}DVB_DUMP_TS_PACKETSTOSDCARD_REQ;

typedef struct
{
	int           drv_status;
}DVB_DUMP_TS_PACKETSTOSDCARD_CNF;

// 13 WM_CMD_DVB_Get_ReceptionMode

typedef struct
{
	unsigned int NotUsed;
}DVB_GET_RECEPTIONMODE_REQ;

typedef struct
{
	unsigned char	FFT;
	unsigned char	GI;
	unsigned char	CodeRate;
	unsigned char	Constellation;
	unsigned char	Hierarchy;
	unsigned char	HP_LP;
	unsigned char	HP_CodeRate;
	unsigned char	LP_CodeRate;
	unsigned char	Indepth;
	unsigned short	CellID;
	int				drv_status;
}DVB_GET_RECEPTIONMODE_CNF;


// 14 WM_CMD_DVB_Get_LockIndicator

typedef struct
{
	unsigned int NotUsed;
}DVB_GET_LOCKINDICATOR_REQ;

typedef struct
{
	unsigned char	AGCLock;
	unsigned char	MDLock;
	unsigned char	TPSLock;
	unsigned char	TSLock;
	unsigned char	CtrlStatus;
	unsigned char	SigStrength;
	unsigned char	SigQuality;
	short			InbandPow;
	short			WidebandPow;
	int				drv_status;
}DVB_GET_LOCKINDICATOR_CNF;

// 15 WM_CMD_DVB_Get_PerformanceInfo

typedef struct
{
	unsigned int NotUsed;
}DVB_GET_PERFORMANCEINFO_REQ;

typedef struct
{
    unsigned char	SNR;
    unsigned char	CCCICount;
    unsigned char	AR;
    unsigned char	FDBW;
    char			RFAGC;
    char			IFAGC;
    unsigned char	RFAGCState;
    unsigned char	ReceiveMode;
    unsigned char	ResetCount;
    unsigned char	AcqCount;
    unsigned char	Wbpd;
    unsigned char	AdcPow;
    unsigned short	INRCount;
    short			WinDrift;
    unsigned short	IQGain;
    unsigned short	TPSTime;
    unsigned short	TSTime;
    unsigned short	FER;
    unsigned short	MFER;
    unsigned int	PostBER;
    unsigned int	TSPER;
    unsigned int	TSBER;
    unsigned int	IQPhase;
    unsigned int	PhaseComp;
    int				CFOInit;
    int				CFOTra;
    int				TimeOffset;
    int				Tope;
	int				drv_status;
}DVB_GET_PERFORMANCEINFO_CNF;

// 16 WM_CMD_DVB_Get_Version

typedef struct
{
	unsigned int	NotUsed;
} DVB_GET_VERSION_REQ;

typedef struct
{
	char	Version[256];
	int		drv_status;
} DVB_GET_VERSION_CNF;

// 17 WM_CMD_DVB_Get_Debug_Counter

typedef struct
{
    unsigned int	NotUsed;
} DVB_GET_DEBUG_COUNTER_REQ;

typedef struct
{
	unsigned int	TSPacketNumber;
	unsigned int	OverflowCounter;
	unsigned int	InterruptCounter;
	int				drv_status;
} DVB_GET_DEBUG_COUNTER_CNF;


//wifi
typedef struct
{    
	unsigned int		int_rx_ok_num;
	unsigned int		int_crc_err_num;
	unsigned int		int_rssi_max;
	unsigned int		int_rssi_min;
	unsigned int		int_rssi_mean;
	unsigned int		int_rssi_variance;
} WIFI_RXSTATUS_T;

typedef enum _ENUM_CFG_SRC_TYPE_T
{
	CFG_SRC_TYPE_EEPROM,	//cfg data is queried/set from/to EEPROM
	CFG_SRC_TYPE_NVRAM,		//cfg data is queried/set from/to NVRAM
	CFG_SRC_TYPE_BOTH,		//cfg data is queried/set from/to NVRAM, and E2PROM presents too
	CFG_SRC_TYPE_AUTO
} ENUM_CFG_SRC_TYPE_T;

typedef struct
{
	int bufSize;
	int bLongPreamble;
	int txRate;
	int pktCount;
	int pktInterval;
	int bGainControl;
	int gainControl;
	int bTrackAlc;
	int bTargetAlc;
	int targetAlcValue;
	int txAntenna;
	
} WIFI_TX_PARAM_T;

META_RESULT  __stdcall SP_META_WiFi_QueryConfig(unsigned int ms_timeout, ENUM_CFG_SRC_TYPE_T *bufType);
META_RESULT  __stdcall SP_META_WiFi_QueryConfig_r(int meta_handle, unsigned int ms_timeout, ENUM_CFG_SRC_TYPE_T *bufType);
META_RESULT  __stdcall SP_META_WiFi_setPacketRx(unsigned int ms_timeout, int condition, int nAntenna);
META_RESULT  __stdcall SP_META_WiFi_setPacketRx_r(const int meta_handle, unsigned int ms_timeout, int condition, int nAntenna);
META_RESULT  __stdcall SP_META_WiFi_readMCR32(unsigned int ms_timeout, unsigned int offset, unsigned long *value);
META_RESULT  __stdcall SP_META_WiFi_readMCR32_r(const int meta_handle, unsigned int ms_timeout, unsigned int offset, unsigned long *value);
META_RESULT  __stdcall SP_META_WiFi_writeMCR32(unsigned int ms_timeout, unsigned int offset, unsigned int value);
META_RESULT  __stdcall SP_META_WiFi_writeMCR32_r(const int meta_handle, unsigned int ms_timeout, unsigned int offset, unsigned int value);


META_RESULT  __stdcall SP_META_WiFi_ReadConfigData(unsigned int ms_timeout, unsigned int offset, unsigned long *value, ENUM_CFG_SRC_TYPE_T type);
META_RESULT  __stdcall SP_META_WiFi_ReadConfigData_r(int meta_handle, unsigned int ms_timeout, unsigned int offset, unsigned long *value, ENUM_CFG_SRC_TYPE_T type);
META_RESULT  __stdcall SP_META_WiFi_WriteConfigData(unsigned int ms_timeout, unsigned int offset, unsigned int value, ENUM_CFG_SRC_TYPE_T type);
META_RESULT  __stdcall SP_META_WiFi_WriteConfigData_r(int meta_handle, unsigned int ms_timeout, unsigned int offset, unsigned int value, ENUM_CFG_SRC_TYPE_T type);

#define SP_META_WiFi_readEEPRom16(ms_timeout, offset, value)	\
	META_WiFi_ReadConfigData(ms_timeout, offset, value, CFG_SRC_TYPE_AUTO)
#define SP_META_WiFi_writeEEPRom16(ms_timeout, offset, value)	\
	META_WiFi_WriteConfigData(ms_timeout, offset, value, CFG_SRC_TYPE_AUTO)
#define SP_META_WiFi_readEEPRom16_r(meta_handle, ms_timeout, offset, value)	\
SP_META_WiFi_ReadConfigData_r(meta_handle, ms_timeout, offset, value, CFG_SRC_TYPE_AUTO)
#define SP_META_WiFi_writeEEPRom16_r(meta_handle, ms_timeout, offset, value)	\
SP_META_WiFi_WriteConfigData_r(meta_handle, ms_timeout, offset, value, CFG_SRC_TYPE_AUTO)

META_RESULT  __stdcall SP_META_WiFi_eepromReadByteStr(unsigned int ms_timeout, unsigned int u4Addr, unsigned int u4Length, char *pszStr);
META_RESULT  __stdcall SP_META_WiFi_eepromReadByteStr_r(const int meta_handle, unsigned int ms_timeout, unsigned int u4Addr, unsigned int u4Length, char *pszStr);
META_RESULT  __stdcall SP_META_WiFi_eepromWriteByteStr(unsigned int ms_timeout, unsigned int u4Addr, unsigned int u4Length, char *pszStr);
META_RESULT  __stdcall SP_META_WiFi_eepromWriteByteStr_r(const int meta_handle, unsigned int ms_timeout, unsigned int u4Addr, unsigned int u4Length, char *pszStr);
META_RESULT  __stdcall SP_META_WiFi_getChannel(unsigned int ms_timeout, long *channelConfig_p);
META_RESULT  __stdcall SP_META_WiFi_getChannel_r(const int meta_handle, unsigned int ms_timeout, long *channelConfig_p);
META_RESULT  __stdcall SP_META_WiFi_setPacketTxEx(unsigned int ms_timeout, WIFI_TX_PARAM_T * pTxParam);
META_RESULT  __stdcall SP_META_WiFi_setPacketTxEx_r(const int meta_handle, unsigned int ms_timeout, WIFI_TX_PARAM_T * pTxParam);
META_RESULT  __stdcall SP_META_WiFi_GetATParam(unsigned int ms_timeout, unsigned int offset, unsigned long *value);
META_RESULT  __stdcall SP_META_WiFi_GetATParam_r(const int meta_handle, unsigned int ms_timeout, unsigned int offset, unsigned long *value);
META_RESULT  __stdcall SP_META_WiFi_SetATParam(unsigned int ms_timeout, unsigned int offset, unsigned int value);
META_RESULT  __stdcall SP_META_WiFi_SetATParam_r(const int meta_handle, unsigned int ms_timeout, unsigned int offset, unsigned int value);
META_RESULT  __stdcall SP_META_WiFi_setOutputPower(unsigned int ms_timeout, WIFI_TX_PARAM_T * pTxParam);
META_RESULT  __stdcall SP_META_WiFi_setOutputPower_r(const int meta_handle, unsigned int ms_timeout, WIFI_TX_PARAM_T * pTxParam);
META_RESULT  __stdcall SP_META_WiFi_setStandBy(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_WiFi_setStandBy_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_WiFi_setCarrierSuppression(unsigned int ms_timeout, WIFI_TX_PARAM_T * pTxParam);
META_RESULT  __stdcall SP_META_WiFi_setCarrierSuppression_r(const int meta_handle, unsigned int ms_timeout, WIFI_TX_PARAM_T * pTxParam);
META_RESULT  __stdcall SP_META_WiFi_setLocalFrequecy(unsigned int ms_timeout, int txPower, int txAntenna);
META_RESULT  __stdcall SP_META_WiFi_setLocalFrequecy_r(const int meta_handle, unsigned int ms_timeout, int txPower, int txAntenna);
META_RESULT  __stdcall SP_META_WiFi_setNormalMode(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_WiFi_setNormalMode_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_WiFi_setOutputPin(unsigned int ms_timeout, int pinIndex, int outputLevel);
META_RESULT  __stdcall SP_META_WiFi_setOutputPin_r(const int meta_handle, unsigned int ms_timeout, int pinIndex, int outputLevel);
META_RESULT  __stdcall SP_META_WiFi_setPnpPower(unsigned int ms_timeout, int i4PowerMode);
META_RESULT  __stdcall SP_META_WiFi_setPnpPower_r(const int meta_handle, unsigned int ms_timeout, int i4PowerMode);
META_RESULT  __stdcall SP_META_WiFi_setTestMode(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_WiFi_setTestMode_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_WiFi_setChannel(unsigned int ms_timeout, int channelConfig);
META_RESULT  __stdcall SP_META_WiFi_setChannel_r(const int meta_handle, unsigned int ms_timeout, int channelConfig);
META_RESULT  __stdcall SP_META_WiFi_readTxPowerFromEEPromEx(unsigned int ms_timeout, int channelFreq, int rate, long *nTxPwr, long *outputPower, long *targetAlc);
META_RESULT  __stdcall SP_META_WiFi_readTxPowerFromEEPromEx_r(const int meta_handle, unsigned int ms_timeout, int channelFreq, int rate, long *nTxPwr, long *outputPower, long *targetAlc);
META_RESULT  __stdcall SP_META_WiFi_getPacketRxStatus(unsigned int ms_timeout, WIFI_RXSTATUS_T *pRxStatus);
META_RESULT  __stdcall SP_META_WiFi_getPacketRxStatus_r(const int meta_handle, unsigned int ms_timeout, WIFI_RXSTATUS_T *pRxStatus);
META_RESULT  __stdcall SP_META_WiFi_setXtalTrimToCr(unsigned int ms_timeout, unsigned int u4Value);
META_RESULT  __stdcall SP_META_WiFi_setXtalTrimToCr_r(const int meta_handle, unsigned int ms_timeout, unsigned int u4Value);
META_RESULT  __stdcall SP_META_WiFi_queryThermoInfo(unsigned int ms_timeout, long * pi4Enable, unsigned long * pu4RawVal);
META_RESULT  __stdcall SP_META_WiFi_queryThermoInfo_r(const int meta_handle, unsigned int ms_timeout, long * pi4Enable, unsigned long * pu4RawVal);
META_RESULT  __stdcall SP_META_WiFi_setThermoEn(unsigned int ms_timeout, long i4Enable);
META_RESULT  __stdcall SP_META_WiFi_setThermoEn_r(const int meta_handle, unsigned int ms_timeout, long i4Enable);


//add by dian.wang for MT6620
META_RESULT __stdcall SP_META_WiFi_readTxPower(unsigned int ms_timeout, unsigned long *value);
META_RESULT __stdcall SP_META_WiFi_readTxPower_r(const int meta_handle, unsigned int ms_timeout, unsigned long *value);
META_RESULT __stdcall SP_META_WiFi_setRxTest(unsigned int ms_timeout);
META_RESULT __stdcall SP_META_WiFi_setRxTest_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT __stdcall SP_META_WiFi_setBandwidth(unsigned int ms_timeout,unsigned int value);
META_RESULT __stdcall SP_META_WiFi_setBandwidth_r(const int meta_handle, unsigned int ms_timeout,unsigned int value);
META_RESULT __stdcall SP_META_WiFi_setGuardinterval( unsigned int ms_timeout,unsigned int value);
META_RESULT __stdcall SP_META_WiFi_setGuardinterval_r(const int meta_handle, unsigned int ms_timeout,unsigned int value);
META_RESULT __stdcall SP_META_WiFi_setModeSelect(unsigned int ms_timeout,unsigned int value);
META_RESULT __stdcall SP_META_WiFi_setModeSelect_r(const int meta_handle, unsigned int ms_timeout,unsigned int value);
META_RESULT __stdcall SP_META_WiFi_setTxRxIQCalibration( unsigned int ms_timeout);
META_RESULT __stdcall SP_META_WiFi_setTxRxIQCalibration_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT __stdcall SP_META_WiFi_setDPDCalibration( unsigned int ms_timeout);
META_RESULT __stdcall SP_META_WiFi_setDPDCalibration_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT __stdcall SP_META_WiFi_getResultInformation( unsigned int ms_timeout,unsigned int index,unsigned long * length);
META_RESULT __stdcall SP_META_WiFi_getResultInformation_r(const int meta_handle, unsigned int ms_timeout,unsigned int index,unsigned long * length);
META_RESULT __stdcall SP_META_WiFi_getCalResult(unsigned int ms_timeout,unsigned int index,unsigned int offset,unsigned long * data);
META_RESULT __stdcall SP_META_WiFi_getCalResult_r(const int meta_handle, unsigned int ms_timeout,unsigned int index,unsigned int offset,unsigned long * data);
META_RESULT __stdcall SP_META_WiFi_getTemperatureSensorResult( unsigned int ms_timeout,unsigned long *value);
META_RESULT __stdcall SP_META_WiFi_getTemperatureSensorResult_r(const int meta_handle, unsigned int ms_timeout,unsigned long *value);
META_RESULT __stdcall SP_META_WiFi_getVoltageSensorResult(unsigned int ms_timeout,unsigned long *value);
META_RESULT __stdcall SP_META_WiFi_getVoltageSensorResult_r(const int meta_handle, unsigned int ms_timeout,unsigned long *value);
META_RESULT __stdcall SP_META_WiFi_readEFuseAddr( unsigned int ms_timeout,unsigned int addr,unsigned long *value);
META_RESULT __stdcall SP_META_WiFi_readEFuseAddr_r(const int meta_handle, unsigned int ms_timeout,unsigned int addr,unsigned long *value);
META_RESULT __stdcall SP_META_WiFi_writeEFuseAddr(unsigned int ms_timeout,unsigned int addr,unsigned int value);
META_RESULT __stdcall SP_META_WiFi_writeEFuseAddr_r(const int meta_handle, unsigned int ms_timeout,unsigned int addr,unsigned int value);
/*DEPRECATED*/META_RESULT __stdcall SP_META_WiFi_setTSSIEnableorDisable(unsigned int ms_timeout,unsigned int flag);
/*DEPRECATED*/META_RESULT __stdcall SP_META_WiFi_setTSSIEnableorDisable_r(const int meta_handle, unsigned int ms_timeout,unsigned int flag);
/*DEPRECATED*/META_RESULT __stdcall SP_META_WiFi_getTSSICalibrationResult( unsigned int ms_timeout,unsigned long * value);
/*DEPRECATED*/META_RESULT __stdcall SP_META_WiFi_getTSSICalibrationResult_r(const int meta_handle, unsigned int ms_timeout,unsigned long * value);
META_RESULT __stdcall SP_META_WiFi_TSSICalibration( unsigned int ms_timeout);
META_RESULT __stdcall SP_META_WiFi_TSSICalibration_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT __stdcall SP_META_WiFi_setRate(unsigned int ms_timeout,unsigned long value);
META_RESULT __stdcall SP_META_WiFi_setRate_r(const int meta_handle, unsigned int ms_timeout,unsigned long value);
META_RESULT __stdcall SP_META_WiFi_ReceivedErrorCount(unsigned int ms_timeout, unsigned long * value);
META_RESULT __stdcall SP_META_WiFi_ReceivedErrorCount_r(const int meta_handle, unsigned int ms_timeout, unsigned long * value);
META_RESULT __stdcall SP_META_WiFi_ReceivedOKCount(unsigned int ms_timeout, unsigned long * value);
META_RESULT __stdcall SP_META_WiFi_ReceivedOKCount_r(const int meta_handle, unsigned int ms_timeout, unsigned long * value);
META_RESULT __stdcall SP_META_WiFi_GetChipVersion( unsigned int ms_timeout,unsigned long * chipVersion);
META_RESULT __stdcall SP_META_WiFi_GetChipVersion_r(const int meta_handle, unsigned int ms_timeout,unsigned long * chipVersion);



typedef struct _NVRAM_ACCESS_STRUCT 
{
    unsigned int dataLen; 
    unsigned int dataOffset; /*set as zero for whole region */
    char * data;
    
} NVRAM_ACCESS_STRUCT;

META_RESULT  __stdcall SP_META_WiFi_WriteNVRAM_r(const int meta_handle, unsigned int  ms_timeout, NVRAM_ACCESS_STRUCT * pReq);
META_RESULT  __stdcall SP_META_WiFi_WriteNVRAM(unsigned int  ms_timeout, NVRAM_ACCESS_STRUCT * pReq);
META_RESULT  __stdcall SP_META_WiFi_ReadNVRAM_r(const int meta_handle, unsigned int  ms_timeout, NVRAM_ACCESS_STRUCT * pReq);
META_RESULT  __stdcall SP_META_WiFi_ReadNVRAM(unsigned int  ms_timeout, NVRAM_ACCESS_STRUCT * pReq);


//for wifi CW mode
//for input parameter nTxRate please set to 0.
//for input parameter nCWModeType please set to 4. 
META_RESULT __stdcall SP_META_WiFi_setCWMode(unsigned int ms_timeout, int nTxRate, int nCWModeType);
META_RESULT __stdcall SP_META_WiFi_setCWMode_r(const int meta_handle, unsigned int ms_timeout, int nTxRate, int nCWModeType);

META_RESULT __stdcall SP_META_WiFi_ReceivedRSSI(unsigned int ms_timeout, long * value);
META_RESULT __stdcall SP_META_WiFi_ReceivedRSSI_r(const int meta_handle, unsigned int ms_timeout, long * value);
//

//For WiFi MT6630
META_RESULT __stdcall SP_META_WiFi_setBandwidthEx(unsigned int ms_timeout, unsigned int nChBandwidth, unsigned int nDataBandwidth, unsigned int nPrimarySetting);
META_RESULT __stdcall SP_META_WiFi_setBandwidthEx_r(const int meta_handle, unsigned int ms_timeout, unsigned int nChBandwidth, unsigned int nDataBandwidth, unsigned int nPrimarySetting);

META_RESULT __stdcall SP_META_WiFi_setJMode(unsigned int ms_timeout, unsigned int nMode);
META_RESULT __stdcall SP_META_WiFi_setJMode_r(const int meta_handle, unsigned int ms_timeout, unsigned int nMode);
//

META_RESULT  __stdcall SP_META_WiFi_setDutyCycle(unsigned int ms_timeout, WIFI_TX_PARAM_T * pTxParam, int nCWMode);
META_RESULT  __stdcall SP_META_WiFi_setDutyCycle_r(const int meta_handle, unsigned int ms_timeout, WIFI_TX_PARAM_T * pTxParam, int nCWMode);



//ui does not use, no test
#if 0
META_RESULT  __stdcall SP_META_WiFi_getPacketTxStatusEx(unsigned int ms_timeout, long *sentCount, long *ackCount, long *alc, 
												long *cckGainControl, long *ofdmGainControl);
META_RESULT  __stdcall SP_META_WiFi_setEEPRomFromFile(unsigned int ms_timeout, TCHAR* fileName);
META_RESULT  __stdcall SP_META_WiFi_setEEPromCKSUpdated(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_WiFi_setEEPRomSize(unsigned int ms_timeout, long eepromSz);
META_RESULT  __stdcall SP_META_WiFi_getChannelBand(unsigned int ms_timeout, long freq, long *channel, long *band);
META_RESULT  __stdcall SP_META_WiFi_getEEPRomSize(unsigned int ms_timeout, long *eepromSz);
META_RESULT  __stdcall SP_META_WiFi_setChipType(unsigned int ms_timeout, unsigned long u4ChipType);

META_RESULT  __stdcall SP_META_WiFi_getPacketTxStatusEx_r(const int meta_handle, unsigned int ms_timeout, long *sentCount, long *ackCount, long *alc, 
												long *cckGainControl, long *ofdmGainControl);
META_RESULT  __stdcall SP_META_WiFi_setEEPRomFromFile_r(const int meta_handle, unsigned int ms_timeout, TCHAR* fileName);
META_RESULT  __stdcall SP_META_WiFi_setEEPromCKSUpdated_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_WiFi_setEEPRomSize_r(const int meta_handle, unsigned int ms_timeout, long eepromSz);
META_RESULT  __stdcall SP_META_WiFi_getChannelBand_r(const int meta_handle, unsigned int ms_timeout, long freq, long *channel, long *band);
META_RESULT  __stdcall SP_META_WiFi_getEEPRomSize_r(const int meta_handle, unsigned int ms_timeout, long *eepromSz);
META_RESULT  __stdcall SP_META_WiFi_setChipType_r(const int meta_handle, unsigned int ms_timeout, unsigned long u4ChipType);
#endif

//Clean Boot Flag
META_RESULT __stdcall SP_META_SetCleanBootFlag(unsigned int ms_timeout,SetCleanBootFlag_REQ *req, SetCleanBootFlag_CNF *cnf);
META_RESULT __stdcall SP_META_SetCleanBootFlag_r(const int meta_handle,unsigned int ms_timeout,SetCleanBootFlag_REQ *req,SetCleanBootFlag_CNF *cnf);

//Battey FW/SOC info
typedef enum{
 BAT_READ_INFO_FAILED=0, 
 BAT_READ_INFO_SUCCESS,
 BAT_READ_FW_SUCCESS,
 BAT_READ_VBAT_SUCCESS 
}WM_Bat_READ_FW_TYPE;

 typedef enum{
	WM_BAT_SOC1_SETTINGS=0,
   	WM_BAT_SOC1_CLEAR
 }WM_BAT_SOC_TYPE;

typedef struct
{
  	int 		ibatteryinfo; //N/A
}WM_Bat_READ_FW_INFO_REQ_T;
 
typedef struct{
  	//int 		ibatteryinfo; //N/A
  	int		nReqReadSocType;	//0-setting, 1-clear
}WM_Bat_READ_SOC_REQ_T; 
 
typedef struct
{
  	//unsigned short 	SocValue; //N/A
  	unsigned char		SocValue;
  	unsigned char		SocClearValue;
  	int		nReqWriteSocType;	//0-setting, 1-clear
}WM_Bat_WRITE_SOC_REQ_T; 
 
typedef struct
{
	unsigned short	BQ27500_FW_Version;		//0xFFFF
	unsigned short	BQ27500_Battery_Voltage;	 //0xFFFF  
	unsigned short	BQ27500_DFI_Version;
//	WM_Bat_READ_FW_TYPE    Drv_Status; 	
  	int				Drv_Status;
 }WM_Bat_READ_FW_INFO_CNF_T;
 
typedef struct{	
	unsigned char   	BQ27500_SOC_Threshold;        //0xFFFF  
	unsigned char		BQ27500_SOC_ClearThreshold;
 	
	//WM_Bat_READ_FW_TYPE    	Drv_Status; 
	int				Drv_Status;
}WM_Bat_READ_SOC_CNF_T;
 
typedef struct{	    
 	//WM_Bat_READ_FW_TYPE    	Drv_Status; 
	int				Drv_Status;
}WM_Bat_WRITE_SOC_CNF_T;

//GPS module
typedef struct{
	unsigned int	len;
	unsigned char	buff[1024];
}GPS_CMD; 

typedef struct {
	unsigned int	len;
	unsigned char	buff[1024];
}GPS_ACK_BUF;

//GPS callback
typedef void (__stdcall *META_GPS_SEND_COMMAND_CNF)(const GPS_ACK_BUF*cnf, const short token, void *usrData);

META_RESULT  __stdcall SP_META_GPS_Open(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_GPS_Open_r(const int meta_handle,unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_GPS_Close(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_GPS_Close_r(const int meta_handle,unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_GPS_SendCommand(unsigned int ms_timeout,const GPS_CMD *req, GPS_ACK_BUF *cnf,META_GPS_SEND_COMMAND_CNF cb);
META_RESULT  __stdcall SP_META_GPS_SendCommand_r(const int meta_handle,unsigned int ms_timeout,const GPS_CMD *req, GPS_ACK_BUF *cnf,META_GPS_SEND_COMMAND_CNF cb);
META_RESULT  __stdcall SP_META_GPS_SendCommandMultiThread(unsigned int ms_timeout,const GPS_CMD *req, GPS_ACK_BUF *cnf,META_GPS_SEND_COMMAND_CNF cb,void *usrData);
META_RESULT  __stdcall SP_META_GPS_SendCommandMultiThread_r(const int meta_handle,unsigned int ms_timeout,const GPS_CMD *req, GPS_ACK_BUF *cnf,META_GPS_SEND_COMMAND_CNF cb,void *usrData);




typedef struct
{
	unsigned int	dwSDHCIndex; // MSDC1/2/3. if dwSDHCIndex no equal 1/2/3 auto test.
}FT_SDCARD_REQ;

typedef struct
{
	unsigned char			DatBusWidth;
	int			IsSecuredMode;
	unsigned short	CardTpye;
	unsigned int	SizeOfProtectErea;
	unsigned char			SpeedClass;
	unsigned char			Performance_move;
	unsigned char			AUSize;
	unsigned char	status;
}FT_SDCARD_CNF;

META_RESULT  __stdcall SP_META_SDCARD_Query(unsigned int ms_timeout,const FT_SDCARD_REQ *req, FT_SDCARD_CNF *cnf);
META_RESULT  __stdcall SP_META_SDCARD_Query_r(const int meta_handle,unsigned int ms_timeout,const FT_SDCARD_REQ *req, FT_SDCARD_CNF *cnf);

typedef struct
{
	unsigned long	time_duration;
}LCDFt_REQ;

typedef struct
{
	int status;
}LCDFt_CNF;

META_RESULT __stdcall SP_META_LcdColorTest(unsigned int ms_timeout, LCDFt_REQ *req, LCDFt_CNF *cnf);
META_RESULT __stdcall SP_META_LcdColorTest_r(const int meta_handle, unsigned int ms_timeout, LCDFt_REQ *req, LCDFt_CNF *cnf);

//Low Power
typedef enum
{
	WM_CMD_POWER_DOWN =0, 
	WM_CMD_POWER_UP,
}WM_LOW_POWER_TYPE;

META_RESULT __stdcall SP_META_LowPowerTest(unsigned int ms_timeout, WM_LOW_POWER_TYPE *ptype /*in & out*/);
META_RESULT __stdcall SP_META_LowPowerTest_r(int meta_handle, unsigned int ms_timeout, WM_LOW_POWER_TYPE *ptype /*in & out*/);


META_RESULT __stdcall SP_META_ReadUuid(unsigned int ms_timeout, unsigned int *high, unsigned int *low);
META_RESULT __stdcall SP_META_ReadUuid_r(int meta_handle, unsigned int ms_timeout, unsigned int *high, unsigned int *low);

META_RESULT __stdcall SP_META_WriteUuid(unsigned int ms_timeout, unsigned int high, unsigned int low);
META_RESULT __stdcall SP_META_WriteUuid_r(int meta_handle, unsigned int ms_timeout, unsigned int high, unsigned int low);




/*
typedef enum
{
    HW_GPIO0 = 0,
	HW_GPIO1,
	HW_GPIO2,
	...
	HW_GPIO146,
	HW_GPIO_MAX,
}HW_GPIO;          //pin number
*/
typedef enum
{
	GET_MODE_STA = 0,
	SET_MODE_0,  // 00
	SET_MODE_1,  // 01
	SET_MODE_2,  // 10
	SET_MODE_3,  // 11

	GET_DIR_STA, 
	SET_DIR_IN,  // 0
	SET_DIR_OUT, // 1
	
	GET_PULLEN_STA,  
	SET_PULLEN_DISABLE,  // 0
	SET_PULLEN_ENABLE,   // 1
	
	GET_PULL_STA,
	SET_PULL_DOWN,  // 0
	SET_PULL_UP,    // 1
	
	GET_INV_STA,
	SET_INV_ENABLE,  // 1
	SET_INV_DISABLE, // 0
	
	GET_DATA_IN,
	GET_DATA_OUT,
	SET_DATA_LOW,  // 0
	SET_DATA_HIGH, // 1

	SET_MODE_4,
	SET_MODE_5,
	SET_MODE_6,
	SET_MODE_7,


}GPIO_OP;

typedef struct
{
	unsigned int	pin;	// pin number
	GPIO_OP	op;		// operation to GPIO	
}GPIO_REQ;

typedef struct
{
	unsigned int	status;
	unsigned long	data;
}GPIO_CNF;

META_RESULT __stdcall SP_META_GpioCtrl(unsigned int ms_timeout, const GPIO_REQ *req, GPIO_CNF *cnf);
META_RESULT __stdcall SP_META_GpioCtrl_r(int meta_handle, unsigned int ms_timeout, const GPIO_REQ *req, GPIO_CNF *cnf);


META_RESULT __stdcall SP_META_Nvram_Backup(unsigned int ms_timeout, const char *file1, const char *file2);
META_RESULT __stdcall SP_META_Nvram_Backup_r(int meta_handle, unsigned int ms_timeout, const char *file1, const char *file2);
META_RESULT __stdcall SP_META_Nvram_Backup_YUSU(unsigned int ms_timeout, const char *file);
META_RESULT __stdcall SP_META_Nvram_Backup_YUSU_r(int meta_handle, unsigned int ms_timeout, const char *file);

META_RESULT __stdcall SP_META_Nvram_Restore(unsigned int ms_timeout, const char *file1, const char *file2);
META_RESULT __stdcall SP_META_Nvram_Restore_r(int meta_handle, unsigned int ms_timeout, const char *file1, const char *file2);
META_RESULT __stdcall SP_META_Nvram_Restore_YUSU(unsigned int ms_timeout, const char *file);
META_RESULT __stdcall SP_META_Nvram_Restore_YUSU_r(int meta_handle, unsigned int ms_timeout, const char *file);

META_RESULT __stdcall SP_META_Clean_Boot(unsigned int ms_timeout);
META_RESULT __stdcall SP_META_Clean_Boot_r(int meta_handle,unsigned int ms_timeout);

META_RESULT __stdcall SP_META_Mode_Lock(unsigned int ms_timeout);
META_RESULT __stdcall SP_META_Mode_Lock_r(int meta_handle,unsigned int ms_timeout);

typedef struct
{
	char mldrVersion[50];
	char ebootVersion[50];
	char flashVersion[50];
	unsigned short mldrCheckSum;
	unsigned short ebootCheckSum;
	unsigned short flashCheckSum;
	unsigned char status;
}FT_BTLDR_FLASH_VER_CNF;

META_RESULT __stdcall SP_META_Btldr_Flash_Ver(unsigned int ms_timeout, FT_BTLDR_FLASH_VER_CNF *cnf);
META_RESULT __stdcall SP_META_Btldr_Flash_Ver_r(int meta_handle, unsigned int ms_timeout, FT_BTLDR_FLASH_VER_CNF *cnf);


META_RESULT __stdcall SP_META_Nvram2Bin(unsigned int ms_timeout);
META_RESULT __stdcall SP_META_Nvram2Bin_r(int meta_handle, unsigned int ms_timeout);




#define MD_FRAME_MAX_LEN 256

typedef struct
{
    short	frame_length;
    char	frame_data[MD_FRAME_MAX_LEN]; 
}MD_FRAME;

typedef struct _AUDIO_VOLUME_CUSTOM_STRUCT
{
	unsigned char audiovolume_ring[3][7];
	unsigned char audiovolume_key[3][7];
	unsigned char audiovolume_mic[3][7];
	unsigned char audiovolume_fmr[3][7];
	unsigned char audiovolume_sph[3][7];
	unsigned char audiovolume_sid[3][7];
	unsigned char audiovolume_media[3][7];
	unsigned char audiovolume_matv[3][7];
} AUDIO_VOLUME_CUSTOM_STRUCT;

typedef struct 
{
	short speech_input_FIR_coeffs[8][45];
	short speech_output_FIR_coeffs[8][6][45];
	short select_FIR_output_index[8];
	short select_FIR_intput_index[8];
	short speech_mode_para[8][16];
	
}AUDIO_PARAM_MED_STRUCT;

typedef struct
{
	unsigned short speech_mode_wb_para[8][16];
	short sph_wb_in_fir[6][90];
	short sph_wb_out_fir[6][90];
	
}AUDIO_CUSTOM_WB_PARAM_STRUCT;

META_RESULT __stdcall SP_META_SwitchUsbChnl(int enter, const WM_META_ConnectInMETA_Req *req, int *p_bootstop, WM_META_ConnectInMETA_Report *p_report);
META_RESULT __stdcall SP_META_SwitchUsbChnl_r(int meta_handle, int enter, const WM_META_ConnectInMETA_Req *req, int *p_bootstop, WM_META_ConnectInMETA_Report *p_report);

META_RESULT  __stdcall SP_META_NVRAM_Compose_AudioVlomeCustomStruct(AUDIO_VOLUME_CUSTOM_STRUCT *param, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_AudioVlomeCustomStruct(AUDIO_VOLUME_CUSTOM_STRUCT *param, const char *buf, const int buf_len);

META_RESULT  __stdcall SP_META_NVRAM_Compose_AudioMedStruct(AUDIO_PARAM_MED_STRUCT *param, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_AudioMedStruct(AUDIO_PARAM_MED_STRUCT *param, const char *buf, const int buf_len);

META_RESULT  __stdcall SP_META_NVRAM_Compose_AudioCustomWBStruct(AUDIO_CUSTOM_WB_PARAM_STRUCT *param, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_AudioCustomWBStruct(AUDIO_CUSTOM_WB_PARAM_STRUCT *param, const char *buf, const int buf_len);


META_RESULT __stdcall SP_META_Nvram_Backup_Custom(unsigned int ms_timeout, 
													const char *file1, const char *file2,const char * buffer,  int count, int mode );

META_RESULT __stdcall SP_META_Nvram_Backup_Custom_r(int meta_handle, unsigned int ms_timeout, 
										const char *file1, const char *file2,const char * buffer,  int count, int mode );

META_RESULT  __stdcall SP_META_Audio_Set_Echo_Loop2(unsigned int  ms_timeout,const Audio_Set_Echo_Req  *req);
META_RESULT  __stdcall SP_META_Audio_Set_Echo_Loop2_r(const int meta_handle,unsigned int  ms_timeout ,const Audio_Set_Echo_Req  *req);


META_RESULT __stdcall SP_META_Customer_Func(int ms_timeout, const unsigned char *data_in, const int data_in_len, int type, unsigned char dummy_in , unsigned char *dummy_out, unsigned char *data_out, int *data_out_len);
META_RESULT __stdcall SP_META_Customer_Func_r(int meta_handle, int ms_timeout, const unsigned char *data_in, const int data_in_len, int type, unsigned char dummy_in, unsigned char *dummy_out,unsigned char *data_out, int *data_out_len);

META_RESULT  __stdcall SP_META_GetChipID(unsigned int  ms_timeout, unsigned char* ChipID);
META_RESULT  __stdcall SP_META_GetChipID_r(const int meta_handle, unsigned int  ms_timeout, unsigned char* ChipID);

META_RESULT  __stdcall SP_META_MSensorTest(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_MSensorTest_r(const int meta_handle, unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_CTPTest(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_CTPTest_r(const int meta_handle, unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_ALSPSTest(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_ALSPSTest_r(const int meta_handle, unsigned int  ms_timeout);




//CMMB

#define MAX_CHANNEL_INFO_NUM    36
#define MAX_SERVICE_NUM   40

typedef struct
{
	int channel;
	int freq;
	
} CMMB_CHANNEL_INFO_S;

typedef struct
{
    int flag;              /*  flag = 0 means continuous confirm  */
                               /*  flag = 1 means all confirms have been received  */
    unsigned int    num;
    CMMB_CHANNEL_INFO_S    chInfo[MAX_CHANNEL_INFO_NUM];
    
} CMMB_CHANNEL_LIST_S;

typedef struct
{
    int flag;              /*  flag = 0 means continuous confirm  */
                               /*  flag = 1 means all confirms have been received  */
    unsigned int    num;
    int    servID[MAX_SERVICE_NUM];
    
} CMMB_SERVICE_LIST_S;

typedef struct
{
    int servID;
    char szMfsFile[260];
    
} CMMB_START_SERV_PARAM_S;

typedef struct
{
    int SNR;
    int PRE_BER;
    int RSSI;
    
} CMMB_PROPS_S;

META_RESULT  __stdcall SP_META_CMMB_Init(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_CMMB_Init_r(const int meta_handle, unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_CMMB_Term(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_CMMB_Term_r(const int meta_handle, unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_CMMB_AutoScan(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_CMMB_AutoScan_r(const int meta_handle, unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_CMMB_CancelScan(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_CMMB_CancelScan_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_CMMB_SetChannel(unsigned int  ms_timeout, int channel);
META_RESULT  __stdcall SP_META_CMMB_SetChannel_r(const int meta_handle, unsigned int  ms_timeout, int channel);
META_RESULT  __stdcall SP_META_CMMB_ListServices(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_CMMB_ListServices_r(const int meta_handle, unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_CMMB_StartService(unsigned int  ms_timeout, CMMB_START_SERV_PARAM_S * servParam);
META_RESULT  __stdcall SP_META_CMMB_StartService_r(const int meta_handle, unsigned int  ms_timeout, CMMB_START_SERV_PARAM_S * servParam);
META_RESULT  __stdcall SP_META_CMMB_StopService(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_CMMB_StopService_r(const int meta_handle, unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_CMMB_GetProp(unsigned int  ms_timeout, CMMB_PROPS_S * prop);
META_RESULT  __stdcall SP_META_CMMB_GetProp_r(const int meta_handle, unsigned int  ms_timeout, CMMB_PROPS_S * prop);

META_RESULT  __stdcall SP_META_CMMB_QueryChannelList(CMMB_CHANNEL_LIST_S * chList);
META_RESULT  __stdcall SP_META_CMMB_QueryChannelList_r(const int meta_handle, CMMB_CHANNEL_LIST_S * chList);
META_RESULT  __stdcall SP_META_CMMB_QueryServiceList(CMMB_SERVICE_LIST_S * servList);
META_RESULT  __stdcall SP_META_CMMB_QueryServiceList_r(const int meta_handle, CMMB_SERVICE_LIST_S * servList);




//-----------------------------------------------------//
//-----------------------NFC--------------------------//
//-----------------------------------------------------//

#define MIFARE4K_LEN        (16)
#define MIFARE1K_LEN        (4)
#define MIFARE1K_PAGE       (4)
#define UID_DATA_LEN        (7)
#define NDEF_DATA_LEN       (256)
#define RAW_COMM_DATA_LEN   (256) 
#define TAG_RAW_DATA_LEN    (256) 
#define TAG_WRITE_MAXDATA   (512)
#define UID_LEN             (10)
#define PNFC_DATA			(256)
#define VERSION_MW			(20)
#define URL_DATA			(64)
#define MTK_NFC_MAX_SE_NUM	(3)

//  NFC: REQ/CNF structure definition
typedef struct 
{
    unsigned int    nfc_enable;               /* feature enable or disable , 0: disable, 1:enable */
    unsigned int    debug_enable;        /*debug enable or disable , 0: disable, 1:enable */  
    unsigned int    sw_protocol;           /*SW protocol,  0: SW stack, 1: raw data mode */ 
    unsigned int     get_capabilities;      /*get chip capability 0: no request, 1: request*/

} NFC_SETTING_REQ_S;


typedef struct
{  
    unsigned int    status;                        /* return setting result*/  
    unsigned int    nfc_enable;               /* return feature enable or disable */  
    unsigned int    debug_enable;        /* return debug enable or disable*/  
    unsigned int    sw_protocol;           /* return SW protocol,*/  
    unsigned int    get_capabilities;      /* return chip capability*/       
    unsigned int    sw_ver;                      /* return software version*/   
    unsigned int    hw_ver;                     /* return hardware version*/  
    unsigned int    fw_ver;                       /* return firmware version*/  
    unsigned int    reader_mode;          /* return support  format bitmap*/  
    unsigned int    card_mode;              /* return support  format bitmap */

} NFC_SETTING_CNF_S;


typedef struct
{  
    unsigned int    reg_type;               /* register notification bitmap */       
    
} NFC_REGNOTIFY_REQ_S;

// Nina modified
typedef struct
{  
    unsigned int     status;          /* return setting result,0 success, other: fail*/  
	
    unsigned int     se;                /* secure element detect, 0: no detect, 1: se typ1 , 2: se type 2*/  
    unsigned int     se_status; /* secure element status, 0:off, 1:Virtual, 2:Wired*/  
    unsigned int     se_type;      /* secure element type, bitmap*/  
    unsigned int     length; /* length of data*/
    
} NFC_REGNOTIFY_CNF_S;


typedef struct
{  
    unsigned int     set_SEtype;      /* setting se  type, 0:off, 1:Virtual, 2:Wired */
    
} NFC_SECURE_REQ_S;

// Nina add 
typedef struct
{  
     unsigned int     status;          /* return setting result, 0:sucess*/
    
} NFC_SECURE_CNF_S;

typedef struct 
{  
    unsigned int    tag_type;               /* return detected tag type*/  
    unsigned int    card_type;            /* card type, 1: Mifare classic 1K*/                                                              
                                                             /* 2: Mifare classic 4K*/                                                              
                                                             /* 3: NDEF*/  
    unsigned int    uid;                        /* card Uid*/  
    unsigned int    sak;                       /* card sak*/               
    unsigned int    atag;                    /* card atag*/  
    unsigned int    appdata;             /* card appdata */  
    unsigned int    maxdatarate;    /* card maxdatarate */

} NFC_TAG_INFO_S;


typedef struct 
{  
    unsigned int    p2p_type;               /* return detected tag type*/

} NFC_P2P_INFO_S;


typedef union
{  
    NFC_TAG_INFO_S    nfc_tag_info;  
    NFC_P2P_INFO_S    nfc_p2p_info;  

} NFC_DEVICE_INFO_U;


typedef struct 
{  
    unsigned int     status;          /* return setting result, 0:sucess */  
    unsigned char    type;           /*1 : Tag ,2: p2p */  
    NFC_DEVICE_INFO_U    nfc_device_info;
    
} NFC_DISCOVERY_CNF_S;

typedef struct 
{
  unsigned int    dis_type;               /* discovery notification bitmap */
  unsigned int duration;                 /* set duration,(unit:ms) */   
    
} NFC_DISCOVERY_REQ_S;


typedef struct
{  
    unsigned int    address;               /*  */  
    unsigned short  data[MIFARE1K_LEN];

} NFC_MIFARE1K_DATA_S;


typedef struct
{  
    unsigned int    sector;               /*  */  
    unsigned int    block;  
    unsigned short data[MIFARE4K_LEN];

} NFC_MIFARE4K_DATA_S;


typedef struct
{  
    unsigned  int  ndef_type;  
    unsigned  int  length;        
    unsigned short data[NDEF_DATA_LEN];

} NFC_NDEF_DATA_S;


typedef union
{   
    NFC_MIFARE1K_DATA_S    nfc_Mifare1K_data;   
    NFC_MIFARE4K_DATA_S    nfc_Mifare4K_data;   
    NFC_NDEF_DATA_S    nfc_ndef_data;

} NFC_RW_DATA_U;


typedef struct 
{  
    unsigned int    read_type;               /*  which type want to read*/  
                                                                /* 1 for Mifare classic 1K */                                                                  
                                                                /* 2 for Mifare classic 4K */                                                                  
                                                                /* 3 for NDEF type*/  
    unsigned int    address;                  /* for Mifare classic 1K used*/  
    unsigned int    sector;                    /* for Mifare classic 4K used*/  
    unsigned int    block;                     /* for Mifare classic 4K used*/
	unsigned char   AuthentificationKey;       /* KEY_A:0 , KEY_B:1 */

} NFC_TAGREAD_REQ_S;


typedef struct 
{  
    unsigned int    status;               /*  return read status, 0 success*/  
    unsigned int    type;                 /*1 : Mifare classic 1K ,2: Mifare classic 4K, 3: NDEF */  
    NFC_RW_DATA_U    nfc_read_data;
    
} NFC_TAGREAD_CNF_S;

typedef struct 
{  
    unsigned int    write_type;               /*  which type want to write*/  
    NFC_RW_DATA_U    nfc_write_data;

} NFC_TAGWRITE_REQ_S;

//Nina add
typedef enum {
    nfc_tag_DEFAULT    = 0,
    nfc_tag_MIFARE_UL  = 1,
    nfc_tag_MIFARE_STD = 2,
    nfc_tag_ISO1443_4A = 3,
    nfc_tag_ISO1443_4B = 4,
    nfc_tag_JEWWL      = 5,
    nfc_tag_NFC        = 6,
    nfc_tag_FELICA     = 7,
    nfc_tag_ISO15693   = 8,
	nfc_NDEF           = 9
}NFC_TAG_TYPE;


//Nina modify
typedef struct 
{  
    unsigned int    status;                /*  return read status, 0 success*/                 
    unsigned int    wrtie_type;      /*  return writed type*/
	//NFC_TAG_TYPE	 wrtie_type;   
    
} NFC_TAGWRITE_CNF_S;

typedef struct 
{  
    unsigned int    action;     /* 1: disconnect, */
    
} NFC_TAGDISCONNECT_REQ_S;

// Nina add
typedef struct
{
	unsigned int    status;      /*0: success*/

}NFC_TAGDISCONNECT_CNF_S;

typedef struct 
{  
    unsigned int    action;      /* 1: format to Ndef, */
    
} NFC_TAGFORMAT2NDEF_REQ_S;

// Nina add
typedef struct 
{  
   unsigned int    status;      /*0: success*/
    
} NFC_TAGFORMAT2NDEF_CNF_S;


typedef struct
{
  unsigned int   length;
  unsigned char data[TAG_RAW_DATA_LEN];
} NFC_TAGRAWCOM_REQ_typeA;

typedef struct 
{
  unsigned int   length;
  unsigned char data[TAG_RAW_DATA_LEN];
} NFC_TAGRAWCOM_REQ_typeB;

typedef struct 
{
  unsigned int   length;
  unsigned char  data[TAG_RAW_DATA_LEN];
}NFC_TAGRAWCOM_REQ_typeJewel;

typedef struct 
{
  unsigned int   length;
  unsigned char  data[TAG_RAW_DATA_LEN];
}NFC_TAGRAWCOM_REQ_typeFelica;

typedef union 
{
  NFC_TAGRAWCOM_REQ_typeA  req_data_typeA;
  NFC_TAGRAWCOM_REQ_typeB  req_data_typeB;
  NFC_TAGRAWCOM_REQ_typeJewel req_data_typeJewel;
  NFC_TAGRAWCOM_REQ_typeFelica req_data_typeFelica;

} NFC_TAGRAWCOM_REQ_DATA_U;

typedef struct 
{  
    unsigned int    action;     /*1: enable raw command */  
    unsigned int    length;     /*Length of written data. Unit is byte. The data is stored in the Meta peer buffer*/

	// Nina add
	NFC_TAGRAWCOM_REQ_DATA_U req_data;   
    
} NFC_TAGRAWCOMM_REQ_S;


typedef struct
{
  unsigned int   length;
  unsigned char data[TAG_RAW_DATA_LEN];

} NFC_TAGRAWCOM_CNF_typeA;

typedef struct
{
  unsigned int   length;
  unsigned char data[TAG_RAW_DATA_LEN];

} NFC_TAGRAWCOM_CNF_typeB;

typedef struct
{
  unsigned int   length;
  unsigned char  data[TAG_RAW_DATA_LEN];

}NFC_TAGRAWCOM_CNF_typeJewel;

typedef struct 
{
  unsigned int   length;
  unsigned char  data[TAG_RAW_DATA_LEN];

}NFC_TAGRAWCOM_CNF_typeFelica;


typedef union 
{
  NFC_TAGRAWCOM_CNF_typeA  rsp_data_typeA;
  NFC_TAGRAWCOM_CNF_typeB  rsp_data_typeB;
  NFC_TAGRAWCOM_CNF_typeJewel  rsp_data_typeJewel;
  NFC_TAGRAWCOM_CNF_typeFelica rsp_data_typeFelica;

} NFC_TAGRAWCOM_CNF_DATA_U;


// Nina add
typedef struct 
{
  //NFC_TAG_TYPE    type;        /*Type A / Type B*/
  unsigned int    type;
  unsigned int    status;      /*0 : success*/
  NFC_TAGRAWCOM_CNF_DATA_U   rsp_data;
} NFC_TAGRAWCOMM_CNF_S;

typedef struct 
{  
    unsigned int    action;      /* 1 : send, 2 receive*/  
    unsigned int    length;      /*Length of written data. Unit is byte. The data is stored in the Meta peer buffer*/

} NFC_P2PCOMM_REQ_S;

// Nina add
typedef struct 
{  
   unsigned int    status;   /* 0:success*/
   unsigned int    length;   /*Length of written data. Unit is byte.*/

} NFC_P2PCOMM_CNF_S;

typedef struct 
{  
    unsigned int    action;      /*1:start test, 0:stop test*/  
    unsigned int    length;      /*Length of written data. Unit is byte. The data is stored in the Meta peer buffer*/
    
} NFC_RDCOMM_REQ_S;

//Nina add
typedef struct 
{  
     unsigned int    status;   /*Test result, 0:success*/
	unsigned int    length;   /*Length of written data. Unit is byte.*/
    
} NFC_RDCOMM_CNF_S;

typedef struct 
{   
    unsigned int   type;           /*Test type: currently, always set 1*/   
    unsigned int   action;	      /*Test action, 1: start test, 0:stop test*/   
    
} NFC_SCRIPT_REQ_S;

typedef struct 
{   
    signed int   result;         /*Test result,0 :success*/

} NFC_SCRIPT_CNF_S;

typedef struct { 
	unsigned int   type;    /*Test type: currently, always set 1*/
	unsigned int   action;	/*Test action, 1: start test, 0:stop test*/  
	unsigned char  modulation_type;   /* 0:type A, 1:type B, 2:type F, 3:No Modulation */
	unsigned char  bitrate;           /* 0:106kbps, 1:212kbps, 2:424kbps */ 
} NFC_TXALWAYS_REQ_S;


typedef struct { 
	unsigned int   type;           /*Test type: currently, always set 1*/
	unsigned int   action;	       /*Test action, 1: start test, 0:stop test*/  
	unsigned short  technology;    /*bitmask: MifareUL=bit 0, MifareStd=bit1, ISO14443_4A=bit 2, ISO14443_4B=bit 3, Jewel=bit 4, Felica=bit 5, ISO15693=bit 6 */
	unsigned short  protocols;     /*bitmask: Iso14443A=bit 0, Iso14443B=bit 1, Felica212=bit 2, Felica424=bit 3, Iso15693=bit 4 */ 
} NFC_CARDEMULATION_REQ_S;

typedef struct 
{   
    unsigned int   type;                /*Test type: currently, always set 1*/   
    unsigned int   action;	      /*Test action, 1: start test, 0:stop test*/   
    unsigned int   uid_type;        /* 1: uid 4bytes, 2 : uid 7bytes*/       
    unsigned short data[UID_DATA_LEN];       /*uid content*/
    
} NFC_SCRIPTUID_REQ_S;

typedef struct 
{   
    signed int   result;                 /*Test result, 0: success*/   
    unsigned int uid_type;         /* 1: uid 4bytes, 2 : uid 7bytes */	   
    unsigned short data[UID_DATA_LEN];      /*uid content*/
    
} NFC_SCRIPTUID_CNF_S;

typedef struct { 
	unsigned int   type;           
	unsigned int   action;	       
	unsigned short  technology;    
	unsigned short  protocols; 
} NFC_CARDMODETEST_REQ_S;

//Chunlan 2013-4-28

typedef enum {
    nfc_ndef_lang_DEFAULT = 0,
    nfc_ndef_lang_DE = 1,
    nfc_ndef_lang_EN = 2,
    nfc_ndef_lang_FR = 3
} NFC_NDEF_LANG_TYPE;

typedef enum {
    nfc_ndef_type_uri = 0,
    nfc_ndef_type_text,
    nfc_ndef_type_sp,
    nfc_ndef_type_others,
} NFC_NDEF_TYPE;

typedef struct {
    char   Name[64];
    char   Compagny[64];
    char   Titlep[64];
    char   Tel[32];
    char   Email[64];
    char   Adress[128];
    char   PostalCode[32];
    char   City[64];
    char   CompagnyUrl[64];
} Vcard;

typedef struct {
    unsigned char  Compagny[64];
    unsigned short CompagnyLength;
    unsigned char  CompagnyUrl[64];
    unsigned short CompagnyUrlLength;
} SmartPoster;

typedef struct {
    unsigned short DataLength;
    unsigned char  data[TAG_WRITE_MAXDATA];
} Text_S;

typedef struct {
    unsigned short URLLength;
    unsigned char  URLData[URL_DATA];
} URL_S;

typedef struct {
    char   EXTTagType[64];
    char   EXTData[TAG_WRITE_MAXDATA];
    unsigned short EXTLength;
} EXTTag;

typedef union {
//    SmartPoster  SP_Data;
//    Vcard        VC_Data;
    Text_S         TX_Data;
    URL_S          URL_Data;
//    EXTTag       EXT_Data;
} NFC_TAG_WRITE_NDEF_DATA;

typedef struct {
    unsigned int                    length;
//    NFC_NDEF_TYPE             ndef_type;
	unsigned int ndef_type;
//    NFC_NDEF_LANG_TYPE        language;
	unsigned int language;
    NFC_TAG_WRITE_NDEF_DATA   ndef_data;
} NFC_TAG_WRITE_NDEF;

typedef struct {
    unsigned int action;          /* Action, please refer ENUM of EM_ACTION*/
    unsigned int supporttype;     /* supporttype, please refer BITMAP of EM_ALS_READER_M_TYPE*/
    unsigned int typeA_datarate;  /* TypeA,datarate, please refer BITMAP of EM_ALS_READER_M_SPDRATE*/
    unsigned int typeB_datarate;  /* TypeB,datarate, please refer BITMAP of EM_ALS_READER_M_SPDRATE*/
    unsigned int typeV_datarate;  /* TypeV,datarate, please refer BITMAP of EM_ALS_READER_M_SPDRATE*/
    unsigned int typeF_datarate;  /* TypeF,datarate, please refer BITMAP of EM_ALS_READER_M_SPDRATE*/
    unsigned int typeV_subcarrier;/* 0: subcarrier, 1 :dual subcarrier*/
//	unsigned int typeV_codingmode;/*0:1 out of 4, 1: 1 out of 256*/
} NFC_EM_ALS_READERM_REQ_S;

typedef struct {
    int  result;          /* 0:Success,Tag connected, 1: Fail, 2:Tag disconnected*/
    unsigned int isNDEF;          /* 1:NDEF, 0: Non-NDEF*/
    unsigned int UidLen;
    unsigned char  Uid[32];
} NFC_EM_ALS_READERM_NTF_S;

typedef struct {
    int  result;          /* 0:Success, 1: Fail,*/
} NFC_EM_ALS_READERM_CNF_S;

typedef struct {
    int  action;          /* Action, please refer ENUM of EM_OPT_ACTION*/   
    NFC_TAG_WRITE_NDEF ndef_write;
} NFC_EM_ALS_READERM_OPT_REQ_S;

typedef struct {
	//   NFC_NDEF_TYPE ndef_type;
	unsigned int   length;
	unsigned int ndef_type;
	unsigned char  recordId[32];
	unsigned char  lang[3];
	unsigned char  recordFlags;
	unsigned char  recordTnf;
	unsigned char  data[512];
} NFC_TAG_READ_NDEF;

typedef struct {
    unsigned int  result;          /* 0:Success,1:Fail*/
    NFC_TAG_READ_NDEF ndef_read;
} NFC_EM_ALS_READERM_OPT_CNF_S;

/* --------------------------------------------------------*/
/* P2P_MODE_RELATED                                        */
/* --------------------------------------------------------*/
typedef struct {
    unsigned int action;          /* Action, please refer ENUM of EM_ACTION*/
    unsigned int supporttype;     /* supporttype, please refer BITMAP of EM_ALS_READER_M_TYPE*/
    unsigned int typeA_datarate;  /* TypeA,datarate, please refer BITMAP of EM_ALS_READER_M_SPDRATE*/
    unsigned int typeF_datarate;  /* TypeV,datarate, please refer BITMAP of EM_ALS_READER_M_SPDRATE*/
    unsigned int mode;            /* BITMAPS bit0: Passive mode, bit1: Active mode, please refer BITMAP of EM_P2P_MODE*/
    unsigned int role;            /* BITMAPS bit0: Initator, bit1: Target, please refer BITMAP of EM_P2P_ROLE*/
    unsigned int isDisableCardM;  /* 0: , 1: disable card mode*/
} NFC_EM_ALS_P2P_REQ_S;

typedef struct {
    int  link_status;     /* 1:llcp link is up,0:llcp link is down*/
    //UINT32  datalen;
    //UINT8 data[256];
} NFC_EM_ALS_P2P_NTF_S;

typedef struct {
    int  result;          /* 0:Success,1:Fail*/
} NFC_EM_ALS_P2P_CNF_S;

/* -------------------------------------------------------- */
/* CARD_MODE_RELATED                                        */
/* -------------------------------------------------------- */
typedef struct {
	
	unsigned int seid;
	unsigned int status;
	unsigned int type;
	unsigned int connecttype;
	unsigned int lowpowermode;
	unsigned int bpf;
	
} mtk_nfc_tool_se_info;

typedef struct {
	
	unsigned int status;
	mtk_nfc_tool_se_info SeInfor[MTK_NFC_MAX_SE_NUM];
	unsigned char SeCount;
	
} NFC_EM_SE_GET_LIST;


typedef struct {
    unsigned int action;          /* Action, please refer ENUM of EM_ACTION*/
    unsigned int SWNum;           /* SWNum, please refer BITMAP of EM_ALS_CARD_M_SW_NUM*/
    unsigned int supporttype;     /* supporttype, please refer BITMAP of EM_ALS_READER_M_TYPE*/
    unsigned int fgvirtualcard;   /* 1:enable virtual card, 0:disable virtual card(default)   */
} NFC_EM_ALS_CARDM_REQ_S;

typedef struct {
    int  result;          /*0:Success,1:Fail*/
} NFC_EM_ALS_CARDM_CNF_S;

/* -------------------------------------------------------- */
/* POLLING_MODE_RELATED                                     */
/* -------------------------------------------------------- */
typedef struct {
    unsigned int action;          /* Action, please refer ENUM of EM_ACTION*/
    unsigned int phase;           /* 0:Listen phase, 1:Pause phase*/
    unsigned int Period;
    unsigned int enablefunc;      /* enablefunc, please refer BITMAP of EM_ENABLE_FUNC*/
    NFC_EM_ALS_P2P_REQ_S     p2pM;
    NFC_EM_ALS_CARDM_REQ_S   cardM;
    NFC_EM_ALS_READERM_REQ_S readerM;
} NFC_EM_POLLING_REQ_S;

typedef struct {
    int  result;          /* 0:Success,1:Fail*/
} NFC_EM_POLLING_CNF_S;

typedef union {
    NFC_EM_ALS_P2P_NTF_S     p2p;
    NFC_EM_ALS_CARDM_CNF_S   card;
    NFC_EM_ALS_READERM_NTF_S reader;
} NFC_EM_POLLING_FUNC_NTF_S;

typedef struct {
    int detecttype;       /* enablefunc, please refer ENUM of EM_ENABLE_FUNC*/
    NFC_EM_POLLING_FUNC_NTF_S ntf;
} NFC_EM_POLLING_NTF_S;

/* -------------------------------------------------------- */
/* TX carrier signal                                        */
/* -------------------------------------------------------- */
typedef struct {
    unsigned int action;          /* Action, please refer ENUM of EM_ACTION*/
} NFC_EM_TX_CARR_ALS_ON_REQ_S;

typedef struct {
    unsigned int result;          /* 0:Success,1:Fail*/
} NFC_EM_TX_CARR_ALS_ON_CNF_S;

/* -------------------------------------------------------- */
/* CARD_MODE_RELATED                                        */
/* -------------------------------------------------------- */

typedef struct {
    unsigned int action;          /* Action, please refer ENUM of EM_ACTION*/
    unsigned int supporttype;     /* supporttype, please refer BITMAP of EM_ALS_READER_M_TYPE*/
    //UINT32 typeA_datarate;  /* TypeA,datarate, please refer BITMAP of EM_ALS_READER_M_SPDRATE*/
    //UINT32 typeB_datarate;  /* TypeB,datarate, please refer BITMAP of EM_ALS_READER_M_SPDRATE*/
    unsigned int typeF_datarate;  /* TypeF,datarate, please refer BITMAP of EM_ALS_READER_M_SPDRATE*/
} NFC_EM_VIRTUAL_CARD_REQ_S;

typedef struct {
    unsigned int result;          /* 0:Success,1:Fail*/
} NFC_EM_VIRTUAL_CARD_CNF_S;

/* --------------------------------------------------------*/
/* PNFC command                                            */
/* --------------------------------------------------------*/
typedef struct {
    unsigned int   action;          /* Action, please refer ENUM of EM_ACTION*/
    unsigned int   datalen;
    unsigned char  data[256];
} NFC_EM_PNFC_RAW_REQ_S;

typedef struct  
{
	NFC_EM_PNFC_RAW_REQ_S pnfc_req;
} NFC_EM_PNFC_REQ_S;

typedef struct {
    unsigned int result;          /* 0:Success,1:Fail*/
    unsigned int datalen;
    unsigned char  data[256];
} NFC_EM_PNFC_CNF_S;


/* --------------------------------------------------------*/
/* Version                                                 */
/* --------------------------------------------------------*/

typedef struct {
    unsigned short fw_ver;
    unsigned short hw_ver;
    char   mw_ver[VERSION_MW];
} NFC_SW_VERSION_CNF_S;

/* --------------------------------------------------------*/
/* HW Test Tool Version                                                 */
/* --------------------------------------------------------*/

typedef struct {
	unsigned int version;
} NFC_META_CHIP_VER_CNF_S;

/* --------------------------------------------------------*/
/* Option setting                                          */
/* --------------------------------------------------------*/
typedef struct
{
    unsigned short   forceDownLoad; 
    unsigned short   TagAutoPresenceChk; 
} NFC_TEST_MODE_SETTING_REQ_S;

typedef struct
{
    int result;
} NFC_TEST_MODE_SETTING_CNF_S;

/* --------------------------------------------------------*/
/* Loopback set                                            */
/* --------------------------------------------------------*/
typedef struct
{
    char   action;
} NFC_LOOPBACK_TEST_REQ_S;

typedef struct
{
    int result;
} NFC_LOOPBACK_TEST_CNF_S;

/* --------------------------------------------------------*/
/* SWP Test                                                */
/* --------------------------------------------------------*/
typedef struct { 
    int  action;
	int  SEmap;
} NFC_FM_SWP_TEST_REQ_S;

typedef struct {
	int result;
} NFC_FM_SWP_TEST_CNF_S;
//  NFC: Callback function definition
//typedef void (__stdcall * NFC_DISCOVERY_CB)(const NFC_DISCOVERY_CNF * pDisCnf, const short token, void *usrData);

typedef void (__stdcall *META_NFC_NOTIFY_CNF)(const NFC_EM_ALS_READERM_NTF_S *cnf);
typedef void (__stdcall *META_NFC_P2P_NOTIRY)(const NFC_EM_ALS_P2P_NTF_S *p2p_cnf);
typedef void (__stdcall *META_NFC_POOLINGLOOP_NOTIFY)(const NFC_EM_POLLING_NTF_S *pooling_loop_cnf);

//  NFC: API declaration
META_RESULT  __stdcall SP_META_NFC_Setting(unsigned int  ms_timeout, NFC_SETTING_REQ_S * pSetReq, NFC_SETTING_CNF_S * pSetCnf);
META_RESULT  __stdcall SP_META_NFC_Setting_r(const int meta_handle, unsigned int  ms_timeout, NFC_SETTING_REQ_S * pSetReq, NFC_SETTING_CNF_S * pSetCnf);
META_RESULT  __stdcall SP_META_NFC_RegNotify(unsigned int  ms_timeout, NFC_REGNOTIFY_REQ_S * pRegReq, NFC_REGNOTIFY_CNF_S * pRegCnf);
META_RESULT  __stdcall SP_META_NFC_RegNotify_r(const int meta_handle, unsigned int  ms_timeout, NFC_REGNOTIFY_REQ_S * pRegReq, NFC_REGNOTIFY_CNF_S * pRegCnf);
//META_RESULT  __stdcall SP_META_NFC_SecureElement(unsigned int  ms_timeout, NFC_SECURE_REQ_S * pSecReq);
//META_RESULT  __stdcall SP_META_NFC_SecureElement_r(const int meta_handle, unsigned int  ms_timeout, NFC_SECURE_REQ_S * pSecReq);
META_RESULT  __stdcall SP_META_NFC_SecureElement(unsigned int  ms_timeout, NFC_SECURE_REQ_S * pSecReq , NFC_SECURE_CNF_S * pSecCnf);
META_RESULT  __stdcall SP_META_NFC_SecureElement_r(const int meta_handle, unsigned int  ms_timeout, NFC_SECURE_REQ_S * pSecReq ,NFC_SECURE_CNF_S * pSecCnf);
//META_RESULT  __stdcall SP_META_NFC_Discovery(unsigned int  ms_timeout, const NFC_DISCOVERY_CB cb, short *token, void *usrData);
//META_RESULT  __stdcall SP_META_NFC_Discovery_r(const int meta_handle, unsigned int  ms_timeout, const NFC_DISCOVERY_CB cb, short *token, void *usrData);
//META_RESULT  __stdcall SP_META_NFC_Discovery(unsigned int  ms_timeout, NFC_DISCOVERY_REQ * pDisReq, const NFC_DISCOVERY_CB cb, short *token, void *usrData);
//META_RESULT  __stdcall SP_META_NFC_Discovery_r(const int meta_handle, unsigned int  ms_timeout, NFC_DISCOVERY_REQ * pDisReq, const NFC_DISCOVERY_CB cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_NFC_Discovery(unsigned int  ms_timeout, NFC_DISCOVERY_REQ_S * pDisReq, NFC_DISCOVERY_CNF_S * pDisCnf);
META_RESULT  __stdcall SP_META_NFC_Discovery_r(const int meta_handle, unsigned int  ms_timeout, NFC_DISCOVERY_REQ_S * pDisReq, NFC_DISCOVERY_CNF_S * pDisCnf);
META_RESULT  __stdcall SP_META_NFC_TagRead(unsigned int  ms_timeout, NFC_TAGREAD_REQ_S * pTagReadReq, NFC_TAGREAD_CNF_S * pTagReadCnf);
META_RESULT  __stdcall SP_META_NFC_TagRead_r(const int meta_handle, unsigned int  ms_timeout, NFC_TAGREAD_REQ_S * pTagReadReq, NFC_TAGREAD_CNF_S * pTagReadCnf);
META_RESULT  __stdcall SP_META_NFC_TagWrite(unsigned int  ms_timeout, NFC_TAGWRITE_REQ_S * pTagWriteReq, NFC_TAGWRITE_CNF_S * pTagWriteCnf);
META_RESULT  __stdcall SP_META_NFC_TagWrite_r(const int meta_handle, unsigned int  ms_timeout, NFC_TAGWRITE_REQ_S * pTagWriteReq, NFC_TAGWRITE_CNF_S * pTagWriteCnf);
META_RESULT  __stdcall SP_META_NFC_TagDisconnect(unsigned int  ms_timeout, NFC_TAGDISCONNECT_REQ_S * pDisReq,NFC_TAGDISCONNECT_CNF_S * pDisCnf);
META_RESULT  __stdcall SP_META_NFC_TagDisconnect_r(const int meta_handle, unsigned int  ms_timeout, NFC_TAGDISCONNECT_REQ_S * pDisReq,NFC_TAGDISCONNECT_CNF_S * pDisCnf);
META_RESULT  __stdcall SP_META_NFC_TagFormatNDEF(unsigned int  ms_timeout, NFC_TAGFORMAT2NDEF_REQ_S * pFormatReq, NFC_TAGFORMAT2NDEF_CNF_S * pFormatCnf);
META_RESULT  __stdcall SP_META_NFC_TagFormatNDEF_r(const int meta_handle, unsigned int  ms_timeout, NFC_TAGFORMAT2NDEF_REQ_S * pFormatReq, NFC_TAGFORMAT2NDEF_CNF_S * pFormatCnf);
META_RESULT  __stdcall SP_META_NFC_TagRawComm(unsigned int  ms_timeout, NFC_TAGRAWCOMM_REQ_S * pRawReq , NFC_TAGRAWCOMM_CNF_S * pRawCnf);
META_RESULT  __stdcall SP_META_NFC_TagRawComm_r(const int meta_handle, unsigned int  ms_timeout, NFC_TAGRAWCOMM_REQ_S * pRawReq , NFC_TAGRAWCOMM_CNF_S * pRawCnf);
META_RESULT  __stdcall SP_META_NFC_P2PComm(unsigned int  ms_timeout, NFC_P2PCOMM_REQ_S * pP2PReq,NFC_P2PCOMM_CNF_S * pP2PCnf);
META_RESULT  __stdcall SP_META_NFC_P2PComm_r(const int meta_handle, unsigned int  ms_timeout, NFC_P2PCOMM_REQ_S * pP2PReq,NFC_P2PCOMM_CNF_S * pP2PCnf);
META_RESULT  __stdcall SP_META_NFC_RDComm(unsigned int  ms_timeout, NFC_RDCOMM_REQ_S * pRDReq,NFC_RDCOMM_CNF_S * pRDCnf);
META_RESULT  __stdcall SP_META_NFC_RDComm_r(const int meta_handle, unsigned int  ms_timeout, NFC_RDCOMM_REQ_S * pRDReq,NFC_RDCOMM_CNF_S * pRDCnf);
META_RESULT  __stdcall SP_META_NFC_TxAlwaysOn(unsigned int  ms_timeout, NFC_TXALWAYS_REQ_S * pScriptReq, NFC_SCRIPT_CNF_S * pScriptCnf);
META_RESULT  __stdcall SP_META_NFC_TxAlwaysOn_r(const int meta_handle, unsigned int  ms_timeout, NFC_TXALWAYS_REQ_S * pScriptReq, NFC_SCRIPT_CNF_S * pScriptCnf);
META_RESULT  __stdcall SP_META_NFC_TxAlwaysOnWOACK(unsigned int  ms_timeout, NFC_TXALWAYS_REQ_S * pScriptReq, NFC_SCRIPT_CNF_S * pScriptCnf);
META_RESULT  __stdcall SP_META_NFC_TxAlwaysOnWOACK_r(const int meta_handle, unsigned int  ms_timeout, NFC_TXALWAYS_REQ_S * pScriptReq, NFC_SCRIPT_CNF_S * pScriptCnf);
//META_RESULT  __stdcall SP_META_NFC_CardEmulationMode(unsigned int  ms_timeout, NFC_CARDEMULATION_REQ_S * pScriptReq, NFC_SCRIPT_CNF_S * pScriptCnf);
//META_RESULT  __stdcall SP_META_NFC_CardEmulationMode_r(const int meta_handle, unsigned int  ms_timeout, NFC_CARDEMULATION_REQ_S * pScriptReq, NFC_SCRIPT_CNF_S * pScriptCnf);
META_RESULT  __stdcall SP_META_NFC_ReaderModeTest(unsigned int  ms_timeout, NFC_SCRIPT_REQ_S * pScriptReq, NFC_SCRIPT_CNF_S * pScriptCnf);
META_RESULT  __stdcall SP_META_NFC_ReaderModeTest_r(const int meta_handle, unsigned int  ms_timeout, NFC_SCRIPT_REQ_S * pScriptReq, NFC_SCRIPT_CNF_S * pScriptCnf);
META_RESULT  __stdcall SP_META_NFC_P2PModeTest(unsigned int  ms_timeout, NFC_SCRIPT_REQ_S * pScriptReq, NFC_SCRIPT_CNF_S * pScriptCnf);
META_RESULT  __stdcall SP_META_NFC_P2PModeTest_r(const int meta_handle, unsigned int  ms_timeout, NFC_SCRIPT_REQ_S * pScriptReq, NFC_SCRIPT_CNF_S * pScriptCnf);
META_RESULT  __stdcall SP_META_NFC_SWPSelfTest(unsigned int  ms_timeout, NFC_SCRIPT_REQ_S * pScriptReq, NFC_SCRIPT_CNF_S * pScriptCnf);
META_RESULT  __stdcall SP_META_NFC_SWPSelfTest_r(const int meta_handle, unsigned int  ms_timeout, NFC_SCRIPT_REQ_S * pScriptReq, NFC_SCRIPT_CNF_S * pScriptCnf);
META_RESULT  __stdcall SP_META_NFC_AntennaSelfTest(unsigned int  ms_timeout, NFC_SCRIPT_REQ_S * pScriptReq, NFC_SCRIPT_CNF_S * pScriptCnf);
META_RESULT  __stdcall SP_META_NFC_AntennaSelfTest_r(const int meta_handle, unsigned int  ms_timeout, NFC_SCRIPT_REQ_S * pScriptReq, NFC_SCRIPT_CNF_S * pScriptCnf);
META_RESULT  __stdcall SP_META_NFC_TagUidRW(unsigned int  ms_timeout, NFC_SCRIPTUID_REQ_S * pUidReq, NFC_SCRIPTUID_CNF_S * pUidCnf);
META_RESULT  __stdcall SP_META_NFC_TagUidRW_r(const int meta_handle, unsigned int  ms_timeout, NFC_SCRIPTUID_REQ_S * pUidReq, NFC_SCRIPTUID_CNF_S * pUidCnf);
META_RESULT  __stdcall SP_META_NFC_CardModeTest(unsigned int  ms_timeout, NFC_CARDMODETEST_REQ_S * pCardModeReq, NFC_SCRIPT_CNF_S * pScriptCnf);
META_RESULT  __stdcall SP_META_NFC_CardModeTest_r(const int meta_handle, unsigned int  ms_timeout, NFC_CARDMODETEST_REQ_S * pCardModeReq, NFC_SCRIPT_CNF_S * pScriptCnf);
META_RESULT  __stdcall SP_META_NFC_Em_Als_Reader_Mode(unsigned int  ms_timeout, NFC_CARDMODETEST_REQ_S * pEmAlsReadermReq, NFC_EM_ALS_READERM_CNF_S * pEmAlsReadermCnf, META_NFC_NOTIFY_CNF nfc_c,int action);
META_RESULT  __stdcall SP_META_NFC_Em_Als_Reader_Mode_r(const int meta_handle, unsigned int  ms_timeout, NFC_EM_ALS_READERM_REQ_S * pEmAlsReadermReq, NFC_EM_ALS_READERM_CNF_S * pEmAlsReadermCnf, META_NFC_NOTIFY_CNF nfc_c,int action);
META_RESULT  __stdcall SP_META_NFC_Em_Als_Reader_Mode_OPT_r(const int meta_handle, unsigned int  ms_timeout, NFC_EM_ALS_READERM_OPT_REQ_S * pEmAlsReadermOptReq,NFC_EM_ALS_READERM_OPT_CNF_S * pEmAlsReadermOptCnf);
META_RESULT  __stdcall SP_META_NFC_Em_Als_Reader_Mode_OPT(unsigned int  ms_timeout, NFC_EM_ALS_READERM_OPT_REQ_S * pEmAlsReadermOptReq, NFC_EM_ALS_READERM_OPT_CNF_S * pEmAlsReadermOptCnf);
META_RESULT  __stdcall SP_META_NFC_Em_Als_P2P_Mode_r(const int meta_handle, unsigned int  ms_timeout, NFC_EM_ALS_P2P_REQ_S * pEmAlsP2PmReq, NFC_EM_ALS_P2P_CNF_S * pEmAlsP2PmCnf, META_NFC_P2P_NOTIRY nfc_cb);
META_RESULT  __stdcall SP_META_NFC_Em_Als_P2P_Mode(unsigned int  ms_timeout, NFC_EM_ALS_P2P_REQ_S * pEmAlsP2PmReq, NFC_EM_ALS_P2P_CNF_S * pEmAlsP2PmCnf, META_NFC_P2P_NOTIRY nfc_cb);
META_RESULT  __stdcall SP_META_NFC_CardMode_SetSE_r(const int meta_handle, unsigned int  ms_timeout, NFC_EM_SE_GET_LIST * pCardModeSetSECnf);
META_RESULT  __stdcall SP_META_NFC_CardMode_SetSE(unsigned int  ms_timeout, NFC_EM_SE_GET_LIST * pCardModeSetSECnf);
META_RESULT  __stdcall SP_META_NFC_CardMode_r(const int meta_handle, unsigned int  ms_timeout, NFC_EM_ALS_CARDM_REQ_S * pCardModeReq, NFC_EM_ALS_CARDM_CNF_S * pCardModeCnf);
META_RESULT  __stdcall SP_META_NFC_CardMode(unsigned int  ms_timeout,  NFC_EM_ALS_CARDM_REQ_S * pCardModeReq, NFC_EM_ALS_CARDM_CNF_S * pCardModeCnf);
META_RESULT  __stdcall SP_META_NFC_TX_Carrier_Signal_AlsOn_r(const int meta_handle, unsigned int  ms_timeout, NFC_EM_TX_CARR_ALS_ON_REQ_S * pTxCarrierAlsOnReq, NFC_EM_TX_CARR_ALS_ON_CNF_S * pTxCarrierAlsOnCnf);
META_RESULT  __stdcall SP_META_NFC_TX_Carrier_Signal_AlsOn(unsigned int  ms_timeout,  NFC_EM_TX_CARR_ALS_ON_REQ_S * pTxCarrierAlsOnReq, NFC_EM_TX_CARR_ALS_ON_CNF_S * pTxCarrierAlsOnCnf);
META_RESULT  __stdcall SP_META_NFC_Virtural_Card_Func_r(const int meta_handle, unsigned int  ms_timeout, NFC_EM_VIRTUAL_CARD_REQ_S * pVirtualCardFuncReq, NFC_EM_VIRTUAL_CARD_CNF_S * pVirtualCardFuncCnf);
META_RESULT  __stdcall SP_META_NFC_Virtural_Card_Func(unsigned int  ms_timeout,  NFC_EM_VIRTUAL_CARD_REQ_S * pVirtualCardFuncReq, NFC_EM_VIRTUAL_CARD_CNF_S * pVirtualCardFuncCnf);
META_RESULT  __stdcall SP_META_NFC_PNFC_COMMAND_r(const int meta_handle, unsigned int  ms_timeout, NFC_EM_PNFC_REQ_S * pPNFCCommandReq, NFC_EM_PNFC_CNF_S * pPNFCCommandCnf);
META_RESULT  __stdcall SP_META_NFC_PNFC_COMMAND(unsigned int  ms_timeout,  NFC_EM_PNFC_REQ_S * pPNFCCommandReq, NFC_EM_PNFC_CNF_S * pPNFCCommandCnf);
META_RESULT  __stdcall SP_META_NFC_VERSION_QUERY_r(const int meta_handle, unsigned int  ms_timeout, NFC_SW_VERSION_CNF_S * pVersionQueryCnf);
META_RESULT  __stdcall SP_META_NFC_VERSION_QUERY(unsigned int  ms_timeout, NFC_SW_VERSION_CNF_S * pVersionQueryCnf);
META_RESULT  __stdcall SP_META_NFC_Option_r(const int meta_handle, unsigned int  ms_timeout, NFC_TEST_MODE_SETTING_REQ_S * pOptionSettingReq, NFC_TEST_MODE_SETTING_CNF_S * pOptionSettingCnf);
META_RESULT  __stdcall SP_META_NFC_Option(unsigned int  ms_timeout,  NFC_TEST_MODE_SETTING_REQ_S * pOptionSettingReq, NFC_TEST_MODE_SETTING_CNF_S * pOptionSettingCnf);
META_RESULT  __stdcall SP_META_NFC_Loopback_Test_r(const int meta_handle, unsigned int  ms_timeout, NFC_LOOPBACK_TEST_REQ_S * pLoopbackTestReq, NFC_LOOPBACK_TEST_CNF_S * pLoopbackTestCnf);
META_RESULT  __stdcall SP_META_NFC_Loopback_Test(unsigned int  ms_timeout,  NFC_LOOPBACK_TEST_REQ_S * pLoopbackTestReq, NFC_LOOPBACK_TEST_CNF_S * pLoopbackTestCnf);
META_RESULT  __stdcall SP_META_NFC_SWP_Test_r(const int meta_handle, unsigned int  ms_timeout, NFC_FM_SWP_TEST_REQ_S * pSWPTestReq, NFC_FM_SWP_TEST_CNF_S * pSWPTestCnf);
META_RESULT  __stdcall SP_META_NFC_SWP_Test(unsigned int  ms_timeout,  NFC_FM_SWP_TEST_REQ_S * pSWPTestReq, NFC_FM_SWP_TEST_CNF_S * pSWPTestCnf);
META_RESULT  __stdcall SP_META_NFC_PollingLoopMode_r(const int meta_handle, unsigned int  ms_timeout, NFC_EM_POLLING_REQ_S * pPollingLoopModeReq, NFC_EM_POLLING_CNF_S * pPollingLoopModeCnf,META_NFC_POOLINGLOOP_NOTIFY poolingloopcb);
META_RESULT  __stdcall SP_META_NFC_PollingLoopMode(unsigned int  ms_timeout, NFC_EM_POLLING_REQ_S * pPollingLoopModeReq, NFC_EM_POLLING_CNF_S * pPollingLoopModeCnf, META_NFC_POOLINGLOOP_NOTIFY poolingloopcb);
META_RESULT  __stdcall SP_META_NFC_HW_Version_Test_r(const int meta_handle, unsigned int  ms_timeout, NFC_META_CHIP_VER_CNF_S * pHWVerTestCnf);
META_RESULT  __stdcall SP_META_NFC_HW_Version_Test(unsigned int  ms_timeout, NFC_META_CHIP_VER_CNF_S * pHWVerTestCnf);


// CCT

/*
typedef struct
{
	char sensor_prefix_name[64];
}CCT_Dual_Dev_ISP_camera_sensor_prefix_name_struct;

typedef struct
{
	char lens_prefix_name[64];
}CCT_Dual_Dev_ISP_camera_lens_prefix_name_struct; 
*/

//------------------------------------------------------------------------------
// Capture Related Functions                                                    
//------------------------------------------------------------------------------

typedef enum {
	CAMERA_SUB_SAMPLE_1_1 =	1,	// 1:1 
	CAMERA_SUB_SAMPLE_1_2 = 2,	// 1:2 
	CAMERA_SUB_SAMPLE_1_4 = 4,	// 1:4 
	CAMERA_SUB_SAMPLE_1_8 = 8	// 1:8 
} CAMERA_SUB_SAMPLE_MODE;

typedef enum {
	 OUTPUT_RAW_8BITS = 0
	,OUTPUT_YUV
	,OUTPUT_JPEG
	,OUTPUT_RGB888
	,OUTPUT_RAW_10BITS
	,OUTPUT_EXT_RAW_8BITS
	,OUTPUT_EXT_RAW_10BITS
	,OUTPUT_EXT_YUV
} CAMERA_OUTPUT_FORMAT;

typedef enum {
	BAYER_PTN_GR = 0,
	BAYER_PTN_R,
	BAYER_PTN_B,
	BAYER_PTN_GB
} CAMERA_BAYER_PATTERN;

typedef void (*CALLBACK_META_CCT_CAPTURE)(unsigned char finished_percentage, unsigned int received_bytes, unsigned int total_bytes, void *cb_arg);

typedef struct {
	// shot screen range (position in pixel) 
	unsigned short	nLeftPos;	// 0~N 
	unsigned short	nTopPos;	// 0~N 
	unsigned short	nWidth;
	unsigned short	nHeight;
} CCT_CaptureScreen_T;

typedef struct {

	// shot screen range (position in pixel) 
	CCT_CaptureScreen_T			ShotScreen;

	// RAW doesn't support subsample 
	CAMERA_SUB_SAMPLE_MODE		SubSample; 

	CAMERA_OUTPUT_FORMAT		OutputFormat;

	CALLBACK_META_CCT_CAPTURE	cb;
	void *cb_arg;

} CCT_Capture_Req;

typedef struct {

	// actual shot screen (position in pixel), the original shot screen might be truncated if out of range 
	CCT_CaptureScreen_T			ShotScreen;

	// the bayer pattern of left-top start pixel 
	CAMERA_BAYER_PATTERN		BayerPattern;

	// actual image data buffer 
	unsigned short	nOutputBuf_Width;
	unsigned short	nOutputBuf_Height;
	char 	*pOutputBuf;		// don't forget to free it by calling META_CCT_FreeCaptureImage 

	// NOTICE! buffer size will be applied different formulas according to output format 
	// For RAW 8BITS format, the size will be nOutputBuf_Width x nOutputBuf_Height bytes 
	// For RAW 10BITS format, the size will be nOutputBuf_Width x nOutputBuf_Height x 2 bytes 
	// For YUV format, the size will be nOutputBuf_Width x nOutputBuf_Height x 4 bytes 
	unsigned int	nOutputBuf_Size;

} CCT_Capture_Result;

typedef struct
{
    unsigned int packetNO;
    unsigned int isEnd; 
    unsigned int bufLength;
    unsigned char DebugBuf[2048];
} CCT_Strobe_DumpData;


META_RESULT __stdcall SP_META_CCT_PreviewOnLCD_Ex(bool bEnablePreview);
META_RESULT __stdcall SP_META_CCT_PreviewOnLCD_Ex_r(const int meta_handle, bool bEnablePreview);
META_RESULT __stdcall SP_META_CCT_SubPreviewOnLCD(bool bEnablePreview);
META_RESULT __stdcall SP_META_CCT_SubPreviewOnLCD_r(const int meta_handle, bool bEnablePreview);
META_RESULT __stdcall SP_META_CCT_PhotoFlashControl();
META_RESULT __stdcall SP_META_CCT_PhotoFlashControl_r(const int meta_handle);

META_RESULT __stdcall SP_META_CCT_Init(bool bEnableUSBCOM, unsigned int &sensorID);
META_RESULT __stdcall SP_META_CCT_Init_r(const int meta_handle, bool bEnableUSBCOM, unsigned int &sensorID);
META_RESULT __stdcall SP_META_CCT_SingleShotCaptureEx(unsigned int DeviceId, const CCT_Capture_Req  *req, CCT_Capture_Result  *p_result);
META_RESULT __stdcall SP_META_CCT_SingleShotCaptureEx_r(const int meta_handle, unsigned int DeviceId, const CCT_Capture_Req  *req, CCT_Capture_Result  *p_result);

META_RESULT __stdcall SP_META_CCT_StrobeCalibrationStart(unsigned int  ms_timeout);
META_RESULT __stdcall SP_META_CCT_StrobeCalibrationStart_r(const int meta_handle, unsigned int  ms_timeout);

META_RESULT __stdcall SP_META_CCT_StrobeGetCalibrationStatus(unsigned int  ms_timeout, unsigned int *cali_status);//out: cali_status //0: End_Success 1:End_Fail 2: Going
META_RESULT __stdcall SP_META_CCT_StrobeGetCalibrationStatus_r(const int meta_handle, unsigned int  ms_timeout, unsigned int *cali_status);

META_RESULT __stdcall SP_META_CCT_StrobeGetCalibrationDump(unsigned int  ms_timeout, CCT_Strobe_DumpData *pCnf);
META_RESULT __stdcall SP_META_CCT_StrobeGetCalibrationDump_r(const int meta_handle, unsigned int  ms_timeout, CCT_Strobe_DumpData *pCnf);

META_RESULT __stdcall SP_META_CCT_StrobeCalibrationStop(unsigned int  ms_timeout);
META_RESULT __stdcall SP_META_CCT_StrobeCalibrationStop_r(const int meta_handle, unsigned int  ms_timeout);




// 2011-11-10 Wei Fang add


META_RESULT __stdcall SP_META_GetDynamicUSBComPortExWithFilter(unsigned int ms_scan_timeout, unsigned short *com_port, int *p_scanstop, char *info, int length, char *valid_usb_info);
META_RESULT __stdcall SP_META_GetDynamicUSBComPortExWithFilter_r(const int meta_handle, unsigned int ms_scan_timeout, unsigned short *com_port, int *p_scanstop, char *info, int length, char *valid_usb_info);

//META_RESULT __stdcall SP_META_GetDynamicUSBComPortWithPrefix_r(const int meta_handle, unsigned int ms_scan_timeout, unsigned short *com_port, int *p_scanstop, const char* prefix);
//META_RESULT __stdcall SP_META_GetDynamicUSBComPortWithFilter_r(const int meta_handle, unsigned int ms_scan_timeout, unsigned short *com_port, int *p_scanstop, char *valid_usb_info);


// EMMC Module



typedef struct
{       
    unsigned char   status;   // The operation whether success , 1 means success
} EMMC_CLEAR_CNF_S;

typedef struct
{       
    unsigned char   sign;   // No means
} EMMC_CLEAR_REQ_S;

typedef struct
{
	unsigned char   sign;   // No means
} EMMC_FORMAT_TCARD_REQ_S;

typedef struct
{       
    unsigned char   status;   // The operation whether success , 1 means success
} EMMC_FORMAT_TCARD_CNF_S;

typedef struct 
{       
    unsigned char   status;   // The operation whether success , 1 means success
}EMMC_CLEAR_WITHOUT_TCARD_CNF_S;

typedef struct 
{
    unsigned char   sign;   // No means
}EMMC_CLEAR_WITHOUT_TCARD_REQ_S;




META_RESULT __stdcall SP_META_ClearValue_r(const int meta_handle, unsigned int  ms_timeout, EMMC_CLEAR_CNF_S *pCnf);
META_RESULT __stdcall SP_META_ClearValue(unsigned int  ms_timeout, EMMC_CLEAR_CNF_S *pCnf);

META_RESULT __stdcall SP_META_EMMC_FormatTCard_r(const int meta_handle, unsigned int  ms_timeout, EMMC_FORMAT_TCARD_CNF_S *pCnf);
META_RESULT __stdcall SP_META_EMMC_FormatTCard(unsigned int  ms_timeout, EMMC_FORMAT_TCARD_CNF_S *pCnf);

META_RESULT __stdcall SP_META_ClearValue_WithoutTCard_r(const int meta_handle, unsigned int  ms_timeout, EMMC_CLEAR_WITHOUT_TCARD_CNF_S *pCnf);
META_RESULT __stdcall SP_META_ClearValue_WithoutTCard(unsigned int  ms_timeout, EMMC_CLEAR_WITHOUT_TCARD_CNF_S *pCnf);



// ENCRYPTED

typedef struct
{       
    unsigned char  sign;   // No means
} CRYPTFS_QUERYSUPPORT_REQ;

typedef struct
{       
    unsigned char   support;    // 1 means support; 0 means unsupport
} CRYPTFS_QUERYSUPPORT_CNF;

typedef struct
{
   unsigned char pwd[32];
   int  length;
} CRYPTFS_VERITIF_REQ;

typedef struct
{       
    unsigned char match_result;   // 1 means match, 0 means unmatch
} CRYPTFS_VERITIF_CNF;


typedef struct
{       
    unsigned char cfg;   // 0 means to disable 'default encryption', 1 means to enable 'default encryption'
} CRYPTFS_SET_CFG_REQ;

typedef struct
{       
    unsigned char set_cfg_result; // 1 means to set cfg successfully, 0 means that failed to set cfg 
} CRYPTFS_SET_CFG_CNF;


typedef struct
{       
	unsigned char  sign;   // No means
} CRYPTFS_GET_CFG_REQ;

typedef struct
{   
    unsigned char get_cfg_result;    //0 means to disable 'default encryption', 
	                                 //1 means to enable 'default encryption', 
	                                 //'F' means failure that no such cfg or something wrong
} CRYPTFS_GET_CFG_CNF;


META_RESULT __stdcall SP_META_ENCRYPTED_Support(unsigned int  ms_timeout, CRYPTFS_QUERYSUPPORT_CNF *pCnf);
META_RESULT __stdcall SP_META_ENCRYPTED_Support_r(const int meta_handle, unsigned int  ms_timeout, CRYPTFS_QUERYSUPPORT_CNF *pCnf);


META_RESULT __stdcall SP_META_ENCRYPTED_VertifyPwd_r(const int meta_handle, unsigned int  ms_timeout, CRYPTFS_VERITIF_REQ *pReq ,CRYPTFS_VERITIF_CNF *pCnf);
META_RESULT __stdcall SP_META_ENCRYPTED_VertifyPwd(unsigned int  ms_timeout, CRYPTFS_VERITIF_REQ *pReq ,CRYPTFS_VERITIF_CNF *pCnf);

META_RESULT __stdcall SP_META_ENCRYPTED_SetConfig_r(const int meta_handle, unsigned int  ms_timeout, CRYPTFS_SET_CFG_REQ *pReq ,CRYPTFS_SET_CFG_CNF *pCnf);
META_RESULT __stdcall SP_META_ENCRYPTED_SetConfig(unsigned int  ms_timeout, CRYPTFS_SET_CFG_REQ *pReq ,CRYPTFS_SET_CFG_CNF *pCnf);

META_RESULT __stdcall SP_META_ENCRYPTED_GetConfig_r(const int meta_handle, unsigned int  ms_timeout, CRYPTFS_GET_CFG_CNF *pCnf);
META_RESULT __stdcall SP_META_ENCRYPTED_GetConfig(unsigned int  ms_timeout, CRYPTFS_GET_CFG_CNF *pCnf);



//MODEM(DFO)
typedef struct 
{
    unsigned char reserved;   //just reserved
} MODEM_QUERY_INFO_REQ;

typedef struct 
{
    unsigned int modem_number;
    unsigned int modem_id;
} MODEM_QUERY_INFO_CNF;

META_RESULT __stdcall SP_META_MODEM_Query_Info(unsigned int  ms_timeout, MODEM_QUERY_INFO_REQ *pReq, MODEM_QUERY_INFO_CNF *pCnf);
META_RESULT __stdcall SP_META_MODEM_Query_Info_r(const int meta_handle, unsigned int  ms_timeout, MODEM_QUERY_INFO_REQ *pReq, MODEM_QUERY_INFO_CNF *pCnf);


typedef struct 
{
    unsigned char reserved;   //just reserved
} MODEM_CAPABILITY_LIST_REQ;

typedef enum 
{
	FT_MODEM_SRV_INVALID = 0,
	FT_MODEM_SRV_TST = 1,
    FT_MODEM_SRV_DHL = 2,
	FT_MODEM_SRV_C2K = 3,
	FT_MODEM_SRV_END = 0x0fffffff
}FT_MODEM_SRV;

typedef enum 
{
	FT_MODEM_CH_NATIVE_INVALID = 0,
	FT_MODEM_CH_NATIVE_TST = 1,
    FT_MODEM_CH_TUNNELING = 2,
    FT_MODEM_CH_TUNNELING_IGNORE_CKSM = 3,
	FT_MODEM_CH_NATIVE_C2K = 4,
	FT_MODEM_CH_END = 0x0fffffff
}FT_MODEM_CH_TYPE;

typedef struct 
{
	unsigned int md_service;
    unsigned int ch_type;
    unsigned char reserved;
}MODEM_CAPABILITY; 

typedef struct
{
	MODEM_CAPABILITY modem_cap[8];
}MODEM_CAPABILITY_LIST_CNF; 


META_RESULT __stdcall SP_META_MODEM_Capability(unsigned int  ms_timeout, MODEM_CAPABILITY_LIST_REQ *pReq, MODEM_CAPABILITY_LIST_CNF *pCnf);
META_RESULT __stdcall SP_META_MODEM_Capability_r(const int meta_handle, unsigned int  ms_timeout, MODEM_CAPABILITY_LIST_REQ *pReq, MODEM_CAPABILITY_LIST_CNF *pCnf);


typedef struct 
{
	unsigned int modem_id;
	unsigned int modem_type;
}MODEM_SET_MODEMTYPE_REQ;

typedef struct 
{
	unsigned char reserved;	
}MODEM_SET_MODEMTYPE_CNF;

META_RESULT __stdcall SP_META_MODEM_Set_ModemType(unsigned int  ms_timeout, MODEM_SET_MODEMTYPE_REQ *pReq,MODEM_SET_MODEMTYPE_CNF *pCnf);
META_RESULT __stdcall SP_META_MODEM_Set_ModemType_r(const int meta_handle, unsigned int  ms_timeout, MODEM_SET_MODEMTYPE_REQ *pReq, MODEM_SET_MODEMTYPE_CNF *pCnf);

typedef struct 
{
	unsigned int modem_id;
}MODEM_GET_CURRENTMODEMTYPE_REQ;

typedef struct 
{
	unsigned int current_modem_type;
}MODEM_GET_CURENTMODEMTYPE_CNF;

META_RESULT __stdcall SP_META_MODEM_Get_CurrentModemType(unsigned int  ms_timeout, MODEM_GET_CURRENTMODEMTYPE_REQ *pReq,MODEM_GET_CURENTMODEMTYPE_CNF *pCnf);
META_RESULT __stdcall SP_META_MODEM_Get_CurrentModemType_r(const int meta_handle, unsigned int  ms_timeout, MODEM_GET_CURRENTMODEMTYPE_REQ *pReq, MODEM_GET_CURENTMODEMTYPE_CNF *pCnf);

typedef struct 
{
	unsigned int modem_id;	
}MODEM_QUERY_MDIMGTYPE_REQ;

typedef struct 
{
	unsigned int mdimg_type[16];
}MODEM_QUERY_MDIMGTYPE_CNF;

META_RESULT __stdcall SP_META_MODEM_Query_MDIMGType(unsigned int  ms_timeout, MODEM_QUERY_MDIMGTYPE_REQ *pReq,MODEM_QUERY_MDIMGTYPE_CNF *pCnf);
META_RESULT __stdcall SP_META_MODEM_Query_MDIMGType_r(const int meta_handle, unsigned int  ms_timeout, MODEM_QUERY_MDIMGTYPE_REQ *pReq, MODEM_QUERY_MDIMGTYPE_CNF *pCnf);


typedef struct 
{
	unsigned char reserved;	
}MODEM_QUERY_DOWNLOAD_STATUS_REQ;


typedef struct 
{
	unsigned int percentage;
	unsigned int status_code;
}MODEM_QUERY_DOWNLOAD_STATUS_CNF;


META_RESULT __stdcall SP_META_MODEM_Query_Download_Status(unsigned int  ms_timeout, MODEM_QUERY_DOWNLOAD_STATUS_REQ *pReq,MODEM_QUERY_DOWNLOAD_STATUS_CNF *pCnf);
META_RESULT __stdcall SP_META_MODEM_Query_Download_Status_r(const int meta_handle, unsigned int  ms_timeout, MODEM_QUERY_DOWNLOAD_STATUS_REQ *pReq,MODEM_QUERY_DOWNLOAD_STATUS_CNF *pCnf);

typedef struct 
{
	unsigned char modem_index;	
	unsigned char reserved;	
}MODEM_TRIGGER_NATIVE_DOWNLOAD_REQ;


typedef struct 
{
	unsigned char reserved;	
}MODEM_TRIGGER_NATIVE_DOWNLOAD_CNF;

META_RESULT __stdcall SP_META_MODEM_TRIGGER_NATIVE_DOWNLOAD(unsigned int ms_timeout, MODEM_TRIGGER_NATIVE_DOWNLOAD_REQ *pReq, MODEM_TRIGGER_NATIVE_DOWNLOAD_CNF *pCnf);
META_RESULT __stdcall SP_META_MODEM_TRIGGER_NATIVE_DOWNLOAD_r(const int meta_handle, unsigned int ms_timeout,MODEM_TRIGGER_NATIVE_DOWNLOAD_REQ *pReq, MODEM_TRIGGER_NATIVE_DOWNLOAD_CNF *pCnf);

//Set mobile log for meta mode
typedef struct
{
    int reserved;
}SAVE_MOBILE_LOG_REQ;

typedef struct
{
    int drv_status;
}SAVE_MOBILE_LOG_CNF;

META_RESULT __stdcall SP_META_SaveMobileLog(unsigned int ms_timeout,SAVE_MOBILE_LOG_REQ *req, SAVE_MOBILE_LOG_CNF *cnf);
META_RESULT __stdcall SP_META_SaveMobileLog_r(const int meta_handle,unsigned int ms_timeout,SAVE_MOBILE_LOG_REQ *req,SAVE_MOBILE_LOG_CNF *cnf);

//

typedef struct
{
    unsigned int level;
}SET_LOG_LEVEL_REQ;

typedef struct
{
    int reserved;
}SET_LOG_LEVEL_CNF;

META_RESULT __stdcall SP_META_SetLogLevel(unsigned int ms_timeout,SET_LOG_LEVEL_REQ *req, SET_LOG_LEVEL_CNF *cnf);
META_RESULT __stdcall SP_META_SetLogLevel_r(const int meta_handle,unsigned int ms_timeout,SET_LOG_LEVEL_REQ *req,SET_LOG_LEVEL_CNF *cnf);

META_RESULT __stdcall SP_META_SDIOAutoCalibration(unsigned int ms_timeout);
META_RESULT __stdcall SP_META_SDIOAutoCalibration_r(const int meta_handle,unsigned int ms_timeout);

META_RESULT __stdcall SP_META_BT_OPEN(unsigned int ms_timeout);
META_RESULT __stdcall SP_META_BT_OPEN_r(const int meta_handle, unsigned int ms_timeout);

META_RESULT __stdcall SP_META_BT_CLOSE(unsigned int ms_timeout);
META_RESULT __stdcall SP_META_BT_CLOSE_r(const int meta_handle, unsigned int ms_timeout);

META_RESULT __stdcall SP_META_WIFI_OPEN(unsigned int ms_timeout);
META_RESULT __stdcall SP_META_WIFI_OPEN_r(const int meta_handle, unsigned int ms_timeout);

META_RESULT __stdcall SP_META_WIFI_CLOSE(unsigned int ms_timeout);
META_RESULT __stdcall SP_META_WIFI_CLOSE_r(const int meta_handle, unsigned int ms_timeout);

// Get Sim Card

META_RESULT __stdcall SP_META_GetSimCardNum(unsigned int ms_timeout, unsigned int *number);
META_RESULT __stdcall SP_META_GetSimCardNum_r(const int meta_handle, unsigned int ms_timeout, unsigned int *number);



struct EXTERNAL_SD_CARD_PATH_CNF
{
    unsigned char sd_path[256];
};
/*
META_RESULT __stdcall SP_META_GetExternalSDCardPath(unsigned int ms_timeout, EXTERNAL_SD_CARD_PATH_CNF *cnf);
META_RESULT __stdcall SP_META_GetExternalSDCardPath_r(const int meta_handle,unsigned int ms_timeout, EXTERNAL_SD_CARD_PATH_CNF *cnf);
*/
// HDCP
#define HDCP_KEY_ARRAY_NUMBER 287
struct FILE_CUSTOM_HDCP_KEY_STRUCT
{
    unsigned char HdcpKeyArray[HDCP_KEY_ARRAY_NUMBER];
};

META_RESULT  __stdcall SP_META_NVRAM_Compose_HDCP(const FILE_CUSTOM_HDCP_KEY_STRUCT *param, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_Decompose_HDCP(FILE_CUSTOM_HDCP_KEY_STRUCT *param, const char *buf, const int buf_len);
// This api is not supported in target side

// BT Module 
META_RESULT  __stdcall SP_META_BT_TxPureTest(unsigned int  ms_timeout, BT_HCI_TX_PURE_TEST *snd, META_BT_HCI_TXTEST_CNF cb_tx, void  *cb_arg);
META_RESULT  __stdcall SP_META_BT_TxPureTest_r(const int meta_handle, unsigned int  ms_timeout, BT_HCI_TX_PURE_TEST *snd, META_BT_HCI_TXTEST_CNF cb_tx, void  *cb_arg);
META_RESULT  __stdcall SP_META_BT_RxTestStart(unsigned int  ms_timeout, META_BT_HCI_RXTEST_CNF cb_rx);
META_RESULT  __stdcall SP_META_BT_RxTestStart_r(const int meta_handle, unsigned int  ms_timeout, META_BT_HCI_RXTEST_CNF cb_rx);
META_RESULT  __stdcall SP_META_BT_TxPureTest_V2(unsigned int  ms_timeout, BT_HCI_TX_PURE_TEST *snd, META_BT_HCI_TXTEST_V2_CNF cb_txtest, void  *cb_arg);
META_RESULT  __stdcall SP_META_BT_TxPureTest_V2_r(const int meta_handle, unsigned int  ms_timeout, BT_HCI_TX_PURE_TEST	*snd, META_BT_HCI_TXTEST_V2_CNF cb_txtest, void  *cb_arg);
META_RESULT  __stdcall SP_META_BT_RxTestStart_V2(unsigned int  ms_timeout, META_BT_HCI_RXTEST_CNF cb_rx);
META_RESULT  __stdcall SP_META_BT_RxTestStart_V2_r(const int meta_handle, unsigned int ms_timeout, META_BT_HCI_RXTEST_CNF cb_rx);
META_RESULT  __stdcall SP_META_BT_RxTestEnd(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_BT_RxTestEnd_r(const int meta_handle, unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_BT_EnableNvramOnlineUpdate(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_BT_EnableNvramOnlineUpdate_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_BT_DisableNvramOnlineUpdate(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_BT_DisableNvramOnlineUpdate_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_BT_EnablePcmClockSyncSignal(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_BT_EnablePcmClockSyncSignal_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_BT_DisablePcmClockSyncSignal(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_BT_DisablePcmClockSyncSignal_r(const int meta_handle, unsigned int ms_timeout);

// This api is not supported in target side

// BT Module 
META_RESULT  __stdcall SP_META_BT_TxPureTest(unsigned int  ms_timeout, BT_HCI_TX_PURE_TEST *snd, META_BT_HCI_TXTEST_CNF cb_tx, void  *cb_arg);
META_RESULT  __stdcall SP_META_BT_TxPureTest_r(const int meta_handle, unsigned int  ms_timeout, BT_HCI_TX_PURE_TEST *snd, META_BT_HCI_TXTEST_CNF cb_tx, void  *cb_arg);
META_RESULT  __stdcall SP_META_BT_RxTestStart(unsigned int  ms_timeout, META_BT_HCI_RXTEST_CNF cb_rx);
META_RESULT  __stdcall SP_META_BT_RxTestStart_r(const int meta_handle, unsigned int  ms_timeout, META_BT_HCI_RXTEST_CNF cb_rx);
META_RESULT  __stdcall SP_META_BT_TxPureTest_V2(unsigned int  ms_timeout, BT_HCI_TX_PURE_TEST *snd, META_BT_HCI_TXTEST_V2_CNF cb_txtest, void  *cb_arg);
META_RESULT  __stdcall SP_META_BT_TxPureTest_V2_r(const int meta_handle, unsigned int  ms_timeout, BT_HCI_TX_PURE_TEST	*snd, META_BT_HCI_TXTEST_V2_CNF cb_txtest, void  *cb_arg);
META_RESULT  __stdcall SP_META_BT_RxTestStart_V2(unsigned int  ms_timeout, META_BT_HCI_RXTEST_CNF cb_rx);
META_RESULT  __stdcall SP_META_BT_RxTestStart_V2_r(const int meta_handle, unsigned int ms_timeout, META_BT_HCI_RXTEST_CNF cb_rx);
META_RESULT  __stdcall SP_META_BT_RxTestEnd(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_BT_RxTestEnd_r(const int meta_handle, unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_BT_EnableNvramOnlineUpdate(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_BT_EnableNvramOnlineUpdate_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_BT_DisableNvramOnlineUpdate(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_BT_DisableNvramOnlineUpdate_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_BT_EnablePcmClockSyncSignal(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_BT_EnablePcmClockSyncSignal_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_BT_DisablePcmClockSyncSignal(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_BT_DisablePcmClockSyncSignal_r(const int meta_handle, unsigned int ms_timeout);

// WIFI Module
META_RESULT  __stdcall SP_META_NVRAM_WiFi_MacAddress_Len(int *len);
META_RESULT  __stdcall SP_META_NVRAM_WiFi_Compose_MacAddress(const WiFi_MacAddress_S  *mac, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_WiFi_Decompose_MacAddress(WiFi_MacAddress_S  *mac, const char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_WiFi_DacDcOffset_Len(int *len);
META_RESULT  __stdcall SP_META_NVRAM_WiFi_Compose_DacDcOffset(const WiFi_DAC_DC_Offset_S  *dac, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_WiFi_Decompose_DacDcOffset(WiFi_DAC_DC_Offset_S  *dac, const char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_WiFi_TxPower2400M_Len(int *len);
META_RESULT  __stdcall SP_META_NVRAM_WiFi_Compose_TxPower2400M(const WiFi_TxPower_2400M_S  *txpwr, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_WiFi_Decompose_TxPower2400M(WiFi_TxPower_2400M_S  *txpwr, const char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_WiFi_TxPower5000M_Len(int *len);
META_RESULT  __stdcall SP_META_NVRAM_WiFi_Compose_TxPower5000M(const WiFi_TxPower_5000M_S  *txpwr, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_WiFi_Decompose_TxPower5000M(WiFi_TxPower_5000M_S  *txpwr, const char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_WiFi_Compose_ALC_2400M(const WiFi_ALC_2400M_S  *alc, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_WiFi_Decompose_ALC_2400M(WiFi_ALC_2400M_S  *alc, const char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_WiFi_ALC_2400M_Len(int *len);
META_RESULT  __stdcall SP_META_NVRAM_WiFi_TxALC2400M_Len(int *len);
META_RESULT  __stdcall SP_META_NVRAM_WiFi_Compose_TxALC2400M(const WiFi_TxALC_2400M_S  *txalc, char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_NVRAM_WiFi_Decompose_TxALC2400M(WiFi_TxALC_2400M_S  *txalc, const char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_WiFi_Stop(unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_WiFi_Stop_r(const int meta_handle, unsigned int  ms_timeout);
META_RESULT  __stdcall SP_META_WiFi_ContTx(unsigned int  ms_timeout, const WiFi_TestTx_S *req);
META_RESULT  __stdcall SP_META_WiFi_ContTx_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_TestTx_S *req);
META_RESULT  __stdcall SP_META_WiFi_LocalFrequencyMeasure(unsigned int  ms_timeout, const WiFi_TestTx_S *req);
META_RESULT  __stdcall SP_META_WiFi_LocalFrequencyMeasure_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_TestTx_S *req);
META_RESULT  __stdcall SP_META_WiFi_CarrierSuppressionMeasure(unsigned int  ms_timeout, const WiFi_TestTx_S *req);
META_RESULT  __stdcall SP_META_WiFi_CarrierSuppressionMeasure_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_TestTx_S *req);
META_RESULT  __stdcall SP_META_WiFi_ContPktTx(unsigned int  ms_timeout, const WiFi_TestPktTx_S *req);
META_RESULT  __stdcall SP_META_WiFi_ContPktTx_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_TestPktTx_S *req);
META_RESULT  __stdcall SP_META_WiFi_ContPktTx_Ex(unsigned int  ms_timeout, const WiFi_TestPktTx_Ex_S *req);
META_RESULT  __stdcall SP_META_WiFi_ContPktTx_Ex_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_TestPktTx_Ex_S *req);

//-----------------------------------------------------//
//  WiFi Calibration: WNDRV SET Functions              //
//-----------------------------------------------------//

META_RESULT  __stdcall SP_META_WiFi_SetPowerManagementMode(unsigned int  ms_timeout, const WiFi_PowerManagementMode_E  mode);
META_RESULT  __stdcall SP_META_WiFi_SetPowerManagementMode_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_PowerManagementMode_E  mode);
META_RESULT  __stdcall SP_META_WiFi_ContPktRx(unsigned int  ms_timeout, const WiFi_TestPktRx_S *req);
META_RESULT  __stdcall SP_META_WiFi_ContPktRx_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_TestPktRx_S *req);
META_RESULT  __stdcall SP_META_WiFi_SetRegDomain(unsigned int  ms_timeout, const WiFi_RegDomain_S  *req);
META_RESULT  __stdcall SP_META_WiFi_SetRegDomain_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_RegDomain_S  *req);
META_RESULT  __stdcall SP_META_WiFi_SetDbmToDac(unsigned int  ms_timeout, const WiFi_DBM2DAC_Set_S *req);
META_RESULT  __stdcall SP_META_WiFi_SetDbmToDac_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_DBM2DAC_Set_S *req);
META_RESULT  __stdcall SP_META_WiFi_MACReg32Write(unsigned int  ms_timeout, const WiFi_MACReg32_S  *array, unsigned int array_cnt);
META_RESULT  __stdcall SP_META_WiFi_MACReg32Write_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_MACReg32_S  *array, unsigned int array_cnt);
META_RESULT  __stdcall SP_META_WiFi_MACReg16Write(unsigned int  ms_timeout, const WiFi_MACReg16_S  *array, unsigned int array_cnt);
META_RESULT  __stdcall SP_META_WiFi_MACReg16Write_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_MACReg16_S  *array, unsigned int array_cnt);
META_RESULT  __stdcall SP_META_WiFi_BBRegWrite(unsigned int  ms_timeout, const WiFi_BBReg8_S  *array, unsigned int array_cnt);
META_RESULT  __stdcall SP_META_WiFi_BBRegWrite_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_BBReg8_S  *array, unsigned int array_cnt);
META_RESULT  __stdcall SP_META_WiFi_EEPROM_Write(unsigned int  ms_timeout, const WiFi_EEPROM_S *array, unsigned int array_cnt);
META_RESULT  __stdcall SP_META_WiFi_EEPROM_Write_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_EEPROM_S *array, unsigned int array_cnt);
META_RESULT  __stdcall SP_META_WiFi_QueryTxStatus(unsigned int  ms_timeout, WiFi_TxStatus_S *cnf);
META_RESULT  __stdcall SP_META_WiFi_QueryTxStatus_r(const int meta_handle, unsigned int  ms_timeout, WiFi_TxStatus_S *cnf);
META_RESULT  __stdcall SP_META_WiFi_QueryTxStatus_Ex(unsigned int  ms_timeout, WiFi_TxStatus_Ex_S *cnf);
META_RESULT  __stdcall SP_META_WiFi_QueryTxStatus_Ex_r(const int meta_handle, unsigned int  ms_timeout, WiFi_TxStatus_Ex_S *cnf);
META_RESULT  __stdcall SP_META_WiFi_QueryRxStatus(unsigned int  ms_timeout, WiFi_RxStatus_S *cnf);
META_RESULT  __stdcall SP_META_WiFi_QueryRxStatus_r(const int meta_handle, unsigned int  ms_timeout, WiFi_RxStatus_S *cnf);
META_RESULT  __stdcall SP_META_WiFi_QueryChannelList(unsigned int  ms_timeout, WiFi_ChannelList_S *cnf);
META_RESULT  __stdcall SP_META_WiFi_QueryChannelList_r(const int meta_handle, unsigned int  ms_timeout, WiFi_ChannelList_S *cnf);
META_RESULT  __stdcall SP_META_WiFi_QueryRxCounter(unsigned int  ms_timeout, WiFi_RxCounter_S *cnf);
META_RESULT  __stdcall SP_META_WiFi_QueryRxCounter_r(const int meta_handle, unsigned int  ms_timeout, WiFi_RxCounter_S *cnf);
META_RESULT  __stdcall SP_META_WiFi_QueryDbmToDac(unsigned int  ms_timeout, WiFi_DBM2DAC_Query_S  *cnf);
META_RESULT  __stdcall SP_META_WiFi_QueryDbmToDac_r(const int meta_handle, unsigned int  ms_timeout, WiFi_DBM2DAC_Query_S  *cnf);


//-----------------------------------------------------//
//  WiFi Calibration: WNDRV QUERY Functions            //
//-----------------------------------------------------//
META_RESULT  __stdcall SP_META_WiFi_MACReg32Read(unsigned int  ms_timeout, WiFi_MACReg32_S  *array, unsigned int array_cnt);
META_RESULT  __stdcall SP_META_WiFi_MACReg32Read_r(const int meta_handle, unsigned int  ms_timeout, WiFi_MACReg32_S  *array, unsigned int array_cnt);
META_RESULT  __stdcall SP_META_WiFi_MACReg16Read(unsigned int  ms_timeout, WiFi_MACReg16_S  *array, unsigned int array_cnt);
META_RESULT  __stdcall SP_META_WiFi_MACReg16Read_r(const int meta_handle, unsigned int  ms_timeout, WiFi_MACReg16_S  *array, unsigned int array_cnt);
META_RESULT  __stdcall SP_META_WiFi_BBRegRead(unsigned int  ms_timeout, WiFi_BBReg8_S  *array, unsigned int array_cnt);
META_RESULT  __stdcall SP_META_WiFi_BBRegRead_r(const int meta_handle, unsigned int  ms_timeout, WiFi_BBReg8_S  *array, unsigned int array_cnt);
META_RESULT  __stdcall SP_META_WiFi_EEPROM_Read(unsigned int  ms_timeout, WiFi_EEPROM_S *array, unsigned int array_cnt);
META_RESULT  __stdcall SP_META_WiFi_EEPROM_Read_r(const int meta_handle, unsigned int  ms_timeout, WiFi_EEPROM_S *array, unsigned int array_cnt);
META_RESULT  __stdcall SP_META_WiFi_DacDcOffsetAutoCalibration(unsigned int  ms_timeout, WiFi_DAC_DC_Offset_S  *cnf);
META_RESULT  __stdcall SP_META_WiFi_DacDcOffsetAutoCalibration_r(const int meta_handle, unsigned int  ms_timeout, WiFi_DAC_DC_Offset_S  *cnf);


//-----------------------------------------------------//
//  WiFi Calibration: Exported Functions               //
//-----------------------------------------------------//
META_RESULT  __stdcall SP_META_WiFi_QueryChipCapability(unsigned int  ms_timeout, WiFi_ChipCapability_S  *cnf);
META_RESULT  __stdcall SP_META_WiFi_QueryChipCapability_r(const int meta_handle, unsigned int  ms_timeout, WiFi_ChipCapability_S  *cnf);
META_RESULT  __stdcall SP_META_WiFi_SetMacAddress(unsigned int  ms_timeout, const WiFi_MacAddress_S  *mac);
META_RESULT  __stdcall SP_META_WiFi_SetMacAddress_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_MacAddress_S  *mac);
META_RESULT  __stdcall SP_META_WiFi_SetTxPower2400M(unsigned int  ms_timeout, const WiFi_TxPower_2400M_S  *txpwr);
META_RESULT  __stdcall SP_META_WiFi_SetTxPower2400M_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_TxPower_2400M_S  *txpwr);
META_RESULT  __stdcall SP_META_WiFi_SetTxPower5000M(unsigned int  ms_timeout, const WiFi_TxPower_5000M_S  *txpwr);
META_RESULT  __stdcall SP_META_WiFi_SetTxPower5000M_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_TxPower_5000M_S  *txpwr);
META_RESULT  __stdcall SP_META_WiFi_SetDacDcOffset(unsigned int  ms_timeout, const WiFi_DAC_DC_Offset_S  *dac_dc_offset);
META_RESULT  __stdcall SP_META_WiFi_SetDacDcOffset_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_DAC_DC_Offset_S  *dac_dc_offset);

META_RESULT  __stdcall SP_META_WiFi_SetTxALC2400M(unsigned int  ms_timeout, const WiFi_TxALC_2400M_S  *txalc);
META_RESULT  __stdcall SP_META_WiFi_SetTxALC2400M_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_TxALC_2400M_S  *txalc);


// ADC Cal
META_RESULT  __stdcall SP_META_ADC_GetChannelNum(unsigned int  ms_timeout, unsigned int * pNum);
META_RESULT  __stdcall SP_META_ADC_GetChannelNum_r(const int meta_handle, unsigned int  ms_timeout, unsigned int * pNum);
META_RESULT  __stdcall SP_META_ADC_QueryEfuseCalExist(unsigned int  ms_timeout, unsigned int * pIsExist);
META_RESULT  __stdcall SP_META_ADC_QueryEfuseCalExist_r(const int meta_handle, unsigned int  ms_timeout, unsigned int * pIsExist);


// pVol: battery voltage(mV) 
// pCapacity: battery capacity
META_RESULT  __stdcall SP_META_ADC_GetBatVol(unsigned int  ms_timeout, int * pVol);   
META_RESULT  __stdcall SP_META_ADC_GetBatVol_r(const int meta_handle, unsigned int ms_timeout, int * pVol);
META_RESULT  __stdcall SP_META_ADC_GetBatCapacity(unsigned int  ms_timeout, int * pCapacity);
META_RESULT  __stdcall SP_META_ADC_GetBatCapacity_r(const int meta_handle, unsigned int ms_timeout, int * pCapacity);
//

// GPS
META_RESULT  __stdcall SP_META_GPS_Stop(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_GPS_Stop_r(const int meta_handle,unsigned int ms_timeout);

//-----------------------------------------------------//
//  3G RF Testing: function definition				   //
//-----------------------------------------------------//

META_RESULT  __stdcall SP_META_3Grf_ContinuousRX(unsigned int  ms_timeout, URfTestCmdRSSI *req);
META_RESULT  __stdcall SP_META_3Grf_ContinuousRX_r(const int meta_handle, unsigned int  ms_timeout, URfTestCmdRSSI *req);

META_RESULT  __stdcall SP_META_3Grf_TxAccess(unsigned int  ms_timeout, URfTestCmdTxAccess *req, URfTestResultParam *cnf);
META_RESULT  __stdcall SP_META_3Grf_TxAccess_r(const int meta_handle, unsigned int  ms_timeout, URfTestCmdTxAccess *req, URfTestResultParam *cnf);
META_RESULT  __stdcall SP_META_3Grf_TestStop(unsigned int  ms_timeout, URfTestResultParam *cnf);
META_RESULT  __stdcall SP_META_3Grf_TestStop_r(const int meta_handle, unsigned int  ms_timeout, URfTestResultParam *cnf);
META_RESULT  __stdcall SP_META_3Grf_TxDpch(unsigned int  ms_timeout, URfTestCmdTxDPCh *req, URfTestResultParam *cnf);
META_RESULT  __stdcall SP_META_3Grf_TxDpch_r(const int meta_handle, unsigned int  ms_timeout, URfTestCmdTxDPCh *req, URfTestResultParam *cnf);
META_RESULT  __stdcall SP_META_3Grf_RxDpch(unsigned int  ms_timeout, URfTestCmdRxDPCh *req, URfTestResultRxDPCh *cnf);
META_RESULT  __stdcall SP_META_3Grf_RxDpch_r(const int meta_handle, unsigned int  ms_timeout, URfTestCmdRxDPCh *req, URfTestResultRxDPCh *cnf);
META_RESULT  __stdcall SP_META_3Grf_Rssi(unsigned int  ms_timeout, URfTestCmdRSSI *req, URfTestResultRSSI *cnf);
META_RESULT  __stdcall SP_META_3Grf_Rssi_r(const int meta_handle, unsigned int  ms_timeout, URfTestCmdRSSI *req, URfTestResultRSSI *cnf);
META_RESULT  __stdcall SP_META_3Grf_Rscp(unsigned int  ms_timeout, URfTestCmdRSCP *req, URfTestResultRSCP *cnf);
META_RESULT  __stdcall SP_META_3Grf_Rscp_r(const int meta_handle, unsigned int  ms_timeout, URfTestCmdRSCP *req, URfTestResultRSCP *cnf);

META_RESULT  __stdcall SP_META_3Grf_Set_Tx_PaApc(unsigned int  ms_timeout, UL1D_RF_TX_PA_APC_REQ_T *req);
META_RESULT  __stdcall SP_META_3Grf_Set_Tx_PaApc_r(const int meta_handle, unsigned int  ms_timeout, UL1D_RF_TX_PA_APC_REQ_T *req);

META_RESULT  __stdcall SP_META_3Grf_AFC(unsigned int  ms_timeout, URfTestCmdAFC *req, URfTestResultAFC *cnf);
META_RESULT  __stdcall SP_META_3Grf_AFC_r(const int meta_handle, unsigned int  ms_timeout, URfTestCmdAFC *req, URfTestResultAFC *cnf);

META_RESULT  __stdcall SP_META_3Grf_GetRFID(unsigned int  ms_timeout, URfTestResultRFID *cnf);
META_RESULT  __stdcall SP_META_3Grf_GetRFID_r(const int meta_handle, unsigned int  ms_timeout, URfTestResultRFID *cnf);

META_RESULT  __stdcall SP_META_3Grf_ConfigHWTPC(unsigned int  ms_timeout, UL1D_RF_HWTPC_CONFIG_REQ_T *req);
META_RESULT  __stdcall SP_META_3Grf_ConfigHWTPC_r(const int meta_handle, unsigned int  ms_timeout, UL1D_RF_HWTPC_CONFIG_REQ_T *req);


META_RESULT  __stdcall SP_META_3Grf_GetPwrDtStep(unsigned int  ms_timeout, URfTestResultPwrDtStep *cnf);
META_RESULT  __stdcall SP_META_3Grf_GetPwrDtStep_r(const int meta_handle, unsigned int  ms_timeout, URfTestResultPwrDtStep *cnf);
META_RESULT  __stdcall SP_META_3Grf_GetPwrDtDac(unsigned int  ms_timeout, URfTestResultPwrDtDac *cnf);
META_RESULT  __stdcall SP_META_3Grf_GetPwrDtDac_r(const int meta_handle, unsigned int  ms_timeout, URfTestResultPwrDtDac *cnf);
META_RESULT  __stdcall SP_META_3Grf_GetPwrDtDefaultThr(unsigned int  ms_timeout, UL1D_RF_GET_PWR_THR_REQ_T *req, URfTestResultPwrDtDefaultThr *cnf);
META_RESULT  __stdcall SP_META_3Grf_GetPwrDtDefaultThr_r(const int meta_handle, unsigned int  ms_timeout, UL1D_RF_GET_PWR_THR_REQ_T *req, URfTestResultPwrDtDefaultThr *cnf);


META_RESULT  __stdcall SP_META_3Grf_SetImmediateBSI(unsigned int  ms_timeout, const UL1D_RF_SET_BSI_DATA_REQ_T *req);
META_RESULT  __stdcall SP_META_3Grf_SetImmediateBSI_r(const int meta_handle, unsigned int  ms_timeout, const UL1D_RF_SET_BSI_DATA_REQ_T *req);
META_RESULT  __stdcall SP_META_3Grf_GetImmediateBSI(unsigned int  ms_timeout, const UL1D_RF_GET_BSI_DATA_REQ_T *req, unsigned int *p_bsi_data);
META_RESULT  __stdcall SP_META_3Grf_GetImmediateBSI_r(const int meta_handle, unsigned int  ms_timeout, const UL1D_RF_GET_BSI_DATA_REQ_T *req, unsigned int *p_bsi_data);


// Base Band Test
META_RESULT  __stdcall SP_META_PMIC_RegRead(unsigned int ms_timeout, const WM_CMD_ReadPMICRegister_REQ_T *req, WM_CMD_ReadRegister_CNF_T *cnf) ;
META_RESULT  __stdcall SP_META_PMIC_RegRead_r(const int meta_handle,unsigned int ms_timeout, const WM_CMD_ReadPMICRegister_REQ_T *req, WM_CMD_ReadRegister_CNF_T *cnf);
META_RESULT  __stdcall SP_META_PMIC_RegWrite(unsigned int ms_timeout, const WM_CMD_WritePMICRegister_REQ_T *req, WM_CMD_WriteRegister_CNF_T *cnf) ;
META_RESULT  __stdcall SP_META_PMIC_RegWrite_r(const int meta_handle,unsigned int ms_timeout, const WM_CMD_WritePMICRegister_REQ_T *req, WM_CMD_WriteRegister_CNF_T *cnf);
META_RESULT  __stdcall SP_META_PMIC_RegRead_DWORD(unsigned int ms_timeout, const WM_CMD_ReadPMICRegister_DWORD_REQ_T *req, WM_CMD_ReadRegister_DWORD_CNF_T *cnf) ;
META_RESULT  __stdcall SP_META_PMIC_RegRead_DWORD_r(const int meta_handle,unsigned int ms_timeout, const WM_CMD_ReadPMICRegister_DWORD_REQ_T *req, WM_CMD_ReadRegister_DWORD_CNF_T *cnf);
META_RESULT  __stdcall SP_META_PMIC_RegWrite_DWORD(unsigned int ms_timeout, const WM_CMD_WritePMICRegister_DWORD_REQ_T *req, WM_CMD_WriteRegister_DWORD_CNF_T *cnf) ;
META_RESULT  __stdcall SP_META_PMIC_RegWrite_DWORD_r(const int meta_handle,unsigned int ms_timeout, const WM_CMD_WritePMICRegister_DWORD_REQ_T *req, WM_CMD_WriteRegister_DWORD_CNF_T *cnf);


// Battery
META_RESULT  __stdcall SP_META_Battery_DownloadImage(unsigned int ms_timeout, const WM_Bat_DLImage_REQ_T *req, WM_Bat_DLImage_CNF_T *cnf, char* fileAddress);
META_RESULT  __stdcall SP_META_Battery_DownloadImage_r(const int meta_handle,unsigned int ms_timeout, const WM_Bat_DLImage_REQ_T *req, WM_Bat_DLImage_CNF_T *cnf, char* fileAddress);
META_RESULT  __stdcall SP_META_Battery_Read_FW_INFO(unsigned int ms_timeout, const WM_Bat_READ_FW_INFO_REQ_T *req,WM_Bat_READ_FW_INFO_CNF_T *cnf);
META_RESULT  __stdcall SP_META_Battery_Read_FW_INFO_r(const int meta_handle,unsigned int ms_timeout, const WM_Bat_READ_FW_INFO_REQ_T *req,WM_Bat_READ_FW_INFO_CNF_T *cnf);
META_RESULT  __stdcall SP_META_Battery_Read_SOC(unsigned int ms_timeout, const WM_Bat_READ_SOC_REQ_T *req, WM_Bat_READ_SOC_CNF_T *cnf);
META_RESULT  __stdcall SP_META_Battery_Read_SOC_r(const int meta_handle,unsigned int ms_timeout, const WM_Bat_READ_SOC_REQ_T *req, WM_Bat_READ_SOC_CNF_T *cnf);
META_RESULT  __stdcall SP_META_Battery_Write_SOC(unsigned int ms_timeout,const WM_Bat_WRITE_SOC_REQ_T *req, WM_Bat_WRITE_SOC_CNF_T *cnf); 
META_RESULT  __stdcall SP_META_Battery_Write_SOC_r(const int meta_handle,unsigned int ms_timeout, const WM_Bat_WRITE_SOC_REQ_T *req, WM_Bat_WRITE_SOC_CNF_T *cnf);
META_RESULT  __stdcall SP_META_Battery_Update_FW(unsigned int ms_timeout,const WM_Bat_UPImage_REQ_T*req, WM_Bat_UPImage_CNF_T *cnf); 
META_RESULT  __stdcall SP_META_Battery_Update_FW_r(const int meta_handle,unsigned int ms_timeout, const WM_Bat_UPImage_REQ_T *req, WM_Bat_UPImage_CNF_T *cnf);
META_RESULT  __stdcall SP_META_Battery_Enable_IT(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_Battery_Enable_IT_r(int meta_handle, unsigned int ms_timeout);


// DVB
//export function
META_RESULT  __stdcall SP_META_DVB_Connect(unsigned int ms_timeout, const DVB_CONNECT_REQ *req, DVB_CONNECT_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Disconnect(unsigned int ms_timeout, const DVB_DISCONNECT_REQ *req, DVB_DISCONNECT_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Middleware_Update(unsigned int ms_timeout, const DVB_MIDDLEWARE_UPDATE_REQ *req, DVB_MIDDLEWARE_UPDATE_CNF *cnf,  char * fileAddress);
//META_RESULT  __stdcall META_DVB_Parameter_Calibration(unsigned int ms_timeout, const DVB_PARAMETER_CALIBRATION_REQ *req, DVB_PARAMETER_CALIBRATION_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Get_Signal_Quality(unsigned int ms_timeout, const DVB_GET_SIGNALQUALITY_REQ *req, DVB_GET_SIGNALQUALITY_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Demodulator_IsAlive(unsigned int ms_timeout, const DVB_DEMODULATOR_ISALIVE_REQ *req, DVB_DEMODULATOR_ISALIVE_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Set_TS_PacketBatch(unsigned int ms_timeout, const DVB_SET_TS_PACKETBATCH_REQ *req, DVB_SET_TS_PACKETBATCH_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Set_TX_PacketTimeout(unsigned int ms_timeout, const DVB_SET_TX_PACKETTIMEOUT_REQ *req, DVB_SET_TX_PACKETTIMEOUT_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Add_TS_PID(unsigned int ms_timeout, const DVB_ADD_TS_PID_REQ *req, DVB_ADD_TS_PID_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Remove_TS_PID(unsigned int ms_timeout, const DVB_REMOVE_TS_PID_REQ *req, DVB_REMOVE_TS_PID_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Disable_AllTS_PIDsFiltering(unsigned int ms_timeout, const DVB_DISABLE_ALLTS_PIDFILTERING_REQ *req, DVB_DISABLE_ALLTS_PIDFILTERING_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Dump_TS_PacketstoSDCard(unsigned int ms_timeout, const DVB_DUMP_TS_PACKETSTOSDCARD_REQ *req, DVB_DUMP_TS_PACKETSTOSDCARD_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Get_ReceptionMode(unsigned int ms_timeout, const DVB_GET_RECEPTIONMODE_REQ *req, DVB_GET_RECEPTIONMODE_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Get_LockIndicator(unsigned int ms_timeout, const DVB_GET_LOCKINDICATOR_REQ *req, DVB_GET_LOCKINDICATOR_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Get_PerformanceInfo(unsigned int ms_timeout, const DVB_GET_PERFORMANCEINFO_REQ *req, DVB_GET_PERFORMANCEINFO_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Get_Version(unsigned int ms_timeout, const DVB_GET_VERSION_REQ *req, DVB_GET_VERSION_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Get_DebugCounter(unsigned int ms_timeout, const DVB_GET_DEBUG_COUNTER_REQ *req, DVB_GET_DEBUG_COUNTER_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Connect_r(const int meta_handle, unsigned int ms_timeout, const DVB_CONNECT_REQ *req, DVB_CONNECT_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Disconnect_r(const int meta_handle, unsigned int ms_timeout, const DVB_DISCONNECT_REQ *req, DVB_DISCONNECT_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Middleware_Update_r(const int meta_handle, unsigned int ms_timeout, const DVB_MIDDLEWARE_UPDATE_REQ *req, DVB_MIDDLEWARE_UPDATE_CNF *cnf,  char * fileAddress);
//META_RESULT  __stdcall META_DVB_Parameter_Calibration_r(const int meta_handle, unsigned int ms_timeout, const DVB_PARAMETER_CALIBRATION_REQ *req, DVB_PARAMETER_CALIBRATION_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Get_Signal_Quality_r(const int meta_handle, unsigned int ms_timeout, const DVB_GET_SIGNALQUALITY_REQ *req, DVB_GET_SIGNALQUALITY_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Demodulator_IsAlive_r(const int meta_handle, unsigned int ms_timeout, const DVB_DEMODULATOR_ISALIVE_REQ *req, DVB_DEMODULATOR_ISALIVE_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Set_TS_PacketBatch_r(const int meta_handle, unsigned int ms_timeout, const DVB_SET_TS_PACKETBATCH_REQ *req, DVB_SET_TS_PACKETBATCH_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Set_TX_PacketTimeout_r(const int meta_handle, unsigned int ms_timeout, const DVB_SET_TX_PACKETTIMEOUT_REQ *req, DVB_SET_TX_PACKETTIMEOUT_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Add_TS_PID_r(const int meta_handle, unsigned int ms_timeout, const DVB_ADD_TS_PID_REQ *req, DVB_ADD_TS_PID_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Remove_TS_PID_r(const int meta_handle, unsigned int ms_timeout, const DVB_REMOVE_TS_PID_REQ *req, DVB_REMOVE_TS_PID_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Disable_AllTS_PIDsFiltering_r(const int meta_handle, unsigned int ms_timeout, const DVB_DISABLE_ALLTS_PIDFILTERING_REQ *req, DVB_DISABLE_ALLTS_PIDFILTERING_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Dump_TS_PacketstoSDCard_r(const int meta_handle, unsigned int ms_timeout, const DVB_DUMP_TS_PACKETSTOSDCARD_REQ *req, DVB_DUMP_TS_PACKETSTOSDCARD_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Get_ReceptionMode_r(const int meta_handle, unsigned int ms_timeout, const DVB_GET_RECEPTIONMODE_REQ *req, DVB_GET_RECEPTIONMODE_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Get_LockIndicator_r(const int meta_handle, unsigned int ms_timeout, const DVB_GET_LOCKINDICATOR_REQ *req, DVB_GET_LOCKINDICATOR_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Get_PerformanceInfo_r(const int meta_handle, unsigned int ms_timeout, const DVB_GET_PERFORMANCEINFO_REQ *req, DVB_GET_PERFORMANCEINFO_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Get_Version_r(const int meta_handle, unsigned int ms_timeout, const DVB_GET_VERSION_REQ *req, DVB_GET_VERSION_CNF *cnf);
META_RESULT  __stdcall SP_META_DVB_Get_DebugCounter_r(const int meta_handle, unsigned int ms_timeout, const DVB_GET_DEBUG_COUNTER_REQ *req, DVB_GET_DEBUG_COUNTER_CNF *cnf);


// ECI
META_RESULT __stdcall SP_META_EciPortTest(unsigned int ms_timeout, unsigned long portIdx);
META_RESULT __stdcall SP_META_EciPortTest_r(int meta_handle, unsigned int ms_timeout, unsigned long portIdx);

// FAT
META_RESULT  __stdcall SP_META_FAT_Open(const char *fat_filepath, FAT_OPEN_MODE  mode, int *fs_handle, short *p_token);
META_RESULT  __stdcall SP_META_FAT_Open_r(const int meta_handle, const char *fat_filepath, FAT_OPEN_MODE  mode, int *fs_handle, short *p_token);
META_RESULT  __stdcall SP_META_FAT_Close(int *fs_handle, short *p_token);
META_RESULT  __stdcall SP_META_FAT_Close_r(const int meta_handle, int *fs_handle, short *p_token);
META_RESULT  __stdcall SP_META_FAT_GetFileSize(const int fs_handle, int *filesize, short *p_token);
META_RESULT  __stdcall SP_META_FAT_GetFileSize_r(const int meta_handle, const int fs_handle, int *filesize, short *p_token);
META_RESULT  __stdcall SP_META_FAT_Read(const int fs_handle, char *buf, const int buf_len, CALLBACK_META_FAT_PROGRESS  cb_progress, void  *cb_progress_arg, short *p_token);
META_RESULT  __stdcall SP_META_FAT_Read_r(const int meta_handle, const int fs_handle, char *buf, const int buf_len, CALLBACK_META_FAT_PROGRESS  cb_progress, void  *cb_progress_arg, short *p_token);
META_RESULT  __stdcall SP_META_FAT_Write(const int fs_handle, const char *buf, const int buf_len, CALLBACK_META_FAT_PROGRESS  cb_progress, void  *cb_progress_arg, short *p_token);
META_RESULT  __stdcall SP_META_FAT_Write_r(const int meta_handle, const int fs_handle, const char *buf, const int buf_len, CALLBACK_META_FAT_PROGRESS  cb_progress, void  *cb_progress_arg, short *p_token);
META_RESULT  __stdcall SP_META_FAT_Read_To_File(const int fs_handle, const char *local_filepath, CALLBACK_META_FAT_PROGRESS  cb_progress, void  *cb_progress_arg, short *p_token);
META_RESULT  __stdcall SP_META_FAT_Read_To_File_r(const int meta_handle, const int fs_handle, const char *local_filepath, CALLBACK_META_FAT_PROGRESS  cb_progress, void  *cb_progress_arg, short *p_token);
META_RESULT  __stdcall SP_META_FAT_Write_By_File(const int fs_handle, const char *local_filepath, CALLBACK_META_FAT_PROGRESS  cb_progress, void  *cb_progress_arg, short *p_token);
META_RESULT  __stdcall SP_META_FAT_Write_By_File_r(const int meta_handle, const int fs_handle, const char *local_filepath, CALLBACK_META_FAT_PROGRESS  cb_progress, void  *cb_progress_arg, short *p_token);
META_RESULT  __stdcall SP_META_FAT_Delete(const char *fat_filepath, short *p_token);
META_RESULT  __stdcall SP_META_FAT_Delete_r(const int meta_handle, const char *fat_filepath, short *p_token);
META_RESULT  __stdcall SP_META_FAT_Move(const char *fat_filepath, const char *new_fat_filepath, short *p_token);
META_RESULT  __stdcall SP_META_FAT_Move_r(const int meta_handle, const char *fat_filepath, const char *new_fat_filepath, short *p_token);
META_RESULT  __stdcall SP_META_FAT_Find_Start(const char *fat_base_dir, const char *fat_find_pattern, FAT_FIND_MODE	 find_mode, int *p_find_handle, short *p_token);
META_RESULT  __stdcall SP_META_FAT_Find_Start_r(const int meta_handle, const char *fat_base_dir, const char *fat_find_pattern, FAT_FIND_MODE	 find_mode, int *p_find_handle, short *p_token);
META_RESULT  __stdcall SP_META_FAT_Find_Head(int find_handle);
META_RESULT  __stdcall SP_META_FAT_Find_Prev(int find_handle);
META_RESULT  __stdcall SP_META_FAT_Find_Next(int find_handle);
META_RESULT  __stdcall SP_META_FAT_Find_GetFileInfo(int find_handle, char *p_filepath, const int filepath_len, int *p_filesize);
META_RESULT  __stdcall SP_META_FAT_Find_Close(int *p_find_handle);
META_RESULT  __stdcall SP_META_FAT_GetDiskInfo(const char DriveLetter, FAT_DiskInfo_T  *p_DiskInfo, short *p_token);
META_RESULT  __stdcall SP_META_FAT_GetDiskInfo_r(const int meta_handle, const char DriveLetter, FAT_DiskInfo_T  *p_DiskInfo, short *p_token);
META_RESULT  __stdcall SP_META_FAT_RemoveDir(const char *fat_dirpath);
META_RESULT  __stdcall SP_META_FAT_RemoveDir_r(const int meta_handle, const char *fat_dirpath);
META_RESULT  __stdcall SP_META_FAT_CheckEnoughSpace(FAT_FILE_INFO_REQ_T *req);
META_RESULT  __stdcall SP_META_FAT_CheckEnoughSpace_r(const int meta_handle, FAT_FILE_INFO_REQ_T *req);

// Query 
META_RESULT  __stdcall SP_META_QueryIfTargetSupportISP(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_QueryIfTargetSupportISP_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_QueryIfTargetSupportAcoustic16level(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_QueryIfTargetSupportAcoustic16level_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_QueryIfTargetSupportAudioParam45Tap(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_QueryIfTargetSupportAudioParam45Tap_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_BTPowerOn(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_BTPowerOn_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_QueryIfTargetSupportWifiALC(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_QueryIfTargetSupportWifiALC_r(const int meta_handle, unsigned int ms_timeout);

//-----------------------------------------------------//
//  RF Testing: exported function definition           //
//-----------------------------------------------------//
// for SP project, RF is exclusive

META_RESULT  __stdcall SP_META_Rf_PM(const RfPm_Req *req, const META_RF_PM_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_PM_r(const int meta_handle, const RfPm_Req *req, const META_RF_PM_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_AFC(const RfAfc_Req *req, const META_RF_AFC_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_AFC_r(const int meta_handle, const RfAfc_Req *req, const META_RF_AFC_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_NB_TX(const RfNbtx_Req *req, const META_RF_NB_TX_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_NB_TX_r(const int meta_handle, const RfNbtx_Req *req, const META_RF_NB_TX_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_CONTINUE_RX(const RfCnRx_Req *req, const META_RF_CONT_RX_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_CONTINUE_RX_r(const int meta_handle, const RfCnRx_Req *req, const META_RF_CONT_RX_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_CONTINUE_TX(const RfCnTx_Req *req, const META_RF_CONT_TX_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_CONTINUE_TX_r(const int meta_handle, const RfCnTx_Req *req, const META_RF_CONT_TX_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_SetBBTXCfg(const RfSetBBTXCfg_Req *req, const META_RF_SETBBTX_CFG_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_SetBBTXCfg_r(const int meta_handle, const RfSetBBTXCfg_Req *req, const META_RF_SETBBTX_CFG_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_SelectFrequencyBand1900(const unsigned char selectPCS1900, const META_RF_SELBAND_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_SelectFrequencyBand1900_r(const int meta_handle, const unsigned char selectPCS1900, const META_RF_SELBAND_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_Stop(const META_RF_STOP_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_Stop_r(const int meta_handle, const META_RF_STOP_CNF cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_MultiSlot_TX(const RfMultiSlotTX_Req *req, const META_RF_MULTISLOT_TX_CNF  cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_MultiSlot_TX_r(const int meta_handle, const RfMultiSlotTX_Req *req, const META_RF_MULTISLOT_TX_CNF  cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_SetAfcDacValue(const RfSetAfcDacValue_Req *req, const META_RF_SET_AFCDACVALUE_CNF  cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_SetAfcDacValue_r(const int meta_handle, const RfSetAfcDacValue_Req *req, const META_RF_SET_AFCDACVALUE_CNF  cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_SetBBTxCfg2(unsigned int ms_timeout, const RfBBTXCfg2  *tx_cfg_req, RfBBTXCfg2  *tx_cfg_cnf);
META_RESULT  __stdcall SP_META_Rf_SetBBTxCfg2_r(const int meta_handle, unsigned int ms_timeout, const RfBBTXCfg2  *tx_cfg_req, RfBBTXCfg2  *tx_cfg_cnf);
META_RESULT  __stdcall SP_META_Rf_GetBBTxCfg2(unsigned int ms_timeout, RfBBTXCfg2  *tx_cfg_cnf);
META_RESULT  __stdcall SP_META_Rf_GetBBTxCfg2_r(const int meta_handle, unsigned int ms_timeout, RfBBTXCfg2  *tx_cfg_cnf);
META_RESULT  __stdcall SP_META_Rf_SetCrystalCapId(unsigned int ms_timeout, const RfSetCrystalCfg_Req  *req);
META_RESULT  __stdcall SP_META_Rf_SetCrystalCapId_r(const int meta_handle, unsigned int ms_timeout, const RfSetCrystalCfg_Req  *req);
META_RESULT  __stdcall SP_META_Rf_BBTXAutoCal(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_Rf_BBTXAutoCal_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_Rf_QueryMSCapability(unsigned int ms_timeout, RfMsCapability_S  *p_type);
META_RESULT  __stdcall SP_META_Rf_QueryMSCapability_r(const int meta_handle, unsigned int ms_timeout, RfMsCapability_S  *p_type);
META_RESULT  __stdcall SP_META_Rf_QueryMSCapabilityEx(unsigned int ms_timeout, RfMsCapabilityEx_S  *p_ms_cap);
META_RESULT  __stdcall SP_META_Rf_QueryMSCapabilityEx_r(const int meta_handle, unsigned int ms_timeout, RfMsCapabilityEx_S  *p_ms_cap);
META_RESULT  __stdcall SP_META_Rf_SetAfcSinWaveDetection(unsigned int ms_timeout, AFC_SINWAVE_DETECTION_E  bIsAfcSinWaveOn);
META_RESULT  __stdcall SP_META_Rf_SetAfcSinWaveDetection_r(const int meta_handle, unsigned int ms_timeout, AFC_SINWAVE_DETECTION_E  bIsAfcSinWaveOn);
META_RESULT  __stdcall SP_META_Rf_QueryIfTwoApcDCOffsetSupport(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_Rf_QueryIfTwoApcDCOffsetSupport_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_Rf_MultiSlot_TX_Ex(unsigned int ms_timeout, const Rf_MultiSlotTXEx_Req *req);
META_RESULT  __stdcall SP_META_Rf_MultiSlot_TX_Ex_r(const int meta_handle, unsigned int ms_timeout, const Rf_MultiSlotTXEx_Req *req);
META_RESULT  __stdcall SP_META_Rf_GetRFID(unsigned int ms_timeout, RFMod_ID *cnf);
META_RESULT  __stdcall SP_META_Rf_GetRFID_r(const int meta_handle, unsigned int ms_timeout, RFMod_ID *cnf);
META_RESULT  __stdcall SP_META_Rf_CONTINUE_TX_Ex(unsigned int ms_timeout, const RfCnTxEx_Req *req);
META_RESULT  __stdcall SP_META_Rf_CONTINUE_TX_Ex_r(const int meta_handle, unsigned int ms_timeout, const RfCnTxEx_Req *req);
META_RESULT  __stdcall SP_META_Rf_SetBBTxCfg3(unsigned int ms_timeout, const RfBBTXCfg3  *tx_cfg_req, RfBBTXCfg3  *tx_cfg_cnf);
META_RESULT  __stdcall SP_META_Rf_SetBBTxCfg3_r(const int meta_handle, unsigned int ms_timeout, const RfBBTXCfg3  *tx_cfg_req, RfBBTXCfg3  *tx_cfg_cnf);
META_RESULT  __stdcall SP_META_Rf_GetBBTxCfg3(unsigned int ms_timeout, RfBBTXCfg3  *tx_cfg_cnf);
META_RESULT  __stdcall SP_META_Rf_GetBBTxCfg3_r(const int meta_handle, unsigned int ms_timeout, RfBBTXCfg3  *tx_cfg_cnf);
META_RESULT  __stdcall SP_META_Rf_CONTINUE_TX_Ex2(unsigned int ms_timeout, const RfCnTxEx2_Req *req);
META_RESULT  __stdcall SP_META_Rf_CONTINUE_TX_Ex2_r(const int meta_handle, unsigned int ms_timeout, const RfCnTxEx2_Req *req);
META_RESULT  __stdcall SP_META_Rf_GetAfcDacValueAtRTXOffsetCal(unsigned int ms_timeout, RfGetAfcDacValueAtRTXOffsetCal *cnf);
META_RESULT  __stdcall SP_META_Rf_GetAfcDacValueAtRTXOffsetCal_r(const int meta_handle, unsigned int ms_timeout, RfGetAfcDacValueAtRTXOffsetCal *cnf);

META_RESULT  __stdcall SP_META_Rf_SetBBTxCfg4(unsigned int ms_timeout, const RfBBTXCfg4  *tx_cfg_req, RfBBTXCfg4  *tx_cfg_cnf);
META_RESULT  __stdcall SP_META_Rf_SetBBTxCfg4_r(const int meta_handle, unsigned int ms_timeout, const RfBBTXCfg4  *tx_cfg_req, RfBBTXCfg4  *tx_cfg_cnf);
META_RESULT  __stdcall SP_META_Rf_GetBBTxCfg4(unsigned int ms_timeout, RfBBTXCfg4  *tx_cfg_cnf);
META_RESULT  __stdcall SP_META_Rf_GetBBTxCfg4_r(const int meta_handle, unsigned int ms_timeout, RfBBTXCfg4  *tx_cfg_cnf);

META_RESULT  __stdcall SP_META_Rf_SetBBTxCfg5(unsigned int ms_timeout, const RfBBTXCfg4  *tx_cfg_req, RfBBTXCfg4  *tx_cfg_cnf);
META_RESULT  __stdcall SP_META_Rf_SetBBTxCfg5_r(const int meta_handle, unsigned int ms_timeout, const RfBBTXCfg4  *tx_cfg_req, RfBBTXCfg4  *tx_cfg_cnf);
META_RESULT  __stdcall SP_META_Rf_GetBBTxCfg5(unsigned int ms_timeout, RfBBTXCfg4  *tx_cfg_cnf);
META_RESULT  __stdcall SP_META_Rf_GetBBTxCfg5_r(const int meta_handle, unsigned int ms_timeout, RfBBTXCfg4  *tx_cfg_cnf);

//-----------------------------------------------------//
//  RunTime Setting Functions Without Update NVRAM     //
//-----------------------------------------------------//
META_RESULT  __stdcall SP_META_Rf_SetRampTable(unsigned int ms_timeout, FrequencyBand  band, const l1cal_rampTable_T  *ramp);
META_RESULT  __stdcall SP_META_Rf_SetRampTable_r(const int meta_handle, unsigned int ms_timeout, FrequencyBand  band, const l1cal_rampTable_T  *ramp);
META_RESULT  __stdcall SP_META_Rf_SetRampApcLevel(const RfSetRampApcLevel_Req *req, const META_RF_SET_RAMPAPCLEVEL_CNF  cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_SetRampApcLevel_r(const int meta_handle, const RfSetRampApcLevel_Req *req, const META_RF_SET_RAMPAPCLEVEL_CNF  cb, short *token, void *usrData);
META_RESULT  __stdcall SP_META_Rf_EPSK_SetRampTable(unsigned int ms_timeout, FrequencyBand  band, const l1cal_rampTable_T  *ramp);
META_RESULT  __stdcall SP_META_Rf_EPSK_SetRampTable_r(const int meta_handle, unsigned int ms_timeout, FrequencyBand  band, const l1cal_rampTable_T  *ramp);
META_RESULT  __stdcall SP_META_Rf_EPSK_SetRampApcLevel(unsigned int ms_timeout, const RfSetRampApcLevel_Req *req);
META_RESULT  __stdcall SP_META_Rf_EPSK_SetRampApcLevel_r(const int meta_handle, unsigned int ms_timeout, const RfSetRampApcLevel_Req *req);
META_RESULT  __stdcall SP_META_Rf_SetRFImmediateBSI(unsigned int ms_timeout, const unsigned int bsi_data);
META_RESULT  __stdcall SP_META_Rf_SetRFImmediateBSI_r(const int meta_handle, unsigned int ms_timeout, const unsigned int bsi_data);
META_RESULT  __stdcall SP_META_Rf_GetRFImmediateBSI(unsigned int ms_timeout, unsigned int bsi_addr, unsigned int *p_bsi_data);
META_RESULT  __stdcall SP_META_Rf_GetRFImmediateBSI_r(const int meta_handle, unsigned int ms_timeout, unsigned int bsi_addr, unsigned int *p_bsi_data);
META_RESULT  __stdcall SP_META_Rf_SetRampTable_Ex(unsigned int ms_timeout, FrequencyBand  band, const l1cal_rampTable_T_Ex  *ramp);
META_RESULT  __stdcall SP_META_Rf_SetRampTable_Ex_r(const int meta_handle, unsigned int ms_timeout, FrequencyBand  band, const l1cal_rampTable_T_Ex  *ramp);
META_RESULT  __stdcall SP_META_Rf_SetRampTable_Ex2(unsigned int ms_timeout, FrequencyBand  band, const l1cal_rampTable_T_Ex2  *ramp);
META_RESULT  __stdcall SP_META_Rf_SetRampTable_Ex2_r(const int meta_handle, unsigned int ms_timeout, FrequencyBand  band, const l1cal_rampTable_T_Ex2  *ramp);
// Skyworks
META_RESULT  __stdcall SP_META_Rf_SKY74045_SetSpecialCoef(unsigned int ms_timeout, const RF_SKY74045_Coef_T *rf_mod_coef);
META_RESULT  __stdcall SP_META_Rf_SKY74045_SetSpecialCoef_r(const int meta_handle, unsigned int ms_timeout, const RF_SKY74045_Coef_T *rf_mod_coef);
META_RESULT  __stdcall SP_META_Rf_SKY74117_SetSpecialCoef(unsigned int ms_timeout, const RF_SKY74117_Coef_T *rf_mod_coef);
META_RESULT  __stdcall SP_META_Rf_SKY74117_SetSpecialCoef_r(const int meta_handle, unsigned int ms_timeout, const RF_SKY74117_Coef_T *rf_mod_coef);
// MT6139B
META_RESULT  __stdcall SP_META_Rf_MT6139B_SetSpecialCoef(unsigned int ms_timeout, const RF_MT6139B_Coef_T *rf_mod_coef);
META_RESULT  __stdcall SP_META_Rf_MT6139B_SetSpecialCoef_r(const int meta_handle, unsigned int ms_timeout, const RF_MT6139B_Coef_T *rf_mod_coef);
// Renesas Bright5P 
META_RESULT  __stdcall SP_META_Rf_BRIGHT5P_SetSpecialCoef(unsigned int ms_timeout, const RF_BRIGHT5P_Coef_T *rf_mod_coef);
META_RESULT  __stdcall SP_META_Rf_BRIGHT5P_SetSpecialCoef_r(const int meta_handle, unsigned int ms_timeout, const RF_BRIGHT5P_Coef_T *rf_mod_coef);
META_RESULT  __stdcall SP_META_Rf_32kCalibration(unsigned int ms_timeout, int *p_result);
META_RESULT  __stdcall SP_META_Rf_32kCalibration_r(const int meta_handle, unsigned int ms_timeout, int *p_result);
META_RESULT  __stdcall SP_META_Rf_AD6546_SetSpecialCoef(unsigned int ms_timeout, const ad6546tx *rf_mod_coef, const char *buf, const int buf_len);
META_RESULT  __stdcall SP_META_Rf_AD6546_SetSpecialCoef_r(const int meta_handle, unsigned int ms_timeout, const ad6546tx *rf_mod_coef, const char *buf, const int buf_len);


// MD
META_RESULT __stdcall SP_META_SendMDCmd(unsigned int ms_timeout, MD_FRAME *frame/*in & out*/);
META_RESULT __stdcall SP_META_SendMDCmd_r(int meta_handle, unsigned int ms_timeout, MD_FRAME *frame/*in & out*/);

// LED
META_RESULT  __stdcall SP_META_SetLEDLightLevel(unsigned int ms_timeout, KeypadBK_REQ *req);
META_RESULT  __stdcall SP_META_SetLEDLightLevel_r(const int meta_handle, unsigned int ms_timeout, KeypadBK_REQ *req);


// TDMB Functions

META_RESULT  __stdcall SP_META_TDMB_TurnOn(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_TDMB_TurnOn_r(const int meta_handle, unsigned int ms_timeout);
// send band may return: META_TDMB_ERR_BAND_NOT_EXIST, META_SUCCESS, META_FAILED
META_RESULT __stdcall SP_META_TDMB_SetBand(unsigned int ms_timeout, TDMB_SET_BAND_REQ_T *req);
META_RESULT __stdcall SP_META_TDMB_SetBand_r(const int meta_handle, unsigned int ms_timeout, TDMB_SET_BAND_REQ_T *req);
META_RESULT __stdcall SP_META_TDMB_AutoScan_GetFreq(unsigned int ms_timeout, TDMB_AUTO_SCAN_CNF_T *cnf);
META_RESULT __stdcall SP_META_TDMB_AutoScan_GetFreq_r(const int meta_handle, unsigned int ms_timeout, TDMB_AUTO_SCAN_CNF_T *cnf);
META_RESULT __stdcall SP_META_TDMB_SetFreq(unsigned int ms_timeout, TDMB_SET_FREQ_REQ_T *req, TDMB_SET_FREQ_CNF_T *cnf);
META_RESULT __stdcall SP_META_TDMB_SetFreq_r(const int meta_handle, unsigned int ms_timeout, TDMB_SET_FREQ_REQ_T *req, TDMB_SET_FREQ_CNF_T *cnf);
META_RESULT __stdcall SP_META_TDMB_AutoScan_GetEnsemble(unsigned int ms_timeout, TDMB_GET_ENSM_INFO_BY_AUTO_SCAN_CNF_T *cnf);
META_RESULT __stdcall SP_META_TDMB_AutoScan_GetEnsemble_r(const int meta_handle, unsigned int ms_timeout, TDMB_GET_ENSM_INFO_BY_AUTO_SCAN_CNF_T *cnf);
META_RESULT __stdcall SP_META_TDMB_GetSignal(unsigned int ms_timeout, TDMB_GET_SIGNAL_CNF_T *cnf);
META_RESULT __stdcall SP_META_TDMB_GetSignal_r(const int meta_handle, unsigned int ms_timeout, TDMB_GET_SIGNAL_CNF_T *cnf);
//META_RESULT __stdcall META_TDMB_SelService(unsigned int ms_timeout, TDMB_SEL_SERVICE_REQ_T *req);
//META_RESULT __stdcall META_TDMB_SelService_r(const int meta_handle, unsigned int ms_timeout, TDMB_SEL_SERVICE_REQ_T *req);
META_RESULT __stdcall SP_META_TDMB_SelService(unsigned int ms_timeout, TDMB_SEL_SERVICE_REQ_T *req, const META_TDMB_SEL_SERV_CNF  cnf_cb);
META_RESULT __stdcall SP_META_TDMB_SelService_r(const int meta_handle, unsigned int ms_timeout, TDMB_SEL_SERVICE_REQ_T *req, const META_TDMB_SEL_SERV_CNF  cnf_cb);
//META_RESULT __stdcall META_TDMB_SetIdle(unsigned int ms_timeout);
//META_RESULT __stdcall META_TDMB_SetIdle_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT __stdcall SP_META_TDMB_SetIdle(unsigned int ms_timeout, CALLBACK_META_FAT_PROGRESS  cb_progress, void  *cb_progress_arg);
META_RESULT __stdcall SP_META_TDMB_SetIdle_r(const int meta_handle, unsigned int ms_timeout, CALLBACK_META_FAT_PROGRESS  cb_progress, void  *cb_progress_arg);
META_RESULT __stdcall SP_META_TDMB_TurnOff(unsigned int ms_timeout);
META_RESULT __stdcall SP_META_TDMB_TurnOff_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT __stdcall SP_META_TDMB_GetEnsm(unsigned int ms_timeout, TDMB_GET_ENSM_CNF_T *cnf);
META_RESULT __stdcall SP_META_TDMB_GetEnsm_r(const int meta_handle, unsigned int ms_timeout, TDMB_GET_ENSM_CNF_T *cnf);
META_RESULT __stdcall SP_META_TDMB_SelServiceOnly( unsigned int ms_timeout, TDMB_SEL_SERVICE_ONLY_REQ_T *req);
META_RESULT __stdcall SP_META_TDMB_SelServiceOnly_r(const int meta_handle, unsigned int ms_timeout, TDMB_SEL_SERVICE_ONLY_REQ_T *);
META_RESULT __stdcall SP_META_TDMB_StopAutoScan(unsigned int ms_timeout);
META_RESULT __stdcall SP_META_TDMB_StopAutoScan_r(const int meta_handle, unsigned int ms_timeout);

// Misc
META_RESULT  __stdcall SP_META_CTI_SendPacketCmd(const unsigned char *pPayLoadBuffer, int nPayloadLength);
META_RESULT  __stdcall SP_META_CTI_SendPacketCmd_r(const int meta_handle, const unsigned char *pPayLoadBuffer, int nPayloadLength);
META_RESULT  __stdcall SP_META_CTI_SetPacketCallback(META_CTI_CallBack  pCBFunc, void* param);
META_RESULT  __stdcall SP_META_CTI_SetPacketCallback_r(const int meta_handle, META_CTI_CallBack  pCBFunc, void* param);

// HW Test Tool Manual test.
META_RESULT  __stdcall SP_META_Audio_GetSupportAfeRegAccess(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_Audio_GetSupportAfeRegAccess_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_Audio_RunAfeRegAccess(unsigned int ms_timeout);
META_RESULT  __stdcall SP_META_Audio_RunAfeRegAccess_r(const int meta_handle, unsigned int ms_timeout);


//-----------------------------------------------------//
//  DFO Editor Functions              //
//-----------------------------------------------------//
typedef struct 
{
    unsigned char reserved;   //just reserved
} DFO_QUERY_STATUS_REQ;

typedef struct 
{
    unsigned char   support;    // 1 means support; 0 means unsupport
} DFO_QUERY_STATUS_CNF;

typedef struct 
{
    unsigned char reserved;   //just reserved
} DFO_READ_COUNT_REQ;

typedef struct 
{
     int count;
} DFO_READ_COUNT_CNF;

typedef struct
{
    int index;          //[0, count)
} DFO_READ_REQ;

typedef struct
{
    char name[32];          //read result, dfo name
    int value;              //read result, dfo value
	int partition;      // 0: NVRAM, 1: MISC
} DFO_READ_CNF;
  
typedef struct
{
    char name[32];
    int value;
	int  partition;      // 0: NVRAM, 1: MISC
    int  save;           // 0: don't save to MISC/NVRAM, 1: save to MISC/NVRAM
} DFO_WRITE_REQ;

typedef struct
{
	unsigned char status;    //the status of ft module:  0 is success
} DFO_WRITE_CNF;

typedef struct
{
    unsigned char reserved;
} DFO_COMBO_COUNT_REQ;

typedef struct
{
    int     count;
} DFO_COMBO_COUNT_CNF;

typedef struct
{
    int     index;          // [0, count) of combo
} DFO_COMBO_READ_REQ;

typedef struct
{
    char    name[32];       // read result, combo name
    int     modeCount;      // read result, the number of mode
} DFO_COMBO_READ_CNF;

typedef struct
{
    int     index;          // [0, count) of combo
    int     modeIndex;      // [0, modeCount) of the mode of a combo
} DFO_COMBO_MODE_REQ;

typedef struct
{
    char    name[32];       // read result, the mode name of a combo
} DFO_COMBO_MODE_CNF;

typedef struct
{
    int     index;          // [0, count) of combo
    int     modeIndex;      // [0, modeCount) of the mode of a combo
} DFO_COMBO_UPDATE_REQ;

typedef struct
{
    int     status;
} DFO_COMBO_UPDATE_CNF;

META_RESULT __stdcall SP_META_DFO_Query_Status(unsigned int ms_timeout, DFO_QUERY_STATUS_CNF *pCnf);
META_RESULT __stdcall SP_META_DFO_Query_Status_r(const int meta_handle, unsigned int ms_timeout, DFO_QUERY_STATUS_CNF *pCnf);

META_RESULT __stdcall SP_META_DFO_Read_Count(unsigned int ms_timeout, DFO_READ_COUNT_CNF *pCnf);
META_RESULT __stdcall SP_META_DFO_Read_Count_r(const int meta_handle, unsigned int ms_timeout, DFO_READ_COUNT_CNF *pCnf);
 
META_RESULT __stdcall SP_META_DFO_Read(unsigned int ms_timeout, DFO_READ_REQ *pReq, DFO_READ_CNF *pCnf);
META_RESULT __stdcall SP_META_DFO_Read_r(const int meta_handle, unsigned int ms_timeout, DFO_READ_REQ *pReq, DFO_READ_CNF *pCnf);

META_RESULT __stdcall SP_META_DFO_Write(unsigned int ms_timeout, DFO_WRITE_REQ *pReq, DFO_WRITE_CNF *pCnf);
META_RESULT __stdcall SP_META_DFO_Write_r(const int meta_handle, unsigned int ms_timeout, DFO_WRITE_REQ *pReq, DFO_WRITE_CNF *pCnf);

META_RESULT __stdcall SP_META_DFO_Combo_Count(unsigned int ms_timeout, DFO_COMBO_COUNT_CNF *pCnf);
META_RESULT __stdcall SP_META_DFO_Combo_Count_r(const int meta_handle, unsigned int ms_timeout, DFO_COMBO_COUNT_CNF *pCnf);

META_RESULT __stdcall SP_META_DFO_Combo_Read(unsigned int ms_timeout, DFO_COMBO_READ_REQ *pReq, DFO_COMBO_READ_CNF *pCnf);
META_RESULT __stdcall SP_META_DFO_Combo_Read_r(const int meta_handle, unsigned int ms_timeout, DFO_COMBO_READ_REQ *pReq, DFO_COMBO_READ_CNF *pCnf);

META_RESULT __stdcall SP_META_DFO_Combo_Mode(unsigned int ms_timeout, DFO_COMBO_MODE_REQ *pReq, DFO_COMBO_MODE_CNF *pCnf);
META_RESULT __stdcall SP_META_DFO_Combo_Mode_r(const int meta_handle, unsigned int ms_timeout, DFO_COMBO_MODE_REQ *pReq, DFO_COMBO_MODE_CNF *pCnf);

META_RESULT __stdcall SP_META_DFO_Combo_Update(unsigned int ms_timeout, DFO_COMBO_UPDATE_REQ *pReq, DFO_COMBO_UPDATE_CNF *pCnf);
META_RESULT __stdcall SP_META_DFO_Combo_Update_r(const int meta_handle, unsigned int ms_timeout, DFO_COMBO_UPDATE_REQ *pReq, DFO_COMBO_UPDATE_CNF *pCnf);
//DFO Editor end


//DRM Key Install
typedef struct 
{
    unsigned int result;
} DRMKEY_INSTALL_SET_CNF;

typedef struct
{
    unsigned int req;  // unused
} DRMKEY_INSTALL_QUERY_REQ;

typedef struct
{
	unsigned int  keycount;
	unsigned int  keytype[512];
} DRMKEY_INSTALL_QUERY_CNF;

typedef struct
{
   	unsigned int  keylength;
	unsigned char content[128];
} DRMKEY_WRITE_MCID_REQ;

typedef struct 
{
    unsigned int result;
} DRMKEY_WRITE_MCID_CNF;

typedef struct
{
    unsigned int req;  // unused
} DRMKEY_READ_MCID_REQ;

typedef struct 
{
	unsigned int  keylength;
	unsigned char content[128];
} DRMKEY_READ_MCID_CNF;
META_RESULT __stdcall SP_META_DRMKey_Install_Set(unsigned int  ms_timeout, const char *file, DRMKEY_INSTALL_SET_CNF *pCnf);
META_RESULT __stdcall SP_META_DRMKey_Install_Set_r(const int meta_handle, unsigned int  ms_timeout, const char *file, DRMKEY_INSTALL_SET_CNF *pCnf);


META_RESULT __stdcall SP_META_DRMKey_Install_Query(unsigned int  ms_timeout, DRMKEY_INSTALL_QUERY_REQ *pReq, DRMKEY_INSTALL_QUERY_CNF *pCnf);
META_RESULT __stdcall SP_META_DRMKey_Install_Query_r(const int meta_handle, unsigned int  ms_timeout, DRMKEY_INSTALL_QUERY_REQ *pReq, DRMKEY_INSTALL_QUERY_CNF *pCnf);

META_RESULT __stdcall SP_META_DRMKey_Write_MCID(unsigned int  ms_timeout, DRMKEY_WRITE_MCID_REQ *pReq, DRMKEY_WRITE_MCID_CNF *pCnf);
META_RESULT __stdcall SP_META_DRMKey_Write_MCID_r(const int meta_handle, unsigned int  ms_timeout, DRMKEY_WRITE_MCID_REQ *pReq, DRMKEY_WRITE_MCID_CNF *pCnf);

META_RESULT __stdcall SP_META_DRMKey_Read_MCID(unsigned int  ms_timeout, DRMKEY_READ_MCID_REQ *pReq, DRMKEY_READ_MCID_CNF *pCnf);
META_RESULT __stdcall SP_META_DRMKey_Read_MCID_r(const int meta_handle, unsigned int  ms_timeout, DRMKEY_READ_MCID_REQ *pReq, DRMKEY_READ_MCID_CNF *pCnf);

//HDCP
typedef struct 
{
	unsigned int install_result;   //0 means success, 1 means fail
} HDCP_INSTALL_CNF;

META_RESULT __stdcall SP_META_HDCP_Install(unsigned int  ms_timeout, const char *file, const char *cek_file, HDCP_INSTALL_CNF *pCnf);
META_RESULT __stdcall SP_META_HDCP_Install_r(const int meta_handle, unsigned int  ms_timeout, const char *file, const char *cek_file, HDCP_INSTALL_CNF *pCnf);
//-------------END---------------

//special test
typedef struct
{
	int  reserved;  //no use
}SPECIALTEST_HUGEDATA_REQ;

typedef struct
{
    unsigned char result;
}SPECIALTEST_HUGEDATA_CNF;


META_RESULT  __stdcall SP_META_SpecialTest_HugeData(unsigned int ms_timeout, unsigned int datasize);
META_RESULT  __stdcall SP_META_SpecialTest_HugeData_r(const int meta_handle, unsigned int ms_timeout, unsigned int datasize);

META_RESULT  __stdcall SP_META_SpecialTest_RawData(unsigned int ms_timeout, unsigned char *dest, unsigned char *src, unsigned int datasize);
META_RESULT  __stdcall SP_META_SpecialTest_RawData_r(const int meta_handle, unsigned int ms_timeout, unsigned char *dest, unsigned char *src, unsigned int datasize);


//-----------------------------------------------------//
//  Switch SIM Functions							   //
//-----------------------------------------------------//

typedef struct  
{
	unsigned int reserved;
}SIM_QUERY_MDTYPE_REQ;

typedef struct  
{
	unsigned int md_type;
}SIM_QUERY_MDTYPE_CNF;

typedef struct  
{
	unsigned int reserved;
}SIM_QUERY_PRJTYPE_REQ;

typedef struct  
{
	unsigned int prj_type;
}SIM_QUERY_PRJTYPE_CNF;

typedef struct  
{
	unsigned int reserved;
}SIM_QUERY_MDIDXSET_REQ;

typedef struct  
{
	unsigned int md_idxset;
}SIM_QUERY_MDIDXSET_CNF;

typedef struct  
{
	unsigned int mode_cmd;
}SIM_SET_SWITCHER_REQ;

typedef struct  
{
	unsigned int reserved;
}SIM_SET_SWITCHER_CNF;

typedef struct  
{
	unsigned int reserved;
}SIM_QUERY_SSW_REQ;

typedef struct  
{
	unsigned int ssw_val;
}SIM_QUERY_SSW_CNF;


META_RESULT __stdcall SP_META_SIM_Check_ExtMd_r(const int meta_handle, unsigned int  ms_timeout, SIM_QUERY_MDTYPE_REQ *pReq ,SIM_QUERY_MDTYPE_CNF *pCnf);
META_RESULT __stdcall SP_META_SIM_Check_ExtMd(unsigned int  ms_timeout, SIM_QUERY_MDTYPE_REQ *pReq ,SIM_QUERY_MDTYPE_CNF *pCnf);

META_RESULT __stdcall SP_META_SIM_Query_PrjType_r(const int meta_handle, unsigned int  ms_timeout, SIM_QUERY_PRJTYPE_REQ *pReq ,SIM_QUERY_PRJTYPE_CNF *pCnf);
META_RESULT __stdcall SP_META_SIM_Query_PrjType(unsigned int  ms_timeout, SIM_QUERY_PRJTYPE_REQ *pReq ,SIM_QUERY_PRJTYPE_CNF *pCnf);

META_RESULT __stdcall SP_META_SIM_Query_MdIdxSet_r(const int meta_handle, unsigned int  ms_timeout, SIM_QUERY_MDIDXSET_REQ *pReq ,SIM_QUERY_MDIDXSET_CNF *pCnf);
META_RESULT __stdcall SP_META_SIM_Query_MdIdxSet(unsigned int  ms_timeout, SIM_QUERY_MDIDXSET_REQ *pReq ,SIM_QUERY_MDIDXSET_CNF *pCnf);

META_RESULT __stdcall SP_META_SIM_Set_Switcher_r(const int meta_handle, unsigned int  ms_timeout, SIM_SET_SWITCHER_REQ *pReq ,SIM_SET_SWITCHER_CNF *pCnf);
META_RESULT __stdcall SP_META_SIM_Set_Switcher(unsigned int  ms_timeout, SIM_SET_SWITCHER_REQ *pReq ,SIM_SET_SWITCHER_CNF *pCnf);

META_RESULT __stdcall SP_META_SIM_Query_SSW_r(const int meta_handle, unsigned int  ms_timeout, SIM_QUERY_SSW_REQ *pReq ,SIM_QUERY_SSW_CNF *pCnf);
META_RESULT __stdcall SP_META_SIM_Query_SSW(unsigned int  ms_timeout, SIM_QUERY_SSW_REQ *pReq, SIM_QUERY_SSW_CNF *pCnf);

//query WCN driver ready
typedef struct
{
    unsigned int result;
}QUERY_WCNDRIVER_READY_CNF;

META_RESULT __stdcall SP_META_Query_WCNDriver_Ready_r(const int meta_handle, unsigned int  ms_timeout, QUERY_WCNDRIVER_READY_CNF *pCnf);
META_RESULT __stdcall SP_META_Query_WCNDriver_Ready(unsigned int  ms_timeout, QUERY_WCNDRIVER_READY_CNF *pCnf);


typedef struct  
{
	unsigned char path_name[256];    //folder path
	unsigned char filename_substr[256];  //file name sub string,if set it as "*", we will parse all the file in the folder
}FILE_OPERATION_PARSE_REQ;

typedef struct  
{
	unsigned int file_count;        //file count for folder
}FILE_OPERATION_PARSE_CNF;


typedef struct  
{
	unsigned int index;             //[0, file_count)
}FILE_OPERATION_GETFILEINFO_REQ;

typedef enum 
{
	FT_FILE_TYPE_INVALID = 0,
	FT_FILE_TYPE_FILE = 1,
	FT_FILE_TYPE_FOLDER = 2,
	FT_FILE_TYPE_END = 0x0fffffff
}FT_FILE_TYPE;

typedef struct
{
	unsigned int file_type;
	unsigned int file_size;    //if the file_type is folder, we will return file_size as 0.
	unsigned char file_name[256];
}FT_FILE_INFO;

typedef struct  
{
    FT_FILE_INFO file_info;	
}FILE_OPERATION_GETFILEINFO_CNF;


META_RESULT __stdcall SP_META_File_Operation_Parse_r(const int meta_handle, unsigned int  ms_timeout, FILE_OPERATION_PARSE_REQ *pReq, FILE_OPERATION_PARSE_CNF *pCnf);
META_RESULT __stdcall SP_META_File_Operation_Parse(unsigned int  ms_timeout, FILE_OPERATION_PARSE_REQ *pReq, FILE_OPERATION_PARSE_CNF *pCnf);

META_RESULT __stdcall SP_META_File_Operation_GetFileInfo_r(const int meta_handle, unsigned int  ms_timeout, FILE_OPERATION_GETFILEINFO_REQ *pReq, FILE_OPERATION_GETFILEINFO_CNF *pCnf);
META_RESULT __stdcall SP_META_File_Operation_GetFileInfo(unsigned int  ms_timeout, FILE_OPERATION_GETFILEINFO_REQ *pReq, FILE_OPERATION_GETFILEINFO_CNF *pCnf);

META_RESULT __stdcall SP_META_File_Operation_SendFile_r(const int meta_handle, unsigned int  ms_timeout, const char *pSourceFileName, const char *pDestFileName);
META_RESULT __stdcall SP_META_File_Operation_SendFile(unsigned int  ms_timeout, const char *pSourceFileName, const char *pDestFileName);

META_RESULT __stdcall SP_META_File_Operation_ReceiveFile_r(const int meta_handle, unsigned int  ms_timeout, const char *pSourceFileName, const char *pDestFileName);
META_RESULT __stdcall SP_META_File_Operation_ReceiveFile(unsigned int  ms_timeout, const char *pSourceFileName, const char *pDestFileName);
////////////////////////////////////////////////////////////////////////////
/*****************For production line tool test flag start*****************/

/////////////////////////////////////////////////////////
/***************From mtk_test_flag.h file***************/
/* 
* ****************************************
*                 ATE_Tool
* ****************************************
*/
typedef struct _s_ate_gsm_flag
{
    unsigned char        total_pass:1;
    unsigned char        tadc:1;
    unsigned char        afc:1;
    unsigned char        capid:1;
    unsigned char        agc:1;
    unsigned char        w_coe:1;
    unsigned char        gmsk_apc:1;
    unsigned char        gmsk_apc_subband:1;
    unsigned char        epsk_apc:1;
    unsigned char        epsk_apc_subband:1;
    unsigned char        LPM:1;
    unsigned char        trx_offset:1;
    unsigned char        b_reserved:4;
    unsigned char        reserved[2];
} s_ate_gsm_flag;         // 4Bytes

typedef struct _s_ate_tdscdma_flag
{
    unsigned char        total_pass:1;
    unsigned char        tadc:1;
    unsigned char        afc:1;
    unsigned char        capid:1;
    unsigned char        agc:1;
    unsigned char        apc:1;
    unsigned char        subband:1;
    unsigned char        b_reserved:1;
    unsigned char        reserved[1];
} s_ate_tdscdma_flag;    // 2Bytes

typedef struct _s_ate_wcdma_flag
{
    unsigned char        total_pass:1;
    unsigned char        tadc:1;
    unsigned char        afc:1;
    unsigned char        capid:1;
    unsigned char        agc:1;
    unsigned char        rxd:1;
    unsigned char        apc:1;
    unsigned char        subband:1;
    unsigned char        reserved[1];
} s_ate_wcdma_flag;      // 2Bytes

typedef struct _s_ate_tddlte_flag
{
    unsigned char        total_pass:1;
    unsigned char        tadc:1;
    unsigned char        afc:1;
    unsigned char        capid:1;
    unsigned char        agc:1;
    unsigned char        rxd:1;
    unsigned char        apc:1;
    unsigned char        subband :1;
    unsigned char        reserved[1];
} s_ate_tddlte_flag;    // 2Bytes

typedef struct _s_ate_fddlte_flag
{
    unsigned char        total_pass:1;
    unsigned char        tadc:1;
    unsigned char        afc:1;
    unsigned char        capid:1;
    unsigned char        agc:1;
    unsigned char        rxd:1;
    unsigned char        apc:1;
    unsigned char        subband :1;
    unsigned char        reserved[1];
} s_ate_fddlte_flag;    // 2Bytes

typedef struct _s_ate_cdma_flag
{
    unsigned char        reserved[2];
} s_ate_cdma_flag;      // 2Bytes

typedef struct _s_ate_nsft_flag
{
    unsigned char        gsm:1;
    unsigned char        tdscdma:1;
    unsigned char        wcdma:1;
    unsigned char        tddlte:1;
    unsigned char        fddlte:1;
    unsigned char        cdma:1;
    
    unsigned char        b_reserved:2;
    unsigned char        reserved[1];
} s_ate_nsft_flag;      // 2Bytes

typedef struct _s_ate_wireless_flag
{
    unsigned char        gsm:1;
    unsigned char        tdscdma:1;
    unsigned char        wcdma:1;
    unsigned char        tddlte:1;
    unsigned char        fddlte:1;
    unsigned char        cdma:1;
    
    unsigned char        b_reserved:2;
    unsigned char        reserved[1];
} s_ate_wireless_flag;  // 2Bytes

typedef struct s_ate_other_flag
{
    unsigned char        gpscoclock:1;
    unsigned char        b_reserved:7;
} s_ate_other_flag;     // 1Bytes

typedef struct _s_ate_flag
{
    unsigned char                    sw_index;
    unsigned char                    md_index;
    
    s_ate_gsm_flag        	gsm_flag;
    s_ate_tdscdma_flag  	tdscdma_flag;
    s_ate_wcdma_flag     	wcdma_flag;
    s_ate_tddlte_flag    	tddlte_flag;
    s_ate_fddlte_flag    	fddlte_flag;
    s_ate_cdma_flag         cdma_flag;
    s_ate_other_flag      	other_flag;
    s_ate_nsft_flag      	nsft_flag;
    s_ate_wireless_flag 	wireless_flag;
    
    unsigned char                    reserved[3];
} s_ate_flag;       // 24Bytes


/* 
* ****************************************
*                 WCN_ATE_Tool
* ****************************************
*/
typedef struct _s_wcn_ate_flag
{
    unsigned char        wifi_2g_cal:1;
    unsigned char        wifi_5g_cal:1;
    unsigned char	    cal_reserved:6;
    
    unsigned char        wifi:1;
    unsigned char        bt:1;
    unsigned char        gps:1;
    unsigned char        fm:1;
    unsigned char	    nsft_reserved:4;
    unsigned char	    reserved[2];
} s_wcn_ate_flag;   // 4Bytes

/* 
* ****************************************
*                 HW_Test_Tool
* ****************************************
*/
typedef struct _s_hw_test_flag
{
    //total pass flag
    unsigned char        total_pass:1;
    
    //test item check flag
    //Auto Test
    unsigned char        bluebooth_check:1;
    unsigned char        wifi_check:1;
    unsigned char        gps_check:1;
    unsigned char        fm_check:1;
    unsigned char        sdcard_check:1;
    unsigned char        sim1_check:1;
    unsigned char        sim2_check:1;
    unsigned char        msensor_check:1;
    unsigned char        gsensor_check:1;
    unsigned char        alspssensor_check:1;
    unsigned char        ctp_check:1;
    unsigned char        nfc_check:1;
    unsigned char        sdio_autoK:1;
    unsigned char        b_reserved_auto_check:2; //2 Bytes
    unsigned char        reserved_auto_check[2];  //2 Bytes
    
    //Manual Test
    unsigned char        keypadled_check:1;
    unsigned char        vibrator_check:1;
    unsigned char        indexled_check:1;
    unsigned char        lcmbacklight_check:1;
    unsigned char        lcm_check:1;
    unsigned char        speakerl_check:1;
    unsigned char        speakerr_check:1;
    unsigned char        receiver_check:1;
    unsigned char        mic1loopback_check:1;
    unsigned char        mic2loopback_check:1;
    unsigned char        photoflash_check:1;
    unsigned char        camera_check:1;
    unsigned char        subcamera_check:1;
    unsigned char        b_reserved_manual_check:3; //2 Bytes
    unsigned char        reserved_manual_check[2];  //2 Bytes
    //test item check flag end(26bit)
    
    //test item flag
    //Auto Test
    unsigned char        bluebooth:1;
    unsigned char        wifi:1;
    unsigned char        gps:1;
    unsigned char        fm:1;
    unsigned char        sdcard:1;
    unsigned char        sim1:1;
    unsigned char        sim2:1;
    unsigned char        msensor:1;
    unsigned char        gsensor:1;
    unsigned char        alspssensor:1;
    unsigned char        ctp:1;
    unsigned char        nfc:1;
    unsigned char        sdio:1;
    unsigned char        b_reserved_auto:3; //2 Bytes
    unsigned char        reserved_auto[2];  //2 Bytes
    
    //Manual Test
    unsigned char        keypadled:1;
    unsigned char        vibrator:1;
    unsigned char        indexled:1;
    unsigned char        lcmbacklight:1;
    unsigned char        lcm:1;
    unsigned char        speakerl:1;
    unsigned char        speakerr:1;
    unsigned char        receiver:1;
    unsigned char        mic1loopback:1;
    unsigned char        mic2loopback:1;
    unsigned char        photoflash:1;
    unsigned char        camera:1;
    unsigned char        subcamera:1;
    unsigned char        b_reserved_manual:3; //2 Bytes
    unsigned char        reserved_manual[2];  //2 Bytes
    //test item flag end(51bit)
    
    //default no use
    //Auto Test
    unsigned char        dvb_check:1;
    unsigned char        battery_check:1;
    unsigned char        pmic_check:1;
    unsigned char        eint_check:1;
    unsigned char        gpioin_check:1;
    unsigned char        sim3_check:1;
    unsigned char        sim4_check:1;
    //Manual Test
    unsigned char        earphone_check:1;
    unsigned char        pwm_check:1;
    unsigned char        sleepmode_check:1;
    unsigned char        charging_check:1;
    unsigned char        gpiooutput_check:1;
    
    //Auto Test
    unsigned char        dvb:1;
    unsigned char        battery:1;
    unsigned char        pmic:1;
    unsigned char        eint:1;
    unsigned char        gpioin:1;
    unsigned char        sim3:1;
    unsigned char        sim4:1;
    //Manual Test
    unsigned char        earphone:1;
    unsigned char        pwm:1;
    unsigned char        sleepmode:1;
    unsigned char        charging:1;
    unsigned char        gpiooutput:1;
    
    unsigned char        reserved[1];    //1 Byte
} s_hw_test_flag;               // 20Bytes

/* 
* ****************************************
*            ATA_Tool & Factory Mode
* ****************************************
*/
typedef struct _s_factory_mode_flag
{
    unsigned char	    reserved[20];
} s_factory_mode_flag;	// 20Bytes

/* 
* ****************************************
*            s_proinfo_test_flag
* ****************************************
*/
typedef struct _s_mtk_test_flag
{
    s_ate_flag			ate_flag[5];	// 120Bytes
    s_wcn_ate_flag		wcn_ate_flag;	// 4Bytes
    s_hw_test_flag		hw_test_flag;	// 20Bytes
    s_factory_mode_flag	factory_mode_flag; // 20Bytes
    unsigned char	            reserved[16];
} s_mtk_test_flag;	// 180Bytes
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
/*********From CFG_PRODUCT_INFO_File.h file*************/
// the record structure define of PRODUCT_INFO nvram file
typedef struct
{
    unsigned char   imei[8];
    unsigned char   svn;
    unsigned char   pad;
} nvram_ef_imei_imeisv_struct;

typedef struct
{
    unsigned char   BTAddr[6];
    unsigned char   WifiAddr[6];
    unsigned char   ADBSeriaNo[20];
    unsigned char   revered[32];
} s_target_info_record;

typedef struct
{
    unsigned char               barcode[64];    // 64B
    nvram_ef_imei_imeisv_struct IMEI[4];        // 40B
    s_target_info_record        target_info;    // 64B
    s_mtk_test_flag             mtk_test_flag;  // 180B
    unsigned char reserved[1024-180-64-40-64];
}PRODUCT_INFO;
/////////////////////////////////////////////////////////

/*******************For production line tool test flag end*****************/
////////////////////////////////////////////////////////////////////////////

//};

#ifdef __cplusplus
}
#endif

#endif







