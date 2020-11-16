/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_less_and_right_side.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include "cc_str.h"

int		redirect_less_and_right_side(t_ast *leafs)
{
	int to;

	to = -1;
	if (strisnum(leafs->left->left->token->raw))
	{
		to = atoi(leafs->left->left->token->raw);
		if (!is_standard_io(to))
			return (redirect_print_error(E_BADFD,
								leafs->left->left->token->raw));
	}
	else if (strcmp(leafs->left->left->token->raw, "-") == 0)
		return (-2);
	else
		return (redirect_print_error(E_AMBIG, leafs->left->left->token->raw));
	return (to);
}
