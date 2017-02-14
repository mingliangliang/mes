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
 *  rom_setting.h
 *
 * Project:
 * --------
 *  Flash Download/Readback/Format Library.
 *
 * Description:
 * ------------
 *  ROM setting
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef _ROM_SETTING_H_
#define _ROM_SETTING_H_

#include "flashtool_handle.h"   // For BBCHIP_TYPE and _BOOL

#define MAX_NUM_ROM_FILES       MAX_LOAD_SECTIONS
#define MAX_ROM_NAME_LEN        128
#define MAX_ROM_FILE_PATH_LEN   512

#ifdef __cplusplus
extern "C" {
#endif


//
// ROMSetting_v01
//
typedef struct ROMSetting_v01
{
    unsigned int numValidEntries;

    char regionName[MAX_NUM_ROM_FILES][MAX_ROM_NAME_LEN + 1];

    // Load address
    unsigned int loadAddr[MAX_NUM_ROM_FILES];
    _BOOL isOffset[MAX_NUM_ROM_FILES];

} ROMSetting_v01;


//
// ROMSetting_v02
//
typedef enum Alignment
{
    Alignment_Invalid = 0,
    Alignment_Block,
    Alignment_Page

} Alignment;

typedef enum PartitionType
{
    RAW = 0x0,
    YAFFS,
    RESERVED = 0x100

} PartitionType;


typedef struct PartitionSetting
{
    char partitionName[MAX_ROM_NAME_LEN + 1];
    char romFilePath[MAX_ROM_FILE_PATH_LEN + 1];
    unsigned int loadAddr;
    PartitionType partitionType;
} PartitionSetting;



typedef struct BootRegionSetting
{
    Alignment alignment;
    char romFilePath[MAX_NUM_ROM_FILES][MAX_ROM_FILE_PATH_LEN + 1];

} BootRegionSetting;


typedef struct ControlBlockRegionSetting
{
    char romFilePath[MAX_NUM_ROM_FILES][MAX_ROM_FILE_PATH_LEN + 1];

} ControlBlockRegionSetting;


typedef struct MainRegionSetting
{
    Alignment alignment;
    char romFilePath[MAX_NUM_ROM_FILES][MAX_ROM_FILE_PATH_LEN + 1];

} MainRegionSetting;


typedef struct LinuxPartitionSetting
{
    unsigned int bmt_pool_address;
    PartitionSetting partition[MAX_NUM_ROM_FILES];

} LinuxPartitionSetting;



// [Tier01-LoadFS]
typedef struct FileSystemRegionSetting
{
    char romFilePath[MAX_NUM_ROM_FILES][MAX_ROM_FILE_PATH_LEN + 1];
} FileSystemRegionSetting;


typedef struct RawRegionSetting
{
    char romFilePath[MAX_NUM_ROM_FILES][MAX_ROM_FILE_PATH_LEN + 1];
} RawRegionSetting;


typedef struct ROMSetting_v02
{
    BBCHIP_TYPE chipType;
    BootRegionSetting bootRegion;
    ControlBlockRegionSetting controlBlockRegion;
    MainRegionSetting mainRegion;
    // [Tier01-LoadFS]
    FileSystemRegionSetting fileSystemRegion;
    //
    LinuxPartitionSetting linuxRegion;
    RawRegionSetting rawRegion;
} ROMSetting_v02;


//
// ROMSetting
//
typedef struct ROMSetting
{
    unsigned int version;

    union
    {
        ROMSetting_v01 v01;
        ROMSetting_v02 v02;
    } u;

} ROMSetting;


#ifdef __cplusplus
}
#endif

#endif // _ROM_SETTING_H_
