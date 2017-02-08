// ChangePasswordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ProductionManagementTool.h"
#include "ChangePasswordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChangePasswordDlg dialog


CChangePasswordDlg::CChangePasswordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChangePasswordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChangePasswordDlg)
	m_csConfirmPsw = _T("");
	m_csCurPsw = _T("");
	m_csNewPsw = _T("");
	m_csUserName = _T("");
	//}}AFX_DATA_INIT
}


void CChangePasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChangePasswordDlg)
	DDX_Control(pDX, IDC_EDIT_USERNAME, m_ctrUserName);
	DDX_Control(pDX, IDC_EDIT_PSW, m_ctrNewPsw);
	DDX_Control(pDX, IDC_EDIT_CURPSW, m_ctrCurPsw);
	DDX_Control(pDX, IDC_EDIT_CPSW, m_ctrConfirmPsw);
	DDX_Text(pDX, IDC_EDIT_CPSW, m_csConfirmPsw);
	DDX_Text(pDX, IDC_EDIT_CURPSW, m_csCurPsw);
	DDX_Text(pDX, IDC_EDIT_PSW, m_csNewPsw);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_csUserName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChangePasswordDlg, CDialog)
	//{{AFX_MSG_MAP(CChangePasswordDlg)
	ON_BN_CLICKED(IDC_CONFIRM, OnConfirm)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChangePasswordDlg message handlers

void CChangePasswordDlg::OnConfirm() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData();
	
	CString temp;
	_variant_t var;
	CString sql;

	if (this->m_csNewPsw == "" || this->m_csConfirmPsw == "" || this->m_csUserName == "" || this->m_csCurPsw == "")
	{
		MessageBox("输入不能为空!","Error",MB_OK);
		Reset();
		return;
	}

	sql.Format("select * from PermissionControl where UserName='%s' and Password='%s'",this->m_csUserName,this->m_csCurPsw);
	try
	{
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		((CProductionManagementToolApp *)AfxGetApp())->m_pRst =  ((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			MessageBox("用户名或密码错误,请重新输入!","Error",MB_OK);
			Reset();
			return;
		}
	
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch (_com_error e) 
	{
		MessageBox("检测用户名、密码失败!","Error",MB_OK);
		Reset();
		return;
	}

	if (this->m_csNewPsw != this->m_csConfirmPsw)
	{
		MessageBox("新密码输入不一致,请重新输入!","Error",MB_OK);
		Reset();
		return;
	}

	sql.Format("UPDATE PermissionControl SET Password='%s' where UserName='%s'",this->m_csConfirmPsw,this->m_csUserName);
	try
	{
		((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		MessageBox("更改密码失败!","Error",MB_OK);
		Reset();
		return;
	}

	MessageBox("密码更改成功!","OK",MB_OK);
	Reset();
	CDialog::OnOK();
}

void CChangePasswordDlg::Reset() 
{
	this->m_csUserName = "";
	this->m_csCurPsw = "";
	this->m_csNewPsw = "";
	this->m_csConfirmPsw = "";
	UpdateData(FALSE);
	this->m_ctrUserName.SetFocus();
}

void CChangePasswordDlg::OnCancel() 
{
	// TODO: Add your control notification handler code here

	EndDialog(IDCANCEL); 
}
