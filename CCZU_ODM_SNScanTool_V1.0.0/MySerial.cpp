// MySerial.cpp: implementation of the CMySerial class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WeighTool.h"
#include "MySerial.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMySerial::CMySerial()
{
	this->m_bOpen = false;

}

CMySerial::~CMySerial()
{

}

bool CMySerial::Port_Init()
{

	if (this->m_bOpen)
	{
		Port_Close();
	}
	CString port;
	port.Format(_T("\\\\.\\COM%d"),this->m_nPort);
	CommHandle = CreateFile(port,
                     GENERIC_READ | GENERIC_WRITE,
                     NULL,			// don't share port
                     NULL,          // SecurityAttributes - none in Win95
                     OPEN_EXISTING, // how to create
                     0,             // file attributes
                     NULL           // handle of file with attributes to copy
                     );

    if (CommHandle != INVALID_HANDLE_VALUE)
    {       

        CommProps.wPacketLength = sizeof(COMMPROP);
        SetupComm         (CommHandle,4096, 4096);
        GetCommProperties (CommHandle, &CommProps);
        GetCommState      (CommHandle, &CommDcb);

		this->CommDcb.DCBlength = sizeof(DCB);
        CommDcb.BaudRate =this->m_nBaudRate;// commDeviceInfo.clockRates[1].baudSetting[COMM_9600_BAUD_INDEX]; // 9600

        CommDcb.ByteSize = 8;
        CommDcb.fParity  = FALSE;
        CommDcb.StopBits = ONESTOPBIT;;

        CommDcb.fBinary           = TRUE;
        CommDcb.fOutxCtsFlow      = FALSE;
        CommDcb.fOutxDsrFlow      = FALSE;

      //  if (dtrEnabled == true)
        //{
           CommDcb.fDtrControl   = DTR_CONTROL_ENABLE;
            //if (dtrOn == COMM_LINE_OFF)
              //  EscapeCommFunction(CommHandle, CLRDTR);
            //else
                EscapeCommFunction(CommHandle, SETDTR);
        //}
        //else
        //{
          //  CommDcb.fDtrControl   = DTR_CONTROL_DISABLE;
        //}


        //if (rtsEnabled == true)
        //{
            CommDcb.fRtsControl   = RTS_CONTROL_ENABLE;
            //if (rtsOn == COMM_LINE_OFF)
              //  EscapeCommFunction(CommHandle, CLRRTS);
            //else
                EscapeCommFunction(CommHandle, SETRTS);
        //}
        //else
        //{
            //CommDcb.fRtsControl   = RTS_CONTROL_DISABLE;
        //}

        CommDcb.fDsrSensitivity   = FALSE;
        CommDcb.fTXContinueOnXoff = FALSE;
        CommDcb.fOutX             = FALSE;
        CommDcb.fInX              = FALSE;
        CommDcb.fErrorChar        = FALSE;
        CommDcb.fNull             = FALSE;

        CommDcb.fAbortOnError     = FALSE;

        if (SetCommState (CommHandle, &CommDcb) == FALSE)
		{
			CloseHandle(CommHandle);
             strcpy(this->m_sLastError,"Could not setup COMM port");
			 return false;
		}

        commTimeOuts.ReadIntervalTimeout         = 0;
        commTimeOuts.ReadTotalTimeoutMultiplier  = 0;
        commTimeOuts.ReadTotalTimeoutConstant    = 100;
        commTimeOuts.WriteTotalTimeoutMultiplier = 0;
        commTimeOuts.WriteTotalTimeoutConstant   = 0;

        if (SetCommTimeouts (CommHandle, &commTimeOuts) == FALSE)
		{
		
           strcpy(this->m_sLastError,"Could not set COMM timeouts");
		   return false;

		}
        PurgeComm (CommHandle, PURGE_TXCLEAR | PURGE_RXCLEAR);
    }
    else
    {
        strcpy(this->m_sLastError,"Open Comm Fail!");
		return false;
    }
	m_bOpen = true;
  return true;
}

void CMySerial::Port_Close()
{
	if (this->m_bOpen==false)
		return;
	  if (CommHandle != INVALID_HANDLE_VALUE)
    {       
		  CloseHandle(this->CommHandle);
		  CommHandle = INVALID_HANDLE_VALUE;
		  this->m_bOpen = false;
	  }
}
