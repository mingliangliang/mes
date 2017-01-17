/*******************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2003
 *
 ******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  brom.h
 *
 * Project:
 * --------
 *  BootRom Library
 *
 * Description:
 * ------------
 *  Exported C interface APIs for BootRom library.
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#ifndef _BROM_H_
#define _BROM_H_

#if defined(_WIN32)
#include <windows.h>
#elif defined(__GNUC__)
    typedef int HANDLE;
    #include <stddef.h>
#endif



#include "external_memory_setting.h"
#include "flashtool_handle.h"

#ifdef	__cplusplus
extern "C" {
#endif

struct FLASHTOOL_API_HANDLE;
typedef struct FLASHTOOL_API_HANDLE *	FLASHTOOL_API_HANDLE_T;
// The magic value to stop boot process
#define BOOT_STOP	9876

// boot infinitely
#define BOOT_INFINITE	0xFFFFFFF

// default start cmd retry count
#define DEFAULT_BROM_START_CMD_RETRY_COUNT	1

//------------------------------------------------------------------------------
// prototype of COM initial stage callback
//------------------------------------------------------------------------------
typedef int (__stdcall *CALLBACK_COM_INIT_STAGE)(HANDLE hCOM, void *usr_arg);

//------------------------------------------------------------------------------
// prototype of BootROM stage callback
//------------------------------------------------------------------------------
typedef int (__stdcall *CALLBACK_IN_BROM_STAGE)(unsigned int brom_handle, HANDLE hCOM, void *usr_arg);

//------------------------------------------------------------------------------
// prototype of write buf progress callback
//------------------------------------------------------------------------------
typedef int (__stdcall *CALLBACK_WRITE_BUF_PROGRESS_INIT)(void *usr_arg);
typedef int (__stdcall *CALLBACK_WRITE_BUF_PROGRESS)(unsigned char finished_percentage, unsigned int finished_bytes, unsigned int total_bytes, void *usr_arg);

//------------------------------------------------------------------------------
// prototype of Serial-Link-Authentication challenge callback
//------------------------------------------------------------------------------
typedef int (__stdcall *CALLBACK_SLA_CHALLENGE)(void *usr_arg, const unsigned char  *p_challenge_in, unsigned int  challenge_in_len, unsigned char  **pp_challenge_out, unsigned int  *p_challenge_out_len);
typedef int (__stdcall *CALLBACK_SLA_CHALLENGE_END)(void *usr_arg, unsigned char  *p_challenge_out);

//------------------------------------------------------------------------------
// runtime debug trace
//------------------------------------------------------------------------------
int __stdcall Brom_Debug_SetLogFilename(const char *filename);
int __stdcall Brom_DebugOn(void);
int __stdcall Brom_DebugOff(void);
int __stdcall Brom_DebugClear(void);
int __stdcall Brom_Debug_SetLogPrefix(const char *prefix);

//------------------------------------------------------------------------------
// translate enum to string
//------------------------------------------------------------------------------
const char * __stdcall BBChipTypeToName(const BBCHIP_TYPE  bbchip);
const char * __stdcall ExtClockToName(const EXT_CLOCK  ext_clock);
const char * __stdcall StatusToString(int status);

//------------------------------------------------------------------------------
// translate data structure
//------------------------------------------------------------------------------
int __stdcall GetComHandleFromFTHandle(FLASHTOOL_API_HANDLE_T ft_handle, HANDLE *hCOM);

//------------------------------------------------------------------------------
// Windows message to notify application ready to power on target
//------------------------------------------------------------------------------
#define WM_BROM_READY_TO_POWER_ON_TGT		(0x8888)
int __stdcall GetReadyToPowerOnWinAppMsgID(unsigned int *p_wm_app_id);
int __stdcall SetReadyToPowerOnWinAppMsgID(unsigned int wm_app_id);

//------------------------------------------------------------------------------
// boot-up result
//------------------------------------------------------------------------------
typedef struct {

	BBCHIP_TYPE		m_bbchip_type;
	char			m_bbchip_name[32];
	unsigned short	m_bbchip_hw_ver;
	unsigned short	m_bbchip_sw_ver;
	unsigned short	m_bbchip_hw_code;
	EXT_CLOCK		m_ext_clock;
	unsigned char	m_bbchip_secure_ver;
	unsigned char	m_bbchip_bl_ver;
	unsigned int	m_fw_ver_len;
	char			m_fw_ver[64];

	unsigned char	m_msp_err_code;
        unsigned int    m_security_config;

    unsigned char	m_meid[16];

} BOOT_RESULT;

//----------------------------------------------------------------------------
// Boot MAUI
//----------------------------------------------------------------------------
typedef enum {
    MAUI_MODE_NORMAL,   // Normal mode
    MAUI_MODE_META      // META mode
} MAUI_MODE;

typedef enum {
    MAUI_MODE_OPTION_EMPTY                       = 0x00000000,
    MAUI_MODE_OPTION_CREATE_USB_COM_AFTER_BOOTUP = 0x00000001,
    MAUI_MODE_OPTION_END                         = 0xFFFFFFFF
} MAUI_MODE_OPTION;

typedef struct {

    BBCHIP_TYPE                 m_bbchip_type;
    EXT_CLOCK                   m_ext_clock;

    unsigned int                m_ms_boot_timeout;
    unsigned int                m_max_start_cmd_retry_count;

    // This callback function will be invoke after COM port is opened
    // You can do some initialization by using this callback function.
    CALLBACK_COM_INIT_STAGE     m_cb_com_init_stage;
    void                        *m_cb_com_init_stage_arg;

    // This callback function will be invoke after BootROM start command
    // is passed. You can issue other BootROM commands by brom_handle and hCOM
    // which provides callback arguments, or do whatever you want otherwise.
    CALLBACK_IN_BROM_STAGE      m_cb_in_brom_stage;
    void                        *m_cb_in_brom_stage_arg;

    // Speed up BootROM stage baudrate
    _BOOL                       m_speedup_brom_baudrate;

#if defined(_WIN32)
    // Application's window handle to send
    // WM_BROM_READY_TO_POWER_ON_TGT message
    HWND                        m_ready_power_on_wnd_handle;
    void                        *m_ready_power_on_wparam;
    void                        *m_ready_power_on_lparam;
#endif
    // Serial Link Authentication
    AUTH_HANDLE_T               m_auth_handle;
    CALLBACK_SLA_CHALLENGE      m_cb_sla_challenge;
    void                        *m_cb_sla_challenge_arg;
    CALLBACK_SLA_CHALLENGE_END  m_cb_sla_challenge_end;
    void                        *m_cb_sla_challenge_end_arg;

	// Security Certificate
	SCERT_HANDLE_T					m_scert_handle; // SCERT file handle

    // Use USB connection or not
    _BOOL                       m_usb_enable;

    // MAUI mode and option
    MAUI_MODE                   m_maui_mode;
    MAUI_MODE_OPTION            m_maui_mode_option;

    // Root Certificate
    _BOOL               m_rootcert_force_assign;
    ROOTCERT_HANDLE_T   m_rootcert_handle;

    // Enable Without Battery for META mode only
    _BOOL               m_enable_without_battery;

    // Enable RNDIS META mode
    _BOOL               m_enable_AP_META_mode;

} BOOT_MAUI_ARG;

int  __stdcall Boot_MAUI(HANDLE hCOM,
                         const BOOT_MAUI_ARG *p_arg,
                         BOOT_RESULT *p_result,
                         int *p_bootstop);


//------------------------------------------------------------------------------
// boot META mode
//------------------------------------------------------------------------------
typedef struct {

	BBCHIP_TYPE		m_bbchip_type;
	EXT_CLOCK		m_ext_clock;

	unsigned int	m_ms_boot_timeout;
	unsigned int	m_max_start_cmd_retry_count;

	// This callback function will be invoke after COM port is opened
	// You can do some initialization by using this callback function.
	CALLBACK_COM_INIT_STAGE		m_cb_com_init_stage;
	void *						m_cb_com_init_stage_arg;

	// This callback function will be invoke after BootROM start cmd is passed.
	// You can issue other BootROM command by brom_handle and hCOM which provides callback arguments,
	// or do whatever you want otherwise.
	CALLBACK_IN_BROM_STAGE		m_cb_in_brom_stage;
	void *						m_cb_in_brom_stage_arg;

	// speed-up BootROM stage baudrate
	_BOOL	m_speedup_brom_baudrate;


#if defined(_WIN32)
	// Application's window handle to send WM_BROM_READY_TO_POWER_ON_TGT message
	HWND	m_ready_power_on_wnd_handle;
	void *	m_ready_power_on_wparam;
	void *	m_ready_power_on_lparam;
#endif

	// Serial Link Authentication
	AUTH_HANDLE_T					m_auth_handle;  // AUTH file handle
	CALLBACK_SLA_CHALLENGE			m_cb_sla_challenge;
	void *							m_cb_sla_challenge_arg;
	CALLBACK_SLA_CHALLENGE_END		m_cb_sla_challenge_end;
	void *							m_cb_sla_challenge_end_arg;

    // Security Certificate
	SCERT_HANDLE_T					m_scert_handle; // SCERT file handle

	// use USB Cable
	_BOOL							m_usb_enable;

    // Root Certificate
    _BOOL               m_rootcert_force_assign;
    ROOTCERT_HANDLE_T   m_rootcert_handle;

    // Enable META Without Battery
	_BOOL               m_enable_without_battery;

    // Enable RNDIS META mode
    _BOOL               m_enable_AP_META_mode;

} BOOT_META_ARG;

int  __stdcall Boot_META(
		HANDLE hCOM,
		const BOOT_META_ARG  *p_arg,
		BOOT_RESULT  *p_result,
		int *p_bootstop);


//------------------------------------------------------------------------------
// boot FlashTool download mode
//------------------------------------------------------------------------------

#define	WAIT_STATE_AUTO_DETECT_BY_FREQUENCY		NULL

#define MAX_NUM_EXTERNAL_MEMORY_SETTINGS        16

typedef struct {

	BBCHIP_TYPE		m_bbchip_type;
	EXT_CLOCK		m_ext_clock;

	unsigned int	m_ms_boot_timeout;
	unsigned int	m_max_start_cmd_retry_count;

	// This callback function will be invoke after COM port is opened
	// You can do some initialization by using this callback function.
	CALLBACK_COM_INIT_STAGE		m_cb_com_init_stage;
	void *						m_cb_com_init_stage_arg;

	// This callback function will be invoke after BootROM start cmd is passed.
	// You can issue other BootROM command by brom_handle and hCOM which provides callback arguments,
	// or do whatever you want otherwise.
	CALLBACK_IN_BROM_STAGE		m_cb_in_brom_stage;
	void *						m_cb_in_brom_stage_arg;

	// speed-up BootROM stage baudrate
	_BOOL	m_speedup_brom_baudrate;

#if defined(_WIN32)
	// Application's window handle to send WM_BROM_READY_TO_POWER_ON_TGT message
	HWND	m_ready_power_on_wnd_handle;
	void *	m_ready_power_on_wparam;
	void *	m_ready_power_on_lparam;
#endif

	// Serial Link Authentication
	AUTH_HANDLE_T		m_auth_handle;			// AUTH file handle
	CALLBACK_SLA_CHALLENGE			m_cb_sla_challenge;
	void *							m_cb_sla_challenge_arg;
	CALLBACK_SLA_CHALLENGE_END		m_cb_sla_challenge_end;
	void *							m_cb_sla_challenge_end_arg;

    // Security Certificate
	SCERT_HANDLE_T		m_scert_handle;			// SCERT file handle

	// EMI Control for Bank0 and Bank1
	unsigned int	*m_p_bank0_mem_cfg;		// bank0 memory config
	unsigned int	*m_p_bank1_mem_cfg;		// bank0 memory config

	// Download Agent
	_BOOL			m_enable_da_start_addr;	// Old parameter, no use now. Use DA_SetDefaultStartAddr instead.
	unsigned int	m_da_start_addr;		// Old parameter, no use now. Use DA_SetDefaultStartAddr instead.
	DA_HANDLE_T		m_da_handle;

	// da download progress callack
	CALLBACK_WRITE_BUF_PROGRESS_INIT	m_cb_download_da_init;
	void *								m_cb_download_da_init_arg;
	CALLBACK_WRITE_BUF_PROGRESS			m_cb_download_da;
	void *								m_cb_download_da_arg;

	// use USB Cable
	_BOOL								m_usb_enable;
	USB_COM_PORT_CONTROL				m_usb_com_port_control;

	// to initialize external RAM
	ExternalMemorySetting				m_external_memory_setting[MAX_NUM_EXTERNAL_MEMORY_SETTINGS];

	// Root Certificate
	_BOOL               m_rootcert_force_assign;
	ROOTCERT_HANDLE_T   m_rootcert_handle;

    // enable USB speedup
    _BOOL               m_enable_usb_2_0;

    // Unlock MT6250 internal SRAM (MT6250 only, default on, if BL don't support it when DL, tool auto disable)
    _BOOL               m_disable_unlock_internal_ram;

} BOOT_FLASHTOOL_ARG;

int  __stdcall Boot_FlashTool(
		HANDLE hCOM,
		const BOOT_FLASHTOOL_ARG  *p_arg,
		BOOT_RESULT  *p_result,
		int *p_bootstop);

//------------------------------------------------------------------------------
// boot BRom only
//------------------------------------------------------------------------------
typedef struct {

	BBCHIP_TYPE		m_bbchip_type;
	EXT_CLOCK		m_ext_clock;

	unsigned int	m_ms_boot_timeout;
	unsigned int	m_max_start_cmd_retry_count;

	// This callback function will be invoke after COM port is opened
	// You can do some initialization by using this callback function.
	CALLBACK_COM_INIT_STAGE		m_cb_com_init_stage;
	void *						m_cb_com_init_stage_arg;

	// This callback function will be invoke after BootROM start cmd is passed.
	// You can issue other BootROM command by brom_handle and hCOM which provides callback arguments,
	// or do whatever you want otherwise.
	CALLBACK_IN_BROM_STAGE		m_cb_in_brom_stage;
	void *						m_cb_in_brom_stage_arg;

	// speed-up BootROM stage baudrate
	_BOOL	m_speedup_brom_baudrate;

	// Serial Link Authentication
	AUTH_HANDLE_T		m_auth_handle;			// AUTH file handle
	CALLBACK_SLA_CHALLENGE			m_cb_sla_challenge;
	void *							m_cb_sla_challenge_arg;
	CALLBACK_SLA_CHALLENGE_END		m_cb_sla_challenge_end;
	void *							m_cb_sla_challenge_end_arg;

    // Security Certificate
	SCERT_HANDLE_T		m_scert_handle;			// SCERT file handle

    // do SLA or SCert with BootROM or not
    _BOOL    m_skip_do_sla;

    // Use USB connection or not
    _BOOL                       m_usb_enable;

    // Enable Download Without Battery
    _BOOL                       m_enable_download_without_battery;
} BOOT_BROM_ARG;
//------------------------------------------------------------------------------
// get brom.dll version
//------------------------------------------------------------------------------
int __stdcall Brom_GetDLLVer(unsigned int *major_ver, unsigned int *minor_ver, unsigned int *build_num, unsigned int *patch_num);
int __stdcall Brom_GetDLLInfo(const char **pp_version, const char **pp_release_type, const char **pp_build_date, const char **pp_load_path);

//------------------------------------------------------------------------------
// BootROM Command
//------------------------------------------------------------------------------
int __stdcall Brom_Create(unsigned int *p_brom_handle, BBCHIP_TYPE  bbchip_type, EXT_CLOCK  ext_clock, int *p_bootstop, unsigned int ms_boot_timeout, unsigned int max_start_cmd_retry_count);
int __stdcall Brom_Destroy(unsigned int *p_brom_handle);
int __stdcall Brom_StartCmd(unsigned int brom_handle, HANDLE hCOM, BOOT_RESULT  *p_result);
int __stdcall Brom_StartCmd_Ex(unsigned int *p_brom_handle, HANDLE hCOM, BOOT_RESULT  *p_result);
int __stdcall Brom_Connect_Ex(unsigned int *p_brom_handle, HANDLE hCOM, BOOT_BROM_ARG *p_arg, BOOT_RESULT  *p_result, int *p_stopflag);
int __stdcall Brom_Write16Cmd(unsigned int brom_handle, HANDLE hCOM, unsigned int write_addr, unsigned short *data, unsigned int num_of_word);
int __stdcall Brom_Read16Cmd(unsigned int brom_handle, HANDLE hCOM, unsigned int read_addr, unsigned short *data, unsigned int num_of_word);
int __stdcall Brom_Write32Cmd(unsigned int brom_handle, HANDLE hCOM, unsigned int write_addr, unsigned int *data, unsigned int num_of_dword);
int __stdcall Brom_Read32Cmd(unsigned int brom_handle, HANDLE hCOM, unsigned int read_addr, unsigned int *data, unsigned int num_of_dword);
int __stdcall Brom_Checksum16Cmd(unsigned int brom_handle, HANDLE hCOM, unsigned int chksum_addr, unsigned int num_of_word, unsigned short *chksum);
int __stdcall Brom_JumpCmd(unsigned int brom_handle, HANDLE hCOM, unsigned int jump_addr, unsigned char bWaitForAck);
int __stdcall Brom_JumpCmd_Ex(unsigned int brom_handle, HANDLE hCOM, unsigned int jump_addr,
                unsigned int  signature_addr, unsigned int  signature_len,unsigned char bWaitForAck);
int __stdcall Brom_GetME_ID(unsigned int brom_handle, HANDLE hCOM,
                    unsigned char *pBufME_ID, const unsigned int lenBufME_ID, unsigned int* lenME_ID);

//------------------------------------------------------------------------------
// BootROM Efsue write Command
//------------------------------------------------------------------------------

// Secure Key structure
typedef struct
{
	unsigned int buf_len;		// key buffer length
	char *buf;					// key string char array buffer with NULL character in the end
}KeyBufST;

typedef struct
{
	KeyBufST key_e;
	KeyBufST key_n;
}PublicKeyStringST;

typedef struct
{
	unsigned int buf_len;		// hash buffer length
	char *buf;					// hash value buffer
}KeyHashValue;


typedef struct
{
	unsigned int buf_len;
	char *buf;
}SpareData;


// Argument for writing Efuse common register
typedef struct{
    // true =  0xA59914B3
    // false = 0x241C8F6D

    unsigned int  	emmc_boot_dis;
    unsigned int  	nand_boot_dis;
    unsigned int  	nand_boot_speedup_dis;

    unsigned int  	usbdl_type_blow;
    unsigned int  	usbdl_type;	// valid value is only 0~3 for 2 bit

    unsigned int  	usb_id_blow;
    unsigned short 	usb_pid;	// 16 bit
    unsigned short 	usb_vid;	// 16 bit

    unsigned int  	spare_blow;
	unsigned int 	spare_num_of_byte;
    SpareData 		spare;

    unsigned int  	usb_download_trapping_invert;
    unsigned int  	sf_boot_dis;
    unsigned int  	spi_nand_boot_dis;
    unsigned int  	sd_card_boot_dis;
} Efuse_Common_Arg;

// Argument for writing Efuse security register
typedef struct{
    // true =  0xA59914B3
    // false = 0x241C8F6D

    unsigned int 	acc_en;
    unsigned int 	ack_en;
    unsigned int 	sbc_en;
    unsigned int 	daa_en;
    unsigned int 	sla_en;
    unsigned int 	root_cert_en;
    unsigned int 	jtag_dis;

    unsigned int 	ac_key_blow;
    KeyBufST 		ac_key;			// ACK length 128 bit = 16 byte

    unsigned int 	sbc_pubk_blow;
    union
    {
        PublicKeyStringST w_sbc_pub_key;  // sbc_public_key argument when using Brom_WriteEfuseSecure()
        KeyHashValue r_sbc_pub_key_hash;  // return sbc_public_key hash value when using Brom_ReadEfuseAll()
    }sbc_pub_key_u;

    unsigned int 	jtag_sw_con;
    unsigned int 	bootrom_cmd_dis;

    unsigned int  	root_cert_id_blow;
    unsigned short 	root_cert_id;
} Efuse_Secure_Arg;

// Argument for locking Efuse register
typedef struct{
    // lock =  0xA59914B3
    // no-action = 0x241C8F6D  (can't unluck)

	unsigned int common_ctrl_lock;
	unsigned int usb_id_lock;
	unsigned int spare_lock;
	unsigned int sec_ctrl_lock;
	unsigned int ackey_lock;
	unsigned int sbc_pubk_hash_lock;
} Efuse_Lock_Arg;

// Argument for writing SV5x Efuse register
typedef struct{
    unsigned int 	sbc_pubk_blow;
    union
    {
        PublicKeyStringST w_sbc_pub_key;  // sbc_public_key argument when using Brom_WriteEfuseSecure()
        KeyHashValue r_sbc_pub_key_hash;  // return sbc_public_key hash value when using Brom_ReadEfuseAll()
    }sbc_pub_key_u;

    unsigned int 	ac_key_blow;
    KeyBufST 		ac_key;			// ACK length 128 bit = 16 byte

    unsigned int  	usb_id_blow;
    unsigned short 	usb_pid;	// 16 bit
    unsigned short 	usb_vid;	// 16 bit

    unsigned int 	acc_en;
    unsigned int 	ack_en;
    unsigned int 	sla_en;
    unsigned int 	daa_en;
    unsigned int 	sbc_en;
    unsigned int 	root_cert_en;

    unsigned int 	wr_en;

    unsigned int 	ecc_sbc_key_hash;
    unsigned int 	ecc_ac_key;
    unsigned int 	ecc_usb_pid_vid;
    unsigned int 	clone_control;
    unsigned int 	customer_region_enable;
} Efuse_SV5x_Arg;


// Connect method for Brom_Connect()
typedef enum {
    CONNECT_METHOD_NONE = 0,  // prototype default value to backward compatible
    CONNECT_METHOD_UART,      // UART
    CONNECT_METHOD_USB        // USB
} CONNECT_METHOD;

#if defined(__GNUC__)
int __stdcall Brom_ConnectByPath(unsigned int *p_brom_handle,
                                 FLASHTOOL_API_HANDLE_T  *p_ft_handle,
                                 char*  dev_path,
                                 BBCHIP_TYPE  bbchip_type,
                                 EXT_CLOCK  ext_clock,
                                 int *p_bootstop,
                                 unsigned int ms_boot_timeout,
                                 unsigned int max_start_cmd_retry_count,
                                 CONNECT_METHOD com_type = CONNECT_METHOD_NONE,
                                 bool enable_connect_without_battery = false,
                                 AUTH_HANDLE_T auth_handle = NULL,
                                 SCERT_HANDLE_T scert_handle = NULL);
#endif

int __stdcall Brom_Connect(unsigned int *p_brom_handle,
                           FLASHTOOL_API_HANDLE_T  *p_ft_handle,
                           unsigned char  com_port,
                           BBCHIP_TYPE  bbchip_type,
                           EXT_CLOCK  ext_clock,
                           int *p_bootstop,
                           unsigned int ms_boot_timeout,
                           unsigned int max_start_cmd_retry_count,
                           CONNECT_METHOD com_type = CONNECT_METHOD_NONE,
                           bool enable_connect_without_battery = false,
                           AUTH_HANDLE_T auth_handle = NULL,
                           SCERT_HANDLE_T scert_handle = NULL);

int __stdcall Brom_DisConnect(unsigned int *p_brom_handle, FLASHTOOL_API_HANDLE_T  *p_ft_handle);
int __stdcall Brom_WriteEfuseCommon(unsigned int brom_handle, FLASHTOOL_API_HANDLE_T ft_handle, const Efuse_Common_Arg *common_arg, bool error_log_en = true);
int __stdcall Brom_WriteEfuseSecure(unsigned int brom_handle, FLASHTOOL_API_HANDLE_T ft_handle, const Efuse_Secure_Arg *secure_arg, bool error_log_en = true);
int __stdcall Brom_WriteEfuseLock(unsigned int brom_handle, FLASHTOOL_API_HANDLE_T ft_handle, const Efuse_Lock_Arg *lock_arg, bool error_log_en = true);
int __stdcall Brom_ReadEfuseAll(unsigned int brom_handle, FLASHTOOL_API_HANDLE_T ft_handle, Efuse_Common_Arg *common_arg, Efuse_Secure_Arg *secure_arg, Efuse_Lock_Arg *lock_arg, bool error_log_en = true);
int __stdcall Brom_EnableWatchDogTimeout(unsigned int brom_handle, FLASHTOOL_API_HANDLE_T ft_handle, const unsigned short ms_timeout_interval);
int __stdcall Brom_GetHR_ID(unsigned int brom_handle, FLASHTOOL_API_HANDLE_T ft_handle, unsigned char *pBufHR_ID, const unsigned int lenBufHR_ID, unsigned int* lenHR_ID);







typedef struct _DataBlock {
	unsigned int	m_baseaddr;
	unsigned char * m_data;
	unsigned int	m_data_len;		// in byte
	unsigned int	m_data_sig_len; // in byte
} _DataBlock;

#define BROM_MAX_DATA_BLOCKS	10

typedef struct {
	unsigned short	m_block_count;
	_DataBlock		m_blocks[BROM_MAX_DATA_BLOCKS];
} BromWriteDataBlocks;

int __stdcall Brom_DownloadData(unsigned int brom_handle, HANDLE hCOM, const BromWriteDataBlocks *p_data_blocks, CALLBACK_WRITE_BUF_PROGRESS_INIT  cb_init,  void *cb_init_arg, CALLBACK_WRITE_BUF_PROGRESS  cb,  void *cb_arg);

#ifdef	__cplusplus
}
#endif

#endif


