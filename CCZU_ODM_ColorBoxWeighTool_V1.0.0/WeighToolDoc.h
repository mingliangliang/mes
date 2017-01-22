// WeighToolDoc.h : interface of the CWeighToolDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WEIGHTOOLDOC_H__439D8017_13E4_47AA_918A_3D1A958F0146__INCLUDED_)
#define AFX_WEIGHTOOLDOC_H__439D8017_13E4_47AA_918A_3D1A958F0146__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWeighToolDoc : public CDocument
{
protected: // create from serialization only
	CWeighToolDoc();
	DECLARE_DYNCREATE(CWeighToolDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWeighToolDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWeighToolDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWeighToolDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEIGHTOOLDOC_H__439D8017_13E4_47AA_918A_3D1A958F0146__INCLUDED_)
