# Microsoft Developer Studio Generated NMAKE File, Based on CreateProduct.dsp
!IF "$(CFG)" == ""
CFG=CreateProduct - Win32 Debug
!MESSAGE No configuration specified. Defaulting to CreateProduct - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "CreateProduct - Win32 Release" && "$(CFG)" != "CreateProduct - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CreateProduct.mak" CFG="CreateProduct - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CreateProduct - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "CreateProduct - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "CreateProduct - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\DEWAV_ODM_CreateProductTool.exe" "$(OUTDIR)\CreateProduct.bsc"


CLEAN :
	-@erase "$(INTDIR)\config.obj"
	-@erase "$(INTDIR)\config.sbr"
	-@erase "$(INTDIR)\CreateProduct.obj"
	-@erase "$(INTDIR)\CreateProduct.pch"
	-@erase "$(INTDIR)\CreateProduct.res"
	-@erase "$(INTDIR)\CreateProduct.sbr"
	-@erase "$(INTDIR)\CreateProductDlg.obj"
	-@erase "$(INTDIR)\CreateProductDlg.sbr"
	-@erase "$(INTDIR)\excel.obj"
	-@erase "$(INTDIR)\excel.sbr"
	-@erase "$(INTDIR)\font.obj"
	-@erase "$(INTDIR)\font.sbr"
	-@erase "$(INTDIR)\IniFile.obj"
	-@erase "$(INTDIR)\IniFile.sbr"
	-@erase "$(INTDIR)\Main.obj"
	-@erase "$(INTDIR)\Main.sbr"
	-@erase "$(INTDIR)\msflexgrid.obj"
	-@erase "$(INTDIR)\msflexgrid.sbr"
	-@erase "$(INTDIR)\OrderRelease.obj"
	-@erase "$(INTDIR)\OrderRelease.sbr"
	-@erase "$(INTDIR)\Password.obj"
	-@erase "$(INTDIR)\Password.sbr"
	-@erase "$(INTDIR)\picture.obj"
	-@erase "$(INTDIR)\picture.sbr"
	-@erase "$(INTDIR)\rowcursor.obj"
	-@erase "$(INTDIR)\rowcursor.sbr"
	-@erase "$(INTDIR)\Setting.obj"
	-@erase "$(INTDIR)\Setting.sbr"
	-@erase "$(INTDIR)\skdlluse.obj"
	-@erase "$(INTDIR)\skdlluse.sbr"
	-@erase "$(INTDIR)\Splash.obj"
	-@erase "$(INTDIR)\Splash.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\CreateProduct.bsc"
	-@erase "$(OUTDIR)\DEWAV_ODM_CreateProductTool.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\CreateProduct.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\CreateProduct.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CreateProduct.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\config.sbr" \
	"$(INTDIR)\CreateProduct.sbr" \
	"$(INTDIR)\CreateProductDlg.sbr" \
	"$(INTDIR)\excel.sbr" \
	"$(INTDIR)\font.sbr" \
	"$(INTDIR)\IniFile.sbr" \
	"$(INTDIR)\Main.sbr" \
	"$(INTDIR)\msflexgrid.sbr" \
	"$(INTDIR)\OrderRelease.sbr" \
	"$(INTDIR)\Password.sbr" \
	"$(INTDIR)\picture.sbr" \
	"$(INTDIR)\rowcursor.sbr" \
	"$(INTDIR)\Setting.sbr" \
	"$(INTDIR)\skdlluse.sbr" \
	"$(INTDIR)\Splash.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\CreateProduct.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=Adsapi32.lib Version.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\DEWAV_ODM_CreateProductTool.pdb" /machine:I386 /out:"$(OUTDIR)\DEWAV_ODM_CreateProductTool.exe" 
LINK32_OBJS= \
	"$(INTDIR)\config.obj" \
	"$(INTDIR)\CreateProduct.obj" \
	"$(INTDIR)\CreateProductDlg.obj" \
	"$(INTDIR)\excel.obj" \
	"$(INTDIR)\font.obj" \
	"$(INTDIR)\IniFile.obj" \
	"$(INTDIR)\Main.obj" \
	"$(INTDIR)\msflexgrid.obj" \
	"$(INTDIR)\OrderRelease.obj" \
	"$(INTDIR)\Password.obj" \
	"$(INTDIR)\picture.obj" \
	"$(INTDIR)\rowcursor.obj" \
	"$(INTDIR)\Setting.obj" \
	"$(INTDIR)\skdlluse.obj" \
	"$(INTDIR)\Splash.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\CreateProduct.res"

"$(OUTDIR)\DEWAV_ODM_CreateProductTool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CreateProduct - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\DEWAV_ODM_CreateProductTool.exe" "$(OUTDIR)\CreateProduct.bsc"


CLEAN :
	-@erase "$(INTDIR)\config.obj"
	-@erase "$(INTDIR)\config.sbr"
	-@erase "$(INTDIR)\CreateProduct.obj"
	-@erase "$(INTDIR)\CreateProduct.pch"
	-@erase "$(INTDIR)\CreateProduct.res"
	-@erase "$(INTDIR)\CreateProduct.sbr"
	-@erase "$(INTDIR)\CreateProductDlg.obj"
	-@erase "$(INTDIR)\CreateProductDlg.sbr"
	-@erase "$(INTDIR)\excel.obj"
	-@erase "$(INTDIR)\excel.sbr"
	-@erase "$(INTDIR)\font.obj"
	-@erase "$(INTDIR)\font.sbr"
	-@erase "$(INTDIR)\IniFile.obj"
	-@erase "$(INTDIR)\IniFile.sbr"
	-@erase "$(INTDIR)\Main.obj"
	-@erase "$(INTDIR)\Main.sbr"
	-@erase "$(INTDIR)\msflexgrid.obj"
	-@erase "$(INTDIR)\msflexgrid.sbr"
	-@erase "$(INTDIR)\OrderRelease.obj"
	-@erase "$(INTDIR)\OrderRelease.sbr"
	-@erase "$(INTDIR)\Password.obj"
	-@erase "$(INTDIR)\Password.sbr"
	-@erase "$(INTDIR)\picture.obj"
	-@erase "$(INTDIR)\picture.sbr"
	-@erase "$(INTDIR)\rowcursor.obj"
	-@erase "$(INTDIR)\rowcursor.sbr"
	-@erase "$(INTDIR)\Setting.obj"
	-@erase "$(INTDIR)\Setting.sbr"
	-@erase "$(INTDIR)\skdlluse.obj"
	-@erase "$(INTDIR)\skdlluse.sbr"
	-@erase "$(INTDIR)\Splash.obj"
	-@erase "$(INTDIR)\Splash.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\CreateProduct.bsc"
	-@erase "$(OUTDIR)\DEWAV_ODM_CreateProductTool.exe"
	-@erase "$(OUTDIR)\DEWAV_ODM_CreateProductTool.ilk"
	-@erase "$(OUTDIR)\DEWAV_ODM_CreateProductTool_V1.0.0.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\CreateProduct.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\CreateProduct.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CreateProduct.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\config.sbr" \
	"$(INTDIR)\CreateProduct.sbr" \
	"$(INTDIR)\CreateProductDlg.sbr" \
	"$(INTDIR)\excel.sbr" \
	"$(INTDIR)\font.sbr" \
	"$(INTDIR)\IniFile.sbr" \
	"$(INTDIR)\Main.sbr" \
	"$(INTDIR)\msflexgrid.sbr" \
	"$(INTDIR)\OrderRelease.sbr" \
	"$(INTDIR)\Password.sbr" \
	"$(INTDIR)\picture.sbr" \
	"$(INTDIR)\rowcursor.sbr" \
	"$(INTDIR)\Setting.sbr" \
	"$(INTDIR)\skdlluse.sbr" \
	"$(INTDIR)\Splash.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\CreateProduct.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=Adsapi32.lib Version.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\DEWAV_ODM_CreateProductTool_V1.0.0.pdb" /debug /machine:I386 /out:"$(OUTDIR)\DEWAV_ODM_CreateProductTool.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\config.obj" \
	"$(INTDIR)\CreateProduct.obj" \
	"$(INTDIR)\CreateProductDlg.obj" \
	"$(INTDIR)\excel.obj" \
	"$(INTDIR)\font.obj" \
	"$(INTDIR)\IniFile.obj" \
	"$(INTDIR)\Main.obj" \
	"$(INTDIR)\msflexgrid.obj" \
	"$(INTDIR)\OrderRelease.obj" \
	"$(INTDIR)\Password.obj" \
	"$(INTDIR)\picture.obj" \
	"$(INTDIR)\rowcursor.obj" \
	"$(INTDIR)\Setting.obj" \
	"$(INTDIR)\skdlluse.obj" \
	"$(INTDIR)\Splash.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\CreateProduct.res"

"$(OUTDIR)\DEWAV_ODM_CreateProductTool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("CreateProduct.dep")
!INCLUDE "CreateProduct.dep"
!ELSE 
!MESSAGE Warning: cannot find "CreateProduct.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "CreateProduct - Win32 Release" || "$(CFG)" == "CreateProduct - Win32 Debug"
SOURCE=.\config.cpp

"$(INTDIR)\config.obj"	"$(INTDIR)\config.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreateProduct.pch"


SOURCE=.\CreateProduct.cpp

"$(INTDIR)\CreateProduct.obj"	"$(INTDIR)\CreateProduct.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreateProduct.pch"


SOURCE=.\CreateProduct.rc

"$(INTDIR)\CreateProduct.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\CreateProductDlg.cpp

"$(INTDIR)\CreateProductDlg.obj"	"$(INTDIR)\CreateProductDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreateProduct.pch"


SOURCE=.\excel.cpp

"$(INTDIR)\excel.obj"	"$(INTDIR)\excel.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreateProduct.pch"


SOURCE=.\font.cpp

"$(INTDIR)\font.obj"	"$(INTDIR)\font.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreateProduct.pch"


SOURCE=.\IniFile.cpp

"$(INTDIR)\IniFile.obj"	"$(INTDIR)\IniFile.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreateProduct.pch"


SOURCE=.\Main.cpp

"$(INTDIR)\Main.obj"	"$(INTDIR)\Main.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreateProduct.pch"


SOURCE=.\msflexgrid.cpp

"$(INTDIR)\msflexgrid.obj"	"$(INTDIR)\msflexgrid.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreateProduct.pch"


SOURCE=.\OrderRelease.cpp

"$(INTDIR)\OrderRelease.obj"	"$(INTDIR)\OrderRelease.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreateProduct.pch"


SOURCE=.\Password.cpp

"$(INTDIR)\Password.obj"	"$(INTDIR)\Password.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreateProduct.pch"


SOURCE=.\picture.cpp

"$(INTDIR)\picture.obj"	"$(INTDIR)\picture.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreateProduct.pch"


SOURCE=.\rowcursor.cpp

"$(INTDIR)\rowcursor.obj"	"$(INTDIR)\rowcursor.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreateProduct.pch"


SOURCE=.\Setting.cpp

"$(INTDIR)\Setting.obj"	"$(INTDIR)\Setting.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreateProduct.pch"


SOURCE=.\skdlluse.cpp

"$(INTDIR)\skdlluse.obj"	"$(INTDIR)\skdlluse.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreateProduct.pch"


SOURCE=.\Splash.cpp

"$(INTDIR)\Splash.obj"	"$(INTDIR)\Splash.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreateProduct.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "CreateProduct - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\CreateProduct.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\CreateProduct.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CreateProduct - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\CreateProduct.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\CreateProduct.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

