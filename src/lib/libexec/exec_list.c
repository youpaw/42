//
// Created by youpaw on 01.05.2020.
//

#include "exec.h"
#include <unistd.h>

void	exec_list(t_ast *ast)
{
	pid_t pid;
	t_job *job;

	if (!ast->token || ast->token->type == l_semi)
		exec_and_or(ast->left, 1, 0, NULL);
	else if (!ast->left->right)
		exec_and_or(ast->left, 0, 0, NULL);
	else
	{
		if (!(pid = fork()))
		{
			g_has_job_control = 0;
			exec_and_or(ast->left, 0, 1, NULL);
			exit(g_exit_code);
		}
		else
		{
			setpgid(pid, pid);
			job = job_new(0);
			job->first_process = process_new();
			job->first_process->pid = pid;
			job->pgid = pid;
			job->command = get_command(ast->left);
			print_job_formatted(job, 0, JPM_BG);
			push_job(job);
		}
	}
	if (ast->right)
		exec_list(ast->right);
}
