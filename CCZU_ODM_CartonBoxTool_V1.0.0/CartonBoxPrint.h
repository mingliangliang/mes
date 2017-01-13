#if !defined(AFX_CARTONBOXPRINT_H__68E3FB33_F5AC_4274_825A_D15958DDAF9A__INCLUDED_)
#define AFX_CARTONBOXPRINT_H__68E3FB33_F5AC_4274_825A_D15958DDAF9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CartonBoxPrint.h : header file
//
#include "BtnST.h"
#include "Label.h"
/////////////////////////////////////////////////////////////////////////////
// CCartonBoxPrint dialog

class CCartonBoxPrint : public CDialog
{
public:
	CString VariantToCString(VARIANT   var);
	void ResetControl();
	BOOL LoadSign();
	bool CheckCartonName();
	bool GetDataInfo();
	BOOL ReplaceResource();
	BOOL GoToPrint();
	char Calculate_Random();
	bool CheckLabelCount();
	bool UpdateLabelCount();

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

	CString csLocalPathtemp;

	CString m_csBatchNo;
	CString m_csCustomerNo;
	CString m_csaShippingDate;
	CString csCurrentLine;
	CString m_csCartonNameStatic;
	CString m_csCartonName;
	CString m_csConfigPath;
	int     m_iMaxCount;
	int     m_iLabelCount;

	CString csPSNStatic;
	int     bPSNStatic;

// Construction
public:
	CCartonBoxPrint(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCartonBoxPrint)
	enum { IDD = IDD_CARTONBOX_PRINT };
	CButton	m_ctrRadioCurrentCarton;
	CButton	m_ctrRadioSpecificCarton;
	CLabel	m_ctrCurrentColor;
	CLabel	m_ctrCurrentOrder;
	CLabel	m_ctrCurrentProduct;
	CButtonST	m_btn_print;
	CString	m_replace_R1;
	CString	m_replace_R10;
	CString	m_replace_R11;
	CString	m_replace_R12;
	CString	m_replace_R13;
	CString	m_replace_R2;
	CString	m_replace_R3;
	CString	m_replace_R4;
	CString	m_replace_R5;
	CString	m_replace_R6;
	CString	m_replace_R7;
	CString	m_replace_R8;
	CString	m_replace_R9;
	CString	m_sreplace_R1;
	CString	m_sreplace_R10;
	CString	m_sreplace_R11;
	CString	m_sreplace_R12;
	CString	m_sreplace_R13;
	CString	m_sreplace_R2;
	CString	m_sreplace_R3;
	CString	m_sreplace_R4;
	CString	m_sreplace_R5;
	CString	m_sreplace_R6;
	CString	m_sreplace_R7;
	CString	m_sreplace_R8;
	CString	m_sreplace_R9;
	CString	m_csCurrentProduct;
	CString	m_csStaticCartonName;
	CString	m_csCurrentOrder;
	CString	m_csCurrentColor;
	int		m_iRadioMainSource;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCartonBoxPrint)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCartonBoxPrint)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnPrintLable();
	afx_msg void OnRadioCurrentCarton();
	afx_msg void OnRadioSpecificCarton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARTONBOXPRINT_H__68E3FB33_F5AC_4274_825A_D15958DDAF9A__INCLUDED_)
