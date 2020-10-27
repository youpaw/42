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

	token = get_predict_token(input_to_str(*inp), inp->cursor_x_position);
//	printf("type = %d, %d %d %d\n", token->type, r_file, r_cmd, r_param);
//	if (token->type == r_file) //file
		handle_file_token(inp, token);
	return 0;
}
