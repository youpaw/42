/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_parse_right_side.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include "cc_str.h"
#include <fcntl.h>
#include "error.h"
#include "cc_num.h"

int		redirect_parse_right_side(t_token *token, int open_options,
							int can_be_number, int is_maybe_minus)
{
	int right_side;

	if (can_be_number && strisnum(token->raw))
	{
		right_side = atoi(token->raw);
		if (!is_standard_io(right_side))
			return (redirect_print_error(E_BADFD, token->raw));
		return (right_side);
	}
	else if (is_maybe_minus)
	{
		if (strcmp(token->raw, "-") == 0)
			return (-2);
	}
	if ((!access(token->raw, F_OK)) && (access(token->raw, W_OK) == -1))
		return (redirect_print_error(E_ACCES, token->raw));
	if ((right_side = open(token->raw, open_options, 0644)) == -1)
		return (1);
	return (right_side);
}
