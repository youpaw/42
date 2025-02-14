/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "jobs.h"

char	**get_args(t_ast *ast)
{
	t_vec	*vec;
	char	**args;

	args = NULL;
	vec = vec_new(JOB_VEC_CAPACITY, sizeof(char *), NULL);
	if (ast->token)
		vec_push(vec, &ast->token->raw);
	ast = ast->right;
	while (ast)
	{
		if (ast->token && ast->token->type == l_word)
			vec_push(vec, &ast->token->raw);
		ast = ast->right;
	}
	if (vec->size)
	{
		args = (char **)vec->data;
		free(vec);
	}
	else
		vec_del(&vec);
	return (args);
}
