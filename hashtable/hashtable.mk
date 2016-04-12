##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=hashtable
ConfigurationName      :=Debug
WorkspacePath          :=E:/develop/code/opengl_core
ProjectPath            :=E:/develop/code/opengl_core/hashtable
IntermediateDirectory  :=../../tmp/$(ProjectName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=phantom
Date                   :=09/04/2016
CodeLitePath           :=E:/develop/CodeLite
LinkerName             :=E:/develop/tdmgcc/bin/g++.exe
SharedObjectLinkerName :=E:/develop/tdmgcc/bin/g++.exe -shared -fPIC
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
OutputFile             :=../../bin/$(ProjectName)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="hashtable.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=E:/develop/tdmgcc/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../core/cmn 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := E:/develop/tdmgcc/bin/ar.exe rcu
CXX      := E:/develop/tdmgcc/bin/g++.exe
CC       := E:/develop/tdmgcc/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := E:/develop/tdmgcc/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=E:\develop\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/cmn_PxLog.cpp$(ObjectSuffix) $(IntermediateDirectory)/cmn_PxHashTable.cpp$(ObjectSuffix) $(IntermediateDirectory)/cmn_PxHash.cpp$(ObjectSuffix) $(IntermediateDirectory)/cmn_PxUtils.cpp$(ObjectSuffix) 



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
	@$(MakeDirCommand) "../../tmp/$(ProjectName)"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "../../tmp/$(ProjectName)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/develop/code/opengl_core/hashtable/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/cmn_PxLog.cpp$(ObjectSuffix): ../core/cmn/PxLog.cpp $(IntermediateDirectory)/cmn_PxLog.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/develop/code/opengl_core/core/cmn/PxLog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cmn_PxLog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cmn_PxLog.cpp$(DependSuffix): ../core/cmn/PxLog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cmn_PxLog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cmn_PxLog.cpp$(DependSuffix) -MM "../core/cmn/PxLog.cpp"

$(IntermediateDirectory)/cmn_PxLog.cpp$(PreprocessSuffix): ../core/cmn/PxLog.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cmn_PxLog.cpp$(PreprocessSuffix) "../core/cmn/PxLog.cpp"

$(IntermediateDirectory)/cmn_PxHashTable.cpp$(ObjectSuffix): ../core/cmn/PxHashTable.cpp $(IntermediateDirectory)/cmn_PxHashTable.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/develop/code/opengl_core/core/cmn/PxHashTable.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cmn_PxHashTable.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cmn_PxHashTable.cpp$(DependSuffix): ../core/cmn/PxHashTable.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cmn_PxHashTable.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cmn_PxHashTable.cpp$(DependSuffix) -MM "../core/cmn/PxHashTable.cpp"

$(IntermediateDirectory)/cmn_PxHashTable.cpp$(PreprocessSuffix): ../core/cmn/PxHashTable.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cmn_PxHashTable.cpp$(PreprocessSuffix) "../core/cmn/PxHashTable.cpp"

$(IntermediateDirectory)/cmn_PxHash.cpp$(ObjectSuffix): ../core/cmn/PxHash.cpp $(IntermediateDirectory)/cmn_PxHash.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/develop/code/opengl_core/core/cmn/PxHash.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cmn_PxHash.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cmn_PxHash.cpp$(DependSuffix): ../core/cmn/PxHash.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cmn_PxHash.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cmn_PxHash.cpp$(DependSuffix) -MM "../core/cmn/PxHash.cpp"

$(IntermediateDirectory)/cmn_PxHash.cpp$(PreprocessSuffix): ../core/cmn/PxHash.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cmn_PxHash.cpp$(PreprocessSuffix) "../core/cmn/PxHash.cpp"

$(IntermediateDirectory)/cmn_PxUtils.cpp$(ObjectSuffix): ../core/cmn/PxUtils.cpp $(IntermediateDirectory)/cmn_PxUtils.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/develop/code/opengl_core/core/cmn/PxUtils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cmn_PxUtils.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cmn_PxUtils.cpp$(DependSuffix): ../core/cmn/PxUtils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cmn_PxUtils.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cmn_PxUtils.cpp$(DependSuffix) -MM "../core/cmn/PxUtils.cpp"

$(IntermediateDirectory)/cmn_PxUtils.cpp$(PreprocessSuffix): ../core/cmn/PxUtils.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cmn_PxUtils.cpp$(PreprocessSuffix) "../core/cmn/PxUtils.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ../../tmp/$(ProjectName)/


