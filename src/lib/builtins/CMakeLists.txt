cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile builtins as static lib

set(BUILTINS_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${BUILTINS_BUILD_DIRECTORY})

#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(builtins STATIC
       echo/handle_esc_chars.c alias/alias_check_opt.c alias/alias_bash_error_print.c cd/cd.c cd/cd_path_canonization.c env/set.c env/unset.c env/export.c env/print_exported_env.c hash/hash.c echo/echo.c cd/cd_path_validation.c cd/cd_check_opt.c echo/echo.h cd/cd_error_print.c alias/unalias.c alias/alias.c alias/alias_usage_error_print.c
        history/history.c alias/alias_usage_error_print.c)

target_link_libraries(builtins cc env error hash)
