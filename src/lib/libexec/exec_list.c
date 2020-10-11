//
// Created by youpaw on 01.05.2020.
//

#include "exec.h"

void exec_list(t_ast *ast, t_tokens *tokens)
{
	t_job *job;

	job = job_new();
	if (!ast->token || ast->token->type == l_semi)
		exec_and_or(ast->left, job);
	else
		exec_and_or(ast->left, job);
	if (ast->right)
		exec_list(ast->right, tokens);
}
