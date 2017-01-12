// DEWAV_MES.h : main header file for the DEWAV_MES application
//

#if !defined(AFX_DEWAV_MES_H__9F5DBD23_C7B7_4834_9157_84A5FE26FAD4__INCLUDED_)
#define AFX_DEWAV_MES_H__9F5DBD23_C7B7_4834_9157_84A5FE26FAD4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDEWAV_MESApp:
// See DEWAV_MES.cpp for the implementation of this class
//

class CDEWAV_MESApp : public CWinApp
{
public:
	CDEWAV_MESApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDEWAV_MESApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDEWAV_MESApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEWAV_MES_H__9F5DBD23_C7B7_4834_9157_84A5FE26FAD4__INCLUDED_)
