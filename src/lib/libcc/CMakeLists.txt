cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libcc as static lib

set(LIBCC_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${LIBCC_BUILD_DIRECTORY})

#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})
include_directories(char string memory vector math search list)

ADD_LIBRARY(cc STATIC
		string/strnew.c
		string/strcmp.c
		string/nstrjoin.c
		string/strstr.c
		string/strdup.c
		string/strlen.c
		string/strcpy.c
		string/strcat.c
		string/strncmp.c
		string/strncpy.c
		string/strsub.c
		string/fdputs.c
		string/atoll.c
		string/strtrim.c
		string/strsplitcharset.c
		string/strchr.c
		string/strnstr.c
		char/isspace.c
		char/isdigit.c
		memory/xmalloc.c
		memory/memset.c
		memory/memmove.c
		memory/bzero.c
		memory/memalloc.c
		memory/memcpy.c
		vector/vec_del.c
		vector/vec_init.c
		vector/vec_push.c
		vector/vec_remove.c
		math/max.c
		math/min.c
		search/avl_del.c
		search/avl_get_height.c
		search/avl_insert.c
		search/avl_new_node.c
		list/lst_add.c
		list/lst_add_sort.c
		list/lst_circle.c
		list/lst_del.c
		list/lst_del_circle.c
		list/lst_del_one.c
		list/lst_iter.c
		list/lst_map.c
		list/lst_new.c
		char/isalpha.c char/isupper.c char/islower.c char/isalnum.c search/avl_balance.c search/avl_get_node.c search/avl_pop.c search/avl_map_prefix.c search/avl_map_infix.c search/avl_map_postfix.c)

