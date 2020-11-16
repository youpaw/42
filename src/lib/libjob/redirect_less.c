/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_less.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/15 18:29:16 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include <unistd.h>
#include <fcntl.h>

int		redirect_less(t_ast *leafs, t_process *process)
{
	int in;
	int to;

	to = redirect_parse_left_side(leafs, 0);
	in = -1;
	if (leafs->left->left->token->type == l_filename)
	{
		if (!access(leafs->left->left->token->raw, F_OK))
		{
			if (access(leafs->left->left->token->raw, R_OK))
				return (redirect_print_error(E_ACCES,\
					leafs->left->left->token->raw));\
					in = open(leafs->left->left->token->raw, O_RDONLY);
			if (-1 == in)
				return (1);
			redirect_init_process_file(process, to, in);
		}
		else
			return (redirect_print_error(E_NOENT,
							leafs->left->left->token->raw));
	}
	return (0);
}
