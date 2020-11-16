/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_single_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:52:34 by dbutterw          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:12 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	tok_single_quote(t_lexer *lexer)
{
	while (lexer->raw[lexer->index] != '\'' && lexer->index < lexer->size)
		lexer->index++;
	if (lexer->index == lexer->size)
		return (E_INCINP);
	else
		vec_rm_last(lexer->slices);
	return (E_OK);
}
