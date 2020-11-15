/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_here_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_ast		*node_here_end(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_here_end);
	if (get_node_token(node, tokens))
		del_ast(&node);
	return (node);
}
