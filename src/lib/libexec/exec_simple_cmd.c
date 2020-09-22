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

static int	is_path(const char *path)
{
	if (*path == '/' || !strncmp(path, "./", 2) || !strncmp(path, "../", 3))
		return (1);
	return (0);
}

static const char **get_args(t_ast *ast)
{
	const char **args;
	t_vec *args_vec;

	args_vec = vec_new(10, sizeof(char *), NULL);
	vec_push(args_vec, &ast->token->raw);
	ast = ast->right;
	while (ast)
	{
		if (ast->token->type == l_word)
			vec_push(args_vec, &ast->token->raw);
		ast = ast->right;
	}
	args = (const char **) args_vec->data;
	free(args_vec);
	return (args);
}

void	exec_simple_cmd(t_ast *ast)
{
	const char	**args;
	const char	*path;
	char		**exec_env;

	args = get_args(ast);
	if (run_builtin((const char **) args))
	{
		if (is_path(args[0]))
			path = args[0];
		else
			path = hash_get_path(args[0]);
		exec_env_init();
		if (path)
		{
			exec_env = exec_env_2array();
			execve(path, (char *const *) args, (char *const *) exec_env);
			strarr_del(exec_env);
			free(exec_env);
		}
		exec_env_del();
	}
	free(args);
}