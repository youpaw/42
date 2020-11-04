//
// Created by Darth Butterwell on 9/5/20.
//

#include <termcap.h>
#include "readline.h"
#include "cc_mem.h"
#include "cc_char.h"

int handle_backspace(t_input *inp)
{
	unsigned char ch[5];
	int len;
	if (inp->cursor_x_position - get_prompt_len(inp->cursor_y_position))
//	if (inp->cursor_x_position)
	{
		g_input_state_flag = INP_CH_FLAG;
		bzero(ch, 5);
		vec_get_at(ch, inp->line[inp->cursor_y_position], inp->cursor_x_position - 1);
		len = get_displayed_symbol_len(ch);
		handle_left_arrow(inp);
		while (len-- != 0)
			tputs(tgetstr("dc", NULL), 1, &putchar);
		vec_rm_at(inp->line[inp->cursor_y_position], inp->cursor_x_position);
		inp->len--;
		inp->line_len[inp->cursor_y_position]--;
		redraw_input_del(inp);
	}
	else
		putchar('\7');
	return 0;
}
