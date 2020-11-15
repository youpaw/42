/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_is_forbidden.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_char.h"

static int	isspecial(char c)
{
	static const char	*str = "*+-/%()<=>!&|";
	int					index;

	index = 0;
	while (str[index] && c != str[index])
		index++;
	if (str[index])
		return (1);
	return (0);
}

int			calc_is_forbidden(char c)
{
	return (!(isalnum(c) || isspecial(c)));
}
