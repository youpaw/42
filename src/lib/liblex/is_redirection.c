/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_redirection(t_token_type type)
{
	int							index;
	static const t_token_type	redirection_map[N_TOKEN_REDIRECTIONS] = {
			l_less_and, l_great_and, l_less, l_great,
			l_double_great, l_double_less};

	index = 0;
	while (index < N_TOKEN_REDIRECTIONS && type != redirection_map[index])
		index++;
	if (index == N_TOKEN_REDIRECTIONS)
		return (0);
	return (1);
}
