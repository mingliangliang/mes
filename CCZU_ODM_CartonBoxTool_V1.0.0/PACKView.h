// PACKView.h : interface of the CPACKView class
//
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INCLUDES()
#include "msflexgrid.h"
//}}AFX_INCLUDES


#include "Config.h"
#include "StateList.h"
#include "Label.h"
#include "BtnST.h"
#include "PrintSetting.h"
#include "skapi.h"
#if !defined(AFX_PACKVIEW_H__6C8D4E97_3F26_4924_9D1B_A9B8695F8446__INCLUDED_)
#define AFX_PACKVIEW_H__6C8D4E97_3F26_4924_9D1B_A9B8695F8446__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPACKView : public CFormView
{
protected: // create from serialization only
	CPACKView();
	DECLARE_DYNCREATE(CPACKView)

public:
	//{{AFX_DATA(CPACKView)
	enum { IDD = IDD_PACK_FORM };
	CEdit	m_ctrAdd;
	CButton	m_ctrAddZ;
	CButton	m_ctrPSNStatic;
	CButtonST	m_ctrSetting;
	CLabel	m_ctrCurrentLine;
	CLabel	m_cCurrentCount;
	CLabel	m_ctrCurrentOrder;
	CLabel	m_ctrCurrentColor;
	CButtonST	m_ctrBtnPrint;
	CButtonST	m_ctrBtnEspeBox;
	CButtonST	m_ctrBtnDiscard;
	CButtonST	m_ctrBtnClose;
	CEdit	m_ctrIMEI4;
	CEdit	m_ctrIMEI3;
	CEdit	m_ctrIMEI2;
	CEdit	m_ctrIMEI1;
	CLabel	m_ctrCurrentProduct;
	CStateList	m_state_list;
	CMSFlexGrid	m_flex;
	CString	m_csCurrentProduct;
	CString	m_csIMEI1;
	CString	m_csIMEI3;
	CString	m_csIMEI2;
	CString	m_csIMEI4;
	CString	m_csCurrentColor;
	CString	m_csCurrentOrder;
	CString	m_csCurrentLine;
	BOOL	m_bPSNStatic;
	BOOL	m_bAddZ;
	CString	m_csAdd;
	//}}AFX_DATA

// Attributes
public:
	CPACKDoc* GetDocument();
	
public:
	
	CFont m_staticfont;

public:
	void CreateTwoFile();
	void SetMyFont();
	void SetUIDisableAll();
	void InsertListInfo(CString state,int imageIndex);
	CString GetCurTimes();
	bool GetProductList();
	CString VariantToCString(VARIANT var);
	void SetRowCol(int rows,int cols);
	void SetNumText(int rows);
	void CurrentAdd(CString& current,UINT step);
	bool Get_Current_Carton_Name();
	bool ReGet_Current_Carton_Name();
	void calculate_15_digit_imei( char *imei_14,char &calculate_digit);
	bool IMEITYPE_0_CheckImei1();
	BOOL IMEITYPE_1_CheckImei1();
	bool IMEITYPE_1_CheckImei2();
	BOOL IMEITYPE_2_CheckImei2();
	bool IMEITYPE_2_CheckImei3();
	BOOL IMEITYPE_3_CheckImei3();
	bool IMEITYPE_3_CheckImei4();
	bool IMEITYPE_0_CheckImei1_Ex();
	bool InsertDataToSQL();
	bool UpdateStatusTo2();
	bool GetProductOrderInfo();
	bool Load_Current_Product_Count();
	void UpdateCount(CString strCount);
	void PopMessageBox_Ex();
	void PopMainCarton_Ex(CString strMainCarton);

public:
	CConfig    m_Config;
	CImageList m_imageList;
	CString    m_csCurrent_Carton;
	CString    m_csReGet_Current_Carton;
	CString    m_csCurrentCount;
	//数据库中获取信息
	int        m_iIMEIType;  //IMEI类型
	int        m_iIMEIRangeType;
	CString    m_csCartonNameStatic;  //卡通箱固定位
	int        m_iCartonNameLength;  //卡通箱流水位长度
	int        m_iMaxCount;  //卡通箱满箱容量
	CString    m_csCartonNameBegin;//卡通箱开始箱号

public:
	BOOL m_showState;
	CString m_csLocalPath;
	
public:
	CStringArray m_csaIMEI1;
	CStringArray m_csaIMEI2;
	CStringArray m_csaIMEI3;
	CStringArray m_csaIMEI4;
	CStringArray m_csaSN;
	CStringArray m_csaPSN;
	CStringArray m_csaBT;
	CStringArray m_csaMAC;
	CStringArray m_csaWeigh;
	CStringArray m_csaNet;

	CString	m_csSN;
	CString	m_csPSN;
	CString	m_csMAC;
	CString m_csWeigh;
	CString	m_csBT;
	CString	m_csIMEI2_Ex;
	CString	m_csIMEI3_Ex;
	CString	m_csIMEI4_Ex;
	CString	m_csNet;

	CString	m_csPSNStatic;

public:  
	CString m_imei1_start;
	CString m_imei1_end;
	CString m_imei2_start;
	CString m_imei2_end;
	CString m_imei3_start;
	CString m_imei3_end;
	CString m_imei4_start;
	CString m_imei4_end;

	int m_cur_row;
	int m_cur_col;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPACKView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPACKView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPACKView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnBtnEspeBox();
	afx_msg void OnBtnClose();
	afx_msg void OnBtnDiscard();
	afx_msg void OnChangeEditImei1();
	afx_msg void OnChangeEditImei2();
	afx_msg void OnChangeEditImei3();
	afx_msg void OnChangeEditImei4();
	afx_msg void OnBtnPrint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnScanAll();
	afx_msg void OnScanOne();
	afx_msg void OnBtnSetting();
	afx_msg void OnCheckPsnStatic();
	afx_msg void OnCheckAddZ();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PACKView.cpp
inline CPACKDoc* CPACKView::GetDocument()
   { return (CPACKDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PACKVIEW_H__6C8D4E97_3F26_4924_9D1B_A9B8695F8446__INCLUDED_)





















