//
// Created by youpaw on 01.05.2020.
//

#include "exec.h"
#include "jobs.h"
#include "unistd.h"
#include <stdio.h>
#include "lexer.h"

void exec_and_or(t_ast *ast, char is_foreground, char is_forked, t_token *token)
{
	t_job	*job;

	if (!token || (!g_exit_code && token->type == l_and_if) \
				|| (g_exit_code && token->type == l_or_if))
	{
		job = job_new(is_foreground);
		exec_pipeline(ast->left, job);
		job->command = get_command(ast->left);
		if (is_forked)
			job->pgid = getpid();
		push_job(job);
		g_exit_code = launch_job(job, is_foreground, is_forked);
		//if (is_forked)
		//	wait_for_job_complete(job);
		//g_exit_code = get_job_status(job);
		//printf("[%d->%d] \n", job->pgid, g_exit_code);
		//fflush(NULL);

		if (job_is_completed(job))
			remove_job_by_index(job->index);
	}
	if (ast->right)
		exec_and_or(ast->right, is_foreground, is_forked, ast->token);
}