//
// Created by youpaw on 01.05.2020.
//

#include "exec.h"
#include "cc_str.h"

void exec_and_or(t_ast *ast, t_job *job, char foreground)
{
	exec_pipeline(ast->left, job);
	job->command = get_command(ast);
	launch_job(job, 1);
//	putendl("job ok");

	while (ast->right)
	{
		job->next = job_new();
		job = job->next;
		job->sequence = ast->token;
		ast = ast->right;
		exec_pipeline(ast->left, job);
		launch_job(job, 1);
	}


}