/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "cc_str.h"

t_tokens	*validate_str(const char *string)
{
	t_lexer		lexer;
	t_tokens	*tokens;
	int			error;

	if (!string || !*string)
		return (NULL);
	error = lex_err(&lexer, lex_raw(&lexer, string, l_vld));
	if (error == E_NOEVENT)
	{
		lex_del(&lexer);
		return (NULL);
	}
	if (!error && lexer.flags[l_print_command])
		puts(lexer.raw);
	tokens = get_tokens(&lexer, error);
	lex_del(&lexer);
	return (tokens);
}
