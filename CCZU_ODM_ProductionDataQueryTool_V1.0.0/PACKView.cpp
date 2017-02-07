// PACKView.cpp : implementation of the CPACKView class
//

#include "stdafx.h"
#include "PACK.h"
#include "Splash.h"
#include "PACKDoc.h"
#include "PACKView.h"
#include "MainFrm.h"
#include <math.h>
#include "Password.h"
#include "Query.h"
#include "OrderQuery.h"
#include "OrderList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CPACKView

IMPLEMENT_DYNCREATE(CPACKView, CFormView)

BEGIN_MESSAGE_MAP(CPACKView, CFormView)
	//{{AFX_MSG_MAP(CPACKView)
	ON_WM_TIMER()
	ON_CBN_CLOSEUP(IDC_COMBO_PRODUCT, OnCloseupComboProduct)
	ON_CBN_CLOSEUP(IDC_COMBO_ORDER, OnCloseupComboOrder)
	ON_BN_CLICKED(IDC_BTN_PRINT, OnBtnPrint)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BTN_IMEIQUERY, OnBtnImeiquery)
	ON_BN_CLICKED(IDC_BTN_UNUSEDIMEI, OnBtnUnusedimei)
	ON_BN_CLICKED(IDC_BTN_ORDERQUERY, OnBtnOrderquery)
	ON_CBN_CLOSEUP(IDC_COMBO_TYPE, OnCloseupComboType)
	ON_BN_CLICKED(IDC_BTN_DETAIL, OnBtnDetail)
	ON_BN_CLICKED(IDC_BTN_CARTON, OnBtnCarton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPACKView construction/destruction

CPACKView::CPACKView()
	: CFormView(CPACKView::IDD)
{
	//{{AFX_DATA_INIT(CPACKView)
	m_iComboxProduct = -1;
	m_iComboxOrder = -1;
	m_csCurrentProduct = _T("");
	m_csCurrentOrder = _T("");
	m_csCurrentColor = _T("");
	m_csCurrentPlan = _T("");
	m_csCreateUser = _T("");
	m_csReleaseUser = _T("");
	m_iComboxType = -1;
	m_iCustomer = -1;
	m_iOrderType = -1;
	//}}AFX_DATA_INIT
}

CPACKView::~CPACKView()
{
}

void CPACKView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPACKView)
	DDX_Control(pDX, IDC_BTN_CARTON, m_ctrCarton);
	DDX_Control(pDX, IDC_COMBO_ORDERTYPE, m_ctrOrderType);
	DDX_Control(pDX, IDC_COMBO_CUSTOMER, m_ctrCustomer);
	DDX_Control(pDX, IDC_COMBO_TYPE, m_ctrComboxType);
	DDX_Control(pDX, IDC_BTN_UNUSEDIMEI, m_ctrUnusedIMEI);
	DDX_Control(pDX, IDC_STATIC_RELEASEUSER, m_ctrReleaseUser);
	DDX_Control(pDX, IDC_STATIC_CREATEUSER, m_ctrCreateUser);
	DDX_Control(pDX, IDC_BTN_IMEIQUERY, m_ctrIMEIQuery);
	DDX_Control(pDX, IDC_STATIC_CURRENT_PLAN, m_ctrCurrentPlan);
	DDX_Control(pDX, IDC_COMBO_PRODUCT, m_ctrComboxProduct);
	DDX_Control(pDX, IDC_COMBO_ORDER, m_ctrComboxOrder);
	DDX_Control(pDX, IDC_STATIC_CURRENT_PRODUCT, m_ctrCurrentProduct);
	DDX_Control(pDX, IDC_STATIC_CURRENT_ORDER, m_ctrCurrentOrder);
	DDX_Control(pDX, IDC_STATIC_CURRENT_COLOR, m_ctrCurrentColor);
	DDX_CBIndex(pDX, IDC_COMBO_PRODUCT, m_iComboxProduct);
	DDX_CBIndex(pDX, IDC_COMBO_ORDER, m_iComboxOrder);
	DDX_Text(pDX, IDC_STATIC_CURRENT_PRODUCT, m_csCurrentProduct);
	DDX_Text(pDX, IDC_STATIC_CURRENT_ORDER, m_csCurrentOrder);
	DDX_Text(pDX, IDC_STATIC_CURRENT_COLOR, m_csCurrentColor);
	DDX_Control(pDX, IDC_BTN_PRINT, m_ctrBtnPrint);
	DDX_Control(pDX, IDC_LIST_STATE, m_state_list);
	DDX_Control(pDX, IDC_FLEX, m_flex);
	DDX_Text(pDX, IDC_STATIC_CURRENT_PLAN, m_csCurrentPlan);
	DDX_Text(pDX, IDC_STATIC_CREATEUSER, m_csCreateUser);
	DDX_Text(pDX, IDC_STATIC_RELEASEUSER, m_csReleaseUser);
	DDX_CBIndex(pDX, IDC_COMBO_TYPE, m_iComboxType);
	DDX_CBIndex(pDX, IDC_COMBO_CUSTOMER, m_iCustomer);
	DDX_CBIndex(pDX, IDC_COMBO_ORDERTYPE, m_iOrderType);
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
 
	//设置FLEX格数
	this->SetRowCol(10,12); 
	this->SetNumText(10);
 
	//设置字体 
	this->SetMyFont();
	
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

void CPACKView::OnTimer(UINT nIDEvent) 
{
	switch(nIDEvent) 
	{
	case 1:
		this->KillTimer(1);
		CFormView::OnTimer(nIDEvent);

		//灰掉控件
		this->SetUIDisableAll();

		//获取项目列表
		if(!this->GetProductList())
		{
			InsertListInfo("获取项目列表失败...",2);
			return;
		}
		else
		{
			InsertListInfo("获取项目列表成功...",0);
			return;
		}
		break;
	case 2:
		ProductionDataRealTimeDisplay();
		break;
	default:
		break;
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
	Column.pszText =   "时间";   
	m_state_list.InsertColumn(0,&Column);
	Column.pszText =   "状态"; 
	Column.cx =   600;
	m_state_list.InsertColumn(1,&Column);
	
	this->m_ctrCurrentProduct.SetFontSize(18);
	this->m_ctrCurrentProduct.SetFontName("黑体");
	this->m_ctrCurrentProduct.SetTextColor(RGB(0,0,255));
	
	this->m_ctrCurrentOrder.SetFontSize(18);
	this->m_ctrCurrentOrder.SetFontName("粗体");
	this->m_ctrCurrentOrder.SetTextColor(RGB(0,0,255));
	
	this->m_ctrCurrentColor.SetFontSize(18);
	this->m_ctrCurrentColor.SetFontName("粗体");
	this->m_ctrCurrentColor.SetTextColor(RGB(0,0,255));

	this->m_ctrCurrentPlan.SetFontSize(18);
	this->m_ctrCurrentPlan.SetFontName("粗体");
	this->m_ctrCurrentPlan.SetTextColor(RGB(0,0,255));

	this->m_ctrReleaseUser.SetFontSize(18);
	this->m_ctrReleaseUser.SetFontName("粗体");
	this->m_ctrReleaseUser.SetTextColor(RGB(0,0,255));

	this->m_ctrCreateUser.SetFontSize(18);
	this->m_ctrCreateUser.SetFontName("粗体");
	this->m_ctrCreateUser.SetTextColor(RGB(0,0,255));

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
//	this->m_ctrIMEIQuery.EnableWindow(FALSE);
	this->m_ctrBtnPrint.EnableWindow(FALSE);
	this->m_ctrUnusedIMEI.EnableWindow(FALSE);
	this->m_ctrCarton.EnableWindow(FALSE);
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


bool CPACKView::ConnectMDBDatabase()
{
	CString temp;
	_variant_t var;
	CString sql;
	sql.Format("driver={SQL Server};Server=%s;DATABASE=%s;UID=%s;PWD=%s",this->m_Config.m_csServer,this->m_Config.m_csDatabaseName,this->m_Config.m_csUserName,this->m_Config.m_csPassword);
	
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pConnection->State)
			((CPACKApp *)AfxGetApp())->m_pConnection->Close();
		((CPACKApp *)AfxGetApp())->m_pConnection->ConnectionTimeout=15;
		((CPACKApp *)AfxGetApp())->m_pConnection->Open((char*)(LPCTSTR)sql,"","",adModeUnknown);
		
	}
	catch(_com_error e)
	{
		return FALSE;
		
	}

	return TRUE;
}


bool CPACKView::GetProductList()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	try
	{
		sql="select DISTINCT ProductName from ProductList where Enable=1";

		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);		
		while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("ProductName"); 
			temp=VariantToCString(var);
			this->m_ctrComboxProduct.AddString(temp);
			((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
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


void CPACKView::OnCloseupComboProduct() 
{
	UpdateData();

	CString temp;
	_variant_t var;
	CString sql;
	int index;
	index=this->m_ctrComboxProduct.GetCurSel();
	if(index==-1)
		return;	
	this->m_ctrComboxProduct.GetLBText(index,m_csCurrentProduct);
	m_csCurrentOrder = "";

	//获取所选项目对应订单插入到Combox中
	if(!this->GetProductOrderList())
	{
		InsertListInfo("获取订单列表失败...",2);
		this->m_ctrComboxOrder.EnableWindow(FALSE);
		return;
	}
	else
	{
		this->m_ctrComboxOrder.EnableWindow();
		InsertListInfo("获取订单列表成功...",0);
	}

	UpdateData(FALSE);
}


bool CPACKView::GetProductOrderList()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	//清空订单列表
	this->m_ctrComboxOrder.ResetContent();

	try
	{
		sql.Format("select *  from ProductList where Enable=1 and ProductName='%s'",this->m_csCurrentProduct);

		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);		
		while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("OrderName");
			temp=VariantToCString(var);
			this->m_ctrComboxOrder.AddString(temp);
			((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
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


void CPACKView::SetRowCol(int rows,int cols)
{
	m_flex.SetRows(rows);
	m_flex.SetCols(cols);
	
	m_flex.SetColWidth(0,1845);

	for (int i=1;i<12;i++)
	{
		m_flex.SetColWidth(i,840);
	}
 
	for (int j=0;j<10;j++) 
	{
		m_flex.SetRowHeight(j,355); 
	}
  
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
		m_flex.SetCol(0);
		m_flex.SetCellAlignment(4);
		
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

		m_flex.SetRow(row);
		m_flex.SetCol(6);
		m_flex.SetCellAlignment(4);

		m_flex.SetRow(row);
		m_flex.SetCol(7);
		m_flex.SetCellAlignment(4);

		m_flex.SetRow(row);
		m_flex.SetCol(8);
		m_flex.SetCellAlignment(4);

		m_flex.SetRow(row);
		m_flex.SetCol(9);
		m_flex.SetCellAlignment(4);

		m_flex.SetRow(row);
		m_flex.SetCol(10);
		m_flex.SetCellAlignment(4);
		
		m_flex.SetRow(row);
		m_flex.SetCol(11);
		m_flex.SetCellAlignment(4);
	}
	
	m_flex.SetTextMatrix(0,0,"工序");
	m_flex.SetTextMatrix(0,1,"9:00");
	m_flex.SetTextMatrix(0,2,"10:00");
	m_flex.SetTextMatrix(0,3,"11:00");
	m_flex.SetTextMatrix(0,4,"12:00");
	m_flex.SetTextMatrix(0,5,"14:00");
	m_flex.SetTextMatrix(0,6,"15:00");
	m_flex.SetTextMatrix(0,7,"16:00");
	m_flex.SetTextMatrix(0,8,"17:00");
	m_flex.SetTextMatrix(0,9,"18:00");
	m_flex.SetTextMatrix(0,10,"24:00");
	m_flex.SetTextMatrix(0,11,"Total");

	m_flex.SetTextMatrix(1,0,"组件生产");
	m_flex.SetTextMatrix(2,0,"写IMEI");
	m_flex.SetTextMatrix(3,0,"检查机身IMEI");
	m_flex.SetTextMatrix(4,0,"打印彩盒标");
	m_flex.SetTextMatrix(5,0,"检查彩盒IMEI");
	m_flex.SetTextMatrix(6,0,"彩盒称重");
	m_flex.SetTextMatrix(7,0,"卡通箱包装");
	m_flex.SetTextMatrix(8,0,"卡通箱称重");
	m_flex.SetTextMatrix(9,0,"栈板包装");
}

void CPACKView::OnBtnPrint()
{
	UpdateData();

	CString temp;
	_variant_t var;
	CString sql;
	COleVariant covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	int index;

	index=this->m_ctrComboxType.GetCurSel();
	if(index==-1)
		return;

	//reset
	m_csaIMEI1.RemoveAll();
	m_csaIMEI2.RemoveAll();
	m_csaIMEI3.RemoveAll();
	m_csaNetCode.RemoveAll();
	m_csaSN.RemoveAll();
	m_csaBoxID.RemoveAll();
	m_csaPalletID.RemoveAll();
	m_csaCartonNametemp.RemoveAll();
	m_csaPalletNametemp.RemoveAll();
	m_csaShippingDate.RemoveAll();
	m_csaColorBoxWeigh.RemoveAll();
	m_csaCartonBoxWeigh.RemoveAll();
	m_csaMACAddr.RemoveAll();
	m_csaBTAddr.RemoveAll();
	
	//获取当前路径
	char csPath[MAX_PATH];
	CString PathSource,PathDest;
   	GetCurrentDirectory(MAX_PATH, csPath);
	
	//获取模板文件路径
	PathSource=CString(csPath)+"\\Template.xls";

	//创建EXCEL进程
	if(!m_ExlApp.CreateDispatch("Excel.Application",NULL))
	{
		AfxMessageBox("创建EXCEL服务失败!");
		return;
	}
	
	m_ExlBooks.AttachDispatch(m_ExlApp.GetWorkbooks(),TRUE);
	
	//加载EXCEL模板
	m_ExlBook.AttachDispatch(m_ExlBooks.Add((_variant_t)PathSource),TRUE);
	
	//加载sheet页面
	//m_ExlSheets.AttachDispatch(m_ExlBook.GetSheets(),TRUE);
	
	//获取Worksheets
	m_ExlSheets.AttachDispatch(m_ExlBook.GetWorksheets(),true);
	
	//获取sheet1
	m_ExlSheet.AttachDispatch(m_ExlSheets.GetItem(_variant_t("sheet1")),true);
	
	//加载所有单元格
	m_ExlRge.AttachDispatch(m_ExlSheet.GetCells(),TRUE);

	if (index == 0)
	{
		//生成目标文件路径
		PathDest=CString(csPath)+"\\出货数据\\"+this->m_csCurrentProduct+"_"+this->m_csCurrentOrder+"_彩盒称重.xls";
		
		InsertListInfo("正在导出彩盒称重数据，请等待...",0);
		
		//获取生产数据
		if(!GetColorBoxWeighData())
		{
			InsertListInfo("获取彩盒称重数据失败...",2);
			return;
		}
		
		//填充EXCEL表格内容
		m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t("Seq"));
		m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)2),_variant_t("IMEI_1"));
		m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)3),_variant_t("ColorBoxWeigh"));
		
		for (int j=2;j<(this->m_csaIMEI1.GetSize())+2;j++)
		{
			m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)1),_variant_t((long)(j-1)));
			m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)2),_variant_t(this->m_csaIMEI1.GetAt(j-2)));
			m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)3),_variant_t(this->m_csaColorBoxWeigh.GetAt(j-2)));
		}
	}
	else if (index == 1)
	{
		//生成目标文件路径
		PathDest=CString(csPath)+"\\出货数据\\"+this->m_csCurrentProduct+"_"+this->m_csCurrentOrder+"_卡通箱称重.xls";
		
		InsertListInfo("正在导出卡通箱称重数据，请等待...",0);
		
		//获取生产数据
		if(!GetCartonBoxWeighData())
		{
			InsertListInfo("获取卡通箱称重数据失败...",2);
			return;
		}
		
		//填充EXCEL表格内容
		m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t("Seq"));
		m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)2),_variant_t("CartonBoxID"));
		m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)3),_variant_t("CartonBoxWeigh"));
		
		for (int j=2;j<(this->m_csaBoxID.GetSize())+2;j++)
		{
			m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)1),_variant_t((long)(j-1)));
			m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)2),_variant_t(this->m_csaBoxID.GetAt(j-2)));
			m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)3),_variant_t(this->m_csaCartonBoxWeigh.GetAt(j-2)));
		}
	}
	else if (index == 2)
	{
		if (m_iCustomer == -1)
		{
			return;
		}

		//生成目标文件路径
		PathDest=CString(csPath)+"\\出货数据\\"+this->m_csCurrentProduct+"_"+this->m_csCurrentOrder+".xls";
		
		InsertListInfo("正在导出出货数据，请等待...",0);
		
		//获取生产数据
		if(!GetShippingData())
		{
			InsertListInfo("获取生产数据失败...",2);
			return;
		}

		if (m_iCustomer == 0)
		{
			//填充EXCEL表格内容
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t("Seq"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)2),_variant_t("ModelName"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)3),_variant_t("Color"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)4),_variant_t("Batch No"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)5),_variant_t("PalletID"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)6),_variant_t("BoxID"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)7),_variant_t("IMEI_1"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)8),_variant_t("IMEI_2"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)9),_variant_t("IMEI_3"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)10),_variant_t("NetCode"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)11),_variant_t("SN"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)12),_variant_t("BTAddress"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)13),_variant_t("WIFIMAC"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)14),_variant_t("ShippingDate"));
			
			
			for (int j=2;j<(this->m_csaIMEI1.GetSize())+2;j++)
			{
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)1),_variant_t((long)(j-1)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)2),_variant_t(this->m_csCurrentOrder));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)3),_variant_t(this->m_csCurrentColor));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)4),_variant_t(this->m_csCustomerNo+this->m_csaShippingDate.GetAt(j-2).Mid(2,2)+this->m_csaShippingDate.GetAt(j-2).Mid(5,2)+this->m_csaShippingDate.GetAt(j-2).Right(2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)5),_variant_t(this->m_csaPalletID.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)6),_variant_t(this->m_csaBoxID.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)7),_variant_t(this->m_csaIMEI1.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)8),_variant_t(this->m_csaIMEI2.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)9),_variant_t(this->m_csaIMEI3.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)10),_variant_t(this->m_csaNetCode.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)11),_variant_t(this->m_csaSN.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)12),_variant_t(this->m_csaBTAddr.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)13),_variant_t(this->m_csaMACAddr.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)14),_variant_t(this->m_csaShippingDate.GetAt(j-2)));
			}
		}
		else if (m_iCustomer == 1)
		{
			//填充EXCEL表格内容
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t("PALLET ID Number"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)2),_variant_t("CARTON ID Number"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)3),_variant_t("Product Number"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)4),_variant_t("HARDWARE VERSION"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)5),_variant_t("IMEI SIM:1"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)6),_variant_t("IMEI SIM:2"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)7),_variant_t("SERIAL Number"));
			
			for (int j=2;j<(this->m_csaIMEI1.GetSize())+2;j++)
			{
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)1),_variant_t(this->m_csaPalletID.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)2),_variant_t(this->m_csaBoxID.GetAt(j-2)));
				
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)5),_variant_t(this->m_csaIMEI1.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)6),_variant_t(this->m_csaIMEI2.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)7),_variant_t(this->m_csaSN.GetAt(j-2)));
			}
		}
		else if (m_iCustomer == 2)
		{
			//填充EXCEL表格内容
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t("DEWAV MODEL"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)2),_variant_t("Q-MOBILE MODEL"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)3),_variant_t("INVOICE NO."));//人工填写
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)4),_variant_t("COLOR"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)5),_variant_t("DATE OF SHIPMENT"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)6),_variant_t("PALLET ID"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)7),_variant_t("FULL PALLETS GROSS WEIGHT"));//人工填写
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)8),_variant_t("CARTON ID"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)9),_variant_t("FULL CARTON BOX GROSS WEIGHT"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)10),_variant_t("MAIN IMEI NUMBER"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)11),_variant_t("SLAVE IMEI NUMBER"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)12),_variant_t("FULL GIFTBOX GROSS WEIGHT"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)13),_variant_t("BATTERY AND CHARGER CODING"));//人工填写
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)14),_variant_t("SERIAL NUMBER"));
			
			for (int j=2;j<(this->m_csaIMEI1.GetSize())+2;j++)
			{
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)1),_variant_t(this->m_csDWNo));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)2),_variant_t(this->m_csCustomerNo));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)4),_variant_t(this->m_csCurrentColor));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)5),_variant_t(this->m_csaShippingDate.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)6),_variant_t(this->m_csaPalletID.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)8),_variant_t(this->m_csaBoxID.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)9),_variant_t(this->m_csaCartonBoxWeigh.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)10),_variant_t(this->m_csaIMEI1.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)11),_variant_t(this->m_csaIMEI2.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)12),_variant_t(this->m_csaColorBoxWeigh.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)14),_variant_t(this->m_csaSN.GetAt(j-2)));
			}
		}
	}

	//加载已使用的单元格
	m_ExlRge.AttachDispatch(m_ExlSheet.GetUsedRange(),TRUE);
	
	//设置左边对齐
	m_ExlRge.SetHorizontalAlignment((_variant_t)(long)-4131);
	
	//保存数据到EXCEL
	m_ExlBook.SaveAs(COleVariant(PathDest),covOptional,covOptional,covOptional,covOptional,covOptional,0,covOptional,covOptional,covOptional,covOptional,covOptional);  
	
	//设置为可见
	m_ExlApp.SetVisible(TRUE);

	//退出
	m_ExlApp.Quit();
	
	//释放对象
	m_ExlRge.ReleaseDispatch();
	m_ExlSheet.ReleaseDispatch();
	m_ExlSheets.ReleaseDispatch();
	m_ExlBook.ReleaseDispatch();
	m_ExlBooks.ReleaseDispatch();
	m_ExlApp.ReleaseDispatch();
	
	InsertListInfo("生产数据导出成功...",0);

	return;
}


int CPACKView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	CSplashWnd::ShowSplashScreen(this);
	
	return 0;
}


void CPACKView::OnCloseupComboOrder()
{
	UpdateData();
	CString temp;
	_variant_t var;
	CString sql;
	int index;
	index=this->m_ctrComboxOrder.GetCurSel();
	if(index==-1)
		return;
	this->m_ctrComboxOrder.GetLBText(index,m_csCurrentOrder);
	
	//reset
	this->m_flex.Clear();
	this->SetNumText(10); 
	m_iPlannedOutput = 0; 
	temp = _T("");

	//获取项目列表
	if(!this->GetProductOrderInfo())
	{
		InsertListInfo("获取订单信息失败...",2);
		this->m_ctrComboxOrder.EnableWindow();
		return;
	}
	else
	{
		InsertListInfo("获取订单信息成功...",0);
	}

	ProductionDataRealTimeDisplay();

	SetTimer(2,60000,NULL);

	this->m_ctrBtnPrint.EnableWindow();
	this->m_ctrIMEIQuery.EnableWindow();
	this->m_ctrUnusedIMEI.EnableWindow();
	this->m_ctrCarton.EnableWindow();

	UpdateData(FALSE);
}


bool CPACKView::GetProductOrderInfo()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	try
	{
		sql.Format("select *  from ProductList where Enable=1 and ProductName='%s' and OrderName='%s'",this->m_csCurrentProduct,m_csCurrentOrder);
		
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CustomerNo");
			this->m_csCustomerNo=var.bstrVal;

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("SNStatic");
			this->m_csDWNo=var.bstrVal;

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("Color");
			temp=VariantToCString(var);
			this->m_csCurrentColor= temp;

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonNameStatic");
			temp=VariantToCString(var);
			this->m_csCartonNameStatic= temp;

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonNameSNLength");
			this->m_iCartonNameLength=var.intVal;
			
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonMaxCount");
			this->m_iCartonMaxCount=var.intVal;
			
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("PalletNameStatic");
			temp=VariantToCString(var);
			this->m_csPalletNameStatic= temp;
			
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("PalletNameSNLength");
			this->m_iPalletNameLength=var.intVal;
			
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("PalletMaxCount");
			this->m_iPalletMaxCount=var.intVal;

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("PlannedOutput");
			this->m_iPlannedOutput=var.intVal;
			this->m_csCurrentPlan.Format("%d",this->m_iPlannedOutput);

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CreateUser");
			temp=VariantToCString(var);
			this->m_csCreateUser= temp;

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("ReleaseUser");
			temp=VariantToCString(var);
			this->m_csReleaseUser= temp;
			
			((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
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


bool CPACKView::GetProductionData()
{
	CString temp;
	_variant_t var;
	CString sql;

	SYSTEMTIME st;
	GetLocalTime(&st);
	CString time8,time9,time10,time11,time12,time14,time15,time16,time17,time18,time24;
	time8.Format("%4d-%2d-%2d 08:00:00",st.wYear,st.wMonth,st.wDay);
	time9.Format("%4d-%2d-%2d 09:00:00",st.wYear,st.wMonth,st.wDay);
	time10.Format("%4d-%2d-%2d 10:00:00",st.wYear,st.wMonth,st.wDay);
	time11.Format("%4d-%2d-%2d 11:00:00",st.wYear,st.wMonth,st.wDay);
	time12.Format("%4d-%2d-%2d 12:00:00",st.wYear,st.wMonth,st.wDay);
	time14.Format("%4d-%2d-%2d 14:00:00",st.wYear,st.wMonth,st.wDay);
	time15.Format("%4d-%2d-%2d 15:00:00",st.wYear,st.wMonth,st.wDay);
	time16.Format("%4d-%2d-%2d 16:00:00",st.wYear,st.wMonth,st.wDay);
	time17.Format("%4d-%2d-%2d 17:00:00",st.wYear,st.wMonth,st.wDay);
	time18.Format("%4d-%2d-%2d 18:00:00",st.wYear,st.wMonth,st.wDay);
	time24.Format("%4d-%2d-%2d 23:59:59",st.wYear,st.wMonth,st.wDay);

	//-----------------------获取主板投入站位各时间段数量-------------------
	//8:00-9:00
	sql.Format("select count(*) as COUNT from %s_%s_SNTemp where datetime>'%s' and datetime<'%s'",m_csCurrentProduct,m_csCurrentOrder,time8,time9);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPut.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//9:00-10:00
	sql.Format("select count(*) as COUNT from %s_%s_SNTemp where datetime>'%s' and datetime<'%s'",m_csCurrentProduct,m_csCurrentOrder,time9,time10);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPut.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	
	//10:00-11:00
	sql.Format("select count(*) as COUNT from %s_%s_SNTemp where datetime>'%s' and datetime<'%s'",m_csCurrentProduct,m_csCurrentOrder,time10,time11);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPut.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//11:00-12:00
	sql.Format("select count(*) as COUNT from %s_%s_SNTemp where datetime>'%s' and datetime<'%s'",m_csCurrentProduct,m_csCurrentOrder,time11,time12);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPut.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//12:00-14:00
	sql.Format("select count(*) as COUNT from %s_%s_SNTemp where datetime>'%s' and datetime<'%s'",m_csCurrentProduct,m_csCurrentOrder,time12,time14);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPut.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//14:00-15:00
	sql.Format("select count(*) as COUNT from %s_%s_SNTemp where datetime>'%s' and datetime<'%s'",m_csCurrentProduct,m_csCurrentOrder,time14,time15);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPut.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//15:00-16:00
	sql.Format("select count(*) as COUNT from %s_%s_SNTemp where datetime>'%s' and datetime<'%s'",m_csCurrentProduct,m_csCurrentOrder,time15,time16);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPut.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//16:00-17:00
	sql.Format("select count(*) as COUNT from %s_%s_SNTemp where datetime>'%s' and datetime<'%s'",m_csCurrentProduct,m_csCurrentOrder,time16,time17);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPut.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//17:00-18:00
	sql.Format("select count(*) as COUNT from %s_%s_SNTemp where datetime>'%s' and datetime<'%s'",m_csCurrentProduct,m_csCurrentOrder,time17,time18);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPut.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//18:00-24:00
	sql.Format("select count(*) as COUNT from %s_%s_SNTemp where datetime>'%s' and datetime<'%s'",m_csCurrentProduct,m_csCurrentOrder,time18,time24);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPut.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//total
	sql.Format("select count(*) as COUNT from %s_%s_SNTemp where datetime>'%s' and datetime<'%s'",m_csCurrentProduct,m_csCurrentOrder,time8,time24);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPut.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//-----------------------获取写号站位各时间段数量-------------------
	//8：00-9：00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where WriteDate>'%s' and WriteDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time8,time9);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaWrite.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//9：00-10：00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where WriteDate>'%s' and WriteDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time9,time10);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaWrite.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//10:00-11:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where WriteDate>'%s' and WriteDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time10,time11);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaWrite.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//11:00-12:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where WriteDate>'%s' and WriteDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time11,time12);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaWrite.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//12:00-14:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where WriteDate>'%s' and WriteDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time12,time14);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaWrite.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//14:00-15:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where WriteDate>'%s' and WriteDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time14,time15);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaWrite.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//15:00-16:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where WriteDate>'%s' and WriteDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time15,time16);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaWrite.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//16:00-17:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where WriteDate>'%s' and WriteDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time16,time17);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaWrite.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//17:00-18:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where WriteDate>'%s' and WriteDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time17,time18);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaWrite.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//18:00-24:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where WriteDate>'%s' and WriteDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time18,time24);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaWrite.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//total
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where WriteDate>'%s' and WriteDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time8,time24);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaWrite.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//-----------------------获取查号站位各时间段数量-------------------
	//8：00-9：00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS1Date>'%s' and CheckS1Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time8,time9);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS1.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//9：00-10：00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS1Date>'%s' and CheckS1Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time9,time10);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS1.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//10:00-11:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS1Date>'%s' and CheckS1Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time10,time11);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS1.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//11:00-12:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS1Date>'%s' and CheckS1Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time11,time12);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS1.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//12:00-14:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS1Date>'%s' and CheckS1Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time12,time14);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS1.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//14:00-15:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS1Date>'%s' and CheckS1Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time14,time15);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS1.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//15:00-16:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS1Date>'%s' and CheckS1Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time15,time16);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS1.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//16:00-17:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS1Date>'%s' and CheckS1Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time16,time17);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS1.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//17:00-18:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS1Date>'%s' and CheckS1Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time17,time18);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS1.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//18:00-24:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS1Date>'%s' and CheckS1Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time18,time24);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS1.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//total
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS1Date>'%s' and CheckS1Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time8,time24);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS1.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//-----------------------获取彩盒包装站位各时间段数量-------------------
	//8：00-9：00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorBoxDate>'%s' and ColorBoxDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time8,time9);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorBox.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//9：00-10：00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorBoxDate>'%s' and ColorBoxDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time9,time10);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorBox.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//10:00-11:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorBoxDate>'%s' and ColorBoxDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time10,time11);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorBox.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//11:00-12:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorBoxDate>'%s' and ColorBoxDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time11,time12);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorBox.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//12:00-14:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorBoxDate>'%s' and ColorBoxDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time12,time14);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorBox.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//14:00-15:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorBoxDate>'%s' and ColorBoxDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time14,time15);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorBox.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//15:00-16:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorBoxDate>'%s' and ColorBoxDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time15,time16);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorBox.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//16:00-17:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorBoxDate>'%s' and ColorBoxDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time16,time17);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorBox.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//17:00-18:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorBoxDate>'%s' and ColorBoxDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time17,time18);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorBox.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//18:00-24:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorBoxDate>'%s' and ColorBoxDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time18,time24);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorBox.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//total
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorBoxDate>'%s' and ColorBoxDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time8,time24);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorBox.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}


	//-----------------------获取检查彩盒IMEI站位各时间段数量-------------------
		//8：00-9：00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS2Date>'%s' and CheckS2Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time8,time9);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS2.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//9：00-10：00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS2Date>'%s' and CheckS2Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time9,time10);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS2.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//10:00-11:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS2Date>'%s' and CheckS2Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time10,time11);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS2.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//11:00-12:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS2Date>'%s' and CheckS2Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time11,time12);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS2.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//12:00-14:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS2Date>'%s' and CheckS2Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time12,time14);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS2.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//14:00-15:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS2Date>'%s' and CheckS2Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time14,time15);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS2.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//15:00-16:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS2Date>'%s' and CheckS2Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time15,time16);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS2.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//16:00-17:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS2Date>'%s' and CheckS2Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time16,time17);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS2.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//17:00-18:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS2Date>'%s' and CheckS2Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time17,time18);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS2.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//18:00-24:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS2Date>'%s' and CheckS2Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time18,time24);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS2.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//total
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CheckS2Date>'%s' and CheckS2Date<='%s'",m_csCurrentProduct,m_csCurrentOrder,time8,time24);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCheckS2.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}


	//-----------------------获取彩盒称重站位各时间段数量-------------------
		//8：00-9：00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorWeighDate>'%s' and ColorWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time8,time9);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//9：00-10：00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorWeighDate>'%s' and ColorWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time9,time10);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//10:00-11:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorWeighDate>'%s' and ColorWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time10,time11);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//11:00-12:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorWeighDate>'%s' and ColorWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time11,time12);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//12:00-14:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorWeighDate>'%s' and ColorWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time12,time14);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//14:00-15:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorWeighDate>'%s' and ColorWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time14,time15);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//15:00-16:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorWeighDate>'%s' and ColorWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time15,time16);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//16:00-17:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorWeighDate>'%s' and ColorWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time16,time17);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//17:00-18:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorWeighDate>'%s' and ColorWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time17,time18);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//18:00-24:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorWeighDate>'%s' and ColorWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time18,time24);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//total
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where ColorWeighDate>'%s' and ColorWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time8,time24);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaColorWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	//---------------------卡通包装----------------------------------
			//8：00-9：00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonDate>'%s' and CartonDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time8,time9);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCarton.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//9：00-10：00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonDate>'%s' and CartonDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time9,time10);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCarton.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//10:00-11:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonDate>'%s' and CartonDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time10,time11);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCarton.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//11:00-12:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonDate>'%s' and CartonDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time11,time12);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCarton.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//12:00-14:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonDate>'%s' and CartonDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time12,time14);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCarton.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//14:00-15:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonDate>'%s' and CartonDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time14,time15);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCarton.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//15:00-16:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonDate>'%s' and CartonDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time15,time16);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCarton.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//16:00-17:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonDate>'%s' and CartonDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time16,time17);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCarton.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//17:00-18:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonDate>'%s' and CartonDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time17,time18);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCarton.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//18:00-24:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonDate>'%s' and CartonDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time18,time24);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCarton.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//total
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonDate>'%s' and CartonDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time8,time24);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCarton.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}



	//-----------------------获取卡通箱称重站位各时间段数量-------------------
				//8：00-9：00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonWeighDate>'%s' and CartonWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time8,time9);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCartonWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//9：00-10：00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonWeighDate>'%s' and CartonWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time9,time10);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCartonWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//10:00-11:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonWeighDate>'%s' and CartonWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time10,time11);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCartonWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//11:00-12:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonWeighDate>'%s' and CartonWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time11,time12);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCartonWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//12:00-14:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonWeighDate>'%s' and CartonWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time12,time14);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCartonWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//14:00-15:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonWeighDate>'%s' and CartonWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time14,time15);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCartonWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//15:00-16:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonWeighDate>'%s' and CartonWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time15,time16);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCartonWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//16:00-17:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonWeighDate>'%s' and CartonWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time16,time17);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCartonWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//17:00-18:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonWeighDate>'%s' and CartonWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time17,time18);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCartonWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//18:00-24:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonWeighDate>'%s' and CartonWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time18,time24);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCartonWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//total
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where CartonWeighDate>'%s' and CartonWeighDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time8,time24);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaCartonWeigh.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}



	//-----------------------获取栈板包装站位各时间段数量-------------------
	//8：00-9：00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where PalletDate>'%s' and PalletDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time8,time9);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPallet.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//9：00-10：00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where PalletDate>'%s' and PalletDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time9,time10);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPallet.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//10:00-11:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where PalletDate>'%s' and PalletDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time10,time11);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPallet.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//11:00-12:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where PalletDate>'%s' and PalletDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time11,time12);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPallet.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//12:00-14:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where PalletDate>'%s' and PalletDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time12,time14);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPallet.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//14:00-15:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where PalletDate>'%s' and PalletDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time14,time15);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPallet.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//15:00-16:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where PalletDate>'%s' and PalletDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time15,time16);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPallet.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//16:00-17:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where PalletDate>'%s' and PalletDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time16,time17);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPallet.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//17:00-18:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where PalletDate>'%s' and PalletDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time17,time18);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPallet.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//18:00-24:00
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where PalletDate>'%s' and PalletDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time18,time24);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPallet.Add(temp);
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//total
	sql.Format("select count(*) as COUNT from %s_%s_ProductionLine where PalletDate>'%s' and PalletDate<='%s'",m_csCurrentProduct,m_csCurrentOrder,time8,time24);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			csaPallet.Add(temp);
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

//获取彩盒称重数据
bool CPACKView::GetColorBoxWeighData()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	sql.Format("select * from %s_%s_ColorBox where (ColorBoxWeigh<>'' and ColorBoxWeigh IS NOT NULL) and Enable=1",this->m_csCurrentProduct,this->m_csCurrentOrder);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1");
			temp=VariantToCString(var);
			m_csaIMEI1.Add(temp);

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("ColorBoxWeigh");
			temp=VariantToCString(var);
			m_csaColorBoxWeigh.Add(temp);
			
			((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
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

//获取卡通箱称重数据
bool CPACKView::GetCartonBoxWeighData()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	sql.Format("select distinct CartonName, * from %s_%s_CartonBox where CartonWeigh<>'' and CartonWeigh IS NOT NULL",this->m_csCurrentProduct,this->m_csCurrentOrder);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonName");
			temp=VariantToCString(var);

			temp=m_csCartonNameStatic+temp;
			m_csaBoxID.Add(temp);

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonWeigh");
			temp=VariantToCString(var);
			m_csaCartonBoxWeigh.Add(temp);
			
			((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
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

//获取出货数据
bool CPACKView::GetShippingData()
{
	CString temp;
	_variant_t var;
	CString sql;

	//以包装完成的卡通箱为基础获取出货数据信息,获取卡通箱号及栈板号
	sql.Format("select distinct CartonName, * from %s_%s_CartonBox where Status=2 or Status=3",this->m_csCurrentProduct,this->m_csCurrentOrder);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonName");
			temp=VariantToCString(var);
			m_csaCartonNametemp.Add(temp);

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("PalletName");
			temp=VariantToCString(var);
			m_csaPalletNametemp.Add(temp);

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonWeigh");
			temp=VariantToCString(var);
			m_csaCartonBoxWeigh.Add(temp);
			
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("datetime");
			//temp=VariantToCString(var);
			temp=(LPCSTR)_bstr_t(var);
			m_csaShippingDatetemp.Add(temp);

			((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	
	//根据卡通箱号获取对应的IMEI、SN号
	for (int j=0;j<m_csaCartonNametemp.GetSize();j++)
	{
		if (m_csaCartonNametemp.GetAt(j) != "")
		{
			sql.Format("select * from %s_%s_ColorBox where CartonName='%s' and Enable=1",this->m_csCurrentProduct,this->m_csCurrentOrder,m_csaCartonNametemp.GetAt(j));
			try
			{
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
				((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
				while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
				{
					var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1");
					temp=VariantToCString(var);
					m_csaIMEI1.Add(temp);

					var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI2");
					temp=VariantToCString(var);
					m_csaIMEI2.Add(temp);

					var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI3");
					temp=VariantToCString(var);
					m_csaIMEI3.Add(temp);
					
					var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("NetCode");
					temp=VariantToCString(var);
					m_csaNetCode.Add(temp);
					
					var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("ProductSN");
					temp=VariantToCString(var);
					m_csaSN.Add(temp);

					var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("BTAddress");
					temp=VariantToCString(var);
					m_csaBTAddr.Add(temp);

					var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("WIFIMAC");
					temp=VariantToCString(var);
					m_csaMACAddr.Add(temp);

					var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("ColorBoxWeigh");
					temp=VariantToCString(var);
					m_csaColorBoxWeigh.Add(temp);

					temp=m_csCartonNameStatic+m_csaCartonNametemp.GetAt(j);
					m_csaBoxID.Add(temp);

					temp=m_csPalletNameStatic+m_csaPalletNametemp.GetAt(j);
					m_csaPalletID.Add(temp);

					temp=m_csaShippingDatetemp.GetAt(j);
					m_csaShippingDate.Add(temp);
					
					((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
				}
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
			}
			catch(_com_error e)
			{
				return FALSE;
			}
		}
	}

	return TRUE;
}


//实时显示各工位生产数据
void CPACKView::ProductionDataRealTimeDisplay()
{
	CString temp;
	int i,j;
	//获取各工位生产数据
	csaPut.RemoveAll();
	csaWrite.RemoveAll();
	csaCheckS1.RemoveAll();
	csaCheckS2.RemoveAll();
	csaColorBox.RemoveAll();
	csaColorWeigh.RemoveAll();
	csaCarton.RemoveAll();
	csaCartonWeigh.RemoveAll();
	csaPallet.RemoveAll();

	if(!this->GetProductionData())
	{
		InsertListInfo("获取各工位生产数据失败...",2);
		this->m_ctrComboxOrder.EnableWindow();
		return;
	}
	else
	{
		InsertListInfo("获取各工位生产数据成功...",0);
	}

	for(i=1; i<12; i++)
	{
		m_flex.SetTextMatrix(1,i,csaPut[i-1]);
	}
	for(i=1; i<12; i++)
	{
		m_flex.SetTextMatrix(2,i,csaWrite[i-1]);
	}
	for(i=1; i<12; i++)
	{
		m_flex.SetTextMatrix(3,i,csaCheckS1[i-1]);
	}
	for(i=1; i<12; i++)
	{
		m_flex.SetTextMatrix(4,i,csaColorBox[i-1]);
	}
	for(i=1; i<12; i++)
	{
		m_flex.SetTextMatrix(5,i,csaCheckS2[i-1]);
	}
	for(i=1; i<12; i++)
	{
		m_flex.SetTextMatrix(6,i,csaColorWeigh[i-1]);
	}
	for(i=1; i<12; i++)
	{
		m_flex.SetTextMatrix(7,i,csaCarton[i-1]);
	}
	for(i=1; i<12; i++)
	{
		m_flex.SetTextMatrix(8,i,csaCartonWeigh[i-1]);
	}
	for(i=1; i<12; i++)
	{
		m_flex.SetTextMatrix(9,i,csaPallet[i-1]);
	}


	UpdateData(FALSE);
}

void CPACKView::OnBtnImeiquery()
{
	CQuery dlg;
	dlg.m_iOperateType = 1;
	dlg.m_csProduction = this->m_csCurrentProduct;
	dlg.m_csOrder = this->m_csCurrentOrder;
	dlg.DoModal();
}


void CPACKView::OnBtnUnusedimei() 
{
	CQuery dlg;
	dlg.m_iOperateType = 2;
	dlg.m_csProduction = this->m_csCurrentProduct;
	dlg.m_csOrder = this->m_csCurrentOrder;
	dlg.DoModal();
}
 
void CPACKView::OnBtnCarton() 
{
	CQuery dlg;
	dlg.m_iOperateType = 3;
	dlg.m_csProduction = this->m_csCurrentProduct;
	dlg.m_csOrder = this->m_csCurrentOrder;
	dlg.DoModal();
}


void CPACKView::OnBtnOrderquery() 
{
	COrderQuery dlg;
	dlg.m_csProductName = this->m_csCurrentProduct;
	dlg.m_csOrderName = this->m_csCurrentOrder;
	dlg.DoModal();
}

void CPACKView::OnCloseupComboType() 
{
	UpdateData();

	int index;

	index = this->m_ctrComboxType.GetCurSel();

	if(index == 2)
	{
		m_iCustomer = -1;
		m_ctrCustomer.EnableWindow(TRUE);
	}
	else
	{
		m_iCustomer = -1;
		m_ctrCustomer.EnableWindow(FALSE);
	}

	UpdateData(FALSE);
}

void CPACKView::OnBtnDetail() 
{
	UpdateData(TRUE);
	int index;
	index=this->m_ctrOrderType.GetCurSel();
	if(index==-1)
		return;

	OrderList dlg;
	dlg.m_iOrderType = index;
	dlg.DoModal();
}

