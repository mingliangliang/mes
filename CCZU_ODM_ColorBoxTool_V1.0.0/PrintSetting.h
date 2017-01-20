#if !defined(AFX_PRINTSETTING_H__85BD68F8_35AC_40D3_8DC4_34BEBD73C53B__INCLUDED_)
#define AFX_PRINTSETTING_H__85BD68F8_35AC_40D3_8DC4_34BEBD73C53B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PrintSetting.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPrintSetting dialog

class CPrintSetting : public CDialog
{
// Construction
public:
	CPrintSetting(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPrintSetting)
	enum { IDD = IDD_PRINTSETTING };
	CString	m_csOffset;
	CString	m_csColor;
	//}}AFX_DATA

public:
	CString csLocalPath;
	int ioffset11;
	int ioffset12;
	int ioffset21;
	int ioffset22;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintSetting)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPrintSetting)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTSETTING_H__85BD68F8_35AC_40D3_8DC4_34BEBD73C53B__INCLUDED_)
