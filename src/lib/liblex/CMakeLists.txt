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
		tok_dollar.c
		tok_double_quote.c
		lex_map.c
		lex_raw.c
		tok_single_quote.c
        token_type_to_string.c
		vld_bang.c
		destruct_tokens.c
		vld_back_slash.c
		tok_bang.c
		tok_unset.c
		get_operator.c
		exp_single_quote.c exp_double_quote.c exp_unset.c recognize_token.c print_tokens.c recognize_operator.c is_operator.c is_delimiter.c is_redirection.c is_number.c destruct_token.c match_brace.c match_bang.c get_tokens.c lex_del.c lex_err.c validate_str.c strjoin_expanded.c match_tilda.c expand_token.c vld_heredoc.c match_parameter.c is_doublequote_esc.c)


target_link_libraries(lex cc expand env)
