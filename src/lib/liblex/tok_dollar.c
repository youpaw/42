/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_dollar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	tok_dollar(t_lexer *lexer)
{
	t_brace	brace;
	int		error;

	error = 0;
	if (get_brace(lexer->raw + lexer->index, &brace) > 0)
		error = match_brace(lexer, brace);
	else
		match_parameter(lexer);
	if (!error && lexer->index < lexer->size)
	{
		lexer->index--;
		vec_rm_last(lexer->slices);
	}
	return (error);
}
