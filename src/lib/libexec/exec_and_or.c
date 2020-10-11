//
// Created by youpaw on 01.05.2020.
//

#include "exec.h"

void exec_and_or(t_ast *ast, t_job *job)
{
	exec_pipeline(ast->left, job);
	while (ast->right)
	{
		job->next = job_new();
		job = job->next;
		job->sequence = ast->token;
		ast = ast->right;
		exec_pipeline(ast->left, job);
	}
}