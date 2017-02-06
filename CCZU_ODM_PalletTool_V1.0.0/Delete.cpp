// Delete.cpp : implementation file
//

#include "stdafx.h"
#include "PACK.h"
#include "Delete.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDelete dialog


CDelete::CDelete(CWnd* pParent /*=NULL*/)
	: CDialog(CDelete::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDelete)
	m_iComboType = 0;
	m_csCarton = _T("");
	//}}AFX_DATA_INIT
}


void CDelete::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDelete)
	DDX_Control(pDX, IDC_EDIT_CARTON_DEL, m_ctrCarton);
	DDX_Radio(pDX, IDC_RADIO_SINGLE, m_iComboType);
	DDX_Text(pDX, IDC_EDIT_CARTON_DEL, m_csCarton);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDelete, CDialog)
	//{{AFX_MSG_MAP(CDelete)
	ON_BN_CLICKED(IDC_RADIO_SINGLE, OnRadioSingle)
	ON_BN_CLICKED(IDC_RADIO_WHOLE, OnRadioWhole)
	ON_EN_CHANGE(IDC_EDIT_CARTON_DEL, OnChangeEditCartonDel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDelete message handlers

BOOL CDelete::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	this->m_ctrCarton.EnableWindow(TRUE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDelete::OnRadioSingle() 
{
	m_ctrCarton.EnableWindow(TRUE);
}

void CDelete::OnRadioWhole() 
{
	m_ctrCarton.EnableWindow(FALSE);
}

void CDelete::OnChangeEditCartonDel() 
{
	UpdateData();
	if(this->m_csCarton.Right(2)=="\r\n")
	{
		this->m_csCarton.Replace("\r\n","");
	}
	UpdateData(FALSE);
}

void CDelete::OnOK()
{
	CString      sql;
	CString      temp;
	_variant_t   var;
	int          m_iNum;

	UpdateData();
	
	this->m_csCarton.Delete(0,this->m_csPalletStatic.GetLength());

	if (this->m_iComboType == 1)   //整板删除
	{
		//删除Pallet表中记录
		try
		{
			sql.Format("delete from %s_%s_Pallet where PalletName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csPalletName);
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
			((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			MessageBox("Unknown error!");
		}

		//删除Carton表中记录
		try
		{
			sql.Format("UPDATE %s_%s_CartonBox SET PalletName = NULL where PalletName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csPalletName);
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
			((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			MessageBox("Unknown error!");
		}
	}
	else if (this->m_iComboType == 0)   //单个卡通箱删除
	{
		//判断扫描箱号是否属于该栈板
		try
		{
			sql.Format("select * from %s_%s_CartonBox where CartonName='%s' and PalletName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csCarton,this->m_csPalletName);
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
			((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			
			if(((CPACKApp *)AfxGetApp())->m_pRst->adoEOF) //空数据
			{
				MessageBox("扫描箱号不属于本栈板,请从新扫描!");
				m_ctrCarton.SetFocus();
				m_ctrCarton.SetSel(0,-1);
				return;
			}

			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			MessageBox("Unknown error!");
		}

		//判断当前要删除箱号是否为该栈板的最后一箱
		try
		{
			sql.Format("select count(*) as COUNT from %s_%s_CartonBox where PalletName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csPalletName);
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
			((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			
			if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
			{			
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
				m_iNum = var.intVal;
			}
			
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			MessageBox("Unknown error!");
		}

		//删除Carton表中本箱的栈板号记录
		try
		{
			sql.Format("UPDATE %s_%s_CartonBox SET PalletName = NULL where CartonName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csCarton);
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
			((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			MessageBox("Unknown error!");
		}

		if (m_iNum == 1) //如果本箱是最后一箱，则还需删除Pallet表中的栈板号记录
		{
			try
			{
				sql.Format("delete from %s_%s_Pallet where PalletName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_csPalletName);
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
				((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
			}
			catch(_com_error e)
			{
				MessageBox("Unknown error!");
			}
		}
	}

	MessageBox("Carton box removed successfully!");
	
	CDialog::OnOK();
}
