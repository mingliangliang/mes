; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDelete
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PACK.h"
LastPage=0

ClassCount=13
Class1=CPACKApp
Class2=CPACKDoc
Class3=CPACKView
Class4=CMainFrame

ResourceCount=12
Resource1=IDD_ESPE_BOX
Resource2=IDD_LOGIN
Class5=CAboutDlg
Resource3=IDD_POP_MESSAGEBOX
Resource4=IDD_CARTONBOX_PRINT
Class6=CEspeBox
Resource5=IDR_MAINFRAME
Class7=CCartonBoxPrint
Resource6=IDR_LIST_CLEAR
Class8=CPassword
Resource7=IDD_DLG_PASSWORD
Class9=CPopMessageBox
Resource8=IDD_PACK_FORM
Class10=CPopMainCarton
Resource9=IDD_PRINTSETTING
Class11=CLogin
Resource10=IDD_ABOUTBOX
Class12=CPrintSetting
Resource11=IDD_DLG_POP_MAINCARTON
Class13=CDelete
Resource12=IDD_DELETE

[CLS:CPACKApp]
Type=0
HeaderFile=PACK.h
ImplementationFile=PACK.cpp
Filter=N

[CLS:CPACKDoc]
Type=0
HeaderFile=PACKDoc.h
ImplementationFile=PACKDoc.cpp
Filter=N

[CLS:CPACKView]
Type=0
HeaderFile=PACKView.h
ImplementationFile=PACKView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=CPACKView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=PACK.cpp
ImplementationFile=PACK.cpp
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

[DLG:IDD_PACK_FORM]
Type=1
Class=CPACKView
ControlCount=24
Control1=IDC_FLEX,{6262D3A0-531B-11CF-91F6-C2863C385E30},1342242816
Control2=IDC_LIST_STATE,SysListView32,1350633473
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC_CURRENT_PRODUCT,static,1342308864
Control5=IDC_STATIC,button,1342177287
Control6=IDC_EDIT_CARTON,edit,1350635716
Control7=IDC_STATIC,button,1342177287
Control8=IDC_BTN_ESPE_BOX,button,1342242816
Control9=IDC_BTN_CLOSE,button,1342242816
Control10=IDC_BTN_DISCARD,button,1342242816
Control11=IDC_BTN_PRINT,button,1342242816
Control12=IDC_STATIC,static,1342179342
Control13=IDC_STATIC,static,1342308354
Control14=IDC_STATIC,static,1342308354
Control15=IDC_STATIC_CURRENT_ORDER,static,1342308864
Control16=IDC_STATIC_CURRENT_COLOR,static,1342308864
Control17=IDC_STATIC,static,1342308354
Control18=IDC_STATIC_CURRENT_COUNT,static,1342308352
Control19=IDC_STATIC,static,1342308354
Control20=IDC_STATIC_CURRENT_LINE,static,1342308864
Control21=IDC_BTN_SETTING,button,1342242816
Control22=IDC_BTN_CHECK,button,1342242816
Control23=IDC_BTN_CLEAR,button,1342242816
Control24=IDC_BTN_DELETE,button,1342242816

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

[DLG:IDD_ESPE_BOX]
Type=1
Class=CEspeBox
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_BOXNAME,edit,1350631552
Control5=IDC_BOXNAME_STATIC,edit,1484849280
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352

[CLS:CEspeBox]
Type=0
HeaderFile=EspeBox.h
ImplementationFile=EspeBox.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_BOXNAME_STATIC

[DLG:IDD_CARTONBOX_PRINT]
Type=1
Class=CCartonBoxPrint
ControlCount=19
Control1=IDC_RADIO_MAIN_SOURCE,button,1342308361
Control2=IDC_RADIO1,button,1342177289
Control3=IDOK,button,1073807361
Control4=IDCANCEL,button,1073807360
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC_CURRENT_PRODUCT,static,1342308864
Control7=IDC_STATIC,button,1342177287
Control8=IDC_EDIT_R1,edit,1484849280
Control9=IDC_BTN_PRINT_LABLE,button,1342242816
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC_CURRENT_ORDER_EX,static,1342308864
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC_CURRENT_PALLET_STATIC,static,1342308864
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC_CURRENT_PALLET,static,1342308864
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_COMBO_SOURCE,combobox,1344339971
Control19=IDC_STATIC,button,1342177287

[CLS:CCartonBoxPrint]
Type=0
HeaderFile=CartonBoxPrint.h
ImplementationFile=CartonBoxPrint.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CCartonBoxPrint

[DLG:IDD_DLG_PASSWORD]
Type=1
Class=CPassword
ControlCount=6
Control1=IDC_EDIT_USERNAME,edit,1350631552
Control2=IDC_EDIT_PSW,edit,1350631584
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
LastObject=CPassword

[DLG:IDD_POP_MESSAGEBOX]
Type=1
Class=CPopMessageBox
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC_RESULTS,static,1342308865

[CLS:CPopMessageBox]
Type=0
HeaderFile=PopMessageBox.h
ImplementationFile=PopMessageBox.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_DLG_POP_MAINCARTON]
Type=1
Class=CPopMainCarton
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC_MAINCARTON,static,1342308865

[CLS:CPopMainCarton]
Type=0
HeaderFile=PopMainCarton.h
ImplementationFile=PopMainCarton.cpp
BaseClass=CDialog
Filter=D
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
Control8=IDC_STATIC,static,1342308354
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,static,1342308354
Control12=IDC_STATIC,static,1342308354
Control13=IDC_STATIC,static,1342308354

[CLS:CLogin]
Type=0
HeaderFile=Login.h
ImplementationFile=Login.cpp
BaseClass=CDialog
Filter=D
LastObject=CLogin
VirtualFilter=dWC

[DLG:IDD_PRINTSETTING]
Type=1
Class=CPrintSetting
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_OFFSET,edit,1350635716
Control7=IDC_EDIT_COLOR,edit,1350635716
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT_OFFSET_SUB,edit,1350635716
Control12=IDC_EDIT_COLOR_SUB,edit,1350635716

[CLS:CPrintSetting]
Type=0
HeaderFile=PrintSetting.h
ImplementationFile=PrintSetting.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPrintSetting

[DLG:IDD_DELETE]
Type=1
Class=CDelete
ControlCount=6
Control1=IDC_EDIT_CARTON_DEL,edit,1350631552
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_RADIO_SINGLE,button,1342308361
Control5=IDC_RADIO_WHOLE,button,1342177289
Control6=IDC_STATIC,static,1342308352

[CLS:CDelete]
Type=0
HeaderFile=Delete.h
ImplementationFile=Delete.cpp
BaseClass=CDialog
Filter=D
LastObject=CDelete
VirtualFilter=dWC

