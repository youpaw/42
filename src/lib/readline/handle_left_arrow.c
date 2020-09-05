//
// Created by Darth Butterwell on 9/5/20.
//

#include "readline.h"
#include "cc_mem.h"
#include "cc_char.h"
#include <termcap.h>

int handle_left_arrow(t_input *inp)
{
	unsigned char ch[5];
	int len;
	if (inp->cursor_x_position)
	{
		g_input_changed_flg = 1;
		bzero(ch, 5);
		vec_get_at(ch, inp->line, inp->cursor_x_position - 1);
		len = get_displayed_symbol_len(ch);
		while (len-- != 0)
		{
			tputs(tgetstr("le", NULL), 1, &putchar);
		}
		inp->cursor_x_position--;
	}
	else
		putchar('\7');
	return 0;
}