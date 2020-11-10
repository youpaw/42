//
// Created by Maxon Gena on 11/8/20.
//

#include "readline.h"
#include "cc_char.h"
#include "cc_str.h"
#include <termcap.h>
#include <unistd.h>

void redraw_input(t_inp inp, char *str)
{
	size_t i;
	int len;
	char *prompt;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '\n')
		{
			tputs(tgetstr("do", NULL), 1, putchar);
			tputs(tgetstr("cr", NULL), 1, putchar);
			prompt = get_prompt(inp.cursor_y_position);
			puts(prompt);
			free(prompt);
			i++;
		}
		else
		{
			len = utf8_sizeof_symbol(str[i]);
			write(STDOUT_FILENO, &str[i], len);
			i += len;
		}
	}

}

