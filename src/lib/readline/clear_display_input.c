//
// Created by Maxon Gena on 11/5/20.
//

#include "readline.h"
#include "cc_char.h"
#include "termcap.h"

void clear_begin_and_after_cursor(t_input *inp)
{
	while (inp->cursor_x_position != inp->line_len[inp->cursor_y_position])
		handle_del(inp);
	while (inp->cursor_x_position - get_prompt_len(inp->cursor_y_position))
		handle_backspace(inp);
}
void clear_second_display_input(t_input *inp)
{
	clear_begin_and_after_cursor(inp);
	handle_shift_up(inp);
}

void clear_first_display_input(t_input *inp)
{
	clear_begin_and_after_cursor(inp);
}

void put_cursor_to_the_end(t_input *inp)
{
	while (inp->line[inp->cursor_y_position + 1])
		handle_shift_down(inp);
	while (inp->cursor_x_position != inp->line_len[inp->cursor_y_position])
		handle_right_arrow(inp);
}

void clear_display_input(t_input *inp)
{
	size_t prev_lines_count;

	put_cursor_to_the_end(inp);
	prev_lines_count = inp->cursor_y_position;
	while (inp->cursor_y_position)
	{
		clear_second_display_input(inp);
	}
	clear_first_display_input(inp);
	tputs(tgetstr("sc", NULL), 1, putchar);
	while (prev_lines_count-- != 0)
	{
		tputs(tgetstr("do", NULL), 1, putchar);
		tputs(tgetstr("cr", NULL), 1, putchar);
		tputs(tgetstr("ce", NULL), 1, putchar);
	}
	tputs(tgetstr("rc", NULL), 1, putchar);
}

