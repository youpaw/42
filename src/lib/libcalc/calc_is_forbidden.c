/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_is_forbidden.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:01:30 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:01:33 by hlorrine         ###   ########.fr       */
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
