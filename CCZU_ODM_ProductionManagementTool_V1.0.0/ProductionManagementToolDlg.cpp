// ProductionManagementToolDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ProductionManagementTool.h"
#include "ProductionManagementToolDlg.h"
#include "Splash.h"
#include "Password.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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

/////////////////////////////////////////////////////////////////////////////
// CProductionManagementToolDlg dialog

CProductionManagementToolDlg::CProductionManagementToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProductionManagementToolDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProductionManagementToolDlg)
	m_csMachine = _T("");
	m_csDatabase = _T("");
	m_csOrder = _T("");
	m_csProduct = _T("");
	m_csCartonWeigh = _T("");
	m_csCheckIMEIS1 = _T("");
	m_csCheckIMEIS2 = _T("");
	m_csCheckOrder = _T("");
	m_csColorBox = _T("");
	m_csColorBoxWeigh = _T("");
	m_csCreateProduct = _T("");
	m_csPack = _T("");
	m_csPallet = _T("");
	m_csWriteTool = _T("");
	m_csSqlPsw = _T("");
	m_csSqlUser = _T("");
	m_csProductionDataQuery = _T("");
	m_csLoginName = _T("");
	m_csLoginPSW = _T("");
	m_csSNScan = _T("");
	m_csRework = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProductionManagementToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProductionManagementToolDlg)
	DDX_Control(pDX, IDC_EDIT_REWORK, m_ctrRework);
	DDX_Control(pDX, IDC_EDIT_SNSCAN, m_ctrSNScan);
	DDX_Control(pDX, IDC_EDIT_LOGINPSW, m_ctrLoginPSW);
	DDX_Control(pDX, IDC_EDIT_LOGINNAME, m_ctrLoginName);
	DDX_Control(pDX, IDC_EDIT_PRODUCTIONDATAQUERY, m_ctrProductionDataQuery);
	DDX_Control(pDX, IDC_EDIT_SQLUSER, m_ctrSqlUser);
	DDX_Control(pDX, IDC_EDIT_SQLPSW, m_ctrSqlPsw);
	DDX_Control(pDX, IDC_EDIT_WRITETOOL, m_ctrWriteTool);
	DDX_Control(pDX, IDC_EDIT_PALLET, m_ctrPallet);
	DDX_Control(pDX, IDC_EDIT_PACK, m_ctrPack);
	DDX_Control(pDX, IDC_EDIT_CREATEPRODUCT, m_ctrCreateProduct);
	DDX_Control(pDX, IDC_EDIT_COLORBOXWEIGH, m_ctrColorBoxWeigh);
	DDX_Control(pDX, IDC_EDIT_COLORBOX, m_ctrColorBox);
	DDX_Control(pDX, IDC_EDIT_CHECKORDER, m_ctrCheckOrder);
	DDX_Control(pDX, IDC_EDIT_CHECKIMEIS2, m_ctrCheckIMEIS2);
	DDX_Control(pDX, IDC_EDIT_CHECKIMEIS1, m_ctrCheckIMEIS1);
	DDX_Control(pDX, IDC_EDIT_CARTONWEIGH, m_ctrCartonWeigh);
	DDX_Control(pDX, IDC_EDIT_PRODUCT, m_ctrProduct);
	DDX_Control(pDX, IDC_EDIT_ORDER, m_ctrOrder);
	DDX_Control(pDX, IDC_EDIT_DATABASE, m_ctrDatabase);
	DDX_Control(pDX, IDC_EDIT_MACHINE, m_ctrMachine);
	DDX_Text(pDX, IDC_EDIT_MACHINE, m_csMachine);
	DDX_Text(pDX, IDC_EDIT_DATABASE, m_csDatabase);
	DDX_Text(pDX, IDC_EDIT_ORDER, m_csOrder);
	DDX_Text(pDX, IDC_EDIT_PRODUCT, m_csProduct);
	DDX_Text(pDX, IDC_EDIT_CARTONWEIGH, m_csCartonWeigh);
	DDX_Text(pDX, IDC_EDIT_CHECKIMEIS1, m_csCheckIMEIS1);
	DDX_Text(pDX, IDC_EDIT_CHECKIMEIS2, m_csCheckIMEIS2);
	DDX_Text(pDX, IDC_EDIT_CHECKORDER, m_csCheckOrder);
	DDX_Text(pDX, IDC_EDIT_COLORBOX, m_csColorBox);
	DDX_Text(pDX, IDC_EDIT_COLORBOXWEIGH, m_csColorBoxWeigh);
	DDX_Text(pDX, IDC_EDIT_CREATEPRODUCT, m_csCreateProduct);
	DDX_Text(pDX, IDC_EDIT_PACK, m_csPack);
	DDX_Text(pDX, IDC_EDIT_PALLET, m_csPallet);
	DDX_Text(pDX, IDC_EDIT_WRITETOOL, m_csWriteTool);
	DDX_Text(pDX, IDC_EDIT_SQLPSW, m_csSqlPsw);
	DDX_Text(pDX, IDC_EDIT_SQLUSER, m_csSqlUser);
	DDX_Text(pDX, IDC_EDIT_PRODUCTIONDATAQUERY, m_csProductionDataQuery);
	DDX_Text(pDX, IDC_EDIT_LOGINNAME, m_csLoginName);
	DDX_Text(pDX, IDC_EDIT_LOGINPSW, m_csLoginPSW);
	DDX_Text(pDX, IDC_EDIT_SNSCAN, m_csSNScan);
	DDX_Text(pDX, IDC_EDIT_REWORK, m_csRework);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CProductionManagementToolDlg, CDialog)
	//{{AFX_MSG_MAP(CProductionManagementToolDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CREATE_ORDER, OnCreateOrder)
	ON_BN_CLICKED(IDC_ADDUSER, OnAdduser)
	ON_BN_CLICKED(IDC_DELETEUSER, OnDeleteuser)
	ON_BN_CLICKED(IDC_CHANGEPASSWORD, OnChangepassword)
	ON_BN_CLICKED(IDC_TOOLVERSION, OnToolversion)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_SQL, OnSql)
	ON_BN_CLICKED(IDC_CHANGESQLPASSWORD, OnChangesqlpassword)
	ON_BN_CLICKED(IDC_CONNECTSQL, OnConnectsql)
	ON_BN_CLICKED(IDC_ALTERSETTING, OnAltersetting)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProductionManagementToolDlg message handlers

BOOL CProductionManagementToolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	SCROLLINFO vinfo1,vinfo2;

	//垂直滚动条
	vinfo1.cbSize=sizeof(vinfo1);
	vinfo1.fMask=SIF_ALL;
	vinfo1.nPage=50;//滚动块自身的长短，通常有如下关系：其长度/滚动条长度（含两个箭头）=nPage/(nMax+2)，  
	//另外nPage取值-1时，滚动条会不见了。  
	vinfo1.nMax=150;//滚动条所能滚动的最大值  
	vinfo1.nMin=0;//滚动条所能滚动的最小值
	vinfo1.nPos = 0;
	SetScrollInfo(SB_VERT,&vinfo1);//即使上述步骤一不做，使用此条语句也可以显示滚动条
/*
	//水平滚动条
	vinfo2.cbSize=sizeof(vinfo2);
	vinfo2.fMask=SIF_ALL;
	vinfo2.nPage=1000;//滚动块自身的长短，通常有如下关系：其长度/滚动条长度（含两个箭头）=nPage/(nMax+2)，  
	//另外nPage取值-1时，滚动条会不见了。  
	vinfo2.nMax=1500;//滚动条所能滚动的最大值  
	vinfo2.nMin=0;//滚动条所能滚动的最小值
	vinfo2.nPos = 0;
	SetScrollInfo(SB_HORZ,&vinfo2);//即使上述步骤一不做，使用此条语句也可以显示滚动条
*/

	//读取config.ini
	m_Config.InitConfigPath();
	m_Config.ReadConfig();

	this->m_csMachine = this->m_Config.m_csServer;
	this->m_csDatabase = this->m_Config.m_csDatabaseName;
	this->m_csSqlUser = this->m_Config.m_csUserName;
	this->m_csSqlPsw = this->m_Config.m_csPassword;
	this->m_csLoginName = this->m_Config.m_csLoginName;
	this->m_csLoginPSW = this->m_Config.m_csLoginPSW;


	UpdateData(FALSE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProductionManagementToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CProductionManagementToolDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProductionManagementToolDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}




void CProductionManagementToolDlg::OnCreateOrder()
{
	UpdateData();
	
	//检测项目名称、订单号不能为空
	if(this->m_csProduct.IsEmpty() || this->m_csOrder.IsEmpty())
	{
		MessageBox("项目名称或订单号不能为空!","Error",MB_OK);
		return;
	}

	//检测名称是否为A-Z、a-z、0-9、_
	if(!CheckProductName(0) || !CheckOrderName(0))
	{
		MessageBox("非法项目名称或订单名称，名称只能包含\'A-Z\'、 \'a-z\'、\'0-9\' 、\'_\'!","Error",MB_OK);
		return;
	}

	//检测SQL productList 内是否有重复产品
	if(!CheckSQLRepeat(0))
	{
		MessageBox("检测数据库中是否有重复项目订单失败!","Error",MB_OK);
		return;
	}

	//录入项目订单
	if(!InputProductOrder(0))
	{
		MessageBox("录入项目订单失败!","Error",MB_OK);
		return;
	}
	else
	{
		MessageBox("录入项目订单成功!","OK",MB_OK);
	}
}


void CProductionManagementToolDlg::OnAltersetting() 
{
	UpdateData();

	CAlterSetting dlg;
	dlg.m_bCheckPCBA = 0;
	if(dlg.DoModal()!=IDOK)
	{
		return;
	}
}


void CProductionManagementToolDlg::OnToolversion()
{
	UpdateData();

	//检测工具版本不能为空
	if(this->m_csCreateProduct.IsEmpty() || this->m_csWriteTool.IsEmpty() || this->m_csCheckIMEIS1.IsEmpty() \
		|| this->m_csColorBox.IsEmpty() || this->m_csCheckIMEIS2.IsEmpty() || this->m_csColorBoxWeigh.IsEmpty() \
		|| this->m_csPack.IsEmpty() || this->m_csCartonWeigh.IsEmpty() || this->m_csPallet.IsEmpty() || this->m_csRework.IsEmpty()\
		|| this->m_csCheckOrder.IsEmpty() || this->m_csProductionDataQuery.IsEmpty() || m_csSNScan.IsEmpty())
	{
		MessageBox("工具版本不能为空!","Error",MB_OK);
		return;
	}

	//录入MES工具版本
	if(!InputToolVersion())
	{
		MessageBox("录入MES工具版本失败!","Error",MB_OK);
		return;
	}
	else
	{
		MessageBox("录入MES工具版本成功!","OK",MB_OK);
	}
}


void CProductionManagementToolDlg::OnAdduser() 
{
	CAddUserDlg dlg;
	if(dlg.DoModal()!=IDOK)
	{
		return;
	}
}


void CProductionManagementToolDlg::OnDeleteuser() 
{
	CDeleteUserDlg dlg;
	if(dlg.DoModal()!=IDOK)
	{
		return;
	}
}


void CProductionManagementToolDlg::OnChangepassword() 
{
	CChangePasswordDlg dlg;
	if(dlg.DoModal()!=IDOK)
	{
		return;
	}
}


BOOL CProductionManagementToolDlg::CheckProductName(int iflag) 
{
	char   ch;
	BOOL   bHz=FALSE;
	CString csProduct;

	csProduct = m_csProduct;
	
	for(int i=0;i<csProduct.GetLength();i++)   
	{   
		ch=csProduct.GetAt(i);   
		if(ch>=48 && ch<=57)
		{    
			continue;   
		}
		else
		{
			if(ch>=65 && ch<=90)
			{
				continue;
			}
			else
			{
				if(ch>=97 && ch<=122)
				{
					continue;
				}
				else
				{
					if(ch=='_')
					{
						continue;
					}
					else
					{
						bHz=TRUE;
						break;
					}
				}
			}
		}
	}
	
	if(!bHz)   
		return TRUE;
	else   
		return FALSE;
}


BOOL CProductionManagementToolDlg::CheckOrderName(int iflag) 
{
	char   ch;   
	BOOL   bHz=FALSE;   
	CString csOrder;

	csOrder = m_csOrder;

	for(int i=0;i<csOrder.GetLength();i++)   
	{   
		ch=csOrder.GetAt(i);   
		if(ch>=48 && ch<=57)    
		{    
			continue;
		}
		else
		{
			if(ch>=65 && ch<=90)
			{
				continue;
			}
			else
			{
				if(ch>=97 && ch<=122)
				{
					continue;
				}
				else
				{
					if(ch=='_')
					{
						continue;
					}
					else
					{
						bHz=TRUE;
						break;
					}
				}
			}
		}
	}
	
	if(!bHz)   
		return TRUE;
	else
		return FALSE;
}


BOOL CProductionManagementToolDlg::CheckSQLRepeat(int iflag)
{
	CString temp;
	_variant_t var;
	CString sql;

	sql.Format("select * from ProductList where OrderName='%s'",m_csOrder);

	//检查项目订单是否在ProductList内重复
	try
	{	
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		((CProductionManagementToolApp *)AfxGetApp())->m_pRst=((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CProductionManagementToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			return FALSE;
		}
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	
	return TRUE;
}


BOOL CProductionManagementToolDlg::InputProductOrder(int iflag)
{
	CString temp;
	_variant_t var;
	CString sql;

	sql.Format("INSERT INTO ProductList (ProductName, OrderName, Enable) VALUES ('%s','%s',%d)",m_csProduct,m_csOrder,2);

	try
	{
		((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}


BOOL CProductionManagementToolDlg::GetToolVersion()
{
	CString temp;
	_variant_t var;
	CString sql;

	try
	{
		sql.Format("select * from ToolVersionList where Enable=1");
		
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		((CProductionManagementToolApp *)AfxGetApp())->m_pRst=((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	
		if(!((CProductionManagementToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("CreateProductTool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csCreateProduct= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("SNScanTool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csSNScan= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("WriteIMEITool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csWriteTool= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("CheckIMEIS1Tool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csCheckIMEIS1= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("ColorBoxTool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csColorBox= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("CheckIMEIS2Tool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csCheckIMEIS2= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("ColorBoxWeighTool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csColorBoxWeigh= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("CartonBoxTool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csPack= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("CartonBoxWeighTool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csCartonWeigh= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("PalletTool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csPallet= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("CheckOrderTool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csCheckOrder= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("ProductionDataQueryTool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csProductionDataQuery= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("ReworkTool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csRework= temp;
		}
		
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		CString sErr = "从ToolVersionList表获取版本信息失败，原因:" + (CString)((LPCTSTR)e.Description());
		MessageBox(sErr, "错误");
		return FALSE;
	}

	return TRUE;
}


BOOL CProductionManagementToolDlg::InputToolVersion()
{
	CString temp;
	_variant_t var;
	CString sql;

	sql.Format("UPDATE ToolVersionList SET CreateProductTool='%s', SNScanTool='%s', WriteIMEITool='%s', \
		CheckIMEIS1Tool='%s', ColorBoxTool='%s', CheckIMEIS2Tool='%s', ColorBoxWeighTool='%s', \
		CartonBoxTool='%s', CartonBoxWeighTool='%s', PalletTool='%s', CheckOrderTool='%s', \
		ProductionDataQueryTool='%s',ReworkTool='%s' \
		WHERE Enable=1",m_csCreateProduct,m_csSNScan,m_csWriteTool,m_csCheckIMEIS1,m_csColorBox,m_csCheckIMEIS2,\
		m_csColorBoxWeigh,m_csPack,m_csCartonWeigh,m_csPallet,m_csCheckOrder,m_csProductionDataQuery,m_csRework);
 
	try
	{
		((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}

int CProductionManagementToolDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	CSplashWnd::ShowSplashScreen(this);

	return 0;
}

void CProductionManagementToolDlg::OnSql() 
{
	UpdateData();
	this->m_Config.m_csServer         = this->m_csMachine;
	this->m_Config.m_csDatabaseName   = this->m_csDatabase;
	this->m_Config.m_csUserName       = this->m_csSqlUser;
	this->m_Config.m_csPassword       = this->m_csSqlPsw;
	this->m_Config.m_csLoginName      = this->m_csLoginName;
	this->m_Config.m_csLoginPSW       = this->m_csLoginPSW;
	this->m_Config.SaveConfig();
		
	MessageBox("修改Config中数据库信息成功!",MB_OK);
}


BOOL CProductionManagementToolDlg::ConnectMDBDatabase()
{
	CString temp;
	_variant_t var;
	CString sql;
	sql.Format("driver={SQL Server};Server=%s;DATABASE=%s;UID=%s;PWD=%s",this->m_Config.m_csServer,this->m_Config.m_csDatabaseName,this->m_Config.m_csUserName,this->m_Config.m_csPassword);
	
	try
	{
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Close();
		((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->ConnectionTimeout=15;
		((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Open((char*)(LPCTSTR)sql,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	return TRUE;
}

void CProductionManagementToolDlg::OnChangesqlpassword()
{
	CString temp;
	_variant_t var;
	CString sql;

	UpdateData();

	sql.Format("EXEC sp_password '%s','%s'",this->m_Config.m_csPassword,this->m_csSqlPsw);
	
	try
	{
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		((CProductionManagementToolApp *)AfxGetApp())->m_pRst = ((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		MessageBox("更改数据库密码成功!",MB_OK);
	}
	catch(_com_error e)
	{
		MessageBox("更改数据库密码失败!","Error",MB_OK);
		return;
	}
}

void CProductionManagementToolDlg::OnConnectsql()
{

	CPassword dlg;
	dlg.ilevel = 1;   //需超级权限验证

	//初始化AOD
	if(!((CProductionManagementToolApp *)AfxGetApp())->InitADO())
	{
		MessageBox("初始化ADO失败","Error",MB_OK);
		return;
	}
	        
	//连接数据库
	if(!ConnectMDBDatabase())
	{
		MessageBox("连接数据库失败","Error",MB_OK);
		return;
	}

	if(dlg.DoModal()!=IDOK)
	{
		((CProductionManagementToolApp *)AfxGetApp())->UninitADO();
		return;
	}
	
	if(!GetToolVersion())
	{
		MessageBox("获取MES工具版本失败","Error",MB_OK);
		exit(0);
	}

	UpdateData(FALSE);
}


void CProductionManagementToolDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	
	SCROLLINFO vinfo;
	GetScrollInfo(SB_HORZ,&vinfo,SIF_ALL);
	
	switch (nSBCode)  
	{  
	case SB_THUMBTRACK://拖动滚动条  
		ScrollWindow(-(nPos-vinfo.nPos),0);
		SetScrollPos(SB_HORZ,nPos);  
		break;  
	case SB_LINELEFT://单击左箭头
		if(vinfo.nPos!=0)
		{
			ScrollWindow(1,0);
			SetScrollPos(SB_HORZ,vinfo.nPos-1);
		}
		break;  
	case SB_LINERIGHT: //单击右箭头 
		if(vinfo.nPos+vinfo.nPage<=vinfo.nMax)
		{
			SetScrollPos(SB_HORZ,vinfo.nPos+1);
			ScrollWindow(-1,0);
		}
		break;  
	case SB_PAGELEFT:  //在滚动条左方空白滚动区域单击 
		if (vinfo.nPos>=vinfo.nPage)
		{
			ScrollWindow(vinfo.nPage,0);
			SetScrollPos(SB_HORZ,vinfo.nPos-vinfo.nPage);
		}  
		else
		{
			ScrollWindow(vinfo.nPos,0);
			SetScrollPos(SB_HORZ,vinfo.nPos-vinfo.nPage);
		}
		break;  
	case SB_PAGERIGHT: //在滚动条右方空白滚动区域单击 
		if (vinfo.nPos+vinfo.nPage<=vinfo.nMax-vinfo.nPage)  
		{  
			ScrollWindow(-vinfo.nPage,0);
			SetScrollPos(SB_HORZ,vinfo.nPos+vinfo.nPage);
		}  
		else
		{
			ScrollWindow(-(vinfo.nMax-(vinfo.nPos+vinfo.nPage)),0);
			SetScrollPos(SB_HORZ,vinfo.nMax-vinfo.nPage);
		}  
		break;
	}
	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CProductionManagementToolDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	
	SCROLLINFO scrollinfo;  
	GetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);  
	
	switch (nSBCode)
	{  
	case SB_BOTTOM: //滑块滚动到最底部  
		ScrollWindow(0,(scrollinfo.nPos-scrollinfo.nMax)*10); //滚动屏幕  
		scrollinfo.nPos = scrollinfo.nMax; //设定滑块新位置  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL); //更新滑块位置  
		break;  
	case SB_TOP: //滑块滚动到最顶部
		ScrollWindow(0,(scrollinfo.nPos-scrollinfo.nMin)*10);  
		scrollinfo.nPos = scrollinfo.nMin;  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);
		break;  
	case SB_LINEUP: //单击上箭头  
		scrollinfo.nPos -= 1;  
		if (scrollinfo.nPos<scrollinfo.nMin)  
		{  
			scrollinfo.nPos = scrollinfo.nMin;  
			break;  
		}  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);  
		ScrollWindow(0,10);  
		break;  
	case SB_LINEDOWN: //单击下箭头  
		scrollinfo.nPos += 1;  
		if (scrollinfo.nPos>scrollinfo.nMax)  
		{  
			scrollinfo.nPos = scrollinfo.nMax;  
			break;  
		}  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);
		ScrollWindow(0,-10);  
		break;  
	case SB_PAGEUP: //单击滑块上方空白区域  
		scrollinfo.nPos -= 5;  
		if (scrollinfo.nPos<scrollinfo.nMin)  
		{  
			scrollinfo.nPos = scrollinfo.nMin;  
			break;  
		}  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);
		ScrollWindow(0,10*5);
		break;
	case SB_PAGEDOWN: //单击滑块下方空白区域  
		scrollinfo.nPos += 5;  
		if (scrollinfo.nPos>scrollinfo.nMax)  
		{  
			scrollinfo.nPos = scrollinfo.nMax;  
			break;  
		}  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);  
		ScrollWindow(0,-10*5);  
		break;  
	case SB_ENDSCROLL: //鼠标离开滑块，结束滑块拖动  
		// MessageBox("SB_ENDSCROLL");  
		break;  
	case SB_THUMBPOSITION:  
		// ScrollWindow(0,(scrollinfo.nPos-nPos)*10);  
		// scrollinfo.nPos = nPos;  
		// SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);  
		break;  
	case SB_THUMBTRACK: //拖动滑块  
		ScrollWindow(0,(scrollinfo.nPos-nPos)*10);  
		scrollinfo.nPos = nPos;  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);  
		break;  
	}

	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}
