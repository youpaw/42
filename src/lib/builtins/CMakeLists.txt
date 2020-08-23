cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile builtins as static lib

set(BUILTINS_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${BUILTINS_BUILD_DIRECTORY})

#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(builtins STATIC
        cd.c)

target_link_libraries(builtins cc env)
