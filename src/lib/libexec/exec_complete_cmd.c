//
// Created by youpaw on 26.04.2020.
//
#include "exec.h"

void exec_complete_cmd(t_ast *ast, t_tokens *tokens)
{
	exec_list(ast->left, tokens);
}