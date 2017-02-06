// PACKView.cpp : implementation of the CPACKView class
//

#include "stdafx.h"
#include "PACK.h"
#include "Splash.h"
#include "PACKDoc.h"
#include "PACKView.h"
#include "MainFrm.h"
#include "EspeBox.h"
#include "Delete.h"
#include <math.h>
#include "CartonBoxPrint.h"
#include "Password.h"
#include "PopMessageBox.h"
#include "PopMainCarton.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define USB_KEY             0

/////////////////////////////////////////////////////////////////////////////
// CPACKView

IMPLEMENT_DYNCREATE(CPACKView, CFormView)

BEGIN_MESSAGE_MAP(CPACKView, CFormView)
	//{{AFX_MSG_MAP(CPACKView)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BTN_ESPE_BOX, OnBtnEspeBox)
	ON_BN_CLICKED(IDC_BTN_CLOSE, OnBtnClose)
	ON_BN_CLICKED(IDC_BTN_DISCARD, OnBtnDiscard)
	ON_EN_CHANGE(IDC_EDIT_CARTON, OnChangeEditCarton)
	ON_BN_CLICKED(IDC_BTN_PRINT, OnBtnPrint)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BTN_SETTING, OnBtnSetting)
	ON_BN_CLICKED(IDC_BTN_CHECK, OnBtnCheck)
	ON_BN_CLICKED(IDC_BTN_CLEAR, OnBtnClear)
	ON_BN_CLICKED(IDC_BTN_DELETE, OnBtnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPACKView construction/destruction

CPACKView::CPACKView()
	: CFormView(CPACKView::IDD)
{
	//{{AFX_DATA_INIT(CPACKView)
	m_csCurrentProduct = _T("");
	m_csCarton = _T("");
	m_csCurrentColor = _T("");
	m_csCurrentOrder = _T("");
	m_csCurrentLine = _T("");
	//}}AFX_DATA_INIT
	m_showState=FALSE;
}

CPACKView::~CPACKView()
{
}

void CPACKView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPACKView)
	DDX_Control(pDX, IDC_BTN_DELETE, m_ctrDelete);
	DDX_Control(pDX, IDC_BTN_CLEAR, m_ctrClear);
	DDX_Control(pDX, IDC_BTN_CHECK, m_ctrCheck);
	DDX_Control(pDX, IDC_BTN_SETTING, m_ctrSetting);
	DDX_Control(pDX, IDC_STATIC_CURRENT_LINE, m_ctrCurrentLine);
	DDX_Control(pDX, IDC_STATIC_CURRENT_COUNT, m_cCurrentCount);
	DDX_Control(pDX, IDC_STATIC_CURRENT_ORDER, m_ctrCurrentOrder);
	DDX_Control(pDX, IDC_STATIC_CURRENT_COLOR, m_ctrCurrentColor);
	DDX_Control(pDX, IDC_BTN_PRINT, m_ctrBtnPrint);
	DDX_Control(pDX, IDC_BTN_ESPE_BOX, m_ctrBtnEspeBox);
	DDX_Control(pDX, IDC_BTN_DISCARD, m_ctrBtnDiscard);
	DDX_Control(pDX, IDC_BTN_CLOSE, m_ctrBtnClose);
	DDX_Control(pDX, IDC_EDIT_CARTON, m_ctrCarton);
	DDX_Control(pDX, IDC_STATIC_CURRENT_PRODUCT, m_ctrCurrentProduct);
	DDX_Control(pDX, IDC_LIST_STATE, m_state_list);
	DDX_Control(pDX, IDC_FLEX, m_flex);
	DDX_Text(pDX, IDC_STATIC_CURRENT_PRODUCT, m_csCurrentProduct);
	DDX_Text(pDX, IDC_EDIT_CARTON, m_csCarton);
	DDX_Text(pDX, IDC_STATIC_CURRENT_COLOR, m_csCurrentColor);
	DDX_Text(pDX, IDC_STATIC_CURRENT_ORDER, m_csCurrentOrder);
	DDX_Text(pDX, IDC_STATIC_CURRENT_LINE, m_csCurrentLine);
	//}}AFX_DATA_MAP
}

BOOL CPACKView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CPACKView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	CreateTwoFile();

	//设置字体
	this->SetMyFont();
	
	//初始化ini文件
	this->m_Config.InitConfigPath();
	
	this->m_Config.ReadConfig();
	
	m_csCurrentOrder = ((CPACKApp *)AfxGetApp())->InputOrder;
	m_csCurrentLine  = ((CPACKApp *)AfxGetApp())->InputProductionLine;
	
	//获取项目订单信息
	if(!this->GetProductOrderInfo())
	{
		InsertListInfo("Access to project orders information failure...",2);
		return;
	}
	else
	{
		UpdateData(FALSE);
		InsertListInfo("To obtain project orders information success...",0);
	}
	
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
	DeleteFile(m_csLocalPath+"\\PalletResource.txt");
	DeleteFile(m_csLocalPath+"\\PalletResource_Sub.txt");
	
	//获取服务器打印模板文件存放路径
	csCFGPath = this->m_Config.m_csCFGPath+m_csCurrentProduct+"_"+m_csCurrentOrder+"\\config\\PalletResource.txt";
	//从服务器copy PalletResource.txt文件至本地
	temp.Format("/c xcopy %s %s /e /i /y", csCFGPath, m_csLocalPath);
	hInstance = ShellExecute(AfxGetMainWnd()->GetSafeHwnd(),"open","cmd.exe",temp,NULL,SW_HIDE);
	iRet = int(hInstance);
	if (iRet < 32)
	{
		MessageBox("Copy PalletResource.txt Fail!","Error",MB_OK);
		exit(0);
	}

	//获取服务器打印模板文件存放路径
	csCFGPath = this->m_Config.m_csCFGPath+m_csCurrentProduct+"_"+m_csCurrentOrder+"\\config\\PalletResource_Sub.txt";
	//从服务器copy PalletResource_Sub.txt文件至本地
	temp.Format("/c xcopy %s %s /e /i /y", csCFGPath, m_csLocalPath);
	hInstance = ShellExecute(AfxGetMainWnd()->GetSafeHwnd(),"open","cmd.exe",temp,NULL,SW_HIDE);
	iRet = int(hInstance);
	if (iRet < 32)
	{
		MessageBox("Copy PalletResource_Sub.txt Fail!","Error",MB_OK);
		exit(0);
	}
	
	//启动定时器
	this->SetTimer(1,500,0);
}

/////////////////////////////////////////////////////////////////////////////
// CPACKView diagnostics

#ifdef _DEBUG
void CPACKView::AssertValid() const
{
	CFormView::AssertValid();
}

void CPACKView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CPACKDoc* CPACKView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPACKDoc)));
	return (CPACKDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPACKView message handlers
void CPACKView::CreateTwoFile()
{
	CFile m_file;
	m_file.Open("c:\\temp.bat",CFile::modeCreate|CFile::modeWrite);
//	m_file.Write("copy c:\\resource.txt lpt1",strlen("copy c:\\resource.txt lpt1")); 
	m_file.Write("print /d:com1 c:\\resource.txt",strlen("print /d:com1 c:\\resource.txt"));  
	m_file.Close();
	m_file.Open("c:\\resource.txt",CFile::modeCreate|CFile::modeWrite);  
	m_file.Close();
}


void CPACKView::OnTimer(UINT nIDEvent) 
{
	CString temp;

	if(nIDEvent == 1)
	{
		this->KillTimer(1);
		CFormView::OnTimer(nIDEvent);
		
		//读取配置文件
		this->m_Config.ReadConfig();

		//灰掉控件
		this->SetUIDisableAll();
		
		//设置FLEX格数
		this->SetRowCol(this->m_iPalletMaxCount+1,6);
		this->SetNumText(this->m_iPalletMaxCount+1);
		
		//显示MAXCOUNT
		CMainFrame *pFrame=(CMainFrame*)GetParentFrame();
		temp.Format("Standard quantity: %d",this->m_iPalletMaxCount);
		pFrame->m_wndStatusBar.SetPaneText(2,temp);
		
		//显示CURRENTCOUNT
		temp.Format("Current quantity: %d",0);
		pFrame->m_wndStatusBar.SetPaneText(3,temp);
		
		//获取当前栈板号
		if(!Get_Current_Pallet_Name())
		{
			InsertListInfo("Get the current project to the pallet, failure...!",2);
		}
		else
		{
			temp.Format("Pallet Number: %s%s",this->m_csPalletNameStatic,this->m_csPalletName);
			pFrame->m_wndStatusBar.SetPaneText(1,temp);
		}
		
		//显示当前总数
		if(!this->Load_Current_Product_Count())
		{
			InsertListInfo("To obtain the number of current orders has failed",2);
			return;
		}
		InsertListInfo("Obtain the number of current orders has been successful",0);
		this->UpdateCount(this->m_csCurrentCount);
		
		UpdateData(FALSE);

		this->m_ctrCarton.EnableWindow(TRUE);
		this->m_ctrBtnEspeBox.EnableWindow(TRUE);
		this->m_ctrBtnDiscard.EnableWindow(TRUE);
		this->m_ctrBtnClose.EnableWindow(TRUE);
		this->m_ctrBtnPrint.EnableWindow(TRUE);
		this->m_ctrCheck.EnableWindow(TRUE);
		this->m_ctrClear.EnableWindow(FALSE);
		this->m_ctrClear.ShowWindow(SW_HIDE);
		this->m_ctrDelete.EnableWindow(FALSE);

		this->m_ctrCarton.SetFocus();
	}
}


void CPACKView::SetMyFont()
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
	Column.cx =   600;
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

	m_ctrBtnEspeBox.SetIcon(IDI_ICON1);
	m_ctrBtnEspeBox.SetActiveFgColor(RGB(0,0,255));

	m_ctrBtnDiscard.SetIcon(IDI_ICON3);
	m_ctrBtnDiscard.SetActiveFgColor(RGB(0,0,255));

	m_ctrBtnClose.SetIcon(IDI_ICON2);
	m_ctrBtnClose.SetActiveFgColor(RGB(0,0,255));

	m_ctrBtnPrint.SetIcon(IDI_ICON4);
	m_ctrBtnPrint.SetActiveFgColor(RGB(0,0,255));

	m_ctrSetting.SetIcon(IDI_ICON6);
	m_ctrSetting.SetActiveFgColor(RGB(0,0,255));

	m_ctrCheck.SetIcon(IDI_ICON7);
	m_ctrCheck.SetActiveFgColor(RGB(0,0,255));

	m_ctrClear.SetIcon(IDI_ICON8);
	m_ctrClear.SetActiveFgColor(RGB(0,0,255));

	m_ctrDelete.SetIcon(IDI_ICON9);
	m_ctrDelete.SetActiveFgColor(RGB(0,0,255));

	VERIFY(m_staticfont.CreateFont(
		30,                        // nHeight
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
		"MS Sans Serif"));                 // lpszFacename

	CMainFrame *pFrame=(CMainFrame*)GetParentFrame();
	pFrame->m_wndStatusBar.SetFont(&m_staticfont);
}


void CPACKView::SetUIDisableAll()
{
	this->m_ctrCarton.EnableWindow(FALSE);
	this->m_ctrBtnEspeBox.EnableWindow(FALSE);
	this->m_ctrBtnDiscard.EnableWindow(FALSE);
	this->m_ctrBtnClose.EnableWindow(FALSE);
	this->m_ctrBtnPrint.EnableWindow(FALSE);
	this->m_ctrCheck.EnableWindow(FALSE);
	this->m_ctrClear.EnableWindow(FALSE);
	this->m_ctrClear.ShowWindow(SW_HIDE);
	this->m_ctrDelete.EnableWindow(FALSE);
}


void CPACKView::InsertListInfo(CString state,int imageIndex)
{
	CString date;
	date=GetCurTimes();
	m_state_list.InsertItem(m_state_list.GetItemCount(),date,imageIndex);
	m_state_list.SetItemText(m_state_list.GetItemCount()-1,1,state);
	m_state_list.EnsureVisible(m_state_list.GetItemCount()-1,TRUE);
}


CString CPACKView::GetCurTimes()
{
	CTime t=CTime::GetCurrentTime();
	CString str=t.Format( "%Y-%m-%d  %H:%M:%S");
	return str;
}


CString CPACKView::VariantToCString(VARIANT   var)   
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

 
void CPACKView::SetRowCol(int rows,int cols)
{
	m_flex.SetRows(rows);
	m_flex.SetCols(cols);
	
	m_flex.SetColWidth(0,280);  
	m_flex.SetColWidth(1,2000);//carton_name_static
	m_flex.SetColWidth(2,2000);//carton_name
	m_flex.SetColWidth(3,2000);//Pallet_static
	m_flex.SetColWidth(4,2000);//Pallet_name
	m_flex.SetColWidth(5,2000);//carton_Weigh
 
	//reset current row and col
	this->m_cur_row=1;
	this->m_cur_col=1;
}


void CPACKView::SetNumText(int rows)
{
	//设置FLEX居中
	for(int row=0;row<rows;row++)
	{
		m_flex.SetRow(row);
		m_flex.SetCol(1);
		m_flex.SetCellAlignment(4);
		
		m_flex.SetRow(row);
		m_flex.SetCol(2);
		m_flex.SetCellAlignment(4);
		
		m_flex.SetRow(row);
		m_flex.SetCol(3);
		m_flex.SetCellAlignment(4);

		m_flex.SetRow(row);
		m_flex.SetCol(4);
		m_flex.SetCellAlignment(4);

		m_flex.SetRow(row);
		m_flex.SetCol(5);
		m_flex.SetCellAlignment(4);
	}
	
	//设置序列号
	CString strT;
	for(int count=1;count<rows;count++)
	{
		strT.Format("%d",count);
		m_flex.SetTextMatrix(count,0,strT);
	}
	
	m_flex.SetTextMatrix(0,1,"卡通箱号固定位");
	m_flex.SetTextMatrix(0,2,"卡通箱号流水位");
	m_flex.SetTextMatrix(0,3,"栈板号固定位");
	m_flex.SetTextMatrix(0,4,"栈板号流水位");
	m_flex.SetTextMatrix(0,5,"卡通箱重量");
}


bool CPACKView::Get_Current_Pallet_Name()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	try
	{
		sql.Format("select * from %s_%s_Pallet ORDER BY PalletName DESC",this->m_csCurrentProduct,this->m_csCurrentOrder);
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(((CPACKApp *)AfxGetApp())->m_pRst->adoEOF) //空数据
		{
			CString cur="                       ";
			for(int counts=0;counts<m_iPalletNameLength-1;counts++)
			{
				cur.SetAt(counts,'0');
			}
			cur.SetAt(m_iPalletNameLength-1,'1');
			m_csPalletName=cur.Left(m_iPalletNameLength);
		}
		else
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("PalletName");
			temp=VariantToCString(var);
			m_csPalletName=temp;
			CurrentAdd(m_csPalletName,10);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}


//每次扫入第一个数据时重新查找栈板号
bool CPACKView::ReGet_Current_Pallet_Name()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	try
	{
		sql.Format("select * from %s_%s_Pallet ORDER BY PalletName DESC",this->m_csCurrentProduct,this->m_csCurrentOrder);
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(((CPACKApp *)AfxGetApp())->m_pRst->adoEOF) //空数据
		{
			CString cur="                       ";
			for(int counts=0;counts<m_iPalletNameLength-1;counts++)
			{
				cur.SetAt(counts,'0');
			}
			cur.SetAt(m_iPalletNameLength-1,'1');
			m_csReGet_PalletName=cur.Left(m_iPalletNameLength);
		}
		else
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("PalletName");
			temp=VariantToCString(var);
			m_csReGet_PalletName=temp;
			CurrentAdd(m_csReGet_PalletName,10);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}	

	return TRUE;
}


void CPACKView::CurrentAdd(CString& current,UINT step) 
{ 
	int i = current.GetLength(); 
	long l = strtol((LPSTR)(LPCTSTR)current, NULL, step); 
	l++; //增1; 
	char buf[33]; 
	ltoa(l, buf, step); 
	CString fmt; fmt.Format("%%0%ds", i); 
	current.Format(fmt, buf); 
	current.MakeUpper();
} 


void CPACKView::OnBtnEspeBox() 
{
	CPassword psw;
	psw.ilevel = 1; //需超级权限验证
	if(IDOK!=psw.DoModal())
		return;

	CEspeBox dlg;
	dlg.m_csPalletNameStatic = this->m_csPalletNameStatic;
	if(IDOK!=dlg.DoModal())
		return;

	CString temp;
	_variant_t var;
	CString sql;
	double dWeigh;

	try
	{
		sql.Format("select * from %s_%s_Pallet where PalletName='%s' and Status=1",this->m_csCurrentProduct,this->m_csCurrentOrder,dlg.m_csEspeBoxName);
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(((CPACKApp *)AfxGetApp())->m_pRst->adoEOF) //空数据
		{
			CString strMsg;
			strMsg.Format("Invalid pallet number or Have finished packing \'%s%s\' !",this->m_csPalletNameStatic,dlg.m_csEspeBoxName);
			InsertListInfo(strMsg,2);
			return;
		}
		else
		{
			//获取当前栈板号以备后续继续插入使用
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("PalletName");
			temp=VariantToCString(var);
			m_csPalletName=temp;
			
			//显示当前栈板号
			CMainFrame *pFrame=(CMainFrame*)GetParentFrame();
			temp.Format("Pallet Number: %s%s",this->m_csPalletNameStatic,this->m_csPalletName);
			pFrame->m_wndStatusBar.SetPaneText(1,temp);

			//========================未封栈板处理====================
			this->m_csaCartonName.RemoveAll();
			this->m_csaWeigh.RemoveAll();

			this->m_flex.Clear();
			SetNumText(m_flex.GetRows());

			//=================获取所有信息并保存到Array中============
			sql.Format("select * from %s_%s_CartonBox where PalletName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,dlg.m_csEspeBoxName);
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
			((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
			{	
				var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonName");
				temp=VariantToCString(var);
				m_csaCartonName.Add(temp);

				var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonWeigh");
				temp=VariantToCString(var);
				m_csaWeigh.Add(temp);
				
				((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
			}

			//插入信息到flex
			for(int i=0 ; i<m_csaCartonName.GetSize() ;i++)
			{
				m_flex.SetTextMatrix(i+1,1,this->m_csCartonNameStatic);
				m_flex.SetTextMatrix(i+1,2,m_csaCartonName.GetAt(i));
				m_flex.SetTextMatrix(i+1,3,this->m_csPalletNameStatic);
				m_flex.SetTextMatrix(i+1,4,this->m_csPalletName);
				dWeigh=atof((char*)(LPCTSTR)m_csaWeigh.GetAt(i));
				temp.Format("%.1lf",dWeigh);
				m_flex.SetTextMatrix(i+1,5,temp);
			}

			//设置当前行数
			m_cur_row=m_csaCartonName.GetSize()+1;

			//删除箱号按钮可用
			this->m_ctrDelete.EnableWindow(TRUE);

			//设置当前栈板号数量
			temp.Format("Current quantity:%d",m_csaCartonName.GetSize());
			pFrame->m_wndStatusBar.SetPaneText(3,temp);

			temp.Format("Specific pallet No.\'%s%s\' Call success ,This is not the pallet packing is completed, you can continue!", this->m_csPalletNameStatic,dlg.m_csEspeBoxName);
			InsertListInfo(temp,1);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
	}
}


void CPACKView::OnBtnClose() 
{
	CPassword psw;
	psw.ilevel = 1; //需超级权限验证
	if(IDOK!=psw.DoModal())
		return;

	if(m_csaCartonName.GetSize()==0)
	{
		InsertListInfo("The packing number can not be sealed or the use of specific pallet pallet, call re sealed pallet...",2);
		return;
	}


	if(IDYES!=MessageBox("Sure you want to do this to enforce the pallet?","Prompt",MB_ICONQUESTION |MB_YESNO))
	{
		return;
	}

	CString temp;
	_variant_t var;
	CString sql;

	//Update block_id to 1
	try
	{
		sql.Format("UPDATE %s_%s_Pallet SET Status=2 where PalletName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csPalletName);
		((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		return;
	}

	this->m_csaCartonName.RemoveAll();
	this->m_csaWeigh.RemoveAll();
	
	this->m_flex.Clear();
	SetNumText(m_flex.GetRows()); 
	m_cur_row=1;

	//删除箱号按钮不可用
	this->m_ctrDelete.EnableWindow(FALSE);

	CMainFrame *pFrame=(CMainFrame*)GetParentFrame();
	temp.Format("Current quantity:%d",0);
	pFrame->m_wndStatusBar.SetPaneText(3,temp);
	
	temp.Format("\'%s\' Successfully sealed pallet!",m_csPalletName);
	InsertListInfo(temp,0);
	
	//获取当前栈板号
	if(!Get_Current_Pallet_Name())
	{
		InsertListInfo("Get the current project to the pallet, failure...!",0);
	}
	else
	{
		temp.Format("Pallet Number: %s%s",this->m_csPalletNameStatic,this->m_csPalletName);
		pFrame->m_wndStatusBar.SetPaneText(1,temp);
	}
}


void CPACKView::OnBtnDiscard()
{
	CPassword psw;
	psw.ilevel = 1; //需超级权限验证
	if(IDOK!=psw.DoModal())
		return;

	CEspeBox dlg;
	dlg.m_csPalletNameStatic=this->m_csPalletNameStatic;
	if(IDOK!=dlg.DoModal())
		return;

	CString temp;
	_variant_t var;
	CString sql;

	//检查栈板号是否存在
	try
	{
		sql.Format("select * from %s_%s_Pallet where PalletName='%s' and Status=2",this->m_csCurrentProduct,this->m_csCurrentOrder,dlg.m_csEspeBoxName);
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			temp.Format("Invalid pallet number or Have finished packing\'%s%s\' !",this->m_csPalletNameStatic,dlg.m_csEspeBoxName);
			InsertListInfo(temp,2);
			return;
			
		}
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		return;
	}

	if(IDYES!=MessageBox("Are you Sure to be scrapped this pallet?","Prompt",MB_ICONQUESTION |MB_YESNO))
	{
		return;
	}
	//报废栈板号
	//Update block_id to 2
	try
	{
		sql.Format("UPDATE %s_%s_Pallet SET Status=0 where PalletName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,dlg.m_csEspeBoxName);
		((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		return;
	}

	//当前箱号报废重置参数
	if(dlg.m_csEspeBoxName==this->m_csPalletName)
	{

		this->m_csaCartonName.RemoveAll();
		this->m_csaWeigh.RemoveAll();
		
		this->m_flex.Clear();
		SetNumText(m_flex.GetRows()); 
		m_cur_row=1;

		CMainFrame *pFrame=(CMainFrame*)GetParentFrame();
		temp.Format("Current quantity:%d",0);
		pFrame->m_wndStatusBar.SetPaneText(3,temp);

		//获取当前栈板号
		if(!Get_Current_Pallet_Name())
		{
			InsertListInfo("Get the current project to the pallet, failure...!",0);
		}
		else
		{
			temp.Format("Pallet Number: %s%s",this->m_csPalletNameStatic,this->m_csPalletName);
			pFrame->m_wndStatusBar.SetPaneText(1,temp);
		}
	}

	temp.Format("\'%s\' Has been successfully scrapped!",dlg.m_csEspeBoxName);
	InsertListInfo(temp,0);		// TODO: Add your control notification handler code here
	
}


void CPACKView::calculate_15_digit_imei( char *imei_14,char &calculate_digit)
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


void CPACKView::OnChangeEditCarton()
{
	UpdateData();
	CString temp;
	double dWeigh;
	
	if(m_csCarton.Right(2)=="\r\n")
	{
		m_csCarton.Replace("\r\n","");
		UpdateData(FALSE);
		//判断卡通箱号合法性
		if(!CheckCartonName())
		{
			m_ctrCarton.SetFocus();
			m_ctrCarton.SetSel(0,-1);
			PopMessageBox_Ex();
			return;
		}
		else
		{
			InsertListInfo("Carton legal number!",0);
		}

		//删除箱号按钮可用
		this->m_ctrDelete.EnableWindow(TRUE);
		
		//插入数据库
		if(!this->InsertDataToSQL_Ex())
		{
			PopMessageBox_Ex();
			return;
		}
		
		//显示到FLEX
		m_flex.SetTextMatrix(m_cur_row,1,m_csCurrent_CartonStatic);
		m_flex.SetTextMatrix(m_cur_row,2,m_csCurrent_Carton);	
		m_flex.SetTextMatrix(m_cur_row,3,m_csPalletNameStatic);
		m_flex.SetTextMatrix(m_cur_row,4,m_csPalletName);
		
		dWeigh=atof((char*)(LPCTSTR)this->m_csWeigh);
		m_csWeigh.Format("%.1lf",dWeigh);
		m_flex.SetTextMatrix(m_cur_row,5,m_csWeigh);
		
		//清空卡通箱号录入框
		m_csCarton.Empty();

		UpdateData(FALSE);	
		this->m_ctrCarton.SetFocus();
		m_cur_row++;
		CMainFrame *pFrame=(CMainFrame*)GetParentFrame();
		temp.Format("Current quantity:%d",m_cur_row-1);
		pFrame->m_wndStatusBar.SetPaneText(3,temp);
		
		//显示当前总数
		if(!this->Load_Current_Product_Count())
		{
			InsertListInfo("To obtain the number of current orders has failed",2);
			return;
		}
		InsertListInfo("Obtain the number of current orders has been successful",0);
		this->UpdateCount(this->m_csCurrentCount);
		
		
		//检测是否满栈板
		if( m_cur_row-1 == this->m_iPalletMaxCount)
		{
			//更新Status值=2
			if(!UpdateStatusTo2())
			{
				InsertListInfo("A pallet failed, please contact the Engineer...",2);
			}
			
			temp.Format("Pallet Number: \'%s\' has Already packaged!",this->m_csPalletName);
			InsertListInfo(temp,0);
			PopMainCarton_Ex(temp);
			//弹出打印框
			OnBtnPrint();

			m_flex.Clear();
			SetNumText(m_flex.GetRows());
			m_cur_col=1;  
			m_cur_row=1;

			//删除箱号按钮不可用
			this->m_ctrDelete.EnableWindow(FALSE);

			temp.Format("Current quantity:%d",0);
			pFrame->m_wndStatusBar.SetPaneText(3,temp);
			
			//获取当前栈板号
			if(!Get_Current_Pallet_Name())
			{
				InsertListInfo("Get the current project to the pallet, failure...!",2);
			}
			else
			{
				temp.Format("Pallet Number: %s%s",this->m_csPalletNameStatic,this->m_csPalletName);
				pFrame->m_wndStatusBar.SetPaneText(1,temp);
			}
			
			//显示当前总数
			if(!this->Load_Current_Product_Count())
			{
				InsertListInfo("To obtain the number of current orders has failed",2);
				return;
			}
			InsertListInfo("Obtain the number of current orders has been successful",0);
			this->UpdateCount(this->m_csCurrentCount);
		}
	}
	
	return;	
}


bool CPACKView::CheckCartonName()
{
	CString temp,temp2;
	_variant_t var;
	CString sql;
	int iCartonNameStaticLength;

	//获取扫描的卡通箱号固定位和流水位
	iCartonNameStaticLength   = strlen(m_csCartonNameStatic);
	m_csCurrent_CartonStatic  = m_csCarton.Left(iCartonNameStaticLength);
	m_csCurrent_Carton        = m_csCarton.Right(m_csCarton.GetLength() - iCartonNameStaticLength);

	//检测卡通箱固定位
	if(m_csCurrent_CartonStatic != m_csCartonNameStatic)
	{
		InsertListInfo("Carton permanent position checks failed...",2);
		this->m_ctrCarton.SetSel(0,-1);
		return FALSE;
	}

	//检测该卡通箱是否已经包装
	try
	{
		sql.Format("select * from %s_%s_CartonBox where CartonName='%s' and PalletName IS NOT NULL",this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCurrent_Carton);
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("PalletName");
			temp=VariantToCString(var);
			temp2.Format("Carton %s is already exist in pallet :%s%s",m_csCarton,this->m_csPalletNameStatic,temp);
			this->m_ctrCarton.SetSel(0,-1);
			InsertListInfo(temp2,2);
			return FALSE;
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		this->m_ctrCarton.SetSel(0,-1);
		return FALSE;
	}
	
	//检查卡通箱号及是否包装完毕并封箱
	try
	{
		sql.Format("select *  from %s_%s_CartonBox where CartonName='%s' and Status=2",this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCurrent_Carton);
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			//卡通箱号存在于数据库中
			temp.Format("Carton %s Sealed box...",m_csCurrent_Carton);
			InsertListInfo(temp,0);
		}
		else
		{
			//数据库内无记录
			temp.Format("Carton %s not in the carton box database or not...",m_csCurrent_Carton);
			InsertListInfo(temp,2);
			return FALSE;
		}

		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
		((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		this->m_ctrCarton.SetSel(0,-1);
		return FALSE;
	}

	//根据卡通箱号从Carton中获取重量信息
	try
	{
		sql.Format("select * from %s_%s_CartonBox where CartonName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCurrent_Carton);
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonWeigh");
			m_csWeigh.Empty();	
			m_csWeigh=VariantToCString(var);

			//判断重量是否为空
			if(m_csWeigh=="")
			{
				this->m_ctrCarton.SetSel(0,-1);
				temp.Format("Carton %s Has Not weight information，Please check if the weighing station is leaking....",m_csCurrent_Carton);
				InsertListInfo(temp,2);
				return FALSE;
			}
		}

		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		this->m_ctrCarton.SetSel(0,-1);
		return FALSE;
	}

	return TRUE;
}


bool CPACKView::InsertDataToSQL_Ex()
{
	_variant_t var;
	CString sql;

	//抢栈板号start->如果是列表中的第一个数据那么重新获取一下数据库中的NEXT栈板号是否和之前获取的栈板号相同
	if(m_cur_row==1)
	{
		this->ReGet_Current_Pallet_Name();
		if(this->m_csReGet_PalletName != this->m_csPalletName)
		{
			CString temp;
			CMainFrame *pFrame=(CMainFrame*)GetParentFrame();
			this->m_csPalletName = this->m_csReGet_PalletName;
			temp.Format("Pallet Number: %s%s",this->m_csPalletNameStatic,this->m_csPalletName);
			pFrame->m_wndStatusBar.SetPaneText(1,temp);
		}

		//将栈板号插入到Pallet
		try
		{
			sql.Format("INSERT INTO %s_%s_Pallet (PalletName,Status) VALUES ('%s', %d)",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csPalletName,1);
			((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		}
		catch(_com_error e)
		{
			InsertListInfo("Save the record to the pallet database failed...",2);
			return FALSE;
		}
		
		InsertListInfo("Save the record to the pallet database successfully...",0);
	}
	//抢栈板号end	
	
	//将栈板号插入到CartonBox
	try
	{
		sql.Format("UPDATE %s_%s_CartonBox SET PalletName='%s' where CartonName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csPalletName,m_csCurrent_Carton);
		((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		InsertListInfo("Save the record to the carton box database failed...",2);
		return FALSE;
	}

	return TRUE;
}


bool CPACKView::UpdateStatusTo2()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	try
	{
		sql.Format("UPDATE %s_%s_Pallet SET Status=2 where PalletName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csPalletName);
		((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		return FALSE;
	}
	return TRUE;
}


void CPACKView::OnBtnPrint()
{
	CCartonBoxPrint CPDlg;

	CPDlg.m_csCurrentProduct     = this->m_csCurrentProduct;
	CPDlg.m_csCurrentOrder       = this->m_csCurrentOrder;
	CPDlg.m_csPalletNameStatic   = this->m_csPalletNameStatic;
	CPDlg.m_csPalletName         = this->m_csPalletName;
	CPDlg.csCartonNameStatic     = this->m_csCartonNameStatic;
	CPDlg.iPalletNameLength      = this->m_iPalletNameLength;
	CPDlg.iPalletMaxCount        = this->m_iPalletMaxCount;
	CPDlg.csProductionLine       = this->m_csCurrentLine;
	CPDlg.csLocalPathtemp        =  this->m_csLocalPath;

	CPDlg.DoModal();
}


int CPACKView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	CSplashWnd::ShowSplashScreen(this);
	
	return 0;
}


bool CPACKView::GetProductOrderInfo()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	try
	{
		sql.Format("select * from ProductList where Enable=1 and OrderName='%s'",m_csCurrentOrder);
		
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("ProductName");
			temp=VariantToCString(var);
			this->m_csCurrentProduct= temp;

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("Color");
			temp=VariantToCString(var);
			this->m_csCurrentColor= temp;

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonNameStatic");
			temp=VariantToCString(var);
			this->m_csCartonNameStatic= temp;

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonNameSNLength");
			this->m_iCartonNameLength=var.intVal;

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("PalletNameStatic");
			temp=VariantToCString(var);
			this->m_csPalletNameStatic= temp;

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("PalletNameSNLength");
			this->m_iPalletNameLength=var.intVal;

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("PalletMaxCount");
			this->m_iPalletMaxCount=var.intVal;
		}
		else
		{
			return FALSE;
		}
		
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	
	return TRUE;
}


bool CPACKView::Load_Current_Product_Count()
{
	CString temp,states;
	_variant_t var;
	CString sql;

	sql.Format("select count(*) as COUNT from %s_%s_Pallet WHERE Status = 2",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder);

	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			this->m_csCurrentCount= temp;
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;  
}


void CPACKView::UpdateCount(CString strCount)
{
	CString temp;
	temp="Quantity:"+strCount;
	this->m_cCurrentCount.SetWindowText(temp);
	UpdateData(FALSE);
}


void CPACKView::PopMessageBox_Ex()
{
	CPopMessageBox dlg;
	dlg.DoModal();
}


void CPACKView::PopMainCarton_Ex(CString strMainCarton)
{
	CPopMainCarton dlg;
	dlg.m_csMainCarton=strMainCarton;
	dlg.DoModal();
}

void CPACKView::OnBtnSetting() 
{
	CPassword dlg;
	dlg.ilevel = 1; //需超级权限验证
	if(dlg.DoModal()!=IDOK)
		return;

	CPrintSetting Pdlg;
	Pdlg.csLocalPath = this->m_csLocalPath;
	Pdlg.DoModal();	
}

BEGIN_EVENTSINK_MAP(CPACKView, CFormView)
    //{{AFX_EVENTSINK_MAP(CPACKView)
	ON_EVENT(CPACKView, IDC_FLEX, -600 /* Click */, OnClickFlex, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CPACKView::OnClickFlex()             //点击卡通箱号流水位，按升序排列
{
    long lRow = m_flex.GetRowSel();      //获取点击的行号
	long lCol = m_flex.GetColSel();      //获取点击的列号
	long m_lRow = m_flex.GetRows();      //获取当前已使用行数

	if (lRow == 1 && lCol == 2)
	{
		m_flex.SetRedraw(FALSE);
		m_flex.SetSort(2);               // 1为升序，2为降序
		m_flex.SetRedraw(TRUE);
	}
}

void CPACKView::OnBtnCheck() 
{
	CEspeBox dlg;
	dlg.m_csPalletNameStatic = this->m_csPalletNameStatic;
	if(IDOK!=dlg.DoModal())
		return;

	CString temp;
	_variant_t var;
	CString sql;
	double dWeigh;

	try
	{
		sql.Format("select * from %s_%s_Pallet where PalletName='%s' and Status=2",this->m_csCurrentProduct,this->m_csCurrentOrder,dlg.m_csEspeBoxName);
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(((CPACKApp *)AfxGetApp())->m_pRst->adoEOF) //空数据
		{
			CString strMsg;
			strMsg.Format("Invalid pallet number or Have finished packing \'%s%s\' !",this->m_csPalletNameStatic,dlg.m_csEspeBoxName);
			InsertListInfo(strMsg,2);
			return;
		}
		else
		{
			//获取当前栈板号以备后续继续插入使用
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("PalletName");
			temp=VariantToCString(var);
			m_csPalletName=temp;
			
			//显示当前栈板号
			CMainFrame *pFrame=(CMainFrame*)GetParentFrame();
			temp.Format("Pallet Number: %s%s",this->m_csPalletNameStatic,this->m_csPalletName);
			pFrame->m_wndStatusBar.SetPaneText(1,temp);

			this->m_csaCartonName.RemoveAll();
			this->m_csaWeigh.RemoveAll();

			this->m_flex.Clear();
			SetNumText(m_flex.GetRows());

			//=================获取所有信息并保存到Array中============
			sql.Format("select * from %s_%s_CartonBox where PalletName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,dlg.m_csEspeBoxName);
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
			((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
			{	
				var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonName");
				temp=VariantToCString(var);
				m_csaCartonName.Add(temp);

				var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonWeigh");
				temp=VariantToCString(var);
				m_csaWeigh.Add(temp);
				
				((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
			}

			//插入信息到flex
			for(int i=0 ; i<m_csaCartonName.GetSize() ;i++)
			{
				m_flex.SetTextMatrix(i+1,1,this->m_csCartonNameStatic);
				m_flex.SetTextMatrix(i+1,2,m_csaCartonName.GetAt(i));
				m_flex.SetTextMatrix(i+1,3,this->m_csPalletNameStatic);
				m_flex.SetTextMatrix(i+1,4,this->m_csPalletName);
				dWeigh=atof((char*)(LPCTSTR)m_csaWeigh.GetAt(i));
				temp.Format("%.1lf",dWeigh);
				m_flex.SetTextMatrix(i+1,5,temp);
			}

			//设置当前行数
			m_cur_row=m_csaCartonName.GetSize()+1;

			//设置当前栈板号数量
			temp.Format("Current quantity:%d",m_csaCartonName.GetSize());
			pFrame->m_wndStatusBar.SetPaneText(3,temp);

			temp.Format("Find Pallet Number\'%s%s\' Pass!", this->m_csPalletNameStatic,dlg.m_csEspeBoxName);
			InsertListInfo(temp,1);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
	}

	this->m_ctrCarton.EnableWindow(FALSE);
	this->m_ctrBtnEspeBox.EnableWindow(FALSE);
	this->m_ctrBtnDiscard.EnableWindow(FALSE);
	this->m_ctrBtnClose.EnableWindow(FALSE);
	this->m_ctrBtnPrint.EnableWindow(FALSE);
	this->m_ctrCheck.EnableWindow(FALSE);
	this->m_ctrCheck.ShowWindow(SW_HIDE);
	this->m_ctrClear.EnableWindow(TRUE);
	this->m_ctrClear.ShowWindow(SW_NORMAL);
	this->m_ctrDelete.EnableWindow(FALSE);
}


void CPACKView::OnBtnClear() 
{
	CString temp;

	this->m_csaCartonName.RemoveAll();
	this->m_csaWeigh.RemoveAll();
	
	this->m_flex.Clear();
	SetNumText(m_flex.GetRows());
	
	CMainFrame *pFrame=(CMainFrame*)GetParentFrame();

	//获取显示当前栈板号
	if(!Get_Current_Pallet_Name())
	{
		InsertListInfo("Get the current project to the pallet, failure...!",2);
	}
	else
	{
		temp.Format("Pallet Number: %s%s",this->m_csPalletNameStatic,this->m_csPalletName);
		pFrame->m_wndStatusBar.SetPaneText(1,temp);
	}
	
	//设置当前栈板号数量
	temp.Format("Current quantity:%d",0);
	pFrame->m_wndStatusBar.SetPaneText(3,temp);
	
	this->m_ctrCarton.EnableWindow(TRUE);
	this->m_ctrBtnEspeBox.EnableWindow(TRUE);
	this->m_ctrBtnDiscard.EnableWindow(TRUE);
	this->m_ctrBtnClose.EnableWindow(TRUE);
	this->m_ctrBtnPrint.EnableWindow(TRUE);
	this->m_ctrCheck.EnableWindow(TRUE);
	this->m_ctrCheck.ShowWindow(SW_NORMAL);
	this->m_ctrClear.EnableWindow(FALSE);
	this->m_ctrClear.ShowWindow(SW_HIDE);
	this->m_ctrDelete.EnableWindow(FALSE);
}

void CPACKView::OnBtnDelete() 
{
	CString temp;
	_variant_t var;
	CString sql;
	double dWeigh;
	CDelete dlg;
	CMainFrame *pFrame=(CMainFrame*)GetParentFrame();
	
	dlg.m_csCurrentProduct  = this->m_csCurrentProduct;
	dlg.m_csCurrentOrder    = this->m_csCurrentOrder;
	dlg.m_csPalletName      = this->m_csPalletName;
	dlg.m_csPalletStatic    = this->m_csPalletNameStatic;

	if(IDOK!=dlg.DoModal())
		return;

	try
	{
		sql.Format("select * from %s_%s_Pallet where PalletName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csPalletName);
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(((CPACKApp *)AfxGetApp())->m_pRst->adoEOF) //空数据
		{
			this->m_csaCartonName.RemoveAll();
			this->m_csaWeigh.RemoveAll();

			m_flex.Clear();
			SetNumText(m_flex.GetRows());
			m_cur_col=1;
			m_cur_row=1;

			//删除箱号按钮不可用
			this->m_ctrDelete.EnableWindow(FALSE);

			temp.Format("Current quantity:%d",0);
			pFrame->m_wndStatusBar.SetPaneText(3,temp);
			
			//获取当前栈板号
			if(!Get_Current_Pallet_Name())
			{
				InsertListInfo("Get the current project to the pallet, failure...!",2);
			}
			else
			{
				temp.Format("Pallet Number: %s%s",this->m_csPalletNameStatic,this->m_csPalletName);
				pFrame->m_wndStatusBar.SetPaneText(1,temp);
			}
			
			//显示当前总数
			if(!this->Load_Current_Product_Count())
			{
				InsertListInfo("To obtain the number of current orders has failed",2);
				return;
			}
			this->UpdateCount(this->m_csCurrentCount);
		}
		else
		{
			//显示当前栈板号
			CMainFrame *pFrame=(CMainFrame*)GetParentFrame();
			temp.Format("Pallet Number: %s%s",this->m_csPalletNameStatic,this->m_csPalletName);
			pFrame->m_wndStatusBar.SetPaneText(1,temp);

			//========================未封栈板处理====================
			this->m_csaCartonName.RemoveAll();
			this->m_csaWeigh.RemoveAll();

			this->m_flex.Clear();
			SetNumText(m_flex.GetRows());

			//=================获取所有信息并保存到Array中============
			sql.Format("select * from %s_%s_CartonBox where PalletName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csPalletName);
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
			((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
			{	
				var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonName");
				temp=VariantToCString(var);
				m_csaCartonName.Add(temp);

				var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonWeigh");
				temp=VariantToCString(var);
				m_csaWeigh.Add(temp);
				
				((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
			}

			//插入信息到flex
			for(int i=0 ; i<m_csaCartonName.GetSize() ;i++)
			{
				m_flex.SetTextMatrix(i+1,1,this->m_csCartonNameStatic);
				m_flex.SetTextMatrix(i+1,2,m_csaCartonName.GetAt(i));
				m_flex.SetTextMatrix(i+1,3,this->m_csPalletNameStatic);
				m_flex.SetTextMatrix(i+1,4,this->m_csPalletName);
				dWeigh=atof((char*)(LPCTSTR)m_csaWeigh.GetAt(i));
				temp.Format("%.1lf",dWeigh);
				m_flex.SetTextMatrix(i+1,5,temp);
			}

			//设置当前行数
			m_cur_row=m_csaCartonName.GetSize()+1;

			//删除箱号按钮可用
			this->m_ctrDelete.EnableWindow(TRUE);

			//设置当前栈板号数量
			temp.Format("Current quantity:%d",m_csaCartonName.GetSize());
			pFrame->m_wndStatusBar.SetPaneText(3,temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
	}
}
