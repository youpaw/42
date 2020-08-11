cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libexpand as static lib

set(LIBEXPAND_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${LIBEXPAND_BUILD_DIRECTORY})

#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(expand STATIC
        handle_raw.c
        get_brace.c
        validate_back_slash.c validate_single_quote.c validate_double_quote.c validate_dollar.c validate_bang.c expand_tilda.c expand_back_slash.c expand_dollar.c get_current_state.c handle_all.c)

target_link_libraries(expand cc)
target_link_libraries(expand env)