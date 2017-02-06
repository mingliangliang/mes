#if !defined(AFX_POPMESSAGEBOX_H__B52D0BDB_6C06_478C_BB96_30477461DF61__INCLUDED_)
#define AFX_POPMESSAGEBOX_H__B52D0BDB_6C06_478C_BB96_30477461DF61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PopMessageBox.h : header file
//
#include "Label.h"
/////////////////////////////////////////////////////////////////////////////
// CPopMessageBox dialog

class CPopMessageBox : public CDialog
{
// Construction
public:
	CPopMessageBox(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPopMessageBox)
	enum { IDD = IDD_POP_MESSAGEBOX };
	CLabel	m_cPopMessageBoxTip;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopMessageBox)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPopMessageBox)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPMESSAGEBOX_H__B52D0BDB_6C06_478C_BB96_30477461DF61__INCLUDED_)
