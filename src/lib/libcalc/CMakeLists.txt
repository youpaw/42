cmake_minimum_required(VERSION 3.8)

set(LIBCALC_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${LIBCALC_BUILD_DIRECTORY})
#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(calc STATIC
        calc_str.c
        )

target_link_libraries(calc cc)