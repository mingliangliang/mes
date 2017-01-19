// WeighToolView.cpp : implementation of the CWeighToolView class
//

#include "stdafx.h"
#include "WeighTool.h"
#include "Splash.h"
#include "WeighToolDoc.h"
#include "WeighToolView.h"
#include "Password.h"
#include <math.h>

#define FAIL                102
#define PASS                103

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CWeighToolView

IMPLEMENT_DYNCREATE(CWeighToolView, CFormView)

BEGIN_MESSAGE_MAP(CWeighToolView, CFormView)
	//{{AFX_MSG_MAP(CWeighToolView)
	ON_EN_CHANGE(IDC_EDIT_PALLET, OnChangeEditPallet)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_EN_CHANGE(IDC_EDIT_CARTON, OnChangeEditCarton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWeighToolView construction/destruction

CWeighToolView::CWeighToolView()
	: CFormView(CWeighToolView::IDD)
{
	//{{AFX_DATA_INIT(CWeighToolView)
	m_csCurrentColor = _T("");
	m_csCurrentOrder = _T("");
	m_csCurrentProduct = _T("");
	m_csPallet = _T("");
	m_csCarton = _T("");
	//}}AFX_DATA_INIT
}

CWeighToolView::~CWeighToolView()
{
}

void CWeighToolView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWeighToolView)
	DDX_Control(pDX, IDC_EDIT_CARTON, m_ctrCarton);
	DDX_Control(pDX, IDC_EDIT_PALLET, m_ctrPallet);
	DDX_Control(pDX, IDC_STATIC_CURRENT_PRODUCT, m_ctrCurrentProduct);
	DDX_Control(pDX, IDC_STATIC_CURRENT_ORDER, m_ctrCurrentOrder);
	DDX_Control(pDX, IDC_STATIC_CURRENT_COLOR, m_ctrCurrentColor);
	DDX_Control(pDX, IDC_STATIC_RESULT, m_cResult);
	DDX_Control(pDX, IDC_LIST_STATE, m_state_list);
	DDX_Text(pDX, IDC_STATIC_CURRENT_COLOR, m_csCurrentColor);
	DDX_Text(pDX, IDC_STATIC_CURRENT_ORDER, m_csCurrentOrder);
	DDX_Text(pDX, IDC_STATIC_CURRENT_PRODUCT, m_csCurrentProduct);
	DDX_Text(pDX, IDC_EDIT_PALLET, m_csPallet);
	DDX_Text(pDX, IDC_EDIT_CARTON, m_csCarton);
	//}}AFX_DATA_MAP
}

BOOL CWeighToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CWeighToolView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	//设置字体
	this->SetMyFont();

	//初始化ini文件
	this->m_Config.InitConfigPath();

	//读取配置文件
	this->m_Config.ReadConfig();

	//灰掉控件
	this->SetUIDisableAll();

	//获取输入订单号
	m_csCurrentOrder = ((CWeighToolApp *)AfxGetApp())->InputOrder;

	//获取项目订单信息
	if(!this->GetProductOrderInfo())
	{
		InsertListInfo("Get product list info fail...",2);
		return;
	}
	else
	{
		UpdateData(FALSE);
		InsertListInfo("Get product list info success...",0);
	}

	UpdateData(FALSE);
	this->m_ctrPallet.EnableWindow();
	this->m_ctrCarton.EnableWindow();
	this->m_ctrPallet.SetFocus();
}

/////////////////////////////////////////////////////////////////////////////
// CWeighToolView diagnostics

#ifdef _DEBUG
void CWeighToolView::AssertValid() const
{
	CFormView::AssertValid();
}

void CWeighToolView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CWeighToolDoc* CWeighToolView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeighToolDoc)));
	return (CWeighToolDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWeighToolView message handlers

void CWeighToolView::SetMyFont()
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
	Column.cx =   400;
	m_state_list.InsertColumn(1,&Column);

	this->m_cResult.SetFontSize(90);
	this->m_cResult.SetFontName("黑体");

	this->m_ctrCurrentProduct.SetFontSize(18);
	this->m_ctrCurrentProduct.SetFontName("黑体");
	this->m_ctrCurrentProduct.SetTextColor(RGB(0,0,255));
	
	this->m_ctrCurrentOrder.SetFontSize(18);
	this->m_ctrCurrentOrder.SetFontName("粗体");
	this->m_ctrCurrentOrder.SetTextColor(RGB(0,0,255));

	this->m_ctrCurrentColor.SetFontSize(18);
	this->m_ctrCurrentColor.SetFontName("粗体");
	this->m_ctrCurrentColor.SetTextColor(RGB(0,0,255));

	VERIFY(m_staticfont.CreateFont(
		18,                        // nHeight
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
		"黑体"));                 // lpszFacename

	VERIFY(m_staticfont1.CreateFont(
		32,                        // nHeight
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
		"黑体"));                 // lpszFacename
	
	((CWnd*)GetDlgItem(IDC_STATIC_PALLET))->SetFont(&m_staticfont);

	((CWnd*)GetDlgItem(IDC_EDIT_PALLET))->SetFont(&m_staticfont1);

	((CWnd*)GetDlgItem(IDC_STATIC_CARTON))->SetFont(&m_staticfont);

	((CWnd*)GetDlgItem(IDC_EDIT_CARTON))->SetFont(&m_staticfont1);

	//m_ctrPalletID.EnableWindow(FALSE);	
}


void CWeighToolView::InsertListInfo(CString state,int imageIndex)
{
	CString date;
	date=GetCurTimes();
	m_state_list.InsertItem(m_state_list.GetItemCount(),date,imageIndex);
	m_state_list.SetItemText(m_state_list.GetItemCount()-1,1,state);
	m_state_list.EnsureVisible(m_state_list.GetItemCount()-1,TRUE);
}


CString CWeighToolView::GetCurTimes()
{
	CTime t=CTime::GetCurrentTime();
	CString str=t.Format( "%Y-%m-%d  %H:%M:%S");
	return str;	
}


void CWeighToolView::SetUIDisableAll()
{
	this->m_ctrPallet.EnableWindow(FALSE);
	this->m_ctrCarton.EnableWindow(FALSE);
}


CString CWeighToolView::VariantToCString(VARIANT   var)   
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


void CWeighToolView::OnChangeEditPallet()
{
	UpdateData();

	if(m_csPallet.Right(2)=="\r\n")
	{
		m_csPallet.Replace("\r\n","");
		UpdateData(FALSE);
		
		if(!CheckPallet())//检测栈板号
		{
			m_ctrPallet.SetFocus();
			m_ctrPallet.SetSel(0,-1);
			ShowCalResult(FAIL);
			return;
		}
		ShowCalResult(PASS);
		//this->ClearUI();
		this->m_csPallet.Empty();
		this->m_ctrPallet.SetFocus();
		UpdateData(FALSE);
	}
}

void CWeighToolView::OnChangeEditCarton() 
{
	UpdateData();

	if(m_csCarton.Right(2)=="\r\n")
	{
		m_csCarton.Replace("\r\n","");
		UpdateData(FALSE);
		
		if(!CheckCarton())//检测卡通箱号
		{
			m_ctrCarton.SetFocus();
			m_ctrCarton.SetSel(0,-1);
			ShowCalResult(FAIL);
			return;
		}
		ShowCalResult(PASS);
		//this->ClearUI();
		this->m_csCarton.Empty();
		this->m_ctrCarton.SetFocus();
		UpdateData(FALSE);
	}
}

bool CWeighToolView::CheckPallet()
{
	CString temp,temp2;
	_variant_t var;
	CString sql;
	int lengthtemp;
	int iPalletNameStaticLength;

	//检测栈板号是否为空
	if(m_csPallet.IsEmpty())
	{
		InsertListInfo("Pallet NO. can not be NULL,please input...",2);
		return FALSE;
	}

	//获取扫描的栈板号固定位和流水位
	iPalletNameStaticLength       = strlen(m_csPalletNameStatic);
	m_csCurrent_PalletNameStatic  = m_csPallet.Left(iPalletNameStaticLength);
	m_csCurrent_PalletName        = m_csPallet.Right(m_iPalletNameSNLength);

	//检测栈板号固定位
	if(m_csCurrent_PalletNameStatic != m_csPalletNameStatic)
	{
		InsertListInfo("Pallet NO. fixed position check fail...",2);
		this->m_ctrPallet.SetSel(0,-1);
		return FALSE;
	}

	try
	{
		sql.Format("select * from %s_%s_Pallet where PalletName='%s' and Status=2",this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCurrent_PalletName);
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			//有记录
			InsertListInfo("Pallets belong to the order number, shipping information check success...",0);
		}
		else
		{
			//无记录
			InsertListInfo("Pallet number does not belong to the order or does not complete package, please check...",2);
			return FALSE;
		}
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		this->m_ctrPallet.SetSel(0,-1);
		return FALSE;
	}
//修改Pallet标志位为3 代表已出货
	try
	{
		sql.Format("UPDATE %s_%s_Pallet SET Status=3 where PalletName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCurrent_PalletName);
		((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		this->m_ctrPallet.SetSel(0,-1);
		return FALSE;
	}
//修改CartonBox标志位为3 代表已出货
	try
	{
		sql.Format("UPDATE %s_%s_CartonBox SET Status=3 where PalletName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCurrent_PalletName);
		((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		this->m_ctrPallet.SetSel(0,-1);
		return FALSE;
	}
	return TRUE;
}

//增加扫描卡通箱号出货
bool CWeighToolView::CheckCarton()
{
	CString temp,temp2;
	_variant_t var;
	CString sql;
	int lengthtemp;
	int iCartonNameStaticLength;

	//检测栈板号是否为空
	if(m_csCarton.IsEmpty())
	{
		InsertListInfo("Carton NO. can not be NULL,please input...",2);
		return FALSE;
	}

	//获取扫描的栈板号固定位和流水位
	iCartonNameStaticLength       = strlen(m_csCartonNameStatic);
	m_csCurrent_CartonNameStatic  = m_csCarton.Left(iCartonNameStaticLength);
	m_csCurrent_CartonName        = m_csCarton.Right(m_iCartonNameSNLength);

	//检测栈板号固定位
	if(m_csCurrent_CartonNameStatic != m_csCartonNameStatic)
	{
		InsertListInfo("Carton NO. fixed position check fail...",2);
		this->m_ctrCarton.SetSel(0,-1);
		return FALSE;
	}

	try
	{
		sql.Format("select * from %s_%s_CartonBox where CartonName='%s' and Status=2",this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCurrent_CartonName);
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			//有记录
			InsertListInfo("Carton box belong to the order number, shipping information check success...",0);
		}
		else
		{
			//无记录
			InsertListInfo("Carton number does not belong to the order or does not complete package, please check...",2);
			return FALSE;
		}
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		this->m_ctrCarton.SetSel(0,-1);
		return FALSE;
	}

//修改CartonBox标志位为3 代表已出货
	try
	{
		sql.Format("UPDATE %s_%s_CartonBox SET Status=3 where CartonName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCurrent_CartonName);
		((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		this->m_ctrCarton.SetSel(0,-1);
		return FALSE;
	}
	return TRUE;
}


void CWeighToolView::ClearUI()
{
	this->m_csPallet.Empty();
	this->m_csCarton.Empty();
	this->m_ctrPallet.SetFocus();
	UpdateData(FALSE);
}


int CWeighToolView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	CSplashWnd::ShowSplashScreen(this);
	
	return 0;
}


void CWeighToolView::ShowCalResult(int state)
{
	switch(state)
	{
	case FAIL:
		this->m_cResult.SetTextColor(RGB(255,0,0));
		this->m_cResult.SetWindowText("FAIL");
		break;
	case PASS:
		this->m_cResult.SetTextColor(RGB(0,128,0));
		this->m_cResult.SetWindowText("PASS");
		break;
	default:
		break;
	}
}


bool CWeighToolView::GetProductOrderInfo()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	try
	{
		sql.Format("select * from ProductList where Enable=1 and OrderName='%s'",m_csCurrentOrder);
		
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("ProductName");
			temp=VariantToCString(var);
			this->m_csCurrentProduct= temp;

			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("Color");
			temp=VariantToCString(var);
			this->m_csCurrentColor= temp;

			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("PalletNameStatic");
			temp=VariantToCString(var);
			this->m_csPalletNameStatic= temp;

			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("PalletNameSNLength");
			this->m_iPalletNameSNLength=var.intVal;

			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("CartonNameStatic");
			temp=VariantToCString(var);
			this->m_csCartonNameStatic= temp;

			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("CartonNameSNLength");
			this->m_iCartonNameSNLength=var.intVal;
		}
		else
		{
			return FALSE;
		}
		
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}	
	
	return TRUE;
}


