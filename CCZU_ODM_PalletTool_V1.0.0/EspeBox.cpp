// EspeBox.cpp : implementation file
//

#include "stdafx.h"
#include "PACK.h"
#include "EspeBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEspeBox dialog


CEspeBox::CEspeBox(CWnd* pParent /*=NULL*/)
	: CDialog(CEspeBox::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEspeBox)
	m_csEspeBoxName = _T("");
	m_csPalletNameStatic = _T("");
	//}}AFX_DATA_INIT
}


void CEspeBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEspeBox)
	DDX_Control(pDX, IDC_BOXNAME, m_ctrEspeBoxName);
	DDX_Text(pDX, IDC_BOXNAME, m_csEspeBoxName);
	DDX_Text(pDX, IDC_BOXNAME_STATIC, m_csPalletNameStatic);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEspeBox, CDialog)
	//{{AFX_MSG_MAP(CEspeBox)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEspeBox message handlers

BOOL CEspeBox::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	this->m_ctrEspeBoxName.SetFocus();
	
	return FALSE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEspeBox::OnOK() 
{
	UpdateData();	
	CDialog::OnOK();
}
