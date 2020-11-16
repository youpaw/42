/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "cc_char.h"
#include "cc_graph.h"
#include "cc_str.h"

static void	del_input_st(t_inp *input)
{
	if (input->hist_storage)
		free(input->hist_storage);
	del_input(input);
}

static int	check_eox(t_inp *inp)
{
	char ch[5];

	if (inp->y_pos)
	{
		vec_get_at(ch, inp->line[inp->y_pos - 1], \
			inp->l_len[inp->y_pos - 1] - 1);
		if (*ch == '\4')
		{
			vec_del(&inp->line[inp->y_pos]);
			inp->line[inp->y_pos] = NULL;
			inp->x_pos = inp->l_len[--inp->y_pos];
			puts("!");
			handle_backspace(inp);
			return (1);
		}
	}
	return (0);
}

int			sh_readline(char **line)
{
	t_let		key;
	t_inp		input;

	if (tty_init())
	{
		free(*line);
		*line = strdup("\4");
		return (0);
	}
	input = input_init(*line);
	if (!check_eox(&input))
		print_prompt(&input);
	while (42)
	{
		key.num = sh_getch();
		if (handle_key(key.ch, &input))
		{
			*line = input_to_str(input, 1);
			if (input.line)
				del_input_st(&input);
			tty_restore();
			return (0);
		}
	}
}
