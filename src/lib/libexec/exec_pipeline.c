//
// Created by youpaw on 02.05.2020.
//

#include "exec.h"

int	exec_pipeline(t_ast *ast)
{
	return (exec_pipe_seq(ast));
}