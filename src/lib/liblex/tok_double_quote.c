/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_double_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	tok_double_quote(t_lexer *lexer)
{
	t_slice	slice;
	char	c;

	slice.state = l_unset;
	c = lexer->raw[lexer->index];
	if (c == '!')
		slice.state = l_history;
	else if (c == '$')
		slice.state = l_dollar;
	else if (c == '\\' && is_doublequote_esc(lexer->raw[lexer->index + 1]))
		slice.state = l_back_slash;
	else if (c == '\"')
		vec_rm_last(lexer->slices);
	if (slice.state != l_unset)
	{
		slice.index = lexer->index;
		vec_push(lexer->slices, &slice);
	}
	return (E_OK);
}
