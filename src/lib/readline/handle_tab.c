/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int		handle_tab(t_inp *inp)
{
	t_prdct_tkn		*token;
	char			*str;

	str = input_to_n_str(*inp);
	token = get_predict_token(str);
	free(str);
	if (token->type == r_file)
		handle_file_token(inp, token, 0);
	else if (token->type == r_cmd)
		handle_command_token(inp, token);
	else if (token->type == r_param)
		handle_param_token(inp, token);
	del_predict_token(&token);
	return (0);
}
