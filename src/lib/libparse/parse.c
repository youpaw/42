/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error.h"
#include "env.h"

t_ast				*sh_parse(t_tokens *tokens)
{
	const char	*args[1];
	t_ast		*ast;

	ast = node_complete_cmd(tokens);
	if (tokens->index < tokens->size)
	{
		del_ast(&ast);
		tokens->error = E_UNEXPTOK;
		g_exit_code = E_UNEXPTOK;
		args[0] = tokens->tokens[tokens->index]->type == l_newline ? \
			token_type_to_string(l_newline) : \
			tokens->tokens[tokens->index]->raw;
		error_print(E_UNEXPTOK, args);
	}
	return (ast);
}
