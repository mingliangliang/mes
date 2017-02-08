// AlterSetting.cpp : implementation file
//

#include "stdafx.h"
#include "productionmanagementtool.h"
#include "AlterSetting.h"
#include "Password.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAlterSetting dialog


CAlterSetting::CAlterSetting(CWnd* pParent /*=NULL*/)
	: CDialog(CAlterSetting::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAlterSetting)
	m_iComboxProduct = -1;
	m_iComboxOrder = -1;
	//}}AFX_DATA_INIT
}


void CAlterSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAlterSetting)
	DDX_Control(pDX, IDC_COMBO_PRODUCT, m_ctrComboxProduct);
	DDX_Control(pDX, IDC_COMBO_ORDER, m_ctrComboxOrder);
	DDX_CBIndex(pDX, IDC_COMBO_PRODUCT, m_iComboxProduct);
	DDX_CBIndex(pDX, IDC_COMBO_ORDER, m_iComboxOrder);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAlterSetting, CDialog)
	//{{AFX_MSG_MAP(CAlterSetting)
	ON_CBN_CLOSEUP(IDC_COMBO_PRODUCT, OnCloseupComboProduct)
	ON_CBN_CLOSEUP(IDC_COMBO_ORDER, OnCloseupComboOrder)
	ON_BN_CLICKED(IDC_DELETEORDER, OnDeleteorder)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAlterSetting message handlers

BOOL CAlterSetting::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	//获取项目列表
	if(!this->GetProductList())
	{
		MessageBox("获取项目列表失败!");
		return FALSE;
	}

	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

bool CAlterSetting::GetProductList()
{
	CString temp;
	_variant_t var;
	CString sql;

	sql="select DISTINCT ProductName from ProductList";
	

	try
	{	
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		((CProductionManagementToolApp *)AfxGetApp())->m_pRst=((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);		
		while(!((CProductionManagementToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("ProductName"); 
			temp=VariantToCString(var);
			this->m_ctrComboxProduct.AddString(temp);
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->MoveNext();
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


bool CAlterSetting::GetProductOrderList()
{
	CString temp;
	_variant_t var;
	CString sql;

	sql.Format("select *  from ProductList where ProductName='%s'",this->m_csProduct);
	
	try
	{
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		((CProductionManagementToolApp *)AfxGetApp())->m_pRst=((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);		
		while(!((CProductionManagementToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("OrderName"); 
			temp=VariantToCString(var);
			this->m_ctrComboxOrder.AddString(temp);
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->MoveNext();
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

void CAlterSetting::OnCloseupComboProduct()
{
	UpdateData();

	int index;

	index=this->m_ctrComboxProduct.GetCurSel();
	if(index==-1)
		return;
	this->m_ctrComboxProduct.GetLBText(index,m_csProduct);

	//获取所选项目对应订单插入到Combox中
	if(!this->GetProductOrderList())
	{
		MessageBox("获取订单列表失败!");
		this->m_ctrComboxOrder.EnableWindow(FALSE);
		return;
	}
	
	UpdateData(FALSE);
	this->m_ctrComboxOrder.EnableWindow(TRUE);
}

void CAlterSetting::OnCloseupComboOrder() 
{
	UpdateData();

	int index;

	index=this->m_ctrComboxOrder.GetCurSel();
	if(index==-1)
		return;	
	this->m_ctrComboxOrder.GetLBText(index,m_csOrder);
	
	UpdateData(FALSE);
}

void CAlterSetting::OnDeleteorder()
{
	CString temp;
	_variant_t var;
	CString sql;

	CPassword psw;
	psw.ilevel = 1; //需超级权限验证
	if(IDOK!=psw.DoModal())
		return;
	
	
	//删除IMEIRange表
	sql.Format("DROP TABLE %s_%s_IMEIRange",(char*)(LPCTSTR)this->m_csProduct,this->m_csOrder);
	try
	{
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		((CProductionManagementToolApp *)AfxGetApp())->m_pRst=((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		MessageBox("订单删除失败!");
		return;
	}
	
	//删除ProductionLine表
	sql.Format("DROP TABLE %s_%s_ProductionLine",(char*)(LPCTSTR)this->m_csProduct,this->m_csOrder);
	try
	{
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		((CProductionManagementToolApp *)AfxGetApp())->m_pRst=((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		MessageBox("订单删除失败!");
		return;
	}
	
	//删除Pallet表
	sql.Format("DROP TABLE %s_%s_Pallet",(char*)(LPCTSTR)this->m_csProduct,this->m_csOrder);
	try
	{
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		((CProductionManagementToolApp *)AfxGetApp())->m_pRst=((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		MessageBox("订单删除失败!");
		return;
	}
	
	//删除Carton表
	sql.Format("DROP TABLE %s_%s_CartonBox",(char*)(LPCTSTR)this->m_csProduct,this->m_csOrder);
	try
	{
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		((CProductionManagementToolApp *)AfxGetApp())->m_pRst=((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		MessageBox("订单删除失败!");
		return;
	}
	
	//删除ColorBox表
	sql.Format("DROP TABLE %s_%s_ColorBox",(char*)(LPCTSTR)this->m_csProduct,this->m_csOrder);
	try
	{
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		((CProductionManagementToolApp *)AfxGetApp())->m_pRst=((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		MessageBox("订单删除失败!");
		return;
	}
	
	
	//删除SettingList表中的订单设置的相关数据
	sql.Format("DELETE from SettingList WHERE (ProductName = '%s') AND (OrderName = '%s')",(char*)(LPCTSTR)this->m_csProduct,this->m_csOrder);
	try
	{
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		
		((CProductionManagementToolApp *)AfxGetApp())->m_pRst=((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		MessageBox("订单删除失败!");
		return;
	}
	
	//删除ProductList表中的订单信息
	sql.Format("DELETE from ProductList WHERE (ProductName = '%s') AND (OrderName = '%s')",(char*)(LPCTSTR)this->m_csProduct,this->m_csOrder);
	try
	{
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		((CProductionManagementToolApp *)AfxGetApp())->m_pRst=((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		MessageBox("订单删除失败!");
		return;
	}


	MessageBox("订单删除成功!");

	CDialog::OnOK();
}

CString CAlterSetting::VariantToCString(VARIANT var)
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
