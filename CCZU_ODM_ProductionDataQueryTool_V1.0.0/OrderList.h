//{{AFX_INCLUDES()
#include "msflexgrid1.h"
//}}AFX_INCLUDES

 
#if !defined(AFX_ORDERLIST_H__B00998FB_4C79_452F_A611_FA8F547E0573__INCLUDED_)
#define AFX_ORDERLIST_H__B00998FB_4C79_452F_A611_FA8F547E0573__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OrderList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// OrderList dialog

class OrderList : public CDialog
{
// Construction
public:
	OrderList(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(OrderList)
	enum { IDD = IDD_ORDERLIST };
	CComboBox	m_ctrCustomer;
	CComboBox	m_ctrComboxType;
	CButton	m_ctrPrint;
	CButton	m_ctrUnusedIMEI;
	CButton	m_ctrIMEIQuery;
	CMSFlexGrid	m_OrderFlex;
	int		m_iComboxType;
	int		m_iCustomer;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(OrderList)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
public:
	void SetRowCol(int rows,int cols);
	void SetNumText(int rows,int cols);
	BOOL GetOrderInfo();
	CString VariantToCString(VARIANT var);
	bool GetColorBoxWeighData();
	bool GetCartonBoxWeighData();
	bool GetShippingData();
	bool GetProductOrderInfo();

public:
	CStringArray csaType;		//机型
	CStringArray csaCustomer;	//客户
	CStringArray csaOrder;		//订单
	CStringArray csaColor;		//颜色
	CStringArray csaTotal;		//订单数量
	CStringArray csaPut;		//累计投入数
	CStringArray csaDone;		//成品完成总数
	CStringArray csaShipping;	//已出货总数
	CStringArray csaNShipping;	//未出货总数
	CStringArray csaNSDone;		//未出货成品数
	CStringArray csaTPut;		//今日投入数
	CStringArray csaTComplete;	//今日组装数
	CStringArray csaTPackage;	//今日包装数
	CStringArray csaUPH;		//组装UPH
	
	int m_iOrderType;// 0：Ongoing、1：Closed、2：No release
	int m_irow;
	int m_icol;
	CString m_csCurrentProduct;
	CString m_csCurrentOrder;

	CStringArray m_csaIMEI1;
	CStringArray m_csaIMEI2;
	CStringArray m_csaIMEI3;
	CStringArray m_csaNetCode;
	CStringArray m_csaSN;
	CStringArray m_csaBoxID;
	CStringArray m_csaPalletID;
	CStringArray m_csaShippingDate;
	CStringArray m_csaCartonNametemp;
	CStringArray m_csaPalletNametemp;
	CStringArray m_csaShippingDatetemp;
	
	
	CStringArray m_csaColorBoxWeigh;
	CStringArray m_csaCartonBoxWeigh;
	
	CStringArray m_csaMACAddr;
	CStringArray m_csaBTAddr; 

	CString	m_csCurrentColor;
	CString m_csCustomerNo;
	CString m_csDWNo;
	CString m_csCartonNameStatic;
	CString m_csPalletNameStatic;
	

	// Implementation
protected:
	
	// Generated message map functions
	//{{AFX_MSG(OrderList)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnBtnUnusedimei();
	afx_msg void OnBtnImeiquery();
	afx_msg void OnBtnPrint();
	afx_msg void OnCloseupComboType();
	afx_msg void OnBtnCarton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ORDERLIST_H__B00998FB_4C79_452F_A611_FA8F547E0573__INCLUDED_)
