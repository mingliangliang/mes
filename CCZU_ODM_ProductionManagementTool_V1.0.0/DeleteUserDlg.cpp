// DeleteUserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ProductionManagementTool.h"
#include "DeleteUserDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeleteUserDlg dialog


CDeleteUserDlg::CDeleteUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDeleteUserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeleteUserDlg)
	m_csUserName = _T("");
	m_csNewPsw = _T("");
	//}}AFX_DATA_INIT
}


void CDeleteUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeleteUserDlg)
	DDX_Control(pDX, IDC_EDIT_NEWPSW, m_ctrNewPsw);
	DDX_Control(pDX, IDC_EDIT_USERNAME, m_ctrUserName);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_csUserName);
	DDX_Text(pDX, IDC_EDIT_NEWPSW, m_csNewPsw);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDeleteUserDlg, CDialog)
	//{{AFX_MSG_MAP(CDeleteUserDlg)
	ON_BN_CLICKED(IDC_CONFIRM, OnConfirm)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeleteUserDlg message handlers

void CDeleteUserDlg::OnConfirm() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData();
	
	CString temp;
	_variant_t var;
	CString sql;

	if (this->m_csNewPsw == "" || this->m_csUserName == "")
	{
		MessageBox("输入不能为空!","Error",MB_OK);
		Reset();
		return;
	}

	sql.Format("select * from PermissionControl where UserName='%s' and Password='%s'",this->m_csUserName,this->m_csNewPsw);
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

	sql.Format("delete from PermissionControl where UserName='%s' and Password='%s'",this->m_csUserName,this->m_csNewPsw);
	try
	{
		((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		MessageBox("删除用户失败!","Error",MB_OK);
		Reset();
		return;
	}

	MessageBox("删除用户成功!","OK",MB_OK);
	Reset();
	CDialog::OnOK();
}

void CDeleteUserDlg::Reset() 
{
	this->m_csUserName = "";
	this->m_csNewPsw = "";
	UpdateData(FALSE);
	this->m_ctrUserName.SetFocus();
}

void CDeleteUserDlg::OnCancel() 
{
	// TODO: Add your control notification handler code here

	EndDialog(IDCANCEL); 
}
