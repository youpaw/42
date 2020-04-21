cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libcc as static lib

set(BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${BUILD_DIRECTORY})


ADD_LIBRARY(parser STATIC
        parse.c
        node_complete_cmd.c
        node_list.c
        node_pipeline.c
        node_pipe_seq.c
        node_command.c
        node_simple_cmd.c
        node_cmd_prefix.c
        node_cmd_suffix.c
        node_io_redirect.c
        node_filename.c
        node_io_file.c
        node_and_or.c
        new_ast_node.c
        get_token_attr.c
        del_ast_node.c)

target_link_libraries(parser cc)
