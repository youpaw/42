//
// Created by youpaw on 01.05.2020.
//

#include "exec.h"
#include "cc.h"

//void 	run_pipe(t_ast *ast)
//{
//	int pid;
//
//	if (!(pid = fork()))
//		exec_pipe_seq(ast, NULL);
//	waitpid(pid, NULL, 0);
//}

void	exec_and_or(t_ast *ast)
{
	t_ast *next;

//	run_pipe(ast->left);
	exec_pipe_seq(ast->left, NULL);
	while ((next = ast->right))
	{
		if ((ast->token->type == l_and_if && !g_exit_code) || \
			(ast->token->type == l_or_if && g_exit_code))
			exec_and_or(ast->right);
		ast = next;
	}
}