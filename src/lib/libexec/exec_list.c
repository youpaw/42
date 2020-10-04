//
// Created by youpaw on 01.05.2020.
//

#include "exec.h"
#include <unistd.h>

void	exec_list(t_ast *ast)
{
	if (ast->token && ast->token->type == l_and)
	{
		if (!fork())
			exec_and_or(ast->left);
	}
	else
		exec_and_or(ast->left);
	if (ast->right)
		exec_list(ast->right);
}
