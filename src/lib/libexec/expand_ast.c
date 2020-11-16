/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_ast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	is_expand_token(t_token_type type)
{
	if (type == l_command_name || type == l_assignment_word ||
		type == l_word || type == l_filename)
		return (1);
	return (0);
}

int			expand_ast(t_ast *ast)
{
	int error;

	if (!ast)
		return (0);
	if (ast->token && is_expand_token(ast->token->type))
	{
		if ((error = expand_token(ast->token)))
			return (error);
	}
	if ((error = expand_ast(ast->left)))
		return (error);
	if ((error = expand_ast(ast->right)))
		return (error);
	return (0);
}
