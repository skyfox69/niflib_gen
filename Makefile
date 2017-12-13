MAKE=make
SHELL=/bin/sh

default: niflib_gen

CC = g++

#CFLAGS = -g -O0 -std=c++14 -pipe -fexceptions -fstack-protector --param=ssp-buffer-size=4 -m64 -D_GNU_SOURCE -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -fno-strict-aliasing -fwrapv -fPIC -static-libgcc -fno-omit-frame-pointer -DMY_PTHREAD_FASTMUTEX=1
CFLAGS = -g -O -std=c++14 -I. -pipe -fexceptions -fstack-protector --param=ssp-buffer-size=4 -m64 -D_GNU_SOURCE -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -fno-strict-aliasing -fwrapv -fPIC -static-libgcc -fno-omit-frame-pointer -DMY_PTHREAD_FASTMUTEX=1 

LIBS =

LDFLAGS = -g -lpthread -lz -lm -lrt -ldl

PRG = niflib_gen
SRC = main.cpp \
      util/xmlfile.cpp \
      util/classdata.cpp \
      util/codegenerator.cpp \
      util/codegenbase.cpp \
      util/codegenniobject.cpp \

OBJ = ${SRC:%.cpp=%.o}

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ ${@:.o=.cpp}

${PRG}: ${OBJ}
	$(CC) $(LDFLAGS) -o ${PRG} ${OBJ} $(LIBS)

clean:
	rm -f ${PRG}
	rm -f ${OBJ}

rebuild: clean niflib_gen

