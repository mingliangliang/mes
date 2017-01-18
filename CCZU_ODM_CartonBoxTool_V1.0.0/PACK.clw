; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPACKView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PACK.h"
LastPage=0

ClassCount=12
Class1=CPACKApp
Class2=CPACKDoc
Class3=CPACKView
Class4=CMainFrame

ResourceCount=11
Resource1=IDD_CARTONBOX_PRINT
Resource2=IDD_LOGIN
Class5=CAboutDlg
Resource3=IDD_PACK_FORM
Resource4=IDR_MAINFRAME
Class6=CEspeBox
Resource5=IDR_LIST_CLEAR
Class7=CCartonBoxPrint
Resource6=IDD_POP_MESSAGEBOX
Class8=CPassword
Resource7=IDD_ESPE_BOX
Class9=CPopMessageBox
Resource8=IDD_DLG_POP_MAINCARTON
Class10=CPopMainCarton
Resource9=IDD_ABOUTBOX
Class11=CLogin
Resource10=IDD_DLG_PASSWORD
Class12=CPrintSetting
Resource11=IDD_PRINTSETTING

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
Command1=IDM_SCAN_ONE
Command2=IDM_SCAN_ALL
Command3=ID_APP_EXIT
Command4=ID_VIEW_TOOLBAR
Command5=ID_VIEW_STATUS_BAR
Command6=ID_APP_ABOUT
CommandCount=6

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
ControlCount=30
Control1=IDC_FLEX,{6262D3A0-531B-11CF-91F6-C2863C385E30},1342242816
Control2=IDC_LIST_STATE,SysListView32,1350633473
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC_CURRENT_PRODUCT,static,1342308864
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,button,1342177287
Control9=IDC_EDIT_IMEI1,edit,1350635716
Control10=IDC_EDIT_IMEI2,edit,1350635716
Control11=IDC_EDIT_IMEI3,edit,1350635716
Control12=IDC_EDIT_IMEI4,edit,1350635716
Control13=IDC_STATIC,button,1342177287
Control14=IDC_BTN_ESPE_BOX,button,1342242816
Control15=IDC_BTN_CLOSE,button,1342242816
Control16=IDC_BTN_DISCARD,button,1342242816
Control17=IDC_BTN_PRINT,button,1342242816
Control18=IDC_STATIC,static,1342177294
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC_CURRENT_ORDER,static,1342308864
Control22=IDC_STATIC_CURRENT_COLOR,static,1342308864
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC_CURRENT_COUNT,static,1342308352
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC_CURRENT_LINE,static,1342308864
Control27=IDC_BTN_SETTING,button,1342242816
Control28=IDC_CHECK_PSN_STATIC,button,1342242819
Control29=IDC_CHECK_ADD_Z,button,1342242819
Control30=IDC_EDIT_ADD,edit,1350631552

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
ControlCount=69
Control1=IDC_RADIO_MAIN_SOURCE,button,1342308361
Control2=IDC_RADIO1,button,1342177289
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC_CURRENT_PRODUCT,static,1342177792
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,static,1342177280
Control7=IDC_EDIT_R1,edit,1484849280
Control8=IDC_STATIC_R1,static,1342177794
Control9=IDC_STATIC,static,1342177280
Control10=IDC_EDIT_R2,edit,1350631552
Control11=IDC_STATIC_R2,static,1342177794
Control12=IDC_STATIC,static,1342177280
Control13=IDC_EDIT_R3,edit,1350631552
Control14=IDC_STATIC_R3,static,1342177794
Control15=IDC_STATIC,static,1342177280
Control16=IDC_EDIT_R4,edit,1350631552
Control17=IDC_STATIC_R4,static,1342177794
Control18=IDC_STATIC,static,1342177280
Control19=IDC_EDIT_R5,edit,1350631552
Control20=IDC_STATIC_R5,static,1342177794
Control21=IDC_STATIC,static,1342177280
Control22=IDC_EDIT_R6,edit,1350631552
Control23=IDC_STATIC_R6,static,1342177794
Control24=IDC_STATIC,static,1342177280
Control25=IDC_EDIT_R7,edit,1350631552
Control26=IDC_STATIC_R7,static,1342177794
Control27=IDC_STATIC,static,1342177280
Control28=IDC_EDIT_R8,edit,1350631552
Control29=IDC_STATIC_R8,static,1342177794
Control30=IDC_STATIC,static,1073741824
Control31=IDC_EDIT_R9,edit,1082196096
Control32=IDC_STATIC_R9,static,1073742338
Control33=IDC_STATIC,static,1073741824
Control34=IDC_EDIT_R10,edit,1082196096
Control35=IDC_STATIC_R10,static,1073742338
Control36=IDC_STATIC,static,1073741824
Control37=IDC_EDIT_R11,edit,1082196096
Control38=IDC_STATIC_R11,static,1073742338
Control39=IDC_STATIC,static,1073741824
Control40=IDC_EDIT_R12,edit,1082196096
Control41=IDC_STATIC_R12,static,1073742338
Control42=IDC_STATIC,static,1073741824
Control43=IDC_EDIT_R13,edit,1082196096
Control44=IDC_STATIC_R13,static,1073742338
Control45=IDC_STATIC,static,1342181383
Control46=IDC_STATIC,static,1342181383
Control47=IDC_STATIC,static,1342181383
Control48=IDC_STATIC,static,1342181383
Control49=IDC_STATIC,static,1342181383
Control50=IDC_STATIC,static,1342181383
Control51=IDC_STATIC,static,1342181383
Control52=IDC_STATIC,static,1342181383
Control53=IDC_STATIC,static,1073745927
Control54=IDC_STATIC,static,1073745927
Control55=IDC_STATIC,static,1073745927
Control56=IDC_STATIC,static,1073745927
Control57=IDC_BTN_PRINT_LABLE,button,1342242816
Control58=IDC_EDIT_CARTON_STATIC,edit,1484849280
Control59=IDC_STATIC_R14,static,1342177794
Control60=IDC_STATIC,static,1342181383
Control61=IDC_STATIC,static,1342308352
Control62=IDC_STATIC,static,1342177280
Control63=IDC_STATIC_CURRENT_ORDER_EX,static,1342177792
Control64=IDC_STATIC,static,1342177280
Control65=IDC_STATIC_CURRENT_COLOR_EX,static,1342177792
Control66=IDC_STATIC,static,1342177280
Control67=IDC_STATIC,static,1073745927
Control68=IDC_RADIO_CURRENT_CARTON,button,1342308361
Control69=IDC_RADIO_SPECIFIC_CARTON,button,1342177289

[CLS:CCartonBoxPrint]
Type=0
HeaderFile=CartonBoxPrint.h
ImplementationFile=CartonBoxPrint.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_RADIO_MAIN_SOURCE

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
LastObject=CPopMainCarton

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

[DLG:IDD_PRINTSETTING]
Type=1
Class=CPrintSetting
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_OFFSET,edit,1350635716
Control8=IDC_EDIT_COLOR,edit,1350635716
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
LastObject=CPrintSetting
VirtualFilter=dWC

