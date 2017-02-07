// Query.cpp : implementation file
//

#include "stdafx.h"
#include "PACK.h"
#include "Query.h"
#include "excel.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQuery dialog


CQuery::CQuery(CWnd* pParent /*=NULL*/)
	: CDialog(CQuery::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQuery)
	m_csIMEI = _T("");
	m_csOrder = _T("");
	m_csProduction = _T("");
	m_csScanCarton = _T("");
	//}}AFX_DATA_INIT
}


void CQuery::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQuery)
	DDX_Control(pDX, IDC_EDITCARTON, m_ctrCarton);
	DDX_Control(pDX, IDC_BTN_EXPORT, m_ctrExport);
	DDX_Control(pDX, IDC_STATIC_IMEI, m_ctrIMEIStatic);
	DDX_Control(pDX, IDC_EDIT_IMEI, m_ctrIMEI);
	DDX_Text(pDX, IDC_EDIT_IMEI, m_csIMEI);
	DDX_Control(pDX, IDC_QUERYFLEX, m_QueryFlex);
	DDX_Text(pDX, IDC_STATIC_ORDER, m_csOrder);
	DDX_Text(pDX, IDC_STATIC_PRODUCTION, m_csProduction);
	DDX_Text(pDX, IDC_EDITCARTON, m_csScanCarton);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQuery, CDialog)
	//{{AFX_MSG_MAP(CQuery)
	ON_EN_CHANGE(IDC_EDIT_IMEI, OnChangeEditImei)
	ON_BN_CLICKED(IDC_BTN_EXPORT, OnBtnExport)
	ON_EN_CHANGE(IDC_EDITCARTON, OnChangeEditcarton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQuery message handlers
BOOL CQuery::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	int iloop;
	CString temp;

	csaIMEI.RemoveAll();
	m_ctrIMEIStatic.SetWindowText("IMEI1");

	m_ctrIMEIStatic.ShowWindow(FALSE);
	m_ctrIMEI.ShowWindow(FALSE);
	m_ctrExport.ShowWindow(FALSE);
	m_ctrCarton.ShowWindow(FALSE);

	switch(m_iOperateType)
	{
	case 1:
		UpdateData();
		m_ctrIMEIStatic.ShowWindow(TRUE);
		m_ctrIMEI.ShowWindow(TRUE);
		m_ctrIMEI.SetFocus();

		m_irow = 2;
		m_icol = 3;
		SetRowCol(m_irow,m_icol);
		SetNumText(m_irow,m_icol);
		break;
	case 2:
		m_ctrExport.ShowWindow(TRUE);

		//获取未使用的IMEI
		if(!this->GetUnusedIMEIData())
		{
			MessageBox("获取订单未使用的IMEI数据失败!","Error",MB_ICONERROR);
			exit(0);
		}
		m_irow = csaUnusedIMEI1.GetSize()+1;
		m_icol = 5;
		SetRowCol(m_irow,m_icol);
		SetNumText(m_irow,m_icol);
		for (iloop=1; iloop<m_irow; iloop++)
		{
			temp.Format("%d",iloop);
			m_QueryFlex.SetTextMatrix(iloop,0,temp);
			m_QueryFlex.SetTextMatrix(iloop,1,csaUnusedIMEI1[iloop-1]);
			m_QueryFlex.SetTextMatrix(iloop,2,csaUnusedIMEI2[iloop-1]);
			m_QueryFlex.SetTextMatrix(iloop,3,csaUnusedIMEI3[iloop-1]);
			m_QueryFlex.SetTextMatrix(iloop,4,csaUnusedIMEI4[iloop-1]);
		}
		break;
	case 3:
		UpdateData();
		m_ctrIMEIStatic.ShowWindow(TRUE);
		m_ctrIMEIStatic.SetWindowText("Carton");
		m_ctrCarton.ShowWindow(TRUE);
		m_ctrCarton.SetFocus();

// 		m_irow = csaIMEI1Range.GetSize()+1;
// 		m_icol = 5;
// 		SetRowCol(m_irow,m_icol);
// 		SetNumText(m_irow,m_icol);

		break;
	default:
		break;
	}
	
	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CQuery::OnChangeEditImei()
{
	CString temp;

	UpdateData();
	
	if(m_csIMEI.Right(2)=="\r\n")
	{
		m_csIMEI.Replace("\r\n","");
		UpdateData(FALSE);
	
		//获取IMEI状态
		if(!this->GetIMEIData())
		{
			MessageBox("获取IMEI状态失败!","Error",MB_ICONERROR);
			this->m_csProduction.Empty();
			this->m_csOrder.Empty();
			m_QueryFlex.Clear();
			this->m_ctrIMEI.SetSel(0,-1);
			this->m_ctrIMEI.SetFocus();
			UpdateData(FALSE);
			return;
		}

		temp.Format("%d",1);
		m_QueryFlex.SetTextMatrix(1,0,temp);
		m_QueryFlex.SetTextMatrix(1,1,m_csStation);
		m_QueryFlex.SetTextMatrix(1,2,m_csCarton);

		this->m_ctrIMEI.SetSel(0,-1);
		this->m_ctrIMEI.SetFocus();
		UpdateData(FALSE);
	}
}

void CQuery::OnChangeEditcarton() 
{
	CString temp;
	int i,j;
	UpdateData();
	
	if(m_csScanCarton.Right(2)=="\r\n")
	{
		m_csScanCarton.Replace("\r\n","");
		UpdateData(FALSE);
		
		//获取IMEI状态
		if(!this->GetCartonIMEI())
		{
			MessageBox("获取卡通箱IMEI失败!","Error",MB_ICONERROR);
			this->m_csProduction.Empty();
			this->m_csOrder.Empty();
			m_QueryFlex.Clear();
			this->m_ctrCarton.SetSel(0,-1);
			this->m_ctrCarton.SetFocus();
			UpdateData(FALSE);
			return;
		}
	 
		m_irow = csaIMEI1Range.GetSize()+1;
		m_icol = 5;
		SetRowCol(m_irow,m_icol);
		SetNumText(m_irow,m_icol);

		for(i=1; i<csaIMEI1Range.GetSize()+1; i++)
		{
			temp.Format("%d",i);
			m_QueryFlex.SetTextMatrix(i,0,temp);
			m_QueryFlex.SetTextMatrix(i,1,csaIMEI1Range[i-1]);
			m_QueryFlex.SetTextMatrix(i,2,csaIMEI2Range[i-1]);
			m_QueryFlex.SetTextMatrix(i,3,csaIMEI3Range[i-1]);
			m_QueryFlex.SetTextMatrix(i,4,csaIMEI4Range[i-1]);		
		}
		
		this->m_ctrCarton.SetSel(0,-1);
		this->m_ctrCarton.SetFocus();
		UpdateData(FALSE);
	}
	
}

void CQuery::SetRowCol(int rows,int cols)
{
	m_QueryFlex.SetRows(rows);
	m_QueryFlex.SetCols(cols);

	m_QueryFlex.SetColWidth(0,980);
	for (int i=1;i<cols;i++)
	{
		m_QueryFlex.SetColWidth(i,2390);
	}

	for (int j=0;j<rows;j++)
	{
		m_QueryFlex.SetRowHeight(j,480);
	}
}


void CQuery::SetNumText(int rows,int cols)
{
	//设置FLEX居中
	for(int row=0;row<rows;row++)
	{
		for (int col=0;col<cols;col++)
		{
			m_QueryFlex.SetRow(row);
			m_QueryFlex.SetCol(col);
			m_QueryFlex.SetCellAlignment(1);
		}
	}

	switch(m_iOperateType)
	{
	case 1:
		m_QueryFlex.SetTextMatrix(0,0,"序号");
		m_QueryFlex.SetTextMatrix(0,1,"已完成工位");
		m_QueryFlex.SetTextMatrix(0,2,"所属卡通箱");
		
		break;
	case 2:
		m_QueryFlex.SetTextMatrix(0,0,"序号");
		m_QueryFlex.SetTextMatrix(0,1,"未使用IMEI1");
		m_QueryFlex.SetTextMatrix(0,2,"未使用IMEI2");
		m_QueryFlex.SetTextMatrix(0,3,"未使用IMEI3");
		m_QueryFlex.SetTextMatrix(0,4,"未使用IMEI4");
		break;
	case 3: 
		m_QueryFlex.SetTextMatrix(0,0,"序号");
		m_QueryFlex.SetTextMatrix(0,1,"IMEI1");
		m_QueryFlex.SetTextMatrix(0,2,"IMEI2");
		m_QueryFlex.SetTextMatrix(0,3,"IMEI3");
		m_QueryFlex.SetTextMatrix(0,4,"IMEI4");
		break;
	default:
		break;
	}
}


bool CQuery::GetIMEIData()
{
	CString temp;
	_variant_t var;
	CString sql;
	int m_iQCType,m_iBatch;
	CStringArray csaProductName;
	CStringArray csaOrderName;

	m_fColorWeigh = 0.0;
	m_fCartonWeigh = 0.0;
	m_csCarton = "";
	m_csPallet = "";
	csaProductName.RemoveAll();
	csaOrderName.RemoveAll();

	//获取IMEI所属订单
	sql.Format("select * from ProductList WHERE Enable=1");
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("ProductName");
			temp=VariantToCString(var);
			csaProductName.Add(temp);
			
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("OrderName");
			temp=VariantToCString(var);
			csaOrderName.Add(temp);
			
			((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	//遍历数据库中所有ColorBox表，确认当前IMEI所属订单
	for (int i=0;i<csaProductName.GetSize();i++)
	{
		sql.Format("select * from %s_%s_ColorBox WHERE IMEI1='%s' and Enable=1",csaProductName[i],csaOrderName[i],this->m_csIMEI);
		try
		{
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
			((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				this->m_csProduction = csaProductName[i];
				this->m_csOrder = csaOrderName[i];
				UpdateData(FALSE);
				break;
			}
			
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}

		if (i == csaProductName.GetSize()-1)
		{
			MessageBox("该IMEI未进入生产包装流程!","Error",MB_ICONERROR);
			return FALSE;
		}
	}

	sql.Format("select * from %s_%s_ColorBox WHERE IMEI1='%s' and Enable=1",this->m_csProduction,this->m_csOrder,this->m_csIMEI);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("Status");
			m_iIMEIStatus=var.intVal;
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("ColorBoxWeigh");
			m_fColorWeigh=var.dblVal;
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonName");
			m_csCarton=VariantToCString(var);
			m_iflag1 = TRUE;
		}
		else
		{
			m_csStation="该IMEI未进入生产包装流程";
			m_iflag1 = FALSE;
		}

		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	if (m_iflag1 == TRUE)
	{
		if (m_csCarton=="")
		{
			if (m_fColorWeigh == 0.0)
			{
				switch(m_iIMEIStatus)
				{
				case 0:
					m_csStation="写号工位";
					break;
				case 1:
					m_csStation="耦合测试工位";
					break;
				case 2:
					m_csStation="检查机身IMEI工位";
					break;
				case 3:
					m_csStation="彩盒包装工位";
					break;
				case 4:
					m_csStation="检查彩盒IMEI工位";
					break;
				default:
					break;
				}
			}
			else
			{
				m_csStation="彩盒称重工位";
			}
		}
		else
		{
			sql.Format("select * from %s_%s_CartonBox WHERE CartonName='%s'",this->m_csProduction,this->m_csOrder,this->m_csCarton);
			try
			{
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
				((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
				if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
				{
					var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonWeigh");
					m_fCartonWeigh=var.dblVal;

					var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("PalletName");
					m_csPallet=VariantToCString(var);
				}
				
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
			}
			catch(_com_error e)
			{
				return FALSE;
			}

			if (m_fCartonWeigh==0.00)
			{
				m_csStation="卡通箱包装工位";
			}
			else
			{
				if (m_csPallet=="")
				{
					m_csStation="卡通箱称重工位";
				}
				else
				{
					m_csStation="栈板包装工位";
				}
			}
		}
	}

	return TRUE;
}

bool CQuery::GetCartonIMEI()
{
	CString temp;
	_variant_t var;
	CString sql;
	csaIMEI1Range.RemoveAll();
	csaIMEI2Range.RemoveAll();
	csaIMEI3Range.RemoveAll();
	csaIMEI4Range.RemoveAll();

	sql.Format("select * from %s_%s_ColorBox WHERE CartonName='%s' and Enable=1",this->m_csProduction,this->m_csOrder,this->m_csScanCarton);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1");
			temp=VariantToCString(var);
			csaIMEI1Range.Add(temp);

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI2");
			temp=VariantToCString(var);
			csaIMEI2Range.Add(temp);

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI3");
			temp=VariantToCString(var);
			csaIMEI3Range.Add(temp);

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI4");
			temp=VariantToCString(var);
			csaIMEI4Range.Add(temp);

			((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
		}
		
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}


	return true;
}


bool CQuery::GetUnusedIMEIData()
{
	CString temp;
	_variant_t var;
	CString sql;
	int m_iNum;
	CString m_csCurrIMEI1,m_csCurrIMEI2,m_csCurrIMEI3,m_csCurrIMEI4;
	char    calculate_digit1,calculate_digit2,calculate_digit3,calculate_digit4;

	m_csCurrIMEI1.Empty();
	m_csCurrIMEI2.Empty();
	m_csCurrIMEI3.Empty();
	m_csCurrIMEI4.Empty();

	csaUnusedIMEI1.RemoveAll();
	csaUnusedIMEI2.RemoveAll();
	csaUnusedIMEI3.RemoveAll();
	csaUnusedIMEI4.RemoveAll();

	csaIMEI1Range.RemoveAll();
	csaIMEI2Range.RemoveAll();
	csaIMEI3Range.RemoveAll();
	csaIMEI4Range.RemoveAll();

	//获取IMEI类型
	sql.Format("select * from ProductList where Enable=1 and ProductName='%s' and OrderName='%s'",this->m_csProduction,this->m_csOrder);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEIType");
			iIMEIType=var.intVal;

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEIRangeType");
			iIMEIRangeType=var.intVal;
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	if (iIMEIRangeType == 0)
	{
		//获取IMEI范围
		sql.Format("select * from ProductList where Enable=1 and ProductName='%s' and OrderName='%s'",this->m_csProduction,this->m_csOrder);
		try
		{
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
			((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEIType");
				iIMEIType=var.intVal;
				
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEIRangeType");
				iIMEIRangeType=var.intVal;
				
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1_STR");
				csIMEI1Start=VariantToCString(var);
				
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1_END");
				csIMEI1End=VariantToCString(var);
				
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI2_STR");
				csIMEI2Start=VariantToCString(var);
				
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI2_END");
				csIMEI2End=VariantToCString(var);
				
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI3_STR");
				csIMEI3Start=VariantToCString(var);
				
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI3_END");
				csIMEI3End=VariantToCString(var);
				
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI4_STR");
				csIMEI4Start=VariantToCString(var);
				
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI4_END");
				csIMEI4End=VariantToCString(var);
				
				((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
			}
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
		
		//根据设置的IMEI范围，计算出未使用的IMEI
		m_iNum = _atoi64(csIMEI1End.Left(14)) - _atoi64(csIMEI1Start.Left(14)) + 1;
		
		//遍历范围内所有IMEI
		for (int i=0;i<m_iNum;i++)
		{
			switch(iIMEIType)
			{
			case 3:
				m_csCurrIMEI4.Format("%I64u",(_atoi64(csIMEI4Start.Left(14))+i));
				calculate_15_digit_imei((char*)(LPCTSTR)m_csCurrIMEI4,calculate_digit4);
				m_csCurrIMEI4 = m_csCurrIMEI4 + calculate_digit4;
			case 2:
				m_csCurrIMEI3.Format("%I64u",(_atoi64(csIMEI3Start.Left(14))+i));
				calculate_15_digit_imei((char*)(LPCTSTR)m_csCurrIMEI3,calculate_digit3);
				m_csCurrIMEI3 = m_csCurrIMEI3 + calculate_digit3;
			case 1:
				m_csCurrIMEI2.Format("%I64u",(_atoi64(csIMEI2Start.Left(14))+i));
				calculate_15_digit_imei((char*)(LPCTSTR)m_csCurrIMEI2,calculate_digit2);
				m_csCurrIMEI2 = m_csCurrIMEI2 + calculate_digit2;
			case 0:
				m_csCurrIMEI1.Format("%I64u",(_atoi64(csIMEI1Start.Left(14))+i));
				calculate_15_digit_imei((char*)(LPCTSTR)m_csCurrIMEI1,calculate_digit1);
				m_csCurrIMEI1 = m_csCurrIMEI1 + calculate_digit1;
			default:
				break;
			}
						
			sql.Format("select * from %s_%s_ColorBox where IMEI1='%s' and Enable=1",this->m_csProduction,this->m_csOrder,m_csCurrIMEI1);
			try
			{
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
				((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
				if(((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
				{
					csaUnusedIMEI1.Add(m_csCurrIMEI1);
				}
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
			}
			catch(_com_error e)
			{
				return FALSE;
			}
			
			sql.Format("select * from %s_%s_ColorBox where IMEI2='%s' and Enable=1",this->m_csProduction,this->m_csOrder,m_csCurrIMEI2);
			try
			{
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
				((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
				if(((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
				{
					csaUnusedIMEI2.Add(m_csCurrIMEI2);
				}
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
			}
			catch(_com_error e)
			{
				return FALSE;
			}
			
			sql.Format("select * from %s_%s_ColorBox where IMEI3='%s' and Enable=1",this->m_csProduction,this->m_csOrder,m_csCurrIMEI3);
			try
			{
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
				((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
				if(((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
				{
					csaUnusedIMEI3.Add(m_csCurrIMEI3);
				}
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
			}
			catch(_com_error e)
			{
				return FALSE;
			}
			
			sql.Format("select * from %s_%s_ColorBox where IMEI4='%s' and Enable=1",this->m_csProduction,this->m_csOrder,m_csCurrIMEI4);
			try
			{
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
				((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
				if(((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
				{
					csaUnusedIMEI4.Add(m_csCurrIMEI4);
				}
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
			}
			catch(_com_error e)
			{
				return FALSE;
			}
		}
	}
	else if (iIMEIRangeType == 1)
	{
		//获取IMEI范围
		sql.Format("select * from %s_%s_IMEIRange",this->m_csProduction,this->m_csOrder);
		try
		{
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
			((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1");
				temp=VariantToCString(var);
				csaIMEI1Range.Add(temp);
				
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI2");
				temp=VariantToCString(var);
				csaIMEI2Range.Add(temp);
				
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI3");
				temp=VariantToCString(var);
				csaIMEI3Range.Add(temp);
				
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI4");
				temp=VariantToCString(var);
				csaIMEI4Range.Add(temp);
				
				((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
			}
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}

		//遍历范围内所有IMEI
		for (int j=0;j<csaIMEI1Range.GetSize();j++)
		{
			sql.Format("select * from %s_%s_ColorBox where IMEI1='%s' and Enable=1",this->m_csProduction,this->m_csOrder,csaIMEI1Range[j]);
			try
			{
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
				((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
				if(((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
				{
					csaUnusedIMEI1.Add(csaIMEI1Range[j]);
				}
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
			}
			catch(_com_error e)
			{
				return FALSE;
			}
			
			sql.Format("select * from %s_%s_ColorBox where IMEI2='%s' and Enable=1",this->m_csProduction,this->m_csOrder,csaIMEI2Range[j]);
			try
			{
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
				((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
				if(((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
				{
					csaUnusedIMEI2.Add(csaIMEI2Range[j]);
				}
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
			}
			catch(_com_error e)
			{
				return FALSE;
			}
			
			sql.Format("select * from %s_%s_ColorBox where IMEI3='%s' and Enable=1",this->m_csProduction,this->m_csOrder,csaIMEI3Range[j]);
			try
			{
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
				((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
				if(((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
				{
					csaUnusedIMEI3.Add(csaIMEI3Range[j]);
				}
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
			}
			catch(_com_error e)
			{
				return FALSE;
			}
			
			sql.Format("select * from %s_%s_ColorBox where IMEI4='%s' and Enable=1",this->m_csProduction,this->m_csOrder,csaIMEI4Range[j]);
			try
			{
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
				((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
				if(((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
				{
					csaUnusedIMEI4.Add(csaIMEI4Range[j]);
				}
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
			}
			catch(_com_error e)
			{
				return FALSE;
			}
		}
	}
}

CString CQuery::VariantToCString(VARIANT   var)   
{   
	CString strValue;   
	_variant_t var_t;   
	_bstr_t bst_t;   
	//time_t cur_time;   
	CTime time_value;   
	COleCurrency var_currency; 
	COleDateTime cur_time;
    
	switch(var.vt)   
	{   
	case   VT_EMPTY:   
		strValue   =   _T("");   
		break;   
	case   VT_UI1:   
		strValue.Format("%d",var.bVal);   
		break;   
	case   VT_I2:   
		strValue.Format("%d",var.iVal);   
		break;   
	case   VT_I4:   
		strValue.Format("%d",var.lVal);   
		break;   
	case   VT_R4:   
		strValue.Format("%f",var.fltVal);   
		break;   
	case   VT_R8:   
		strValue.Format("%f",var.dblVal);   
		break;   
	case   VT_CY:   
		var_currency   =   var;   
		strValue   =   var_currency.Format(0);   
		break;   
	case   VT_BSTR:   
		var_t   =   var;   
		bst_t   =   var_t;   
		strValue.Format   ("%s",(const   char*)bst_t);   
		break;   
	case   VT_NULL:   
		strValue   =   _T("");   
		break;   
	case   VT_DATE:   
		//cur_time   =   (long)var.date;   
		// time_value   =   cur_time;   
		// strValue   =   time_value.Format("%Y-%m-%d");  
		cur_time   =   var; 
		strValue   =   cur_time.Format("%Y-%m-%d"); 
		break;   
	case   VT_BOOL:   
		strValue.Format("%d",var.boolVal   );   
		break;   
	default:     
		strValue   =   _T("");   
		break;   
	}   

	return   strValue;   
}

void CQuery::OnBtnExport()
{
	//excel
	_Application m_ExlApp;
	_Workbook    m_ExlBook;
	_Worksheet   m_ExlSheet;
	Workbooks    m_ExlBooks;
	Worksheets   m_ExlSheets;
	Range        m_ExlRge;
	COleVariant covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	int j;
	
	//获取当前路径
	char csPath[MAX_PATH];
	CString PathSource,PathDest;
   	GetCurrentDirectory(MAX_PATH, csPath);
	
	//获取模板文件路径
	PathSource=CString(csPath)+"\\Template.xls";

	//创建EXCEL进程
	if(!m_ExlApp.CreateDispatch("Excel.Application",NULL))
	{
		MessageBox("创建EXCEL服务失败!","Error",MB_ICONERROR);
		return;
	}

	m_ExlBooks.AttachDispatch(m_ExlApp.GetWorkbooks(),TRUE);
	
	//加载EXCEL模板
	m_ExlBook.AttachDispatch(m_ExlBooks.Add((_variant_t)PathSource),TRUE);

	//获取Worksheets
	m_ExlSheets.AttachDispatch(m_ExlBook.GetWorksheets(),true);

	//获取sheet1
	m_ExlSheet.AttachDispatch(m_ExlSheets.GetItem(_variant_t("sheet1")),true);
	
	//加载所有单元格
	m_ExlRge.AttachDispatch(m_ExlSheet.GetCells(),TRUE);
	
	switch(m_iOperateType)
	{
	case 2:
		//生成目标文件路径
		PathDest=CString(csPath)+"\\出货数据\\"+this->m_csProduction+"_"+this->m_csOrder+"_未使用IMEI"+".xls";

		//填充EXCEL表格内容
		m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t("序号"));
		m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)2),_variant_t("未使用IMEI1"));
		m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)3),_variant_t("未使用IMEI2"));
		m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)4),_variant_t("未使用IMEI3"));
		m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)5),_variant_t("未使用IMEI4"));
		
		for (j=2;j<(this->csaUnusedIMEI1.GetSize())+2;j++)
		{
			m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)1),_variant_t((long)(j-1)));
			m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)2),_variant_t(this->csaUnusedIMEI1[j-2]));
			m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)3),_variant_t(this->csaUnusedIMEI2[j-2]));
			m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)4),_variant_t(this->csaUnusedIMEI3[j-2]));
			m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)5),_variant_t(this->csaUnusedIMEI4[j-2]));
		}
		break;
	default:
		break;
	}

	//加载已使用的单元格
	m_ExlRge.AttachDispatch(m_ExlSheet.GetUsedRange(),TRUE);
	
	//设置左边对齐
	m_ExlRge.SetHorizontalAlignment((_variant_t)(long)-4131);

	//保存数据到EXCEL
	m_ExlBook.SaveAs(COleVariant(PathDest),covOptional,covOptional,covOptional,covOptional,covOptional,0,covOptional,covOptional,covOptional,covOptional,covOptional);

	//退出
	m_ExlApp.Quit();

	//释放对象
	m_ExlRge.ReleaseDispatch();
	m_ExlSheet.ReleaseDispatch();
	m_ExlSheets.ReleaseDispatch();
	m_ExlBook.ReleaseDispatch();
	m_ExlBooks.ReleaseDispatch();
	m_ExlApp.ReleaseDispatch();

	MessageBox("导出数据成功!");
}

void CQuery::calculate_15_digit_imei( char *imei_14,char &calculate_digit)
{
	int check_digit,sum1,sum2,total_sum,temp_value,temp_value_2_part;
	int i;
	char temp[16];
	
	
	// the following is calculate IMEI 15th digit -- check digit //
	// according   3G TS 22.016  V3.1.0 //
	/*
	A.2 Computation of Check Digit for an IMEI
	Computation of CD from the IMEI proceeds as follows:
	Step 1: Double the values of the odd labelled digits D1, D3, D5 ... D13 of the IMEI.
	Step 2: Add together the individual digits of all the seven numbers obtained in Step 1, and then add this sum to
	the sum of all the even labelled digits D2, D4, D6 ... D14 of the IMEI.
	Step 3: If the number obtained in Step 2 ends in 0, then set CD to be 0. If the number obtained in Step 2 does not
	end in 0, then set CD to be that number subtracted from the next higher number which does end in 0.
	
	  
		A.3 Example of computation
		IMEI (14 most significant digits):
		TAC FAC SNR
		D14  D13 D12 D11 D10 D9 D8 D7  D6 D5 D4 D3 D2 D1
		2    6   0   5   3   1  7  9  3   1  1  3  8  3
		Step 1:
		2    6   0   5   3   1  7  9  3   1  1  3  8  3 
		x2      x2      x2    x2     x2    x2   x2
		12      10      2     18     2      6    6
		Step 2:
		2 + 1 + 2 + 0 + 1 + 0 + 3 + 2 + 7 + 1 + 8 + 3 + 2 + 1 + 6 + 8 + 6 = 53
		Step 3:
		CD = 60 - 53 = 7
	*/
	for(i=0;i<14;i++)
		temp[i] = imei_14[i];
	
	sum1 = 0;
	for (i=1;i<=13;i++)		  // sum digit 1,3,5,7,9,11,13
	{
		sum1 = sum1 + (temp[i-1]-48);
		i++;
	}
	sum2 = 0;
	for (i=2;i<=14;i++)			 // sum digit 2,4,6,8,10,12,14   
	{
		temp_value =  (temp[i-1]-48) * 2 ;			// temp_value range from 0 --> 9*2 = 18
		if ( temp_value < 10 )  
			sum2 = sum2 +  temp_value ;
		else  
		{
			temp_value_2_part = temp_value - 10 ;
			sum2 = sum2 + 1 +temp_value_2_part;
		} 
		
		i++;				  
	}
	
	total_sum = sum1 + sum2 ;
	
	if ( fmod(total_sum,10) == 0 )
		check_digit = 0  ; 	   // if total_sum ends in 0 ( mod 10 reminder is 0 ) 
	else 
	{
		check_digit = (total_sum /10)*10 + 10 - total_sum;
		
	}
	calculate_digit=check_digit+48;
	
}


