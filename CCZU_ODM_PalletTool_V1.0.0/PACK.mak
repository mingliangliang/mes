# Microsoft Developer Studio Generated NMAKE File, Based on PACK.dsp
!IF "$(CFG)" == ""
CFG=PACK - Win32 Debug
!MESSAGE No configuration specified. Defaulting to PACK - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "PACK - Win32 Release" && "$(CFG)" != "PACK - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "PACK - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\DEWAV_ODM_PalletTool.exe" "$(OUTDIR)\PACK.bsc"


CLEAN :
	-@erase "$(INTDIR)\BtnST.obj"
	-@erase "$(INTDIR)\BtnST.sbr"
	-@erase "$(INTDIR)\CartonBoxPrint.obj"
	-@erase "$(INTDIR)\CartonBoxPrint.sbr"
	-@erase "$(INTDIR)\config.obj"
	-@erase "$(INTDIR)\config.sbr"
	-@erase "$(INTDIR)\EspeBox.obj"
	-@erase "$(INTDIR)\EspeBox.sbr"
	-@erase "$(INTDIR)\font1.obj"
	-@erase "$(INTDIR)\font1.sbr"
	-@erase "$(INTDIR)\IniFile.obj"
	-@erase "$(INTDIR)\IniFile.sbr"
	-@erase "$(INTDIR)\LABEL.OBJ"
	-@erase "$(INTDIR)\LABEL.SBR"
	-@erase "$(INTDIR)\Login.obj"
	-@erase "$(INTDIR)\Login.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\msflexgrid1.obj"
	-@erase "$(INTDIR)\msflexgrid1.sbr"
	-@erase "$(INTDIR)\PACK.obj"
	-@erase "$(INTDIR)\PACK.pch"
	-@erase "$(INTDIR)\PACK.res"
	-@erase "$(INTDIR)\PACK.sbr"
	-@erase "$(INTDIR)\PACKDoc.obj"
	-@erase "$(INTDIR)\PACKDoc.sbr"
	-@erase "$(INTDIR)\PACKView.obj"
	-@erase "$(INTDIR)\PACKView.sbr"
	-@erase "$(INTDIR)\Password.obj"
	-@erase "$(INTDIR)\Password.sbr"
	-@erase "$(INTDIR)\picture1.obj"
	-@erase "$(INTDIR)\picture1.sbr"
	-@erase "$(INTDIR)\PopMainCarton.obj"
	-@erase "$(INTDIR)\PopMainCarton.sbr"
	-@erase "$(INTDIR)\PopMessageBox.obj"
	-@erase "$(INTDIR)\PopMessageBox.sbr"
	-@erase "$(INTDIR)\PrintSetting.obj"
	-@erase "$(INTDIR)\PrintSetting.sbr"
	-@erase "$(INTDIR)\rowcursor1.obj"
	-@erase "$(INTDIR)\rowcursor1.sbr"
	-@erase "$(INTDIR)\skdlluse.obj"
	-@erase "$(INTDIR)\skdlluse.sbr"
	-@erase "$(INTDIR)\Splash.obj"
	-@erase "$(INTDIR)\Splash.sbr"
	-@erase "$(INTDIR)\StateList.obj"
	-@erase "$(INTDIR)\StateList.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\DEWAV_ODM_PalletTool.exe"
	-@erase "$(OUTDIR)\PACK.bsc"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\PACK.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\PACK.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PACK.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\BtnST.sbr" \
	"$(INTDIR)\CartonBoxPrint.sbr" \
	"$(INTDIR)\config.sbr" \
	"$(INTDIR)\EspeBox.sbr" \
	"$(INTDIR)\font1.sbr" \
	"$(INTDIR)\IniFile.sbr" \
	"$(INTDIR)\LABEL.SBR" \
	"$(INTDIR)\Login.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\msflexgrid1.sbr" \
	"$(INTDIR)\PACK.sbr" \
	"$(INTDIR)\PACKDoc.sbr" \
	"$(INTDIR)\PACKView.sbr" \
	"$(INTDIR)\Password.sbr" \
	"$(INTDIR)\picture1.sbr" \
	"$(INTDIR)\PopMainCarton.sbr" \
	"$(INTDIR)\PopMessageBox.sbr" \
	"$(INTDIR)\PrintSetting.sbr" \
	"$(INTDIR)\rowcursor1.sbr" \
	"$(INTDIR)\skdlluse.sbr" \
	"$(INTDIR)\Splash.sbr" \
	"$(INTDIR)\StateList.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\PACK.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=Adsapi32.lib Version.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\DEWAV_ODM_PalletTool.pdb" /machine:I386 /out:"$(OUTDIR)\DEWAV_ODM_PalletTool.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BtnST.obj" \
	"$(INTDIR)\CartonBoxPrint.obj" \
	"$(INTDIR)\config.obj" \
	"$(INTDIR)\EspeBox.obj" \
	"$(INTDIR)\font1.obj" \
	"$(INTDIR)\IniFile.obj" \
	"$(INTDIR)\LABEL.OBJ" \
	"$(INTDIR)\Login.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\msflexgrid1.obj" \
	"$(INTDIR)\PACK.obj" \
	"$(INTDIR)\PACKDoc.obj" \
	"$(INTDIR)\PACKView.obj" \
	"$(INTDIR)\Password.obj" \
	"$(INTDIR)\picture1.obj" \
	"$(INTDIR)\PopMainCarton.obj" \
	"$(INTDIR)\PopMessageBox.obj" \
	"$(INTDIR)\PrintSetting.obj" \
	"$(INTDIR)\rowcursor1.obj" \
	"$(INTDIR)\skdlluse.obj" \
	"$(INTDIR)\Splash.obj" \
	"$(INTDIR)\StateList.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\PACK.res"

"$(OUTDIR)\DEWAV_ODM_PalletTool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "PACK - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\DEWAV_ODM_PalletTool.exe" "$(OUTDIR)\PACK.bsc"


CLEAN :
	-@erase "$(INTDIR)\BtnST.obj"
	-@erase "$(INTDIR)\BtnST.sbr"
	-@erase "$(INTDIR)\CartonBoxPrint.obj"
	-@erase "$(INTDIR)\CartonBoxPrint.sbr"
	-@erase "$(INTDIR)\config.obj"
	-@erase "$(INTDIR)\config.sbr"
	-@erase "$(INTDIR)\EspeBox.obj"
	-@erase "$(INTDIR)\EspeBox.sbr"
	-@erase "$(INTDIR)\font1.obj"
	-@erase "$(INTDIR)\font1.sbr"
	-@erase "$(INTDIR)\IniFile.obj"
	-@erase "$(INTDIR)\IniFile.sbr"
	-@erase "$(INTDIR)\LABEL.OBJ"
	-@erase "$(INTDIR)\LABEL.SBR"
	-@erase "$(INTDIR)\Login.obj"
	-@erase "$(INTDIR)\Login.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\msflexgrid1.obj"
	-@erase "$(INTDIR)\msflexgrid1.sbr"
	-@erase "$(INTDIR)\PACK.obj"
	-@erase "$(INTDIR)\PACK.pch"
	-@erase "$(INTDIR)\PACK.res"
	-@erase "$(INTDIR)\PACK.sbr"
	-@erase "$(INTDIR)\PACKDoc.obj"
	-@erase "$(INTDIR)\PACKDoc.sbr"
	-@erase "$(INTDIR)\PACKView.obj"
	-@erase "$(INTDIR)\PACKView.sbr"
	-@erase "$(INTDIR)\Password.obj"
	-@erase "$(INTDIR)\Password.sbr"
	-@erase "$(INTDIR)\picture1.obj"
	-@erase "$(INTDIR)\picture1.sbr"
	-@erase "$(INTDIR)\PopMainCarton.obj"
	-@erase "$(INTDIR)\PopMainCarton.sbr"
	-@erase "$(INTDIR)\PopMessageBox.obj"
	-@erase "$(INTDIR)\PopMessageBox.sbr"
	-@erase "$(INTDIR)\PrintSetting.obj"
	-@erase "$(INTDIR)\PrintSetting.sbr"
	-@erase "$(INTDIR)\rowcursor1.obj"
	-@erase "$(INTDIR)\rowcursor1.sbr"
	-@erase "$(INTDIR)\skdlluse.obj"
	-@erase "$(INTDIR)\skdlluse.sbr"
	-@erase "$(INTDIR)\Splash.obj"
	-@erase "$(INTDIR)\Splash.sbr"
	-@erase "$(INTDIR)\StateList.obj"
	-@erase "$(INTDIR)\StateList.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\DEWAV_ODM_PalletTool.exe"
	-@erase "$(OUTDIR)\DEWAV_ODM_PalletTool.ilk"
	-@erase "$(OUTDIR)\DEWAV_ODM_PalletTool.pdb"
	-@erase "$(OUTDIR)\PACK.bsc"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\PACK.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\PACK.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PACK.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\BtnST.sbr" \
	"$(INTDIR)\CartonBoxPrint.sbr" \
	"$(INTDIR)\config.sbr" \
	"$(INTDIR)\EspeBox.sbr" \
	"$(INTDIR)\font1.sbr" \
	"$(INTDIR)\IniFile.sbr" \
	"$(INTDIR)\LABEL.SBR" \
	"$(INTDIR)\Login.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\msflexgrid1.sbr" \
	"$(INTDIR)\PACK.sbr" \
	"$(INTDIR)\PACKDoc.sbr" \
	"$(INTDIR)\PACKView.sbr" \
	"$(INTDIR)\Password.sbr" \
	"$(INTDIR)\picture1.sbr" \
	"$(INTDIR)\PopMainCarton.sbr" \
	"$(INTDIR)\PopMessageBox.sbr" \
	"$(INTDIR)\PrintSetting.sbr" \
	"$(INTDIR)\rowcursor1.sbr" \
	"$(INTDIR)\skdlluse.sbr" \
	"$(INTDIR)\Splash.sbr" \
	"$(INTDIR)\StateList.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\PACK.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=Adsapi32.lib Version.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\DEWAV_ODM_PalletTool.pdb" /debug /machine:I386 /out:"$(OUTDIR)\DEWAV_ODM_PalletTool.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\BtnST.obj" \
	"$(INTDIR)\CartonBoxPrint.obj" \
	"$(INTDIR)\config.obj" \
	"$(INTDIR)\EspeBox.obj" \
	"$(INTDIR)\font1.obj" \
	"$(INTDIR)\IniFile.obj" \
	"$(INTDIR)\LABEL.OBJ" \
	"$(INTDIR)\Login.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\msflexgrid1.obj" \
	"$(INTDIR)\PACK.obj" \
	"$(INTDIR)\PACKDoc.obj" \
	"$(INTDIR)\PACKView.obj" \
	"$(INTDIR)\Password.obj" \
	"$(INTDIR)\picture1.obj" \
	"$(INTDIR)\PopMainCarton.obj" \
	"$(INTDIR)\PopMessageBox.obj" \
	"$(INTDIR)\PrintSetting.obj" \
	"$(INTDIR)\rowcursor1.obj" \
	"$(INTDIR)\skdlluse.obj" \
	"$(INTDIR)\Splash.obj" \
	"$(INTDIR)\StateList.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\PACK.res"

"$(OUTDIR)\DEWAV_ODM_PalletTool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("PACK.dep")
!INCLUDE "PACK.dep"
!ELSE 
!MESSAGE Warning: cannot find "PACK.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "PACK - Win32 Release" || "$(CFG)" == "PACK - Win32 Debug"
SOURCE=.\BtnST.cpp

"$(INTDIR)\BtnST.obj"	"$(INTDIR)\BtnST.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\CartonBoxPrint.cpp

"$(INTDIR)\CartonBoxPrint.obj"	"$(INTDIR)\CartonBoxPrint.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\config.cpp

"$(INTDIR)\config.obj"	"$(INTDIR)\config.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\EspeBox.cpp

"$(INTDIR)\EspeBox.obj"	"$(INTDIR)\EspeBox.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\font1.cpp

"$(INTDIR)\font1.obj"	"$(INTDIR)\font1.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\IniFile.cpp

"$(INTDIR)\IniFile.obj"	"$(INTDIR)\IniFile.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\LABEL.CPP

"$(INTDIR)\LABEL.OBJ"	"$(INTDIR)\LABEL.SBR" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\Login.cpp

"$(INTDIR)\Login.obj"	"$(INTDIR)\Login.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\MainFrm.cpp

"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\msflexgrid1.cpp

"$(INTDIR)\msflexgrid1.obj"	"$(INTDIR)\msflexgrid1.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\PACK.cpp

"$(INTDIR)\PACK.obj"	"$(INTDIR)\PACK.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\PACK.rc

"$(INTDIR)\PACK.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\PACKDoc.cpp

"$(INTDIR)\PACKDoc.obj"	"$(INTDIR)\PACKDoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\PACKView.cpp

"$(INTDIR)\PACKView.obj"	"$(INTDIR)\PACKView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\Password.cpp

"$(INTDIR)\Password.obj"	"$(INTDIR)\Password.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\picture1.cpp

"$(INTDIR)\picture1.obj"	"$(INTDIR)\picture1.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\PopMainCarton.cpp

"$(INTDIR)\PopMainCarton.obj"	"$(INTDIR)\PopMainCarton.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\PopMessageBox.cpp

"$(INTDIR)\PopMessageBox.obj"	"$(INTDIR)\PopMessageBox.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\PrintSetting.cpp

"$(INTDIR)\PrintSetting.obj"	"$(INTDIR)\PrintSetting.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\rowcursor1.cpp

"$(INTDIR)\rowcursor1.obj"	"$(INTDIR)\rowcursor1.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\skdlluse.cpp

"$(INTDIR)\skdlluse.obj"	"$(INTDIR)\skdlluse.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\Splash.cpp

"$(INTDIR)\Splash.obj"	"$(INTDIR)\Splash.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\StateList.cpp

"$(INTDIR)\StateList.obj"	"$(INTDIR)\StateList.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PACK.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "PACK - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\PACK.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\PACK.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PACK - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\PACK.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\PACK.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

