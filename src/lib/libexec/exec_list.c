//
// Created by youpaw on 01.05.2020.
//

#include "exec.h"
#include "jobs.h"

void	exec_list(t_ast *ast)
{
	t_job *job;

	if (ast->token && ast->token->type == l_and)
		job = job_new();
	else
		job = job_new();
	exec_and_or(ast->left, job);
	if (ast->right)
		exec_list(ast->right);
}
