// CreateProductDlg.h : header file
//
#include "Config.h"
#include "skapi.h"
#include "excel.h"

#if !defined(AFX_CREATEPRODUCTDLG_H__A1AD0E92_6D0B_4EC2_88D3_95E70DD713D3__INCLUDED_)
#define AFX_CREATEPRODUCTDLG_H__A1AD0E92_6D0B_4EC2_88D3_95E70DD713D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCreateProductDlg dialog

class CCreateProductDlg : public CDialog
{
// Construction
public:
	CCreateProductDlg(CWnd* pParent = NULL);	// standard constructor

public:
	BOOL CheckProductName();
	BOOL CheckCFGFile();
	BOOL CheckSQLRepart();
	BOOL CheckIMEI(CString imei);
	BOOL CheckIMEIRange();
	BOOL GreatePDirectory();
	BOOL CreateConfigINI();
	BOOL CopyResource();
	BOOL InsertProductToSQL();
	BOOL CheckOrderName();
	void SetMyFont();
	CString VariantToCString(VARIANT var);
	CString IndexToString(int row, int col);
	void  clear();
	BOOL GetOrderList();
	BOOL GetProductList();

public:
	CFont m_staticfont;
	int  iIMEIRange;
	bool step1;
	bool step2;
	bool step3;
	bool step4;
	bool step5;
	bool step6;

/*lucky
	//工具功能设置项
	int     iRadioPlat;
	CString m_csDBpath;
	CString m_csAPpath;
	BOOL	bCheckBoardVersion;
	BOOL	bCheckBTFT;
	BOOL	bCheckResetFactory;
	BOOL	bCheckVersion;
	CString	csBoardVersion;
	CString	csVersion;
	double	dCartonHighWeigh;
	double	dCartonLowWeigh;
	double	dColorHighWeigh;
	double	dColorLowWeigh;

	BOOL    bCheckScanPSN;
	BOOL    bCheckWrite;
	int     iPSNLength;
	BOOL    bCheckPSNChk;
	CString csPSNChk;
	BOOL    bScanNetCode;
	int     iNetLength;
	CString csNetHeader;
*/
	//耦合测试设置
	BOOL    bCheckGSM1800;
	BOOL    bCheckGSM900;
	BOOL    bCheckGSM1900;
	BOOL    bCheckGSM850;
	BOOL    bCheckLTE;
	BOOL    bCheckG1800Fber;
	BOOL    bCheckG900Fber;
	BOOL    bCheckG1900Fber;
	BOOL    bCheckG850Fber;
	BOOL    bCheckWCDMA850;
	BOOL    bCheckWCDMA900;
	BOOL    bCheckWCDMA1900;
	BOOL    bCheckWCDMA2100;
	float   fGSM900BCHPower1;
	float   fGSM900BCHPower2;
	int     iGSM900TCHChannel;
	int     iGSM900TCHTxL;
	float   fGSM900PowerSTR;
	float   fGSM900PowerEND;
	float   fGSM900FBEREND;
	float   fGSM900FBERSTR;
	float   fGSM1800BCHPower1;
	float   fGSM1800BCHPower2;
	int     iGSM1800TCHChannel;
	int     iGSM1800TCHTxL;
	float   fGSM1800FBERSTR;
	float   fGSM1800FBEREND;
	float   fGSM1800PowerEND;
	float   fGSM1800PowerSTR;

	float   fGSM850BCHPower1;
	float   fGSM850BCHPower2;
	int     iGSM850TCHChannel;
	int     iGSM850TCHTxL;
	float   fGSM850PowerSTR;
	float   fGSM850PowerEND;
	float   fGSM850FBEREND;
	float   fGSM850FBERSTR;
	float   fGSM1900BCHPower1;
	float   fGSM1900BCHPower2;
	int     iGSM1900TCHChannel;
	int     iGSM1900TCHTxL;
	float   fGSM1900FBERSTR;
	float   fGSM1900FBEREND;
	float   fGSM1900PowerEND;
	float   fGSM1900PowerSTR;

	float   fW850CellPow;
	int     iW850DLChannel;
	int     iW850MsPow;
	float   fW850PowStr;
	float   fW850PowEnd;
	float   fW900CellPow;
	int     iW900DLChannel;
	int     iW900MsPow;
	float   fW900PowStr;
	float   fW900PowEnd;
	float   fW1900CellPow;
	int     iW1900DLChannel;
	int     iW1900MsPow;
	float   fW1900PowStr;
	float   fW1900PowEnd;
	float   fW2100CellPow;
	int     iW2100DLChannel;
	int     iW2100MsPow;
	float   fW2100PowStr;
	float   fW2100PowEnd;

	//excel
	CString      m_excel_path;
	_Application m_ExlApp;
	_Workbook    m_ExlBook;
	_Worksheet   m_ExlSheet;
	Workbooks    m_ExlBooks;
	Worksheets   m_ExlSheets;
	Range        m_ExlRge;
	Range        ExlRge;

// Dialog Data
	//{{AFX_DATA(CCreateProductDlg)
	enum { IDD = IDD_CREATEPRODUCT_DIALOG };
	CComboBox	m_ctrProductName;
	CComboBox	m_ctrOrderName;
	CButton	m_ctrSelectAPDBButton;
	CButton	m_ctrSelectDBButton;
	CEdit	m_ctrDBpath;
	CEdit	m_ctrAPpath;
	CEdit	m_ctrSNStatic;
	CEdit	m_ctrCustomer;
	CEdit	m_ctrimei4_start;
	CEdit	m_ctrimei3_start;
	CEdit	m_ctrimei2_start;
	CEdit	m_ctrimei1_start;
	CEdit	m_ctrimei4_end;
	CEdit	m_ctrimei3_end;
	CEdit	m_ctrimei2_end;
	CEdit	m_ctrimei1_end;
	CComboBox	m_ctrIMEIRange;
	CEdit	m_ctrStrCarton;
	CEdit	m_ctrEndCarton;
	CButton	m_ctrCreate;
	int		m_iIMEIType;
	CString	m_imei1_start;
	CString	m_imei2_start;
	CString	m_imei3_start;
	CString	m_imei4_start;
	CString	m_imei1_end;
	CString	m_imei2_end;
	CString	m_imei3_end;
	CString	m_imei4_end;
	CString	m_color_resource_path;
	CString	m_pack_resource_path;
	int		m_iCartonNameLength;
	int		m_iMaxCount;
	CString	m_csCartonNameStatic;
	CString	m_csColor;
	CString	m_pack_resource_path_sub;
	CString	m_pallet_resource_path;
	int		m_iPalletMaxCount;
	CString	m_csPalletNameStatic;
	int		m_iPalletNameLength;
	int		m_iPlannedOutput;
	CString	m_pallet_resource_path_sub;
	CString	m_csEndCarton;
	CString	m_csStrCarton;
	BOOL	m_bCartonRange;
	int		m_iIMEIRange;
	CString	m_csIMEIPath;
	CString	m_color_resource_path_sub;
	CString	m_csCustomer;
	CString	m_csSNStatic;
	int		iRadioPlat;
	CString	m_csDBpath;
	CString	m_csAPpath;
	BOOL	bCheckBoardVersion;
	BOOL	bCheckBTFT;
	BOOL	bCheckResetFactory;
	BOOL	bCheckVersion;
	CString	csBoardVersion;
	CString	csVersion;
	double	dCartonHighWeigh;
	double	dCartonLowWeigh;
	double	dColorHighWeigh;
	double	dColorLowWeigh;
	BOOL	bCheckScanPSN;
	BOOL	bCheckWrite;
	int		iPSNLength;
	BOOL	bCheckPSNChk;
	CString	csPSNChk;
	BOOL	bScanNetCode;
	int		iNetLength;
	CString	csNetHeader;
	CString	m_csProductName;
	CString	m_csOrderName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateProductDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreateProductDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnCheckProjectName();
	afx_msg void OnBtnColorOpen();
	afx_msg void OnBtnPackOpen();
	afx_msg void OnBtnResourceCheck();
	afx_msg void OnBtnCartonNameLengthCheck();
	afx_msg void OnBtnCreate();
	afx_msg void OnBtnPackOpenSub();
	afx_msg void OnBtnPalletOpen();
	afx_msg void OnBtnPalletNameLengthCheck();
	afx_msg void OnBtnPalletOpenSub();
	afx_msg void OnBtnSetting();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnCheckCartonrange();
	afx_msg void OnBtnCheckImei();
	afx_msg void OnBtnImeiOpen();
	afx_msg void OnCloseupComboImeirange();
	afx_msg void OnBtnColorOpenSub();
	afx_msg void OnRadioPlatSp();
	afx_msg void OnRadioPlatSprd();
	afx_msg void OnBtnSelect();
	afx_msg void OnBtnSelectap();
	afx_msg void OnCloseupComboProductname();
	afx_msg void OnCloseupComboOrdername();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEPRODUCTDLG_H__A1AD0E92_6D0B_4EC2_88D3_95E70DD713D3__INCLUDED_)
