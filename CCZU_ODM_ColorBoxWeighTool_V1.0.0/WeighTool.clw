; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=Csetting
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "weightool.h"
LastPage=0

ClassCount=11
Class1=CLabel
Class2=CLogin
Class3=CMainFrame
Class4=CPassword
Class5=Csetting
Class6=CSplashWnd
Class7=CStateList
Class8=CWeighToolApp
Class9=CAboutDlg
Class10=CWeighToolDoc
Class11=CWeighToolView

ResourceCount=7
Resource1=IDR_MAINFRAME
Resource2=IDD_WEIGHTOOL_FORM
Resource3=IDD_ABOUTBOX
Resource4=IDD_LOGIN
Resource5=IDD_DLG_PASSWORD
Resource6=IDR_LIST_CLEAR
Resource7=IDD_SETTING

[CLS:CLabel]
Type=0
BaseClass=CStatic
HeaderFile=LABEL.H
ImplementationFile=LABEL.CPP

[CLS:CLogin]
Type=0
BaseClass=CDialog
HeaderFile=Login.h
ImplementationFile=Login.cpp

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

[CLS:Csetting]
Type=0
BaseClass=CDialog
HeaderFile=setting.h
ImplementationFile=setting.cpp
LastObject=Csetting
Filter=D
VirtualFilter=dWC

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
Filter=D
VirtualFilter=VWC
LastObject=CWeighToolView

[DLG:IDD_LOGIN]
Type=1
Class=CLogin
ControlCount=13
Control1=IDC_EDIT_ORDER,edit,1350635716
Control2=IDC_EDIT_LINE,edit,1350635716
Control3=IDC_CHECK_SELECT,button,1342242819
Control4=IDC_COMBO_PRODUCT,combobox,1478557955
Control5=IDC_COMBO_ORDER,combobox,1478557955
Control6=IDOK,button,1342242817
Control7=IDCANCEL,button,1342242816
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352

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

[DLG:IDD_SETTING]
Type=1
Class=Csetting
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_WEIGHLOW,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_WEIGHHIGH,edit,1350631552
Control7=IDC_STATIC,static,1342308352

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_WEIGHTOOL_FORM]
Type=1
Class=CWeighToolView
ControlCount=34
Control1=IDC_COMBO_COMPORT,combobox,1344339971
Control2=IDC_EDIT_IMEI1,edit,1350635716
Control3=IDC_EDIT_IMEI2,edit,1350635716
Control4=IDC_EDIT_IMEI3,edit,1350635716
Control5=IDC_EDIT_IMEI4,edit,1350635716
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC_CURR,static,1342312961
Control10=IDC_STATIC_UNIT,static,1342308865
Control11=IDC_LIST_STATE,SysListView32,1350633473
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EDIT_LOW_WEGIH,edit,1350633600
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDIT_HIGH_WEGIH,edit,1350633600
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC_IMEI1,static,1342308352
Control18=IDC_STATIC_IMEI3,static,1342308352
Control19=IDC_STATIC_IMEI4,static,1342308352
Control20=IDC_STATIC_IMEI2,static,1342308352
Control21=IDC_STATIC,static,1342177294
Control22=IDC_STATIC_RESULT,static,1342308865
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC_CURRENT_PRODUCT,static,1342308352
Control27=IDC_STATIC_CURRENT_ORDER,static,1342308352
Control28=IDC_STATIC_CURRENT_COLOR,static,1342308352
Control29=IDC_STATIC_CURRENT_COUNT,static,1342308352
Control30=IDC_BTN_START,button,1073807360
Control31=IDC_STATIC,static,1342308352
Control32=IDC_STATIC_CURRENT_LINE,static,1342308352
Control33=IDC_BTN_SETTING,button,1342242816
Control34=IDC_BTN_REFRESH,button,1342242816

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=IDC_BTN_SETTING
Command2=ID_APP_ABOUT
CommandCount=2

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=IDM_SCAN_MODE_1
Command2=IDM_SCAN_MODE_2
Command3=ID_APP_EXIT
Command4=ID_VIEW_TOOLBAR
Command5=ID_VIEW_STATUS_BAR
Command6=ID_APP_ABOUT
CommandCount=6

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

