// CartonBoxPrint.cpp : implementation file
//


#include "stdafx.h"
#include "PACK.h"
#include "CartonBoxPrint.h"
#include "PACKDoc.h"
#include "MainFrm.h"
#include "PACKView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define MAIN_SOURCE     0
#define SUB_SOURCE      1
/////////////////////////////////////////////////////////////////////////////
// CCartonBoxPrint dialog


CCartonBoxPrint::CCartonBoxPrint(CWnd* pParent /*=NULL*/)
	: CDialog(CCartonBoxPrint::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCartonBoxPrint)
	m_replace_R1 = _T("");
	m_csCurrentProduct = _T("");
	m_csCurrentOrder = _T("");
	m_csPalletNameStatic = _T("");
	m_csPalletName = _T("");
	m_iRadioMainSource = 0;
	m_iComboxSource = 0;
	//}}AFX_DATA_INIT
}


void CCartonBoxPrint::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCartonBoxPrint)
	DDX_Control(pDX, IDC_COMBO_SOURCE, m_ctrComboxSource);
	DDX_Control(pDX, IDC_RADIO_MAIN_SOURCE, m_ctrMainSource);
	DDX_Control(pDX, IDC_RADIO1, m_ctrRADIO1);
	DDX_Control(pDX, IDC_STATIC_CURRENT_PALLET, m_ctrPalletName);
	DDX_Control(pDX, IDC_STATIC_CURRENT_PALLET_STATIC, m_ctrPalletNameStatic);
	DDX_Control(pDX, IDC_STATIC_CURRENT_ORDER_EX, m_ctrCurrentOrder);
	DDX_Control(pDX, IDC_STATIC_CURRENT_PRODUCT, m_ctrCurrentProduct);
	DDX_Control(pDX, IDC_BTN_PRINT_LABLE, m_btn_print);
	DDX_Text(pDX, IDC_EDIT_R1, m_replace_R1);
	DDX_Text(pDX, IDC_STATIC_CURRENT_PRODUCT, m_csCurrentProduct);
	DDX_Text(pDX, IDC_STATIC_CURRENT_ORDER_EX, m_csCurrentOrder);
	DDX_Text(pDX, IDC_STATIC_CURRENT_PALLET_STATIC, m_csPalletNameStatic);
	DDX_Text(pDX, IDC_STATIC_CURRENT_PALLET, m_csPalletName);
	DDX_Radio(pDX, IDC_RADIO_MAIN_SOURCE, m_iRadioMainSource);
	DDX_CBIndex(pDX, IDC_COMBO_SOURCE, m_iComboxSource);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCartonBoxPrint, CDialog)
	//{{AFX_MSG_MAP(CCartonBoxPrint)
	ON_BN_CLICKED(IDC_BTN_PRINT_LABLE, OnBtnPrintLable)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO_MAIN_SOURCE, OnRadioMainSource)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCartonBoxPrint message handlers

BOOL CCartonBoxPrint::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_btn_print.SetIcon(IDI_ICON5);
	m_btn_print.SetActiveFgColor(RGB(0,0,255));

	this->m_ctrCurrentProduct.SetFontSize(18);
	this->m_ctrCurrentProduct.SetFontName("Arial");
	this->m_ctrCurrentProduct.SetTextColor(RGB(0,0,255));
	
	this->m_ctrCurrentOrder.SetFontSize(18);
	this->m_ctrCurrentOrder.SetFontName("Bold");
	this->m_ctrCurrentOrder.SetTextColor(RGB(0,0,255));
	
	this->m_ctrPalletName.SetFontSize(18);
	this->m_ctrPalletName.SetFontName("Bold");
	this->m_ctrPalletName.SetTextColor(RGB(0,0,255));
	
	this->m_ctrPalletNameStatic.SetFontSize(18);
	this->m_ctrPalletNameStatic.SetFontName("Bold");
	this->m_ctrPalletNameStatic.SetTextColor(RGB(0,0,255));

	ResetControl();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


CString CCartonBoxPrint::VariantToCString(VARIANT   var)   
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


void CCartonBoxPrint::ResetControl()
{
	m_replace_R1 = _T("");
	UpdateData(FALSE);
}


void CCartonBoxPrint::OnBtnPrintLable() 
{
	CString temp;

	//reset
	m_csaCartonName.RemoveAll();
	m_csaWeigh.RemoveAll();

	//获取当前项目、订单、栈板号固定位
	csCurrentProduct   = this->m_csCurrentProduct;
	csCurrentOrder     = this->m_csCurrentOrder;
	csPalletNameStatic = this->m_csPalletNameStatic;
	
	//获取config.ini路径
	CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	CPACKView *pView=(CPACKView *)pMain->GetActiveView();
	this->m_csConfigPath.Format("%s%s_%s",pView->m_Config.m_csCFGPath,this->m_csCurrentProduct,this->m_csCurrentOrder);

	UpdateData();

	switch (this->m_iRadioMainSource)
	{
	case MAIN_SOURCE:  //打印当前栈板号
		//获取当前栈板流水号
		csPalletName = this->m_csPalletName;
		if(!CheckPalletName()) //检测栈板号是否有效
		{
			return;
		}
		
		if(!GetDataInfo()) //根据栈板号获取相应数据
		{
			return;	
		}
		
		if(!ReplaceResource()) //替换资源
		{
			return;	
		}
		
		if(!GoToPrint()) //打印资源
		{
			return;	
		}
		break;
	case SUB_SOURCE:  //打印特定栈板号
		//检查是否输入栈板号
		if (m_replace_R1.IsEmpty ())
		{
			temp.Format("栈板流水号不能为空，请输入!");
			MessageBox(temp,"Prompt",MB_OK);
			return;	
		}
		//获取输入的栈板流水号
		csPalletName = m_replace_R1;

		if(!CheckPalletName()) //检测栈板号是否有效
		{
			return;
		}
		
		if(!GetDataInfo()) //根据栈板号获取相应数据
		{
			return;	
		}
		
		if(!ReplaceResource()) //替换资源
		{
			return;	
		}
		
		if(!GoToPrint()) //打印资源
		{
			return;	
		}
		break;
	}

	return;	
}


bool CCartonBoxPrint::CheckPalletName()
{
	CString temp,temp2;
	_variant_t var;
	CString sql;

	try
	{
		sql.Format("select * from %s_%s_Pallet where PalletName='%s' and Status=2",csCurrentProduct,csCurrentOrder,csPalletName);
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			temp.Format("Invalid pallet number \'%s\' !",csPalletName);
			MessageBox(temp,"Prompt",MB_ICONHAND);
			return FALSE;
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		MessageBox("Unknown error...","Prompt",MB_ICONQUESTION);
		return FALSE;
	}
	return TRUE;
}


bool CCartonBoxPrint::GetDataInfo()
{
	CString temp,temp2;
	_variant_t var;
	CString sql;
	CStringArray m_csaIMEI1;
	
	try
	{
		sql.Format("select * from %s_%s_CartonBox where PalletName='%s'",csCurrentProduct,csCurrentOrder,csPalletName);
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonName");
			temp=VariantToCString(var);
			m_csaCartonName.Add(temp);

			var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonWeigh");
			temp=VariantToCString(var);
			m_csaWeigh.Add(temp);

			((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		MessageBox("Unknown error...","Prompt",MB_ICONQUESTION);
		return FALSE;
	}

	for (int i=0; i<m_csaCartonName.GetSize(); i++)
	{
		try
		{
			sql.Format("select * from %s_%s_ColorBox where CartonName='%s'",csCurrentProduct,csCurrentOrder,m_csaCartonName[i]);
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
			((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				var=((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1");
				temp=VariantToCString(var);
				m_csaIMEI1.Add(temp);
				
				((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
			}
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
		} 
		catch(_com_error e)
		{
			MessageBox("Unknown error...","Prompt",MB_ICONQUESTION);
			return FALSE;
		}
	}

	for (int j=0; j<m_csaIMEI1.GetSize(); j++)
	{
		sql.Format("UPDATE %s_%s_ProductionLine SET Pallet='%s', PalletName='%s',PalletDate=getdate() where IMEI1='%s'", \
			(char*)(LPCTSTR)this->m_csCurrentProduct,this->m_csCurrentOrder, \
			this->csProductionLine,csPalletName,m_csaIMEI1[j]);
		try
		{
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
			((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		}
		catch(_com_error e)
		{
			MessageBox("Unknown error...","Prompt",MB_ICONQUESTION);
			return FALSE;
		}
	}

	return TRUE;
}


void CCartonBoxPrint::OnOK() 
{

}

void CCartonBoxPrint::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}


BOOL CCartonBoxPrint::ReplaceResource()
{
	_variant_t var;
	CString sql;
	CStdioFile fp;
	CStdioFile fp1;
	CString temp;
	CString CommandBuff;
	temp.Empty();
	CommandBuff.Empty();
	CString csSourcePath;
	int index;

	index=this->m_ctrComboxSource.GetCurSel();

	switch (index)
	{
	case MAIN_SOURCE:
		csSourcePath=csLocalPathtemp+"\\PalletResource.txt";
		break;
	case SUB_SOURCE:
		csSourcePath=csLocalPathtemp+"\\PalletResource_Sub.txt";
		break;
	default :
		csSourcePath=csLocalPathtemp+"\\PalletResource.txt";
		break;
	}
	
	if (!fp.Open(csSourcePath,CFile::modeRead | CFile::typeBinary))
	{
		MessageBox("The type of pallet resource file not found, please contact the Engineer!","Prompt",MB_ICONHAND);
		return FALSE;
	}
	else
	{
		while(fp.ReadString(temp))
		{
			if(temp.Find("P1P")!=-1)
			{
				temp.Replace("P1P",(this->csPalletNameStatic)+(this->csPalletName));
				CommandBuff+=temp;
				continue;
			}
			
			if(temp.Find("PQ1P")!=-1)
			{
				temp.Replace("PQ1P",(csPalletNameStatic+csPalletName.Left(iPalletNameLength-1))+">6"+csPalletName.Right(1));
				CommandBuff+=temp;
				continue;
			}
			
			CommandBuff+=temp;
		}
		fp.Close();
		
		//如果不满栈板那么增加空数据到数组
		int icurrentSize=0;
		icurrentSize = this->m_csaCartonName.GetSize();
		if(iPalletMaxCount != icurrentSize)
		{
			for(int a=icurrentSize ;a<iPalletMaxCount ;a++)
			{
				this->m_csaCartonName.Add("");
				this->m_csaWeigh.Add("");
			}
		}
		
		CString sTp;
		
		for(int i=0;i<this->m_csaCartonName.GetSize();i++)
		{
			sTp.Format("!CN%d!",i+1);
			if(CommandBuff.Find(sTp)!=-1)
				CommandBuff.Replace(sTp,(this->csCartonNameStatic)+(this->m_csaCartonName.GetAt(i)));
			
			sTp.Format("{%d{",i+1);
			if(CommandBuff.Find(sTp)!=-1)
				CommandBuff.Replace(sTp,this->m_csaWeigh.GetAt(i));
			
			sTp.Format("!QCN%d!",i+1);
			if(CommandBuff.Find(sTp)!=-1)
				CommandBuff.Replace(sTp,this->csCartonNameStatic+this->m_csaCartonName.GetAt(i).Left(this->m_csaCartonName.GetAt(i).GetLength()-1)+">6"+this->m_csaCartonName.GetAt(i).Right(1));
			
			sTp.Format("{Q%d{",i+1);
			if(CommandBuff.Find(sTp)!=-1)
				CommandBuff.Replace(sTp,this->m_csaWeigh.GetAt(i).Left(this->m_csaWeigh.GetAt(i).GetLength()-1)+">6"+this->m_csaWeigh.GetAt(i).Right(1));
		}
		
		fp1.Open("c:\\resource.txt",CFile::modeWrite | CFile::typeBinary | CFile::modeCreate);
		fp1.WriteString(CommandBuff);
		fp1.Close();
	}
	return TRUE;
}


BOOL CCartonBoxPrint::GoToPrint()
{
	
	ShellExecute(AfxGetMainWnd()->GetSafeHwnd(), "open", "c:\\temp.bat", NULL, NULL, SW_HIDE );
	return TRUE;
}


char CCartonBoxPrint::Calculate_Random()
{
	int random=0;
	for(int a=0 ; a< this->m_replace_R1.GetLength() ; a++)
	{
		random+=this->m_replace_R1.GetAt(a) -48;
	}
	
	random = (random*3)%10;

	char value = random+48;
	return value;
}


void CCartonBoxPrint::OnRadioMainSource()
{
	// TODO: Add your control notification handler code here
	m_replace_R1 = _T("");
	UpdateData(FALSE);
	m_ctrMainSource.SetCheck(TRUE);
	m_ctrRADIO1.SetCheck(FALSE);
	((CWnd*)GetDlgItem(IDC_EDIT_R1))->EnableWindow(FALSE);
}

void CCartonBoxPrint::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	m_replace_R1 = _T("");
	UpdateData(FALSE);
	m_ctrRADIO1.SetCheck(TRUE);
	m_ctrMainSource.SetCheck(FALSE);
	((CWnd*)GetDlgItem(IDC_EDIT_R1))->EnableWindow(TRUE);
	((CWnd*)GetDlgItem(IDC_EDIT_R1))->SetFocus();
}
