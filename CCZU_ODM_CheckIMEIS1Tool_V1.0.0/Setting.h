#if !defined(AFX_SETTING_H__970BDC9B_39E1_441F_B044_77EBB124B09D__INCLUDED_)
#define AFX_SETTING_H__970BDC9B_39E1_441F_B044_77EBB124B09D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Setting.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetting dialog

class CSetting : public CDialog
{
public:
	BOOL VerifyOperator(CString str);
	bool Insert_OperatorSerial(CString str);
	bool Check_OperatorSerial(CString str);
// Construction
public:
	CSetting(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetting)
	enum { IDD = IDD_DLG_CHECKNV };
	CEdit	m_ctrWIFIMAC;
	CEdit	m_ctrBoardVersion;
	CButton	m_ctrCheckBoardVersion;
	CEdit	m_ctrVersion;
	CButton	m_ctrCheckVersion;
	CEdit	m_ctrOperator;
	BOOL	m_bCheckATV;
	BOOL	m_bCheckBattery;
	BOOL	m_bCheckBluetooth;
	BOOL	m_bCheckBTFT;
	BOOL	m_bCheckDTV;
	BOOL	m_bCheckGS;
	BOOL	m_bCheckBoardMMI;
	BOOL	m_bCheckMainMMI;
	BOOL	m_bCheckBoardOperator;
	BOOL	m_bCheckMainOperator;
	BOOL	m_bCheckScreen;
	BOOL	m_bCheckWIFI;
	CString	m_csOperator;
	BOOL	m_bCheckVersion;
	CString	m_csVersion;
	BOOL	m_bCheckResetFactory;
	BOOL	m_bCheckBoardVersion;
	CString	m_csBoardVersion;
    BOOL	m_bCheckWIFIMAC;
	CString	m_csWIFIMAC;
	BOOL	m_bCheckPsCalibration;
	BOOL	m_bCopyFile;
	BOOL	m_bCheckColor;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetting)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetting)
	afx_msg void OnBtnAddOperator();
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckVersion();
	afx_msg void OnCheckBoardVersion();
	afx_msg void OnCheckWifimac();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETTING_H__970BDC9B_39E1_441F_B044_77EBB124B09D__INCLUDED_)

