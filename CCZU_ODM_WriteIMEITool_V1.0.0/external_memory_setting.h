/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2010
 *
 ****************************************************************************/

/*****************************************************************************
 * Filename:
 * ---------
 *  external_memory_setting.h
 *
 * Project:
 * --------
 *  Flash Download/Readback/Format Library.
 *
 * Description:
 * ------------
 *  External memory setting
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef _EXTERNAL_MEMORY_SETTING_H_
#define _EXTERNAL_MEMORY_SETTING_H_

#include "flashtool_handle.h"   // For DRAM_SETTING and _BOOL

// The current maximum number of MCPs supported in
// a Combo-MCP-enabled MAUI load is around 5
#define MAX_NUM_FLASH_INFO_ENTRIES              8
#define MAX_NUM_EXTERNAL_RAM_SETTING_ENTRIES    MAX_NUM_FLASH_INFO_ENTRIES

#ifdef __cplusplus
extern "C" {
#endif


//
// Flash information
//

typedef enum FLASHType
{
    FLASHType_Invalid = 0,
    FLASHType_NAND,
    FLASHType_NOR,
    FLASHType_SERIAL_FLASH,
    FLASHType_EMMC,
    FLASHType_SPI_NAND,
    FLASHType_End = 0x42424242

} FLASHType;

typedef struct flashID
{
	unsigned int idNumber; // max = 8
	unsigned short id[8];
}flashID;

typedef struct LTE_NFISetting_v01
{
    unsigned int        version;            /*equal to 0x00000301 */
    char                DevName_str[64];	/*Device name string*/
    unsigned char       ID_info[8];			/*equal sizeof(nAND_ID)*/
    unsigned char       ID_valid_mask[8];	/*valid-bit mask of ID_info*/
    unsigned short      deviceSize;			/*unit by MByte (so max < 64GB), exclude the extended block size*/
    unsigned int        blockSize;			/*unit by Byte*/
    unsigned int        nfi_acccon_val;		/*NFI_ACCCON_VAL : NFIC access timing*/
    unsigned int        nfi_rdyto_val;		/*NFI_RDYTO_VAL : FCD busy to ready timeout*/
    unsigned int        nfi_adnob_val;		/*NFI_ADNOB_VAL : Address cycle*/
    unsigned int        nfi_bb_mark[4];		/*NFI_BB_MARK : Bad block mark offset*/
    unsigned int        nfi_dc_val;			/*NFI_DC_VAL : NFIC driving*/
    unsigned int        nfi_drv_set;		/*NFI_DRV_SET : driver type set*/
    unsigned int        nfi_pgfmt_val;		/*NFI_PGFMT_VAL : page format*/
    unsigned int        nfi_tnum_val;		/*NFI_TNUM_VAL: ECC tnum*/
} LTE_NFISetting_v01;


// NOR
typedef struct FlashInfo_v01
{
    flashID NOR_ID;
    struct { int dummy; } NOR_geometry;

} FlashInfo_v01;


// NAND
typedef struct FlashInfo_v02
{
    flashID NAND_ID;
    struct { int dummy; } NAND_Geometry;

    union
    {
        unsigned int       version;
        LTE_NFISetting_v01 v01;
    } SV5x_NFI_Setting_U;

} FlashInfo_v02;


typedef struct FlashInfo
{
    unsigned int version;
    unsigned int numValidEntries;
    FLASHType flashType;

    union
    {
        FlashInfo_v01 v01[MAX_NUM_FLASH_INFO_ENTRIES];
        FlashInfo_v02 v02[MAX_NUM_FLASH_INFO_ENTRIES];
    } u;

} FlashInfo;


//
// External RAM setting (include DRAM, PSRAM)
//

typedef enum DRAMType
{
    DRAMType_Invalid = 0x0,
    DRAMType_DDR,
    DRAMType_DDR2,
    DRAMType_DDR_166M,
    DRAMType_DDR_200M,
    DRAMType_DDR2_166M,
    DRAMType_DDR2_200M,
    DRAMType_DDR3_125M,
    DRAMType_LPDDR = 0x800,
    DRAMType_LPDDR2,
    DRAMType_LPDDR_166M,
    DRAMType_LPDDR_200M,
    DRAMType_LPDDR2_166M,
    DRAMType_LPDDR2_200M,	
    DRAMType_DDR_166M_SIP = 0x1000,   // SIP DRAM
    DRAMType_DDR_200M_SIP,
    DRAMType_DDR2_166M_SIP,
    DRAMType_DDR2_200M_SIP,
    DRAMType_LPDDR_SIP = 0x1800,
    DRAMType_LPDDR2_SIP,
    DRAMType_LPDDR_166M_SIP,
    DRAMType_LPDDR_200M_SIP,
    DRAMType_LPDDR2_166M_SIP,
    DRAMType_LPDDR2_200M_SIP,
    DRAMType_End = 0x42424242
} DRAMType;


typedef enum PMIC_Controller
{
    PMIC_Dev_Invalid = 0x0,
    PMIC_MT6321,
    PMIC_MT6327,
    PMIC_MT6329,
    PMIC_MT7205,
    PMIC_Dev_End = 0x42424242
}PMIC_Controller;


typedef struct DRAMSetting_v03
{
    DRAMType ramType;
    unsigned int EMI_CONI_Value;
    unsigned int EMI_CONJ_Value;
    unsigned int EMI_CONK_Value;
    unsigned int EMI_CONL_Value;
    unsigned int EMI_CONN_Value;
    unsigned int EMI_DQSA_Value;
    unsigned int EMI_DRVA_Value;
    unsigned int EMI_DRVB_Value;
    unsigned int EMI_ODLA_Value;
    unsigned int EMI_ODLB_Value;
    unsigned int EMI_ODLC_Value;
    unsigned int EMI_ODLD_Value;
    unsigned int EMI_ODLE_Value;
    unsigned int EMI_ODLG_Value;
} DRAMSetting_v03;

typedef struct DRAMSetting_v05
{
    DRAMType ramType;
    unsigned int EMI_CONI_Value;
    unsigned int EMI_CONJ_Value;
    unsigned int EMI_CONK_Value;
    unsigned int EMI_CONL_Value;
    unsigned int EMI_CONN_Value;
    // remove DQSA
    unsigned int EMI_DRVA_Value;
    unsigned int EMI_DRVB_Value;
    unsigned int EMI_ODLA_Value;
    unsigned int EMI_ODLB_Value;
    unsigned int EMI_ODLC_Value;
    unsigned int EMI_ODLD_Value;
    unsigned int EMI_ODLE_Value;
    unsigned int EMI_ODLF_Value; //New
    unsigned int EMI_ODLG_Value;
    // new 6 register
    unsigned int EMI_DUTA_Value;
    unsigned int EMI_DUTB_Value;
    unsigned int EMI_DUTC_Value;
    unsigned int EMI_DUCA_Value;
    unsigned int EMI_DUCB_Value;
    unsigned int EMI_DUCE_Value;
    unsigned int EMI_IOCL_Value;
} DRAMSetting_v05;

typedef struct DRAMSetting_v06
{
    DRAMType ramType;
    unsigned int EMI_CONI_Value;
    unsigned int EMI_CONJ_Value;
    unsigned int EMI_CONK_Value;
    unsigned int EMI_CONL_Value;
    unsigned int EMI_CONN_Value;

    unsigned int EMI_DRVA_Value;
    unsigned int EMI_DRVB_Value;
//    unsigned int EMI_ODLA_Value;
//    unsigned int EMI_ODLB_Value;
//    unsigned int EMI_ODLC_Value;
//    unsigned int EMI_ODLD_Value;
    unsigned int EMI_ODLE_Value;
    unsigned int EMI_ODLF_Value;
    unsigned int EMI_ODLG_Value;
    unsigned int EMI_ODLH_Value;
    //New 7 register (to v05)
    unsigned int EMI_ODLI_Value;
    unsigned int EMI_ODLJ_Value;
    unsigned int EMI_ODLK_Value;
    unsigned int EMI_ODLL_Value;
    unsigned int EMI_ODLM_Value;
    unsigned int EMI_ODLN_Value;

    unsigned int EMI_DUTA_Value;
    unsigned int EMI_DUTB_Value;
    unsigned int EMI_DUTC_Value;
    unsigned int EMI_DUCA_Value;
    unsigned int EMI_DUCB_Value;
    unsigned int EMI_DUCE_Value;
    unsigned int EMI_IOCL_Value;
} DRAMSetting_v06;


typedef struct LTE_DRAMSetting_v01
{
    DRAMType ramType;
    unsigned int EMI_CONA_val;              //@0x3000
    unsigned int EMI_TESTD_val;             //@0x30F8
    unsigned int DRAMC_DRVCTL0_val;         //@0x40B8               -> customized TX I/O driving
    unsigned int DRAMC_DRVCTL1_val;         //@0x40BC               -> customized TX I/O driving
    unsigned int DRAMC_PADCTL4_val;         //@0x40E4               -> customized
    unsigned int DRAMC_ACTIM0_val;          //@0x4000
    unsigned int DRAMC_GDDR3CTL1_val;       //@0x40F4
    unsigned int DRAMC_CONF1_val;           //@0x4004
    unsigned int DRAMC_DDR2CTL_val;         //@0x407C
    unsigned int DRAMC_TEST2_3_val;         //@0x4044
    unsigned int DRAMC_CONF2_val;           //@0x4008
    unsigned int DRAMC_PD_CTRL_val;         //@0x41DC
    unsigned int DRAMC_PADCTL3_val;         //@0x4014               -> customized TX DQS delay
    unsigned int DRAMC_DQODLY_val;          //@0x4200~0x420C        -> customized TX DQ delay
    unsigned int DRAMC_ADDRODLY_val;        //for ASIC only
    unsigned int DRAMC_CLKODLY_val;         //for ASIC only
    unsigned int DRAMC_ACTIM1_val;          //@0x41E8
    unsigned int DRAMC_MISCTL0_val;         //@0x40FC
    unsigned int DRAM_LPDDR2_MR2_val;       //only for LPDDR2
    unsigned int DRAM_LPDDR2_MR3_val;       //only for LPDDR2

} LTE_DRAMSetting_v01;

typedef struct LTE_DRAMSetting_v02
{
    DRAMType ramType;
    unsigned int DRAMC_ACTIM0_val;
    unsigned int DRAMC_ACTIM1_val;
    unsigned int DRAMC_ADDRODLY_val;
    unsigned int DRAMC_CLKODLY_val;
    unsigned int DRAMC_CONF1_val;
    unsigned int DRAMC_CONF2_val;
    unsigned int DRAMC_DDR2CTL_val;
    unsigned int DRAMC_DQODLY_val;
    unsigned int DRAMC_DQSODLY_val;
    unsigned int DRAMC_DRVCTL0_val;
    unsigned int DRAMC_DRVCTL1_val;
    unsigned int DRAMC_MISCTL0_val;
    unsigned int DRAMC_PADCTL4_val;
    unsigned int DRAMC_PD_CTRL_val;
    unsigned int DRAMC_TEST2_3_val;
    unsigned int DRAM_AC_DERATING_val;
    unsigned int DRAM_LPDDR2_MR2_val;
    unsigned int DRAM_LPDDR2_MR3_val;
    unsigned int DRAMC_GDDR3CTL1_val;
    unsigned int EMI_CONA_val;
    unsigned int EMI_TESTD_val;

} LTE_DRAMSetting_v02;


typedef enum ExtRamType
{
    RAMType_Invalid = 0,
    RAMType_DDR,         // MCP DRAM
    RAMType_DDR2,
    RAMType_DDR_166M,
    RAMType_DDR_200M,
    RAMType_DDR2_166M,
    RAMType_DDR2_200M,
    RAMType_DDR3_125M,
    RAMType_DDR_166M_SIP = 0x1000,   // SIP DRAM
    RAMType_DDR_200M_SIP,
    RAMType_DDR2_166M_SIP,
    RAMType_DDR2_200M_SIP,
    RAMType_SRAM_Normal = 0x10000,       // PSRAM
    RAMType_End = 0x42424242

} ExtRamType;


// DA EMI PARAM
typedef enum {
    LTE_DRAMSetting_VER_3_0 = 0x0003000,
    LTE_DRAMSetting_VER_3_1 = 0x0003001,
} LET_DRAMSetting_Version;

typedef struct{
    LET_DRAMSetting_Version version;  // map to EMI's LET_CFG_Version enum
    union
    {
        LTE_DRAMSetting_v01 v01;
        LTE_DRAMSetting_v02 v02;
    } LTE_DRAMSetting_U;
} SV5x_DRAMSetting; // map to EMI's LTE_DRAMSetting struct
// End of DA EMI PARAM


typedef struct ExternalRAMSetting
{
    unsigned int version;
    unsigned int numValidEntries;
    ExtRamType ramType;

    union
    {
        DRAM_SETTING    v00[MAX_NUM_EXTERNAL_RAM_SETTING_ENTRIES];
        DRAMSetting_v03 v03[MAX_NUM_EXTERNAL_RAM_SETTING_ENTRIES];
        DRAMSetting_v05 v05[MAX_NUM_EXTERNAL_RAM_SETTING_ENTRIES];
        DRAMSetting_v06 v06[MAX_NUM_EXTERNAL_RAM_SETTING_ENTRIES];
    } u;

    SV5x_DRAMSetting SV5x_dramSetting[MAX_NUM_EXTERNAL_RAM_SETTING_ENTRIES]; // SV5x

} ExternalRAMSetting;

typedef enum CFG_Type_Version
{
    CFGType_Invalid = 0,
    CFGType_ALPHA3,
    CFGType_V1,
    CFGType_V2,
    CFGType_V3,
    CFGType_V3_1,
    CFGType_End = 0x42424242
}CFG_Type_Version;


//
// External memory setting
//
typedef struct ExternalMemorySetting
{
    _BOOL               valid;
    BBCHIP_TYPE         bbchipType;
    CFG_Type_Version    CFGVersion;
    PMIC_Controller     PMICController;
    ExternalRAMSetting  ramSetting;
    FlashInfo           flashInfo;  // Required for Combo MCP

} ExternalMemorySetting;

//
// EPP PARAM
//

typedef union
{
    DRAMSetting_v03 v03;
    DRAMSetting_v05 v05;
    DRAMSetting_v06 v06;
} DRAMSetting_U;

typedef struct
{
    CFG_Type_Version cfg_version;
    ExtRamType       m_ExtRamType;
    PMIC_Controller  m_PMIC_Controller;
    DRAMSetting_U    MTK_DRAM_Setting;

    unsigned char reserved[256 -
                   sizeof(unsigned int) -
                   sizeof(ExtRamType) -
                   sizeof(PMIC_Controller) -
                   sizeof(DRAMSetting_U)];
} EPP_PARAM;



#ifdef __cplusplus
}
#endif

#endif // _EXTERNAL_MEMORY_SETTING_H_
