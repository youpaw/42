cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile readline as static lib

set(READLINE_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${READLINE_BUILD_DIRECTORY})

#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(readline STATIC
        readline.c
        termcap_init.c complete_print.c handle_right_arrow.c handle_del.c handle_escape_sequense.c handle_symdol_key.c handle_tab.c tty_init.c tty_restore.c input_to_str.c get_displayed_symbol_length.c handle_file_token.c choose_token.c input_init.c handle_key.c handle_left_arrow.c handle_backspace.c signal_init.c signal_handler.c handle_shift_up.c handle_shift_down.c common_redraw.c check_input_adding.c check_input_del.c hancle_choice_tab.c try_to_print_same_part.c print_propmt.c)

target_link_libraries(readline cc termcap)

