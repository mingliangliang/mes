//{{AFX_INCLUDES()
#include "msflexgrid1.h"
//}}AFX_INCLUDES
#if !defined(AFX_QUERY_H__DA7FFA85_7FD0_4A69_9273_1C9560FB7B62__INCLUDED_)
#define AFX_QUERY_H__DA7FFA85_7FD0_4A69_9273_1C9560FB7B62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Query.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQuery dialog

class CQuery : public CDialog
{
// Construction
public:
	CQuery(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CQuery)
	enum { IDD = IDD_QUERY };
	CEdit	m_ctrCarton;
	CButton	m_ctrExport;
	CStatic	m_ctrIMEIStatic;
	CEdit	m_ctrIMEI;
	CString	m_csIMEI;
	CMSFlexGrid	m_QueryFlex;
	CString	m_csOrder;
	CString	m_csProduction;
	CString	m_csScanCarton;
	//}}AFX_DATA

public:
	int m_iOperateType;
	int m_irow;
	int m_icol;

	int m_iIMEIStatus;
	CString m_csCarton;
	float m_fColorWeigh;
	float m_fCartonWeigh;
	CString m_csPallet;
	bool m_iflag1;
	CString AResult;

	CString m_csStation;

	CStringArray csaIMEI;
	CStringArray csaSN;


	//IMEI类型
	int iIMEIType;
	int iIMEIRangeType;

	//IMEI范围
	CString csIMEI1Start;
	CString csIMEI1End;
	CString csIMEI2Start;
	CString csIMEI2End;
	CString csIMEI3Start;
	CString csIMEI3End;
	CString csIMEI4Start;
	CString csIMEI4End;

	//IMEI范围
	CStringArray csaIMEI1Range;
	CStringArray csaIMEI2Range;
	CStringArray csaIMEI3Range;
	CStringArray csaIMEI4Range;

	//未使用的IMEI
	CStringArray csaUnusedIMEI1;
	CStringArray csaUnusedIMEI2;
	CStringArray csaUnusedIMEI3;
	CStringArray csaUnusedIMEI4;

public:
	void SetRowCol(int rows,int cols);
	void SetNumText(int rows,int cols);
	bool GetIMEIData();
	bool GetCartonIMEI();
	bool GetUnusedIMEIData();
	CString VariantToCString(VARIANT var);
	void calculate_15_digit_imei( char *imei_14,char &calculate_digit);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQuery)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CQuery)
	afx_msg void OnChangeEditImei();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnExport();
	afx_msg void OnChangeEditcarton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUERY_H__DA7FFA85_7FD0_4A69_9273_1C9560FB7B62__INCLUDED_)
