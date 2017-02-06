#if !defined(AFX_POPMAINCARTON_H__DACE836E_9D56_40F1_94FD_81415BE66845__INCLUDED_)
#define AFX_POPMAINCARTON_H__DACE836E_9D56_40F1_94FD_81415BE66845__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PopMainCarton.h : header file
//
#include "Label.h"
/////////////////////////////////////////////////////////////////////////////
// CPopMainCarton dialog

class CPopMainCarton : public CDialog
{
// Construction
public:
	CPopMainCarton(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPopMainCarton)
	enum { IDD = IDD_DLG_POP_MAINCARTON };
	CLabel	m_cPopMainCarton;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopMainCarton)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	CString m_csMainCarton;
protected:

	// Generated message map functions
	//{{AFX_MSG(CPopMainCarton)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPMAINCARTON_H__DACE836E_9D56_40F1_94FD_81415BE66845__INCLUDED_)
