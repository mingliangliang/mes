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
	CLabel	m_cCurrentCount;
	CEdit	m_ctrPallet;
	CLabel	m_ctrCurrentProduct;
	CLabel	m_ctrCurrentOrder;
	CLabel	m_ctrCurrentColor;
	CLabel	m_cResult;
	CStateList	m_state_list;
	CString	m_csCurrentColor;
	CString	m_csCurrentOrder;
	CString	m_csCurrentProduct;
	CString	m_csPallet;
	//}}AFX_DATA

// Attributes
public:
	CWeighToolDoc* GetDocument();


public:
	CImageList m_imageList;
	CFont m_staticfont;
	CFont m_staticfont1;
	CConfig m_Config;

	CString m_csCurrentCount;
	CString m_csSNStatic;

public:
	void SetMyFont();
	void InsertListInfo(CString state,int imageIndex);
	CString GetCurTimes();
	void SetUIDisableAll();
	CString VariantToCString(VARIANT var);   
	void ClearUI();
	void ShowCalResult(int state);
	bool GetProductOrderInfo();
	bool CheckSN();
	BOOL verifySN(CString str);
	bool SaveSN();
	void UpdateCount(CString strCount);
	bool Load_Current_Product_Count();
	CString Decrypt(CString cs); // ½âÃÜº¯Êý

// Operations
public:

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
	afx_msg void OnChangeEditPallet();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
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
