/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_parse_left_side.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include "cc_num.h"

int		redirect_parse_left_side(t_ast *leafs, int default_value)
{
	int left;

	left = default_value;
	if (leafs->token)
	{
		if (leafs->token->type == l_io_number)
		{
			if (leafs->token->raw)
				left = atoi(leafs->token->raw);
		}
	}
	return (left);
}
