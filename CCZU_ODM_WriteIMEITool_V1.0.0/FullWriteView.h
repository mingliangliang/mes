// FullWriteView.h : interface of the CFullWriteView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FULLWRITEVIEW_H__7EAE63C5_2D37_49CC_AC69_0BC0AED0D559__INCLUDED_)
#define AFX_FULLWRITEVIEW_H__7EAE63C5_2D37_49CC_AC69_0BC0AED0D559__INCLUDED_

#include "Config.h"
#include "Label.h"
#include "METAAPP.h"
#include "META.h"
#include "brom.h"
#include "flashtool_handle.h" 
#include "SLA_Challenge.h"
#include "interface.h"
#include "MySpMeta.h"
#include "skapi.h"
#include "PhoneCommand.h"
#include "sp_brom.h"

#define WM_CAL_MSG  WM_USER+100
#define WM_UPDATEDATA  WM_USER+101
#define WM_SETMYFOCUS  WM_USER+102

//20150728 glory add spmeta.h
namespace SPMETA_DLL
{
	#include "Spmeta.h"
}
//#include ".\Common\Common.h"
#define M2S(x) #x
#define  MAX_MD_CHANNEL_NUM 8
//end
//20150728 glory add follow fun def
char* ResultToString_SP(int MR);
char* ResultToString(int MR);
//end

//20150728 glory add new Struct
typedef enum
{
    SP_MODEM_META = 0,
    SP_AP_META,
    SP_AP2MD_FAIL,
    SP_MD2AP_FAIL,
    SP_NOTIN_META = 256
}SP_METAMODE_e;

typedef struct  
{
    unsigned int number_of_md;
    unsigned int active_md_idx; 
    unsigned int current_mdtype; 
    unsigned int mdimg_type[16];
    unsigned int number_of_mdSwImg; 
    int          activeMdTypeIdx;
    unsigned int multi_md_capability_support;
}SP_MODEMInfo_s;

typedef struct r_buf
{
	char rd_buf[1000];

}ADB_READ_BUF;
//end

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFullWriteView : public CFormView
{
protected: // create from serialization only
	CFullWriteView();
	DECLARE_DYNCREATE(CFullWriteView)

public:
	//{{AFX_DATA(CFullWriteView)
	enum { IDD = IDD_FULLWRITE_FORM };
	CLabel	m_ctrCurrentLine;
	CEdit	m_ctrInputIMEI4;
	CEdit	m_ctrInputIMEI3;
	CLabel	m_ctrCurrentColor;
	CLabel	m_ctrCurrentOrder;
	CLabel	m_ctrCurrentProduct;
	CLabel	m_cCurrentCount;
	CEdit	m_ctrInputPSN;
	CEdit	m_ctrInputIMEI2;
	CEdit	m_ctrInputIMEI1;
	CLabel	m_cResult;
	CRichEditCtrl	m_cedTrace;
	CButton	m_ctrSelectAPDBButton;
	CButton	m_ctrSelectDBButton;
	CComboBox	m_ctrComboxComPort;
	int		m_iComboxComPort;
	CString	m_csAPDBPath;
	CString	m_csDBPath;
	CString	m_csInputIMEI1;
	CString	m_csInputIMEI2;
	CString	m_csInputPSN;
	CString	m_csCurrentProduct;
	CString	m_csCurrentOrder;
	CString	m_csCurrentColor;
	CString	m_csInputIMEI3;
	CString	m_csInputIMEI4;
	CString	m_csCurrentLine;
	//}}AFX_DATA

// Attributes
public:
	CFullWriteDoc* GetDocument();
		
public:  
	CString m_imei1_start;
	CString m_imei1_end;
	CString m_imei2_start;
	CString m_imei2_end;
	CString m_imei3_start;
	CString m_imei3_end;
	CString m_imei4_start;
	CString m_imei4_end;


	CString m_csLCDSN;
	CString m_csTPSN;
	CString m_csCameraSN;
	CString m_csPCBASN;

	int m_iIMEIType;
	int m_iIMEIRangeType;
	int m_iPlatform;

	int	m_iScanPSN;
	int m_iPSNLength;
	int	m_iCheckPSN;
	CString	m_csPSNCheckBit;

	//当前PS校准数据
	CString m_csPSdata1;
	CString m_csPSdata2;

	//CHECK NV
	int m_iBTFT;
	int m_iWIFI;
	int m_iBluetooth;
	int m_iResetFactory;
	int	m_iCheckColor;
	int m_iCheckVersion;
	CString m_csVersion;
    int m_iCheckBoardVersion;
	CString m_csBoardVersion;
    int m_iCheckWIFIMAC;
    CString m_csWIFIMAC;
	int  m_iWritePSNToPhone;


	//展讯
	SP_HANDLE  g_hDiagPhone;
	int        nErrorCode;
	HANDLE     m_hEnterModeSuccess;
	
	bool EnterSPRD();
	bool	CheckApVer_SPRD(CString sAPVersionToCompare);
	bool ReadBarCode_SPRD(CString& sBarcode);
	bool ReadMAC_SPRD(CString& sMAC);
	bool WriteSN_SPRD(CString sSN);

public:
	CConfig m_Config;
	CFont m_staticfont;
	int m_comnum[255];
	int m_comport;
	
public:
	HANDLE m_hThreadModemNVInit;
	DWORD m_dThreadIdModemNVInit;	
	HANDLE m_hThreadSPNVInit;
	DWORD	m_dThreadIdSPNVInit;
	HANDLE m_hThreadFPStart;
	DWORD	m_dThreadIdFPStart;
	HANDLE m_hThreadSPStart;
	DWORD	m_dThreadIdSPStart;
	HANDLE m_hThreadFPStart_ScanMode;
	DWORD	m_dThreadIdFPStart_ScanMode;
	HANDLE m_hThreadSPStart_ScanMode;
	DWORD	m_dThreadIdSPStart_ScanMode;

public:
	METAAPP_RESULT m_MetaappResult;
	META_RESULT    m_MetaResult;
	int m_nMetaHandle;
	CMySpMeta m_ApExe;
	VerInfo_Cnf p_verinfo;

	META_Connect_Req META_connect_req; 
	META_Connect_Report META_connect_report;
	AUTH_HANDLE_T  m_sAuthHandle;

	BBCHIP_TYPE  m_UARTCOM;                       //MT6236平台写蓝牙失败问题
	BBCHIP_TYPE  m_USBCOM;						  //MT6236平台写蓝牙失败问题

	FT_NVRAM_READ_CNF tNVRAM_ReadCnf;
	FT_NVRAM_READ_REQ tNVRAM_ReadReq;
	FT_NVRAM_WRITE_REQ tNVRAM_WriteReq;

	META_ConnectInMETA_Req tMETA_Connect_Req;
	META_ConnectInMETA_Report tMETA_Connect_Report;
	char  s_com_symbol[100];
	char  s_com_port[100];
	int m_usb_port;

public:
	unsigned short us_com_port;	

public:
	CString m_csPcbaSN;
	CString m_csSN;
	CString m_csPcbaBarcode;
	CString m_csWriteSN;
	CString m_csWriteWIFI;
	CString m_csWriteBT;
	CString m_csWriteIMEI1;
	CString m_csWriteIMEI2;
	CString m_csWriteIMEI3;
	CString m_csWriteIMEI4;
	CString m_csWriteIMEI1_15;
	CString m_csWriteIMEI2_15;
	CString m_csWriteIMEI3_15;
	CString m_csWriteIMEI4_15;
	CString m_csReadIMEI1;
	CString m_csReadIMEI2;
	CString m_csReadIMEI3;
	CString m_csReadIMEI4;

public:
	CString m_csCurrentCount;

	DWORD	m_iFirstKeyTime;
	DWORD	m_iLastKeyTime;
	DWORD	m_iKeyPeriod;

public:
	void SetMyFont();
	void LoadComPort();
	void SetBTNEnable(bool flag);
	void OnGetMessage(WPARAM wParam, LPARAM lParam);
	void OnUpdateData(WPARAM wParam, LPARAM lParam);
	void OnSetMyFocus(WPARAM wParam, LPARAM lParam);
	void ShowInfo(char *msg);
	void Display(char *msg,int);
	void ShowCalResult(int state);
	bool DoInitFPNV();
	bool DoInitSPModemNV();
	bool DoInitSPApNV();
	void CleanAndSetBuffer();
	bool Check_ProductSN_Repeat();
	bool Check_IMEI1_Repeat();
	bool Check_IMEI2_Repeat();
	bool Check_IMEI3_Repeat();
	bool Check_IMEI4_Repeat();
	void calculate_15_digit_imei( char *imei_14,char &calculate_digit);
	AUTH_HANDLE_T Get_AuthHandle(void);
	bool FP_Read_PCB_BARCODE();
	bool FP_Read_IMEI();
	bool ReadSimpleIMEI();
	bool ReadDoubleIMEI();
	bool ReadThreeIMEI();
	bool ReadFourIMEI();
	bool Check_PCB_Net_Repeat();
	bool Check_PCB_SN_Repeat();
	bool Check_PCB_IMEI1_Repeat();
	bool Check_PCB_IMEI2_Repeat();
	bool Check_PCB_IMEI3_Repeat();
	bool Check_PCB_IMEI4_Repeat();
	bool FP_WriteAndRead_IMEI();
	bool FP_WriteAndRead_SimpleIMEI();
	bool FP_WriteAndRead_DoubleIMEI();
	bool FP_WriteAndRead_ThreeIMEI();
	bool FP_WriteAndRead_FourIMEI();
	char Ascii2BCD(char iAscii);
	META_RESULT REQ_ReadFromNVRAM(void);
	META_RESULT REQ_WriteNVRAM(void);
	bool CheckNetRepeatFinal();
	bool DisconnectInMetaMode();
	void SP_Exit_MetaModemMode();
	int  GetCurrentComPort();
	bool DisconnectInApMeta();
	bool Switch_AP_TO_MEDEM_META_Mode(int comport);
    bool AP_CheckMAC();
	void SaveLogToFile();
	bool SP_CHECK_NV();


    bool CheckBoardVersion(CString str);
	CString VariantToCString(VARIANT   var);
	BOOL CheckIMEI1();
	BOOL CheckIMEI2();
	BOOL CheckIMEI3();
	BOOL CheckIMEI4();
	void DisplayWriteNumber_ScanMode();
	bool CheckNetRepeat_ScanMode();
	void CleanUI();
	BOOL CheckPSNLength();
  	BOOL CheckPSNStatic();
	void SetInputCtrEnableWindow(BOOL flag);
	BOOL SaveToMdb_ScanMode();
	bool FPCheckVersion();
	bool GetProductOrderInfo();
	bool Load_Current_Product_Count();
	void UpdateCount(CString strCount);

	BOOL GetSetting();
	BOOL GetOtherIMEI();

	bool SpWriteBarcode();

	int TryToOpenSPKernelComport(int KernelCom_Num);	
	bool QueryEncryptionSupport(int * MetaHandle);
	int GetSPModemInfo_Ex();
	META_RESULT EnterModemMetaToInitModemDB();
	META_RESULT APSwithToModemMeta_Ex();
	META_RESULT ModemSwithToAPMeta();
	META_RESULT LoadModemDatabase(int MDindex);
	SPMETA_DLL::META_RESULT EnterAPMetaMode();
	void SetupMetaModeParameters();
	void Display(CString sMsg,int index=3);
	int ConnectWithPreloader();
	int ConnectWithKernelPort_Ex(SP_METAMODE_e spMetaMode);
	SPMETA_DLL::META_RESULT ExitAPMetaMode();	
	META_RESULT ExitSPModemMeta();
	void SP_Exit_MetaModemMode_New();
	SP_MODEMInfo_s m_sMdInfo;
	bool m_bDSDAProject;
	bool m_bDualModem;
    bool m_bWithoutMD;
	META_Connect_Ex_Req       m_tMetaReq_Ex;
	SPMETA_DLL::MODEM_CAPABILITY_LIST_CNF m_SpMdCapList;
	UINT m_iMDChannelIndex[MAX_MD_CHANNEL_NUM];
	UINT m_iCurMDChanelIndex;
	bool m_bInitExtMDdb;
	bool m_bWorldPhone;
	int m_eMetaMode;
	UINT m_iKernelComport;
	int *m_pMetaStopFlag;
	META_Connect_Report       m_tMetaConnReport_Ex;
	SP_BOOT_ARG_S m_stModeArg;
	bool m_bUseNewConnectMauiMetaAPI;
	bool m_bTargetInMetaMode;
	bool   m_bStopBeforeUSBInsert;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFullWriteView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFullWriteView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFullWriteView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnBtnSelect();
	afx_msg void OnBtnSelectap();
	afx_msg void OnBtnStart();
	afx_msg void OnSelchangeComboComport();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnChangeEditInputimei1();
	afx_msg void OnChangeEditInputimei2();
	afx_msg void OnChangeEditInputpsn();
	afx_msg void OnChangeEditInputimei3();
	afx_msg void OnChangeEditInputimei4();
	afx_msg void OnScanMainImei();
	afx_msg void OnScanALLImei();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FullWriteView.cpp
inline CFullWriteDoc* CFullWriteView::GetDocument()
   { return (CFullWriteDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FULLWRITEVIEW_H__7EAE63C5_2D37_49CC_AC69_0BC0AED0D559__INCLUDED_)
