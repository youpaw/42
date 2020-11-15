/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_bang.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_char.h"
#include "cc_str.h"
#include "history.h"
#include "stdlib.h"

static int	is_number(const char *num)
{
	if (*num == '-')
		num++;
	while (isdigit(*num))
		num++;
	if (!*num)
		return (1);
	return (0);
}

int			expand_bang(char **str)
{
	char	*value;

	value = NULL;
	if (strcmp(*str, "!") == 0)
		value = hist_get_last();
	else if (is_number(*str))
		value = hist_get_by_index(atoi(*str));
	else
		value = hist_get_by_prefix(*str);
	if (value)
	{
		free(*str);
		*str = strdup(value);
		return (0);
	}
	return (1);
}
