// PACKDoc.cpp : implementation of the CPACKDoc class
//

#include "stdafx.h"
#include "PACK.h"

#include "PACKDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPACKDoc

IMPLEMENT_DYNCREATE(CPACKDoc, CDocument)

BEGIN_MESSAGE_MAP(CPACKDoc, CDocument)
	//{{AFX_MSG_MAP(CPACKDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPACKDoc construction/destruction

CPACKDoc::CPACKDoc()
{
	// TODO: add one-time construction code here

}

CPACKDoc::~CPACKDoc()
{
}

BOOL CPACKDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPACKDoc serialization

void CPACKDoc::Serialize(CArchive& ar)
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
// CPACKDoc diagnostics

#ifdef _DEBUG
void CPACKDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPACKDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPACKDoc commands
