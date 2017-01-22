// Login.cpp : implementation file
//

#include "stdafx.h"
#include "WeighTool.h"
#include "Login.h"
#include "Password.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogin dialog


CLogin::CLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CLogin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogin)
	m_csOrder = _T("");
	m_iComboxOrder = -1;
	m_iComboxProduct = -1;
	m_bSelect = FALSE;
	m_csProductionLine = _T("");
	//}}AFX_DATA_INIT
}


void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogin)
	DDX_Control(pDX, IDC_EDIT_LINE, m_ctrProductionLine);
	DDX_Control(pDX, IDC_CHECK_SELECT, m_ctrSelect);
	DDX_Control(pDX, IDC_COMBO_PRODUCT, m_ctrComboxProduct);
	DDX_Control(pDX, IDC_COMBO_ORDER, m_ctrComboxOrder);
	DDX_Control(pDX, IDC_EDIT_ORDER, m_ctrOrder);
	DDX_Text(pDX, IDC_EDIT_ORDER, m_csOrder);
	DDX_CBIndex(pDX, IDC_COMBO_ORDER, m_iComboxOrder);
	DDX_CBIndex(pDX, IDC_COMBO_PRODUCT, m_iComboxProduct);
	DDX_Check(pDX, IDC_CHECK_SELECT, m_bSelect);
	DDX_Text(pDX, IDC_EDIT_LINE, m_csProductionLine);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogin, CDialog)
	//{{AFX_MSG_MAP(CLogin)
	ON_EN_CHANGE(IDC_EDIT_ORDER, OnChangeEditOrder)
	ON_BN_CLICKED(IDC_CHECK_SELECT, OnCheckSelect)
	ON_CBN_EDITCHANGE(IDC_COMBO_PRODUCT, OnCloseupComboProduct)
	ON_CBN_CLOSEUP(IDC_COMBO_ORDER, OnCloseupComboOrder)
	ON_CBN_CLOSEUP(IDC_COMBO_PRODUCT, OnCloseupComboProduct)
	ON_EN_CHANGE(IDC_EDIT_LINE, OnChangeEditLine)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogin message handlers

BOOL CLogin::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_ctrOrder.SetFocus();
	m_ctrSelect.SetCheck(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CLogin::OnChangeEditOrder() 
{
	m_iFirstKeyTime = GetTickCount();
	if(m_csOrder.GetLength() != 0)
	{
		m_iKeyPeriod = m_iFirstKeyTime - m_iLastKeyTime;
		if(m_iKeyPeriod > 100)
		{
			MessageBox("Use Scanner to input please!");
			m_csOrder.Empty();
			UpdateData(FALSE);
			m_ctrOrder.SetFocus();
			return;
		}
	}
	m_iLastKeyTime = m_iFirstKeyTime;

	UpdateData();
	if(m_csOrder.Right(2) == "\r\n")
	{
		m_csOrder.Replace("\r\n","");
		UpdateData(FALSE);
		this->m_ctrProductionLine.SetFocus();
		this->m_ctrProductionLine.SetSel(0,-1);
	}
}


void CLogin::OnChangeEditLine() 
{
	UpdateData();
	if(m_csProductionLine.Right(2) == "\r\n")
	{
		m_csProductionLine.Replace("\r\n","");
		UpdateData(FALSE);
		OnOK();
	}
}


void CLogin::OnOK() 
{
	// TODO: Add extra validation here
	if (m_csOrder == "" || m_csProductionLine=="")
	{
		MessageBox("Order name or line can't be null!");
		m_ctrOrder.SetFocus();
		return;
	}
	
	CDialog::OnOK();
}


void CLogin::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}


void CLogin::OnCheckSelect() 
{
	if (m_ctrSelect.GetCheck() == TRUE)
	{
		CPassword dlg;
		dlg.ilevel = 1; //需超级权限验证
		if(dlg.DoModal()!=IDOK)
		{
			m_ctrComboxProduct.SetCurSel(-1);
			m_ctrComboxOrder.SetCurSel(-1);
			m_ctrComboxProduct.EnableWindow(FALSE);
			m_ctrComboxOrder.EnableWindow(FALSE);
			m_ctrOrder.EnableWindow(TRUE);
			m_ctrProductionLine.EnableWindow(TRUE);
			m_ctrSelect.SetCheck(FALSE);
			return;
		}

		((CComboBox*)GetDlgItem(IDC_COMBO_PRODUCT))->ResetContent();
		//获取项目列表
		if(!this->GetProductList())
		{
			MessageBox("Get project list fail!");
			return;
		}
	
		m_csOrder.Empty();
		m_csProductionLine.Empty();
		UpdateData(FALSE);
		m_ctrOrder.EnableWindow(FALSE);
		m_ctrComboxProduct.SetCurSel(-1);
		m_ctrComboxOrder.SetCurSel(-1);
		m_ctrComboxProduct.EnableWindow(TRUE);
		m_ctrSelect.SetCheck(TRUE);
	}
	else
	{
		m_ctrOrder.EnableWindow(TRUE);
		m_ctrProductionLine.EnableWindow(TRUE);
		m_ctrComboxProduct.SetCurSel(-1);
		m_ctrComboxOrder.SetCurSel(-1);
		m_ctrComboxProduct.EnableWindow(FALSE);
		m_ctrComboxOrder.EnableWindow(FALSE);
	}
}


void CLogin::OnCloseupComboProduct() 
{
	UpdateData();

	CString temp;
	_variant_t var;
	CString sql;
	int index;

	index=this->m_ctrComboxProduct.GetCurSel();
	if(index==-1)
		return;	
	this->m_ctrComboxProduct.GetLBText(index,csProduct);
	
	((CComboBox*)GetDlgItem(IDC_COMBO_ORDER))->ResetContent();
	//获取订单列表
	if(!this->GetOrderList())
	{
		MessageBox("Get order list fail!");
		return;
	}
	
	UpdateData(FALSE);
	m_ctrComboxProduct.EnableWindow(FALSE);
	m_ctrComboxOrder.EnableWindow(TRUE);
}


void CLogin::OnCloseupComboOrder() 
{
	UpdateData();

	CString temp;
	_variant_t var;
	CString sql;
	int index;

	index=this->m_ctrComboxOrder.GetCurSel();
	if(index==-1)
		return;	
	this->m_ctrComboxOrder.GetLBText(index,csOrder);
	
	m_ctrComboxProduct.EnableWindow(FALSE);
	m_ctrComboxOrder.EnableWindow(FALSE);

	m_csOrder = csOrder;
	UpdateData(FALSE);
	this->m_ctrProductionLine.SetFocus();
	this->m_ctrProductionLine.SetSel(0,-1);
}


bool CLogin::GetProductList()
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
			temp=(LPCTSTR)(_bstr_t)var;
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


bool CLogin::GetOrderList()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	try
	{
		sql.Format("select *  from ProductList where Enable=1 and ProductName='%s'",csProduct);

		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);		
		while(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("OrderName"); 
			temp=(LPCTSTR)(_bstr_t)var;
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
