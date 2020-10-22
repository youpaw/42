//
// Created by youpaw on 02.05.2020.
//

#include "exec.h"
#include "env.h"

void		exec_simple_cmd(t_ast *ast, t_process *process)
{
	if (expand_ast(ast) || prepare_redirect(ast, process))
		return ;
	process->argv = get_args(ast);
	prepare_exec_env(ast->left);
	process->env = exec_env_2array();
	exec_env_del();
}
