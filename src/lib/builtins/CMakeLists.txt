cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile builtins as static lib

set(BUILTINS_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${BUILTINS_BUILD_DIRECTORY})

#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(builtins STATIC
        cd/cd.c cd/path_canonization.c env/set.c env/unset.c env/export.c sh_exit/sh_exit.c run_builtin.c env/print_exported_env.c hash/hash.c echo/echo.c cd/check_av.c)

target_link_libraries(builtins cc env error hash)
