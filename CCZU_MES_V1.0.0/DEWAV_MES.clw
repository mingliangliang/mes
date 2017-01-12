; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDEWAV_MESDlg
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DEWAV_MES.h"

ClassCount=4
Class1=CDEWAV_MESApp
Class2=CDEWAV_MESDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CMyButton
Resource3=IDD_DEWAV_MES_DIALOG

[CLS:CDEWAV_MESApp]
Type=0
HeaderFile=DEWAV_MES.h
ImplementationFile=DEWAV_MES.cpp
Filter=N

[CLS:CDEWAV_MESDlg]
Type=0
HeaderFile=DEWAV_MESDlg.h
ImplementationFile=DEWAV_MESDlg.cpp
Filter=D
LastObject=IDC_BTN_CREATE
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=DEWAV_MESDlg.h
ImplementationFile=DEWAV_MESDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC_CAPTION,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_DEWAV_MES_DIALOG]
Type=1
Class=CDEWAV_MESDlg
ControlCount=21
Control1=IDC_BTN_CREATE,button,1342254848
Control2=IDC_BTN_WRITE_IMEI,button,1342251008
Control3=IDC_BTN_COUPLINGTEST,button,1208033280
Control4=IDC_BTN_CHECKSI,button,1342251008
Control5=IDC_BTN_COLORBOX,button,1342251008
Control6=IDC_BTN_CHECKS2,button,1342251008
Control7=IDC_BTN_COLORBOX_WEIGH,button,1342251008
Control8=IDC_BTN_CARTON,button,1342251008
Control9=IDC_BTN_CARTON_WEIGH,button,1342251008
Control10=IDC_BTN_PALLET,button,1342251008
Control11=IDC_BTN_QUERY,button,1342251008
Control12=IDC_STATIC1,button,1342177287
Control13=IDC_STATIC,static,1342181390
Control14=IDC_STATIC,button,1342177287
Control15=IDC_STATIC2,button,1342177287
Control16=IDC_BTN_CHECKORDER,button,1342251008
Control17=IDC_BTN_REWORK,button,1342251008
Control18=IDC_BTN_CLEANIMEI,button,1208033280
Control19=IDC_STATIC3,button,1342177287
Control20=IDC_BTN_CHECKS3,button,1208033280
Control21=IDC_BTN_WRITE_SNSCAN,button,1342251008

[CLS:CMyButton]
Type=0
HeaderFile=MyButton.h
ImplementationFile=MyButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC
LastObject=CMyButton

