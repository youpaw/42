/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	destruct_tokens(t_tokens **tokens)
{
	t_tokens	*p_tokens;
	size_t		index;

	if (!tokens || !*tokens)
		return ;
	index = 0;
	p_tokens = *tokens;
	while (index < p_tokens->size)
	{
		destruct_token(&p_tokens->tokens[index]);
		index++;
	}
	free(p_tokens->tokens);
	free(p_tokens->raw);
	free(p_tokens);
	*tokens = NULL;
}
