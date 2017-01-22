// WeighToolView.cpp : implementation of the CWeighToolView class
//

#include "stdafx.h"
#include "WeighTool.h"
#include "Splash.h"
#include "WeighToolDoc.h"
#include "WeighToolView.h"
#include "Password.h"
#include <math.h>
#include "setting.h"

#include "mmsystem.h"//导入声音头文件
#pragma comment(lib,"winmm.lib")//导入声音头文件库

#define FAIL                102
#define PASS                103

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CWeighToolView

IMPLEMENT_DYNCREATE(CWeighToolView, CFormView)

BEGIN_MESSAGE_MAP(CWeighToolView, CFormView)
	//{{AFX_MSG_MAP(CWeighToolView)
	ON_CBN_SELCHANGE(IDC_COMBO_COMPORT, OnSelchangeComboComport)
	ON_BN_CLICKED(IDC_BTN_START, OnBtnStart)
	ON_WM_TIMER()
	ON_EN_CHANGE(IDC_EDIT_IMEI1, OnChangeEditImei1)
	ON_EN_CHANGE(IDC_EDIT_IMEI2, OnChangeEditImei2)
	ON_EN_CHANGE(IDC_EDIT_IMEI3, OnChangeEditImei3)
	ON_EN_CHANGE(IDC_EDIT_IMEI4, OnChangeEditImei4)
	ON_WM_CREATE()
	ON_COMMAND(IDM_SCAN_MODE_1, OnScanMode1)
	ON_COMMAND(IDM_SCAN_MODE_2, OnScanMode2)
	ON_BN_CLICKED(IDC_BTN_SETTING, OnBtnSetting)
	ON_BN_CLICKED(IDC_BTN_REFRESH, OnBtnRefresh)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWeighToolView construction/destruction
CWeighToolView::CWeighToolView()
	: CFormView(CWeighToolView::IDD)
{
	//{{AFX_DATA_INIT(CWeighToolView)
	m_iComport = -1;
	m_dHighWeigh = 0.0;
	m_dLowWeigh = 0.0;
	m_csIMEI1 = _T("");
	m_csIMEI2 = _T("");
	m_csIMEI3 = _T("");
	m_csIMEI4 = _T("");
	m_csCurrentColor = _T("");
	m_csCurrentOrder = _T("");
	m_csCurrentProduct = _T("");
	m_csCurrentLine = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CWeighToolView::~CWeighToolView()
{
}

void CWeighToolView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWeighToolView)
	DDX_Control(pDX, IDC_STATIC_CURRENT_LINE, m_ctrCurrentLine);
	DDX_Control(pDX, IDC_STATIC_CURRENT_COUNT, m_cCurrentCount);
	DDX_Control(pDX, IDC_STATIC_CURRENT_PRODUCT, m_ctrCurrentProduct);
	DDX_Control(pDX, IDC_STATIC_CURRENT_ORDER, m_ctrCurrentOrder);
	DDX_Control(pDX, IDC_STATIC_CURRENT_COLOR, m_ctrCurrentColor);
	DDX_Control(pDX, IDC_STATIC_RESULT, m_cResult);
	DDX_Control(pDX, IDC_EDIT_IMEI4, m_ctrIMEI4);
	DDX_Control(pDX, IDC_EDIT_IMEI3, m_ctrIMEI3);
	DDX_Control(pDX, IDC_EDIT_IMEI2, m_ctrIMEI2);
	DDX_Control(pDX, IDC_EDIT_IMEI1, m_ctrIMEI1);
	DDX_Control(pDX, IDC_EDIT_LOW_WEGIH, m_ctrLowWeigh);
	DDX_Control(pDX, IDC_EDIT_HIGH_WEGIH, m_ctrHighWeigh);
	DDX_Control(pDX, IDC_LIST_STATE, m_state_list);
	DDX_Control(pDX, IDC_STATIC_CURR, m_ctrWeigh);
	DDX_Control(pDX, IDC_STATIC_UNIT, m_ctrUnit);
	DDX_Control(pDX, IDC_COMBO_COMPORT, m_ctrComport);
	DDX_CBIndex(pDX, IDC_COMBO_COMPORT, m_iComport);
	DDX_Text(pDX, IDC_EDIT_HIGH_WEGIH, m_dHighWeigh);
	DDX_Text(pDX, IDC_EDIT_LOW_WEGIH, m_dLowWeigh);
	DDX_Text(pDX, IDC_EDIT_IMEI1, m_csIMEI1);
	DDX_Text(pDX, IDC_EDIT_IMEI2, m_csIMEI2);
	DDX_Text(pDX, IDC_EDIT_IMEI3, m_csIMEI3);
	DDX_Text(pDX, IDC_EDIT_IMEI4, m_csIMEI4);
	DDX_Text(pDX, IDC_STATIC_CURRENT_COLOR, m_csCurrentColor);
	DDX_Text(pDX, IDC_STATIC_CURRENT_ORDER, m_csCurrentOrder);
	DDX_Text(pDX, IDC_STATIC_CURRENT_PRODUCT, m_csCurrentProduct);
	DDX_Text(pDX, IDC_STATIC_CURRENT_LINE, m_csCurrentLine);
	//}}AFX_DATA_MAP
}

BOOL CWeighToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CWeighToolView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	CString path;
	GetModuleFileName(NULL,path.GetBufferSetLength(MAX_PATH+1),MAX_PATH);
	path.ReleaseBuffer();
	int pos = path.ReverseFind('\\');
	path = path.Left(pos);
	m_csErrorSndPath = path + _T("\\MES_ERROR.wav");
	m_csOkSndPath = path + _T("\\MES_OK.wav");

	//装载端口
	this->LoadComPort();

	//设置字体
	this->SetMyFont();

	//初始化ini文件
	this->m_Config.InitConfigPath();

	//读取配置文件
	this->m_Config.ReadConfig();

	m_csCurrentOrder = ((CWeighToolApp *)AfxGetApp())->InputOrder;
	m_csCurrentLine  = ((CWeighToolApp *)AfxGetApp())->InputProductionLine;

	//设置菜单勾选
	switch (this->m_Config.m_iScanMode)
	{
	case 1:
		AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_MODE_1, MF_BYCOMMAND | MF_CHECKED );
		break;
	case 2:
		AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_MODE_2, MF_BYCOMMAND | MF_CHECKED );
		break;
	default:
		this->m_Config.m_iScanMode=1;
		this->m_Config.SaveConfig();
		AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_MODE_1, MF_BYCOMMAND | MF_CHECKED );
		break;
	}

	//灰掉控件
	this->SetUIDisableAll();

	//获取项目列表
	if(!this->GetProductOrderInfo())
	{
		//警告提示音
		PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);
		InsertListInfo("Get project orders information fail...",2);
		return;
	}
	else
	{
		UpdateData(FALSE);
		InsertListInfo("Get project orders information success...",0);
	}

	//获取重量范围
	if(!this->GetSetting())
	{
		//警告提示音
		PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);
		InsertListInfo("Get weight range fail...",2);
		return;
	}
	else
	{
		UpdateData(FALSE);
		InsertListInfo("Get weight range success...",0);
	}

	//初始化前两次的称重数据
	dWeigh[0] = 0.0;
	dWeigh[1] = 0.0;

	if(!this->Load_Current_Product_Count())
	{
		//警告提示音
		PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);
		InsertListInfo("Get the current produced number of orders fail",2);
		return;
	}
	InsertListInfo("Get the current produced number of orders success",0);
	this->UpdateCount(this->m_csCurrentCount);
}

/////////////////////////////////////////////////////////////////////////////
// CWeighToolView diagnostics

#ifdef _DEBUG
void CWeighToolView::AssertValid() const
{
	CFormView::AssertValid();
}

void CWeighToolView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CWeighToolDoc* CWeighToolView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeighToolDoc)));
	return (CWeighToolDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWeighToolView message handlers

void CWeighToolView::LoadComPort()
{
	CString str;
	this->m_ctrComport.ResetContent();
	int portnum = 0;   
	CHAR port[MAX_PATH];   
	COMMCONFIG comcfg;   
	ULONG BuffSize = sizeof(port);
	for(int i = 0; i< 255 ; i++) 
	{
		m_comnum[i] = 0;
	}
	for( i = 1; i< 255 ; i++)   
	{   		
		_stprintf(port,_T("COM%d"),i);   
		BuffSize = sizeof(port);   
		if(GetDefaultCommConfig(port,&comcfg,&BuffSize))   
		{
			this->m_ctrComport.AddString(port); 
			m_comnum[portnum++] = i;
		}			
		memset(port,0,sizeof(port));   
	}
	m_ctrComport.SetCurSel(-1);	
}


void CWeighToolView::OnSelchangeComboComport() 
{
	m_iComport= m_ctrComport.GetCurSel();	
	m_comport = m_iComport;
	m_comport = m_comnum[m_comport];

	if(InitComPort())
	{
		InsertListInfo("Init port success!",0);
		this->SetTimer(1,500,0);

		switch(this->m_iIMEIType) 
		{
		case 0:
			this->m_ctrIMEI1.EnableWindow(TRUE);
			break;
		case 1:
			this->m_ctrIMEI1.EnableWindow(TRUE);
			this->m_ctrIMEI2.EnableWindow(TRUE);
			break;
		case 2:
			this->m_ctrIMEI1.EnableWindow(TRUE);
			this->m_ctrIMEI2.EnableWindow(TRUE);
			this->m_ctrIMEI3.EnableWindow(TRUE);
			break;
		case 3:
			this->m_ctrIMEI1.EnableWindow(TRUE);
			this->m_ctrIMEI2.EnableWindow(TRUE);
			this->m_ctrIMEI3.EnableWindow(TRUE);
			this->m_ctrIMEI4.EnableWindow(TRUE);
			break;
		default:
			break;
		}
		
		if(this->m_Config.m_iScanMode==1)//只扫描主IMEI号
		{
			this->m_ctrIMEI1.EnableWindow(TRUE);
			this->m_ctrIMEI2.EnableWindow(FALSE);
			this->m_ctrIMEI3.EnableWindow(FALSE);
			this->m_ctrIMEI4.EnableWindow(FALSE);
		}

		this->m_ctrIMEI1.SetFocus();
	}
	else
	{
		this->m_ctrIMEI1.EnableWindow(FALSE);
		this->m_ctrIMEI2.EnableWindow(FALSE);
		this->m_ctrIMEI3.EnableWindow(FALSE);
		this->m_ctrIMEI4.EnableWindow(FALSE);
		InsertListInfo("Init port fail!",2);
		//警告提示音
		PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);
	}
}


BOOL CWeighToolView::InitComPort()
{
	try
	{
		//初始化串口
		this->m_Serial.m_nBaudRate = 9600;
		this->m_Serial.m_nPort=this->m_comport;
		
		if(this->m_Serial.Port_Init())
		{	
			this->m_RSData.m_hPort = this->m_Serial.CommHandle;  //将之前初始化好的CMySerial Port 句柄传递给CRSData句柄以便读写数据
		}
		else
		{
			return false;
		}
	}
	catch (int k)
	{
		return false;
	}
	
	return true;
}


void StartDoWight(LPVOID x)
{
	CWeighToolView *Sv = (CWeighToolView *)x;
	Sv->DoWeigh();
}


void CWeighToolView::DoWeigh() 
{
	int RS232Error,SN_Long;
	char  read_buffer[200];
	DWORD dwdTotalBytesSent=0;
	DWORD dwdBytesReceived=0;
	char *PointorSN,*PointorEnd;
	char csWeigh[10];
	memset(read_buffer, 0, sizeof(read_buffer));
	
	strcpy (read_buffer,"" );
	RS232Error =ReadFile (this->m_RSData.m_hPort,read_buffer, 50, &dwdBytesReceived, NULL);
	PurgeComm (this->m_RSData.m_hPort, PURGE_TXCLEAR | PURGE_RXCLEAR);//FlushInQ (comport);    
	
 	PointorSN=strstr(read_buffer,",NT,"); //,NT,+    0.0g
	if(PointorSN!=0)
	{
		PointorSN=PointorSN+4;
		PointorEnd=PointorSN+8;
		SN_Long=PointorEnd-PointorSN;
		for(int b=0;b<SN_Long;b++)
		{
			csWeigh[b]=*(PointorSN+b);
			if(b+1==SN_Long)
				csWeigh[b+1]='\0';
		}

		CString temp;
		temp.Format("%s",csWeigh);
		temp.Replace(" ","");

		double tempdWeigh;
		sscanf(temp, "%lf", &tempdWeigh);
		temp.Format("%.1f",tempdWeigh);

		this->m_dWeigh=tempdWeigh;
		if(m_dWeigh>this->m_dHighWeigh || m_dWeigh<this->m_dLowWeigh)
		{
			this->m_ctrWeigh.SetTextColor(RGB(255,0,0));
		}
		else
		{
			this->m_ctrWeigh.SetTextColor(RGB(0,255,0));
		}

		this->m_ctrWeigh.SetWindowText(temp);
	}
	else
	{
		this->m_ctrWeigh.SetWindowText("");
		InsertListInfo("Electronic scales and PC communication was not successful!",2);
	}
}


void CWeighToolView::OnBtnStart() 
{
	m_hThread =
		CreateThread (NULL,  
		0,     
		(LPTHREAD_START_ROUTINE)StartDoWight,
		(void *)this,  
		0,     
		&m_dThreadId);
}


void CWeighToolView::OnTimer(UINT nIDEvent) 
{
	if(nIDEvent == 1)
	{
		OnBtnStart();
	}
}


void CWeighToolView::SetMyFont()
{
	//===============set imagelist=====================================
	HICON hIcon[3];
	hIcon[0]=AfxGetApp()->LoadIcon(IDI_PASS);
	hIcon[1]=AfxGetApp()->LoadIcon(IDI_ERRORS);
	hIcon[2]=AfxGetApp()->LoadIcon(IDI_STOP);
	if(m_imageList.m_hImageList!=NULL)
		m_imageList.DeleteImageList();
	m_imageList.Create(16,16,ILC_COLOR32,3,3);
	m_imageList.SetBkColor(RGB(255,255,255));
	m_imageList.Add(hIcon[0]);
	m_imageList.Add(hIcon[1]);
	m_imageList.Add(hIcon[2]);	
	
	//==========init state list=====================================
    DWORD dwStyle;
	LVCOLUMN   Column;	
	
	m_state_list.SetImageList(&m_imageList,LVSIL_SMALL);
	dwStyle = m_state_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl）
	//dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl）
	//dwStyle |= LVS_EX_CHECKBOXES;//item前生成checkbox控件
	m_state_list.SetExtendedStyle(dwStyle); //设置扩展风格

	//((CWnd*)GetDlgItem(IDC_LIST_STATE))->SetFont(&m_sysfont);
	Column.mask =   LVCF_TEXT|LVCF_FMT|LVCF_WIDTH;
	Column.cchTextMax =   30;   
	Column.cx =   170;     //column宽度，不工作！   
	Column.fmt =   LVCFMT_LEFT;     //不工作   
	Column.iImage =   0;     
	Column.iOrder =   0;     //不明白干什么用   
	Column.iSubItem =   8;        
	Column.pszText =   "TIME";   
	m_state_list.InsertColumn(0,&Column);
	Column.pszText =   "Status"; 
	Column.cx =   400;
	m_state_list.InsertColumn(1,&Column);
	
	this->m_ctrWeigh.SetFontSize(90);
	this->m_ctrWeigh.SetFontName("Arial");
	this->m_ctrUnit.SetFontSize(90);
	this->m_ctrUnit.SetFontName("Arial");

	this->m_cResult.SetFontSize(90);
	this->m_cResult.SetFontName("Arial");

	this->m_cCurrentCount.SetFontSize(30);
	this->m_cCurrentCount.SetFontName("Arial");
	this->m_cCurrentCount.SetTextColor(RGB(0,0,255));

	this->m_ctrCurrentProduct.SetFontSize(18);
	this->m_ctrCurrentProduct.SetFontName("Arial");
	this->m_ctrCurrentProduct.SetTextColor(RGB(0,0,255));
	
	this->m_ctrCurrentOrder.SetFontSize(18);
	this->m_ctrCurrentOrder.SetFontName("Bold");
	this->m_ctrCurrentOrder.SetTextColor(RGB(0,0,255));

	this->m_ctrCurrentLine.SetFontSize(18);
	this->m_ctrCurrentLine.SetFontName("Bold");
	this->m_ctrCurrentLine.SetTextColor(RGB(0,0,255));
	
	this->m_ctrCurrentColor.SetFontSize(18);
	this->m_ctrCurrentColor.SetFontName("Bold");
	this->m_ctrCurrentColor.SetTextColor(RGB(0,0,255));

	VERIFY(m_staticfont.CreateFont(
		18,                        // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_NORMAL,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		"Arial"));                 // lpszFacename

	VERIFY(m_staticfont1.CreateFont(
		32,                        // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_NORMAL,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		"Arial"));                 // lpszFacename
	
	((CWnd*)GetDlgItem(IDC_STATIC_IMEI1))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_STATIC_IMEI2))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_STATIC_IMEI3))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_STATIC_IMEI4))->SetFont(&m_staticfont);

	((CWnd*)GetDlgItem(IDC_EDIT_IMEI1))->SetFont(&m_staticfont1);
	((CWnd*)GetDlgItem(IDC_EDIT_IMEI2))->SetFont(&m_staticfont1);
	((CWnd*)GetDlgItem(IDC_EDIT_IMEI3))->SetFont(&m_staticfont1);
	((CWnd*)GetDlgItem(IDC_EDIT_IMEI4))->SetFont(&m_staticfont1);
	
	((CWnd*)GetDlgItem(IDC_EDIT_HIGH_WEGIH))->SetFont(&m_staticfont);
	((CWnd*)GetDlgItem(IDC_EDIT_LOW_WEGIH))->SetFont(&m_staticfont);
}


void CWeighToolView::InsertListInfo(CString state,int imageIndex)
{
	CString date;
	date=GetCurTimes();
	m_state_list.InsertItem(m_state_list.GetItemCount(),date,imageIndex);
	m_state_list.SetItemText(m_state_list.GetItemCount()-1,1,state);
	m_state_list.EnsureVisible(m_state_list.GetItemCount()-1,TRUE);
}


CString CWeighToolView::GetCurTimes()
{
	CTime t=CTime::GetCurrentTime();
	CString str=t.Format( "%Y-%m-%d  %H:%M:%S");
	return str;
}


void CWeighToolView::SetUIDisableAll()
{
	this->m_ctrIMEI1.EnableWindow(FALSE);
	this->m_ctrIMEI2.EnableWindow(FALSE);
	this->m_ctrIMEI3.EnableWindow(FALSE);
	this->m_ctrIMEI4.EnableWindow(FALSE);
}


CString CWeighToolView::VariantToCString(VARIANT   var)   
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


void CWeighToolView::OnChangeEditImei1() 
{
	UpdateData();

	if(this->m_Config.m_iScanMode==1)//只扫描IMEI1模式走这个流程
	{
		if(m_csIMEI1.Right(2)=="\r\n")
		{
			m_csIMEI1.Replace("\r\n","");
			UpdateData(FALSE);
			
			if(!IMEITYPE_0_CheckImei1())
			{
				//警告提示音
				PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);  
				m_ctrIMEI1.SetFocus();
				m_ctrIMEI1.SetSel(0,-1);
				ShowCalResult(FAIL);
				return;
			}

			if(!this->Load_Current_Product_Count())
			{
				//警告提示音
				PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);
				InsertListInfo("Get the current produced number of orders fail",2);
				return;
			}
			InsertListInfo("Get the current produced number of orders success",0);
			this->UpdateCount(this->m_csCurrentCount);
			this->ClearUI();
			ShowCalResult(PASS);

			//成功提示音
			PlaySound((LPCSTR)(LPCTSTR)m_csOkSndPath, NULL, SND_FILENAME | SND_ASYNC);  
		}
	}
	else //否则走扫描所有IMEI流程
	{
		switch(this->m_iIMEIType)
		{
		case 0:			
			if(m_csIMEI1.Right(2)=="\r\n")
			{
				m_csIMEI1.Replace("\r\n","");
				UpdateData(FALSE);
				
				if(!IMEITYPE_0_CheckImei1())
				{
					//警告提示音
					PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);
					m_ctrIMEI1.SetFocus();
					m_ctrIMEI1.SetSel(0,-1);
					ShowCalResult(FAIL);
					return;
				}

				if(!this->Load_Current_Product_Count())
				{
					//警告提示音
					PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);
					InsertListInfo("Get the current produced number of orders fail",2);
					return;
				}
				InsertListInfo("Get the current produced number of orders success",0);
				this->ClearUI();
				this->UpdateCount(this->m_csCurrentCount);
				ShowCalResult(PASS);
				//成功提示音
				PlaySound((LPCSTR)(LPCTSTR)m_csOkSndPath, NULL, SND_FILENAME | SND_ASYNC);  
			}
			break;
		case 1:
			if(m_csIMEI1.Right(2)=="\r\n")
			{
				m_csIMEI1.Replace("\r\n","");
				UpdateData(FALSE);
				if(!IMEITYPE_1_CheckImei1())
				{
					//警告提示音
					PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);
					m_ctrIMEI1.SetFocus();
					m_ctrIMEI1.SetSel(0,-1);
					ShowCalResult(FAIL);
					return;
				}
				this->m_ctrIMEI2.SetFocus();
				this->m_ctrIMEI2.SetSel(0,-1);
			}
			break;
		case 2:
			if(m_csIMEI1.Right(2)=="\r\n")
			{
				m_csIMEI1.Replace("\r\n","");
				UpdateData(FALSE);
				if(!IMEITYPE_1_CheckImei1())
				{
					//警告提示音
					PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);
					m_ctrIMEI1.SetFocus();
					m_ctrIMEI1.SetSel(0,-1);
					ShowCalResult(FAIL);
					return;
				}
				this->m_ctrIMEI2.SetFocus();
				this->m_ctrIMEI2.SetSel(0,-1);	
			}
			break;
		case 3:
			if(m_csIMEI1.Right(2)=="\r\n")
			{
				m_csIMEI1.Replace("\r\n","");
				UpdateData(FALSE);
				if(!IMEITYPE_1_CheckImei1())
				{
					//警告提示音
					PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);
					m_ctrIMEI1.SetFocus();
					m_ctrIMEI1.SetSel(0,-1);
					ShowCalResult(FAIL);
					return;
				}
				this->m_ctrIMEI2.SetFocus();
				this->m_ctrIMEI2.SetSel(0,-1);
			}	
			break;
		default:
			break;
		}
	}
}


void CWeighToolView::OnChangeEditImei2() 
{
	UpdateData();
	
	switch(this->m_iIMEIType)
	{
	case 1:
		if(m_csIMEI2.Right(2)=="\r\n")
		{
			m_csIMEI2.Replace("\r\n","");
			UpdateData(FALSE);
			if(!IMEITYPE_1_CheckImei2())
			{
				//警告提示音
				PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);
				m_ctrIMEI1.SetFocus();
				m_ctrIMEI1.SetSel(0,-1);
				ShowCalResult(FAIL);
				return;
			}

			if(!this->Load_Current_Product_Count())
			{
				//警告提示音
				PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);
				InsertListInfo("Get the current produced number of orders fail",2);
				return;
			}
			InsertListInfo("Get the current produced number of orders success",0);
			this->ClearUI();
			this->UpdateCount(this->m_csCurrentCount);
			ShowCalResult(PASS);
			//成功提示音
			PlaySound((LPCSTR)(LPCTSTR)m_csOkSndPath, NULL, SND_FILENAME | SND_ASYNC);  
		}
		break;
	case 2:
		if(m_csIMEI2.Right(2)=="\r\n")
		{
			m_csIMEI2.Replace("\r\n","");
			UpdateData(FALSE);
			if(!IMEITYPE_2_CheckImei2())
			{
				//警告提示音
				PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);
				m_ctrIMEI1.SetFocus();
				m_ctrIMEI1.SetSel(0,-1);
				ShowCalResult(FAIL);
				return;
			}
			this->m_ctrIMEI3.SetFocus();
			this->m_ctrIMEI3.SetSel(0,-1);			
		}
		break;
	case 3:
		if(m_csIMEI2.Right(2)=="\r\n")
		{
			m_csIMEI2.Replace("\r\n","");
			UpdateData(FALSE);
			if(!IMEITYPE_2_CheckImei2())
			{
				//警告提示音
				PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);
				m_ctrIMEI1.SetFocus();
				m_ctrIMEI1.SetSel(0,-1);
				ShowCalResult(FAIL);
				return;
			}
			this->m_ctrIMEI3.SetFocus();
			this->m_ctrIMEI3.SetSel(0,-1);			
		}
		break;
	default:
		break;
	}
}


void CWeighToolView::OnChangeEditImei3() 
{
	UpdateData();
	
	switch(this->m_iIMEIType)
	{
	case 2:
		if(m_csIMEI3.Right(2)=="\r\n")
		{
			m_csIMEI3.Replace("\r\n","");
			UpdateData(FALSE);
			if(!IMEITYPE_2_CheckImei3())
			{
				//警告提示音
				PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);
				m_ctrIMEI1.SetFocus();
				m_ctrIMEI1.SetSel(0,-1);
				ShowCalResult(FAIL);
				return;
			}

			if(!this->Load_Current_Product_Count())
			{
				//警告提示音
				PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);
				InsertListInfo("Get the current produced number of orders fail",2);
				return;
			}
			InsertListInfo("Get the current produced number of orders success",0);
			this->ClearUI();
			this->UpdateCount(this->m_csCurrentCount);	
			ShowCalResult(PASS);
			//成功提示音
			PlaySound((LPCSTR)(LPCTSTR)m_csOkSndPath, NULL, SND_FILENAME | SND_ASYNC);  
		}
		break;
	case 3:
		if(m_csIMEI3.Right(2)=="\r\n")
		{
			m_csIMEI3.Replace("\r\n","");
			UpdateData(FALSE);
			if(!IMEITYPE_3_CheckImei3())
			{
				//警告提示音
				PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);
				m_ctrIMEI1.SetFocus();
				m_ctrIMEI1.SetSel(0,-1);
				ShowCalResult(FAIL);
				return;
			}
			this->m_ctrIMEI4.SetFocus();
			this->m_ctrIMEI4.SetSel(0,-1);			
		}
		break;
	default:
		break;
	}
}


void CWeighToolView::OnChangeEditImei4() 
{
	UpdateData();
	
	switch(this->m_iIMEIType)
	{
	case 3:
		if(m_csIMEI4.Right(2)=="\r\n")
		{
			m_csIMEI4.Replace("\r\n","");
			UpdateData(FALSE);
			if(!IMEITYPE_3_CheckImei4())
			{
				//警告提示音
				PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);
				m_ctrIMEI1.SetFocus();
				m_ctrIMEI1.SetSel(0,-1);
				ShowCalResult(FAIL);
				return;
			}

			if(!this->Load_Current_Product_Count())
			{
				//警告提示音
				PlaySound((LPCSTR)(LPCTSTR)m_csErrorSndPath, NULL, SND_FILENAME | SND_ASYNC);
				InsertListInfo("Get the current produced number of orders fail",2);
				return;
			}
			InsertListInfo("Get the current produced number of orders success",0);
			this->ClearUI();
			this->UpdateCount(this->m_csCurrentCount);	
			ShowCalResult(PASS);
			//成功提示音
			PlaySound((LPCSTR)(LPCTSTR)m_csOkSndPath, NULL, SND_FILENAME | SND_ASYNC);  
		}
		break;
	default:
		break;
	}	
}


BOOL CWeighToolView::IMEITYPE_0_CheckImei1()
{
	//检测长度是否为15位
	if(m_csIMEI1.GetLength()!=15)
	{
		InsertListInfo("IMEI1 Length error...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}

	//检测号码是否再合法范围内
	if (m_iIMEIRangeType==0)
	{
		if(m_csIMEI1.Left(14)>this->m_imei1_end || m_csIMEI1.Left(14)<this->m_imei1_start)
		{
			InsertListInfo("IMEI1 out of range...",2);
			this->m_ctrIMEI1.SetSel(0,-1);
			return FALSE;
		}
	}
	else if(m_iIMEIRangeType==1)
	{
		_variant_t var;
		CString sql;

		sql.Format("select * from %s_%s_IMEIRange WHERE IMEI1='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csIMEI1);
		
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

			if(((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				InsertListInfo("IMEI1 ont int the IMEI Form...",2);
				return FALSE;
			}

			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}

	//检测IMEI校验位是否正确
	char calculate_digit;
	calculate_15_digit_imei((char*)(LPCTSTR)m_csIMEI1.Left(14),calculate_digit);

	if(calculate_digit!=m_csIMEI1.Right(1))	
	{
		InsertListInfo("Illegal IMEI1,Parity bit error...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}

	CString temp,temp2;
	_variant_t var;
	CString sql;
	try
	{
		sql.Format("select * from %s_%s_ColorBox where IMEI1='%s' and Status=3 and Enable=1 ",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,(char*)(LPCTSTR)m_csIMEI1);  //@@ Call storage course @@
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			m_checkColorDone=TRUE;
		}
		else//彩盒数据库内无记录
		{
			m_checkColorDone=FALSE;
		}
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}	

	if(m_checkColorDone)//如果彩盒内有数据，更新Weigh参数
	{	
		try
		{
			//先判断重量
			if(this->m_dWeigh >this->m_dHighWeigh || this->m_dWeigh < this->m_dLowWeigh)
			{
				InsertListInfo("Weight out of spec...",2);
				return FALSE;
			}

			//比对前两次称重数据，如有相同则需权限验证
			if (dWeigh[0] != 0.0 && dWeigh[1] != 0.0)
			{
				if ((m_dWeigh == dWeigh[0]) && (m_dWeigh == dWeigh[1]))
				{
					dWeigh[1] = dWeigh[0];
					dWeigh[0] = m_dWeigh;
					InsertListInfo("3 consecutive weighing the same data, re-weighing...",2);
					return FALSE;
				}
			}

			dWeigh[1] = dWeigh[0];
			dWeigh[0] = m_dWeigh;

			sql.Format("UPDATE %s_%s_ColorBox SET ColorBoxWeigh=%.1f where IMEI1='%s' and Enable=1",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_dWeigh,(char*)(LPCTSTR)m_csIMEI1);
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();

			sql.Format("UPDATE %s_%s_ProductionLine SET ColorBoxWeighTool='%s',ColorBoxWeighTool=getdate() where IMEI1='%s'", \
				(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder, \
				this->m_csCurrentLine,this->m_csIMEI1);
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			InsertListInfo("Update Database weight data error...",2);
			return FALSE;
		}

		temp.Format("Weighing success，Weight=%.1fg，Update Database weight data success...",this->m_dWeigh);
		InsertListInfo(temp,0);
		return TRUE;
	}
	else//如果彩盒内无数据提示失败
	{
		InsertListInfo("Foolproof process fails,Check the phone is done Check S2 station please...",2);
		return FALSE;
	}
	
	return TRUE;
}


void CWeighToolView::calculate_15_digit_imei( char *imei_14,char &calculate_digit)
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


void CWeighToolView::ClearUI()
{
	switch(this->m_iIMEIType) 
	{
	case 0:
		this->m_csIMEI1.Empty();
		break;
	case 1:
		this->m_csIMEI1.Empty();
		this->m_csIMEI2.Empty();
		break;
	case 2:
		this->m_csIMEI1.Empty();
		this->m_csIMEI2.Empty();
		this->m_csIMEI3.Empty();
		break;
	case 3:
		this->m_csIMEI1.Empty();
		this->m_csIMEI2.Empty();
		this->m_csIMEI3.Empty();
		this->m_csIMEI4.Empty();
		break;
	default:
		break;
	}
	UpdateData(FALSE);
	this->m_ctrIMEI1.SetFocus();
}


BOOL CWeighToolView::IMEITYPE_1_CheckImei1()
{
	//检测长度是否为15位
	if(m_csIMEI1.GetLength()!=15)
	{
		InsertListInfo("IMEI1 Length error...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}

	//检测号码是否再合法范围内
	if (m_iIMEIRangeType==0)
	{
		if(m_csIMEI1.Left(14)>this->m_imei1_end || m_csIMEI1.Left(14)<this->m_imei1_start)
		{
			InsertListInfo("IMEI1 out of range...",2);
			this->m_ctrIMEI1.SetSel(0,-1);
			return FALSE;
		}
	}
	else if(m_iIMEIRangeType==1)
	{
		_variant_t var;
		CString sql;

		sql.Format("select * from %s_%s_IMEIRange WHERE IMEI1='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csIMEI1);
		
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

			if(((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				InsertListInfo("IMEI1 not in the IMEI form...",2);
				return FALSE;
			}

			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}
	
	//检测IMEI校验位是否正确
	char calculate_digit;
	calculate_15_digit_imei((char*)(LPCTSTR)m_csIMEI1.Left(14),calculate_digit);
	
	if(calculate_digit!=m_csIMEI1.Right(1))	
	{
		InsertListInfo("Illegal IMEI1,Parity bit error...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}
	
	return TRUE;
}


BOOL CWeighToolView::IMEITYPE_1_CheckImei2()
{
	if(m_csIMEI1==m_csIMEI2)  
	{
		InsertListInfo("IMEI1 and IMEI2 must be different...",2);
		this->m_ctrIMEI2.SetSel(0,-1);
		return FALSE;
	}
	
	//检测长度是否为15位
	if(m_csIMEI2.GetLength()!=15)
	{
		InsertListInfo("Length error...",2);
		this->m_ctrIMEI2.SetSel(0,-1);
		return FALSE;
	}
	
	//检测号码是否再合法范围内
	if (m_iIMEIRangeType==0)
	{
		if(m_csIMEI2.Left(14)>m_imei2_end || m_csIMEI2.Left(14)<m_imei2_start)
		{
			InsertListInfo("out of range...",2);
			this->m_ctrIMEI2.SetSel(0,-1);
			return FALSE;
		}
	}
	else if(m_iIMEIRangeType==1)
	{
		_variant_t var;
		CString sql;

		sql.Format("select * from %s_%s_IMEIRange WHERE IMEI2='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csIMEI2);
		
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

			if(((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				InsertListInfo("IMEI2 not in the IMEI form...",2);
				return FALSE;
			}

			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}
	
	//检测IMEI2校验位是否正确
	char calculate_digit;
	calculate_15_digit_imei((char*)(LPCTSTR)m_csIMEI2.Left(14),calculate_digit);
	
	if(calculate_digit!=m_csIMEI2.Right(1))
	{
		InsertListInfo("Illegal IMEI,Parity bit error...",2);
		this->m_ctrIMEI2.SetSel(0,-1);
		return FALSE;
	}
	
	//判断IMEI1和IMEI2是否同时在colorbox表中
	CString temp,temp2;
	_variant_t var;
	CString sql;
	try
	{
		sql.Format("select * from %s_%s_ColorBox where (IMEI1='%s') AND (IMEI2='%s') AND (Status=5) AND Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,(char*)(LPCTSTR)m_csIMEI1,(char*)(LPCTSTR)m_csIMEI2);  //@@ Call storage course @@
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			m_checkColorDone=TRUE;
		}
		else//彩盒数据库内无记录
		{
			m_checkColorDone=FALSE;
		}
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}	

	if(m_checkColorDone)//如果彩盒内有数据，更新Weigh参数
	{		
		try
		{
			//先判断重量
			if(this->m_dWeigh >this->m_dHighWeigh || this->m_dWeigh < this->m_dLowWeigh)
			{
				InsertListInfo("Weight out of spec...",2);
				return FALSE;
			}

			//比对前两次称重数据，如有相同则需权限验证
			if (dWeigh[0] != 0.0 && dWeigh[1] != 0.0)
			{
				if ((m_dWeigh == dWeigh[0]) && (m_dWeigh == dWeigh[1]))
				{
					dWeigh[1] = dWeigh[0];
					dWeigh[0] = m_dWeigh;
					InsertListInfo("3 consecutive weighing the same data, re-weighing...",2);
					return FALSE;
				}
			}

			dWeigh[1] = dWeigh[0];
			dWeigh[0] = m_dWeigh;
			
			sql.Format("UPDATE %s_%s_ColorBox SET ColorBoxWeigh=%.1f where (IMEI1='%s') AND (IMEI2='%s') AND Enable=1",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_dWeigh,(char*)(LPCTSTR)m_csIMEI1,(char*)(LPCTSTR)m_csIMEI2);
			((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

			sql.Format("UPDATE %s_%s_ProductionLine SET ColorBoxWeighTool='%s',ColorBoxWeighTool=getdate() where IMEI1='%s'", \
				(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder, \
				this->m_csCurrentLine,this->m_csIMEI1);
			((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		}
		catch(_com_error e)
		{
			InsertListInfo("Update Database weight data error...",2);
			return FALSE;
		}
		
		temp.Format("Weighing success，Weight=%.1fg，Update Database weight data success...",this->m_dWeigh);
		InsertListInfo(temp,0);
		return TRUE;
	}
	else//如果彩盒内无数据提示失败
	{
		InsertListInfo("Foolproof process fails,Check the phone is done Check IMEI S2 station please...",2);
		return FALSE;
	}

	return TRUE;
}


BOOL CWeighToolView::IMEITYPE_2_CheckImei2()
{
	//检测长度是否为15位
	if(m_csIMEI2.GetLength()!=15)
	{
		InsertListInfo("IMEI2 Length error...",2);
		this->m_ctrIMEI2.SetSel(0,-1);
		return FALSE;
	}
	
	//检测号码是否再合法范围内
	if (m_iIMEIRangeType==0)
	{
		if(m_csIMEI2.Left(14)>this->m_imei2_end || m_csIMEI2.Left(14)<this->m_imei2_start)
		{
			InsertListInfo("IMEI2 out of range...",2);
			this->m_ctrIMEI2.SetSel(0,-1);
			return FALSE;
		}
	}
	else if(m_iIMEIRangeType==1)
	{
		_variant_t var;
		CString sql;

		sql.Format("select * from %s_%s_IMEIRange WHERE IMEI2='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csIMEI2);
		
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

			if(((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				InsertListInfo("IMEI2 not in the IMEI form...",2);
				return FALSE;
			}

			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}
	
	//检测IMEI校验位是否正确
	char calculate_digit;
	calculate_15_digit_imei((char*)(LPCTSTR)m_csIMEI2.Left(14),calculate_digit);
	
	if(calculate_digit!=m_csIMEI2.Right(1))	
	{
		InsertListInfo("Illegal IMEI2,Parity bit error...",2);
		this->m_ctrIMEI2.SetSel(0,-1);
		return FALSE;
	}
	
	return TRUE;
}


BOOL CWeighToolView::IMEITYPE_2_CheckImei3()
{
	if(m_csIMEI1==m_csIMEI2)
	{
		InsertListInfo("IMEI1 and IMEI2 must be different...",2);
		this->m_ctrIMEI2.SetSel(0,-1);
		return FALSE;
	}

	if(m_csIMEI2==m_csIMEI3)
	{
		InsertListInfo("IMEI2 and IMEI3 must be different...",2);
		this->m_ctrIMEI3.SetSel(0,-1);
		return FALSE;
	}

	if(m_csIMEI1==m_csIMEI3)
	{
		InsertListInfo("IMEI1 and IMEI3 must be different...",2);
		this->m_ctrIMEI3.SetSel(0,-1);
		return FALSE;
	}
	
	//检测长度是否为15位
	if(m_csIMEI3.GetLength()!=15)
	{
		InsertListInfo("Length error...",2);
		this->m_ctrIMEI3.SetSel(0,-1);
		return FALSE;
	}
	
	//检测号码是否再合法范围内
	if (m_iIMEIRangeType==0)
	{
		if(m_csIMEI3.Left(14)>m_imei3_end || m_csIMEI3.Left(14)<m_imei3_start)
		{
			InsertListInfo("out of range...",2);
			this->m_ctrIMEI3.SetSel(0,-1);
			return FALSE;	
		}
	}
	else if(m_iIMEIRangeType==1)
	{
		_variant_t var;
		CString sql;

		sql.Format("select * from %s_%s_IMEIRange WHERE IMEI3='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csIMEI3);
		
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

			if(((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				InsertListInfo("IMEI3 not int the IMEI form...",2);
				return FALSE;
			}

			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}
	
	//检测IMEI3校验位是否正确
	char calculate_digit;
	calculate_15_digit_imei((char*)(LPCTSTR)m_csIMEI3.Left(14),calculate_digit);
	
	if(calculate_digit!=m_csIMEI3.Right(1))
	{
		InsertListInfo("Illegal IMEI,Parity bit error...",2);
		this->m_ctrIMEI3.SetSel(0,-1);
		return FALSE;
	}
	
	//判断IMEI1和IMEI2和IMEI3是否同时在colorbox表中
	CString temp,temp2;
	_variant_t var;
	CString sql;
	try
	{
		sql.Format("select * from %s_%s_ColorBox where (IMEI1='%s') AND (IMEI2='%s') AND (IMEI3='%s') AND (Status=5) AND Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,(char*)(LPCTSTR)m_csIMEI1,(char*)(LPCTSTR)m_csIMEI2,(char*)(LPCTSTR)m_csIMEI3);  //@@ Call storage course @@
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			m_checkColorDone=TRUE;
		}
		else//彩盒数据库内无记录
		{
			m_checkColorDone=FALSE;
		}
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}	
		
	if(m_checkColorDone)//如果彩盒内有数据，更新Weigh参数
	{		
		try
		{
			//先判断重量
			if(this->m_dWeigh >this->m_dHighWeigh || this->m_dWeigh < this->m_dLowWeigh)
			{
				InsertListInfo("Weight out of spec...",2);
				return FALSE;
			}

			//比对前两次称重数据，如有相同则需权限验证
			if (dWeigh[0] != 0.0 && dWeigh[1] != 0.0)
			{
				if ((m_dWeigh == dWeigh[0]) && (m_dWeigh == dWeigh[1]))
				{
					dWeigh[1] = dWeigh[0];
					dWeigh[0] = m_dWeigh;
					InsertListInfo("3 consecutive weighing the same data, re-weighing...",2);
					return FALSE;
				}
			}

			dWeigh[1] = dWeigh[0];
			dWeigh[0] = m_dWeigh;
			
			sql.Format("UPDATE %s_%s_ColorBox SET ColorBoxWeigh=%.1f where (IMEI1='%s') AND (IMEI2='%s') AND (IMEI3='%s') AND Enable=1",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_dWeigh,(char*)(LPCTSTR)m_csIMEI1,(char*)(LPCTSTR)m_csIMEI2,(char*)(LPCTSTR)m_csIMEI3);
			((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

			sql.Format("UPDATE %s_%s_ProductionLine SET ColorBoxWeighTool='%s',ColorBoxWeighTool=getdate() where IMEI1='%s'", \
				(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder, \
				this->m_csCurrentLine,this->m_csIMEI1);
			((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		}
		catch(_com_error e)
		{
			InsertListInfo("Update Database weight data error...",2);
			return FALSE;
		}
		
		temp.Format("Weighing success，Weight=%.1fg，Update Database weight data success...",this->m_dWeigh);
		InsertListInfo(temp,0);
		return TRUE;
	}
	else//如果彩盒内无数据提示失败
	{
		InsertListInfo("Foolproof process fails,Check the phone is done Check IMEI S2 station please...",2);
		return FALSE;
	}
	
	return TRUE;
}


BOOL CWeighToolView::IMEITYPE_3_CheckImei3()
{
 	//检测长度是否为15位
	if(m_csIMEI3.GetLength()!=15)
	{
		InsertListInfo("IMEI3 Length error...",2);
		this->m_ctrIMEI3.SetSel(0,-1);
		return FALSE;
	}
	
	//检测号码是否再合法范围内
	if (m_iIMEIRangeType==0)
	{
		if(m_csIMEI3.Left(14)>this->m_imei3_end || m_csIMEI3.Left(14)<this->m_imei3_start)
		{
			InsertListInfo("IMEI3 out of range...",2);
			this->m_ctrIMEI3.SetSel(0,-1);
			return FALSE;
		}
	}
	else if(m_iIMEIRangeType==1)
	{
		_variant_t var;
		CString sql;

		sql.Format("select * from %s_%s_IMEIRange WHERE IMEI3='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csIMEI3);
		
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

			if(((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				InsertListInfo("IMEI3 not in the IMEI form...",2);
				return FALSE;
			}

			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}
	
	//检测IMEI校验位是否正确
	char calculate_digit;
	calculate_15_digit_imei((char*)(LPCTSTR)m_csIMEI3.Left(14),calculate_digit);
	
	if(calculate_digit!=m_csIMEI3.Right(1))	
	{
		InsertListInfo("Illegal IMEI3,Parity bit error...",2);
		this->m_ctrIMEI3.SetSel(0,-1);
		return FALSE;
	}

	return TRUE;
}


BOOL CWeighToolView::IMEITYPE_3_CheckImei4()
{
	if(m_csIMEI1==m_csIMEI2)
	{
		InsertListInfo("IMEI1 and IMEI2 must be different...",2);
		this->m_ctrIMEI2.SetSel(0,-1);
		return FALSE;
	}

	if(m_csIMEI2==m_csIMEI3)
	{
		InsertListInfo("IMEI2 and IMEI3 must be different...",2);
		this->m_ctrIMEI3.SetSel(0,-1);
		return FALSE;
	}

	if(m_csIMEI1==m_csIMEI3)
	{
		InsertListInfo("IMEI1 and IMEI3 must be different...",2);
		this->m_ctrIMEI3.SetSel(0,-1);
		return FALSE;
	}

	if(m_csIMEI1==m_csIMEI4)
	{
		InsertListInfo("IMEI1 and IMEI4 must be different...",2);
		this->m_ctrIMEI4.SetSel(0,-1);
		return FALSE;
	}

	if(m_csIMEI2==m_csIMEI4)
	{
		InsertListInfo("IMEI2 and IMEI4 must be different...",2);
		this->m_ctrIMEI4.SetSel(0,-1);
		return FALSE;
	}

	if(m_csIMEI3==m_csIMEI4)
	{
		InsertListInfo("IMEI3 and IMEI4 must be different...",2);
		this->m_ctrIMEI4.SetSel(0,-1);
		return FALSE;
	}
	
	//检测长度是否为15位
	if(m_csIMEI4.GetLength()!=15)
	{
		InsertListInfo("Length error...",2);
		this->m_ctrIMEI4.SetSel(0,-1);
		return FALSE;
	}
	
	//检测号码是否再合法范围内
	if (m_iIMEIRangeType==0)
	{
		if(m_csIMEI4.Left(14)>m_imei4_end || m_csIMEI4.Left(14)<m_imei4_start)
		{
			InsertListInfo("out of range...",2);
			this->m_ctrIMEI4.SetSel(0,-1);
			return FALSE;
		}
	}
	else if(m_iIMEIRangeType==1)
	{
		_variant_t var;
		CString sql;

		sql.Format("select * from %s_%s_IMEIRange WHERE IMEI4='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,m_csIMEI4);
		
		try
		{
			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
			((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

			if(((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				InsertListInfo("IMEI4 not in the IMEI form...",2);
				return FALSE;
			}

			if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
				((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}
	
	//检测IMEI4校验位是否正确
	char calculate_digit;
	calculate_15_digit_imei((char*)(LPCTSTR)m_csIMEI4.Left(14),calculate_digit);
	
	if(calculate_digit!=m_csIMEI4.Right(1))
	{
		InsertListInfo("Illegal IMEI,Parity bit error...",2);
		this->m_ctrIMEI4.SetSel(0,-1);
		return FALSE;
	}
	
	//判断IMEI1和IMEI2和IMEI3和IMEI4是否同时在colorbox表中
	CString temp,temp2;
	_variant_t var;  
	CString sql;
	try
	{
		sql.Format("select * from %s_%s_ColorBox where (IMEI1='%s') AND (IMEI2='%s') AND (IMEI3='%s') AND (IMEI4='%s') AND (Status=5) AND Enable=1",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder,(char*)(LPCTSTR)m_csIMEI1,(char*)(LPCTSTR)m_csIMEI2,(char*)(LPCTSTR)m_csIMEI3,(char*)(LPCTSTR)m_csIMEI4);  //@@ Call storage course @@
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			m_checkColorDone=TRUE;
		}
		else//彩盒数据库内无记录
		{
			m_checkColorDone=FALSE;
		}
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("Unknown error...",2);
		this->m_ctrIMEI1.SetSel(0,-1);
		return FALSE;
	}	
	
	if(m_checkColorDone)//如果彩盒内有数据，更新Weigh参数
	{		
		try
		{
			//先判断重量
			if(this->m_dWeigh >this->m_dHighWeigh || this->m_dWeigh < this->m_dLowWeigh)
			{
				InsertListInfo("Weight out of spec...",2);
				return FALSE;
			}
			
			//比对前两次称重数据，如有相同则需权限验证
			if (dWeigh[0] != 0.0 && dWeigh[1] != 0.0)
			{
				if ((m_dWeigh == dWeigh[0]) && (m_dWeigh == dWeigh[1]))
				{
					dWeigh[1] = dWeigh[0];
					dWeigh[0] = m_dWeigh;
					InsertListInfo("3 consecutive weighing the same data, re-weighing...",2);
					return FALSE;
				}
			}

			dWeigh[1] = dWeigh[0];
			dWeigh[0] = m_dWeigh;
			
			sql.Format("UPDATE %s_%s_ColorBox SET ColorBoxWeigh=%.1f where (IMEI1='%s') AND (IMEI2='%s') AND (IMEI3='%s') AND (IMEI4='%s') AND Enable=1",this->m_csCurrentProduct,this->m_csCurrentOrder,this->m_dWeigh,(char*)(LPCTSTR)m_csIMEI1,(char*)(LPCTSTR)m_csIMEI2,(char*)(LPCTSTR)m_csIMEI3,(char*)(LPCTSTR)m_csIMEI4);
			((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

			sql.Format("UPDATE %s_%s_ProductionLine SET ColorBoxWeighTool='%s',ColorBoxWeighTool=getdate() where IMEI1='%s'", \
				(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder, \
				this->m_csCurrentLine,this->m_csIMEI1);
			((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		}
		catch(_com_error e)
		{
			InsertListInfo("Update Database weight data error...",2);
			return FALSE;
		}
		
		temp.Format("Weighing success，Weight=%.1fg，Update Database weight data success...",this->m_dWeigh);
		InsertListInfo(temp,0);
		return TRUE;
	}
	else//如果彩盒内无数据提示失败
	{
		InsertListInfo("Foolproof process fails,Check the phone is done Check IMEI S2 station please...",2);
		return FALSE;
	}
	return TRUE;
}


int CWeighToolView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	CSplashWnd::ShowSplashScreen(this);
	
	return 0;
}


void CWeighToolView::ShowCalResult(int state)
{	
	switch(state) 
	{
	case FAIL:
		this->m_cResult.SetTextColor(RGB(255,0,0));
		this->m_cResult.SetWindowText("FAIL");
		break;
	case PASS:
		this->m_cResult.SetTextColor(RGB(0,128,0));
		this->m_cResult.SetWindowText("PASS");
		break;
	default:
		break;
	}
}


void CWeighToolView::OnScanMode1() 
{
	CPassword dlg;
	dlg.ilevel = 1; //需超级权限验证
	if(dlg.DoModal()!=IDOK)
		return;

	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_MODE_2, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_MODE_1, MF_BYCOMMAND | MF_CHECKED );
	this->m_Config.m_iScanMode=1;
	this->m_Config.SaveConfig();	
}


void CWeighToolView::OnScanMode2() 
{
	CPassword dlg;
	dlg.ilevel = 1; //需超级权限验证
	if(dlg.DoModal()!=IDOK)
		return;

	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_MODE_1, MF_BYCOMMAND | MF_UNCHECKED );
	AfxGetMainWnd()->GetMenu()->GetSubMenu(0)->CheckMenuItem(IDM_SCAN_MODE_2, MF_BYCOMMAND | MF_CHECKED );
	this->m_Config.m_iScanMode=2;
	this->m_Config.SaveConfig();
}


bool CWeighToolView::GetProductOrderInfo()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	try
	{
		sql.Format("select *  from ProductList where Enable=1 and OrderName='%s'",m_csCurrentOrder);
		
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("ProductName");
			temp=VariantToCString(var);
			this->m_csCurrentProduct= temp;
			
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("IMEIType");
			this->m_iIMEIType=var.intVal;

			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("IMEIRangeType");
			this->m_iIMEIRangeType=var.intVal;
			
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1_STR");
			temp=VariantToCString(var);
			this->m_imei1_start= temp;
			
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1_END");
			temp=VariantToCString(var);
			this->m_imei1_end= temp;
			
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("IMEI2_STR");
			temp=VariantToCString(var);
			this->m_imei2_start= temp;
			
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("IMEI2_END");
			temp=VariantToCString(var);
			this->m_imei2_end= temp;
			
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("IMEI3_STR");
			temp=VariantToCString(var);
			this->m_imei3_start= temp;
			
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("IMEI3_END");
			temp=VariantToCString(var);
			this->m_imei3_end= temp;
			
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("IMEI4_STR");
			temp=VariantToCString(var);
			this->m_imei4_start= temp;
			
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("IMEI4_END");
			temp=VariantToCString(var);
			this->m_imei4_end= temp;
			
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("Color");
			temp=VariantToCString(var);
			this->m_csCurrentColor= temp;
			
		}
		else
		{
			return  FALSE;
		}

		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}	
	
	return TRUE;
}


bool CWeighToolView::Load_Current_Product_Count()   
{
	CString temp,states; 
	_variant_t var;
	CString sql;

	sql.Format("select count(*) as COUNT from %s_%s_ColorBox WHERE (ColorBoxWeigh<>'' or ColorBoxWeigh IS NOT NULL)",(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder);

	try
	{
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{			
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
			temp=VariantToCString(var);
			this->m_csCurrentCount= temp;
		}
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}


void CWeighToolView::UpdateCount(CString strCount)
{
	CString temp;
	temp="Quantity:"+strCount;
	this->m_cCurrentCount.SetWindowText(temp);
	UpdateData(FALSE);
}


BOOL CWeighToolView::GetSetting()//water
{
	CString temp;
	_variant_t var;
	CString sql;

	try
	{
		sql.Format("select * from SettingList where Enable=1 and ProductName='%s' and OrderName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder);
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("ColorBoxLowWeigh");
			this->m_dLowWeigh=atof((_bstr_t)var);

			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("ColorBoxHighWeigh");
			this->m_dHighWeigh=atof((_bstr_t)var);
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

	return TRUE;
}

void CWeighToolView::OnBtnSetting() 
{
	CPassword dlg;
	dlg.ilevel = 1; //需超级权限验证
	if(dlg.DoModal()!=IDOK)
	{
		return;
	}

	Csetting pdlg;
	pdlg.m_csProduct = m_csCurrentProduct;
	pdlg.m_csOrder = m_csCurrentOrder;
	if(pdlg.DoModal()!=IDOK)
	{
		return;
	}
}

void CWeighToolView::OnBtnRefresh() 
{
	CString temp;
	_variant_t var;
	CString sql;

	try
	{
		sql.Format("select * from SettingList where Enable=1 and ProductName='%s' and OrderName='%s'",this->m_csCurrentProduct,this->m_csCurrentOrder);
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
		((CWeighToolApp *)AfxGetApp())->m_pRst=((CWeighToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CWeighToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("ColorBoxLowWeigh");
			this->m_dLowWeigh=atof((_bstr_t)var);

			var = ((CWeighToolApp *)AfxGetApp())->m_pRst->GetCollect("ColorBoxHighWeigh");
			this->m_dHighWeigh=atof((_bstr_t)var);
		}
		else
		{
			return;
		}
		if(((CWeighToolApp *)AfxGetApp())->m_pRst->State)
			((CWeighToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		InsertListInfo("Get ColorBox weigh range fail...",2);
		return;
	}

	UpdateData(FALSE);
}
