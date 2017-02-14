// FullWriteView.cpp : implementation of the CFullWriteView class
//

#include "stdafx.h"
#include "FullWrite.h"
#include "Splash.h"
#include "FullWriteDoc.h"
#include "FullWriteView.h"
#include "Password.h"
#include <math.h>
#include "sp_brom.h" //water
#include ".\Common\Common.h"

#include "PhaseCheckExport.h"

#define RFT_SUCCESS         0

#define IDLE                101
#define FAIL                102
#define PASS                103
#define Testing             104
#define InitFail            105
#define BT_ADDRESS_MAX_LENGTH  ( BD_ADDR_LEN * 2 )
#define MAC_ADDR_LEN  6
#define WIFI_MAC_MAX_LENGTH  ( MAC_ADDR_LEN * 2 )
#define USB_VCOM             17
#define META_CONNECT_TIME_OUT  80000  //30000
#define  PID_ANDROID       "2000"
#define  VID_ANDROID       "0E8D"
#define  PID                      PID_ANDROID
#define  VID                      VID_ANDROID
#define  InterfaceClassGuidConstant  Guid_ANDROID_USB2Ser

HANDLE m_ReadFromNVRAMEvent;
HANDLE m_WriteToNVRAMEvent;

//20150728 glory add
#ifndef PreloaderUSB
#define  PreloaderUSB  1
#endif
#ifndef BootROMUSB
#define  BootROMUSB   0
#endif
static const GUID GUID_PORT_CLASS_USB2SER ={0x4D36E978L,0xE325,0x11CE,{0xBF,0xC1,0x08,0x00,0x2B,0xE1,0x03,0x18}};
//end
//20150728 glory add global variament
META_Common_struct g_sMetaComm;
int  g_iMetaStopFlag;
#define  ERROR 0
#define  OK 1
char* ResultToString(int MR);
#define CWriteToolDlg CColorBoxView
//end

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFullWriteView

IMPLEMENT_DYNCREATE(CFullWriteView, CFormView)

BEGIN_MESSAGE_MAP(CFullWriteView, CFormView)
	//{{AFX_MSG_MAP(CFullWriteView)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BTN_SELECT, OnBtnSelect)
	ON_BN_CLICKED(IDC_BTN_SELECTAP, OnBtnSelectap)
	ON_BN_CLICKED(IDC_BTN_START, OnBtnStart)
	ON_CBN_SELCHANGE(IDC_COMBO_COMPORT, OnSelchangeComboComport)
	ON_WM_CREATE()
	ON_EN_CHANGE(IDC_EDIT_INPUTIMEI1, OnChangeEditInputimei1)
	ON_EN_CHANGE(IDC_EDIT_INPUTIMEI2, OnChangeEditInputimei2)
	ON_EN_CHANGE(IDC_EDIT_INPUTPSN, OnChangeEditInputpsn)
	ON_EN_CHANGE(IDC_EDIT_INPUTIMEI3, OnChangeEditInputimei3)
	ON_EN_CHANGE(IDC_EDIT_INPUTIMEI4, OnChangeEditInputimei4)
	ON_COMMAND(IDM_SCAN_MAIN_IMEI, OnScanMainImei)
	ON_COMMAND(IDM_SCAN_ALL_IMEI, OnScanALLImei)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_CAL_MSG,OnGetMessage)
	ON_MESSAGE(WM_UPDATEDATA,OnUpdateData)
	ON_MESSAGE(WM_SETMYFOCUS,OnSetMyFocus)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFullWriteView construction/destruction

CFullWriteView::CFullWriteView()
	: CFormView(CFullWriteView::IDD)
{
	//{{AFX_DATA_INIT(CFullWriteView)
	m_iComboxComPort = -1;
	m_csAPDBPath = _T("");
	m_csDBPath = _T("");
	m_csInputIMEI1 = _T("");
	m_csInputIMEI2 = _T("");
	m_csInputPSN = _T("");
	m_csCurrentProduct = _T("");
	m_csCurrentOrder = _T("");
	m_csCurrentColor = _T("");
	m_csInputIMEI3 = _T("");
	m_csInputIMEI4 = _T("");
	m_csCurrentLine = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	//20150730 GLORY add
	g_iMetaStopFlag = 0;
	m_pMetaStopFlag = &g_iMetaStopFlag;
	if(strlen(g_sMetaComm.sPortFilter.strBromFilter) <= 0)
		sprintf(g_sMetaComm.sPortFilter.strBromFilter,"%s","VID_0E8D&PID_0003");
	if(strlen(g_sMetaComm.sPortFilter.strPreloaderFilter) <= 0)
		sprintf(g_sMetaComm.sPortFilter.strPreloaderFilter, "%s", "VID_0E8D&PID_2000");
	if(strlen(g_sMetaComm.sPortFilter.strKernelFilter) <= 0)
		sprintf(g_sMetaComm.sPortFilter.strKernelFilter, "%s", "VID_0E8D&PID_2000");	
	//end
}

CFullWriteView::~CFullWriteView()
{
}

void CFullWriteView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFullWriteView)
	DDX_Control(pDX, IDC_STATIC_CURRENT_LINE, m_ctrCurrentLine);
	DDX_Control(pDX, IDC_EDIT_INPUTIMEI4, m_ctrInputIMEI4);
	DDX_Control(pDX, IDC_EDIT_INPUTIMEI3, m_ctrInputIMEI3);
	DDX_Control(pDX, IDC_STATIC_CURRENT_COLOR, m_ctrCurrentColor);
	DDX_Control(pDX, IDC_STATIC_CURRENT_ORDER, m_ctrCurrentOrder);
	DDX_Control(pDX, IDC_STATIC_CURRENT_PRODUCT, m_ctrCurrentProduct);
	DDX_Control(pDX, IDC_STATIC_CURRENT_COUNT, m_cCurrentCount);
	DDX_Control(pDX, IDC_EDIT_INPUTPSN, m_ctrInputPSN);
	DDX_Control(pDX, IDC_EDIT_INPUTIMEI2, m_ctrInputIMEI2);
	DDX_Control(pDX, IDC_EDIT_INPUTIMEI1, m_ctrInputIMEI1);
	DDX_Control(pDX, IDC_STATIC_RESULT, m_cResult);
	DDX_Control(pDX, IDC_RICHEDIT_TRACE, m_cedTrace);
	DDX_Control(pDX, IDC_BTN_SELECTAP, m_ctrSelectAPDBButton);
	DDX_Control(pDX, IDC_BTN_SELECT, m_ctrSelectDBButton);
	DDX_Control(pDX, IDC_COMBO_COMPORT, m_ctrComboxComPort);
	DDX_CBIndex(pDX, IDC_COMBO_COMPORT, m_iComboxComPort);
	DDX_Text(pDX, IDC_EDIT_APDBPATH, m_csAPDBPath);
	DDX_Text(pDX, IDC_EDIT_DBPATH, m_csDBPath);
	DDX_Text(pDX, IDC_EDIT_INPUTIMEI1, m_csInputIMEI1);
	DDX_Text(pDX, IDC_EDIT_INPUTIMEI2, m_csInputIMEI2);
	DDX_Text(pDX, IDC_EDIT_INPUTPSN, m_csInputPSN);
	DDX_Text(pDX, IDC_STATIC_CURRENT_PRODUCT, m_csCurrentProduct);
	DDX_Text(pDX, IDC_STATIC_CURRENT_ORDER, m_csCurrentOrder);
	DDX_Text(pDX, IDC_STATIC_CURRENT_COLOR, m_csCurrentColor);
	DDX_Text(pDX, IDC_EDIT_INPUTIMEI3, m_csInputIMEI3);
	DDX_Text(pDX, IDC_EDIT_INPUTIMEI4, m_csInputIMEI4);
	DDX_Text(pDX, IDC_STATIC_CURRENT_LINE, m_csCurrentLine);
	//}}AFX_DATA_MAP
}


static  void __stdcall CNF_WriteNVRAM( const FT_NVRAM_WRITE_CNF *cnf, const short token, void *usrData)
{
    if (cnf->status != META_SUCCESS)
    {  
		return; 
	}
	SetEvent (m_WriteToNVRAMEvent);   
}


static void __stdcall CNF_ReadFromNVRAM(const FT_NVRAM_READ_CNF *cnf, const short token, void *usrData)
{
	if (cnf->status != META_SUCCESS)
    {  
		return; 
	}	
	SetEvent(m_ReadFromNVRAMEvent);   
}


//-----------------------------------------------
META_RESULT CFullWriteView::REQ_ReadFromNVRAM(void)
{
    DWORD wait_result;
	short int m_sNVRAM_OPID;
	
    m_ReadFromNVRAMEvent = CreateEvent( NULL, TRUE, FALSE, NULL);
	
    ResetEvent(m_ReadFromNVRAMEvent);
	
    m_MetaResult = META_NVRAM_Read_r(m_nMetaHandle,&tNVRAM_ReadReq,&tNVRAM_ReadCnf,CNF_ReadFromNVRAM,&m_sNVRAM_OPID,NULL);
	
    wait_result = WaitForSingleObject(m_ReadFromNVRAMEvent,15000);
	
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


//-----------------------------------------------
META_RESULT CFullWriteView::REQ_WriteNVRAM(void)
{
	short int m_sNVRAM_OPID;
	DWORD wait_result;
	
    m_WriteToNVRAMEvent = CreateEvent(NULL,TRUE,FALSE,NULL);
	
    ResetEvent (m_WriteToNVRAMEvent);
	
    m_MetaResult = META_NVRAM_Write_r (m_nMetaHandle,&tNVRAM_WriteReq,CNF_WriteNVRAM,&m_sNVRAM_OPID,NULL);
	
    wait_result = WaitForSingleObject (m_WriteToNVRAMEvent, 15000 );
	
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


//初始化FIXTURE PHONE NV
void InitFPNV(LPVOID x)
{
	CFullWriteView *Sv = (CFullWriteView *)x;

	Sv->m_Config.ReadConfig();

	if(!Sv->DoInitFPNV())
	{
		Sv->Display("Init Modem NV Fail...",1);
		Sv->ShowCalResult(InitFail);
		return;
	}
	
	Sv->Display("Init Modem NV  Pass...",0);
	Sv->ShowCalResult(IDLE);
}


//初始化SMART PHONE NV
void InitSPNV(LPVOID x)
{
	CFullWriteView *Sv = (CFullWriteView *)x;

	Sv->m_Config.ReadConfig();

	if(!Sv->DoInitSPModemNV())
	{
		Sv->Display("Init Modem NV Fail...",1);
		Sv->ShowCalResult(InitFail);
		return;
	}
	else
	{
		Sv->Display("Init Modem NV Pass...",0);
	}
	
	if(!Sv->DoInitSPApNV())
	{
		Sv->Display("Init AP NV Fail...",1);
		Sv->ShowCalResult(InitFail);
		return;
	}
	
	Sv->Display("Init AP NV Pass...",0);
	Sv->ShowCalResult(IDLE);
}

void SmartStart_ScanMode_New(CFullWriteView* Sv)
{
	CString sInfo;
	int iRet = 0;
	bool bAnyOperationFail = false;	

 	Sv->SetupMetaModeParameters();


#ifdef _DEBUG
	Sv->m_iPSdata=1;
	Sv->m_iCheckColor=1;
	Sv->m_iSIMLock=0;
	Sv->m_iCheckVersion=0;
	Sv->m_iSIMUnLock=0;
	Sv->m_iDTV=0;
	Sv->m_iCheckWIFIMAC=1;
	Sv->m_iWritePSNToPhone=1;
	Sv->m_iODMDTV=0;
#endif
	
	///////////////////////////////////////
	//20150728 glory add first into AP MODE
	///////////////////////////////////////
	META_RESULT MetaResult = META_SUCCESS;
	//EnterAPMetaMode
 	if(Sv->EnterAPMetaMode() != SPMETA_DLL::META_SUCCESS)
	{			
		Sv->CleanUI();
		Sv->ShowCalResult(FAIL);
		Sv->Display("Enter ap Meta Modem Mode Fail",1);
		Sv->SP_Exit_MetaModemMode_New();
		Sv->SetInputCtrEnableWindow(TRUE);
		return;
	}
	//SPMETA_DLL::SP_META_QueryIfFunctionSupportedByTarget_r
	if(SPMETA_DLL::META_SUCCESS == SPMETA_DLL::SP_META_QueryIfFunctionSupportedByTarget_r(Sv->m_ApExe.iMetaAP_handle, 500, "SP_META_ENCRYPTED_Support_r"))
	{
	//QueryEncryptionSupport
		if(Sv->QueryEncryptionSupport(&(Sv->m_ApExe.iMetaAP_handle)));
	}
	Sv->Display("GetSPModemInfo_Ex(): Query modem information start...");
	//GetSPModemInfo_Ex
	iRet = Sv->GetSPModemInfo_Ex(); 
	if (iRet == 0)
	{
		Sv->Display("GetSPModemInfo_Ex(): Query modem information successfully!!");
	} 
	else
	{		
		Sv->CleanUI();
		Sv->ShowCalResult(FAIL);
		bAnyOperationFail = true;
		sInfo.Format("GetSPModemInfo_Ex(): Query modem information fail, MetaResult = %s", ResultToString_SP(iRet));
		Sv->Display(sInfo);
		Sv->SP_Exit_MetaModemMode_New();
		Sv->SetInputCtrEnableWindow(TRUE);
		return;
	}
	//1.读取版本号和比较版本号
	//2.读取距离感校准数据

	//lucky 20151215读取检测外部版本号
	if(Sv->m_iCheckVersion)
 	{
		CString get_swver;
		CString temp_ver;
		get_swver = Sv->m_ApExe.SP_REQ_GetVersion_2();
		get_swver.Replace("\n", "");

 		if(get_swver.GetLength()<3)
 		{
 			Sv->Display("Read version FAIL...",1);
 			Sv->ShowCalResult(FAIL);
 			Sv->CleanUI();
			Sv->SP_Exit_MetaModemMode_New();
 			return;
 		}
		else
 		{
 			Sv->Display("Read version Pass...",0);
 		}

 		if(get_swver.Compare(Sv->m_csVersion) != 0)
 		{

 			temp_ver.Format("Comparison version number failed... %s, %s", get_swver, Sv->m_csVersion);
 			Sv->Display((LPSTR)(LPCTSTR)temp_ver,1);
			temp_ver.Format("%s, %s", get_swver, Sv->m_csVersion);
			Sv->Display((LPSTR)(LPCTSTR)temp_ver,1);  
 			Sv->ShowCalResult(FAIL);
 			Sv->CleanUI();
			Sv->SP_Exit_MetaModemMode_New();
 			return;
 		}
 		else
 		{
 			Sv->Display("Comparison version number success...",0);
 		}
 	}
	//end

	///////////////////////////////////////
	//20150728 glory add then into MODEM MODE
	///////////////////////////////////////
	META_RESULT eMeta_Result = Sv->EnterModemMetaToInitModemDB();
	if(META_SUCCESS == eMeta_Result)
	{
		Sv->Display("EnterModemMetaToInitModemDB(): Query modem information successfully!!");
	}
	else
	{    		
		Sv->CleanUI();
		Sv->ShowCalResult(FAIL);
		bAnyOperationFail = true;
		sInfo.Format("EnterModemMetaToInitModemDB() : MetaResult = %s", ResultToString(eMeta_Result));
		Sv->Display(sInfo.GetBuffer(sInfo.GetLength()));
		Sv->SP_Exit_MetaModemMode_New();
		return;
	}

	CString temp;
	if(!Sv->FP_Read_PCB_BARCODE())
	{
 		Sv->Display("Read phone internal SN failed...",1);
 		Sv->CleanUI();
 		Sv->SetInputCtrEnableWindow(TRUE);
 		Sv->SP_Exit_MetaModemMode_New();
 		Sv->ShowCalResult(FAIL);
 		return;
	}
	else
 	{
 		temp.Format("Read the phone inside SN = %s",Sv->m_csPcbaSN); 
 		Sv->Display((LPSTR)(LPCTSTR)temp,0);
	}	

	
	if(!Sv->SP_CHECK_NV())
	{
		Sv->Display("Check NVRAM Fail...",1);
		Sv->CleanUI();
		Sv->SetInputCtrEnableWindow(TRUE);
		Sv->SP_Exit_MetaModemMode_New();
		Sv->ShowCalResult(FAIL);
		return;
	}
	else
	{
		Sv->Display("Check NVRAM Pass...",0);
	}

	if(!Sv->FP_Read_IMEI())
	{
		Sv->CleanUI();
		Sv->SetInputCtrEnableWindow(TRUE);
		Sv->SP_Exit_MetaModemMode_New();
		Sv->ShowCalResult(FAIL);
		return;
	}
#ifndef NOSQL	
	if(!Sv->Check_PCB_Net_Repeat())
	{
		Sv->Display("Mobile phone internal number database failed to detect...",1);
		Sv->CleanUI();
		Sv->SetInputCtrEnableWindow(TRUE);
		Sv->SP_Exit_MetaModemMode_New();
		Sv->ShowCalResult(FAIL);
		return;
	}
	else
#endif
	{
		Sv->Display("Mobile phone internal numbers, the number of data base detection success...",0);
	}
	
	if(!Sv->FP_WriteAndRead_IMEI())
	{
		Sv->CleanUI();
		Sv->SetInputCtrEnableWindow(TRUE);
		Sv->SP_Exit_MetaModemMode_New();
		Sv->ShowCalResult(FAIL);
		Sv->SaveLogToFile();
		return;
	}

	//PSN替换手机内部SN并写入手机
 	if (Sv->m_iWritePSNToPhone)
 	{
 		if(!Sv->SpWriteBarcode())
 		{
 			Sv->Display("PSN number substitution fail...",1);
 			Sv->CleanUI();
 			Sv->SetInputCtrEnableWindow(TRUE);
 			Sv->SP_Exit_MetaModemMode_New();
 			Sv->ShowCalResult(FAIL);
 			return;
 		}
 		else
 		{
 			Sv->Display("PSN number substitution success...",0);
 		}
 	}
	///////////////////////////////////////
	//切换到AP模式下
	///////////////////////////////////////
	eMeta_Result = Sv->ModemSwithToAPMeta();
	if(META_SUCCESS != eMeta_Result)
	{		 
		Sv->Display("quit Moedm Meta Fail...",1);
		Sv->ShowCalResult(FAIL);
		Sv->SP_Exit_MetaModemMode_New();
		Sv->CleanUI();
		return;
	}

	//读取AP端barcode	
	CString APSN;
	APSN = Sv->m_ApExe.ApReadBarcode(63);


	//AP写入barcode
	if(!Sv->m_ApExe.ApWriteBarcode(Sv->m_csPcbaSN))
	{
		Sv->Display("AP write barcode failed...",1);
		Sv->CleanUI();
		Sv->SetInputCtrEnableWindow(TRUE);
		Sv->SP_Exit_MetaModemMode_New();
		Sv->ShowCalResult(FAIL);
		return;
	}
	else
	{
		Sv->Display("AP write barcode Pass...",0);
	}

	//AP写入PSN，再读出后比较

 	if (Sv->m_iWritePSNToPhone)
 	{
 		CString SNtemp;
 
 		if(!Sv->m_ApExe.ApWriteBarcode(Sv->m_csWriteSN))
 		{
 			Sv->Display("AP write PSN fail...",1);
 			Sv->CleanUI();
 			Sv->SetInputCtrEnableWindow(TRUE);
			Sv->SP_Exit_MetaModemMode_New();
			Sv->ShowCalResult(FAIL);
 			return;
 		}
 		else
 		{
 			Sv->Display("AP write PSN success...",0);
 		}
 
 		Sleep(1000);
 
 		SNtemp = Sv->m_ApExe.ApReadBarcode(Sv->m_csWriteSN.GetLength());
 		
 		if(Sv->m_csWriteSN != SNtemp)
 		{
			Sv->Display("AP read and PSN write are different...",1);
			Sv->CleanUI();
 			Sv->SetInputCtrEnableWindow(TRUE);
 			Sv->SP_Exit_MetaModemMode_New();
 			Sv->ShowCalResult(FAIL);
 			return;
 		}
 		else
 		{
 			Sv->Display("AP read and PSN write are the same...",0);
 		}
 	}
 
 	if(!Sv->m_ApExe.WM_META_SetCleanBootFlag_Customize())
 	{
 		Sv->Display("Backup NVRAM and clear Boot Flag fail...",1);
 		Sv->CleanUI();
 		Sv->SetInputCtrEnableWindow(TRUE);
		Sv->ShowCalResult(FAIL);
 		Sv->SP_Exit_MetaModemMode_New();
 		Sv->SaveLogToFile();
 		return;
	}
 	else
 	{
 		Sv->Display("Backup NVRAM and clear Boot Flag success...",0);
	}
	
#ifndef NOSQL	
	if(!Sv->SaveToMdb_ScanMode())
	{
		Sv->Display("Save database failure...",1);
		Sv->CleanUI();
		Sv->SetInputCtrEnableWindow(TRUE);
		Sv->SP_Exit_MetaModemMode_New();
		Sv->ShowCalResult(FAIL);
		Sv->SaveLogToFile();
		return;
	}
	else
#endif
	{
		Sv->Display("Save database successfully...",0);
	}
	
	Sv->Display("Start checking whether all data has been saved to the database...",0);
#ifndef NOSQL	
	if(!Sv->CheckNetRepeatFinal())
	{
		Sv->CleanUI();
		Sv->SetInputCtrEnableWindow(TRUE);
		Sv->SP_Exit_MetaModemMode_New();
		Sv->ShowCalResult(FAIL);
		Sv->SaveLogToFile();
		return;
	}
#endif	
	///////////////////////////////////////
	//保存数据成功，准备退出
	///////////////////////////////////////
	Sv->SP_Exit_MetaModemMode_New();
	Sv->SetInputCtrEnableWindow(TRUE);
	Sv->CleanUI();
	Sv->ShowCalResult(PASS);
#ifndef NOSQL		
	if(!Sv->Load_Current_Product_Count())
	{
		Sv->Display("To obtain the number of current orders has failed",1);
		return;
	}
#endif
	Sv->Display("Obtain the number of current orders has been successful",0);
	Sv->UpdateCount(Sv->m_csCurrentCount);
}





void SmartStart_ScanMode(LPVOID x) 
{	
	CFullWriteView *Sv = (CFullWriteView *)x;
	Sv->m_cedTrace.SetWindowText("");
	SendMessage(Sv->m_hWnd, WM_UPDATEDATA, TRUE, FALSE);
	Sv->ShowCalResult(Testing);	

	if(Sv->m_ctrComboxComPort.GetCurSel()==-1)
	{
		Sv->Display("Comport Fail!",1);
		Sv->ShowCalResult(FAIL);
		Sv->CleanUI();
		return;
	}

	Sv->CleanAndSetBuffer();
	
	Sv->DisplayWriteNumber_ScanMode();
	//20150801 GLORY
#ifndef NOSQL	
	if(!Sv->CheckNetRepeat_ScanMode())
	{
		Sv->Display("Number database to be written test failed...",1);
		Sv->SetInputCtrEnableWindow(TRUE);
		Sv->ShowCalResult(FAIL);
		Sv->CleanUI();
		return;
	}
	else
#endif
	//end
	{
		Sv->Display("Number database to be written to detect success...",0);
	}
	
	Sv->SetInputCtrEnableWindow(FALSE);
	
	CString text;
	Sv->m_ctrComboxComPort.GetLBText(Sv->m_ctrComboxComPort.GetCurSel(),text);
	if(text=="USB")
	{
		//---------------------------------------
		//用新的线程函数处理检测功能
		SmartStart_ScanMode_New(Sv);
		return;
	}
}


void SPRDStart(LPVOID x)
{
	CFullWriteView *Sv = (CFullWriteView *)x;
	Sv->m_cedTrace.SetWindowText("");
	SendMessage(Sv->m_hWnd, WM_UPDATEDATA, TRUE, FALSE);
	Sv->ShowCalResult(Testing);

	if(Sv->m_ctrComboxComPort.GetCurSel()==-1)
	{
		Sv->Display("Select Comport Fail!",1);
		Sv->ShowCalResult(FAIL);
		Sv->CleanUI();
		return;
	}

	Sv->CleanAndSetBuffer();

	Sv->DisplayWriteNumber_ScanMode();

#ifndef _DEBUG
	if(!Sv->CheckNetRepeat_ScanMode())
	{
		Sv->Display("The Input IMEI Is Already Exist In Server FAIL",1);
		Sv->SetInputCtrEnableWindow(TRUE);
		Sv->ShowCalResult(FAIL);
		Sv->CleanUI();
		Sv->SetInputCtrEnableWindow(TRUE);
		return;
	}
	else
	{
		Sv->Display("The Input IMEI Is Not Already Exist In Server Pass...",0);
	}
#endif
	
	Sv->SetInputCtrEnableWindow(FALSE);
	
	//展讯常规模式
	Sv->Display(">>>>>Begin To Enter Sprd Mode...",0);
	
	if (!Sv->EnterSPRD())
	{
		Sv->Display(">>>>>Enter Sprd Mode Fail...",1);
		Sv->CleanUI();
		Sv->SetInputCtrEnableWindow(TRUE);
		Sv->ShowCalResult(FAIL);
		Sv->SetInputCtrEnableWindow(TRUE);
		return;
	}
	else
	{
		Sv->Display(">>>>>Enter Sprd Mode Pass...",0);
	}

	//比对外部版本号
	if(Sv->m_iCheckVersion)
	{
		if(!Sv->CheckApVer_SPRD(Sv->m_csVersion))
		{
 			Sv->Display("Check AP Version Fail...",1);
			Sv->CleanUI();
			SP_StopModeProcess(Sv->g_hDiagPhone);
			SP_EndPhoneTest(Sv->g_hDiagPhone);
			Sv->SetInputCtrEnableWindow(TRUE);
			Sv->ShowCalResult(FAIL);
			return;
		}
		else
		{
			Sv->Display("Check AP Version Pass...",0);
		}
	
	}	

	//读取SN	
	CString temp;
	if(!Sv->FP_Read_PCB_BARCODE())
	{
 		Sv->Display("Read Module SN Fail...",1);
 		SP_StopModeProcess(Sv->g_hDiagPhone);
 		SP_EndPhoneTest(Sv->g_hDiagPhone);
 		Sv->CleanUI();
 		Sv->SetInputCtrEnableWindow(TRUE);
 		Sv->ShowCalResult(FAIL);
 		return;
	}
 	else
 	{
 		temp.Format("Read Module SN = %s",Sv->m_csPcbaSN);
 		Sv->Display((LPSTR)(LPCTSTR)temp,0);
 	}
	
	//比对主板型号 ok
	if(Sv->m_iCheckBoardVersion)
	{
		char OPS[6] = "";			 
		for(int i = 0;i < 5;i++)
		{
			OPS[i] = Sv->m_csPcbaSN.GetAt(i);			  
		}
		OPS[5] = '\0';
		CString csOPS;
		csOPS.Format("%s",OPS);
	
		if(!Sv->CheckBoardVersion(csOPS))
		{
 			Sv->Display("NVRAM:Check Mainboard Version Fail...",1);
			Sv->Display((LPSTR)(LPCTSTR)csOPS,1);
			SP_StopModeProcess(Sv->g_hDiagPhone);
			SP_EndPhoneTest(Sv->g_hDiagPhone);
			Sv->CleanUI();
			Sv->SetInputCtrEnableWindow(TRUE);
			Sv->ShowCalResult(FAIL);
			return;
		}
		else
		{
			Sv->Display("NVRAM:Check Mainboard Version Pass...",0);
			Sv->Display((LPSTR)(LPCTSTR)csOPS,0);
		}		
	}

	//读取Barcode
	if(!Sv->ReadBarCode_SPRD(Sv->m_csPcbaBarcode))
	{
		Sv->Display("Barcode Read Fail...",1);
		Sv->Display((LPSTR)(LPCTSTR)Sv->m_csPcbaBarcode,1);
		SP_StopModeProcess(Sv->g_hDiagPhone);
		SP_EndPhoneTest(Sv->g_hDiagPhone);
		Sv->CleanUI();
		Sv->SetInputCtrEnableWindow(TRUE);
		Sv->ShowCalResult(FAIL);
		return;
	}
	else
	{
		Sv->Display("Barcode Read Pass...",0);
		Sv->Display((LPSTR)(LPCTSTR)Sv->m_csPcbaBarcode,0);
	}

	//校准终测结果 ok
	int nErrorCode = RFT_SUCCESS; 
	char m_szCurrentStation[]="IMEI";
	char m_szCheckStation[]="CFT";
	if(Sv->m_iBTFT)
	{
		SPPH_OBJECT m_hPhaseCheckObj = CreatePhaseCheckObject(Sv->g_hDiagPhone);
		if(m_hPhaseCheckObj!=NULL)
        {
            	// PutProperty(m_hPhaseCheckObj, SPPH_VERSION, SPPH_SP09);
            nErrorCode =CheckPhase(m_hPhaseCheckObj,m_szCurrentStation,m_szCheckStation);
        }
        else
        {
 			Sv->Display("Read CFT Fail...",1);
			SP_StopModeProcess(Sv->g_hDiagPhone);
			SP_EndPhoneTest(Sv->g_hDiagPhone);
			Sv->CleanUI();
			Sv->SetInputCtrEnableWindow(TRUE);
			Sv->ShowCalResult(FAIL);
			return;
        }
		if(nErrorCode != RFT_SUCCESS)	
		{
 			Sv->Display("Check CFT Fail...",1);
			SP_StopModeProcess(Sv->g_hDiagPhone);
			SP_EndPhoneTest(Sv->g_hDiagPhone);
			Sv->CleanUI();
			Sv->SetInputCtrEnableWindow(TRUE);
			Sv->ShowCalResult(FAIL);
			return;
		}
		Sv->Display("Check CFT Pass...",0);     		
	}

	
	//Check IMEI
	if(!Sv->FP_Read_IMEI())
	{
 		SP_StopModeProcess(Sv->g_hDiagPhone);
		SP_EndPhoneTest(Sv->g_hDiagPhone);
		Sv->CleanUI();
		Sv->SetInputCtrEnableWindow(TRUE);
		Sv->ShowCalResult(FAIL);
		return;
	}
#ifndef _DEBUG	

	if(!Sv->Check_PCB_Net_Repeat())
	{
 		Sv->Display("The IMEI Number Of TelePhone Is Already Exist In Server Fail",1);
		SP_StopModeProcess(Sv->g_hDiagPhone);
		SP_EndPhoneTest(Sv->g_hDiagPhone);
		Sv->CleanUI();
		Sv->SetInputCtrEnableWindow(TRUE);
		Sv->ShowCalResult(FAIL);
		return;
	}
	else
	{
		Sv->Display("The IMEI Number Of TelePhone Is not Exist In Server Pass",0);
	}
#endif	
	//Write IMEI
	if(!Sv->FP_WriteAndRead_IMEI())
	{
 		SP_StopModeProcess(Sv->g_hDiagPhone);
		SP_EndPhoneTest(Sv->g_hDiagPhone);
		Sv->CleanUI();
		Sv->SetInputCtrEnableWindow(TRUE);
		Sv->ShowCalResult(FAIL);
		Sv->SaveLogToFile();
		return;
	}
 	//Write PSN
 	if (Sv->m_iWritePSNToPhone)
 	{
 		if(!Sv->WriteSN_SPRD(Sv->m_csWriteSN))
 		{
 			SP_StopModeProcess(Sv->g_hDiagPhone);
 			SP_EndPhoneTest(Sv->g_hDiagPhone);
 			Sv->CleanUI();
 			Sv->SetInputCtrEnableWindow(TRUE);
 			Sv->ShowCalResult(FAIL);
 			Sv->SaveLogToFile();
 			return;
 		}
 	}

	SP_StopModeProcess(Sv->g_hDiagPhone);
	SP_EndPhoneTest(Sv->g_hDiagPhone);
#ifndef _DEBUG	
	if(!Sv->SaveToMdb_ScanMode())
	{
		Sv->Display("Save Data To db Fail",1);
		Sv->CleanUI();
		Sv->SetInputCtrEnableWindow(TRUE);
		Sv->ShowCalResult(FAIL);
		Sv->SaveLogToFile();
		return;
	}
	else
	{
		Sv->Display("Save Data To db Pass",0);
	}
	
	Sv->Display("Starting test whether all the data has been saved to the database",0);
	
 	if(!Sv->CheckNetRepeatFinal())
	{
		Sv->CleanUI();
		Sv->SetInputCtrEnableWindow(TRUE);
		Sv->ShowCalResult(FAIL);
		Sv->SaveLogToFile();
		return;
 	}

	Sv->SetInputCtrEnableWindow(TRUE);
	Sv->CleanUI();
	Sv->ShowCalResult(PASS);
	
	if(!Sv->Load_Current_Product_Count())
	{
		Sv->Display("Load Current Product Count  Fail",1);
		return;
	}
	Sv->Display("Load Current Product Count Pass",0);
	Sv->UpdateCount(Sv->m_csCurrentCount);
#endif
	Sv->SetInputCtrEnableWindow(TRUE);
	Sv->CleanUI();
	Sv->ShowCalResult(PASS);
}


bool CFullWriteView::EnterSPRD()
{
	CHANNEL_ATTRIBUTE ca;
	ca.ChannelType = CHANNEL_TYPE_USBMON;
	
	if (!_SPOK(SP_BeginPhoneTest(g_hDiagPhone, &ca)))
    {
        return FALSE;
    }
	
	if (NULL == m_hEnterModeSuccess)
	{
		m_hEnterModeSuccess = CreateEvent(NULL, TRUE, FALSE, NULL);
	}
	ResetEvent(m_hEnterModeSuccess);
	
	SP_EnterModeProcess(g_hDiagPhone, true, -1, RM_CALIBRATION_MODE, m_hEnterModeSuccess, 0);
	
	if (WAIT_OBJECT_0 != WaitForSingleObject(m_hEnterModeSuccess,30000))
	{
		SP_StopModeProcess(g_hDiagPhone);
		SP_EndPhoneTest(g_hDiagPhone);
		ResetEvent(m_hEnterModeSuccess);
		return FALSE;
	}
	else
	{
		ResetEvent(m_hEnterModeSuccess);
	}
	
	return TRUE;
}

bool CFullWriteView::CheckApVer_SPRD(CString sAPVersionToCompare)
{
	CString sAPVersion = "";
	char szRecvBuf[4096] = {0};
	CString temp_ver;
    	//int nOperCode = SP_GetAPVersion(g_hDiagPhone,szRecvBuf,sizeof(szRecvBuf));
    	//int nOperCode = SP_GetMsVersion(g_hDiagPhone,szRecvBuf,sizeof(szRecvBuf));
		int nOperCode = SP_GetExVersion(g_hDiagPhone,szRecvBuf,sizeof(szRecvBuf));
    	
	sAPVersion = szRecvBuf;
	if(nOperCode != 0)
	{
		this->Display("SPRD AP Version Fail...",1);
		return false;
	}
	else
	{
		sAPVersionToCompare.MakeLower();
		sAPVersion.MakeLower();
		
		if (strcmp(sAPVersionToCompare,sAPVersion)==0)
		{
			return TRUE;
		}
		else
		{
			temp_ver.Format("Compare Version Fail... %s, %s", sAPVersion, sAPVersionToCompare);
			this->Display((LPSTR)(LPCTSTR)temp_ver,1);
			return FALSE;
		}
//		return (sAPVersionToCompare == sAPVersion);
	}	
}

#define BARCODE_LEN  63
bool ConvertBarCode(char* intBuf, char* charbuf)
{
	if(!intBuf || !charbuf)  return false;
	try
	{
		for(int i = 0; i < BARCODE_LEN; i++)
		{
			if(i < 17)
				charbuf[i] = ' ';
			else
			{

				if(intBuf[i*4]>=48 && intBuf[i*4]<=57)    
				{    
					charbuf[i] = intBuf[i*4];
				}
				else
				{
					if(intBuf[i*4]>=65 && intBuf[i*4]<=90)
					{
						charbuf[i] = intBuf[i*4];
					}
					else
					{
						if(intBuf[i*4]>=97 && intBuf[i*4]<=122)
						{
							charbuf[i] = intBuf[i*4];
						}
						else
						{
							charbuf[i] = ' ';
						}
					}
				}
			}
		}
		return true;
	}
	catch(...)
	{
		return false;
	}
}



bool CFullWriteView::ReadBarCode_SPRD(CString& sBarcode)
{
    char szBuf[BARCODE_LEN*4] = {0};
	char szReadBuf[BARCODE_LEN+1] = {0};
	int nErrroCode = SP_ReadTraceInfo(g_hDiagPhone, (void *)szBuf, BARCODE_LEN * 4);
	if(RFT_SUCCESS != nErrroCode)
	{
		sBarcode = "";
		return false;
	}	
	else
	{
		if(!ConvertBarCode(szBuf, szReadBuf))
		{
			return false;
		}
		else
			sBarcode = szReadBuf; 
	}
	return (RFT_SUCCESS == nErrroCode);
}


bool CFullWriteView::ReadMAC_SPRD(CString& sMAC)
{
	FASTNVACCESS_T NvReadParam;
	ZeroMemory((void *)&NvReadParam, sizeof(NvReadParam));
	NvReadParam.dwOperMask |= FNAMASK_WRITE_WIFIADDR;
	int nErrorCode =SP_FastReadNvInfo(g_hDiagPhone, &NvReadParam);
	if(RFT_SUCCESS != nErrorCode)
	{
		Display("读取MAC地址失败...",1);
		return false;
	}
	else
	{
		char szMAC[MAX_WIFI_ADDR_STR_LENGTH] = {0};
		strcpy(szMAC, (const char *)NvReadParam.szWIFIAddr);
		sMAC = szMAC;
	}
	return (RFT_SUCCESS == nErrorCode);
}

#define WIMEI_SN_LENGTH_MAXIMIZE  (0x18)
bool CFullWriteView::WriteSN_SPRD(CString sSN)
{
	char *pszN1 = NULL;
	int nErrorCode = RFT_SUCCESS;
	pszN1 = new char[WIMEI_SN_LENGTH_MAXIMIZE];
	ZeroMemory(pszN1, sizeof(char)*WIMEI_SN_LENGTH_MAXIMIZE);
	strcpy(pszN1,sSN.GetBuffer(sSN.GetLength()));
	nErrorCode = SP_WriteSN(g_hDiagPhone, true,  (const void *)pszN1, sSN.GetLength());
	if(RFT_SUCCESS != nErrorCode)
	{
		Display("写PSN失败...",1);
		return false;
	}
	Display("写PSN成功...",0);
	return (RFT_SUCCESS == nErrorCode);
}

BOOL CFullWriteView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CFullWriteView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_hEnterModeSuccess = CreateEvent(NULL, TRUE, FALSE, NULL);

	this->SetMyFont();
	
	this->m_Config.InitConfigPath();

	this->m_Config.ReadConfig();

	m_csCurrentOrder = ((CFullWriteApp *)AfxGetApp())->InputOrder;
	m_csCurrentLine  = ((CFullWriteApp *)AfxGetApp())->InputProductionLine;
	
	this->LoadComPort();
	
	this->SetTimer(1,500,0);
}

/////////////////////////////////////////////////////////////////////////////
// CFullWriteView diagnostics

#ifdef _DEBUG
void CFullWriteView::AssertValid() const
{
	CFormView::AssertValid();
}

void CFullWriteView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CFullWriteDoc* CFullWriteView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFullWriteDoc)));
	return (CFullWriteDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFullWriteView message handlers

void CFullWriteView::SetMyFont()
{
	this->m_ctrCurrentProduct.SetFontSize(18);
	this->m_ctrCurrentProduct.SetFontName("Arial");
	this->m_ctrCurrentProduct.SetTextColor(RGB(0,0,255));

	this->m_ctrCurrentOrder.SetFontSize(18);
	this->m_ctrCurrentOrder.SetFontName("BOLD");
	this->m_ctrCurrentOrder.SetTextColor(RGB(0,0,255));

	this->m_ctrCurrentColor.SetFontSize(18);
	this->m_ctrCurrentColor.SetFontName("BOLD");
	this->m_ctrCurrentColor.SetTextColor(RGB(0,0,255));

	this->m_ctrCurrentLine.SetFontSize(18);
	this->m_ctrCurrentLine.SetFontName("BOLD");
	this->m_ctrCurrentLine.SetTextColor(RGB(0,0,255));

	this->m_cCurrentCount.SetFontSize(30);
	this->m_cCurrentCount.SetFontName("Arial");
	this->m_cCurrentCount.SetTextColor(RGB(0,0,255));

	VERIFY(m_staticfont.CreateFont(
		50,                        // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_BOLD,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		"Arial"));
	
	this->m_cedTrace.SetBackgroundColor(false,RGB(192,255,255));//设置CRichEdit背景颜色
	this->m_cResult.SetFontSize(50);
	this->m_cResult.SetFontName("Arial");

	this->m_cCurrentCount.SetFontSize(30);
	this->m_cCurrentCount.SetFontName("Arial");
	this->m_cCurrentCount.SetTextColor(RGB(0,0,255));
}


void CFullWriteView::LoadComPort()
{
	CString str;
	this->m_ctrComboxComPort.ResetContent();
	int portnum = 0;   
	CHAR port[MAX_PATH];   
	COMMCONFIG comcfg;   
	ULONG BuffSize = sizeof(port);
	for(int i = 0; i< 255 ; i++) 
	{
		m_comnum[i] = 0;
	}
	for( i = 3; i< 255 ; i++)   
	{   		
		_stprintf(port,_T("COM%d"),i);   
		BuffSize = sizeof(port);   
		if(GetDefaultCommConfig(port,&comcfg,&BuffSize))   
		{
			this->m_ctrComboxComPort.AddString(port); 
			m_comnum[portnum++] = i;
		}			
		memset(port,0,sizeof(port));   
	} 	
	m_ctrComboxComPort.SetCurSel(-1);
	this->m_ctrComboxComPort.AddString("USB");
}


void CFullWriteView::OnTimer(UINT nIDEvent) 
{
	CString temp;
	CString csCFGPath;
	HINSTANCE hInstance;
	char direc[MAX_PATH];
	CFileFind findfile;
	int iRet;
	BOOL bIsFinded;
	CString filename;
	if(nIDEvent == 1)
	{
		this->KillTimer(1);
		CFormView::OnTimer(nIDEvent);
		
		this->m_cedTrace.SetWindowText("");
		this->m_Config.ReadConfig();
		
		this->SetBTNEnable(FALSE);

		this->SetInputCtrEnableWindow(FALSE);

		switch (this->m_Config.m_iIsScanMainImei)
		{
		case 0:
			AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_ALL_IMEI, MF_BYCOMMAND | MF_CHECKED );
			Display("The Current Operation Mode：Scan All IMEI Mode...",0);
			break;
		case 1:
			AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_MAIN_IMEI, MF_BYCOMMAND | MF_CHECKED );
			Display("The Current Operation Mode：Scan IMEI1 Mode...",0);
			break;
		default:
			this->m_Config.m_iIsScanMainImei=0;
			this->m_Config.SaveConfig();
			AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_ALL_IMEI, MF_BYCOMMAND | MF_CHECKED );
			Display("The Current Operation Mode：Scan All IMEI Mode...",0);
			break;
		}
#ifndef NOSQL
		if(!this->GetProductOrderInfo())
		{
			Display("Get Product Informmation Fail...",1);
			return;
		}
		else
		{
			Display("Get Product Informmation Pass...",0);
		}

		//获取工具设置
		if(!this->GetSetting())
		{
			Display("Get Product Setting Fail...",1);
			return;
		}
		else
		{
			Display("Get Product Setting Pass...",0);
		}
#else
	#ifdef SPRD
		m_iPlatform = 2;
	#else
		
		m_iPlatform = 2;
		
	#endif
#endif
		if(m_iPlatform==0 || m_iPlatform==1)
		{
#ifndef NOSQL
			//建立远程共享连接
			csCFGPath = this->m_Config.m_csCFGPath.Left(this->m_Config.m_csCFGPath.GetLength()-1);
			
			if (csCFGPath.Left(2) == "\\\\")
			{
				temp.Format("/c net use %s %s /user:%s", csCFGPath, this->m_Config.m_csLoginPSW, this->m_Config.m_csLoginName);
				hInstance = ShellExecute(AfxGetMainWnd()->GetSafeHwnd(),"open","cmd.exe",temp,NULL,SW_HIDE);
				iRet = int(hInstance);
				if (iRet < 32)
				{
					MessageBox("Establish a remote Shared connection Fail!","Error",MB_OK);
					exit(0);
				}
			}
#endif	
#ifndef NOSQL
			//获取服务器DataBase文件存放路径
			csCFGPath = this->m_Config.m_csCFGPath+m_csCurrentProduct+"_"+m_csCurrentOrder+"\\DataBase";
			
			//获取当前文件路径
			GetCurrentDirectory(MAX_PATH,direc);
			
			//如果本地Database文件夹有文件则删除
			bIsFinded = findfile.FindFile(CString(direc)+"\\DataBase\\*");
			while( bIsFinded )
			{
				bIsFinded = (BOOL)findfile.FindNextFile();
				if( !findfile.IsDots() && !findfile.IsDirectory()) 
				{
					filename = findfile.GetFileName();
					DeleteFile(CString(direc)+"\\DataBase\\"+filename);
				}
			}
			findfile.Close();		
			//从服务器copy Database文件至本地
			temp.Format("cmd /c xcopy %s %s /e /i /y", csCFGPath, CString(direc)+"\\DataBase");
#endif	
#ifndef NOSQL			
			//清空结构
			STARTUPINFO sInfo;
			PROCESS_INFORMATION pInfo;
			ZeroMemory(&sInfo,sizeof(sInfo));
			sInfo.cb=sizeof(sInfo);
			sInfo.dwFlags=STARTF_USESHOWWINDOW;
			sInfo.wShowWindow=SW_HIDE;
			ZeroMemory(&pInfo,sizeof(pInfo));
			
			if(!::CreateProcess(NULL,temp.GetBuffer(0),
				NULL,
				NULL,
				FALSE,
				0,
				NULL,
				NULL,
				&sInfo,
				&pInfo))
			{
				MessageBox("Copy Version File Fail!","Error",MB_OK);
				exit(0);
			}
			//等进程关闭
			WaitForSingleObject(pInfo.hProcess,INFINITE);
			//关闭进程和线程的句柄
			CloseHandle(pInfo.hProcess);
			CloseHandle(pInfo.hThread);
#endif	
#ifndef NOSQL
			//获取本地Database文件夹下文件名
			bIsFinded = findfile.FindFile(CString(direc)+"\\DataBase\\*");
			
			while( bIsFinded )
			{
				bIsFinded = (BOOL)findfile.FindNextFile();
				
				if(!findfile.IsDots() && !findfile.IsDirectory())
				{
					filename = findfile.GetFileName();
					
					if (filename.Left(3) == "BPL")
					{
						this->m_csDBPath = CString(direc)+"\\DataBase\\"+filename;
					}
					
					if (filename.Left(4) == "APDB")
					{
						this->m_csAPDBPath = CString(direc)+"\\DataBase\\"+filename;
					}
				}
			}
			
			findfile.Close();
#endif	
		}
#ifdef NOSQL
//		this->m_iIMEIType = 0;
		this->m_csDBPath = "E:\\文档资料\\MTKDB文件\\C3588_DW_C102\\BPLGUInfoCustomAppSrcP_MT6735_S00_MOLY_LR9_W1444_MD_LWTG_MP_V16_P6_1_lwg_n";
		this->m_csAPDBPath = "E:\\文档资料\\MTKDB文件\\C3588_DW_C102\\APDB_MT6735_S01_L1.MP3_W15.23";
#endif
		UpdateData(FALSE);

		if(this->m_iPlatform==0)
		{
			m_hThreadModemNVInit =
				CreateThread (NULL,
				0,     
				(LPTHREAD_START_ROUTINE)InitFPNV,
				(void *)this,  
				0,     
				&m_dThreadIdModemNVInit);
		}
		else if(this->m_iPlatform==1)
		{
			m_hThreadSPNVInit =
				CreateThread (NULL,  
				0,     
				(LPTHREAD_START_ROUTINE)InitSPNV,
				(void *)this,  
				0,     
				&m_dThreadIdSPNVInit);
		}
		else if(this->m_iPlatform==2)
		{
			g_hDiagPhone = SP_CreatePhone(NULL);
			if (INVALID_PHONE_HANDLE == g_hDiagPhone)
			{
				return;
			}
			
			ShowCalResult(IDLE);
		}
#ifndef NOSQL
		if(!this->Load_Current_Product_Count())
		{
			this->Display("Load Current Product Count Fail",1);
			return;
		}
#endif
		this->Display("Load Current Product Count Pass",0);
		this->UpdateCount(this->m_csCurrentCount);

		this->SetBTNEnable(TRUE);
		this->SetInputCtrEnableWindow(TRUE);
	}
}


void CFullWriteView::SetBTNEnable(bool flag)
{
	if(this-m_iPlatform==0)
	{
		this->m_ctrSelectAPDBButton.EnableWindow(FALSE);
	}
	else
	{
		this->m_ctrSelectAPDBButton.EnableWindow(flag);
	}

	this->m_ctrSelectDBButton.EnableWindow(flag);
}


void CFullWriteView::OnBtnSelect()
{
	CPassword dlg;
	dlg.ilevel = 0; //需普通权限验证
	if(dlg.DoModal()!=IDOK)
	{
		return;
	}

	CFileDialog filedlg(TRUE);
	filedlg.m_ofn.lpstrTitle="Select Modem DBFile";
	if(filedlg.DoModal()==IDOK)
	{
		this->m_csDBPath = filedlg.GetPathName();

		if(this->m_csDBPath.IsEmpty())
		{
			
		}
		UpdateData(FALSE);

		m_hThreadModemNVInit =
				CreateThread (NULL,
				0,
				(LPTHREAD_START_ROUTINE)InitFPNV,
				(void *)this, 
				0,
				&m_dThreadIdModemNVInit);
	}
	else
	{
		return;
	}
}


void CFullWriteView::OnBtnSelectap() 
{
	CPassword dlg;
	dlg.ilevel = 0; //需普通权限验证
	if(dlg.DoModal()!=IDOK)
	{
		return;
	}

	CFileDialog filedlg(TRUE);
	filedlg.m_ofn.lpstrTitle="Select AP DBFile";
	if(filedlg.DoModal()==IDOK)
	{
		this->m_csAPDBPath = filedlg.GetPathName();

		if(this->m_csAPDBPath.IsEmpty())
		{
			
		}
		UpdateData(FALSE);

		m_hThreadSPNVInit =
				CreateThread (NULL,  
				0,     
				(LPTHREAD_START_ROUTINE)InitSPNV,
				(void *)this,  
				0,     
				&m_dThreadIdSPNVInit);
	}
	else
	{
		return;
	}
}


void CFullWriteView::OnGetMessage(WPARAM wParam, LPARAM lParam)
{ 
	int i;
	CHARFORMAT cf;
	i = (int)lParam; 
#ifndef _DEBUG
	if(3 == i)
		return;
#endif
	char *lpsz = (char*)wParam;
    memset(&cf, 0, sizeof(CHARFORMAT));
	m_cedTrace.GetDefaultCharFormat(cf);
	cf.dwEffects ^= CFE_AUTOCOLOR;          // 为了让设置颜色有效
	cf.yHeight = 15*15;//文字高度
	
	// 新的颜色
	if (i==1)
	{
		cf.crTextColor = RGB(255,0,0);	
	}
	else
	{
		cf.crTextColor = RGB(0,0,255);	
	}
	m_cedTrace.SetWordCharFormat(cf);		//为将要输入的内容设定字//csText	 
	this->ShowInfo(lpsz);	 
}


void CFullWriteView::ShowInfo(char *msg)
{
	CHAR   szt[256];
	char *lpsz = msg ;
	_stprintf(szt, _T("%s\x0D\x0A"), lpsz);
	m_cedTrace.ReplaceSel(szt);
}


void CFullWriteView::Display(char *msg,int index)
{
	SendMessage(WM_CAL_MSG,(WPARAM)msg,index);
}


void CFullWriteView::OnUpdateData(WPARAM wParam, LPARAM lParam) 
{ 
	UpdateData(wParam);
}


void CFullWriteView::ShowCalResult(int state)
{
	switch(state) 
	{
	case IDLE:
		this->m_cResult.SetTextColor(RGB(0,128,0));
		this->m_cResult.SetWindowText("IDLE...");
		break;
	case FAIL:
		this->m_cResult.SetTextColor(RGB(255,0,0));
		this->m_cResult.SetWindowText("FAIL");
		break;
	case PASS:
		this->m_cResult.SetTextColor(RGB(0,128,0));
		this->m_cResult.SetWindowText("PASS");
		break;
	case Testing:
		this->m_cResult.SetTextColor(RGB(0,0,255));
		this->m_cResult.SetWindowText("Testing...");
		break;
	case InitFail:
		this->m_cResult.SetTextColor(RGB(255,0,0));
		this->m_cResult.SetWindowText("InitFail");
	default:
		break;
	}
}


bool CFullWriteView::DoInitFPNV()
{
	m_MetaappResult=METAAPP_DeInit(m_nMetaHandle);	
	m_MetaappResult=METAAPP_GetAvailableHandle(&m_nMetaHandle);
	m_MetaappResult=METAAPP_Init(m_nMetaHandle);
	m_MetaappResult=METAAPP_NVRAM_Init(m_nMetaHandle,this->m_csDBPath);
	if(m_MetaappResult != METAAPP_SUCCESS)   
	{ 
		m_MetaappResult=METAAPP_DeInit(m_nMetaHandle);
		return FALSE;
	}

	return TRUE;	
}


bool CFullWriteView::DoInitSPModemNV()
{
	m_MetaappResult=METAAPP_DeInit(m_nMetaHandle);
	m_MetaappResult=METAAPP_GetAvailableHandle(&m_nMetaHandle);
	m_MetaappResult=METAAPP_Init(m_nMetaHandle);
	m_MetaappResult=METAAPP_NVRAM_Init(m_nMetaHandle,this->m_csDBPath);
	if(m_MetaappResult != METAAPP_SUCCESS)   
	{ 
		m_MetaappResult=METAAPP_DeInit(m_nMetaHandle);
		return FALSE;
	}
	
	return TRUE;	
}


bool CFullWriteView::DoInitSPApNV()
{
	BOOL bResult=false;
	this->m_ApExe.MetaAPHandleDeInit();
	bResult = this->m_ApExe.MetaAPHandleInit();
	
	if(!bResult)
		return FALSE;
	
	bResult = this->m_ApExe.InitAPDatabase((LPSTR)(LPCTSTR)this->m_csAPDBPath);
	
	if(bResult)
		return TRUE;
	else
		return FALSE;
}
  

void CFullWriteView::OnBtnStart()
{
	if(this->m_iPlatform==1)
	{
		m_hThreadSPStart_ScanMode =
			CreateThread (NULL,  
			0,     
			(LPTHREAD_START_ROUTINE)SmartStart_ScanMode,
			(void *)this,  
			0,     
			&m_dThreadIdSPStart_ScanMode);
	}
	else if(this->m_iPlatform==2)
	{
		m_hThreadSPStart =
			CreateThread (NULL,  
			0,     
			(LPTHREAD_START_ROUTINE)SPRDStart,
			(void *)this,  
			0,     
			&m_dThreadIdSPStart);
	}
}

void CFullWriteView::OnSelchangeComboComport()
{
	m_comport = this->m_ctrComboxComPort.GetCurSel();
	this->m_iComboxComPort=m_comport;
	m_comport = m_comnum[m_comport];
	UpdateData();
}


void CFullWriteView::CleanAndSetBuffer()
{
	//清空BUFF
	this->m_csPcbaSN.Empty();
	this->m_csPcbaBarcode.Empty();
	this->m_csWriteSN.Empty();
	this->m_csWriteWIFI.Empty();
	this->m_csWriteBT.Empty();
	this->m_csWriteIMEI1.Empty();
	this->m_csWriteIMEI2.Empty();
	this->m_csWriteIMEI3.Empty();
	this->m_csWriteIMEI4.Empty();

	//设置BUFF
	this->m_csPcbaSN;//该参数需要从手机读取
	this->m_csPcbaBarcode;
	this->m_csWriteSN=this->m_csInputPSN;
	this->m_csWriteWIFI="";
	this->m_csWriteBT="";
	this->m_csWriteIMEI1_15=this->m_csInputIMEI1;
	this->m_csWriteIMEI2_15=this->m_csInputIMEI2;
	this->m_csWriteIMEI3_15=this->m_csInputIMEI3;
	this->m_csWriteIMEI4_15=this->m_csInputIMEI4;
	return;

	//生成15位IMEI
	//检测IMEI校验位是否正确
	char calculate_digit;
	switch(this->m_iIMEIType)
	{
	case 0:
		calculate_15_digit_imei((char*)(LPCTSTR)m_csWriteIMEI1,calculate_digit);
		this->m_csWriteIMEI1_15=m_csWriteIMEI1+calculate_digit;
		break;
	case 1:
		calculate_15_digit_imei((char*)(LPCTSTR)m_csWriteIMEI1,calculate_digit);
		this->m_csWriteIMEI1_15=m_csWriteIMEI1+calculate_digit;
		calculate_15_digit_imei((char*)(LPCTSTR)m_csWriteIMEI2,calculate_digit);
		this->m_csWriteIMEI2_15=m_csWriteIMEI2+calculate_digit;
		break;
	case 2:
		calculate_15_digit_imei((char*)(LPCTSTR)m_csWriteIMEI1,calculate_digit);
		this->m_csWriteIMEI1_15=m_csWriteIMEI1+calculate_digit;
		calculate_15_digit_imei((char*)(LPCTSTR)m_csWriteIMEI2,calculate_digit);
		this->m_csWriteIMEI2_15=m_csWriteIMEI2+calculate_digit;
		calculate_15_digit_imei((char*)(LPCTSTR)m_csWriteIMEI3,calculate_digit);
		this->m_csWriteIMEI3_15=m_csWriteIMEI3+calculate_digit;
		break;
	case 3:
		calculate_15_digit_imei((char*)(LPCTSTR)m_csWriteIMEI1,calculate_digit);
		this->m_csWriteIMEI1_15=m_csWriteIMEI1+calculate_digit;
		calculate_15_digit_imei((char*)(LPCTSTR)m_csWriteIMEI2,calculate_digit);
		this->m_csWriteIMEI2_15=m_csWriteIMEI2+calculate_digit;
		calculate_15_digit_imei((char*)(LPCTSTR)m_csWriteIMEI3,calculate_digit);
		this->m_csWriteIMEI3_15=m_csWriteIMEI3+calculate_digit;
		calculate_15_digit_imei((char*)(LPCTSTR)m_csWriteIMEI4,calculate_digit);
		this->m_csWriteIMEI4_15=m_csWriteIMEI4+calculate_digit;
		break;
	default:
		break;
	}
}


void CFullWriteView::DisplayWriteNumber_ScanMode()
{
	CString temp;
	
	//SN
 	if(this->m_iScanPSN)
 	{
 		temp.Format("Ready To Write Product SN = %s ",this->m_csWriteSN);
 		this->Display((LPSTR)(LPCTSTR)temp,0);
 	}
	
	switch(this->m_iIMEIType)
	{
	case 0:
		temp.Format("Ready To Write IMEI1 = %s ",this->m_csWriteIMEI1_15);
		this->Display((LPSTR)(LPCTSTR)temp,0);
		break;
	case 1:
		temp.Format("Ready To Write IMEI1 = %s ",this->m_csWriteIMEI1_15);
		this->Display((LPSTR)(LPCTSTR)temp,0);
		temp.Format("Ready To WriteIMEI2 = %s ",this->m_csWriteIMEI2_15);
		this->Display((LPSTR)(LPCTSTR)temp,0);
		break;
	case 2:
		temp.Format("Ready To WriteIMEI1 = %s ",this->m_csWriteIMEI1_15);
		this->Display((LPSTR)(LPCTSTR)temp,0);
		temp.Format("Ready To WriteIMEI2 = %s ",this->m_csWriteIMEI2_15);
		this->Display((LPSTR)(LPCTSTR)temp,0);
		temp.Format("Ready To WriteIMEI3 = %s ",this->m_csWriteIMEI3_15);
		this->Display((LPSTR)(LPCTSTR)temp,0);
		break;
	case 3:
		temp.Format("Ready To WriteIMEI1 = %s ",this->m_csWriteIMEI1_15);
		this->Display((LPSTR)(LPCTSTR)temp,0);
		temp.Format("Ready To WriteIMEI2 = %s ",this->m_csWriteIMEI2_15);
		this->Display((LPSTR)(LPCTSTR)temp,0);
		temp.Format("Ready To WriteIMEI3 = %s ",this->m_csWriteIMEI3_15);
		this->Display((LPSTR)(LPCTSTR)temp,0);
		temp.Format("Ready To WriteIMEI4 = %s ",this->m_csWriteIMEI4_15);
		this->Display((LPSTR)(LPCTSTR)temp,0);
		break;
	default:
		break;
	}
}


bool CFullWriteView::CheckNetRepeat_ScanMode()
{

	CString temp;
	
 	if(this->m_iScanPSN)
 	{
 		if(!Check_ProductSN_Repeat())
 		{
 			temp.Format("Ready to write the product SN =%s already exists in the database...",this->m_csWriteSN);
 			this->Display((LPSTR)(LPCTSTR)temp,1);
 			return FALSE;
		}
 	}

	switch(this->m_iIMEIType)
	{
	case 0:
		if(!Check_IMEI1_Repeat())
		{
			temp.Format("IMEI1 =%s already exists in the database...",this->m_csWriteIMEI1_15);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		break;
	case 1:
		if(!Check_IMEI1_Repeat())
		{
			temp.Format("IMEI1 =%s already exists in the database...",this->m_csWriteIMEI1_15);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}

		if(!Check_IMEI2_Repeat())
		{
			temp.Format("IMEI2 =%s already exists in the database...",this->m_csWriteIMEI2_15);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		break;
	case 2:
		if(!Check_IMEI1_Repeat())
		{
			temp.Format("IMEI1 =%s already exists in the database...",this->m_csWriteIMEI1_15);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		
		if(!Check_IMEI2_Repeat())
		{
			temp.Format("IMEI2 =%s already exists in the database...",this->m_csWriteIMEI2_15);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		
		if(!Check_IMEI3_Repeat())
		{
			temp.Format("IMEI3 =%s already exists in the database...",this->m_csWriteIMEI3_15);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		break;
	case 3:
		if(!Check_IMEI1_Repeat())
		{
			temp.Format("IMEI1 =%s already exists in the database...",this->m_csWriteIMEI1_15);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		
		if(!Check_IMEI2_Repeat())
		{
			temp.Format("IMEI2 =%s already exists in the database...",this->m_csWriteIMEI2_15);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		
		if(!Check_IMEI3_Repeat())
		{
			temp.Format("IMEI3 =%s already exists in the database...",this->m_csWriteIMEI3_15);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}

		if(!Check_IMEI4_Repeat())
		{
			temp.Format("IMEI4 =%s already exists in the database...",this->m_csWriteIMEI4_15);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		break;
	default:
		break;
	}
	
	return TRUE;
}


bool CFullWriteView::Check_ProductSN_Repeat()
{
	CString temp,states;
	_variant_t var;
	CString sql;

	sql.Format("select * from %s_%s_ColorBox where ProductSN='%s' and Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csWriteSN);
	
	try
	{
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			return FALSE;
		}
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		this->Display("unknown error",1);
		return FALSE;
	}
	return TRUE;
}


bool CFullWriteView::Check_IMEI1_Repeat()
{
	CString temp,states;
	_variant_t var;
	CString sql;

	sql.Format("select * from %s_%s_ColorBox where (IMEI1='%s' or IMEI2='%s' or IMEI3='%s' or IMEI4='%s') and\
		Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csWriteIMEI1_15,\
		this->m_csWriteIMEI1_15,this->m_csWriteIMEI1_15,this->m_csWriteIMEI1_15);
	try
	{
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			return FALSE;
		}
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		this->Display("unknown error",1);
		return FALSE;
	}

	return TRUE;
}


bool CFullWriteView::Check_IMEI2_Repeat()
{
	CString temp,states;
	_variant_t var;
	CString sql;

	sql.Format("select * from %s_%s_ColorBox where (IMEI1='%s' or IMEI2='%s' or IMEI3='%s' or IMEI4='%s') and\
		Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csWriteIMEI2_15,\
		this->m_csWriteIMEI2_15,this->m_csWriteIMEI2_15,this->m_csWriteIMEI2_15);

	try
	{
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			return FALSE;
		}
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		this->Display("unknown error",1);
		return FALSE;
	}

	return TRUE;
}


bool CFullWriteView::Check_IMEI3_Repeat()
{
	CString temp,states;
	_variant_t var;
	CString sql;

	sql.Format("select * from %s_%s_ColorBox where (IMEI1='%s' or IMEI2='%s' or IMEI3='%s' or IMEI4='%s') and\
		Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csWriteIMEI3_15,\
		this->m_csWriteIMEI3_15,this->m_csWriteIMEI3_15,this->m_csWriteIMEI3_15);
	
	try
	{
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			return FALSE;
		}
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		this->Display("unknown error",1);
		return FALSE;
	}

	return TRUE;
}


bool CFullWriteView::Check_IMEI4_Repeat()
{
	CString temp,states;
	_variant_t var;
	CString sql;
	
	sql.Format("select * from %s_%s_ColorBox where (IMEI1='%s' or IMEI2='%s' or IMEI3='%s' or IMEI4='%s') and\
		Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csWriteIMEI4_15,\
		this->m_csWriteIMEI4_15,this->m_csWriteIMEI4_15,this->m_csWriteIMEI4_15);
		
	try
	{
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			return FALSE;
		}
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		this->Display("unknown error",1);
		return FALSE;
	}

	return TRUE;
}


void CFullWriteView::calculate_15_digit_imei( char *imei_14,char &calculate_digit)
{
	int check_digit,sum1,sum2,total_sum,temp_value,temp_value_2_part;
	int i;
	char temp[16];
	
	// the following is calculate IMEI 15th digit -- check digit //
	// according   3G TS 22.016  V3.1.0 //
	/* 
	A.2 Computation of Check Digit for an IMEI
	Computation of CD from the IMEI proceeds as follows:
	Step 1: Double the values of the odd labelled digits D1, D3, D5 ... D13 of the IMEI.
	Step 2: Add together the individual digits of all the seven numbers obtained in Step 1, and then add this sum to
	the sum of all the even labelled digits D2, D4, D6 ... D14 of the IMEI.
	Step 3: If the number obtained in Step 2 ends in 0, then set CD to be 0. If the number obtained in Step 2 does not
	end in 0, then set CD to be that number subtracted from the next higher number which does end in 0.
	
		A.3 Example of computation
		IMEI (14 most significant digits):
		TAC FAC SNR
		D14  D13 D12 D11 D10 D9 D8 D7  D6 D5 D4 D3 D2 D1 
		2    6   0   5   3   1  7  9  3   1  1  3  8  3
		Step 1:
		2    6   0   5   3   1  7  9  3   1  1  3  8  3 
		x2      x2      x2    x2     x2    x2   x2
		12      10      2     18     2      6    6
		Step 2:
		2 + 1 + 2 + 0 + 1 + 0 + 3 + 2 + 7 + 1 + 8 + 3 + 2 + 1 + 6 + 8 + 6 = 53
		Step 3:
		CD = 60 - 53 = 7
	*/
	for(i=0;i<14;i++)
		temp[i] = imei_14[i];
	
	sum1 = 0;
	for (i=1;i<=13;i++)		  // sum digit 1,3,5,7,9,11,13
	{
		sum1 = sum1 + (temp[i-1]-48);
		i++;
	}
	sum2 = 0;
	for (i=2;i<=14;i++)			 // sum digit 2,4,6,8,10,12,14   
	{
		temp_value =  (temp[i-1]-48) * 2 ;			// temp_value range from 0 --> 9*2 = 18
		if ( temp_value < 10 )  
			sum2 = sum2 +  temp_value ;
		else  
		{
			temp_value_2_part = temp_value - 10 ;
			sum2 = sum2 + 1 +temp_value_2_part;
		} 
		
		i++;				  
	}
	
	total_sum = sum1 + sum2 ;
	
	if ( fmod(total_sum,10) == 0 )
		check_digit = 0  ; 	   // if total_sum ends in 0 ( mod 10 reminder is 0 ) 
	else 
	{
		check_digit = (total_sum /10)*10 + 10 - total_sum;
		
	}
	calculate_digit=check_digit+48;
}


AUTH_HANDLE_T CFullWriteView::Get_AuthHandle( void )
{   
    return m_sAuthHandle;
}


bool CFullWriteView::FP_Read_PCB_BARCODE()	
{
	char read_buffer_temp[70];
	char ch;
	if (m_iPlatform == 0 || m_iPlatform == 1)
	{
		m_MetaappResult=METAAPP_readBarcodefromNVRAM(m_nMetaHandle, 5000, read_buffer_temp);
		if (m_MetaappResult!=0)
		{
			return FALSE;
		}   
		
		read_buffer_temp[63]='\0';
		this->m_csPcbaBarcode.Format("%s",read_buffer_temp);
	} 
	else if (m_iPlatform == 2)
	{
		nErrorCode = SP_ReadSN(g_hDiagPhone, true, (void *)read_buffer_temp, 24);
		if(RFT_SUCCESS != nErrorCode)
		{
			return FALSE;
		}	
		ch = read_buffer_temp[14];
		if((ch>=48&&ch<=57)||(ch>=97&&ch<=122)||(ch>=65&&ch<=90))
		{
			read_buffer_temp[16]='\0';
		}
		else
		{
			read_buffer_temp[14]='\0';
		}
	}

	this->m_csPcbaSN.Format("%s",read_buffer_temp);
	return TRUE;
}


bool CFullWriteView::FP_Read_IMEI()	
{
	switch(this->m_iIMEIType)
	{
	case 0:
		if(!this->ReadSimpleIMEI())
			return FALSE;
		break;
	case 1: 
		if(!this->ReadDoubleIMEI())
			return FALSE;
		break;

	case 2: 
		if(!this->ReadThreeIMEI())
			return FALSE;
		break;

	case 3:
		if(!this->ReadFourIMEI())
			return FALSE;
		break;
	}

	return TRUE;
}


bool CFullWriteView::ReadSimpleIMEI()
{
	FASTNVACCESS_T      nvparam;
	ZeroMemory((void *)&nvparam, sizeof(nvparam));
	IMEISV_struct_T IMEISV;
	CString temp;

	if (m_iPlatform == 0 || m_iPlatform == 1)
	{
		m_MetaappResult=METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,1,&IMEISV);
		
		if(m_MetaappResult!=METAAPP_SUCCESS)   
		{
			this->Display("Read Module IMEI1 Fail...",1);
			return FALSE;
		}
		else
		{
			this->m_csReadIMEI1=IMEISV.imei;
			temp.Format("Read Module IMEI1 = %s",this->m_csReadIMEI1);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
	} 
	else if (m_iPlatform == 2)
	{
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI1;

		nErrorCode = SP_FastReadNvInfo (g_hDiagPhone, &nvparam);
		
		if(RFT_SUCCESS != nErrorCode)
		{
			this->Display("Read Module IMEI Fail...",1);
			return FALSE;
		}
		else
		{
			this->m_csReadIMEI1=nvparam.szImei1;
			temp.Format("Read Module IMEI1 = %s",this->m_csReadIMEI1);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
	}

	return TRUE;
}


bool CFullWriteView::ReadDoubleIMEI()
{
	FASTNVACCESS_T      nvparam;
	ZeroMemory((void *)&nvparam, sizeof(nvparam));
	IMEISV_struct_T IMEISV;
	CString temp;
	
	if (m_iPlatform == 0 || m_iPlatform == 1)
	{
		m_MetaappResult=METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,1,&IMEISV);
		
		if(m_MetaappResult!=METAAPP_SUCCESS)
		{
			this->Display("Read Module IMEI1 Fail...",1);
			return FALSE;
		}
		else
		{
			this->m_csReadIMEI1=IMEISV.imei;
			temp.Format("Read Module IMEI1 = %s",this->m_csReadIMEI1);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		m_MetaappResult=METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,2,&IMEISV);
		
		if(m_MetaappResult!=METAAPP_SUCCESS)
		{
			this->Display("Read Module IMEI2 Fail...",1);
			return FALSE;
		}
		else
		{
			this->m_csReadIMEI2=IMEISV.imei;
			temp.Format("Read Module IMEI2 = %s",this->m_csReadIMEI2);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
	}
	else if (m_iPlatform == 2)
	{
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI1;
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI2;
		
		nErrorCode = SP_FastReadNvInfo (g_hDiagPhone, &nvparam);
		
		if(RFT_SUCCESS != nErrorCode)
		{
			this->Display("Read Module IMEI Fail...",1);
			return FALSE;
		}
		else
		{
			this->m_csReadIMEI1=nvparam.szImei1;
			temp.Format("Read Module IMEI1 = %s",this->m_csReadIMEI1);
			this->Display((LPSTR)(LPCTSTR)temp,0);

			this->m_csReadIMEI2=nvparam.szImei2;
			temp.Format("Read Module IMEI2 = %s",this->m_csReadIMEI2);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
	}
	
	return TRUE;
}


bool CFullWriteView::ReadThreeIMEI()
{
	FASTNVACCESS_T      nvparam;
	ZeroMemory((void *)&nvparam, sizeof(nvparam));
	IMEISV_struct_T IMEISV;
	CString temp;
	
	if (m_iPlatform == 0 || m_iPlatform == 1)
	{
		m_MetaappResult=METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,1,&IMEISV);
		
		if(m_MetaappResult!=METAAPP_SUCCESS)
		{
			this->Display("Read Module IMEI1 Fail...",1);
			return FALSE;
		}
		else
		{
			this->m_csReadIMEI1=IMEISV.imei;
			temp.Format("Read Module IMEI1 = %s",this->m_csReadIMEI1);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		m_MetaappResult=METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,2,&IMEISV);
		
		if(m_MetaappResult!=METAAPP_SUCCESS)
		{
			this->Display("Read Module IMEI2  Fail...",1);
			return FALSE;
		}
		else
		{
			this->m_csReadIMEI2=IMEISV.imei;
			temp.Format("Read Module IMEI2 = %s",this->m_csReadIMEI2);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		m_MetaappResult=METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,3,&IMEISV);
		
		if(m_MetaappResult!=METAAPP_SUCCESS)
		{
			this->Display("Read Module IMEI3 Fail...",1);
			return FALSE;
		}
		else
		{
			this->m_csReadIMEI3=IMEISV.imei;
			temp.Format("Read Module IMEI3 = %s",this->m_csReadIMEI3);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
	}
	else if (m_iPlatform == 2)
	{
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI1;
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI2;
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI3;
		
		nErrorCode = SP_FastReadNvInfo (g_hDiagPhone, &nvparam);
		
		if(RFT_SUCCESS != nErrorCode)
		{
			this->Display("Read Module IMEI Fail...",1);
			return FALSE;
		}
		else
		{
			this->m_csReadIMEI1=nvparam.szImei1;
			temp.Format("Read Module IMEI1 = %s",this->m_csReadIMEI1);
			this->Display((LPSTR)(LPCTSTR)temp,0);
			
			this->m_csReadIMEI2=nvparam.szImei2;
			temp.Format("Read Module IMEI2 = %s",this->m_csReadIMEI2);
			this->Display((LPSTR)(LPCTSTR)temp,0);

			this->m_csReadIMEI3=nvparam.szImei3;
			temp.Format("Read Module IMEI3 = %s",this->m_csReadIMEI3);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
	}
	
	return TRUE;
}


bool CFullWriteView::ReadFourIMEI()
{
	FASTNVACCESS_T      nvparam;
	ZeroMemory((void *)&nvparam, sizeof(nvparam));
	IMEISV_struct_T IMEISV;
	CString temp;
	
	if (m_iPlatform == 0 || m_iPlatform == 1)
	{
		m_MetaappResult=METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,1,&IMEISV);		
		
		if(m_MetaappResult!=METAAPP_SUCCESS)   
		{
			this->Display("Read Module IMEI1 Fail...",1);
			return FALSE;
		}
		else
		{
			this->m_csReadIMEI1=IMEISV.imei;
			temp.Format("Read Module IMEI1 = %s",this->m_csReadIMEI1);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		m_MetaappResult=METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,2,&IMEISV);
		
		if(m_MetaappResult!=METAAPP_SUCCESS)   
		{
			this->Display("Read Module IMEI2 Fail...",1);
			return FALSE;
		}
		else
		{
			this->m_csReadIMEI2=IMEISV.imei;
			temp.Format("Read Module IMEI2 = %s",this->m_csReadIMEI2);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		m_MetaappResult=METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,3,&IMEISV);	
		
		if(m_MetaappResult!=METAAPP_SUCCESS)   
		{
			this->Display("Read Module IMEI3 Fail...",1);
			return FALSE;
		}
		else
		{
			this->m_csReadIMEI3=IMEISV.imei;
			temp.Format("Read Module IMEI3 = %s",this->m_csReadIMEI3);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		m_MetaappResult=METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,4,&IMEISV);
		
		if(m_MetaappResult!=METAAPP_SUCCESS)
		{
			this->Display("Read Module IMEI4 Fail...",1);
			return FALSE;
		}
		else
		{
			this->m_csReadIMEI4=IMEISV.imei;
			temp.Format("Read Module IMEI4 = %s",this->m_csReadIMEI4);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
	}
	else if (m_iPlatform == 2)
	{
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI1;
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI2;
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI3;
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI4;
		
		nErrorCode = SP_FastReadNvInfo (g_hDiagPhone, &nvparam);
		
		if(RFT_SUCCESS != nErrorCode)
		{
			this->Display("Read Module IMEI Fail...",1);
			return FALSE;
		}
		else
		{
			this->m_csReadIMEI1=nvparam.szImei1;
			temp.Format("Read Module IMEI1 = %s",this->m_csReadIMEI1);
			this->Display((LPSTR)(LPCTSTR)temp,0);
			
			this->m_csReadIMEI2=nvparam.szImei2;
			temp.Format("Read Module IMEI2 = %s",this->m_csReadIMEI2);
			this->Display((LPSTR)(LPCTSTR)temp,0);
			
			this->m_csReadIMEI3=nvparam.szImei3;
			temp.Format("Read Module IMEI3 = %s",this->m_csReadIMEI3);
			this->Display((LPSTR)(LPCTSTR)temp,0);

			this->m_csReadIMEI4=nvparam.szImei4;
			temp.Format("Read Module IMEI4 = %s",this->m_csReadIMEI4);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
	}
	
	return TRUE;
}



bool CFullWriteView::Check_PCB_Net_Repeat()
{
	CString temp;
	
	if(!Check_PCB_SN_Repeat())
	{
	
		temp.Format("Module SN = %s Already Exist In Server...",this->m_csPcbaSN);
		this->Display((LPSTR)(LPCTSTR)temp,1);
		return FALSE;
	}

	switch(this->m_iIMEIType)
	{
	case 0:
		if(!Check_PCB_IMEI1_Repeat())
		{
			temp.Format("Module IMEI1 = %s Already Exist In Server...",this->m_csReadIMEI1);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		break;
	case 1:
		if(!Check_PCB_IMEI1_Repeat())
		{
			temp.Format("Module IMEI1 = %s Already Exist In Server...",this->m_csReadIMEI1);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}

		if(!Check_PCB_IMEI2_Repeat())
		{
			temp.Format("Module IMEI2 = %s Already Exist In Server...",this->m_csReadIMEI2);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		break;
	case 2:
		if(!Check_PCB_IMEI1_Repeat())
		{
			temp.Format("Module IMEI1 = %s Already Exist In Server...",this->m_csReadIMEI1);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		
		if(!Check_PCB_IMEI2_Repeat())
		{
			temp.Format("Module IMEI2 = %s Already Exist In Server...",this->m_csReadIMEI2);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		
		if(!Check_PCB_IMEI3_Repeat())
		{
			temp.Format("Module IMEI3 = %s Already Exist In Server...",this->m_csReadIMEI3);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		break;
	case 3:
		if(!Check_PCB_IMEI1_Repeat())
		{
			temp.Format("Module IMEI1 = %s Already Exist In Server...",this->m_csReadIMEI1);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		
		if(!Check_PCB_IMEI2_Repeat())
		{
			temp.Format("Module IMEI2 = %s Already Exist In Server...",this->m_csReadIMEI2);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		
		if(!Check_PCB_IMEI3_Repeat())
		{
			temp.Format("Module IMEI3 = %s Already Exist In Server...",this->m_csReadIMEI3);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}

		if(!Check_PCB_IMEI4_Repeat())
		{
			temp.Format("Module IMEI4 = %s Already Exist In Server...",this->m_csReadIMEI4);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		break;
	default:
		break;
	}
	
	return TRUE;
}


bool CFullWriteView::Check_PCB_SN_Repeat()
{
	CString temp,states;
	_variant_t var;
	CString sql;
	
	sql.Format("select * from %s_%s_ColorBox where BarCode='%s' and Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csPcbaSN);
	
	try
	{
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			return FALSE;
		}
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}


bool CFullWriteView::Check_PCB_IMEI1_Repeat()
{
	CString temp,states;
	_variant_t var;
	CString sql;
	//and Enable=1
	sql.Format("select * from %s_%s_ColorBox where IMEI1='%s' ", \
		(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csReadIMEI1);
	
	try
	{
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			return FALSE;
		}
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}


bool CFullWriteView::Check_PCB_IMEI2_Repeat()
{
	CString temp,states;
	_variant_t var;
	CString sql;

	sql.Format("select * from %s_%s_ColorBox where IMEI2='%s' and Enable=1", \
		(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csReadIMEI2);
	
	try
	{
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			return FALSE;
		}
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}


bool CFullWriteView::Check_PCB_IMEI3_Repeat()
{
	CString temp,states;
	_variant_t var;
	CString sql;
	
	sql.Format("select * from %s_%s_ColorBox where IMEI3='%s' and Enable=1", \
		(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csReadIMEI3);
	
	try
	{
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			return FALSE;
		}
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}


bool CFullWriteView::Check_PCB_IMEI4_Repeat()
{
	CString temp,states;
	_variant_t var;
	CString sql;

	sql.Format("select * from %s_%s_ColorBox where IMEI4='%s' and Enable=1", \
		(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csReadIMEI4);
	
	try
	{
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			return FALSE;
		}
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}

bool CFullWriteView::FP_WriteAndRead_IMEI()	
{
	switch(this->m_iIMEIType)
	{
		case 0:
			if(!this->FP_WriteAndRead_SimpleIMEI())
				return FALSE;
			break;
		case 1: 
			if(!this->FP_WriteAndRead_DoubleIMEI())
				return FALSE;
			break;
		case 2: 
			if(!this->FP_WriteAndRead_ThreeIMEI())
				return FALSE;
			break;
		case 3: 
			if(!this->FP_WriteAndRead_FourIMEI())
				return FALSE;
			break;
	}

	if (m_iPlatform == 0 || m_iPlatform == 1)
	{
		//summer 2011-10-22 begin 解决读取Last IMEI问题
		IMEISV_struct_T IMEISV;
		METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,1,&IMEISV);	
		//summer 2011-10-22 end 解决读取Last IMEI问题
	}
	
	return TRUE;
}


bool CFullWriteView::FP_WriteAndRead_SimpleIMEI()
{
	FASTNVACCESS_T      nvparam;
    ZeroMemory((void *)&nvparam, sizeof(nvparam));
	CString temp;
	IMEISV_struct_T IMEISV_W;
	IMEISV_struct_T IMEISV_R;
	CString tempReadIMEI;

	if (m_iPlatform == 0 || m_iPlatform == 1)
	{
		strcpy(IMEISV_W.imei,this->m_csWriteIMEI1_15);
		IMEISV_W.imei[15]='\0';
		m_MetaappResult= METAAPP_writeIMEItoNVRAM_Ex3(m_nMetaHandle,5000,FALSE,0,1,&IMEISV_W);
		Sleep(200);		
		if(m_MetaappResult!=METAAPP_SUCCESS)
		{
			temp.Format("Write IMEI1 = %s Fail...",this->m_csWriteIMEI1_15);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		else
		{
			temp.Format("Write IMEI1 = %s Pass...",this->m_csWriteIMEI1_15);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		m_MetaappResult=METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,1,&IMEISV_R);
		tempReadIMEI.Format("%s",IMEISV_R.imei);
		if(m_MetaappResult!=METAAPP_SUCCESS)
		{
			this->Display("Read IMEI1 Fail...",1);
			return FALSE;
		}
		else
		{
			temp.Format("Read IMEI1 = %s",tempReadIMEI);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		if(this->m_csWriteIMEI1_15 != tempReadIMEI)
		{
			this->Display("IMEI1 Input and IMEI1 Read From Module are inconsistent...",1);
			return FALSE;
		}
		else
		{
			this->Display("IMEI1 Input and IMEI1 Read From Module are inconsistent...",0);
		}
	}
	else if (m_iPlatform == 2)
	{
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI1;
		strncpy((char *)nvparam.szImei1, m_csWriteIMEI1_15, MAX_IMEI_STR_LENGTH);

		nErrorCode = SP_FastWriteNvInfo (g_hDiagPhone, &nvparam);
		
		if(RFT_SUCCESS != nErrorCode)
		{
			temp.Format("Write IMEI Fail...");
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		else
		{
			temp.Format("Write IMEI Pass...");
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}

		ZeroMemory((void *)&nvparam, sizeof(nvparam));
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI1;

		nErrorCode = SP_FastReadNvInfo (g_hDiagPhone, &nvparam);
		
		if(RFT_SUCCESS != nErrorCode)
		{
			this->Display("Read IMEI Fail...",1);
			return FALSE;
		}
		else
		{
			tempReadIMEI.Format("%s",nvparam.szImei1);
			temp.Format("Read IMEI1 = %s",tempReadIMEI);
			this->Display((LPSTR)(LPCTSTR)temp,0);

			if(this->m_csWriteIMEI1_15 != tempReadIMEI)
			{
				this->Display("IMEI1 Input and IMEI1 Read From Module are inconsistent...",1);
				return FALSE;
			}
			else
			{
				this->Display("IMEI1 Input and IMEI1 Read From Module are inconsistent...",0);
			}
		}
	}

	return TRUE;
}


bool CFullWriteView::FP_WriteAndRead_DoubleIMEI()
{
	FASTNVACCESS_T      nvparam;
    ZeroMemory((void *)&nvparam, sizeof(nvparam));
	CString temp;
	IMEISV_struct_T IMEISV_W;
	IMEISV_struct_T IMEISV_R;
	CString tempReadIMEI;
	
	if (m_iPlatform == 0 || m_iPlatform == 1)
	{
		strcpy(IMEISV_W.imei,this->m_csWriteIMEI1_15); 
		IMEISV_W.imei[15]='\0';
		m_MetaappResult= METAAPP_writeIMEItoNVRAM_Ex3(m_nMetaHandle,5000,FALSE,0,1,&IMEISV_W);
		Sleep(200); 		
		if(m_MetaappResult!=METAAPP_SUCCESS)   
		{
			temp.Format("Write IMEI1 = %s Fail...",this->m_csWriteIMEI1_15);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		else
		{
			temp.Format("Write IMEI1 = %s Pass...",this->m_csWriteIMEI1_15);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		m_MetaappResult=METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,1,&IMEISV_R);
		tempReadIMEI.Format("%s",IMEISV_R.imei);
		if(m_MetaappResult!=METAAPP_SUCCESS)   
		{
			this->Display("Read IMEI1 Fail...",1);
			return FALSE;
		}
		else
		{
			temp.Format("Read IMEI1 = %s",tempReadIMEI);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		if(this->m_csWriteIMEI1_15 != tempReadIMEI)
		{
			this->Display("IMEI1 Input and IMEI1 Read From Module are inconsistent Fail...",1);
			return FALSE;
		}
		else
		{
			this->Display("IMEI1 Input and IMEI1 Read From Module are consistent Pass...",0);
		}	
		
		strcpy(IMEISV_W.imei,this->m_csWriteIMEI2_15); 
		IMEISV_W.imei[15]='\0';
		m_MetaappResult= METAAPP_writeIMEItoNVRAM_Ex3(m_nMetaHandle,5000,FALSE,0,2,&IMEISV_W);
		Sleep(200); 		
		if(m_MetaappResult!=METAAPP_SUCCESS)   
		{
			temp.Format("Write IMEI2 = %s Fail...",this->m_csWriteIMEI2_15);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		else
		{
			temp.Format("Write IMEI2 = %s  Pass...",this->m_csWriteIMEI2_15);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		m_MetaappResult=METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,2,&IMEISV_R);
		tempReadIMEI.Format("%s",IMEISV_R.imei);
		if(m_MetaappResult!=METAAPP_SUCCESS)   
		{
			this->Display("Read IMEI2 Fail...",1);
			return FALSE;
		}
		else
		{
			temp.Format("Read IMEI2 = %s",tempReadIMEI);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		if(this->m_csWriteIMEI2_15 != tempReadIMEI)
		{
			this->Display("IMEI1 Input and IMEI1 Read From Module are inconsistent Fail...",1);
			return FALSE;
		}
		else
		{
			this->Display("IMEI1 Input and IMEI1 Read From Module are consistent Pass...",0);
		}
	}
	else if (m_iPlatform == 2)
	{
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI1;
		strncpy((char *)nvparam.szImei1, m_csWriteIMEI1_15, MAX_IMEI_STR_LENGTH);

		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI2;
		strncpy((char *)nvparam.szImei2, m_csWriteIMEI2_15, MAX_IMEI_STR_LENGTH);
		
		nErrorCode = SP_FastWriteNvInfo (g_hDiagPhone, &nvparam);
		
		if(RFT_SUCCESS != nErrorCode)
		{
			temp.Format("Write IMEI Fail...");
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		else
		{
			temp.Format("Write IMEI Pass...");
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}

		ZeroMemory((void *)&nvparam, sizeof(nvparam));
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI1;
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI2;
		
		nErrorCode = SP_FastReadNvInfo (g_hDiagPhone, &nvparam);
		
		if(RFT_SUCCESS != nErrorCode)
		{
			this->Display("Read IMEI Fail...",1);
			return FALSE;
		}
		else
		{
			tempReadIMEI.Format("%s",nvparam.szImei1);
			temp.Format("Read IMEI1 = %s",tempReadIMEI);
			this->Display((LPSTR)(LPCTSTR)temp,0);

			if(this->m_csWriteIMEI1_15 != tempReadIMEI)
			{
				this->Display("IMEI1 Input and IMEI1 Read From Module are inconsistent Fail...",1);
				return FALSE;
			}
			else
			{
				this->Display("IMEI1 Input and IMEI1 Read From Module are consistent Fail...",0);
			}

			tempReadIMEI.Format("%s",nvparam.szImei2);
			temp.Format("Read IMEI2 = %s",tempReadIMEI);
			this->Display((LPSTR)(LPCTSTR)temp,0);
			
			if(this->m_csWriteIMEI2_15 != tempReadIMEI)
			{
				this->Display("IMEI2 Input and IMEI2 Read From Module are inconsistent Fail...",1);
				return FALSE;
			}
			else
			{
				this->Display("IMEI2 Input and IMEI2 Read From Module are consistent Pass...",0);
			}
		}	
	}
	
	return TRUE;
}


bool CFullWriteView::FP_WriteAndRead_ThreeIMEI()
{
	FASTNVACCESS_T      nvparam;
    ZeroMemory((void *)&nvparam, sizeof(nvparam));
	CString temp;
	IMEISV_struct_T IMEISV_W;
	IMEISV_struct_T IMEISV_R;
	CString tempReadIMEI;
	
	if (m_iPlatform == 0 || m_iPlatform == 1)
	{
		strcpy(IMEISV_W.imei,this->m_csWriteIMEI1_15); 
		IMEISV_W.imei[15]='\0';
		m_MetaappResult= METAAPP_writeIMEItoNVRAM_Ex3(m_nMetaHandle,5000,FALSE,0,1,&IMEISV_W);
		Sleep(200); 		
		if(m_MetaappResult!=METAAPP_SUCCESS)   
		{
			temp.Format("Write IMEI1 = %s Fail...",this->m_csWriteIMEI1_15);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		else
		{
			temp.Format("Write IMEI1 = %s  Pass...",this->m_csWriteIMEI1_15);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		m_MetaappResult=METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,1,&IMEISV_R);
		tempReadIMEI.Format("%s",IMEISV_R.imei);
		if(m_MetaappResult!=METAAPP_SUCCESS)   
		{
			this->Display("Read IMEI1 Fail...",1);
			return FALSE;
		}
		else
		{
			temp.Format("Read IMEI1 = %s",tempReadIMEI);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		if(this->m_csWriteIMEI1_15 != tempReadIMEI)
		{
			this->Display("IMEI1 Input and IMEI1 Read From Module are inconsistent Fail...",1);
			return FALSE;
		}
		else
		{
			this->Display("IMEI1 Input and IMEI1 Read From Module are consistent Pass......",0);
		}	
		
		strcpy(IMEISV_W.imei,this->m_csWriteIMEI2_15);
		IMEISV_W.imei[15]='\0';
		m_MetaappResult= METAAPP_writeIMEItoNVRAM_Ex3(m_nMetaHandle,5000,FALSE,0,2,&IMEISV_W);
		Sleep(200); 		
		if(m_MetaappResult!=METAAPP_SUCCESS)
		{
			temp.Format("Write IMEI2 = %s Fail...",this->m_csWriteIMEI2_15);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		else
		{
			temp.Format("Write IMEI2 = %s  Pass...",this->m_csWriteIMEI2_15);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		m_MetaappResult=METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,2,&IMEISV_R);
		tempReadIMEI.Format("%s",IMEISV_R.imei);
		if(m_MetaappResult!=METAAPP_SUCCESS)   
		{
			this->Display("Read IMEI2 Fail...",1);
			return FALSE;
		}
		else
		{
			temp.Format("Read IMEI2 = %s",tempReadIMEI);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		if(this->m_csWriteIMEI2_15 != tempReadIMEI)
		{
			this->Display("IMEI2 Input and IMEI2 Read From Module are inconsistent Fail...",1);
			return FALSE;
		}
		else
		{
			this->Display("IMEI2 Input and IMEI2 Read From Module are consistent Pass...",0);
		}
		
		strcpy(IMEISV_W.imei,this->m_csWriteIMEI3_15); 
		IMEISV_W.imei[15]='\0';
		m_MetaappResult= METAAPP_writeIMEItoNVRAM_Ex3(m_nMetaHandle,5000,FALSE,0,3,&IMEISV_W);
		Sleep(200); 		
		if(m_MetaappResult!=METAAPP_SUCCESS)
		{
			temp.Format("Write MEI3 = %s Fail...",this->m_csWriteIMEI3_15);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		else
		{
			temp.Format("Write IMEI3 = %s  Pass...",this->m_csWriteIMEI3_15);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		m_MetaappResult=METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,3,&IMEISV_R);
		tempReadIMEI.Format("%s",IMEISV_R.imei);
		if(m_MetaappResult!=METAAPP_SUCCESS)
		{
			this->Display("Read IMEI3 Fail...",1);
			return FALSE;
		}
		else
		{
			temp.Format("Read IMEI3 = %s",tempReadIMEI);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		if(this->m_csWriteIMEI3_15 != tempReadIMEI)
		{
			this->Display("IMEI3 Input and IMEI3 Read From Module are inconsistent Fail......",1);
			return FALSE;
		}
		else
		{
			this->Display("IMEI3 Input and IMEI3 Read From Module are consistent Pass......",0);
		}
	}
	else if (m_iPlatform == 2)
	{
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI1;
		strncpy((char *)nvparam.szImei1, m_csWriteIMEI1_15, MAX_IMEI_STR_LENGTH);
		
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI2;
		strncpy((char *)nvparam.szImei2, m_csWriteIMEI2_15, MAX_IMEI_STR_LENGTH);

		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI3;
		strncpy((char *)nvparam.szImei3, m_csWriteIMEI3_15, MAX_IMEI_STR_LENGTH);
		
		nErrorCode = SP_FastWriteNvInfo (g_hDiagPhone, &nvparam);
		
		if(RFT_SUCCESS != nErrorCode)
		{
			temp.Format("Write IMEI Fail...");
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		else
		{
			temp.Format("Write IMEI Pass...");
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}

		ZeroMemory((void *)&nvparam, sizeof(nvparam));
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI1;
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI2;
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI3;
		
		nErrorCode = SP_FastReadNvInfo (g_hDiagPhone, &nvparam);
		
		if(RFT_SUCCESS != nErrorCode)
		{
			this->Display("Read IMEI Fail...",1);
			return FALSE;
		}
		else
		{
			tempReadIMEI.Format("%s",nvparam.szImei1);
			temp.Format("Read IMEI1 = %s",tempReadIMEI);
			this->Display((LPSTR)(LPCTSTR)temp,0);
			
			if(this->m_csWriteIMEI1_15 != tempReadIMEI)
			{
				this->Display("IMEI1 Input and IMEI1 Read From Module are inconsistent Fail......",1);
				return FALSE;
			}
			else
			{
				this->Display("IMEI1 Input and IMEI1 Read From Module are consistent Pass......",0);
			}
			
			tempReadIMEI.Format("%s",nvparam.szImei2);
			temp.Format("读取IMEI2 = %s",tempReadIMEI);
			this->Display((LPSTR)(LPCTSTR)temp,0);
			
			if(this->m_csWriteIMEI2_15 != tempReadIMEI)
			{
				this->Display("IMEI2 Input and IMEI2 Read From Module are inconsistent Fail...",1);
				return FALSE;
			}
			else
			{
				this->Display("IMEI2 Input and IMEI2 Read From Module are consistent Pass...",0);
			}

			tempReadIMEI.Format("%s",nvparam.szImei3);
			temp.Format("读取IMEI3 = %s",tempReadIMEI);
			this->Display((LPSTR)(LPCTSTR)temp,0);
			
			if(this->m_csWriteIMEI3_15 != tempReadIMEI)
			{
				this->Display("IMEI3 Input and IMEI3 Read From Module are inconsistent Fail......",1);
				return FALSE;
			}
			else
			{
				this->Display("IMEI3 Input and IMEI3 Read From Module are consistent Pass...",0);
			}
		}	
	}

	return TRUE;
}


bool CFullWriteView::FP_WriteAndRead_FourIMEI()
{
	FASTNVACCESS_T      nvparam;
    ZeroMemory((void *)&nvparam, sizeof(nvparam));
	CString temp;
	IMEISV_struct_T IMEISV_W;
	IMEISV_struct_T IMEISV_R;
	CString tempReadIMEI;
	
	if (m_iPlatform == 0 || m_iPlatform == 1)
	{
		strcpy(IMEISV_W.imei,this->m_csWriteIMEI1_15); 
		IMEISV_W.imei[15]='\0';
		m_MetaappResult= METAAPP_writeIMEItoNVRAM_Ex3(m_nMetaHandle,5000,FALSE,0,1,&IMEISV_W);
		Sleep(200); 		
		if(m_MetaappResult!=METAAPP_SUCCESS)   
		{
			temp.Format("Write IMEI1 = %s Fail...",this->m_csWriteIMEI1_15);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		else
		{
			temp.Format("Write IMEI1 = %s  Pass...",this->m_csWriteIMEI1_15);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		m_MetaappResult=METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,1,&IMEISV_R);
		tempReadIMEI.Format("%s",IMEISV_R.imei);
		if(m_MetaappResult!=METAAPP_SUCCESS)   
		{
			this->Display("Read IMEI1 Fail...",1);
			return FALSE;
		}
		else
		{
			temp.Format("Read IMEI1 = %s",tempReadIMEI);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		if(this->m_csWriteIMEI1_15 != tempReadIMEI)
		{
			this->Display("IMEI1 Input and IMEI1 Read From Module are inconsistent Fail...",1);
			return FALSE;
		}
		else
		{
			this->Display("IMEI1 Input and IMEI1 Read From Module are consistent Pass...",0);
		}
		
		strcpy(IMEISV_W.imei,this->m_csWriteIMEI2_15);
		IMEISV_W.imei[15]='\0';
		m_MetaappResult= METAAPP_writeIMEItoNVRAM_Ex3(m_nMetaHandle,5000,FALSE,0,2,&IMEISV_W);
		Sleep(200);
		if(m_MetaappResult!=METAAPP_SUCCESS)
		{
			temp.Format("Write 入IMEI2 = %s Fail...",this->m_csWriteIMEI2_15);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		else
		{
			temp.Format("Write IMEI2 = %s  Pass...",this->m_csWriteIMEI2_15);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		m_MetaappResult=METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,2,&IMEISV_R);
		tempReadIMEI.Format("%s",IMEISV_R.imei);
		if(m_MetaappResult!=METAAPP_SUCCESS)   
		{
			this->Display("Read IMEI2 Fail...",1);
			return FALSE;
		}
		else
		{
			temp.Format("Read IMEI2 = %s",tempReadIMEI);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		if(this->m_csWriteIMEI2_15 != tempReadIMEI)
		{
			this->Display("IMEI2 Input and IMEI2 Read From Module are inconsistent Fail...",1);
			return FALSE;
		}
		else
		{
			this->Display("IMEI2 Input and IMEI2 Read From Module are consistent Pass...",0);
		}	
		
		strcpy(IMEISV_W.imei,this->m_csWriteIMEI3_15);
		IMEISV_W.imei[15]='\0';
		m_MetaappResult= METAAPP_writeIMEItoNVRAM_Ex3(m_nMetaHandle,5000,FALSE,0,3,&IMEISV_W);
		Sleep(200); 		
		if(m_MetaappResult!=METAAPP_SUCCESS)   
		{
			temp.Format("Write IMEI3 = %s Fail...",this->m_csWriteIMEI3_15);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		else
		{
			temp.Format("Write IMEI3 = %s  Pass...",this->m_csWriteIMEI3_15);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		m_MetaappResult=METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,3,&IMEISV_R);
		tempReadIMEI.Format("%s",IMEISV_R.imei);
		if(m_MetaappResult!=METAAPP_SUCCESS)   
		{
			this->Display("Read IMEI3 Fail...",1);
			return FALSE;
		}
		else
		{
			temp.Format("Read IMEI3 = %s",tempReadIMEI);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		if(this->m_csWriteIMEI3_15 != tempReadIMEI)
		{
			this->Display("IMEI3 Input and IMEI3 Read From Module are inconsistent Fail...",1);
			return FALSE;
		}
		else
		{
			this->Display("IMEI3 Input and IMEI3 Read From Module are consistent Pass...",0);
		}
		
		strcpy(IMEISV_W.imei,this->m_csWriteIMEI4_15); 
		IMEISV_W.imei[15]='\0';
		m_MetaappResult= METAAPP_writeIMEItoNVRAM_Ex3(m_nMetaHandle,5000,FALSE,0,4,&IMEISV_W);
		Sleep(200); 		
		if(m_MetaappResult!=METAAPP_SUCCESS)   
		{
			temp.Format("Write IMEI4 = %s  Fail...",this->m_csWriteIMEI4_15);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		else
		{
			temp.Format("Write IMEI4 = %s  Pass...",this->m_csWriteIMEI4_15);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		m_MetaappResult=METAAPP_readIMEIfromNVRAM_Ex3(m_nMetaHandle,5000,4,&IMEISV_R);
		tempReadIMEI.Format("%s",IMEISV_R.imei);
		if(m_MetaappResult!=METAAPP_SUCCESS)   
		{
			this->Display("Read IMEI4 Fail...",1);
			return FALSE;
		}
		else
		{
			temp.Format("Read IMEI4 = %s",tempReadIMEI);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		
		if(this->m_csWriteIMEI4_15 != tempReadIMEI)
		{
			this->Display("IMEI4 Input and IMEI4 Read From Module are inconsistent Fail...",1);
			return FALSE;
		}
		else
		{
			this->Display("IMEI4 Input and IMEI4 Read From Module are consistent Pass...",0);
		}
	}
	else if (m_iPlatform == 2)
	{
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI1;
		strncpy((char *)nvparam.szImei1, m_csWriteIMEI1_15, MAX_IMEI_STR_LENGTH);
		
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI2;
		strncpy((char *)nvparam.szImei2, m_csWriteIMEI2_15, MAX_IMEI_STR_LENGTH);
		
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI3;
		strncpy((char *)nvparam.szImei3, m_csWriteIMEI3_15, MAX_IMEI_STR_LENGTH);

		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI4;
		strncpy((char *)nvparam.szImei4, m_csWriteIMEI4_15, MAX_IMEI_STR_LENGTH);
		
		nErrorCode = SP_FastWriteNvInfo (g_hDiagPhone, &nvparam);
		
		if(RFT_SUCCESS != nErrorCode)
		{
			temp.Format("Write IMEI Fail...");
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		else
		{
			temp.Format("Write IMEI Pass...");
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}

		ZeroMemory((void *)&nvparam, sizeof(nvparam));
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI1;
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI2;
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI3;
		nvparam.dwOperMask |= FNAMASK_WRITE_IMEI4;
		
		nErrorCode = SP_FastReadNvInfo (g_hDiagPhone, &nvparam);
		
		if(RFT_SUCCESS != nErrorCode)
		{
			this->Display("Read IMEI Fail...",1);
			return FALSE;
		}
		else
		{
			tempReadIMEI.Format("%s",nvparam.szImei1);
			temp.Format("Read IMEI1 = %s",tempReadIMEI);
			this->Display((LPSTR)(LPCTSTR)temp,0);
			
			if(this->m_csWriteIMEI1_15 != tempReadIMEI)
			{
				this->Display("IMEI1 Input and IMEI1 Read From Module are inconsistent Fail...",1);
				return FALSE;
			}
			else
			{
				this->Display("IMEI1 Input and IMEI1 Read From Module are consistent Pass...",0);
			}
			
			tempReadIMEI.Format("%s",nvparam.szImei2);
			temp.Format("Read IMEI2 = %s",tempReadIMEI);
			this->Display((LPSTR)(LPCTSTR)temp,0);
			
			if(this->m_csWriteIMEI2_15 != tempReadIMEI)
			{
				this->Display("IMEI2 Input and IMEI2 Read From Module are inconsistent Fail...",1);
				return FALSE;
			}
			else
			{
				this->Display("IMEI2 Input and IMEI2 Read From Module are consistent Pass...",0);
			}
			
			tempReadIMEI.Format("%s",nvparam.szImei3);
			temp.Format("Read IMEI3 = %s",tempReadIMEI);
			this->Display((LPSTR)(LPCTSTR)temp,0);
			
			if(this->m_csWriteIMEI3_15 != tempReadIMEI)
			{
				this->Display("IMEI3 Input and IMEI3 Read From Module are inconsistent Fail...",1);
				return FALSE;
			}
			else
			{
				this->Display("IMEI3 Input and IMEI3 Read From Module are consistent Pass...",0);
			}

			tempReadIMEI.Format("%s",nvparam.szImei4);
			temp.Format("读取IMEI4 = %s",tempReadIMEI);
			this->Display((LPSTR)(LPCTSTR)temp,0);
			
			if(this->m_csWriteIMEI4_15 != tempReadIMEI)
			{
				this->Display("IMEI4 Input and IMEI4 Read From Module are inconsistent Fail...",1);
				return FALSE;
			}
			else
			{
				this->Display("IMEI4 Input and IME4 Read From Module are consistent Pass...",0);
			}
		}	
	}
	
	return TRUE;
}


char CFullWriteView::Ascii2BCD(char iAscii)
{
	char iBCD;
	if ( iAscii>= '0' && iAscii<= '9')
	{
        iBCD = iAscii - '0';
		
	} else if ( iAscii>= 'a' && iAscii<= 'f' )
	{
        iBCD = iAscii - 'a' + 0x0a;
		
	} else if ( iAscii>= 'A' && iAscii<= 'F' )
	{
        iBCD = iAscii - 'A' + 0x0a;
	} else
	{
		return -1;
	}
	
	return iBCD;
}



BOOL CFullWriteView::SaveToMdb_ScanMode()
{
	CString sql;
	_variant_t var;

	if(!this->m_iScanPSN)
		this->m_csWriteSN.Empty();
	this->m_csWriteBT.Empty();
	this->m_csWriteWIFI.Empty();

	switch(this->m_iIMEIType)
	{
	case 0:
		sql.Format("INSERT INTO %s_%s_ColorBox (IMEI1,Barcode,ProductSN,BTAddress,WIFIMAC,PSData1,PSData2,Status,Enable) VALUES \
			('%s','%s','%s','%s','%s','%s','%s',%d,%d)",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder, \
			this->m_csWriteIMEI1_15,this->m_csPcbaSN,this->m_csWriteSN,this->m_csWriteBT,this->m_csWriteWIFI, \
			this->m_csPSdata1,this->m_csPSdata2,0,1);
		
		try
		{
			((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		}
		catch(_com_error e)
		{
			return FALSE;
		}
		break;
	case 1:
		sql.Format("INSERT INTO %s_%s_ColorBox (IMEI1,IMEI2,Barcode,ProductSN,BTAddress,WIFIMAC,PSData1,PSData2,Status,Enable) \
			VALUES ('%s','%s','%s','%s','%s','%s','%s','%s',%d,%d)",(char*)(LPCTSTR)this->m_csCurrentProduct, \
			this->m_csCurrentOrder,this->m_csWriteIMEI1_15,this->m_csWriteIMEI2_15,this->m_csPcbaSN, \
			this->m_csWriteSN,this->m_csWriteBT,this->m_csWriteWIFI,this->m_csPSdata1,this->m_csPSdata2,0,1);
		try
		{
			((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		}
		catch(_com_error e)
		{
			return FALSE;
		}
		break;
	case 2:
		sql.Format("INSERT INTO %s_%s_ColorBox (IMEI1,IMEI2,IMEI3,Barcode,ProductSN,BTAddress,WIFIMAC,PSData1,PSData2,Status,Enable) \
			VALUES ('%s','%s','%s','%s','%s','%s','%s','%s','%s',%d,%d)",(char*)(LPCTSTR)this->m_csCurrentProduct, \
			this->m_csCurrentOrder,this->m_csWriteIMEI1_15,this->m_csWriteIMEI2_15,this->m_csWriteIMEI3_15, \
			this->m_csPcbaSN,this->m_csWriteSN,this->m_csWriteBT,this->m_csWriteWIFI,this->m_csPSdata1,this->m_csPSdata2,0,1);
		try
		{
			((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		}
		catch(_com_error e)
		{
			return FALSE;
		}
		break;
	case 3:
		sql.Format("INSERT INTO %s_%s_ColorBox (IMEI1,IMEI2,IMEI3,IMEI4,Barcode,ProductSN,BTAddress,WIFIMAC,PSData1,PSData2,Status, \
			Enable) VALUES ('%s','%s','%s','%s','%s','%s','%s','%s','%s','%s',%d,%d)",(char*)(LPCTSTR)this->m_csCurrentProduct, \
			this->m_csCurrentOrder,this->m_csWriteIMEI1_15,this->m_csWriteIMEI2_15,this->m_csWriteIMEI3_15, \
			this->m_csWriteIMEI4_15,this->m_csPcbaSN,this->m_csWriteSN,this->m_csWriteBT,this->m_csWriteWIFI,this->m_csPSdata1,
			this->m_csPSdata2,0,1);
		try
		{
			((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		}
		catch(_com_error e)
		{
			return FALSE;
		}
		break;
	default:
		break;
	}

	sql.Format("INSERT INTO %s_%s_ProductionLine (IMEI1,WriteTool,WriteDate) VALUES ('%s','%s',getdate())", \
		(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder, this->m_csWriteIMEI1_15,this->m_csCurrentLine);
	try
	{
		((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	
	return TRUE;
}


bool CFullWriteView::CheckNetRepeatFinal()
{
	CString temp;
	CString csNoSave="Not saved to the database...";
	CString csSave="It has been saved to the database...";

	//PCB SN
	if(!Check_PCB_SN_Repeat())
	{
		temp.Format("PCB SN = %s %s",this->m_csPcbaSN,csSave);
		this->Display((LPSTR)(LPCTSTR)temp,0);
	}
	else
	{
		temp.Format("PCB SN = %s %s",this->m_csPcbaSN,csNoSave);
		this->Display((LPSTR)(LPCTSTR)temp,1);
		return FALSE;
	}

	//SN
	if(this->m_iScanPSN)
	{
		if(!Check_ProductSN_Repeat())
		{
			temp.Format("Product SN = %s %s",this->m_csWriteSN,csSave);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		else
		{
			temp.Format("Product SN = %s %s",this->m_csWriteSN,csNoSave);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
	}

	//IMEI
	switch(this->m_iIMEIType)
	{
	case 0:
		if(!Check_IMEI1_Repeat())
		{
			temp.Format("Product IMEI1 = %s %s",this->m_csWriteIMEI1_15,csSave);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		else
		{
			temp.Format("Product IMEI1 = %s %s",this->m_csWriteIMEI1_15,csNoSave);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		break;
	case 1:
		if(!Check_IMEI1_Repeat())
		{
			temp.Format("Product IMEI1 = %s %s",this->m_csWriteIMEI1_15,csSave);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		else
		{
			temp.Format("Product IMEI1 = %s %s",this->m_csWriteIMEI1_15,csNoSave);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}

		if(!Check_IMEI2_Repeat())
		{
			temp.Format("Product IMEI2 = %s %s",this->m_csWriteIMEI2_15,csSave);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		else
		{
			temp.Format("Product IMEI2 = %s %s",this->m_csWriteIMEI2_15,csNoSave);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		break;
	case 2:
		if(!Check_IMEI1_Repeat())
		{
			temp.Format("Product IMEI1 = %s %s",this->m_csWriteIMEI1_15,csSave);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		else
		{
			temp.Format("Product IMEI1 = %s %s",this->m_csWriteIMEI1_15,csNoSave);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		
		if(!Check_IMEI2_Repeat())
		{
			temp.Format("Product IMEI2 = %s %s",this->m_csWriteIMEI2_15,csSave);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		else
		{
			temp.Format("Product IMEI2 = %s %s",this->m_csWriteIMEI2_15,csNoSave);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}

		if(!Check_IMEI3_Repeat())
		{
			temp.Format("Product IMEI3 = %s %s",this->m_csWriteIMEI3_15,csSave);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		else
		{
			temp.Format("Product IMEI3 = %s %s",this->m_csWriteIMEI3_15,csNoSave);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		break;
	case 3:
		if(!Check_IMEI1_Repeat())
		{
			temp.Format("Product IMEI1 = %s %s",this->m_csWriteIMEI1_15,csSave);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		else
		{
			temp.Format("Product IMEI1 = %s %s",this->m_csWriteIMEI1_15,csNoSave);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		
		if(!Check_IMEI2_Repeat())
		{
			temp.Format("Product IMEI2 = %s %s",this->m_csWriteIMEI2_15,csSave);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		else
		{
			temp.Format("Product IMEI2 = %s %s",this->m_csWriteIMEI2_15,csNoSave);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		
		if(!Check_IMEI3_Repeat())
		{
			temp.Format("Product IMEI3 = %s %s",this->m_csWriteIMEI3_15,csSave);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		else
		{
			temp.Format("Product IMEI3 = %s %s",this->m_csWriteIMEI3_15,csNoSave);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}

		if(!Check_IMEI4_Repeat())
		{
			temp.Format("Product IMEI4 = %s %s",this->m_csWriteIMEI4_15,csSave);
			this->Display((LPSTR)(LPCTSTR)temp,0);
		}
		else
		{
			temp.Format("Product IMEI4 = %s %s",this->m_csWriteIMEI4_15,csNoSave);
			this->Display((LPSTR)(LPCTSTR)temp,1);
			return FALSE;
		}
		break;
	default:
		break;
	}
	
	return TRUE;
}


//断开MODEM META
bool CFullWriteView::DisconnectInMetaMode()
{
	m_MetaResult = META_DisconnectInMetaMode_r(this->m_nMetaHandle);
	if(m_MetaResult != METAAPP_SUCCESS)
	{
		return FALSE;
	}
	return TRUE;
}


//断开AP META
bool CFullWriteView::DisconnectInApMeta()
{
	if(!this->m_ApExe.AP_META_DisconnectInMetaMode_r())
	{
		return FALSE;
	}
	return TRUE;
}


void CFullWriteView::SP_Exit_MetaModemMode()
{
	METAAPP_DisconnectWithTarget(this->m_nMetaHandle);
	this->m_ApExe.Switch2SP_META_Mode(this->m_usb_port);
	this->m_ApExe.Exit_MetaAPMode();
}

int CFullWriteView::GetCurrentComPort()
{
	CString text;
	m_ctrComboxComPort.GetLBText(m_ctrComboxComPort.GetCurSel(),text);	
	if(text=="USB")		
	{
		return this->m_usb_port;
	}
	else
	{
		return this->m_comport;
	}
}


bool CFullWriteView::Switch_AP_TO_MEDEM_META_Mode(int comport)
{
	CString text;
	m_ctrComboxComPort.GetLBText(m_ctrComboxComPort.GetCurSel(),text);	
	
    META_RESULT MetaResult;
	META_ConnectInMETA_Req BootRequest;
	int BootStop=0;
	META_ConnectInMETA_Report BootReport;
	META_ConnectByUSB_Req usbRequest;
    META_ConnectByUSB_Report usbReport;
	
	//---------------------Connect with target ----------------------------------
	BootRequest.com_port = comport;
	// [META] META stage baudrate polling array, it must end with META_BAUD_END.
	BootRequest.baudrate[0] = META_BAUD115200;
	BootRequest.baudrate[1] = META_BAUD230400;
	BootRequest.baudrate[2] = META_BAUD460800;
	BootRequest.baudrate[3] = META_BAUD921600;
	BootRequest.baudrate[4] = META_BAUD57600;
	BootRequest.baudrate[5] = META_BAUD_END;
	
	BootRequest.flowctrl = META_SW_FLOWCTRL;
	BootRequest.ms_connect_timeout = 80000; //30000;
	
	if(text=="USB")
	{
		usbRequest.com_port = comport;
		usbRequest.ms_connect_timeout =8000;
		MetaResult = META_ConnectInMetaModeByUSB_r(this->m_nMetaHandle, &usbRequest, &BootStop, &usbReport);
	}
	else
	{
        MetaResult = META_ConnectInMetaMode_r(this->m_nMetaHandle, &BootRequest, &BootStop, &BootReport);
	}
	
	if(META_SUCCESS != MetaResult && META_MAUI_DB_INCONSISTENT != MetaResult)
		return FALSE;
	
	return TRUE;
}


bool CFullWriteView::AP_CheckMAC()
{
	WiFi_MacAddress_S tWifiMac_C, tWifiMac_R;		
	char strWifiMac_C [ WIFI_MAC_MAX_LENGTH + 1 ];
	char srtWifiMac_R [ WIFI_MAC_MAX_LENGTH + 1 ];
	int ilen;

	//获取比对WIFI MAC位数
	ilen = this->m_csWIFIMAC.GetLength();

	sprintf(strWifiMac_C,"%s",(LPSTR)(LPCTSTR)this->m_csWIFIMAC);

	//转换MAC
	for (int i = 0; i < 12; i++ )
	{
		strWifiMac_C[i] = Ascii2BCD( strWifiMac_C[i] );
	}

	//读MAC
	m_MetaappResult=(METAAPP_RESULT)this->m_ApExe.REQ_ReadWifiMACFromNVRAM_Start(tWifiMac_R.mac_addr);
	if(m_MetaappResult!=METAAPP_SUCCESS)   
	{
		this->Display("读取MAC地址失败...",1);
		return FALSE;
	}
	else
	{
		this->Display("读取MAC地址成功...",0);
	}

	//转换MAC
	srtWifiMac_R[1]  = tWifiMac_R.mac_addr[1] & 0x0f;
	srtWifiMac_R[0]  = tWifiMac_R.mac_addr[1] >> 4;
	srtWifiMac_R[3]  = tWifiMac_R.mac_addr[0] & 0x0f;
	srtWifiMac_R[2]  = tWifiMac_R.mac_addr[0] >> 4;
	srtWifiMac_R[5]  = tWifiMac_R.mac_addr[3] & 0x0f;
	srtWifiMac_R[4]  = tWifiMac_R.mac_addr[3] >> 4;
	srtWifiMac_R[7]  = tWifiMac_R.mac_addr[2] & 0x0f;
	srtWifiMac_R[6]  = tWifiMac_R.mac_addr[2] >> 4;
	srtWifiMac_R[9]  = tWifiMac_R.mac_addr[5] & 0x0f;
	srtWifiMac_R[8]  = tWifiMac_R.mac_addr[5] >> 4;
	srtWifiMac_R[11] = tWifiMac_R.mac_addr[4] & 0x0f;
	srtWifiMac_R[10] = tWifiMac_R.mac_addr[4] >> 4;

	//比对MAC
	for (int j = 0; j < ilen; j++ )
	{
		if (strWifiMac_C[j] != srtWifiMac_R[j])
		{
			this->Display("MAC地址比对不一致...",1);
			return FALSE;
		}
	}

	this->Display("MAC地址比对一致...",0);
	return TRUE;
}


void CFullWriteView::SaveLogToFile()
{
	CString log,strLogPath;
	this->m_cedTrace.GetWindowText(log);
	strLogPath.Format("%sBarcode=%s,ProductSN=%s.log",this->m_Config.m_csLogPath,this->m_csPcbaSN,this->m_csWriteSN);

	CFile m_file;
	m_file.Open((LPSTR)(LPCTSTR)strLogPath,CFile::modeCreate|CFile::modeWrite);
	m_file.Write((LPSTR)(LPCTSTR)log,log.GetLength()); 
	m_file.Close();
}


int CFullWriteView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	CSplashWnd::ShowSplashScreen(this);
	
	return 0;
}



bool CFullWriteView::SP_CHECK_NV()
{
	//20150801 GLORY
#ifdef _DEBUG
	return TRUE;
#endif
	//end
	//检测BARCODE长度
	if (this->m_csPcbaSN.GetLength()< 62)
	{
		Display("NVRAM:Mobile phone is not calibrated or full wipe Download...",1);
		return FALSE;
	}
	
	//ian
	if(this->m_iCheckBoardVersion)
	{
		char OPS[6] = "";			 
		for(int i = 0;i < 5;i++)
		{
			OPS[i] = this->m_csPcbaSN.GetAt(i);			  
		}
		OPS[5] = '\0';
		CString csOPS;
		csOPS.Format("%s",OPS);
		if(!this->CheckBoardVersion(csOPS))
		{
			Display("NVRAM:Motherboard model test failed...",1);
			Display((LPSTR)(LPCTSTR)csOPS,1);
			return FALSE;
		}
		else
		{
			Display("NVRAM:Motherboard model test success...",0);
			Display((LPSTR)(LPCTSTR)csOPS,0);
		}		
	}

	//检测校准终测标志位
	if(this->m_iBTFT)
	{
		if(this->m_iPlatform==0) //fixture phone
		{

			if(m_csPcbaSN.GetAt(60)!='1' ||
				m_csPcbaSN.GetAt(61)!='0' ||
				m_csPcbaSN.GetAt(62)!='P')
			{
				Display("NVRAM:Mobile phone is not calibrated or final test...",1);
				return FALSE;
			}
			else
			{
				Display("NVRAM:Test and calibration of the final success...",0);		
			}
		}
		else
		{
			if( m_csPcbaSN.GetAt(60)!='1' ||
				m_csPcbaSN.GetAt(61)!='0' ||
				m_csPcbaSN.GetAt(62)!='P')
			{
				Display("NVRAM:Mobile phone is not calibrated or final test...",1);
				return FALSE;
			}
			else
			{
				Display("NVRAM:Test and calibration of the final success...",0);		
			}
		}
	}

	return TRUE;
}


bool CFullWriteView::CheckBoardVersion(CString str)
{
	 if(strcmp((LPSTR)(LPCTSTR)str, (LPSTR)(LPCTSTR)this->m_csBoardVersion))
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}


bool CFullWriteView::GetProductOrderInfo()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	try
	{
		sql.Format("select * from ProductList where Enable=1 and OrderName='%s'",m_csCurrentOrder);
		
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	
		if(!((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("ProductName");
			temp=VariantToCString(var);
			this->m_csCurrentProduct= temp;

			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("IMEIType");
			this->m_iIMEIType=var.intVal;
 
			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("IMEIRangeType");
			this->m_iIMEIRangeType=var.intVal;

			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1_STR");
			temp=VariantToCString(var);
			this->m_imei1_start= temp;

			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1_END");
			temp=VariantToCString(var);
			this->m_imei1_end= temp;

			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("IMEI2_STR");
			temp=VariantToCString(var);
			this->m_imei2_start= temp;

			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("IMEI2_END");
			temp=VariantToCString(var);
			this->m_imei2_end= temp;

			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("IMEI3_STR");
			temp=VariantToCString(var);
			this->m_imei3_start= temp;

			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("IMEI3_END");
			temp=VariantToCString(var);
			this->m_imei3_end= temp;

			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("IMEI4_STR");
			temp=VariantToCString(var);
			this->m_imei4_start= temp;

			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("IMEI4_END");
			temp=VariantToCString(var);
			this->m_imei4_end= temp;

			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("Color");
			temp=VariantToCString(var);
			this->m_csCurrentColor= temp;
		}
		else
		{
			return FALSE;
		}
		
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}


CString CFullWriteView::VariantToCString(VARIANT   var)   
{   
	CString strValue;   
	_variant_t var_t;   
	_bstr_t bst_t;   
	//time_t cur_time;   
	CTime time_value;   
	COleCurrency var_currency; 
	COleDateTime cur_time;
    
	switch(var.vt)   
	{   
	case   VT_EMPTY:   
		strValue   =   _T("");   
		break;   
	case   VT_UI1:   
		strValue.Format("%d",var.bVal);   
		break;   
	case   VT_I2:   
		strValue.Format("%d",var.iVal);   
		break;   
	case   VT_I4:   
		strValue.Format("%d",var.lVal);   
		break;   
	case   VT_R4:   
		strValue.Format("%f",var.fltVal);   
		break;   
	case   VT_R8:   
		strValue.Format("%f",var.dblVal);   
		break;   
	case   VT_CY:   
		var_currency   =   var;   
		strValue   =   var_currency.Format(0);   
		break;   
	case   VT_BSTR:   
		var_t   =   var;   
		bst_t   =   var_t;   
		strValue.Format   ("%s",(const   char*)bst_t);   
		break;   
	case   VT_NULL:   
		strValue   =   _T("");   
		break;   
	case   VT_DATE:   
		//cur_time   =   (long)var.date;   
		// time_value   =   cur_time;   
		// strValue   =   time_value.Format("%Y-%m-%d");  
		cur_time   =   var; 
		strValue   =   cur_time.Format("%Y-%m-%d"); 
		break;   
	case   VT_BOOL:   
		strValue.Format("%d",var.boolVal   );   
		break;   
	default:     
		strValue   =   _T("");   
		break;   
	}   

	return   strValue;   
}
void CFullWriteView::SP_Exit_MetaModemMode_New()
{
	// 根据当前META模式选择从AP推出还是从MODEM退出
	if (m_eMetaMode == SP_AP_META || m_eMetaMode == SP_AP2MD_FAIL)
    {
        ExitAPMetaMode();
    }
    else if(m_eMetaMode == SP_MODEM_META || m_eMetaMode == SP_MD2AP_FAIL)
    {
        ExitSPModemMeta();
    }
	//end
}


void CFullWriteView::OnChangeEditInputimei1() 
{
	m_iFirstKeyTime = GetTickCount();
	if(m_csInputIMEI1.GetLength() != 0)
	{	
		m_iKeyPeriod = m_iFirstKeyTime - m_iLastKeyTime;
#ifndef _DEBUG
		if(m_iKeyPeriod > 100)
		{
			Display("Please Use The Scanner",1);
			m_csInputIMEI1.Empty();
			UpdateData(FALSE);
			m_ctrInputIMEI1.SetFocus();
			m_ctrInputIMEI1.SetSel(0,-1);
			ShowCalResult(FAIL);
			return;
		}
#endif
	}
	m_iLastKeyTime = m_iFirstKeyTime;

	UpdateData();
	if(m_csInputIMEI1.Right(2)=="\r\n" )
	{
		m_cedTrace.SetWindowText("");

		m_csInputIMEI1.Replace("\r\n","");
		UpdateData(FALSE);
		
		if(!CheckIMEI1())
		{
			m_csInputIMEI1.Empty();
			UpdateData(FALSE);
			m_ctrInputIMEI1.SetFocus();
			m_ctrInputIMEI1.SetSel(0,-1);
			ShowCalResult(FAIL);
			return;
		}
		
		if (m_iIMEIType != 0)
		{
			if (this->m_Config.m_iIsScanMainImei==0)
			{
				this->m_ctrInputIMEI1.EnableWindow(FALSE);
				this->m_ctrInputIMEI2.SetFocus();
				this->m_ctrInputIMEI2.SetSel(0,-1);
			}
			else  //查询XXX_XXX_IMEIRange，获取与IMEI1相对应的其他IMEI
			{
				if (!GetOtherIMEI())
				{
					Display("Get Another IMEI About The IMEI Of Input Fail!",1);
					m_csInputIMEI1.Empty();
					UpdateData(FALSE);
					m_ctrInputIMEI1.SetFocus();
					m_ctrInputIMEI1.SetSel(0,-1);
					ShowCalResult(FAIL);
					return;
				}
 				if(this->m_iScanPSN)
 				{
 					this->m_ctrInputIMEI1.EnableWindow(FALSE);
 					this->m_ctrInputPSN.SetFocus();
 					this->m_ctrInputPSN.SetSel(0,-1);
 				}
 				else
 				{
					this->m_ctrInputIMEI1.EnableWindow(FALSE);
					OnBtnStart();
				}
			}
		}
		else
		{
 			if(this->m_iScanPSN)
 			{
				this->m_ctrInputIMEI1.EnableWindow(FALSE);
 				this->m_ctrInputPSN.SetFocus();
 				this->m_ctrInputPSN.SetSel(0,-1);
 			}
 			else
 			{
				this->m_ctrInputIMEI1.EnableWindow(FALSE);
				OnBtnStart();
			}
		}
	}
}


void CFullWriteView::OnChangeEditInputimei2()
{	
	m_iFirstKeyTime = GetTickCount();
	if(m_csInputIMEI2.GetLength() != 0)
	{
		m_iKeyPeriod = m_iFirstKeyTime - m_iLastKeyTime;
		if(m_iKeyPeriod > 100)
		{   
			Display("Please Use The Scanner!",1);
			m_csInputIMEI2.Empty();
			UpdateData(FALSE);
			m_ctrInputIMEI2.SetFocus();
			m_ctrInputIMEI2.SetSel(0,-1);
			ShowCalResult(FAIL);
			return;
		}
	}
	m_iLastKeyTime = m_iFirstKeyTime;

	UpdateData();
	if(m_csInputIMEI2.Right(2)=="\r\n")
	{
		m_csInputIMEI2.Replace("\r\n","");
		UpdateData(FALSE);
		if(!CheckIMEI2())
		{
			m_csInputIMEI2.Empty();
			m_ctrInputIMEI1.EnableWindow();
			m_csInputIMEI1.Empty();
			UpdateData(FALSE);
			m_ctrInputIMEI1.SetFocus();
			m_ctrInputIMEI1.SetSel(0,-1);
			ShowCalResult(FAIL);
			return;
		}

		if (m_iIMEIType != 1)
		{
			this->m_ctrInputIMEI2.EnableWindow(FALSE);
			this->m_ctrInputIMEI3.SetFocus();
			this->m_ctrInputIMEI3.SetSel(0,-1);
		}
		else
		{
 			if(this->m_iScanPSN )
 			{
 				this->m_ctrInputIMEI2.EnableWindow(FALSE);
 				this->m_ctrInputPSN.SetFocus();
 				this->m_ctrInputPSN.SetSel(0,-1);
 			}
 			else
			{
				this->m_ctrInputIMEI2.EnableWindow(FALSE);
				OnBtnStart();
			}
		}
	}
}


void CFullWriteView::OnChangeEditInputimei3() 
{
	m_iFirstKeyTime = GetTickCount();
	if(m_csInputIMEI3.GetLength() != 0)
	{
		m_iKeyPeriod = m_iFirstKeyTime - m_iLastKeyTime;
		if(m_iKeyPeriod > 100)
		{   
			Display("Please Use The Scanner!",1);
			m_csInputIMEI3.Empty();
			UpdateData(FALSE);
			m_ctrInputIMEI3.SetFocus();
			m_ctrInputIMEI3.SetSel(0,-1);
			ShowCalResult(FAIL);
			return;
		}
	}
	m_iLastKeyTime = m_iFirstKeyTime;

	UpdateData();

	if(m_csInputIMEI3.Right(2)=="\r\n")
	{
		m_csInputIMEI3.Replace("\r\n","");
		UpdateData(FALSE);
		if(!CheckIMEI3())
		{
			m_csInputIMEI3.Empty();
			m_ctrInputIMEI2.EnableWindow();
			m_csInputIMEI2.Empty();
			m_ctrInputIMEI1.EnableWindow();			
			m_csInputIMEI1.Empty();
			UpdateData(FALSE);
			m_ctrInputIMEI1.SetFocus();
			m_ctrInputIMEI1.SetSel(0,-1);
			ShowCalResult(FAIL);
			return;
		}

		if (m_iIMEIType != 2)
		{
			this->m_ctrInputIMEI3.EnableWindow(FALSE);
			this->m_ctrInputIMEI4.SetFocus();
			this->m_ctrInputIMEI4.SetSel(0,-1);
		}
		else
		{
 			if(this->m_iScanPSN)
 			{
 				this->m_ctrInputIMEI3.EnableWindow(FALSE);
 				this->m_ctrInputPSN.SetFocus();
 				this->m_ctrInputPSN.SetSel(0,-1);
 			}
 			else
 			{
				this->m_ctrInputIMEI3.EnableWindow(FALSE);
				OnBtnStart();
			}
		}
	}
}


void CFullWriteView::OnChangeEditInputimei4() 
{
	m_iFirstKeyTime = GetTickCount();
	if(m_csInputIMEI4.GetLength() != 0)
	{
		m_iKeyPeriod = m_iFirstKeyTime - m_iLastKeyTime;
		if(m_iKeyPeriod > 100)
		{   
			Display("Please Use The Scanner!",1);
			m_csInputIMEI4.Empty();
			UpdateData(FALSE);
			m_ctrInputIMEI4.SetFocus();
			m_ctrInputIMEI4.SetSel(0,-1);
			ShowCalResult(FAIL);
			return;
		}
	}
	m_iLastKeyTime = m_iFirstKeyTime;

	UpdateData();

	if(m_csInputIMEI4.Right(2)=="\r\n")
	{
		m_csInputIMEI4.Replace("\r\n","");
		UpdateData(FALSE);
		if(!CheckIMEI4())
		{
			m_csInputIMEI4.Empty();
			m_ctrInputIMEI3.EnableWindow();
			m_csInputIMEI3.Empty();
			m_ctrInputIMEI2.EnableWindow();
			m_csInputIMEI2.Empty();
			m_ctrInputIMEI1.EnableWindow();		
			m_csInputIMEI1.Empty();
			UpdateData(FALSE);
			m_ctrInputIMEI1.SetFocus();
			m_ctrInputIMEI1.SetSel(0,-1);
			ShowCalResult(FAIL);
			return;
		}
		
 		if(this->m_iScanPSN)
 		{
 			this->m_ctrInputIMEI4.EnableWindow(FALSE);
 			this->m_ctrInputPSN.SetFocus();
 			this->m_ctrInputPSN.SetSel(0,-1);
 		}
 		else
 		{
			this->m_ctrInputIMEI4.EnableWindow(FALSE);
			OnBtnStart();
		}
	}
}


void CFullWriteView::OnChangeEditInputpsn() 
{
	m_iFirstKeyTime = GetTickCount();
	if(m_csInputPSN.GetLength() != 0)
	{
#ifndef _DEBUG
		m_iKeyPeriod = m_iFirstKeyTime - m_iLastKeyTime;
		if(m_iKeyPeriod > 100) 
		{
			Display("Please Use The Scanner!",1);
			m_csInputPSN.Empty();
			UpdateData(FALSE);
			m_ctrInputPSN.SetFocus();
			m_ctrInputPSN.SetSel(0,-1);
			ShowCalResult(FAIL);
			return;
		}
#endif
	}
	m_iLastKeyTime = m_iFirstKeyTime;

	UpdateData();

	if(m_csInputPSN.Right(2)=="\r\n")
	{
		m_csInputPSN.Replace("\r\n","");
		UpdateData(FALSE);
			
		if((!CheckPSNLength()) || (!CheckPSNStatic()))
		{
			m_csInputIMEI1.Empty();
			m_csInputIMEI2.Empty();
			m_csInputIMEI3.Empty();
			m_csInputIMEI4.Empty();
			SetInputCtrEnableWindow(TRUE);

			m_csInputPSN.Empty();
			UpdateData(FALSE);
			m_ctrInputIMEI1.SetFocus();
			m_ctrInputIMEI1.SetSel(0,-1);
			ShowCalResult(FAIL);
			return;
		}
		
		this->m_ctrInputPSN.EnableWindow(FALSE);
		OnBtnStart();
	}
}


BOOL CFullWriteView::CheckIMEI1()
{
	//20150801 GLORY
#ifdef _DEBUG
	return TRUE;
#endif
	_variant_t var;
	CString sql;
	CString temp;

	if(m_csInputIMEI1.GetLength()!=15)
	{
		Display("IMEI1 Length Is Not 15 Fail...",1);
		this->m_ctrInputIMEI1.SetSel(0,-1);
		return FALSE;
	}

	if (m_iIMEIRangeType==0)
	{
		if(m_csInputIMEI1.Left(14)>this->m_imei1_end || m_csInputIMEI1.Left(14)<this->m_imei1_start)
		{
			Display("IMEI1 Out Of Range...",1);
			this->m_ctrInputIMEI1.SetSel(0,-1);
			return FALSE;
		}
	}
	else if(m_iIMEIRangeType==1)
	{
		sql.Format("select * from %s_%s_IMEIRange WHERE IMEI1='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csInputIMEI1);
		
		try
		{
			if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
				((CFullWriteApp *)AfxGetApp())->m_pRst->Close();

			((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			
			if(((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				Display("IMEI1 Is Not Exsit In Server Table Fail...",1);
				return FALSE;
			}
			if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
				((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}
	
	char calculate_digit;
	calculate_15_digit_imei((char*)(LPCTSTR)m_csInputIMEI1.Left(14),calculate_digit);
	
	if(calculate_digit!=m_csInputIMEI1.Right(1))
	{
		Display("Illegal IMEI1,The 15th IMEI Error Fail...",1);
		this->m_ctrInputIMEI1.SetSel(0,-1);
		return FALSE;
	}
	
	//lucky 20160121 SQL重号检查
	sql.Format("select * from %s_%s_ColorBox WHERE (IMEI1='%s' or IMEI2='%s' or IMEI3='%s' or IMEI4='%s')", \
		(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csInputIMEI1,m_csInputIMEI1,m_csInputIMEI1,m_csInputIMEI1);
	try
	{
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		
		((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			Display("This IMEI1 already exists...",1);
			return FALSE;
		}
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		Display("unknown error",1);
		return FALSE;
	}
	//lucky 20160121 end

	return TRUE;
}


BOOL CFullWriteView::CheckIMEI2()
{
	_variant_t var;
	CString sql;

	if(m_csInputIMEI2.GetLength()!=15)
	{
		Display("IMEI2 Length Is Not 15 Fail...",1);
		this->m_ctrInputIMEI2.SetSel(0,-1);
		return FALSE;
	}

	if(m_csInputIMEI1==m_csInputIMEI2)
	{
		Display("IMEI1 and IMEI2 cannot be the same Fail...",1);
		this->m_ctrInputIMEI2.SetSel(0,-1);
		return FALSE;
	}
	
	if (m_iIMEIRangeType==0)
	{
		if(m_csInputIMEI2.Left(14)>this->m_imei2_end || m_csInputIMEI2.Left(14)<this->m_imei2_start)
		{
			Display("IMEI2 Out Of Range...",1);
			this->m_ctrInputIMEI2.SetSel(0,-1);
			return FALSE;
		}
	}
	else if(m_iIMEIRangeType==1)
	{
		sql.Format("select * from %s_%s_IMEIRange WHERE IMEI2='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csInputIMEI2);
		
		try
		{
			if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
				((CFullWriteApp *)AfxGetApp())->m_pRst->Close();

			((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			
			if(((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				Display("IMEI2 Is Not Exist In The Database...",1);
				return FALSE;
			}
			if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
				((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}

	char calculate_digit;
	calculate_15_digit_imei((char*)(LPCTSTR)m_csInputIMEI2.Left(14),calculate_digit);
	
	if(calculate_digit!=m_csInputIMEI2.Right(1))	
	{
		Display("Illegal IMEI2,The 15th IMEI Error Fail...",1);
		this->m_ctrInputIMEI2.SetSel(0,-1);
		return FALSE;
	}
	
	//lucky 20160121 SQL重号检查
	sql.Format("select * from %s_%s_ColorBox WHERE (IMEI1='%s' or IMEI2='%s' or IMEI3='%s' or IMEI4='%s')", \
		(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csInputIMEI2,m_csInputIMEI2,m_csInputIMEI2,m_csInputIMEI2);
	try
	{
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		
		((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			Display("This IMEI2 already exists...",1);
			return FALSE;
		}
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		Display("unknown error",1);
		return FALSE;
	}
	//lucky 20160121 end

	return TRUE;
}

BOOL CFullWriteView::CheckIMEI3()
{
	CString sql;
	if(m_csInputIMEI3.GetLength()!=15)
	{
		Display("IMEI3 Length Is Not 15 Fail...",1);
		this->m_ctrInputIMEI3.SetSel(0,-1);
		return FALSE;
	}

	if(m_csInputIMEI1==m_csInputIMEI3)
	{
		Display("IMEI1 and IMEI3 cannot be the same Fail...",1);
		this->m_ctrInputIMEI3.SetSel(0,-1);
		return FALSE;
	}

	if(m_csInputIMEI2==m_csInputIMEI3)
	{
		Display("IMEI2 and IMEI3 cannot be the same Fail...",1);
		this->m_ctrInputIMEI3.SetSel(0,-1);
		return FALSE;
	}
	
	if (m_iIMEIRangeType==0)
	{
		if(m_csInputIMEI3.Left(14)>this->m_imei3_end || m_csInputIMEI3.Left(14)<this->m_imei3_start)
		{
			Display("IMEI2 Out Of Range...",1);
			this->m_ctrInputIMEI3.SetSel(0,-1);
			return FALSE;	
		}
	}
	else if(m_iIMEIRangeType==1)
	{
		_variant_t var;
		CString sql;
		
		sql.Format("select * from %s_%s_IMEIRange WHERE IMEI3='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csInputIMEI3);
		
		try
		{
			if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
				((CFullWriteApp *)AfxGetApp())->m_pRst->Close();

			((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			
			if(((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				Display("IMEI3 Is Not Exist In The Database...",1);
				return FALSE;
			}
			if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
				((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}

	char calculate_digit;
	calculate_15_digit_imei((char*)(LPCTSTR)m_csInputIMEI3.Left(14),calculate_digit);
	
	if(calculate_digit!=m_csInputIMEI3.Right(1))
	{
		Display("Illegal IMEI3,The 15th IMEI Error Fail...",1);
		this->m_ctrInputIMEI3.SetSel(0,-1);
		return FALSE;
	}

	//lucky 20160121 SQL重号检查
	sql.Format("select * from %s_%s_ColorBox WHERE (IMEI1='%s' or IMEI2='%s' or IMEI3='%s' or IMEI4='%s')", \
		(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csInputIMEI3,m_csInputIMEI3,m_csInputIMEI3,m_csInputIMEI3);
	try
	{
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		
		((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			Display("This IMEI3 already exists...",1);
			return FALSE;
		}
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		Display("unknown error",1);
		return FALSE;
	}
	//lucky 20160121 end 
	
	return TRUE;
}


BOOL CFullWriteView::CheckIMEI4()
{
	CString sql;

	if(m_csInputIMEI4.GetLength()!=15)
	{
		Display("IMEI4 Length Is Not 15 Fail...",1);
		this->m_ctrInputIMEI4.SetSel(0,-1);
		return FALSE;
	}
	
	if (m_iIMEIRangeType==0)
	{
		if(m_csInputIMEI4.Left(14)>this->m_imei4_end || m_csInputIMEI4.Left(14)<this->m_imei4_start)
		{
			Display("IMEI4 Out Of Range...",1);
			this->m_ctrInputIMEI4.SetSel(0,-1);
			return FALSE;
		}
	}
	else if(m_iIMEIRangeType==1)
	{
		_variant_t var;
		CString sql;
		
		sql.Format("select * from %s_%s_IMEIRange WHERE IMEI4='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csInputIMEI4);
		
		try
		{
			if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
				((CFullWriteApp *)AfxGetApp())->m_pRst->Close();

			((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			
			if(((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				Display("IMEI4 Is Not Exist In The Database...",1);
				return FALSE;
			}
			if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
				((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}
	
	char calculate_digit;
	calculate_15_digit_imei((char*)(LPCTSTR)m_csInputIMEI4.Left(14),calculate_digit);
	
	if(calculate_digit!=m_csInputIMEI4.Right(1))	
	{
		Display("Illegal IMEI4,The 15th IMEI Error Fail...",1);
		this->m_ctrInputIMEI4.SetSel(0,-1);
		return FALSE;
	}

	//lucky 20160121 SQL重号检查
	sql.Format("select * from %s_%s_ColorBox WHERE (IMEI1='%s' or IMEI2='%s' or IMEI3='%s' or IMEI4='%s')", \
		(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csInputIMEI4,m_csInputIMEI4,m_csInputIMEI4,m_csInputIMEI4);
	try
	{
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		
		((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			Display("This IMEI4 already exists...",1);
			return FALSE;
		}
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		Display("unknown error",1);
		return FALSE;
	}
	//lucky 20160121 end

	return TRUE;
}


BOOL CFullWriteView::CheckPSNLength()
{
	//20150801 GLORY 
#ifndef _DEBUG
	if(m_csInputPSN.GetLength()!=this->m_iPSNLength)
	{
		Display("PSN length error...",1);
		this->m_ctrInputPSN.SetSel(0,-1);
		return FALSE;
	}
#endif
	//end
	return TRUE;
}


BOOL CFullWriteView::CheckPSNStatic()
{
	//20150801 GLORY 
#ifndef _DEBUG
	if(m_csPSNCheckBit.Right(2)=="\r\n")
	{		
		m_csPSNCheckBit.Replace("\r\n","");
	}
	
	if(m_csPSNCheckBit.GetLength() == 0)
	{
		Display("PSN number of fixed-bit checksum string is empty...",1);
		this->m_ctrInputPSN.SetSel(0,-1);
		return FALSE;
	}

	if(m_iCheckPSN)
	{
		if(strcmp((LPSTR)(LPCTSTR)m_csInputPSN.Left(m_csPSNCheckBit.GetLength()), (LPSTR)(LPCTSTR)m_csPSNCheckBit))
		{
			Display("PSN number constant bit error...",1);
			this->m_ctrInputPSN.SetSel(0,-1);
			return FALSE;
		}
		else
		{
			Display("PSN number constant bit success...",0);
		}
	}
#endif
	//end
	return TRUE; 
}


void CFullWriteView::OnSetMyFocus(WPARAM wParam, LPARAM lParam)
{
	CEdit* a;
	a=(CEdit*)wParam;
	a->SetFocus();
}


void CFullWriteView::CleanUI()
{
	this->m_csInputIMEI1.Empty();
	this->m_csInputIMEI2.Empty();
	this->m_csInputIMEI3.Empty();
	this->m_csInputIMEI4.Empty();
	this->m_csInputPSN.Empty();
	SendMessage(WM_UPDATEDATA, FALSE, FALSE);
	SendMessage(WM_SETMYFOCUS,(WPARAM)(&this->m_ctrInputIMEI1),FALSE);
}


void CFullWriteView::SetInputCtrEnableWindow(BOOL flag)
{
	switch(m_iIMEIType) 
	{
	case 0:
		this->m_ctrInputIMEI1.EnableWindow(flag);
		break;
	case 1:
		this->m_ctrInputIMEI1.EnableWindow(flag);
		this->m_ctrInputIMEI2.EnableWindow(flag);
		break;
	case 2:
		this->m_ctrInputIMEI1.EnableWindow(flag);
		this->m_ctrInputIMEI2.EnableWindow(flag);
		this->m_ctrInputIMEI3.EnableWindow(flag);
		break;
	case 3:
		this->m_ctrInputIMEI1.EnableWindow(flag);
		this->m_ctrInputIMEI2.EnableWindow(flag);
		this->m_ctrInputIMEI3.EnableWindow(flag);
		this->m_ctrInputIMEI4.EnableWindow(flag);
		break;
	default:
		break;
	}

 	if (flag = TRUE)
	{
		//如果是扫描IMEI1，那么重新设置控件
		if(this->m_Config.m_iIsScanMainImei==1)
		{
			this->m_ctrInputIMEI1.EnableWindow(TRUE);
			this->m_ctrInputIMEI2.EnableWindow(FALSE);
			this->m_ctrInputIMEI3.EnableWindow(FALSE);
			this->m_ctrInputIMEI4.EnableWindow(FALSE);
		}
	}

 	if(this->m_iScanPSN)
 		this->m_ctrInputPSN.EnableWindow(flag);
}


bool CFullWriteView::FPCheckVersion()
{
	m_MetaappResult= METAAPP_GetTargetVerInfo( this->m_nMetaHandle, 5000, &p_verinfo);
	if(m_MetaappResult != METAAPP_SUCCESS)
	{
		return FALSE;
	}
	else
	{
		if(strcmp(p_verinfo.SW_VER,(LPSTR)(LPCTSTR)this->m_csVersion))
		{
			return FALSE;
		}
		else
		{
			return TRUE;
		}
	}

	return TRUE;
}


bool CFullWriteView::Load_Current_Product_Count()
{
	CString temp,states;
	_variant_t var;
	CString sql;

	sql.Format("select count(*) as COUNT from %s_%s_ColorBox WHERE Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder);
	
	try
	{ 
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			this->m_csCurrentCount= temp;
		}
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}


void CFullWriteView::UpdateCount(CString strCount)
{
	CString temp;
	temp="Product Number:"+strCount;
	this->m_cCurrentCount.SetWindowText(temp);
	SendMessage(WM_UPDATEDATA, FALSE, FALSE);
	//UpdateData(FALSE);
}

  

BOOL CFullWriteView::GetSetting()
{
	CString temp;
	_variant_t var;
	CString sql;
	int itemp;

	try
	{
		sql.Format("select * from SettingList where Enable=1 and ProductName='%s' and OrderName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder);
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("Platform");
			this->m_iPlatform=var.intVal;

 			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("ScanPSN");
 			this->m_iScanPSN=var.intVal;
 
 			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("PSNLength");
 			this->m_iPSNLength=var.intVal;

 			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("CheckPSN");
 			this->m_iCheckPSN=var.intVal;

			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("PSNCheckBit");
			temp=VariantToCString(var);
 			this->m_csPSNCheckBit = temp;

			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("BTFT");
			this->m_iBTFT=var.intVal;

 			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("WritePSNToPhone");
			this->m_iWritePSNToPhone=var.intVal;

			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("ResetFactory");
			this->m_iResetFactory=var.intVal;

			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("CheckVersion");
			this->m_iCheckVersion=var.intVal;

			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("CheckBoardVersion");
			this->m_iCheckBoardVersion=var.intVal;

			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("VersionCode");
			temp=VariantToCString(var);
			this->m_csVersion = temp;

			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("BoardVersionCode");
			temp=VariantToCString(var);
			this->m_csBoardVersion = temp;
		}
		else
		{
			return FALSE;
		}
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	return TRUE;
}


void CFullWriteView::OnScanMainImei() 
{
	CPassword dlg;
	dlg.ilevel = 1; //需超级权限验证
	if(dlg.DoModal()!=IDOK)
		return;
	
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_MAIN_IMEI, MF_BYCOMMAND | MF_CHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_ALL_IMEI, MF_BYCOMMAND | MF_UNCHECKED ); 
	this->m_Config.m_iIsScanMainImei=1;
	this->m_Config.SaveConfig();
	SetInputCtrEnableWindow(TRUE);
}

void CFullWriteView::OnScanALLImei()
{
	CPassword dlg;
	dlg.ilevel = 1; //需超级权限验证
	if(dlg.DoModal()!=IDOK)
		return;

	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_MAIN_IMEI, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_ALL_IMEI, MF_BYCOMMAND | MF_CHECKED ); 
	this->m_Config.m_iIsScanMainImei=0;
	this->m_Config.SaveConfig();
	SetInputCtrEnableWindow(TRUE);
}

BOOL CFullWriteView::GetOtherIMEI()
{
	_variant_t var;
	CString sql;

	try
	{
		sql.Format("select * from %s_%s_IMEIRange where IMEI1='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,m_csInputIMEI1);
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("IMEI2");
			this->m_csInputIMEI2 = VariantToCString(var);

			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("IMEI3");
			this->m_csInputIMEI3 = VariantToCString(var);

			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("IMEI4");
			this->m_csInputIMEI4 = VariantToCString(var);
		}
		else
		{
			return FALSE;
		}
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	UpdateData(FALSE);

	return TRUE;
}


bool CFullWriteView::SpWriteBarcode()
{
	char strBarcode_W [ 64 + 1 ];

	memset(strBarcode_W, 0, sizeof(strBarcode_W));

	for(int i=0;i<this->m_csPcbaSN.GetLength();i++)
	{
		strBarcode_W[i] = this->m_csPcbaSN.GetAt(i);
	}

	for (int j=0;j<this->m_csWriteSN.GetLength();j++)
	{
		strBarcode_W[j] = this->m_csWriteSN.GetAt(j);
	}
	
	m_MetaappResult= METAAPP_writeBarcodetoNVRAM( this->m_nMetaHandle, strBarcode_W, 5000 );

	if(m_MetaappResult != METAAPP_SUCCESS)
	{
		return FALSE;
	}

	return TRUE;
}


int CFullWriteView::ConnectWithPreloader()
{
	CString sInfo;
    this->Display("SmartPhoneSN::ConnectWithPreloader(): Start to get dynamic preloader comport...", 3);

    SP_COM_FILTER_LIST_S sCOMFilter;
    SP_COM_PROPERTY_S sCOMProperty;   
    memset(&sCOMFilter, 0, sizeof(SP_COM_FILTER_LIST_S));
    memset(&sCOMProperty, 0, sizeof(SP_COM_PROPERTY_S));

    int iRet = 0;
    unsigned int eType;   //0:BoorROMUSB,1:PreloaderUSB
    char *ppFilter[2];    

    char *asPreloaderPortFilter = g_sMetaComm.sPortFilter.strPreloaderFilter;
    char *asBROMPortFilter = g_sMetaComm.sPortFilter.strBromFilter;

    ppFilter[0]=asPreloaderPortFilter;
	ppFilter[1]=asBROMPortFilter;
   
    sCOMFilter.m_uCount=2;
    sCOMFilter.m_ppFilterID=ppFilter;
	sCOMFilter.m_eType=SP_WHITE_LIST;

    if (g_sMetaComm.bUsbEnable == false)
    {
        m_stModeArg.m_uPortNumber = g_sMetaComm.iCOMPort;
        eType = PreloaderUSB;
    } 
    else
    {     
        int iTimeout = m_stModeArg.m_uTimeout / 1000;  //timeout unit: s, but m_stModeArg.m_uTimeout unit is ms
        iRet = SP_GetIncrementCOMPortWithFilter(&sCOMFilter, &sCOMProperty, NULL, _TRUE, m_pMetaStopFlag, 30);              
        if(0 == iRet)
        {      
            m_bStopBeforeUSBInsert = false;
            switch(sCOMProperty.m_iFilterIndex)
            {
            case 0:
                eType = PreloaderUSB;
                break;

            case 1:
                eType = BootROMUSB;
                break;

            default:
                //MessageBox (NULL, "Filter index error!", "fail", MB_OK);
                return SPMETA_DLL::META_FAILED;
            }
            
            m_stModeArg.m_uPortNumber = sCOMProperty.m_uNumber;
        }
        else
        {
            if (iRet == SP_S_TIMEOUT)
            {
                this->Display("SmartPhoneSN::ConnectWithPreloader(): Get dynamic preloader comport timeout...");                                
            }

            return iRet;
        }
    }
   
    Sleep (0.01);
    if(BootROMUSB == eType)
    {
        sInfo.Format("SmartPhoneSN::ConnectWithPreloader(): Get preloader comport successfully, comport = %d", m_stModeArg.m_uPortNumber);
		this->Display(sInfo);
        iRet = SP_BootROM_BootMode(&m_stModeArg);       
        if (iRet == 0)
        {
            this->Display("SmartPhoneSN::SP_BootROM_BootMode(): Preloader boot meta mode success!!", 3);
        }   
        else
        {
            sInfo.Format("SmartPhoneSN::SP_BootROM_BootMode(): Preloader boot meta mode Fail, Err = %d", iRet);
			this->Display(sInfo);
        }

        m_bStopBeforeUSBInsert = false;
    }
    else if(PreloaderUSB == eType)
    {
        sInfo.Format("SmartPhoneSN::ConnectWithPreloader(): Get preloader comport successfully, comport = %d", m_stModeArg.m_uPortNumber);
		this->Display(sInfo);
        iRet = SP_Preloader_BootMode(&m_stModeArg);
        if (iRet == 0)
        {
            this->Display("SmartPhoneSN::SP_Preloader_BootMode(): Preloader boot meta mode success!!");
        }   
        else
        {
            sInfo.Format("SmartPhoneSN::SP_Preloader_BootMode(): Preloader boot meta mode Fail, Err = %d", iRet);
			this->Display(sInfo);
        }

        m_bStopBeforeUSBInsert = false;
    }
    
   
    return iRet;
}

int CFullWriteView::ConnectWithKernelPort_Ex(SP_METAMODE_e spMetaMode)
{
	CString sInfo;
    int iRet = 0;
    unsigned short kernelComport = 0; 
    char *pFuncName = NULL;
    
    SPMETA_DLL::META_ConnectByUSB_Req     spUSBConnReq;
    SPMETA_DLL::META_ConnectByUSB_Report  spUSBConnReport;   
    memset(&spUSBConnReq, 0, sizeof(spUSBConnReq));
    memset(&spUSBConnReport, 0, sizeof(spUSBConnReport));
    
    SP_COM_FILTER_LIST_S sCOMFilter;
    SP_COM_PROPERTY_S sCOMProperty;   
    memset(&sCOMFilter, 0, sizeof(SP_COM_FILTER_LIST_S));
    memset(&sCOMProperty, 0, sizeof(SP_COM_PROPERTY_S));
    
    const UINT filterNums = 2;
    char *ppFilter[filterNums];
    for (int i = 0; i < filterNums; i++)
    {
        ppFilter[i] = NULL;
    }
    
    // Black kernel comport filter list
    ppFilter[0] = g_sMetaComm.sPortFilter.strBromFilter;
    ppFilter[1] = g_sMetaComm.sPortFilter.strKernelFilter;
    
    sCOMFilter.m_uCount = filterNums;
    sCOMFilter.m_ppFilterID = ppFilter;
    sCOMFilter.m_eType = SP_BLACK_LIST;
    
    if (g_sMetaComm.bUsbEnable)
    {     
        //phase out SP_META_GetDynamicUSBComPort_r API, cause it have probabilistic can`t fetch kernel comport issue  
        int iTimeout = m_tMetaReq_Ex.ms_connect_timeout / 1000;  //timeout unit: s, but m_tMetaReq_Ex.ms_connect_timeout unit is ms
        iRet = SP_GetIncrementCOMPortWithFilter(&sCOMFilter, &sCOMProperty, &GUID_PORT_CLASS_USB2SER, _FALSE, m_pMetaStopFlag, 100); 
        if(0 == iRet)
        { 
            kernelComport = sCOMProperty.m_uNumber;
            m_iKernelComport = kernelComport;
            if (spMetaMode == SP_AP_META)
            {  
                spUSBConnReq.com_port = kernelComport;
                spUSBConnReq.ms_connect_timeout = m_tMetaReq_Ex.ms_connect_timeout;
                iRet = TryToOpenSPKernelComport(kernelComport);
                if(iRet == OK)
                {
                    sInfo.Format("SmartPhoneSN::SP_META_ConnectInMetaModeByUSB_r(): Start enter AP meta mode, KernelComPort = %d", kernelComport);
					this->Display(sInfo);
                    iRet = SPMETA_DLL::SP_META_ConnectInMetaModeByUSB_r (this->m_ApExe.iMetaAP_handle, &spUSBConnReq, m_pMetaStopFlag, &spUSBConnReport);
					//if(g_sMetaComm.IgnoreApdatabase)
					if(1)
					{

						if (iRet == META_SUCCESS || iRet == SPMETA_DLL::META_MAUI_DB_INCONSISTENT)
						{
							iRet = META_SUCCESS;                
							this->Display("SmartPhoneSN::SP_META_ConnectInMetaModeByUSB_r(): Enter meta successfully!!");
						}//end if (iRet == META_SUCCESS || iRet == SPMETA_DLL::META_MAUI_DB_INCONSISTENT)
					}
					else
					{
						if (iRet == META_SUCCESS)
						{               
							this->Display("SmartPhoneSN::SP_META_ConnectInMetaModeByUSB_r(): Enter meta successfully!!");
						}//end if (iRet == META_SUCCESS)
						else
						{
							pFuncName = "SP_META_ConnectInMetaModeByUSB_r()";
							sInfo.Format("SmartPhoneSN::SP_META_ConnectInMetaModeByUSB_r(): Enter meta fail, MetaResult = %s", ResultToString_SP(iRet));                       
							this->Display(sInfo);
							goto Err;
						}
					}
                }//if(iRet==OK)
                else
                {
                    iRet = 1;
                    pFuncName = "TryToOpenSPKernelComport()";
                    this->Display("SmartPhoneSN::TryToOpenSPKernelComport(): Try to open kernel comport fail!!");                       
                    goto Err;
                }
            }//end if (spMetaMode == SP_AP_META)
            else
            {
                //TO DO
                iRet = META_FAILED;
            }
        }
        else
        {
            pFuncName = "SP_GetIncrementCOMPortWithFilter()";
            sInfo.Format("SmartPhoneSN::ConnectWithKernelPort_Ex(): SP_GetIncrementCOMPortWithFilter get kernel comport fail, iRet = %d", iRet);
			this->Display(sInfo);
            return iRet;
        }
    }//end if(g_sMetaComm.bUsbEnable)
    else
    {
        kernelComport = g_sMetaComm.iCOMPort;
        m_iKernelComport = kernelComport;

        SPMETA_DLL::WM_META_ConnectInMETA_Req uartMETA_Req;
        SPMETA_DLL::WM_META_ConnectInMETA_Report uartMETA_Report;
        memset(&uartMETA_Req, 0 ,sizeof(SPMETA_DLL::WM_META_ConnectInMETA_Req));
        memset(&uartMETA_Report, 0 ,sizeof(SPMETA_DLL::WM_META_ConnectInMETA_Report));

        uartMETA_Req.com_port = m_iKernelComport;
        uartMETA_Req.baudrate[0] = SPMETA_DLL::META_BAUD921600;
        uartMETA_Req.baudrate[1] = SPMETA_DLL::META_BAUD_END;
        uartMETA_Req.flowctrl    = SPMETA_DLL::META_NO_FLOWCTRL;//META_SW_FLOWCTRL;
        uartMETA_Req.ms_connect_timeout = m_tMetaReq_Ex.ms_connect_timeout;

        
        sInfo.Format("SmartPhoneSN::SP_META_ConnectInMetaMode_r(): Start enter AP meta mode, KernelComPort = %d", kernelComport);
		this->Display(sInfo);
        iRet = SPMETA_DLL::SP_META_ConnectInMetaMode_r(m_ApExe.iMetaAP_handle, &uartMETA_Req, m_pMetaStopFlag, &uartMETA_Report);
        if (iRet == META_SUCCESS)
        {                          
            this->Display("SmartPhoneSN::SP_META_ConnectInMetaMode_r(): Enter meta successfully!!");
        }//end if (iRet == META_SUCCESS)
        else
        {
            pFuncName = "SmartPhoneSN::SP_META_ConnectInMetaMode_r()";
            sInfo.Format("SmartPhoneSN::SP_META_ConnectInMetaMode_r(): enter meta fail, MetaResult = %s", ResultToString_SP(iRet));
			this->Display(sInfo);
            goto Err;
        } 
    }
	
	return iRet;

Err:
    sInfo.Format("SmartPhoneSN::%s: MetaResult = %s", pFuncName, ResultToString_SP(iRet));
	this->Display(sInfo);
    return iRet;
}

SPMETA_DLL::META_RESULT CFullWriteView::EnterAPMetaMode()
{
	CString strmsg;
    this->Display("SmartPhoneSN::EnterAPMetaMode() : Enter ap meta start...", 3);

    SPMETA_DLL::META_RESULT spMetaResult = SPMETA_DLL::META_SUCCESS;
    int bootResult = 0;    
    this->Display("Start searching preloader com port and handshake...", 3);    	

    bootResult = ConnectWithPreloader();
    if (bootResult != 0)
    {
        this->Display("Searching preloader com port and handshake Fail!!", 3);        
        spMetaResult = (SPMETA_DLL::META_RESULT)bootResult;
        return spMetaResult;
    }
    else
    {
        this->Display("Searching preloader com port and handshake OK!!", 3);        
        this->Display("Start searching kernel com port and handshake...", 3);                
        bootResult = ConnectWithKernelPort_Ex(SP_AP_META);        
        if (bootResult == 0)
        {
            this->Display("Searching kernel com port and handshake OK!!", 3);            
            m_eMetaMode = SP_AP_META;
            m_bTargetInMetaMode = true;
        }  
        else
        {
            this->Display("Searching kernel com port and handshake Fail!!", 3);            
            if (bootResult == SPMETA_DLL::META_MAUI_DB_INCONSISTENT)
            {
                m_eMetaMode = SP_AP_META;
                m_bTargetInMetaMode = true;
            } 
            else
            {
                m_eMetaMode = SP_NOTIN_META;
                m_bTargetInMetaMode = false;
            }            
        }
    }
    
    this->Display("SmartPhoneSN::EnterAPMetaMode() : Enter ap meta end...", 3);
    spMetaResult = (SPMETA_DLL::META_RESULT)bootResult;
    return spMetaResult;
}

bool CFullWriteView::QueryEncryptionSupport(int * MetaHandle )
{
	CString sInfo;
	SPMETA_DLL::CRYPTFS_QUERYSUPPORT_CNF cryptfs_Support_cnf;
	SPMETA_DLL::META_RESULT MetaResult;
	MetaResult = SPMETA_DLL::SP_META_ENCRYPTED_Support_r(*MetaHandle,60000, &cryptfs_Support_cnf);

	if((MetaResult == META_SUCCESS) && (cryptfs_Support_cnf.support == 1))
	{
		this->Display(" Do support Encryption!",3);
		return true;
	}
    else
    {
		sInfo.Format(" Do not support Encryption : MetaResult = %s!", ResultToString_SP(MetaResult));
		this->Display(sInfo.GetBuffer(sInfo.GetLength()), 3);
        return false;
    }	
	//return true;
}

int CFullWriteView::GetSPModemInfo_Ex()
{
	CString sInfo;
    int iRet = 0;
    char *pFuncName = NULL;
//	bool bExternMDDownload = (g_sMetaComm.sWriteOption.bWriteBarcode)? g_sMetaComm.sBarcodeOption.bExtMdDl:false;
	
    //Init parameters for without world phone feature
    m_sMdInfo.number_of_md = 1;
    m_sMdInfo.active_md_idx = 1;
    m_sMdInfo.number_of_mdSwImg = 1;
    m_sMdInfo.activeMdTypeIdx = 0;
    m_bDSDAProject = false;

    
    SPMETA_DLL::MODEM_QUERY_INFO_REQ pReq;
    SPMETA_DLL::MODEM_QUERY_INFO_CNF pCnf;
    memset(&pReq, 0, sizeof(SPMETA_DLL::MODEM_QUERY_INFO_REQ));
    memset(&pCnf, 0, sizeof(SPMETA_DLL::MODEM_QUERY_INFO_CNF));

    if(SPMETA_DLL::SP_META_QueryIfFunctionSupportedByTarget_r(m_ApExe.iMetaAP_handle, 5000, "SP_META_MODEM_Query_Info_r") == SPMETA_DLL::META_SUCCESS)
    {       
        iRet = SPMETA_DLL::SP_META_MODEM_Query_Info_r(m_ApExe.iMetaAP_handle, 2000, &pReq, &pCnf); 
        if (iRet != META_SUCCESS)
        {
            sInfo.Format("SmartPhoneSN::SP_META_MODEM_Query_Info_r(): Get modem info from target Fail, MetaResult = %s!", ResultToString_SP(iRet));
			this->Display(sInfo.GetBuffer(sInfo.GetLength()), 3);
            return iRet;
        }
        else
        {
            sInfo.Format("SmartPhoneSN::SP_META_MODEM_Query_Info_r(): Get modem info from target successfully! md_numb = %d, active_md_idx = %d!",
                pCnf.modem_number, pCnf.modem_id);
			this->Display(sInfo.GetBuffer(sInfo.GetLength()), 3);
            m_sMdInfo.number_of_md = pCnf.modem_number;
            m_sMdInfo.active_md_idx = pCnf.modem_id;
            m_bWithoutMD = (m_sMdInfo.number_of_md == 0) ? true : false;
            m_bDualModem = (m_sMdInfo.number_of_md == 2) ? true : false;
        }
    }
    
    
    
    SPMETA_DLL::MODEM_CAPABILITY_LIST_REQ pCapabilitiesReq;
    SPMETA_DLL::MODEM_CAPABILITY_LIST_CNF pCapabilitiesCnf;
    memset(&pCapabilitiesReq, 0, sizeof(pCapabilitiesReq));
    memset(&pCapabilitiesCnf, 0, sizeof(pCapabilitiesCnf));
    
    if(SPMETA_DLL::SP_META_QueryIfFunctionSupportedByTarget_r(m_ApExe.iMetaAP_handle, 5000, "SP_META_MODEM_Capability_r") == SPMETA_DLL::META_SUCCESS)
    {       
        iRet = SPMETA_DLL::SP_META_MODEM_Capability_r(m_ApExe.iMetaAP_handle, 2000, &pCapabilitiesReq, &pCapabilitiesCnf); 
        if (iRet != META_SUCCESS)
        {
            m_sMdInfo.multi_md_capability_support = 0;
            this->Display("SmartPhoneSN::SP_META_MODEM_Capability_r(): Get modem capability from target Fail!!",3);
            
            m_tMetaReq_Ex.protocol = 1;
            m_tMetaReq_Ex.channel_type = 1;
            iRet = META_SUCCESS;
        }
        else
        {                  
            m_sMdInfo.multi_md_capability_support = 1;
            memcpy(&m_SpMdCapList, &pCapabilitiesCnf, sizeof(pCapabilitiesCnf));
            m_tMetaReq_Ex.protocol = m_SpMdCapList.modem_cap[m_sMdInfo.active_md_idx-1].md_service;
            m_tMetaReq_Ex.channel_type =  m_SpMdCapList.modem_cap[m_sMdInfo.active_md_idx-1].ch_type;
            
                       
            //for MT6595 DSDA project
            if (m_sMdInfo.number_of_md >= 2)
            {
                m_bDSDAProject = true;
                int mdIndex = 0;
                for (int i = 0; i < MAX_MD_CHANNEL_NUM; i++)
                {
                    sInfo.Format("SmartPhoneSN: Modem capability, protocol = %d, channel_type = %d!",
                        m_SpMdCapList.modem_cap[i].md_service, m_SpMdCapList.modem_cap[i].ch_type);
					this->Display(sInfo.GetBuffer(sInfo.GetLength()), 3);
                    if (m_SpMdCapList.modem_cap[i].md_service > 0 )
                    {
                        m_iMDChannelIndex[mdIndex] = i;
                        mdIndex += 1;
                    }

					if (m_sMdInfo.number_of_md == 2 && m_SpMdCapList.modem_cap[i].md_service ==3)
					{
						m_bDSDAProject = false;
					}

                }
            }      
        }
        sInfo.Format("SmartPhoneSN::SP_META_MODEM_Capability_r(): Get modem capability, protocol = %d, channel_type = %d!",
            m_tMetaReq_Ex.protocol, m_tMetaReq_Ex.channel_type);
		this->Display(sInfo.GetBuffer(sInfo.GetLength()), 3);
    }
    
       
    SPMETA_DLL::MODEM_GET_CURRENTMODEMTYPE_REQ pCurMDTypeReq;
    SPMETA_DLL::MODEM_GET_CURENTMODEMTYPE_CNF pCurMDTypeCnf;
    memset(&pCurMDTypeReq, 0, sizeof(pCurMDTypeReq));
    memset(&pCurMDTypeCnf, 0, sizeof(pCurMDTypeCnf));
    
    if(SPMETA_DLL::SP_META_QueryIfFunctionSupportedByTarget_r(m_ApExe.iMetaAP_handle, 5000, "SP_META_MODEM_Get_CurrentModemType_r") == SPMETA_DLL::META_SUCCESS)
    {       
        iRet = SPMETA_DLL::SP_META_MODEM_Get_CurrentModemType_r(m_ApExe.iMetaAP_handle, 2000, &pCurMDTypeReq, &pCurMDTypeCnf);
        if (iRet != META_SUCCESS)
        {
            iRet = META_SUCCESS;
            this->Display("SmartPhoneSN::SP_META_MODEM_Get_CurrentModemType_r(): Get modem type from target Fail, mean that handset not support worldphone feature!!", 3);
        }
        else
        {
            m_sMdInfo.current_mdtype = pCurMDTypeCnf.current_modem_type;
            sInfo.Format("SmartPhoneSN::SP_META_MODEM_Get_CurrentModemType_r(): Get MD Image info from target success, MdType = %d.", m_sMdInfo.current_mdtype);
			this->Display(sInfo.GetBuffer(sInfo.GetLength()), 3);
        }
    }
    
    
    SPMETA_DLL::MODEM_QUERY_MDIMGTYPE_REQ pMDImgTypeReq;
    SPMETA_DLL::MODEM_QUERY_MDIMGTYPE_CNF pMDImgTypeCnf;
    memset(&pMDImgTypeReq, 0, sizeof(pMDImgTypeReq));
    memset(&pMDImgTypeCnf, 0, sizeof(pMDImgTypeCnf));
    
    if(SPMETA_DLL::SP_META_QueryIfFunctionSupportedByTarget_r(m_ApExe.iMetaAP_handle, 5000, "SP_META_MODEM_Query_MDIMGType_r") == SPMETA_DLL::META_SUCCESS)
    {       
        iRet = SPMETA_DLL::SP_META_MODEM_Query_MDIMGType_r(m_ApExe.iMetaAP_handle, 2000, &pMDImgTypeReq, &pMDImgTypeCnf);
        if (iRet != META_SUCCESS)
        {
            iRet = META_SUCCESS;
            this->Display("SmartPhoneSN::SP_META_MODEM_Query_MDIMGType_r(): Get MD Image info from target fail, mean that handset not support worldphone feature!!", 3);
        }
        else
        {
            memcpy(m_sMdInfo.mdimg_type, pMDImgTypeCnf.mdimg_type, 16);
            bool bAllZero = true;
            m_bWorldPhone = true;
            m_sMdInfo.number_of_mdSwImg = 0;
            //Get current active mdtype index
            for(int i = 0; i < 16; i++)
            {
                if(m_sMdInfo.mdimg_type[i] !=0 )
                {
                    m_sMdInfo.number_of_mdSwImg += 1;                                    
                    bAllZero = false;
                }
                
                if(m_sMdInfo.current_mdtype != 0 && m_sMdInfo.mdimg_type[i] == m_sMdInfo.current_mdtype)
                {
                    m_sMdInfo.activeMdTypeIdx = i;
                }
            }
            
            //For before MT6577(include MT6577)old chip project
            //Old chip project call this api will return success, but mdimg_type array data all zero
            if (bAllZero)
            {
                m_sMdInfo.number_of_mdSwImg = 1;
                m_sMdInfo.activeMdTypeIdx = 0;
                m_bWorldPhone = false;
                this->Display("SmartPhoneSN::SP_META_MODEM_Query_MDIMGType_r(): Get MD Image info from target success but all zero, mean that handset not support worldphone feature!!", 3);
            }
            else
            {
                sInfo.Format("SmartPhoneSN::SP_META_MODEM_Query_MDIMGType_r(): Get MD Image info from target success, activeMdTypeIdx = %d, mean that handset support worldphone feature!!", m_sMdInfo.activeMdTypeIdx);
				this->Display(sInfo.GetBuffer(sInfo.GetLength()), 3);
            }
            
            if (m_sMdInfo.number_of_md >= 2)
            {
                //extern modem have one SwImg
                m_sMdInfo.number_of_mdSwImg += (m_sMdInfo.number_of_md - 1);
            }
        }
    }  
	SPMETA_DLL::MODEM_QUERY_DOWNLOAD_STATUS_REQ pDLReq;
	SPMETA_DLL::MODEM_QUERY_DOWNLOAD_STATUS_CNF pDLCnf;
	   
    memset(&pDLReq, 0, sizeof(SPMETA_DLL::MODEM_QUERY_DOWNLOAD_STATUS_REQ));
    memset(&pDLCnf, 0, sizeof(SPMETA_DLL::MODEM_QUERY_DOWNLOAD_STATUS_CNF));
	   
	   //if(SPMETA_DLL:P_META_QueryIfFunctionSupportedByTarget_r(m_hSPMetaHandle, 5000, "SP_META_MODEM_Query_Download_Status_r ") == SPMETA_DLL::META_SUCCESS)
    if(m_bDSDAProject)
    {	   
	   iRet = SPMETA_DLL::SP_META_MODEM_Query_Download_Status_r (m_ApExe.iMetaAP_handle, 80000, &pDLReq, &pDLCnf);
	   if (iRet != META_SUCCESS)
	   {
		   sInfo.Format("SmartPhoneSN::SP_META_MODEM_Query_Download_Status_r(): Query extern modem download process fail, MetaResult = %s", ResultToString_SP(iRet));
		   this->Display(sInfo.GetBuffer(sInfo.GetLength()), 3);
		   iRet = 0;
	   }
    }

	return iRet;
}

META_RESULT CFullWriteView::LoadModemDatabase(int MDindex)
{
	return META_SUCCESS;
	CString sInfo;
    unsigned long db = 0;
    META_RESULT meta_result = META_SUCCESS;
    
    bool bInitMD1Done = true;
    
    bool *pbInitDBDone = NULL;
    char *pStrMDDbpath = NULL;
    switch (MDindex)
    {
    case 0:
		{
			if(strlen(g_sMetaComm.sDBFileOption.strMD1Dbpath) <= 0)
				strncpy(g_sMetaComm.sDBFileOption.strMD1Dbpath,(LPCTSTR)this->m_csDBPath,strlen(this->m_csDBPath)+1);
            pbInitDBDone = &g_sMetaComm.sDBFileOption.bDBInitModem_1;
            pStrMDDbpath = g_sMetaComm.sDBFileOption.strMD1Dbpath;
		}
        break;
        
    case 1:
		{
			if(strlen(g_sMetaComm.sDBFileOption.strMD2Dbpath) <= 0)
				strncpy(g_sMetaComm.sDBFileOption.strMD2Dbpath,(LPCTSTR)this->m_csDBPath,strlen(this->m_csDBPath)+1);
			pbInitDBDone = &g_sMetaComm.sDBFileOption.bDBInitModem_2;
			pStrMDDbpath = g_sMetaComm.sDBFileOption.strMD2Dbpath;
		}
        break;
        
    default:
        sInfo.Format("SmartPhoneSN::LoadModemDatabase(): Incorrect MDIndex = %d!", MDindex);
        return META_INVALID_ARGUMENTS;
        break;
    }
    
    if (!pStrMDDbpath || strlen(pStrMDDbpath) == 0)
    {
        this->Display ("SmartPhoneSN::LoadModemDatabase(): Incorrect database file path!", 3);
        return META_INVALID_ARGUMENTS;
    }
    else
    {
        if((*pbInitDBDone) == false)
        {                             
            char *pFuncName = NULL;
            //if (g_sMetaComm.eTargetType == SMART_PHONE_DUALMODEM)
            if ((m_bDualModem == true && m_bWorldPhone == false) /*|| g_sMetaComm.eTargetType == SMART_PHONE_DUALMODEM*/)
            {
                meta_result = META_NVRAM_Init_Ex_r ( m_nMetaHandle, MDindex, pStrMDDbpath, &db);
                pFuncName = "META_NVRAM_Init_Ex_r";
            } 
            else
            {
                MDindex = m_sMdInfo.active_md_idx - 1;                 
                //For MT6595 DSDA project
                if (m_bDSDAProject)
                {
                    MDindex = m_iCurMDChanelIndex;
                    if (m_bInitExtMDdb)
                    {
                        m_sMdInfo.activeMdTypeIdx = 0;
                    }
                }

                meta_result = META_NVRAM_Init_Ex_Mdtype_r(m_nMetaHandle, MDindex, m_sMdInfo.activeMdTypeIdx, pStrMDDbpath, &db);
                pFuncName = "META_NVRAM_Init_Ex_Mdtype_r";
            }
            sInfo.Format("SmartPhoneSN::%s(): start to init MD[%d] database, DB path = \"%s\"...", 
                pFuncName, MDindex, pStrMDDbpath);
			this->Display(sInfo.GetBuffer(sInfo.GetLength()), 3);
           
        #ifdef _IGNORE_DB_INCONSISTENT_
            if (META_SUCCESS == meta_result || meta_result == META_MAUI_DB_INCONSISTENT)
            {
                *pbInitDBDone = true;				
                if (META_SUCCESS == meta_result)
                {
                    MTRACE (g_hEBOOT_DEBUG, "SmartPhoneSN::%s(): Init MD[%d] database successfully!", pFuncName, MDindex);
                } 
                else if(META_MAUI_DB_INCONSISTENT == meta_result)
                {
                    MTRACE (g_hEBOOT_DEBUG, "Warning: SmartPhoneSN::%s(): Current database not match handset, MetaResult = %s!", 
                        pFuncName, ResultToString(meta_result));
                }
                meta_result = META_SUCCESS;
            }
        #else
            if (META_SUCCESS == meta_result)
            {
                *pbInitDBDone = true;				
                sInfo.Format("SmartPhoneSN::%s(): Init MD[%d] database successfully!", pFuncName, MDindex);             
				this->Display(sInfo.GetBuffer(sInfo.GetLength()), 3);
            }
        #endif           
            else
            {
                *pbInitDBDone = false;
                sInfo.Format("SmartPhoneSN::%s(): Init MD[%d] database Fail, MetaResult = %s",
                    pFuncName, MDindex, ResultToString(meta_result)); 
				this->Display(sInfo.GetBuffer(sInfo.GetLength()), 3);
            }
            
        }
        else
        {
            //For MT6595 DSDA project
            if (m_bDSDAProject)
            {
                MDindex = m_iCurMDChanelIndex;
            }
            sInfo.Format("SmartPhoneSN::META_NVRAM_Init_r(): MD[%d] database already init done!",  MDindex);
			this->Display(sInfo.GetBuffer(sInfo.GetLength()), 3);
        }       
    }

    return meta_result;
}

META_RESULT CFullWriteView::EnterModemMetaToInitModemDB()
{  
	CString sInfo;
    META_RESULT MetaResult = META_SUCCESS;
    this->Display("SmartPhoneSN::ApSwithToModemMeta_Ex(): Switch to modem meta from AP meta start...", 3);
    MetaResult = APSwithToModemMeta_Ex();

    if (MetaResult == META_SUCCESS)
    {       
        m_eMetaMode = SP_MODEM_META;
        MetaResult = LoadModemDatabase(0);
    }
    else
    {
        sInfo.Format("SmartPhoneSN::EnterModemMetaToInitModemDB(): AP meta switch to modem meta cause error, MetaResult = %s",
            ResultToString(MetaResult));
		this->Display(sInfo.GetBuffer(sInfo.GetLength()), 3);
    }

    return MetaResult;
}

META_RESULT CFullWriteView::APSwithToModemMeta_Ex()
{
	CString sInfo;
    this->Display("SmartPhoneSN::META_ConnectWithMultiModeTarget_r():  Switch to Modem meta from AP meta by META_ConnectWithMultiModeTarget_r start...!", 3);
    int iRet = 0;
    iRet = SPMETA_DLL::SP_META_DisconnectInMetaMode_r(m_ApExe.iMetaAP_handle);
    if(iRet == META_SUCCESS)
    {	  
        m_tMetaReq_Ex.com_port = m_iKernelComport;
        iRet = META_ConnectWithMultiModeTarget_r(m_nMetaHandle, &m_tMetaReq_Ex,sizeof(m_tMetaReq_Ex),m_pMetaStopFlag,&m_tMetaConnReport_Ex);
        if(iRet != META_SUCCESS)
        {        
            m_eMetaMode = SP_AP2MD_FAIL;
            sInfo.Format("SmartPhoneSN::META_ConnectWithMultiModeTarget_r():  Switch to Modem meta from AP meta Fail, MetaResult = %s", ResultToString(iRet));
			this->Display(sInfo.GetBuffer(sInfo.GetLength()), 3);
        }
		else
		{           
            m_eMetaMode = SP_MODEM_META;
		    this->Display("SmartPhoneSN::META_ConnectWithMultiModeTarget_r():  Switch to Modem meta from AP meta successfully!", 3);
		}
    }	
    
    return (META_RESULT)iRet;
}

META_RESULT CFullWriteView::ModemSwithToAPMeta()
{
	CString sInfo;
    this->Display("SmartPhoneSN::ModemSwithToAPMeta(): Start switch to AP meta from Modem meta...");

    META_RESULT MetaResult = META_SUCCESS;
	
       
    MetaResult = META_DisconnectInMetaMode_r (m_nMetaHandle);        
    if (MetaResult != META_SUCCESS)
    {
        sInfo.Format("SmartPhoneSN::META_DisconnectInMetaMode_r(): Disconnect Modem meta mode Fail!, MetaResult = %s",  ResultToString(MetaResult));
		this->Display(sInfo);
    }
    else
    {       
        int BootStop = 0;
        int usb_port = 0;
        SPMETA_DLL::WM_META_ConnectInMETA_Req BootRequest; 
        SPMETA_DLL::WM_META_ConnectInMETA_Report BootReport;
        
        BootRequest.com_port = m_iKernelComport;
        BootRequest.baudrate[0] = SPMETA_DLL::META_BAUD115200;
        BootRequest.baudrate[1] = SPMETA_DLL::META_BAUD230400;
        BootRequest.baudrate[2] = SPMETA_DLL::META_BAUD460800;
        BootRequest.baudrate[3] = SPMETA_DLL::META_BAUD921600;
        BootRequest.baudrate[4] = SPMETA_DLL::META_BAUD57600;
        BootRequest.baudrate[5] = SPMETA_DLL::META_BAUD_END;
        BootRequest.flowctrl    = SPMETA_DLL::META_NO_FLOWCTRL;//META_SW_FLOWCTRL;
        BootRequest.ms_connect_timeout = m_tMetaReq_Ex.ms_connect_timeout;
              
        MetaResult = (META_RESULT)SPMETA_DLL::SP_META_ConnectInMetaMode_r(this->m_ApExe.iMetaAP_handle, &BootRequest, &BootStop, &BootReport); 
        if (META_SUCCESS != MetaResult)
        {
            m_eMetaMode = SP_MD2AP_FAIL;
            sInfo.Format("SmartPhoneSN::SP_META_ConnectInMetaMode_r(): Modem meta switch to AP meta Fail!, BootRequest.com_port = %d, MetaResult = %s", 
                BootRequest.com_port, ResultToString_SP(MetaResult));
			this->Display(sInfo);
        }  
		else
		{
			m_eMetaMode = SP_AP_META;
			this->Display("SmartPhoneSN::SP_META_ConnectInMetaMode_r(): switch to AP meta from Modem meta  successfully!");    		
		}
    }
    
    
    return MetaResult;
}

void CFullWriteView::SetupMetaModeParameters()
{
    this->Display("SmartPhoneSN::SetupMetaModeParameters() start...", 3);
	//For preloader handshake parameters
    memset (&m_stModeArg, 0x0, sizeof(SP_BOOT_ARG_S));
	//For new api parameters
	m_bUseNewConnectMauiMetaAPI = true;
    memset(&m_tMetaReq_Ex, 0, sizeof(m_tMetaReq_Ex));
    memset(&m_tMetaConnReport_Ex, 0, sizeof(m_tMetaConnReport_Ex));

    if (g_sMetaComm.iPre_Connect_Timeout < 10000)
    {
        g_sMetaComm.iPre_Connect_Timeout = 10000;
    }

    if (g_sMetaComm.iKernel_Connect_Timeout < 20000)
    {
        g_sMetaComm.iKernel_Connect_Timeout = 20000;
    }
	g_sMetaComm.bUsbEnable = true;
    m_iKernelComport = g_sMetaComm.iCOMPort;
		
    //Old parameters
    m_stModeArg.m_bbchip_type=SP_AUTO_DETECT_BBCHIP;
    m_stModeArg.m_ext_clock=SP_AUTO_DETECT_EXT_CLOCK;
    m_stModeArg.m_ms_boot_timeout=SP_BOOT_INFINITE;
    //m_stModeArg.m_max_start_cmd_retry_count = SP_DEFAULT_BROM_START_CMD_RETRY_COUNT;
    m_stModeArg.m_max_start_cmd_retry_count = 0;   
    //New parameters
    m_stModeArg.m_uTimeout = g_sMetaComm.iPre_Connect_Timeout;
    m_stModeArg.m_uRetryTime = 2000;
    m_stModeArg.m_uInterval = 10;
    m_stModeArg.m_uBaudrate = CBR_115200;
    m_stModeArg.m_pStopFlag  = &g_iMetaStopFlag;

    {
        m_stModeArg.m_auth_handle = NULL;
        m_stModeArg.m_scert_handle = NULL;
        m_stModeArg.m_cb_sla_challenge = NULL;
        m_stModeArg.m_cb_sla_challenge_arg = NULL;
        m_stModeArg.m_cb_sla_challenge_end = NULL;
        m_stModeArg.m_cb_sla_challenge_end_arg = NULL;
    }      
    m_stModeArg.m_bIsUSBEnable = g_sMetaComm.bUsbEnable;   
    m_stModeArg.m_bIsSymbolicEnable = false;
    m_stModeArg.m_bIsCompositeDeviceEnable = g_sMetaComm.bCompositeDeviceEnable;
    m_stModeArg.m_euBootMode = SP_META_BOOT;
    m_stModeArg.m_uPortNumber = 0;
    m_stModeArg.m_uMDMode = 0;

    //Common
    m_tMetaReq_Ex.com_port = m_iKernelComport;
    m_tMetaReq_Ex.ms_connect_timeout = g_sMetaComm.iKernel_Connect_Timeout;
    m_tMetaReq_Ex.close_com_port = 1;
    m_tMetaReq_Ex.InMetaMode = 1;
    m_tMetaReq_Ex.protocol = 1;          // DHL
    m_tMetaReq_Ex.channel_type = 1;      // Native channel
    m_tMetaReq_Ex.boot_meta_arg.m_bbchip_type = AUTO_DETECT_BBCHIP; 
    m_tMetaReq_Ex.boot_meta_arg.m_ext_clock = AUTO_DETECT_EXT_CLOCK;
    //UART parameters
    //m_tMetaReq_Ex.baudrate[0] = META_BAUD115200;
    //m_tMetaReq_Ex.baudrate[1] = META_BAUD230400;
    //m_tMetaReq_Ex.baudrate[2] = META_BAUD460800;
    m_tMetaReq_Ex.baudrate[0] = META_BAUD921600;
    m_tMetaReq_Ex.baudrate[1] = META_BAUD_END;   
    m_tMetaReq_Ex.flowctrl = META_SW_FLOWCTRL;
    //USB
    if (g_sMetaComm.bUsbEnable)
    {
        this->Display("SmartPhoneSN::SetupMetaModeParameters(): Target enter meta mode by [USB].",3);
        m_tMetaReq_Ex.usb_enable = 1;
        m_tMetaReq_Ex.boot_meta_arg.m_usb_enable = _TRUE;       
    } 
    else
    {
        this->Display("SmartPhoneSN::SetupMetaModeParameters(): Target enter meta mode by [UART].",3);
        m_tMetaReq_Ex.usb_enable = 0;
        m_tMetaReq_Ex.boot_meta_arg.m_usb_enable = _FALSE;
        m_tMetaReq_Ex.escape = 1;
    }                    
    
    
    this->Display("SmartPhoneSN::SetupMetaModeParameters() end...",3);
}


char* ResultToString_SP(int MR)
{
  int nError = (META_RESULT)MR;
  switch((META_RESULT)MR)
  { 
	 case SPMETA_DLL::META_SUCCESS:
		  return M2S(SPMETA_DLL::META_SUCCESS);
	 
	 case SPMETA_DLL::META_FAILED:
		  return M2S(SPMETA_DLL::META_FAILED);
	 
	 case SPMETA_DLL::META_COMM_FAIL:
		  return M2S(SPMETA_DLL::META_COMM_FAIL);
	 
	 case SPMETA_DLL::META_NORESPONSE:
		  return M2S(SPMETA_DLL::META_NORESPONSE);
	 
	 case SPMETA_DLL::META_BUFFER_LEN:
		  return M2S(SPMETA_DLL::META_BUFFER_LEN);
	 
	 case SPMETA_DLL::META_FILE_BAD:
		  return M2S(SPMETA_DLL::META_FILE_BAD);
	 
	 case SPMETA_DLL::META_LID_INVALID:
		  return M2S(SPMETA_DLL::META_LID_INVALID);
	 
	 case SPMETA_DLL::META_INTERNAL_DB_ERR:
		  return M2S(SPMETA_DLL::META_INTERNAL_DB_ERR);
	 
	 case SPMETA_DLL::META_NO_MEMORY:
		  return M2S(SPMETA_DLL::META_NO_MEMORY);
	 
	 case SPMETA_DLL::META_INVALID_ARGUMENTS:
		  return M2S(SPMETA_DLL::META_INVALID_ARGUMENTS);
	 
	 case SPMETA_DLL::META_TIMEOUT:
		  return M2S(SPMETA_DLL::META_TIMEOUT);
	 
	 case SPMETA_DLL::META_BUSY:
		  return M2S(SPMETA_DLL::META_BUSY);
	 
	 case SPMETA_DLL::META_INVALID_HANDLE:
		  return M2S(SPMETA_DLL::META_INVALID_HANDLE);
	 
	 case SPMETA_DLL::META_FAT_ERROR:
		  return M2S(SPMETA_DLL::META_FAT_ERROR);
	 
	 case SPMETA_DLL::META_FAT_DISK_FULL:
		  return M2S(SPMETA_DLL::META_FAT_DISK_FULL);
	 
	 case SPMETA_DLL::META_FAT_ROOT_DIR_FULL:
		  return M2S(SPMETA_DLL::META_FAT_ROOT_DIR_FULL);
	 
	 case SPMETA_DLL::META_FAT_INVALID_FILENAME:
		  return M2S(SPMETA_DLL::META_FAT_INVALID_FILENAME);
	 
	 case SPMETA_DLL::META_FAT_INVALID_FILE_HANDLE:
		  return M2S(SPMETA_DLL::META_FAT_INVALID_FILE_HANDLE);
	 
	 case SPMETA_DLL::META_FAT_FILE_NOT_FOUND:
		  return M2S(SPMETA_DLL::META_FAT_FILE_NOT_FOUND);
	 
	 case SPMETA_DLL::META_FAT_DRIVE_NOT_FOUND:
		  return M2S(SPMETA_DLL::META_FAT_DRIVE_NOT_FOUND);
	 
	 case SPMETA_DLL::META_FAT_PATH_NOT_FOUND:
		  return M2S(SPMETA_DLL::META_FAT_PATH_NOT_FOUND);
	 
	 case SPMETA_DLL::META_FAT_ACCESS_DENIED:
		  return M2S(SPMETA_DLL::META_FAT_ACCESS_DENIED);
	 
	 case SPMETA_DLL::META_FAT_TOO_MANY_FILES:
		  return M2S(SPMETA_DLL::META_FAT_TOO_MANY_FILES);
	 
	 case SPMETA_DLL::META_INCORRECT_TARGET_VER:
		  return M2S(SPMETA_DLL::META_INCORRECT_TARGET_VER);
	 
	 case SPMETA_DLL::META_COM_ERROR:
		  return M2S(SPMETA_DLL::META_COM_ERROR);
	 
	 case SPMETA_DLL::META_BROM_CMD_ERROR:
		  return M2S(SPMETA_DLL::META_BROM_CMD_ERROR);
	 
	 case SPMETA_DLL::META_INCORRECT_BBCHIP_TYPE:
		  return M2S(SPMETA_DLL::META_INCORRECT_BBCHIP_TYPE);
	 
	 case SPMETA_DLL::META_BROM_ERROR:
		  return M2S(SPMETA_DLL::META_BROM_ERROR);
	 
	 case SPMETA_DLL::META_STOP_BOOTUP_PROCEDURE:
		  return M2S(SPMETA_DLL::META_STOP_BOOTUP_PROCEDURE);
	 
	 case SPMETA_DLL::META_CANCEL:
		  return M2S(SPMETA_DLL::META_CANCEL);
	 
	 case SPMETA_DLL::META_CCT_NOT_IMPORT_PROFILE:
		  return M2S(SPMETA_DLL::META_CCT_NOT_IMPORT_PROFILE);
	 
	 case SPMETA_DLL::META_CCT_INVALID_SENSOR_ID:
		  return M2S(SPMETA_DLL::META_CCT_INVALID_SENSOR_ID);
	 
	 case SPMETA_DLL::META_CCT_TGT_NO_MEM_FOR_SINGLE_SHOT:
		  return M2S(SPMETA_DLL::META_CCT_TGT_NO_MEM_FOR_SINGLE_SHOT);
	 
	 case SPMETA_DLL::META_CCT_TGT_NO_MEM_FOR_MULTI_SHOT:
		  return M2S(SPMETA_DLL::META_CCT_TGT_NO_MEM_FOR_MULTI_SHOT);
	 
	 case SPMETA_DLL::META_FUNC_NOT_IMPLEMENT_YET:
		  return M2S(SPMETA_DLL::META_FUNC_NOT_IMPLEMENT_YET);
	/* 
	 case SPMETA_DLL::META_CCT_NOT_IMPLEMENT_YET:
		  return M2S(SPMETA_DLL::META_CCT_NOT_IMPLEMENT_YET);
	*/ 
	 case SPMETA_DLL::META_CCT_PREVIEW_ALREADY_STARTED:
		  return M2S(SPMETA_DLL::META_CCT_PREVIEW_ALREADY_STARTED);
	 
	 case SPMETA_DLL::META_CCT_PREVIEW_ALREADY_STOPPED:
		  return M2S(SPMETA_DLL::META_CCT_PREVIEW_ALREADY_STOPPED);
	 
	 case SPMETA_DLL::META_CCT_READ_REG_NO_CNF:
		  return M2S(SPMETA_DLL::META_CCT_READ_REG_NO_CNF);
	 
	 case SPMETA_DLL::META_CCT_WRITE_REG_NO_CNF:
		  return M2S(SPMETA_DLL::META_CCT_WRITE_REG_NO_CNF);
	 
	 case SPMETA_DLL::META_CCT_TGT_ABORT_IMAGE_SENDING:
		  return M2S(SPMETA_DLL::META_CCT_TGT_ABORT_IMAGE_SENDING);
	 
	 case SPMETA_DLL::META_CCT_READ_ONLY_REGISTER:
		  return M2S(SPMETA_DLL::META_CCT_READ_ONLY_REGISTER);
	 
	 case SPMETA_DLL::META_CCT_LOAD_FROM_NVRAM_FAIL:
		  return M2S(SPMETA_DLL::META_CCT_LOAD_FROM_NVRAM_FAIL);
	 
	 case SPMETA_DLL::META_CCT_SAVE_TO_NVRAM_FAIL:
		  return M2S(SPMETA_DLL::META_CCT_SAVE_TO_NVRAM_FAIL);
	 
	 case SPMETA_DLL::META_CCT_AE_INVALID_EC_LEVEL:
		  return M2S(SPMETA_DLL::META_CCT_AE_INVALID_EC_LEVEL);
	 
	 case SPMETA_DLL::META_CCT_AE_INVALID_EC_STEP:
		  return M2S(SPMETA_DLL::META_CCT_AE_INVALID_EC_STEP);
	 
	 case SPMETA_DLL::META_CCT_AE_ALREADY_ENABLED:
		  return M2S(SPMETA_DLL::META_CCT_AE_ALREADY_ENABLED);
	 
	 case SPMETA_DLL::META_CCT_AE_ALREADY_DISABLED:
		  return M2S(SPMETA_DLL::META_CCT_AE_ALREADY_DISABLED);
	 
	 case SPMETA_DLL::META_CCT_WB_INVALID_INDEX:
		  return M2S(SPMETA_DLL::META_CCT_WB_INVALID_INDEX);
	 
	 case SPMETA_DLL::META_CCT_NO_TGT_SENSOR_MATCH_IN_PROFILE:
		  return M2S(SPMETA_DLL::META_CCT_NO_TGT_SENSOR_MATCH_IN_PROFILE);
	 
	 case SPMETA_DLL::META_CCT_IMAGE_SENDING_FAME_NUM_ERROR:
		  return M2S(SPMETA_DLL::META_CCT_IMAGE_SENDING_FAME_NUM_ERROR);
	 
	 case SPMETA_DLL::META_CCT_AE_IS_NOT_DISABLED:
		  return M2S(SPMETA_DLL::META_CCT_AE_IS_NOT_DISABLED);
	 
	 case SPMETA_DLL::META_FAT_APP_QUOTA_FULL:
		  return M2S(SPMETA_DLL::META_FAT_APP_QUOTA_FULL);
	 
	 case SPMETA_DLL::META_IMEI_CD_ERROR:
		  return M2S(SPMETA_DLL::META_IMEI_CD_ERROR);
	 
	 case SPMETA_DLL::META_RFID_MISMATCH:
		  return M2S(SPMETA_DLL::META_RFID_MISMATCH);
	 
	 case SPMETA_DLL::META_NVRAM_DB_IS_NOT_LOADED_YET:
		  return M2S(SPMETA_DLL::META_NVRAM_DB_IS_NOT_LOADED_YET);
	 
	 case SPMETA_DLL::META_CCT_ERR_CAPTURE_WIDTH_HEIGHT_TOO_SMALL:
		  return M2S(SPMETA_DLL::META_CCT_ERR_CAPTURE_WIDTH_HEIGHT_TOO_SMALL);
	 
	 case SPMETA_DLL::META_WAIT_FOR_TARGET_READY_TIMEOUT:
		  return M2S(SPMETA_DLL::META_WAIT_FOR_TARGET_READY_TIMEOUT);
	 
	 case SPMETA_DLL::META_CCT_ERR_SENSOR_ENG_SET_INVALID_VALUE:
		  return M2S(SPMETA_DLL::META_CCT_ERR_SENSOR_ENG_SET_INVALID_VALUE);
	 
	 case SPMETA_DLL::META_CCT_ERR_SENSOR_ENG_GROUP_NOT_EXIST:
		  return M2S(SPMETA_DLL::META_CCT_ERR_SENSOR_ENG_GROUP_NOT_EXIST);
	 
	 case SPMETA_DLL::META_CCT_NO_TGT_ISP_MATCH_IN_PROFILE:
		  return M2S(SPMETA_DLL::META_CCT_NO_TGT_ISP_MATCH_IN_PROFILE);
	 
	 case SPMETA_DLL::META_CCT_TGT_ISP_SUPPORT_NOT_DEFINED:
		  return M2S(SPMETA_DLL::META_CCT_TGT_ISP_SUPPORT_NOT_DEFINED);
	 
	 case SPMETA_DLL::META_CCT_ERR_SENSOR_ENG_ITEM_NOT_EXIST:
		  return M2S(SPMETA_DLL::META_CCT_ERR_SENSOR_ENG_ITEM_NOT_EXIST);
	 
	 case SPMETA_DLL::META_CCT_ERR_INVALID_COMPENSATION_MODE:
		  return M2S(SPMETA_DLL::META_CCT_ERR_INVALID_COMPENSATION_MODE);
	 
	 case SPMETA_DLL::META_CCT_ERR_USB_COM_NOT_READY:
		  return M2S(SPMETA_DLL::META_CCT_ERR_USB_COM_NOT_READY);
	 
	 case SPMETA_DLL::META_CCT_DEFECTPIXEL_CAL_UNDER_PROCESSING:
		  return M2S(SPMETA_DLL::META_CCT_DEFECTPIXEL_CAL_UNDER_PROCESSING);
	 
	 case SPMETA_DLL::META_CCT_ERR_DEFECTPIXEL_CAL_NO_MEM:
		  return M2S(SPMETA_DLL::META_CCT_ERR_DEFECTPIXEL_CAL_NO_MEM);
	 
	 case SPMETA_DLL::META_CCT_ERR_TOO_MANY_DEFECT_PIXEL:
		  return M2S(SPMETA_DLL::META_CCT_ERR_TOO_MANY_DEFECT_PIXEL);
	 
	 case SPMETA_DLL::META_CCT_ERR_CAPTURE_JPEG_FAIL:
		  return M2S(SPMETA_DLL::META_CCT_ERR_CAPTURE_JPEG_FAIL);
	 
	 case SPMETA_DLL::META_CCT_ERR_CAPTURE_JPEG_TIMEOUT:
		  return M2S(SPMETA_DLL::META_CCT_ERR_CAPTURE_JPEG_TIMEOUT);
	 
	 case SPMETA_DLL::META_CCT_ERR_AF_FAIL:
		  return M2S(SPMETA_DLL::META_CCT_ERR_AF_FAIL);
	 
	 case SPMETA_DLL::META_CCT_ERR_AF_TIMEOUT:
		  return M2S(SPMETA_DLL::META_CCT_ERR_AF_TIMEOUT);
	 
	 case SPMETA_DLL::META_CCT_ERR_AF_LENS_OFFSET_CAL_FAIL:
		  return M2S(SPMETA_DLL::META_CCT_ERR_AF_LENS_OFFSET_CAL_FAIL);
	 
	 case SPMETA_DLL::META_CCT_ERR_PREVIEW_MUST_ENABLE:
		  return M2S(SPMETA_DLL::META_CCT_ERR_PREVIEW_MUST_ENABLE);
	 
	 case SPMETA_DLL::META_CCT_ERR_UNSUPPORT_CAPTURE_FORMAT:
		  return M2S(SPMETA_DLL::META_CCT_ERR_UNSUPPORT_CAPTURE_FORMAT);
	 
	 case SPMETA_DLL::META_CCT_ERR_EXCEED_MAX_DEFECT_PIXEL:
		  return M2S(SPMETA_DLL::META_CCT_ERR_EXCEED_MAX_DEFECT_PIXEL);
	 
	 case SPMETA_DLL::META_ERR_EXCEED_MAX_PEER_BUF_SIZE:
		  return M2S(SPMETA_DLL::META_ERR_EXCEED_MAX_PEER_BUF_SIZE);
	 
	 case SPMETA_DLL::META_CCT_ERR_INVALID_WIDTH_FACTOR:
		  return M2S(SPMETA_DLL::META_CCT_ERR_INVALID_WIDTH_FACTOR);
	 
	 case SPMETA_DLL::META_BROM_SECURITY_CHECK_FAIL:
		  return M2S(SPMETA_DLL::META_BROM_SECURITY_CHECK_FAIL);
	 
	 case SPMETA_DLL::META_CCT_ERR_PREVIEW_MUST_DISABLE:
		  return M2S(SPMETA_DLL::META_CCT_ERR_PREVIEW_MUST_DISABLE);
	 
	 case SPMETA_DLL::META_MAUI_DB_INCONSISTENT:
		  return M2S(SPMETA_DLL::META_MAUI_DB_INCONSISTENT);
	 
	 case SPMETA_DLL::META_FAT_FILEPATH_TOO_LONG:
		  return M2S(SPMETA_DLL::META_FAT_FILEPATH_TOO_LONG);
	 
	 case SPMETA_DLL::META_FAT_RESTRICTED_FILEPATH:
		  return M2S(SPMETA_DLL::META_FAT_RESTRICTED_FILEPATH);
	 
	 case SPMETA_DLL::META_FAT_DIR_NOT_EXIST:
		  return M2S(SPMETA_DLL::META_FAT_DIR_NOT_EXIST);
	 
	 case SPMETA_DLL::META_FAT_DISK_SPACE_IS_NOT_ENOUGH:
		  return M2S(SPMETA_DLL::META_FAT_DISK_SPACE_IS_NOT_ENOUGH);
	 
	 case SPMETA_DLL::META_TDMB_ERR_BAND_NOT_EXIST:
		  return M2S(SPMETA_DLL::META_TDMB_ERR_BAND_NOT_EXIST);
	 
	 case SPMETA_DLL::META_TDMB_ERR_FREQ_NOT_EXIST:
		  return M2S(SPMETA_DLL::META_TDMB_ERR_FREQ_NOT_EXIST);
	 
	 case SPMETA_DLL::META_TDMB_ERR_ENSM_NOT_EXIST:
		  return M2S(SPMETA_DLL::META_TDMB_ERR_ENSM_NOT_EXIST);
	 
	 case SPMETA_DLL::META_TDMB_ERR_SERV_NOT_EXIST:
		  return M2S(SPMETA_DLL::META_TDMB_ERR_SERV_NOT_EXIST);
	 
	 case SPMETA_DLL::META_TDMB_ERR_SUB_CHAN_NOT_EXIST:
		  return M2S(SPMETA_DLL::META_TDMB_ERR_SUB_CHAN_NOT_EXIST);
	 
	 case SPMETA_DLL::META_TDMB_ERR_DEMOD_STATE:
		  return M2S(SPMETA_DLL::META_TDMB_ERR_DEMOD_STATE);
	 
	 case SPMETA_DLL::META_PERMISSION_DENIED:
		  return M2S(SPMETA_DLL::META_PERMISSION_DENIED);
	 
	 case SPMETA_DLL::META_ENUMERATE_USB_FAIL:
		  return M2S(SPMETA_DLL::META_ENUMERATE_USB_FAIL);
	 
	 case SPMETA_DLL::META_STOP_ENUM_USB_PROCEDURE:
		  return M2S(SPMETA_DLL::META_STOP_ENUM_USB_PROCEDURE);
	 
	 case SPMETA_DLL::META_CCT_6238_AE_ALREADY_ENABLED:
		  return M2S(SPMETA_DLL::META_CCT_6238_AE_ALREADY_ENABLED);
	 
	 case SPMETA_DLL::META_CCT_6238_AE_ALREADY_DISABLED:
		  return M2S(SPMETA_DLL::META_CCT_6238_AE_ALREADY_DISABLED);
	 
	 case SPMETA_DLL::META_CCT_6238_AE_IS_NOT_DISABLED:
		  return M2S(SPMETA_DLL::META_CCT_6238_AE_IS_NOT_DISABLED);
	 
	 case SPMETA_DLL::META_CCT_6238_ISP_FLASHLIGHT_LINEARITY_PRESTROBE_FAIL:
		  return M2S(SPMETA_DLL::META_CCT_6238_ISP_FLASHLIGHT_LINEARITY_PRESTROBE_FAIL);
	 
	 case SPMETA_DLL::META_NOT_SUPPORT:
		  return M2S(SPMETA_DLL::META_NOT_SUPPORT);
	 
	 case SPMETA_DLL::META_LAST_RESULT:
		  return M2S(SPMETA_DLL::META_LAST_RESULT);
  default:
		return M2S(DEFAULT_FAIL);
  }
  
}

char* ResultToString(int MR)
{
	switch((META_RESULT)MR)
	{
	
	case META_SUCCESS:
		 return M2S(META_SUCCESS);
	
	case META_FAILED:
		 return M2S(META_FAILED);
	
	case META_COMM_FAIL:
		 return M2S(META_COMM_FAIL);
	
	case META_NORESPONSE:
		 return M2S(META_NORESPONSE);
	
	case META_EBOOT_FAILED:
		 return M2S(META_EBOOT_FAILED);
	
	case META_BUFFER_LEN:
		 return M2S(META_BUFFER_LEN);
	
	case META_FILE_BAD:
		 return M2S(META_FILE_BAD);
	
	case META_LID_INVALID:
		 return M2S(META_LID_INVALID);
	
	case META_INTERNAL_DB_ERR:
		 return M2S(META_INTERNAL_DB_ERR);
	
	case META_NO_MEMORY:
		 return M2S(META_NO_MEMORY);
	
	case META_INVALID_ARGUMENTS:
		 return M2S(META_INVALID_ARGUMENTS);
	
	case META_TIMEOUT:
		 return M2S(META_TIMEOUT);
	
	case META_BUSY:
		 return M2S(META_BUSY);
	
	case META_INVALID_HANDLE:
		 return M2S(META_INVALID_HANDLE);
	
	case META_FAT_ERROR:
		 return M2S(META_FAT_ERROR);
	
	case META_FAT_DISK_FULL:
		 return M2S(META_FAT_DISK_FULL);
	
	case META_FAT_ROOT_DIR_FULL:
		 return M2S(META_FAT_ROOT_DIR_FULL);
	
	case META_FAT_INVALID_FILENAME:
		 return M2S(META_FAT_INVALID_FILENAME);
	
	case META_FAT_INVALID_FILE_HANDLE:
		 return M2S(META_FAT_INVALID_FILE_HANDLE);
	
	case META_FAT_FILE_NOT_FOUND:
		 return M2S(META_FAT_FILE_NOT_FOUND);
	
	case META_FAT_DRIVE_NOT_FOUND:
		 return M2S(META_FAT_DRIVE_NOT_FOUND);
	
	case META_FAT_PATH_NOT_FOUND:
		 return M2S(META_FAT_PATH_NOT_FOUND);
	
	case META_FAT_ACCESS_DENIED:
		 return M2S(META_FAT_ACCESS_DENIED);
	
	case META_FAT_TOO_MANY_FILES:
		 return M2S(META_FAT_TOO_MANY_FILES);
	
	case META_INCORRECT_TARGET_VER:
		 return M2S(META_INCORRECT_TARGET_VER);
	
	case META_COM_ERROR:
		 return M2S(META_COM_ERROR);
	
	case META_BROM_CMD_ERROR:
		 return M2S(META_BROM_CMD_ERROR);
	
	case META_INCORRECT_BBCHIP_TYPE:
		 return M2S(META_INCORRECT_BBCHIP_TYPE);
	
	case META_BROM_ERROR:
		 return M2S(META_BROM_ERROR);
	
	case META_STOP_BOOTUP_PROCEDURE:
		 return M2S(META_STOP_BOOTUP_PROCEDURE);
	
	case META_CANCEL:
		 return M2S(META_CANCEL);
	
	case META_FUNC_NOT_IMPLEMENT_YET:
		 return M2S(META_FUNC_NOT_IMPLEMENT_YET);
	
	case META_FAT_APP_QUOTA_FULL:
		 return M2S(META_FAT_APP_QUOTA_FULL);
	
	case META_IMEI_CD_ERROR:
		 return M2S(META_IMEI_CD_ERROR);
	
	case META_RFID_MISMATCH:
		 return M2S(META_RFID_MISMATCH);
	
	case META_NVRAM_DB_IS_NOT_LOADED_YET:
		 return M2S(META_NVRAM_DB_IS_NOT_LOADED_YET);
	
	case META_WAIT_FOR_TARGET_READY_TIMEOUT:
		 return M2S(META_WAIT_FOR_TARGET_READY_TIMEOUT);
	
	case META_ERR_EXCEED_MAX_PEER_BUF_SIZE:
		 return M2S(META_ERR_EXCEED_MAX_PEER_BUF_SIZE);
	
	case META_BROM_SECURITY_CHECK_FAIL:
		 return M2S(META_BROM_SECURITY_CHECK_FAIL);
	
	case META_MAUI_DB_INCONSISTENT:
		 return M2S(META_MAUI_DB_INCONSISTENT);
	
	case META_FAT_FILEPATH_TOO_LONG:
		 return M2S(META_FAT_FILEPATH_TOO_LONG);
	
	case META_FAT_RESTRICTED_FILEPATH:
		 return M2S(META_FAT_RESTRICTED_FILEPATH);
	
	case META_FAT_DIR_NOT_EXIST:
		 return M2S(META_FAT_DIR_NOT_EXIST);
	
	case META_FAT_DISK_SPACE_IS_NOT_ENOUGH:
		 return M2S(META_FAT_DISK_SPACE_IS_NOT_ENOUGH);
	
	case META_TDMB_ERR_BAND_NOT_EXIST:
		 return M2S(META_TDMB_ERR_BAND_NOT_EXIST);
	
	case META_TDMB_ERR_FREQ_NOT_EXIST:
		 return M2S(META_TDMB_ERR_FREQ_NOT_EXIST);
	
	case META_TDMB_ERR_ENSM_NOT_EXIST:
		 return M2S(META_TDMB_ERR_ENSM_NOT_EXIST);
	
	case META_TDMB_ERR_SERV_NOT_EXIST:
		 return M2S(META_TDMB_ERR_SERV_NOT_EXIST);
	
	case META_TDMB_ERR_SUB_CHAN_NOT_EXIST:
		 return M2S(META_TDMB_ERR_SUB_CHAN_NOT_EXIST);
	
	case META_TDMB_ERR_DEMOD_STATE:
		 return M2S(META_TDMB_ERR_DEMOD_STATE);
	
	case META_ENUMERATE_USB_FAIL:
		 return M2S(META_ENUMERATE_USB_FAIL);
	
	case META_STOP_ENUM_USB_PROCEDURE:
		 return M2S(META_STOP_ENUM_USB_PROCEDURE);
	
	case META_MISC_TARGET_LOAD_NEED_TO_BE_PATCHED:
		 return M2S(META_MISC_TARGET_LOAD_NEED_TO_BE_PATCHED);
	
	case META_MISC_INI_FILE_SETTINGS_WRONG:
		 return M2S(META_MISC_INI_FILE_SETTINGS_WRONG);
	
	case META_MISC_FAIL_TO_READ_IMEI:
		 return M2S(META_MISC_FAIL_TO_READ_IMEI);
	
	case META_MISC_FAIL_TO_BACKUP_FILE:
		 return M2S(META_MISC_FAIL_TO_BACKUP_FILE);
	
	case META_MISC_FAIL_TO_WRITE_BACKUP_RESULT:
		 return M2S(META_MISC_FAIL_TO_WRITE_BACKUP_RESULT);
	
	case META_MISC_FAIL_TO_GET_NVRAM_FOLDER_PATH:
		 return M2S(META_MISC_FAIL_TO_GET_NVRAM_FOLDER_PATH);
	
	case META_MISC_FAIL_TO_GET_NVRAM_MUST_LIST:
		 return M2S(META_MISC_FAIL_TO_GET_NVRAM_MUST_LIST);
	
	case META_STOP_CURRENT_PROCEDURE:
		 return M2S(META_STOP_CURRENT_PROCEDURE);
	
	case META_MISC_CUSTOMIZED_NVRAM_ERROR:
		 return M2S(META_MISC_CUSTOMIZED_NVRAM_ERROR);
	
	case META_MISC_FOLDER_EMPTY_CHECKING_FAIL:
		 return M2S(META_MISC_FOLDER_EMPTY_CHECKING_FAIL);
	
	case META_MISC_TOO_MANY_BACKUP_RESULT_FILE:
		 return M2S(META_MISC_TOO_MANY_BACKUP_RESULT_FILE);
	
	case META_MISC_TOO_MANY_RESTORE_RESULT_FILE:
		 return M2S(META_MISC_TOO_MANY_RESTORE_RESULT_FILE);
	
	case META_MISC_RESTORE_RESULT_FILE_NOT_EXIST:
		 return M2S(META_MISC_RESTORE_RESULT_FILE_NOT_EXIST);
	
	case META_MISC_RESTORE_RESULT_FILE_INCOMPLETE:
		 return M2S(META_MISC_RESTORE_RESULT_FILE_INCOMPLETE);
	
	case META_FAIL_TO_CELAR_ALL_IN_BACUP_FOLDER:
		 return M2S(META_FAIL_TO_CELAR_ALL_IN_BACUP_FOLDER);
	
	case META_MISC_BACKUP_RESULT_FILE_NOT_EXIST:
		 return M2S(META_MISC_BACKUP_RESULT_FILE_NOT_EXIST);
	
	case META_MISC_BACKUP_RESULT_FILE_INCOMPLETE:
		 return M2S(META_MISC_BACKUP_RESULT_FILE_INCOMPLETE);
	
	case META_MISC_IMEI_MISMATCH:
		 return M2S(META_MISC_IMEI_MISMATCH);
	
	case META_MISC_SML_FILE_VERIFY_FAIL:
		 return M2S(META_MISC_SML_FILE_VERIFY_FAIL);
	
	case META_MISC_BACKUP_RESULT_NOT_ENOUGH_FOR_NEW_LOAD:
		 return M2S(META_MISC_BACKUP_RESULT_NOT_ENOUGH_FOR_NEW_LOAD);
	
	case META_MISC_FAIL_TO_RESTORE_FILE:
		 return M2S(META_MISC_FAIL_TO_RESTORE_FILE);
	
	case META_MISC_FAIL_TO_WRITE_RESTORE_RESULT:
		 return M2S(META_MISC_FAIL_TO_WRITE_RESTORE_RESULT);
	
	case META_MISC_USE_WRONG_API_FOR_NEW_LOAD:
		 return M2S(META_MISC_USE_WRONG_API_FOR_NEW_LOAD);
	
	case META_MISC_QUERY_TARGET_CAPABILITY_FAIL:
		 return M2S(META_MISC_QUERY_TARGET_CAPABILITY_FAIL);
	
	case META_MISC_INI_SETTINGS_ERR_IN_NVRAM_SEC:
		 return M2S(META_MISC_INI_SETTINGS_ERR_IN_NVRAM_SEC);
	
	case META_MISC_INI_SETTINGS_ERR_IN_TARGET_SEC:
		 return M2S(META_MISC_INI_SETTINGS_ERR_IN_TARGET_SEC);
	
	case META_MISC_INI_SETTINGS_ERR_IN_PC_SEC:
		 return M2S(META_MISC_INI_SETTINGS_ERR_IN_PC_SEC);
	
	case META_MISC_NO_FILES_NEED_TO_BE_UPLOAD:
		 return M2S(META_MISC_NO_FILES_NEED_TO_BE_UPLOAD);
	
	case META_FAT_ACTION_NOT_SUPPORT:
		 return M2S(META_FAT_ACTION_NOT_SUPPORT);
	
	case META_MISC_EMPTY_UPLOADFILES_AND_IMEI_SEC:
		 return M2S(META_MISC_EMPTY_UPLOADFILES_AND_IMEI_SEC);
	
	case META_MISC_INI_SETTINGS_ERR_IN_MORE_SEC:
		 return M2S(META_MISC_INI_SETTINGS_ERR_IN_MORE_SEC);
	
	case META_MISC_INI_SETTINGS_ERR_IN_DELETE_SEC:
		 return M2S(META_MISC_INI_SETTINGS_ERR_IN_DELETE_SEC);
	
	case META_MISC_CHECK_TARGET_NVRAM_FILES_FAIL:
		 return M2S(META_MISC_CHECK_TARGET_NVRAM_FILES_FAIL);
	
	case META_MISC_FAIL_TO_GET_NVRAM_FOLDER_AMOUNT:
		 return M2S(META_MISC_FAIL_TO_GET_NVRAM_FOLDER_AMOUNT);
	
	case META_AUDIO_CHECK_WAVE_FILE_FAIL:
		 return M2S(META_AUDIO_CHECK_WAVE_FILE_FAIL);
	
	case META_MISC_COLLECT_NVRAM_FOLDER_FILES_FAILED:
		 return M2S(META_MISC_COLLECT_NVRAM_FOLDER_FILES_FAILED);
	
	case META_MISC_COLLECT_NVRAM_FOLDER_FILES_FIRST:
		 return M2S(META_MISC_COLLECT_NVRAM_FOLDER_FILES_FIRST);
	
	case META_MISC_BACKUP_FILE_NOT_FOUND_IN_NVRAM:
		 return M2S(META_MISC_BACKUP_FILE_NOT_FOUND_IN_NVRAM);
	
	case META_MISC_BACKUP_MORE_FILE_NOT_FOUND_IN_NVRAM:
		 return M2S(META_MISC_BACKUP_MORE_FILE_NOT_FOUND_IN_NVRAM);
	
	case META_MISC_LOCAL_FS_UNKNOWN_ERROR:
		 return M2S(META_MISC_LOCAL_FS_UNKNOWN_ERROR);
	
	case META_MISC_RETORE_FILE_NOT_FOUND_IN_BACKUP_RESULT:
		 return M2S(META_MISC_RETORE_FILE_NOT_FOUND_IN_BACKUP_RESULT);
	
	case META_MISC_LEGACY_ADC_FILE_NOT_FOUND:
		 return M2S(META_MISC_LEGACY_ADC_FILE_NOT_FOUND);
	
	case META_MISC_LEGACY_BARCODE_FILE_NOT_FOUND:
		 return M2S(META_MISC_LEGACY_BARCODE_FILE_NOT_FOUND);
	
	case META_MISC_FILE_SIZE_MISMATCH:
		 return M2S(META_MISC_FILE_SIZE_MISMATCH);
	
	case META_MISC_RESTORE_TARGET_NOT_FOUND_IN_NVRAM:
		 return M2S(META_MISC_RESTORE_TARGET_NOT_FOUND_IN_NVRAM);
	
	case META_UTIL_CONVERT_MULTIBYTE_TO_WCHAR_FAILED:
		 return M2S(META_UTIL_CONVERT_MULTIBYTE_TO_WCHAR_FAILED);
	
	case META_FAT_RECURSIVE_CREATE_FOLDER_FAILED:
		 return M2S(META_FAT_RECURSIVE_CREATE_FOLDER_FAILED);
	
	case META_FAT_COPY_INVALID_SOURCE_FOLDER:
		 return M2S(META_FAT_COPY_INVALID_SOURCE_FOLDER);
	
	case META_FAT_COPY_EMPTY_SOURCE_FOLDER:
		 return M2S(META_FAT_COPY_EMPTY_SOURCE_FOLDER);
	
	case META_MISC_MULTIPLE_ENTRY_NOT_SUPPORTED:
		 return M2S(META_MISC_MULTIPLE_ENTRY_NOT_SUPPORTED);
	
	case META_MISC_INVALID_FORMAT:
		 return M2S(META_MISC_INVALID_FORMAT);
	
	case META_FAT_FILE_LENGTH_ZERO:
		 return M2S(META_FAT_FILE_LENGTH_ZERO);
	
	case META_MISC_INI_SETTINGS_ERR_IN_PC_FOLDER_SEC:
		 return M2S(META_MISC_INI_SETTINGS_ERR_IN_PC_FOLDER_SEC);
	
	case META_PC_FILE_NOT_FOUND:
		 return M2S(META_PC_FILE_NOT_FOUND);
	
	case META_MEMBER_FIELD_TYPE_NOT_FOUND:
		 return M2S(META_MEMBER_FIELD_TYPE_NOT_FOUND);
	
	case META_MEMBER_FIELD_OFFSET_NOT_FOUND:
		 return M2S(META_MEMBER_FIELD_OFFSET_NOT_FOUND);
	
	case META_NVRAM_GET_KEY_LENGTH_CALLBACK_ERROR:
		 return M2S(META_NVRAM_GET_KEY_LENGTH_CALLBACK_ERROR);
	
	case META_NVRAM_ALLOCATE_KEY_BUFFER_ERROR:
		 return M2S(META_NVRAM_ALLOCATE_KEY_BUFFER_ERROR);
	
	case META_NVRAM_GET_KEY_BUFFER_CALLBACK_ERROR:
		 return M2S(META_NVRAM_GET_KEY_BUFFER_CALLBACK_ERROR);
	
	case META_NVRAM_KEY_ENTRY_MISSING:
		 return M2S(META_NVRAM_KEY_ENTRY_MISSING);
	
	case META_NVRAM_KEY_ENTRY_ERROR:
		 return M2S(META_NVRAM_KEY_ENTRY_ERROR);
	
	case META_NVRAM_KEY_LENGTH_EXCEEDS_INTERNAL_BUFFER:
		 return M2S(META_NVRAM_KEY_LENGTH_EXCEEDS_INTERNAL_BUFFER);
	
	case META_FAT_SPACE_SIZE_OVERFLOW:
		 return M2S(META_FAT_SPACE_SIZE_OVERFLOW);
	
	case META_LIB_INCONSISTENT:
		 return M2S(META_LIB_INCONSISTENT);
	
	case META_INTERNAL_DB_ERROR:
		 return M2S(META_INTERNAL_DB_ERROR);
	
	case META_REQUIRED_TOOL_VERSION_CHECK_FAILD:
		 return M2S(META_REQUIRED_TOOL_VERSION_CHECK_FAILD);
	
	case META_CROSS_BRANCH_BACKUP_OPEN_FAILED:
		 return M2S(META_CROSS_BRANCH_BACKUP_OPEN_FAILED);
	
	case META_CROSS_BRANCH_BACKUP_PARSE_FAILED:
		 return M2S(META_CROSS_BRANCH_BACKUP_PARSE_FAILED);
	
	case META_CROSS_BRANCH_BACKUP_FILE_ATT_NOT_MATCH:
		 return M2S(META_CROSS_BRANCH_BACKUP_FILE_ATT_NOT_MATCH);
	
	case META_NVRAM_VALUE_NOT_LEGAL:
		 return M2S(META_NVRAM_VALUE_NOT_LEGAL);
	
	case META_INIT_CONNECTION_STARTED:
		 return M2S(META_INIT_CONNECTION_STARTED);
	
	case META_QUERY_NO_MODEM_SUPPORT:
		 return M2S(META_QUERY_NO_MODEM_SUPPORT);
	
	case META_MEMBER_FIELD_SIZE_NOT_FOUND:
		 return M2S(META_MEMBER_FIELD_SIZE_NOT_FOUND);
	
	case META_LAST_RESULT:
		 return M2S(META_LAST_RESULT);

	default:
		return M2S(DEFAULT_FAIL);
	}
}

//20150728 glory add
//Fix connect with kernel comport probabilistic fail bug
int CFullWriteView::TryToOpenSPKernelComport(int KernelCom_Num)
{
    CString sInfo;
	sInfo.Format("SmartPhoneSN::TryToOpenSPKernelComport(): Try to open kernel comport until it ready, KernelCom_Num = %d...",KernelCom_Num);
	this->Display(sInfo.GetBuffer(sInfo.GetLength()), 3);
    HANDLE Hcom;
    char tmp_com[30] = {0};
    sprintf(tmp_com, "\\\\.\\COM%d", KernelCom_Num);
    
    int retryTime = 0;
    //try to open kernel comport until it ready
    do
    {
        retryTime += 1;
        sInfo.Format("SmartPhoneSN::TryToOpenSPKernelComport(): Try to open kernel comport until it ready, retryTime = %d...",retryTime);
		this->Display(sInfo.GetBuffer(sInfo.GetLength()), 3);
        Hcom = CreateFile(tmp_com, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
        if (INVALID_HANDLE_VALUE != Hcom)
        {
            int Ret = CloseHandle(Hcom);
            sInfo.Format("SmartPhoneSN::TryToOpenSPKernelComport(): Open kernel comport success, retryTime = %d...",  retryTime);
			this->Display(sInfo.GetBuffer(sInfo.GetLength()), 3);
            return OK;
        }
        Sleep(1000);
    }while(retryTime <= 50);
    
    sInfo.Format("SmartPhoneSN::TryToOpenSPKernelComport(): Open kernel comport fail, retryTime = %d...", retryTime);
	this->Display(sInfo.GetBuffer(sInfo.GetLength()), 3);
    return ERROR;
}
//end

void CFullWriteView::Display(CString sMsg,int index/*=3*/)
{
	SendMessage(WM_CAL_MSG,(WPARAM)sMsg.GetBuffer(sMsg.GetLength()),index);
}

SPMETA_DLL::META_RESULT CFullWriteView::ExitAPMetaMode()
{
	CString sInfo;
    SPMETA_DLL::META_RESULT spMetaResult;  
    char *pFuncName = NULL;
    
    if (m_bTargetInMetaMode)
    {
        //Switch to modem meta fail from AP meta last time, so need to reconnect to AP meta mode
        if (m_eMetaMode == SP_AP2MD_FAIL)
        {
            int BootStop = 0;
            int usb_port = 0;
            SPMETA_DLL::WM_META_ConnectInMETA_Req BootRequest; 
            SPMETA_DLL::WM_META_ConnectInMETA_Report BootReport;
            
            BootRequest.com_port = m_iKernelComport;
            BootRequest.baudrate[0] = SPMETA_DLL::META_BAUD115200;
            BootRequest.baudrate[1] = SPMETA_DLL::META_BAUD230400;
            BootRequest.baudrate[2] = SPMETA_DLL::META_BAUD460800;
            BootRequest.baudrate[3] = SPMETA_DLL::META_BAUD921600;
            BootRequest.baudrate[4] = SPMETA_DLL::META_BAUD57600;
            BootRequest.baudrate[5] = SPMETA_DLL::META_BAUD_END;
            BootRequest.flowctrl    = SPMETA_DLL::META_NO_FLOWCTRL;//META_SW_FLOWCTRL;
            BootRequest.ms_connect_timeout = m_tMetaReq_Ex.ms_connect_timeout;
            
            spMetaResult = SPMETA_DLL::SP_META_ConnectInMetaMode_r(this->m_ApExe.iMetaAP_handle, &BootRequest, &BootStop, &BootReport); 
            if (META_SUCCESS != spMetaResult)
            {
                sInfo.Format("SmartPhoneSN::SP_META_ConnectInMetaMode_r(): Connect to AP meta Fail!, BootRequest.com_port = %d, MetaResult = %s", 
                    BootRequest.com_port, ResultToString_SP(spMetaResult));
				this->Display(sInfo);
            }  
        }
        
        
        spMetaResult = SPMETA_DLL::SP_META_DisconnectWithTarget_r (this->m_ApExe.iMetaAP_handle);
        pFuncName = "SP_META_DisconnectWithTarget_r()";
        if (spMetaResult == SPMETA_DLL::META_SUCCESS)
        {
            m_bTargetInMetaMode = false;
        } 
    }

    sInfo.Format("SmartPhoneSN::ExitAPMeta(): Exit meta mode by %s successfully! MetaResult = %s", pFuncName, ResultToString_SP(spMetaResult));
	this->Display(sInfo);
    return spMetaResult;
}

META_RESULT CFullWriteView::ExitSPModemMeta()
{
	CString sInfo;
    META_RESULT MetaResult = META_SUCCESS;

    //Switch to AP meta fail from modem meta last time, so need to reconnect to modem meta mode
    if (m_eMetaMode == SP_MD2AP_FAIL)
    {
        m_tMetaReq_Ex.com_port = m_iKernelComport;
        MetaResult = META_ConnectWithMultiModeTarget_r(this->m_nMetaHandle, &m_tMetaReq_Ex,sizeof(m_tMetaReq_Ex),m_pMetaStopFlag,&m_tMetaConnReport_Ex);
        if(MetaResult != META_SUCCESS)
        {        
            m_eMetaMode = SP_AP2MD_FAIL;
            sInfo.Format("SmartPhoneSN::META_ConnectWithMultiModeTarget_r():  Connect to Modem meta Fail, MetaResult = %s", ResultToString(MetaResult));
			this->Display(sInfo);
        }     
    }

    MetaResult = ModemSwithToAPMeta(); //Must switch to AP meta first, if not target can`t shutdown successfully
    if (MetaResult == META_SUCCESS)
    {
        ExitAPMetaMode();
    }
    
    return META_SUCCESS;
}




