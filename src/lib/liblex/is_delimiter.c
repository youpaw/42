/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_delimiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_delimiter(t_token_type type)
{
	static const t_token_type	delimiter_map[N_TOKEN_DELIMITERS] = {
			l_and_if, l_or_if, l_and, l_or, l_semi
	};
	int							index;

	index = 0;
	while (index < N_TOKEN_DELIMITERS && type != delimiter_map[index])
		index++;
	if (index == N_TOKEN_DELIMITERS)
		return (0);
	return (1);
}
