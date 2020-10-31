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
		exec_and_or(ast->left, 1, 0, NULL);
	else
	{
		if (!(pid = fork()))
		{
//			set_ignore_handlers();
			exec_and_or(ast->left, 1, 1, NULL);
			exit(g_exit_code);
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
