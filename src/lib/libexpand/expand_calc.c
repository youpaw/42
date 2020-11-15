/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"
#include "cc_regex.h"
#include "cc_str.h"

int			expand_calc(char **str)
{
	const char	*arg[4];
	char		*tmp;

	if (!match(*str, "(*)"))
	{
		arg[0] = "(";
		arg[1] = *str;
		arg[2] = ")";
		arg[3] = NULL;
		tmp = strnjoin(arg);
		free(*str);
		*str = tmp;
	}
	return (sh_calc(str));
}
