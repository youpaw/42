/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 16:40:10 by mgena             #+#    #+#             */
/*   Updated: 2020/08/22 14:48:26 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "../libcc/cc.h"
#include <stdio.h>

char	*get_last_token(char *str)
{
	size_t len;

	len = strlen(str) - 1;
	while (!isspace(str[len]))
		len--;
	return (&str[len + 1]);
}

void get_dir(t_input *input)
{
	char *fullname;


	fullname = get_last_token((char*)input->line->data);
	printf("\n!!!%s!!!", fullname);
}

void get_command(t_input *input)
{
	;
}

int			autocomplete(t_input *input)
{
	int token = 2;

//	token = last_token_type(input);
	if (token == 0) //cur token shouldn't be anithing (wrong or quote)
		ft_put('\7');
	else if (token == 1) //cur token end and no command could be added
		symbol_key_pressed(input, ' ');
	else if (token == 2) //cur token is dir
		get_dir(input);
	else if (token == 3) //cur token is command
		get_command(input);
	return 1;
}
