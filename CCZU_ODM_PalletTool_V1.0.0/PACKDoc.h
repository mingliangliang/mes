// PACKDoc.h : interface of the CPACKDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PACKDOC_H__9B5E3464_9EE5_4087_AF62_B588DE5841AD__INCLUDED_)
#define AFX_PACKDOC_H__9B5E3464_9EE5_4087_AF62_B588DE5841AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPACKDoc : public CDocument
{
protected: // create from serialization only
	CPACKDoc();
	DECLARE_DYNCREATE(CPACKDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPACKDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPACKDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPACKDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PACKDOC_H__9B5E3464_9EE5_4087_AF62_B588DE5841AD__INCLUDED_)
