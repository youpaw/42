/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_cmd_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_ast		*node_cmd_prefix(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_cmd_pref);
	if ((node->left = node_io_redirect(tokens)) || \
		!get_node_token(node, tokens))
		node->right = node_cmd_prefix(tokens);
	else
		del_ast(&node);
	return (node);
}
