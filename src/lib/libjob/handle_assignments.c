//
// Created by Darth Butterwell on 11/11/20.
//

#include "jobs.h"
#include "env.h"
#include "cc_str.h"

void	handle_assignments(t_process *process)
{
	t_ast		*ast;
	char		*tmp;
	t_hash_map	*env;

	ast = process->ast->left;
	while (ast)
	{
		if (ast->token && ast->token->type == l_assignment_word)
		{
			tmp = strchr(ast->token->raw, '=');
			*tmp = '\0';
			env = env_get_value(ast->token->raw) ? g_env : g_inter_env;
			*tmp = '=';
			env_insert_to(env, ast->token->raw);
		}
		ast = ast->right;
	}
}
