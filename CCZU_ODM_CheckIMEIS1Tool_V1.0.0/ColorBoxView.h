// ColorBoxView.h : interface of the CColorBoxView class
//
/////////////////////////////////////////////////////////////////////////////
#include "Label.h"
#include "Config.h"
#include "StateList.h"
#include "skapi.h"
#include "METAAPP.h"
#include "META.h"
#include "brom.h"    
#include "flashtool_handle.h" 
#include "SLA_Challenge.h"
#include "interface.h"
#include "MySpMeta.h"

#include "Password.h"
#include "PhoneCommand.h"
#include "sp_brom.h"

#if !defined(AFX_COLORBOXVIEW_H__65D02BA8_820F_4963_A9FA_C6A9AE29763C__INCLUDED_)
#define AFX_COLORBOXVIEW_H__65D02BA8_820F_4963_A9FA_C6A9AE29763C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


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

class CColorBoxView : public CFormView
{
protected: // create from serialization only
	CColorBoxView();
	DECLARE_DYNCREATE(CColorBoxView)

public:
	//{{AFX_DATA(CColorBoxView)
	enum { IDD = IDD_COLORBOX_FORM };
	CLabel	m_cResult;
	CLabel	m_ctrCurrentLine;
	CButton	m_ctrClean;
	CLabel	m_cCurrentCount;
	CLabel	m_ctrCurrentOrder;
	CLabel	m_ctrCurrentColor;
	CButton	m_ctrSelectDBButton;
	CButton	m_ctrSelectAPDBButton;
	CComboBox	m_ctrComboxComPort;
	CEdit	m_ctrIMEI4;
	CEdit	m_ctrIMEI3;
	CEdit	m_ctrIMEI2;
	CEdit	m_ctrIMEI1;
	CStateList	m_state_list;
	CLabel	m_ctrCurrentProduct;
	CString	m_csCurrentProduct;
	CString	m_csIMEI1;
	CString	m_csIMEI2;
	CString	m_csIMEI3;
	CString	m_csIMEI4;
	CString	m_csAPDBPath;
	CString	m_csDBPath;
	CString	m_csCurrentColor;
	CString	m_csCurrentOrder;
	DWORD	m_iFirstKeyTime;
	DWORD	m_iLastKeyTime;
	DWORD	m_iKeyPeriod;
   	VerInfo_Cnf p_verinfo;
	int		m_iComboxComPort;
	CString	m_csCurrentLine;
	//}}AFX_DATA

// Attributes
public:
	CColorBoxDoc* GetDocument();

public:
	void SetMyFont();
	void InsertListInfo(CString state,int imageIndex);
	CString GetCurTimes();
	void SetUIDisableAll();
	CString VariantToCString(VARIANT   var);
	void ClearUI();
	BOOL IMEITYPE_0_CheckImei1();
	BOOL IMEITYPE_1_CheckImei1();
	BOOL IMEITYPE_1_CheckImei2();
	BOOL IMEITYPE_2_CheckImei2();
	BOOL IMEITYPE_2_CheckImei3();
	BOOL IMEITYPE_3_CheckImei3();
	BOOL IMEITYPE_3_CheckImei4();
	BOOL IMEITYPE_0_CheckImei1_Ex();
	BOOL IMEITYPE_1_CheckImei2_Ex();
	BOOL IMEITYPE_2_CheckImei3_Ex();
	BOOL IMEITYPE_3_CheckImei4_Ex();
	void calculate_15_digit_imei( char *imei_14,char &calculate_digit);

	BOOL SaveToColorInfo();
	void OnUpdateData(WPARAM wParam, LPARAM lParam);
	void OnSetMyFocus(WPARAM wParam, LPARAM lParam);
	void ShowCalResult(int state);

public:
	void EnableMobileCtrl(bool flag);
	void LoadComPort();
	void PrintLabel();
	bool DoInitFPNV();
	bool DoInitSPApNV();
	bool DoInitSPModemNV();
	AUTH_HANDLE_T Get_AuthHandle( void );
	bool FP_ExitMetaMode();
	bool FP_Read_PCB_BARCODE();	
	bool SP_CHECK_NV();
	bool FPCheckVersion();
	bool Read_Mode_Check_Database();
	bool Read_Mode_Check_Database_1IMEI();
	bool Read_Mode_Check_Database_2IMEI();
	bool Read_Mode_Check_Database_3IMEI();
	bool Read_Mode_Check_Database_4IMEI();
	bool SP_Enter_Modem_Meta_by_USB();
	bool SP_Enter_Modem_Meta_by_UART();
	bool DisconnectInMetaMode();
	void SP_Exit_MetaModemMode();
	bool Switch_AP_TO_MODEM_META_Mode(int comport);
	bool DisconnectInApMeta();
	bool Read_Mode_Check_Database_IMEI_Ex();
	bool FP_Read_IMEI_Ex();	
	bool ReadSimpleIMEI_Ex();
	bool ReadDoubleIMEI_Ex();
	bool ReadThreeIMEI_Ex();
	bool ReadFourIMEI_Ex();
	BOOL Check_Read_and_Scan_IMEI();
	bool GetProductOrderInfo();
	bool Load_Current_Product_Count();
	void UpdateCount(CString strCount);
    void CleanImeiWindow();
	BOOL GetSetting();
	BOOL SP_WriteResetFactory2Barcode(); 
	//20150728 glory add follow fun def and member
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
	void SP_Exit_MetaModemMode_NEW();
	SP_MODEMInfo_s m_sMdInfo;
	//int m_hSPMetaHandle;
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
	//end
public:
	CConfig m_Config;
	CImageList m_imageList;
	CFont m_staticfont;
	CFont m_staticfont3;
	CFont m_staticfont4;
	int m_iIMEIType;
	int m_iIMEIRangeType;
	int m_iPlatform;
	CString m_csConfigPath;
	BOOL m_checkColorDone;

	CString m_csErrorSndPath;    
	CString m_csOkSndPath;
	CString m_csPcbaSN;
	CString m_csPcbaBarcode;
	CString m_csAPPcbaSN;
	int     m_iPSNLen;

	//CHECK NV
	int m_iBTFT;
	int m_iResetFactory;

	int m_iCheckVersion;
	CString m_csVersion;
	int m_iCheckAPSN;


	//展讯
	SP_HANDLE  g_hDiagPhone;
	int        nErrorCode;
	HANDLE     m_hEnterModeSuccess;
	
	bool EnterSPRD();
    bool CheckApVer_SPRD(CString sAPVersionToCompare);
	bool ReadBarCode_SPRD(CString& sBarcode);
	bool WriteFactoryResetFlag_SPRD();
    
public:  
	CString m_imei1_start;
	CString m_imei1_end;
	CString m_imei2_start;
	CString m_imei2_end;
	CString m_imei3_start;
	CString m_imei3_end;
	CString m_imei4_start;
	CString m_imei4_end;

public:
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

	HANDLE m_hThreadFPStart_Ex;
	DWORD	m_dThreadIdFPStart_Ex;
	HANDLE m_hThreadSPStart_Ex;
	DWORD	m_dThreadIdSPStart_Ex;

public:
	METAAPP_RESULT m_MetaappResult;
	META_RESULT    m_MetaResult;
	int m_nMetaHandle;
	CMySpMeta m_ApExe;

	META_Connect_Req META_connect_req; 
	META_Connect_Report META_connect_report;
	AUTH_HANDLE_T  m_sAuthHandle;
	
	//summer 20110826 begin
	BBCHIP_TYPE  m_UARTCOM;                       //MT6236平台写蓝牙失败问题
	BBCHIP_TYPE  m_USBCOM;						  //MT6236平台写蓝牙失败问题
	//summer 20110826 end	

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

	CString	m_csIMEI1_Ex;
	CString	m_csIMEI2_Ex;
	CString	m_csIMEI3_Ex;
	CString	m_csIMEI4_Ex;
	CString m_csCurrentCount;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorBoxView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CColorBoxView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
// Generated message map functions
protected:
	//{{AFX_MSG(CColorBoxView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnChangeEditImei1();
	afx_msg void OnChangeEditImei2();
	afx_msg void OnChangeEditImei3();
	afx_msg void OnChangeEditImei4();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMode1();
	afx_msg void OnMode2();
	afx_msg void OnMode3();
	afx_msg void OnBtnSelect();
	afx_msg void OnBtnSelectap();
	afx_msg void OnScanMainImeiYes();
	afx_msg void OnScanMainImeiNo();
	afx_msg void OnBtnClean();
	afx_msg void OnSelchangeComboComport();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ColorBoxView.cpp
inline CColorBoxDoc* CColorBoxView::GetDocument()
   { return (CColorBoxDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORBOXVIEW_H__65D02BA8_820F_4963_A9FA_C6A9AE29763C__INCLUDED_)
