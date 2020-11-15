//
// Created by Darth Butterwell on 11/11/20.
//

#include "jobs.h"
#include "env.h"
#include "cc_str.h"

void	handle_assignments(t_process *process)
{
	t_ast		*ast;

	ast = process->ast->left;
	while (ast)
	{
		if (ast->token && ast->token->type == l_assignment_word)
			env_update(ast->token->raw);
		ast = ast->right;
	}
}
