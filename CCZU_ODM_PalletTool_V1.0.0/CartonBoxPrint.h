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
	bool CheckPalletName();
	bool GetDataInfo();
	BOOL ReplaceResource();
	BOOL GoToPrint();
	char Calculate_Random();

public:
	CStringArray m_csaCartonName;
	CStringArray m_csaWeigh;

	CString csCurrentProduct;
	CString	csCurrentOrder;
	CString	csPalletNameStatic;
	CString	csPalletName;
	CString	csCartonNameStatic;
	int iPalletMaxCount;
	int iPalletNameLength;

	CString csLocalPathtemp;

	CString m_csConfigPath;
	CString csProductionLine;

// Construction
public:
	CCartonBoxPrint(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCartonBoxPrint)
	enum { IDD = IDD_CARTONBOX_PRINT };
	CComboBox	m_ctrComboxSource;
	CButton	m_ctrMainSource;
	CButton	m_ctrRADIO1;
	CButtonST	m_btn_print;
	CLabel	m_ctrPalletName;
	CLabel	m_ctrPalletNameStatic;
	CLabel	m_ctrCurrentOrder;
	CLabel	m_ctrCurrentProduct;
	CString	m_replace_R1;
	CString	m_csCurrentProduct;
	CString	m_csCurrentOrder;
	CString	m_csPalletNameStatic;
	CString	m_csPalletName;
	int		m_iRadioMainSource;
	int		m_iComboxSource;
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
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnRadio1();
	afx_msg void OnRadioMainSource();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARTONBOXPRINT_H__68E3FB33_F5AC_4274_825A_D15958DDAF9A__INCLUDED_)
