//
// Created by Maxon Gena on 9/10/20.
//

#include "readline.h"
#include "cc_str.h"
#include "cc_char.h"
#include <unistd.h>

void	redraw_input(t_input *input)
{
	int		cur_y_pos;
	int		cur_x_pos;
	char	buf[1024];
	int i;

	cur_y_pos = input->cursor_y_position;
	cur_x_pos = input->cursor_x_position;
	i = 0;

	while (input->line[cur_y_pos])
	{
		while (cur_x_pos != input->line_len[cur_y_pos])
		{
			vec_get_at(&buf[i], input->line[cur_y_pos], cur_x_pos);
			i += get_utf8_len(buf[i]);
			if (i >= 1020)
			{
				write(STDIN_FILENO, buf, i);
				i = 0;
			}
			cur_x_pos++;
		}
		cur_y_pos++;
	}
	if (i)
		write(STDIN_FILENO, buf, i);
}