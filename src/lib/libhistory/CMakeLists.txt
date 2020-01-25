cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libcc as static lib

set(BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${BUILD_DIRECTORY})


ADD_LIBRARY(history STATIC
        h_dlist.c
        h_dlist2.c
        h_file.c
        )

        
target_link_libraries(history cc)
target_link_libraries(history lists)