//
// Created by youpaw on 01.05.2020.
//

#include "exec.h"
#include <unistd.h>

void exec_list(t_ast *ast)
{
	pid_t pid;
	t_job *job;

	if (!ast->token || ast->token->type == l_semi)
		exec_and_or(ast->left, 1, NULL);
	else
	{
		if (!(pid = fork()))
		{
			exec_and_or(ast->left, 0, NULL);
			exit(0);
		}
		else
		{
			job = job_new();
			job->first_process = process_new();
			job->first_process->pid = pid;
			job->pgid = pid;
			setpgid(pid, job->pgid);
			job->command = get_command(ast->left);
			push_job(job);
		}
	}
	if (ast->right)
		exec_list(ast->right);
}
