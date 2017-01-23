// Password.cpp : implementation file
//

#include "stdafx.h"
#include "CreateProduct.h"
#include "Password.h"
#include "CreateProductDlg.h"
#include "OrderRelease.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPassword dialog


CPassword::CPassword(CWnd* pParent /*=NULL*/)
	: CDialog(CPassword::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPassword)
	m_csUserName = _T("");
	m_csPassword = _T("");
	//}}AFX_DATA_INIT
}


void CPassword::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPassword)
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_ctrPassword);
	DDX_Control(pDX, IDC_EDIT_USERNAME, m_ctrUserName);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_csUserName);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_csPassword);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPassword, CDialog)
	//{{AFX_MSG_MAP(CPassword)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPassword message handlers

void CPassword::OnOK() 
{
	// TODO: Add extra validation here

	UpdateData();

	CString temp,states;
	_variant_t var;
	CString sql;
	int ileveltemp,iTooltemp1,iTooltemp2;

	((CCreateProductApp *)AfxGetApp())->m_csCreateUser = this->m_csUserName;
	((CCreateProductApp *)AfxGetApp())->m_csReleaseUser = this->m_csUserName;

	sql.Format("select * from PermissionControl where UserName='%s' and Password='%s'",this->m_csUserName,this->m_csPassword);
	try
	{
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
		((CCreateProductApp *)AfxGetApp())->m_pRst=((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

		if(!((CCreateProductApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			//数据库内有记录
			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("PermissionLevel");
			ileveltemp=var.intVal;
			
			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CreateProductTool");
			iTooltemp1=var.intVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("AllTool");
			iTooltemp2=var.intVal;
		}
		else
		{
			//数据库内无记录
			MessageBox("用户名或密码错误，请重新输入!","Error",MB_ICONERROR);
			this->m_csUserName.Empty();
			this->m_csPassword.Empty();
			UpdateData(FALSE);
			this->m_ctrUserName.SetFocus();
			return;
		}

		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		this->m_csUserName.Empty();
		this->m_csPassword.Empty();
		UpdateData(FALSE);
		this->m_ctrUserName.SetFocus();
		return;
	}

	//ilevel:所需权限 0—普通权限，1—超级权限
	//ileveltemp:用户实际权限 0—普通权限，1—超级权限
	if (ilevel == 0)
	{
		//if (ileveltemp != 0 && ileveltemp != 1)
		if (ileveltemp != 0)
		{
			MessageBox("对不起，您的权限等级出错!","Error",MB_ICONERROR);
			this->m_csUserName.Empty();
			this->m_csPassword.Empty();
			UpdateData(FALSE);
			this->m_ctrUserName.SetFocus();
			return;
		}
	}
	else if (ilevel == 1)
	{
		if (ileveltemp != 1)
		{
			MessageBox("对不起，您的权限不够!","Error",MB_ICONERROR);
			this->m_csUserName.Empty();
			this->m_csPassword.Empty();
			UpdateData(FALSE);
			this->m_ctrUserName.SetFocus();
			return;
		}
	}

	//工具权限：本工具需要工单创建工具权限 或 所有工具权限
	if (iTooltemp1 != 1 && iTooltemp2 != 1)
	{
		MessageBox("对不起，您没有该工具的权限!","Error",MB_ICONERROR);
		this->m_csUserName.Empty();
		this->m_csPassword.Empty();
		UpdateData(FALSE);
		this->m_ctrUserName.SetFocus();
		return;
	}

	CDialog::OnOK();
}

BOOL CPassword::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	this->m_ctrUserName.SetFocus();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
