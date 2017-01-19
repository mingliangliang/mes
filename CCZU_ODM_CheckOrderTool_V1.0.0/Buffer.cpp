// Buffer.cpp: implementation of the CBuffer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WeighTool.h"
#include "Buffer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBuffer::CBuffer()
{
	this->m_lIndex = 0;

}

CBuffer::~CBuffer()
{

}
void CBuffer::InsertByte(long iData)
{
	InsertAt(0,iData & 0xff);
}

long CBuffer::AddByte(long iData)
{
	int count;
	
	count = Add(iData & 0xff);

	return count;
}

long CBuffer::AddWord(long iData)
{
	long count;

	count = Add((iData >> 8) & 0xff);
	count += Add(iData & 0xff);

	return count;
}

long CBuffer::AddLong(long iData)
{
	long count;
    
    
	count += Add(iData & 0xff);
	count += Add((iData >> 8) & 0xff);	
	count += Add((iData >> 16) & 0xff);
	count = Add((iData >> 24) & 0xff);
	return count;
}

long CBuffer::GetPaddedByte()
{
	long value = 0;

	if (m_lIndex < (GetSize() - 1))
	{
		value = GetAt(m_lIndex);
		m_lIndex++;
		m_lIndex++;
	}
	else
	{
		return NULL;
	}
		
	return value;
}

long CBuffer::GetByte()
{
	long value = 0;

	if (m_lIndex < GetSize())
	{
		value = GetAt(m_lIndex);
		m_lIndex++;
	}
	else
	{
		return NULL;
	}
	
	return value;
}

long CBuffer::GetWord()
{
	long value = 0;

	if (m_lIndex < (GetSize() - 1))
	{
		value = GetAt(m_lIndex) << 8;
		m_lIndex++;
		value |= GetAt(m_lIndex);
		m_lIndex++;
	}
	else
	{
		return NULL;
	}
	
	return value;
}

long CBuffer::GetSignedWord()
{
	long value = 0;

	value = GetWord();

	if (value > 32768)
	{
		value -= 65536;
	}

	return value;
}

long CBuffer::RemoveByte()
{
	long value = 0;
	long k;
	k=GetSize();

	if (m_lIndex <k)
	{
		value = GetAt(m_lIndex);
		RemoveAt(m_lIndex);
	}
	else
	{
		return NULL;
	}
	
	return value;
}

long CBuffer::RemoveWord()
{
	long value = 0;

	if (m_lIndex < (GetSize() - 1))
	{
		value = GetAt(m_lIndex) << 8;
		RemoveAt(m_lIndex);
		value |= GetAt(m_lIndex);
		RemoveAt(m_lIndex);
	}
	else
	{
		return NULL;
	}
	
	return value;
}
