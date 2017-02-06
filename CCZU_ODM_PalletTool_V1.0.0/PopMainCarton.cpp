// PopMainCarton.cpp : implementation file
//

#include "stdafx.h"
#include "PACK.h"
#include "PopMainCarton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPopMainCarton dialog


CPopMainCarton::CPopMainCarton(CWnd* pParent /*=NULL*/)
	: CDialog(CPopMainCarton::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPopMainCarton)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPopMainCarton::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPopMainCarton)
	DDX_Control(pDX, IDC_STATIC_MAINCARTON, m_cPopMainCarton);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPopMainCarton, CDialog)
	//{{AFX_MSG_MAP(CPopMainCarton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPopMainCarton message handlers

BOOL CPopMainCarton::OnInitDialog() 
{
	CDialog::OnInitDialog();

	this->m_cPopMainCarton.SetFontSize(30);
	this->m_cPopMainCarton.SetFontName("Arial");
	this->m_cPopMainCarton.SetTextColor(RGB(0,0,255));
	this->m_cPopMainCarton.SetWindowText(m_csMainCarton);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
