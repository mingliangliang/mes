#if !defined(AFX_PATHLOSS_H__0A471D46_BDCD_4061_924F_40734ED538E1__INCLUDED_)
#define AFX_PATHLOSS_H__0A471D46_BDCD_4061_924F_40734ED538E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PathLoss.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPathLoss dialog

class CPathLoss : public CDialog
{
// Construction
public:
	CPathLoss(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPathLoss)
	enum { IDD = IDD_PATHLOSS };
	float	m_fG900Loss1;
	float	m_fG900Loss2;
	float	m_fG900Loss3;
	float	m_fG900Loss4;
	float	m_fG900Loss5;
	float	m_fG900Loss6;
	float	m_fG900Loss7;
	float	m_fG900Loss8;
	float	m_fG900Loss9;
	float	m_fG900Loss10;
	float	m_fG900Loss11;
	float	m_fG900Loss12;
	float	m_fG900Loss13;
	float	m_fG900Loss14;
	float	m_fG900Loss15;
	float	m_fG900Loss16;
	float	m_fG900Loss17;
	float	m_fG900Loss18;
	float	m_fG900Loss19;
	float	m_fG900Loss20;
	float	m_fG1800Loss1;
	float	m_fG1800Loss2;
	float	m_fG1800Loss3;
	float	m_fG1800Loss4;
	float	m_fG1800Loss5;
	float	m_fG1800Loss6;
	float	m_fG1800Loss7;
	float	m_fG1800Loss8;
	float	m_fG1800Loss9;
	float	m_fG1800Loss10;
	float	m_fG1800Loss11;
	float	m_fG1800Loss12;
	float	m_fG1800Loss13;
	float	m_fG1800Loss14;
	float	m_fG1800Loss15;
	float	m_fG1800Loss16;
	float	m_fG1800Loss17;
	float	m_fG1800Loss18;
	float	m_fG1800Loss19;
	float	m_fG1800Loss20;
	float	m_fW850Loss1;
	float	m_fW850Loss2;
	float	m_fW850Loss3;
	float	m_fW850Loss4;
	float	m_fW850Loss5;
	float	m_fW850Loss6;
	float	m_fW850Loss7;
	float	m_fW850Loss8;
	float	m_fW850Loss9;
	float	m_fW850Loss10;
	float	m_fW850Loss11;
	float	m_fW850Loss12;
	float	m_fW850Loss13;
	float	m_fW850Loss14;
	float	m_fW850Loss15;
	float	m_fW850Loss16;
	float	m_fW850Loss17;
	float	m_fW850Loss18;
	float	m_fW850Loss19;
	float	m_fW850Loss20;
	float	m_fW900Loss1;
	float	m_fW900Loss2;
	float	m_fW900Loss3;
	float	m_fW900Loss4;
	float	m_fW900Loss5;
	float	m_fW900Loss6;
	float	m_fW900Loss7;
	float	m_fW900Loss8;
	float	m_fW900Loss9;
	float	m_fW900Loss10;
	float	m_fW900Loss11;
	float	m_fW900Loss12;
	float	m_fW900Loss13;
	float	m_fW900Loss14;
	float	m_fW900Loss15;
	float	m_fW900Loss16;
	float	m_fW900Loss17;
	float	m_fW900Loss18;
	float	m_fW900Loss19;
	float	m_fW900Loss20;
	float	m_fW1900Loss1;
	float	m_fW1900Loss2;
	float	m_fW1900Loss3;
	float	m_fW1900Loss4;
	float	m_fW1900Loss5;
	float	m_fW1900Loss6;
	float	m_fW1900Loss7;
	float	m_fW1900Loss8;
	float	m_fW1900Loss9;
	float	m_fW1900Loss10;
	float	m_fW1900Loss11;
	float	m_fW1900Loss12;
	float	m_fW1900Loss13;
	float	m_fW1900Loss14;
	float	m_fW1900Loss15;
	float	m_fW1900Loss16;
	float	m_fW1900Loss17;
	float	m_fW1900Loss18;
	float	m_fW1900Loss19;
	float	m_fW1900Loss20;
	float	m_fW2100Loss1;
	float	m_fW2100Loss2;
	float	m_fW2100Loss3;
	float	m_fW2100Loss4;
	float	m_fW2100Loss5;
	float	m_fW2100Loss6;
	float	m_fW2100Loss7;
	float	m_fW2100Loss8;
	float	m_fW2100Loss9;
	float	m_fW2100Loss10;
	float	m_fW2100Loss11;
	float	m_fW2100Loss12;
	float	m_fW2100Loss13;
	float	m_fW2100Loss14;
	float	m_fW2100Loss15;
	float	m_fW2100Loss16;
	float	m_fW2100Loss17;
	float	m_fW2100Loss18;
	float	m_fW2100Loss19;
	float	m_fW2100Loss20;
	//}}AFX_DATA

public:
	bool GetPathLoss();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPathLoss)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPathLoss)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PATHLOSS_H__0A471D46_BDCD_4061_924F_40734ED538E1__INCLUDED_)
