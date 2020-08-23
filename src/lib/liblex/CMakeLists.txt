cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libcc as static lib

set(LIBCC_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${LIBCC_BUILD_DIRECTORY})
#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(lex STATIC
		exp_back_slash.c
		exp_dollar.c
		get_brace.c
		get_current_state.c
		lex_str.c
		tok_dollar.c
		tok_double_quote.c
		lex_map.c
		lex_raw.c
		tok_single_quote.c
		type_to_string.c
		vld_bang.c
		vld_back_slash.c
		lex_str_len.c destruct_tokens.c tok_back_slash.c tok_bang.c tok_unset.c)


target_link_libraries(lex cc)
target_link_libraries(lex expand)
target_link_libraries(lex env)