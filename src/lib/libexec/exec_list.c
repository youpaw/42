//
// Created by youpaw on 01.05.2020.
//

#include "exec.h"
#include "cc_str.h"
#include <unistd.h>

void exec_list(t_ast *ast)
{
	t_job *job;
	pid_t pid;

	job = job_new();
	push_job(job);
	if (!ast->token || ast->token->type == l_semi)
		exec_and_or(ast->left, job, 1);
	else
	{
		exec_and_or(ast->left, job, 0);
	}
	if (ast->right)
		exec_list(ast->right);
	//putendl("execlist ended");
}
