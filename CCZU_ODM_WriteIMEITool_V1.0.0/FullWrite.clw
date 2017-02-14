; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFullWriteView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FullWrite.h"
LastPage=0

ClassCount=9
Class1=CFullWriteApp
Class2=CFullWriteDoc
Class3=CFullWriteView
Class4=CMainFrame

ResourceCount=5
Resource1=IDR_MAINFRAME
Resource2=IDD_PASSWORD
Class5=CAboutDlg
Resource3=IDD_FULLWRITE_FORM
Class6=CPassword
Resource4=IDD_ABOUTBOX
Class7=CSetting
Class8=CLogin
Class9=CRepairemodule
Resource5=IDD_LOGIN

[CLS:CFullWriteApp]
Type=0
HeaderFile=FullWrite.h
ImplementationFile=FullWrite.cpp
Filter=N

[CLS:CFullWriteDoc]
Type=0
HeaderFile=FullWriteDoc.h
ImplementationFile=FullWriteDoc.cpp
Filter=N
LastObject=CFullWriteDoc

[CLS:CFullWriteView]
Type=0
HeaderFile=FullWriteView.h
ImplementationFile=FullWriteView.cpp
Filter=D
LastObject=IDC_EDIT_INPUTBCODE
BaseClass=CFormView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=FullWrite.cpp
ImplementationFile=FullWrite.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=IDM_SCAN_MAIN_IMEI
Command2=IDM_SCAN_ALL_IMEI
Command3=IDC_BTN_SAVE
Command4=ID_APP_EXIT
Command5=ID_VIEW_TOOLBAR
Command6=ID_VIEW_STATUS_BAR
Command7=ID_APP_ABOUT
CommandCount=7

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
CommandCount=11

[DLG:IDD_FULLWRITE_FORM]
Type=1
Class=CFullWriteView
ControlCount=32
Control1=IDC_EDIT_INPUTIMEI1,edit,1484853444
Control2=IDC_EDIT_INPUTIMEI2,edit,1484853444
Control3=IDC_EDIT_INPUTIMEI3,edit,1484853444
Control4=IDC_EDIT_INPUTIMEI4,edit,1484853444
Control5=IDC_EDIT_INPUTPSN,edit,1484853444
Control6=IDC_BTN_START,button,1073807361
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,static,1342308352
Control9=IDC_COMBO_COMPORT,combobox,1344340227
Control10=IDC_EDIT_DBPATH,edit,1350633600
Control11=IDC_EDIT_APDBPATH,edit,1350633600
Control12=IDC_BTN_SELECT,button,1342242816
Control13=IDC_BTN_SELECTAP,button,1342242816
Control14=IDC_RICHEDIT_TRACE,RICHEDIT,1353779652
Control15=IDC_STATIC_RESULT,static,1342308353
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,button,1342177287
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342177294
Control22=IDC_STATIC,button,1342177287
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC_CURRENT_COUNT,static,1342308353
Control26=IDC_STATIC_CURRENT_PRODUCT,static,1342308352
Control27=IDC_STATIC_CURRENT_ORDER,static,1342308352
Control28=IDC_STATIC_CURRENT_COLOR,static,1342308352
Control29=IDC_STATIC,static,1342308352
Control30=IDC_STATIC,static,1342308352
Control31=IDC_STATIC,static,1342308352
Control32=IDC_STATIC_CURRENT_LINE,static,1342308352

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=IDC_BTN_SAVE
Command2=ID_EDIT_SETTING
Command3=ID_APP_ABOUT
CommandCount=3

[DLG:IDD_PASSWORD]
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
LastObject=IDC_EDIT_PASSWORD

[CLS:CSetting]
Type=0
HeaderFile=Setting.h
ImplementationFile=Setting.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT_WIFIMAC

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
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352

[CLS:CLogin]
Type=0
HeaderFile=Login.h
ImplementationFile=Login.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CLogin

[CLS:CRepairemodule]
Type=0
HeaderFile=Repairemodule.h
ImplementationFile=Repairemodule.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_CAMERA
VirtualFilter=dWC

