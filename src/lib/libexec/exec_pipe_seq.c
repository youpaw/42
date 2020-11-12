//
// Created by youpaw on 02.05.2020.
//

#include "exec.h"

void		exec_pipe_seq(t_ast *ast, t_process *process)
{
	exec_simple_cmd(ast->left, process);
	if (ast->right)
	{
		process->next = process_new();
		exec_pipe_seq(ast->right, process->next);
	}
}
