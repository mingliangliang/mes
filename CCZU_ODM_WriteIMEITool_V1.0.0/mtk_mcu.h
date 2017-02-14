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
 *  mtk_mcu.h
 *
 * Project:
 * --------
 *  BootRom Library
 *
 * Description:
 * ------------
 *  The definition of MediaTek chip types and external clock arguments.
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#ifndef _MTK_MCU_H_
#define _MTK_MCU_H_

typedef enum
{
    EXT_13M = 1,
    EXT_26M = 2,
    EXT_39M = 3,
    EXT_52M = 4,
    EXT_CLOCK_END,
    AUTO_DETECT_EXT_CLOCK = 254,
    UNKNOWN_EXT_CLOCK = 255
} EXT_CLOCK;

typedef enum
{
    MT6205      = 0,
    MT6205B     = 1,
    MT6218      = 2,
    MT6218B     = 4,
    MT6219      = 5,
    MT6217      = 6,
    MT6228      = 7,
    MT6227      = 8,
    MT6229      = 9,
    MT6226      = 10,
    MT6226M     = 11,
    MT6230      = 12,
    MT6225      = 13,
    MT6268T     = 14,
    MT6223      = 15,
    MT6227D     = 16,
    MT6226D     = 17,
    MT6223P     = 18,
    MT6238      = 19,
    MT6235      = 20,
    MT6235B     = 21,
    TK6516_MD   = 22,
    TK6516_AP   = 23,
    MT6268A     = 24,
    MT6516_MD   = 25,
    MT6516_AP   = 26,
    MT6239      = 27,
    MT6251T     = 28,
    MT6253T     = 29,
    MT6268B     = 30,
    MT6253      = 32,
    MT6253D     = 33,
    MT6236      = 34,
    MT6252      = 37,
    MT6921B     = 40,
    MT6276      = 128,
    MT6251      = 129,
    MT6256      = 130,
    MT6276M     = 131,
    MT6276W     = 132,
    MT6255      = 133,
    MT6250      = 136,
    MT6280      = 137,
    MT6922      = 138,
    MT6260      = 139,
    MT6290      = 140,
    MT6261_Dev  = 141,
    MT6261      = 142,
    MT2501      = 143,
    MT2502      = 144,

    BBCHIP_TYPE_END,
    AUTO_DETECT_BBCHIP = 254,
    UNKNOWN_BBCHIP_TYPE = 255
} BBCHIP_TYPE;

#endif
