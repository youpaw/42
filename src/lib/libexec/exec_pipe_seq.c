//
// Created by youpaw on 02.05.2020.
//

#include "exec.h"
#include <unistd.h>

void	exec_pipe_seq(t_ast *ast, int *prev_pl)
{
//	int pl[2];
//
//	if (ast->right)
//	{
//		pipe(pl);
//		if (!fork())
//			exec_pipe_seq(ast->right, pl);
//		close(pl[1]);
//		dup2(pl[0], STDIN_FILENO);
//	}
//	if (prev_pl)
//	{
//		close(prev_pl[0]);
//		dup2(prev_pl[1], STDOUT_FILENO);
//	}
	exec_simple_cmd(ast->left);
}
