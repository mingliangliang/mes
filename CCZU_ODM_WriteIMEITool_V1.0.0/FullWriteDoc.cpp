// FullWriteDoc.cpp : implementation of the CFullWriteDoc class
//

#include "stdafx.h"
#include "FullWrite.h"

#include "FullWriteDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFullWriteDoc

IMPLEMENT_DYNCREATE(CFullWriteDoc, CDocument)

BEGIN_MESSAGE_MAP(CFullWriteDoc, CDocument)
	//{{AFX_MSG_MAP(CFullWriteDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFullWriteDoc construction/destruction

CFullWriteDoc::CFullWriteDoc()
{
	// TODO: add one-time construction code here

}

CFullWriteDoc::~CFullWriteDoc()
{
}

BOOL CFullWriteDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFullWriteDoc serialization

void CFullWriteDoc::Serialize(CArchive& ar)
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
// CFullWriteDoc diagnostics

#ifdef _DEBUG
void CFullWriteDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFullWriteDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFullWriteDoc commands
