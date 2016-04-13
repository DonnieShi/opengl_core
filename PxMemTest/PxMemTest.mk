##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=PxMemTest
ConfigurationName      :=Debug
WorkspacePath          := "D:\gits\opengl_core"
ProjectPath            := "D:\gits\opengl_core\PxMemTest"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Administrator
Date                   :=12/04/2016
CodeLitePath           :="E:\application\CodeLite"
LinkerName             :=E:/tdmgcc32/bin/g++.exe
SharedObjectLinkerName :=E:/tdmgcc32/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="PxMemTest.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=E:/tdmgcc32/bin/windres.exe
LinkOptions            :=  
IncludePath            := $(IncludeSwitch)E:/tdmgcclib/include $(IncludeSwitch)E:/tdmgcclib/include/freetype $(IncludeSwitch)F:/opengl/wxWidgets-3.0.2/include $(IncludeSwitch)F:/opengl/wxWidgets-3.0.2  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../core/cmn 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                :=$(LibraryPathSwitch)E:/tdmgcclib/lib $(LibraryPathSwitch)F:/opengl/wxWidgets-3.0.2/lib  $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := E:/tdmgcc32/bin/ar.exe rcu
CXX      := E:/tdmgcc32/bin/g++.exe
CC       := E:/tdmgcc32/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := E:/tdmgcc32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=E:\application\CodeLite
BuildDir:=E:/projects/builds
WXWIN:=G:/wxwidgets
WXCFG:=gcc_lib/mswud
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/cmn_PxHash.cpp$(ObjectSuffix) $(IntermediateDirectory)/cmn_PxHashTable.cpp$(ObjectSuffix) $(IntermediateDirectory)/cmn_PxLog.cpp$(ObjectSuffix) $(IntermediateDirectory)/cmn_PxMem.cpp$(ObjectSuffix) $(IntermediateDirectory)/cmn_PxUtils.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/gits/opengl_core/PxMemTest/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/cmn_PxHash.cpp$(ObjectSuffix): ../core/cmn/PxHash.cpp $(IntermediateDirectory)/cmn_PxHash.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/gits/opengl_core/core/cmn/PxHash.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cmn_PxHash.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cmn_PxHash.cpp$(DependSuffix): ../core/cmn/PxHash.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cmn_PxHash.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cmn_PxHash.cpp$(DependSuffix) -MM "../core/cmn/PxHash.cpp"

$(IntermediateDirectory)/cmn_PxHash.cpp$(PreprocessSuffix): ../core/cmn/PxHash.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cmn_PxHash.cpp$(PreprocessSuffix) "../core/cmn/PxHash.cpp"

$(IntermediateDirectory)/cmn_PxHashTable.cpp$(ObjectSuffix): ../core/cmn/PxHashTable.cpp $(IntermediateDirectory)/cmn_PxHashTable.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/gits/opengl_core/core/cmn/PxHashTable.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cmn_PxHashTable.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cmn_PxHashTable.cpp$(DependSuffix): ../core/cmn/PxHashTable.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cmn_PxHashTable.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cmn_PxHashTable.cpp$(DependSuffix) -MM "../core/cmn/PxHashTable.cpp"

$(IntermediateDirectory)/cmn_PxHashTable.cpp$(PreprocessSuffix): ../core/cmn/PxHashTable.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cmn_PxHashTable.cpp$(PreprocessSuffix) "../core/cmn/PxHashTable.cpp"

$(IntermediateDirectory)/cmn_PxLog.cpp$(ObjectSuffix): ../core/cmn/PxLog.cpp $(IntermediateDirectory)/cmn_PxLog.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/gits/opengl_core/core/cmn/PxLog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cmn_PxLog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cmn_PxLog.cpp$(DependSuffix): ../core/cmn/PxLog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cmn_PxLog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cmn_PxLog.cpp$(DependSuffix) -MM "../core/cmn/PxLog.cpp"

$(IntermediateDirectory)/cmn_PxLog.cpp$(PreprocessSuffix): ../core/cmn/PxLog.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cmn_PxLog.cpp$(PreprocessSuffix) "../core/cmn/PxLog.cpp"

$(IntermediateDirectory)/cmn_PxMem.cpp$(ObjectSuffix): ../core/cmn/PxMem.cpp $(IntermediateDirectory)/cmn_PxMem.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/gits/opengl_core/core/cmn/PxMem.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cmn_PxMem.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cmn_PxMem.cpp$(DependSuffix): ../core/cmn/PxMem.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cmn_PxMem.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cmn_PxMem.cpp$(DependSuffix) -MM "../core/cmn/PxMem.cpp"

$(IntermediateDirectory)/cmn_PxMem.cpp$(PreprocessSuffix): ../core/cmn/PxMem.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cmn_PxMem.cpp$(PreprocessSuffix) "../core/cmn/PxMem.cpp"

$(IntermediateDirectory)/cmn_PxUtils.cpp$(ObjectSuffix): ../core/cmn/PxUtils.cpp $(IntermediateDirectory)/cmn_PxUtils.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/gits/opengl_core/core/cmn/PxUtils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cmn_PxUtils.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cmn_PxUtils.cpp$(DependSuffix): ../core/cmn/PxUtils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cmn_PxUtils.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cmn_PxUtils.cpp$(DependSuffix) -MM "../core/cmn/PxUtils.cpp"

$(IntermediateDirectory)/cmn_PxUtils.cpp$(PreprocessSuffix): ../core/cmn/PxUtils.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cmn_PxUtils.cpp$(PreprocessSuffix) "../core/cmn/PxUtils.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


