//{{AFX_INCLUDES()
#include "msflexgrid.h"
//}}AFX_INCLUDES
#if !defined(AFX_ORDERRELEASE_H__CE3B3119_FB07_4DC3_9621_2521DDCF5779__INCLUDED_)
#define AFX_ORDERRELEASE_H__CE3B3119_FB07_4DC3_9621_2521DDCF5779__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OrderRelease.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// COrderRelease dialog

class COrderRelease : public CDialog
{
// Construction
public:
	COrderRelease(CWnd* pParent = NULL);   // standard constructor

public:
// Dialog Data
	//{{AFX_DATA(COrderRelease)
	enum { IDD = IDD_ORDERRELEASE };
	CComboBox	m_ctrProductName;
	CComboBox	m_ctrOrderName;
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
	CString	m_csSNStatic;
	BOOL	m_bScanPSN;
	BOOL	m_bWrite;
	CString	m_csPSNLen;
	BOOL	m_bPSNCHK;
	CString	m_csPSN_CHK;
	BOOL	m_bScanNet;
	CString	m_csNetLength;
	CString	m_csNetHeader;
	CString	m_csCustomer;
	//}}AFX_DATA

public:
	BOOL GetProductList();
	BOOL GetOrderList();
	BOOL GetProductOrderInfo();
	void CleanUI();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COrderRelease)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COrderRelease)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnCloseupComboProduction();
	afx_msg void OnCloseupComboOrder();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ORDERRELEASE_H__CE3B3119_FB07_4DC3_9621_2521DDCF5779__INCLUDED_)
