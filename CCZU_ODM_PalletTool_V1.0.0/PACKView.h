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
#include "skapi.h"
#include "PrintSetting.h"
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
	CButtonST	m_ctrDelete;
	CButtonST	m_ctrClear;
	CButtonST	m_ctrCheck;
	CButtonST	m_ctrSetting;
	CLabel	m_ctrCurrentLine;
	CLabel	m_cCurrentCount;
	CLabel	m_ctrCurrentOrder;
	CLabel	m_ctrCurrentColor;
	CButtonST	m_ctrBtnPrint;
	CButtonST	m_ctrBtnEspeBox;
	CButtonST	m_ctrBtnDiscard;
	CButtonST	m_ctrBtnClose;
	CEdit	m_ctrCarton;
	CLabel	m_ctrCurrentProduct;
	CStateList	m_state_list;
	CMSFlexGrid	m_flex;
	CString	m_csCurrentProduct;
	CString	m_csCarton ;
	CString	m_csCurrentColor;
	CString	m_csCurrentOrder;
	CString	m_csCurrentLine;
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
	CString VariantToCString(VARIANT var);
	void SetRowCol(int rows,int cols);
	void SetNumText(int rows);
	void CurrentAdd(CString& current,UINT step);
	bool Get_Current_Pallet_Name();
	bool ReGet_Current_Pallet_Name();
	void calculate_15_digit_imei( char *imei_14,char &calculate_digit);

	bool CheckCartonName();
	bool InsertDataToSQL_Ex();
	bool UpdateStatusTo2();
	bool GetProductOrderInfo();
	bool Load_Current_Product_Count();
	void UpdateCount(CString strCount);
	void PopMessageBox_Ex();
	void PopMainCarton_Ex(CString strMainCarton);

public:
	CConfig    m_Config;
	CImageList m_imageList;

	//数据库中获取卡通箱信息
	CString m_csCartonNameStatic;  //卡通箱固定位
	int     m_iCartonNameLength;   //卡通箱流水位长度

	//数据库中获取栈板信息
	CString m_csPalletNameStatic;  //栈板固定位
	int     m_iPalletNameLength;   //栈板流水位长度
	int     m_iPalletMaxCount;     //栈板满箱数量

	CString m_csPalletName;
	CString m_csReGet_PalletName;
	CString m_csCurrent_CartonStatic;  //扫描录入的卡通箱号固定位
	CString m_csCurrent_Carton;     //扫描录入的卡通箱号流水位
	CString m_csCurrentCount;      //已生产数量

public:
	BOOL m_showState;
	CString m_csLocalPath;

public:
	CStringArray m_csaCartonName;
	CStringArray m_csaWeigh;

	CString m_csWeigh;

public:  
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
	afx_msg void OnChangeEditCarton();
	afx_msg void OnBtnPrint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBtnSetting();
	afx_msg void OnClickFlex();
	afx_msg void OnBtnCheck();
	afx_msg void OnBtnClear();
	afx_msg void OnBtnDelete();
	DECLARE_EVENTSINK_MAP()
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





















