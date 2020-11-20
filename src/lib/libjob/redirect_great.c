/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_great.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "jobs.h"

int		redirect_great(t_ast *leafs, t_process *process, int is_double_great)
{
	int options;
	int from;
	int to;

	options = O_WRONLY | O_CREAT | (is_double_great ? O_APPEND : O_TRUNC);
	from = redirect_parse_left_side(leafs, 1);
	to = redirect_parse_right_side(leafs->left->left->token, options, 0, 0);
	if (to == 1 || to == -1)
		return (1);
	redirect_init_process_file(process, from, to);
	return (0);
}
