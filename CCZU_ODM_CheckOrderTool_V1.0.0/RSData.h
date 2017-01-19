// RSData.h: interface for the CRSData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RSDATA_H__3A5ECA38_5397_464F_ACB8_CC4C33045348__INCLUDED_)
#define AFX_RSDATA_H__3A5ECA38_5397_464F_ACB8_CC4C33045348__INCLUDED_
#include "Buffer.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRSData //Class  Receive and  Send Data 
{
public:
	CRSData();
	virtual ~CRSData();
public:
	long  Clear();
	long  Read(CBuffer *, unsigned long);
	long  Write(CBuffer *);
	long  Reply(long);

	HANDLE m_hPort;
};

#endif // !defined(AFX_RSDATA_H__3A5ECA38_5397_464F_ACB8_CC4C33045348__INCLUDED_)
