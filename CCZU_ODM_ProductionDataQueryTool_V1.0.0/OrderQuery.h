#if !defined(AFX_ORDERQUERY_H__915E709D_4C86_4243_B1FC_F8B96B5389E3__INCLUDED_)
#define AFX_ORDERQUERY_H__915E709D_4C86_4243_B1FC_F8B96B5389E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OrderQuery.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COrderQuery dialog

class COrderQuery : public CDialog
{
// Construction
public:
	COrderQuery(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COrderQuery)
	enum { IDD = IDD_ORDERQUERY };
	CString	m_csProductName;
	CString	m_csOrderName;
	CString	m_csCartonNameBegin;
	CString	m_csCartonNameEnd;
	CString	m_csCartonNameLength;
	CString	m_csCartonMaxCount;
	CString	m_csCartonNameStatic;
	CString	m_csColor;
	CString	m_csPlannedOutput;
	CString	m_csPalletNameStatic;
	CString	m_csPalletMaxCount;
	CString	m_csPalletNameLength;
	CString	m_csIMEIType;
	CString	m_csIMEIRangeType;
	CString	m_csIMEI1_STR;
	CString	m_csIMEI1_END;
	CString	m_csIMEI2_END;
	CString	m_csIMEI3_END;
	CString	m_csIMEI4_END;
	CString	m_csIMEI2_STR;
	CString	m_csIMEI3_STR;
	CString	m_csIMEI4_STR;
	int		m_iPlat;
	BOOL	m_bPSNCHK;
	BOOL	m_bScanPSN;
	CString	m_csPSN_CHK;
	CString	m_csPSNLen;
	BOOL	m_bBoardVer;
	BOOL	m_bBTFT;
	BOOL	m_bResetFactory;
	BOOL	m_bVer;
	CString	m_csBoardVer;
	CString	m_csVer;
	CString	m_csCartonHighWeigh;
	CString	m_csCartonLowWeigh;
	CString	m_csColorHighWeigh;
	CString	m_csColorLowWeigh;
	BOOL	m_bScanNet;
	CString	m_csNetHeader;
	CString	m_csNetLength;
	//}}AFX_DATA

public:
	BOOL GetProductOrderInfo();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COrderQuery)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COrderQuery)
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ORDERQUERY_H__915E709D_4C86_4243_B1FC_F8B96B5389E3__INCLUDED_)
