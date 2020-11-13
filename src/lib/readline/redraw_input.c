//
// Created by Maxon Gena on 11/8/20.
//

#include "readline.h"
#include "cc_char.h"
#include "cc_str.h"
#include <termcap.h>
#include <unistd.h>
#include <sys/ioctl.h>

void	draw_letter(size_t *i, size_t *line_len, char *str)
{
	struct winsize	ws;
	int				len;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	len = utf8_sizeof_symbol(*str);
	write(STDOUT_FILENO, str, len);
	(*line_len)++;
	if (!(*line_len % ws.ws_col))
	{
		tputs(tgetstr("do", NULL), 1, &putchar);
		tputs(tgetstr("cr", NULL), 1, &putchar);
	}
	*i += len;
}

void	redraw_input(t_inp inp, char *str)
{
	size_t	i;
	char	*prompt;
	size_t	line_len;

	i = 0;
	line_len = get_prompt_len(inp.y_pos);
	while (str[i] != 0)
	{
		if (str[i] == '\n')
		{
			tputs(tgetstr("do", NULL), 1, putchar);
			tputs(tgetstr("cr", NULL), 1, putchar);
			prompt = get_prompt(inp.y_pos);
			puts(prompt);
			free(prompt);
			line_len += get_prompt_len(inp.y_pos);
			i++;
		}
		else
			draw_letter(&i, &line_len, &str[i]);
	}
}
