//
// Created by youpaw on 02.05.2020.
//

#include "exec.h"

int	exec_command(t_ast *ast)
{
	return (exec_simple_cmd(ast->left));
}