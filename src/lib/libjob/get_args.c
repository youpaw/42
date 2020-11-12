//
// Created by youpaw on 10/5/20.
//

#include "parser.h"
#include "jobs.h"

char	**get_args(t_ast *ast)
{
	t_vec	*vec;
	char	**args;

	vec = vec_new(JOB_VEC_CAPACITY, sizeof(char *), NULL);
	vec_push(vec, &ast->token->raw);
	ast = ast->right;
	while (ast)
	{
		if (ast->token && ast->token->type == l_word)
			vec_push(vec, &ast->token->raw);
		ast = ast->right;
	}
	args = (char **)vec->data;
	free(vec);
	return (args);
}
