//
// Created by Maxon Gena on 10/29/20.
//

#include "readline.h"
#include "ft_select.h"
#include "cc_str.h"
#include "cc_char.h"

void 	select_choise(void *files, t_input *inp)
{
	char *selection;
	size_t i;
	struct winsize ws;

	i = 0;
	tputs(tgetstr("do", NULL), 1, putchar);
	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	selection = ft_select(files);
	tputs(tgetstr("up", NULL), 1, putchar);
	while (i++ != inp->cursor_x_position % ws.ws_col)
		tputs(tgetstr("nd", NULL), 1, putchar);
	if (!selection)
		return ;
	put_str_to_inp(inp, selection);
}

