// CreateProductDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CreateProduct.h"
#include "CreateProductDlg.h"
#include "Splash.h"
#include "Password.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define USB_KEY             0
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCreateProductDlg dialog

CCreateProductDlg::CCreateProductDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCreateProductDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCreateProductDlg)
	m_iIMEIType = 0;
	m_imei1_start = _T("");
	m_imei2_start = _T("");
	m_imei3_start = _T("");
	m_imei4_start = _T("");
	m_imei1_end = _T("");
	m_imei2_end = _T("");
	m_imei3_end = _T("");
	m_imei4_end = _T("");
	m_color_resource_path = _T("");
	m_pack_resource_path = _T("");
	m_iCartonNameLength = 0;
	m_iMaxCount = 0;
	m_csCartonNameStatic = _T("");
	m_csColor = _T("");
	m_pack_resource_path_sub = _T("");
	m_pallet_resource_path = _T("");
	m_iPalletMaxCount = 0;
	m_csPalletNameStatic = _T("");
	m_iPalletNameLength = 0;
	m_iPlannedOutput = 0;
	m_pallet_resource_path_sub = _T("");
	m_csEndCarton = _T("");
	m_csStrCarton = _T("");
	m_bCartonRange = FALSE;
	m_iIMEIRange = -1;
	m_csIMEIPath = _T("");
	m_color_resource_path_sub = _T("");
	m_csCustomer = _T("");
	m_csSNStatic = _T("");
	iRadioPlat = -1;
	m_csDBpath = _T("");
	m_csAPpath = _T("");
	bCheckBoardVersion = FALSE;
	bCheckBTFT = FALSE;
	bCheckResetFactory = FALSE;
	bCheckVersion = FALSE;
	csBoardVersion = _T("");
	csVersion = _T("");
	dCartonHighWeigh = 0.0;
	dCartonLowWeigh = 0.0;
	dColorHighWeigh = 0.0;
	dColorLowWeigh = 0.0;
	bCheckScanPSN = FALSE;
	bCheckWrite = FALSE;
	iPSNLength = 0;
	bCheckPSNChk = FALSE;
	csPSNChk = _T("");
	bScanNetCode = FALSE;
	iNetLength = 0;
	csNetHeader = _T("");
	m_csProductName = _T("");
	m_csOrderName = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCreateProductDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCreateProductDlg)
	DDX_Control(pDX, IDC_COMBO_PRODUCTNAME, m_ctrProductName);
	DDX_Control(pDX, IDC_COMBO_ORDERNAME, m_ctrOrderName);
	DDX_Control(pDX, IDC_BTN_SELECTAP, m_ctrSelectAPDBButton);
	DDX_Control(pDX, IDC_BTN_SELECT, m_ctrSelectDBButton);
	DDX_Control(pDX, IDC_EDIT_DBPATH, m_ctrDBpath);
	DDX_Control(pDX, IDC_EDIT_APDBPATH, m_ctrAPpath);
	DDX_Control(pDX, IDC_EDIT_SNSTATIC, m_ctrSNStatic);
	DDX_Control(pDX, IDC_EDIT_CUSTOMER, m_ctrCustomer);
	DDX_Control(pDX, IDC_EDIT_SRT_IMEI4, m_ctrimei4_start);
	DDX_Control(pDX, IDC_EDIT_SRT_IMEI3, m_ctrimei3_start);
	DDX_Control(pDX, IDC_EDIT_SRT_IMEI2, m_ctrimei2_start);
	DDX_Control(pDX, IDC_EDIT_SRT_IMEI1, m_ctrimei1_start);
	DDX_Control(pDX, IDC_EDIT_END_IMEI4, m_ctrimei4_end);
	DDX_Control(pDX, IDC_EDIT_END_IMEI3, m_ctrimei3_end);
	DDX_Control(pDX, IDC_EDIT_END_IMEI2, m_ctrimei2_end);
	DDX_Control(pDX, IDC_EDIT_END_IMEI1, m_ctrimei1_end);
	DDX_Control(pDX, IDC_COMBO_IMEIRANGE, m_ctrIMEIRange);
	DDX_Control(pDX, IDC_EDIT_STR_CARTON, m_ctrStrCarton);
	DDX_Control(pDX, IDC_EDIT_END_CARTON, m_ctrEndCarton);
	DDX_Control(pDX, IDC_BTN_CREATE, m_ctrCreate);
	DDX_Radio(pDX, IDC_RADIO_IMEITYPE, m_iIMEIType);
	DDX_Text(pDX, IDC_EDIT_SRT_IMEI1, m_imei1_start);
	DDX_Text(pDX, IDC_EDIT_SRT_IMEI2, m_imei2_start);
	DDX_Text(pDX, IDC_EDIT_SRT_IMEI3, m_imei3_start);
	DDX_Text(pDX, IDC_EDIT_SRT_IMEI4, m_imei4_start);
	DDX_Text(pDX, IDC_EDIT_END_IMEI1, m_imei1_end);
	DDX_Text(pDX, IDC_EDIT_END_IMEI2, m_imei2_end);
	DDX_Text(pDX, IDC_EDIT_END_IMEI3, m_imei3_end);
	DDX_Text(pDX, IDC_EDIT_END_IMEI4, m_imei4_end);
	DDX_Text(pDX, IDC_EDIT_COLOR_PATH, m_color_resource_path);
	DDX_Text(pDX, IDC_EDIT_PACK_PATH, m_pack_resource_path);
	DDX_Text(pDX, IDC_EDIT_CARTON_NAME_LENGTH, m_iCartonNameLength);
	DDX_Text(pDX, IDC_EDIT_MAX_COUNT, m_iMaxCount);
	DDX_Text(pDX, IDC_EDIT_CARTON_NAME_STATIC, m_csCartonNameStatic);
	DDX_Text(pDX, IDC_EDIT_COLOR, m_csColor);
	DDX_Text(pDX, IDC_EDIT_PACK_PATH_SUB, m_pack_resource_path_sub);
	DDX_Text(pDX, IDC_EDIT_PALLET_PATH, m_pallet_resource_path);
	DDX_Text(pDX, IDC_EDIT_PALLET_MAX_COUNT, m_iPalletMaxCount);
	DDX_Text(pDX, IDC_EDIT_PALLET_NAME_STATIC, m_csPalletNameStatic);
	DDX_Text(pDX, IDC_EDIT_PALLET_NAME_LENGTH, m_iPalletNameLength);
	DDX_Text(pDX, IDC_EDIT_PLANNEDOUTPUT, m_iPlannedOutput);
	DDX_Text(pDX, IDC_EDIT_PALLET_PATH_SUB, m_pallet_resource_path_sub);
	DDX_Text(pDX, IDC_EDIT_END_CARTON, m_csEndCarton);
	DDX_Text(pDX, IDC_EDIT_STR_CARTON, m_csStrCarton);
	DDX_Check(pDX, IDC_CHECK_CARTONRANGE, m_bCartonRange);
	DDX_CBIndex(pDX, IDC_COMBO_IMEIRANGE, m_iIMEIRange);
	DDX_Text(pDX, IDC_EDIT_IMEI_PATH, m_csIMEIPath);
	DDX_Text(pDX, IDC_EDIT_COLOR_PATH_SUB, m_color_resource_path_sub);
	DDX_Text(pDX, IDC_EDIT_CUSTOMER, m_csCustomer);
	DDX_Text(pDX, IDC_EDIT_SNSTATIC, m_csSNStatic);
	DDX_Radio(pDX, IDC_RADIO_PLAT_SP, iRadioPlat);
	DDX_Text(pDX, IDC_EDIT_DBPATH, m_csDBpath);
	DDX_Text(pDX, IDC_EDIT_APDBPATH, m_csAPpath);
	DDX_Check(pDX, IDC_CHECK_BOARD_VERSION3, bCheckBoardVersion);
	DDX_Check(pDX, IDC_CHECK_BTFT2, bCheckBTFT);
	DDX_Check(pDX, IDC_CHECK_RESET_FACTORY, bCheckResetFactory);
	DDX_Check(pDX, IDC_CHECK_VERSION3, bCheckVersion);
	DDX_Text(pDX, IDC_EDIT_BOARD_VERSION2, csBoardVersion);
	DDX_Text(pDX, IDC_EDIT_VERSION2, csVersion);
	DDX_Text(pDX, IDC_EDIT_CARTON_HIGH_WEIGH, dCartonHighWeigh);
	DDX_Text(pDX, IDC_EDIT_CARTON_LOW_WEIGH, dCartonLowWeigh);
	DDX_Text(pDX, IDC_EDIT_COLOR_HIGH_WEIGH, dColorHighWeigh);
	DDX_Text(pDX, IDC_EDIT_COLOR_LOW_WEIGH, dColorLowWeigh);
	DDX_Check(pDX, IDC_CHECK_SCANPSN, bCheckScanPSN);
	DDX_Check(pDX, IDC_CHECK_WRITETOPHONE, bCheckWrite);
	DDX_Text(pDX, IDC_EDIT_PSN_LENGTH, iPSNLength);
	DDX_Check(pDX, IDC_CHECK_PSNCHK, bCheckPSNChk);
	DDX_Text(pDX, IDC_EDIT_PSN_CHK, csPSNChk);
	DDX_Check(pDX, IDC_CHECK_SCANNETCODE2, bScanNetCode);
	DDX_Text(pDX, IDC_EDIT_NET_LENGTH2, iNetLength);
	DDX_Text(pDX, IDC_EDIT_NET_HEADER2, csNetHeader);
	DDX_CBString(pDX, IDC_COMBO_PRODUCTNAME, m_csProductName);
	DDX_CBString(pDX, IDC_COMBO_ORDERNAME, m_csOrderName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCreateProductDlg, CDialog)
	//{{AFX_MSG_MAP(CCreateProductDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CHECK_PROJECT_NAME, OnBtnCheckProjectName)
	ON_BN_CLICKED(IDC_BTN_COLOR_OPEN, OnBtnColorOpen)
	ON_BN_CLICKED(IDC_BTN_PACK_OPEN, OnBtnPackOpen)
	ON_BN_CLICKED(IDC_BTN_RESOURCE_CHECK, OnBtnResourceCheck)
	ON_BN_CLICKED(IDC_BTN_CARTON_NAME_LENGTH_CHECK, OnBtnCartonNameLengthCheck)
	ON_BN_CLICKED(IDC_BTN_CREATE, OnBtnCreate)
	ON_BN_CLICKED(IDC_BTN_PACK_OPEN_SUB, OnBtnPackOpenSub)
	ON_BN_CLICKED(IDC_BTN_PALLET_OPEN, OnBtnPalletOpen)
	ON_BN_CLICKED(IDC_BTN_PALLET_NAME_LENGTH_CHECK, OnBtnPalletNameLengthCheck)
	ON_BN_CLICKED(IDC_BTN_PALLET_OPEN_SUB, OnBtnPalletOpenSub)
	ON_BN_CLICKED(IDC_BTN_SETTING, OnBtnSetting)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_CHECK_CARTONRANGE, OnCheckCartonrange)
	ON_BN_CLICKED(IDC_BTN_CHECK_IMEI, OnBtnCheckImei)
	ON_BN_CLICKED(IDC_BTN_IMEI_OPEN, OnBtnImeiOpen)
	ON_CBN_CLOSEUP(IDC_COMBO_IMEIRANGE, OnCloseupComboImeirange)
	ON_BN_CLICKED(IDC_BTN_COLOR_OPEN_SUB, OnBtnColorOpenSub)
	ON_BN_CLICKED(IDC_RADIO_PLAT_SP, OnRadioPlatSp)
	ON_BN_CLICKED(IDC_RADIO_PLAT_SPRD, OnRadioPlatSprd)
	ON_BN_CLICKED(IDC_BTN_SELECT, OnBtnSelect)
	ON_BN_CLICKED(IDC_BTN_SELECTAP, OnBtnSelectap)
	ON_CBN_CLOSEUP(IDC_COMBO_PRODUCTNAME, OnCloseupComboProductname)
	ON_CBN_CLOSEUP(IDC_COMBO_ORDERNAME, OnCloseupComboOrdername)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCreateProductDlg message handlers

BOOL CCreateProductDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// TODO: Add extra initialization here

	//设置字体
	this->SetMyFont();

	//设置UI
	this->m_ctrEndCarton.EnableWindow(FALSE);
	this->m_ctrStrCarton.EnableWindow(FALSE);

	m_ctrIMEIRange.InsertString(0, "manual input");
	m_ctrIMEIRange.InsertString(1, "EXCEL Lead");
	m_ctrIMEIRange.SetCurSel(-1);

	//获取项目列表
	if(!this->GetProductList())
	{
		MessageBox("获取项目列表失败!", "Error", MB_OK);
		exit(0);
	}

	step1=FALSE;
	step2=FALSE;
	step3=FALSE;
	step4=FALSE;
	step5=FALSE;
	step6=FALSE;
	
	m_ctrProductName.SetFocus();
	this->m_ctrOrderName.EnableWindow(FALSE);

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	return FALSE;  // return TRUE  unless you set the focus to a control
}


void CCreateProductDlg::SetMyFont()
{
	VERIFY(m_staticfont.CreateFont(
		40,                        // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_BOLD,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		"宋体")); 

		m_ctrCreate.SetFont(&m_staticfont); 
}


void CCreateProductDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCreateProductDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCreateProductDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCreateProductDlg::OnBtnCheckProjectName()
{
	UpdateData();

	if(this->m_csProductName.IsEmpty() || this->m_csOrderName.IsEmpty())
	{
		MessageBox("Production Or Order Can't Be Empty！","Remind",MB_ICONHAND);
		return;
	}

	//检测名称是否为A-Z、a-z、0-9、_
	if(!CheckProductName() || !CheckOrderName())
	{
		MessageBox("Illegal Production Or Order,Only Include\'A-Z\'、 \'a-z\'、\'0-9\' 、\'_\'!","Remind",MB_ICONHAND);
		return;
	}

	if(this->m_csSNStatic.IsEmpty())
	{
		MessageBox("The Module type Can't Be Empty!","Remind",MB_ICONHAND);
		return;
	}

	if(this->m_csCustomer.IsEmpty())
	{
		MessageBox("Customer model cannot be empty！","Remind",MB_ICONHAND);
		return;
	}

	if(this->m_iPlannedOutput<=0)
	{
		MessageBox("Planned production quantity cannot be zero or negative!","Remind",MB_ICONHAND);
		return;
	}

	UpdateData(FALSE);
	
	// 检测CFG文件夹内文件名称是否相同
	if(!CheckCFGFile())
	{
		MessageBox("The project orders CFG file already exists, unable to create the same project orders!","Remind",MB_ICONHAND);
		return;
	}
	
	//检测SQL productList 内是否有重复产品
	if(!CheckSQLRepart())
	{
		MessageBox("The project orders already exists, within the SQL Server name can't create the same order!","Remind",MB_ICONHAND);
		return;
	}
	
	MessageBox("Legal project orders!","Remind",MB_ICONASTERISK );

	step1=TRUE;
}

void CCreateProductDlg::OnBtnCheckImei() 
{
	UpdateData();

	iIMEIRange = this->m_ctrIMEIRange.GetCurSel();

	if(iIMEIRange == -1)
	{
		MessageBox("Please select a IMEI them roughly range set mode!","Remind",MB_ICONHAND);
		return;
	}
	else if (iIMEIRange == 1)
	{
		if (this->m_csIMEIPath=="")
		{
			MessageBox("Please Export The File of The IMEI Range!","Remind",MB_ICONHAND);
			return;
		}
	}
	else
	{
		switch(this->m_iIMEIType)
		{
		case 0:
			if(!CheckIMEI(m_imei1_start))
			{
				return;
			}
			if(!CheckIMEI(m_imei1_end))
			{
				return;
			}
			if(m_imei1_start>m_imei1_end || m_imei1_start==m_imei1_end)
			{
				MessageBox("The IMEI Of Begin Can't Be Bigger Than  The IMEI Of End","Tip",MB_ICONERROR);
				return;
			}
			break;
		case 1:
			if(!CheckIMEI(m_imei1_start))
			{
				return;
			}
			if(!CheckIMEI(m_imei1_end))
			{
				return;
			}
			if(!CheckIMEI(m_imei2_start))
			{
				return;
			}
			if(!CheckIMEI(m_imei2_end))
			{
				return;
			}
			if(m_imei1_start>m_imei1_end || m_imei1_start==m_imei1_end ||m_imei2_start>m_imei2_end || m_imei2_start==m_imei2_end)
			{
				MessageBox("The IMEI Of Begin Can't Be Bigger Than  The IMEI Of End","Tip",MB_ICONERROR);
				return;
			}
			break;
		case 2:
			if(!CheckIMEI(m_imei1_start))
			{
				return;
			}
			if(!CheckIMEI(m_imei1_end))
			{
				return;
			}
			if(!CheckIMEI(m_imei2_start))
			{
				return;
			}
			if(!CheckIMEI(m_imei2_end))
			{
				return;
			}
			if(!CheckIMEI(m_imei3_start))
			{
				return;
			}
			if(!CheckIMEI(m_imei3_end))
			{
				return;
			}
			if(m_imei1_start>m_imei1_end || m_imei1_start==m_imei1_end ||m_imei2_start>m_imei2_end || m_imei2_start==m_imei2_end  ||m_imei3_start>m_imei3_end || m_imei3_start==m_imei3_end)
			{
				MessageBox("The IMEI Of Begin Can't Be Bigger Than  The IMEI Of End","Tip",MB_ICONERROR);
				return;
			}
			break;
		case 3:
			if(!CheckIMEI(m_imei1_start))
			{
				return;
			}
			if(!CheckIMEI(m_imei1_end))
			{
				return;
			}
			if(!CheckIMEI(m_imei2_start))
			{
				return;
			}
			if(!CheckIMEI(m_imei2_end))
			{
				return;
			}
			if(!CheckIMEI(m_imei3_start))
			{
				return;
			}
			if(!CheckIMEI(m_imei3_end))
			{
				return;
			}
			if(!CheckIMEI(m_imei4_start))
			{
				return;
			}
			if(!CheckIMEI(m_imei4_end))
			{
				return;
			}
			if(m_imei1_start>m_imei1_end || m_imei1_start==m_imei1_end ||m_imei2_start>m_imei2_end || m_imei2_start==m_imei2_end  ||m_imei3_start>m_imei3_end || m_imei3_start==m_imei3_end ||m_imei4_start>m_imei4_end || m_imei4_start==m_imei4_end)
			{
				MessageBox("The IMEI Of Begin Can't Be Bigger Than  The IMEI Of End","Tip",MB_ICONERROR);
				return;
			}
			break;
		default:
			break;
		}
		
		if(!CheckIMEIRange())
		{
			return;
		}
	}

	MessageBox("IMEI detection Pass!","Remind",MB_ICONASTERISK );
	step2=TRUE;
}


BOOL CCreateProductDlg::CheckProductName() 
{
	
	char   ch;   
	BOOL   bHz=FALSE;   
	for(int i=0;i<m_csProductName.GetLength();i++)   
	{   
		ch=m_csProductName.GetAt(i);   
		if(ch>=48 && ch<=57)    
		{    
			continue;   
		}
		else
		{
			if(ch>=65 && ch<=90)
			{
				continue;
			}
			else
			{
				if(ch>=97 && ch<=122)
				{
					continue;
				}
				else
				{
					if(ch=='_')
					{
						continue;
					}
					else
					{
						bHz=TRUE;
						break;
					}
				}
			}
		}
	}
	
	if(!bHz)   
		return TRUE;
	else   
		return FALSE;
}


BOOL CCreateProductDlg::CheckOrderName() 
{
	char   ch;   
	BOOL   bHz=FALSE;   
	for(int i=0;i<m_csOrderName.GetLength();i++)   
	{   
		ch=m_csOrderName.GetAt(i);   
		if(ch>=48 && ch<=57)    
		{    
			continue;   
		}
		else
		{
			if(ch>=65 && ch<=90)
			{
				continue;
			}
			else
			{
				if(ch>=97 && ch<=122)
				{
					continue;
				}
				else
				{
					if(ch=='_')
					{
						continue;
					}
					else
					{
						bHz=TRUE;
						break;
					}
				}
			}
		}
	}
	
	if(!bHz)   
		return TRUE;
	else   
		return FALSE;
}


BOOL CCreateProductDlg::CheckCFGFile() 
{
	CString tempPN;
	tempPN=this->m_csProductName+'_'+this->m_csOrderName;
	
	
	CString CFGPath;
	CFGPath=((CCreateProductApp *)AfxGetApp())->m_Config.m_csCFGPath;
	CFGPath+="*.*";
	
	CFileFind   findSub;   
	BOOL bFindSub=findSub.FindFile(CFGPath);   
	while(bFindSub)   
	{   
		bFindSub=findSub.FindNextFile();   
		
		if(findSub.IsDots())
			continue;
		if(findSub.IsDirectory())
		{
			if(findSub.GetFileName()==tempPN)
				return FALSE;
		}
	}
	return TRUE;
}


BOOL CCreateProductDlg::CheckSQLRepart() 
{
	CString temp;
	_variant_t var;
	CString sql;

	//检查产品是否在ProductList内重复
	try
	{
		sql.Format("select * from ProductList where OrderName='%s' and Enable!=2",m_csOrderName);
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
		((CCreateProductApp *)AfxGetApp())->m_pRst=((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CCreateProductApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			return FALSE;
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


BOOL CCreateProductDlg::CheckIMEI(CString imei) 
{
	char ch;

	if(imei.GetLength()!=14)
	{
		MessageBox("IMEI Length Must Be 14！","Remind",MB_ICONHAND);
		return FALSE;
	}

    for(int i=0;i<imei.GetLength();i++)   
	{   
        ch=imei.GetAt(i);   
        if(ch>=48 && ch<=57)
		{    
            continue;
		}
		else
		{
			MessageBox("Illegal IMEI！","Remind",MB_ICONHAND);
			return FALSE;
		}
	}

	return TRUE;
}


BOOL CCreateProductDlg::CheckIMEIRange()
{
	CStringArray m_csaIMEISTR,m_csaIMEIEND;
	_variant_t var;
	CString sql,temp;
	int    j;

	m_csaIMEISTR.RemoveAll();
	m_csaIMEIEND.RemoveAll();

	try
	{
		sql.Format("select *  from ProductList");
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
		((CCreateProductApp *)AfxGetApp())->m_pRst=((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		while(!((CCreateProductApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1_STR");
			temp=VariantToCString(var);
			m_csaIMEISTR.Add(temp);
			
			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1_END");
			temp=VariantToCString(var);
			m_csaIMEIEND.Add(temp);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("IMEI2_STR");
			temp=VariantToCString(var);
			m_csaIMEISTR.Add(temp);
			
			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("IMEI2_END");
			temp=VariantToCString(var);
			m_csaIMEIEND.Add(temp);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("IMEI3_STR");
			temp=VariantToCString(var);
			m_csaIMEISTR.Add(temp);
			
			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("IMEI3_END");
			temp=VariantToCString(var);
			m_csaIMEIEND.Add(temp);

			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("IMEI4_STR");
			temp=VariantToCString(var);
			m_csaIMEISTR.Add(temp);
			
			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("IMEI4_END");
			temp=VariantToCString(var);
			m_csaIMEIEND.Add(temp);
			
			((CCreateProductApp *)AfxGetApp())->m_pRst->MoveNext();
		}
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	
	switch(this->m_iIMEIType)
	{
	case 3:
		for (j=0; j<m_csaIMEISTR.GetSize(); j++)
		{
			if (m_imei4_start>m_csaIMEIEND[j] || m_imei4_end<m_csaIMEISTR[j])
			{
			}
			else
			{
				MessageBox("IMEI4 Has Never Been Used in server","Remind",MB_ICONHAND);
				return FALSE;
			}
		}
	case 2:
		for (j=0; j<m_csaIMEISTR.GetSize(); j++)
		{
			if (m_imei3_start>m_csaIMEIEND[j] || m_imei3_end<m_csaIMEISTR[j])
			{
			}
			else
			{
				MessageBox("IMEI3 Has Never Been Used in server","Remind",MB_ICONHAND);
				return FALSE;
			}
		}
	case 1:
		for (j=0; j<m_csaIMEISTR.GetSize(); j++)
		{
			if (m_imei2_start>m_csaIMEIEND[j] || m_imei2_end<m_csaIMEISTR[j])
			{
			}
			else
			{
				MessageBox("IMEI2 Has Never Been Used in server","Remind",MB_ICONHAND);
				return FALSE;
			}
		}
	case 0:
		for (j=0; j<m_csaIMEISTR.GetSize(); j++)
		{
			if (m_imei1_start>m_csaIMEIEND[j] || m_imei1_end<m_csaIMEISTR[j])
			{
			}
			else
			{
				MessageBox("IMEI1 Has Never Been Used in server","Remind",MB_ICONHAND);
				return FALSE;
			}
		}
	default:
		break;
	}

	return TRUE;
}


void CCreateProductDlg::OnBtnColorOpen() 
{
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrFilter="Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";
	if(IDOK==fileDlg.DoModal())
	{
		this->m_color_resource_path=fileDlg.GetPathName();
		UpdateData(FALSE);
	}
}


void CCreateProductDlg::OnBtnColorOpenSub()
{
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrFilter="Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";
	if(IDOK==fileDlg.DoModal())
	{
		this->m_color_resource_path_sub=fileDlg.GetPathName();
		UpdateData(FALSE);
	}
}

void CCreateProductDlg::OnBtnPackOpen()
{
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrFilter="Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";
	if(IDOK==fileDlg.DoModal())
	{
		this->m_pack_resource_path=fileDlg.GetPathName();
		UpdateData(FALSE);
	}
}

void CCreateProductDlg::OnBtnResourceCheck() 
{
	if(this->m_color_resource_path.Right(4) != ".txt" && this->m_color_resource_path.Right(4) != ".TXT")
	{
		MessageBox("Error resource file type!","Remind",MB_ICONHAND);
		return;
	}

	if(this->m_color_resource_path_sub.Right(4) != ".txt" && this->m_color_resource_path_sub.Right(4) != ".TXT")
	{
		MessageBox("Error resource file type!","Remind",MB_ICONHAND);
		return;
	}

	if(this->m_pallet_resource_path.Right(4) != ".txt" && this->m_pallet_resource_path.Right(4) != ".TXT")
	{
		MessageBox("Error resource file type!","Remind",MB_ICONHAND);
		return;
	}

	if(this->m_pallet_resource_path_sub.Right(4) != ".txt" && this->m_pallet_resource_path_sub.Right(4) != ".TXT")
	{
		MessageBox("Error resource file type!","Remind",MB_ICONHAND);
		return;
	}

	if(this->m_pack_resource_path.Right(4) != ".txt" && this->m_pack_resource_path.Right(4) != ".TXT")
	{
		MessageBox("Error resource file type!","Remind",MB_ICONHAND);
		return;
	}

	if(this->m_pack_resource_path_sub.Right(4) != ".txt" && this->m_pack_resource_path_sub.Right(4) != ".TXT")
	{
		MessageBox("Error resource file type!","Remind",MB_ICONHAND);
		return;
	}

	MessageBox("Resource file type test successfully!","Remind",MB_ICONASTERISK );

	step5=TRUE;

}

void CCreateProductDlg::OnBtnCartonNameLengthCheck()
{
	UpdateData();
	if(this->m_iCartonNameLength<=0)
	{
		MessageBox("Cartoon case number digits cannot be zero or negative!","Remind",MB_ICONHAND);
		return;
	}

	if(this->m_iMaxCount<=0)
	{
		MessageBox("Maximum capacity can not be zero or negative!","Remind",MB_ICONHAND);
		return;
	}

	if(this->m_csCartonNameStatic.IsEmpty())
	{
		MessageBox("Carton box Constanted position can't be empty!","Remind",MB_ICONHAND);
		return;
	}

	if(m_bCartonRange == 1)
	{
		if (m_csStrCarton.IsEmpty() || m_csEndCarton.IsEmpty())
		{
			MessageBox("Carton number serial number range cannot be empty!","Remind",MB_ICONHAND);
			return;
		}

		if (m_csStrCarton.GetLength()!=m_iCartonNameLength || m_csEndCarton.GetLength()!=m_iCartonNameLength) 
		{
			MessageBox("Length must equal to CartonNameLength!","Remind",MB_ICONHAND);
			return;
		}

		if(m_csStrCarton>m_csEndCarton || m_csStrCarton==m_csEndCarton)
		{
			MessageBox("Carton number of serial number starting value must be smaller than the Carton number serial number of the end value","Tip",MB_ICONERROR);
			return;
		}
	}
	else//lucky 如果不设置起始卡通箱号，则清空数据，避免后期判定错误
	{
		m_csStrCarton.Empty();
		m_csEndCarton.Empty();
	}

	MessageBox("Carton number and maximum capacity testing success!","Remind",MB_ICONASTERISK );
	step3=TRUE;
}

void CCreateProductDlg::OnBtnCreate() 
{
	UpdateData();
	iRadioPlat+=1;
	if(!step1)
	{
		MessageBox("Step1 tests Fail!","Remind",MB_ICONHAND);
		return;
	}
	if(!step2)
	{
		MessageBox("Step2 tests Fail!","Remind",MB_ICONHAND);
		return;
	}
	if(!step3)
	{
		MessageBox("Step3 tests Fail!","Remind",MB_ICONHAND);
		return;
	}
	if(!step4)
	{
		MessageBox("Step4 tests Fail!","Remind",MB_ICONHAND); 
		return;
	}
	if(!step5)
	{
		MessageBox("Step5 tests Fail!","Remind",MB_ICONHAND);
		return;
	}

	if(!step6)
	{
		MessageBox("Step6 tests Fail!","Remind",MB_ICONHAND);
		return;
	}

	//新建文件夹
	if(!GreatePDirectory())
	{
		MessageBox("Create Fold Fail","Remind",MB_ICONHAND);
		return;
	}
	
	//文件夹内新建config.ini
	if(!CreateConfigINI())
	{
		MessageBox("Error Code:1037","Remind",MB_ICONHAND);
		return;
	}

	//copy resource到文件夹内
	if(!CopyResource())
	{
		MessageBox("Error Code:1038","Remind",MB_ICONHAND);
		return;
	}

	//ProductList、SettingList、CouplingList 内添加数据
	if(!InsertProductToSQL())
	{
		return;
	}

	MessageBox("Create Production Pass","Remind",MB_ICONASTERISK);

	clear();
}


BOOL CCreateProductDlg::CopyResource()
{
	CString DirectoryName;
	CString temp;

	HINSTANCE hInstance;
	int iRet;
	DirectoryName=m_csProductName+'_'+m_csOrderName;
	
	CString CFGPath;
	CFGPath=((CCreateProductApp *)AfxGetApp())->m_Config.m_csCFGPath;
	CFGPath+=DirectoryName;

	if(!CopyFile(m_pack_resource_path,CFGPath+"\\config\\CartonResource.txt",FALSE))
		return FALSE;
	if(!CopyFile(m_pack_resource_path_sub,CFGPath+"\\config\\CartonResource_Sub.txt",FALSE))
		return FALSE;
	if(!CopyFile(m_color_resource_path,CFGPath+"\\config\\ColorResource.txt",FALSE))
		return FALSE;
	if(!CopyFile(m_color_resource_path_sub,CFGPath+"\\config\\ColorResource_Sub.txt",FALSE))
		return FALSE;
	if(!CopyFile(m_pallet_resource_path,CFGPath+"\\config\\PalletResource.txt",FALSE))
		return FALSE;
	if(!CopyFile(m_pallet_resource_path_sub,CFGPath+"\\config\\PalletResource_Sub.txt",FALSE))
		return FALSE;
/*lucky
	//copy Database文件  原来的
	temp.Format("/c xcopy %s %s /e /i /y", this->m_csDBpath, CFGPath+"\\DataBase");

	hInstance = ShellExecute(AfxGetMainWnd()->GetSafeHwnd(),"open","cmd.exe",temp,NULL,SW_HIDE);
	iRet = int(hInstance);  
	if (iRet < 32)
	{
		MessageBox("Copy DB File Fail!","Error",MB_OK);
		return FALSE;
	}  
	
	temp.Format("/c xcopy %s %s /e /i /y", this->m_csAPpath, CFGPath+"\\DataBase");
	
	hInstance = ShellExecute(AfxGetMainWnd()->GetSafeHwnd(),"open","cmd.exe",temp,NULL,SW_HIDE);
	iRet = int(hInstance);
	if (iRet < 32)
	{
		MessageBox("Copy AP Fail Fail!","Error",MB_OK);
		return FALSE;
	}
	*/
	// lucky 新的拷贝数据库操作
	if(this->iRadioPlat==1)
	{
		int i,j;
		CString DBName,APName;
		char Name[MAX_PATH];
		j=0;
		for(i=this->m_csDBpath.GetLength()-1;i>0;i--)
		{
			if(this->m_csDBpath.GetAt(i) != 92)
			{
				Name[j]=m_csDBpath.GetAt(i);
				j++;
			} 
			else
			{
				break;
			}
		}
		Name[j]='\0';
		DBName = (CString)Name;
		DBName.MakeReverse();

		if(!CopyFile(m_csDBpath,CFGPath+"\\DataBase\\"+DBName,FALSE))
		{
			MessageBox("Copy DB Fail!","Error",MB_OK);
			return FALSE;
		}

		j=0;
		for(i=this->m_csAPpath.GetLength()-1;i>0;i--)
		{
			if(this->m_csAPpath.GetAt(i) != 92)
			{
				Name[j]=m_csAPpath.GetAt(i);
				j++;
			}
			else
			{
				break;
			}
		}
		Name[j]='\0'; 
		APName = (CString)Name;
		APName.MakeReverse();
		if(!CopyFile(m_csAPpath,CFGPath+"\\DataBase\\"+APName,FALSE))
		{
			MessageBox("Copy AP Fail Fail!","Error",MB_OK);
			return FALSE;
		}
	}
	//end
	return TRUE;
}

BOOL CCreateProductDlg::GreatePDirectory()
{
	CString DirectoryName;
	DirectoryName=m_csProductName+'_'+m_csOrderName;
	
	CString CFGPath;
	CFGPath=((CCreateProductApp *)AfxGetApp())->m_Config.m_csCFGPath;
	CFGPath+=DirectoryName;
	
	if(!CreateDirectory(CFGPath,NULL))
	{
		return FALSE;
	}
	if(!CreateDirectory(CFGPath+"\\config",NULL))
	{
		return FALSE;
	}
	if(!CreateDirectory(CFGPath+"\\DataBase",NULL))
	{
		return FALSE;
	}
	return TRUE;
}


BOOL CCreateProductDlg::CreateConfigINI()
{
	CString DirectoryName;
	DirectoryName=m_csProductName+'_'+m_csOrderName;
	
	CString CFGPath;
	CFGPath=((CCreateProductApp *)AfxGetApp())->m_Config.m_csCFGPath;
	CFGPath+=DirectoryName;

	CFile m_file;
	m_file.Open(CFGPath+"\\config"+"\\config.ini",CFile::modeCreate|CFile::modeWrite);
	m_file.Close();

	CFile fp;	
    if (!fp.Open(CFGPath+"\\config"+"\\config.ini",CFile::modeRead))
    {
	    return FALSE;
    }
    fp.Close();
	
	return TRUE;
}


BOOL CCreateProductDlg::InsertProductToSQL()
{
	UpdateData();
	iRadioPlat+=1;
	//获取产品名字
	CString CreateTablePN;

	CreateTablePN = m_csProductName+'_'+m_csOrderName;

	_variant_t var;
	CString sql;
	CString csIMEI1,csIMEI2,csIMEI3,csIMEI4,csSN;
	COleVariant covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	long  irow,icol;
	COleVariant rValue;


	//插入ProductList
	try
	{
		sql.Format("UPDATE ProductList SET SNStatic = '%s', CustomerNo = '%s', \
			IMEIType = %d, IMEIRangeType = %d, IMEI1_STR = '%s', IMEI1_END = '%s', IMEI2_STR = '%s', \
			IMEI2_END = '%s', IMEI3_STR = '%s', IMEI3_END = '%s', IMEI4_STR = '%s', IMEI4_END = '%s', \
			CartonNameStatic = '%s', CartonNameSNLength = %d, CartonNameBegin = '%s', CartonNameEnd = '%s', \
			CartonMaxCount = %d, PalletNameStatic = '%s', PalletNameSNLength = %d, PalletMaxCount = %d, \
			PlannedOutput = %d, Color = '%s', Enable = %d, CreateUser = '%s' where ProductName = '%s' and OrderName = '%s'", \
			this->m_csSNStatic, this->m_csCustomer, \
			this->m_iIMEIType, iIMEIRange, this->m_imei1_start, this->m_imei1_end, this->m_imei2_start, this->m_imei2_end, \
			this->m_imei3_start, this->m_imei3_end, this->m_imei4_start, this->m_imei4_end, \
			this->m_csCartonNameStatic, this->m_iCartonNameLength, this->m_csStrCarton, this->m_csEndCarton, \
			this->m_iMaxCount, this->m_csPalletNameStatic, this->m_iPalletNameLength, \
			this->m_iPalletMaxCount, this->m_iPlannedOutput, this->m_csColor, 3, ((CCreateProductApp *)AfxGetApp())->m_csCreateUser, \
			this->m_csProductName, this->m_csOrderName);

		((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
// 	try
// 	{
// 		sql.Format("INSERT INTO ProductList(ProductName,OrderName,SNStatic,CustomerNo,\
// 			IMEIType,IMEIRangeType,IMEI1_STR,IMEI1_END,IMEI2_STR,IMEI2_END,IMEI3_STR,IMEI3_END,\
// 			IMEI4_STR,IMEI4_END,CartonNameStatic,CartonNameSNLength,CartonNameBegin,CartonNameEnd,\
// 			CartonMaxCount,PalletNameStatic,PalletNameSNLength,PalletMaxCount,PlannedOutput,\
// 			Color,Enable,CreateUser) VALUES ('%s','%s','%s','%s',%d,%d,'%s','%s','%s','%s','%s',\
// 			'%s','%s','%s','%s',%d,'%s','%s',%d,'%s',%d,%d,%d,'%s',%d,'%s')", \
// 			this->m_csProductName, this->m_csOrderName,\
// 			this->m_csSNStatic, this->m_csCustomer, \
// 			this->m_iIMEIType, iIMEIRange, this->m_imei1_start, this->m_imei1_end, this->m_imei2_start, this->m_imei2_end, \
// 			this->m_imei3_start, this->m_imei3_end, this->m_imei4_start, this->m_imei4_end, \
// 			this->m_csCartonNameStatic, this->m_iCartonNameLength, this->m_csStrCarton, this->m_csEndCarton, \
// 			this->m_iMaxCount, this->m_csPalletNameStatic, this->m_iPalletNameLength, \
// 			this->m_iPalletMaxCount, this->m_iPlannedOutput, this->m_csColor, 3, ((CCreateProductApp *)AfxGetApp())->m_csCreateUser);
// 		((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);  
// 	}
	catch(_com_error e)
	{
		MessageBox("Insert Order of Product ProductList Fail","Remind",MB_ICONHAND);
		return FALSE;
	}
   
	//插入SettingList
	try
	{
		sql.Format("INSERT INTO SettingList (ProductName,OrderName,Platform, BTFT,ResetFactory, \
			CheckVersion,CheckBoardVersion,VersionCode,BoardVersionCode, \
			ColorBoxLowWeigh,ColorBoxHighWeigh,CartonBoxLowWeigh,CartonBoxHighWeigh,\
			ScanPSN,WritePSNToPhone,PSNLength,CheckPSN,PSNCheckBit,ScanNetCode,NetCodeLength,NetCodeHeader,\
			Enable \
			) VALUES ('%s','%s',%d,%d,%d,%d,%d,'%s','%s',%f,%f,%f,%f,%d,%d,%d,%d,'%s',%d,%d,'%s',1)", \
			this->m_csProductName,this->m_csOrderName,this->iRadioPlat,this->bCheckBTFT,this->bCheckResetFactory, \
			this->bCheckVersion,this->bCheckBoardVersion,this->csVersion,this->csBoardVersion, \
			this->dColorLowWeigh,this->dColorHighWeigh,this->dCartonLowWeigh,this->dCartonHighWeigh,\
			this->bCheckScanPSN,this->bCheckWrite,this->iPSNLength,this->bCheckPSNChk,this->csPSNChk,\
			this->bScanNetCode,this->iNetLength,this->csNetHeader);

		((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		MessageBox("Insert Product Order into SettingList Fail","Remind",MB_ICONHAND);    
		return FALSE;
	}

	//创建IMEIRange表、ColorBox表、CartonBox表、Pallet表
	try
	{
		sql.Format("exec eM_CreateProduct '%s'",CreateTablePN);
		((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		MessageBox("Create IMEIRange Table、ColorBox Table、CartonBox Table or Pallet Table Fail","Remind",MB_ICONHAND);
		return FALSE;
	}

	//导入EXCEL数据至IMEIRange表 
	if (iIMEIRange==1)
	{
		//创建EXCEL进程
		if(!m_ExlApp.CreateDispatch("Excel.Application",NULL))
		{
			MessageBox("Create EXCEL Server Fail","Remind",MB_ICONHAND);
			return FALSE;
		}
		
		m_ExlBooks.AttachDispatch(m_ExlApp.GetWorkbooks(),TRUE);
		
		//加载EXCEL
		m_ExlBook.AttachDispatch(m_ExlBooks.Add((_variant_t)m_csIMEIPath),TRUE);
		
		//获取Worksheets
		m_ExlSheets.AttachDispatch(m_ExlBook.GetWorksheets(),true);
		
		//获取sheet1
		m_ExlSheet.AttachDispatch(m_ExlSheets.GetItem(_variant_t("sheet1")),true);
		
		//加载所有单元格
		m_ExlRge.AttachDispatch(m_ExlSheet.GetCells(),TRUE);
		
		//获取EXCEL表格已使用行数
		m_ExlRge.AttachDispatch(m_ExlSheet.GetUsedRange());
		ExlRge.AttachDispatch(m_ExlRge.GetRows());
		irow = ExlRge.GetCount();
		ExlRge.AttachDispatch(m_ExlRge.GetColumns());
		icol = ExlRge.GetCount();
		
		for (long i=1; i<=irow; i++)
		{
			//获取EXCEL表格内容
			switch(m_iIMEIType)
			{
			case 0:
				ExlRge=m_ExlSheet.GetRange(COleVariant(IndexToString(i,1)),COleVariant(IndexToString(i,1)));
				rValue=COleVariant(ExlRge.GetValue2());
				rValue.ChangeType(VT_BSTR);
				csIMEI1 = CString(rValue.bstrVal);
				
				ExlRge=m_ExlSheet.GetRange(COleVariant(IndexToString(i,2)),COleVariant(IndexToString(i,2)));
				rValue=COleVariant(ExlRge.GetValue2());
				rValue.ChangeType(VT_BSTR);
				csSN = CString(rValue.bstrVal);
				break;
			case 1:
				ExlRge=m_ExlSheet.GetRange(COleVariant(IndexToString(i,1)),COleVariant(IndexToString(i,1)));
				rValue=COleVariant(ExlRge.GetValue2());
				rValue.ChangeType(VT_BSTR);
				csIMEI1 = CString(rValue.bstrVal);
				
				ExlRge=m_ExlSheet.GetRange(COleVariant(IndexToString(i,2)),COleVariant(IndexToString(i,2)));
				rValue=COleVariant(ExlRge.GetValue2());
				rValue.ChangeType(VT_BSTR);
				csIMEI2 = CString(rValue.bstrVal);
				
				ExlRge=m_ExlSheet.GetRange(COleVariant(IndexToString(i,3)),COleVariant(IndexToString(i,3)));
				rValue=COleVariant(ExlRge.GetValue2());
				rValue.ChangeType(VT_BSTR);
				csSN = CString(rValue.bstrVal);
				break;
			case 2:
				ExlRge=m_ExlSheet.GetRange(COleVariant(IndexToString(i,1)),COleVariant(IndexToString(i,1)));
				rValue=COleVariant(ExlRge.GetValue2());
				rValue.ChangeType(VT_BSTR);
				csIMEI1 = CString(rValue.bstrVal);
				
				ExlRge=m_ExlSheet.GetRange(COleVariant(IndexToString(i,2)),COleVariant(IndexToString(i,2)));
				rValue=COleVariant(ExlRge.GetValue2());
				rValue.ChangeType(VT_BSTR);
				csIMEI2 = CString(rValue.bstrVal);

				ExlRge=m_ExlSheet.GetRange(COleVariant(IndexToString(i,3)),COleVariant(IndexToString(i,3)));
				rValue=COleVariant(ExlRge.GetValue2());
				rValue.ChangeType(VT_BSTR);
				csIMEI3 = CString(rValue.bstrVal);
				
				ExlRge=m_ExlSheet.GetRange(COleVariant(IndexToString(i,4)),COleVariant(IndexToString(i,4)));
				rValue=COleVariant(ExlRge.GetValue2());
				rValue.ChangeType(VT_BSTR);
				csSN = CString(rValue.bstrVal);
				break;
			case 3:
				ExlRge=m_ExlSheet.GetRange(COleVariant(IndexToString(i,1)),COleVariant(IndexToString(i,1)));
				rValue=COleVariant(ExlRge.GetValue2());
				rValue.ChangeType(VT_BSTR);
				csIMEI1 = CString(rValue.bstrVal);
				
				ExlRge=m_ExlSheet.GetRange(COleVariant(IndexToString(i,2)),COleVariant(IndexToString(i,2)));
				rValue=COleVariant(ExlRge.GetValue2());
				rValue.ChangeType(VT_BSTR);
				csIMEI2 = CString(rValue.bstrVal);
				
				ExlRge=m_ExlSheet.GetRange(COleVariant(IndexToString(i,3)),COleVariant(IndexToString(i,3)));
				rValue=COleVariant(ExlRge.GetValue2());
				rValue.ChangeType(VT_BSTR);
				csIMEI3 = CString(rValue.bstrVal);

				ExlRge=m_ExlSheet.GetRange(COleVariant(IndexToString(i,4)),COleVariant(IndexToString(i,4)));
				rValue=COleVariant(ExlRge.GetValue2());
				rValue.ChangeType(VT_BSTR);
				csIMEI4 = CString(rValue.bstrVal);
				
				ExlRge=m_ExlSheet.GetRange(COleVariant(IndexToString(i,5)),COleVariant(IndexToString(i,5)));
				rValue=COleVariant(ExlRge.GetValue2());
				rValue.ChangeType(VT_BSTR);
				csSN = CString(rValue.bstrVal);
				break;
			default:
				break;
			}
			
			sql.Format("INSERT INTO %s_%s_IMEIRange (IMEI1,IMEI2,IMEI3,IMEI4,SN) VALUES ('%s','%s','%s','%s','%s')", \
				this->m_csProductName,this->m_csOrderName,csIMEI1,csIMEI2,csIMEI3,csIMEI4,csSN);
			
			try
			{
				if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
					((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
				((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
				if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
					((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
			}
			catch(_com_error e)
			{
				MessageBox("IMEI Enter IMEIRange Table Fail","Remind",MB_ICONHAND);
				return FALSE;
			}
		}

		//释放对象
		m_ExlRge.ReleaseDispatch();
		m_ExlSheet.ReleaseDispatch();
		m_ExlSheets.ReleaseDispatch();
		m_ExlBook.ReleaseDispatch();
		m_ExlBooks.ReleaseDispatch();
		m_ExlApp.ReleaseDispatch();
		//退出
		m_ExlApp.Quit();
	}

	return TRUE;
}

void CCreateProductDlg::OnBtnPackOpenSub()
{
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrFilter="Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";
	if(IDOK==fileDlg.DoModal())
	{
		this->m_pack_resource_path_sub=fileDlg.GetPathName();
		UpdateData(FALSE);
	}
}

void CCreateProductDlg::OnBtnPalletOpen() 
{
	// TODO: Add your control notification handler code here
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrFilter="Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";
	if(IDOK==fileDlg.DoModal())
	{
		this->m_pallet_resource_path=fileDlg.GetPathName();
		UpdateData(FALSE);
	}
}

void CCreateProductDlg::OnBtnPalletNameLengthCheck() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(this->m_iPalletNameLength<=0)
	{
		MessageBox("Pallet Name length cannot be zero or negative!","Remind",MB_ICONHAND);
		return;
	}

	if(this->m_iPalletMaxCount<=0)
	{
		MessageBox("PalletMaxCount Can't be zero or negative!","Remind",MB_ICONHAND);
		return;
	}

	if(this->m_csPalletNameStatic.IsEmpty())
	{
		MessageBox("Pallet constant can't be empty!","Remind",MB_ICONHAND);
		return;
	}

	MessageBox("Pallet Length And Max Number Per Pallet Set Pass!","Remind",MB_ICONASTERISK );
	step6=TRUE;
}


void CCreateProductDlg::OnBtnPalletOpenSub()
{
	// TODO: Add your control notification handler code here
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrFilter="Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";
	if(IDOK==fileDlg.DoModal())
	{
		this->m_pallet_resource_path_sub=fileDlg.GetPathName();
		UpdateData(FALSE);
	}
}


void CCreateProductDlg::OnBtnSetting() 
{
	UpdateData();

//	iRadioPlat           = iRadioPlat+1;//MTK:1 SPRD:2 
//CString temp;
//temp.Format("平台：%d",iRadioPlat);
//MessageBox(temp,"Remind",MB_ICONASTERISK );

	bCheckGSM1800        = 0;
	bCheckGSM900         = 0;
	bCheckGSM1900        = 0;
	bCheckGSM850         = 0;
	bCheckLTE            = 0;
	bCheckG1800Fber      = 0;
	bCheckG900Fber       = 0;
	bCheckG1900Fber      = 0;
	bCheckG850Fber       = 0;
	bCheckWCDMA850       = 0;
	bCheckWCDMA900       = 0;
	bCheckWCDMA1900      = 0;
	bCheckWCDMA2100      = 0;

	fGSM850BCHPower1     = 0.0;
	fGSM850BCHPower2     = 0.0;
	iGSM850TCHChannel    = 0;
	iGSM850TCHTxL        = 0;
	fGSM850PowerSTR      = 0.0;
	fGSM850PowerEND      = 0.0;
	fGSM850FBEREND       = 0.0;
	fGSM850FBERSTR       = 0.0;

	fGSM900BCHPower1     = 0.0;
	fGSM900BCHPower2     = 0.0;
	iGSM900TCHChannel    = 0;
	iGSM900TCHTxL        = 0;
	fGSM900PowerSTR      = 0.0;
	fGSM900PowerEND      = 0.0;
	fGSM900FBEREND       = 0.0;
	fGSM900FBERSTR       = 0.0;
	fGSM1800BCHPower1    = 0.0;
	fGSM1800BCHPower2    = 0.0;
	iGSM1800TCHChannel   = 0.0;
	iGSM1800TCHTxL       = 0;
	fGSM1800FBERSTR      = 0.0;
	fGSM1800FBEREND      = 0.0;
	fGSM1800PowerEND     = 0.0;
	fGSM1800PowerSTR     = 0.0;

	fGSM1900BCHPower1    = 0.0;
	fGSM1900BCHPower2    = 0.0;
	iGSM1900TCHChannel   = 0; 
	iGSM1900TCHTxL       = 0;
	fGSM1900FBERSTR      = 0.0;
	fGSM1900FBEREND      = 0.0;
	fGSM1900PowerEND     = 0.0;
	fGSM1900PowerSTR     = 0.0;

	fW850CellPow         = 0.0;
	iW850DLChannel       = 0;
	iW850MsPow           = 0;
	fW850PowStr          = 0.0;
	fW850PowEnd          = 0.0;
	fW900CellPow         = 0.0;
	iW900DLChannel       = 0;
	iW900MsPow           = 0;
	fW900PowStr          = 0.0;
	fW900PowEnd          = 0.0;
	fW1900CellPow        = 0.0;
	iW1900DLChannel      = 0;
	iW1900MsPow          = 0;
	fW1900PowStr         = 0.0;
	fW1900PowEnd         = 0.0;
	fW2100CellPow        = 0.0;
	iW2100DLChannel      = 0.0;
	iW2100MsPow          = 0;
	fW2100PowStr         = 0.0;
	fW2100PowEnd         = 0.0;

	MessageBox("Production tools feature set success!","Remind",MB_ICONASTERISK );
	step4=TRUE;
}


CString CCreateProductDlg::VariantToCString(VARIANT   var)   
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


int CCreateProductDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	CSplashWnd::ShowSplashScreen(this);
	
	return 0;
}

void CCreateProductDlg::OnCheckCartonrange() 
{
	UpdateData(); 
	if(m_bCartonRange == 1)
	{
		m_ctrStrCarton.EnableWindow();
		m_ctrEndCarton.EnableWindow();
	}
	else
	{
		m_ctrStrCarton.EnableWindow(false);
		m_ctrEndCarton.EnableWindow(false);
	}
	UpdateData(false);
}

void CCreateProductDlg::OnBtnImeiOpen() 
{
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrFilter="Files(*.xls)\0*.xls\0All Files(*.*)\0*.*\0\0";
	if(IDOK==fileDlg.DoModal())
	{
		this->m_csIMEIPath=fileDlg.GetPathName();
		UpdateData(FALSE);
	}
}

void CCreateProductDlg::OnCloseupComboImeirange() 
{
	UpdateData();

	int index;

	index = this->m_ctrIMEIRange.GetCurSel();
	if(index == -1)
		return;
}

CString CCreateProductDlg::IndexToString(int row, int col)  
{  
	CString strResult;
	if( col > 26 )
	{    
		strResult.Format(_T("%c%c%d"),'A' + (col-1)/26-1,'A' + (col-1)%26,row);
	}   
	else   
	{    
		strResult.Format(_T("%c%d"), 'A' + (col-1)%26,row);  
	}  
	return strResult; 
}  


void CCreateProductDlg::clear()
{
	step1=FALSE;
	step2=FALSE;
	step3=FALSE;
	step4=FALSE;
	step5=FALSE;
	step6=FALSE;

	m_csCustomer="";
	m_csSNStatic="";
	m_csEndCarton="";
	m_csStrCarton="";
	m_bCartonRange=0;
	this->m_ctrEndCarton.EnableWindow(FALSE);
	this->m_ctrStrCarton.EnableWindow(FALSE);

	this->m_ctrProductName.EnableWindow();
	this->m_ctrOrderName.EnableWindow();
	this->m_ctrProductName.SetCurSel(-1);
	this->m_ctrOrderName.SetCurSel(-1);
	this->m_csProductName.Empty();
	this->m_csOrderName.Empty();

	m_ctrIMEIRange.InsertString(0, "manual input");
	m_ctrIMEIRange.InsertString(1, "EXCEL Lead");
	m_ctrIMEIRange.SetCurSel(-1);

	m_iIMEIType=0;
	m_iPlannedOutput=0;

	m_imei1_start="";
	m_imei2_start="";	
	m_imei3_start="";	
	m_imei4_start="";
	m_imei1_end="";
	m_imei2_end="";
	m_imei3_end="";
	m_imei4_end="";

	
	m_color_resource_path="";
	m_color_resource_path_sub="";
	m_pack_resource_path="";
	m_pack_resource_path_sub="";
	m_pallet_resource_path="";
	m_pallet_resource_path_sub="";
	m_csIMEIPath="";

	m_iCartonNameLength=0;
	m_iMaxCount=0;
	m_csCartonNameStatic="";

	m_iPalletMaxCount=0;
	m_iPalletNameLength=0;
	m_csPalletNameStatic="";

	m_csColor="";
    //20151230
	iRadioPlat = -1;
	m_csDBpath = _T("");
	m_csAPpath = _T("");
	bCheckBoardVersion = FALSE;
	bCheckBTFT = FALSE;
	bCheckResetFactory = FALSE;
	bCheckVersion = FALSE;
	csBoardVersion = _T("");
	csVersion = _T("");
	dCartonHighWeigh = 0.0;
	dCartonLowWeigh = 0.0;
	dColorHighWeigh = 0.0;
	dColorLowWeigh = 0.0;
	bCheckScanPSN = FALSE;
	bCheckWrite = FALSE;
	iPSNLength = 0;
	bCheckPSNChk = FALSE;
	csPSNChk = _T("");
	bScanNetCode = FALSE;
	iNetLength = 0;
	csNetHeader = _T("");
	//end
	UpdateData(FALSE);
}



void CCreateProductDlg::OnRadioPlatSp() 
{
	this->iRadioPlat = 0;  
	m_ctrSelectDBButton.EnableWindow(TRUE);
	m_ctrSelectAPDBButton.EnableWindow(TRUE);
	UpdateData(FALSE);	
}

void CCreateProductDlg::OnRadioPlatSprd() 
{
	this->iRadioPlat = 1;
	m_ctrSelectDBButton.EnableWindow(FALSE);
	m_ctrSelectAPDBButton.EnableWindow(FALSE);
	UpdateData(FALSE);
}

void CCreateProductDlg::OnBtnSelect() 
{
	CFileDialog filedlg(TRUE);
	filedlg.m_ofn.lpstrTitle="Select Modem DBFile";
	if(filedlg.DoModal()==IDOK)
	{
		this->m_csDBpath = filedlg.GetPathName();

		if(this->m_csDBpath.IsEmpty())
		{
			
		}
		UpdateData(FALSE);
	}
	else
	{
		return;
	}	
}

void CCreateProductDlg::OnBtnSelectap() 
{
	CFileDialog filedlg(TRUE);
	filedlg.m_ofn.lpstrTitle="Select AP DBFile";
	if(filedlg.DoModal()==IDOK)
	{
		this->m_csAPpath = filedlg.GetPathName();

		if(this->m_csAPpath.IsEmpty())
		{
			
		}
		UpdateData(FALSE);
	}
	else
	{
		return;
	}	
}

void CCreateProductDlg::OnCloseupComboProductname() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData();
	
	CString     temp;
	CString     sql;
	_variant_t  var;
	int         index;
	
	index = this->m_ctrProductName.GetCurSel();
	if(index == -1)
		return;
	this->m_ctrProductName.GetLBText(index,m_csProductName);
	
	//获取所选项目对应订单插入到Combox中
	if(!this->GetOrderList())
	{
		MessageBox("获取订单列表失败!","Error",MB_ICONERROR);
		this->m_ctrOrderName.EnableWindow(FALSE);
		return;
	}
	
	this->m_ctrOrderName.EnableWindow();
	UpdateData(FALSE);
	this->m_ctrProductName.EnableWindow(FALSE);
}

void CCreateProductDlg::OnCloseupComboOrdername() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData();
	
	int index;
	
	index = this->m_ctrOrderName.GetCurSel();
	if(index == -1)
		return;	
	this->m_ctrOrderName.GetLBText(index,m_csOrderName);
	
	UpdateData(FALSE);
	this->m_ctrOrderName.EnableWindow(FALSE);
}

BOOL CCreateProductDlg::GetOrderList()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	try
	{
		sql.Format("select *  from ProductList where ProductName='%s' and Enable = 2",this->m_csProductName);
		if(((CCreateProductApp *)AfxGetApp())->m_pRst->State)
			((CCreateProductApp *)AfxGetApp())->m_pRst->Close();
		((CCreateProductApp *)AfxGetApp())->m_pRst=((CCreateProductApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);		
		while(!((CCreateProductApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			var = ((CCreateProductApp *)AfxGetApp())->m_pRst->GetCollect("OrderName");
			temp=VariantToCString(var);
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

BOOL CCreateProductDlg::GetProductList()
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
			temp=VariantToCString(var);
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
