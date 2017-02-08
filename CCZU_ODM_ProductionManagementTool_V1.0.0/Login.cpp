// Login.cpp : implementation file
//

#include "stdafx.h"
#include "productionmanagementtool.h"
#include "Login.h"

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
	m_csLogin = _T("");
	//}}AFX_DATA_INIT
}


void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogin)
	DDX_Control(pDX, IDC_EDIT_LOGIN, m_ctrLogin);
	DDX_Text(pDX, IDC_EDIT_LOGIN, m_csLogin);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogin, CDialog)
	//{{AFX_MSG_MAP(CLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogin message handlers

void CLogin::OnOK() 
{
	// TODO: Add extra validation here

	UpdateData();
	m_csLogin.MakeLower();
	if (m_csLogin != "cczu")
	{
		MessageBox("µÇÂ½ÃÜÂë´íÎó!");
		m_ctrLogin.SetSel(0,-1);
		m_ctrLogin.SetFocus();
		return;
	}
	
	CDialog::OnOK();
}
