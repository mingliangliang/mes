// Buffer.h: interface for the CBuffer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BUFFER_H__D052F372_BF66_4BA8_944D_E67E0F31E523__INCLUDED_)
#define AFX_BUFFER_H__D052F372_BF66_4BA8_944D_E67E0F31E523__INCLUDED_

#include <afx.h>
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBuffer : public CByteArray  
{
public:
	CBuffer();
	virtual ~CBuffer();
public:
	void InsertByte(long);
	long AddByte(long);
	long AddWord(long);
	long AddLong(long);
	long GetPaddedByte();
	long GetByte();
	long GetWord();
	long GetSignedWord();
	long RemoveByte();
	long RemoveWord();
	long m_lIndex;
};

#endif // !defined(AFX_BUFFER_H__D052F372_BF66_4BA8_944D_E67E0F31E523__INCLUDED_)
