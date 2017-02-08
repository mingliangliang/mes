#if !defined(AFX_ALTERSETTING_H__9180CF18_B8D7_47D1_BDF6_FEF53AC4BB35__INCLUDED_)
#define AFX_ALTERSETTING_H__9180CF18_B8D7_47D1_BDF6_FEF53AC4BB35__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AlterSetting.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAlterSetting dialog

class CAlterSetting : public CDialog
{
// Construction
public:
	CAlterSetting(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAlterSetting)
	enum { IDD = IDD_ALTERSETTING };
	CComboBox	m_ctrComboxProduct;
	CComboBox	m_ctrComboxOrder;
	int		m_iComboxProduct;
	int		m_iComboxOrder;
	//}}AFX_DATA

public:
	CString m_csProduct;
	CString m_csOrder;
	BOOL    m_bCheckPCBA;

public:
	bool GetProductList();
	bool GetProductOrderList();
	CString VariantToCString(VARIANT var);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAlterSetting)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAlterSetting)
	virtual BOOL OnInitDialog();
	afx_msg void OnCloseupComboProduct();
	afx_msg void OnCloseupComboOrder();
	afx_msg void OnDeleteorder();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALTERSETTING_H__9180CF18_B8D7_47D1_BDF6_FEF53AC4BB35__INCLUDED_)
