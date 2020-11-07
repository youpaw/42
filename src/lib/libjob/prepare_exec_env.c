//
// Created by youpaw on 10/5/20.
//

#include "exec.h"

void prepare_exec_env(t_ast *ast)
{
	exec_env_init();
	if (!ast)
		return ;
	while (ast)
	{
		if (ast->token && ast->token->type == l_assignment_word)
			exec_env_insert(ast->token->raw);
		ast = ast->right;
	}
}