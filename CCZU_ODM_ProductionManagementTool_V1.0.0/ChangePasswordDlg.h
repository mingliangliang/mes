#if !defined(AFX_CHANGEPASSWORDDLG_H__352FD880_C573_4A3E_9CA5_2066A6F30558__INCLUDED_)
#define AFX_CHANGEPASSWORDDLG_H__352FD880_C573_4A3E_9CA5_2066A6F30558__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChangePasswordDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChangePasswordDlg dialog

class CChangePasswordDlg : public CDialog
{
// Construction
public:
	CChangePasswordDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChangePasswordDlg)
	enum { IDD = IDD_CHANGEPASSWORD_DIALOG };
	CEdit	m_ctrUserName;
	CEdit	m_ctrNewPsw;
	CEdit	m_ctrCurPsw;
	CEdit	m_ctrConfirmPsw;
	CString	m_csConfirmPsw;
	CString	m_csCurPsw;
	CString	m_csNewPsw;
	CString	m_csUserName;
	//}}AFX_DATA

public:
	void Reset();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangePasswordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChangePasswordDlg)
	afx_msg void OnConfirm();
	afx_msg void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGEPASSWORDDLG_H__352FD880_C573_4A3E_9CA5_2066A6F30558__INCLUDED_)
