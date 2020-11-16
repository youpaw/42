/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_ast		*node_list(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_list);
	if ((node->left = node_and_or(tokens)))
	{
		if (!get_node_token(node, tokens))
			node->right = node_list(tokens);
	}
	else
		del_ast(&node);
	return (node);
}
