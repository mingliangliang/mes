# Microsoft Developer Studio Generated NMAKE File, Based on ProductionManagementTool.dsp
!IF "$(CFG)" == ""
CFG=ProductionManagementTool - Win32 Debug
!MESSAGE No configuration specified. Defaulting to ProductionManagementTool - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "ProductionManagementTool - Win32 Release" && "$(CFG)" != "ProductionManagementTool - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ProductionManagementTool.mak" CFG="ProductionManagementTool - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ProductionManagementTool - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ProductionManagementTool - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "ProductionManagementTool - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\DEWAV_ODM_ProductionManagementTool_V1.0.2.exe" "$(OUTDIR)\ProductionManagementTool.bsc"


CLEAN :
	-@erase "$(INTDIR)\AddUserDlg.obj"
	-@erase "$(INTDIR)\AddUserDlg.sbr"
	-@erase "$(INTDIR)\AlterSetting.obj"
	-@erase "$(INTDIR)\AlterSetting.sbr"
	-@erase "$(INTDIR)\ChangePasswordDlg.obj"
	-@erase "$(INTDIR)\ChangePasswordDlg.sbr"
	-@erase "$(INTDIR)\config.obj"
	-@erase "$(INTDIR)\config.sbr"
	-@erase "$(INTDIR)\DeleteUserDlg.obj"
	-@erase "$(INTDIR)\DeleteUserDlg.sbr"
	-@erase "$(INTDIR)\IniFile.obj"
	-@erase "$(INTDIR)\IniFile.sbr"
	-@erase "$(INTDIR)\Login.obj"
	-@erase "$(INTDIR)\Login.sbr"
	-@erase "$(INTDIR)\Password.obj"
	-@erase "$(INTDIR)\Password.sbr"
	-@erase "$(INTDIR)\ProductionManagementTool.obj"
	-@erase "$(INTDIR)\ProductionManagementTool.pch"
	-@erase "$(INTDIR)\ProductionManagementTool.res"
	-@erase "$(INTDIR)\ProductionManagementTool.sbr"
	-@erase "$(INTDIR)\ProductionManagementToolDlg.obj"
	-@erase "$(INTDIR)\ProductionManagementToolDlg.sbr"
	-@erase "$(INTDIR)\Splash.obj"
	-@erase "$(INTDIR)\Splash.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\DEWAV_ODM_ProductionManagementTool_V1.0.2.exe"
	-@erase "$(OUTDIR)\ProductionManagementTool.bsc"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ProductionManagementTool.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\ProductionManagementTool.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ProductionManagementTool.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\AddUserDlg.sbr" \
	"$(INTDIR)\AlterSetting.sbr" \
	"$(INTDIR)\ChangePasswordDlg.sbr" \
	"$(INTDIR)\config.sbr" \
	"$(INTDIR)\DeleteUserDlg.sbr" \
	"$(INTDIR)\IniFile.sbr" \
	"$(INTDIR)\Login.sbr" \
	"$(INTDIR)\Password.sbr" \
	"$(INTDIR)\ProductionManagementTool.sbr" \
	"$(INTDIR)\ProductionManagementToolDlg.sbr" \
	"$(INTDIR)\Splash.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\ProductionManagementTool.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\DEWAV_ODM_ProductionManagementTool_V1.0.2.pdb" /machine:I386 /out:"$(OUTDIR)\DEWAV_ODM_ProductionManagementTool_V1.0.2.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AddUserDlg.obj" \
	"$(INTDIR)\AlterSetting.obj" \
	"$(INTDIR)\ChangePasswordDlg.obj" \
	"$(INTDIR)\config.obj" \
	"$(INTDIR)\DeleteUserDlg.obj" \
	"$(INTDIR)\IniFile.obj" \
	"$(INTDIR)\Login.obj" \
	"$(INTDIR)\Password.obj" \
	"$(INTDIR)\ProductionManagementTool.obj" \
	"$(INTDIR)\ProductionManagementToolDlg.obj" \
	"$(INTDIR)\Splash.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ProductionManagementTool.res"

"$(OUTDIR)\DEWAV_ODM_ProductionManagementTool_V1.0.2.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ProductionManagementTool - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\DEWAV_ODM_ProductionManagementTool_V1.0.2.exe" "$(OUTDIR)\ProductionManagementTool.bsc"


CLEAN :
	-@erase "$(INTDIR)\AddUserDlg.obj"
	-@erase "$(INTDIR)\AddUserDlg.sbr"
	-@erase "$(INTDIR)\AlterSetting.obj"
	-@erase "$(INTDIR)\AlterSetting.sbr"
	-@erase "$(INTDIR)\ChangePasswordDlg.obj"
	-@erase "$(INTDIR)\ChangePasswordDlg.sbr"
	-@erase "$(INTDIR)\config.obj"
	-@erase "$(INTDIR)\config.sbr"
	-@erase "$(INTDIR)\DeleteUserDlg.obj"
	-@erase "$(INTDIR)\DeleteUserDlg.sbr"
	-@erase "$(INTDIR)\IniFile.obj"
	-@erase "$(INTDIR)\IniFile.sbr"
	-@erase "$(INTDIR)\Login.obj"
	-@erase "$(INTDIR)\Login.sbr"
	-@erase "$(INTDIR)\Password.obj"
	-@erase "$(INTDIR)\Password.sbr"
	-@erase "$(INTDIR)\ProductionManagementTool.obj"
	-@erase "$(INTDIR)\ProductionManagementTool.pch"
	-@erase "$(INTDIR)\ProductionManagementTool.res"
	-@erase "$(INTDIR)\ProductionManagementTool.sbr"
	-@erase "$(INTDIR)\ProductionManagementToolDlg.obj"
	-@erase "$(INTDIR)\ProductionManagementToolDlg.sbr"
	-@erase "$(INTDIR)\Splash.obj"
	-@erase "$(INTDIR)\Splash.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\DEWAV_ODM_ProductionManagementTool_V1.0.2.exe"
	-@erase "$(OUTDIR)\DEWAV_ODM_ProductionManagementTool_V1.0.2.ilk"
	-@erase "$(OUTDIR)\DEWAV_ODM_ProductionManagementTool_V1.0.2.pdb"
	-@erase "$(OUTDIR)\ProductionManagementTool.bsc"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ProductionManagementTool.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\ProductionManagementTool.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ProductionManagementTool.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\AddUserDlg.sbr" \
	"$(INTDIR)\AlterSetting.sbr" \
	"$(INTDIR)\ChangePasswordDlg.sbr" \
	"$(INTDIR)\config.sbr" \
	"$(INTDIR)\DeleteUserDlg.sbr" \
	"$(INTDIR)\IniFile.sbr" \
	"$(INTDIR)\Login.sbr" \
	"$(INTDIR)\Password.sbr" \
	"$(INTDIR)\ProductionManagementTool.sbr" \
	"$(INTDIR)\ProductionManagementToolDlg.sbr" \
	"$(INTDIR)\Splash.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\ProductionManagementTool.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\DEWAV_ODM_ProductionManagementTool_V1.0.2.pdb" /debug /machine:I386 /out:"$(OUTDIR)\DEWAV_ODM_ProductionManagementTool_V1.0.2.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\AddUserDlg.obj" \
	"$(INTDIR)\AlterSetting.obj" \
	"$(INTDIR)\ChangePasswordDlg.obj" \
	"$(INTDIR)\config.obj" \
	"$(INTDIR)\DeleteUserDlg.obj" \
	"$(INTDIR)\IniFile.obj" \
	"$(INTDIR)\Login.obj" \
	"$(INTDIR)\Password.obj" \
	"$(INTDIR)\ProductionManagementTool.obj" \
	"$(INTDIR)\ProductionManagementToolDlg.obj" \
	"$(INTDIR)\Splash.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ProductionManagementTool.res"

"$(OUTDIR)\DEWAV_ODM_ProductionManagementTool_V1.0.2.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("ProductionManagementTool.dep")
!INCLUDE "ProductionManagementTool.dep"
!ELSE 
!MESSAGE Warning: cannot find "ProductionManagementTool.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "ProductionManagementTool - Win32 Release" || "$(CFG)" == "ProductionManagementTool - Win32 Debug"
SOURCE=.\AddUserDlg.cpp

"$(INTDIR)\AddUserDlg.obj"	"$(INTDIR)\AddUserDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ProductionManagementTool.pch"


SOURCE=.\AlterSetting.cpp

"$(INTDIR)\AlterSetting.obj"	"$(INTDIR)\AlterSetting.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ProductionManagementTool.pch"


SOURCE=.\ChangePasswordDlg.cpp

"$(INTDIR)\ChangePasswordDlg.obj"	"$(INTDIR)\ChangePasswordDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ProductionManagementTool.pch"


SOURCE=.\config.cpp

"$(INTDIR)\config.obj"	"$(INTDIR)\config.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ProductionManagementTool.pch"


SOURCE=.\DeleteUserDlg.cpp

"$(INTDIR)\DeleteUserDlg.obj"	"$(INTDIR)\DeleteUserDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ProductionManagementTool.pch"


SOURCE=.\IniFile.cpp

"$(INTDIR)\IniFile.obj"	"$(INTDIR)\IniFile.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ProductionManagementTool.pch"


SOURCE=.\Login.cpp

"$(INTDIR)\Login.obj"	"$(INTDIR)\Login.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ProductionManagementTool.pch"


SOURCE=.\Password.cpp

"$(INTDIR)\Password.obj"	"$(INTDIR)\Password.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ProductionManagementTool.pch"


SOURCE=.\ProductionManagementTool.cpp

"$(INTDIR)\ProductionManagementTool.obj"	"$(INTDIR)\ProductionManagementTool.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ProductionManagementTool.pch"


SOURCE=.\ProductionManagementTool.rc

"$(INTDIR)\ProductionManagementTool.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\ProductionManagementToolDlg.cpp

"$(INTDIR)\ProductionManagementToolDlg.obj"	"$(INTDIR)\ProductionManagementToolDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ProductionManagementTool.pch"


SOURCE=.\Splash.cpp

"$(INTDIR)\Splash.obj"	"$(INTDIR)\Splash.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ProductionManagementTool.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "ProductionManagementTool - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ProductionManagementTool.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\ProductionManagementTool.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ProductionManagementTool - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ProductionManagementTool.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\ProductionManagementTool.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

