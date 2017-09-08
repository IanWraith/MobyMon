# Microsoft Developer Studio Generated NMAKE File, Format Version 40001
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=mobymon - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to mobymon - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "mobymon - Win32 Release" && "$(CFG)" !=\
 "mobymon - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "mobymon.mak" CFG="mobymon - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mobymon - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "mobymon - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "mobymon - Win32 Debug"
CPP=cl.exe
MTL=mktyplib.exe
RSC=rc.exe

!IF  "$(CFG)" == "mobymon - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\mobymon.exe"

CLEAN : 
	-@erase ".\Release\mobymon.exe"
	-@erase ".\Release\man_select.obj"
	-@erase ".\Release\mobymon.pch"
	-@erase ".\Release\comselect.obj"
	-@erase ".\Release\StdAfx.obj"
	-@erase ".\Release\remote.obj"
	-@erase ".\Release\mobymon.obj"
	-@erase ".\Release\MainFrm.obj"
	-@erase ".\Release\mobymonView.obj"
	-@erase ".\Release\mobymonDoc.obj"
	-@erase ".\Release\mobymon.res"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/mobymon.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /c 
CPP_OBJS=.\Release/
CPP_SBRS=
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x809 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x809 /fo"$(INTDIR)/mobymon.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/mobymon.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/mobymon.pdb" /machine:I386 /out:"$(OUTDIR)/mobymon.exe" 
LINK32_OBJS= \
	"$(INTDIR)/man_select.obj" \
	"$(INTDIR)/comselect.obj" \
	"$(INTDIR)/StdAfx.obj" \
	"$(INTDIR)/remote.obj" \
	"$(INTDIR)/mobymon.obj" \
	"$(INTDIR)/MainFrm.obj" \
	"$(INTDIR)/mobymonView.obj" \
	"$(INTDIR)/mobymonDoc.obj" \
	"$(INTDIR)/mobymon.res"

"$(OUTDIR)\mobymon.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "mobymon - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\mobymon.exe"

CLEAN : 
	-@erase ".\Debug\vc40.pdb"
	-@erase ".\Debug\mobymon.pch"
	-@erase ".\Debug\vc40.idb"
	-@erase ".\Debug\mobymon.exe"
	-@erase ".\Debug\comselect.obj"
	-@erase ".\Debug\mobymonView.obj"
	-@erase ".\Debug\man_select.obj"
	-@erase ".\Debug\remote.obj"
	-@erase ".\Debug\StdAfx.obj"
	-@erase ".\Debug\mobymon.obj"
	-@erase ".\Debug\MainFrm.obj"
	-@erase ".\Debug\mobymonDoc.obj"
	-@erase ".\Debug\mobymon.res"
	-@erase ".\Debug\mobymon.ilk"
	-@erase ".\Debug\mobymon.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/mobymon.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x809 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x809 /fo"$(INTDIR)/mobymon.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/mobymon.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/mobymon.pdb" /debug /machine:I386 /out:"$(OUTDIR)/mobymon.exe" 
LINK32_OBJS= \
	"$(INTDIR)/comselect.obj" \
	"$(INTDIR)/mobymonView.obj" \
	"$(INTDIR)/man_select.obj" \
	"$(INTDIR)/remote.obj" \
	"$(INTDIR)/StdAfx.obj" \
	"$(INTDIR)/mobymon.obj" \
	"$(INTDIR)/MainFrm.obj" \
	"$(INTDIR)/mobymonDoc.obj" \
	"$(INTDIR)/mobymon.res"

"$(OUTDIR)\mobymon.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "mobymon - Win32 Release"
# Name "mobymon - Win32 Debug"

!IF  "$(CFG)" == "mobymon - Win32 Release"

!ELSEIF  "$(CFG)" == "mobymon - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "mobymon - Win32 Release"

!ELSEIF  "$(CFG)" == "mobymon - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\mobymon.cpp
DEP_CPP_MOBYM=\
	".\StdAfx.h"\
	".\mobymon.h"\
	".\MainFrm.h"\
	".\mobymonDoc.h"\
	".\mobymonView.h"\
	

"$(INTDIR)\mobymon.obj" : $(SOURCE) $(DEP_CPP_MOBYM) "$(INTDIR)"\
 "$(INTDIR)\mobymon.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "mobymon - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/mobymon.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\mobymon.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "mobymon - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/mobymon.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\mobymon.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\StdAfx.h"\
	".\mobymon.h"\
	".\MainFrm.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\mobymon.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\mobymonDoc.cpp
DEP_CPP_MOBYMO=\
	".\StdAfx.h"\
	".\mobymon.h"\
	".\mobymonDoc.h"\
	

"$(INTDIR)\mobymonDoc.obj" : $(SOURCE) $(DEP_CPP_MOBYMO) "$(INTDIR)"\
 "$(INTDIR)\mobymon.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\mobymonView.cpp
DEP_CPP_MOBYMON=\
	".\StdAfx.h"\
	".\mobymon.h"\
	".\mobymonDoc.h"\
	".\mobymonView.h"\
	".\comselect.h"\
	".\remote.h"\
	".\man_select.h"\
	

"$(INTDIR)\mobymonView.obj" : $(SOURCE) $(DEP_CPP_MOBYMON) "$(INTDIR)"\
 "$(INTDIR)\mobymon.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\mobymon.rc
DEP_RSC_MOBYMON_=\
	".\res\mobymon.ico"\
	".\res\icon1.ico"\
	".\res\mobymon.rc2"\
	

"$(INTDIR)\mobymon.res" : $(SOURCE) $(DEP_RSC_MOBYMON_) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\comselect.cpp
DEP_CPP_COMSE=\
	".\StdAfx.h"\
	".\mobymon.h"\
	".\comselect.h"\
	

"$(INTDIR)\comselect.obj" : $(SOURCE) $(DEP_CPP_COMSE) "$(INTDIR)"\
 "$(INTDIR)\mobymon.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\remote.cpp
DEP_CPP_REMOT=\
	".\StdAfx.h"\
	".\mobymon.h"\
	".\remote.h"\
	

"$(INTDIR)\remote.obj" : $(SOURCE) $(DEP_CPP_REMOT) "$(INTDIR)"\
 "$(INTDIR)\mobymon.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\man_select.cpp
DEP_CPP_MAN_S=\
	".\StdAfx.h"\
	".\mobymon.h"\
	".\man_select.h"\
	

"$(INTDIR)\man_select.obj" : $(SOURCE) $(DEP_CPP_MAN_S) "$(INTDIR)"\
 "$(INTDIR)\mobymon.pch"


# End Source File
# End Target
# End Project
################################################################################
