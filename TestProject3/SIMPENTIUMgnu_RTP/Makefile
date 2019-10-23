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
PROJECT_TARGETS = company/$(MODE_DIR)/company.vxe \
	 monitor/$(MODE_DIR)/monitor.vxe


#Rules

# company
ifeq ($(DEBUG_MODE),1)
company/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
company/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
company/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
company/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
company/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
company/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler =  -O2  -fno-defer-pop
company/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler =  -O2  -fno-defer-pop
company/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
company/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
company/$(MODE_DIR)/% : DEBUGFLAGS_Assembler =  -O2  -fno-defer-pop
endif
company/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/usr/h/wrn/coreip 
company/$(MODE_DIR)/% : IDE_LIBRARIES = 
company/$(MODE_DIR)/% : IDE_DEFINES = -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" 
company/$(MODE_DIR)/% : PROJECT_TYPE = RTP
company/$(MODE_DIR)/% : DEFINES = 
company/$(MODE_DIR)/% : DO_STRIP = 0
company/$(MODE_DIR)/% : EXPAND_DBG = 0
company/$(MODE_DIR)/% : VX_CPU_FAMILY = simpentium
company/$(MODE_DIR)/% : CPU = SIMPENTIUM
company/$(MODE_DIR)/% : TOOL_FAMILY = gnu
company/$(MODE_DIR)/% : TOOL = gnu
company/$(MODE_DIR)/% : TOOL_PATH = 
company/$(MODE_DIR)/% : CC_ARCH_SPEC = -mtune=i486 -march=i486
company/$(MODE_DIR)/% : LIBPATH = 
company/$(MODE_DIR)/% : LIBS = -lstdc++
company/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
company/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
company/$(MODE_DIR)/% : OBJ_DIR := company/$(MODE_DIR)

company/$(MODE_DIR)/Objects/TestProject3/memoryInit.o : $(PRJ_ROOT_DIR)/memoryInit.c $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -std=c99 -fasm -Wall    -MD -MP $(IDE_DEFINES) $(DEFINES) $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


company/$(MODE_DIR)/Objects/TestProject3/test3.o : $(PRJ_ROOT_DIR)/test3.c $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -std=c99 -fasm -Wall    -MD -MP $(IDE_DEFINES) $(DEFINES) $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


OBJECTS_company = company/$(MODE_DIR)/Objects/TestProject3/memoryInit.o \
	 company/$(MODE_DIR)/Objects/TestProject3/test3.o

ifeq ($(TARGET_JOBS),1)
company/$(MODE_DIR)/company.vxe : $(OBJECTS_company)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -std=c99 -fasm -Wall    -MD -MP  -mrtp -o "$@" $(OBJECTS_company) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) -L$(VSB_DIR)/usr/lib/simpentium/SIMPENTIUM/common $(ADDED_LIBPATH) $(ADDED_LIBS) -Wl,--start-group -Wl,--end-group && if [ "$(DO_STRIP)" = "1" ]; then mv -f "$@" "$@.unstripped" && strippentium -g -o "$@" "$@.unstripped";fi && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

else
company/$(MODE_DIR)/company.vxe : company/$(MODE_DIR)/company.vxe_jobs

endif
company/$(MODE_DIR)/company_compile_file : $(FILE) ;

_clean :: company/$(MODE_DIR)/company_clean

company/$(MODE_DIR)/company_clean : 
	$(TRACE_FLAG)if [ -d "company" ]; then cd "company"; rm -rf $(MODE_DIR); fi


# monitor
ifeq ($(DEBUG_MODE),1)
monitor/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
monitor/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
monitor/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
monitor/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
monitor/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
monitor/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler =  -O2  -fno-defer-pop
monitor/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler =  -O2  -fno-defer-pop
monitor/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
monitor/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
monitor/$(MODE_DIR)/% : DEBUGFLAGS_Assembler =  -O2  -fno-defer-pop
endif
monitor/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/usr/h/wrn/coreip 
monitor/$(MODE_DIR)/% : IDE_LIBRARIES = 
monitor/$(MODE_DIR)/% : IDE_DEFINES = -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" 
monitor/$(MODE_DIR)/% : PROJECT_TYPE = RTP
monitor/$(MODE_DIR)/% : DEFINES = 
monitor/$(MODE_DIR)/% : DO_STRIP = 0
monitor/$(MODE_DIR)/% : EXPAND_DBG = 0
monitor/$(MODE_DIR)/% : VX_CPU_FAMILY = simpentium
monitor/$(MODE_DIR)/% : CPU = SIMPENTIUM
monitor/$(MODE_DIR)/% : TOOL_FAMILY = gnu
monitor/$(MODE_DIR)/% : TOOL = gnu
monitor/$(MODE_DIR)/% : TOOL_PATH = 
monitor/$(MODE_DIR)/% : CC_ARCH_SPEC = -mtune=i486 -march=i486
monitor/$(MODE_DIR)/% : LIBPATH = 
monitor/$(MODE_DIR)/% : LIBS = -lstdc++
monitor/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
monitor/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
monitor/$(MODE_DIR)/% : OBJ_DIR := monitor/$(MODE_DIR)

monitor/$(MODE_DIR)/Objects/TestProject3/monitor.o : $(PRJ_ROOT_DIR)/monitor.c $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -std=c99 -fasm -Wall    -MD -MP $(IDE_DEFINES) $(DEFINES) $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


OBJECTS_monitor = monitor/$(MODE_DIR)/Objects/TestProject3/monitor.o

ifeq ($(TARGET_JOBS),1)
monitor/$(MODE_DIR)/monitor.vxe : $(OBJECTS_monitor)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)c++pentium $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -mrtp -fno-strict-aliasing -D_C99 -D_HAS_C9X -std=c99 -fasm -Wall    -MD -MP  -mrtp -o "$@" $(OBJECTS_monitor) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) -L$(VSB_DIR)/usr/lib/simpentium/SIMPENTIUM/common $(ADDED_LIBPATH) $(ADDED_LIBS) -Wl,--start-group -Wl,--end-group && if [ "$(DO_STRIP)" = "1" ]; then mv -f "$@" "$@.unstripped" && strippentium -g -o "$@" "$@.unstripped";fi && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

else
monitor/$(MODE_DIR)/monitor.vxe : monitor/$(MODE_DIR)/monitor.vxe_jobs

endif
monitor/$(MODE_DIR)/monitor_compile_file : $(FILE) ;

_clean :: monitor/$(MODE_DIR)/monitor_clean

monitor/$(MODE_DIR)/monitor_clean : 
	$(TRACE_FLAG)if [ -d "monitor" ]; then cd "monitor"; rm -rf $(MODE_DIR); fi

force : 

TARGET_JOBS_RULE?=echo "Update the makefile template via File > Import > Build Settings : Update makefile template";exit 1
%_jobs : 
	$(TRACE_FLAG)$(TARGET_JOBS_RULE)

DEP_FILES := company/$(MODE_DIR)/Objects/TestProject3/memoryInit.d company/$(MODE_DIR)/Objects/TestProject3/test3.d monitor/$(MODE_DIR)/Objects/TestProject3/monitor.d
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
