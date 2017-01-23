// CreateProduct.h : main header file for the CREATEPRODUCT application
//

#if !defined(AFX_CREATEPRODUCT_H__3F394552_612C_484D_81A5_6728CD3DAB2E__INCLUDED_)
#define AFX_CREATEPRODUCT_H__3F394552_612C_484D_81A5_6728CD3DAB2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "Config.h"

/////////////////////////////////////////////////////////////////////////////
// CCreateProductApp:
// See CreateProduct.cpp for the implementation of this class
//

class CCreateProductApp : public CWinApp
{
public:
	CCreateProductApp();
public:  //database
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRst;
	CConfig m_Config;
	int m_istatus;
	CString m_csCreateUser;
	CString m_csReleaseUser;
public:
	BOOL InitADO();
	void UninitADO();
	bool ConnectMDBDatabase();
	BOOL CheckToolVersion();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateProductApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreateProductApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEPRODUCT_H__3F394552_612C_484D_81A5_6728CD3DAB2E__INCLUDED_)
