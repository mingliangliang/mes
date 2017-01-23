#if !defined(AFX_MAIN_H__0CF60B87_416D_43E6_8663_AFE6AC75F655__INCLUDED_)
#define AFX_MAIN_H__0CF60B87_416D_43E6_8663_AFE6AC75F655__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Main.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMain dialog

class CMain : public CDialog
{
// Construction
public:
	CMain(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMain)
	enum { IDD = IDD_MAIN };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMain)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMain)
	afx_msg void OnCreate();
	afx_msg void OnRelease();
	afx_msg void OnAltersetting();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAIN_H__0CF60B87_416D_43E6_8663_AFE6AC75F655__INCLUDED_)
