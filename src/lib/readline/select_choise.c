/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_choise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "ft_select.h"
#include "cc_str.h"
#include "cc_char.h"

void	select_choise(void *files, t_inp *inp, char *current)
{
	struct winsize	ws;
	char			*selection;
	size_t			i;

	i = 0;
	clear_last_display_token(current, inp);
	tputs(tgetstr("do", NULL), 1, putchar);
	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	selection = ft_select(files);
	tputs(tgetstr("up", NULL), 1, putchar);
	if (!selection)
		selection = strdup(current);
	while (i++ != inp->x_pos % ws.ws_col)
		tputs(tgetstr("nd", NULL), 1, putchar);
	put_str_to_input(inp, selection);
}
