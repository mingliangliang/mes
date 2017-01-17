/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
*
******************************************************************************/

/*******************************************************************************
* Filename:
* ---------
*  flashtool_api.h
*
* Project:
* --------
*  Flash Download/Readback/Format Library.
*
* Description:
* ------------
*  Exported C interface APIs for FlashTool Library.
*
* Author:
* -------
*  Amos Hsu (mtk00539)
*
*******************************************************************************/
#ifndef _FLASHTOOL_API_H_
#define _FLASHTOOL_API_H_

#include "mtk_status.h"
#include "brom.h"
#include "DOWNLOAD.H"
#include "flashtool_handle.h"

#ifdef	__cplusplus
extern "C" {
#endif

    struct FLASHTOOL_API_HANDLE;
    typedef struct FLASHTOOL_API_HANDLE *	FLASHTOOL_API_HANDLE_T;

    //------------------------------------------------------------------------------
    // accuracy enum
    //------------------------------------------------------------------------------
    typedef enum {
        ACCURACY_AUTO		= 0,		// auto detect by baudrate
            ACCURACY_1_3		= 3,		//   33%
            ACCURACY_1_4		= 4,		//   25%
            ACCURACY_1_10		= 10,		//   10%
            ACCURACY_1_100		= 100,		//    1%
            ACCURACY_1_1000		= 1000,		//  0.1%
            ACCURACY_1_10000	= 10000		// 0.01%
    }ACCURACY;

    //------------------------------------------------------------------------------
    // com port setting
    //------------------------------------------------------------------------------

#ifndef COM_DEFAULT_TIMEOUT
#define	COM_DEFAULT_TIMEOUT		0xFFFFFFF
#endif
#define	COM_NO_TIMEOUT			0

    //------------------------------------------------------------------------------
    // DA report structure
    //------------------------------------------------------------------------------
    typedef struct DA_REPORT_T {
        // DA version
        unsigned char		m_expected_da_major_ver;
        unsigned char		m_expected_da_minor_ver;
        unsigned char		m_da_major_ver;
        unsigned char		m_da_minor_ver;
        // bbchip
        BBCHIP_TYPE			m_bbchip_type;
        char				m_bbchip_name[32];
        unsigned short		m_bbchip_hw_ver;
        unsigned short		m_bbchip_sw_ver;
        unsigned short		m_bbchip_hw_code;
        EXT_CLOCK			m_ext_clock;
        unsigned char		m_bbchip_secure_ver;
        unsigned char		m_bbchip_bl_ver;
        // NOR flash report
        STATUS_E			m_nor_ret;
        HW_ChipSelect_E		m_nor_chip_select[2];
        unsigned short		m_nor_flash_id;
        unsigned int		m_nor_flash_size;
        unsigned int            m_nor_flash_size_die1;
        unsigned short		m_nor_flash_dev_code_1;
        unsigned short		m_nor_flash_dev_code_2;
        unsigned short		m_nor_flash_dev_code_3;
        unsigned short		m_nor_flash_dev_code_4;
        STATUS_E			m_nor_flash_otp_status;
        unsigned int		m_nor_flash_otp_size;
        unsigned short		m_nor_flash_id_die2;
        unsigned int		m_nor_flash_size_die2;
        unsigned short		m_nor_flash_dev_code_1_die2;
        unsigned short		m_nor_flash_dev_code_2_die2;
        unsigned short		m_nor_flash_dev_code_3_die2;
        unsigned short		m_nor_flash_dev_code_4_die2;
        STATUS_E		m_nor_flash_otp_status_die2;
        unsigned int		m_nor_flash_otp_size_die2;
        unsigned char       m_nor_flash_name[64];
        // NAND flash report
        STATUS_E			m_nand_ret;
        HW_ChipSelect_E		m_nand_chip_select;
        unsigned short		m_nand_flash_id;
        unsigned int		m_nand_flash_size;
        unsigned short		m_nand_flash_dev_code_1;
        unsigned short		m_nand_flash_dev_code_2;
        unsigned short		m_nand_flash_dev_code_3;
        unsigned short		m_nand_flash_dev_code_4;
    	unsigned short		m_nand_flash_dev_code_1_part2;
    	unsigned short		m_nand_flash_dev_code_2_part2;
    	unsigned short		m_nand_flash_dev_code_3_part2;
    	unsigned short		m_nand_flash_dev_code_4_part2;
        unsigned short		m_nand_pagesize;
        unsigned short		m_nand_sparesize;
        unsigned short		m_nand_pages_per_block;
        unsigned char		m_nand_io_interface;
        unsigned char		m_nand_addr_cycle;
        unsigned char       m_nand_flash_name[64];
		// EMMC flash report
	    STATUS_E			m_emmc_ret;
	    unsigned char       m_emmc_manufacture_id;
	    char                m_emmc_product_name[8];
		unsigned char       m_emmc_partitioned;
	    unsigned int		m_emmc_boot1_size; // unit: 512 bytes
	    unsigned int		m_emmc_boot2_size; // unit: 512 bytes
	    unsigned int		m_emmc_rpmb_size;  // unit: 512 bytes
	    unsigned int		m_emmc_gp1_size;   // unit: 512 bytes
	    unsigned int		m_emmc_gp2_size;   // unit: 512 bytes
	    unsigned int		m_emmc_gp3_size;   // unit: 512 bytes
	    unsigned int		m_emmc_gp4_size;   // unit: 512 bytes
	    unsigned int        m_emmc_ua_size;    // unit: 512 bytes


        // internal sram report
        STATUS_E			m_int_sram_ret;
        unsigned int		m_int_sram_size;
        // external ram report
        STATUS_E			m_ext_ram_ret;
        HW_RAMType_E		m_ext_ram_type;
        HW_ChipSelect_E		m_ext_ram_chip_select;
        unsigned int		m_ext_ram_size;

        // MTK Security Platform error code
        unsigned char		m_msp_err_code;

        // CODE area and SEC_RO area download status
        STATUS_E			m_download_status;

        // target boot-up style
        STATUS_E			m_boot_style;

        // target fw version
        unsigned int		m_fw_ver_len;
        char				m_fw_ver[64];

        // current selected DL_HANDLE
        DL_HANDLE_T			m_dl_handle;

        unsigned int        m_security_config;

    } DA_REPORT_T;

    //------------------------------------------------------------------------------
    // prototype of callback function
    //------------------------------------------------------------------------------
    typedef int (__stdcall *CALLBACK_DA_REPORT)(const DA_REPORT_T  *p_da_report, void *usr_arg);
    typedef int (__stdcall *CALLBACK_SET_HIGHSPEED_BAUDRATE)(HANDLE hCOM, unsigned char BaudrateId, void *usr_arg);
    typedef int (__stdcall *CALLBACK_DOWNLOAD_PROGRESS_INIT)(void *usr_arg);
    typedef int (__stdcall *CALLBACK_DOWNLOAD_PROGRESS)(unsigned char finished_percentage, unsigned int finished_bytes, unsigned int total_bytes, void *usr_arg);
//typedef int (__stdcall *CALLBACK_SETUP_PROGRESS_COLOR)(void *usr_arg, unsigned int color, char *hint);  (remove after BROM DLL v5.1128.03.00)
    typedef int (__stdcall *CALLBACK_BOOTLOADER_DOWNLOAD_PROGRESS_INIT)(void *usr_arg);
    typedef int (__stdcall *CALLBACK_BOOTLOADER_DOWNLOAD_PROGRESS)(unsigned char finished_percentage, unsigned int finished_bytes, unsigned int total_bytes, void *usr_arg);
    typedef int (__stdcall *CALLBACK_READBACK_PROGRESS_INIT)(HW_StorageType_E  storage_type, unsigned int rb_addr, unsigned int rb_length, const char *rb_filepath, void *usr_arg);
    typedef int (__stdcall *CALLBACK_READBACK_PROGRESS)(unsigned char finished_percentage, unsigned int finished_bytes, unsigned int total_bytes, void *usr_arg);
    typedef int (__stdcall *CALLBACK_FORMAT_PROGRESS_INIT)(HW_StorageType_E  storage_type, unsigned int begin_addr, unsigned int length, void *usr_arg);
    typedef int (__stdcall *CALLBACK_FORMAT_PROGRESS)(unsigned char finished_percentage, void *usr_arg);
    typedef struct {
        unsigned int	m_fmt_begin_addr;
        unsigned int	m_fmt_length;
        unsigned int	m_total_blocks;
        unsigned int	m_bad_blocks;
        unsigned int	m_err_blocks;
    } FormatStatisticsReport_T;
    typedef int (__stdcall *CALLBACK_FORMAT_STATISTICS)(const FormatStatisticsReport_T  *p_report, void *usr_arg);
    typedef int (__stdcall *CALLBACK_POST_PROCESS_INIT)(void *usr_arg);
    typedef int (__stdcall *CALLBACK_POST_PROCESS)(unsigned char finished_percentage, void *usr_arg);
    typedef int (__stdcall *CALLBACK_SECURITY_PRE_PROCESS_NOTIFY)(void *usr_arg);
    typedef int (__stdcall *CALLBACK_SECURITY_POST_PROCESS_NOTIFY)(void *usr_arg);
    typedef int (__stdcall *CALLBACK_DOWNLOAD_FAT_CHANGE_NOTIFY)(void *usr_arg);

    typedef int (__stdcall *CALLBACK_PROGRESS_INIT)(void *usr_arg);
    typedef int (__stdcall *CALLBACK_PROGRESS)(unsigned char finished_percentage, unsigned int finished_bytes, unsigned int total_bytes, void *usr_arg);

    typedef int (__stdcall *CALLBACK_MEMORYTEST_PROGRESS_INIT)(void *usr_arg);
    typedef int (__stdcall *CALLBACK_MEMORYTEST_PROGRESS)(unsigned int current_progress, void *usr_arg);
    typedef int (__stdcall *CALLBACK_MEMORYTEST_NAND_BAD_BLOCK_REPORT)(unsigned int bad_block_address, void *usr_arg);

typedef int (__stdcall *CALLBACK_PRE_FORMAT_PROGRESS_INIT)(void *usr_arg);
typedef int (__stdcall *CALLBACK_PRE_FORMAT_PROGRESS)(unsigned char finished_percentage, void *usr_arg);

    typedef CALLBACK_READBACK_PROGRESS CALLBACK_READ_FLASH_PROGRESS;
    typedef CALLBACK_DOWNLOAD_PROGRESS_INIT CALLBACK_WRITE_FLASH_PROGRESS_INIT;
    typedef CALLBACK_DOWNLOAD_PROGRESS CALLBACK_WRITE_FLASH_PROGRESS;

    //------------------------------------------------------------------------------
    // Connect/Disconnect
    //------------------------------------------------------------------------------
    typedef	struct {

        // com port timeout setting
        unsigned int							m_com_ms_read_timeout;
        unsigned int							m_com_ms_write_timeout;

        // BootFlashTool arg
        BOOT_FLASHTOOL_ARG						m_boot_arg;

        // security pre-process notify callback
        CALLBACK_SECURITY_PRE_PROCESS_NOTIFY	m_cb_security_pre_process_notify;
        void									*m_cb_security_pre_process_notify_arg;

        // chip-select of NOR flash memory
        HW_ChipSelect_E							m_nor_chip_select[2];

        // chip-select of NAND flash memory
        HW_ChipSelect_E							m_nand_chip_select;

        // NFI access control register
        unsigned int							*m_p_nand_acccon;

        // to enable BAT_ON check for USBDL w/o battery
        _BOOL									m_enable_download_without_battery;

    	// to disable Flash ID & EMI Comparison when Combo Memory
    	_BOOL				                    m_disable_flashID_comparison;

        // bmt pool address
        unsigned int							m_bmt_pool_address;

    } FlashTool_Connect_Arg;

    typedef struct {

        DA_REPORT_T m_da_report;
        DA_INFO     m_da_info;

    } FlashTool_Connect_Result;

    typedef enum {
        RESET_DOWNLOAD_OPERATION_NO_CHANGE = 0,
        RESET_DOWNLOAD_OPERATION_BY_BOOTROM,
        RESET_DOWNLOAD_OPERATION_BY_BOOTLOADER,
        RESET_DOWNLOAD_OPERATION_END
    } RESET_DOWNLOAD_MODE_OPERATION;

    extern int __stdcall FlashTool_Connect(
        unsigned char  com_port,
        const FlashTool_Connect_Arg  *p_arg,
        FlashTool_Connect_Result  *p_result,
        int *p_stopflag,
        FLASHTOOL_API_HANDLE_T  *p_ft_handle);

    extern int __stdcall FlashTool_Connect_ByhCOM(
        HANDLE  hCOM,
        const FlashTool_Connect_Arg  *p_arg,
        FlashTool_Connect_Result  *p_result,
        int *p_stopflag,
        FLASHTOOL_API_HANDLE_T  *p_ft_handle);
#if defined(__GNUC__)
    extern int __stdcall FlashTool_Connect_ByPath(
        const char* dev_path,
        const FlashTool_Connect_Arg  *p_arg,
        FlashTool_Connect_Result  *p_result,
        int *p_stopflag,
        FLASHTOOL_API_HANDLE_T  *p_ft_handle);
#endif


    extern int __stdcall FlashTool_Connect_FromBootROMStage
        (unsigned int *p_brom_handle,
        FLASHTOOL_API_HANDLE_T  ft_handle,
        const FlashTool_Connect_Arg  *p_arg,
        FlashTool_Connect_Result  *p_result);

    extern int __stdcall FlashTool_Disconnect(FLASHTOOL_API_HANDLE_T  *p_ft_handle, bool bResetDownloadMode = false, RESET_DOWNLOAD_MODE_OPERATION DownloadMode_Operation = RESET_DOWNLOAD_OPERATION_NO_CHANGE);

    //------------------------------------------------------------------------------
    // Post-Process
    //------------------------------------------------------------------------------
    typedef	struct {

        // post-process callback
        CALLBACK_POST_PROCESS_INIT			m_cb_post_process_init;
        void *								m_cb_post_process_init_arg;
        CALLBACK_POST_PROCESS				m_cb_post_process;
        void *								m_cb_post_process_arg;

    } FlashTool_PostProcess_Arg;

    extern int __stdcall FlashTool_PostProcess(FLASHTOOL_API_HANDLE_T  ft_handle, const FlashTool_PostProcess_Arg *p_arg);

    //------------------------------------------------------------------------------
    // Change Baudrate
    //------------------------------------------------------------------------------
    typedef	struct {

        UART_BAUDRATE	m_baudrate;
        unsigned char	m_baudrate_full_sync_count;

        // set high-speed baudrate callback
        CALLBACK_SET_HIGHSPEED_BAUDRATE			m_cb_set_high_speed_baudrate;
        void *									m_cb_set_high_speed_baudrate_arg;

    } FlashTool_ChangeBaudrate_Arg;

    extern int __stdcall FlashTool_ChangeBaudrate(FLASHTOOL_API_HANDLE_T  ft_handle, const FlashTool_ChangeBaudrate_Arg  *p_arg);

    //------------------------------------------------------------------------------
    // Enable WatchDog Timeout and force reset to Normal Mode
    //------------------------------------------------------------------------------
    extern int __stdcall FlashTool_EnableWatchDogTimeoutAndResetToNormalMode(
        FLASHTOOL_API_HANDLE_T  ft_handle, unsigned int ms_timeout_interval);


    //------------------------------------------------------------------------------
    // Enable WatchDog Timeout
    //------------------------------------------------------------------------------
    extern int __stdcall FlashTool_EnableWatchDogTimeout(FLASHTOOL_API_HANDLE_T  ft_handle, unsigned int ms_timeout_interval, bool bResetDownloadMode = false, RESET_DOWNLOAD_MODE_OPERATION DownloadMode_Operation = RESET_DOWNLOAD_OPERATION_NO_CHANGE);

    //----------------------------------------------------------------------------
    // Enable SRAM
    //----------------------------------------------------------------------------

    typedef struct {

        // external ram report
        STATUS_E        m_ext_ram_ret;
        HW_RAMType_E    m_ext_ram_type;
        HW_ChipSelect_E m_ext_ram_chip_select;
        unsigned int    m_ext_ram_size;

    } FlashTool_EnableSRAM_Result;

    extern int __stdcall FlashTool_EnableSRAM(
        FLASHTOOL_API_HANDLE_T ft_handle,
        FlashTool_EnableSRAM_Result *p_enable_sram_result);

    //------------------------------------------------------------------------------
    // Enable DRAM
    //------------------------------------------------------------------------------

    typedef	struct {

        // external ram report
        STATUS_E			m_ext_ram_ret;
        HW_RAMType_E		m_ext_ram_type;
        HW_ChipSelect_E		m_ext_ram_chip_select;
        unsigned int		m_ext_ram_size;

    } FlashTool_EnableDRAM_Result;

    extern int __stdcall FlashTool_EnableDRAM(
        FLASHTOOL_API_HANDLE_T  ft_handle,
        const DRAM_SETTING  dram_setting,
        FlashTool_EnableDRAM_Result    *p_dram_result);

    //------------------------------------------------------------------------------
    // Download
    //------------------------------------------------------------------------------

    typedef enum {
        NOR_FLASH_ERASE_FAST_MODE = 0,  // All erase operations are with blank block check before erase.
        NOR_FLASH_ERASE_SAFE_MODE = 1,  // All erase operations are actual real erase to flash without blank block check before erase.
        NOR_FLASH_ERASE_MODE_END = 0xFFFFFFFF
    } NOR_FLASH_ERASE_MODE; // just workable for serial nor flash platform (MT6252/6251/6250/6260)

    typedef enum {
        LNP_NONE = 0,           // Do NOT backup and restore the linux NVRAM partition. If NVRAM is changed, stop download.
        LNP_BACKUP_RESTORE = 1, // Backup and restore the linux NVRAM partition when the NVRAM modification is detedted.
        LNP_RESTORE_ONLY = 2    // Do NOT backup the linux NVRAM partition. Check if the file existed and then restore it to NVRAM partition.
    } LINUX_NVRAM_PARTITION_OPTION; // just workable for linux load

    typedef	struct {
        // single DL_HANDLE
        DL_HANDLE_T						m_dl_handle;

        // multi DL_HANDLE List
        DL_HANDLE_LIST_T				m_dl_handle_list;

        // da report callback
        CALLBACK_DA_REPORT					m_cb_da_report;
        void *								m_cb_da_report_arg;

        // DL_HANDLE download progress callback
        ACCURACY							m_download_accuracy;
        CALLBACK_DOWNLOAD_PROGRESS_INIT		m_cb_download_flash_init;
        void *								m_cb_download_flash_init_arg;
        CALLBACK_DOWNLOAD_PROGRESS			m_cb_download_flash;
        void *								m_cb_download_flash_arg;

        // Filesystem image downloading
        CALLBACK_DOWNLOAD_PROGRESS_INIT		m_cb_download_fs_init;
        void *								m_cb_download_fs_init_arg;
        CALLBACK_DOWNLOAD_PROGRESS			m_cb_download_fs;
        void *								m_cb_download_fs_arg;

        // Partition downloading
        CALLBACK_DOWNLOAD_PROGRESS_INIT		m_cb_download_partition_init;
        void *								m_cb_download_partition_init_arg;
        CALLBACK_DOWNLOAD_PROGRESS			m_cb_download_partition;
        void *								m_cb_download_partition_arg;

        // NVRAM Partition backup
        CALLBACK_READBACK_PROGRESS_INIT		m_cb_nvram_backup_init;
        void *								m_cb_nvram_backup_init_arg;
        CALLBACK_READBACK_PROGRESS			m_cb_nvram_backup;
        void *								m_cb_nvram_backup_arg;

        // Boot Loader download progress callback
        CALLBACK_BOOTLOADER_DOWNLOAD_PROGRESS_INIT	m_cb_download_bloader_init;
        void *										m_cb_download_bloader_init_arg;
        CALLBACK_BOOTLOADER_DOWNLOAD_PROGRESS		m_cb_download_bloader;
        void *										m_cb_download_bloader_arg;

        // security post-process notify callback
        CALLBACK_SECURITY_POST_PROCESS_NOTIFY		m_cb_security_post_process_notify;
        void *										m_cb_security_post_process_notify_arg;

        CALLBACK_DOWNLOAD_FAT_CHANGE_NOTIFY         m_cb_download_fat_change_notify;
        void *										m_cb_download_fat_change_notify_arg;

        // The flag of m_enable_tgt_res_layout_check is used to control whether if target resource
        // layout checking operation will be performed.
        // _TRUE: Enable target resource layout checking operation.
        // _FALSE: Disable target resource layout checking operation.
        _BOOL				m_enable_tgt_res_layout_check;

        // The flag to check if target side baseband chip version is corresponding to ROM file on PC side.
        _BOOL				m_enable_bbchip_ver_check;

        // Download Style : _FALSE	: best effort erase
        //					_TRUE	: sequential erase (sector by sector)
        _BOOL				m_downloadstyle_sequential;

        // enable DRAM setting from UI thread
        _BOOL				m_enable_ui_dram_cfg;
        DRAM_SETTING		m_dram_cfg;

	// to disable Flash ID & EMI Comparison when Combo Memory
	_BOOL				m_disable_flashID_comparison;

	// setup progress bar color callback (remove after BROM DLL v5.1128.03.00)
	// CALLBACK_SETUP_PROGRESS_COLOR       m_cb_setup_progress_color;
	// void *								m_cb_setup_progress_color_arg;

	// pre-format progress callback (Serial-flash platform)
	CALLBACK_PRE_FORMAT_PROGRESS_INIT	m_cb_pre_format_flash_init;
	void *							    m_cb_pre_format_flash_init_arg;
	CALLBACK_PRE_FORMAT_PROGRESS		m_cb_pre_format_flash;
	void *							    m_cb_pre_format_flash_arg;

        // The flag to check if target has FAT info, and if exist, compare with PC's side's load if primary ROM is selected to be downloaded
        // note: if the flag is enabled, and if the FAT ranges are different between target and PC's load, the download flow will stop!
        _BOOL               m_enable_fat_range_check_before_dl;

        // The flag decide that auto-format all CBR region or not when all main region + CBR region is enable
        // If this flag is _TRUE , BROM DLL will not format CBR region when all main region + CBR region is enable
        // If this flag is _FALSE, BROM DLL will format CBR region when all main region + CBR region is enable
        _BOOL               m_keep_cbr_region_intact;


        // Backup the nvram partition if the downloaded PMT is not matched with the target's PMT.
        // If the flag is LNP_NONE, the downloaded PMT must be same  as the PMT in target, otherwise,
        // forbid downloading
        LINUX_NVRAM_PARTITION_OPTION	m_nvram_partition_backup;

        // Enable download software to serial nor flash in safe mode,it's just for MT6252/6251/6250/6260. (default is fast mode)
        // In safe mode, all erase operations are actual real erase to flash. (without blank block check before erase)
        NOR_FLASH_ERASE_MODE				m_nor_flash_erase_mode;
    } FlashTool_Download_Arg;

    typedef	struct {

        // dummy
        _BOOL   m_BLNotDownloadWarning;
        _BOOL	m_BLFeatureNotMatchWarning;
        _BOOL	m_BOOTCERTNotDownloadWarning;

    } FlashTool_Download_Result;

    extern int __stdcall FlashTool_Download(
        FLASHTOOL_API_HANDLE_T  ft_handle,
        const FlashTool_Download_Arg  *p_dl_arg,
        FlashTool_Download_Result  *p_dl_result);

    //------------------------------------------------------------------------------
    // Readback
    //------------------------------------------------------------------------------
    typedef	struct {

        HW_StorageType_E					m_storage_type;

        RB_HANDLE_T							m_rb_handle;

        // readback progress callback
        ACCURACY							m_readback_accuracy;
        CALLBACK_READBACK_PROGRESS_INIT		m_cb_readback_flash_init;
        void *								m_cb_readback_flash_init_arg;
        CALLBACK_READBACK_PROGRESS			m_cb_readback_flash;
        void *								m_cb_readback_flash_arg;

    } FlashTool_Readback_Arg;

    typedef	struct {

        // dummy

    } FlashTool_Readback_Result;

    extern int __stdcall FlashTool_Readback(
        FLASHTOOL_API_HANDLE_T  ft_handle,
        const FlashTool_Readback_Arg  *p_rb_arg,
        FlashTool_Readback_Result  *p_rb_result);



    //------------------------------------------------------------------------------
    // Format
    //------------------------------------------------------------------------------
    typedef	struct {
        // automatically format the FAT area on flash
        _BOOL				m_auto_format_fat;
        // enable/disable erase validation
        _BOOL				m_validation;
        // begin_addr and length only take effect when option is m_enable_auto_format_fat is _FALSE
        unsigned int		m_format_begin_addr;
        unsigned int		m_format_length;
        // automatically format whole flash
        _BOOL                 m_total_format;

        //EMMC manual format begin_addr and length
        unsigned int m_EMMC_format_begin_addr_BP1;
        unsigned int m_EMMC_format_length_BP1;
        unsigned int m_EMMC_format_begin_addr_GP1;
        unsigned int m_EMMC_format_length_GP1;
        unsigned int m_EMMC_format_begin_addr_UA;
        unsigned int m_EMMC_format_length_UA;
    } FORMAT_CONFIG_T;

    typedef	struct {

        HW_StorageType_E					m_storage_type;

        // format config
        FORMAT_CONFIG_T					m_format_cfg;

        // only take effect on NAND flash
        NUTL_EraseFlag_E  					m_erase_flag;

        // format progress callback
        CALLBACK_FORMAT_PROGRESS_INIT		m_cb_format_report_init;
        void *								m_cb_format_report_init_arg;
        CALLBACK_FORMAT_PROGRESS			m_cb_format_report;
        void *								m_cb_format_report_arg;
        // format statistics callback
        CALLBACK_FORMAT_STATISTICS			m_cb_format_statistics;
        void *								m_cb_format_statistics_arg;

        // Enable erase serial nor flash in safe mode, it's just for MT6252/6251/6250/6260. (default is fast mode)
        // In safe mode, all erase operations are actual real erase to flash. (without blank block check before erase)
        NOR_FLASH_ERASE_MODE				m_nor_flash_erase_mode;
    } FlashTool_Format_Arg;

    typedef	struct {

        FormatStatisticsReport_T			m_format_statistics;

    } FlashTool_Format_Result;

    extern int __stdcall FlashTool_Format(
        FLASHTOOL_API_HANDLE_T  ft_handle,
        const FlashTool_Format_Arg  *p_fmt_arg,
        FlashTool_Format_Result  *p_fmt_result);

    typedef enum
    {
        NOT_FORMAT = 0,
            FAT_FORMAT,
            NORMAL_MANUAL_FORMAT,
            EMMC_MANUAL_FORMAT,
            REGION_FROMAT,
            TOTAL_FORMAT
    }FORMAT_ACTION_TYPE_E;

    typedef enum
    {
        BOOT_REGION = 0,
            MAIN_REGION
    }REGION_LAYOUT_E;

    typedef struct
    {
        REGION_LAYOUT_E    region;
    }RegionFormatArg;

    typedef struct
    {
        unsigned int startAddr;
        unsigned int length;
    }ManualFormatArg;

    typedef struct
    {
        _BOOL                   isTotalFormatEnabled;
        ManualFormatArg     formatRange;
    }PartitionFormatArg;

#define BOOT_AREA_NUM                      2
#define RPMB_AREA_NUM                      1
#define GENERAL_PURPOSE_AREA_NUM    4
#define USER_DATA_AREA_NUM              1

    typedef struct
    {
        ManualFormatArg bootArea[BOOT_AREA_NUM];
        ManualFormatArg rpmbArea[RPMB_AREA_NUM];
        ManualFormatArg generalPurposeArea[GENERAL_PURPOSE_AREA_NUM];
        ManualFormatArg userDataArea[USER_DATA_AREA_NUM];
    }EMMC_ManualFormatArg;

    typedef struct
    {
        NUTL_EraseFlag_E    formatFlag;
        ManualFormatArg     formatRange;
    }NAND_ManualFormatArg;

    typedef union
    {
        RegionFormatArg                region;
        ManualFormatArg               manual;
        NAND_ManualFormatArg      NAND_manual;
        EMMC_ManualFormatArg     EMMC_manual;
    }FORMAT_ACTION_ARG_U;

    typedef struct
    {
        FORMAT_ACTION_TYPE_E    type;
        FORMAT_ACTION_ARG_U     uArg;
    }FORMAT_ACTION_T;

    typedef struct
    {
        HW_StorageType_E   storageType;
        _BOOL				validation;	// enable/disable erase validation
        FORMAT_ACTION_T   formatAction;
    }FORMAT_CONFIG_EX_T;

    typedef	struct
    {

        FORMAT_CONFIG_EX_T  m_format_cfg;

        // format progress callback
        CALLBACK_FORMAT_PROGRESS_INIT		m_cb_format_report_init;
        void *								m_cb_format_report_init_arg;
        CALLBACK_FORMAT_PROGRESS			m_cb_format_report;
        void *								m_cb_format_report_arg;
        // format statistics callback
        CALLBACK_FORMAT_STATISTICS			m_cb_format_statistics;
        void *								m_cb_format_statistics_arg;

        // Enable erase serial nor flash in safe mode, it's just for MT6252/6251/6250/6260. (default is fast mode)
        // In safe mode, all erase operations are actual real erase to flash. (without blank block check before erase)
        NOR_FLASH_ERASE_MODE				m_nor_flash_erase_mode;
    } FlashTool_Format_Arg_Ex;

    extern void ConvertArgExToArg(const FlashTool_Format_Arg_Ex& src,
        FlashTool_Format_Arg& dest);

    extern int __stdcall FlashTool_Format_Ex(
        FLASHTOOL_API_HANDLE_T ft_handle,
        const FlashTool_Format_Arg_Ex  *p_fmt_arg_ex,
        FlashTool_Format_Result  *p_fmt_result);

    extern int __stdcall FlashTool_EraseFirstBlock(FLASHTOOL_API_HANDLE_T ft_handle);

    //------------------------------------------------------------------------------
    // Flash read/write
    //------------------------------------------------------------------------------

    //
    // [Parameters]
    //   ft_handle     [IN] flashtool API handle
    //   block_index   [IN] physical block index
    //   page_buf      [IN] page buffer
    //   spare_buf     [IN] spare buffer
    //
    // [Remarks]
    //   The length of page buffer must be (page size) * (# of pages per block).
    //   The length of spare buffer must be (spare size) * (# of pages per block).
    extern int __stdcall FlashTool_NANDWriteBlock(FLASHTOOL_API_HANDLE_T ft_handle,
        unsigned int block_index,
        const unsigned char *page_buf,
        const unsigned char *spare_buf);

    typedef enum
    {
        AddressingMode_BlockIndex = 0,
            AddressingMode_PhysicalAddress
    } AddressingMode;

    typedef enum
    {
        OutputMode_ToBuffer = 0,
            OutputMode_ToFile
    } OutputMode;

    typedef struct
    {
        HW_StorageType_E m_flash_type;
        AddressingMode m_addressing_mode;
        unsigned int m_address;
        unsigned int m_length;
        unsigned int m_container_length; // In blocks, only valid for NAND
        OutputMode m_output_mode;
        char *m_output;

        CALLBACK_READ_FLASH_PROGRESS m_cb_progress;
        void *m_cb_progress_arg;
    } ReadFlashMemoryParameter;

    typedef struct
    {
        unsigned int m_num_bytes_read;
    } ReadFlashMemoryResult;

    typedef enum
    {
        InputMode_FromBuffer = 0,
            InputMode_FromFile
    } InputMode;

    typedef struct
    {
        HW_StorageType_E m_flash_type;
        AddressingMode m_addressing_mode;
        unsigned int m_address;
        unsigned int m_container_length; // In blocks, only valid for NAND
        InputMode m_input_mode;
        const char *m_input;
        unsigned int m_input_length;

        CALLBACK_WRITE_FLASH_PROGRESS m_cb_progress;
        void *m_cb_progress_arg;
    } WriteFlashMemoryParameter;

    extern int __stdcall FlashTool_ReadFlashMemory(
        FLASHTOOL_API_HANDLE_T ft_handle,
        const ReadFlashMemoryParameter *parameter,
        ReadFlashMemoryResult *result);

    extern int __stdcall FlashTool_WriteFlashMemory(
        FLASHTOOL_API_HANDLE_T ft_handle,
        const WriteFlashMemoryParameter *parameter);



    //------------------------------------------------------------------------------
    // Retrieve FAT ranges
    //------------------------------------------------------------------------------
    typedef struct
    {
        unsigned int m_start_address;
        unsigned int m_length;    // 0 for an invalid range
    } Range;

    extern int __stdcall FlashTool_GetFATRanges(FLASHTOOL_API_HANDLE_T ft_handle,
        Range *nor_fat_range,
        Range *nand_fat_range);

    typedef struct
    {
        HW_StorageType_E m_storage_type;
        unsigned int m_start_address;
        unsigned int m_length;
    } FATRegion;

    extern int __stdcall FlashTool_GetFATRanges_Ex(
        FLASHTOOL_API_HANDLE_T ft_handle,
        unsigned int *num_fat_regions, // in/out
        FATRegion *fat_regions);

    //------------------------------------------------------------------------------
    // SEC_RO read/write
    //------------------------------------------------------------------------------
    typedef struct {
        unsigned int		m_addr;
        unsigned int		m_len;
    } SecRO_Info_T;

    typedef struct {
        unsigned int		m_len;
        unsigned char *		m_data;
    } SecRO_T;

    extern int __stdcall FlashTool_SecRO_GetInfo(FLASHTOOL_API_HANDLE_T  ft_handle, SecRO_Info_T  *p_sec_ro_info);
    extern int __stdcall FlashTool_SecRO_Read(FLASHTOOL_API_HANDLE_T  ft_handle, SecRO_T  *p_sec_ro);
    extern int __stdcall FlashTool_SecRO_Write(FLASHTOOL_API_HANDLE_T  ft_handle, const SecRO_T  *p_sec_ro);

    //------------------------------------------------------------------------------
    // CustPara read/write
    //------------------------------------------------------------------------------
    typedef struct {
        unsigned int		m_addr;
        unsigned int		m_len;
    } CustPara_Info_T;

    typedef struct {
        unsigned int		m_len;
        unsigned char *		m_data;
    } CustPara_T;

    extern int __stdcall FlashTool_CustPara_GetInfo(FLASHTOOL_API_HANDLE_T  ft_handle, CustPara_Info_T  *p_cust_para_info);
    extern int __stdcall FlashTool_CustPara_Read(FLASHTOOL_API_HANDLE_T  ft_handle, CustPara_T  *p_cust_para);
    extern int __stdcall FlashTool_CustPara_Write(FLASHTOOL_API_HANDLE_T  ft_handle, const CustPara_T  *p_cust_para);

    //------------------------------------------------------------------------------
    // Update FlashTool Config
    //------------------------------------------------------------------------------
    typedef struct {
        unsigned int		m_lockdown:1;
        unsigned int		m_disable_code_download:1;
        unsigned int		m_disable_code_readback:1;
        unsigned int		m_disable_code_format:1;
        unsigned int		m_disable_sec_ro_download:1;
        unsigned int		m_disable_sec_ro_readback:1;
        unsigned int		m_disable_fat_download:1;
        unsigned int		m_disable_fat_readback:1;
        unsigned int		m_disable_fat_format:1;
        unsigned int		m_restricted_area_access_forbidden:1;
    } SecurityBitCtrl_T;

    typedef union {
        SecurityBitCtrl_T	m_bit_ctrl;
        unsigned int		m_uint32;
    } SecurityCfg_U;

    typedef struct {
        SecurityCfg_U		m_security_cfg;
    } FlashToolCfg_T;

    extern int __stdcall FlashTool_UpdateConfig(FLASHTOOL_API_HANDLE_T  ft_handle, const FlashToolCfg_T  *p_ft_cfg);

    //----------------------------------------------------------------------------
    // Enable boot
    //----------------------------------------------------------------------------
    typedef struct {
        unsigned int m_len;
        unsigned char *m_data;
    } BootCert_T;

    extern int __stdcall FlashTool_EnableBoot(FLASHTOOL_API_HANDLE_T ft_handle,
        const BootCert_T *p_boot_cert);

    //------------------------------------------------------------------------------
    // Get Project ID
    //------------------------------------------------------------------------------
    extern int __stdcall FlashTool_GetProjectId(FLASHTOOL_API_HANDLE_T  ft_handle, char *output_buf, unsigned int output_buf_len);

    //------------------------------------------------------------------------------
    // OTP read/write
    //------------------------------------------------------------------------------
    typedef enum {
        PARAM_READ = 0
            ,PARAM_WRITE
            ,PARAM_OPERATION_END
    } PARAM_OPERATION;

    typedef enum {
        OTP_READ = 0
            ,OTP_WRITE
            ,OTP_LOCK
            ,OTP_WRITE_AND_LOCK
            ,OTP_OPERATION_END
    } OTP_OPERATION;

    typedef struct {
        unsigned int		m_addr;
        unsigned int		m_len;
        unsigned char *		m_data;
    } OTP_T;

    extern int __stdcall FlashTool_OTP_CheckDevice(FLASHTOOL_API_HANDLE_T  ft_handle);
    extern int __stdcall FlashTool_OTP_GetSize(FLASHTOOL_API_HANDLE_T  ft_handle, unsigned int * otp_size);
    extern int __stdcall FlashTool_OTP_Read(FLASHTOOL_API_HANDLE_T  ft_handle, OTP_T * p_otp);
    extern int __stdcall FlashTool_OTP_Write(FLASHTOOL_API_HANDLE_T  ft_handle, const OTP_T * p_otp);
    extern int __stdcall FlashTool_OTP_Lock(FLASHTOOL_API_HANDLE_T  ft_handle);
    extern int __stdcall FlashTool_OTP_LockCheckStatus(FLASHTOOL_API_HANDLE_T  ft_handle);

    //------------------------------------------------------------------------------
    // Repair Tool : Exception Record Retriever
    //------------------------------------------------------------------------------
    extern int __stdcall RepairTool_GetDIRInfo( FLASHTOOL_API_HANDLE_T  ft_handle, char * fn_dir);
    extern int __stdcall RepairTool_GetExceptionRecord( FLASHTOOL_API_HANDLE_T  ft_handle, char * fn_exceptionlog, char * fn_store);

    //------------------------------------------------------------------------------
    // CBR read/write
    //------------------------------------------------------------------------------

    typedef struct {
        unsigned int		m_recordID;
        unsigned int		m_len;
    } CBR_Info_T;

    typedef struct {
        unsigned int		m_len;
        unsigned char *		m_data;
    } CBR_T;

    extern int __stdcall FlashTool_CBR_GetInfo(FLASHTOOL_API_HANDLE_T  ft_handle, const unsigned int recordID, CBR_Info_T  *p_cbr_info);
    // Note : if target flash haven't CBR, FlashTool_CBR_GetInfo() will return S_DA_CBR_RECORD_NOT_EXIST (3162).
    extern int __stdcall FlashTool_CBR_Read(FLASHTOOL_API_HANDLE_T  ft_handle, const unsigned int recordID, CBR_T  *p_cbr);
    extern int __stdcall FlashTool_CBR_Write(FLASHTOOL_API_HANDLE_T  ft_handle, const CBR_T  *p_cbr);
    extern int __stdcall FlashTool_CBR_Raw_Write(FLASHTOOL_API_HANDLE_T  ft_handle, const unsigned int recordID, CBR_T  *p_cbr);
    //------------------------------------------------------------------------------
    // Memory Test Tool : RAM/Flash Stress Test and Addr/Data Bus Test
    //------------------------------------------------------------------------------
#define MEMORYTEST_STOP		9876

    typedef struct {
        HW_MemoryType_E			m_memory_device;
        unsigned int			m_start_addr;
        unsigned int			m_size;
        HW_MemoryIO_E			m_memory_io;
        HW_MemoryTestMethod_E	m_test_method;
        unsigned int			m_test_pattern;

        // callback function
        CALLBACK_MEMORYTEST_PROGRESS_INIT		  m_cb_memorytest_progress_init;
        void *									  m_cb_memorytest_progress_init_arg;
        CALLBACK_MEMORYTEST_PROGRESS			  m_cb_memorytest_progress;
        void *									  m_cb_memorytest_progress_arg;
        CALLBACK_MEMORYTEST_NAND_BAD_BLOCK_REPORT m_cb_memorytest_nand_bad_block_report;
        void *                                    m_cb_memorytest_nand_bad_block_report_arg;

        // stop flag
        int *					m_p_stopflag;
    } FlashTool_MemoryTest_Arg;

    typedef struct {
        // return value
        unsigned int			m_ret;
        // Error result for Pattern Test and Inc/Dec Test
        unsigned int			m_pass_pattern;
        unsigned int			m_fail_addr;
        unsigned int			m_fail_pattern;
        // Error result for Data Bus Test, Address Bus Test, and I/O Bus Test
        unsigned int			m_fail_value;
        unsigned int			m_fail_pin;
        unsigned int			m_fail_pin2;
        // Memory dump value for HW_MEM_DUMP
        unsigned char			*m_dump_buf;

        unsigned int			m_num_bad_blocks; // Only valid for NAND test
    } FlashTool_MemoryTest_Result;

    extern int __stdcall FlashTool_MemoryTest( FLASHTOOL_API_HANDLE_T  ft_handle, const FlashTool_MemoryTest_Arg *p_mt_arg, FlashTool_MemoryTest_Result * p_mt_result);

    //------------------------------------------------------------------------------
    // Partition Download
    //------------------------------------------------------------------------------
    extern int __stdcall FlashTool_ReadPartitionInfo(FLASHTOOL_API_HANDLE_T ft_handle, PART_INFO *p_part_info, unsigned int max_part_count);
    extern int __stdcall FlashTool_ReadPartitionCount(FLASHTOOL_API_HANDLE_T ft_handle, unsigned int *p_part_count);

    /* Phase out
    //------------------------------------------------------------------------------
    // ROM Writer : Extract/Inject NFB Images
    //------------------------------------------------------------------------------
    #define DEFAULT_STORING_EXTRACT_NFB			"C:\\MTK_ExtractNFB.bin"

     #define	MAX_FILENAME_LENGTH		256

      typedef	struct {
      // post-process callback
      CALLBACK_PROGRESS_INIT				m_cb_progress_init;
      void *								m_cb_progress_init_arg;
      CALLBACK_PROGRESS					m_cb_progress;
      void *								m_cb_progress_arg;
      } FlashTool_Progress_Arg;

       typedef	struct {
       // dummy
       } FlashTool_Progress_RESULT;


         extern int __stdcall FlashTool_ExtractNFB( FLASHTOOL_API_HANDLE_T  ft_handle, char * fn_store, const FlashTool_Progress_Arg  *p_pgs_arg);
         extern int __stdcall FlashTool_InjectNFB( FLASHTOOL_API_HANDLE_T  ft_handle, char * fn_store, const FlashTool_Progress_Arg  *p_pgs_arg);
    */

    //------------------------------------------------------------------------------
    // DA Relay Mode for GPS Project
    //------------------------------------------------------------------------------
    typedef struct {

        unsigned int		m_power_pin;
        unsigned int		m_reset_pin;
        unsigned int		m_standby_pin;
        unsigned int		m_32k_pin;
    } GPIO_GPS_SETTING;

    extern int __stdcall FlashTool_RelayDA( FLASHTOOL_API_HANDLE_T  ft_handle, const GPIO_GPS_SETTING *p_gpio_gps);


    //------------------------------------------------------------------------------
    //  Change USB1.1 to USB2.0 in download stage while using BROM USBDL
    //------------------------------------------------------------------------------

    typedef int (__stdcall *CALLBACK_CHANGE_USB_SPEED_PREPROCESS)(void *usr_arg);
    typedef int (__stdcall *CALLBACK_CHANGE_USB_SPEED_POSTPROCESS)(void *usr_arg);

    typedef struct {
        // callback function
        CALLBACK_CHANGE_USB_SPEED_PREPROCESS	  m_cb_preprocess;
        void *									  m_cb_preprocess_arg;
        CALLBACK_CHANGE_USB_SPEED_POSTPROCESS	  m_cb_postprocess;
        void *									  m_cb_postprocess_arg;

        // stop flag
        int *					m_p_stopflag;
    } FlashTool_ChangeUSBSpeed_Arg;

    extern int __stdcall FlashTool_ChangeUSBSpeed(FLASHTOOL_API_HANDLE_T  ft_handle,
        const FlashTool_ChangeUSBSpeed_Arg *pArg);

    //------------------------------------------------------------------------------
    //  Change the behavior of com port operations, open/read/write...
    //------------------------------------------------------------------------------
	typedef HANDLE	(_stdcall *FUNC_Open)(unsigned short port, char* filename, const int line);
	typedef BOOL	(_stdcall *FUNC_Cancel)(HANDLE hCon, char* filename, const int line);
	typedef BOOL	(_stdcall *FUNC_Close)(HANDLE hCon, char* filename, const int line);
	typedef BOOL	(_stdcall *FUNC_Send)(HANDLE hCon, const void *pBuf, DWORD nNumberOfBytesToWrite, DWORD *pNumberOfBytesWritten, char* filename, const int line);
	typedef BOOL	(_stdcall *FUNC_Recv)(HANDLE hCon, void *pBuf, DWORD nNumberOfBytesToRead, DWORD *pNumberOfBytesRead, char* filename, const int line);

	typedef DWORD	(_stdcall *FUNC_GetLastError)(char* filename, const int line);
	typedef BOOL	(_stdcall *FUNC_FlushFileBuffers)(HANDLE hCon, char* filename, const int line);
	typedef BOOL	(_stdcall *FUNC_ClearCommBreak)(HANDLE hCon, char* filename, const int line);
	typedef BOOL	(_stdcall *FUNC_ClearCommError)(HANDLE hCon, DWORD *pErrors, COMSTAT *pStat, char* filename, const int line);
	typedef BOOL	(_stdcall *FUNC_SetupComm)(HANDLE hCon, DWORD dwInQueue, DWORD dwOutQueue, char* filename, const int line);
	typedef BOOL	(_stdcall *FUNC_EscapeCommFunction)(HANDLE hCon, DWORD dwFunc, char* filename, const int line);
	typedef BOOL	(_stdcall *FUNC_GetCommProperties)(HANDLE hCon, COMMPROP *pCommProp, char* filename, const int line);
	typedef BOOL	(_stdcall *FUNC_GetCommState)(HANDLE hCon, DCB *pDCB, char* filename, const int line);
	typedef BOOL	(_stdcall *FUNC_GetCommTimeouts)(HANDLE hCon, COMMTIMEOUTS *pCommTimeouts, char* filename, const int line);
	typedef BOOL	(_stdcall *FUNC_PurgeComm)(HANDLE hCon, DWORD dwFlags, char* filename, const int line);
	typedef BOOL	(_stdcall *FUNC_SetCommState)(HANDLE hCon, DCB *pDCB, char* filename, const int line);
	typedef BOOL	(_stdcall *FUNC_SetCommTimeouts)(HANDLE hCon, COMMTIMEOUTS *pCommTimeouts, char* filename, const int line);


    extern void __stdcall FlashTool_RegFunctions(
                        FUNC_Open               pFuncOpen,
                        FUNC_Cancel             pFuncCancel,
                        FUNC_Close              pFuncClose,
                        FUNC_Send               pFuncSend,
                        FUNC_Recv               pFuncRecv,
                        FUNC_GetLastError       pFuncGetLastError,
                        FUNC_FlushFileBuffers   pFuncFlushFileBuffers,
                        FUNC_ClearCommBreak     pFuncClearCommBreak,
                        FUNC_ClearCommError     pFuncClearCommError,
                        FUNC_SetupComm          pFuncSetupComm,
                        FUNC_EscapeCommFunction pFuncEscapeCommFunction,
                        FUNC_GetCommProperties  pFuncGetCommProperties,
                        FUNC_GetCommState       pFuncGetCommState,
                        FUNC_GetCommTimeouts    pFuncGetCommTimeouts,
                        FUNC_PurgeComm          pFuncPurgeComm,
                        FUNC_SetCommState       pFuncSetCommState,
                        FUNC_SetCommTimeouts    pFuncSetCommTimeouts);

    extern void __stdcall FlashTool_UnRegFunctions();

#ifdef	__cplusplus
}
#endif

#endif


