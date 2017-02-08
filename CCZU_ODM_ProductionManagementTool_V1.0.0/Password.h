#if !defined(AFX_PASSWORD_H__91AF23EC_44F2_4F78_854E_AF692DBAB38F__INCLUDED_)
#define AFX_PASSWORD_H__91AF23EC_44F2_4F78_854E_AF692DBAB38F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Password.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPassword dialog

class CPassword : public CDialog
{
// Construction
public:
	CPassword(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPassword)
	enum { IDD = IDD_PASSWORD };
	CEdit	m_ctrPassword;
	CEdit	m_ctrUserName;
	CString	m_csUserName;
	CString	m_csPassword;
	//}}AFX_DATA

public:
	int ilevel;   //权限等级控制

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPassword)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPassword)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PASSWORD_H__91AF23EC_44F2_4F78_854E_AF692DBAB38F__INCLUDED_)
