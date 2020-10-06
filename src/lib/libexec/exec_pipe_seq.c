//
// Created by youpaw on 02.05.2020.
//

#include "exec.h"
#include <unistd.h>
#include <sys/wait.h>
#include "jobs.h"

static void create_pipe_seq(t_ast *node, int *prev_pl)
{
	int pl[2];

	print_process_stats("into pipe:");
	if (node->right)
	{
		pipe(pl);
		if (!fork())
		{
			create_pipe_seq(node->right, pl);
			exit(0);
		}
		close(pl[0]);
		dup2(pl[1], STDOUT_FILENO);
	}
	if (prev_pl)
	{
		close(prev_pl[1]);
		dup2(prev_pl[0], STDIN_FILENO);
	}
	exec_simple_cmd(node->left);
}

void exec_pipe_seq(t_ast *ast)
{
	int pid;
	if (ast->right)
	{
		if (!(pid = fork()))
		{
			create_pipe_seq(ast, NULL);
			exit(0);
		}
		waitpid(pid, NULL, 0);
	}
	else
		exec_simple_cmd(ast->left);
}
