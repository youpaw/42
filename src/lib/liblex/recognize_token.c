/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognize_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "env.h"

t_token_type	recognize_token(t_lexer *lexer)
{
	t_token token;

	if (!lexer->tokens->size)
	{
		if (lexer->raw[lexer->begin] == '!')
			return (l_bang);
		if (get_valid_name_length(lexer->raw + lexer->begin))
			return (l_assignment_word);
		lexer->flags[l_cmd_appeared] = 1;
		return (l_command_name);
	}
	vec_get_last(&token, lexer->tokens);
	if (is_redirection(token.type))
		return (l_filename);
	if (is_delimiter(token.type) && lexer->raw[lexer->begin] == '!')
		return (l_bang);
	if (!lexer->flags[l_cmd_appeared])
	{
		if (get_valid_name_length(lexer->raw + lexer->begin))
			return (l_assignment_word);
		lexer->flags[l_cmd_appeared] = 1;
		return (l_command_name);
	}
	return (l_word);
}
