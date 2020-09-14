cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libalias as static lib

set(LIBALIAS_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${LIBALIAS_BUILD_DIRECTORY})

#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(alias STATIC
        alias_init.c alias_del.c alias_get_value.c alias_print.c alias_remove.c alias_add.c alias_cmp_pair.c alias_del_pair.c)

target_link_libraries(alias cc)