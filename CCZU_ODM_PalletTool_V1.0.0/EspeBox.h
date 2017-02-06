#if !defined(AFX_ESPEBOX_H__11B36F05_AA19_4A8D_80CA_8934F9A0B575__INCLUDED_)
#define AFX_ESPEBOX_H__11B36F05_AA19_4A8D_80CA_8934F9A0B575__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EspeBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEspeBox dialog

class CEspeBox : public CDialog
{
// Construction
public:
	CEspeBox(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEspeBox)
	enum { IDD = IDD_ESPE_BOX };
	CEdit	m_ctrEspeBoxName;
	CString	m_csEspeBoxName;
	CString	m_csPalletNameStatic;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEspeBox)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEspeBox)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ESPEBOX_H__11B36F05_AA19_4A8D_80CA_8934F9A0B575__INCLUDED_)
