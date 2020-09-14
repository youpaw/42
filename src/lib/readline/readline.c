//
// Created by Darth Butterwell on 8/16/20.
//

#include "readline.h"
#include "cc_char.h"


int			readline(char **line)
{
	t_letter key;
	t_input input;

	input = input_init(*line);
	while (42)
	{
		key.num = getch();
//		printf("\n%d, %d, %d, %d, %d", key.ch[0], key.ch[1], key.ch[2], key.ch[3], key.num);
		if (handle_key(key.ch, &input))
		{
//			if (vec_push_at(input.line[input.cursor_y_position], "\n", input.cursor_x_position))
//			{
//				return (1);
//			}
			input.cursor_x_position++;
			input.len++;
			*line = input_to_str(input.line[input.cursor_y_position], input.len);
//			printf("\n%s", *line);
			return 0;
		}
	}
}

