#if !defined(AFX_SETTING_H__59EB10E6_2523_4FC9_8570_98586EFE8AFC__INCLUDED_)
#define AFX_SETTING_H__59EB10E6_2523_4FC9_8570_98586EFE8AFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// setting.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Csetting dialog

class Csetting : public CDialog
{
// Construction
public:
	Csetting(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Csetting)
	enum { IDD = IDD_SETTING };
	double	m_dHigh;
	double	m_dLow;
	//}}AFX_DATA

public:
	CString m_csProduct;
	CString m_csOrder;

public:
	bool GetWeighRange();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Csetting)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Csetting)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETTING_H__59EB10E6_2523_4FC9_8570_98586EFE8AFC__INCLUDED_)
