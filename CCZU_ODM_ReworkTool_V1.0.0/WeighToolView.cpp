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
	ON_EN_CHANGE(IDC_EDIT_CARTONNUM, OnChangeEditCartonNum)
	ON_CBN_CLOSEUP(IDC_COMBO_ORDER, OnCloseupComboOrder)
	ON_CBN_CLOSEUP(IDC_COMBO_PRODUCT, OnCloseupComboProduct)
	ON_CBN_CLOSEUP(IDC_COMBO_REWORK, OnCloseupComboRework)
	ON_CBN_CLOSEUP(IDC_COMBO_WORKSTATION, OnCloseupComboWorkstation)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BTN_REWORK, OnBtnRework)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWeighToolView construction/destruction

CWeighToolView::CWeighToolView()
	: CFormView(CWeighToolView::IDD)
{
	//{{AFX_DATA_INIT(CWeighToolView)
	m_csCartonNum = _T("");
	m_csCurrentColor = _T("");
	m_csCurrentOrder = _T("");
	m_csCurrentProduct = _T("");
	m_iComboxOrder = -1;
	m_iComboxProduct = -1;
	m_iComboxRework = -1;
	m_iComboxWorkStation = -1;
	//}}AFX_DATA_INIT
	// TODO: add construction code here
}


CWeighToolView::~CWeighToolView()
{
}


void CWeighToolView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWeighToolView)
	DDX_Control(pDX, IDC_BTN_REWORK, m_ctrRework);
	DDX_Control(pDX, IDC_COMBO_WORKSTATION, m_ctrComboxWorkStation);
	DDX_Control(pDX, IDC_COMBO_REWORK, m_ctrComboxRework);
	DDX_Control(pDX, IDC_COMBO_PRODUCT, m_ctrComboxProduct);
	DDX_Control(pDX, IDC_COMBO_ORDER, m_ctrComboxOrder);
	DDX_Control(pDX, IDC_EDIT_CARTONNUM, m_ctrCartonNum);
	DDX_Text(pDX, IDC_EDIT_CARTONNUM, m_csCartonNum);
	DDX_Control(pDX, IDC_STATIC_CURRENT_PRODUCT, m_ctrCurrentProduct);
	DDX_Control(pDX, IDC_STATIC_CURRENT_ORDER, m_ctrCurrentOrder);
	DDX_Control(pDX, IDC_STATIC_CURRENT_COLOR, m_ctrCurrentColor);
	DDX_Text(pDX, IDC_STATIC_CURRENT_COLOR, m_csCurrentColor);
	DDX_Text(pDX, IDC_STATIC_CURRENT_ORDER, m_csCurrentOrder);
	DDX_Text(pDX, IDC_STATIC_CURRENT_PRODUCT, m_csCurrentProduct);
	DDX_Control(pDX, IDC_LIST_STATE, m_state_list);
	DDX_CBIndex(pDX, IDC_COMBO_ORDER, m_iComboxOrder);
	DDX_CBIndex(pDX, IDC_COMBO_PRODUCT, m_iComboxProduct);
	DDX_CBIndex(pDX, IDC_COMBO_REWORK, m_iComboxRework);
	DDX_CBIndex(pDX, IDC_COMBO_WORKSTATION, m_iComboxWorkStation);
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

	//获取项目列表
	if(!this->GetProductList())
	{
		InsertListInfo("Get product list fail...",2);
		return;
	}
	else
	{
		InsertListInfo("Get product list success...",0);
		return;
	}

	UpdateData(FALSE);
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
	Column.cx =   150;     //column宽度，不工作！   
	Column.fmt =   LVCFMT_LEFT;     //不工作
	Column.iImage =   0;     
	Column.iOrder =   0;     //不明白干什么用   
	Column.iSubItem =   8;        
	Column.pszText =   "时间";   
	m_state_list.InsertColumn(0,&Column);
	Column.pszText =   "状态"; 
	Column.cx =   400;
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

	VERIFY(m_staticfont.CreateFont(
		40,                        // nHeight
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

	this->m_ctrRework.SetFont(&m_staticfont);
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
	this->m_ctrCartonNum.EnableWindow(FALSE);
	this->m_ctrComboxWorkStation.EnableWindow(FALSE);
	this->m_ctrComboxRework.EnableWindow(FALSE);
	this->m_ctrRework.EnableWindow(FALSE);
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


void CWeighToolView::ClearUI()
{
	this->m_csCartonNum.Empty();
	this->m_ctrCartonNum.SetFocus();
}


int CWeighToolView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	CSplashWnd::ShowSplashScreen(this);
	
	return 0;
}


void CWeighToolView::OnCloseupComboProduct() 
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
	m_csCurrentColor = "";
	
	//获取所选项目对应订单插入到Combox中
	if(!this->GetProductOrderList())
	{
		InsertListInfo("Get order list fail...",2);
		this->m_ctrComboxOrder.EnableWindow(FALSE);
		return;
	}
	else
	{
		this->m_ctrComboxOrder.EnableWindow();
		InsertListInfo("Get order list success...",0);
	}
	
	this->m_ctrComboxWorkStation.SetCurSel(-1);
	this->m_ctrComboxRework.SetCurSel(-1);
	
	UpdateData(FALSE);
}


void CWeighToolView::OnCloseupComboOrder() 
{
	UpdateData();

	_variant_t var;
	CString sql;
	int index;
	index=this->m_ctrComboxOrder.GetCurSel();
	if(index==-1)
		return;
	this->m_ctrComboxOrder.GetLBText(index,m_csCurrentOrder);
	
	
	//获取项目列表
	if(!this->GetProductOrderInfo())
	{
		InsertListInfo("Get order info fail...",2);
		this->m_ctrComboxOrder.EnableWindow();
		return;
	}
	else
	{
		InsertListInfo("Get order info success...",0);
	}
	
	this->m_ctrComboxRework.EnableWindow();
	this->m_ctrRework.EnableWindow();
	this->m_ctrComboxWorkStation.SetCurSel(-1);
	this->m_ctrComboxRework.SetCurSel(-1);
	
	UpdateData(FALSE);
}


void CWeighToolView::OnCloseupComboRework()
{
	UpdateData();

	m_iReworkType = this->m_ctrComboxRework.GetCurSel();
	
	m_csCartonNum.Empty();
	
	UpdateData(FALSE);
	
	if(m_iReworkType==-1)
	{
		return;
	}
	else if (m_iReworkType==0)
	{
		//订单返工需权限确认
		CPassword psw;
		psw.ilevel = 1; //需超级权限验证
		if(IDOK != psw.DoModal())
		{
			this->m_ctrComboxRework.SetCurSel(-1);
			this->m_ctrComboxWorkStation.SetCurSel(-1);
			this->m_ctrComboxWorkStation.EnableWindow(FALSE);
			this->m_ctrCartonNum.EnableWindow(FALSE);
			return;
		}
		else
		{
			this->m_ctrComboxWorkStation.SetCurSel(-1);
			this->m_ctrComboxWorkStation.EnableWindow();
			this->m_ctrCartonNum.EnableWindow(FALSE);
		}
	}
	else if(m_iReworkType==1)
	{
		//单机返工需权限确认
		CPassword psw;
		psw.ilevel = 0; //需普通权限验证
		if(IDOK != psw.DoModal())
		{
			this->m_ctrComboxRework.SetCurSel(-1);
			this->m_ctrComboxWorkStation.SetCurSel(-1);
			this->m_ctrComboxWorkStation.EnableWindow(FALSE);
			this->m_ctrCartonNum.EnableWindow(FALSE);
			return;
		}
		else
		{
			this->m_ctrComboxWorkStation.SetCurSel(-1);
			this->m_ctrComboxWorkStation.EnableWindow();
			this->m_ctrCartonNum.EnableWindow();
		}
	}
	else if(m_iReworkType==2)
	{
		//卡通箱返工需权限确认
		CPassword psw;
		psw.ilevel = 0; //需普通权限验证
		if(IDOK != psw.DoModal())
		{
			this->m_ctrComboxRework.SetCurSel(-1);
			this->m_ctrComboxWorkStation.SetCurSel(-1);
			this->m_ctrComboxWorkStation.EnableWindow(FALSE);
			this->m_ctrCartonNum.EnableWindow(FALSE);
			return;
		}
		else
		{
			this->m_ctrComboxWorkStation.SetCurSel(-1);
			this->m_ctrComboxWorkStation.EnableWindow();
			this->m_ctrCartonNum.EnableWindow();
		}
	}
}


void CWeighToolView::OnCloseupComboWorkstation() 
{
	UpdateData();
	
	int index;
	
	m_csCartonNum.Empty();
	
	index=this->m_ctrComboxWorkStation.GetCurSel();
	
	if(m_iReworkType==-1)
	{
		return;
	}
	
	UpdateData(FALSE);
}


void CWeighToolView::OnChangeEditCartonNum() 
{
	UpdateData();
	
	if(m_csCartonNum.Right(2)=="\r\n")
	{
		m_csCartonNum.Replace("\r\n","");
		UpdateData(FALSE);
		
		OnBtnRework();
	}
}


void CWeighToolView::OnBtnRework() 
{
	UpdateData();

	CString temp;
	int index;
	_variant_t var;
	CString sql;
	int i;

	m_iReworkType = this->m_ctrComboxRework.GetCurSel();
	if(m_iReworkType==-1)
	{
		InsertListInfo("Please select rework mode...",2);
		m_csCartonNum.Empty();
		UpdateData(FALSE);
		return;
	}

	index = this->m_ctrComboxWorkStation.GetCurSel();
	if(index==-1)
	{
		InsertListInfo("Please select work station...",2);
		m_csCartonNum.Empty();
		UpdateData(FALSE);
		return;
	}
//	this->m_ctrComboxWorkStation.GetLBText(index,m_csCurrentWorkStation);

	if(m_iReworkType == 0)
	{
		if(IDNO == ::MessageBox(NULL,"Order rework production orders data will be deleted, whether to continue?","system hint",MB_YESNO))
		{
			m_csCartonNum.Empty();
			UpdateData(FALSE);
			return;
		}
	}
//增加判断是否已经出货，已出货不能进行返工
	if (m_iReworkType==0)    //订单返工
	{		
		sql.Format("select * from %s_%s_Pallet where Status=3",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder);
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				InsertListInfo("Orders Shipped, can not rework...",2);
				return;
			}
			
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return;
		}
	}
	else if (m_iReworkType==1) //单机返工
	{
		sql.Format("select * from %s_%s_ColorBox WHERE IMEI1='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCartonNum);		
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("CartonName");
				temp=VariantToCString(var);
				sql.Format("select * from %s_%s_CartonBox WHERE CartonName ='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,temp);
		
				try
				{
					if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
						((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
					((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
					if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
					{
						var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("Status");
						i=var.intVal;
						if(i==3)//已出货
						{
							InsertListInfo("This IMEI has Shipped, can not rework...",2);
							return;
						}

						var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("PalletName");
						temp=VariantToCString(var);
						sql.Format("select * from %s_%s_Pallet where Status=3 AND PalletName='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,temp);
						
						try
						{
							if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
								((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
							((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
							if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
							{
								InsertListInfo("This IMEI has Shipped, can not rework...",2);
								return;
							}
							
							if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
								((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
						}
						catch(_com_error e)
						{
							return;
						}
					}
					
					if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
						((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
				}
				catch(_com_error e)
				{
					return;
				}
			}
			
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return;
		}
	}
	else if (m_iReworkType==2) //卡通箱返工
	{
		sql.Format("select * from %s_%s_CartonBox WHERE CartonName ='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csCartonNum.Right(m_iCartonNameLength));
		
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("Status");
				i=var.intVal;
				if(i==3)//已出货
				{
					InsertListInfo("This Carton NO. has Shipped, can not rework...",2);
					return;
				}

				var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("PalletName");
				temp=VariantToCString(var);
				sql.Format("select * from %s_%s_Pallet where Status=3 AND PalletName='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,temp);
	 			
				try
				{
					if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
						((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
					((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
					if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
					{
						InsertListInfo("This Carton NO. has Shipped, can not rework...",2);
						return;
					}
					
					if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
						((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
				}
				catch(_com_error e)
				{
					return;
				}
			}
			
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return;
		}
	}
//end

	//不同站位执行返工
	switch(index)
	{
	case 0:
		//1写IMEI站位执行返工
		if (!WriteIMEIDeleteData())
		{
			InsertListInfo("Write IMEI station rework fail...",2);
			m_csCartonNum.Empty();
			UpdateData(FALSE);
			return;
		}
		else
		{
			InsertListInfo("Write IMEI station rework success...",0);
		}
		break;
	case 1:
		//1检查机身IMEI站位执行返工
		if (!CheckMobileIMEIDeleteData())
		{
			InsertListInfo("Check IMEI S1 station rework fail...",2);
			m_csCartonNum.Empty();
			UpdateData(FALSE);
			return;
		}
		else
		{
			InsertListInfo("Check IMEI S1 station rework success...",0);
		}
		break;

	case 2:
		//2打印彩盒标站位执行返工
		if (!ColorBoxLabelDeleteData())
		{
			InsertListInfo("Color box station rework fail...",2);
			m_csCartonNum.Empty();
			UpdateData(FALSE);
			return;
		}
		else
		{
			InsertListInfo("Color box station rework success...",0);
		}
		break;
	case 3:
		//3检查彩盒IMEI站位执行返工
		if (!CheckColorBoxIMEIDeleteData())
		{
			InsertListInfo("Check IMEI S2 station rework fail...",2);
			m_csCartonNum.Empty();
			UpdateData(FALSE);
			return;
		}
		else
		{
			InsertListInfo("Check IMEI S2 station rework success...",0);
		}
		break;
	case 4:
		//4彩盒称重站位执行返工
		if (!ColorBoxWeighDeleteData())
		{
			InsertListInfo("Color box weigh station rework fail...",2);
			m_csCartonNum.Empty();
			UpdateData(FALSE);
			return;
		}
		else
		{
			InsertListInfo("Color box weigh station rework success...",0);
		}
		break;
	case 5:
		//5卡通箱包装站位执行返工
		if (!CartonDeleteData())
		{
			InsertListInfo("Carton box station rework fail...",2);
			m_csCartonNum.Empty();
			UpdateData(FALSE);
			return;
		}
		else
		{
			InsertListInfo("Carton box station rework success...",0);
		}
		break;
	case 6:
		//6卡通箱称重站位执行返工
		if (!CartonWeighDeleteData())
		{
			InsertListInfo("Carton box weigh station rework fail...",2);
			m_csCartonNum.Empty();
			UpdateData(FALSE);
			return;
		}
		else
		{
			InsertListInfo("Carton box weigh station rework success...",0);
		}
		break;
	case 7:
		//7栈板包装站位执行返工
		if (!PalletDeleteData())
		{
			InsertListInfo("Pallet station rework fail...",2);
			m_csCartonNum.Empty();
			UpdateData(FALSE);
			return;
		}
		else
		{
			InsertListInfo("Pallet station rework success...",0);
		}
		break;
	default:
		break;
	}

	UpdateData();
	m_iReworkType = this->m_ctrComboxRework.GetCurSel();
	if(m_iReworkType==1)
	{
		this->m_ctrCartonNum.SetSel(0,-1);
		this->m_ctrCartonNum.SetFocus();
		UpdateData(FALSE);
	}

	return;
}


bool CWeighToolView::GetProductList()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	try
	{
		sql="select DISTINCT ProductName from ProductList where Enable=1";
		
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);		
		while(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("ProductName");
			temp=VariantToCString(var);
			this->m_ctrComboxProduct.AddString(temp);
			((CWeighToolApp *)AfxGetApp())->m_pRst->MoveNext();
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


bool CWeighToolView::GetProductOrderList()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	//清空订单列表
	this->m_ctrComboxOrder.ResetContent();
	
	try
	{
		sql.Format("select *  from ProductList where Enable=1 and ProductName='%s'",this->m_csCurrentProduct);
		
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);		
		while(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("OrderName");
			temp=VariantToCString(var);
			this->m_ctrComboxOrder.AddString(temp);
			((CWeighToolApp *)AfxGetApp())->m_pRst->MoveNext();
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

bool CWeighToolView::GetProductOrderInfo()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	try
	{
		sql.Format("select *  from ProductList where Enable=1 and ProductName='%s' and OrderName='%s'",this->m_csCurrentProduct,m_csCurrentOrder);
		
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		while(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("Color");
			temp=VariantToCString(var);
			this->m_csCurrentColor= temp;

			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("CartonNameSNLength");
			this->m_iCartonNameLength=var.intVal;

			((CWeighToolApp *)AfxGetApp())->m_pRst->MoveNext();
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


//1写IMEI站位返工
bool CWeighToolView::WriteIMEIDeleteData()
{
	CString temp;
	_variant_t var;
	CString sql;

	if (!CheckMobileIMEIDeleteData())
	{
		return FALSE;
	}

	if (m_iReworkType==0)    //订单返工
	{		
		sql.Format("delete from %s_%s_ColorBox",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder);
	}
	else if (m_iReworkType==1) //单机返工
	{
		sql.Format("DELETE FROM %s_%s_ColorBox WHERE IMEI1='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csCartonNum);
	}
	else if (m_iReworkType==2) //卡通箱返工
	{
		sql.Format("DELETE FROM %s_%s_ColorBox WHERE CartonName='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csCartonNum.Right(m_iCartonNameLength));
	}
	
	try
	{
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}


//2检查机身IMEI站位返工
bool CWeighToolView::CheckMobileIMEIDeleteData()
{
	CString temp;
	_variant_t var;
	CString sql;

	if (!ColorBoxLabelDeleteData())
	{
		return FALSE;
	}

	if (m_iReworkType==0)    //订单返工
	{
		sql.Format("UPDATE %s_%s_ColorBox SET Status=0 WHERE Status=1 and Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder);
	}
	else if (m_iReworkType==1) //单机返工
	{
		sql.Format("UPDATE %s_%s_ColorBox SET Status=0 WHERE IMEI1='%s' and Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCartonNum);
	}
	else if (m_iReworkType==2) //卡通箱返工
	{
		sql.Format("UPDATE %s_%s_ColorBox SET Status=0 WHERE CartonName='%s' and Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCartonNum.Right(m_iCartonNameLength));
	}
	
	try
	{
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}


//3打印彩盒标站位返工
bool CWeighToolView::ColorBoxLabelDeleteData()
{
	CString temp;
	_variant_t var;
	CString sql;

	if (!CheckColorBoxIMEIDeleteData())
	{
		return FALSE;
	}

	if (m_iReworkType==0)    //订单返工
	{
		sql.Format("UPDATE %s_%s_ColorBox SET Status=1 WHERE Status=2 and Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder);
	}
	else if (m_iReworkType==1) //单机返工
	{
		sql.Format("UPDATE %s_%s_ColorBox SET Status=1 WHERE IMEI1='%s' and Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCartonNum);
	}
	else if (m_iReworkType==2) //卡通箱返工
	{
		sql.Format("UPDATE %s_%s_ColorBox SET Status=1 WHERE CartonName='%s' and Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCartonNum.Right(m_iCartonNameLength));
	}

	try
	{
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	
	return TRUE;
}


//4检查彩盒IMEI站位返工
bool CWeighToolView::CheckColorBoxIMEIDeleteData()
{
	CString temp;
	_variant_t var;
	CString sql;

	if (!ColorBoxWeighDeleteData())
	{
		return FALSE;
	}

	if (m_iReworkType==0)    //订单返工
	{
		sql.Format("UPDATE %s_%s_ColorBox SET Status=2 WHERE Status=3 and Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder);
	}
	else if (m_iReworkType==1) //单机返工
	{
		sql.Format("UPDATE %s_%s_ColorBox SET Status=2 WHERE IMEI1='%s' and Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCartonNum);
	}
	else if (m_iReworkType==2) //卡通箱返工
	{
		sql.Format("UPDATE %s_%s_ColorBox SET Status=2 WHERE CartonName='%s' and Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCartonNum.Right(m_iCartonNameLength));
	}

	try
	{
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}


//5彩盒称重站位返工
bool CWeighToolView::ColorBoxWeighDeleteData()
{
	CString temp;
	_variant_t var;
	CString sql;

	if (!CartonDeleteData())
	{
		return FALSE;
	}

	if (m_iReworkType==0)    //订单返工
	{
		sql.Format("UPDATE %s_%s_ColorBox SET ColorBoxWeigh=NULL where Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder);
	}
	else if (m_iReworkType==1)  //单机返工
	{
		sql.Format("UPDATE %s_%s_ColorBox SET ColorBoxWeigh=NULL WHERE IMEI1='%s' and Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCartonNum);
	}
	else if (m_iReworkType==2)  //卡通箱返工
	{
		sql.Format("UPDATE %s_%s_ColorBox SET ColorBoxWeigh=NULL WHERE CartonName='%s' and Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCartonNum.Right(m_iCartonNameLength));
	}
	
	try
	{
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	
	return TRUE;
}


//6卡通箱包装站位返工
bool CWeighToolView::CartonDeleteData()
{
	CString temp;
	_variant_t var;
	CString sql;

	if (!CartonWeighDeleteData())
	{
		return FALSE;
	}

	if (m_iReworkType==0)    //订单返工
	{	
		sql.Format("delete from %s_%s_CartonBox",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder);
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
		
		sql.Format("UPDATE %s_%s_ColorBox SET CartonName=NULL where Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder);
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}
	else if (m_iReworkType==1)  //单机返工
	{	
		sql.Format("select * from %s_%s_ColorBox where IMEI1='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCartonNum);
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("CartonName");
				temp=VariantToCString(var);
			}
			
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}

		sql.Format("UPDATE %s_%s_ColorBox SET CartonName=NULL where CartonName='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,temp);
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}

		sql.Format("UPDATE %s_%s_CartonBox SET Status=0 where CartonName='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,temp);
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}
	else if (m_iReworkType==2)  //卡通箱返工
	{
		sql.Format("UPDATE %s_%s_CartonBox SET Status=0 where CartonName='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCartonNum.Right(m_iCartonNameLength));
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}

		sql.Format("UPDATE %s_%s_ColorBox SET CartonName=NULL where CartonName='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCartonNum.Right(m_iCartonNameLength));
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}

	return TRUE;
}


//7卡通箱称重站位返工
bool CWeighToolView::CartonWeighDeleteData()
{
	CString temp;
	_variant_t var;
	CString sql;

	if (!PalletDeleteData())
	{
		return FALSE;
	}

	if (m_iReworkType==0)    //订单返工
	{	
		sql.Format("UPDATE %s_%s_CartonBox SET CartonWeigh=NULL",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder);
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}
	else if (m_iReworkType==1)  //单机返工
	{
		sql.Format("select * from %s_%s_ColorBox where IMEI1='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCartonNum);
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("CartonName");
				temp=VariantToCString(var);
			}
			
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
		
		sql.Format("UPDATE %s_%s_CartonBox SET CartonWeigh=NULL where CartonName='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,temp);
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}
	else if (m_iReworkType==2)  //卡通箱返工
	{	
		sql.Format("UPDATE %s_%s_CartonBox SET CartonWeigh=NULL where CartonName='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCartonNum.Right(m_iCartonNameLength));
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}

	return TRUE;
}


//8栈板包装站位返工
bool CWeighToolView::PalletDeleteData()
{
	CString temp,temp1,temp2;
	CStringArray csaCarton,csaIMEI;
	_variant_t var;
	CString sql;

	csaCarton.RemoveAll();
	csaIMEI.RemoveAll();

	if (m_iReworkType==0)    //订单返工
	{
		sql.Format("delete from %s_%s_Pallet",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder);
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
		
		sql.Format("UPDATE %s_%s_CartonBox SET PalletName=NULL",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder);
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}
	else if (m_iReworkType==1)   //单机返工
	{
		sql.Format("select * from %s_%s_ColorBox where IMEI1='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCartonNum);
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("CartonName");
				temp1=VariantToCString(var);
			}
			
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}

		sql.Format("select * from %s_%s_CartonBox where CartonName='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,temp1);
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("PalletName");
				temp2=VariantToCString(var);
			}
			
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}

		sql.Format("UPDATE %s_%s_Pallet SET Status=0 where PalletName='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,temp2);
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}

		sql.Format("select * from %s_%s_CartonBox where PalletName='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,temp2);
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			while(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("CartonName");
				temp=VariantToCString(var);
				csaCarton.Add(temp);
				((CWeighToolApp *)AfxGetApp())->m_pRst->MoveNext();
			}
			
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}

		for (int l=0;l<csaCarton.GetSize();l++)
		{
			sql.Format("UPDATE %s_%s_CartonBox SET PalletName=NULL where CartonName='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,csaCarton[l]);
			try
			{
				if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
					((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
				((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
				if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
					((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			}
			catch(_com_error e)
			{
				return FALSE;
			}
		}
	}
	else if (m_iReworkType==2)   //卡通箱返工
	{
		sql.Format("select * from %s_%s_CartonBox where CartonName='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csCartonNum.Right(m_iCartonNameLength));
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("PalletName");
				temp1=VariantToCString(var);
			}
			
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}

		sql.Format("select * from %s_%s_CartonBox where PalletName='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,temp1);
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("CartonName");
				temp=VariantToCString(var);
				csaCarton.Add(temp);
				((CWeighToolApp *)AfxGetApp())->m_pRst->MoveNext();
			}
			
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}

		sql.Format("UPDATE %s_%s_Pallet SET Status=0 where PalletName='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,temp1);
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}

		for (int l=0;l<csaCarton.GetSize();l++)
		{
			sql.Format("UPDATE %s_%s_CartonBox SET PalletName=NULL where CartonName='%s'",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,csaCarton[l]);
			try
			{
				if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
					((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
				((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
				if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
					((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			}
			catch(_com_error e)
			{
				return FALSE;
			}
		}
	}
	
	return TRUE;
}
