/*
 * (C) Copyright 2008
 * MediaTek <www.mediatek.com>
 * Jauping Chen <jauping.chen@mediatek.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __MT6516_DOWNLOAD_H
#define __MT6516_DOWNLOAD_H


typedef	unsigned short UINT16;
typedef unsigned int   UINT32;
typedef unsigned char UINT8;


/**************************************************************************
 *  CONSTANT DEFINITION
 **************************************************************************/
/* Note : all the following constant definition                  */
/*        must be sych with tool side, once any one modifies it  */
/*        remember to inform any guy doing the same modification */

#define DM_FLASH_INFO_PKT_PATN  0x50414C46      /* Flash Info Packet pattern */
/* = ascii value of "FLAP"   */

#define DM_IMAGE_INFO_PKT_PATN  0x50474D49      /* Image Info Packet pattern */
/* = ascii value of "IMGP"   */

#define DM_CHKSUM_PKT_PATN      0x4D534B43      /* Image Info Packet pattern */
/* = ascii value of "CKSM"   */

#define DM_ERROR_PKT_PATN       0x50525245      /* Error Code Packet pattern */
/* = ascii value of "ERRP"   */

#define DM_PCMD_INFO_PKT_PATN   0x444D4350      /* Patch Command Packet pattern */
/* = ascii value of "PCMD"   */

#define DM_PARTITION_INFO_PKT_PATN      0x504E5450      /* Partition Info Packet pattern */
/* = ascii value of "PTNP"   */

#define DM_PL_INFO_PKT_PATN          0x50494C50         /* Preloader Info Packet pattern */
/* = ascii value of "PLIP"   */


/**************************************************************************
 *  STRUCTURE DEFINITION
 **************************************************************************/
/* Note : all the following structure and enumeration definition */
/*        must be sych with tool side, once any one modifies it  */
/*        remember to inform any guy doing the same modification */

typedef struct _DM_CHKSUM_PACKET
{
    UINT32              pattern;
    UINT32              chk_sum;        /* check sum value of whole image */
} DM_CHKSUM_PACKET;

typedef enum _DM_ERR_CODE
{
    DM_ERR_OK           = 0,        /* success   */
    DM_ERR_NOMEM        = 1,        /* no memory */
    DM_ERR_NAND_RD_FAIL = 2,        /* nand read fail  */
    DM_ERR_NAND_WR_FAIL = 3,        /* nand write fail */
    DM_ERR_NAND_ER_FAIL = 4,
    DM_ERR_WRONG_SEQ    = 5,        /* protocol fail, wrong sequence */
    DM_ERR_WRONG_ADDR   = 6,
    DM_ERR_WRONG_PKT_SZ = 7,        /* for Image patch */
    DM_ERR_EXCEED_BOUNDARY = 8,
    DM_ERR_INVALID_TABLE = 9,        /* for partition table checking */
    DM_ERR_SPACE_NOT_FOUND = 10,     /* for partition table checking */

    DM_ERR_UNKNOWN      = 0xFFFFFFFF

} DM_ERR_CODE;

typedef struct _DM_ERRCODE_PACKET
{
    UINT32              pattern;
    DM_ERR_CODE         err_code;       /* check sum value of whole image */
} DM_ERRCODE_PACKET;

typedef struct _DM_FLASH_INFO
{
    UINT16              man_code;       /* flash manufacture code      */
    UINT16              dev_id;         /* flash device id             */
    UINT16              dev_code;       /* flash device code           */
    UINT16              reserve;
    UINT32              dev_size;       /* flash device size           */
    UINT32              page_size;      /* flash device page size      */
    UINT32              spare_size;     /* flash device spare size     */
    /* mostly spare size = page size / 32 */
    /* but there may be exceptions */
} DM_FLASH_INFO;

typedef struct _DM_FLASH_INFO_PKT
{
    UINT32              pattern;
    DM_FLASH_INFO       flash_info;
} DM_FLASH_INFO_PACKET;

typedef struct _DM_PL_INFO_PKT
{
    UINT32              pattern;
    UINT32              version;
    UINT32              chip;
    UINT32              reserved1;
    UINT32              reserved2;
    DM_FLASH_INFO       flash_info;
} DM_PL_INFO_PACKET;


typedef enum
{
    DM_IMG_FORMAT_FAT     = 0,
    DM_IMG_FORMAT_YAFFS2  = 1,
    DM_IMG_FORMAT_UNKNOWN = 0xFFFFFFFF
} DM_IMG_FORMAT;

typedef enum
{
    DM_IMG_TYPE_LOGO      = 0,
    DM_IMG_TYPE_BOOTIMG   = 1,
    DM_IMG_TYPE_ANDROID   = 2,
    DM_IMG_TYPE_USRDATA   = 3,
    DM_IMG_TYPE_RECOVERY    = 4,
    DM_IMG_TYPE_UBOOT       = 5,
    DM_IMG_TYPE_AUTHEN_FILE    = 6,    // no use
    DM_IMG_TYPE_SECSTATIC		= 7,
    DM_IMG_TYPE_EU_FT_INFORM	= 8,
    DM_IMG_TYPE_FT_LOCK_INFORM   = 9,
    DM_IMG_TYPE_PT_TABLE_INFORM =10,


    //cust pack image
    DM_IMG_TYPE_CUST_IMAGE1 =           100,
    DM_IMG_TYPE_CUST_IMAGE2 =           101,
    DM_IMG_TYPE_CUST_IMAGE3 =           102,
    DM_IMG_TYPE_CUST_IMAGE4 =           103,

    DM_IMG_TYPE_DA =                                  200,
    DM_IMG_TYPE_JUMP_ADDR =               201,
    DM_IMG_TYPE_DA_VERIFY_INFORM = 202,

    DM_IMG_TYPE_UNKNOWN =               0xFFFFFFFF

} DM_IMG_TYPE;

typedef struct _DM_IMG_INFO
{
    DM_IMG_FORMAT       img_format;     /* image format                */
    DM_IMG_TYPE         img_type;       /* image type                  */
    UINT32              img_size;       /* image file size             */
    UINT32              addr_off;       /* image nand address offset   */
    UINT32              pkt_size;       /* packet size per transmition ( page + spare ) */
} DM_IMG_INFO;

typedef struct _DM_IMAGE_INFO_PACKET
{
    UINT32              pattern;        /* pattern to recgnize image info packet */
    struct _DM_IMG_INFO img_info;
} DM_IMAGE_INFO_PACKET;


//Image info packet with image address boundary check
typedef struct _DM_IMG_INFO_BC
{
    DM_IMG_FORMAT       img_format;     /* image format                */
    DM_IMG_TYPE         img_type;       /* image type                  */
    UINT32              img_size;       /* image file size             */
    UINT32              addr_off;       /* image nand address offset   */
    UINT32              addr_boundary;     /* image address boundary */
    UINT32              pkt_size;       /* packet size per transmition ( page + spare ) */
} DM_IMG_INFO_BC;

typedef struct _DM_IMAGE_INFO_PACKET_BC
{
    UINT32              pattern;        /* pattern to recgnize image info packet */
    struct _DM_IMG_INFO_BC img_info;
} DM_IMAGE_INFO_PACKET_BC;

/**************************************************************************
*  Modification History
*  20100721 : Wei add verification command for image patch
**************************************************************************/
#define IMAGE_PATCH_CMD_MAGIC   0x5613A8C3
typedef struct _DM_PATCH_CMD_PACKET
{
    UINT32              		pattern;               /* pattern to recgnize image info packet */
    UINT32 						magic_number;
    UINT8							enable_patch_verify;   /* 0 : no need to verify patch*/
    /* 1 : need to verify patch*/
} DM_PATCH_CMD_PACKET;


/**************************************************************************
*  Modification History
*  20110118 : Wei add partition info packet
**************************************************************************/
#define MAX_PARTITION_NAME_LEN     (64)
typedef struct _DM_PARTITION_INFO
{
    char                   part_name[MAX_PARTITION_NAME_LEN];         /* the name of partition */
    UINT32              start_addr;            /* the start address of partition  */
    UINT32              part_len;              /* the length of partition     */
    UINT8                part_visibility;              /* part_visibility is 0: this partition is hidden and CANNOT download */
    /* part_visibility is 1: this partition is visible and can download */

    UINT8                dl_selected;           /* dl_selected is 0: this partition is NOT selected to download */
    /* dl_selected is 1: this partition is selected to download */

} DM_PARTITION_INFO;

#define MAX_FLASH_PARTITION     (20)
typedef struct
{
    UINT32                                        pattern;
    unsigned int                                part_num;            // The actual number of partitions
    DM_PARTITION_INFO             part_info[MAX_FLASH_PARTITION];

} DM_PARTITION_INFO_PACKET;


/**************************************************************************
 *  OTHER TYPE OR MACRO DEFINITION
 **************************************************************************/
typedef struct _TARGET_RESP_INFO
{
    DWORD      pattern;
    DWORD	   info;

} TARGET_RESP_INFO;


/**************************************************************************
 *  EXPORT FUNCTION PROTOTYPE
 **************************************************************************/
extern void download_mode(void);

#endif /* __MT6516_DOWNLOAD_H */

