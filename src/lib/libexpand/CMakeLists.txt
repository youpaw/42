cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libexpand as static lib

set(LIBEXPAND_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${LIBEXPAND_BUILD_DIRECTORY})

#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(expand STATIC
        expand_raw.c
        expand_input.c
        get_brace.c
        expand_input_handler.c)

target_link_libraries(expand cc)
target_link_libraries(expand env)