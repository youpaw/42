//
// Created by youpaw on 02.05.2020.
//

#include "exec.h"
#include "cc_mem.h"
#include "builtins.h"
#include "hash.h"
#include "cc_str.h"
#include "env.h"
#include <unistd.h>

static void run_bin(const char **args)
{
	char		**exec_env;
	const char	*path;
	pid_t		pid;

	if (is_path(args[0]))
		path = args[0];
	else
		path = hash_get_path(args[0]);
	if (path)
	{
		exec_env = exec_env_2array();
		if (!(pid = fork()))
		{
			execve(path, (char *const *) args, (char *const *) exec_env);
			exit(0);
		}
		else
			waitpid(pid, NULL, 0);
		strarr_del(exec_env);
		free(exec_env);
	}
}

static void close_redirect_fds(int *fd_arr)
{
	int index;

	if (!fd_arr)
		return ;
	index = 0;
	while (fd_arr[index] >= 0)
		close(fd_arr[index++]);
}

void	exec_simple_cmd(t_ast *ast)
{
	char	**args;
	int 	*fd_arr;
	int 	fd_backup[3];

	fd_arr = NULL;
	if (stdio_backup(fd_backup))
		return ;
	if (expand_ast(ast) || prepare_redirect(ast, &fd_arr))
	{
		close_fds(fd_backup, 3);
		return ;
	}
	args = get_args(ast);
	if (run_builtin((const char **) args))
	{
		prepare_exec_env(ast->left);
		run_bin((const char **) args);
		exec_env_del();
	}
	stdio_reset(fd_backup);
	close_fds(fd_backup, 3);
	close_redirect_fds(fd_arr);
	free(args);
}
