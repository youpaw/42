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
        tokenize_str.c
		tok_dollar.c
		tok_double_quote.c
		lex_map.c
		lex_raw.c
		tok_single_quote.c
        token_type_to_string.c
		vld_bang.c
		vld_back_slash.c
		tokenize_str_sub.c
		destruct_tokens.c
		tok_back_slash.c
		tok_bang.c
		tok_unset.c
		get_operator.c
		exp_single_quote.c exp_double_quote.c exp_unset.c recognize_token.c print_tokens.c recognize_operator.c get_last_token.c is_operator.c is_delimiter.c is_redirection.c is_number.c destruct_token.c match_brace.c match_bang.c get_tokens.c lex_del.c lex_err.c validate_str.c)


target_link_libraries(lex cc)
target_link_libraries(lex expand)
target_link_libraries(lex env)