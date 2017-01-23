#if !defined(AFX_ALTERSETTING_H__8120282D_E6A8_4E22_8E54_B4F7FA763131__INCLUDED_)
#define AFX_ALTERSETTING_H__8120282D_E6A8_4E22_8E54_B4F7FA763131__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AlterSetting.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAlterSetting dialog

class CAlterSetting : public CDialog
{
// Construction
public:
	CAlterSetting(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAlterSetting)
	enum { IDD = IDD_ALTERSETTING };
	CEdit	m_ctrVersion;
	CEdit	m_ctrBoardVersion;
	BOOL	m_bCheckBoardVersion;
	BOOL	m_bCheckBTFT;
	BOOL	m_bCheckResetFactory;
	BOOL	m_bCheckVersion;
	CString	m_csBoardVersion;
	CString	m_csVersion;
	double	m_dCartonHighWeigh;
	double	m_dCartonLowWeigh;
	double	m_dColorHighWeigh;
	double	m_dColorLowWeigh;
	int		m_iRadioPlat;
	CComboBox	m_ctrComboxProduct;
	CComboBox	m_ctrComboxOrder;
	int		m_iComboxProduct;
	int		m_iComboxOrder;
	CString	m_color_resource_path2;
	CString	m_pack_resource_path_sub2;
	CString	m_pack_resource_path2;
	CString	m_pallet_resource_path_sub2;
	CString	m_pallet_resource_path2;
	int		m_iCartonNameLength2;
	CString	m_csCartonNameStatic2;
	int		m_iMaxCount2;
	int		m_iPalletMaxCount2;
	int		m_iPalletNameLength2;
	CString	m_csPalletNameStatic2;
	CString	m_color_resource_path_sub2;
	BOOL	m_bCheckScanPSN;
	int		m_iPSNLength;
	BOOL	m_bCheckPSNChk;
	CString	m_csPSNChk;
	BOOL	m_bCheckWrite;
	BOOL	m_bScanNetCode;
	int		m_iNetLength;
	CString	m_csNetHeader;
	//}}AFX_DATA

public:
	CString m_csProduct;
	CString m_csOrder;


public:
	CString VariantToCString(VARIANT var);
	bool GetProductList();
	bool GetProductOrderList();
	bool GetProductOrderSetting();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAlterSetting)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAlterSetting)
	virtual BOOL OnInitDialog();
	afx_msg void OnCloseupComboProduct();
	afx_msg void OnCloseupComboOrder();
	afx_msg void OnCheckVersion();
	afx_msg void OnCheckBoardVersion();
	virtual void OnOK();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBtnColorOpen2();
	afx_msg void OnBtnPackOpen2();
	afx_msg void OnBtnPackOpenSub2();
	afx_msg void OnBtnPalletOpen2();
	afx_msg void OnBtnPalletOpenSub2();
	afx_msg void OnBtnColorOpenSub2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALTERSETTING_H__8120282D_E6A8_4E22_8E54_B4F7FA763131__INCLUDED_)
