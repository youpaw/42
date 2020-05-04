//
// Created by youpaw on 26.04.2020.
//

#include "exec.h"

int 	exec(t_ast *ast)
{
	return (exec_complete_cmd(ast));
}