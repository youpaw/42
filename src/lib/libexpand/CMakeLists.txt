cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libexpand as static lib

set(LIBEXPAND_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${LIBEXPAND_BUILD_DIRECTORY})

#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(expand STATIC
        expand_raw.c
        get_brace.c
        handle_back_slash.c handle_single_quote.c handle_double_quote.c handle_dollar.c handle_bang.c handle_tilda.c handle_unset.c)

target_link_libraries(expand cc)
target_link_libraries(expand env)