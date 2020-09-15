cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libcc as static lib

set(BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${BUILD_DIRECTORY})


ADD_LIBRARY(hash STATIC
        hash_init.c hash_insert.c hash_print.c hash_del.c hash_get_path.c hash_get_bin_path.c)

target_link_libraries(hash cc)
