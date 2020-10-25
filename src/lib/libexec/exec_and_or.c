//
// Created by youpaw on 01.05.2020.
//

#include "exec.h"
#include "jobs.h"
#include "unistd.h"
#include <stdio.h>
#include "lexer.h"

void exec_and_or(t_ast *ast, char is_foreground, t_token *token)
{
	t_job	*job;
	int		cur_job_status;

	if (!token || (!g_exit_code && token->type == l_and_if) \
				|| (g_exit_code && token->type == l_or_if))
	{
		job = job_new();
		exec_pipeline(ast->left, job);
		job->command = get_command(ast->left);
		if (!is_foreground)
			job->pgid = getpid();
		push_job(job);
		launch_job(job, is_foreground);
		if (!is_foreground)
			wait_for_job(job);
		g_exit_code = get_job_status(job);
		printf("job with PID=%d has status=%d\n", job->pgid, g_exit_code);
		if (job_is_completed(job))
			remove_job(job->index);
	}
	if (ast->right)
		exec_and_or(ast->right, is_foreground, ast->token);
}