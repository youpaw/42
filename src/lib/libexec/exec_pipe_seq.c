//
// Created by youpaw on 02.05.2020.
//

#include "exec.h"
#include <stddef.h>
#include <unistd.h>

void	exec_pipe_seq(t_ast *ast)
{
	int pl[2];
	int status;

	pipe(pl);
	while (ast)
	{
		if (!fork())
		{
			if (ast->right)
				dup2(pl[1], 1);
			exec_simple_cmd(ast->left);
			exit(g_exit_code);
		}
		dup2(pl[0], 0);
		close(pl[1]);
		ast = ast->right;
	}
	waitpid(NULL, &status, 0);
	g_exit_code = WEXITSTATUS(status);
	dup2(STDIN_FILENO, pl[0]);
}
