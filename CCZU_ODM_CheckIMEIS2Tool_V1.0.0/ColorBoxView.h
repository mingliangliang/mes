// ColorBoxView.h : interface of the CColorBoxView class
//
/////////////////////////////////////////////////////////////////////////////
#include "Label.h"
#include "Config.h"
#include "StateList.h"
#include "skapi.h"
#include "Password.h"

#if !defined(AFX_COLORBOXVIEW_H__65D02BA8_820F_4963_A9FA_C6A9AE29763C__INCLUDED_)
#define AFX_COLORBOXVIEW_H__65D02BA8_820F_4963_A9FA_C6A9AE29763C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WM_UPDATEDATA  WM_USER+101
#define WM_SETMYFOCUS  WM_USER+102

class CColorBoxView : public CFormView
{
protected: // create from serialization only
	CColorBoxView();
	DECLARE_DYNCREATE(CColorBoxView)

public:
	//{{AFX_DATA(CColorBoxView)
	enum { IDD = IDD_COLORBOX_FORM };
	CLabel	m_cResult;
	CLabel	m_ctrCurrentLine;
	CEdit	m_ctrmIMEI4;
	CEdit	m_ctrmIMEI3;
	CEdit	m_ctrmIMEI2;
	CEdit	m_ctrmIMEI1;
	CEdit	m_ctrcIMEI4;
	CEdit	m_ctrcIMEI3;
	CEdit	m_ctrcIMEI2;
	CEdit	m_ctrcIMEI1;
	CString	m_cscIMEI1;
	CString	m_cscIMEI2;
	CString	m_cscIMEI3;
	CString	m_cscIMEI4;
	CString	m_csmIMEI1;
	CString	m_csmIMEI2;
	CString	m_csmIMEI3;
	CString	m_csmIMEI4;
	CLabel	m_ctrCurrentProduct;
	CLabel	m_ctrCurrentOrder;
	CLabel	m_ctrCurrentColor;
	CLabel	m_cCurrentCount;
	CString	m_csCurrentProduct;
	CString	m_csCurrentColor;
	CString	m_csCurrentOrder;
	CStateList	m_state_list;
	CString	m_csCurrentLine;
	//}}AFX_DATA
	
// Attributes
public:
	CColorBoxDoc* GetDocument();

public:
	void SetMyFont();
	void InsertListInfo(CString state,int imageIndex);
	CString GetCurTimes();
	void SetUIDisableAll();
	bool GetProductList();
	CString VariantToCString(VARIANT   var);   
	bool Load_Current_Product_Config();
	void ClearUI();
	BOOL CheckImei1();
	BOOL CheckImei2();
	BOOL CheckImei3();
	BOOL CheckImei4();
	void calculate_15_digit_imei( char *imei_14,char &calculate_digit);
	void PrintLabel();
	BOOL SaveToColorInfo();
	void OnUpdateData(WPARAM wParam, LPARAM lParam);
	void OnSetMyFocus(WPARAM wParam, LPARAM lParam);
	void ShowCalResult(int state);
public:
	bool GetProductOrderInfo();
	bool Load_Current_Product_Count();
	void UpdateCount(CString strCount);
	bool CheckColorPrintStatus_Mode1();
	bool CheckColorPrintStatus_Mode2();
	bool CheckColorPrintStatus_Mode3();
	bool CheckColorPrintStatus_Mode4();

public:
	CConfig m_Config;
	CImageList m_imageList;
	CFont m_staticfont;
	CFont m_staticfont3;
	int m_iIMEIType;
	int m_iIMEIRangeType;
	CString m_csConfigPath;
	BOOL m_checkColorDone;

	CString m_csErrorSndPath;    
	CString m_csOkSndPath;
	CString m_csCurrentCount;

public:  
	CString m_imei1_start;
	CString m_imei1_end;
	CString m_imei2_start;
	CString m_imei2_end;
	CString m_imei3_start;
	CString m_imei3_end;
	CString m_imei4_start;
	CString m_imei4_end;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorBoxView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CColorBoxView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CColorBoxView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnChangeEditCimei1();
	afx_msg void OnChangeEditCimei2();
	afx_msg void OnChangeEditCimei3();
	afx_msg void OnChangeEditCimei4();
	afx_msg void OnChangeEditMimei1();
	afx_msg void OnChangeEditMimei2();
	afx_msg void OnChangeEditMimei3();
	afx_msg void OnChangeEditMimei4();
	afx_msg void OnScanMainImeiYes();
	afx_msg void OnScanMainImeiNo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ColorBoxView.cpp
inline CColorBoxDoc* CColorBoxView::GetDocument()
   { return (CColorBoxDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORBOXVIEW_H__65D02BA8_820F_4963_A9FA_C6A9AE29763C__INCLUDED_)
