// WeighTool.h : main header file for the WEIGHTOOL application
//

#if !defined(AFX_WEIGHTOOL_H__A9D04A4B_C23A_4C22_8A9D_65C6F11BB15F__INCLUDED_)
#define AFX_WEIGHTOOL_H__A9D04A4B_C23A_4C22_8A9D_65C6F11BB15F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "Config.h"

/////////////////////////////////////////////////////////////////////////////
// CWeighToolApp:
// See WeighTool.cpp for the implementation of this class
//

class CWeighToolApp : public CWinApp
{
public:  //database
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRst;
	CConfig m_Config;
public:
	BOOL InitADO();
	void UninitADO();
	bool ConnectMDBDatabase();
	BOOL CheckToolVersion();//water
	
public:
	CWeighToolApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWeighToolApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CWeighToolApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEIGHTOOL_H__A9D04A4B_C23A_4C22_8A9D_65C6F11BB15F__INCLUDED_)
