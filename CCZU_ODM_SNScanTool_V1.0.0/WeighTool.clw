; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWeighToolView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "WeighTool.h"
LastPage=0

ClassCount=9
Class1=CWeighToolApp
Class2=CWeighToolDoc
Class3=CWeighToolView
Class4=CMainFrame

ResourceCount=6
Resource1=IDR_MAINFRAME
Resource2=IDD_WEIGHTOOL_FORM
Class5=CAboutDlg
Class6=CStateList
Resource3=IDD_DLG_PASSWORD
Resource4=IDR_LIST_CLEAR
Class7=CPassword
Class8=CSetting
Resource5=IDD_ABOUTBOX
Class9=CLogin
Resource6=IDD_LOGIN

[CLS:CWeighToolApp]
Type=0
HeaderFile=WeighTool.h
ImplementationFile=WeighTool.cpp
Filter=N

[CLS:CWeighToolDoc]
Type=0
HeaderFile=WeighToolDoc.h
ImplementationFile=WeighToolDoc.cpp
Filter=N

[CLS:CWeighToolView]
Type=0
HeaderFile=WeighToolView.h
ImplementationFile=WeighToolView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=CWeighToolView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=WeighTool.cpp
ImplementationFile=WeighTool.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=6
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342177294
Control6=IDC_STATIC,static,1342181383

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_APP_EXIT
Command2=ID_VIEW_TOOLBAR
Command3=ID_VIEW_STATUS_BAR
Command4=ID_APP_ABOUT
CommandCount=4

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_WEIGHTOOL_FORM]
Type=1
Class=CWeighToolView
ControlCount=14
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,button,1342177287
Control3=IDC_LIST_STATE,SysListView32,1350633473
Control4=IDC_STATIC_PALLET,static,1342308352
Control5=IDC_EDIT_PALLET,edit,1350635716
Control6=IDC_STATIC,static,1342177294
Control7=IDC_STATIC_RESULT,static,1342308865
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC_CURRENT_PRODUCT,static,1342308352
Control12=IDC_STATIC_CURRENT_ORDER,static,1342308352
Control13=IDC_STATIC_CURRENT_COLOR,static,1342308352
Control14=IDC_STATIC_CURRENT_COUNT,static,1342308353

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_APP_ABOUT
CommandCount=1

[CLS:CStateList]
Type=0
HeaderFile=StateList.h
ImplementationFile=StateList.cpp
BaseClass=CListCtrl
Filter=W

[MNU:IDR_LIST_CLEAR]
Type=1
Class=?
Command1=IDM_LIST_CLEAR
CommandCount=1

[DLG:IDD_DLG_PASSWORD]
Type=1
Class=CPassword
ControlCount=6
Control1=IDC_EDIT_USERNAME,edit,1350631552
Control2=IDC_EDIT_PASSWORD,edit,1350631584
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[CLS:CPassword]
Type=0
HeaderFile=Password.h
ImplementationFile=Password.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:CSetting]
Type=0
HeaderFile=Setting.h
ImplementationFile=Setting.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:CLogin]
Type=0
HeaderFile=Login.h
ImplementationFile=Login.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CLogin

[DLG:IDD_LOGIN]
Type=1
Class=CLogin
ControlCount=11
Control1=IDC_EDIT_ORDER,edit,1350635716
Control2=IDC_CHECK_SELECT,button,1342242819
Control3=IDC_COMBO_PRODUCT,combobox,1478557955
Control4=IDC_COMBO_ORDER,combobox,1478557955
Control5=IDOK,button,1342242817
Control6=IDCANCEL,button,1342242816
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352

