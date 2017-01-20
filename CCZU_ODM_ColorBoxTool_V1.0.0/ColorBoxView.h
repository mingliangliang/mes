// ColorBoxView.h : interface of the CColorBoxView class
//
/////////////////////////////////////////////////////////////////////////////
#include "Label.h"
#include "Config.h"
#include "StateList.h"
#include "skapi.h"
#include "Password.h"
#include "PrintSetting.h"


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
	CButton	m_ctrPSNStatic;
	CEdit	m_ctrNet;
	CEdit	m_ctrColorBoxCode;
	CLabel	m_ctrCurrentLine;
	CLabel	m_cCurrentCount;
	CLabel	m_ctrCurrentOrder;
	CLabel	m_ctrCurrentColor;
	CEdit	m_ctrSN;
	CEdit	m_ctrPSN;
	CEdit	m_ctrMAC;
	CEdit	m_ctrBT;
	CEdit	m_ctrIMEI4;
	CEdit	m_ctrIMEI3;
	CEdit	m_ctrIMEI2;
	CEdit	m_ctrIMEI1;
	CStateList	m_state_list;
	CLabel	m_ctrCurrentProduct;
	CString	m_csIMEI1;
	CString	m_csIMEI2;
	CString	m_csIMEI3;
	CString	m_csIMEI4;
	CString	m_csBT;
	CString	m_csMAC;
	CString	m_csPSN;
	CString	m_csSN;
	CString	m_csCurrentProduct;
	CString	m_csCurrentColor;
	CString	m_csCurrentOrder;
	DWORD	m_iFirstKeyTime;
	DWORD	m_iLastKeyTime;
	DWORD	m_iKeyPeriod;
	CString	m_csCurrentLine;
	CString	m_csColorBoxCode;
	CString	m_csNet;
	int		m_iRadioMainSource;
	BOOL	m_bPSNStatic;
	//}}AFX_DATA


// Attributes
public:
	CColorBoxDoc* GetDocument();

public:
	int m_PrintNum;

public:
	void CreateTwoFile();
	void SetMyFont();
	void InsertListInfo(CString state,int imageIndex);
	CString GetCurTimes();
	void SetUIDisableAll();
	bool GetProductList();
	CString VariantToCString(VARIANT   var);   
	void ClearUI();
	BOOL IMEITYPE_0_CheckImei1();
	BOOL IMEITYPE_1_CheckImei1();
	BOOL IMEITYPE_1_CheckImei2();
	BOOL IMEITYPE_2_CheckImei2();
	BOOL IMEITYPE_2_CheckImei3();
	BOOL IMEITYPE_3_CheckImei3();
	BOOL IMEITYPE_3_CheckImei4();
	BOOL SCAN_MAIN_IMEI_CheckImei();
	BOOL SCAN_Check_ColorBoxCode();  //water
	void calculate_15_digit_imei( char *imei_14,char &calculate_digit);
	void PrintLabel();
	BOOL GoToPrint();
	BOOL SginResource();
	BOOL SaveToColorInfo();
	void OnUpdateData(WPARAM wParam, LPARAM lParam);
	void OnSetMyFocus(WPARAM wParam, LPARAM lParam);
    void PlayWarningTone(CString Path);
	BOOL CheckNetCode();

	bool GetProductOrderInfo();
	bool Load_Current_Product_Count();
	void UpdateCount(CString strCount);

public:
	CConfig m_Config;
	CImageList m_imageList;
	CFont m_staticfont;
	int m_iIMEIType;
	int m_iIMEIRangeType;
	CString m_csConfigPath;
	CString m_csLocalPath;
    CString m_csErrorSndPath;    
	CString m_csOkSndPath;
	int     m_iSampleNum;
	int     m_iQCNum;

public:  
	CString m_imei1_start;
	CString m_imei1_end;
	CString m_imei2_start;
	CString m_imei2_end;
	CString m_imei3_start;
	CString m_imei3_end;
	CString m_imei4_start;
	CString m_imei4_end;

	bool    m_bCheckColorBoxCode;
	CString csColorBoxCode;

	CString m_csPSNStatic;

	bool    m_bScanNetCode;
	int     m_iNetCodeLength;
	CString m_csNetCodeHeader;

	CString m_csCurrentCount;

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
	afx_msg void OnChangeEditImei1();
	afx_msg void OnChangeEditImei2();
	afx_msg void OnChangeEditImei3();
	afx_msg void OnChangeEditImei4();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPrint1();
	afx_msg void OnPrint2();
	afx_msg void OnPrint3();
	afx_msg void OnPrint4();
	afx_msg void OnPrint5();
	afx_msg void OnScanMainImeiYes();
	afx_msg void OnScanMainImeiNo();
	afx_msg void OnSetting();
	afx_msg void OnChangeEditColorboxcode();
	afx_msg void OnChangeEditNetcode();
	afx_msg void OnCheckPsnStatic();
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
