/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cc_mem.h>
#include "cc_vec.h"
#include "readline.h"
#include "cc_str.h"
#include "cc_char.h"

static int		strcmp_in_input(t_vec **vec_ptr, char *str)
{
	char	letter[5];
	int		letter_len;
	int		line_len;
	size_t	i;

	i = 0;
	line_len = 0;
	bzero(letter, 5);
	while (str[i])
	{
		letter_len = utf8_sizeof_symbol(str[i]);
		bzero(letter, 5);
		strncpy(letter, &str[i], letter_len);
		vec_push(*vec_ptr, letter);
		i += letter_len;
		line_len++;
	}
	free(str);
	return (line_len);
}

static t_inp	fill_input(char *line)
{
	t_inp	inp;
	char	**prev;

	inp.y_pos = 0;
	inp.len = 0;
	prev = split_newline(line);
	while (prev[inp.y_pos])
		inp.y_pos++;
	inp.line = xmalloc(sizeof(t_vec*) * (inp.y_pos + 2));
	inp.l_len = xmalloc(sizeof(size_t) * (inp.y_pos + 2));
	inp.y_pos = 0;
	while (prev[inp.y_pos])
	{
		inp.line[inp.y_pos] = vec_new(8, sizeof(char[5]), NULL);
		inp.l_len[inp.y_pos] = strcmp_in_input(\
			&inp.line[inp.y_pos], get_prompt(inp.y_pos));
		inp.l_len[inp.y_pos] += strcmp_in_input(
				&inp.line[inp.y_pos], prev[inp.y_pos]);
		inp.len += inp.l_len[inp.y_pos];
		inp.y_pos++;
	}
	free(prev);
	return (inp);
}

t_inp			input_init(char *line)
{
	t_inp inp;

	if (*line)
		inp = fill_input(line);
	else
	{
		inp.line = xmalloc(sizeof(t_vec*) * 2);
		inp.l_len = xmalloc(sizeof(int) * 2);
		inp.y_pos = 0;
		inp.len = 0;
	}
	inp.line[inp.y_pos] = vec_new(8, sizeof(char[5]), NULL);
	inp.line[inp.y_pos + 1] = NULL;
	inp.l_len[inp.y_pos] = 0;
	inp.x_pos = 0;
	inp.hist_storage = NULL;
	free(line);
	return (inp);
}
