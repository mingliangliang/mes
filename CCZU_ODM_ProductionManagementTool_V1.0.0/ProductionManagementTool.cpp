// ProductionManagementTool.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ProductionManagementTool.h"
#include "ProductionManagementToolDlg.h"
#include "Splash.h"
#include "Login.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProductionManagementToolApp

BEGIN_MESSAGE_MAP(CProductionManagementToolApp, CWinApp)
	//{{AFX_MSG_MAP(CProductionManagementToolApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProductionManagementToolApp construction

CProductionManagementToolApp::CProductionManagementToolApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CProductionManagementToolApp object

CProductionManagementToolApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CProductionManagementToolApp initialization

BOOL CProductionManagementToolApp::InitInstance()
{
	AfxEnableControlContainer();

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

	CLogin pdlg;
	if(pdlg.DoModal()!=IDOK)
	{
		return FALSE;
	}
	 
	//º”‘ÿdewav log
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	CSplashWnd::EnableSplashScreen(cmdInfo.m_bShowSplash);

	CProductionManagementToolDlg dlg;
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

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}


BOOL CProductionManagementToolApp::InitADO()
{
	CoInitialize(NULL);	
	HRESULT hrpC,hrpR;
	hrpC=m_pConnection.CreateInstance(__uuidof(Connection));
	hrpR=m_pRst.CreateInstance(__uuidof(Recordset));
	if(SUCCEEDED(hrpC) && SUCCEEDED(hrpR))
		return TRUE;
	return FALSE;
}


void CProductionManagementToolApp::UninitADO()
{
	m_pRst.Release();
	m_pConnection.Release();
	CoUninitialize();
}
