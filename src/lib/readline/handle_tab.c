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

int			handle_tab(t_input *inp)
{
	static t_list	*options;
	t_predict_token *token;

	if (g_input_state_flag == INP_MAKING_CHOICE)
		handle_choice_tab(inp, &options);
	else
	{
		token = get_predict_token(input_to_str(*inp), inp->cursor_x_position);
		//		if (token->type == l_word) //file
//			handle_file_token(inp, &token);
	}
	return 0;
}
