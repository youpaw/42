//
// Created by youpaw on 10/6/20.
//

#include "exec.h"

static int is_expand_token(t_token_type type)
{
	if (type == l_command_name || type == l_assignment_word || type == l_word)
		return (1);
	return (0);
}

int 	expand_ast(t_ast *ast)
{
	int error;

	if (!ast)
		return (0);
	if (ast->token && is_expand_token(ast->token->type))
	{
		if ((error = expand_token(ast->token)))
		{
			g_exit_code = error;
			return (error);
		}
	}
	if ((error = expand_ast(ast->left)) || (error = expand_ast(ast->right)))
		return (error);
	return (0);
}