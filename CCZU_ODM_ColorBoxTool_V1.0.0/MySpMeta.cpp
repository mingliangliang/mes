// MySpMeta.cpp: implementation of the CMySpMeta class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ColorBox.h"
#include "MySpMeta.h"
#include "spmeta.h"
#include "interface.h"


//CFullWriteView

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


#define USB_VCOM     17;
#define BD_ADDR_LEN                      6
#define MT5921 0x5921
#define MT6620 0x6620
//For EEPROM Checksum
#define  EEPROM_NIC_CHKSUM_ADD_BYTE                0x13F
#define  EEPROM_NIC_CHKSUM_START_ADD_BYTE          0x1A/* EEPROM offset for HIF section checksum */
#define  EEPROM_NIC_CHKSUM_ADD_DW                0x9F
#define  EEPROM_NIC_CHKSUM_START_ADD_DW          0x0D

//全局变量
HANDLE m_SP_ReadFromNVRAMEvent;
HANDLE m_SP_WriteToNVRAMEvent;
FT_NVRAM_READ_CNF SP_tNVRAM_ReadCnf;
FT_NVRAM_READ_REQ SP_tNVRAM_ReadReq;
FT_NVRAM_WRITE_REQ SP_tNVRAM_WriteReq;

static void cbMETA_Init( META_CNF_ERR_CODE mr)
{
	return;
}

static  void __stdcall SP_CNF_WriteNVRAM( const FT_NVRAM_WRITE_CNF *cnf, const short token, void *usrData)
{
    if (cnf->status != META_SUCCESS)
    {  
		return; 
	}
	SetEvent (m_SP_WriteToNVRAMEvent);   
	
}


static void __stdcall SP_CNF_ReadFromNVRAM(const FT_NVRAM_READ_CNF *cnf, const short token, void *usrData)
{
	if (cnf->status != META_SUCCESS)
    {  
		return; 
	}	
	SetEvent(m_SP_ReadFromNVRAMEvent);   
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMySpMeta::CMySpMeta()
{

}

CMySpMeta::~CMySpMeta()
{

}

bool CMySpMeta::MetaAPHandleInit() 
{
	if ( SP_META_GetAvailableHandle (&this->iMetaAP_handle))
		return false;
	
	if ( SP_META_Init_r(this->iMetaAP_handle , (META_Error_CallBack) cbMETA_Init ))
		return false;
	
	return true;
}

//---------------------------------------------------------------------------------------------------
void CMySpMeta::MetaAPHandleDeInit ( void ) 
{
	SP_META_Deinit_r( &this->iMetaAP_handle );
}

//---------------------------------------------------------------------------------------------------
bool CMySpMeta::InitAPDatabase(char* apDBPath)
{
	try
	{
		unsigned long db;
		
		META_RESULT m_MetaResult = SP_META_NVRAM_Init_r (this->iMetaAP_handle, apDBPath, &db);
		if((m_MetaResult != META_SUCCESS) && (m_MetaResult != META_MAUI_DB_INCONSISTENT))
			return false;
		return true;
	}
	catch(...)
	{ return false; }
}

bool CMySpMeta::Exit_MetaAPMode()
{
	if(META_SUCCESS == SP_META_DisconnectWithTarget_r( this->iMetaAP_handle))
		return true;
	return false;
};

bool CMySpMeta::AP_META_DisconnectInMetaMode_r()
{

	if(META_SUCCESS == SP_META_DisconnectInMetaMode_r( this->iMetaAP_handle))
		return true;
	return false;

}

//---------------------------------------------------------------------------------------------------
bool CMySpMeta::Switch2SP_META_Mode(int comport)
{
	int bootstop;
	WM_META_ConnectInMETA_Req META_connect_req;
	WM_META_ConnectInMETA_Report META_connect_report;
	META_RESULT metaResult;

	
	META_connect_req.com_port = comport;	
	META_connect_req.baudrate[0] = META_BAUD115200;
	META_connect_req.baudrate[1] = META_BAUD230400;
	META_connect_req.baudrate[2] = META_BAUD460800;
	META_connect_req.baudrate[2] = META_BAUD921600;
	META_connect_req.baudrate[3] = META_BAUD_END;	
	
	META_connect_req.flowctrl = META_NO_FLOWCTRL;    //for Modem side SW_FLOWCTRL
	META_connect_req.ms_connect_timeout = 80000;
	
	metaResult = SP_META_ConnectInMetaMode_r( this->iMetaAP_handle, &META_connect_req, &bootstop, &META_connect_report);
	Sleep(200);
	if(metaResult != META_SUCCESS)
		return false;
	return true;

}


bool CMySpMeta::WM_META_SetCleanBootFlag_Customize()
{
	
	SetCleanBootFlag_REQ req;
	SetCleanBootFlag_CNF cnf;
	META_RESULT metaResult;
    metaResult = SP_META_SetCleanBootFlag_r(this->iMetaAP_handle, 5000, &req, &cnf);

	if(metaResult != META_SUCCESS)
		return false;
	return true;
}



//----------------------------------------------------------------------
int CMySpMeta::SP_REQ_ReadFromNVRAM(void)
{
    DWORD wait_result;
	short int m_sNVRAM_OPID;
	META_RESULT    m_MetaResult;
	
    m_SP_ReadFromNVRAMEvent = CreateEvent( NULL, TRUE, FALSE, NULL);
	
    ResetEvent(m_SP_ReadFromNVRAMEvent);
	
    m_MetaResult = SP_META_NVRAM_Read_r(iMetaAP_handle,&SP_tNVRAM_ReadReq,&SP_tNVRAM_ReadCnf,SP_CNF_ReadFromNVRAM,&m_sNVRAM_OPID,NULL);
	
    wait_result = WaitForSingleObject(m_SP_ReadFromNVRAMEvent,15000);
	
    if ( WAIT_TIMEOUT == wait_result )
    {
        return META_TIMEOUT;
    }
	
    if ( m_MetaResult != META_SUCCESS )
    {
        return m_MetaResult;
    }
	
    return META_SUCCESS;
}


int CMySpMeta::SP_REQ_Write2NVRAM(void)
{
	short int m_sNVRAM_OPID;
	DWORD wait_result;
	META_RESULT    m_MetaResult;
	
	
    m_SP_WriteToNVRAMEvent = CreateEvent(NULL,TRUE,FALSE,NULL);
	
    ResetEvent (m_SP_WriteToNVRAMEvent);
	
    m_MetaResult = SP_META_NVRAM_Write_r (iMetaAP_handle,&SP_tNVRAM_WriteReq,SP_CNF_WriteNVRAM,&m_sNVRAM_OPID,NULL);
	
	
    wait_result = WaitForSingleObject (m_SP_WriteToNVRAMEvent, 15000 );
	
    if ( WAIT_TIMEOUT == wait_result )
    {
        return META_TIMEOUT;
    }
	
    if (m_MetaResult != META_SUCCESS )
    {
        return m_MetaResult;
    }
    return META_SUCCESS;
}
//===========================================================================
int CMySpMeta::REQ_WriteBTAddr2NVRAM_Start(int iBTId, unsigned char pBTAddress[6])
{
    int m_usRID = 1;
    int m_iBTBufSize;
    char *pLID;
    NVRAM_BTRADIO_MT6611_S  tBT;
    NVRAM_BTRADIO_MT6620_S  tBT1;
    BT_CHIP_ID_E  Chip_id;
	META_RESULT    m_MetaResult;


	
	switch ( iBTId )	
	{
		case BTMODULE_MT6601:  //6601
		case BTMODULE_MT6611:
		//case BTMODULE_MT6612:
			if (!SP_META_NVRAM_GetRecLen ( "AP_CFG_RDCL_FILE_BT_ADDR_LID", &m_iBTBufSize )) // to Test LID exist
			{
				pLID = "AP_CFG_RDCL_FILE_BT_ADDR_LID";  //after DUMA 1004
			} else if (!SP_META_NVRAM_GetRecLen ( "AP_CFG_RDEB_FILE_BT_ADDR_LID", &m_iBTBufSize ))
			{
				pLID = "AP_CFG_RDEB_FILE_BT_ADDR_LID";  //before DUMA 1004
			} else
			{
				return META_LID_INVALID;
			}
			break;
			
		case BTMODULE_RFMD3500:  //RFMD
			pLID = "AP_CFG_RDEB_FILE_BT_ADDR_LID"; 
			break;
		case BTMODULE_RFMD4020:
			
			pLID = "AP_CFG_RDEB_FILE_BT_ADDR_LID"; 
			break;
		default:
			break;
	}

	m_MetaResult = SP_META_NVRAM_GetRecLen ( pLID, &m_iBTBufSize );
    if ( m_MetaResult != META_SUCCESS )
    {
        return m_MetaResult;
    }


	SP_tNVRAM_ReadReq.LID = pLID;
    SP_tNVRAM_ReadReq.RID = m_usRID;
    SP_tNVRAM_ReadCnf.len = m_iBTBufSize;
    SP_tNVRAM_ReadCnf.buf = (unsigned char*) malloc (m_iBTBufSize*sizeof(unsigned char));

	m_MetaResult =(META_RESULT)SP_REQ_ReadFromNVRAM();
	if ( m_MetaResult!=META_SUCCESS )
    {
    	return m_MetaResult;
    }


     m_MetaResult = SP_META_NVRAM_BT_QueryChipByStructSize(&Chip_id);
     if ( m_MetaResult != META_SUCCESS )
    {
        return m_MetaResult;
    }


	if(Chip_id==BT_CHIP_ID_MT6611) 
    {
        m_MetaResult = SP_META_NVRAM_BT_Decompose_MT6611Radio( &tBT, (char*)SP_tNVRAM_ReadCnf.buf, m_iBTBufSize);
	}
    else 
    {
        m_MetaResult = SP_META_NVRAM_BT_Decompose_MT6620Radio( &tBT1, (char*)SP_tNVRAM_ReadCnf.buf, m_iBTBufSize);
    }
	   
	if ( m_MetaResult != META_SUCCESS )
    {
    	return m_MetaResult;
    }
	
	if(Chip_id==BT_CHIP_ID_MT6611) 
    {
		memcpy ( tBT.addr, pBTAddress, BD_ADDR_LEN ); 
	}
	else
	{
		memcpy ( tBT1.addr, pBTAddress, BD_ADDR_LEN ); 
	}

	
	switch (iBTId)	
	{
		case BTMODULE_MT6601:  //6601
		case BTMODULE_MT6611:
		//case BTMODULE_MT6612:
			if (!SP_META_NVRAM_GetRecLen ( "AP_CFG_RDCL_FILE_BT_ADDR_LID", &m_iBTBufSize )) // to Test LID exist
			{
				pLID = "AP_CFG_RDCL_FILE_BT_ADDR_LID";  //after DUMA 1004
			} else if (!SP_META_NVRAM_GetRecLen ( "AP_CFG_RDEB_FILE_BT_ADDR_LID", &m_iBTBufSize ))
			{
				pLID = "AP_CFG_RDEB_FILE_BT_ADDR_LID";  //before DUMA 1004
			} else
			{
				return META_LID_INVALID;
			}
			break;
			
		case BTMODULE_RFMD3500:  //RFMD
			pLID = "AP_CFG_RDEB_FILE_BT_ADDR_LID"; 
			break;
		case BTMODULE_RFMD4020:
			
			pLID = "AP_CFG_RDEB_FILE_BT_ADDR_LID"; 
			break;
		default:
			break;
	}

	m_MetaResult = SP_META_NVRAM_GetRecLen ( pLID, &m_iBTBufSize );
    if ( m_MetaResult != META_SUCCESS )
    {
        return m_MetaResult;
    }
		
	m_usRID = 1;
	SP_tNVRAM_WriteReq.LID = pLID;
    SP_tNVRAM_WriteReq.RID = m_usRID;
    SP_tNVRAM_WriteReq.len = m_iBTBufSize;
    SP_tNVRAM_WriteReq.buf = (unsigned char*) malloc ( m_iBTBufSize*sizeof(unsigned char) );



    m_MetaResult = SP_META_NVRAM_BT_QueryChipByStructSize(&Chip_id);
    if( m_MetaResult != META_SUCCESS )
    {
        return m_MetaResult;
    }

	 
	if(Chip_id==BT_CHIP_ID_MT6611) 
	{
		m_MetaResult = SP_META_NVRAM_BT_Compose_MT6611Radio( &tBT,  (char*)SP_tNVRAM_WriteReq.buf,  m_iBTBufSize );
	}
	else 
	{
		m_MetaResult = SP_META_NVRAM_BT_Compose_MT6620Radio( &tBT1,  (char*)SP_tNVRAM_WriteReq.buf,  m_iBTBufSize );
	}
	   
	if ( m_MetaResult != META_SUCCESS )
	{
		return m_MetaResult;
	}
	   

	m_MetaResult = (META_RESULT)SP_REQ_Write2NVRAM();
    
	if ( m_MetaResult != META_SUCCESS )
    {
		return m_MetaResult;
    }
	
    return META_SUCCESS;
}





//===========================================================================
int CMySpMeta::REQ_ReadBTAddrFromNVRAM_Start( int iBTId, unsigned char* pBTAddress )
{
    int m_usRID = 1, m_iBTBufSize;
	char *pLID;

	NVRAM_BTRADIO_MT6611_S  tBT;
	NVRAM_BTRADIO_MT6620_S  tBT1;
	BT_CHIP_ID_E  Chip_id;
	META_RESULT    m_MetaResult;
	
	switch ( iBTId )	
	{
		case BTMODULE_MT6601:  //6601
		case BTMODULE_MT6611:
			if (!SP_META_NVRAM_GetRecLen ( "AP_CFG_RDCL_FILE_BT_ADDR_LID", &m_iBTBufSize )) // to Test LID exist
			{
				pLID = "AP_CFG_RDCL_FILE_BT_ADDR_LID";  //after DUMA 1004
			} else if (!SP_META_NVRAM_GetRecLen ( "AP_CFG_RDEB_FILE_BT_ADDR_LID", &m_iBTBufSize ))
			{
				pLID = "AP_CFG_RDEB_FILE_BT_ADDR_LID";  //before DUMA 1004
			} else
			{
				return META_LID_INVALID;
			}
			break;
			
		case BTMODULE_RFMD3500:  //RFMD
			pLID = "AP_CFG_RDEB_FILE_BT_ADDR_LID"; 
			break;
		case BTMODULE_RFMD4020:
			
			pLID = "AP_CFG_RDEB_FILE_BT_ADDR_LID"; 
			break;
		default:
			break;
	}

    m_MetaResult = SP_META_NVRAM_GetRecLen( pLID, &m_iBTBufSize);
    if ( m_MetaResult!=META_SUCCESS )
    {
    	return m_MetaResult;
    }



	SP_tNVRAM_ReadReq.LID = pLID;
    SP_tNVRAM_ReadReq.RID = m_usRID;
    SP_tNVRAM_ReadCnf.len = m_iBTBufSize;
    SP_tNVRAM_ReadCnf.buf = (unsigned char*) malloc ( m_iBTBufSize*sizeof(unsigned char) );

	m_MetaResult =  (META_RESULT)SP_REQ_ReadFromNVRAM();
	if ( m_MetaResult!=META_SUCCESS )
    {
    	return m_MetaResult;
    }

    m_MetaResult = SP_META_NVRAM_BT_QueryChipByStructSize(&Chip_id);
	if ( m_MetaResult != META_SUCCESS )
    {
        return m_MetaResult;
    }
	if(Chip_id==BT_CHIP_ID_MT6611) 
	{
		m_MetaResult = SP_META_NVRAM_BT_Decompose_MT6611Radio ( &tBT, (char*)SP_tNVRAM_ReadCnf.buf, m_iBTBufSize);
	}
	else 
	{
		m_MetaResult = SP_META_NVRAM_BT_Decompose_MT6620Radio( &tBT1, (char*)SP_tNVRAM_ReadCnf.buf, m_iBTBufSize);
	}
	   
	if ( m_MetaResult!=META_SUCCESS )
    {
    	return m_MetaResult;
    }
     
     
	if(Chip_id==BT_CHIP_ID_MT6611) 
	{
		memcpy ( pBTAddress, tBT.addr, BD_ADDR_LEN ); 
	}
	else
	{
		memcpy ( pBTAddress, tBT1.addr, BD_ADDR_LEN ); 	
	}

	
	return m_MetaResult;
}


int CMySpMeta::REQ_WriteWifiMAC2NVRAM_Start(unsigned char mac_addr[6])
{
	int m_usRID = 1;
	int m_iBTBufSize;
	char *pLID = "AP_CFG_RDEB_FILE_WIFI_LID";
    int index = 0;
    int tempValue = 0;
    unsigned long ChipVersion;
	META_RESULT    m_MetaResult;

    m_MetaResult = SP_META_NVRAM_GetRecLen ( pLID, &m_iBTBufSize );
    if ( m_MetaResult != META_SUCCESS )
    {
        return m_MetaResult;
    }


    m_MetaResult = SP_META_WiFi_GetChipVersion_r(iMetaAP_handle, 5000, &ChipVersion);
    if(m_MetaResult != META_SUCCESS)
    {
	  return m_MetaResult;
    }

    if(ChipVersion == MT6620)
    {


		SP_tNVRAM_ReadReq.LID = pLID;
	   	SP_tNVRAM_ReadReq.RID = m_usRID;
	    SP_tNVRAM_ReadCnf.len = m_iBTBufSize;
	    SP_tNVRAM_ReadCnf.buf = (unsigned char*) malloc (m_iBTBufSize*sizeof(unsigned char));

		m_MetaResult =  (META_RESULT)SP_REQ_ReadFromNVRAM ();
		if ( m_MetaResult!=META_SUCCESS )
       	{
    	    return m_MetaResult;
       	}

	       //Modify MAC Address Part
       	for (index = 0; index <6; index=index+2)
       	{
            SP_tNVRAM_ReadCnf.buf[0x4+index+1] = mac_addr[index];
            SP_tNVRAM_ReadCnf.buf[0x4+index] = mac_addr[index+1];
       	}

	    Checksum_Generation (SP_tNVRAM_ReadCnf.buf);
			
		m_usRID = 1;
		SP_tNVRAM_WriteReq.LID = pLID;
       	SP_tNVRAM_WriteReq.RID = m_usRID;
       	SP_tNVRAM_WriteReq.len = m_iBTBufSize;
       	SP_tNVRAM_WriteReq.buf = SP_tNVRAM_ReadCnf.buf;
	       
		m_MetaResult= (META_RESULT)SP_REQ_Write2NVRAM ();
	    
		if (m_MetaResult != META_SUCCESS )
       	{
    	    return m_MetaResult;
       	}


    }
	else// if(ChipVersion == MT5921)
	{
		SP_tNVRAM_ReadReq.LID = pLID;
		SP_tNVRAM_ReadReq.RID = m_usRID;
		SP_tNVRAM_ReadCnf.len = m_iBTBufSize;
		SP_tNVRAM_ReadCnf.buf = (unsigned char*) malloc (m_iBTBufSize*sizeof(unsigned char));

		m_MetaResult =  (META_RESULT)SP_REQ_ReadFromNVRAM ();
		if ( m_MetaResult!=META_SUCCESS )
		{
			return m_MetaResult;
		}

	       //Modify MAC Address Part
	       
		for (index = 0; index <6; index=index+2)
		{
			SP_tNVRAM_ReadCnf.buf[0x26+index+1] = mac_addr[index];
			SP_tNVRAM_ReadCnf.buf[0x26+index] = mac_addr[index+1];
		}

		Checksum_Generation (SP_tNVRAM_ReadCnf.buf);

		m_usRID = 1;
		SP_tNVRAM_WriteReq.LID = pLID;
		SP_tNVRAM_WriteReq.RID = m_usRID;
		SP_tNVRAM_WriteReq.len = m_iBTBufSize;
		SP_tNVRAM_WriteReq.buf = SP_tNVRAM_ReadCnf.buf;
	       
		m_MetaResult = (META_RESULT)SP_REQ_Write2NVRAM ();
	    
		if ( m_MetaResult != META_SUCCESS )
       	{
    	    return m_MetaResult;
       	}

    }
	
    return META_SUCCESS;
}

int CMySpMeta::REQ_ReadWifiMACFromNVRAM_Start(unsigned char* mac_addr)
{	
	int m_usRID = 1;
    int m_iBTBufSize;
    char *pLID = "AP_CFG_RDEB_FILE_WIFI_LID";
    int index = 0;
    unsigned long ChipVersion;
	META_RESULT    m_MetaResult;

    m_MetaResult = SP_META_NVRAM_GetRecLen ( pLID, &m_iBTBufSize );
    if ( m_MetaResult != META_SUCCESS )
    {
		return m_MetaResult;
    }
		
	m_MetaResult = SP_META_WiFi_GetChipVersion_r(iMetaAP_handle, 5000, &ChipVersion);
	if(m_MetaResult != META_SUCCESS)
	{
		return m_MetaResult;
	}
	
	if(ChipVersion == MT6620)
	{

		SP_tNVRAM_ReadReq.LID = pLID;
		SP_tNVRAM_ReadReq.RID = m_usRID;
		SP_tNVRAM_ReadCnf.len = m_iBTBufSize;
	    SP_tNVRAM_ReadCnf.buf = (unsigned char*) malloc (m_iBTBufSize*sizeof(unsigned char));
		m_MetaResult =  (META_RESULT)SP_REQ_ReadFromNVRAM ();
		if ( m_MetaResult!=META_SUCCESS )
		{
			return m_MetaResult;
		}
		
		for (index=0; index < 6; index=index+2)
		{
			mac_addr[index] = SP_tNVRAM_ReadCnf.buf[0x4+index+1];
			mac_addr[index+1] = SP_tNVRAM_ReadCnf.buf[0x4+index];
		}
			
	}else //MT5921
	{
		SP_tNVRAM_ReadReq.LID = pLID;
		SP_tNVRAM_ReadReq.RID = m_usRID;
		SP_tNVRAM_ReadCnf.len = m_iBTBufSize;
	    SP_tNVRAM_ReadCnf.buf = (unsigned char*) malloc (m_iBTBufSize*sizeof(unsigned char));
		m_MetaResult =  (META_RESULT)SP_REQ_ReadFromNVRAM ();
		if ( m_MetaResult!=META_SUCCESS )
		{
			return m_MetaResult;
		}
		
		for (index=0; index < 6; index=index+2)
		{
			mac_addr[index] = SP_tNVRAM_ReadCnf.buf[0x26+index+1];
			mac_addr[index+1] = SP_tNVRAM_ReadCnf.buf[0x26+index];
		}
	}
	
	
    return META_SUCCESS;
}




void CMySpMeta::Checksum_Generation(unsigned char StorageBuf[])
{
	int u2Len = (EEPROM_NIC_CHKSUM_ADD_DW - EEPROM_NIC_CHKSUM_START_ADD_DW + 1) * 2;
	
	/* 5921 Start NIC EEPROM Checksum from 0x0D ~ 0x9F */
	int StartIndex = EEPROM_NIC_CHKSUM_START_ADD_DW * 2;	//from word to byte
	int EndIndex = EEPROM_NIC_CHKSUM_ADD_DW * 2;
	int LoopIndex = 0;
	unsigned char Chksum = 0;
	unsigned char New_Chksum = 0;
	unsigned char Old_Chksum = 0;
	
	//for (LoopIndex = StartIndex; LoopIndex <= EndIndex; LoopIndex++)
	for (LoopIndex = 0; LoopIndex < u2Len - 1; LoopIndex++)//not count 0x13F
	{
		Chksum = (Chksum + StorageBuf[LoopIndex + StartIndex]) & 0x00FF;
	}
	Old_Chksum = StorageBuf[0x13F];
	New_Chksum = (0x01FF - Chksum) & 0x00FF;
    
	StorageBuf[0x13F] = (0x01FF - Chksum) & 0x00FF;
}
