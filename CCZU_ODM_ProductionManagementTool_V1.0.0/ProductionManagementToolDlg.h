// ProductionManagementToolDlg.h : header file
//

#if !defined(AFX_PRODUCTIONMANAGEMENTTOOLDLG_H__40D7ADB5_644C_48F7_AA2E_9881B54D36E8__INCLUDED_)
#define AFX_PRODUCTIONMANAGEMENTTOOLDLG_H__40D7ADB5_644C_48F7_AA2E_9881B54D36E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IniFile.h"
#include "config.h"
#include "AddUserDlg.h"
#include "ChangePasswordDlg.h"
#include "DeleteUserDlg.h"
#include "AlterSetting.h"
#include "PathLoss.h"

/////////////////////////////////////////////////////////////////////////////
// CProductionManagementToolDlg dialog

class CProductionManagementToolDlg : public CDialog
{
// Construction
public:
	CProductionManagementToolDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CProductionManagementToolDlg)
	enum { IDD = IDD_PRODUCTIONMANAGEMENTTOOL_DIALOG };
	CEdit	m_ctrRework;
	CEdit	m_ctrSNScan;
	CEdit	m_ctrLoginPSW;
	CEdit	m_ctrLoginName;
	CEdit	m_ctrProductionDataQuery;
	CEdit	m_ctrSqlUser;
	CEdit	m_ctrSqlPsw;
	CEdit	m_ctrWriteTool;
	CEdit	m_ctrPallet;
	CEdit	m_ctrPack;
	CEdit	m_ctrCreateProduct;
	CEdit	m_ctrColorBoxWeigh;
	CEdit	m_ctrColorBox;
	CEdit	m_ctrCheckOrder;
	CEdit	m_ctrCheckIMEIS2;
	CEdit	m_ctrCheckIMEIS1;
	CEdit	m_ctrCartonWeigh;
	CEdit	m_ctrProduct;
	CEdit	m_ctrOrder;
	CEdit	m_ctrDatabase;
	CEdit	m_ctrMachine;
	CString	m_csMachine;
	CString	m_csDatabase;
	CString	m_csOrder;
	CString	m_csProduct;
	CString	m_csCartonWeigh;
	CString	m_csCheckIMEIS1;
	CString	m_csCheckIMEIS2;
	CString	m_csCheckOrder;
	CString	m_csColorBox;
	CString	m_csColorBoxWeigh;
	CString	m_csCreateProduct;
	CString	m_csPack;
	CString	m_csPallet;
	CString	m_csWriteTool;
	CString	m_csSqlPsw;
	CString	m_csSqlUser;
	CString	m_csProductionDataQuery;
	CString	m_csLoginName;
	CString	m_csLoginPSW;
	CString	m_csSNScan;
	CString	m_csRework;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProductionManagementToolDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

public:
	CConfig m_Config;

public:
	BOOL GetToolVersion();
	BOOL InputToolVersion();
	BOOL CheckProductName(int iflag);           //iflag---0表示组装包装段
	BOOL CheckOrderName(int iflag);             //iflag---0表示组装包装段
	BOOL CheckSQLRepeat(int iflag);             //iflag---0表示组装包装段
	BOOL InputProductOrder(int iflag);          //iflag---0表示组装包装段
	BOOL ConnectMDBDatabase();
	
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CProductionManagementToolDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCreateOrder();
	afx_msg void OnAdduser();
	afx_msg void OnDeleteuser();
	afx_msg void OnChangepassword();
	afx_msg void OnToolversion();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSql();
	afx_msg void OnChangesqlpassword();
	afx_msg void OnConnectsql();
	afx_msg void OnAltersetting();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRODUCTIONMANAGEMENTTOOLDLG_H__40D7ADB5_644C_48F7_AA2E_9881B54D36E8__INCLUDED_)
