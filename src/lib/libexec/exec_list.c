//
// Created by youpaw on 01.05.2020.
//

#include "exec.h"
#include <unistd.h>

void	exec_list(t_ast *ast)
{
	int pid;

//	if (!(pid = fork()))
//	{
		exec_and_or(ast->left);
//		exit(g_exit_code);
//	}
//	if (ast->token->type != l_and)
//		waitpid(pid, NULL, 0);
	if (ast->right)
		exec_list(ast->right);
}
