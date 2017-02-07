# Microsoft Developer Studio Project File - Name="PACK" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=PACK - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "PACK.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PACK.mak" CFG="PACK - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PACK - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "PACK - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "PACK - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 Adsapi32.lib Version.lib SkinMagicTrial.lib /nologo /subsystem:windows /machine:I386 /out:"D:\CCZU_MES_V1.0.0\bin\CCZU_ODM_ProductionDataQueryTool.exe"

!ELSEIF  "$(CFG)" == "PACK - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 Adsapi32.lib Version.lib /nologo /subsystem:windows /debug /machine:I386 /out:"D:\DEWAV_MES_System_V1.1.4\DEWAV_ODM_ProductionDataQueryTool_V1.0.8\Debug\DEWAV_ODM_ProductionDataQueryTool.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "PACK - Win32 Release"
# Name "PACK - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BtnST.cpp
# End Source File
# Begin Source File

SOURCE=.\config.cpp
# End Source File
# Begin Source File

SOURCE=.\excel.cpp
# End Source File
# Begin Source File

SOURCE=.\font1.cpp
# End Source File
# Begin Source File

SOURCE=.\IniFile.cpp
# End Source File
# Begin Source File

SOURCE=.\LABEL.CPP
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\msflexgrid1.cpp
# End Source File
# Begin Source File

SOURCE=.\OrderList.cpp
# End Source File
# Begin Source File

SOURCE=.\OrderQuery.cpp
# End Source File
# Begin Source File

SOURCE=.\PACK.cpp
# End Source File
# Begin Source File

SOURCE=.\PACK.rc
# End Source File
# Begin Source File

SOURCE=.\PACKDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\PACKView.cpp
# End Source File
# Begin Source File

SOURCE=.\Password.cpp
# End Source File
# Begin Source File

SOURCE=.\picture1.cpp
# End Source File
# Begin Source File

SOURCE=.\Query.cpp
# End Source File
# Begin Source File

SOURCE=.\rowcursor1.cpp
# End Source File
# Begin Source File

SOURCE=.\skdlluse.cpp
# End Source File
# Begin Source File

SOURCE=.\Splash.cpp
# End Source File
# Begin Source File

SOURCE=.\StateList.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BtnST.h
# End Source File
# Begin Source File

SOURCE=.\config.h
# End Source File
# Begin Source File

SOURCE=.\excel.h
# End Source File
# Begin Source File

SOURCE=.\font1.h
# End Source File
# Begin Source File

SOURCE=.\IniFile.h
# End Source File
# Begin Source File

SOURCE=.\LABEL.H
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\msflexgrid1.h
# End Source File
# Begin Source File

SOURCE=.\OrderList.h
# End Source File
# Begin Source File

SOURCE=.\OrderQuery.h
# End Source File
# Begin Source File

SOURCE=.\PACK.h
# End Source File
# Begin Source File

SOURCE=.\PACKDoc.h
# End Source File
# Begin Source File

SOURCE=.\PACKView.h
# End Source File
# Begin Source File

SOURCE=.\Password.h
# End Source File
# Begin Source File

SOURCE=.\picture1.h
# End Source File
# Begin Source File

SOURCE=.\Query.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\rowcursor1.h
# End Source File
# Begin Source File

SOURCE=.\skapi.h
# End Source File
# Begin Source File

SOURCE=.\Splash.h
# End Source File
# Begin Source File

SOURCE=.\StateList.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\box.ico
# End Source File
# Begin Source File

SOURCE=".\res\DEWAV LOGON.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\discard.ICO
# End Source File
# Begin Source File

SOURCE=.\res\ERROR.ico
# End Source File
# Begin Source File

SOURCE=.\res\EXPORT.ICO
# End Source File
# Begin Source File

SOURCE=.\res\ico00001.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon5.ico
# End Source File
# Begin Source File

SOURCE=.\res\IDB_BITMAPSPLASH.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LOGFRAME.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LOGO.bmp
# End Source File
# Begin Source File

SOURCE=.\res\PACK.ico
# End Source File
# Begin Source File

SOURCE=.\res\PACK.rc2
# End Source File
# Begin Source File

SOURCE=.\res\PACKDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\PRINT004.ICO
# End Source File
# Begin Source File

SOURCE=.\res\PRINT012.ICO
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section PACK : {5F4DF280-531B-11CF-91F6-C2863C385E30}
# 	2:5:Class:CMSFlexGrid
# 	2:10:HeaderFile:msflexgrid1.h
# 	2:8:ImplFile:msflexgrid1.cpp
# End Section
# Section PACK : {BEF6E003-A874-101A-8BBA-00AA00300CAB}
# 	2:5:Class:COleFont
# 	2:10:HeaderFile:font1.h
# 	2:8:ImplFile:font1.cpp
# End Section
# Section PACK : {6262D3A0-531B-11CF-91F6-C2863C385E30}
# 	2:21:DefaultSinkHeaderFile:msflexgrid1.h
# 	2:16:DefaultSinkClass:CMSFlexGrid
# End Section
# Section PACK : {7BF80981-BF32-101A-8BBB-00AA00300CAB}
# 	2:5:Class:CPicture
# 	2:10:HeaderFile:picture1.h
# 	2:8:ImplFile:picture1.cpp
# End Section
# Section PACK : {9F6AA700-D188-11CD-AD48-00AA003C9CB6}
# 	2:5:Class:CRowCursor
# 	2:10:HeaderFile:rowcursor1.h
# 	2:8:ImplFile:rowcursor1.cpp
# End Section
