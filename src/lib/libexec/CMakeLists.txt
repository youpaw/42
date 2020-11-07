cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libcc as static lib

set(BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${BUILD_DIRECTORY})


ADD_LIBRARY(exec STATIC
        exec.c
        exec_complete_cmd.c
        exec_list.c exec_and_or.c exec_pipeline.c exec_pipe_seq.c exec_simple_cmd.c ../libjob/get_args.c ../libjob/prepare_exec_env.c ../libjob/get_redirect_nodes.c expand_ast.c ../libjob/prepare_redirect.c get_command.c ../libjob/redirect_heredoc.c ../libjob/redirect_less.c ../libjob/redirect_great.c ../libjob/redirect_init_process_file.c ../libjob/redirect_less_and.c ../libjob/redirect_great_and.c ../libjob/redirect_parse_left_side.c ../libjob/redirect_parse_right_side.c ../libjob/is_minus.c ../libjob/redirect_print_error.c ../libjob/redirect_close_stdio.c)

target_link_libraries(exec cc env parser builtins hash jobs error)
