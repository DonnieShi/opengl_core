##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=core
ConfigurationName      :=Debug
WorkspacePath          :=D:/git/opengl_core
ProjectPath            :=D:/git/opengl_core/core
IntermediateDirectory  :=../../tmp/$(ProjectName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=PHANTOM
Date                   :=27/03/2016
CodeLitePath           :=D:/app/CodeLite
LinkerName             :=F:/tdmgcc/bin/g++.exe
SharedObjectLinkerName :=F:/tdmgcc/bin/g++.exe -shared -fPIC
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
ObjectsFileList        :="core.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=F:/tdmgcc/bin/windres.exe
LinkOptions            :=  -lopengl32 -lgdi32
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := F:/tdmgcc/bin/ar.exe rcu
CXX      := F:/tdmgcc/bin/g++.exe
CC       := F:/tdmgcc/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := F:/tdmgcc/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=D:\app\CodeLite
Objects0=$(IntermediateDirectory)/src_gl3w.c$(ObjectSuffix) $(IntermediateDirectory)/core_ViewOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_ShaderOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_PxBase.cpp$(ObjectSuffix) $(IntermediateDirectory)/cmn_PxLog.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Application.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/src_gl3w.c$(ObjectSuffix): src/gl3w.c $(IntermediateDirectory)/src_gl3w.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/git/opengl_core/core/src/gl3w.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_gl3w.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_gl3w.c$(DependSuffix): src/gl3w.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_gl3w.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_gl3w.c$(DependSuffix) -MM "src/gl3w.c"

$(IntermediateDirectory)/src_gl3w.c$(PreprocessSuffix): src/gl3w.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_gl3w.c$(PreprocessSuffix) "src/gl3w.c"

$(IntermediateDirectory)/core_ViewOGL.cpp$(ObjectSuffix): core/ViewOGL.cpp $(IntermediateDirectory)/core_ViewOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/git/opengl_core/core/core/ViewOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_ViewOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_ViewOGL.cpp$(DependSuffix): core/ViewOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_ViewOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_ViewOGL.cpp$(DependSuffix) -MM "core/ViewOGL.cpp"

$(IntermediateDirectory)/core_ViewOGL.cpp$(PreprocessSuffix): core/ViewOGL.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_ViewOGL.cpp$(PreprocessSuffix) "core/ViewOGL.cpp"

$(IntermediateDirectory)/core_ShaderOGL.cpp$(ObjectSuffix): core/ShaderOGL.cpp $(IntermediateDirectory)/core_ShaderOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/git/opengl_core/core/core/ShaderOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_ShaderOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_ShaderOGL.cpp$(DependSuffix): core/ShaderOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_ShaderOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_ShaderOGL.cpp$(DependSuffix) -MM "core/ShaderOGL.cpp"

$(IntermediateDirectory)/core_ShaderOGL.cpp$(PreprocessSuffix): core/ShaderOGL.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_ShaderOGL.cpp$(PreprocessSuffix) "core/ShaderOGL.cpp"

$(IntermediateDirectory)/core_PxBase.cpp$(ObjectSuffix): core/PxBase.cpp $(IntermediateDirectory)/core_PxBase.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/git/opengl_core/core/core/PxBase.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_PxBase.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_PxBase.cpp$(DependSuffix): core/PxBase.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_PxBase.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_PxBase.cpp$(DependSuffix) -MM "core/PxBase.cpp"

$(IntermediateDirectory)/core_PxBase.cpp$(PreprocessSuffix): core/PxBase.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_PxBase.cpp$(PreprocessSuffix) "core/PxBase.cpp"

$(IntermediateDirectory)/cmn_PxLog.cpp$(ObjectSuffix): cmn/PxLog.cpp $(IntermediateDirectory)/cmn_PxLog.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/git/opengl_core/core/cmn/PxLog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cmn_PxLog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cmn_PxLog.cpp$(DependSuffix): cmn/PxLog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cmn_PxLog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cmn_PxLog.cpp$(DependSuffix) -MM "cmn/PxLog.cpp"

$(IntermediateDirectory)/cmn_PxLog.cpp$(PreprocessSuffix): cmn/PxLog.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cmn_PxLog.cpp$(PreprocessSuffix) "cmn/PxLog.cpp"

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/git/opengl_core/core/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Application.cpp$(ObjectSuffix): Application.cpp $(IntermediateDirectory)/Application.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/git/opengl_core/core/Application.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Application.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Application.cpp$(DependSuffix): Application.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Application.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Application.cpp$(DependSuffix) -MM "Application.cpp"

$(IntermediateDirectory)/Application.cpp$(PreprocessSuffix): Application.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Application.cpp$(PreprocessSuffix) "Application.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ../../tmp/$(ProjectName)/


