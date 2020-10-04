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

static char **get_args(t_ast *ast)
{
	char		**args;
	t_ast		*cpy;
	int			cnt;

	cnt = 0;
	cpy = ast;
	while (ast)
	{
		if (ast->token->type == l_word || ast->token->type == l_command_name)
		{
			if ((g_exit_code = expand_token(ast->token)))
				exit(g_exit_code);
			cnt++;
		}
		ast = ast->right;
	}
	args = xmalloc(sizeof(char *) * (cnt + 1));
	cnt = 0;
	args[cnt] = cpy->token->raw;
	while (cpy)
	{
		if (cpy->token->type == l_word || cpy->token->type == l_command_name)
			args[cnt++] = cpy->token->raw;
		cpy = cpy->right;
	}
	args[cnt] = NULL;
	return (args);
}

void	exec_simple_cmd(t_ast *ast)
{
	char		**args;
	const char	*path;
	char		**exec_env;

	args = get_args(ast);
	strarr_print(args, NULL, NULL);
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
			if (!fork())
				execve(path, (char *const *) args, (char *const *) exec_env);
			strarr_del(exec_env);
			free(exec_env);
		}
		exec_env_del();
	}
	free(args);
}