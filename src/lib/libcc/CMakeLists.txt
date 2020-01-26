cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libcc as static lib

set(LIBCC_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${LIBCC_BUILD_DIRECTORY})

#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(cc STATIC
		file_exists.c
		str_append.c
		str_contains.c
		str_equals.c
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
		strsplitcharset.c
		strchr.c
		vec_init.c
		vec_push.c
		memalloc.c
		memcpy.c
		strtrim.c
		str_starts_with.c
		)

