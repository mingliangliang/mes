// ColorBox.h : main header file for the COLORBOX application
//

#if !defined(AFX_COLORBOX_H__26507711_CEFA_4165_8B62_444C01E5CA64__INCLUDED_)
#define AFX_COLORBOX_H__26507711_CEFA_4165_8B62_444C01E5CA64__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "Config.h"
#include "Login.h" 

/////////////////////////////////////////////////////////////////////////////
// CColorBoxApp:
// See ColorBox.cpp for the implementation of this class
//

class CColorBoxApp : public CWinApp
{
public:  //database
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRst;
	CString InputOrder;
	CString InputProductionLine;
	CConfig m_Config;
public:
	BOOL InitADO();
	void UninitADO();
	bool ConnectMDBDatabase();
	BOOL CheckToolVersion();
public:
	CColorBoxApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorBoxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CColorBoxApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORBOX_H__26507711_CEFA_4165_8B62_444C01E5CA64__INCLUDED_)
