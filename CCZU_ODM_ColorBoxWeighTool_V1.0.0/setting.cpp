// setting.cpp : implementation file
//

#include "stdafx.h"
#include "WeighTool.h"
#include "setting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Csetting dialog


Csetting::Csetting(CWnd* pParent /*=NULL*/)
	: CDialog(Csetting::IDD, pParent)
{
	//{{AFX_DATA_INIT(Csetting)
	m_dHigh = 0.0;
	m_dLow = 0.0;
	//}}AFX_DATA_INIT
}


void Csetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Csetting)
	DDX_Text(pDX, IDC_EDIT_WEIGHHIGH, m_dHigh);
	DDX_Text(pDX, IDC_EDIT_WEIGHLOW, m_dLow);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Csetting, CDialog)
	//{{AFX_MSG_MAP(Csetting)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Csetting message handlers

BOOL Csetting::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if (!GetWeighRange())
	{
		MessageBox("Get ColorBox weigh range fail!","´íÎó",MB_OK);
		return FALSE;
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Csetting::OnOK() 
{
	// TODO: Add extra validation here
	_variant_t var;
	CString sql;

	UpdateData();

	try
	{
		sql.Format("UPDATE SettingList SET ColorBoxLowWeigh=%f, ColorBoxHighWeigh=%f WHERE Enable=1 and ProductName='%s' and OrderName='%s'", \
			m_dLow,m_dHigh,m_csProduct,m_csOrder);
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		MessageBox("Reset ColorBox weight failure!","´íÎó",MB_OK);
		return;
	}
	
	CDialog::OnOK();
}


bool Csetting::GetWeighRange()
{
	_variant_t var;
	CString sql;
	
	try
	{
		sql.Format("select * from SettingList where Enable=1 and ProductName='%s' and OrderName='%s'",this->m_csProduct,this->m_csOrder);
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("ColorBoxLowWeigh");
			m_dLow=atof((_bstr_t)var);

			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("ColorBoxHighWeigh");
			m_dHigh=atof((_bstr_t)var);
		}
		else
		{
			return FALSE;
		}
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	UpdateData(FALSE);
	return TRUE;
}
