cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libcc as static lib

set(LIBCC_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${LIBCC_BUILD_DIRECTORY})

#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(cc STATIC
        strnew.c
		strcmp.c
		nstrjoin.c
		xmalloc.c
		memset.c
		strstr.c
		isspace.c
		memmove.c
		strdup.c
		strlen.c
		strcpy.c
		strcat.c
		bzero.c
		strncmp.c
		strncpy.c
		strsub.c
		fdputs.c
		atoll.c
		isdigit.c
		strsplitcharset.c)

