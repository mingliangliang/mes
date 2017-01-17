# Microsoft Developer Studio Project File - Name="ColorBox" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=ColorBox - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ColorBox.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ColorBox.mak" CFG="ColorBox - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ColorBox - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ColorBox - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ColorBox - Win32 Release"

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
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NODEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 FlashtoolLib.lib META_APP.lib brom.lib META_DLL.lib SLA_Challenge.lib eboot.lib SPMETA_DLL.lib Adsapi32.lib Version.lib PhoneCommand.lib PhaseCheck.lib /nologo /subsystem:windows /incremental:yes /debug /machine:I386 /out:"D:\CCZU_MES_V1.0.0\bin\CCZU_ODM_CheckIMEIS1Tool.exe"

!ELSEIF  "$(CFG)" == "ColorBox - Win32 Debug"

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
# ADD LINK32 FlashtoolLib.lib META_APP.lib brom.lib META_DLL.lib SLA_Challenge.lib eboot.lib SPMETA_DLL.lib Adsapi32.lib Version.lib PhoneCommand.lib PhaseCheck.lib /nologo /subsystem:windows /debug /machine:I386 /out:"E:\CODE\DEWAV_MES_System_V1.1.2\DEWAV_ODM_CheckIMEIS1Tool_V1.0.8\Debug\DEWAV_ODM_CheckIMEIS1Tool.exe" /pdbtype:sept
# SUBTRACT LINK32 /incremental:no

!ENDIF 

# Begin Target

# Name "ColorBox - Win32 Release"
# Name "ColorBox - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ColorBox.cpp
# End Source File
# Begin Source File

SOURCE=.\ColorBox.rc
# End Source File
# Begin Source File

SOURCE=.\ColorBoxDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\ColorBoxView.cpp
# End Source File
# Begin Source File

SOURCE=.\config.cpp
# End Source File
# Begin Source File

SOURCE=.\IniFile.cpp
# End Source File
# Begin Source File

SOURCE=.\LABEL.CPP
# End Source File
# Begin Source File

SOURCE=.\Login.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MySpMeta.cpp
# End Source File
# Begin Source File

SOURCE=.\Password.cpp
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

SOURCE=.\android_dl_structure.h
# End Source File
# Begin Source File

SOURCE=.\brom.h
# End Source File
# Begin Source File

SOURCE=.\ColorBox.h
# End Source File
# Begin Source File

SOURCE=.\ColorBoxDoc.h
# End Source File
# Begin Source File

SOURCE=.\ColorBoxView.h
# End Source File
# Begin Source File

SOURCE=.\com_enum.h
# End Source File
# Begin Source File

SOURCE=.\config.h
# End Source File
# Begin Source File

SOURCE=.\DOWNLOAD.H
# End Source File
# Begin Source File

SOURCE=.\external_memory_setting.h
# End Source File
# Begin Source File

SOURCE=.\flashtool.h
# End Source File
# Begin Source File

SOURCE=.\flashtool_api.h
# End Source File
# Begin Source File

SOURCE=.\flashtool_handle.h
# End Source File
# Begin Source File

SOURCE=..\..\DEWAV_PCBAMES_V1.0.3\DEWAV_ODM_PCBACheckNVTool_V1.0.1\ICommChannel.h
# End Source File
# Begin Source File

SOURCE=.\IniFile.h
# End Source File
# Begin Source File

SOURCE=.\interface.h
# End Source File
# Begin Source File

SOURCE=..\..\DEWAV_PCBAMES_V1.0.3\DEWAV_ODM_PCBACheckNVTool_V1.0.1\ISpLog.h
# End Source File
# Begin Source File

SOURCE=.\LABEL.H
# End Source File
# Begin Source File

SOURCE=.\Login.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\meta.h
# End Source File
# Begin Source File

SOURCE=.\metaapp.h
# End Source File
# Begin Source File

SOURCE=.\mtk_mcu.h
# End Source File
# Begin Source File

SOURCE=.\mtk_resource.h
# End Source File
# Begin Source File

SOURCE=.\mtk_status.h
# End Source File
# Begin Source File

SOURCE=.\MySpMeta.h
# End Source File
# Begin Source File

SOURCE=.\Password.h
# End Source File
# Begin Source File

SOURCE=..\..\DEWAV_PCBAMES_V1.0.3\DEWAV_ODM_PCBACheckNVTool_V1.0.1\PhoneCommand.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\rom_setting.h
# End Source File
# Begin Source File

SOURCE=.\skapi.h
# End Source File
# Begin Source File

SOURCE=.\SLA_Challenge.h
# End Source File
# Begin Source File

SOURCE=.\Splash.h
# End Source File
# Begin Source File

SOURCE=.\spmeta.h
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

SOURCE=.\res\41010.bmp
# End Source File
# Begin Source File

SOURCE=.\res\410100.bmp
# End Source File
# Begin Source File

SOURCE=.\res\41070.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ColorBox.ico
# End Source File
# Begin Source File

SOURCE=.\res\ColorBox.rc2
# End Source File
# Begin Source File

SOURCE=.\res\ColorBoxDoc.ico
# End Source File
# Begin Source File

SOURCE=".\res\DEWAV LOGON.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\ERROR.ico
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

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
