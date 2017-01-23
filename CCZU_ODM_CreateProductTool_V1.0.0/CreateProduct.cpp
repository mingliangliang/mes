// CreateProduct.cpp : Defines the class behaviors for the application.
//
#include <windows.h>
#include "stdafx.h"
#include "CreateProduct.h"
#include "CreateProductDlg.h"
#include "Splash.h"
#include "Password.h"
#include "Main.h"
#include "OrderRelease.h"
#include "AlterSetting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCreateProductApp

BEGIN_MESSAGE_MAP(CCreateProductApp, CWinApp)
	//{{AFX_MSG_MAP(CCreateProductApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCreateProductApp construction

CCreateProductApp::CCreateProductApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCreateProductApp object

CCreateProductApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CCreateProductApp initialization

BOOL CCreateProductApp::InitInstance()
{
	AfxEnableControlContainer();

	if (CoInitialize(NULL)!=0) 
	{ 
		AfxMessageBox("Init COM Lib Fail!"); 
		exit (1);
	}

	VERIFY( 1 == InitSkinMagicLib( AfxGetInstanceHandle(), _T("ReadUI") ,NULL,NULL ) );
	VERIFY( 1 == LoadSkinFile("Skins\\corona.smf")); 
	VERIFY( 1 == SetDialogSkin( _T("Dialog") ) );

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	//初始化config文件
	this->m_Config.InitConfigPath();

	//读取config文件
	this->m_Config.ReadConfig();

	CString temp;
	CString csCFGPath;
	HINSTANCE hInstance;
	int iRet;
	
	//建立远程共享连接
	csCFGPath = this->m_Config.m_csCFGPath.Left(this->m_Config.m_csCFGPath.GetLength()-1);
	
	if (csCFGPath.Left(2) == "\\\\")
	{
		temp.Format("/c net use %s %s /user:%s", csCFGPath, this->m_Config.m_csLoginPSW, this->m_Config.m_csLoginName);
		hInstance = ShellExecute(AfxGetMainWnd()->GetSafeHwnd(),"open","cmd.exe",temp,NULL,SW_HIDE);
		iRet = int(hInstance);
		if (iRet < 32)
		{
			AfxMessageBox("Failure to establish a remote shared connection!", MB_OK,0);
			exit(0);
		}
	}
	
	//初始化ADO
	if(!((CCreateProductApp *)AfxGetApp())->InitADO())
	{
		return FALSE;
	}

	//连接生产数据库
	if(!this->ConnectMDBDatabase())
	{
		AfxMessageBox("Connect Server Fail", MB_OK,0);
		return FALSE;
	}

	//检查软件版本是否最新
	if (CheckToolVersion() != TRUE)
	{
		return FALSE;
	}	

	CMain Mdlg;
	Mdlg.DoModal();

	if (m_istatus == 3)    //订单设置修改
	{
		CPassword Pdlg;
		Pdlg.ilevel = 1;   //需超级权限验证
		if (Pdlg.DoModal() != IDOK)
		{
			return FALSE;
		}
		
		//加载dewav log
		CCommandLineInfo cmdInfo;
		ParseCommandLine(cmdInfo);
		CSplashWnd::EnableSplashScreen(cmdInfo.m_bShowSplash);
		
		CAlterSetting Odlg;
		if (Odlg.DoModal() != IDOK)
		{
			return FALSE;
		}
	}
	else if (m_istatus == 2)    //订单校对释放
	{
		CPassword Pdlg;
		Pdlg.ilevel = 1;   //需超级权限验证
		if (Pdlg.DoModal() != IDOK)
		{
			return FALSE;
		}

		//加载dewav log
		CCommandLineInfo cmdInfo;
		ParseCommandLine(cmdInfo);
		CSplashWnd::EnableSplashScreen(cmdInfo.m_bShowSplash);
		
		COrderRelease Odlg;
		if (Odlg.DoModal() != IDOK)
		{
			return FALSE;
		}
	}
	else if(m_istatus == 1) //订单创建
	{	
		CPassword Pdlg;
		Pdlg.ilevel = 0;   //需普通权限验证
		if (Pdlg.DoModal() != IDOK)
		{
			return FALSE;
		}   
		
		//加载dewav log  
		CCommandLineInfo cmdInfo;
		ParseCommandLine(cmdInfo);
		CSplashWnd::EnableSplashScreen(cmdInfo.m_bShowSplash);
		
		CCreateProductDlg dlg;
		m_pMainWnd = &dlg;
		int nResponse = dlg.DoModal();
		if (nResponse == IDOK)
		{
			// TODO: Place code here to handle when the dialog is
			//  dismissed with OK
		}
		else if (nResponse == IDCANCEL)
		{
			// TODO: Place code here to handle when the dialog is
			//  dismissed with Cancel
		}
	}
	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	CoUninitialize();
	return FALSE;
}

BOOL CCreateProductApp::InitADO()
{
	CoInitialize(NULL);
	HRESULT hrpC,hrpR;
	hrpC=m_pConnection.CreateInstance(__uuidof(Connection));
	hrpR=m_pRst.CreateInstance(__uuidof(Recordset)); 
	if(SUCCEEDED(hrpC) && SUCCEEDED(hrpR))
		return TRUE;
	return FALSE;
}

void CCreateProductApp::UninitADO()
{
	m_pRst.Release();
	m_pConnection.Release();
	CoUninitialize();
}

bool CCreateProductApp::ConnectMDBDatabase()
{	
	CString temp;
	_variant_t var;
	CString sql;
	sql.Format("driver={SQL Server};Server=%s;DATABASE=%s;UID=%s;PWD=%s",this->m_Config.m_csServer,this->m_Config.m_csDatabaseName,this->m_Config.m_csUserName,this->m_Config.m_csPassword);
	
	try
	{
			if(((CCreateProductApp *)AfxGetApp())->m_pConnection->State)
			((CCreateProductApp *)AfxGetApp())->m_pConnection->Close();
					((CCreateProductApp *)AfxGetApp())->m_pConnection->ConnectionTimeout=15;
		((CCreateProductApp *)AfxGetApp())->m_pConnection->Open((char*)(LPCTSTR)sql,"","",adModeUnknown);
	}
		catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}


BOOL CCreateProductApp::CheckToolVersion()
{

	CString     csVer;
	CString     strVersion ;
	CString     sql;
	_variant_t  var;
	TCHAR szFullPath[MAX_PATH];
	DWORD dwVerInfoSize = 0;
	DWORD dwVerHnd;
	VS_FIXEDFILEINFO * pFileInfo;

	//从数据库中获取最新软件版本
	try
	{
		sql.Format("select * from ToolVersionList where Enable = 1");
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
		((CCreateProductApp *)AfxGetApp())->m_pRst=((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

		if(!((CCreateProductApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CreateProductTool");
			csVer=var.bstrVal;
		}
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	
	//获取当前软件版本PRODUCTVERSION
	GetModuleFileName(NULL, szFullPath, sizeof(szFullPath));
    dwVerInfoSize = GetFileVersionInfoSize(szFullPath, &dwVerHnd);
    if (dwVerInfoSize)
    {
        HANDLE  hMem;
        LPVOID  lpvMem;
		unsigned int uInfoSize = 0;
		
        hMem = GlobalAlloc(GMEM_MOVEABLE, dwVerInfoSize);
        lpvMem = GlobalLock(hMem);
        GetFileVersionInfo(szFullPath, dwVerHnd, dwVerInfoSize, lpvMem);
		
		::VerQueryValue(lpvMem, (LPTSTR)_T("\\"), (void**)&pFileInfo, &uInfoSize);
		
		WORD m_nProdVersion[3];
		
		m_nProdVersion[0] = LOWORD(pFileInfo->dwProductVersionMS);
		m_nProdVersion[1] = HIWORD(pFileInfo->dwProductVersionLS);
		m_nProdVersion[2] = LOWORD(pFileInfo->dwProductVersionLS); 
		
		strVersion.Format(_T("%d.%d.%d"),m_nProdVersion[0],m_nProdVersion[1],m_nProdVersion[2]);
		
		GlobalUnlock(hMem);
        GlobalFree(hMem);
	}
	
	//版本对比
	if (strVersion != csVer.Right(5))
	{
		AfxMessageBox("该软件版本不是最新，请使用最新版本"+csVer+"!", MB_OK,0);
		return FALSE;
	}

	return TRUE;
}
