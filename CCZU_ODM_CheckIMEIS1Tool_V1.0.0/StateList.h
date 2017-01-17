#if !defined(AFX_STATELIST_H__8AED2776_0A65_4109_95D8_E15A30224003__INCLUDED_)
#define AFX_STATELIST_H__8AED2776_0A65_4109_95D8_E15A30224003__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StateList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStateList window

class CStateList : public CListCtrl
{
// Construction
public:
	CStateList();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStateList)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CStateList();

	// Generated message map functions
protected:
	//{{AFX_MSG(CStateList)
	afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnListClear();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATELIST_H__8AED2776_0A65_4109_95D8_E15A30224003__INCLUDED_)
