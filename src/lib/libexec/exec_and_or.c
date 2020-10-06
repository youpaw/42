//
// Created by youpaw on 01.05.2020.
//

#include "exec.h"

void exec_and_or(t_ast *ast)
{
	t_ast *next;

	exec_pipeline(ast->left);
	while ((next = ast->right))
	{
		if ((ast->token->type == l_and_if && !g_exit_code) || \
			(ast->token->type == l_or_if && g_exit_code))
			exec_and_or(ast->right);
		ast = next;
	}
}