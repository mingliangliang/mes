#if !defined(AFX_DELETEUSERDLG_H__30975364_FEDF_499B_B8CC_11609A870F3B__INCLUDED_)
#define AFX_DELETEUSERDLG_H__30975364_FEDF_499B_B8CC_11609A870F3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeleteUserDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeleteUserDlg dialog

class CDeleteUserDlg : public CDialog
{
// Construction
public:
	CDeleteUserDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDeleteUserDlg)
	enum { IDD = IDD_DELETEUSER_DIALOG };
	CEdit	m_ctrNewPsw;
	CEdit	m_ctrUserName;
	CString	m_csUserName;
	CString	m_csNewPsw;
	//}}AFX_DATA

public:
	void Reset();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleteUserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDeleteUserDlg)
	afx_msg void OnConfirm();
	afx_msg void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETEUSERDLG_H__30975364_FEDF_499B_B8CC_11609A870F3B__INCLUDED_)
