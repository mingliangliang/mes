// ProductionManagementTool.h : main header file for the PRODUCTIONMANAGEMENTTOOL application
//

#if !defined(AFX_PRODUCTIONMANAGEMENTTOOL_H__71124363_FE7E_4680_A202_4BCA85E4476E__INCLUDED_)
#define AFX_PRODUCTIONMANAGEMENTTOOL_H__71124363_FE7E_4680_A202_4BCA85E4476E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CProductionManagementToolApp:
// See ProductionManagementTool.cpp for the implementation of this class
//

class CProductionManagementToolApp : public CWinApp
{
public:
	CProductionManagementToolApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProductionManagementToolApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

public:
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRst;

public:
	BOOL InitADO();
	void UninitADO();

// Implementation

	//{{AFX_MSG(CProductionManagementToolApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRODUCTIONMANAGEMENTTOOL_H__71124363_FE7E_4680_A202_4BCA85E4476E__INCLUDED_)
