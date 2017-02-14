# Microsoft Developer Studio Project File - Name="FullWrite" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=FullWrite - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "FullWrite.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "FullWrite.mak" CFG="FullWrite - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "FullWrite - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "FullWrite - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "FullWrite - Win32 Release"

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
# ADD LINK32 FlashtoolLib.lib META_APP.lib brom.lib META_DLL.lib SLA_Challenge.lib eboot.lib SPMETA_DLL.lib Adsapi32.lib Version.lib PhoneCommand.lib PhaseCheck.lib /nologo /subsystem:windows /debug /machine:I386 /out:"D:\CCZU_MES_V1.0.0\bin\CCZU_ODM_WriteIMEITool.exe"

!ELSEIF  "$(CFG)" == "FullWrite - Win32 Debug"

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
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_DEBUG" /D "NOSQL" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 FlashtoolLib.lib META_APP.lib brom.lib META_DLL.lib SLA_Challenge.lib eboot.lib SPMETA_DLL.lib Adsapi32.lib Version.lib PhoneCommand.lib PhaseCheck.lib /nologo /subsystem:windows /debug /machine:I386 /out:"D:\DEWAV_MES_V1.1.1\bin\DEWAV_ODM_WriteIMEITool.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "FullWrite - Win32 Release"
# Name "FullWrite - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\config.cpp
# End Source File
# Begin Source File

SOURCE=.\FullWrite.cpp
# End Source File
# Begin Source File

SOURCE=.\FullWrite.rc
# End Source File
# Begin Source File

SOURCE=.\FullWriteDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\FullWriteView.cpp
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

SOURCE=.\FullWrite.h
# End Source File
# Begin Source File

SOURCE=.\FullWriteDoc.h
# End Source File
# Begin Source File

SOURCE=.\FullWriteView.h
# End Source File
# Begin Source File

SOURCE=.\IniFile.h
# End Source File
# Begin Source File

SOURCE=.\interface.h
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

SOURCE=.\METAAPP.h
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

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\FullWrite.ico
# End Source File
# Begin Source File

SOURCE=.\res\FullWrite.rc2
# End Source File
# Begin Source File

SOURCE=.\res\FullWriteDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\IDB_BITMAPLOGO.bmp
# End Source File
# Begin Source File

SOURCE=.\res\IDB_BITMAPSPLASH.bmp
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
