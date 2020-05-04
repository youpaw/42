//
// Created by youpaw on 02.05.2020.
//

#include "exec.h"
#include <stdlib.h>
#include <zconf.h>
#include <wait.h>

int					exec_pipe_seq(t_ast *ast)
{
	int pl[2];
	int code;
	int pid;
	int status;

	pipe(pl);
	if (!(pid = fork()))
	{
		if (ast->right)
			dup2(pl[1], 1);
		exit(exec_command(ast->left));
	}
	dup2(pl[0], 0);
	close(pl[1]);
	if (ast->right)
		code = exec_pipe_seq(ast->right);
	waitpid(pid, &status, 0);
	if (!ast->right)
		code = WEXITSTATUS(status);
	close(pl[0]);
	return (code);
}