
#****************************************************************************
#
# Makefile
# 
# This is a GNU make (gmake) makefile
# Author:Dive
#****************************************************************************
DIRS		:=src
DEBUG		:=NO
ONLYCXX		:=NO
OBJDIR		:=obj/${arm}

INCDIRS		=${DIRS}


#****************************************************************************
# Target
#****************************************************************************
TARGET		:=obj/${arm}/libailib.so

#****************************************************************************
# Compiler
#****************************************************************************
CC                 := ${CROSS_COMPILE}gcc
CXX                := ${CROSS_COMPILE}g++
AR                 := ${CROSS_COMPILE}ar
ARFLAGS            := rs
DEBUG_CFLAGS       := -fPIC -Wall -Wno-format -g 
RELEASE_CFLAGS     := -fPIC -Wall -Wno-unknown-pragmas -Wno-format -Os -g 

ifeq (${DEBUG},YES)
   CCFLAGS         += ${DEBUG_CFLAGS}
   CXXFLAGS        += ${DEBUG_CFLAGS}
else
   CCFLAGS         += ${RELEASE_CFLAGS}
   CXXFLAGS        += ${RELEASE_CFLAGS}
endif

#****************************************************************************
# Paths
#****************************************************************************
#$(shell find . -maxdepth 2 -type d)
INCPRJ=$(foreach dir,$(INCDIRS),$(join -I,$(dir)))

LIB_PATH           :=-L$(SRC_TOPDIR)/lib/$(arm) -L$(SRC_TOPDIR)/lib/$(arm)/lib_third -L$(SDK_TOPDIR)/lib

INC_PATH           := ${INCPRJ} \
                      -I${SRC_TOPDIR}/include \
		      -I${SRC_TOPDIR}/include/if \
		      -I${SRC_TOPDIR}/include/third
#****************************************************************************
# Source files
#****************************************************************************
ifeq (${ONLYCXX},NO)
SRCS               := ${foreach n,$(DIRS),$(wildcard ${n}/*.cpp ${n}/*.c)}
else
SRCS               := ${foreach n,$(DIRS),$(wildcard ${n}/*.cpp)}
endif

OBJS               := ${SRCS:%.cpp=${OBJDIR}/%.o}
OBJS               := ${OBJS:%.c=${OBJDIR}/%.o}
DEPE               := ${OBJS:%.o=%.d}
TMPDEF		   := ${foreach n,$(DIRS),$(wildcard ${n}/*.i)}


LIBS               :=-lpthread -ldl -lc -lgcc -lm -lrt

#****************************************************************************
# Output
#****************************************************************************
${TARGET}:${OBJS}
	${CXX} -fPIC -rdynamic -s -shared -o $@ ${LIB_PATH} ${OBJS} ${LIBS}
	${CROSS_COMPILE}strip ${TARGET}
	cp ${TARGET} /nsd/
-include $(DEPE) 

${OBJDIR}/%.o : %.cpp
	@[ -d $(@D) ] || mkdir -p $(@D)
	${CXX} -c ${CXXFLAGS} ${INC_PATH} $< -o $@

${OBJDIR}/%.d : %.cpp 
	@[ -d $(@D) ] || mkdir -p $(@D)
	@set -e; ${RM} $@; \
	$(CXX) -MM ${CXXFLAGS} ${INC_PATH} $< > $@.$$$$.i; \
	sed 's,\($(*F)\)\.o[ :]*,$*.o $@ : ,g' < $@.$$$$.i > $@; \
	${RM} $@.$$$$.i;

ifeq (${ONLYCXX},NO)
${OBJDIR}/%.o : %.c
	@[ -d $(@D) ] || mkdir -p $(@D)
	${CC} -c ${CCFLAGS} ${INC_PATH} $< -o $@

${OBJDIR}/%.d : %.c
	@[ -d $(@D) ] || mkdir -p $(@D)
	@set -e; ${RM} $@; \
	$(CC) -MM ${CCFLAGS} ${INC_PATH} $< > $@.$$$$.i; \
	sed 's,\($(*F)\)\.o[ :]*,$*.o $@ : ,g' < $@.$$$$.i > $@; \
	${RM} $@.$$$$.i;
endif	


.PHONY:all
all:${TARGET}

.PHONY:clean 
clean:
	${RM} ${TARGET} ${OBJS} ${DEPE} ${TMPDEF}


	 
