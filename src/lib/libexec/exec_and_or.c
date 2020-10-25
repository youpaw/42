//
// Created by youpaw on 01.05.2020.
//

#include "exec.h"
#include "cc_str.h"
#include "builtins.h"
#include "jobs.h"
#include "unistd.h"

void exec_and_or(t_ast *ast, char is_foreground, int status)
{
	t_job	*job;

	job = job_new();
	exec_pipeline(ast->left, job);
	job->command = get_command(ast->left);
	if (!is_foreground)
		job->pgid = getppid(); // need getppid()
	push_job(job);
	launch_job(job, is_foreground);
	if (!is_foreground)
		wait_for_job(job);
	if (ast->right)
		exec_and_or(ast->right, is_foreground, status);


/*
	while (ast->right)
	{
		job->next = job_new();
		job = job->next;
		job->sequence = ast->token;
		ast = ast->right;
		exec_pipeline(ast->left, job);
		push_job(job);
		launch_job(job, is_foreground);
	}

*/
}