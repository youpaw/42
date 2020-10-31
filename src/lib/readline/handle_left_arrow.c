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
	if (inp->cursor_x_position - inp->indent)
	{
		g_input_state_flag = INP_CH_FLAG;
		tputs(tgetstr("le", NULL), 1, &putchar);
		inp->cursor_x_position--;
	}
	else
		putchar('\7');
	return 0;
}