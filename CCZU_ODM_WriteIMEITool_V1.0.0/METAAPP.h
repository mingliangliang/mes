/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   METAAPP.h
 *
 * Project:
 * --------
 *   Maui META APP DLL
 *
 * Description:
 * ------------
 *  META APP dll export function header
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _METAAPP_H_
#define _METAAPP_H_

#include <windows.h>
#include "meta.h"
#include "mtk_mcu.h"

/*
#define  TOTAL_6205B_ADC_NUM 5
#define  TOTAL_6218B_ADC_NUM 7
*/

typedef enum
{
    TOTAL_6205B_ADC_NUM = 5
                          , TOTAL_ADC_NUM_6 = 6
                                  , TOTAL_6218B_ADC_NUM = 7
                                          , TOTAL_ADC_NUM_8 = 8
                                                  , TOTAL_ADC_NUM_9 = 9
                                                          , TOTAL_ADC_NUM_13 = 13
                                                                  , TOTAL_ADC_NUM_MAX = TOTAL_ADC_NUM_13

} TOTAL_ADC_NUM_E;

#define  MAX_BARCODE_LEN 63

// security LID
#define NUM_OF_BYTE_KEY     8
#define NUM_OF_BYTE_NP      3
#define NUM_NP              3
#define NUM_OF_BYTE_NSP     5
#define NUM_NSP             3
#define NUM_GID            20
#define NUM_OF_BYTE_IMSI    9
#define NUM_PIN1            8
#define NUM_OF_BYTE_ICCID  10

// phase error
#define  BBTX_BATTERY_TEMP_SCALE     1000.0
#define  BBTX_BATTERY_VOLTAGE_SCALE  1000000.0
#define  BBTX_CALIBRATED_SCALE  191

// setting band
#define  BAND_MODE_GSM900           0x02
#define  BAND_MODE_DCS1800          0x08
#define  BAND_MODE_PCS1900          0x10
#define  BAND_MODE_GSM850           0x80
#define  DUAL_BAND_MODE             0x0A
#define  DUAL_BAND_MODE_850_1900    0x90

// WiFi
#define   NUM_TX_POWER_2400M         14
#define   WIFI_ALC_2400M_TX_RATE_NUM  8
#define   WIFI_ALC_2400M_CH_NUM      14

#define DLLEXPORT extern "C"  __declspec(dllexport)
#define  CALL_CONVENTION   __stdcall
//#define  CALL_CONVENTION   APIENTRY
typedef enum
{
    BANDSEL_GSM900 = 0,
    BANDSEL_DCS1800,
    BANDSEL_PCS1900,
    BANDSEL_GSM850
} BAND;

typedef struct
{
    int  ADCSlope[TOTAL_ADC_NUM_MAX];
    int  ADCOffset[TOTAL_ADC_NUM_MAX];
} bmt_adcdata;


// security
typedef struct
{
    unsigned char                reg_ps_key[NUM_OF_BYTE_KEY];
    unsigned char                security_indication;
    unsigned char                auto_lock_item;
    unsigned char                np_code[NUM_OF_BYTE_NP* NUM_NP];
    unsigned char                np_key[NUM_OF_BYTE_KEY];
    unsigned char                nsp_code[NUM_OF_BYTE_NSP* NUM_NSP];
    unsigned char                nsp_key[NUM_OF_BYTE_KEY];
    unsigned char                np_of_sp[NUM_OF_BYTE_NP];
    unsigned char                np_of_cp[NUM_OF_BYTE_NP];
    unsigned char                gid1[NUM_GID];
    unsigned char                gid2[NUM_GID];
    unsigned char                sp_key[NUM_OF_BYTE_KEY];
    unsigned char                cp_key[NUM_OF_BYTE_KEY];
    unsigned char                imsi_code[NUM_OF_BYTE_IMSI];
    unsigned char                imsi_key[NUM_OF_BYTE_KEY];
    unsigned char                phone_key[NUM_OF_BYTE_KEY];
    unsigned char                last_imsi[NUM_OF_BYTE_IMSI];
    unsigned char                pin1[NUM_PIN1];
    unsigned char                pin1_valid;
    unsigned char                phone_lock_verified;
} s_security_info_struct;



typedef struct
{
    unsigned char security_indication;
    unsigned char phone_key[NUM_OF_BYTE_KEY];
    unsigned char last_imsi[NUM_OF_BYTE_IMSI];
    unsigned char pin1[NUM_PIN1];
    unsigned char pin1_valid;
    unsigned char phone_lock_verified;
    unsigned char iccid[NUM_OF_BYTE_ICCID];

} s_security_info_struct_ex; //smu_security_info_struct;





// phase error
typedef struct
{
    unsigned char bbtx_common_mode_voltage;
    unsigned char bbtx_gain;
    unsigned char bbtx_calrcsel;
    int           apc_bat_low_voltage;
    int           apc_bat_high_voltage;
    int           apc_bat_low_temperature;
    int           apc_bat_high_temperature;
    char bbtx_trimI;
    char bbtx_trimQ;
    char bbtx_offsetI;
    char bbtx_offsetQ;
    unsigned char bbtx_isCalibrated;
} sBBTXParameters;

typedef struct
{
    sBBTXParameters BBTXParameters;
} l1cal_txiq_T;

typedef struct
{

    unsigned char bbtx_common_mode_voltage;
    unsigned char bbtx_gain;
    unsigned char bbtx_calrcsel;
    int           apc_bat_low_voltage;
    int           apc_bat_high_voltage;
    int           apc_bat_low_temperature;
    int           apc_bat_high_temperature;
    char bbtx_isCalibrated;
    char bbtx_trimI;
    char bbtx_trimQ;
    char bbtx_offsetI;
    char bbtx_offsetQ;
    char bbtx_phsel;
    // high band
    char bbtx_common_mode_voltage_h;
    char bbtx_gain_h;
    char bbtx_calrcsel_h;
    char bbtx_trimI_h;
    char bbtx_trimQ_h;
    char bbtx_offsetI_h;
    char bbtx_offsetQ_h;
    char bbtx_phsel_h;
} S_BBTXParameters_EX_T;

typedef struct
{
    S_BBTXParameters_EX_T BBTXParameters;
} S_L1CAL_TXIQ_EX_T;

// band setting
typedef struct
{
    unsigned char    band;
    unsigned char    arg1;
} nvram_ef_rac_preference_struct;

// port setting
typedef struct
{
    unsigned short         tst_port;
    unsigned short         ps_port;
    unsigned int           tst_baudrate;
    unsigned int           ps_baudrate;
    unsigned char          high_speed_sim_enabled;
    unsigned char          swdbg;
} nvram_ef_port_setting_struct;

typedef struct
{
    unsigned short         tst_port_ps;
    unsigned short         ps_port;
    unsigned int           tst_baudrate_ps;
    unsigned int           ps_baudrate;
    unsigned char          high_speed_sim_enabled;
    unsigned char          swdbg;
    unsigned char          tst_port_l1;
    unsigned int           tst_baudrate_l1;
} nvram_ef_port_setting_ex_struct;

//-----------------  IP2  -------------------------
// Skyworks 74045
typedef struct
{
    signed char     icorrection;
    signed char     qcorrection;
} c_RFMod_Sky74045_IP2_Coef;

typedef struct
{
    c_RFMod_Sky74045_IP2_Coef       coef[5/*band*/];
} c_RFMod_Sky74045_RX_Coef;

typedef struct
{
    c_RFMod_Sky74045_RX_Coef        rx;
} c_RFMod_Sky74045_Coef_T;

// Skyworks 74117
typedef struct
{
    signed char     icorrection;
    signed char     qcorrection;
} c_RFMod_Sky74117_IP2_Coef;

typedef struct
{
    c_RFMod_Sky74117_IP2_Coef       coef[5/*band*/];
} c_RFMod_Sky74117_RX_Coef;

typedef struct
{
    c_RFMod_Sky74117_RX_Coef        rx;
} c_RFMod_Sky74117_Coef_T;

// MT6139, MT6140
typedef struct
{
    unsigned char       acodeI;
    unsigned char       acodeQ;
    unsigned char       amcodeI;
    unsigned char       amcodeQ;
} uc_RFMod_MT6139_IP2_Coef;

typedef struct
{
    uc_RFMod_MT6139_IP2_Coef        coef[5/*band*/];
    unsigned char rxamcalmode;
} uc_RFMod_MT6139_RX_Coef;

typedef struct
{
    uc_RFMod_MT6139_RX_Coef     rx;
} uc_RFMod_MT6139_Coef_T;


typedef struct
{
    unsigned char dc_dac_ai;
    unsigned char dc_dac_aq;
    unsigned char auto_cal;
    unsigned char mode;
    unsigned char gain_table;
} MT6140_CW2;

//======================================================================
// BT common
#define BD_ADDR_LEN                      6

typedef struct
{
    unsigned char bd_addr[BD_ADDR_LEN];
} S_HANDSET_BT_ADRRESS;
typedef enum
{
    METAAPP_SUCCESS = 0,                           // Success
    METAAPP_GET_AVAILABLE_HANDLE_FAIL,             // get available handle fail
    METAAPP_OPEN_UART_FAIL,                        // open uart fail
    METAAPP_CLOSE_UART_FAIL,                        // open uart fail
    METAAPP_BOOT_FAIL,                             // boot fail
    METAAPP_BOOT_STOP_FAIL,                        // boot stop fail
    METAAPP_INIT_FAIL,                             // initialization fail
    METAAPP_WAIT_FOR_TARGET_READY_FAIL,            // wait for target ready fail
    METAAPP_COMM_SET_BAUD_RATE_FAIL,                // set baud rate fail.
    METAAPP_COMM_START_FAIL,                       // COMM start error
    METAAPP_COMM_STOP_FAIL,                        // COMM stop error
    METAAPP_COM_ERROR,                             // open com port fail
    METAAPP_CONNECT_WITH_TARGET_FAIL,              // Connect with target fail
    METAAPP_DISCONNECT_WITH_TARGET_FAIL,           // disconnect with target fail
    METAAPP_RF_SELECT_BAND_FAIL,                   // select band fail
    METAAPP_RF_SELECT_BAND_CNF_FAIL,               // select band cnf fail
    METAAPP_RF_AFC_MEASURE_FAIL,                   // AFC measure fail
    METAAPP_RF_AFC_MEASURE_CNF_FAIL,               // AFC measure cnf fail
    METAAPP_RF_AFC_SET_DAC_VALUE_FAIL,             // AFC set dac value fail
    METAAPP_RF_AFC_SET_DAC_VALUE_CNF_FAIL,         // AFC set dac value cnf fail
    METAAPP_RF_CRYSTALAFC_SET_CAPID_FAIL,          // Crystal AFC set cap id fail
    METAAPP_RF_PM_FAIL,                            // RF power measurement fail
    METAAPP_RF_NB_TX_FAIL,                         // RF NB TX fail
    METAAPP_RF_NB_TX_CNF_FAIL,                     // RF NB TX cnf fail
    METAAPP_RF_SET_APC_LEVEL_DAC_FAIL,             // RF set ramp apc level fail
    METAAPP_RF_SET_APC_LEVEL_DAC_CNF_FAIL,         // RF set ramp apc level cnf fail
    METAAPP_RF_STOP_FAIL,                          // RF stop fail
    METAAPP_RF_STOP_CNF_FAIL,                      // RF stop cnf fail
    METAAPP_RF_BBTXAUTOCAL_FAIL,                   // RF bbtx auto calibration fail
    METAAPP_RF_GETBBTXCFG2_FAIL,                   // RF get bbtx cfg2 fail
    METAAPP_RF_SETBBTXCFG2_FAIL,                   // RF set bbtx cfg2 fail
    METAAPP_RF_SETAFCSINEWAVEDETECT_FAIL,          // RF set sine wave detection fail
    METAAPP_RF_SET_MT6140CW2_TO_REG_FAIL,          // RF set MT6140 CW2 to register fail
    METAAPP_RF_GET_MT6140ACODE_FROM_REG_FAIL,      // RF Get MT6140 Acode from register fail
    METAAPP_RF_GET_RFID_FAIL,                      // RF Get RF ID fail
    METAAPP_RF_GET_IMMEIDATE_BSI_FAIL,             // RF get immediate BSI fail
    METAAPP_RF_SET_IMMEIDATE_BSI_FAIL,             // RF set immediate BSI fail
    METAAPP_RF_MULTISLOT_TX_FAIL,                  // RF multislot TX fail
    METAAPP_RF_EPSK_SET_APC_LEVEL_DAC_FAIL,        // RF EPSK set APC level DAC fail
    METAAPP_RF_BAND_NOT_SUPPORT_FAIL,              // RF band not support fail
    METAAPP_NVRAM_INIT_FAIL,                       // NVRAM init fail
    METAAPP_NVRAM_AFC_SLOPE_INVALID_FAIL,          // NVRAM AFC slope invalid fail
    METAAPP_NVRAM_AGC_PATHLOSS_LEN_FAIL,           // NVRAM AGC path loss length fail
    METAAPP_NVRAM_GET_REC_LEN_FAIL,                // NVRAM get rec length fail
    METAAPP_NVRAM_GET_RAMPTABLE_LEN_FAIL,          // NVRAM get ramp table length fail
    METAAPP_NVRAM_COMPOSE_AGC_PATHLOSS_FAIL,       // NVRAM compse AGC pathloss fail
    METAAPP_NVRAM_DECOMPOSE_AGC_PATHLOSS_FAIL,     // NVRAM decompse AGC pathloss fail
    METAAPP_NVRAM_COMPOSE_RAMPTABLE_FAIL,          // NVRAM compose ramp table fail
    METAAPP_NVRAM_DECOMPOSE_RAMPTABLE_FAIL,        // NVRAM decompose ramp table fail
    METAAPP_NVRAM_SET_REC_FIELD_VALUE_FAIL,        // NVRAM set rec field value fail
    METAAPP_NVRAM_GET_REC_FIELD_VALUE_FAIL,        // NVRAM get rec field value fail
    METAAPP_NVRAM_COMPOSE_ADC_CAL_TABLE_FAIL,      // NVRAM compose ADC cal table fail
    METAAPP_NVRAM_DECOMPOSE_ADC_CAL_TABLE_FAIL,    // NVRAM decompose ADC cal table fail
    METAAPP_NVRAM_COMPOSE_BARCODE_FAIL,            // NVRAM compose barcode fail
    METAAPP_NVRAM_DECOMPOSE_BARCODE_FAIL,          // NVRAM decompose barcode fail
    METAAPP_NVRAM_COMPOSE_IMEI_FAIL,                // NVRAM compose IMEI fail
    METAAPP_NVRAM_DECOMPOSE_IMEI_FAIL,              // NVRAM decompose IMEI fail
    METAAPP_NVRAM_COMPOSE_IP2_FAIL,                // NVRAM compose IP2 fail
    METAAPP_NVRAM_DECOMPOSE_IP2_FAIL,              // NVRAM decompose IP2 fail
    METAAPP_NVRAM_WRITE_FAIL,                      // NVRAM write fail
    METAAPP_NVRAM_WRITE_CNF_FAIL,                  // NVRAM write cnf fail
    METAAPP_NVRAM_READ_FAIL,                       // NVRAM read fail
    METAAPP_NVRAM_READ_CNF_FAIL,                   // NVRAM read cnf fail
    METAAPP_NVRAM_COMPOSE_SECURITY_FAIL,           // NVRAM compose security fail
    METAAPP_NVRAM_DECOMPOSE_SECURITY_FAIL,         // NVRAM decompose security fail
    METAAPP_NVRAM_GET_TXIQ_LEN_FAIL,               // NVRAM get TXIQ length fail
    METAAPP_NVRAM_COMPOSE_TXIQ_FAIL,             // NVRAM compose TXIQ fail
    METAAPP_NVRAM_DECOMPOSE_TXIQ_FAIL,             // NVRAM decompose TXIQ fail
    METAAPP_NVRAM_COMPOSE_SETTINGBAND_FAIL,        // NVRAM compose setting band fail
    METAAPP_NVRAM_DECOMPOSE_SETTINGBAND_FAIL,      // NVRAM decompose setting band fail
    METAAPP_NVRAM_COMPOSE_CUST_ACOUSTIC_FAIL,      // NVRAM compose cust acoustic fail
    METAAPP_NVRAM_DECOMPOSE_CUST_ACOUSTIC_FAIL,    // NVRAM decompose cust acoustic fail
    METAAPP_NVRAM_COMPOSE_BT_MT6601_INFO_FAIL,     // NVRAM compose MT6601 BT information fail
    METAAPP_NVRAM_DECOMPOSE_BT_MT6601_INFO_FAIL,   // NVRAM decompose MT6601 BT information fail
    METAAPP_NVRAM_COMPOSE_BT_RFMD3500_INFO_FAIL,   // NVRAM compose RFMD 3500 BT information fail
    METAAPP_NVRAM_DECOMPOSE_BT_RFMD3500_INFO_FAIL, // NVRAM decompose RFMD 3500 BT information fail
    METAAPP_NVRAM_LOCK_FAIL,                      // NVRAM lock fail
    METAAPP_NVRAM_DB_INCONSISTENT,                   // NVRAM DB inconsistent with target load
    METAAPP_FILE_READ_FAIL,                         // file read fail
    METAAPP_FILE_WRITE_FAIL,                        // file write fail
    METAAPP_IMEI_CALCULATE_CD_FAIL,                 // IMEI calculate CD fail
    METAAPP_ADC_READ_FROM_NVRAM_CNF_FAIL,          // ADC read from NVRAM cnf fail
    METAAPP_ADC_MEASURE_FAIL,                      // ADC measure fail
    METAAPP_ADC_MEASURE_CNF_FAIL,                  // ADC measure cnf fail
    METAAPP_BB_REG_READ_FAIL,                      // BB register read fail
    METAAPP_BB_REG_READ_CNF_FAIL,                  // BB reigster read cnf fail
    METAAPP_BB_REG_WRITE_FAIL,                     // BB register write fail
    METAAPP_BB_REG_WRITE_CNF_FAIL,                 // BB register write cnf fail
    METAAPP_GET_VERSION_INFO_FAIL,                 // Get target version info fail
    METAAPP_GET_VERSION_INFO_CNF_FAIL,             // Get target version info cnf fail
    METAAPP_FAT_OPEN_FAIL,                         // FAT open fail
    METAAPP_FAT_CLOSE_FAIL,                        // FAT close fail
    METAAPP_FAT_GET_FILE_SIZE_FAIL,                // FAT get file size fail
    METAAPP_FAT_READ_FAIL,                         // FAT read to buffer fail
    METAAPP_FAT_WRITE_FAIL,                        // FAT write by buffer fail
    METAAPP_FAT_READ_TO_FILE_FAIL,                 // FAT read to file fail
    METAAPP_FAT_WRITE_BY_FILE_FAIL,                // FAT write by file fail
    METAAPP_FAT_DELETE_FAIL,                       // FAT delete fail
    METAAPP_FAT_FIND_START_FAIL,                   // FAT find start fail
    METAAPP_FAT_FIND_HEAD_FAIL,                    // FAT find head fail
    METAAPP_FAT_FIND_PREV_FAIL,                    // FAT find previous fail
    METAAPP_FAT_FIND_NEXT_FAIL,                    // FAT find next fail
    METAAPP_FAT_FIND_GET_DISK_INFO_FAIL,           // FAT find get disk info fail
    METAAPP_FAT_GET_DISK_INFO_FAIL,                // FAT get disk info fail
    METAAPP_QUERY_TWO_APC_DC_OFFSET_SUPPORT_FAIL,  // Query two APC DC offset support fail
    METAAPP_WIFI_SET_REGDOMAIN_FAIL,               // WiFi set register domain fail
    METAAPP_WIFI_SET_TXPOWER_FAIL,                 // WiFi set TX power fail
    METAAPP_WIFI_CONTTX_FAIL,                      // WiFi continuous TX fail
    METAAPP_WIFI_CSM_FAIL,                         // WiFi carrier suppression measure fail
    METAAPP_WIFI_CONTPKTTX_FAIL,                   // WiFi continuous packet TX fail
    METAAPP_WIFI_QUERY_TX_STATUS_FAIL,             // WiFi query continuous packet TX status fail
    METAAPP_WIFI_CONTPKTRX_FAIL,                   // WiFi continuous packet RX fail
    METAAPP_WIFI_QUERY_RX_STATUS_FAIL,             // WiFi query RX status fail
    METAAPP_WIFI_QUERY_RX_COUNTER_FAIL,            // WiFi query RX counter fail
    METAAPP_WIFI_QUERY_CHIPCAP_FAIL,               // WiFi query chip capability fail
    METAAPP_WIFI_QUERY_CHANNELLIST_FAIL,           // WiFi query channel list fail
    METAAPP_WIFI_STOP_FAIL,                        // WiFi stop fail
    METAAPP_WIFI_MAC_ADDRESS_FORMAT_FAIL,          // WiFi MAC address format fail
    METAAPP_BT_ADDRESS_FORMAT_FAIL,                // BT address format error
    METAAPP_BT_QUERY_MODULE_ID_FAIL,               // BT query module ID fail
    METAAPP_TIMEOUT_FAIL,                           // timeout
    METAAPP_NVRAM_GET_LENGTH_FAIL,                  // [NVRAM common error]: Get some specific structure from NVRAM database fail
    METAAPP_NVRAM_DECOMPOSE_FAIL_AFTER_READ,         // [NVRAM common error]: Decompose buffer after read NVRAM data from phone's NVRAM
    METAAPP_NVRAM_COMPOSE_FAIL_BEFORE_WRITE,         // [NVRAM common error]: Compose buffer before write NVRAM data to phone's NVRAM
    METAAPP_INVALID_PARAMETER,                      // invalid input parameter
    METAAPP_WCDMA_GET_PHASE_COMP_FAIL               // WCDMA, get phase compensation fail

} METAAPP_RESULT;


//******************************************************************************
//*****************            export function            **********************
//******************************************************************************
// get handle
DLLEXPORT METAAPP_RESULT  CALL_CONVENTION      METAAPP_GetAvailableHandle(int* p_meta_handle);


// initialization
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_ConnectWithTarget(int meta_handle, META_Connect_Req*  req, int* p_bootstop, META_Connect_Report*  p_report);
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_DisconnectWithTarget(int meta_handle);
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_Init( int meta_handle );
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_DeInit( int meta_handle );

// NVRAM general
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_NVRAM_Init( const int meta_handle, const char* PathName );
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_NVRAM_Lock( const int meta_handle, const unsigned int ms_timeout );
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_NVRAM_Read(const int meta_handle, const unsigned int ms_timeout, const FT_NVRAM_READ_REQ* p_req, unsigned char* buf, unsigned int    len);
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_NVRAM_Write(const int meta_handle, const unsigned int ms_timeout, const FT_NVRAM_WRITE_REQ* p_req);


// RF general
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_Rf_GetRFID(const int meta_handle, unsigned int ms_timeout, RFMod_ID* cnf);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_GetRFImmediateBSI(const int meta_handle, unsigned int ms_timeout, const unsigned int bsi_data, unsigned int* p_bsi_data);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_SetRFImmediateBSI(const int meta_handle, unsigned int ms_timeout, const unsigned int bsi_data);

// AFC
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_Rf_AFC(const int meta_handle, int timeout, BAND band, const RfAfc_Req* req, RfAfc_Cnf* cnf );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_getAFCSlopeAndOffset(const int meta_handle, BAND band, ARFCN arfcn, short AFCDAC1, short AFCDAC2, Gain gain, short testNumber, int timeout, bool* AfcSlopeOffsetValid, int* p_InitAfcDac, float* p_AfcSlope );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_SetAfcDacValue(const int meta_handle, short dacValue, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readAFCfromNVRAM(const int meta_handle, int timeout, int* p_InitAfcDac, float* p_AfcSlope);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeAFCtoNVRAM(const int meta_handle, int InitAfcDac, float AfcSlope, int timeout );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_ReadAFCfromFile( const int meta_handle, char* filename, int* p_InitAfcDac, float* p_AfcSlope );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WriteAFCToFile( const int meta_handle, char* filename, int InitAfcDac, float AfcSlope );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_Rf_SetAfcSinWaveDetection( const int meta_handle, unsigned int ms_timeout, AFC_SINWAVE_DETECTION_E  bIsAfcSinWaveOn);

// Crystal AFC
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_Rf_SetCrystalCapId( const int meta_handle, const RfSetCrystalCfg_Req*  req, unsigned int ms_timeout );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readCapIdfromNVRAM(const int meta_handle, int timeout, int* p_cap_id );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeCapIdtoNVRAM( const int meta_handle, int cap_id, int timeout );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_ReadCapIdfromFile( const int meta_handle, char* filename, int* p_cap_id );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WriteCapIdToFile( const int meta_handle, char* filename, int cap_id );

// RX path loss
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_PM(const int meta_handle, BAND band, ARFCN arfcn, char sampleNoPerFrame, Gain gain, short frames, int timeout,
        int* p_power, int* p_deviation, Gain* p_usedGain, RfPmExtraInfo_T* p_extra_info);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readAgcFromNVRAM(const int meta_handle, int timeout, l1cal_agcPathLoss_T* p_AgcPathLoss);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeAgcToNVRAM(const int meta_handle, l1cal_agcPathLoss_T* p_AgcPathLoss, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readAgcFromFile( const int meta_handle, char* filename, l1cal_agcPathLoss_T* P_AgcPathLoss );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeAgcToFile( const int meta_handle, char* filename, l1cal_agcPathLoss_T* p_AgcPathLoss );

// IP2
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_Read_Sky74045_IP2_From_NVRAM(const int meta_handle, int timeout, RF_SKY74045_Coef_T* p_coef );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_Write_Sky74045_IP2_To_NVRAM(const int meta_handle, RF_SKY74045_Coef_T* coef, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readSky74045IP2FromFile( const int meta_handle, char* filename,  c_RFMod_Sky74045_Coef_T* p_coef );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeSky74045IP2ToFile( const int meta_handle, char* filename,  c_RFMod_Sky74045_Coef_T* p_coef );

DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_Read_Sky74117_IP2_From_NVRAM(const int meta_handle, int timeout, RF_SKY74117_Coef_T* p_coef );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_Write_Sky74117_IP2_To_NVRAM(const int meta_handle, RF_SKY74117_Coef_T* coef, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readSky74117IP2FromFile( const int meta_handle, char* filename,  c_RFMod_Sky74117_Coef_T* p_coef );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeSky74117IP2ToFile( const int meta_handle, char* filename,  c_RFMod_Sky74117_Coef_T* p_coef );

DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_Read_MT6140_IP2_From_NVRAM(const int meta_handle, int timeout, RF_MT6139B_Coef_T* p_coef );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_Write_MT6140_IP2_To_NVRAM(const int meta_handle, RF_MT6139B_Coef_T* coef, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readMT6140FromFile( const int meta_handle, char* filename, uc_RFMod_MT6139_Coef_T* p_coef );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeMT6140IP2ToFile( const int meta_handle, char* filename, uc_RFMod_MT6139_Coef_T* p_coef );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_GetMT6140AcodeFromReg(const int meta_handle, unsigned char* p_acodeI,
        unsigned char* p_acodeQ, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_SetMT6140CW2ToReg(const int meta_handle, MT6140_CW2* p_mt6140_cw2, int timeout);

// APC
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_Rf_QueryIfTwoApcDCOffsetSupport(const int meta_handle, bool* TwoAPcDcOffsetSupport, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_RF_NB_TX(const int meta_handle, BAND band, ARFCN arfcn, char c_TSC, int pcl, int i_N_TX, unsigned short us_Default_value, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_RF_NB_TX_Ex(const int meta_handle, BAND band, ARFCN arfcn, char c_TSC, int pcl, int i_N_TX, unsigned short us_Default_value, APCTxPattern burstTypeNB, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_RF_ApcSetLevelDac(const int meta_handle, FrequencyBand band, int power_level, int apc_dac, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readAPCfromNVRAM(const int meta_handle, BAND band, int timeout, int* ApcDcOffset, l1cal_rampTable_T*  p_ApcProfile);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeAPCtoNVRAM(const int meta_handle, BAND band, int ApcDcOffset, l1cal_rampTable_T* p_ApcProfile, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readAPCfromFile( const int meta_handle, BAND band, char* filename, int* ApcDcOffset, l1cal_rampTable_T*  p_ApcProfile );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WriteAPCtoFile( const int meta_handle, BAND band, char* filename, int ApcDcOffset, l1cal_rampTable_T*  p_ApcProfile);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readAPCfromNVRAM_Ex(const int meta_handle, BAND band, int timeout, int* HiApcDcOffset, int* LowApcDcOffset, int* ApcLowestPower, l1cal_rampTable_T*  p_ApcProfile);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeAPCtoNVRAM_Ex(const int meta_handle, BAND band, int HiApcDcOffset, int LowApcDcOffset, int ApcLowestPower, l1cal_rampTable_T* p_ApcProfile, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readAPCfromFile_Ex( const int meta_handle, BAND band, char* filename, int* HiApcDcOffset, int* LowApcDcOffset, int* ApcLowestPower, l1cal_rampTable_T*  p_ApcProfile );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WriteAPCtoFile_Ex( const int meta_handle, BAND band, char* filename, int HiApcDcOffset, int LowApcDcOffset, int ApcLowestPower, l1cal_rampTable_T*  p_ApcProfile);
// EPSK APC
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_RF_MultiSlot_TX_Ex(const int meta_handle, const BAND band, const Rf_MultiSlotTXEx_Req* req, const int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_RF_EPSK_ApcSetLevelDac(const int meta_handle, FrequencyBand band, const int power_level, const int apc_dac, const int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readEpskAPCfromNVRAM(const int meta_handle, BAND band, int timeout, l1cal_rampTable_T*  p_ApcProfile);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeEpskAPCtoNVRAM(const int meta_handle, BAND band, l1cal_rampTable_T* p_ApcProfile, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readEpskAPCfromFile( const int meta_handle, BAND band, char* filename, l1cal_rampTable_T*  p_ApcProfile );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WriteEpskAPCtoFile( const int meta_handle, BAND band, char* filename, l1cal_rampTable_T*  p_ApcProfile);


DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readEpskAPCfromNVRAM_Ex(const int meta_handle, BAND band, int timeout, int* p_iHiApcDcOffset, unsigned char* p_ucInterSlotLowestDac, l1cal_rampTable_T*  p_ApcProfile);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeEpskAPCtoNVRAM_Ex(const int meta_handle, BAND band, int HiApcDcOffset, unsigned char ucInterSlotLowestDac, l1cal_rampTable_T* p_ApcProfile, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readEpskAPCfromFile_Ex( const int meta_handle, BAND band, char* filename, unsigned char* p_ucInterSlotLowestDac, l1cal_rampTable_T*  p_ApcProfile );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WriteEpskAPCtoFile_Ex( const int meta_handle, BAND band, char* filename, unsigned char ucInterSlotLowestDac, l1cal_rampTable_T*  p_ApcProfile);

// EPSK Inter Slot Ramp profile
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readEpskInterSlotRampfromNVRAM(const int meta_handle, BAND band, int timeout, l1cal_EPSK_interRampData_T*  p_EpskInterSlotRampProfile);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeEpskInterSlotRamptoNVRAM(const int meta_handle, BAND band, l1cal_EPSK_interRampData_T* p_EpskInterSlotRampProfile, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readEpskInterSlotRampfromFile( const int meta_handle, BAND band, char* filename, l1cal_EPSK_interRampData_T*  p_EpskInterSlotRampProfile );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WriteEpskInterSlotRamptoFile( const int meta_handle, BAND band, char* filename, l1cal_EPSK_interRampData_T*  p_EpskInterSlotRampProfile);


// GPRS Inter Slot profile
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readGprsInterSlotRampfromNVRAM(const int meta_handle, BAND band, int timeout, l1cal_interRampData_T*  p_GprsInterSlotRampProfile);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeGprsInterSlotRamptoNVRAM(const int meta_handle, BAND band, l1cal_interRampData_T* p_GprsInterSlotRampProfile, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readGprsInterSlotRampfromFile( const int meta_handle, BAND band, char* filename, l1cal_interRampData_T*  p_GprsInterSlotRampProfile );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WriteGprsInterSlotRamptoFile( const int meta_handle, BAND band, char* filename, l1cal_interRampData_T*  p_GprsInterSlotRampProfile);


// Vbias
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_Read_Vbias_From_NVRAM(const int meta_handle, int timeout, mt6140tx* p_coef);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_Write_Vbias_To_NVRAM(const int meta_handle, mt6140tx* p_coef, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readVbiasFromFile(const int meta_handle, char* filename, mt6140tx* p_coef);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeVbiasToFile(const int meta_handle, char* filename, mt6140tx* p_coef);

// RF stop
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_RF_Select_Band(const int meta_handle, BAND band, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_RF_STOP( const int meta_handle, int timeout );
// ADC
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_MeasureADC( const int meta_handle, int ADCChannel, int MeasureCount, int timeout, BBCHIP_TYPE bb_chip, ADCMeaData_Cnf* cnf);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readADCfromNVRAM(const int meta_handle, int timeout, BBCHIP_TYPE bb_chip, bmt_adcdata* p_adcdata);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeADCtoNVRAM(const int meta_handle, int timeout, BBCHIP_TYPE bb_chip, bmt_adcdata* p_adcdata);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readADCfromFile( const int meta_handle, char* filename, BBCHIP_TYPE bb_chip, bmt_adcdata* p_adcdata);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WriteADCtoFile( const int meta_handle, char* filename, BBCHIP_TYPE bb_chip, bmt_adcdata* p_adcdata);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_GetADCChnNumfromNVRAMDB(const int meta_handle, int timeout, int* p_adc_chn_num);



// BB register
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_BB_RegRead( const int meta_handle, const unsigned int ms_timeout, const RegRead_Req* req, unsigned short* p_reg_value);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_BB_RegWrite( const int meta_handle, const unsigned int ms_timeout, const RegWrite_Req* req);

// barcode
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readBarcodefromNVRAM( const int meta_handle, int timeout, char* p_Barcode );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeBarcodetoNVRAM( const int meta_handle, char* p_Barcode, int timeout );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readBarcodefromFile( const int meta_handle, char* filename, char* p_barcode);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WriteBarcodetoFile( const int meta_handle, char* filename,  char* p_barcode);

// IMEI
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_Calcualte_IMEI_Spare(const int meta_handle, char* p_imei, unsigned short* p_spare);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readIMEIfromNVRAM(const int meta_handle, int timeout, IMEISV_struct_T* p_IMEISV);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeIMEItoNVRAM(const int meta_handle, IMEISV_struct_T* p_IMEISV, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeIMEItoNVRAM_Ex(const int meta_handle, IMEISV_struct_T* p_IMEISV, bool NVRAM_lock, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeIMEItoNVRAM_Ex2(const int meta_handle, IMEISV_struct_T* p_IMEISV, bool b_check_checksum, bool b_NVRAM_lock, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readIMEIfromNVRAM_Ex3(const int meta_handle, const int timeout, unsigned short rid, IMEISV_struct_T* p_IMEISV);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeIMEItoNVRAM_Ex3(const int meta_handle, const int timeout, bool b_check_checksum, bool b_NVRAM_lock, unsigned short rid, IMEISV_struct_T* p_IMEISV);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readIMEIfromFile(const int meta_handle, char* filename, char* p_IMEI);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WriteIMEItoFile(const int meta_handle, char* filename,  char* p_IMEI);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readIMEI2fromFile(const int meta_handle, char* filename, char* p_IMEI);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WriteI2MEItoFile(const int meta_handle, char* filename, char* p_IMEI);

// security
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readSecurityfromNVRAM( const int meta_handle, int timeout, s_security_info_struct* p_Security);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeSecuritytoNVRAM( const int meta_handle, s_security_info_struct* p_Security, int timeout );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readSecurityfromFile( const int meta_handle, char* filename, s_security_info_struct* p_Security);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WriteSecuritytoFile( const int meta_handle, char* filename,  s_security_info_struct* p_Security);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readSecurityfromNVRAM_Ex(const int meta_handle, int timeout, unsigned short rid, s_security_info_struct* p_Security);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeSecuritytoNVRAM_Ex(const int meta_handle, unsigned short rid, s_security_info_struct* p_Security, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readSecurity2fromFile(const int meta_handle, char* filename, s_security_info_struct* p_Security);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WriteSecurity2toFile( const int meta_handle, char* filename,  s_security_info_struct* p_Security);



DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readSecurityfromNVRAM_Ex2( const int meta_handle, int timeout, s_security_info_struct_ex* p_Security);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeSecuritytoNVRAM_Ex2( const int meta_handle, s_security_info_struct_ex* p_Security, int timeout );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readSecurityfromFile_Ex2( const int meta_handle, char* filename, s_security_info_struct_ex* p_Security);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WriteSecuritytoFile_Ex2( const int meta_handle, char* filename,  s_security_info_struct_ex* p_Security);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readSecurityfromNVRAM_Ex_Ex2(const int meta_handle, int timeout, unsigned short rid, s_security_info_struct_ex* p_Security);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeSecuritytoNVRAM_Ex_Ex2(const int meta_handle, unsigned short rid, s_security_info_struct_ex* p_Security, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readSecurity2fromFile_Ex2(const int meta_handle, char* filename, s_security_info_struct_ex* p_Security);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WriteSecurity2toFile_Ex2( const int meta_handle, char* filename,  s_security_info_struct_ex* p_Security);



// COM stop
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_COMM_Stop( int meta_handle );

// Get target version
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION  METAAPP_GetTargetVerInfo( const int meta_handle, int timeout, VerInfo_Cnf* p_verinfo );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_ReadVersionfromFile( const int meta_handle, char* filename, VerInfo_Cnf* p_VerInfoCnf );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION  METAAPP_WriteVersionToFile( const int meta_handle, char* filename, VerInfo_Cnf* p_VerInfoCnf );

// get DLL version
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION  METAAPP_GetMETADllVersion( const int meta_handle, char* p_dllver );
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION  METAAPP_GetMETAAPPDllVersion( const int meta_handle, char* p_dllver );
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION  METAAPP_GetBROMDllVersion( const int meta_handle, char* p_dllver );

// TXIQ
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_Rf_BBTXAutoCal( const int meta_handle, int timeout );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_Rf_GetBBTxCfg2( const int meta_handle, int timeout,  RfBBTXCfg2*  tx_cfg_cnf);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_Rf_SetBBTxCfg2( const int meta_handle, int timeout,  const RfBBTXCfg2*  tx_cfg_req, RfBBTXCfg2*  tx_cfg_cnf);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readTxIQfromNVRAM(const int meta_handle, int timeout, l1cal_txiq_T*  p_txiq);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeTxIQtoNVRAM(const int meta_handle, l1cal_txiq_T*  p_txiq, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readTxIQfromFile( const int meta_handle, char* filename, l1cal_txiq_T*  p_txiq );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WriteTxIQtoFile( const int meta_handle, char* filename, l1cal_txiq_T*  p_txiq);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readTxIQfromNVRAM_Ex(const int meta_handle, int timeout, S_L1CAL_TXIQ_EX_T*  p_txiq);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeTxIQtoNVRAM_Ex(const int meta_handle, S_L1CAL_TXIQ_EX_T*  p_txiq, int timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readTxIQfromFile_Ex( const int meta_handle, char* filename, S_L1CAL_TXIQ_EX_T*  p_txiq );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WriteTxIQtoFile_Ex( const int meta_handle, char* filename, S_L1CAL_TXIQ_EX_T*  p_txiq);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readTxIQfromNVRAM_Ex2(const int meta_handle, const int timeout, BBTXParameters_T*  p_txiq);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeTxIQtoNVRAM_Ex2(const int meta_handle, BBTXParameters_T* p_txiq, const int timeout);

// band setting
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readSettingBandfromNVRAM( const int meta_handle, int timeout, nvram_ef_rac_preference_struct*  p_rac_preference);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeSettingBandtoNVRAM( const int meta_handle, nvram_ef_rac_preference_struct*  p_rac_preference, int timeout );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readSettingBandfromFile( const int meta_handle, char* filename, unsigned char* p_band);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WriteSettingBandtoFile( const int meta_handle, char* filename,  unsigned char*  p_band);

// port setting
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readPortSettingfromNVRAM(const int meta_handle, int timeout, nvram_ef_port_setting_struct* p_port_seting);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writePortSettingtoNVRAM(const int meta_handle, int timeout, nvram_ef_port_setting_struct* p_port_seting);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_ReadPortSettingfromFile(const int meta_handle, char* filename, nvram_ef_port_setting_struct* p_port_seting);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WritePortSettingToFile(const int meta_handle, char* filename, nvram_ef_port_setting_struct* p_port_seting);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readPortSettingfromNVRAM_Ex(const int meta_handle, int timeout, nvram_ef_port_setting_ex_struct* p_port_seting);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writePortSettingtoNVRAM_Ex(const int meta_handle, int timeout, nvram_ef_port_setting_ex_struct* p_port_seting);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_ReadPortSettingfromFile_Ex(const int meta_handle, char* filename, nvram_ef_port_setting_ex_struct* p_port_seting);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WritePortSettingToFile_Ex(const int meta_handle, char* filename, nvram_ef_port_setting_ex_struct* p_port_seting);

// custom acoustic volume
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readCustAcstfromNVRAM(const int meta_handle, int timeout, CustAcousticVol_T* p_CustAcousticVol);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeCustAcsttoNVRAM(const int meta_handle, int timeout, CustAcousticVol_T* p_CustAcousticVol);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_readCustAcstfromFile( const int meta_handle, char* filename, CustAcousticVol_T* p_CustAcousticVol);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_writeCustAcsttoFile( const int meta_handle, char* filename, CustAcousticVol_T* p_CustAcousticVol);

// FAT
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_FAT_Open(const int meta_handle, const char* fat_filepath, FAT_OPEN_MODE  mode, int* fs_handle);
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_FAT_Close( const int meta_handle, int* fs_handle );
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_FAT_GetFileSize( const int meta_handle, const int fs_handle, int* filesize );
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_FAT_Read(const int meta_handle, const unsigned int ms_timeout, const int fs_handle, char* buf, const int len );
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_FAT_Write(const int meta_handle, const unsigned int ms_timeout, const int fs_handle, char* buf, const int len );
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_FAT_Read_To_File(const int meta_handle, const unsigned int ms_timeout, const int fs_handle, const char* local_filepath );
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_FAT_Write_By_File(const int meta_handle, const unsigned int ms_timeout, const int fs_handle, const char* local_filepath );
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_FAT_Delete(const int meta_handle, const char* fat_filepath );
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_FAT_Find_Start(const int meta_handle, const char* fat_base_dir, const char* fat_find_pattern, FAT_FIND_MODE   find_mode, int* p_find_handle );
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_FAT_Find_Head( const int meta_handle, int find_handle );
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_FAT_Find_Prev( const int meta_handle, int find_handle );
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_FAT_Find_Next( const int meta_handle, int find_handle );
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_FAT_Find_GetFileInfo(const int meta_handle, int find_handle, char* p_filepath, const int filepath_len, int* p_filesize);
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_FAT_Find_Close(const int meta_handle, int* p_find_handle);
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_FAT_GetDiskInfo(const int meta_handle, const char DriveLetter, FAT_DiskInfo_T*  p_DiskInfo);

// WiFi
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_QueryChipCapability(const int meta_handle, unsigned int  ms_timeout, WiFi_ChipCapability_S*  cnf);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_QueryChannelList(const int meta_handle, unsigned int  ms_timeout, WiFi_ChannelList_S* cnf);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_SetTxPower2400M(const int meta_handle, unsigned int  ms_timeout, const WiFi_TxPower_2400M_S*  txpwr);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_SetTxPower5000M(const int meta_handle, unsigned int  ms_timeout, const WiFi_TxPower_5000M_S*  txpwr);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_ContTx(const int meta_handle, unsigned int  ms_timeout, const WiFi_RegDomain_S*  reg_domain_req, const WiFi_TestTx_S* tx_req);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_CarrierSuppressionMeasure(const int meta_handle, unsigned int  ms_timeout, const WiFi_RegDomain_S*  reg_domain_req, const WiFi_TestTx_S* tx_req);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_ContPktTx(const int meta_handle, unsigned int  ms_timeout, const WiFi_RegDomain_S*  reg_domain_req, const WiFi_TestPktTx_S* pkt_tx_req);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_QueryTxStatus(const int meta_handle, unsigned int  ms_timeout, WiFi_TxStatus_S* cnf);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_ContPktRx(const int meta_handle, unsigned int  ms_timeout, const WiFi_TestPktRx_S* req);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_QueryRxStatus(const int meta_handle, unsigned int  ms_timeout, WiFi_RxStatus_S* cnf);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_QueryRxCounter(const int meta_handle, unsigned int  ms_timeout, WiFi_RxCounter_S* cnf);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_Stop(const int meta_handle, unsigned int  ms_timeout);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_readTxPower2400MfromNVRAM(const int meta_handle, int timeout, WiFi_TxPower_2400M_S*  pTxPower2400M);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_writeTxPower2400MtoNVRAM(const int meta_handle, WiFi_TxPower_2400M_S*  pTxPower2400M, int timeout );
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_readTxPower2400MfromFile(const int meta_handle, char* filename, WiFi_TxPower_2400M_S*  pTxPower2400M);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_writeTxPower2400MtoFile(const int meta_handle, char* filename, WiFi_TxPower_2400M_S*  pTxPower2400M);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_readTxDcOffsetFromNVRAM(const int meta_handle, const int timeout, WiFi_DAC_DC_Offset_S*  psTxDcOffset);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_writeTxDcOffsetToNVRAM(const int meta_handle, const int timeout, WiFi_DAC_DC_Offset_S*  psTxDcOffset);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_readTxDcOffsetFromFile(const int meta_handle, char* filename, WiFi_DAC_DC_Offset_S* psTxDcOffset);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_writeTxDcOffsetToFile(const int meta_handle, char* filename, WiFi_DAC_DC_Offset_S* psTxDcOffset);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_readWiFiMacAddressFromNVRAM(const int meta_handle, int timeout, WiFi_MacAddress_S* p_wifi_mac_addr);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_writeWiFiMacAddressToNVRAM(const int meta_handle, int timeout, WiFi_MacAddress_S* p_wifi_mac_addr);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_ReadWiFiMacAddressFromFile(const int meta_handle, char* filename, WiFi_MacAddress_S* p_wifi_mac_addr);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_WriteWiFiMacAddressToFile(const int meta_handle, char* filename, WiFi_MacAddress_S* p_wifi_mac_addr);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_readWiFiAlcPowerFromNVRAM(const int meta_handle, int timeout, WiFi_ALC_2400M_S* p_wifi_alc_power);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_writeWiFiAlcPowerToNVRAM(const int meta_handle, int timeout, WiFi_ALC_2400M_S* p_wifi_alc_power);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_ReadWiFiAlcPowerFromFile(const int meta_handle, char* filename, WiFi_ALC_2400M_S* p_wifi_alc_power);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_WriteWiFiAlcPowerToFile(const int meta_handle, char* filename, WiFi_ALC_2400M_S* p_wifi_alc_power);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_readWiFiAlcSlopeFromNVRAM(const int meta_handle, int timeout, WiFi_TxALC_2400M_S* p_wifi_alc_slope);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_writeWiFiAlcSlopeToNVRAM(const int meta_handle, int timeout, WiFi_TxALC_2400M_S* p_wifi_alc_slope);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_ReadWiFiAlcSlopeFromFile(const int meta_handle, char* filename, WiFi_TxALC_2400M_S* p_wifi_alc_slope);
DLLEXPORT  METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_WriteWiFiAlcSlopeToFile(const int meta_handle, char* filename, WiFi_TxALC_2400M_S* p_wifi_alc_slope);

// BT
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_BT_readMT6601BTAddrfromNVRAM(const int meta_handle, int timeout, S_HANDSET_BT_ADRRESS* p_bt_addr);
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_BT_writeMT6601BTAddrtoNVRAM(const int meta_handle, int timeout, S_HANDSET_BT_ADRRESS* p_bt_addr);
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_BT_ReadMT6601BTAddrfromFile(const int meta_handle, char* filename, S_HANDSET_BT_ADRRESS* p_bt_addr);
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_BT_WriteMT6601BTAddrToFile(const int meta_handle, char* filename, S_HANDSET_BT_ADRRESS* p_bt_addr);
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_BT_ReadMT6601CapIdfromNVRAM(const int meta_handle, int timeout, unsigned char* p_cap_id);
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_BT_WriteMT6601CapIdtoNVRAM(const int meta_handle, int timeout, unsigned char cap_id);
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_BT_ReadMT6601CapIdfromFile(const int meta_handle, char* filename, unsigned char* p_cap_id);
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_BT_WriteMT6601CapIdToFile(const int meta_handle, char* filename, unsigned char cap_id);
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_BT_readRFMD3500BTAddrfromNVRAM(const int meta_handle, int timeout, S_HANDSET_BT_ADRRESS* p_bt_addr);
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_BT_writeRFMD3500BTAddrtoNVRAM(const int meta_handle, int timeout, S_HANDSET_BT_ADRRESS* p_bt_addr);
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_BT_ReadRFMD3500BTAddrfromFile(const int meta_handle, char* filename, S_HANDSET_BT_ADRRESS* p_bt_addr);
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_BT_WriteRFMD3500BTAddrToFile(const int meta_handle, char* filename, S_HANDSET_BT_ADRRESS* p_bt_addr);


typedef struct
{
    S_HANDSET_BT_ADRRESS  bt_addr;
    unsigned char Cap_Id;
} METAAPP_BT_INFO_T;

/*
     Chip ID   ,    LID_Name
BTMODULE_MT6611 NVRAM_EF_BTRADIO_MT6611_LID
BTMODULE_MT6612 NVRAM_EF_BTRADIO_MT6612_LID
BTMODULE_MT6616 NVRAM_EF_BTRADIO_MT6616_LID
BTMODULE_MT6236 NVRAM_EF_BTRADIO_MT6236_LID
*/
DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_BT_ReadBTInfofromNVRAM(const int meta_handle,
        int timeout,
        const char* LID_Name,
        METAAPP_BT_INFO_T* p_bt_info);

DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_BT_writeInfotoNVRAM(const int meta_handle,
        int timeout,
        const char* LID_Name,
        METAAPP_BT_INFO_T* p_bt_info);


DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_BT_ReadInfofromFile( const int meta_handle, char* filename, METAAPP_BT_INFO_T* p_bt_info);
DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_BT_WriteInfoToFile( const int meta_handle, char* filename, METAAPP_BT_INFO_T* p_bt_info);


DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_AFC_ReadCrystalDatafromNVRAM(const int meta_handle,
        const int timeout, l1cal_crystalAfcData_T* afc_data);
DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_AFC_writeCrystalDatatoNVRAM(const int meta_handle,
        const int timeout,
        const l1cal_crystalAfcData_T* afc_data);
DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_AFC_ReadCrystalDatafromFile( const int meta_handle, const char* filename, l1cal_crystalAfcData_T* afc_data);
DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_AFC_WriteCrystalDataToFile( const int meta_handle, const char* filename, const l1cal_crystalAfcData_T* afc_data);


// For MT5921

typedef struct // LID: NVRAM_EF_WNDRV_EXT_SETTING_TRIMVAL_THERMOVAL_LID
{
    //char           cAbsTemp;
    unsigned char  ucThermoValue;
    unsigned char  ucXtalTrim;
} METAAPP_WiFi_CrystalInfo_T; // partial of wndrv_cal_setting_trim_thermo_struct

DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_ReadCrystalInfofromNVRAM(const int meta_handle,
        const int timeout, METAAPP_WiFi_CrystalInfo_T* data);
DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_WriteCrystalInfotoNVRAM(const int meta_handle,
        const int timeout,
        const METAAPP_WiFi_CrystalInfo_T* data);
DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_ReadCrystalInfofromFile( const int meta_handle, const char* filename, METAAPP_WiFi_CrystalInfo_T* data);
DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_WiFi_WriteCrystalInfoToFile( const int meta_handle, const char* filename, const METAAPP_WiFi_CrystalInfo_T* data);




#ifdef __META_DLL_WCDMA__

DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_WCDMA_ReadTempADCfromNVRAM(const int meta_handle,
        const int timeout, ul1cal_tempdacData_T* dac);
DLLEXPORT   METAAPP_RESULT CALL_CONVENTION METAAPP_WCDMA_WriteTempADCtoNVRAM(const int meta_handle,
        const int timeout,
        const ul1cal_tempdacData_T* dac);
DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_WCDMA_ReadTempADCfromFile( const int meta_handle, const char* filename, ul1cal_tempdacData_T* dac);
DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_WCDMA_WriteTempADCToFile( const int meta_handle, const char* filename, const ul1cal_tempdacData_T* dac);

/*
NVRAM_EF_UL1_PATHLOSS_BAND1_LID
NVRAM_EF_UL1_PATHLOSS_BAND2_LID
NVRAM_EF_UL1_PATHLOSS_BAND3_LID
NVRAM_EF_UL1_PATHLOSS_BAND4_LID
NVRAM_EF_UL1_PATHLOSS_BAND5_LID
NVRAM_EF_UL1_PATHLOSS_BAND6_LID
NVRAM_EF_UL1_PATHLOSS_BAND7_LID
NVRAM_EF_UL1_PATHLOSS_BAND8_LID
NVRAM_EF_UL1_PATHLOSS_BAND9_LID
NVRAM_EF_UL1_PATHLOSS_BAND10_LID
*/

DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_WCDMA_ReadRxPathLossfromNVRAM(const int meta_handle,
        const int timeout,
        const char* LID_Name, ul1cal_pathlossData_T* pathloss);

DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_WCDMA_WriteRxPathLosstoNVRAM(const int meta_handle,
        const int timeout, const char* LID_Name,
        const ul1cal_pathlossData_T* pathloss);
DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_WCDMA_ReadRxPathLossfromFile( const int meta_handle,
        const char* filename,
        const int band, // 1~10
        ul1cal_pathlossData_T* pathloss);
DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_WCDMA_WriteRxPathLossToFile( const int meta_handle,
        const char* filename,
        const int band, // 1~10
        const ul1cal_pathlossData_T* pathloss);

/*
NVRAM_EF_UL1_TXDAC_BAND1_LID
NVRAM_EF_UL1_TXDAC_BAND2_LID
NVRAM_EF_UL1_TXDAC_BAND3_LID
NVRAM_EF_UL1_TXDAC_BAND4_LID
NVRAM_EF_UL1_TXDAC_BAND5_LID
NVRAM_EF_UL1_TXDAC_BAND6_LID
NVRAM_EF_UL1_TXDAC_BAND7_LID
NVRAM_EF_UL1_TXDAC_BAND8_LID
NVRAM_EF_UL1_TXDAC_BAND9_LID
NVRAM_EF_UL1_TXDAC_BAND10_LID
*/
DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_WCDMA_ReadTpcfromNVRAM(const int meta_handle,
        const int timeout,
        const char* LID_Name,
        ul1cal_txdacData_T_B* txdac);

DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_WCDMA_WriteTpctoNVRAM(const int meta_handle,
        const int timeout, const char* LID_Name,
        const ul1cal_txdacData_T_B* txdac);
DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_WCDMA_ReadTpcfromFile( const int meta_handle,
        const char* filename,
        const int band, // 1~10
        ul1cal_txdacData_T_B* txdac);
DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_WCDMA_WriteTpcToFile( const int meta_handle,
        const char* filename,
        const int band, // 1~10
        const ul1cal_txdacData_T_B* txdac);

/* PA control */
/*
NVRAM_EF_UL1_TXPAOCTLEV_BAND1_LID
NVRAM_EF_UL1_TXPAOCTLEV_BAND2_LID
NVRAM_EF_UL1_TXPAOCTLEV_BAND3_LID
NVRAM_EF_UL1_TXPAOCTLEV_BAND4_LID
NVRAM_EF_UL1_TXPAOCTLEV_BAND5_LID
NVRAM_EF_UL1_TXPAOCTLEV_BAND6_LID
NVRAM_EF_UL1_TXPAOCTLEV_BAND7_LID
NVRAM_EF_UL1_TXPAOCTLEV_BAND8_LID
NVRAM_EF_UL1_TXPAOCTLEV_BAND9_LID
NVRAM_EF_UL1_TXPAOCTLEV_BAND10_LID
*/
/**
 * Read pa control parameters from nvram by LID name
 **/
DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_WCDMA_ReadPaControlfromNVRAM(const int meta_handle,
        const int timeout,
        const char* LID_Name,
        ul1cal_txPaOctLevData_T* sWcdmaPaOctLevData);
/**
 * Write pa control parameters to nvram by LID name
 **/
DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_WCDMA_WritePaControltoNVRAM(const int meta_handle,
        const int timeout, const char* LID_Name,
        const ul1cal_txPaOctLevData_T* sWcdmaPaOctLevData);
/**
 * Read pa control parameters from file by band
 **/
DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_WCDMA_ReadPaControlfromFile( const int meta_handle,
        const char* filename,
        const int band, // 1~10
        ul1cal_txPaOctLevData_T* sWcdmaPaOctLevData);
/**
 * Write pa control parameters from file by band
 **/
DLLEXPORT METAAPP_RESULT CALL_CONVENTION METAAPP_WCDMA_WritePaControlToFile( const int meta_handle,
        const char* filename,
        const int band, // 1~10
        const ul1cal_txPaOctLevData_T* sWcdmaPaOctLevData);

#endif //__META_DLL_WCDMA__ 


#endif


