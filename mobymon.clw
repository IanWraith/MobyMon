; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMobymonApp
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "mobymon.h"
LastPage=0

ClassCount=8
Class1=CMobymonApp
Class2=CMobymonDoc
Class3=CMobymonView
Class4=CMainFrame

ResourceCount=6
Resource1=IDD_ABOUTBOX
Resource2=IDD_COMSELECT
Class5=CAboutDlg
Resource3=IDR_MAINFRAME (English (U.S.))
Class6=comselect
Resource4=IDD_REMOTE
Class7=remote
Resource5=IDD_MANSELECT
Class8=man_select
Resource6=IDD_ABOUTBOX (English (U.S.))

[CLS:CMobymonApp]
Type=0
HeaderFile=mobymon.h
ImplementationFile=mobymon.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CMobymonApp

[CLS:CMobymonDoc]
Type=0
HeaderFile=mobymonDoc.h
ImplementationFile=mobymonDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CMobymonDoc

[CLS:CMobymonView]
Type=0
HeaderFile=mobymonView.h
ImplementationFile=mobymonView.cpp
Filter=C
LastObject=ID_SYSTEM_CHANNELS
BaseClass=CScrollView
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame



[CLS:CAboutDlg]
Type=0
HeaderFile=mobymon.cpp
ImplementationFile=mobymon.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_STATUS_BAR
Command15=ID_APP_ABOUT
CommandCount=15
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_CONNECT
Command2=ID_MON_BASE
Command3=ID_MON_MOB
Command4=ID_START_LOGGING
Command5=ID_END_LOGGING
Command6=ID_APP_EXIT
Command7=ID_MRM
Command8=ID_ACK
Command9=ID_NAK
Command10=ID_REB
Command11=ID_RES
Command12=ID_ABD
Command13=ID_ABL
Command14=ID_ATD
Command15=ID_ATL
Command16=ID_BKD
Command17=ID_FRI
Command18=ID_SVP
Command19=ID_TST
Command20=ID_AKT
Command21=ID_ADDCONFAST
Command22=ID_ADDCONREQ
Command23=ID_CLOOPOFF
Command24=ID_CLOOPON
Command25=ID_CONFAST
Command26=ID_CONGRA
Command27=ID_CONORD
Command28=ID_CONREA
Command29=ID_CONREQ
Command30=ID_DISCON
Command31=ID_EXCONREQ
Command32=ID_LINEOFF
Command33=ID_LINEON
Command34=ID_LINSEL
Command35=ID_SOSCONFAST
Command36=ID_SOSCONREQ
Command37=ID_ACTIVE
Command38=ID_AREALIST
Command39=ID_BORN
Command40=ID_DIE
Command41=ID_ESNINFO
Command42=ID_ESNREQ
Command43=ID_FLEXLIST
Command44=ID_FLEXREQ
Command45=ID_GROUPLIST
Command46=ID_INACTIVE
Command47=ID_INFO
Command48=ID_INFOREQ
Command49=ID_LIVE
Command50=ID_LOGINGRA
Command51=ID_LOGINREF
Command52=ID_LOGINREQ
Command53=ID_LOGOUT
Command54=ID_LOGOUTORD
Command55=ID_ROAM
Command56=ID_ROAMORD
Command57=ID_SOSRX
Command58=ID_TIME
Command59=ID_VICESOSRX
Command60=ID_SOS
Command61=ID_SOSACK
Command62=ID_SOSINFO
Command63=ID_DATA
Command64=ID_EXTPAK
Command65=ID_HPDATA_GATEWAY
Command66=ID_HPDATA_MESSAGING
Command67=ID_HPDATA_MTP1
Command68=ID_HPDATA_RAMP
Command69=ID_HPDATA_RNM
Command70=ID_HPDATA_USER
Command71=ID_STATUS
Command72=ID_TEXT
Command73=ID_RE_DISPLAY
Command74=ID_SEQUENCE
Command75=ID_TRAFFIC_STATE
Command76=ID_IGNORE_OK
Command77=ID_IGNORE_FROM_MAIL
Command78=ID_IGNORE_IN_MAIL
Command79=ID_IGNORE_NO_TRANSER
Command80=ID_IGNORE_ILLEGAL
Command81=ID_IGNORE_CONGEST
Command82=ID_IGNORE_ERROR
Command83=ID_IGNORE_BUSY
Command84=ID_SINGLE_MAN
Command85=ID_BLACKLIST_CLEAR
Command86=ID_EXCLUSIVE_USR
Command87=ID_IGNORE_USR
Command88=ID_SIGNALQUALITY
Command89=ID_SYSTEM_CHANNELS
Command90=ID_DEBUG
Command91=ID_ERROR_CHECKING
Command92=ID_FEC
Command93=ID_DATA_AS_ASCII
Command94=ID_EXTPAK_ASCII
Command95=ID_130_DECODE
Command96=ID_SOS_ASCII
Command97=ID_SOSINFO_ASCII
Command98=ID_HELP
Command99=ID_FIRMWARE_INFO
Command100=ID_APP_ABOUT
CommandCount=100

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_COMSELECT]
Type=1
Class=comselect
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_COM1,button,1342177289
Control4=IDC_COM2,button,1342177289
Control5=IDC_COM3,button,1342177289
Control6=IDC_COM4,button,1342177289

[CLS:comselect]
Type=0
HeaderFile=comselect.h
ImplementationFile=comselect.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=comselect

[CLS:remote]
Type=0
HeaderFile=remote.h
ImplementationFile=remote.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT2

[DLG:IDD_REMOTE]
Type=1
Class=remote
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT2,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342308480
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342177283

[DLG:IDD_MANSELECT]
Type=1
Class=man_select
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[CLS:man_select]
Type=0
HeaderFile=man_select.h
ImplementationFile=man_select.cpp
BaseClass=CDialog
Filter=D
LastObject=IDCANCEL
VirtualFilter=dWC

