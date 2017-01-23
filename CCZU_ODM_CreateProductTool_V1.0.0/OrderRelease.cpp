// OrderRelease.cpp : implementation file
//

#include "stdafx.h"
#include "CreateProduct.h"
#include "OrderRelease.h"
#include "Splash.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COrderRelease dialog


COrderRelease::COrderRelease(CWnd* pParent /*=NULL*/)
	: CDialog(COrderRelease::IDD, pParent)
{
	//{{AFX_DATA_INIT(COrderRelease)
	m_csProductName = _T("");
	m_csOrderName = _T("");
	m_csCartonNameBegin = _T("");
	m_csCartonNameEnd = _T("");
	m_csCartonNameLength = _T("");
	m_csCartonMaxCount = _T("");
	m_csCartonNameStatic = _T("");
	m_csColor = _T("");
	m_csPlannedOutput = _T("");
	m_csPalletNameStatic = _T("");
	m_csPalletMaxCount = _T("");
	m_csPalletNameLength = _T("");
	m_csIMEIType = _T("");
	m_csIMEIRangeType = _T("");
	m_csIMEI1_STR = _T("");
	m_csIMEI1_END = _T("");
	m_csIMEI2_END = _T("");
	m_csIMEI3_END = _T("");
	m_csIMEI4_END = _T("");
	m_csIMEI2_STR = _T("");
	m_csIMEI3_STR = _T("");
	m_csIMEI4_STR = _T("");
	m_iPlat = -1;
	m_bBoardVer = FALSE;
	m_bBTFT = FALSE;
	m_bResetFactory = FALSE;
	m_bVer = FALSE;
	m_csBoardVer = _T("");
	m_csVer = _T("");
	m_csCartonHighWeigh = _T("");
	m_csCartonLowWeigh = _T("");
	m_csColorHighWeigh = _T("");
	m_csColorLowWeigh = _T("");
	m_csSNStatic = _T("");
	m_bScanPSN = FALSE;
	m_bWrite = FALSE;
	m_csPSNLen = _T("");
	m_bPSNCHK = FALSE;
	m_csPSN_CHK = _T("");
	m_bScanNet = FALSE;
	m_csNetLength = _T("");
	m_csNetHeader = _T("");
	m_csCustomer = _T("");
	//}}AFX_DATA_INIT
}


void COrderRelease::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COrderRelease)
	DDX_Control(pDX, IDC_COMBO_PRODUCTION, m_ctrProductName);
	DDX_Control(pDX, IDC_COMBO_ORDER, m_ctrOrderName);
	DDX_CBString(pDX, IDC_COMBO_PRODUCTION, m_csProductName);
	DDX_CBString(pDX, IDC_COMBO_ORDER, m_csOrderName);
	DDX_Text(pDX, IDC_STATIC_CARTONBEGIN, m_csCartonNameBegin);
	DDX_Text(pDX, IDC_STATIC_CARTONEND, m_csCartonNameEnd);
	DDX_Text(pDX, IDC_STATIC_CARTONLENTH, m_csCartonNameLength);
	DDX_Text(pDX, IDC_STATIC_CARTONMAXCOUNT, m_csCartonMaxCount);
	DDX_Text(pDX, IDC_STATIC_CARTONSTATIC, m_csCartonNameStatic);
	DDX_Text(pDX, IDC_STATIC_COLOR, m_csColor);	
	DDX_Text(pDX, IDC_STATIC_PLANOUTPUT, m_csPlannedOutput);
	DDX_Text(pDX, IDC_STATIC_PALLETSTATIC, m_csPalletNameStatic);
	DDX_Text(pDX, IDC_STATIC_PALLETMAXCOUNT, m_csPalletMaxCount);
	DDX_Text(pDX, IDC_STATIC_PALLETLENTH, m_csPalletNameLength);
	DDX_Text(pDX, IDC_STATIC_IMEITYPE, m_csIMEIType);
	DDX_Text(pDX, IDC_STATIC_IMEIRANGETYPE, m_csIMEIRangeType);
	DDX_Text(pDX, IDC_STATIC_IMEI1STR, m_csIMEI1_STR);
	DDX_Text(pDX, IDC_STATIC_IMEI1END, m_csIMEI1_END);
	DDX_Text(pDX, IDC_STATIC_IMEI2END, m_csIMEI2_END);
	DDX_Text(pDX, IDC_STATIC_IMEI3END, m_csIMEI3_END);
	DDX_Text(pDX, IDC_STATIC_IMEI4END, m_csIMEI4_END);
	DDX_Text(pDX, IDC_STATIC_IMEI2STR, m_csIMEI2_STR);
	DDX_Text(pDX, IDC_STATIC_IMEI3STR, m_csIMEI3_STR);
	DDX_Text(pDX, IDC_STATIC_IMEI4STR, m_csIMEI4_STR);
	DDX_Radio(pDX, IDC_RADIO_PLAT_SP, m_iPlat);
	DDX_Check(pDX, IDC_CHECK_BOARD_VERSION, m_bBoardVer);
	DDX_Check(pDX, IDC_CHECK_BTFT, m_bBTFT);
	DDX_Check(pDX, IDC_CHECK_RESET_FACTORY, m_bResetFactory);
	DDX_Check(pDX, IDC_CHECK_VERSION, m_bVer);
	DDX_Text(pDX, IDC_STATIC_BOARD_VERSION, m_csBoardVer);
	DDX_Text(pDX, IDC_STATIC_VERSION, m_csVer);
	DDX_Text(pDX, IDC_STATIC_CARTON_HIGH_WEIGH, m_csCartonHighWeigh);
	DDX_Text(pDX, IDC_STATIC_CARTON_LOW_WEIGH, m_csCartonLowWeigh);
	DDX_Text(pDX, IDC_STATIC_COLOR_HIGH_WEIGH, m_csColorHighWeigh);
	DDX_Text(pDX, IDC_STATIC_COLOR_LOW_WEIGH, m_csColorLowWeigh);
	DDX_Text(pDX, IDC_STATIC_SNSTATIC, m_csSNStatic);
	DDX_Check(pDX, IDC_CHECK_SCANPSN, m_bScanPSN);
	DDX_Check(pDX, IDC_CHECK_WRITETOPHONE, m_bWrite);
	DDX_Text(pDX, IDC_STATIC_PSN_LENGTH, m_csPSNLen);
	DDX_Check(pDX, IDC_CHECK_PSNCHK, m_bPSNCHK);
	DDX_Text(pDX, IDC_STATIC_PSN_CHK2, m_csPSN_CHK);
	DDX_Check(pDX, IDC_CHECK_SCANNET, m_bScanNet);
	DDX_Text(pDX, IDC_STATIC_NET_LENGTH2, m_csNetLength);
	DDX_Text(pDX, IDC_STATIC_NET_HEADER2, m_csNetHeader);
	DDX_Text(pDX, IDC_STATIC_CUSTOMER, m_csCustomer);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COrderRelease, CDialog)
	//{{AFX_MSG_MAP(COrderRelease)
	ON_CBN_CLOSEUP(IDC_COMBO_PRODUCTION, OnCloseupComboProduction)
	ON_CBN_CLOSEUP(IDC_COMBO_ORDER, OnCloseupComboOrder)
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COrderRelease message handlers

BOOL COrderRelease::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CSplashWnd::ShowSplashScreen(this);

	SCROLLINFO vinfo;
	vinfo.cbSize=sizeof(vinfo);
	vinfo.fMask=SIF_ALL;
	vinfo.nPage=100;//滚动块自身的长短，通常有如下关系：其长度/滚动条长度（含两个箭头）=nPage/(nMax+2)， 
	//另外nPage取值-1时，滚动条会不见了。  
	vinfo.nMax=150;//滚动条所能滚动的最大值  
	vinfo.nMin=0;//滚动条所能滚动的最小值
	vinfo.nPos = 0;
	SetScrollInfo(SB_VERT,&vinfo);//即使上述步骤一不做，使用此条语句也可以显示滚动条

	UpdateData(FALSE);
	
	//获取项目列表
	if(!this->GetProductList())
	{
		MessageBox("Get Product List Fail!", "Error", MB_OK);
		exit(0);
	}
 
//	MoveWindow(250,100,730,670); //lucky 改变窗口的位置和大小 
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COrderRelease::OnCloseupComboProduction()
{
	UpdateData();

	int  index;

	index = this->m_ctrProductName.GetCurSel();
	if(index == -1)
		return;
	this->m_ctrProductName.GetLBText(index,m_csProductName);

	//获取所选项目对应订单插入到Combox中
	if(!this->GetOrderList())
	{
		MessageBox("Get Order List Fail!","Error",MB_ICONERROR);
		return;
	}

	UpdateData(FALSE);
}

void COrderRelease::OnCloseupComboOrder() 
{
	UpdateData();

	int index;

	index = this->m_ctrOrderName.GetCurSel();
	if(index == -1)
		return;	
	this->m_ctrOrderName.GetLBText(index,m_csOrderName);

	//获取项目列表
	if(!this->GetProductOrderInfo())
	{
		MessageBox("Get Product List Fail!","Error",MB_ICONERROR);
		return;
	}
	
	UpdateData(FALSE);
}

void COrderRelease::OnOK() 
{
	// TODO: Add extra validation here

	CString temp;
	CString sql;
	_variant_t var;

	try
	{
		sql.Format("UPDATE ProductList SET Enable = 1, ReleaseUser = '%s' where OrderName = '%s'",((CCreateProductApp *)AfxGetApp())->m_csReleaseUser,m_csOrderName);

		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
		((CCreateProductApp *)AfxGetApp())->m_pRst=((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		MessageBox("Release Order Fail!", "Error", MB_OK);
		return;
	}	

	MessageBox("Release Order Pass!", MB_OK);
	CleanUI();
//	CDialog::OnOK();
}

BOOL COrderRelease::GetProductList()
{
	CString temp;
	CString sql;
	_variant_t var;

	try
	{
		sql="select DISTINCT ProductName from ProductList";
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
		((CCreateProductApp *)AfxGetApp())->m_pRst=((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);		
		while(!((CCreateProductApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("ProductName"); 
			temp=var.bstrVal;
			this->m_ctrProductName.AddString(temp);
			((CCreateProductApp *)AfxGetApp())->m_pRst->MoveNext();
		}
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}	

	return TRUE;
}


BOOL COrderRelease::GetOrderList()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	try
	{
		sql.Format("select *  from ProductList where ProductName='%s' and Enable = 3",this->m_csProductName);
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
		((CCreateProductApp *)AfxGetApp())->m_pRst=((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);		
		while(!((CCreateProductApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("OrderName"); 
			temp=var.bstrVal;
			this->m_ctrOrderName.AddString(temp);
			((CCreateProductApp *)AfxGetApp())->m_pRst->MoveNext();
		}
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}


BOOL COrderRelease::GetProductOrderInfo()
{
	_variant_t var;
	CString sql;
	int i,itemp;
	float j,x,y;
	
	try
	{
		sql.Format("select *  from ProductList where Enable=3 and OrderName='%s'",m_csOrderName);
		
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
		((CCreateProductApp *)AfxGetApp())->m_pRst=((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CCreateProductApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("SNStatic");
			m_csSNStatic=var.bstrVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CustomerNo");
			m_csCustomer=var.bstrVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("IMEIType");
			i=var.uintVal;

			switch(i) 
			{
			case 0:
				m_csIMEIType = "1 IMEI";
				break;
			case 1:
				m_csIMEIType = "2 IMEI";
				break;
			case 2:
				m_csIMEIType = "3 IMEI";
				break;
			case 3:
				m_csIMEIType = "4 IMEI";
				break;
			default:
				break; 
			}

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("IMEIRangeType");
			i=var.uintVal;

			switch(i) 
			{
			case 0:
				m_csIMEIRangeType = "Manual Input";
				break;
			case 1:
				m_csIMEIRangeType = "EXCEL Export";
				break;
			default:
				break; 
			}

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1_STR");
			m_csIMEI1_STR=var.bstrVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1_END");
			m_csIMEI1_END=var.bstrVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("IMEI2_STR");
			m_csIMEI2_STR=var.bstrVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("IMEI2_END");
			m_csIMEI2_END=var.bstrVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("IMEI3_STR");
			m_csIMEI3_STR=var.bstrVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("IMEI3_END");
			m_csIMEI3_END=var.bstrVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("IMEI4_STR");
			m_csIMEI4_STR=var.bstrVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("IMEI4_END");
			m_csIMEI4_END=var.bstrVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CartonNameStatic");
			m_csCartonNameStatic=var.bstrVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CartonNameSNLength");
			i=var.uintVal;
			m_csCartonNameLength.Format("%d",i);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CartonNameBegin");
			m_csCartonNameBegin=var.bstrVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CartonNameEnd");
			m_csCartonNameEnd=var.bstrVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CartonMaxCount");
			i=var.uintVal;
			m_csCartonMaxCount.Format("%d",i);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("PalletNameStatic");
			m_csPalletNameStatic=var.bstrVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("PalletNameSNLength");
			i=var.uintVal;
			m_csPalletNameLength.Format("%d",i);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("PalletMaxCount");
			i=var.uintVal;
			m_csPalletMaxCount.Format("%d",i);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("PlannedOutput");
			i=var.uintVal;
			m_csPlannedOutput.Format("%d",i);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("Color");
			m_csColor=var.bstrVal;

		}
		else
		{
			return  FALSE;
		}
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	try
	{
		sql.Format("select *  from SettingList where Enable=1 and OrderName='%s'",m_csOrderName);
		
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
		((CCreateProductApp *)AfxGetApp())->m_pRst=((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CCreateProductApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("Platform");
			m_iPlat=var.uintVal-1;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("BTFT");
			m_bBTFT=var.uintVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("ResetFactory");
			m_bResetFactory=var.uintVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CheckVersion");
			m_bVer=var.uintVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("VersionCode");
			m_csVer=var.bstrVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CheckBoardVersion");
			m_bBoardVer=var.uintVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("BoardVersionCode");
			m_csBoardVer=var.bstrVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("ColorBoxLowWeigh");
			j=var.dblVal;
			m_csColorLowWeigh.Format("%.4f",j);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("ColorBoxHighWeigh");
			j=var.dblVal;
			m_csColorHighWeigh.Format("%.4f",j);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CartonBoxLowWeigh");
			j=var.dblVal;
			m_csCartonLowWeigh.Format("%.4f",j);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CartonBoxHighWeigh");
			j=var.dblVal;
			m_csCartonHighWeigh.Format("%.4f",j);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("ScanPSN");
			m_bScanPSN=var.uintVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("WritePSNToPhone");
			m_bWrite=var.uintVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CheckPSN");
			m_bPSNCHK=var.uintVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("ScanNetCode");
			m_bScanNet=var.uintVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("PSNCheckBit");
			m_csPSN_CHK=var.bstrVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("NetCodeHeader");
			m_csNetHeader=var.bstrVal;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("PSNLength");
			i=var.intVal;
			m_csPSNLen.Format("%d",i); 

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("NetCodeLength");
			i=var.intVal;
			m_csNetLength.Format("%d",i);

		}
		else
		{
			return  FALSE;
		}
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	
	return TRUE;
}

void COrderRelease::CleanUI()
{
	m_csProductName.Empty();
	m_csOrderName.Empty();
	m_ctrOrderName.ResetContent();
	UpdateData(FALSE);
	m_iPlat = -1;
	m_bBoardVer = FALSE;
	m_bBTFT = FALSE;
	m_bResetFactory = FALSE;

	m_bVer = FALSE;
	m_csCustomer.Empty();
	m_csSNStatic.Empty();
	m_csCartonNameBegin.Empty();
	m_csCartonNameEnd.Empty();
	m_csCartonNameLength.Empty();
	m_csCartonMaxCount.Empty();
	m_csCartonNameStatic.Empty();
	m_csColor.Empty();

	m_csPlannedOutput.Empty();

	m_bScanPSN = FALSE;
	m_bWrite   = FALSE;
	m_csPSNLen.Empty();
	m_bPSNCHK = FALSE;
	m_csPSN_CHK.Empty();
	m_bScanNet = FALSE;
	m_csNetLength.Empty();
	m_csNetHeader.Empty();

	m_csPalletNameStatic.Empty();
	m_csPalletMaxCount.Empty();
	m_csPalletNameLength.Empty();
	m_csIMEIType.Empty();
	m_csIMEIRangeType.Empty();
	m_csIMEI1_STR.Empty();
	m_csIMEI1_END.Empty();
	m_csIMEI2_END.Empty();
	m_csIMEI3_END.Empty();
	m_csIMEI4_END.Empty();
	m_csIMEI2_STR.Empty();
	m_csIMEI3_STR.Empty();
	m_csIMEI4_STR.Empty();

	m_csBoardVer.Empty();
	m_csVer.Empty();
	m_csCartonHighWeigh.Empty();
	m_csCartonLowWeigh.Empty();
	m_csColorHighWeigh.Empty();
	m_csColorLowWeigh.Empty();
		
	UpdateData(FALSE);
}

void COrderRelease::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	SCROLLINFO scrollinfo;  
	GetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);
	
	switch (nSBCode)
	{
	case SB_BOTTOM: //滑块滚动到最底部
		ScrollWindow(0,(scrollinfo.nPos-scrollinfo.nMax)*10); //滚动屏幕  
		scrollinfo.nPos = scrollinfo.nMax; //设定滑块新位置  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL); //更新滑块位置  
		break;  
	case SB_TOP: //滑块滚动到最顶部
		ScrollWindow(0,(scrollinfo.nPos-scrollinfo.nMin)*10);  
		scrollinfo.nPos = scrollinfo.nMin;  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);
		break;  
	case SB_LINEUP: //单击上箭头  
		scrollinfo.nPos -= 1;
		if (scrollinfo.nPos<scrollinfo.nMin)  
		{  
			scrollinfo.nPos = scrollinfo.nMin;  
			break;  
		}  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);  
		ScrollWindow(0,10);  
		break;  
	case SB_LINEDOWN: //单击下箭头  
		scrollinfo.nPos += 1;  
		if (scrollinfo.nPos>scrollinfo.nMax)  
		{  
			scrollinfo.nPos = scrollinfo.nMax;  
			break;  
		}  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);  
		ScrollWindow(0,-10);  
		break;  
	case SB_PAGEUP: //单击滑块上方空白区域  
		scrollinfo.nPos -= 5;  
		if (scrollinfo.nPos<scrollinfo.nMin)  
		{  
			scrollinfo.nPos = scrollinfo.nMin;  
			break;  
		}  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);  
		ScrollWindow(0,10*5);  
		break;  
	case SB_PAGEDOWN: //单击滑块下方空白区域  
		scrollinfo.nPos += 5;  
		if (scrollinfo.nPos>scrollinfo.nMax)  
		{  
			scrollinfo.nPos = scrollinfo.nMax;  
			break;  
		}  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);  
		ScrollWindow(0,-10*5);  
		break;  
	case SB_ENDSCROLL: //鼠标离开滑块，结束滑块拖动  
		// MessageBox("SB_ENDSCROLL");  
		break;  
	case SB_THUMBPOSITION:  
		// ScrollWindow(0,(scrollinfo.nPos-nPos)*10);  
		// scrollinfo.nPos = nPos;  
		// SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);  
		break;  
	case SB_THUMBTRACK: //拖动滑块  
		ScrollWindow(0,(scrollinfo.nPos-nPos)*10);  
		scrollinfo.nPos = nPos;  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);  
		break;  
	}

	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}
