cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libcc as static lib

set(LIBCC_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${LIBCC_BUILD_DIRECTORY})
include_directories(validate recognize)
#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(lex STATIC
		type_to_string.c
		lex_str.c
		recognize/recognize_tokens.c
		validate/validate_input.c
		validate/v_handle_bs.c
		validate/v_handle_sq.c
		validate/v_handle_dq.c
		validate/v_handle_us.c
		validate/v_handle_dollar.c
		get_brace.c
		validate/v_handle_bang.c)


target_link_libraries(lex cc)