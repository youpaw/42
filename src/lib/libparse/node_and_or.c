/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_and_or.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_ast	*node_and_or(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_and_or);
	if ((node->left = node_pipeline(tokens)))
	{
		if (!get_node_token(node, tokens))
			node->right = node_and_or(tokens);
	}
	else
		del_ast(&node);
	return (node);
}
