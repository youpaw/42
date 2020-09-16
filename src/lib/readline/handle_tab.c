/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 16:40:10 by mgena             #+#    #+#             */
/*   Updated: 2020/08/22 22:29:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <stdio.h>

int			handle_tab(t_input *inp)
{
	static t_list	*to_print;
	t_tokens 		*tokens;
	t_token 		*token;

	if (g_input_changed_flg)
	{
		lst_del(&to_print, NULL);
		to_print = NULL;
	}
	if (!to_print)
	{
		g_input_changed_flg = 0;
		tokens = tokenize_str_sub(
				input_to_str(*inp),
				inp->cursor_x_position);
		token = get_last_token(tokens);
		if (token->type == l_word) //file
		{
			to_print = get_list_files(inp, token);
			if (!to_print->next)
				complete_print(inp, &to_print);
			else
				putchar('\7');
		}
	destruct_token(&token);
	destruct_tokens(&tokens);
		return 0;
	}
	else
	{
		choose_token(inp, to_print);
		g_input_changed_flg = 0;
	}
	return 1;
}
