//
// Created by youpaw on 26.04.2020.
//
#include "exec.h"

int					exec_complete_cmd(t_ast *ast)
{
	return (exec_list(ast->left));
}