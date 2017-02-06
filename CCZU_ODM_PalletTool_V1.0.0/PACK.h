// PACK.h : main header file for the PACK application
//

#if !defined(AFX_PACK_H__8041B5D9_D239_48E6_B807_7BB420F74687__INCLUDED_)
#define AFX_PACK_H__8041B5D9_D239_48E6_B807_7BB420F74687__INCLUDED_

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
// CPACKApp:
// See PACK.cpp for the implementation of this class
//

class CPACKApp : public CWinApp
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
	CPACKApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPACKApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPACKApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PACK_H__8041B5D9_D239_48E6_B807_7BB420F74687__INCLUDED_)
