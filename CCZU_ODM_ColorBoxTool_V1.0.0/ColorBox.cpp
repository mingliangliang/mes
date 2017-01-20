// ColorBox.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ColorBox.h"
#include "Splash.h"
#include "MainFrm.h"
#include "ColorBoxDoc.h"
#include "ColorBoxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorBoxApp

BEGIN_MESSAGE_MAP(CColorBoxApp, CWinApp)
	//{{AFX_MSG_MAP(CColorBoxApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorBoxApp construction

CColorBoxApp::CColorBoxApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CColorBoxApp object

CColorBoxApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CColorBoxApp initialization

BOOL CColorBoxApp::InitInstance()
{
	AfxOleInit();
	AfxEnableControlContainer();

	//检查进程是否已经运行
	HANDLE dlgHandle = ::CreateMutex(NULL, FALSE, _T("DEWAV_ODM_ColorBoxTool.exe"));
	if(GetLastError() == ERROR_ALREADY_EXISTS)
	{
		AfxMessageBox("The application has been running!");
		CloseHandle(dlgHandle);
		exit(1);
	}

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	this->m_Config.InitConfigPath();

	this->m_Config.ReadConfig();
	
	if(!this->InitADO())
	{
		AfxMessageBox("Init ADO Fail!");
		return FALSE;
	}
	
	if(!this->ConnectMDBDatabase())
	{
		AfxMessageBox("ConnectMDBDatabase Fail!");
		return FALSE;
	}

	//检查软件版本是否最新
	if (CheckToolVersion() != TRUE)
	{
		return FALSE;
	}

	CLogin LoginDlg;
	if (LoginDlg.DoModal() == IDOK)
	{
		InputOrder = LoginDlg.m_csOrder;
		InputProductionLine = LoginDlg.m_csProductionLine;
		
		CSingleDocTemplate* pDocTemplate;
		pDocTemplate = new CSingleDocTemplate(
			IDR_MAINFRAME,
			RUNTIME_CLASS(CColorBoxDoc),
			RUNTIME_CLASS(CMainFrame),       // main SDI frame window
			RUNTIME_CLASS(CColorBoxView));
		AddDocTemplate(pDocTemplate);
		
		// Parse command line for standard shell commands, DDE, file open
		CCommandLineInfo cmdInfo;
		ParseCommandLine(cmdInfo);
		CSplashWnd::EnableSplashScreen(cmdInfo.m_bShowSplash);
		
		// Dispatch commands specified on the command line
		if (!ProcessShellCommand(cmdInfo))
			return FALSE;
		
		
		// The one and only window has been initialized, so show and update it.
		m_pMainWnd->SetWindowText("CCZU ODM MES System----Print Label Tool");
		m_pMainWnd->ShowWindow(SW_RESTORE);
		m_pMainWnd->UpdateWindow();
		
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CColorBoxApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CColorBoxApp message handlers

BOOL CColorBoxApp::InitADO()
{
	CoInitialize(NULL);	
	HRESULT hrpC,hrpR;
	hrpC=m_pConnection.CreateInstance(__uuidof(Connection));
	hrpR=m_pRst.CreateInstance(__uuidof(Recordset)); 
	if(SUCCEEDED(hrpC) && SUCCEEDED(hrpR))
		return TRUE;
	return FALSE;
}

void CColorBoxApp::UninitADO()
{
	m_pRst.Release();
	m_pConnection.Release();
	CoUninitialize();
}

bool CColorBoxApp::ConnectMDBDatabase()
{	
	CString temp;
	_variant_t var;
	CString sql;
	sql.Format("driver={SQL Server};Server=%s;DATABASE=%s;UID=%s;PWD=%s",this->m_Config.m_csServer,this->m_Config.m_csDatabaseName,this->m_Config.m_csUserName,this->m_Config.m_csPassword);
	
	try
	{
		if(m_pConnection->State)
			m_pConnection->Close();
		m_pConnection->ConnectionTimeout=15;
		m_pConnection->Open((char*)(LPCTSTR)sql,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}

BOOL CColorBoxApp::CheckToolVersion()
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
		if(m_pRst->State)
			m_pRst->Close();
		m_pRst=m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

		if(!m_pRst->adoEOF)
		{
			var = m_pRst->GetCollect("ColorBoxTool");
			csVer = (LPCTSTR)(_bstr_t)var;
		}
		if(m_pRst->State)
			m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//获取当前软件版本
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
		AfxMessageBox("The software version is not the latest, please use the latest version"+csVer+"!");
		return FALSE;
	}

	return TRUE;
}
