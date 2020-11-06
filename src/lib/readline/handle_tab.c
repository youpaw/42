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

#include "cc.h"
#include <stdio.h>

int			handle_tab(t_input *inp)
{
	static t_list	*options;
	t_predict_token *token;
	char *str;

	str = input_to_n_str(*inp);
	token = get_predict_token(str);
	free(str);
	if (token->type == r_file) //file
		handle_file_token(inp, token, F_OK);
	else if (token->type == r_cmd)
		handle_command_token(inp, token);
	else if (token->type == r_param)
		handle_param_token(inp, token);
	del_predict_token(&token);
	return 0;
}
