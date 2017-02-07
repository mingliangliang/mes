// PACKView.h : interface of the CPACKView class
//
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INCLUDES()
#include "msflexgrid1.h"
//}}AFX_INCLUDES
#include "Config.h"
#include "StateList.h"
#include "Label.h"
#include "BtnST.h"
#include "skapi.h"
#include "excel.h"
#include "comdef.h"
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
	CButton	m_ctrCarton;
	CComboBox	m_ctrOrderType;
	CComboBox	m_ctrCustomer;
	CComboBox	m_ctrComboxType;
	CButton	m_ctrUnusedIMEI;
	CLabel	m_ctrReleaseUser;
	CLabel	m_ctrCreateUser;
	CButton	m_ctrRework;
	CButton	m_ctrIMEIQuery;
	CLabel	m_ctrCurrentPlan;
	CComboBox	m_ctrComboxProduct;
	CComboBox	m_ctrComboxOrder;
	CLabel	m_ctrCurrentProduct;
	CLabel	m_ctrCurrentOrder;
	CLabel	m_ctrCurrentColor;
	int		m_iComboxProduct;
	int		m_iComboxOrder;
	CString	m_csCurrentProduct;
	CString	m_csCurrentOrder;
	CString	m_csCurrentColor;
	CString	m_csCurrentWorkStation;
	CButton	m_ctrBtnPrint;
	CStateList	m_state_list;
	CMSFlexGrid	m_flex;
	CString	m_csCurrentPlan;
	CString	m_csCreateUser;
	CString	m_csReleaseUser;
	int		m_iComboxType;
	int		m_iCustomer;
	int		m_iOrderType;
	//}}AFX_DATA

// Attributes
public:
	CPACKDoc* GetDocument();

	
public://KEY
	unsigned short UserID;
	CString m_csReadCount;
	CString m_csWriteCount;
	int m_iReadCount;
	int m_iWriteCount;
	CFont m_staticfont;

public:
	void SetMyFont();
	void SetUIDisableAll();
	void InsertListInfo(CString state,int imageIndex);
	CString GetCurTimes();
	bool ConnectMDBDatabase();
	CString VariantToCString(VARIANT var);
	void SetRowCol(int rows,int cols);
	void SetNumText(int rows);

	bool GetProductList();
	bool GetProductOrderList();
	bool GetProductOrderInfo();

	bool GetProductionData();
	bool GetColorBoxWeighData();
	bool GetCartonBoxWeighData();
	bool GetShippingData();
	void ProductionDataRealTimeDisplay();

public:
	CConfig    m_Config;
	CImageList m_imageList;
	CString    m_csConfigPath;

	//分时段数据显示
	CStringArray csaPut;
	CStringArray csaWrite;
	CStringArray csaCheckS1;
	CStringArray csaColorBox;
	CStringArray csaCheckS2;
	CStringArray csaColorWeigh;
	CStringArray csaCarton;
	CStringArray csaCartonWeigh;
	CStringArray csaPallet;


	//数据库中获取卡通箱信息
	CString m_csCustomerNo;
	CString m_csDWNo;
	CString m_csCartonNameStatic;
	int     m_iCartonNameLength;
	int     m_iCartonMaxCount;

	//数据库中获取栈板信息
	CString m_csPalletNameStatic;
	int     m_iPalletNameLength;
	int     m_iPalletMaxCount;

	//数据库中计划产量
	int     m_iPlannedOutput;

	//excel
	CString      m_excel_path;
	_Application m_ExlApp;
	_Workbook    m_ExlBook;
	_Worksheet   m_ExlSheet;
	Workbooks    m_ExlBooks;
	Worksheets   m_ExlSheets;
	Range        m_ExlRge;

public:
	CStringArray m_csaIMEI1;
	CStringArray m_csaIMEI2;
	CStringArray m_csaIMEI3;
	CStringArray m_csaNetCode;
	CStringArray m_csaSN;
	CStringArray m_csaBoxID;
	CStringArray m_csaPalletID;
	CStringArray m_csaShippingDate;
	CStringArray m_csaCartonNametemp;
	CStringArray m_csaPalletNametemp;
	CStringArray m_csaShippingDatetemp;


	CStringArray m_csaColorBoxWeigh;
	CStringArray m_csaCartonBoxWeigh;

	CStringArray m_csaMACAddr;
	CStringArray m_csaBTAddr; 

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
	afx_msg void OnCloseupComboProduct();
	afx_msg void OnCloseupComboOrder();
	afx_msg void OnBtnPrint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBtnImeiquery();
	afx_msg void OnBtnUnusedimei();
	afx_msg void OnBtnOrderquery();
	afx_msg void OnCloseupComboType();
	afx_msg void OnBtnDetail();
	afx_msg void OnBtnCarton();
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





















