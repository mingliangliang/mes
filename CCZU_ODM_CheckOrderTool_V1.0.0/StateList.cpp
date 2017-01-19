// StateList.cpp : implementation file
//

#include "stdafx.h"
#include "WeighTool.h"
#include "StateList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStateList

CStateList::CStateList()
{
}

CStateList::~CStateList()
{
}


BEGIN_MESSAGE_MAP(CStateList, CListCtrl)
	//{{AFX_MSG_MAP(CStateList)
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclick)
	ON_COMMAND(IDM_LIST_CLEAR, OnListClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStateList message handlers
void CStateList::OnRclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
    NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
    if(pNMListView->iItem != -1)
    {
		DWORD dwPos = GetMessagePos();
		CPoint point( LOWORD(dwPos), HIWORD(dwPos) );
		
		CMenu menu;
		VERIFY( menu.LoadMenu( IDR_LIST_CLEAR ) );
		CMenu* popup = menu.GetSubMenu(0);
		ASSERT( popup != NULL );
		popup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this );
    } 
	
    if(pNMListView->iItem == -1)
    {
		DWORD dwPos = GetMessagePos();
		CPoint point( LOWORD(dwPos), HIWORD(dwPos) );
		
		CMenu menu;
		VERIFY( menu.LoadMenu( IDR_LIST_CLEAR ) );
		CMenu* popup = menu.GetSubMenu(0);
		ASSERT( popup != NULL );
		popup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this );
    }	
	
	*pResult = 0;
}

void CStateList::OnListClear() 
{
	this->DeleteAllItems();	
}
