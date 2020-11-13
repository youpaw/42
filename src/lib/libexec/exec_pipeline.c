//
// Created by youpaw on 02.05.2020.
//

#include "exec.h"

void		exec_pipeline(t_ast *ast, t_job *job)
{
	job->first_process = process_new();
	exec_pipe_seq(ast->left, job->first_process);
}
