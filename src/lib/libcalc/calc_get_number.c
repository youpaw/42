/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_get_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:52:34 by dbutterw          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:12 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_str.h"
#include "cc_char.h"
#include "calc.h"

static char	*get_number_str(t_calc *calc)
{
	char	*token;
	size_t	start;

	start = calc->index;
	token = NULL;
	while (calc->index < calc->size && isalnum(calc->raw[calc->index]))
		calc->index++;
	if (calc->index > start)
	{
		token = strsub(calc->raw, start, calc->index - start);
		calc->state = c_st_number;
		calc->index--;
	}
	return (token);
}

int			calc_get_number(t_calc *calc)
{
	t_calc_token token;

	if (!(token.raw = get_number_str(calc)))
		return (1);
	token.type = c_number;
	token.priority = calc_get_priority(token.type);
	vec_push(calc->tokens, &token);
	return (0);
}
