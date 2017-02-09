# Microsoft Developer Studio Generated NMAKE File, Based on WeighTool.dsp
!IF "$(CFG)" == ""
CFG=WeighTool - Win32 Debug
!MESSAGE No configuration specified. Defaulting to WeighTool - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "WeighTool - Win32 Release" && "$(CFG)" != "WeighTool - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "WeighTool.mak" CFG="WeighTool - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WeighTool - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "WeighTool - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "WeighTool - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\DEWAV_ODM_QCTool.exe" "$(OUTDIR)\WeighTool.bsc"


CLEAN :
	-@erase "$(INTDIR)\Buffer.obj"
	-@erase "$(INTDIR)\Buffer.sbr"
	-@erase "$(INTDIR)\Config.obj"
	-@erase "$(INTDIR)\Config.sbr"
	-@erase "$(INTDIR)\IniFile.obj"
	-@erase "$(INTDIR)\IniFile.sbr"
	-@erase "$(INTDIR)\LABEL.OBJ"
	-@erase "$(INTDIR)\LABEL.SBR"
	-@erase "$(INTDIR)\Login.obj"
	-@erase "$(INTDIR)\Login.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\MySerial.obj"
	-@erase "$(INTDIR)\MySerial.sbr"
	-@erase "$(INTDIR)\Password.obj"
	-@erase "$(INTDIR)\Password.sbr"
	-@erase "$(INTDIR)\RSData.obj"
	-@erase "$(INTDIR)\RSData.sbr"
	-@erase "$(INTDIR)\Splash.obj"
	-@erase "$(INTDIR)\Splash.sbr"
	-@erase "$(INTDIR)\StateList.obj"
	-@erase "$(INTDIR)\StateList.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\WeighTool.obj"
	-@erase "$(INTDIR)\WeighTool.pch"
	-@erase "$(INTDIR)\WeighTool.res"
	-@erase "$(INTDIR)\WeighTool.sbr"
	-@erase "$(INTDIR)\WeighToolDoc.obj"
	-@erase "$(INTDIR)\WeighToolDoc.sbr"
	-@erase "$(INTDIR)\WeighToolView.obj"
	-@erase "$(INTDIR)\WeighToolView.sbr"
	-@erase "$(OUTDIR)\DEWAV_ODM_QCTool.exe"
	-@erase "$(OUTDIR)\WeighTool.bsc"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\WeighTool.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\WeighTool.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\WeighTool.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Buffer.sbr" \
	"$(INTDIR)\Config.sbr" \
	"$(INTDIR)\IniFile.sbr" \
	"$(INTDIR)\LABEL.SBR" \
	"$(INTDIR)\Login.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\MySerial.sbr" \
	"$(INTDIR)\Password.sbr" \
	"$(INTDIR)\RSData.sbr" \
	"$(INTDIR)\Splash.sbr" \
	"$(INTDIR)\StateList.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\WeighTool.sbr" \
	"$(INTDIR)\WeighToolDoc.sbr" \
	"$(INTDIR)\WeighToolView.sbr"

"$(OUTDIR)\WeighTool.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=Version.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\DEWAV_ODM_QCTool.pdb" /machine:I386 /out:"$(OUTDIR)\DEWAV_ODM_QCTool.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Buffer.obj" \
	"$(INTDIR)\Config.obj" \
	"$(INTDIR)\IniFile.obj" \
	"$(INTDIR)\LABEL.OBJ" \
	"$(INTDIR)\Login.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MySerial.obj" \
	"$(INTDIR)\Password.obj" \
	"$(INTDIR)\RSData.obj" \
	"$(INTDIR)\Splash.obj" \
	"$(INTDIR)\StateList.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WeighTool.obj" \
	"$(INTDIR)\WeighToolDoc.obj" \
	"$(INTDIR)\WeighToolView.obj" \
	"$(INTDIR)\WeighTool.res"

"$(OUTDIR)\DEWAV_ODM_QCTool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "WeighTool - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\DEWAV_ODM_QCTool.exe" "$(OUTDIR)\WeighTool.bsc"


CLEAN :
	-@erase "$(INTDIR)\Buffer.obj"
	-@erase "$(INTDIR)\Buffer.sbr"
	-@erase "$(INTDIR)\Config.obj"
	-@erase "$(INTDIR)\Config.sbr"
	-@erase "$(INTDIR)\IniFile.obj"
	-@erase "$(INTDIR)\IniFile.sbr"
	-@erase "$(INTDIR)\LABEL.OBJ"
	-@erase "$(INTDIR)\LABEL.SBR"
	-@erase "$(INTDIR)\Login.obj"
	-@erase "$(INTDIR)\Login.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\MySerial.obj"
	-@erase "$(INTDIR)\MySerial.sbr"
	-@erase "$(INTDIR)\Password.obj"
	-@erase "$(INTDIR)\Password.sbr"
	-@erase "$(INTDIR)\RSData.obj"
	-@erase "$(INTDIR)\RSData.sbr"
	-@erase "$(INTDIR)\Splash.obj"
	-@erase "$(INTDIR)\Splash.sbr"
	-@erase "$(INTDIR)\StateList.obj"
	-@erase "$(INTDIR)\StateList.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\WeighTool.obj"
	-@erase "$(INTDIR)\WeighTool.pch"
	-@erase "$(INTDIR)\WeighTool.res"
	-@erase "$(INTDIR)\WeighTool.sbr"
	-@erase "$(INTDIR)\WeighToolDoc.obj"
	-@erase "$(INTDIR)\WeighToolDoc.sbr"
	-@erase "$(INTDIR)\WeighToolView.obj"
	-@erase "$(INTDIR)\WeighToolView.sbr"
	-@erase "$(OUTDIR)\DEWAV_ODM_QCTool.exe"
	-@erase "$(OUTDIR)\DEWAV_ODM_QCTool.ilk"
	-@erase "$(OUTDIR)\DEWAV_ODM_QCTool.pdb"
	-@erase "$(OUTDIR)\WeighTool.bsc"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\WeighTool.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\WeighTool.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\WeighTool.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Buffer.sbr" \
	"$(INTDIR)\Config.sbr" \
	"$(INTDIR)\IniFile.sbr" \
	"$(INTDIR)\LABEL.SBR" \
	"$(INTDIR)\Login.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\MySerial.sbr" \
	"$(INTDIR)\Password.sbr" \
	"$(INTDIR)\RSData.sbr" \
	"$(INTDIR)\Splash.sbr" \
	"$(INTDIR)\StateList.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\WeighTool.sbr" \
	"$(INTDIR)\WeighToolDoc.sbr" \
	"$(INTDIR)\WeighToolView.sbr"

"$(OUTDIR)\WeighTool.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=Version.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\DEWAV_ODM_QCTool.pdb" /debug /machine:I386 /out:"$(OUTDIR)\DEWAV_ODM_QCTool.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Buffer.obj" \
	"$(INTDIR)\Config.obj" \
	"$(INTDIR)\IniFile.obj" \
	"$(INTDIR)\LABEL.OBJ" \
	"$(INTDIR)\Login.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MySerial.obj" \
	"$(INTDIR)\Password.obj" \
	"$(INTDIR)\RSData.obj" \
	"$(INTDIR)\Splash.obj" \
	"$(INTDIR)\StateList.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WeighTool.obj" \
	"$(INTDIR)\WeighToolDoc.obj" \
	"$(INTDIR)\WeighToolView.obj" \
	"$(INTDIR)\WeighTool.res"

"$(OUTDIR)\DEWAV_ODM_QCTool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("WeighTool.dep")
!INCLUDE "WeighTool.dep"
!ELSE 
!MESSAGE Warning: cannot find "WeighTool.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "WeighTool - Win32 Release" || "$(CFG)" == "WeighTool - Win32 Debug"
SOURCE=.\Buffer.cpp

"$(INTDIR)\Buffer.obj"	"$(INTDIR)\Buffer.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WeighTool.pch"


SOURCE=.\Config.cpp

"$(INTDIR)\Config.obj"	"$(INTDIR)\Config.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WeighTool.pch"


SOURCE=.\IniFile.cpp

"$(INTDIR)\IniFile.obj"	"$(INTDIR)\IniFile.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WeighTool.pch"


SOURCE=.\LABEL.CPP

"$(INTDIR)\LABEL.OBJ"	"$(INTDIR)\LABEL.SBR" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WeighTool.pch"


SOURCE=.\Login.cpp

"$(INTDIR)\Login.obj"	"$(INTDIR)\Login.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WeighTool.pch"


SOURCE=.\MainFrm.cpp

"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WeighTool.pch"


SOURCE=.\MySerial.cpp

"$(INTDIR)\MySerial.obj"	"$(INTDIR)\MySerial.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WeighTool.pch"


SOURCE=.\Password.cpp

"$(INTDIR)\Password.obj"	"$(INTDIR)\Password.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WeighTool.pch"


SOURCE=.\RSData.cpp

"$(INTDIR)\RSData.obj"	"$(INTDIR)\RSData.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WeighTool.pch"


SOURCE=.\Splash.cpp

"$(INTDIR)\Splash.obj"	"$(INTDIR)\Splash.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WeighTool.pch"


SOURCE=.\StateList.cpp

"$(INTDIR)\StateList.obj"	"$(INTDIR)\StateList.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WeighTool.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "WeighTool - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\WeighTool.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\WeighTool.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "WeighTool - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\WeighTool.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\WeighTool.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\WeighTool.cpp

"$(INTDIR)\WeighTool.obj"	"$(INTDIR)\WeighTool.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WeighTool.pch"


SOURCE=.\WeighTool.rc

"$(INTDIR)\WeighTool.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\WeighToolDoc.cpp

"$(INTDIR)\WeighToolDoc.obj"	"$(INTDIR)\WeighToolDoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WeighTool.pch"


SOURCE=.\WeighToolView.cpp

"$(INTDIR)\WeighToolView.obj"	"$(INTDIR)\WeighToolView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WeighTool.pch"



!ENDIF 

