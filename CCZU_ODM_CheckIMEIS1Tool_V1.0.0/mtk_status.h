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
 *  mtk_status.h
 *
 * Project:
 * --------
 *  BootRom Library
 *
 * Description:
 * ------------
 *  The definition of error code
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *******************************************************************************/
#ifndef _MTK_STATUS_H_
#define _MTK_STATUS_H_

//------------------------------------------------------------------------------
// return code
//------------------------------------------------------------------------------
/*! \file mtk_status.h
    \brief A header file which includes the enum type definition of all error codes.

    Details.
*/

/*! \mainpage FlashTool Error Codes

- \subpage page1
- \subpage intro

The information on this document is intended to be used by programmers.
The error codes are listed in mtk_status.h header file.

*/

//-----------------------------------------------------------
/*! \page page1 Legal Disclaimer
BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS ONLY.

MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
PURPOSE OR NONINFRINGEMENT.  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER
WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN,
OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH THIRD PARTY
FOR ANY WARRANTY CLAIM RELATING THERETO.  MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY
MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD
OR OPEN FORUM.

BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO
REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR
SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.

THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS OF
THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
*/
//-----------------------------------------------------------

/*! \page intro Introduction
For all APIs in BROM DLL, if the function succeeds, the return value is zero value, S_DONE(0).
If the function fails, the return value is non-zero value. This document is designed to help
phone maker to understand what these error codes (non-zero value) mean.

In the following sections, many series of error code information are introduced.
They are error codes for user issues, MAUI S/W issues, H/W issues, Tool issues, DLL issues,
DA issues, internal errors, internal states, and obsolete errors. Each series of error code
information is used to specific purpose.

2, User's issue is used to give user a warning message for his incorrect using.

3, MAUI S/W Issue is used to describe there's some problem in MAUI project.
H/W Issue is used to describe that there's some problem in UAR cable or SMT issue.
Please ask for MTK's help.

4, Tool Issue is used to describe there's some problem in Tool's developing.
Please ask Tool developer for help. DLL Issue is used to describe there's some problem in DLL.
DA (Download Agent) Issue is used to describe there's some problem in DA.
Please ask for MTK's help.

5, Internal Error is used in internal implementation. Internal State is used in internal
implementation. Obsolete Error has not been used. Please ignore error code in this section.
*/
//-----------------------------------------------------------


/*! \var typedef enum STATUS_E
    \brief A type definition for error code.

    Details.
    private random error code (1~999)
    common error code (1000~1999)
*/
    //[User's Issue]
    //[MAUI S/W Issue]
    //[H/W Issue]
    //[Tool Issue]
    //[DLL Issue]
    //[DA Issue]
    //[Internal Error]
    //[Internal State]
    //[Obsolete Error]
typedef enum {

    S_DONE = 0                          /*!< (0) OK */
    // private random error code (1~999)

    // common error code (1000~1999)
    ,S_COMMON_ERROR_BEGIN = 1000                /*!<common error code (1000~1999)*/
    ,S_STOP = S_COMMON_ERROR_BEGIN              /*!<(1000) Operation stopped by the user */
    ,S_UNDEFINED_ERROR = 1001                   /*!<(1001) <B>[DLL Issue]</B> */
    ,S_INVALID_ARGUMENTS = 1002                 /*!<(1002) <B>[Tool Issue]</B> An error occurs when user uses BROM DLL APIs with invalid arguments, like NULL pointer. Please check your parameters again.*/
    ,S_INVALID_BBCHIP_TYPE = 1003               /*!<(1003) <B>[Tool Issue]</B> An internal error occurs when BROM DLL uses an invalid type of baseband chip. Please check the parameter again.*/
    ,S_INVALID_EXT_CLOCK = 1004                 /*!<(1004) <B>[Tool Issue]</B> An internal error occurs when BROM DLL uses an invalid external clock type. Please check your parameter again. */
    ,S_GET_DLL_VER_FAIL = 1005                  /*!<(1005) <B>[DLL Issue]</B> */
    ,S_INVALID_BUF = 1006                       /*!<(1006) <B>[Obsolete Error]</B> */
    ,S_BUF_IS_NULL = 1007                       /*!<(1007) <B>[Tool Issue]</B> An error occurs when pointer of buffer is NULL. Please check your parameters again.*/
    ,S_BUF_LEN_IS_ZERO = 1008                   /*!<(1008) <B>[Tool Issue]</B> An error occurs when the length of buffer is zero. Please check your parameters again.*/
    ,S_BUF_SIZE_TOO_SMALL = 1009                /*!<(1009) <B>[Tool Issue]</B> An error occurs when the length of buffer is too small. Please check your parameters again.*/
    ,S_NOT_ENOUGH_MEMORY = 1010                 /*!<(1010) <B>[Tool Issue]</B> An error occurs when BROM DLL creates handle because the memory is not enough. Please give user a warning message and close this Tool.*/
    ,S_COM_PORT_OPEN_FAIL = 1011                /*!<(1011) <B>[Tool Issue]</B> An error occurs when BROM DLL fails to open com port because other software is using this com port. Please give user a warning message.*/
    ,S_COM_PORT_SET_TIMEOUT_FAIL = 1012         /*!<(1012) <B>[Tool Issue]</B> An error occurs when SetCommTimeouts() return fail. Please give user a warning message.*/
    ,S_COM_PORT_SET_STATE_FAIL = 1013           /*!<(1013) <B>[Obsolete Error]</B> */
    ,S_COM_PORT_PURGE_FAIL = 1014               /*!<(1014) <B>[Obsolete Error]</B> */
    ,S_FILEPATH_NOT_SPECIFIED_YET = 1015        /*!<(1015) <B>[Tool Issue]</B> An error occurs when the path of read-back file is not specified. Please check your parameters again.*/
    ,S_UNKNOWN_TARGET_BBCHIP = 1016             /*!<(1016) <B>[User's Issue]</B> An error occurs when handset's
                                                    baseband chip is unknown type. Please check DA
                                                    and BROM DLL are on the same version. */
    ,S_SKIP_BBCHIP_HW_VER_CHECK = 1017          /*!<(1017) <B>[Internal Error]</B> */
    ,S_UNSUPPORTED_VER_OF_BOOT_ROM = 1018       /*!<(1018) <B>[User's Issue]</B> An error occurs when BOOT ROM returns
                                                    an unsupported version of BOOT ROM. Please
                                                    check DA and BROM DLL are the latest version.*/
    ,S_UNSUPPORTED_VER_OF_BOOTLOADER = 1019     /*!<(1019) <B>[MAUI S/W Issue]</B> A Tool's warning that Boot Loader Image file contains an unsupported version in its header. Please ask for help.*/
    ,S_UNSUPPORTED_VER_OF_DA = 1020             /*!<(1020) <B>[MAUI S/W Issue]</B> A Tool's warning that DA binary file contains an unsupported version in its header. Please ask for help.*/
    ,S_UNSUPPORTED_VER_OF_SEC_INFO = 1021       /*!<(1021) <B>[MAUI S/W Issue]</B> A Tool's warning that MAUI binary file contains an unsupported security version. Please ask for help.*/
    ,S_UNSUPPORTED_VER_OF_ROM_INFO = 1022       /*!<(1022) <B>[MAUI S/W Issue]</B> A Tool's warning that MAUI binary file contains an unsupported MAUI version. Please ask for help.*/
    ,S_SEC_INFO_NOT_FOUND = 1023                /*!<(1023) <B>[User's Issue]</B> You are using a non-secure MAUI, but there exists a secure-MAUI in the handset. Please format flash before downloading this non-secure MAUI.*/
    ,S_ROM_INFO_NOT_FOUND = 1024                /*!<(1024) <B>[MAUI S/W Issue]</B> A Tool's warning that there doesn't exist a header in MAUI file. Please ask for help*/
    ,S_CUST_PARA_NOT_SUPPORTED = 1025           /*!<(1025) <B>[User's Issue]</B> A Tool's warning that the phone doesn't support CUST_PARA.*/
    ,S_CUST_PARA_WRITE_LEN_INCONSISTENT = 1026  /*!<(1026) <B>[User's Issue]</B> A Tool's warning that the size of CUST_PARA file needed to write is inconsistent with the length described in the phone.*/
    ,S_SEC_RO_NOT_SUPPORTED = 1027              /*!<(1027) <B>[User's Issue]</B> A Tool's warning that the phone doesn't support SEC_RO.*/
    ,S_SEC_RO_WRITE_LEN_INCONSISTENT = 1028     /*!<(1028) <B>[User's Issue]</B> A Tools warning that the size of SEC_RO file needed to write is inconsistent with the length described in the phone.*/
    ,S_ADDR_N_LEN_NOT_32BITS_ALIGNMENT = 1029   /*!<(1029) <B>[Internal Error]</B> */
    ,S_UART_CHKSUM_ERROR = 1030                 /*!<(1030) <B>[H/W Issue]</B> A Tool's warning that read-back SEC_RO or CUST_PARA and its checksum is mismatched with the checksum BROM DLL calculates after receiving through UART. Please check your UART cable is stable or not.*/
    ,S_SF_FLASH_BOOT = 1031                     /*!<(1031) */
    ,S_EMMC_FLASH_BOOT = 1032                   /*!<(1032) */
    ,S_NOR_FLASH_BOOT = 1033                    /*!<(1033) <B>[Internal State]</B> */
    ,S_NAND_FLASH_BOOT = 1034                   /*!<(1034) <B>[Internal State]</B> */
    ,S_UNSUPPORTED_VER_OF_EMI_INFO = 1035       /*!<(1035) <B>[MAUI S/W Issue]</B> A Tool's warning that MAUI binary file contains an unsupported version of EMI setting. Please ask for help.*/
    ,S_UNSUPPORTED_OPERATION = 1036             /*!<(1036) */
    ,S_COM_PORT_SEARCH_TIMEOUT = 1037           /*!<(1037) */
    ,S_SPI_NAND_FLASH_BOOT = 1038               /*!<(1038) <B>[Internal State]</B> SPI-NAND Flash Booting */
    ,S_FILE_IO_FAIL = 1039               /*!<(1039) <B>[Tool Issue]</B> An error occurs when the host-side file IO is failed */

    ,S_COMMON_ERROR_END // END

    // BOOT ROM error code (2000~2999)
    ,S_BROM_ERROR_BEGIN = 2000                  /*!<BOOT ROM error code (2000~2999) */
    ,S_BROM_SET_META_REG_FAIL = S_BROM_ERROR_BEGIN  /*!<(2000) <B>[DLL Issue]</B> */
    ,S_BROM_SET_FLASHTOOL_REG_FAIL = 2001       /*!<(2001) <B>[DLL Issue]</B> */
    ,S_BROM_SET_REMAP_REG_FAIL = 2002           /*!<(2002) <B>[DLL Issue]</B> */
    ,S_BROM_SET_EMI_FAIL = 2003                 /*!<(2003) <B>[DLL Issue]</B> */
    ,S_BROM_DOWNLOAD_DA_FAIL = 2004             /*!<(2004) <B>[H/W Issue]</B> A Tool's warning that BROM DLL fails to download DA. Please check your UART cable is stable or not.*/// Failed to download DA to target
    ,S_BROM_CMD_STARTCMD_FAIL = 2005            /*!<(2005) <B>[DLL Issue]</B> */// Failed to sync with target
    ,S_BROM_CMD_STARTCMD_TIMEOUT = 2006         /*!<(2006) <B>[DLL Issue]</B> */// Failed to sync with target
    ,S_BROM_CMD_JUMP_FAIL = 2007                /*!<(2007) <B>[DLL Issue]</B> */// Failed to jump to DA for execution
    ,S_BROM_CMD_GET_ME_ID_FAIL = 2008           /*!<(2008) <B>[DLL Issue]</B> */
    ,S_BROM_CMD_WRITE16_MEM_FAIL = 2009         /*!<(2009) <B>[DLL Issue]</B> */
    ,S_BROM_CMD_READ16_MEM_FAIL = 2010          /*!<(2010) */
    ,S_BROM_CMD_WRITE16_REG_FAIL = 2011         /*!<(2011) <B>[Obsolete Error]</B> */
    ,S_BROM_CMD_READ16_REG_FAIL = 2012          /*!<(2012) <B>[Obsolete Error]</B> */
    ,S_BROM_CMD_CHKSUM16_MEM_FAIL = 2013        /*!<(2013) <B>[DLL Issue]</B> */
    ,S_BROM_CMD_WRITE32_MEM_FAIL = 2014         /*!<(2014) <B>[DLL Issue]</B> */
    ,S_BROM_CMD_READ32_MEM_FAIL = 2015          /*!<(2015) <B>[DLL Issue]</B> */
    ,S_BROM_CMD_WRITE32_REG_FAIL = 2016         /*!<(2016) <B>[Obsolete Error]</B> */
    ,S_BROM_CMD_READ32_REG_FAIL = 2017          /*!<(2017) <B>[Obsolete Error]</B> */
    ,S_BROM_CMD_CHKSUM32_MEM_FAIL = 2018        /*!<(2018) <B>[DLL Issue]</B> */
    ,S_BROM_JUMP_TO_META_MODE_FAIL = 2019       /*!<(2019) <B>[DLL Issue]</B> */// Failed to enter META mode
    ,S_BROM_WR16_RD16_MEM_RESULT_DIFF = 2020    /*!<(2020) <B>[Obsolete Error]</B> */
    ,S_BROM_CHKSUM16_MEM_RESULT_DIFF = 2021     /*!<(2021) <B>[DLL Issue]</B> */
    ,S_BROM_BBCHIP_HW_VER_INCORRECT = 2022      /*!<(2022) <B>[DLL Issue]</B> */
    ,S_BROM_FAIL_TO_GET_BBCHIP_HW_VER = 2023    /*!<(2023) <B>[H/W Issue]</B> A Tool's warning that BROM DLL fails to get H/W version of baseband chip. Please ask for help.*/// Failed to get HW ver from target
    ,S_BROM_AUTOBAUD_FAIL = 2024                /*!<(2024) <B>[DLL Issue]</B> */
    ,S_BROM_SPEEDUP_BAUDRATE_FAIL = 2025        /*!<(2025) <B>[DLL Issue]</B> */
    ,S_BROM_LOCK_POWERKEY_FAIL = 2026           /*!<(2026) <B>[DLL Issue]</B> */
    ,S_BROM_WM_APP_MSG_OUT_OF_RANGE = 2027      /*!<(2027) <B>[Obsolete Error]</B> */
    ,S_BROM_NOT_SUPPORT_MT6205B = 2028          /*!<(2028) <B>[Obsolete Error]</B> */
    ,S_BROM_EXCEED_MAX_DATA_BLOCKS = 2029       /*!<(2029) <B>[MAUI S/W Issue]</B> A Tool's warning that the number of Multi-Bin files is more than 10. Please don't build more than 10 binary files.*/
    ,S_BROM_EXTERNAL_SRAM_DETECTION_FAIL = 2030 /*!<(2030) <B>[DLL Issue]</B> */
    ,S_BROM_EXTERNAL_DRAM_DETECTION_FAIL = 2031	/*!<(2031) <B>[DLL Issue]</B> */
    ,S_BROM_GET_FW_VER_FAIL = 2032              /*!<(2032) <B>[DLL Issue]</B> */
    ,S_BROM_CONNECT_TO_BOOTLOADER_FAIL = 2033   /*!<(2033) */
    ,S_BROM_CMD_JUMP_DA_FAIL = 2034             /*!<(2034) */
    ,S_BROM_CMD_JUMP_BL_FAIL = 2035             /*!<(2035) */
    ,S_BROM_DOWNLOAD_EPP_FAIL = 2036            /*!<(2036) */
    ,S_BROM_EFUSE_REG_NO_MATCH_WITH_TARGET = 2037   /*!<(2037) */
    ,S_BROM_EFUSE_WRITE_TIMEOUT = 2038          /*!<(2038) */
    ,S_BROM_EFUSE_DATA_PROCESS_ERROR = 2039     /*!<(2039) */
    ,S_BROM_EFUSE_BLOW_ERROR = 2040             /*!<(2040) */
    ,S_BROM_EFUSE_READBACK_DATA_NOT_THE_SAME = 2041  /*!<(2041) */
    ,S_BROM_EFUSE_VALUE_IS_NOT_ZERO          = 2042  /*!<(2042) */
    ,S_BROM_EFUSE_UNKNOW_EXCEPTION           = 2043  /*!<(2043) */
    ,S_BROM_EFUSE_READ_ERROR                 = 2044  /*!<(2044) */
    ,S_BROM_EFUSE_WRITE_TIMEOUT_WITHOUT_EFUSE_VERIFY = 2045 /*!<(2045) */
    ,S_BROM_EFUSE_UNKNOW_EXCEPTION_WITHOUT_EFUSE_VERIFY = 2046 /*!<(2046) */
    ,S_BROM_EFUSE_ROOT_CERT_ID_LENGTH_INVALID  = 2047 /*!<(2047) */
    ,S_BROM_ERROR_END // END

    // DA error code (3000~3999)
    ,S_DA_ERROR_BEGIN = 3000                    /*!<DA error code (3000~3999)*/
    ,S_DA_INT_RAM_ERROR = S_DA_ERROR_BEGIN      /*!<(3000) <B>[H/W Issue]</B> A Tool's warning that DA didn't detect internal RAM. It maybe a SMT issue. Please ask for help.*/// Failed to detect internal RAM
    ,S_DA_EXT_RAM_ERROR = 3001                  /*!<(3001) <B>[H/W Issue]</B> A Tool's warning that DA didn't detect external RAM. Please ask for help.*/// Failed to detect external RAM
    ,S_DA_SETUP_DRAM_FAIL = 3002                /*!<(3002) <B>[DA Issue]</B> */
    ,S_DA_SETUP_PLL_ERR = 3003                  /*!<(3003) <B>[DA Issue]</B> */
    ,S_DA_DRAM_NOT_SUPPORT = 3004               /*!<(3004) <B>[H/W Issue]</B> A Tool's warning that the handset doesn't support DRAM. Please ask for help.*/
    ,S_DA_RAM_FLOARTING = 3005                  /*!<(3005) <B>[H/W Issue]</B> A Tool's warning that DA detects that RAM is floating. It maybe a SMT issue. Please ask for help.*/
    ,S_DA_RAM_UNACCESSABLE = 3006               /*!<(3006) <B>[H/W Issue]</B> A Tool's warning that DA detects that RAM is un-accessable. It maybe a SMT issue. Please ask for help.*/
    ,S_DA_RAM_ERROR = 3007                      /*!<(3007) <B>[H/W Issue]</B> A Tool's warning that DA detects that RAM is un-accessable. It maybe a SMT issue. Please ask for help.*/
    ,S_DA_DEVICE_NOT_FOUND = 3008               /*!<(3008) <B>[H/W Issue]</B> A Tool's warning that DA didn't detect external SRAM or external DRAM on the phone. Please ask for help.*/
    ,S_DA_NOR_UNSUPPORTED_DEV_ID = 3009         /*!<(3009) <B>[User's Issue]</B> An error occurs when DA returns an unsupported device ID of NOR Flash. Please check DA and BROM DLL are on the same version.*/
    ,S_DA_NAND_UNSUPPORTED_DEV_ID = 3010        /*!<(3010) <B>[User's Issue]</B> An error occurs when DA returns an unsupported device ID of NAND Flash. Please check DA and BROM DLL are on the same version.*/
    ,S_DA_NOR_FLASH_NOT_FOUND = 3011            /*!<(3011) <B>[H/W Issue]</B> A Tool's warning that DA didn't detect external SRAM or external DRAM on the phone. Please ask for help.*/
    ,S_DA_NAND_FLASH_NOT_FOUND = 3012           /*!<(3012) <B>[H/W Issue]</B> A Tool's warning that DA didn't detect NAND Flash. Please ask for help.*/
    ,S_DA_SOC_CHECK_FAIL = 3013                 /*!<(3013) <B>[User's Issue]</B> An error occurs when DA fails to check SOC. Please check the customization function SOC.*/
    ,S_DA_NOR_PROGRAM_FAILED = 3014             /*!<(3014) <B>[H/W Issue]</B> A Tool's warning that DA fails to program NOR Flash. It maybe a SMT issue. Please ask for help.*/
    ,S_DA_NOR_ERASE_FAILED = 3015               /*!<(3015) <B>[H/W Issue]</B> A Tool's warning that DA fails to erase NOR Flash. It maybe a SMT issue. Please ask for help.*/
    ,S_DA_NAND_PAGE_PROGRAM_FAILED = 3016       /*!<(3016) <B>[H/W Issue]</B> A Tool's warning that DA fails to page-program NANR Flash.*/
    ,S_DA_NAND_SPARE_PROGRAM_FAILED = 3017      /*!<(3017) <B>[H/W Issue]</B> A Tool's warning that when DA fails to spare-program NAND Flash.*/
    ,S_DA_NAND_HW_COPYBACK_FAILED = 3018        /*!<(3018) <B>[H/W Issue]</B> A Tool's warning that DA fails to copy-back NAND Flash.*/
    ,S_DA_NAND_ERASE_FAILED = 3019              /*!<(3019) <B>[H/W Issue]</B> A Tool's warning that DA fails to erase NAND Flash.*/
    ,S_DA_TIMEOUT = 3020                        /*!<(3020) <B>[DA Issue]</B> */// Operation timeout (general error)
    ,S_DA_IN_PROGRESS = 3021                    /*!<(3021) <B>[Internal State]</B> */
    ,S_DA_SUPERAND_ONLY_SUPPORT_PAGE_READ = 3022/*!<(3022) <B>[DA Issue]</B> */
    ,S_DA_SUPERAND_PAGE_READ_NOT_SUPPORT = 3023 /*!<(3023) <B>[DA Issue]</B> */
    ,S_DA_SUPERAND_PAGE_PRGRAM_NOT_SUPPORT = 3024   /*!<(3024) <B>[DA Issue]</B> */
    ,S_DA_SUPERAND_SPARE_PRGRAM_NOT_SUPPORT = 3025  /*!<(3025) <B>[DA Issue]</B> */
    ,S_DA_SUPERAND_SPARE_READ_NOT_SUPPORT = 3026/*!<(3026) <B>[DA Issue]</B> */
    ,S_DA_SUPERAND_PAGE_SPARE_PRGRAM_NOT_SUPPORT = 3027 /*!<(3027) <B>[DA Issue]</B> */
    ,S_DA_SUPERAND_COPYBACK_NOT_SUPPORT = 3028  /*!<(3028) <B>[DA Issue]</B> */
    ,S_DA_NOR_CMD_SEQUENCE_ERR = 3029           /*!<(3029) <B>[DA Issue]</B> */
    ,S_DA_NOR_BLOCK_IS_LOCKED = 3030            /*!<(3030) <B>[DA Issue]</B> */
    ,S_DA_NAND_BLOCK_IS_LOCKED = 3031           /*!<(3031) <B>[DA Issue]</B> */
    ,S_DA_NAND_BLOCK_DATA_UNSTABLE = 3032       /*!<(3032) <B>[H/W Issue]</B> A Tool's warning that data of the block is unstable after erasing NAND Flash. Please ask for help.*/
    ,S_DA_NOR_BLOCK_DATA_UNSTABLE = 3033        /*!<(3033) <B>[H/W Issue]</B> A Tool's warning that might be \n
                                                    1. Data of the block is unstable after erasing or programming NOR Flash.
                                                    2. For memory test, If more than two same MCP has the error message in the same address, it might be the memory layout of setting incorrect in flash_dev_tbl.c.
                                                    Please ask for help.*/
    ,S_DA_NOR_VPP_RANGE_ERR = 3034              /*!<(3034) <B>[H/W Issue]</B> A Tool's warning that Vpp is out of working range for NOR Flash. Please ask for help.*/
    ,S_DA_INVALID_BEGIN_ADDR = 3035             /*!<(3035) <B>[Internal Error]</B> */
    ,S_DA_NOR_INVALID_ERASE_BEGIN_ADDR = 3036   /*!<(3036) <B>[User's Issue]</B> A Tool's warning that an invalid begging address is given for erase operation on NOR Flash. Please check your erase address again.*/
    ,S_DA_NOR_INVALID_READ_BEGIN_ADDR = 3037    /*!<(3037) <B>[User's Issue]</B> A Tool's warning that an invalid begging address is given for read operation on NOR Flash. Please check your read address again.*/
    ,S_DA_NOR_INVALID_PROGRAM_BEGIN_ADDR = 3038 /*!<(3038) <B>[User's Issue]</B> A Tool's warning that an invalid begging address is given for program operation on NOR Flash. Please check your program address again.*/
    ,S_DA_INVALID_RANGE = 3039                  /*!<(3039) <B>[User's Issue]</B> A Tool's warning that invalid begging and end addresses are given for program operation on NOR Flash. Please check your MAUI address and length again.*/
    ,S_DA_NOR_PROGRAM_AT_ODD_ADDR = 3040        /*!<(3040) <B>[User's Issue]</B> A Tool's warning that an odd begging address is given for downloading MAUI on NOR Flash. Please check your program address again.*/
    ,S_DA_NOR_PROGRAM_WITH_ODD_LENGTH = 3041    /*!<(3041) <B>[User's Issue]</B> A Tool's warning that an odd length of MAUI Rom file is given for downloading MAUI on NOR Flash. Please check your program length again.*/
    ,S_DA_NOR_BUFPGM_NO_SUPPORT = 3042          /*!<(3042) <B>[Internal Error]</B> */
    ,S_DA_NAND_UNKNOWN_ERR = 3043               /*!<(3043) <B>[Internal State]</B> */
    ,S_DA_NAND_BAD_BLOCK = 3044                 /*!<(3044) <B>[Internal Error]</B> */
    ,S_DA_NAND_ECC_1BIT_CORRECT = 3045          /*!<(3045) <B>[Internal Error]</B> */
    ,S_DA_NAND_ECC_2BITS_ERR = 3046             /*!<(3046) <B>[Internal Error]</B> */
    ,S_DA_NAND_ECC_UNCORRECTABLE_ERROR = 3047   /*!<(3047) <B>[Internal Error]</B> */
    ,S_DA_NAND_SPARE_CHKSUM_ERR = 3048          /*!<(3048) <B>[Internal Error]</B> */
    ,S_DA_NAND_HW_COPYBACK_DATA_INCONSISTENT = 3049 /*!<(3049) <B>[Internal Error]</B> */
    ,S_DA_NAND_INVALID_PAGE_INDEX = 3050        /*!<(3050) <B>[Internal Error]</B> */
    ,S_DA_NFI_NOT_SUPPORT = 3051                /*!<(3051) <B>[Internal State]</B> */
    ,S_DA_NFI_CS1_NOT_SUPPORT = 3052            /*!<(3052) <B>[Internal State]</B> */
    ,S_DA_NFI_16BITS_IO_NOT_SUPPORT = 3053      /*!<(3053) <B>[Internal State]</B> */
    ,S_DA_NFB_BOOTLOADER_NOT_EXIST = 3054       /*!<(3054) <B>[H/W Issue]</B> A Tool's warning that there doesn't exist Boot Loader Image on NAND Flash before NFB downloading. Please ask for help.*/
    ,S_DA_NAND_NO_GOOD_BLOCK = 3055             /*!<(3055) <B>[H/W Issue]</B> A Tool's warning that there doesn't exist any good block on NAND Flash.*/
    ,S_DA_BOOTLOADER_IS_TOO_LARGE = 3056        /*!<(3056) <B>[MAUI S/W Issue]</B> A Tool's warning that Boot Loader Image is more than 7 blocks on NAND Flash. Please ask for help.*/
    ,S_DA_SIBLEY_REWRITE_OBJ_MODE_REGION = 3057 /*!<(3057) <B>[Internal State]</B> */
    ,S_DA_SIBLEY_WRITE_B_HALF_IN_CTRL_MODE_REGION = 3058    /*!<(3058) <B>[Internal State]</B> */
    ,S_DA_SIBLEY_ILLEGAL_CMD = 3059             /*!<(3059) <B>[Internal State]</B> */
    ,S_DA_SIBLEY_PROGRAM_AT_THE_SAME_REGIONS = 3060 /*!<(3060) <B>[Internal State]</B> */
    ,S_DA_UART_GET_DATA_TIMEOUT = 3061          /*!<(3061) <B>[Obsolete Error]</B> */
    ,S_DA_UART_GET_CHKSUM_LSB_TIMEOUT = 3062    /*!<(3062) <B>[Obsolete Error]</B> */
    ,S_DA_UART_GET_CHKSUM_MSB_TIMEOUT = 3063    /*!<(3063) <B>[Obsolete Error]</B> */
    ,S_DA_UART_DATA_CKSUM_ERROR = 3064          /*!<(3064) <B>[Obsolete Error]</B> */
    ,S_DA_UART_RX_BUF_FULL = 3065               /*!<(3065) <B>[DA Issue]</B> */
    ,S_DA_FLASH_RECOVERY_BUF_NOT_ENOUGH = 3066  /*!<(3066) <B>[DA Issue]</B> */
    ,S_DA_HANDSET_SEC_INFO_NOT_FOUND = 3067     /*!<(3067) <B>[Internal State]</B> */
    ,S_DA_HANDSET_SEC_INFO_MAC_VERIFY_FAIL = 3068   /*!<(3068) <B>[Internal Error]</B> */
    ,S_DA_HANDSET_ROM_INFO_NOT_FOUND = 3069     /*!<(3069) <B>[Internal State]</B> */
    ,S_DA_HANDSET_FAT_INFO_NOT_FOUND = 3070     /*!<(3070) <B>[Internal State]</B> */
    ,S_DA_OPERATION_UNSUPPORT_FOR_NFB = 3071    /*!<(3071) <B>[Internal Error]</B> */
    ,S_DA_BYPASS_POST_PROCESS = 3072            /*!<(3072) <B>[Internal State]</B> */
    ,S_DA_NOR_OTP_NOT_SUPPORT = 3073            /*!<(3073) <B>[Internal State]</B> */
    ,S_DA_NOR_OTP_EXIST = 3074                  /*!<(3074) <B>[Internal State]</B> */
    ,S_DA_NOR_OTP_LOCKED = 3075                 /*!<(3075) <B>[Internal State]</B> */
    ,S_DA_NOR_OTP_GETSIZE_FAIL = 3076           /*!<(3076) <B>[DLL Issue]</B> */
    ,S_DA_NOR_OTP_READ_FAIL = 3077              /*!<(3077) <B>[DLL Issue]</B> */
    ,S_DA_NOR_OTP_PROGRAM_FAIL = 3078           /*!<(3078) <B>[DLL Issue]</B> */
    ,S_DA_NOR_OTP_LOCK_FAIL = 3079              /*!<(3079) <B>[DLL Issue]</B> */
    ,S_DA_NOR_OTP_LOCK_CHECK_STATUS_FAIL = 3080 /*!<(3080) <B>[DLL Issue]</B> */
    ,S_DA_BLANK_FLASH = 3081                    /*!<(3081) <B>[User's Issue]</B> A Tool's warning that there doesn't exist MAUI code and SEC_RO (option) on the flash. Please choose MAUI file and SEC_RO file (option) for downloading.*/
    ,S_DA_CODE_AREA_IS_BLANK = 3082             /*!<(3082) <B>[User's Issue]</B> A Tool's warning that there doesn't exist MAUI code on the flash. Please choose MAUI file for downloading.*/
    ,S_DA_SEC_RO_AREA_IS_BLANK = 3083           /*!<(3083) <B>[User's Issue]</B> A Tool's warning that there doesn't exist SEC_RO on the flash. Please choose SEC_RO file for downloading.*/
    ,S_DA_NOR_OTP_UNLOCKED = 3084               /*!<(3084) <B>[Internal State]</B> */
    ,S_DA_UNSUPPORTED_BBCHIP = 3085             /*!<(3085) <B>[User's Issue]</B> A Tool's warning that BROM DLL is too old to support this baseband chip on the phone. Please update your Tool.*/
    ,S_DA_FAT_NOT_EXIST = 3086                  /*!<(3086) <B>[User's Issue]</B> A Tool's warning that FAT doesn't exist on the phone.*/
    ,S_DA_EXT_SRAM_NOT_FOUND = 3087             /*!<(3087) <B>[H/W Issue]</B> A Tool's warning that DA didn't detect external SRAM on the phone. Please ask for help.*/
    ,S_DA_EXT_DRAM_NOT_FOUND = 3088             /*!<(3088) <B>[H/W Issue]</B> A Tool's warning that DA didn't detect external DRAM on the phone. Please ask for help.*/
    ,S_DA_MT_PIN_LOW = 3089                     /*!<(3089) <B>[H/W Issue]</B> A Tool's warning that DA detects that a pin is always low on the phone while memory test. Please ask for help.*/
    ,S_DA_MT_PIN_HIGH = 3090                    /*!<(3090) <B>[H/W Issue]</B> A Tool's warning that DA detects that a pin is always high on the phone while memory test. Please ask for help.*/
    ,S_DA_MT_PIN_SHORT = 3091                   /*!<(3091) <B>[H/W Issue]</B> A Tool's warning that DA detects that two pins are short on the phone while memory test. Please ask for help.*/
    ,S_DA_MT_BUS_ERROR = 3092                   /*!<(3092) <B>[H/W Issue]</B> A Tool's warning that DA detects bus error on the phone while memory test. Please ask for help.*/
    ,S_DA_MT_ADDR_NOT_2BYTE_ALIGNMENT = 3093    /*!<(3093) <B>[User's Issue]</B> A Tool's warning that input address is not 2-Byte aligned while memory test. Please ask for help.*/
    ,S_DA_MT_ADDR_NOT_4BYTE_ALIGNMENT = 3094    /*!<(3094) <B>[User's Issue]</B> A Tool's warning that input address is not 4-Byte aligned while memory test. Please ask for help.*/
    ,S_DA_MT_SIZE_NOT_2BYTE_ALIGNMENT = 3095    /*!<(3095) <B>[User's Issue]</B> A Tool's warning that input size is not 2-Byte aligned while memory test. Please ask for help.*/
    ,S_DA_MT_SIZE_NOT_4BYTE_ALIGNMENT = 3096    /*!<(3096) <B>[User's Issue]</B> A Tool's warning that input size is not 4-Byte aligned while memory test. Please ask for help.*/
    ,S_DA_MT_DEDICATED_PATTERN_ERROR = 3097     /*!<(3097) <B>[H/W Issue]</B> A Tool's warning that DA detects error on the phone while memory test with dedicated pattern. Please ask for help.*/
    ,S_DA_MT_INC_PATTERN_ERROR = 3098           /*!<(3098) <B>[H/W Issue]</B> A Tool's warning that DA detects error on the phone while memory test with incremental pattern. Please ask for help.*/
    ,S_DA_MT_DEC_PATTERN_ERROR = 3099           /*!<(3099) <B>[H/W Issue]</B> A Tool's warning that DA detects error on the phone while memory test with decremental pattern. Please ask for help.*/
    ,S_DA_NFB_BLOCK_0_IS_BAD = 3100             /*!<(3100) <B>[H/W Issue]</B> A Tool's warning that DA detects Block 0 of NAND Flash is bad. Please ask for help.*/
    ,S_DA_CUST_PARA_AREA_IS_BLANK = 3101        /*!<(3101) <B>[User's Issue]</B> A Tool's warning that DA detects custom parameter is blank. Please check whether phone has custom parameter or not.*/
    ,S_DA_ENTER_RELAY_MODE_FAIL = 3102          /*!<(3102) <B>[DLL Issue]</B> */
    ,S_DA_ENTER_RELAY_MODE_IS_FORBIDDEN_AFTER_META = 3103   /*!<(3103) <B>[User's Issue]</B> A Tool's warning that you cannot enter DA Relay Mode after enter META mode. */
    ,S_DA_NAND_PAGE_READ_FAILED = 3104          /*!<(3104) <B>[H/W Issue]</B> A Tool's warning that DA operates Page Read command but fails. Please ask for help.*/
    ,S_DA_NAND_IMAGE_BLOCK_NO_EXIST = 3105      /*!<(3105) <B>[Internal Error]</B> */
    ,S_DA_NAND_IMAGE_LIST_NOT_EXIST = 3106      /*!<(3106) <B>[Internal Error]</B> */
    ,S_DA_MBA_RESOURCE_NO_EXIST_IN_TARGET = 3107/*!<(3107) <B>[User's Issue]</B> A Tool's warning that you cannot update partial resource files because there's no MBA feature in the target. */
    ,S_DA_MBA_PROJECT_VERSION_NO_MATCH_WITH_TARGET = 3108   /*!<(3108) <B>[User's Issue]</B> A Tool's warning that you cannot update any resource file because the project version is different with the target. */
    ,S_DA_MBA_UPDATING_RESOURCE_NO_EXIST_IN_TARGET = 3109   /*!<(3109) <B>[User's Issue]</B> A Tool's warning that you cannot update some specific resource files because there doesn't exit this resource file in current target.. */
    ,S_DA_MBA_UPDATING_RESOURCE_SIZE_EXCEED_IN_TARGET = 3110    /*!<(3110) <B>[User's Issue]</B> A Tool's warning that you cannot update some specific resource files because their size exceeds the reserved space in the target.*/
    ,S_DA_NAND_BIN_SIZE_EXCEED_MAX_SIZE = 3111  /*!<(3111) <B>[User's Issue]</B> A Tool's warning that you cannot update some specific binary files because their size exceeds the reserved space in the target. */
    ,S_DA_NAND_EXCEED_CONTAINER_LIMIT = 3112    /*!<(3112) */
    ,S_DA_NAND_REACH_END_OF_FLASH = 3113        /*!<(3113) */
    ,S_DA_NAND_OTP_NOT_SUPPORT = 3114           /*!<(3114) */
    ,S_DA_NAND_OTP_EXIST = 3115                 /*!<(3115) */
    ,S_DA_NAND_OTP_LOCKED = 3116                /*!<(3116) */
    ,S_DA_NAND_OTP_LOCK_FAIL = 3117             /*!<(3117) */
    ,S_DA_NAND_OTP_UNLOCKED = 3118              /*!<(3118) */
    ,S_DA_OTP_NOT_SUPPORT = 3119                /*!<(3119) */
    ,S_DA_OTP_EXIST = 3120                      /*!<(3120) */
    ,S_DA_OTP_LOCKED = 3121                     /*!<(3121) */
    ,S_DA_OTP_GETSIZE_FAIL = 3122               /*!<(3122) */
    ,S_DA_OTP_READ_FAIL = 3123                  /*!<(3123) */
    ,S_DA_OTP_PROGRAM_FAIL = 3124               /*!<(3124) */
    ,S_DA_OTP_LOCK_FAIL = 3125                  /*!<(3125) */
    ,S_DA_OTP_LOCK_CHECK_STATUS_FAIL = 3126     /*!<(3126) */
    ,S_DA_OTP_UNLOCKED = 3127                   /*!<(3127) */
    ,S_DA_SEC_RO_ILLEGAL_MAGIC_TAIL = 3128      /*!<(3128) */
    ,S_DA_HANDSET_FOTA_INFO_NOT_FOUND = 3129    /*!<(3129) */
    ,S_DA_HANDSET_UA_INFO_NOT_FOUND = 3130      /*!<(3130) */
    ,S_DA_SB_FSM_INVALID_INFO = 3131            /*!<(3131) */
    ,S_DA_NFB_TARGET_DUAL_BL_PAIRED_VERSION_NOT_MATCHED_WITH_MAUI = 3132    /*!<(3132) */
    ,S_DA_NFB_TARGET_DUAL_BL_FEATURE_COMBINATION_NOT_MATCHED_WITH_MAUI = 3133 /*!<(3133) */
    ,S_DA_NFB_TARGET_IS_SINGLE_BL_BUT_PC_NOT = 3134 /*!<(3134) */
    ,S_DA_NFB_TARGET_IS_DUAL_BL_BUT_PC_NOT = 3135    /*!<(3135) */
    ,S_DA_NOR_TARGET_BL_PAIRED_VERSION_NOT_MATCHED_WITH_MAUI = 3136 /*!<(3136) */
    ,S_DA_NOR_TARGET_BL_FEATURE_COMBINATION_NOT_MATCHED_WITH_MAUI = 3137    /*!<(3137) */
    ,S_DA_NOR_TARGET_IS_NOT_NEW_BL_BUT_PC_IS = 3138 /*!<(3138) */
    ,S_DA_NOR_TARGET_IS_NEW_BL_BUT_PC_NOT = 3139    /*!<(3139) */
    ,S_DA_GEN_DA_VERSION_INFO_TEMP_ILB_FAIL = 3140  /*!<(3140) */
    ,S_DA_FLASH_NOT_FOUND = 3141                /*!<(3141) */
    ,S_DA_BOOT_CERT_NOT_EXIST = 3142            /*!<(3142) */
    ,S_DA_NAND_CODE_IMAGE_OVERLAP_FAT_REGION = 3143 /*!<(3143) */
// MT6276 SV5 Bootloader
    ,S_DA_DOWNLOAD_BOOTLOADER_FLASH_DEV_IS_NONE = 3144  /*!<(3144) */
    ,S_DA_DOWNLOAD_BOOTLOADER_FLASH_DEV_IS_NOT_SUPPORTED = 3145 /*!<(3145) */
    ,S_DA_DOWNLOAD_BOOTLOADER_BEGIN_ADDR_OVERLAPS_WITH_PREVIOUS_BOUNDARY = 3146 /*!<(3146) */
    ,S_DA_UPDATE_BOOTLOADER_EXIST_MAGIC_NOT_MATCHED = 3147  /*!<(3147) */
    ,S_DA_UPDATE_BOOTLOADER_FILE_TYPE_NOT_MATCHED = 3148    /*!<(3148) */
    ,S_DA_UPDATE_BOOTLOADER_FILE_SIZE_EXCEEDS_BOUNDARY_ADDR = 3149  /*!<(3149) */
    ,S_DA_UPDATE_BOOTLOADER_BEGIN_ADDR_NOT_MATCHED = 3150   /*!<(3150) */
    // SV5 CBR
    ,S_DA_CBR_SET_BUF_AND_API_FAIL = 3151       /*!<(3151) */
    ,S_DA_CBR_NOT_FOUND = 3152                  /*!<(3152) */
    ,S_DA_CBR_FLASH_LAYOUT_NOT_FOUND = 3153     /*!<(3153) */
    ,S_DA_CBR_FLASH_SPACE_INFO_NOT_FOUND = 3154 /*!<(3154) */
    ,S_DA_CBR_FLASH_CONFIG_NOT_FOUND = 3155     /*!<(3155) */
    ,S_DA_CBR_SET_ENVRIONMENT_FAILED = 3156     /*!<(3156) */
    ,S_DA_CBR_CREAT_FAILED = 3157               /*!<(3157) */
    ,S_DA_CBR_COMPARE_FAILED = 3158             /*!<(3158) */
    ,S_DA_CBR_WRONG_VERSION = 3159              /*!<(3159) */
    ,S_DA_CBR_ALREADY_EXIST = 3160              /*!<(3160) */
    ,S_DA_CBR_RECORD_BUF_TOO_SMALL = 3161       /*!<(3161) */
    ,S_DA_CBR_RECORD_NOT_EXIST = 3162           /*!<(3162) */
    ,S_DA_CBR_RECORD_ALREADY_EXIST = 3163       /*!<(3163) */
    ,S_DA_CBR_FULL = 3164                       /*!<(3164) */
    ,S_DA_CBR_RECORD_WRITE_LEN_INCONSISTENT = 3165  /*!<(3165) */
    ,S_DA_CBR_VERSION_NOT_MATCHED = 3166        /*!<(3166) */
    ,S_DA_CBR_NOT_SUPPORT_PCT_FLASH = 3167      /*!<(3167) */
    ,S_DA_CBR_UNKNOWN_ERROR = 3168              /*!<(3168) */
    // SV5 SEC_RO
    ,S_DA_SEC_RO_ACC_PARSE_ERROR = 3169         /*!<(3169) */
    // SV5 Security preprocess
    ,S_DA_HEADER_BLOCK_NOT_EXIST = 3170         /*!<(3170) */
    ,S_DA_S_PRE_PARSE_CUSTOMER_NAME_FAIL = 3171 /*!<(3171) */
    ,S_DA_S_RETRIEVE_SEC_RO_FAIL_IN_SECURE_INIT = 3172  /*!<(3172) */
    ,S_DA_S_FLASH_INFO_NOT_EXIST = 3173         /*!<(3173) */
    ,S_DA_S_MAUI_INFO_NOT_EXIST = 3174          /*!<(3174) */
    ,S_DA_S_BOOTLOADER_SHARE_DATA_NOT_EXIST = 3175  /*!<(3175) */
    // GFH
    ,S_DA_GFH_FILE_INFO_RETREIVAL_FAIL = 3176   /*!<(3176) */
    ,S_DA_NAND_REMARK_FAIL = 3177               /*!<(3177) */
    ,S_DA_TARGET_IS_NOT_NEW_BL_BUT_PC_IS = 3178 /*!<(3178) */
    //eMMC
    ,S_DA_EMMC_FLASH_NOT_FOUND  = 3179 /*!<(3179) */
    ,S_DA_EMMC_ENABLE_BOOT_FAILED  = 3180 /*!<(3180) */
    ,S_DA_HB_FOUND_IN_OTHER_FLASH_DEV  = 3181 /*!<(3181) found HB in target's flash dev, but try to download on different flash dev*/
    ,S_DA_USB_2_0_NOT_SUPPORT = 3182 /*!<(3182) */
    ,S_DA_CBR_INIT_FAILED = 3183 /*!<(3183) */
    ,S_DA_CBR_MAUI_INFO_SIZE_TOO_BIG = 3184 /*!<(3184) */
    ,S_DA_CBR_WRITE_MAUI_INFO_FAILED = 3185 /*!<(3185) */
    ,S_DA_CBR_READ_MAUI_INFO_FAILED = 3186 /*!<(3186) */
    ,S_DA_UNSUPPORTED_OPERATION = 3187     /*!<(3187) the operation is not suppported*/
    ,S_DA_MBA_RESOURCE_BIN_NUMBER_NOT_MATCH_WITH_TARGET = 3188    /*!<(3188) */
    ,S_DA_MBA_HEADER_NOT_EXIST = 3189      /*!<(3189) */
    ,S_DA_MBA_RESOURCE_VERSION_NO_MATCH_WITH_TARGET = 3190    /*!<(3190) */
    ,S_DA_BOOTLOADER_SELF_UPDATE_FAIL = 3191    /*!<(3191) */
    ,S_DA_SEARCH_BL_SELF_UPDATE_INFO_FAIL = 3192       /*!<(3192) */
    ,S_DA_SPACE_NOT_ENOUGH_FOR_EXT_BL_MARKER = 3193    /*!<(3193) */
    ,S_DA_FIND_EXT_BL_MARKER_FAIL = 3194        /*!<(3194) */
    ,S_DA_TOO_MANY_BAD_BLOCKS_FOR_EXT_BL_MARKER = 3195 /*!<(3195) */
    ,S_DA_TOO_MANY_BAD_BLOCKS_FOR_EXT_BL_BACKUP = 3196 /*!<(3196) */
    ,S_DA_EXT_BL_VER_MISMATCHED = 3197    /*!<(3197) */
    ,S_DA_EXT_BL_VER_NOT_FOUND = 3198     /*!<(3198) */
    ,S_DA_BL_SELF_UPDATE_FEATURE_CHECK_FAILED = 3199   /*!<(3199) */
    ,S_DA_BL_ROM_INFO_NOT_FOUND = 3200    /*!<(3200) */
    ,S_DA_EXT_BL_MAX_SIZE_MISMATCHED = 3201 /*!<(3201) */
    ,S_DA_INVALID_PARAMETER_FROM_PC = 3202 /*!<(3202) */
    ,S_DA_BL_SELF_UPDATE_NOT_SUPPORTED = 3203 /*!<(3203) */
    ,S_DA_EXT_BL_HDR_NOT_FOUND  = 3204 /*!<(3204) */
    ,S_DA_S_FLASH_LAYOUT_NOT_EXIST  = 3205 /*!<(3205) */
    ,S_DA_S_FLASH_ID_NOT_EXIST      = 3206 /*!<(3206) */
    ,S_DA_MAUI_GFH_FLASH_ID_NOT_MATCH_WITH_TARGET  = 3207 /*!<(3207) */
    ,S_DA_FLASH_ERASE_SIZE_NOT_SUPPORT = 3208
    ,S_DA_SRD_NOT_FOUND = 3209 /*!<(3209) The SRD struct could not be found, possible worn-out error on the block*/
    ,S_DA_SRD_UPDATE_FAILED = 3210 /*!<(3210) The SRD struct re-write op is failed due to bad-block (re-download is needed) */
    ,S_DA_NAND_DATA_ADDR_NOT_PAGE_ALIGNMENT = 3211  /*!<(3211) */
    ,S_DA_BL_GFH_BROM_SEC_CFG_NOT_FOUND = 3212      /*!<(3212) The GFH_BROM_SEC_CFG is not found in ARM_BL */
    ,S_DA_BL_CUSTOMER_NAME_BUFFER_INSUFFICIENT = 3213   /*!<(3213) The supplied buffer fro customer name is insufficient */
    ,S_DA_COM_BUSY          = 3214  /*!<(3214) */
    ,S_DA_INITIAL_BMT_FAILED_CAUSED_FROM_POOL_SIZE_ERROR = 3215 /*!<(3215) */
    ,S_DA_LOAD_ORIGINAL_BMT_FAILED = 3216 /*!<(3216) */
    ,S_DA_INVALID_NAND_PAGE_BUFFER = 3217 /*!<(3217) the location of the page buffer is invalid */
    ,S_DA_DL_BOOT_REGION_IS_OVERLAP_CONTROL_BLOCK_REGION = 3218 /*!<(3218) */
    ,S_DA_PRE_DL_HB_INIT_FAIL = 3219/*!<(3219) The pre pare download, init header block fail */
    ,S_DA_POST_DL_HB_WRITE_FAIL = 3220/*!<(3220) The pre pare download, init header block fail */
    ,S_DA_LOAD_IMG_PARA_FAIL = 3221/*!<(3221) load imageParameter from flash fail */
    ,S_DA_WRITE_IMG_PARA_FAIL = 3222/*!<(3222) writeback imageParameter to flash fail */
    ,S_DA_UPDATE_HB_FAIL = 3223/*!<(3223) update headerblock fail */
    ,S_DA_BIN_SIZE_EXCEED_MAX_ERR = 3224/*!<(3224) DA check download bin size limit fail */
    ,S_DA_PARTIAL_BIN_TYPE_ERR = 3225/*!<(3225) DA partial download bin type check error */
    ,S_DA_IMAGE_PARA_QUERY_ERR = 3226/*!<(3226) Query specific bin's address from image parameter fail error */
    ,S_DA_IMAGE_PARA_UPDATE_ERR = 3227/*!<(3227) Update ImageParameter in memory fail */
    ,S_DA_FLASH_LAYOUT_BIN_NOT_FOUND = 3228/*!<(3228) Can not found the specific bin type in FlashLayout */
    ,S_DA_FLASH_LAYOUT_GET_ELEMENT_FAIL = 3229/*!<(3229) Get a element from FlashLayout  fail*/
    ,S_DA_FLASH_LAYOUT_ADD_ELEMENT_FAIL = 3230/*!<(3230) Add a element to FlashLayout  fail*/
    ,S_DA_CBR_FOUND_BUT_MAUI_NOT_EXIST = 3231/*!<(3231) DA detect target has CBR data, but it has no MAUI. It's abnormal target status*/
    ,S_DA_UPDATE_BOOTLOADER_NOT_CONTAIN_CRITICAL_DATA = 3232/*!<(3232) New ARM_BL doesn't have critical data inside that make download fail.*/
    ,S_DA_DUMP_FLASH_LAYOUT_FAIL = 3233/*!<(3233) Can not get the FlashLayout information from target*/
    ,S_DA_BMT_NO_INIT = 3234/*!<(3234) DA doesn't do any BMT init operation*/
    ,S_DA_NOR_PROGRAM_REGION_IS_OVERLAP  = 3235  /*!<(3235) */
    ,S_DA_ERROR_END // END

    // FlashTool error code (4000~4999)
    ,S_FT_ERROR_BEGIN = 4000                    /*!<FlashTool error code (4000~4999) */
    ,S_FT_CALLBACK_DA_REPORT_FAIL = S_FT_ERROR_BEGIN    /*!<(4000) <B>[Tool Issue]</B> An error occurs when CALLBACK_DA_REPORT callback function returns fail. Please check your callback function.*/
    ,S_FT_DA_NO_RESPONSE = 4001                 /*!<(4001) <B>[DA Issue]</B> No response from DA (general error). */
    ,S_FT_DA_SYNC_INCORRECT = 4002              /*!<(4002) <B>[User's Issue]</B> A Tool's warning that BROM DLL fails to synchronize with DA. Please check DA is "MTK_AllInOne_DA.bin".*/
    ,S_FT_DA_VERSION_INCORRECT = 4003           /*!<(4003) <B>[User's Issue]</B> A Tool's warning that DA and BROM DLL have the different major and minor version. Please check they are the same version.*/
    ,S_FT_DA_INIT_SYNC_ERROR = 4004             /*!<(4004) <B>[DLL Issue]</B> Cannot sync with DA in the initial stage*/// Cannot sync with DA in the initial stage
    ,S_FT_GET_DSP_VER_FAIL = 4005               /*!<(4005) <B>[DLL Issue]</B> */
    ,S_FT_CHANGE_BAUDRATE_FAIL = 4006           /*!<(4006) <B>[DLL Issue]</B> Failed to change baudrate*/// Failed to change baudrate
    ,S_FT_SET_DOWNLOAD_BLOCK_FAIL = 4007        /*!<(4007) <B>[DLL Issue]</B> */
    ,S_FT_DOWNLOAD_FAIL = 4008                  /*!<(4008) <B>[DLL Issue]</B> Failed to complete download operation (general error)*/
    ,S_FT_DOWNLOAD_CHKSUM_MISMATCH = 4009       /*!<(4009) */// Checksum of the downloaded image is incorrect
    ,S_FT_READBACK_FAIL = 4010                  /*!<(4010) <B>[DLL Issue]</B> Failed to complete readback operation (general error)*/
    ,S_FT_FORMAT_FAIL = 4011                    /*!<(4011) <B>[DLL Issue]</B> Failed to complete format operation (general error)*/
    ,S_FT_FINISH_CMD_FAIL = 4012                /*!<(4012) <B>[DLL Issue]</B> Failed to disconnect with DA*/
    ,S_FT_ENABLE_WATCHDOG_FAIL = 4013           /*!<(4013) <B>[DLL Issue]</B> Failed to enable watchdog timer*/
    ,S_FT_NFB_DOWNLOAD_BOOTLOADER_FAIL = 4014   /*!<(4014) <B>[DLL Issue]</B> */
    ,S_FT_NFB_DOWNLOAD_CODE_FAIL = 4015         /*!<(4015) <B>[DLL Issue]</B> */
    ,S_FT_NFB_INVALID_BOOTLOADER_DRAM_SETTING = 4016    /*!<(4016) <B>[DLL Issue]</B> */
    ,S_FT_NAND_READADDR_NOT_PAGE_ALIGNMENT = 4017   /*!<(4017) <B>[User's Issue]</B> A Tool's warning that the begging address of read-back operation is not page-aligned on NAND Flash. Please check your read address again.*/
    ,S_FT_NAND_READLEN_NOT_PAGE_ALIGNMENT = 4018    /*!<(4018) <B>[User's Issue]</B> A Tool's warning that the length of read-back operation is not page-aligned on NAND Flash. Please check your read length again.*/
    ,S_FT_READ_REG16_FAIL = 4019                /*!<(4019) <B>[DLL Issue]</B> */
    ,S_FT_WRITE_REG16_FAIL = 4020               /*!<(4020) <B>[DLL Issue]</B> */
    ,S_FT_CUST_PARA_GET_INFO_FAIL = 4021        /*!<(4021) <B>[DLL Issue]</B> */
    ,S_FT_CUST_PARA_READ_FAIL = 4022            /*!<(4022) <B>[DLL Issue]</B> */
    ,S_FT_CUST_PARA_WRITE_FAIL = 4023           /*!<(4023) <B>[DLL Issue]</B> */
    ,S_FT_INVALID_FTCFG_OPERATION = 4024        /*!<(4024) <B>[Tool Issue]</B> An error occurs when using an invalid operation for Tool configuration. Please refer to "Develop Kit User Manual".*/
    ,S_FT_INVALID_CUST_PARA_OPERATION = 4025    /*!<(4025) <B>[Tool Issue]</B> An error occurs when using an invalid operation for CUST_PARA. Please refer to "Develop Kit User Manual".*/
    ,S_FT_INVALID_SEC_RO_OPERATION = 4026       /*!<(4026) <B>[Tool Issue]</B> An error occurs when using an invalid operation for SEC_RO. Please refer to "Develop Kit User Manual".*/
    ,S_FT_INVALID_OTP_OPERATION = 4027          /*!<(4027) <B>[Tool Issue]</B> An error occurs when using an invalid operation for OTP operation. Please refer to "Develop Kit User Manual".*/
    ,S_FT_POST_PROCESS_FAIL = 4028              /*!<(4028) <B>[DLL Issue]</B> */
    ,S_FT_FTCFG_UPDATE_FAIL = 4029              /*!<(4029) <B>[DLL Issue]</B> */
    ,S_FT_SEC_RO_GET_INFO_FAIL = 4030           /*!<(4030) <B>[DLL Issue]</B> */
    ,S_FT_SEC_RO_READ_FAIL = 4031               /*!<(4031) <B>[DLL Issue]</B> */
    ,S_FT_SEC_RO_WRITE_FAIL = 4032              /*!<(4032) <B>[DLL Issue]</B> */
    ,S_FT_ENABLE_SRAM_FAIL = 4033               /*!<(4033) <B>[DLL Issue]</B> Failed to enable SRAM.*/
    ,S_FT_ENABLE_DRAM_FAIL = 4034               /*!<(4034) <B>[DLL Issue]</B> Failed to enable DRAM.*/
    ,S_FT_FS_FINDFIRSTEX_FAIL = 4035            /*!<(4035) <B>[DLL Issue]</B> */
    ,S_FT_FS_FINDNEXTEX_FAIL = 4036             /*!<(4036) <B>[DLL Issue]</B> */
    ,S_FT_FS_FOPEN_FAIL = 4037                  /*!<(4037) <B>[DLL Issue]</B> */
    ,S_FT_FS_GETFILESIZE_FAIL = 4038            /*!<(4038) <B>[DLL Issue]</B> */
    ,S_FT_FS_READ_FAIL = 4039                   /*!<(4039) <B>[DLL Issue]</B> */
    ,S_FT_FS_FILENAME_INVALID = 4040            /*!<(4040) <B>[User's Issue]</B> A Tool's warning that the used filename is valid. Please check if your file exists.*/
    ,S_FT_FS_FILENAME_TOO_LONG = 4041           /*!<(4041) <B>[User's Issue]</B> A Tool's warning that the length of used filename is too long. Please check your filename is valid.*/
    ,S_FT_FS_ASSERT = 4042                      /*!<(4042) <B>[DLL Issue]</B> */
    ,S_FT_OTP_ADDR_NOT_WORD_ALIGNMENT = 4043    /*!<(4043) <B>[User's Issue]</B> A Tool's warning that the address given of OTP operation is not word-aligned. Please check your OTP address again.*/
    ,S_FT_OTP_LENGTH_NOT_WORD_ALIGNMENT = 4044  /*!<(4044) <B>[User's Issue]</B> A Tool's warning that the length given of OTP operation is not word-aligned. Please check your OTP length again.*/
    ,S_FT_OTP_INVALID_ADDRESS_RANGE = 4045      /*!<(4045) <B>[User's Issue]</B> A Tool's warning that the address given of OTP operation is out of range. Please check your OTP address and length again.*/
    ,S_FT_NAND_READ_TO_BUFFER_NOT_SUPPORT = 4046/*!<(4046) <B>[Tool Issue]</B> An error occurs when user would like to read data into buffer and the read flag is not  NUTL_READ_PAGE_WITH_ECC.*/
    ,S_FT_GET_PROJECT_ID_FAIL = 4047            /*!<(4047) <B>[DLL Issue]</B> */
    ,S_FT_ENFB_ROM_FILE_SMALL_THAN_HEADER_DESCRIBE = 4048   /*!<(4048) <B>[MAUI S/W Issue]</B> A Tool's warning that the size of E-NFB Rom file is smaller than that described in header of E-NFB Rom file. Please ask for help.*/
    ,S_FT_RW_EXTRACT_NFB_FAIL = 4049            /*!<(4049) <B>[DLL Issue]</B> */
    ,S_FT_MEMORY_TEST_FAIL = 4050               /*!<(4050) <B>[DLL Issue]</B> */
    ,S_FT_CHECK_BOOTLOADER_FEATURE_FAIL = 4051  /*!<(4051) */
    ,S_FT_ENABLE_BOOT_FAIL = 4052               /*!<(4052) */
    ,S_FT_FORBIDDEN_DOWNLOAD_BOOTLOADER_FAIL_SUART = 4053   /*!<(4053) */
    ,S_FT_SPK_FEATURE_FAIL = 4054               /*!<(4054) */
    ,S_FT_FS_FLASH_SETTING_DIFFERENT_FROM_TARGET = 4055 /*!<(4055) */
    ,S_FT_FS_EXCEED_FAT_RANGE_ON_TARGET = 4056  /*!<(4056) */
    ,S_FT_FS_INVALID_BRMT_BLOCK = 4057          /*!<(4057) */
    ,S_FT_FILE_NOT_EXIST = 4058                 /*!<(4058) */
    ,S_FT_CAN_NOT_OPEN_FILE = 4059              /*!<(4059) */
    ,S_FT_INVALID_FORMAT = 4060                 /*!<(4060) */
    ,S_FT_COMMUNICATION_ERROR = 4061            /*!<(4061) */
    ,S_FT_PROTOCOL_EXCEPTION = 4062             /*!<(4062) */
    ,S_FT_CBR_INFO_NOT_EXIST = 4063             /*!<(4063) */
    ,S_FT_INVALID_CBR_RECORD_INDEX = 4064       /*!<(4064) */
    ,S_FT_CBR_WRITE_FAIL = 4065                 /*!<(4065) */
    ,S_FT_CBR_READ_FAIL = 4066                  /*!<(4066) */
    ,S_FT_INVALID_CBR_FILE_TYPE = 4067          /*!<(4067) */
    ,S_FT_USB_CHANGE_2_0_FAIL = 4068            /*!<(4068) */
    ,S_FT_SECURE_USB_DL_NOT_SUPPORT_DL_BOOT_REGION = 4069   /*!<(4069) */
    ,S_FT_SECURE_USB_DL_NOT_SUPPORT_DL_CONTROL_BLOCK_REGION = 4070  /*!<(4070) */
    ,S_FT_USB_1_1_INVALID_COM_NUMBER = 4071   /*!<(4071) */
    ,S_FT_INVALID_REGISTER_ADDRESS_ACCESS = 4072   /*!<(4072) */
    ,S_FT_INVALID_CFG_FILE = 4073               /*!<(4073) */
    ,S_FT_SECURE_USB_DL_NOT_SUPPORT_DL_NO_UPDATABLE_BL = 4074    /*!<(4074) */
    ,S_FT_BOOTLOADER_USB_DL_NOT_SUPPORT_DL_BOOT_REGION = 4075    /*!<(4075) */
    ,S_FT_BOOTLOADER_USB_DL_NOT_SUPPORT_DL_NO_UPDATABLE_BL = 4076    /*!<(4076) */
    ,S_FT_MOUNT_FLASH_NOT_SUPPORTED = 4077    /*!<(4077) */
    ,S_FT_DOWNLOAD_SIGNATURE_MISMATCH = 4078  /*!<(4078) */
    ,S_FT_FAT_CHANGE = 4079  /*!<(4079) */


    ,S_FT_COMMUNICATION_ERROR_WITHOUT_EFUSE_VERIFY = 4080    /*!<(4080) */
    ,S_FT_PROTOCOL_EXCEPTION_WITHOUT_EFUSE_VERIFY  = 4081    /*!<(4081) */
    ,S_FT_UNSUPPORTED_API_IN_GNUC = 4082    /*!<(4082) */
    ,S_PART_NO_VALID_TABLE = 4083 /*!<(4083) */
    ,S_PART_NO_SPACE_FOUND = 4084 /*!<(4084) */
    ,S_DL_PMT_ERR_NO_SPACE = 4085  /*!<(4085) */
    ,S_FT_NEED_DOWNLOAD_ALL_PARTITION_FAIL = 4086  /*!<(4086) */
    ,S_FT_LAST_PARTITION_NOT_FOUND = 4087  /*!<(4087) <B>[DLL Issue]</B> Failed to find the last partition with size = 0. */
    ,S_FT_PMT_MISMATCH = 4088  /*!<(4088) <B>[DLL Issue]</B> The PMT mismatches to the target's PMT. */
    ,S_FT_BACKUP_OF_NVRAM_PARTITION_MISMATCH = 4089  /*!<(4089) <B>[User's Issue]</B> The size of backup nvram partition mismatches to the new configuration. */
    ,S_FT_DOWNLOAD_MAUI_BUT_TARGET_CONTAIN_LINUX_IMAGE = 4090 /*!<(4089) <B>[User's Issue]</B> User download maui code but there are linux images in the target. User must total format before downloading */
    ,S_FT_LINUX_NVRAM_FILE_EXIST_WHEN_BACKUP = 4091                  /*!<(4091) <B>[User's Issue]</B> The backup file exsits on PC side and then causes the flashtool can not backup the file with the same name. If the old backup file is not important, please clean it up */
    ,S_FT_LINUX_NVRAM_FILE_NOT_EXIST_WHEN_RESTORE = 4092                  /*!<(4092) <B>[User's Issue]</B> The backup file exsits on PC side and then causes the flashtool can not backup the file with the same name. If the old backup file is not important, please clean it up */
    ,S_FT_LINUX_NVRAM_PARTITION_CHANGE = 4093                  /*!<(4093) <B>[User's Issue]</B> The linux NVRAM partition will be changed, but user doens't enable backup mechanism. Please total format or enable backup mechanism before downloading. */
    ,S_FT_LINUX_NVRAM_CRC_RECORD_NOT_EXIST = 4094                  /*!<(4094) <B>[User's Issue]</B> Cannot open the CRC record of the restored file. The CRC record may be lost. */
    ,S_FT_LINUX_NVRAM_CRC_CHECK_FAIL = 4095                  /*!<(4095) <B>[User's Issue]</B> The CRC check failed. The resored data may be modified. */
    ,S_FT_GET_HANDSET_FEATURE_COMBINATION_FAIL = 4096  /*!<(4096) */
    ,S_FT_ERROR_END // END

    // FlashTool Handle error code (5000~5999)
    ,S_FTHND_ERROR_BEGIN = 5000                 /*!<FlashTool Handle error code (5000~5999) */
    ,S_AUTH_HANDLE_IS_NOT_READY = S_FTHND_ERROR_BEGIN   /*!<(5000) <B>[User's Issue]</B> A Tool's warning that you're using secure baseband chip. Please select the authentication file first.*/
    ,S_INVALID_AUTH_FILE = 5001                 /*!<(5001) <B>[User's Issue]</B> A Tool's warning that you're using secure baseband chip. Please select the authentication file first.*/
    ,S_INVALID_DA_FILE = 5002                   /*!<(5002) <B>[User's Issue]</B> A Tool's warning that you're using an invalid DA file with wrong format. Please ask for help.*/
    ,S_DA_HANDLE_IS_NOT_READY = 5003            /*!<(5003) <B>[Tool Issue]</B> An error occurs when the instance of DA_HANDLE is not ready. Please create the instance of DA_HANDLE before you use it.*/
    ,S_FTHND_ILLEGAL_INDEX = 5004               /*!<(5004) <B>[Tool Issue]</B> An error occurs when user uses an illegal index to request any rom entry in DL_HANDLE.*/
    ,S_FTHND_HANDLE_BUSY_NOW = 5005             /*!<(5005) <B>[Tool Issue]</B> An error occurs when the HANDLE you want to use is used by other thread.*/
    ,S_FTHND_FILE_IS_UPDATED = 5006             /*!<(5006) <B>[Tool Issue]</B> An error occurs when the file controlled by some Handle is updated.*/
    ,S_FTHND_FILE_IS_NOT_LOADED_YET = 5007      /*!<(5007) <B>[Tool Issue]</B> An error occurs when the file is not loaded into some HANDLE.*/
    ,S_FTHND_FILE_LOAD_FAIL = 5008              /*!<(5008) <B>[DLL Issue]</B> */
    ,S_FTHND_FILE_UNLOAD_FAIL = 5009            /*!<(5009) <B>[DLL Issue]</B> */
    ,S_FTHND_LIST_IS_EMPTY = 5010               /*!<(5010) <B>[Tool Issue]</B> An error occurs when DL_HANDLE_LIST doesn't contain any DL_HANDLE.*/
    ,S_DL_SCAT_INCORRECT_FORMAT = 5011          /*!<(5011) <B>[MAUI S/W Issue]</B> A Tool's warning that the scatter file has incorrect format. Please ask for help.*/
    ,S_DL_SCAT_ADDR_IS_NOT_WORD_ALIGN = 5012    /*!<(5012) <B>[MAUI S/W Issue]</B> A Tool's warning that the address of some Load Region in the scatter file is not word-aligned. Please ask for help.*/
    ,S_DL_SCAT_OFFSET_IS_NOT_WORD_ALIGN = 5013  /*!<(5013) <B>[MAUI S/W Issue]</B> A Tool's warning that the offset of some Load Region in the scatter file is not word-aligned. Please ask for help.*/
    ,S_DL_SCAT_ADDR_IS_NOT_ASCENDING_ORDER = 5014   /*!<(5014) <B>[MAUI S/W Issue]</B> A Tool's warning that the offset of some Load Region in the scatter file is not word-aligned. Please ask for help.*/
    ,S_DL_SCAT_JUMPTABLE_IS_NOT_ABSOLUTE_ADDR = 5015/*!<(5015) <B>[MAUI S/W Issue]</B> A Tool's warning that the address of jump table binary file in the scatter file is not absolute address. Please ask for help.*/
    ,S_DL_LOAD_REGION_IS_OVERLAP = 5016         /*!<(5016) <B>[MAUI S/W Issue]</B> A Tool's warning that the addresses of some Load Regions in the scatter file are overlapped. Please ask for help.*/
    ,S_DL_LOAD_REGION_NOT_FOUND = 5017          /*!<(5017) <B>[Internal Error]</B> */
    ,S_DL_NOT_RESOURCE_BIN = 5018               /*!<(5018) <B>[Tool Issue]</B> An error occurs when DL_HANDLE get resource information in some binary file and the binary file is not a resource binary file.*/
    ,S_DL_MULTIBIN_MECHANISM_DISABLED = 5019    /*!<(5019) <B>[Tool Issue]</B> An error occurs when Multi-Bin related APIs is used and the DL_HANDLE disable Multi-Bin mechanism.*/
    ,S_DL_RESOURCE_NOT_MATCH_IN_JUMPTABLE = 5020/*!<(5020) <B>[Tool Issue]</B> An error occurs when information of resource binary file is not matched with jump table binary file.*/
    ,S_DL_RESOURCE_MUST_DOWNLOAD_WITH_JUMPTABLE = 5021  /*!<(5021) <B>[User's Issue]</B> A Tool's warning that resource binary file and jump table binary are not downloaded together. Please choose resource binary with jump table binary file.*/
    ,S_DL_OVERLAP_WITH_EXISTING_RESOURCE = 5022 /*!<(5022) <B>[Tool Issue]</B> An error occurs when the resource binary file overlaps some existed resource binary file.*/
    ,S_DL_INVALID_RESOURCE_BIN = 5023           /*!<(5023) <B>[Tool Issue]</B> An error occurs when the resource binary has invalid information in its header.*/
    ,S_DL_JUMPTABLE_INCONSISTENT_WITH_SCAT = 5024   /*!<(5024) <B>[Tool Issue]</B> An error occurs when the information of some entry in jump table binary is inconsistent with the scatter file.*/
    ,S_DL_INVALID_JUMPTABLE = 5025              /*!<(5025) <B>[MAUI S/W Issue]</B> A Tool's warning that the jump table binary has invalid information in its header. Please ask for help.*/
    ,S_DL_REGION_ADDR_INCONSISTENT_WITH_SCAT = 5026 /*!<(5026) <B>[Tool Issue]</B> An error occurs when the address of some rom entry in DL_HANDLE is inconsistent with that in the scatter file.*/
    ,S_DL_REGION_ADDR_INCONSISTENT_WITH_RESOURCE_ADDR = 5027    /*!<(5027) <B>[MAUI S/W Issue]</B> A Tool's warning that the address of resource binary file in scatter file is inconsistent with the address in the header of resource binary file. Please ask for help.*/
    ,S_DL_INVALID_BOOTLOADER = 5028             /*!<(5028) <B>[MAUI S/W Issue]</B> A Tool's warning that the Boot Loader Image file has invalid information in its header. Please ask for help.*/
    ,S_DL_INVALID_BOOTLOADER_CHKSUM_SEED = 5029 /*!<(5029) */
    ,S_DL_BOOTLOADER_IS_NOT_LOADED_YET = 5030   /*!<(5030) <B>[Tool Issue]</B> An error occurs when the address of some rom entry in DL_HANDLE is inconsistent with that in the scatter file.*/
    ,S_DL_BOOTLOADER_NOT_FOUND = 5031           /*!<(5031) <B>[Tool Issue]</B> An error occurs when DL_HANDLE auto-loads Boot Loader Image file and there isn't any filename matched for Boot Loader Image file. Please ask for help.*/
    ,S_DL_REMOTE_FILE_UNSUPPORTED_BY_BL_AUTOLOAD = 5032 /*!<(5032) <B>[User's Issue]</B> A Tool's warning that Boot Loader Image file is in remote server. Please use a local Boot Loader Image file in your computer.*/
    ,S_DLIST_SAME_FLASHID_AND_BBCHIP_SW_VER = 5033  /*!<(5033) <B>[Tool Issue]</B> An error occurs when adding a new DL_HANDLE into DL_HANDLE_LIST and there exists a DL_HANDLE with the same S/W version of baseband chip in DL_HANDLE_LIST.*/
    ,S_DLIST_SAME_BBCHIP_SW_VER = 5034          /*!<(5034) */
    ,S_DLIST_BBCHIP_HW_VER_NOT_MATCHED = 5035   /*!<(5035) <B>[User's Issue]</B> An error occurs when there doesn't exist a specific H/W version of baseband chip in the DL_HANDLE_LIST.*/
    ,S_DLIST_NO_MATCHED_DL_HANDLE_FOUND = 5036  /*!<(5036) <B>[Obsolete Error]</B> */
    ,S_DLIST_DL_HANDLE_NOT_IN_LIST = 5037       /*!<(5037) <B>[Tool Issue]</B> An error occurs when there doesn't exist a DL_HANDLE with a specific S/W version to remove in the DL_HANDLE_LIST.*/
    ,S_DLIST_DL_HANDLE_ALREADY_IN_LIST = 5038   /*!<(5038) <B>[Tool Issue]</B> An error occurs when there doesn't exist a DL_HANDLE with a specific S/W version to add in the DL_HANDLE_LIST.*/
    ,S_FTHND_CALLBACK_REMOTE_GET_FILE_LEN_FAIL = 5039   /*!<(5039) <B>[Tool Issue]</B> An error occurs when CALLBACK_REMOTE_GET_FILE_LEN callback function returns fail. Please check your callback function.*/
    ,S_FTHND_CALLBACK_REMOTE_READ_FILE_FAIL = 5040  /*!<(5040) <B>[Tool Issue]</B> An error occurs when CALLBACK_REMOTE_READ_FILE callback function returns fail. Please check your callback function.*/
    ,S_FTHND_CALLBACK_FILE_INTEGRITY_CHECK_FAIL = 5041  /*!<(5041) <B>[Tool Issue]</B> An error occurs when CALLBACK_FILE_INTEGRITY_CHECK callback function returns fail. Please check your callback function.*/
    ,S_UNSUPPORTED_VER_OF_AUTH_FILE = 5042      /*!<(5042) <B>[User's Issue]</B> A Tool's warning that the authentication file contains an unsupported version. Please check the Tool is the latest version, or ask for help.*/
    ,S_DL_PROJECT_ID_DIFF_BETWEEN_MAIN_CODE_AND_JUMP_TBL = 5043 /*!<(5043) <B>[MAUI S/W Issue]</B> A Tool's warning that the project IDs between MAUI code and jump table binary file are different. Please check the MAUI and jump table are in the same project.*/
    ,S_DL_SCAT_OPEN_FAIL = 5044                 /*!<(5044) <B>[User's Issue]</B> A Tool's warning that scatter file cannot be opened. Please check if your scatter file exists and is not used by other software.*/
    ,S_FTHND_CALLBACK_COM_INIT_STAGE_FAIL = 5045/*!<(5045) <B>[Tool Issue]</B> An error occurs when CALLBACK_COM_INIT_STAGE callback function returns fail. Please check your callback function.*/
    ,S_DL_UNSECURE_MAUI_TO_SECURE_BB = 5046     /*!<(5046) <B>[User's Issue]</B> A Tool's warning that un-secure MAUI cannot be downloaded into secure BB. Please use secure MAUI.*/
    ,S_FTHND_CALLBACK_REMOTE_GET_SIG_LEN_FAIL = 5047    /*!<(5047) <B>[DLL Issue]</B> */
    ,S_FTHND_CALLBACK_REMOTE_READ_SIG_FAIL = 5048   /*!<(5048) <B>[DLL Issue]</B> */
    ,S_DL_RESOURCE_MUST_DOWNLOAD_WITH_ANOTHERBIN = 5049 /*!<(5049) <B>[Internal Error]</B> */
    ,S_DL_RESOURCE_MUST_DOWNLOAD_WITH_ENFB = 5050   /*!<(5050) <B>[User's Issue]</B> A Tool's warning that resource binary must download with ENFB file at the same time. Please check it again.*/
    ,S_DL_PROJECT_ID_DIFF_BETWEEN_MAIN_CODE_AND_RESOURCE_BIN = 5051 /*!<(5051) <B>[User's Issue]</B> A Tool's warning that project id between main code and resource files are different. Please check it again.*/
    ,S_DL_PROJECT_ID_DIFF_AMONG_RESOURCE_BIN = 5052 /*!<(5052) <B>[User's Issue]</B> A Tool's warning that project id among resource files are different. Please check it again.*/
    ,S_DL_UNSECURE_BOOTLOADER_TO_SECURE_BB = 5053   /*!<(5053) <B>[User's Issue]</B> A Tool's warning that un-secure Boot Loader file would be downloaded into target. Please check it again.*/
    ,S_DL_GET_DRAM_SETTING_FAIL = 5054          /*!<(5054) <B>[Tool Issue]</B> An error occurs might be the following reasons:
                                                    1. There does not exist the MTK_ROM_INFO structure in the ROM.
                                                    2. There does not exist the MTK_BLOADER_INFO structure in the boot-loader.
                                                    3. It is not NFB-booting.*/
    ,S_DL_FOTA_INFO_IMAGE_NUMBER_NOT_MATCH_WITH_SCATTER_FILE = 5055 /*!<(5055) <B>[User's Issue]</B> A Tool's warning that image number in FOTA_INFO is different with scatter file. Please check it again.*/
    ,S_DL_PROJECT_ID_DIFF_BETWEEN_THIRD_ROM_AND_RESOURCE_BIN = 5056 /*!<(5056) <B>[User's Issue]</B> A Tool's warning that project id between resource files and ENFB are different. Please check it again.*/
    ,S_DL_FOTA_SEC_INFO_MAC_ADDR_NOT_MATCH_WITH_MAUI = 5057 /*!<(5057) <B>[User's Issue]</B> A Tool's warning that MAC address between FOTA UA file and ROM file are different. Please check it again.*/
    ,S_DL_PC_NFB_DUAL_BL_PAIRED_VERSION_NOT_MATCHED_WITH_MAUI = 5058    /*!<(5058) */
    ,S_DL_PC_NFB_DUAL_BL_FEATURE_COMBINATION_NOT_MATCHED_WITH_MAUI = 5059   /*!<(5059) */
    ,S_DL_PC_NOR_XIP_BL_PAIRED_VERSION_NOT_MATCHED_WITH_MAUI = 5060 /*!<(5060) */
    ,S_DL_PC_NOR_XIP_BL_FEATURE_COMBINATION_NOT_MATCHED_WITH_MAUI = 5061    /*!<(5061) */
    ,S_DL_INVALID_BOOT_CERT = 5062              /*!<(5062) */
	,S_DL_FILE_NOT_FOUND = 5063                 /*!<(5063) */
    ,S_INVALID_SCERT_FILE = 5064                /*!<(5064) */
    ,S_UNSUPPORTED_VER_OF_SCERT_FILE = 5065     /*!<(5065) */
    ,S_UNSUPPORTED_TARGET_CHIP_VERSION = 5066   /*!<(5066) */
    ,S_SCERT_HANDLE_IS_NOT_READY = 5067         /*!<(5067) */
    ,S_FTHND_ROM_ENTRIES_NOT_CREATED_YET = 5068 /*!<(5068) */
    ,S_FTHND_NO_ROM_IS_ENABLED = 5069           /*!<(5069) */
    ,S_INVALID_ROOTCERT_FILE = 5070             /*!<(5070) */
    ,S_UNSUPPORTED_VER_OF_ROOTCERT_FILE = 5071  /*!<(5071) */
    ,S_ROOTCERT_HANDLE_IS_NOT_READY = 5072      /*!<(5072) */
    ,S_SECURE_USB_DL_DA_UNENCRYPTED = 5073      /*!<(5073) */
    ,S_NORMAL_USB_DL_DA_ENCRYPTED = 5074        /*!<(5074) */
    ,S_DL_COMBO_MEMORY_SETTING_NOT_MATCHED = 5075   /*!<(5075) */
    ,S_DL_PSRAM_DIDR_NOT_MATCHED = 5076         /*!<(5076) */
    ,S_DL_FAT_RANGE_CHECK_FAIL = 5077           /*!<(5077) */
    ,S_DL_MAUI_NOT_FOUND = 5078                 /*!<(5078) */
    ,S_FTHND_SV3_SV5_NOT_MATCH = 5079           /*!<(5079) */
    ,S_DL_SDS_INFO_CHECK_FAIL = 5080            /*!<(5080) */
    ,S_FTHND_SDS_INFO_NOT_EXIST = 5081          /*!<(5081) */
    ,S_DL_HANDSET_SDS_INFO_NOT_EXIST = 5082     /*!<(5082) */
    ,S_DL_ROM_BOOT_DEVICE_NOT_ALIGN = 5083      /*!<(5083) */
    ,S_DL_ROM_BOOT_DEVICE_NONE = 5084           /*!<(5084) */
    ,S_DL_DSP_INFO_CHECK_FAIL = 5085            /*!<(5085) */
    ,S_DL_UNSUPPORTED_TOOL_VERSION = 5086       /*!<(5086) */
    ,S_DL_MAIN_CODE_MUST_DOWNLOAD_ALL_BIN = 5087    /*!<(5087) */
    ,S_DL_MBA_MUST_DOWNLOAD_ALL_RESOURCE_BIN = 5088 /*!<(5088) */
    ,S_DL_FACTORY_BIN_NOT_MATCHED_WITH_MAUI = 5089  /*!<(5089) */
    ,S_DL_EMMC_BOOTING_INFO_NOT_FOUND = 5090  /*!<(5090) */
    ,S_DL_EMMC_CONFIG_PARTITION_INVALID = 5091 /*!<(5091) */
    ,S_DL_EMMC_CONFIG_PARTITION_INFO_FAIL = 5092  /*!<(5092) */
    ,S_NORMAL_DL_BUT_MAUI_IS_ENCRYPTED = 5093  /*!<(5093) */
    ,S_DL_NO_ROOTCERT_FILE_IN_DL_HANDLE = 5094  /*!<(5094) */
    ,S_DL_MAUI_FLASH_ID_NOT_MATCHED_WITH_TARGET = 5095  /*!<(5095) */
    ,S_DL_MAUI_FLASH_ID_NOT_MATCHED_WITH_CFG_FILE = 5096  /*!<(5096) */
    ,S_DL_MAUI_EMI_SETTING_NOT_MATCHED_WITH_CFG_FILE = 5097  /*!<(5097) */
    ,S_DL_MBA_RESOURCE_VERSION_DIFF_BETWEEN_MAIN_CODE_AND_RESOURCE_BIN = 5098  /*!<(5098) */
    ,S_DL_PC_ARM_BL_FEATURE_COMBINATION_NOT_MATCHED_WITH_EXT_BL = 5099    /*!<(5099) */
    ,S_DL_PC_ARM_BL_PAIRED_VERSION_NOT_MATCHED_WITH_EXT_BL = 5100         /*!<(5100) */
    ,S_DL_MBA_JUMPTABLE_PARTIAL_DOWNLOAD_NOT_MATCHED_WITH_HANDSET = 5101         /*!<(5101) */
    ,S_DL_UNSUPPORTED_VER_OF_MBA_RES_INFO = 5102  /*!<(5102) */
    ,S_DL_MBA_RESOURCE_VERSION_THE_SAME_IN_RESOURCE_BINS = 5103   /*!<(5103) */
    ,S_NORMAL_BLUSBDL_AND_CHIP_SUPPORT_BROMUSBV2 = 5104   /*!<(5104) */
    ,S_DL_MAUI_FAT_RANGE_EXCEEDS_FLASH_RANGE = 5105   /*!<(5105) */
    ,S_DL_MBA_JUMPTABLE_PARTIAL_DOWNLOAD_NOT_FOUND_ON_TARGET = 5106         /*!<(5106) */
	,S_DL_MAUI_BBCHIP_CHECK_ID_NOT_MATCH = 5107         /*!<(5107) */
    ,S_DA_BOOT_CERT_SRD_STRUCT_MISMATCH = 5108          /*!<(5108) <B>[MAUI S/W Issue]</B> A error that the SRD structure size does not match the definition in DA. Please ask for help.*/
    ,S_SECURE_BLUSBDL_WITH_UNENCRYPTED_DA_AND_CHIP_SUPPORT_BROMUSBV2 = 5109   /*!<(5109) */
    ,S_NORMAL_UART_DL_BUT_DA_ENCRYPTED = 5110        /*!<(5110) */
    ,S_CHIP_SUPPORT_BROMUSBV2_BUT_MAUI_IS_NOT_SUPPORT = 5111   /*!<(5111) */
    ,S_DL_SDS_INFO_CHECK_FAIL_BUT_PC_SW_COMPATIBLE  = 5112   /*!<(5112) */
    ,S_DL_PMIC_MT6327_BUT_USER_TRIGGER_DL_WITHOUT_BATTERY = 5113 /*!<(5113) */
    ,S_LTE_PARTIAL_DOWNLOAD_CONDITON_CHECK_FAIL = 5114/*!<(5114) The partial download condition check fail */
    ,S_LTE_AP_AND_MODEN_OVERLAP = 5115/*!<(5115) The ap and moden overlap */
    ,S_DL_MAUI_FLASH_TYPE_NOT_MATCHED_WITH_TARGET = 5116/*!<(5116) The ap and moden overlap */
    ,S_DL_LTE_DSP_INFO_CHECK_FAIL = 5117/*!<(5117) The DSP info of LTE_DSP_ROM does not match to the maui info of main rom*/
    ,S_DL_SDS_REGION_OVERLAP_WITH_PARTITION_REGION = 5118/*!<(5118) PC SW's SDS region is overlap with partition region. Please check SW layout is correct with SW build owner. */
    ,S_DL_BINARY_AUTODECRYPT_FAIL = 5119             /*!<(5119) */
    ,S_DL_PC_PROJECT_ID_IS_INVALID   = 5120   /*!<(5120) */
    ,S_DL_TARGET_PROJECT_ID_IS_INVALID   = 5121   /*!<(5121) */
    ,S_DL_PROJECT_ID_IS_NOT_MATCH_BETWEEN_PC_AND_HANDSET   = 5122   /*!<(5122) */
    ,S_NORMAL_DL_WITHOUT_AUTH_FILE_INPUT_BUT_MAUI_IS_ENCRYPTED = 5123  /*!<(5123) */
    ,S_NORMAL_DL_IN_NORMAL_PHONE_BUT_MAUI_IS_ENCRYPTED = 5124  /*!<(5124) */
    ,S_DA_VERSION_NOT_MATCH_WITH_BROM_DLL = 5125  /*!<(5125) */
    ,S_DL_PROJECT_ID_TYPE_IS_NOT_MATCH_BETWEEN_PC_AND_HANDSET   = 5126   /*!<(5126) */
    ,S_DL_PROJECT_ID_NAME_IS_NOT_MATCH_BETWEEN_PC_AND_HANDSET   = 5127   /*!<(5127) */
    ,S_FTHND_ERROR_END // END

    // security error code (6000~6999)
    ,S_SECURITY_ERROR_BEGIN = 6000              /*!<security error code (6000~6999) */
    ,S_SECURITY_CALLBACK_SLA_CHALLENGE_FAIL = S_SECURITY_ERROR_BEGIN    /*!<(6000) <B>[Tool Issue]</B> A fail from CALLBACK_SLA_CHALLENGE callback function.*/
    ,S_SECURITY_SLA_WRONG_AUTH_FILE = 6001      /*!<(6001) <B>[User's Issue]</B> A Tool's warning that the authentication file with a custom name is different from the custom name in the handset. Please ask the owner of this handset for an authentication file with a correct custom name. */
    ,S_SECURITY_SLA_INVALID_AUTH_FILE = 6002    /*!<(6002) <B>[User's Issue]</B> A Tool's warning that an invalid authentication file is used. This error message will occurs with MSP (MTK Secure Platform) code. Please keep up the MSP code and ask for help.*/
    ,S_SECURITY_SLA_CHALLENGE_FAIL = 6003       /*!<(6003) <B>[Tool Issue]</B> An error occurs when an authentication file is used with an invalid public key.*/
    ,S_SECURITY_SLA_FAIL = 6004                 /*!<(6004) <B>[DLL Issue]</B> */
    ,S_SECURITY_DAA_FAIL = 6005                 /*!<(6005) <B>[Tool Issue]</B> An error occurs when the DA signature can not pass DA Authentication.*/
    ,S_SECURITY_SBC_FAIL = 6006                 /*!<(6006) <B>[MAUI S/W Issue]</B> An error occurs when the target start address can not pass Secure Boot Checker.*/
    ,S_SECURITY_ME_ID_FAIL = 6007               /*!<(6007) No Used*/
    ,S_SECURITY_SF_SECURE_VER_CHECK_FAIL = 6008 /*!<(6008) <B>[User's Issue]</B> A Tool's warning that the secure version of the secure-MAUI is older than that in the handset. Please choose a secure-MAUI with an equal or newer secure version.*/
    ,S_SECURITY_SF_HANDSET_SECURE_CUSTOM_NAME_NOT_MATCH = 6009  /*!<(6009) <B>[User's Issue]</B> A Tool's warning that the custom name of the secure-MAUI is different from that in the handset. Please choose a secure-MAUI with the same custom name.*/
    ,S_SECURITY_SF_FTCFG_LOCKDOWN = 6010        /*!<(6010) <B>[User's Issue]</B> A Tool's warning that the Tool configuration is locked down.*/
    ,S_SECURITY_SF_CODE_DOWNLOAD_FORBIDDEN = 6011   /*!<(6011) <B>[User's Issue]</B> A Tool's warning that to download code area is forbidden in this phone.*/
    ,S_SECURITY_SF_CODE_READBACK_FORBIDDEN = 6012   /*!<(6012) <B>[User's Issue]</B> A Tool's warning that to read-back code area is forbidden in this phone.*/
    ,S_SECURITY_SF_CODE_FORMAT_FORBIDDEN = 6013 /*!<(6013) <B>[User's Issue]</B> A Tool's warning that to format code area is forbidden in this phone.*/
    ,S_SECURITY_SF_SEC_RO_DOWNLOAD_FORBIDDEN = 6014 /*!<(6014) <B>[User's Issue]</B> A Tool's warning that to download SEC_RO is forbidden in this phone.*/
    ,S_SECURITY_SF_SEC_RO_READBACK_FORBIDDEN = 6015 /*!<(6015) <B>[User's Issue]</B> A Tool's warning that to read-back SEC_RO is forbidden in this phone.*/
    ,S_SECURITY_SF_SEC_RO_FORMAT_FORBIDDEN = 6016   /*!<(6016) <B>[User's Issue]</B> A Tool's warning that to format SEC_RO is forbidden in this phone*/
    ,S_SECURITY_SF_FAT_DOWNLOAD_FORBIDDEN = 6017    /*!<(6017) <B>[User's Issue]</B> A Tool's warning that to download FAT area is forbidden in this phone.*/
    ,S_SECURITY_SF_FAT_READBACK_FORBIDDEN = 6018    /*!<(6018) <B>[User's Issue]</B> A Tool's warning that to read-back FAT area is forbidden in this phone.*/
    ,S_SECURITY_SF_FAT_FORMAT_FORBIDDEN = 6019  /*!<(6019) <B>[User's Issue]</B> A Tool's warning that to format FAT area is forbidden in this phone.*/
    ,S_SECURITY_SF_RESTRICTED_AREA_ACCESS_FORBIDDEN = 6020  /*!<(6020) <B>[User's Issue]</B> A Tool's warning that to access restricted area (SEC_RO area and Flash Tool configuration area in the handset) is forbidden in this phone.*/
    ,S_SECURITY_SECURE_CUSTOM_NAME_NOT_MATCH_BETWEEN_AUTH_AND_DL_HANDLE = 6021  /*!<(6021) <B>[User's Issue]</B> A Tool's warning that the custom name in the authentication file is different from that in secure-MAUI. Please choose the same custom name between authentication file and secure-MAUI.*/
    ,S_SECURITY_SECURE_CUSTOM_NAME_NOT_MATCH_BETWEEN_AUTH_AND_BL = 6022 /*!<(6022) [User's Issue]</B> A Tool's warning that the custom name in the authentication file is different from that in secure-Bootloader information. Please choose the same custom name between authentication file and secure-Bootloader.*/
    ,S_SECURITY_DOWNLOAD_FILE_IS_CORRUPTED = 6023   /*!<(6023) <B>[MAUI S/W Issue]</B> A Tool's warning that some information about security in secure-MAUI file is corrupted or broken. Please ask for help.*/
    ,S_SECURITY_NOT_SUPPORT = 6024              /*!<(6024) <B>[User's Issue]</B> An error occurs when trying to write CUST_PARA on un-secure NFB */
    ,S_SECURITY_BOOTLOADER_IMAGE_SIGNATURE_FAIL = 6025  /*!<(6025) <B>[User's Issue]</B> A Tool's warning that the signature of updating firmware for end user is invalid, please check if K2 and K3 are both valid.*/
    ,S_SECURITY_BOOTLOADER_ELDER_SW_VERSION_CANNOT_BE_DOWNLOADED = 6026 /*!<(6026) <B>[User's Issue]</B> A Tool's warning that the version of updating firmware for end user is elder than phone's, it's not allowed to updated a elder firmware to the phone.*/
    ,S_SECURITY_SW_VERSION_IN_HEADER_IS_NOT_MATCH_THAT_IN_ROM_INFO = 6027   /*!<(6027) <B>[MAUI S/W Issue]</B> A Tool's warning that the the SW version in confidential bin's header is not match that in rom info. */
    ,S_SECURITY_BOOTLOADER_IMAGE_NO_SIGNATURE = 6028    /*!<(6028) <B>[User's Issue]</B> A Tool's warning that the signature of updating firmware for end user doesn't exist, it's not allowed to be updated to the phone.*/
    ,S_SECURITY_BOOTLOADER_CORRUPTED_SCATTER_FILE = 6029/*!<(6029) <B>[MAUI S/W Issue]</B> A Tool's warning that scatter file is corrupted for secure USB download. Please ask for help.*/
    ,S_SECURITY_SECURE_USB_DL_NO_MAUI_IN_SCATTER_FILE = 6030    /*!<(6030) <B>[MAUI S/W Issue]</B> A Tool's warning that there is no MAUI ROM defined in the scatter file. */
    ,S_SECURITY_SEND_CERT_FAIL = 6031           /*!<(6031) <B>[User's Issue]</B> A Tool's warning that the secure cerificate file is illegal to this phone. */
    ,S_SECURITY_SEND_AUTH_FAIL = 6032           /*!<(6032) <B>[User's Issue]</B> A Tool's warning that the authentication file is illegal to this phone. */
    ,S_SECURITY_GET_SEC_CONFIG_FAIL = 6033      /*!<(6033) <B>[Tool Issue]</B> An error occurs when trying to get security statuc from the target. */
    ,S_SECURITY_GET_ME_ID_FAIL = 6034           /*!<(6034) <B>[Tool Issue]</B> An error occurs when the invalid parameters are sent to the BRom_GetME_ID function. */
    ,S_SECURITY_SEND_ROOTCERT_FAIL = 6035       /*!<(6035) <B>[User's Issue]</B> A Tool's warning that the root cerificate file is illegal to this phone. */
    ,S_SECURITY_SECURE_USB_DL_MAUI_IS_NOT_ENCRYPTED = 6036  /*!<(6036) <B>[User's Issue]</B> A Tool's warning that to download normal(unencrypted) MAUI load in Secure USB download mode. */
    ,S_SECURITY_GET_HR_ID_FAIL = 6037           /*!<(6037) <B>[Tool Issue]</B> An error occurs when the invalid parameters are sent to the BRom_GetHR_ID function. */
    ,S_SECURITY_BOOTLOADER_USB_DL_REMAP_EMI_REGION_FAIL = 6038 /*!<(6038) <B>[Tool Issue]</B> An error occurs when BROM DLL ask bootloader to remap the EMI bank. */

    ,S_SECURITY_ERROR_END // END

    // expand to 32bits width
    ,S_MAX_STATUS_WIDTH = 0x7FFFFFFF

} STATUS_E;


/*! \cond */
#define STATUS_CODE(err_code, private_err_code)\
    ((S_COMMON_ERROR_BEGIN<=err_code)?err_code:private_err_code)

#endif
/*! \endcond */

