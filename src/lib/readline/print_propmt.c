/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_propmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <string.h>

int		get_prompt_len(int y)
{
	if (y)
		return (NEXT_PROMPT_LEN);
	else
		return (FIRST_PROMPT_LEN);
}

char	*get_prompt(int y)
{
	if (y)
		return (strdup(NEXT_PROMPT_TEXT));
	else
		return (strdup(FIRST_PROMPT_TEXT));
}

void	print_prompt(t_inp *inp)
{
	int		i;
	char	sym[4];
	char	*prompt;

	i = 0;
	bzero(sym, 4);
	prompt = get_prompt(inp->y_pos);
	while (prompt[i])
	{
		sym[0] = prompt[i++];
		handle_key(sym, inp);
	}
	free(prompt);
}
