// FullWrite.h : main header file for the FULLWRITE application
//

#if !defined(AFX_FULLWRITE_H__C6278869_9CC1_403B_9054_74B82B82BB47__INCLUDED_)
#define AFX_FULLWRITE_H__C6278869_9CC1_403B_9054_74B82B82BB47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "Config.h"
#include "Login.h" //water

/////////////////////////////////////////////////////////////////////////////
// CFullWriteApp:
// See FullWrite.cpp for the implementation of this class
//

class CFullWriteApp : public CWinApp
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
	BOOL CheckToolVersion();//water

public:
	CFullWriteApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFullWriteApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFullWriteApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FULLWRITE_H__C6278869_9CC1_403B_9054_74B82B82BB47__INCLUDED_)
