// AddUserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ProductionManagementTool.h"
#include "AddUserDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddUserDlg dialog


CAddUserDlg::CAddUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddUserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddUserDlg)
	m_csUserName = _T("");
	m_csNewPsw = _T("");
	m_csConfirmPsw = _T("");
	m_iComboPermission = -1;
	m_bAll = FALSE;
	m_bCartonWeigh = FALSE;
	m_bCheckIMEIS1 = FALSE;
	m_bCheckIMEIS2 = FALSE;
	m_bCheckOrder = FALSE;
	m_bColorBox = FALSE;
	m_bColorWeigh = FALSE;
	m_bCreateProduct = FALSE;
	m_bDataQuery = FALSE;
	m_bPack = FALSE;
	m_bPallet = FALSE;
	m_bWriteIMEI = FALSE;
	m_bSNScan = FALSE;
	m_bRework = FALSE;
	//}}AFX_DATA_INIT
}


void CAddUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddUserDlg)
	DDX_Control(pDX, IDC_COMBO_PERMISSION, m_ctrComboPermission);
	DDX_Control(pDX, IDC_EDIT_CONFIRMPSW, m_ctrConfirmPsw);
	DDX_Control(pDX, IDC_EDIT_NEWPSW, m_ctrNewPsw);
	DDX_Control(pDX, IDC_EDIT_USERNAME, m_ctrUserName);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_csUserName);
	DDX_Text(pDX, IDC_EDIT_NEWPSW, m_csNewPsw);
	DDX_Text(pDX, IDC_EDIT_CONFIRMPSW, m_csConfirmPsw);
	DDX_CBIndex(pDX, IDC_COMBO_PERMISSION, m_iComboPermission);
	DDX_Check(pDX, IDC_CHECK_ALL, m_bAll);
	DDX_Check(pDX, IDC_CHECK_CARTONWEIGH, m_bCartonWeigh);
	DDX_Check(pDX, IDC_CHECK_CHECKIMEIS1, m_bCheckIMEIS1);
	DDX_Check(pDX, IDC_CHECK_CHECKIMEIS2, m_bCheckIMEIS2);
	DDX_Check(pDX, IDC_CHECK_CHECKORDER, m_bCheckOrder);
	DDX_Check(pDX, IDC_CHECK_COLORBOX, m_bColorBox);
	DDX_Check(pDX, IDC_CHECK_COLORWEIGH, m_bColorWeigh);
	DDX_Check(pDX, IDC_CHECK_CREATEPRODUCT, m_bCreateProduct);
	DDX_Check(pDX, IDC_CHECK_DATAQUERY, m_bDataQuery);
	DDX_Check(pDX, IDC_CHECK_PACK, m_bPack);
	DDX_Check(pDX, IDC_CHECK_PALLET, m_bPallet);
	DDX_Check(pDX, IDC_CHECK_WRITEIMEI, m_bWriteIMEI);
	DDX_Check(pDX, IDC_CHECK_SNSCAN, m_bSNScan);
	DDX_Check(pDX, IDC_CHECK_REWORK, m_bRework);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddUserDlg, CDialog)
	//{{AFX_MSG_MAP(CAddUserDlg)
	ON_BN_CLICKED(IDC_CONFIRM, OnConfirm)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddUserDlg message handlers

void CAddUserDlg::OnConfirm() 
{
	// TODO: Add your control notification handler code here

	UpdateData();
	
	CString temp;
	_variant_t var;
	CString sql;
	int index;

	if (this->m_csNewPsw == "" || this->m_csConfirmPsw == "" || this->m_csUserName == "")
	{
		MessageBox("输入不能为空!","Error",MB_OK);
//		Reset();
		return;
	}

	sql.Format("select * from PermissionControl where UserName='%s'",this->m_csUserName);
	try
	{
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		((CProductionManagementToolApp *)AfxGetApp())->m_pRst =  ((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	
		if(!((CProductionManagementToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			MessageBox("用户名已存在,请重新输入!","Error",MB_OK);
//			Reset();
			return;
		}
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch (_com_error e)
	{
		MessageBox("检测用户名失败!","Error",MB_OK);
//		Reset();
		return;
	}
	
	if (this->m_csNewPsw != this->m_csConfirmPsw)
	{
		MessageBox("密码输入不一致,请重新输入!","Error",MB_OK);
//		Reset();
		return;
	}

	index=this->m_ctrComboPermission.GetCurSel();
	if(index==-1)
	{
		MessageBox("请选择用户权限!","Error",MB_OK);
//		Reset();
		return;
	}

	if (m_bSNScan == FALSE && m_bAll == FALSE && m_bCartonWeigh == FALSE && m_bCheckIMEIS1 == FALSE
		&& m_bCheckIMEIS2 == FALSE && m_bCheckOrder == FALSE && m_bColorBox == FALSE
		&& m_bColorWeigh == FALSE && m_bCreateProduct == FALSE
		&& m_bDataQuery == FALSE && m_bPack == FALSE && m_bPallet == FALSE && m_bWriteIMEI == FALSE 
		&& m_bRework == FALSE)
	{
		MessageBox("请选择所属工具!","Error",MB_OK);
//		Reset();
		return;
	}

	sql.Format("INSERT INTO PermissionControl (UserName,Password,PermissionLevel,CreateProductTool, SNScanTool, \
		WriteIMEITool,CheckIMEIS1Tool,ColorBoxTool,CheckIMEIS2Tool,ColorBoxWeighTool,CartonBoxTool, \
		CartonBoxWeighTool,PalletTool,CheckOrderTool,ProductionDataQueryTool, \
		AllTool,ReworkTool) \
		VALUES('%s','%s',%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d)", \
		this->m_csUserName,this->m_csConfirmPsw,index,m_bCreateProduct,m_bSNScan,m_bWriteIMEI,m_bCheckIMEIS1, \
		m_bColorBox,m_bCheckIMEIS2,m_bColorWeigh,m_bPack,m_bCartonWeigh,m_bPallet,m_bCheckOrder,m_bDataQuery, \
		m_bAll,m_bRework);
	try
	{
//		MessageBox("添加用户失败!","Error",MB_OK);
		((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		MessageBox("添加用户失败!","Error",MB_OK);
		Reset();
		return;
	}

	MessageBox("添加用户成功!","OK",MB_OK);
	Reset();
	CDialog::OnOK();
}

void CAddUserDlg::Reset()
{
	this->m_csUserName = "";
	this->m_csNewPsw = "";
	this->m_csConfirmPsw = "";
	UpdateData(FALSE);
	this->m_ctrUserName.SetFocus();
	this->m_ctrComboPermission.SetCurSel(-1);
	this->m_bAll = FALSE;
	this->m_bCartonWeigh = FALSE;
	this->m_bCheckIMEIS1 = FALSE;
	this->m_bCheckIMEIS2 = FALSE;
	this->m_bCheckOrder = FALSE;
	this->m_bColorBox = FALSE;
	this->m_bColorWeigh = FALSE;
	this->m_bCreateProduct = FALSE;
	this->m_bSNScan = FALSE;
	this->m_bDataQuery = FALSE;
	this->m_bPack = FALSE;
	this->m_bPallet = FALSE;
	this->m_bWriteIMEI = FALSE;
	this->m_bRework = FALSE;
}

void CAddUserDlg::OnCancel() 
{
	// TODO: Add your control notification handler code here
	
	EndDialog(IDCANCEL);
}

BOOL CAddUserDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_ctrComboPermission.InsertString(0,"普通权限");
	m_ctrComboPermission.InsertString(1,"超级权限");
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
