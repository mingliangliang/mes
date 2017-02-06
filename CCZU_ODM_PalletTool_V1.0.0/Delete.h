#if !defined(AFX_DELETE_H__E9985C57_63DC_4E94_A87E_F63A2200C241__INCLUDED_)
#define AFX_DELETE_H__E9985C57_63DC_4E94_A87E_F63A2200C241__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Delete.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDelete dialog

class CDelete : public CDialog
{
// Construction
public:
	CDelete(CWnd* pParent = NULL);   // standard constructor

public:
	CString m_csCurrentProduct;
	CString m_csCurrentOrder;
	CString m_csPalletName;
	CString m_csPalletStatic;

// Dialog Data
	//{{AFX_DATA(CDelete)
	enum { IDD = IDD_DELETE };
	CEdit	m_ctrCarton;
	int		m_iComboType;
	CString	m_csCarton;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDelete)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDelete)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioSingle();
	afx_msg void OnRadioWhole();
	afx_msg void OnChangeEditCartonDel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETE_H__E9985C57_63DC_4E94_A87E_F63A2200C241__INCLUDED_)
