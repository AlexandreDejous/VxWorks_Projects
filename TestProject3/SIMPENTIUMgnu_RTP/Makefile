# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))
WRVX_COMPBASE := $(subst \,/,$(WRVX_COMPBASE))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

JOBS?=1
TARGET_JOBS?=$(JOBS)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = SIMPENTIUMgnu_RTP
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := /home/dejouale/WindRiver/workspace
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/TestProject3



#Global Build Macros
PROJECT_TYPE = RTP
DEFINES = 
DO_STRIP = 0
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = simpentium
CPU = SIMPENTIUM
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mtune=i486 -march=i486
LIBPATH = 
LIBS = -lstdc++
VSB_DIR = $(WIND_BASE)/target/lib
VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h

IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/usr/h/wrn/coreip 

IDE_LIBRARIES = 

IDE_DEFINES = -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler =  -O2  -fno-defer-pop
DEBUGFLAGS_C++-Compiler =  -O2  -fno-defer-pop
DEBUGFLAGS_Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler =  -O2  -fno-defer-pop
endif


#Project Targets
PROJECT_TARGETS = TestProject3/$(MODE_DIR)/TestProject3.vxe


#Rules

# TestProject3
ifeq ($(DEBUG_MODE),1)
TestProject3/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
TestProject3/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
TestProject3/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
TestProject3/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
TestProject3/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
TestProject3/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler =  -O2  -fno-defer-pop
TestProject3/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler =  -O2  -fno-defer-pop
TestProject3/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
TestProject3/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
TestProject3/$(MODE_DIR)/% : DEBUGFLAGS_Assembler =  -O2  -fno-defer-pop
endif
TestProject3/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/usr/h/wrn/coreip 
TestProject3/$(MODE_DIR)/% : IDE_LIBRARIES = 
TestProject3/$(MODE_DIR)/% : IDE_DEFINES = -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" 
TestProject3/$(MODE_DIR)/% : PROJECT_TYPE = RTP
TestProject3/$(MODE_DIR)/% : DEFINES = 
TestProject3/$(MODE_DIR)/% : DO_STRIP = 0
TestProject3/$(MODE_DIR)/% : EXPAND_DBG = 0
TestProject3/$(MODE_DIR)/% : VX_CPU_FAMILY = simpentium
TestProject3/$(MODE_DIR)/% : CPU = SIMPENTIUM
TestProject3/$(MODE_DIR)/% : TOOL_FAMILY = gnu
TestProject3/$(MODE_DIR)/% : TOOL = gnu
TestProject3/$(MODE_DIR)/% : TOOL_PATH = 
TestProject3/$(MODE_DIR)/% : CC_ARCH_SPEC = -mtune=i486 -march=i486
TestProject3/$(MODE_DIR)/% : LIBPATH = 
TestProject3/$(MODE_DIR)/% : LIBS = -lstdc++
TestProject3/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
TestProject3/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
TestProject3/$(MODE_DIR)/% : OBJ_DIR := TestProject3/$(MODE_DIR)

TestProject3/$(MODE_DIR)/Objects/TestProject3/test3.o : $(PRJ_ROOT_DIR)/test3.c $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -std=c99 -fasm -Wall    -MD -MP $(IDE_DEFINES) $(DEFINES) $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


OBJECTS_TestProject3 = TestProject3/$(MODE_DIR)/Objects/TestProject3/test3.o

ifeq ($(TARGET_JOBS),1)
TestProject3/$(MODE_DIR)/TestProject3.vxe : $(OBJECTS_TestProject3)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -std=c99 -fasm -Wall    -MD -MP  -mrtp -o "$@" $(OBJECTS_TestProject3) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) -L$(VSB_DIR)/usr/lib/simpentium/SIMPENTIUM/common $(ADDED_LIBPATH) $(ADDED_LIBS) -Wl,--start-group -Wl,--end-group && if [ "$(DO_STRIP)" = "1" ]; then mv -f "$@" "$@.unstripped" && strippentium -g -o "$@" "$@.unstripped";fi && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

else
TestProject3/$(MODE_DIR)/TestProject3.vxe : TestProject3/$(MODE_DIR)/TestProject3.vxe_jobs

endif
TestProject3/$(MODE_DIR)/TestProject3_compile_file : $(FILE) ;

_clean :: TestProject3/$(MODE_DIR)/TestProject3_clean

TestProject3/$(MODE_DIR)/TestProject3_clean : 
	$(TRACE_FLAG)if [ -d "TestProject3" ]; then cd "TestProject3"; rm -rf $(MODE_DIR); fi

force : 

TARGET_JOBS_RULE?=echo "Update the makefile template via File > Import > Build Settings : Update makefile template";exit 1
%_jobs : 
	$(TRACE_FLAG)$(TARGET_JOBS_RULE)

DEP_FILES := TestProject3/$(MODE_DIR)/Objects/TestProject3/test3.d
-include $(DEP_FILES)


WIND_SCOPETOOLS_BASE := $(subst \,/,$(WIND_SCOPETOOLS_BASE))

clean_scopetools :
	$(TRACE_FLAG)rm -rf $(PRJ_ROOT_DIR)/.coveragescope/db

CLEAN_STEP := clean_scopetools


-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

TARGET_JOBS_RULE=$(MAKE) -f $(MAKEFILE) --jobs $(TARGET_JOBS) $(MFLAGS) $* TARGET_JOBS=1
ifeq ($(JOBS),1)
main_all : external_build  $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"
else
main_all : external_build 
	@$(MAKE) -f $(MAKEFILE) --jobs $(JOBS) $(MFLAGS) $(PROJECT_TARGETS) TARGET_JOBS=1 &&\
	echo "make: built targets of `pwd`"
endif 

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
