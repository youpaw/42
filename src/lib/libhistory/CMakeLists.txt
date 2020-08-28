cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libcc as static lib

set(BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${BUILD_DIRECTORY})


ADD_LIBRARY(history STATIC
        hist_init.c
        hist_save.c hist_print.c hist_get_by_index.c hist_get_by_prefix.c hist_get_last.c hist_get_prev.c hist_get_next.c hist_reset_cur_ind.c hist_push.c)

        
target_link_libraries(history cc)
