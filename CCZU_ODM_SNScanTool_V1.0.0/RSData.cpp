// RSData.cpp: implementation of the CRSData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WeighTool.h"
#include "RSData.h"
#include "resource.h"


// EMMI Flag definitions //

#define STX									2
#define ETX									3
#define ACK									6
#define NAK									21
#define PAD									0
#define LOF									255

// VISA interface definitions //

#define MAX_FRAME_SIZE						253		// 31/08/99
#define ASRL_BUFFER_SIZE					1024
#define ASRL_MAX_TRIES						5

// Miscellaneous definitions //

#define BYTE_MASK							0xFF
#define WORD_MASK							0xFFFF

#define LENGTH_IMEI							7

#define ON									1
#define OFF									0

#define MMI_KEY_PRESS_DELAY					750

//Revised by Xiong Gang, 12/24/1999
#define GSM_BURST_TYPE						2

// GKI definitions //

#define SIGNAL_ID							0xD3
#define COMMAND_ID							0xD5
#define SIGNAL_REF							0xA5A5
#define MMI_KEY_ANSWER						0x04
#define MMI_KEY_DEVMAN						0x09
#define MMI_KEY_ON_OFF						0x1D
#define MMI_KEY_POWER_ON_OFF				0x00

// Error codes //

#define ERR_SUCCESS							0

#define ERR_SERIAL_TIMEOUT                  179
#define ERR_SERIAL_PORT_WRITE               131
#define ERR_SERIAL_PORT_NAK                 129
#define ERR_SERIAL_PORT_UNKNOWN             177
/*
#define ERR_SERIAL_TIMEOUT					-102
#define ERR_SERIAL_PORT_NAK					-111
#define ERR_SERIAL_PORT_UNKNOWN				-112
#define ERR_SERIAL_PORT_READ				-109
#define ERR_SERIAL_PORT_WRITE				-110
#define ERR_SERIAL_PORT_FLUSH				-111


#define ERR_EMMI_STX						-200
#define ERR_EMMI_ETX						-201
#define ERR_EMMI_LEN						-202
#define ERR_EMMI_CHK						-203

#define ERR_GKI_BUFFER_OVERRUN				-300
#define ERR_GKI_TX_NAK						-301
#define ERR_GKI_RX_TIMEOUT					-302
#define ERR_GKI_FRAME_SEND					-303
#define ERR_GKI_FRAME_RECEIVE				-304

#define ERR_TASK_SRC_TASK_ID				-400
#define ERR_TASK_DEST_TASK_ID				-401
#define ERR_TASK_FRAME_LENGTH				-402
#define ERR_TASK_SIGNAL_ID					-403
#define ERR_TASK_COMMAND_REF				-404
#define ERR_TASK_ASP_DAC_READ				-405
#define ERR_TASK_TIMING_ADVANCE				-406
#define ERR_TASK_ADJUST_TIMING				-407
#define ERR_TASK_FB_ARFCN					-408
#define ERR_TASK_FB_DAC_VALUE				-409
#define ERR_TASK_FB_USE_TIMING_OFFSET		-410
#define ERR_TASK_FB_TIMING_OFFSET			-411
#define ERR_TASK_RSSI_RX_ARFCN				-412
#define ERR_TASK_RSSI_RX_GAIN				-413
#define ERR_TASK_RSSI_MON_ARFCN				-414
#define ERR_TASK_RSSI_MON_GAIN				-415

#define ERR_TEST_CALC_AFC_NO_FB				-522
#define ERR_TEST_CALC_AGC					-523
#define ERR_TEST_TX_POWER_LOW				-524
#define ERR_TEST_TX_POWER_HIGH				-525
#define ERR_TEST_TX_POWER_EXPECTED			-526
#define ERR_TEST_TX_POWER					-527
#define ERR_TEST_CAL_TX						-528       //Added by Xiong

#define ERR_TEST_CALC_DCOFFSET				-531       //Added by luqiang
 
#define ERR_SCALING_FACTOR					-550
#define ERR_RFPATH_CALTABLE					-560
#define ERR_RFPATH_CALTABLE_LOWFREQ			-570
#define ERR_RFPATH_CALTABLE_HIGHFREQ		-580
#define ERR_FREQBURST_NOT_FOUND             -590
#define ERR_NO_POWER_MEASURED               -600
#define ERR_INVALID_DATA                    -610

#define ERR_RF_CONNECTOR					-701
#define ERR_MAX_LEVEL_SCALING_FACTOR		-702
#define ERR_UNABLE_TO_CALIBRATE				-703
#define ERR_TX_CAL_RESULT					-704
#define ERR_UNABLE_TO_PRECHARGE				-705
*/
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRSData::CRSData()
{

}

CRSData::~CRSData()
{

}
//Funcation Clear()
//Params:
//-NONE
//Return Value
//-SUCCESS  :success
//-ERR_SERIAL_PORT_FLUSH :FLUSH  PORT Failure
//Description:
//-Used to clear serial port ReadBuffer before send data
long CRSData::Clear()
{
 

	PurgeComm (m_hPort, PURGE_TXCLEAR | PURGE_RXCLEAR|PURGE_TXABORT|PURGE_RXABORT);
	//Sleep(10);
	return  ERR_SUCCESS;
 
}

//Functuion Read()
//Params:
//-CBUFFER *fameBuffer used to store readout data from serial
//-unsigned long count data long
//RETURN VALUE
//-SUCCESS read data success!
//-ERR_SERIAL_TIMEOUT ReadData TimeOut 
//Description:
//-Used to read data from serial port
long CRSData::Read(CBuffer *frameBuffer, unsigned long count)
{
 
	unsigned long actual,i;
	char buffer[512];

	DWORD	dwdBytesReceived = 0;
	if (ReadFile (m_hPort, buffer, count, &dwdBytesReceived, NULL)==false)
	{
		return ERR_SERIAL_TIMEOUT;	
	}
	if (dwdBytesReceived<count)
	{
			return ERR_SERIAL_TIMEOUT;	
	}
		for (i = 0; i < dwdBytesReceived; i++)
	{
		frameBuffer->Add(buffer[i]);
	}
	return ERR_SUCCESS;//huangbo changed

 
}

//Functuion write()
//Params:
//-CBUFFER *fameBuffer used to store readout data from serial
//-unsigned long count data long
//RETURN VALUE
//-SUCCESS write data and receive reply!
//-ERR_SERIAL_PORT_WRITE write data fail 
//-ERR_SERIAL_TIMEOUT Read replay timeout
//-ERR_SERIAL_PORT_NAK handset answer error command!
//-ERR_SERIAL_PORT_UNKNOWN Unexpected data received
//Description:
//-Used to write data to serial port
long CRSData::Write(CBuffer *frameBuffer)
{
 
	unsigned short count;
	unsigned long actual, i;
	unsigned char buffer[ASRL_BUFFER_SIZE], reply;
	char temp[2048];
	char tt[10];
	count = frameBuffer->GetSize();
	temp[0]=0;
	for(i = 0; i < count; i++)
	{
		buffer[i] = frameBuffer->GetAt(i);
		if(i%16==0)
			sprintf(tt,"\r\n  %02X ",buffer[i]&0xff);
		else if(i%4==0)
			sprintf(tt,"  %02X ",buffer[i]&0xff);
		else
			sprintf(tt,"%02X ",buffer[i]&0xff);
		strcat(temp,tt);
	}
	strcat(temp,"\r\n");
     Clear();	
	/* 
	status = viWrite(m_vSerialPort, (ViBuf)buffer, count, &actual);
	if (status != VI_SUCCESS)
	{
		return ERR_SERIAL_PORT_WRITE;
	}
	*/
	DWORD dwdTotalBytesSent;
	if (WriteFile(m_hPort,buffer, count, &dwdTotalBytesSent, NULL) == FALSE)
	{
		LPVOID lpMsgBuf;
         FormatMessage( 
    FORMAT_MESSAGE_ALLOCATE_BUFFER | 
    FORMAT_MESSAGE_FROM_SYSTEM | 
    FORMAT_MESSAGE_IGNORE_INSERTS,
    NULL,
    GetLastError(),
    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
    (LPTSTR) &lpMsgBuf,
    0,
    NULL 
);
// Process any inserts in lpMsgBuf.
// ...
// Display the string.
MessageBox( NULL, (LPCTSTR)lpMsgBuf, "Error", MB_OK | MB_ICONINFORMATION );
// Free the buffer.
LocalFree( lpMsgBuf );
    	dwdTotalBytesSent = 0;
    	return ERR_SERIAL_PORT_WRITE;	
	}
	DWORD	dwdBytesReceived = 0;
	if (!ReadFile (m_hPort, (BYTE *)&reply, 1, &dwdBytesReceived, NULL))
	{
		return ERR_SERIAL_TIMEOUT;
	
	}

/*
	status = viRead(m_vSerialPort,(BYTE *)&reply,1,&actual); 
	if ((status != VI_SUCCESS) &&
		(status != VI_SUCCESS_TERM_CHAR) &&
		(status != VI_SUCCESS_MAX_CNT))
	{
	//	Sleep(500);
		return ERR_SERIAL_TIMEOUT;
	}

  */
	if (reply == ACK)
	{
		return ERR_SUCCESS;
	}
	else if (reply == NAK)
	{
		//Sleep(500);
		return ERR_SERIAL_PORT_NAK;
	}

	return ERR_SERIAL_PORT_UNKNOWN;

}
//Funcation : Replay()
//params:
//long reply :reply code :such as 0x06 or 0x15
//Return Value
//-ERR_SERIAL_PORT_WRITE :write data fail.
//description:send reply byte to handset
long CRSData::Reply(long reply)
{
 
	unsigned long actual;
	Clear();
	DWORD dwdTotalBytesSent;
	if (WriteFile(m_hPort, (BYTE *)&reply, 1, &dwdTotalBytesSent, NULL) == FALSE)
	{
    	dwdTotalBytesSent = 0;
    	return ERR_SERIAL_PORT_WRITE;	
	}
	/*
	status = viWrite(m_vSerialPort,(BYTE *)&reply,1,&actual); 
	if (status != VI_SUCCESS)
	{
		return ERR_SERIAL_PORT_WRITE;
	}
	*/
	return ERR_SUCCESS;
}

