//
// Created by youpaw on 01.05.2020.
//

#include "exec.h"
#include <unistd.h>
#include "jobs.h"

void	exec_list(t_ast *ast)
{
	pid_t	pid;

	if (ast->token && ast->token->type == l_and)
	{
		if (!(pid = fork()))
		{
			exec_and_or(ast->left);
			exit(0);
		}
		else
		{
			add_job_to_list(pid, 0);
		}
	}
	else
		exec_and_or(ast->left);
	if (ast->right)
		exec_list(ast->right);
}
