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
		tputs(tgetstr("le", NULL), 1, &putchar);
		inp->cursor_x_position--;
	}
	else
		putchar('\7');
	return 0;
}