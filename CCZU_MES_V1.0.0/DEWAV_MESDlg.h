// DEWAV_MESDlg.h : header file
//

#include "MyButton.h"

#if !defined(AFX_DEWAV_MESDLG_H__629E8A25_5A10_4E6E_830B_D7632A2FC42F__INCLUDED_)
#define AFX_DEWAV_MESDLG_H__629E8A25_5A10_4E6E_830B_D7632A2FC42F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDEWAV_MESDlg dialog

class CDEWAV_MESDlg : public CDialog
{
// Construction
public:
	CDEWAV_MESDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDEWAV_MESDlg)
	enum { IDD = IDD_DEWAV_MES_DIALOG };
	CButton	m_ctrSNScan;
	CButton	m_ctrCheckS3;
	CButton	m_ctrStatic3; 
	CButton	m_ctrRework;
	CButton	m_ctrCleanIMEI;
	CButton	m_ctrCheckOrder;
	CButton	m_ctrStatic2;
	CButton	m_ctrStatic1;
	CButton	m_ctrPallet;
	CButton	m_ctrCouplingTest;
	CButton	m_ctrColorBoxWeigh;
	CButton	m_ctrColorBox;
	CButton	m_ctrCheckS1;
	CButton	m_ctrCheckS2;
	CButton	m_ctrCartonWeigh;
	CButton	m_ctrCarton;
	CButton	m_ctrWriteIMEI;
	CButton	m_ctrQuery;
	CButton	m_ctrCreate;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDEWAV_MESDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

public:
	BOOL CallExe(int iWorkStation);

	CFont m_staticfont;
	CFont m_staticfont1;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDEWAV_MESDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnCreate();
	afx_msg void OnBtnWriteImei();
	afx_msg void OnBtnCouplingtest();
	afx_msg void OnBtnChecksi();
	afx_msg void OnBtnColorbox();
	afx_msg void OnBtnChecks2();
	afx_msg void OnBtnColorboxWeigh();
	afx_msg void OnBtnCarton();
	afx_msg void OnBtnCartonWeigh();
	afx_msg void OnBtnPallet();
	afx_msg void OnBtnQuery();
	afx_msg void OnBtnCheckorder();
	afx_msg void OnBtnRework();
	afx_msg void OnBtnCleanimei();
	afx_msg void OnBtnChecks3();
	afx_msg void OnBtnWriteSnscan();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEWAV_MESDLG_H__629E8A25_5A10_4E6E_830B_D7632A2FC42F__INCLUDED_)
