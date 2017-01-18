; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWeighToolView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "weightool.h"
LastPage=0

ClassCount=12
Class1=CLabel
Class2=CMainFrame
Class3=CPassword
Class4=CSetting
Class5=CSplashWnd
Class6=CStateList
Class7=CWeighToolApp
Class8=CAboutDlg
Class9=CWeighToolDoc
Class10=CWeighToolView

ResourceCount=7
Resource1=IDR_MAINFRAME
Resource2=IDD_LOGIN
Resource3=IDD_ABOUTBOX
Resource4=IDR_LIST_CLEAR
Resource5=IDD_DLG_PASSWORD
Class11=CLogin
Resource6=IDD_WEIGHTOOL_FORM
Class12=CWeighSetting
Resource7=IDD_SETTING

[CLS:CLabel]
Type=0
BaseClass=CStatic
HeaderFile=LABEL.H
ImplementationFile=LABEL.CPP

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CPassword]
Type=0
BaseClass=CDialog
HeaderFile=Password.h
ImplementationFile=Password.cpp
Filter=D
VirtualFilter=dWC
LastObject=CPassword

[CLS:CSetting]
Type=0
BaseClass=CDialog
HeaderFile=Setting.h
ImplementationFile=Setting.cpp

[CLS:CSplashWnd]
Type=0
BaseClass=CWnd
HeaderFile=Splash.h
ImplementationFile=Splash.cpp

[CLS:CStateList]
Type=0
BaseClass=CListCtrl
HeaderFile=StateList.h
ImplementationFile=StateList.cpp

[CLS:CWeighToolApp]
Type=0
BaseClass=CWinApp
HeaderFile=WeighTool.h
ImplementationFile=WeighTool.cpp
LastObject=CWeighToolApp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=WeighTool.cpp
ImplementationFile=WeighTool.cpp
LastObject=CAboutDlg

[CLS:CWeighToolDoc]
Type=0
BaseClass=CDocument
HeaderFile=WeighToolDoc.h
ImplementationFile=WeighToolDoc.cpp

[CLS:CWeighToolView]
Type=0
BaseClass=CFormView
HeaderFile=WeighToolView.h
ImplementationFile=WeighToolView.cpp
LastObject=CWeighToolView
Filter=D
VirtualFilter=VWC

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

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342308480
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342177294
Control5=IDC_STATIC,static,1342181383

[DLG:IDD_WEIGHTOOL_FORM]
Type=1
Class=CWeighToolView
ControlCount=28
Control1=IDC_COMBO_COMPORT,combobox,1344339971
Control2=IDC_EDIT_CARTONNUM,edit,1350635716
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_BTN_START,button,1073807360
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC_CURR,static,1342312961
Control8=IDC_STATIC_UNIT,static,1342308865
Control9=IDC_LIST_STATE,SysListView32,1350633473
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT_LOW_WEGIH,edit,1350633600
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EDIT_HIGH_WEGIH,edit,1350633600
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC_CARTONNUM,static,1342308352
Control16=IDC_STATIC,static,1342177294
Control17=IDC_STATIC_RESULT,static,1342308865
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC_CURRENT_PRODUCT,static,1342308352
Control22=IDC_STATIC_CURRENT_ORDER,static,1342308352
Control23=IDC_STATIC_CURRENT_COLOR,static,1342308352
Control24=IDC_STATIC_CURRENT_COUNT,static,1342308352
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC_CURRENT_LINE,static,1342308352
Control27=IDC_BTN_SETTING,button,1342242816
Control28=IDC_BTN_REFRESH,button,1342242816

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=IDC_BTN_SETTING
Command2=ID_APP_ABOUT
CommandCount=2

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_APP_EXIT
Command2=ID_VIEW_TOOLBAR
Command3=ID_VIEW_STATUS_BAR
Command4=ID_APP_ABOUT
CommandCount=4

[MNU:IDR_LIST_CLEAR]
Type=1
Class=?
Command1=IDM_LIST_CLEAR
CommandCount=1

[ACL:IDR_MAINFRAME]
Type=1
Class=?
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

[DLG:IDD_LOGIN]
Type=1
Class=CLogin
ControlCount=13
Control1=IDC_CHECK_SELECT,button,1342242819
Control2=IDC_COMBO_PRODUCT,combobox,1478557955
Control3=IDC_COMBO_ORDER,combobox,1478557955
Control4=IDC_EDIT_ORDER,edit,1350635716
Control5=IDC_EDIT_LINE,edit,1350635716
Control6=IDOK,button,1342242817
Control7=IDCANCEL,button,1342242816
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352

[CLS:CLogin]
Type=0
HeaderFile=Login.h
ImplementationFile=Login.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_LINE
VirtualFilter=dWC

[DLG:IDD_SETTING]
Type=1
Class=CWeighSetting
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_LOW,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_HIGH,edit,1350631552
Control7=IDC_STATIC,static,1342308352

[CLS:CWeighSetting]
Type=0
HeaderFile=WeighSetting.h
ImplementationFile=WeighSetting.cpp
BaseClass=CDialog
Filter=D
LastObject=CWeighSetting
VirtualFilter=dWC

