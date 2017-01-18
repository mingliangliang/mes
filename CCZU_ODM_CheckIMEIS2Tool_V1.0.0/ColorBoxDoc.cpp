// ColorBoxDoc.cpp : implementation of the CColorBoxDoc class
//

#include "stdafx.h"
#include "ColorBox.h"

#include "ColorBoxDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorBoxDoc

IMPLEMENT_DYNCREATE(CColorBoxDoc, CDocument)

BEGIN_MESSAGE_MAP(CColorBoxDoc, CDocument)
	//{{AFX_MSG_MAP(CColorBoxDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorBoxDoc construction/destruction

CColorBoxDoc::CColorBoxDoc()
{
	// TODO: add one-time construction code here

}

CColorBoxDoc::~CColorBoxDoc()
{
}

BOOL CColorBoxDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CColorBoxDoc serialization

void CColorBoxDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CColorBoxDoc diagnostics

#ifdef _DEBUG
void CColorBoxDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CColorBoxDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CColorBoxDoc commands
