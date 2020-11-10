//
// Created by Maxon Gena on 9/10/20.
//

#include "readline.h"
#include "cc_str.h"
#include "cc_char.h"
#include <unistd.h>
#include <termcap.h>
#include <sys/ioctl.h>

void	common_redraw(t_inp *input)
{
	int		cur_y_pos;
	int		cur_x_pos;
	char	buf[1024];
	struct winsize ws;
	int i;

	cur_y_pos = input->cursor_y_position;
	cur_x_pos = input->cursor_x_position;

	i = 0;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	while (input->line[cur_y_pos])
	{
		while (cur_x_pos != input->line_len[cur_y_pos])
		{
			vec_get_at(&buf[i], input->line[cur_y_pos], cur_x_pos);
			i += utf8_sizeof_symbol(buf[i]);
			if (i >= 1020)
			{
				write(STDIN_FILENO, buf, i);
				i = 0;
			}
			cur_x_pos++;
		}
		write(STDIN_FILENO, buf, i);
		i = 0;
		if (input->line[cur_y_pos + 1])
		{
			tputs(tgetstr("do", NULL), 1, &putchar);
			tputs(tgetstr("cr", NULL), 1, &putchar);
		}

		cur_y_pos++;
		cur_x_pos = 0;
	}
}