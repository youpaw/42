cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libcc as static lib

set(LIBCC_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${LIBCC_BUILD_DIRECTORY})

#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})
include_directories(char string memory vector math avl hash list)

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
		vector/vec_new.c
		vector/vec_push.c
		vector/vec_rm_last.c
		math/max.c
		math/min.c
		avl/avl_del.c
		avl/avl_get_height.c
		avl/avl_insert.c
		avl/avl_new_node.c
		list/lst_add.c
		list/lst_add_sort.c
		list/lst_circle.c
		list/lst_del.c
		list/lst_del_circle.c
		list/lst_del_one.c
		list/lst_iter.c
		list/lst_map.c
		list/lst_new.c
		vector/vec_rm_at.c
		vector/vec_get_at.c
		vector/vec_get_last.c
		char/isalpha.c
		char/isupper.c
		char/islower.c
		char/isalnum.c
		avl/avl_balance.c
		avl/avl_get.c
		avl/avl_del_one.c
		avl/avl_map_prefix.c
		avl/avl_map_infix.c
		avl/avl_map_postfix.c
		hash/hash_new.c
		hash/hash_insert.c
		hash/hash_get.c
		hash/hash_get_pair.c
		hash/hash_get_val.c
		hash/hash_del_one.c
		hash/hash_del.c
		avl/avl_new.c
		avl/avl_get_pair.c
		avl/avl_get_val.c
		string/strhash.c hash/hash_iter.c hash/hash_iter_pair.c)

