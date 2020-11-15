/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "cc_str.h"

int		expand_token(t_token *token)
{
	int			error;
	t_lexer		lexer;

	error = lex_raw(&lexer, token->raw, l_exp);
	if (!error)
	{
		free(token->raw);
		token->raw = strdup(lexer.raw);
	}
	lex_del(&lexer);
	return (error);
}
