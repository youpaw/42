//
// Created by youpaw on 01.05.2020.
//

#include "exec.h"
#include <wait.h>
#include "cc.h"

int	exec_list(t_ast *ast)
{
	int code;
	int pid;

	if (!ast->right)
		return (exec_and_or(ast->left));
	if (!strcmp(ast->attr.raw, ";"))
	{
		exec_and_or(ast->left);
		return (exec_list(ast->right));
	}
	if (!(pid = fork()))
		exit(exec_and_or(ast->left));
	code = exec_list(ast->right);
	waitpid(pid, NULL, 0);
	return (code);
}