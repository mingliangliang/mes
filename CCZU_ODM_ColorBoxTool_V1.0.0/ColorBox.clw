; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CColorBoxView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ColorBox.h"
LastPage=0

ClassCount=8
Class1=CColorBoxApp
Class2=CColorBoxDoc
Class3=CColorBoxView
Class4=CMainFrame

ResourceCount=7
Resource1=IDD_COLORBOX_FORM
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDR_LIST_CLEAR
Resource4=IDD_PASSWORD
Class6=CPassword
Resource5=IDD_ABOUTBOX
Class7=CLogin
Resource6=IDD_LOGIN
Class8=CPrintSetting
Resource7=IDD_PRINTSETTING

[CLS:CColorBoxApp]
Type=0
HeaderFile=ColorBox.h
ImplementationFile=ColorBox.cpp
Filter=N
LastObject=CColorBoxApp

[CLS:CColorBoxDoc]
Type=0
HeaderFile=ColorBoxDoc.h
ImplementationFile=ColorBoxDoc.cpp
Filter=N

[CLS:CColorBoxView]
Type=0
HeaderFile=ColorBoxView.h
ImplementationFile=ColorBoxView.cpp
Filter=D
LastObject=IDC_EDIT_IMEI4
BaseClass=CFormView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=IDM_SCAN_MAIN_IMEI_YES
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=ColorBox.cpp
ImplementationFile=ColorBox.cpp
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
Command1=IDM_PRINT_1
Command2=IDM_PRINT_2
Command3=IDM_PRINT_3
Command4=IDM_PRINT_4
Command5=IDM_PRINT_5
Command6=IDM_MODE_1
Command7=IDM_MODE_2
Command8=IDM_MODE_3
Command9=IDM_SCAN_MAIN_IMEI_YES
Command10=IDM_SCAN_MAIN_IMEI_NO
Command11=ID_APP_EXIT
Command12=ID_VIEW_TOOLBAR
Command13=ID_VIEW_STATUS_BAR
Command14=ID_APP_ABOUT
CommandCount=14

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

[DLG:IDD_COLORBOX_FORM]
Type=1
Class=CColorBoxView
ControlCount=37
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC_CURRENT_PRODUCT,static,1342308864
Control3=IDC_LIST_STATE,SysListView32,1350633473
Control4=IDC_STATIC_IMEI1,static,1342308354
Control5=IDC_EDIT_IMEI1,edit,1350635716
Control6=IDC_STATIC_IMEI2,static,1342308354
Control7=IDC_EDIT_IMEI2,edit,1350635716
Control8=IDC_STATIC_IMEI3,static,1342308354
Control9=IDC_EDIT_IMEI3,edit,1350635716
Control10=IDC_STATIC_IMEI4,static,1342308354
Control11=IDC_EDIT_IMEI4,edit,1350635716
Control12=IDC_STATIC_IMEI5,static,1342308354
Control13=IDC_EDIT_SN,edit,1350631552
Control14=IDC_STATIC_IMEI6,static,1342308354
Control15=IDC_EDIT_PSN,edit,1350631552
Control16=IDC_STATIC_IMEI7,static,1342308354
Control17=IDC_EDIT_BT,edit,1350631552
Control18=IDC_STATIC_IMEI8,static,1342308354
Control19=IDC_EDIT_MAC,edit,1350631552
Control20=IDC_STATIC,button,1342177287
Control21=IDC_STATIC,static,1342177294
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC_CURRENT_ORDER,static,1342308864
Control25=IDC_STATIC_CURRENT_COLOR,static,1342308864
Control26=IDC_STATIC,static,1342308352
Control27=IDC_STATIC_CURRENT_COUNT,static,1342308352
Control28=IDC_STATIC_CURRENT_LINE,static,1342308864
Control29=IDC_STATIC,static,1342308352
Control30=IDC_SETTING,button,1342242816
Control31=IDC_STATIC_IMEI9,static,1342308354
Control32=IDC_EDIT_COLORBOXCODE,edit,1350635716
Control33=IDC_STATIC_IMEI10,static,1342308354
Control34=IDC_EDIT_NETCODE,edit,1350635716
Control35=IDC_RADIO_MAIN_SOURCE,button,1342308361
Control36=IDC_RADIO1,button,1342177289
Control37=IDC_CHECK_PSN_STATIC,button,1342242819

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_APP_ABOUT
CommandCount=1

[MNU:IDR_LIST_CLEAR]
Type=1
Class=?
Command1=IDM_LIST_CLEAR
CommandCount=1

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
LastObject=CPassword
VirtualFilter=dWC

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

[CLS:CLogin]
Type=0
HeaderFile=Login.h
ImplementationFile=Login.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CLogin

[DLG:IDD_PRINTSETTING]
Type=1
Class=CPrintSetting
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_OFFSET,edit,1350635716
Control6=IDC_EDIT_COLOR,edit,1350635716

[CLS:CPrintSetting]
Type=0
HeaderFile=PrintSetting.h
ImplementationFile=PrintSetting.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPrintSetting

