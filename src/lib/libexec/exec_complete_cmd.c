//
// Created by youpaw on 26.04.2020.
//
#include "exec.h"

void		exec_complete_cmd(t_ast *ast)
{
	exec_list(ast->left);
}
