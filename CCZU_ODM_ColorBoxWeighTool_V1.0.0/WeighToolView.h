// WeighToolView.h : interface of the CWeighToolView class
//
/////////////////////////////////////////////////////////////////////////////

#include "Config.h"
#include "RSData.h"
#include "myserial.h"
#include "Label.h"
#include "StateList.h"
#include "Config.h"


#if !defined(AFX_WEIGHTOOLVIEW_H__FFF3576F_8B6D_477D_9B18_2F71DCD6E059__INCLUDED_)
#define AFX_WEIGHTOOLVIEW_H__FFF3576F_8B6D_477D_9B18_2F71DCD6E059__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWeighToolView : public CFormView
{
protected: // create from serialization only
	CWeighToolView();
	DECLARE_DYNCREATE(CWeighToolView)

public:
	//{{AFX_DATA(CWeighToolView)
	enum { IDD = IDD_WEIGHTOOL_FORM };
	CLabel	m_ctrCurrentLine;
	CLabel	m_cCurrentCount;
	CLabel	m_ctrCurrentProduct;
	CLabel	m_ctrCurrentOrder;
	CLabel	m_ctrCurrentColor;
	CLabel	m_cResult;
	CEdit	m_ctrIMEI4;
	CEdit	m_ctrIMEI3;
	CEdit	m_ctrIMEI2;
	CEdit	m_ctrIMEI1;
	CEdit	m_ctrLowWeigh;
	CEdit	m_ctrHighWeigh;
	CStateList	m_state_list;
	CLabel	m_ctrWeigh;
	CLabel	m_ctrUnit;
	CComboBox	m_ctrComport;
	int		m_iComport;
	double	m_dHighWeigh;
	double	m_dLowWeigh;
	CString	m_csIMEI1;
	CString	m_csIMEI2;
	CString	m_csIMEI3;
	CString	m_csIMEI4;
	CString	m_csCurrentColor;
	CString	m_csCurrentOrder;
	CString	m_csCurrentProduct;
	CString	m_csCurrentLine;
	//}}AFX_DATA

// Attributes
public:
	CWeighToolDoc* GetDocument();

public:
	CMySerial m_Serial;
	CRSData m_RSData;
	int m_comnum[255];
	int m_comport;
	CImageList m_imageList;
	double m_dWeigh;
	CFont m_staticfont;
	CFont m_staticfont1;
	CConfig m_Config;
	int m_iIMEIType;
	int m_iIMEIRangeType;
	BOOL m_checkColorDone;
	CString m_csCurrentCount;

public:
	HANDLE m_hThread;
	DWORD m_dThreadId;

	CString m_csErrorSndPath;    
	CString m_csOkSndPath;

public:  
	CString m_imei1_start;
	CString m_imei1_end;
	CString m_imei2_start;
	CString m_imei2_end;
	CString m_imei3_start;
	CString m_imei3_end;
	CString m_imei4_start;
	CString m_imei4_end;

	double m_dLow_Weigh;
	double m_dHigh_Weigh;
	double dWeigh[2];  //记录前两次的称重数据

public:
	void LoadComPort();
	BOOL InitComPort();
	void SetMyFont();
	void InsertListInfo(CString state,int imageIndex);
	CString GetCurTimes();
	void DoWeigh();
	void SetUIDisableAll();
	CString VariantToCString(VARIANT var);
	void ClearUI();
	void ShowCalResult(int state);
	bool GetProductOrderInfo();
	bool Load_Current_Product_Count();
	void UpdateCount(CString strCount);

	void calculate_15_digit_imei( char *imei_14,char &calculate_digit);
	BOOL IMEITYPE_0_CheckImei1();
	BOOL IMEITYPE_1_CheckImei1();
	BOOL IMEITYPE_1_CheckImei2();
	BOOL IMEITYPE_2_CheckImei2();
	BOOL IMEITYPE_2_CheckImei3();
	BOOL IMEITYPE_3_CheckImei3();
	BOOL IMEITYPE_3_CheckImei4();
// Operations
public:
	BOOL GetSetting();//water

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWeighToolView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWeighToolView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWeighToolView)
	afx_msg void OnSelchangeComboComport();
	afx_msg void OnBtnStart();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnChangeEditImei1();
	afx_msg void OnChangeEditImei2();
	afx_msg void OnChangeEditImei3();
	afx_msg void OnChangeEditImei4();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnScanMode1();
	afx_msg void OnScanMode2();
	afx_msg void OnBtnSetting();
	afx_msg void OnBtnRefresh();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in WeighToolView.cpp
inline CWeighToolDoc* CWeighToolView::GetDocument()
   { return (CWeighToolDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEIGHTOOLVIEW_H__FFF3576F_8B6D_477D_9B18_2F71DCD6E059__INCLUDED_)
