cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libcc as static lib

set(BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${BUILD_DIRECTORY})


ADD_LIBRARY(exec STATIC
        exec.c
        exec_complete_cmd.c
        exec_list.c exec_and_or.c exec_pipeline.c exec_pipe_seq.c exec_simple_cmd.c)

target_link_libraries(exec cc env parser builtins)
