// PopMessageBox.cpp : implementation file
//

#include "stdafx.h"
#include "PACK.h"
#include "PopMessageBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPopMessageBox dialog


CPopMessageBox::CPopMessageBox(CWnd* pParent /*=NULL*/)
	: CDialog(CPopMessageBox::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPopMessageBox)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPopMessageBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPopMessageBox)
	DDX_Control(pDX, IDC_STATIC_RESULTS, m_cPopMessageBoxTip);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPopMessageBox, CDialog)
	//{{AFX_MSG_MAP(CPopMessageBox)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPopMessageBox message handlers

void CPopMessageBox::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

BOOL CPopMessageBox::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	this->m_cPopMessageBoxTip.SetFontSize(120);
	this->m_cPopMessageBoxTip.SetFontName("Arial");
	this->m_cPopMessageBoxTip.SetTextColor(RGB(255,0,0));
	this->m_cPopMessageBoxTip.SetWindowText("FAIL");

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
