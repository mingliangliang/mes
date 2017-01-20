// ColorBoxView.cpp : implementation of the CColorBoxView class
//

#include "stdafx.h"
#include "ColorBox.h"
#include "Splash.h"
#include "ColorBoxDoc.h"
#include "ColorBoxView.h"
#include <math.h>

#include "mmsystem.h"//导入声音头文件
#pragma comment(lib,"winmm.lib")//导入声音头文件库


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define MAIN_SOURCE     0
#define SUB_SOURCE      1

/////////////////////////////////////////////////////////////////////////////
// CColorBoxView

IMPLEMENT_DYNCREATE(CColorBoxView, CFormView)

BEGIN_MESSAGE_MAP(CColorBoxView, CFormView)
	//{{AFX_MSG_MAP(CColorBoxView)
	ON_WM_TIMER()
	ON_EN_CHANGE(IDC_EDIT_IMEI1, OnChangeEditImei1)
	ON_EN_CHANGE(IDC_EDIT_IMEI2, OnChangeEditImei2)
	ON_EN_CHANGE(IDC_EDIT_IMEI3, OnChangeEditImei3)
	ON_EN_CHANGE(IDC_EDIT_IMEI4, OnChangeEditImei4)
	ON_WM_CREATE()
	ON_COMMAND(IDM_PRINT_1, OnPrint1)
	ON_COMMAND(IDM_PRINT_2, OnPrint2)
	ON_COMMAND(IDM_PRINT_3, OnPrint3)
	ON_COMMAND(IDM_PRINT_4, OnPrint4)
	ON_COMMAND(IDM_PRINT_5, OnPrint5)
	ON_COMMAND(IDM_SCAN_MAIN_IMEI_YES, OnScanMainImeiYes)
	ON_COMMAND(IDM_SCAN_MAIN_IMEI_NO, OnScanMainImeiNo)
	ON_BN_CLICKED(IDC_SETTING, OnSetting)
	ON_EN_CHANGE(IDC_EDIT_COLORBOXCODE, OnChangeEditColorboxcode)
	ON_EN_CHANGE(IDC_EDIT_NETCODE, OnChangeEditNetcode)
	ON_BN_CLICKED(IDC_CHECK_PSN_STATIC, OnCheckPsnStatic)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_UPDATEDATA,OnUpdateData)
	ON_MESSAGE(WM_SETMYFOCUS,OnSetMyFocus)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorBoxView construction/destruction

CColorBoxView::CColorBoxView()
	: CFormView(CColorBoxView::IDD)
{
	//{{AFX_DATA_INIT(CColorBoxView)
	m_csIMEI1 = _T("");
	m_csIMEI2 = _T("");
	m_csIMEI3 = _T("");
	m_csIMEI4 = _T("");
	m_csBT = _T("");
	m_csMAC = _T("");
	m_csPSN = _T("");
	m_csSN = _T("");
	m_csCurrentProduct = _T("");
	m_csCurrentColor = _T("");
	m_csCurrentOrder = _T("");
	m_csCurrentLine = _T("");
	m_csColorBoxCode = _T("");
	m_csNet = _T("");
	m_iRadioMainSource = 0;
	m_bPSNStatic = FALSE;
	//}}AFX_DATA_INIT
	m_PrintNum=1;
	m_bScanNetCode=0;
	m_bCheckColorBoxCode=0;
}

CColorBoxView::~CColorBoxView()
{
}

void CColorBoxView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CColorBoxView)
	DDX_Control(pDX, IDC_CHECK_PSN_STATIC, m_ctrPSNStatic);
	DDX_Control(pDX, IDC_EDIT_NETCODE, m_ctrNet);
	DDX_Control(pDX, IDC_EDIT_COLORBOXCODE, m_ctrColorBoxCode);
	DDX_Control(pDX, IDC_STATIC_CURRENT_LINE, m_ctrCurrentLine);
	DDX_Control(pDX, IDC_STATIC_CURRENT_COUNT, m_cCurrentCount);
	DDX_Control(pDX, IDC_STATIC_CURRENT_ORDER, m_ctrCurrentOrder);
	DDX_Control(pDX, IDC_STATIC_CURRENT_COLOR, m_ctrCurrentColor);
	DDX_Control(pDX, IDC_EDIT_SN, m_ctrSN);
	DDX_Control(pDX, IDC_EDIT_PSN, m_ctrPSN);
	DDX_Control(pDX, IDC_EDIT_MAC, m_ctrMAC);
	DDX_Control(pDX, IDC_EDIT_BT, m_ctrBT);
	DDX_Control(pDX, IDC_EDIT_IMEI4, m_ctrIMEI4);
	DDX_Control(pDX, IDC_EDIT_IMEI3, m_ctrIMEI3);
	DDX_Control(pDX, IDC_EDIT_IMEI2, m_ctrIMEI2);
	DDX_Control(pDX, IDC_EDIT_IMEI1, m_ctrIMEI1);
	DDX_Control(pDX, IDC_LIST_STATE, m_state_list);
	DDX_Control(pDX, IDC_STATIC_CURRENT_PRODUCT, m_ctrCurrentProduct);
	DDX_Text(pDX, IDC_EDIT_IMEI1, m_csIMEI1);
	DDX_Text(pDX, IDC_EDIT_IMEI2, m_csIMEI2);
	DDX_Text(pDX, IDC_EDIT_IMEI3, m_csIMEI3);
	DDX_Text(pDX, IDC_EDIT_IMEI4, m_csIMEI4);
	DDX_Text(pDX, IDC_EDIT_BT, m_csBT);
	DDX_Text(pDX, IDC_EDIT_MAC, m_csMAC);
	DDX_Text(pDX, IDC_EDIT_PSN, m_csPSN);
	DDX_Text(pDX, IDC_EDIT_SN, m_csSN);
	DDX_Text(pDX, IDC_STATIC_CURRENT_PRODUCT, m_csCurrentProduct);
	DDX_Text(pDX, IDC_STATIC_CURRENT_COLOR, m_csCurrentColor);
	DDX_Text(pDX, IDC_STATIC_CURRENT_ORDER, m_csCurrentOrder);
	DDX_Text(pDX, IDC_STATIC_CURRENT_LINE, m_csCurrentLine);
	DDX_Text(pDX, IDC_EDIT_COLORBOXCODE, m_csColorBoxCode);
	DDX_Text(pDX, IDC_EDIT_NETCODE, m_csNet);
	DDX_Radio(pDX, IDC_RADIO_MAIN_SOURCE, m_iRadioMainSource);
	DDX_Check(pDX, IDC_CHECK_PSN_STATIC, m_bPSNStatic);
	//}}AFX_DATA_MAP
}

BOOL CColorBoxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CColorBoxView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();


	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	CreateTwoFile();

	this->SetMyFont();

	this->m_Config.InitConfigPath();
	
	this->m_Config.ReadConfig();
	
	m_csCurrentOrder = ((CColorBoxApp *)AfxGetApp())->InputOrder;
	m_csCurrentLine  = ((CColorBoxApp *)AfxGetApp())->InputProductionLine;
	
	if(!this->GetProductOrderInfo())
	{
		//警告提示音
		PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);  
		InsertListInfo("Access to project orders information failure...",2);
		return;
	}
	else
	{
		UpdateData(FALSE);
		InsertListInfo("Access to project orders information Pass...",0);
	}
	
	if(!this->Load_Current_Product_Count())
	{
		//警告提示音
		PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);
		InsertListInfo("To obtain the number of current orders has failed",2);
		return;
	}
	InsertListInfo("Obtain the number of current orders has been successful",0);
	this->UpdateCount(this->m_csCurrentCount);
	
	//设置CONFIG.INI路径
	this->m_csConfigPath.Format("%s%s_%s",this->m_Config.m_csCFGPath,m_csCurrentProduct,this->m_csCurrentOrder);
	
	//建立远程共享连接
	CString csCFGPath;
	HINSTANCE hInstance;
	CString temp;
	int iRet;
	char direc[MAX_PATH];
	
	csCFGPath = this->m_Config.m_csCFGPath.Left(this->m_Config.m_csCFGPath.GetLength()-1);
	
	if (csCFGPath.Left(2) == "\\\\")
	{
		temp.Format("/c net use %s %s /user:%s", csCFGPath, this->m_Config.m_csLoginPSW, this->m_Config.m_csLoginName);
		hInstance = ShellExecute(AfxGetMainWnd()->GetSafeHwnd(),"open","cmd.exe",temp,NULL,SW_HIDE);
		iRet = int(hInstance);
		if (iRet < 32)
		{
			MessageBox("Establish remote shared connection failure!","Error",MB_OK);
			exit(0);
		}
	}
	
	//获取当前文件路径
	GetCurrentDirectory(MAX_PATH,direc);
	m_csLocalPath = CString(direc);
	
	//删除本地ColorResource.txt文件
	DeleteFile(m_csLocalPath+"\\ColorResource.txt");
	DeleteFile(m_csLocalPath+"\\ColorResource_Sub.txt");
	
	//获取服务器打印模板文件存放路径
	csCFGPath = this->m_Config.m_csCFGPath+m_csCurrentProduct+"_"+m_csCurrentOrder+"\\config\\ColorResource.txt";

	//从服务器copy ColorResource.txt文件至本地
	temp.Format("/c xcopy %s %s /e /i /y", csCFGPath, m_csLocalPath);
	hInstance = ShellExecute(AfxGetMainWnd()->GetSafeHwnd(),"open","cmd.exe",temp,NULL,SW_HIDE);
	iRet = int(hInstance);
	if (iRet < 32)
	{
		MessageBox("Copy ColorResource.txt Fail!","Error",MB_OK);
		exit(0);
	}

	//获取服务器打印模板文件存放路径
	csCFGPath = this->m_Config.m_csCFGPath+m_csCurrentProduct+"_"+m_csCurrentOrder+"\\config\\ColorResource_Sub.txt";
	
	//从服务器copy ColorResource_Sub.txt文件至本地
	temp.Format("/c xcopy %s %s /e /i /y", csCFGPath, m_csLocalPath);
	hInstance = ShellExecute(AfxGetMainWnd()->GetSafeHwnd(),"open","cmd.exe",temp,NULL,SW_HIDE);
	iRet = int(hInstance);
	if (iRet < 32)
	{
		MessageBox("Copy ColorResource_Sub.txt Fail!","Error",MB_OK);
		exit(0);
	}
	
	this->SetTimer(1,500,0);
}

/////////////////////////////////////////////////////////////////////////////
// CColorBoxView diagnostics

#ifdef _DEBUG
void CColorBoxView::AssertValid() const
{
	CFormView::AssertValid();
}

void CColorBoxView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CColorBoxDoc* CColorBoxView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CColorBoxDoc)));
	return (CColorBoxDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CColorBoxView message handlers
void CColorBoxView::SetMyFont()
{
	//===============set imagelist=====================================
	
	HICON hIcon[3];
	hIcon[0]=AfxGetApp()->LoadIcon(IDI_PASS);
	hIcon[1]=AfxGetApp()->LoadIcon(IDI_ERRORS);
	hIcon[2]=AfxGetApp()->LoadIcon(IDI_STOP);
	if(m_imageList.m_hImageList!=NULL)
		m_imageList.DeleteImageList();
	m_imageList.Create(16,16,ILC_COLOR32,3,3);
	m_imageList.SetBkColor(RGB(255,255,255));
	m_imageList.Add(hIcon[0]);
	m_imageList.Add(hIcon[1]);
	m_imageList.Add(hIcon[2]);	

	//==========init state list=====================================
    DWORD dwStyle;
	LVCOLUMN   Column;	
	
	m_state_list.SetImageList(&m_imageList,LVSIL_SMALL);
	dwStyle = m_state_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl）
	//dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl）
	//dwStyle |= LVS_EX_CHECKBOXES;//item前生成checkbox控件
	m_state_list.SetExtendedStyle(dwStyle); //设置扩展风格

	//((CWnd*)GetDlgItem(IDC_LIST_STATE))->SetFont(&m_sysfont);
	Column.mask =   LVCF_TEXT|LVCF_FMT|LVCF_WIDTH;
	Column.cchTextMax =   30;   
	Column.cx =   170;     //column宽度，不工作！   
	Column.fmt =   LVCFMT_LEFT;     //不工作   
	Column.iImage =   0;     
	Column.iOrder =   0;     //不明白干什么用   
	Column.iSubItem =   8;        
	Column.pszText =   "Time";   
	m_state_list.InsertColumn(0,&Column);
	Column.pszText =   "Status"; 
	Column.cx =   280;
	m_state_list.InsertColumn(1,&Column);

	this->m_ctrCurrentProduct.SetFontSize(18);
	this->m_ctrCurrentProduct.SetFontName("Arial");
	this->m_ctrCurrentProduct.SetTextColor(RGB(0,0,255));

	this->m_ctrCurrentOrder.SetFontSize(18);
	this->m_ctrCurrentOrder.SetFontName("Bold");
	this->m_ctrCurrentOrder.SetTextColor(RGB(0,0,255));

	this->m_ctrCurrentColor.SetFontSize(18);
	this->m_ctrCurrentColor.SetFontName("Bold");
	this->m_ctrCurrentColor.SetTextColor(RGB(0,0,255));

	this->m_ctrCurrentLine.SetFontSize(18);
	this->m_ctrCurrentLine.SetFontName("Bold");
	this->m_ctrCurrentLine.SetTextColor(RGB(0,0,255));

	this->m_cCurrentCount.SetFontSize(30);
	this->m_cCurrentCount.SetFontName("Arial");
	this->m_cCurrentCount.SetTextColor(RGB(0,0,255));
	
	VERIFY(m_staticfont.CreateFont(
		26,                        // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_NORMAL,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		"Arial"));                 // lpszFacename

	((CWnd*)GetDlgItem(IDC_STATIC_IMEI1))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_STATIC_IMEI2))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_STATIC_IMEI3))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_STATIC_IMEI4))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_STATIC_IMEI5))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_STATIC_IMEI6))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_STATIC_IMEI7))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_STATIC_IMEI8))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_STATIC_IMEI9))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_STATIC_IMEI10))->SetFont(&m_staticfont);

	((CWnd*)GetDlgItem(IDC_EDIT_IMEI1))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_EDIT_IMEI2))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_EDIT_IMEI3))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_EDIT_IMEI4))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_EDIT_NETCODE))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_EDIT_COLORBOXCODE))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_EDIT_SN))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_EDIT_PSN))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_EDIT_BT))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_EDIT_MAC))->SetFont(&m_staticfont);
}


void CColorBoxView::CreateTwoFile()
{
	CFile  m_file;
	m_file.Open("c:\\temp.bat",CFile::modeCreate|CFile::modeWrite);
//	m_file.Write("copy c:\\resource.txt lpt1",strlen("copy c:\\resource.txt lpt1"));
	m_file.Write("print /d:com1 c:\\resource.txt",strlen("print /d:com1 c:\\resource.txt"));
	m_file.Close();
	m_file.Open("c:\\resource.txt",CFile::modeCreate|CFile::modeWrite);  
	m_file.Close();
}


void CColorBoxView::OnTimer(UINT nIDEvent)
{
	CString path;
	GetModuleFileName(NULL,path.GetBufferSetLength(MAX_PATH+1),MAX_PATH);
	path.ReleaseBuffer();
	int pos = path.ReverseFind('\\');
	path = path.Left(pos);
	m_csErrorSndPath = path + _T("\\MES_ERROR.wav");
	m_csOkSndPath = path + _T("\\MES_OK.wav");

	if(nIDEvent == 1)
	{
		this->KillTimer(1);
		CFormView::OnTimer(nIDEvent);
		
		this->m_Config.ReadConfig();

		this->m_Config.m_iHandleMode=1;

		this->m_Config.SaveConfig();
		
		switch (this->m_Config.m_iHandleMode)
		{
		case 1:
			AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_MODE_1, MF_BYCOMMAND | MF_CHECKED );
			break;
		case 2:
			AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_MODE_2, MF_BYCOMMAND | MF_CHECKED );
			break;
		case 3:
			AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_MODE_3, MF_BYCOMMAND | MF_CHECKED );
			break;
		default:
			this->m_Config.m_iHandleMode=1;
			this->m_Config.SaveConfig();
			AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_MODE_1, MF_BYCOMMAND | MF_CHECKED );
			break;
		}

		switch (this->m_Config.m_iIsScanMainImei)
		{
		case 1:
			AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_MAIN_IMEI_YES, MF_BYCOMMAND | MF_CHECKED );
			break;
		case 0:
			AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_MAIN_IMEI_NO, MF_BYCOMMAND | MF_CHECKED );
			break;
		default:
			this->m_Config.m_iIsScanMainImei=0;
			this->m_Config.SaveConfig();
			AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_MAIN_IMEI_NO, MF_BYCOMMAND | MF_CHECKED );
			break;
		}

		this->SetUIDisableAll();

		InsertListInfo("Current operating mode: scan mode...",0);
		
		//设置CONFIG.INI路径
		this->m_csConfigPath.Format("%s%s_%s",this->m_Config.m_csCFGPath,m_csCurrentProduct,this->m_csCurrentOrder);
		
		//根据IMEIType情况设置空间
		switch(this->m_iIMEIType)
		{
		case 0:
			this->m_ctrIMEI1.EnableWindow(TRUE);
			this->m_ctrIMEI2.EnableWindow(FALSE);
			this->m_ctrIMEI3.EnableWindow(FALSE);
			this->m_ctrIMEI4.EnableWindow(FALSE);
			break;
		case 1:
			this->m_ctrIMEI1.EnableWindow(TRUE);
			this->m_ctrIMEI2.EnableWindow(TRUE);
			this->m_ctrIMEI3.EnableWindow(FALSE);
			this->m_ctrIMEI4.EnableWindow(FALSE);
			break;
		case 2:
			this->m_ctrIMEI1.EnableWindow(TRUE);
			this->m_ctrIMEI2.EnableWindow(TRUE);
			this->m_ctrIMEI3.EnableWindow(TRUE);
			this->m_ctrIMEI4.EnableWindow(FALSE);
			break;
		case 3:
			this->m_ctrIMEI1.EnableWindow(TRUE);
			this->m_ctrIMEI2.EnableWindow(TRUE);
			this->m_ctrIMEI3.EnableWindow(TRUE);
			this->m_ctrIMEI4.EnableWindow(TRUE);
			break;
		default:
			break;
		}
		
		//如果是扫描主IMEI号，那么重新设置控件
		if(this->m_Config.m_iIsScanMainImei==1)
		{
			this->m_ctrIMEI1.EnableWindow(TRUE);
			this->m_ctrIMEI2.EnableWindow(FALSE);
			this->m_ctrIMEI3.EnableWindow(FALSE);
			this->m_ctrIMEI4.EnableWindow(FALSE);
		}

		//是否扫描比对网标
		if (m_bScanNetCode)
		{
			this->m_ctrNet.EnableWindow(TRUE);
		}
		else
		{
			this->m_ctrNet.EnableWindow(FALSE);
		}

		//是否扫描比对彩盒料号
		if (m_bCheckColorBoxCode)
		{
			this->m_ctrColorBoxCode.EnableWindow(TRUE);
		}
		else
		{
			this->m_ctrColorBoxCode.EnableWindow(FALSE);
		}

		this->m_ctrIMEI1.SetFocus();
	}
}


void CColorBoxView::InsertListInfo(CString state,int imageIndex)
{
	CString date;
	date=GetCurTimes();
	m_state_list.InsertItem(m_state_list.GetItemCount(),date,imageIndex);
	m_state_list.SetItemText(m_state_list.GetItemCount()-1,1,state);
	m_state_list.EnsureVisible(m_state_list.GetItemCount()-1,TRUE);
}


CString CColorBoxView::GetCurTimes()
{
	CTime t=CTime::GetCurrentTime();
	CString str=t.Format( "%Y-%m-%d  %H:%M:%S");
	return str;
	
}


void CColorBoxView::SetUIDisableAll()
{
	this->m_ctrIMEI1.EnableWindow(FALSE);
	this->m_ctrIMEI2.EnableWindow(FALSE);
	this->m_ctrIMEI3.EnableWindow(FALSE);
	this->m_ctrIMEI4.EnableWindow(FALSE);
	this->m_ctrColorBoxCode.EnableWindow(FALSE);
	this->m_ctrBT.EnableWindow(FALSE);
	this->m_ctrSN.EnableWindow(FALSE);
	this->m_ctrPSN.EnableWindow(FALSE);
	this->m_ctrMAC.EnableWindow(FALSE);
}


void CColorBoxView::ClearUI()
{
	this->m_csIMEI1.Empty();
	this->m_csIMEI2.Empty();
	this->m_csIMEI3.Empty();
	this->m_csIMEI4.Empty();
	this->m_csNet.Empty();
	this->m_csColorBoxCode.Empty();
	this->m_csBT.Empty();
	this->m_csMAC.Empty();
	this->m_csSN.Empty();
	this->m_csPSN.Empty();
	
	SendMessage(WM_UPDATEDATA, FALSE, FALSE);
	SendMessage(WM_SETMYFOCUS,(WPARAM)(&this->m_ctrIMEI1),FALSE);
}


CString CColorBoxView::VariantToCString(VARIANT   var)   
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


void CColorBoxView::OnChangeEditImei1() 
{
	m_iFirstKeyTime = GetTickCount();
	if(m_csIMEI1.GetLength() != 0)
	{
		m_iKeyPeriod = m_iFirstKeyTime - m_iLastKeyTime;
		if(m_iKeyPeriod > 100)
		{
			PlayWarningTone(m_csErrorSndPath);
			InsertListInfo("Please use the scan gun input!",2);
			m_csIMEI1.Empty();
			UpdateData(FALSE);
			m_ctrIMEI1.SetFocus();
			return;
		}
	}
	m_iLastKeyTime = m_iFirstKeyTime;

	if(this->m_Config.m_iHandleMode==1)
	{
		SendMessage(WM_UPDATEDATA, TRUE, FALSE);
		
		switch(this->m_iIMEIType)
		{
		case 0:	
			if(m_csIMEI1.Right(2)=="\r\n")
			{
				m_csIMEI1.Replace("\r\n","");
				SendMessage(WM_UPDATEDATA, FALSE, FALSE);
				
				if(!IMEITYPE_0_CheckImei1())
				{
					PlayWarningTone(m_csErrorSndPath);
					m_ctrIMEI1.SetFocus();
					m_ctrIMEI1.SetSel(0,-1);
					return;
				}

				if(m_bScanNetCode==0)
				{
					if (m_bCheckColorBoxCode)
					{
						this->m_ctrColorBoxCode.SetFocus();
						this->m_ctrColorBoxCode.SetSel(0,-1);
					}
					else
					{
						this->PrintLabel();
						this->ClearUI();
					}
				}
				else
				{
					m_ctrNet.SetFocus();
					m_ctrNet.SetSel(0,-1);
				}
			}
			break;
		case 1:
            if(this->m_Config.m_iIsScanMainImei==1)
			{
				if(m_csIMEI1.Right(2)=="\r\n")
				{
					m_csIMEI1.Replace("\r\n","");
					SendMessage(WM_UPDATEDATA, FALSE, FALSE);
					
					if(!SCAN_MAIN_IMEI_CheckImei())
					{
						PlayWarningTone(m_csErrorSndPath);
						m_ctrIMEI1.SetFocus();
						m_ctrIMEI1.SetSel(0,-1);
						return;
					}
					
					if(m_bScanNetCode==0)
					{
						if (m_bCheckColorBoxCode)
						{
							this->m_ctrColorBoxCode.SetFocus();
							this->m_ctrColorBoxCode.SetSel(0,-1);
						}
						else
						{
							this->PrintLabel();
							this->ClearUI();
						}
					}
					else
					{
						m_ctrNet.SetFocus();					
						m_ctrNet.SetSel(0,-1);
					}
				}
			}
			else
			{
				if(m_csIMEI1.Right(2)=="\r\n")
				{
					m_csIMEI1.Replace("\r\n","");
					SendMessage(WM_UPDATEDATA, FALSE, FALSE);

					if(!IMEITYPE_1_CheckImei1())
					{
						PlayWarningTone(m_csErrorSndPath);
						m_ctrIMEI1.SetFocus();
						m_ctrIMEI1.SetSel(0,-1);
						return;
					}
					this->m_ctrIMEI2.SetFocus();
					this->m_ctrIMEI2.SetSel(0,-1);
				}
			}
			break;
		case 2:
            if(this->m_Config.m_iIsScanMainImei==1)
			{
				if(m_csIMEI1.Right(2)=="\r\n")
				{
					m_csIMEI1.Replace("\r\n","");
					SendMessage(WM_UPDATEDATA, FALSE, FALSE);
					
					if(!SCAN_MAIN_IMEI_CheckImei())
					{
						PlayWarningTone(m_csErrorSndPath);
						m_ctrIMEI1.SetFocus();
						m_ctrIMEI1.SetSel(0,-1);
						return;
					}
					
					if(m_bScanNetCode==0)
					{
						if (m_bCheckColorBoxCode)
						{
							this->m_ctrColorBoxCode.SetFocus();
							this->m_ctrColorBoxCode.SetSel(0,-1);
						}
						else
						{
							this->PrintLabel();
							this->ClearUI();
						}
					}
					else
					{
						m_ctrNet.SetFocus();					
						m_ctrNet.SetSel(0,-1);
					}
				}
			}
			else
			{
				if(m_csIMEI1.Right(2)=="\r\n")
				{
					m_csIMEI1.Replace("\r\n","");
					SendMessage(WM_UPDATEDATA, FALSE, FALSE);

					if(!IMEITYPE_1_CheckImei1())
					{
						PlayWarningTone(m_csErrorSndPath);
						m_ctrIMEI1.SetFocus();
						m_ctrIMEI1.SetSel(0,-1);
						return;
					}
					this->m_ctrIMEI2.SetFocus();
					this->m_ctrIMEI2.SetSel(0,-1);
				}
			}
			break;
		case 3:
            if(this->m_Config.m_iIsScanMainImei==1)
			{
				if(m_csIMEI1.Right(2)=="\r\n")
				{
					m_csIMEI1.Replace("\r\n","");
					SendMessage(WM_UPDATEDATA, FALSE, FALSE);
					
					if(!SCAN_MAIN_IMEI_CheckImei())
					{
						PlayWarningTone(m_csErrorSndPath);
						m_ctrIMEI1.SetFocus();
						m_ctrIMEI1.SetSel(0,-1);
						return;
					}
					
					if(m_bScanNetCode==0)
					{
						if (m_bCheckColorBoxCode)
						{
							this->m_ctrColorBoxCode.SetFocus();
							this->m_ctrColorBoxCode.SetSel(0,-1);
						}
						else
						{
							this->PrintLabel();
							this->ClearUI();
						}
					}
					else
					{
						m_ctrNet.SetFocus();					
						m_ctrNet.SetSel(0,-1);
					}
				}
			}
			else
			{
				if(m_csIMEI1.Right(2)=="\r\n")
				{
					m_csIMEI1.Replace("\r\n","");
					SendMessage(WM_UPDATEDATA, FALSE, FALSE);

					if(!IMEITYPE_1_CheckImei1())
					{
						PlayWarningTone(m_csErrorSndPath);
						m_ctrIMEI1.SetFocus();
						m_ctrIMEI1.SetSel(0,-1);
						return;
					}
					this->m_ctrIMEI2.SetFocus();
					this->m_ctrIMEI2.SetSel(0,-1);
				}
			}
			break;
		default:
			break;
		}
	}
}


void CColorBoxView::OnChangeEditImei2() 
{
	m_iFirstKeyTime = GetTickCount();
	if(m_csIMEI2.GetLength() != 0)
	{
		m_iKeyPeriod = m_iFirstKeyTime - m_iLastKeyTime;
		if(m_iKeyPeriod > 100)
		{   
			PlayWarningTone(m_csErrorSndPath);
			InsertListInfo("Please use the scan gun input!",2);
			m_csIMEI2.Empty();
			UpdateData(FALSE);
			m_ctrIMEI2.SetFocus();	
			return;
		}
	}
	m_iLastKeyTime = m_iFirstKeyTime;

	if(this->m_Config.m_iHandleMode==1)
	{
		SendMessage(WM_UPDATEDATA, TRUE, FALSE);
		switch(this->m_iIMEIType)
		{
		case 1:
			if(m_csIMEI2.Right(2)=="\r\n")
			{
				m_csIMEI2.Replace("\r\n","");
				SendMessage(WM_UPDATEDATA, FALSE, FALSE);

				if(!IMEITYPE_1_CheckImei2())
				{
					PlayWarningTone(m_csErrorSndPath);
					m_ctrIMEI1.SetFocus();
					m_ctrIMEI1.SetSel(0,-1);
					return;
				}
				
				if(m_bScanNetCode==0)
				{
					if (m_bCheckColorBoxCode)
					{
						this->m_ctrColorBoxCode.SetFocus();
						this->m_ctrColorBoxCode.SetSel(0,-1);
					}
					else
					{
						this->PrintLabel();
						this->ClearUI();
					}
				}
				else
				{
					m_ctrNet.SetFocus();					
					m_ctrNet.SetSel(0,-1);
				}
			}
			break;
		case 2:
			if(m_csIMEI2.Right(2)=="\r\n")
			{
				m_csIMEI2.Replace("\r\n","");
				SendMessage(WM_UPDATEDATA, FALSE, FALSE);

				if(!IMEITYPE_2_CheckImei2())
				{
					PlayWarningTone(m_csErrorSndPath);
					m_ctrIMEI1.SetFocus();
					m_ctrIMEI1.SetSel(0,-1);
					return;
				}
				this->m_ctrIMEI3.SetFocus();
				this->m_ctrIMEI3.SetSel(0,-1);			
			}
			break;
		case 3:
			if(m_csIMEI2.Right(2)=="\r\n")
			{
				m_csIMEI2.Replace("\r\n","");
				SendMessage(WM_UPDATEDATA, FALSE, FALSE);

				if(!IMEITYPE_2_CheckImei2())
				{
					PlayWarningTone(m_csErrorSndPath);
					m_ctrIMEI1.SetFocus();
					m_ctrIMEI1.SetSel(0,-1);
					return;
				}
				this->m_ctrIMEI3.SetFocus();
				this->m_ctrIMEI3.SetSel(0,-1);			
			}
			break;
		default:
			break;
		}
	}
}


void CColorBoxView::OnChangeEditImei3() 
{
	m_iFirstKeyTime = GetTickCount();
	if(m_csIMEI3.GetLength() != 0)
	{
		m_iKeyPeriod = m_iFirstKeyTime - m_iLastKeyTime;
		if(m_iKeyPeriod > 100)
		{   
			PlayWarningTone(m_csErrorSndPath);
			InsertListInfo("Please use the scan gun input!",2);
			m_csIMEI3.Empty();
			UpdateData(FALSE);
			m_ctrIMEI3.SetFocus();	//Ian
			return;
		}
	}
	m_iLastKeyTime = m_iFirstKeyTime;

	if(this->m_Config.m_iHandleMode==1)
	{
		SendMessage(WM_UPDATEDATA, TRUE, FALSE);	
		switch(this->m_iIMEIType)
		{
		case 2:
			if(m_csIMEI3.Right(2)=="\r\n")
			{
				m_csIMEI3.Replace("\r\n","");
				SendMessage(WM_UPDATEDATA, FALSE, FALSE);

				if(!IMEITYPE_2_CheckImei3())
				{
					PlayWarningTone(m_csErrorSndPath);
					m_ctrIMEI1.SetFocus();
					m_ctrIMEI1.SetSel(0,-1);
					return;
				}
				
				if(m_bScanNetCode==0)
				{
					if (m_bCheckColorBoxCode)
					{
						this->m_ctrColorBoxCode.SetFocus();
						this->m_ctrColorBoxCode.SetSel(0,-1);
					}
					else
					{
						this->PrintLabel();
						this->ClearUI();
					}
				}
				else
				{
					m_ctrNet.SetFocus();					
					m_ctrNet.SetSel(0,-1);
				}
			}
			break;
		case 3:
			if(m_csIMEI3.Right(2)=="\r\n")
			{
				m_csIMEI3.Replace("\r\n","");
				SendMessage(WM_UPDATEDATA, FALSE, FALSE);
				
				if(!IMEITYPE_3_CheckImei3())
				{
					PlayWarningTone(m_csErrorSndPath);
					m_ctrIMEI1.SetFocus();
					m_ctrIMEI1.SetSel(0,-1);
					return;
				}
				this->m_ctrIMEI4.SetFocus();
				this->m_ctrIMEI4.SetSel(0,-1);			
			}
			break;
		default:
			break;
		}
	}
}


void CColorBoxView::OnChangeEditImei4() 
{
	m_iFirstKeyTime = GetTickCount();
	if(m_csIMEI4.GetLength() != 0)
	{
		m_iKeyPeriod = m_iFirstKeyTime - m_iLastKeyTime;
		if(m_iKeyPeriod > 100)
		{   
			PlayWarningTone(m_csErrorSndPath);
			InsertListInfo("Please use the scan gun input!",2);
			m_csIMEI4.Empty();
			UpdateData(FALSE);
			m_ctrIMEI4.SetFocus();	//Ian
			return;
		}
	}
	m_iLastKeyTime = m_iFirstKeyTime;

	if(this->m_Config.m_iHandleMode==1)
	{
		SendMessage(WM_UPDATEDATA, TRUE, FALSE);
		switch(this->m_iIMEIType)
		{
		case 3:
			if(m_csIMEI4.Right(2)=="\r\n")
			{
				m_csIMEI4.Replace("\r\n","");
				SendMessage(WM_UPDATEDATA, FALSE, FALSE);
				
				if(!IMEITYPE_3_CheckImei4())
				{
					PlayWarningTone(m_csErrorSndPath);
					m_ctrIMEI1.SetFocus();
					m_ctrIMEI1.SetSel(0,-1);
					return;
				}
				
				if(m_bScanNetCode==0)
				{
					if (m_bCheckColorBoxCode)
					{
						this->m_ctrColorBoxCode.SetFocus();
						this->m_ctrColorBoxCode.SetSel(0,-1);
					}
					else
					{
						this->PrintLabel();
						this->ClearUI();
					}
				}
				else
				{
					m_ctrNet.SetFocus();					
					m_ctrNet.SetSel(0,-1);
				}
			}
			break;
		default:
			break;
		}
	}	
}

//扫描彩盒料号，并与数据库比对
void CColorBoxView::OnChangeEditColorboxcode() 
{
	m_iFirstKeyTime = GetTickCount();
	if(m_csColorBoxCode.GetLength() != 0)
	{
		m_iKeyPeriod = m_iFirstKeyTime - m_iLastKeyTime;
		if(m_iKeyPeriod > 100)
		{   
			PlayWarningTone(m_csErrorSndPath);
			InsertListInfo("Please use the scan gun input!",2);
			m_csColorBoxCode.Empty();
			UpdateData(FALSE);
			m_ctrColorBoxCode.SetFocus();
			return;
		}
	}
	m_iLastKeyTime = m_iFirstKeyTime;

	SendMessage(WM_UPDATEDATA, TRUE, FALSE);
	
	if(m_csColorBoxCode.Right(2)=="\r\n")
	{
		m_csColorBoxCode.Replace("\r\n","");
		SendMessage(WM_UPDATEDATA, FALSE, FALSE);
		
		if(!SCAN_Check_ColorBoxCode())
		{
			PlayWarningTone(m_csErrorSndPath);
			m_ctrColorBoxCode.SetFocus();
			m_ctrColorBoxCode.SetSel(0,-1);
			return;
		}
		this->PrintLabel();
		this->ClearUI();
	}
}


BOOL CColorBoxView::SCAN_Check_ColorBoxCode()
{/*lucky
	if (this->m_csColorBoxCode != csColorBoxCode)
	{
		InsertListInfo("彩盒料号与数据库中记录不一致...",2);
		return FALSE;
	}
	else
	{
		InsertListInfo("彩盒料号与数据库比对成功...",0);
		return TRUE;
	}
	*/
	return TRUE;
}


BOOL CColorBoxView::SCAN_MAIN_IMEI_CheckImei()
{
	//检测长度是否为15位
	if(m_csIMEI1.GetLength()!=15)
	{
		InsertListInfo("IMEI1 Length Error...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}

	//检测号码是否再合法范围内
	if (m_iIMEIRangeType==0)
	{
		if(m_csIMEI1.Left(14)>this->m_imei1_end || m_csIMEI1.Left(14)<this->m_imei1_start)
		{
			InsertListInfo("IMEI1 Out of Range...",2);
			this->m_ctrIMEI1.SetSel(0,-1);
			return FALSE;
		}
	}
	else if(m_iIMEIRangeType==1)
	{
		_variant_t var;
		CString sql;

		sql.Format("select * from %s_%s_IMEIRange WHERE IMEI1='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csIMEI1);
		
		try
		{
			if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
				((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
			((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

			if(((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				InsertListInfo("IMEI1 is not in IMEI Table...",2);
				return FALSE;
			}

			if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
				((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}

	//检测IMEI校验位是否正确
	char calculate_digit;
	calculate_15_digit_imei((char*)(LPCTSTR)m_csIMEI1.Left(14),calculate_digit);

	if(calculate_digit!=m_csIMEI1.Right(1))	
	{
		InsertListInfo("Illegal IMEI1,Parity error...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}

	CString temp,temp2; 
	_variant_t var;
	CString sql;
	
	try
	{
		sql.Format("select * from %s_%s_ColorBox where IMEI1='%s' and (Status=1 or Status=2 or Status=3 or Status=4) and Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,(char*)(LPCTSTR)m_csIMEI1);
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("IMEI2");
			this->m_csIMEI2.Empty();
			this->m_csIMEI2=VariantToCString(var);
			
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("IMEI3");
			this->m_csIMEI3.Empty();
			this->m_csIMEI3=VariantToCString(var);
			
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("IMEI4");
			this->m_csIMEI4.Empty();
			this->m_csIMEI4=VariantToCString(var);
			
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("BarCode");
			this->m_csSN.Empty();
			this->m_csSN=VariantToCString(var);
			
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("ProductSN");
			this->m_csPSN.Empty();
			this->m_csPSN=VariantToCString(var);
			
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("BTAddress");
			this->m_csBT.Empty();
			this->m_csBT=VariantToCString(var);
			
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("WIFIMAC");
			this->m_csMAC.Empty();
			this->m_csMAC=VariantToCString(var);

			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("NetCode");
			this->m_csNet.Empty();
			this->m_csNet=VariantToCString(var);
			
			SendMessage(WM_UPDATEDATA, FALSE, FALSE);
		}
		else
		{
			InsertListInfo("No Check IMEI S1 box database records, please check whether the IMEI Check did IMEI S1 station...",2);
			return FALSE;
		}
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}
/*
	try
	{
		sql.Format("select count(*) as COUNT from %s_%s_QCData where QCType=%d",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,0);
		
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			this->m_iQCNum=var.intVal;
		}
		else
		{
			return  FALSE;
		}
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//判断QC抽检是否已完成一个批次
	if (m_iQCNum < m_iSampleNum)
	{
		InsertListInfo("当前订单未完成一个批次的QC抽检，无法继续包装...",2);
		return FALSE;
	}

	try
	{
		sql.Format("select * from %s_%s_QCData where IMEI1='%s' and Status=0",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,(char*)(LPCTSTR)m_csIMEI1);
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			InsertListInfo("该机器为外观坏机或功能坏机，无法打印彩盒标签...",2);
			return FALSE;
		}

		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("未知错误...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}
	*/
	return TRUE;
}


BOOL CColorBoxView::IMEITYPE_0_CheckImei1()
{
	//检测长度是否为15位
	if(m_csIMEI1.GetLength()!=15)
	{
		InsertListInfo("IMEI1 Length Error...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}

	//检测号码是否再合法范围内
	if (m_iIMEIRangeType==0)
	{
		if(m_csIMEI1.Left(14)>this->m_imei1_end || m_csIMEI1.Left(14)<this->m_imei1_start)
		{
			InsertListInfo("IMEI1 is out of Range...",2);
			this->m_ctrIMEI1.SetSel(0,-1);
			return FALSE;
		}
	}
	else if(m_iIMEIRangeType==1)
	{
		_variant_t var;
		CString sql;

		sql.Format("select * from %s_%s_IMEIRange WHERE IMEI1='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csIMEI1);
		
		try
		{
			if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
				((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
			((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

			if(((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				InsertListInfo("IMEI1 is not in the IMEI Table...",2);
				return FALSE;
			}

			if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
				((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}

	//检测IMEI校验位是否正确
	char calculate_digit;
	calculate_15_digit_imei((char*)(LPCTSTR)m_csIMEI1.Left(14),calculate_digit);

	if(calculate_digit!=m_csIMEI1.Right(1))	
	{
		InsertListInfo("Illegal IMEI1,Parity error...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}

	CString temp,temp2;
	_variant_t var;
	CString sql;

	try
	{
		sql.Format("select * from %s_%s_ColorBox where IMEI1='%s' and (Status=1 or Status=2 or Status=3 or Status=4) and Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,(char*)(LPCTSTR)m_csIMEI1);
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("BarCode");
			this->m_csSN.Empty();
			this->m_csSN=VariantToCString(var);
			
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("ProductSN");
			this->m_csPSN.Empty();
			this->m_csPSN=VariantToCString(var);
			
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("BTAddress");
			this->m_csBT.Empty();
			this->m_csBT=VariantToCString(var);
			
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("WIFIMAC");
			this->m_csMAC.Empty();
			this->m_csMAC=VariantToCString(var);
			
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("NetCode");
			this->m_csNet.Empty();
			this->m_csNet=VariantToCString(var);
			
			SendMessage(WM_UPDATEDATA, FALSE, FALSE);
		}
		else
		{
			InsertListInfo("No Check IMEI S1 box database records, please check whether the IMEI Check did IMEI S1 station...",2);
			return FALSE;
		}
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}
/*
	try
	{
		sql.Format("select count(*) as COUNT from %s_%s_QCData where QCType=%d",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,0);
		
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			this->m_iQCNum=var.intVal;
		}
		else
		{
			return  FALSE;
		}
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//判断QC抽检是否已完成一个批次
	if (m_iQCNum < m_iSampleNum)
	{
		InsertListInfo("当前订单未完成一个批次的QC抽检，无法继续包装...",2);
		return FALSE;
	}

	try
	{
		sql.Format("select * from %s_%s_QCData where IMEI1='%s' and Status=0",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,(char*)(LPCTSTR)m_csIMEI1);
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			InsertListInfo("该机器检测为坏机，无法打印彩盒标签...",2);
			return FALSE;
		}

		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("未知错误...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}
	*/
	return TRUE;
}


BOOL CColorBoxView::IMEITYPE_1_CheckImei1()
{
	//检测长度是否为15位
	if(m_csIMEI1.GetLength()!=15)
	{
		InsertListInfo("IMEI1 length error...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}

	//检测号码是否再合法范围内
	if (m_iIMEIRangeType==0)
	{
		if(m_csIMEI1.Left(14)>this->m_imei1_end || m_csIMEI1.Left(14)<this->m_imei1_start)
		{
			InsertListInfo("IMEI1 is out of range...",2);
			this->m_ctrIMEI1.SetSel(0,-1);
			return FALSE;
		}
	}
	else if(m_iIMEIRangeType==1)
	{
		_variant_t var;
		CString sql;

		sql.Format("select * from %s_%s_IMEIRange WHERE IMEI1='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csIMEI1);
		
		try
		{
			if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
				((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
			((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

			if(((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				InsertListInfo("IMEI1 is not in IMEI Table...",2);
				return FALSE;
			}

			if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
				((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}

	//检测IMEI校验位是否正确
	char calculate_digit;
	calculate_15_digit_imei((char*)(LPCTSTR)m_csIMEI1.Left(14),calculate_digit);

	if(calculate_digit!=m_csIMEI1.Right(1))	
	{
		InsertListInfo("Illegal IMEI1,Parity error...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}

	return TRUE;
}


BOOL CColorBoxView::IMEITYPE_1_CheckImei2()
{
	if(m_csIMEI1==m_csIMEI2)
	{
		InsertListInfo("IMEI1 and IMEI2 can not be the same...",2);
		this->m_ctrIMEI2.SetSel(0,-1);
		return FALSE;
	}
	
	//检测号码是否再合法范围内
	if (m_iIMEIRangeType==0)
	{
		if(m_csIMEI2.Left(14)>m_imei2_end || m_csIMEI2.Left(14)<m_imei2_start)
		{
			InsertListInfo("IMEI2 is out of range...",2);
			this->m_ctrIMEI2.SetSel(0,-1);
			return FALSE;
		}
	}
	else if(m_iIMEIRangeType==1)
	{
		_variant_t var;
		CString sql;

		sql.Format("select * from %s_%s_IMEIRange WHERE IMEI2='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csIMEI2);
		
		try
		{
			if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
				((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
			((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

			if(((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				InsertListInfo("IMEI2 is not in IMEI Table...",2);
				return FALSE;
			}

			if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
				((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}
	
	//检测IMEI2校验位是否正确
	char calculate_digit;
	calculate_15_digit_imei((char*)(LPCTSTR)m_csIMEI2.Left(14),calculate_digit);
	
	if(calculate_digit!=m_csIMEI2.Right(1))
	{
		InsertListInfo("Illegal IMEI,Parity error...",2);
		this->m_ctrIMEI2.SetSel(0,-1);
		return FALSE;
	}
	
	CString temp,temp2;
	_variant_t var;
	CString sql;
	try
	{
		sql.Format("select * from %s_%s_ColorBox where (IMEI1='%s') and (IMEI2='%s') and (Status=1 or Status=2 or Status=3 or Status=4) and Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,(char*)(LPCTSTR)m_csIMEI1,(char*)(LPCTSTR)m_csIMEI2);
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("BarCode");
			this->m_csSN.Empty();
			this->m_csSN=VariantToCString(var);
			
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("ProductSN");
			this->m_csPSN.Empty();
			this->m_csPSN=VariantToCString(var);
			
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("BTAddress");
			this->m_csBT.Empty();
			this->m_csBT=VariantToCString(var);
			
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("WIFIMAC");
			this->m_csMAC.Empty();
			this->m_csMAC=VariantToCString(var); 

			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("NetCode");
			this->m_csNet.Empty();
			this->m_csNet=VariantToCString(var);
			
			SendMessage(WM_UPDATEDATA, FALSE, FALSE);
		}
		else
		{
			InsertListInfo("No Check IMEI S1 box database records, please check whether the IMEI Check did IMEI S1 station...",2);
			return FALSE;
		}
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}	

	return TRUE;
}


BOOL CColorBoxView::IMEITYPE_2_CheckImei2()
{
	//检测长度是否为15位
	if(m_csIMEI2.GetLength()!=15)
	{
		InsertListInfo("IMEI2 length error...",2);
		this->m_ctrIMEI2.SetSel(0,-1);
		return FALSE;
	}
	
	//检测号码是否再合法范围内
	if (m_iIMEIRangeType==0)
	{
		if(m_csIMEI2.Left(14)>this->m_imei2_end || m_csIMEI2.Left(14)<this->m_imei2_start)
		{
			InsertListInfo("IMEI2 is out of range...",2);
			this->m_ctrIMEI2.SetSel(0,-1);
			return FALSE;
		}
	}
	else if(m_iIMEIRangeType==1)
	{
		_variant_t var;
		CString sql;

		sql.Format("select * from %s_%s_IMEIRange WHERE IMEI2='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csIMEI2);
		
		try
		{
			if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
				((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
			((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

			if(((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				InsertListInfo("IMEI2 is not in IMEI Table...",2);
				return FALSE;
			}

			if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
				((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}
	
	//检测IMEI校验位是否正确
	char calculate_digit;
	calculate_15_digit_imei((char*)(LPCTSTR)m_csIMEI2.Left(14),calculate_digit);
	
	if(calculate_digit!=m_csIMEI2.Right(1))	
	{
		InsertListInfo("Illegal IMEI2,Parity error...",2);
		this->m_ctrIMEI2.SetSel(0,-1);
		return FALSE;
	}
	return TRUE;
}


BOOL CColorBoxView::IMEITYPE_2_CheckImei3()
{
	if(m_csIMEI1==m_csIMEI2)
	{
		InsertListInfo("IMEI1 and IMEI2 can not be the same...",2);
		this->m_ctrIMEI2.SetSel(0,-1);
		return FALSE;
	}

	if(m_csIMEI2==m_csIMEI3)
	{
		InsertListInfo("IMEI2 and IMEI3 can not be the same...",2);
		this->m_ctrIMEI3.SetSel(0,-1);
		return FALSE;
	}

	if(m_csIMEI1==m_csIMEI3)
	{
		InsertListInfo("IMEI1 and IMEI3 can not be the same...",2);
		this->m_ctrIMEI3.SetSel(0,-1);
		return FALSE;
	}
	
	//检测长度是否为15位
	if(m_csIMEI3.GetLength()!=15)
	{
		InsertListInfo("length error...",2);
		this->m_ctrIMEI3.SetSel(0,-1);
		return FALSE;
	}
	
	//检测号码是否再合法范围内
	if (m_iIMEIRangeType==0)
	{
		if(m_csIMEI3.Left(14)>m_imei3_end || m_csIMEI3.Left(14)<m_imei3_start)
		{
			InsertListInfo("IMEI3 is out of range...",2);
			this->m_ctrIMEI3.SetSel(0,-1);
			return FALSE;
		}
	}
	else if(m_iIMEIRangeType==1)
	{
		_variant_t var;
		CString sql;

		sql.Format("select * from %s_%s_IMEIRange WHERE IMEI3='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csIMEI3);
		
		try
		{
			if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
				((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
			((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

			if(((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				InsertListInfo("IMEI3 is not in IMEI Table...",2);
				return FALSE;
			}

			if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
				((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}
	
	//检测IMEI3校验位是否正确
	char calculate_digit;
	calculate_15_digit_imei((char*)(LPCTSTR)m_csIMEI3.Left(14),calculate_digit);
	
	if(calculate_digit!=m_csIMEI3.Right(1))
	{
		InsertListInfo("Illegal IMEI,Parity error...",2);
		this->m_ctrIMEI3.SetSel(0,-1);
		return FALSE;
	}
	
	CString temp,temp2;
	_variant_t var;
	CString sql;
	
	try
	{
		sql.Format("select * from %s_%s_ColorBox where (IMEI1='%s') AND (IMEI2='%s') AND (IMEI3='%s') AND (Status=1 or Status=2 or Status=3 or Status=4) AND Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,(char*)(LPCTSTR)m_csIMEI1,(char*)(LPCTSTR)m_csIMEI2,(char*)(LPCTSTR)m_csIMEI3);
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("BarCode");
			this->m_csSN.Empty();
			this->m_csSN=VariantToCString(var);
			
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("ProductSN");
			this->m_csPSN.Empty();
			this->m_csPSN=VariantToCString(var);
			
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("BTAddress");
			this->m_csBT.Empty();
			this->m_csBT=VariantToCString(var);
			
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("WIFIMAC");
			this->m_csMAC.Empty();
			this->m_csMAC=VariantToCString(var);

			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("NetCode");
			this->m_csNet.Empty();
			this->m_csNet=VariantToCString(var);
			
			//UpdateData(FALSE);
			SendMessage(WM_UPDATEDATA, FALSE, FALSE);
		}
		else
		{
			InsertListInfo("No Check IMEI S1 box database records, please check whether the IMEI Check did IMEI S1 station...",2);
			return FALSE;
		}
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}	

	return TRUE;
}


BOOL CColorBoxView::IMEITYPE_3_CheckImei3()
{
	//检测长度是否为15位
	if(m_csIMEI3.GetLength()!=15)
	{
		InsertListInfo("IMEI3length error...",2);
		this->m_ctrIMEI3.SetSel(0,-1);
		return FALSE;
	}
	
	//检测号码是否再合法范围内
	if (m_iIMEIRangeType==0)
	{
		if(m_csIMEI3.Left(14)>this->m_imei3_end || m_csIMEI3.Left(14)<this->m_imei3_start)
		{
			InsertListInfo("IMEI3 is out of range...",2);
			this->m_ctrIMEI3.SetSel(0,-1);
			return FALSE;
		}
	}
	else if(m_iIMEIRangeType==1)
	{
		_variant_t var;
		CString sql;

		sql.Format("select * from %s_%s_IMEIRange WHERE IMEI3='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csIMEI3);
		
		try
		{
			if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
				((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
			((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

			if(((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				InsertListInfo("IMEI3 is not in IMEI Table...",2);
				return FALSE;
			}

			if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
				((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}
	
	//检测IMEI校验位是否正确
	char calculate_digit;
	calculate_15_digit_imei((char*)(LPCTSTR)m_csIMEI3.Left(14),calculate_digit);
	
	if(calculate_digit!=m_csIMEI3.Right(1))	
	{
		InsertListInfo("Illegal IMEI3,Parity error...",2);
		this->m_ctrIMEI3.SetSel(0,-1);
		return FALSE;
	}

	return TRUE;
}


BOOL CColorBoxView::IMEITYPE_3_CheckImei4()
{
	if(m_csIMEI1==m_csIMEI2)
	{
		InsertListInfo("IMEI1 and IMEI2 can not be the same...",2);
		this->m_ctrIMEI2.SetSel(0,-1);
		return FALSE;
	}

	if(m_csIMEI1==m_csIMEI3)
	{
		InsertListInfo("IMEI1 and IMEI3 can not be the same...",2);
		this->m_ctrIMEI3.SetSel(0,-1);
		return FALSE;
	}

	if(m_csIMEI1==m_csIMEI4)
	{
		InsertListInfo("IMEI1 and IMEI4 can not be the same...",2);
		this->m_ctrIMEI4.SetSel(0,-1);
		return FALSE;
	}
	
	if(m_csIMEI2==m_csIMEI3)
	{
		InsertListInfo("IMEI2 and IMEI3 can not be the same...",2);
		this->m_ctrIMEI3.SetSel(0,-1);
		return FALSE;
	}

	if(m_csIMEI2==m_csIMEI4)
	{
		InsertListInfo("IMEI2 and IMEI4 can not be the same...",2);
		this->m_ctrIMEI4.SetSel(0,-1);
		return FALSE;
	}

	if(m_csIMEI3==m_csIMEI4)
	{
		InsertListInfo("IMEI3 and IMEI4 can not be the same...",2);
		this->m_ctrIMEI4.SetSel(0,-1);
		return FALSE;
	}
	
	//检测长度是否为15位
	if(m_csIMEI4.GetLength()!=15)
	{
		InsertListInfo("length error...",2);
		this->m_ctrIMEI4.SetSel(0,-1);
		return FALSE;
	}
	
	//检测号码是否再合法范围内
	if (m_iIMEIRangeType==0)
	{
		if(m_csIMEI4.Left(14)>m_imei4_end || m_csIMEI4.Left(14)<m_imei4_start)
		{
			InsertListInfo("IMEI is out of range...",2);
			this->m_ctrIMEI4.SetSel(0,-1);
			return FALSE;
		}
	}
	else if(m_iIMEIRangeType==1)
	{
		_variant_t var;
		CString sql;

		sql.Format("select * from %s_%s_IMEIRange WHERE IMEI4='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csIMEI4);
		
		try
		{
			if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
				((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
			((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

			if(((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				InsertListInfo("IMEI4 is not in IMEI Table...",2);
				return FALSE;
			}

			if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
				((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}
	
	//检测IMEI4校验位是否正确
	char calculate_digit;
	calculate_15_digit_imei((char*)(LPCTSTR)m_csIMEI4.Left(14),calculate_digit);
	
	if(calculate_digit!=m_csIMEI4.Right(1))
	{
		InsertListInfo("Illegal IMEI,Parity error...",2);
		this->m_ctrIMEI4.SetSel(0,-1);
		return FALSE;
	}
	
	CString temp,temp2;
	_variant_t var;
	CString sql;

	try
	{
		sql.Format("select * from %s_%s_ColorBox where (IMEI1='%s') AND (IMEI2='%s') AND (IMEI3='%s') AND (IMEI4='%s') AND (Status=1 or Status=2 or Status=3 or Status=4) AND Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,(char*)(LPCTSTR)m_csIMEI1,(char*)(LPCTSTR)m_csIMEI2,(char*)(LPCTSTR)m_csIMEI3,(char*)(LPCTSTR)m_csIMEI4);
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("BarCode");
			this->m_csSN.Empty();
			this->m_csSN=VariantToCString(var);
			
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("ProductSN");
			this->m_csPSN.Empty();
			this->m_csPSN=VariantToCString(var);
			
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("BTAddress");
			this->m_csBT.Empty();
			this->m_csBT=VariantToCString(var);
			
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("WIFIMAC");
			this->m_csMAC.Empty();
			this->m_csMAC=VariantToCString(var);

			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("NetCode");
			this->m_csNet.Empty();
			this->m_csNet=VariantToCString(var);
			
			SendMessage(WM_UPDATEDATA, FALSE, FALSE);
		}
		else
		{
			InsertListInfo("No Check IMEI S1 box database records, please check whether the IMEI Check did IMEI S1 station...",2);
			return FALSE;
		}
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}

	return TRUE;
}
  

void CColorBoxView::PrintLabel()
{
	CString status;
	_variant_t var;
	CString sql;

	sql.Format("select * from %s_%s_ColorBox where IMEI1='%s' and (Status=2 or Status=3 or Status=4) and Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csIMEI1);
	if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
		((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
	((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	if(!((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
	{
		if (this->m_iRadioMainSource == MAIN_SOURCE) 
		{
			
			CPassword dlg;
			dlg.ilevel = 0; //需普通权限验证
			if(dlg.DoModal()!=IDOK)
				return;
		}
	}

	if(!SginResource())
		return;

	if(!GoToPrint())
		return;

	if(!SaveToColorInfo())
		return;

	InsertListInfo("Print and save data box",0);

	if(!Load_Current_Product_Count())
	{
		PlayWarningTone(m_csErrorSndPath);
		InsertListInfo("To obtain the number of current orders has failed",2);
		return;
	}

	InsertListInfo("Obtain the number of current orders has been successful",0);
	UpdateCount(m_csCurrentCount);
}


BOOL CColorBoxView::SaveToColorInfo()
{
	CString temp;
	_variant_t var;
	CString sql;

	try
	{
		sql.Format("UPDATE %s_%s_ColorBox SET Status=2, NetCode='%s' where IMEI1='%s' and Enable=1",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csNet,this->m_csIMEI1);
		((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e) 
	{
		PlayWarningTone(m_csErrorSndPath);
		InsertListInfo("To save the record box database failed...",2);
		return FALSE;
	}
	
	sql.Format("UPDATE %s_%s_ProductionLine SET ColorBox='%s',ColorBoxDate=getdate() where IMEI1='%s'", \
		(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder, \
		this->m_csCurrentLine,this->m_csIMEI1);

	try
	{
		((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	
	return TRUE;
}


BOOL CColorBoxView::SginResource()
{
	CStdioFile fp;
	CStdioFile fp1;
	CString temp;
	CString CommandBuff;
	CString csSourcePath;
	CString csPSNStatic;

	temp.Empty();
	CommandBuff.Empty();
	csSourcePath.Empty();

	UpdateData();

	switch (this->m_iRadioMainSource)
	{
	case MAIN_SOURCE:
		csSourcePath=this->m_csLocalPath+"\\ColorResource.txt";
		break;
	case SUB_SOURCE:
		csSourcePath=this->m_csLocalPath+"\\ColorResource_Sub.txt";
		break;
	default :
		csSourcePath=this->m_csLocalPath+"\\ColorResource.txt";
		break;
	}
	
	if (!fp.Open(csSourcePath,CFile::modeRead | CFile::typeBinary))
	{
		PlayWarningTone(m_csErrorSndPath);
		InsertListInfo("The machine box resource file not found, please contact the Engineer!",2);
		return FALSE;
	}
	else
	{
		while(fp.ReadString(temp))
		{
			if(temp.Find("%IMEI1")!=-1)
			{
				temp.Replace("%IMEI1",this->m_csIMEI1);
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("%IMEI2")!=-1)
			{
				temp.Replace("%IMEI2",this->m_csIMEI2);
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("%IMEI3")!=-1)
			{
				temp.Replace("%IMEI3",this->m_csIMEI3);
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("%IMEI4")!=-1)
			{
				temp.Replace("%IMEI4",this->m_csIMEI4);
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("%PRODUCTSN")!=-1)
			{
				if (m_bPSNStatic == TRUE)
				{
					//PSN明码只打印流水位
					temp.Replace("%PRODUCTSN",this->m_csPSN.Right(this->m_csPSN.GetLength() - this->m_csPSNStatic.GetLength()));
				}
				else
				{
					temp.Replace("%PRODUCTSN",this->m_csPSN);
				}
				
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("%PCBSN")!=-1)
			{
				temp.Replace("%PCBSN",this->m_csSN);
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("%BT")!=-1)
			{
				temp.Replace("%BT",this->m_csBT);
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("%MAC")!=-1)
			{
				temp.Replace("%MAC",this->m_csMAC);
				CommandBuff+=temp;
				continue;
			}
			
			if(temp.Find("%CIMEI1")!=-1)
			{
				temp.Replace("%CIMEI1",this->m_csIMEI1.Left(m_csIMEI1.GetLength()-1)+">6"+m_csIMEI1.Right(1));
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("%CIMEI2")!=-1)
			{
				temp.Replace("%CIMEI2",this->m_csIMEI2.Left(m_csIMEI2.GetLength()-1)+">6"+m_csIMEI2.Right(1));
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("%CIMEI3")!=-1)
			{
				temp.Replace("%CIMEI3",this->m_csIMEI3.Left(m_csIMEI3.GetLength()-1)+">6"+m_csIMEI3.Right(1));
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("%CIMEI4")!=-1)
			{
				temp.Replace("%CIMEI4",this->m_csIMEI4.Left(m_csIMEI4.GetLength()-1)+">6"+m_csIMEI4.Right(1));
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("%CPRODUCTSN")!=-1)
			{
				char   ch;
				int    ilen = 0;           //PSN总长度
				int    isite[20];          //PSN中字母的位数
				int    iNum = 0;           //PSN中字母的个数
				CString cstmp;

				//获取PSN总长度
				ilen = this->m_csPSN.GetLength();

				//获取PSN中所有字母位数
				for(int i=0;i<ilen;i++)
				{
					ch = this->m_csPSN.GetAt(i);

					if((ch>=65 && ch<=90) || (ch>=97 && ch<=122)) //字母
					{
						isite[iNum] = i;
						iNum++;
					}
				}
				
				if (isite[0] == 0)    //PSN第一个字符为字母
				{
					temp.Replace("%CPRODUCTSN",this->m_csPSN.Left(m_csPSN.GetLength()-1)+">6"+m_csPSN.Right(1));
				}
				else if (iNum == 0)   //PSN全部为数字
				{
					temp.Replace("%CPRODUCTSN",this->m_csPSN.Left(m_csPSN.GetLength()-1)+">6"+m_csPSN.Right(1));
				}
				else  if(isite[0] != 0 && iNum != 0)     //PSN第一个字符不为字母并且PSN中包含字母
				{
					int j = 0;
					cstmp = this->m_csPSN;
					for(i=0;i<iNum;i++)
					{
						cstmp.Insert((isite[i]+2*j),">6");
						cstmp.Insert((isite[i]+1+2*(j+1)),">5");
						j+=2;
					}
					cstmp.Insert(ilen+4*iNum-1,">6");

					temp.Replace("%CPRODUCTSN",cstmp);
				}
/*
				char   ch;
				int    ilen = 0;           //PSN总长度
				int    isite[64];          //PSN中字母的位数
				int    iNum = 0;           //PSN中字母的个数
				
				//获取PSN总长度
				ilen = this->m_csPSN.GetLength();
				
				//获取PSN中所有字母位数
				for(int i=0;i<ilen;i++)
				{
					ch = this->m_csPSN.GetAt(i);
					
					if((ch>=65 && ch<=90) || (ch>=97 && ch<=122)) //字母
					{
						isite[iNum] = i;
						iNum++;
					}
				}

				if (iNum == 0)               //PSN全部为数字
				{
					if (ilen%2 == 0)         //PSN位数为偶数
					{
						temp.Replace("%CPRODUCTSN",this->m_csPSN);
					} 
					else                     //PSN位数为奇数
					{
						temp.Replace("%CPRODUCTSN",this->m_csPSN.Left(m_csPSN.GetLength()-1)+">6"+m_csPSN.Right(1));
					}
				}
				else                         //PSN为数字与字母混合
				{
					if (isite[0] == 0)       //PSN第一个字符为字母
					{
						if ((isite[1]-isite[0]))
						{
						}
						else
						{
						}
						temp.Replace("%CPRODUCTSN",this->m_csPSN.Left(m_csPSN.GetLength()-1)+">6"+m_csPSN.Right(1));
					}
					else
					{
						temp.Replace("%CPRODUCTSN",this->m_csPSN.Left(m_csPSN.GetLength()-1)+">6"+m_csPSN.Right(1));
					}
				}
*/
				//temp.Replace("%CPRODUCTSN",this->m_csPSN);
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("%CPCBSN")!=-1)
			{
				temp.Replace("%CPCBSN",this->m_csSN.Left(m_csSN.GetLength()-1)+">6"+m_csSN.Right(1));
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("%CBT")!=-1)
			{
				temp.Replace("%CBT",this->m_csBT.Left(m_csBT.GetLength()-1)+">6"+m_csBT.Right(1));
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("%CMAC")!=-1)
			{
				temp.Replace("%CMAC",this->m_csMAC.Left(m_csMAC.GetLength()-1)+">6"+m_csMAC.Right(1));
				CommandBuff+=temp;
				continue;
			}
			if(temp.Find("%Net")!=-1)
			{
				temp.Replace("%Net",this->m_csNet);
				CommandBuff+=temp;
				continue;
			}
			
			CommandBuff+=temp;
		}

		fp.Close();
		fp1.Open("c:\\resource.txt",CFile::modeWrite | CFile::typeBinary| CFile::modeCreate);
		fp1.WriteString(CommandBuff);
		fp1.Close();
	}
	   
	   return TRUE;
}

BOOL CColorBoxView::GoToPrint()
{
	if(m_PrintNum==1)
	{
		ShellExecute(AfxGetMainWnd()->GetSafeHwnd(), "open", "c:\\temp.bat", NULL, NULL, SW_HIDE );
	}
	if(m_PrintNum==2)
	{
		ShellExecute(AfxGetMainWnd()->GetSafeHwnd(), "open", "c:\\temp.bat", NULL, NULL, SW_HIDE );
		Sleep(700);
		ShellExecute(AfxGetMainWnd()->GetSafeHwnd(), "open", "c:\\temp.bat", NULL, NULL, SW_HIDE );
	}
	if(m_PrintNum==3)
	{
		ShellExecute(AfxGetMainWnd()->GetSafeHwnd(), "open", "c:\\temp.bat", NULL, NULL, SW_HIDE );
		Sleep(700);
		ShellExecute(AfxGetMainWnd()->GetSafeHwnd(), "open", "c:\\temp.bat", NULL, NULL, SW_HIDE );
		Sleep(700);
		ShellExecute(AfxGetMainWnd()->GetSafeHwnd(), "open", "c:\\temp.bat", NULL, NULL, SW_HIDE );
	}
	if(m_PrintNum==4)
	{
		ShellExecute(AfxGetMainWnd()->GetSafeHwnd(), "open", "c:\\temp.bat", NULL, NULL, SW_HIDE );
		Sleep(700);
		ShellExecute(AfxGetMainWnd()->GetSafeHwnd(), "open", "c:\\temp.bat", NULL, NULL, SW_HIDE );
		Sleep(700);
		ShellExecute(AfxGetMainWnd()->GetSafeHwnd(), "open", "c:\\temp.bat", NULL, NULL, SW_HIDE );
		Sleep(700);
		ShellExecute(AfxGetMainWnd()->GetSafeHwnd(), "open", "c:\\temp.bat", NULL, NULL, SW_HIDE );
	}
	if(m_PrintNum==5)
	{
		ShellExecute(AfxGetMainWnd()->GetSafeHwnd(), "open", "c:\\temp.bat", NULL, NULL, SW_HIDE );
		Sleep(700);
		ShellExecute(AfxGetMainWnd()->GetSafeHwnd(), "open", "c:\\temp.bat", NULL, NULL, SW_HIDE );
		Sleep(700);
		ShellExecute(AfxGetMainWnd()->GetSafeHwnd(), "open", "c:\\temp.bat", NULL, NULL, SW_HIDE );
		Sleep(700);
		ShellExecute(AfxGetMainWnd()->GetSafeHwnd(), "open", "c:\\temp.bat", NULL, NULL, SW_HIDE );
		Sleep(700);
		ShellExecute(AfxGetMainWnd()->GetSafeHwnd(), "open", "c:\\temp.bat", NULL, NULL, SW_HIDE );
	}

	return TRUE;
}


int CColorBoxView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	CSplashWnd::ShowSplashScreen(this);
	
	return 0;
}

void CColorBoxView::OnPrint1() 
{
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_2, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_3, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_4, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_5, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_1, MF_BYCOMMAND | MF_CHECKED );
	this->m_PrintNum=1;
}

void CColorBoxView::OnPrint2() 
{
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_1, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_3, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_4, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_5, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_2, MF_BYCOMMAND | MF_CHECKED ); 
	this->m_PrintNum=2;
}

void CColorBoxView::OnPrint3() 
{
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_1, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_2, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_4, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_5, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_3, MF_BYCOMMAND | MF_CHECKED ); 
	this->m_PrintNum=3;
}

void CColorBoxView::OnPrint4() 
{
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_1, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_2, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_3, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_5, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_4, MF_BYCOMMAND | MF_CHECKED ); 
	this->m_PrintNum=4;
}

void CColorBoxView::OnPrint5() 
{
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_1, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_2, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_3, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_4, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_PRINT_5, MF_BYCOMMAND | MF_CHECKED );
	this->m_PrintNum=5;
}

void CColorBoxView::OnUpdateData(WPARAM wParam, LPARAM lParam) 
{ 
	UpdateData(wParam); 
}


void CColorBoxView::OnSetMyFocus(WPARAM wParam, LPARAM lParam)
{
	CEdit* a;
	a=(CEdit*)wParam;
	a->SetFocus();
}


bool CColorBoxView::GetProductOrderInfo()
{
	CString temp;
	_variant_t var;
	CString sql;

	try
	{
		sql.Format("select * from ProductList where Enable=1 and OrderName='%s'",m_csCurrentOrder);
		
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("ProductName");
			temp=VariantToCString(var);
			this->m_csCurrentProduct= temp;

			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("IMEIType");
			this->m_iIMEIType=var.intVal;

			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("IMEIRangeType");
			this->m_iIMEIRangeType=var.intVal;

			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1_STR");
			temp=VariantToCString(var);
			this->m_imei1_start= temp;

			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1_END");
			temp=VariantToCString(var);
			this->m_imei1_end= temp;

			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("IMEI2_STR");
			temp=VariantToCString(var);
			this->m_imei2_start= temp;

			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("IMEI2_END");
			temp=VariantToCString(var);
			this->m_imei2_end= temp;

			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("IMEI3_STR");
			temp=VariantToCString(var);
			this->m_imei3_start= temp;

			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("IMEI3_END");
			temp=VariantToCString(var);
			this->m_imei3_end= temp;

			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("IMEI4_STR");
			temp=VariantToCString(var);
			this->m_imei4_start= temp;

			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("IMEI4_END");
			temp=VariantToCString(var);
			this->m_imei4_end= temp;

			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("Color");
			temp=VariantToCString(var);
			this->m_csCurrentColor= temp;

		}
		else
		{
			return FALSE;
		}
		
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	try
	{
		sql.Format("select * from SettingList where Enable=1 and OrderName='%s'",m_csCurrentOrder);
		
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("PSNCheckBit");
			temp=VariantToCString(var);
			this->m_csPSNStatic=temp;

			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("ScanNetCode");
			this->m_bScanNetCode=var.intVal;

			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("NetCodeLength");
			this->m_iNetCodeLength=var.intVal;

			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("NetCodeHeader");
			temp=VariantToCString(var);
			this->m_csNetCodeHeader=temp;
		}
		else
		{
			return FALSE;
		}
		
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	} 
	
	return TRUE;
}

bool CColorBoxView::Load_Current_Product_Count()
{

	CString temp,states;
	_variant_t var;
	CString sql;
	sql.Format("select count(*) as COUNT from %s_%s_ColorBox WHERE (Status = 2 or Status=3 or Status=4) AND (Enable = 1)",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder);

	try
	{
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			this->m_csCurrentCount= temp;
		}
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	
	return TRUE;
}


void CColorBoxView::UpdateCount(CString strCount)
{
	CString temp;
	temp="Quantity:"+strCount;
	this->m_cCurrentCount.SetWindowText(temp);
	UpdateData(FALSE);
}


void CColorBoxView::OnScanMainImeiYes() 
{
	
	CPassword dlg;
	dlg.ilevel = 1; //需超级权限验证
	if(dlg.DoModal()!=IDOK)
		return;

	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_MAIN_IMEI_YES, MF_BYCOMMAND | MF_CHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_MAIN_IMEI_NO, MF_BYCOMMAND | MF_UNCHECKED );

	this->m_Config.m_iIsScanMainImei=1;
	this->m_Config.SaveConfig();
}


void CColorBoxView::OnScanMainImeiNo() 
{

	CPassword dlg;
	dlg.ilevel = 1; //需超级权限验证
	if(dlg.DoModal()!=IDOK)
		return;
	
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_MAIN_IMEI_YES, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_MAIN_IMEI_NO, MF_BYCOMMAND | MF_CHECKED );
	
	this->m_Config.m_iIsScanMainImei=0;
	this->m_Config.SaveConfig();
}


void CColorBoxView::PlayWarningTone(CString Path)
{
	PlaySound((LPCSTR)(LPCTSTR)Path, NULL, SND_FILENAME | SND_ASYNC);  
}


void CColorBoxView::calculate_15_digit_imei( char *imei_14,char &calculate_digit)
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

void CColorBoxView::OnSetting() 
{
	CPassword dlg;
	dlg.ilevel = 1; //需超级权限验证
	if(dlg.DoModal()!=IDOK)
		return;

	CPrintSetting Pdlg;
	Pdlg.csLocalPath = (this->m_csLocalPath)+"\\ColorResource.txt";
	Pdlg.DoModal();
}

void CColorBoxView::OnChangeEditNetcode() 
{
	m_iFirstKeyTime = GetTickCount();
	if(m_csNet.GetLength() != 0)
	{
		m_iKeyPeriod = m_iFirstKeyTime - m_iLastKeyTime;
		if(m_iKeyPeriod > 100)
		{   
			PlayWarningTone(m_csErrorSndPath);
			InsertListInfo("Please use the scan gun input!",2);
			m_csNet.Empty();
			UpdateData(FALSE);
			m_ctrNet.SetFocus();	
			return;
		}
	}
	m_iLastKeyTime = m_iFirstKeyTime;
	
	SendMessage(WM_UPDATEDATA, TRUE, FALSE);

	if(m_csNet.Right(2)=="\r\n")
	{
		m_csNet.Replace("\r\n","");
		SendMessage(WM_UPDATEDATA, FALSE, FALSE);
		
		if(!CheckNetCode())
		{
			PlayWarningTone(m_csErrorSndPath);
			m_ctrNet.SetFocus();
			m_ctrNet.SetSel(0,-1);
			return;
		}
		
		if(this->m_Config.m_iHandleMode==1)//扫描模式
		{
			if (m_bCheckColorBoxCode)
			{
				this->m_ctrColorBoxCode.SetFocus();
				this->m_ctrColorBoxCode.SetSel(0,-1);
			}
			else
			{
				this->PrintLabel();
				this->ClearUI();
				m_ctrIMEI1.SetFocus();
				m_ctrIMEI1.SetSel(0,-1);
			}
		}
	}
}


BOOL CColorBoxView::CheckNetCode()
{  
	 
	//检测网标长度
	if(m_csNet.GetLength() != m_iNetCodeLength)
	{
		InsertListInfo("NetCode号码长度出错...",2);
		this->m_ctrNet.SetSel(0,-1);
		return FALSE;
	}
	
	//检测网标是否合法
	if(m_csNet.Left(m_csNetCodeHeader.GetLength()) != m_csNetCodeHeader)
	{
		InsertListInfo("NetCode Header 出错...",2);
		this->m_ctrNet.SetSel(0,-1);
		return FALSE;
	}
	
	//检测网标是否存在
	
	CString temp;
	_variant_t var;
	CString sql;

	try
	{
		sql.Format("select * from %s_%s_ColorBox where NetCode='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,(char*)(LPCTSTR)m_csCurrentOrder,(char*)(LPCTSTR)m_csNet);
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
		((CColorBoxApp *)AfxGetApp())->m_pRst=((CColorBoxApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CColorBoxApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CColorBoxApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1");
			temp=VariantToCString(var);

			if(this->m_csIMEI1==temp)
			{
				if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
					((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
				return TRUE;
			}
			else
			{
				InsertListInfo("NetCode is already exist in the giftbox Server...",2);
				this->m_ctrNet.SetSel(0,-1);
				return FALSE;
			}
		}
		if(((CColorBoxApp *)AfxGetApp())->m_pRst->State)
			((CColorBoxApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		this->m_ctrNet.SetSel(0,-1);
		return FALSE;
	}

	return TRUE;
}

void CColorBoxView::OnCheckPsnStatic() 
{
	UpdateData();
	bool flag;

	flag = m_bPSNStatic;

	CPassword dlg;
	dlg.ilevel = 1; //需超级权限验证
	if(dlg.DoModal()!=IDOK)
	{
		m_ctrPSNStatic.SetCheck(!flag);
		return;
	}
}
