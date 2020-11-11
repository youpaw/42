cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile readline as static lib

set(READLINE_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${READLINE_BUILD_DIRECTORY})

#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(readline STATIC
        readline.c
        handle_command_token.c fill_complition_graph.c handle_right_arrow.c handle_del.c handle_escape_sequense.c handle_symdol_key.c handle_tab.c tty_init.c tty_restore.c input_to_str.c handle_file_token.c input_init.c handle_key.c handle_left_arrow.c handle_backspace.c signal_init.c signal_handler.c handle_shift_up.c handle_shift_down.c common_redraw.c redraw_input_redline.c handle_choice_tab.c try_to_print_same_part.c print_propmt.c handle_shift_right.c handle_shift_left.c get_predict_token.c del_predict_token.c select_choise.c input_to_n_str.c clear_last_disp_token.c handle_param_token.c handle_up_arrow.c handle_down_arrow.c clear_display_input.c hist_storage.c handle_home_key.c handle_end_key.c check_for_utf8_comb_charecter.c put_str_to_input.c reload_input.c redraw_input.c put_cursor_to_the_end.c split_newline.c handle_EOX.c handle_EOT.c del_inp_structure.c parse_filename.c)

target_link_libraries(readline ft_select cc lex termcap)

