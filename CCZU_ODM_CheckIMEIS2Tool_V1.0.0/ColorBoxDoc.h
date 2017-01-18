// ColorBoxDoc.h : interface of the CColorBoxDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COLORBOXDOC_H__954BC967_46C0_48AE_8362_ED615061F8A2__INCLUDED_)
#define AFX_COLORBOXDOC_H__954BC967_46C0_48AE_8362_ED615061F8A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CColorBoxDoc : public CDocument
{
protected: // create from serialization only
	CColorBoxDoc();
	DECLARE_DYNCREATE(CColorBoxDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorBoxDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CColorBoxDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CColorBoxDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORBOXDOC_H__954BC967_46C0_48AE_8362_ED615061F8A2__INCLUDED_)
