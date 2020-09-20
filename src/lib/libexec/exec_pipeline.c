//
// Created by youpaw on 02.05.2020.
//

#include "exec.h"

void	exec_pipeline(t_ast *ast)
{
	exec_pipe_seq(ast->left, NULL);
}