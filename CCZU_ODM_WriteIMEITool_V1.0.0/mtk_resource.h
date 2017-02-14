/*******************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2004
 *
 ******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  mtk_resource.h
 *
 * Project:
 * --------
 *  Flash Download/Readback/Format Library.
 *
 * Description:
 * ------------
 *  Resource layout analyzer.
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#ifndef	_MTK_RESOURCE_H_
#define	_MTK_RESOURCE_H_

#define MTK_RESOURCE_MAGIC		0x12345678
#define MAX_PROJECT_ID_LENGTH   72
#define MAX_PROJECT_ID_LENGTH_OLD	32
#define MAX_RESOURCE_ENTRY		8

//-----------------------------------------------------------------------------
// MTK Resource Structure
//-----------------------------------------------------------------------------
typedef struct {

	// resource prefix name
	char			m_prefix[32];

    unsigned int    m_mba_ver;      // v1~v3

	char			m_project_id[MAX_PROJECT_ID_LENGTH]; // string to describe project name and S/W version

	unsigned int	m_type_ver;		// resource type and version

	unsigned int	m_base_addr;	// base address of resoure
	unsigned int	m_table_size;	// size of resource table
	unsigned int	m_content_size;	// size of resource content

	unsigned int	m_magic;		// resource magic

    unsigned short  m_compressed;   // resource bin compress or not (v3 or later)
    unsigned short  m_existed;      // resource bin entry exist or not (v3 or later)
    unsigned int    m_compressed_size;   // if compress, compress size (v3 or later)
    unsigned int    m_max_ram_size; // memory usage size (v3 or later)
    unsigned int    m_exec_addr;    // execution address (v3 or later)
} MTK_Resource;

//-----------------------------------------------------------------------------
// 1st Level Indirect JumpTable
//-----------------------------------------------------------------------------
typedef struct {

	// jump table prefix name
	char			m_prefix[32];

	unsigned int	m_base_addr;	// base address of 1st indirect jumptable
	unsigned int	m_size;			// size of 1st indirect jumptable

	unsigned short	m_res_count;	// (0~MAX_RESOURCE_ENTRY), max MAX_RESOURCE_ENTRY entries
	MTK_Resource	m_res[MAX_RESOURCE_ENTRY];	// resource arrary

} MTK_JumpTable;

#endif
