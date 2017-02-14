# Microsoft Developer Studio Generated NMAKE File, Based on FullWrite.dsp
!IF "$(CFG)" == ""
CFG=FullWrite - Win32 Debug
!MESSAGE No configuration specified. Defaulting to FullWrite - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "FullWrite - Win32 Release" && "$(CFG)" != "FullWrite - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "FullWrite - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\DEWAV_ODM_WriteIMEITool.exe" "$(OUTDIR)\FullWrite.bsc"


CLEAN :
	-@erase "$(INTDIR)\config.obj"
	-@erase "$(INTDIR)\config.sbr"
	-@erase "$(INTDIR)\FullWrite.obj"
	-@erase "$(INTDIR)\FullWrite.pch"
	-@erase "$(INTDIR)\FullWrite.res"
	-@erase "$(INTDIR)\FullWrite.sbr"
	-@erase "$(INTDIR)\FullWriteDoc.obj"
	-@erase "$(INTDIR)\FullWriteDoc.sbr"
	-@erase "$(INTDIR)\FullWriteView.obj"
	-@erase "$(INTDIR)\FullWriteView.sbr"
	-@erase "$(INTDIR)\IniFile.obj"
	-@erase "$(INTDIR)\IniFile.sbr"
	-@erase "$(INTDIR)\LABEL.OBJ"
	-@erase "$(INTDIR)\LABEL.SBR"
	-@erase "$(INTDIR)\Login.obj"
	-@erase "$(INTDIR)\Login.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\MySpMeta.obj"
	-@erase "$(INTDIR)\MySpMeta.sbr"
	-@erase "$(INTDIR)\Password.obj"
	-@erase "$(INTDIR)\Password.sbr"
	-@erase "$(INTDIR)\skdlluse.obj"
	-@erase "$(INTDIR)\skdlluse.sbr"
	-@erase "$(INTDIR)\Splash.obj"
	-@erase "$(INTDIR)\Splash.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\DEWAV_ODM_WriteIMEITool.exe"
	-@erase "$(OUTDIR)\FullWrite.bsc"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\FullWrite.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\FullWrite.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\FullWrite.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\config.sbr" \
	"$(INTDIR)\FullWrite.sbr" \
	"$(INTDIR)\FullWriteDoc.sbr" \
	"$(INTDIR)\FullWriteView.sbr" \
	"$(INTDIR)\IniFile.sbr" \
	"$(INTDIR)\LABEL.SBR" \
	"$(INTDIR)\Login.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\MySpMeta.sbr" \
	"$(INTDIR)\Password.sbr" \
	"$(INTDIR)\skdlluse.sbr" \
	"$(INTDIR)\Splash.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\FullWrite.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=FlashtoolLib.lib META_APP.lib brom.lib META_DLL.lib SLA_Challenge.lib eboot.lib SPMETA_DLL.lib Adsapi32.lib Version.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\DEWAV_ODM_WriteIMEITool.pdb" /machine:I386 /out:"$(OUTDIR)\DEWAV_ODM_WriteIMEITool.exe" 
LINK32_OBJS= \
	"$(INTDIR)\config.obj" \
	"$(INTDIR)\FullWrite.obj" \
	"$(INTDIR)\FullWriteDoc.obj" \
	"$(INTDIR)\FullWriteView.obj" \
	"$(INTDIR)\IniFile.obj" \
	"$(INTDIR)\LABEL.OBJ" \
	"$(INTDIR)\Login.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MySpMeta.obj" \
	"$(INTDIR)\Password.obj" \
	"$(INTDIR)\skdlluse.obj" \
	"$(INTDIR)\Splash.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\FullWrite.res"

"$(OUTDIR)\DEWAV_ODM_WriteIMEITool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "FullWrite - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\DEWAV_ODM_WriteIMEITool.exe" "$(OUTDIR)\FullWrite.bsc"


CLEAN :
	-@erase "$(INTDIR)\config.obj"
	-@erase "$(INTDIR)\config.sbr"
	-@erase "$(INTDIR)\FullWrite.obj"
	-@erase "$(INTDIR)\FullWrite.pch"
	-@erase "$(INTDIR)\FullWrite.res"
	-@erase "$(INTDIR)\FullWrite.sbr"
	-@erase "$(INTDIR)\FullWriteDoc.obj"
	-@erase "$(INTDIR)\FullWriteDoc.sbr"
	-@erase "$(INTDIR)\FullWriteView.obj"
	-@erase "$(INTDIR)\FullWriteView.sbr"
	-@erase "$(INTDIR)\IniFile.obj"
	-@erase "$(INTDIR)\IniFile.sbr"
	-@erase "$(INTDIR)\LABEL.OBJ"
	-@erase "$(INTDIR)\LABEL.SBR"
	-@erase "$(INTDIR)\Login.obj"
	-@erase "$(INTDIR)\Login.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\MySpMeta.obj"
	-@erase "$(INTDIR)\MySpMeta.sbr"
	-@erase "$(INTDIR)\Password.obj"
	-@erase "$(INTDIR)\Password.sbr"
	-@erase "$(INTDIR)\skdlluse.obj"
	-@erase "$(INTDIR)\skdlluse.sbr"
	-@erase "$(INTDIR)\Splash.obj"
	-@erase "$(INTDIR)\Splash.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\DEWAV_ODM_WriteIMEITool.exe"
	-@erase "$(OUTDIR)\DEWAV_ODM_WriteIMEITool.ilk"
	-@erase "$(OUTDIR)\DEWAV_ODM_WriteIMEITool.pdb"
	-@erase "$(OUTDIR)\FullWrite.bsc"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\FullWrite.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\FullWrite.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\FullWrite.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\config.sbr" \
	"$(INTDIR)\FullWrite.sbr" \
	"$(INTDIR)\FullWriteDoc.sbr" \
	"$(INTDIR)\FullWriteView.sbr" \
	"$(INTDIR)\IniFile.sbr" \
	"$(INTDIR)\LABEL.SBR" \
	"$(INTDIR)\Login.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\MySpMeta.sbr" \
	"$(INTDIR)\Password.sbr" \
	"$(INTDIR)\skdlluse.sbr" \
	"$(INTDIR)\Splash.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\FullWrite.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=FlashtoolLib.lib META_APP.lib brom.lib META_DLL.lib SLA_Challenge.lib eboot.lib SPMETA_DLL.lib Adsapi32.lib Version.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\DEWAV_ODM_WriteIMEITool.pdb" /debug /machine:I386 /out:"$(OUTDIR)\DEWAV_ODM_WriteIMEITool.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\config.obj" \
	"$(INTDIR)\FullWrite.obj" \
	"$(INTDIR)\FullWriteDoc.obj" \
	"$(INTDIR)\FullWriteView.obj" \
	"$(INTDIR)\IniFile.obj" \
	"$(INTDIR)\LABEL.OBJ" \
	"$(INTDIR)\Login.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MySpMeta.obj" \
	"$(INTDIR)\Password.obj" \
	"$(INTDIR)\skdlluse.obj" \
	"$(INTDIR)\Splash.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\FullWrite.res"

"$(OUTDIR)\DEWAV_ODM_WriteIMEITool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("FullWrite.dep")
!INCLUDE "FullWrite.dep"
!ELSE 
!MESSAGE Warning: cannot find "FullWrite.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "FullWrite - Win32 Release" || "$(CFG)" == "FullWrite - Win32 Debug"
SOURCE=.\config.cpp

"$(INTDIR)\config.obj"	"$(INTDIR)\config.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FullWrite.pch"


SOURCE=.\FullWrite.cpp

"$(INTDIR)\FullWrite.obj"	"$(INTDIR)\FullWrite.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FullWrite.pch"


SOURCE=.\FullWrite.rc

"$(INTDIR)\FullWrite.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\FullWriteDoc.cpp

"$(INTDIR)\FullWriteDoc.obj"	"$(INTDIR)\FullWriteDoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FullWrite.pch"


SOURCE=.\FullWriteView.cpp

"$(INTDIR)\FullWriteView.obj"	"$(INTDIR)\FullWriteView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FullWrite.pch"


SOURCE=.\IniFile.cpp

"$(INTDIR)\IniFile.obj"	"$(INTDIR)\IniFile.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FullWrite.pch"


SOURCE=.\LABEL.CPP

"$(INTDIR)\LABEL.OBJ"	"$(INTDIR)\LABEL.SBR" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FullWrite.pch"


SOURCE=.\Login.cpp

"$(INTDIR)\Login.obj"	"$(INTDIR)\Login.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FullWrite.pch"


SOURCE=.\MainFrm.cpp

"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FullWrite.pch"


SOURCE=.\MySpMeta.cpp

"$(INTDIR)\MySpMeta.obj"	"$(INTDIR)\MySpMeta.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FullWrite.pch"


SOURCE=.\Password.cpp

"$(INTDIR)\Password.obj"	"$(INTDIR)\Password.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FullWrite.pch"


SOURCE=.\skdlluse.cpp

"$(INTDIR)\skdlluse.obj"	"$(INTDIR)\skdlluse.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FullWrite.pch"


SOURCE=.\Splash.cpp

"$(INTDIR)\Splash.obj"	"$(INTDIR)\Splash.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FullWrite.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "FullWrite - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\FullWrite.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\FullWrite.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "FullWrite - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\FullWrite.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\FullWrite.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

