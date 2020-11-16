/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "cc_str.h"

static void		get_node_tokens(t_ast *ast, t_vec *vec)
{
	static char *delimiter = " ";

	if (!ast)
		return ;
	if (ast->type == p_io_redirect)
	{
		if (ast->token)
			vec_push(vec, &ast->token->raw);
		vec_push(vec, &ast->left->token->raw);
		vec_push(vec, &ast->left->left->token->raw);
		vec_push(vec, &delimiter);
		return ;
	}
	get_node_tokens(ast->left, vec);
	if (ast->token)
	{
		vec_push(vec, &ast->token->raw);
		vec_push(vec, &delimiter);
	}
	get_node_tokens(ast->right, vec);
}

char			*get_command(t_ast *ast)
{
	char	*command;
	t_vec	*vec;

	vec = vec_new(JOB_VEC_CAPACITY, sizeof(char *), NULL);
	get_node_tokens(ast, vec);
	vec_rm_last(vec);
	command = strnjoin((const char **)vec->data);
	vec_del(&vec);
	return (command);
}
