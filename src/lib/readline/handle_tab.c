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
#include "cc.h"

int			handle_tab(t_input *inp)
{
	static t_list	*options;
	t_tokens 		*tokens;
	t_token 		token;

	if (g_input_state_flag == INP_MAKING_CHOICE)
		handle_choice_tab(inp, &options);
	else
	{
		tokens = tokenize_str_sub(
				input_to_str(*inp),
				inp->cursor_x_position);
		token.raw = strdup("../CM");
		//		if (token->type == l_word) //file
			handle_file_token(inp, &token);
//		destruct_token(&token);
//		destruct_tokens(&tokens);
	}
	return 0;
}
