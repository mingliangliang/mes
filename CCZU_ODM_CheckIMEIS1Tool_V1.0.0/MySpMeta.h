// MySpMeta.h: interface for the CMySpMeta class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSPMETA_H__8CCC355A_E157_4664_97B9_3B4B754D5C6F__INCLUDED_)
#define AFX_MYSPMETA_H__8CCC355A_E157_4664_97B9_3B4B754D5C6F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMySpMeta  
{
public:
	CMySpMeta();
	virtual ~CMySpMeta();

	bool MetaAPHandleInit();
	void MetaAPHandleDeInit() ;
	bool InitAPDatabase(char* apDBPath);
	bool Switch2SP_META_Mode(int comport);
	bool Exit_MetaAPMode();
	bool WM_META_SetCleanBootFlag_Customize();
	bool AP_META_DisconnectInMetaMode_r();


	int REQ_WriteBTAddr2NVRAM_Start(int iBTId, unsigned char pBTAddress[6]);
	int REQ_ReadBTAddrFromNVRAM_Start( int iBTId, unsigned char* pBTAddress );
	int SP_REQ_ReadFromNVRAM(void);
	int SP_REQ_Write2NVRAM(void);

	int REQ_WriteWifiMAC2NVRAM_Start(unsigned char mac_addr[6]);
	int REQ_ReadWifiMACFromNVRAM_Start(unsigned char *mac_addr);
	int REQ_ReadPSCaliFromNVRAM_Start(unsigned char* PSCali);
	int REQ_ReadCopyFileFromNVRAM_Start(unsigned char* Copy_File);
	void Checksum_Generation(unsigned char StorageBuf[]);

    bool SP_REQ_GetVersion(void);
	CString SP_Get_SWVersion(void);

	CString SP_REQ_GetVersion_2(void);

	CString ApReadBarcode(int iPSNLen);
	bool ApWriteBarcode(CString barcode);

public:
	int iMetaAP_handle;
	short GETID_VERSION;

public:

};

#endif // !defined(AFX_MYSPMETA_H__8CCC355A_E157_4664_97B9_3B4B754D5C6F__INCLUDED_)

