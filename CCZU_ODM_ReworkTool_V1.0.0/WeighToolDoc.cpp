// WeighToolDoc.cpp : implementation of the CWeighToolDoc class
//

#include "stdafx.h"
#include "WeighTool.h"

#include "WeighToolDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWeighToolDoc

IMPLEMENT_DYNCREATE(CWeighToolDoc, CDocument)

BEGIN_MESSAGE_MAP(CWeighToolDoc, CDocument)
	//{{AFX_MSG_MAP(CWeighToolDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWeighToolDoc construction/destruction

CWeighToolDoc::CWeighToolDoc()
{
	// TODO: add one-time construction code here

}

CWeighToolDoc::~CWeighToolDoc()
{
}

BOOL CWeighToolDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWeighToolDoc serialization

void CWeighToolDoc::Serialize(CArchive& ar)
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
// CWeighToolDoc diagnostics

#ifdef _DEBUG
void CWeighToolDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWeighToolDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWeighToolDoc commands
