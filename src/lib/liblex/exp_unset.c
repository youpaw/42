/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "expand.h"
#include "cc_str.h"

int		exp_unset(t_lexer *lexer)
{
	char	*sub;
	size_t	index;

	index = lexer->index;
	if (!match_tilda(lexer))
	{
		sub = strsub(lexer->raw, index, lexer->index - index);
		expand_tilda(&sub);
		strjoin_expanded(lexer, index, sub, 0);
		free(sub);
	}
	return (E_OK);
}
