#ifndef _SN_COMMON_H_
#define _SN_COMMON_H_

#include "flashtool_handle.h"
#include "SNFstream.h"
#include "SLA.h"
#include "AUTH.h"
#include "SCERT.h"
#include "meta.h"


#if defined(_WIN32)
#include <windows.h>
#elif defined(__GNUC__)
typedef int HANDLE;
#endif

#define M2S(x) #x

#define  ERROR 0
#define  OK 1
#define  MAX_LOG_LENGTH 1024

#define INVALID_META_HANDLE -1
#define MAX_SUPPORT_COMPORT_NUM 4

#define META_CONNECT_TIME_OUT  80000  //30000
#define META_BOOT_TIMERS  3
#define META_BOOT_STOP 9876
#define SP_DEFAULT_BROM_START_CMD_RETRY_COUNT  1

#define HEADER_MAX_LENGTH 8
#define MAX_IMEI_NUMS 4
#define IMEI_MAX_LENGTH  15
#define IMEI_ARRAY_LEN (IMEI_MAX_LENGTH + 1)
#define BARCODE_MAX_LENGTH  64
#define BARCODE_ARRAY_LEN  BARCODE_MAX_LENGTH+1
#define BD_ADDR_LEN  6
#define BT_ADDRESS_MAX_LENGTH  ( BD_ADDR_LEN * 2 )
#define BT_ARRAY_LEN  ( BT_ADDRESS_MAX_LENGTH + 1 )
/*
#define VENDOR_ID_LEN 6
#define VENDOR_ID_MAX_LENGTH (VENDOR_ID_LEN *2)
#define VENDOR_ARRAY_LEN (VENDOR_ID_MAX_LENGTH + 1)
*/
#define MAC_ADDR_LEN  6
#define WIFI_MAC_MAX_LENGTH  ( MAC_ADDR_LEN * 2 )
#define WIFI_ARRAY_LEN  ( WIFI_MAC_MAX_LENGTH + 1)
#define EEPROM_SIZE 512
#define ETHERNET_MAC_ARRAY_LEN (WIFI_ARRAY_LEN)
#define DRMKEY_MCID_LENGTH 32
#define DRMKEY_MCID_ARRAY_LEN (DRMKEY_MCID_LENGTH + 1)

#define MEID_LENGTH 14
#define MEID_ARRAY_LEN (MEID_LENGTH + 1)
#define ESN_LENGTH 8
#define ESN_ARRAY_LEN (ESN_LENGTH + 1)

//#define THREAD_SCAN_DATA 
//#define WM_RESIZEPAGE WM_APP+1
#define LOGIN_PASSWORD_MAX 64

typedef enum
{
    ENGINEER = 0,
    OPERATOR = 1,
    UNKNOW_IDENTIFY = 256
}Login_Identify_e;

typedef enum
{
    DENARY_RADIX = 0,   //Denary notation
    HEX_RADIX           //Hexadecimal
}Radix_e;

enum 
{  CDF_CENTER, 
   CDF_TOPLEFT, 
};

typedef enum
{
    BUSY = 0,
    FREE = 1
}Thread_Resource_Status_e;

typedef enum
{
    FAIL = 0,
    PASS = 1,
    CANCEL = 2,
    NORMAL = 255
}WriteNvram_Status_e;

typedef enum
{
    WRITE_BARCODE = 0,
    WRITE_IMEI,
    WRITE_BT,
    WRITE_WIFI,
    WRITE_ETHERNET_MAC,
    WRITE_PRODINFO,
    WRITE_TEMPERATURE,
	WRITE_MEID,
	WRITE_ESN
    // WRITE_VENDORID     //20141021 BY MENGXU
}WriteData_Type_e;

typedef enum
{       
    CAL_FLAG_PASS = 0,
    CAL_FLAG_FAILED = 1,
    CAL_FLAG_NOT_EXIST = 2,
}CheckCalFlag_Status_e;

typedef enum
{       
    FT_FLAG_PASS = 0,
    FT_FLAG_FAILED = 1,
    FT_FLAG_NOT_EXIST = 2,
}CheckFinalTestFlag_Status_e;


typedef struct  
{
    int iThreadIndex;
    int iComPort;
    int iKernelComPort;
    bool bThreadStart;
}Thread_Info_s;

typedef struct  
{
    int iComPort;
    int iKernelComPort;
    bool bUse;
}SPComPort_Info_s;

typedef struct
{
    bool bCheckHeader;
    char strHeader[HEADER_MAX_LENGTH+1];
}HeaderOption_struct;

typedef enum {
    NONE_IMEI = 0,
        ONE_IMEI,
        DUAL_IMEI,
        THREE_IMEI,
        FOUR_IMEI      
} E_IMEI_NUM;

typedef struct
{
    bool bWriteTemperature;
	char strTemperatureData[10];
}Temperature_Option;

typedef struct
{
    int iImeiNums;
    bool bDualIMEI;
    bool bThreeIMEI;
    bool bFourIMEI;
    bool bLockIMEI;
    bool bCheckSum;
    bool bDualIMEISame;
    Temperature_Option Temp_Option;
}IMEIOption_struct;
/*
typedef struct
{
    bool bExtMdDl;
}BarcodeOption_struct;
*/
typedef struct
{
    bool bDBInitModem_1;
    bool bDBInitModem_2;
    bool bDBInitAP;
    char strMD1Dbpath[MAX_PATH];
    char strMD2Dbpath[MAX_PATH];
    char strAPDbpath[MAX_PATH];
}DBFileOption_struct;

typedef struct
{
    char strFPAuthPath[MAX_PATH];
    char strSPAuthPath[MAX_PATH];
    char strHdcpBinPath[MAX_PATH];
    char strDrmKeyPath[MAX_PATH];
    char strHdcpDataPath[MAX_PATH];
    char strHdcpCekPath[MAX_PATH];
}LoadFile_struct;

typedef struct
{
    char strBromFilter[MAX_PATH];
    char strPreloaderFilter[MAX_PATH];
    char strKernelFilter[MAX_PATH];
}PortFilter_struct;

typedef struct
{
    char strBarcode[BARCODE_ARRAY_LEN];
    char strBTAddr[BT_ARRAY_LEN];
    char strWifiAddr[WIFI_ARRAY_LEN];
    char strIMEI[MAX_IMEI_NUMS][IMEI_ARRAY_LEN];
    char strSerialNo[IMEI_ARRAY_LEN];
    char strEthernetMac[ETHERNET_MAC_ARRAY_LEN];
    char strDrmkeyMCID[DRMKEY_MCID_ARRAY_LEN];
	char strMeid[MEID_ARRAY_LEN];
	char strEsn[ESN_ARRAY_LEN];
}ScanData_struct;

typedef struct  
{
    bool bWriteBarcode;
    bool bWriteIMEI;
    bool bWriteSerialNo;
    bool bWriteBT;
    bool bWriteWifi;
    bool bWifiEPPCopy;
    bool bWriteHdcp;
    bool bWriteDrm;
    bool bInstallHdcpData;
    bool bWriteEthernetMac;
    bool bWriteDrmkeyMCID;
	bool bWriteMeid;
	bool bWriteEsn;
}WriteOption_struct;

typedef struct
{
    bool bAuthenEnable;
    AUTH_HANDLE_T  t_AuthHandle; 
    SP_AUTH_HANDLE_T t_SpAuthHandle;
    SP_SCERT_HANDLE_T t_SpScertHandle;
}AuthOption_struct;


typedef enum
{
    FEATURE_PHONE = 0,
    SMART_PHONE = 1,
    SMART_PHONE_DUALMODEM = 2,
    TABLET_WIFI_ONLY = 3,
    RNDIG_DONGLE = 4,
	C2K = 5
}E_TARGET_TYPE;

typedef enum
{
    META_MODE = 0,
    AT_MODE = 1,
}E_OPERATOR_MODE;

typedef struct {
    bool bCompositeDeviceEnable;
    bool bUsbEnable;
    bool bSecurityUSB;
    bool bWithoutBattery;
    bool bSwithTool;
    bool bDualTalk;   
    bool bSkipWriteProdInfo; 
    bool bCheckCalFlag;
    bool bCheckFtFlag;
	bool bCheckBTWifi;
	bool bCheckBackNVtoPC;
	bool bCheckFastbootLock;
    UINT iCOMPort;
	UINT iPre_Connect_Timeout;
	UINT iKernel_Connect_Timeout;
    E_OPERATOR_MODE     eOperatorMode;
    E_TARGET_TYPE       eTargetType;
    AuthOption_struct   sAuthOption;
    DBFileOption_struct sDBFileOption;
    WriteOption_struct  sWriteOption;
    IMEIOption_struct   sIMEIOption;
//	BarcodeOption_struct sBarcodeOption;
    HeaderOption_struct sBarcHeader_Option;
    HeaderOption_struct sIMEIHeader_Option[MAX_IMEI_NUMS];
    HeaderOption_struct sSerialNoHeader_Option;
    HeaderOption_struct sBTHeader_Option;
    HeaderOption_struct sWifiHeader_Option;
    HeaderOption_struct sEthernetMacHeader_Option;
    HeaderOption_struct sDrmkeyMCIDHeader_Option;
	HeaderOption_struct sMeidHeader_Option;
	HeaderOption_struct sEsnHeader_Option;
    ScanData_struct     sScanData;
    LoadFile_struct     sLoadFile;
    PortFilter_struct   sPortFilter;
	bool  EnableSerialNo;
	bool IgnoreApdatabase;
	bool SerialNumFromIMEI;
} META_Common_struct;

typedef struct
{
    bool bInitMD1Db_Done;
    bool bInitMD2Db_Done;
    bool bInitAPDb_Done;
}DBInitInfo_struct;

typedef enum
{
    FP_START_STAGE = 0,
    FP_BARCODE_STAGE,
    FP_IMEI_STAGE,
    FP_BT_ADDRESS_STAGE,
    FP_WIFI_ADDRESS_STAGE,
    FP_BACKUP_NVRAM_STAGE,
    FP_END_STAGE = 256   
}FEATURE_PHONE_STAGE_e;

typedef enum
{
    SP_START_STAGE = 0,
    SP_CHECK_CAL_FT_FLAG_STAGE,
    SP_BARCODE_MD_STAGE,
    SP_IMEI_MD_STAGE,
    SP_AP2MD_STAGE,
	SP_C2K_STAGE,
    SP_MD2AP_STAGE,
    SP_PRODINFO_STAGE,
    SP_WRITE_TEMP_STAGE,
    SP_BT_ADDRESS_STAGE,
    //SP_VENDOR_ID_STAGE,
    SP_WIFI_ADDRESS_STAGE,
    SP_ETHERNET_MAC_STAGE,
    SP_HDCP_STAGE,
    SP_DRMKEY_STAGE,
    SP_HDCPDATA_INSTALL_STAGE,
    SP_DRMKEY_MCID_STAGE,
	//C2K Modem
	//SP_MEID_STAGE,
	//SP_ESN_STAGE,
    SP_BACKUPNV_TO_PC_STAGE,
    SP_BACKUP_NVRAM_STAGE,
    SP_END_STAGE = 256   
}SMART_PHONE_STAGE_e;

typedef enum
{
	SINGLE_MD_SINGLE_IMEI = 0,
	SINGLE_MD_MULTI_IMEI = 1,
	DUAL_MD_DUAL_IMEI,
	MULTIIMEI_RESERVE =255
}MULTIIMEI_OPTION_e;

#define _AUTO_GEN_FEATURE_
#ifdef _AUTO_GEN_FEATURE_
typedef struct
{
    UINT iStep;
    char Start[BARCODE_ARRAY_LEN];
    char End[BARCODE_ARRAY_LEN];
    char Next[BARCODE_ARRAY_LEN];
}BarcodeData_struct;

typedef struct
{
    UINT iStep;
    char Start[IMEI_ARRAY_LEN];
    char End[IMEI_ARRAY_LEN];
    char Next[IMEI_ARRAY_LEN];
}IMEIData_struct;

typedef struct
{
    UINT iStep;
    char Start[BT_ARRAY_LEN];
    char End[BT_ARRAY_LEN];
    char Next[BT_ARRAY_LEN];
}BTAddressData_struct;

typedef struct
{
    UINT iStep;
    char Start[WIFI_ARRAY_LEN];
    char End[WIFI_ARRAY_LEN];
    char Next[WIFI_ARRAY_LEN];
}WifiAddressData_struct;

typedef struct
{
    UINT iStep;
    char Start[ETHERNET_MAC_ARRAY_LEN];
    char End[ETHERNET_MAC_ARRAY_LEN];
    char Next[ETHERNET_MAC_ARRAY_LEN];
}EthernetAddressData_struct;

typedef struct
{
    UINT iStep;
    char Start[DRMKEY_MCID_ARRAY_LEN];
    char End[DRMKEY_MCID_ARRAY_LEN];
    char Next[DRMKEY_MCID_ARRAY_LEN];
}DRMKEYMCID_Data_struct;

typedef struct
{
    bool bAllDataValid;
    bool bBarcodeValid;
    bool bIMEIValid;
    bool bBTValid;
    bool bWifiValid;
    bool bEthernetValid;
    bool bDRMKeyMCIDValid;
}AutoGenDataValid_struct;

typedef struct
{
    BarcodeData_struct sBarcode;
    IMEIData_struct    sIMEI;
    BTAddressData_struct sBtAddress;
    WifiAddressData_struct sWifiAddress;
    EthernetAddressData_struct sEthernetAddress;
    DRMKEYMCID_Data_struct sDRMKeyMCID;
    AutoGenDataValid_struct sDataValid;
    Radix_e eIncreaseRadix;
    
    bool bEnableAutoGen;
    bool bAutoGenBarcode;
    bool bAutoGenIMEI;
    bool bAutoGenBT;
    bool bAutoGenWifi;
    bool bAutoGenEthernet;
    bool bAutoGenDRMKeyMCID;
}AutoGenData_struct;

extern AutoGenData_struct  g_AutoGenData;
extern char g_pAutoGenSetupFilepath[MAX_PATH];
RW_SetupFile_Status GetAutoGenParaFromSetupFile();
RW_SetupFile_Status SaveAutoGenParaToSetupFile();
RW_SetupFile_Status UpdateAutoGenParaToSetupFile();
#endif //#ifdef _AUTO_GEN_FEATURE_
char* ResultToString_SP(int MR);
char* ResultToString(int MR);
int InitSNIni();
void InitGlobalValue();
int GetSNSetupFilePath();
void EnableUSBSwitch();
void DisableUSBSwitch();
Login_Identify_e GetLoginIdentify();
UINT SaveLoginIdentify(const Login_Identify_e identify);
UINT SaveLoginPasswd(const char *strPasswd);
E_TARGET_TYPE GetTargetType();
long GetFilesize( FILE *fp );
bool CheckFileSize( const char *strFilePath, const long fileSize );

bool AuthHandle_Init();
void AuthHandle_DeInit();
bool AuthInit(const char *strAuthFilePath);
bool SPAuthInit(const char *strSPAuthFilePath);
bool SPScertInit(const char *strSPScertFilePath);

//void EnterC2KModemMeta(META_RESULT * MetaResult, int * m_hSPMetaHandle, int *C2K_Flag);


RW_SetupFile_Status GetParaFromSetupFile();
RW_SetupFile_Status SaveParaToSetupFile();

RW_SetupFile_Status GetItemParaFromSetupFile(const char *strFilePath, LPCTSTR lpKeyName, void* lpValue, E_INI_DATA_TYPE dataType);
RW_SetupFile_Status SaveItemParaToSetupFile(const char *strFilePath, LPCTSTR lpKeyName, void* lpValue, E_INI_DATA_TYPE dataType);

//Global parameters
//extern DWORD g_MainDlgHandle; 
//extern META_Common_struct g_sMetaComm;
extern char g_pSetupFilepath[MAX_PATH];
extern char g_pPasswdFilepath[MAX_PATH];
extern int  g_iMetaStopFlag;
extern Login_Identify_e g_LoginIdentify;

#endif
