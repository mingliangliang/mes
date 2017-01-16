#if !defined(AFX_WEIGHSETTING_H__35C65090_9AE8_4F40_928C_B73FC20E2A61__INCLUDED_)
#define AFX_WEIGHSETTING_H__35C65090_9AE8_4F40_928C_B73FC20E2A61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WeighSetting.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWeighSetting dialog

class CWeighSetting : public CDialog
{
// Construction
public:
	CWeighSetting(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWeighSetting)
	enum { IDD = IDD_SETTING };
	double	m_dHigh;
	double	m_dLow;
	//}}AFX_DATA

public:
	CString m_csProduct;
	CString m_csOrder;

public:
	bool GetWeighRange();


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWeighSetting)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWeighSetting)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEIGHSETTING_H__35C65090_9AE8_4F40_928C_B73FC20E2A61__INCLUDED_)
