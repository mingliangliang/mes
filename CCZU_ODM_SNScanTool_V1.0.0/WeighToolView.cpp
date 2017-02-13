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
	ON_WM_TIMER()
	ON_EN_CHANGE(IDC_EDIT_PALLET, OnChangeEditPallet)
	ON_WM_CREATE()
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
	//}}AFX_DATA_INIT
}

CWeighToolView::~CWeighToolView()
{
}

void CWeighToolView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWeighToolView)
	DDX_Control(pDX, IDC_STATIC_CURRENT_COUNT, m_cCurrentCount);
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
		InsertListInfo("Get product list information fail...",2);
		return;
	}
	else
	{
		UpdateData(FALSE);
		InsertListInfo("Get product list information success...",0);
	}

	if(!Load_Current_Product_Count())
	{
		InsertListInfo("Get the number of production fail...",2);
		return;
	}
	InsertListInfo("Get the number of production success...",0);
	UpdateCount(m_csCurrentCount);

	UpdateData(FALSE);
	this->m_ctrPallet.EnableWindow();
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

	this->m_cCurrentCount.SetFontSize(30);
	this->m_cCurrentCount.SetFontName("黑体");
	this->m_cCurrentCount.SetTextColor(RGB(0,0,255));

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
		//检查SN是否加密，如已加密则先解密
		if (m_csPallet.FindOneOf(_T("$%*+-./:")) != -1)
		{
			m_csPallet = Decrypt(m_csPallet.Left(14));
		}
		//SN解密
		m_csPallet.MakeUpper();
		UpdateData(FALSE);

		if(!verifySN(m_csPallet))
		{
			InsertListInfo("SN Format error...",2);
			m_ctrPallet.SetFocus();
			m_ctrPallet.SetSel(0,-1);
			ShowCalResult(FAIL);
			return;
		}
		//检测SN
		if(!CheckSN())
		{
			m_ctrPallet.SetFocus();
			m_ctrPallet.SetSel(0,-1);
			ShowCalResult(FAIL);
			return;
		}
		InsertListInfo("SN check success...",0);

		//录入数据库
		if(!SaveSN())
		{
			m_ctrPallet.SetFocus();
			m_ctrPallet.SetSel(0,-1);
			ShowCalResult(FAIL);
			return;
		}
		InsertListInfo("Save SN success...",0);

		if(!Load_Current_Product_Count())
		{
			InsertListInfo("Get the number of production fail...",2);
			return;
		}
		InsertListInfo("Get the number of production success...",0);
		UpdateCount(m_csCurrentCount);

		ShowCalResult(PASS);
		this->ClearUI();
	}
}


bool CWeighToolView::CheckSN()
{
	CString temp;
	_variant_t var;
	CString sql;

	//检测栈板号是否为空
	if(m_csPallet.IsEmpty())
	{
		InsertListInfo("SN can not be NULL, Please input SN...",2);
		return FALSE;
	}

	if(m_csPallet.Left(5) != m_csSNStatic)
	{
		InsertListInfo("Board type detection failed...",2);
		return FALSE;
	}

	try
	{
		sql.Format("select * from %s_%s_SNTemp where SN='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,m_csPallet);
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			//有记录
			temp.Format("SN:%s has been scan...",m_csPallet);
			InsertListInfo(temp,2);
			return FALSE;
		}
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("unknown error...",2);
		this->m_ctrPallet.SetSel(0,-1);
		return FALSE;
	}

	return TRUE;
}

BOOL CWeighToolView::verifySN(CString str)
{
	char ch;
	
	if (str.GetAt(5) != 'Z' && str.GetAt(5) != 'Y' && str.GetAt(5) != 'C')
	{
		return FALSE;
	}
	
	if(str.GetAt(6)<48 || str.GetAt(6)>57)    
	{    
		return FALSE;
	}
	
	if(str.GetAt(7)<48 || str.GetAt(7)>57)    
	{    
		return FALSE;
	}
	
	if(str.GetAt(8)<65 || str.GetAt(8)>90)    
	{    
		return FALSE;
	}
	
	for(int i=10;i<str.GetLength();i++)
	{   
		ch=str.GetAt(i);
		if(ch>=48 && ch<=57)    
		{
			continue;
		}
		else if (ch>=65 && ch<=70)
		{
			continue;
		}
		else if (ch>=97 && ch<=102)
		{
			continue;
		} 
		else
		{
			return FALSE;
		}
	}
	
	return TRUE;
}

bool CWeighToolView::SaveSN()
{
	_variant_t var;
	CString sql;

	sql.Format("INSERT INTO %s_%s_SNTemp (SN) VALUES ('%s')",this->m_csCurrentProduct,this->m_csCurrentOrder,m_csPallet);
	try
	{
		((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	
	return TRUE;
}


void CWeighToolView::ClearUI()
{
	this->m_csPallet.Empty();
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

			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("SNStatic");
			temp=VariantToCString(var);
			this->m_csSNStatic= temp;
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


void CWeighToolView::UpdateCount(CString strCount)
{
	CString temp;
	temp="Quantity:"+strCount;
	this->m_cCurrentCount.SetWindowText(temp);
	UpdateData(FALSE);
}


bool CWeighToolView::Load_Current_Product_Count()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	sql.Format("select count(*) as COUNT from %s_%s_SNTemp",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder);
	
	try
	{
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			this->m_csCurrentCount= temp;
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

CString CWeighToolView::Decrypt(CString cs) // 解密函数
{
	CString Result;
	char ch;
	int i;

	Result = "00000000000000";
	for (i=0;i<cs.GetLength();i++)
	{
		ch = cs.GetAt(i);

		switch(ch)
		{
		case '$':
			Result.SetAt(i,'0');
			break;
		case '1':
			Result.SetAt(i,'1');
			break;
		case '%':
			Result.SetAt(i,'2');
			break;
		case '*':
			Result.SetAt(i,'3');
			break;
		case '+':
			Result.SetAt(i,'4');
			break;
		case '-':
			Result.SetAt(i,'5');
			break;
		case '.':
			Result.SetAt(i,'6');
			break;
		case '/':
			Result.SetAt(i,'7');
			break;
		case ':':
			Result.SetAt(i,'8');
			break;
		case '9':
			Result.SetAt(i,'9');
			break;
		case 'A':
			Result.SetAt(i,'S');
			break;
		case 'B':
			Result.SetAt(i,'V');
			break;
		case 'C':
			Result.SetAt(i,'X');
			break;
		case 'D':
			Result.SetAt(i,'F');
			break;
		case 'E':
			Result.SetAt(i,'R');
			break;
		case 'F':
			Result.SetAt(i,'D');
			break;
		case 'G':
			Result.SetAt(i,'H');
			break;
		case 'H':
			Result.SetAt(i,'G');
			break;
		case 'I':
			Result.SetAt(i,'U');
			break;
		case 'J':
			Result.SetAt(i,'K');
			break;
		case 'K':
			Result.SetAt(i,'J');
			break;
		case 'L':
			Result.SetAt(i,'Z');
			break;
		case 'M':
			Result.SetAt(i,'N');
			break;
		case 'N':
			Result.SetAt(i,'M');
			break;
		case 'O':
			Result.SetAt(i,'P');
			break;
		case 'P':
			Result.SetAt(i,'O');
			break;
		case 'Q':
			Result.SetAt(i,'W');
			break;
		case 'R':
			Result.SetAt(i,'E');
			break;
		case 'S':
			Result.SetAt(i,'A');
			break;
		case 'T':
			Result.SetAt(i,'Y');
			break;
		case 'U':
			Result.SetAt(i,'I');
			break;
		case 'V':
			Result.SetAt(i,'B');
			break;
		case 'W':
			Result.SetAt(i,'Q');
			break;
		case 'X':
			Result.SetAt(i,'C');
			break;
		case 'Y':
			Result.SetAt(i,'T');
			break;
		case 'Z':
			Result.SetAt(i,'L');
			break;
		default:
			Result.SetAt(i,ch);
			break;
		}
	}
	
	return Result;
}
