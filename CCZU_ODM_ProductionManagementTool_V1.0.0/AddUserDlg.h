#if !defined(AFX_ADDUSERDLG_H__5E6CD480_D75B_48F1_9D5A_A1F59347FA68__INCLUDED_)
#define AFX_ADDUSERDLG_H__5E6CD480_D75B_48F1_9D5A_A1F59347FA68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddUserDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddUserDlg dialog

class CAddUserDlg : public CDialog
{
// Construction
public:
	CAddUserDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddUserDlg)
	enum { IDD = IDD_ADDUSER_DIALOG };
	CComboBox	m_ctrComboPermission;
	CEdit	m_ctrConfirmPsw;
	CEdit	m_ctrNewPsw;
	CEdit	m_ctrUserName;
	CString	m_csUserName;
	CString	m_csNewPsw;
	CString	m_csConfirmPsw;
	int		m_iComboPermission;
	BOOL	m_bAll;
	BOOL	m_bCartonWeigh;
	BOOL	m_bCheckIMEIS1;
	BOOL	m_bCheckIMEIS2;
	BOOL	m_bCheckOrder;
	BOOL	m_bColorBox;
	BOOL	m_bColorWeigh;
	BOOL	m_bCreateProduct;
	BOOL	m_bDataQuery;
	BOOL	m_bPack;
	BOOL	m_bPallet;
	BOOL	m_bWriteIMEI;
	BOOL	m_bSNScan;
	BOOL	m_bRework;
	//}}AFX_DATA
	
public:
	void Reset();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddUserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddUserDlg)
	afx_msg void OnConfirm();
	afx_msg void OnCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDUSERDLG_H__5E6CD480_D75B_48F1_9D5A_A1F59347FA68__INCLUDED_)
