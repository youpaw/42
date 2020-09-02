cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libexpand as static lib

set(LIBEXPAND_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${LIBEXPAND_BUILD_DIRECTORY})

#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(expand STATIC
        expand_tilda.c expand_parameter.c expand_bang.c expand_by_type.c get_env_or_av_value.c expand_prefix.c expand_suffix.c)

target_link_libraries(expand cc)
target_link_libraries(expand env)
