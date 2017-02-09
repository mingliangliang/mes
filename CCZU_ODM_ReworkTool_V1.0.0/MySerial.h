// MySerial.h: interface for the CMySerial class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSERIAL_H__CDCD089A_25D2_497B_BE96_1DAEDA7B7DEE__INCLUDED_)
#define AFX_MYSERIAL_H__CDCD089A_25D2_497B_BE96_1DAEDA7B7DEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMySerial  
{
public:
	void Port_Close();
	bool Port_Init();
	CMySerial();
	virtual ~CMySerial();

	  

    HANDLE        CommHandle;
    COMMPROP      CommProps;
    COMMTIMEOUTS  commTimeOuts;
    DCB           CommDcb;
	int m_nBaudRate;
	int m_nPort;
	bool m_bOpen;
	char m_sLastError[128];

};

#endif // !defined(AFX_MYSERIAL_H__CDCD089A_25D2_497B_BE96_1DAEDA7B7DEE__INCLUDED_)
