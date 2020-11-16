/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_cmd_suffix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_ast			*node_cmd_suffix(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_cmd_suff);
	if ((node->left = node_io_redirect(tokens)) || \
		!get_node_token(node, tokens))
		node->right = node_cmd_suffix(tokens);
	else
		del_ast(&node);
	return (node);
}
