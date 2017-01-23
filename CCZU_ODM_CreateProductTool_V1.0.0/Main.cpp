// Main.cpp : implementation file
//

#include "stdafx.h"
#include "CreateProduct.h"
#include "Main.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMain dialog


CMain::CMain(CWnd* pParent /*=NULL*/)
	: CDialog(CMain::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMain)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMain::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMain)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMain, CDialog)
	//{{AFX_MSG_MAP(CMain)
	ON_BN_CLICKED(IDC_CREATE, OnCreate)
	ON_BN_CLICKED(IDC_RELEASE, OnRelease)
	ON_BN_CLICKED(IDC_ALTERSETTING, OnAltersetting)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMain message handlers

void CMain::OnCreate() 
{
	((CCreateProductApp *)AfxGetApp())->m_istatus = 1;
	CDialog::OnOK();
}

void CMain::OnRelease()
{
	((CCreateProductApp *)AfxGetApp())->m_istatus = 2;
	CDialog::OnOK();     
}

void CMain::OnAltersetting()
{
	((CCreateProductApp *)AfxGetApp())->m_istatus = 3;
	CDialog::OnOK();
}
