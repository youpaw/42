cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libcc as static lib

set(BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${BUILD_DIRECTORY})


ADD_LIBRARY(exec STATIC
        exec.c
        exec_complete_cmd.c
        exec_list.c exec_and_or.c exec_pipeline.c exec_pipe_seq.c exec_simple_cmd.c get_args.c prepare_exec_env.c get_redirect_nodes.c expand_ast.c prepare_redirect.c get_command.c redirect_heredoc.c redirect_less.c redirect_great.c redirect_init_process_ioerr.c redirect_less_and.c redirect_great_and.c redirect_parse_left_side.c redirect_parse_right_side.c redirect_utils.c redirect_print_error.c redirect_minus_arg.c)

target_link_libraries(exec cc env parser builtins hash jobs error)
