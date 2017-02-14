// FullWriteDoc.h : interface of the CFullWriteDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FULLWRITEDOC_H__7668A49C_EA4A_4E49_99B7_486967A7754B__INCLUDED_)
#define AFX_FULLWRITEDOC_H__7668A49C_EA4A_4E49_99B7_486967A7754B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFullWriteDoc : public CDocument
{
protected: // create from serialization only
	CFullWriteDoc();
	DECLARE_DYNCREATE(CFullWriteDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFullWriteDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFullWriteDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFullWriteDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FULLWRITEDOC_H__7668A49C_EA4A_4E49_99B7_486967A7754B__INCLUDED_)
