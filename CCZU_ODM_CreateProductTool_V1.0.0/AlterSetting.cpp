// AlterSetting.cpp : implementation file
//

#include "stdafx.h"
#include "CreateProduct.h"
#include "AlterSetting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAlterSetting dialog


CAlterSetting::CAlterSetting(CWnd* pParent /*=NULL*/)
	: CDialog(CAlterSetting::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAlterSetting)
	m_bCheckBoardVersion = FALSE;
	m_bCheckBTFT = FALSE;
	m_bCheckResetFactory = FALSE;
	m_bCheckVersion = FALSE;
	m_csBoardVersion = _T("");
	m_csVersion = _T("");
	m_dCartonHighWeigh = 0.0;
	m_dCartonLowWeigh = 0.0;
	m_dColorHighWeigh = 0.0;
	m_dColorLowWeigh = 0.0;
	m_iRadioPlat = -1;
	m_iComboxProduct = -1;
	m_iComboxOrder = -1;
	m_color_resource_path2 = _T("");
	m_pack_resource_path_sub2 = _T("");
	m_pack_resource_path2 = _T("");
	m_pallet_resource_path_sub2 = _T("");
	m_pallet_resource_path2 = _T("");
	m_iCartonNameLength2 = 0;
	m_csCartonNameStatic2 = _T("");
	m_iMaxCount2 = 0;
	m_iPalletMaxCount2 = 0;
	m_iPalletNameLength2 = 0;
	m_csPalletNameStatic2 = _T("");
	m_color_resource_path_sub2 = _T("");
	m_bCheckScanPSN = FALSE;
	m_iPSNLength = 0;
	m_bCheckPSNChk = FALSE;
	m_csPSNChk = _T("");
	m_bCheckWrite = FALSE;
	m_bScanNetCode = FALSE;
	m_iNetLength = 0;
	m_csNetHeader = _T("");
	//}}AFX_DATA_INIT
}


void CAlterSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAlterSetting)
	DDX_Control(pDX, IDC_EDITVERSION, m_ctrVersion);
	DDX_Control(pDX, IDC_EDITBOARD_VERSION, m_ctrBoardVersion);
	DDX_Check(pDX, IDC_CHECKBOARD_VERSION, m_bCheckBoardVersion);
	DDX_Check(pDX, IDC_CHECKBTFT, m_bCheckBTFT);
	DDX_Check(pDX, IDC_CHECKRESET_FACTORY, m_bCheckResetFactory);
	DDX_Check(pDX, IDC_CHECKVERSION, m_bCheckVersion);
	DDX_Text(pDX, IDC_EDITBOARD_VERSION, m_csBoardVersion);
	DDX_Text(pDX, IDC_EDITVERSION, m_csVersion);
	DDX_Text(pDX, IDC_EDITCARTON_HIGH_WEIGH, m_dCartonHighWeigh);
	DDX_Text(pDX, IDC_EDITCARTON_LOW_WEIGH, m_dCartonLowWeigh);
	DDX_Text(pDX, IDC_EDITCOLOR_HIGH_WEIGH, m_dColorHighWeigh);
	DDX_Text(pDX, IDC_EDITCOLOR_LOW_WEIGH, m_dColorLowWeigh);
	DDX_Radio(pDX, IDC_RADIOPLAT_SP, m_iRadioPlat);
	DDX_Control(pDX, IDC_COMBOPRODUCT, m_ctrComboxProduct);
	DDX_Control(pDX, IDC_COMBOORDER, m_ctrComboxOrder);
	DDX_CBIndex(pDX, IDC_COMBOPRODUCT, m_iComboxProduct);
	DDX_CBIndex(pDX, IDC_COMBOORDER, m_iComboxOrder);
	DDX_Text(pDX, IDC_EDIT_COLOR_PATH2, m_color_resource_path2);
	DDX_Text(pDX, IDC_EDIT_PACK_PATH_SUB2, m_pack_resource_path_sub2);
	DDX_Text(pDX, IDC_EDIT_PACK_PATH2, m_pack_resource_path2);
	DDX_Text(pDX, IDC_EDIT_PALLET_PATH_SUB2, m_pallet_resource_path_sub2);
	DDX_Text(pDX, IDC_EDIT_PALLET_PATH2, m_pallet_resource_path2);
	DDX_Text(pDX, IDC_EDIT_CARTON_NAME_LENGTH2, m_iCartonNameLength2);
	DDX_Text(pDX, IDC_EDIT_CARTON_NAME_STATIC2, m_csCartonNameStatic2);
	DDX_Text(pDX, IDC_EDIT_MAX_COUNT2, m_iMaxCount2);
	DDX_Text(pDX, IDC_EDIT_PALLET_MAX_COUNT2, m_iPalletMaxCount2);
	DDX_Text(pDX, IDC_EDIT_PALLET_NAME_LENGTH2, m_iPalletNameLength2);
	DDX_Text(pDX, IDC_EDIT_PALLET_NAME_STATIC2, m_csPalletNameStatic2);
	DDX_Text(pDX, IDC_EDIT_COLOR_PATH_SUB2, m_color_resource_path_sub2);
	DDX_Check(pDX, IDC_CHECKSCANPSN2, m_bCheckScanPSN);
	DDX_Text(pDX, IDC_EDITPSN_LENGTH2, m_iPSNLength);
	DDX_Check(pDX, IDC_CHECKPSNCHK2, m_bCheckPSNChk);
	DDX_Text(pDX, IDC_EDITPSN_CHK2, m_csPSNChk);
	DDX_Check(pDX, IDC_CHECKWRITETOPHONE, m_bCheckWrite);
	DDX_Check(pDX, IDC_CHECKSCANNETCODE2, m_bScanNetCode);
	DDX_Text(pDX, IDC_EDITNET_LENGTH2, m_iNetLength);
	DDX_Text(pDX, IDC_EDITNET_HEADER2, m_csNetHeader);
	//}}AFX_DATA_MAP
}



BEGIN_MESSAGE_MAP(CAlterSetting, CDialog)
	//{{AFX_MSG_MAP(CAlterSetting)
	ON_CBN_CLOSEUP(IDC_COMBOPRODUCT, OnCloseupComboProduct)
	ON_CBN_CLOSEUP(IDC_COMBOORDER, OnCloseupComboOrder)
	ON_BN_CLICKED(IDC_CHECKVERSION, OnCheckVersion)
	ON_BN_CLICKED(IDC_CHECKBOARD_VERSION, OnCheckBoardVersion)
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_BTN_COLOR_OPEN2, OnBtnColorOpen2)
	ON_BN_CLICKED(IDC_BTN_PACK_OPEN2, OnBtnPackOpen2)
	ON_BN_CLICKED(IDC_BTN_PACK_OPEN_SUB2, OnBtnPackOpenSub2)
	ON_BN_CLICKED(IDC_BTN_PALLET_OPEN2, OnBtnPalletOpen2)
	ON_BN_CLICKED(IDC_BTN_PALLET_OPEN_SUB2, OnBtnPalletOpenSub2)
	ON_BN_CLICKED(IDC_BTN_COLOR_OPEN_SUB2, OnBtnColorOpenSub2)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAlterSetting message handlers

BOOL CAlterSetting::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	SCROLLINFO vinfo;
	vinfo.cbSize=sizeof(vinfo);
	vinfo.fMask=SIF_ALL;
	vinfo.nPage=100;//滚动块自身的长短，通常有如下关系：其长度/滚动条长度（含两个箭头）=nPage/(nMax+2)，  
	//另外nPage取值-1时，滚动条会不见了。  
	vinfo.nMax=150;//滚动条所能滚动的最大值  
	vinfo.nMin=0;//滚动条所能滚动的最小值
	vinfo.nPos = 0;
	SetScrollInfo(SB_VERT,&vinfo);//即使上述步骤一不做，使用此条语句也可以显示滚动条

	//获取项目列表
	if(!this->GetProductList())
	{
		MessageBox("Get Product List Fail!");
		return FALSE;
	}

	this->m_iRadioPlat = 0; 
	this->m_ctrVersion.EnableWindow(FALSE);
	this->m_ctrBoardVersion.EnableWindow(FALSE); 
	
//	MoveWindow(250,100,490,880); //lucky 改变窗口的位置和大小
	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


CString CAlterSetting::VariantToCString(VARIANT var)
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


bool CAlterSetting::GetProductList()
{
	CString temp;
	_variant_t var;
	CString sql;

	try
	{
		sql="select DISTINCT ProductName from ProductList";
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
		((CCreateProductApp *)AfxGetApp())->m_pRst=((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);		
		while(!((CCreateProductApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("ProductName"); 
			temp=VariantToCString(var);
			this->m_ctrComboxProduct.AddString(temp);
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


bool CAlterSetting::GetProductOrderList()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	try
	{
		sql.Format("select *  from ProductList where ProductName='%s' and Enable=1",this->m_csProduct);
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
		((CCreateProductApp *)AfxGetApp())->m_pRst=((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);		
		while(!((CCreateProductApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("OrderName");
			temp=VariantToCString(var);
			this->m_ctrComboxOrder.AddString(temp);
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


bool CAlterSetting::GetProductOrderSetting()
{
	_variant_t var;
	CString sql;
	int itemp;

	try
	{
		sql.Format("select *  from ProductList where Enable=1 and ProductName='%s' and OrderName='%s'",this->m_csProduct,this->m_csOrder);
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
		((CCreateProductApp *)AfxGetApp())->m_pRst=((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);		
		if(!((CCreateProductApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CartonNameStatic");
			m_csCartonNameStatic2=VariantToCString(var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CartonNameSNLength");
			m_iCartonNameLength2 = atoi((_bstr_t)var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CartonMaxCount");
			m_iMaxCount2 = atoi((_bstr_t)var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("PalletNameStatic");
			m_csPalletNameStatic2=VariantToCString(var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("PalletNameSNLength");
			m_iPalletNameLength2 = atoi((_bstr_t)var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("PalletMaxCount");
			m_iPalletMaxCount2 = atoi((_bstr_t)var);
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
		sql.Format("select *  from SettingList where Enable=1 and ProductName='%s' and OrderName='%s'",this->m_csProduct,this->m_csOrder);
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
		((CCreateProductApp *)AfxGetApp())->m_pRst=((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);		
		if(!((CCreateProductApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("Platform");
			m_iRadioPlat = atoi((_bstr_t)var)-1;

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("BTFT");
			m_bCheckBTFT = atoi((_bstr_t)var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("ResetFactory");
			m_bCheckResetFactory = atoi((_bstr_t)var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CheckVersion");
			m_bCheckVersion = atoi((_bstr_t)var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("VersionCode"); 
			m_csVersion=VariantToCString(var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CheckBoardVersion");
			m_bCheckBoardVersion = atoi((_bstr_t)var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("BoardVersionCode"); 
			m_csBoardVersion=VariantToCString(var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("ColorBoxLowWeigh");
			m_dColorLowWeigh = atof((_bstr_t)var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("ColorBoxHighWeigh");
			m_dColorHighWeigh = atof((_bstr_t)var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CartonBoxLowWeigh");
			m_dCartonLowWeigh = atof((_bstr_t)var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CartonBoxHighWeigh");
			m_dCartonHighWeigh = atof((_bstr_t)var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("ScanPSN");
			m_bCheckScanPSN = atoi((_bstr_t)var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("CheckPSN");
			m_bCheckPSNChk = atoi((_bstr_t)var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("WritePSNToPhone");
			m_bCheckWrite = atoi((_bstr_t)var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("ScanNetCode");
			m_bScanNetCode = atoi((_bstr_t)var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("PSNLength");
			m_iPSNLength = atoi((_bstr_t)var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("NetCodeLength");
			m_iNetLength = atoi((_bstr_t)var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("PSNCheckBit"); 
			m_csPSNChk=VariantToCString(var);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("NetCodeHeader"); 
			m_csNetHeader=VariantToCString(var);

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


void CAlterSetting::OnCloseupComboProduct()
{
	UpdateData();

	int index;

	index=this->m_ctrComboxProduct.GetCurSel();
	if(index==-1)
		return;
	this->m_ctrComboxProduct.GetLBText(index,m_csProduct);

	//获取所选项目对应订单插入到Combox中
	if(!this->GetProductOrderList())
	{
		MessageBox("Get Order List Fail!");
		this->m_ctrComboxOrder.EnableWindow(FALSE);
		return;
	}
	
	UpdateData(FALSE);
	this->m_ctrComboxOrder.EnableWindow(TRUE);
}


void CAlterSetting::OnCloseupComboOrder() 
{
	UpdateData();

	int index;

	index=this->m_ctrComboxOrder.GetCurSel();
	if(index==-1)
		return;	
	this->m_ctrComboxOrder.GetLBText(index,m_csOrder);
	
	
	//获取项目列表
	if(!this->GetProductOrderSetting())
	{
		MessageBox("Get Product Order Setting Fail!");
		return;
	}

	if(this->m_bCheckVersion)
		this->m_ctrVersion.EnableWindow();
	else
		this->m_ctrVersion.EnableWindow(FALSE);

	if(this->m_bCheckBoardVersion)
		this->m_ctrBoardVersion.EnableWindow();
	else
		this->m_ctrBoardVersion.EnableWindow(FALSE);
	
	UpdateData(FALSE);
}

void CAlterSetting::OnCheckVersion() 
{
	UpdateData();
	if(m_bCheckVersion == 1)
		m_ctrVersion.EnableWindow();
	else
		m_ctrVersion.EnableWindow(false);
	UpdateData(false);
}


void CAlterSetting::OnCheckBoardVersion() 
{
	UpdateData();
	if(m_bCheckBoardVersion == 1)
		m_ctrBoardVersion.EnableWindow();
	else
		m_ctrBoardVersion.EnableWindow(false);
	UpdateData(false);
}



void CAlterSetting::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	_variant_t var;
	CString sql;
	int itemp1,itemp2;

	CString DirectoryName;
	DirectoryName=m_csProduct+'_'+m_csOrder;
	
	CString CFGPath;
	CFGPath=((CCreateProductApp *)AfxGetApp())->m_Config.m_csCFGPath;
	CFGPath+=DirectoryName;

	CopyFile(m_pack_resource_path2,CFGPath+"\\config\\CartonResource.txt",FALSE);
	CopyFile(m_pack_resource_path_sub2,CFGPath+"\\config\\CartonResource_Sub.txt",FALSE);
	CopyFile(m_color_resource_path2,CFGPath+"\\config\\ColorResource.txt",FALSE);
	CopyFile(m_color_resource_path_sub2,CFGPath+"\\config\\ColorResource_Sub.txt",FALSE);
	CopyFile(m_pallet_resource_path2,CFGPath+"\\config\\PalletResource.txt",FALSE);
	CopyFile(m_pallet_resource_path_sub2,CFGPath+"\\config\\PalletResource_Sub.txt",FALSE);

	try
	{
		sql.Format("UPDATE ProductList SET CartonNameStatic = '%s', CartonNameSNLength = %d, CartonMaxCount = %d, \
			PalletNameStatic = '%s', PalletNameSNLength = %d, PalletMaxCount = %d where ProductName = '%s' and OrderName = '%s'", \
			m_csCartonNameStatic2,m_iCartonNameLength2,m_iMaxCount2, \
			m_csPalletNameStatic2,m_iPalletNameLength2,m_iPalletMaxCount2,m_csProduct,m_csOrder);

		((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		MessageBox("Change order Setting ProductList Fail","Remind",MB_ICONHAND);   
		return;
	}

	try
	{
		sql.Format("UPDATE SettingList SET Platform = %d,BTFT = %d, ScanPSN= %d, PSNLength = %d,\
			CheckPSN = %d, PSNCheckBit = '%s', WritePSNToPhone=%d, ScanNetCode = %d, NetCodeLength=%d,NetCodeHeader='%s',\
			ResetFactory = %d,CheckVersion = %d,VersionCode = '%s',CheckBoardVersion = %d,BoardVersionCode = '%s',\
			ColorBoxLowWeigh = %f, ColorBoxHighWeigh = %f, CartonBoxLowWeigh = %f, \
			CartonBoxHighWeigh = %f where ProductName = '%s' and OrderName = '%s'", \
			m_iRadioPlat+1,m_bCheckBTFT, m_bCheckScanPSN, m_iPSNLength, m_bCheckPSNChk,m_csPSNChk,\
			m_bCheckWrite,m_bScanNetCode,m_iNetLength,m_csNetHeader,\
			m_bCheckResetFactory,m_bCheckVersion,m_csVersion,m_bCheckBoardVersion,m_csBoardVersion, \
			m_dColorLowWeigh,m_dColorHighWeigh,m_dCartonLowWeigh,m_dCartonHighWeigh, \
			m_csProduct,m_csOrder);

		((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);	
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		MessageBox("Change Order Setting SettingList Fail","Remind",MB_ICONHAND);
		return;
	}

	MessageBox("Change Order Setting Pass!");
	
	CDialog::OnOK();
}

void CAlterSetting::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
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


void CAlterSetting::OnBtnColorOpen2() 
{
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrFilter="Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";
	if(IDOK==fileDlg.DoModal())
	{
		this->m_color_resource_path2=fileDlg.GetPathName();
		UpdateData(FALSE);
	}
}

void CAlterSetting::OnBtnColorOpenSub2()
{
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrFilter="Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";
	if(IDOK==fileDlg.DoModal())
	{
		this->m_color_resource_path_sub2=fileDlg.GetPathName();
		UpdateData(FALSE);
	}
}

void CAlterSetting::OnBtnPackOpen2() 
{
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrFilter="Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";
	if(IDOK==fileDlg.DoModal())
	{
		this->m_pack_resource_path2=fileDlg.GetPathName();
		UpdateData(FALSE);
	}
}

void CAlterSetting::OnBtnPackOpenSub2() 
{
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrFilter="Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";
	if(IDOK==fileDlg.DoModal())
	{
		this->m_pack_resource_path_sub2=fileDlg.GetPathName();
		UpdateData(FALSE);
	}	
}

void CAlterSetting::OnBtnPalletOpen2() 
{
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrFilter="Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";
	if(IDOK==fileDlg.DoModal())
	{
		this->m_pallet_resource_path2=fileDlg.GetPathName();
		UpdateData(FALSE);
	}
}

void CAlterSetting::OnBtnPalletOpenSub2() 
{
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrFilter="Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";
	if(IDOK==fileDlg.DoModal())
	{
		this->m_pallet_resource_path_sub2=fileDlg.GetPathName();
		UpdateData(FALSE);
	}
}



