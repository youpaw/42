/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 02:35:24 by dbutterw          #+#    #+#             */
/*   Updated: 2020/08/20 19:30:12 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_str.h"

int		strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
		if (strcmp(s1, s2) == 0)
			return (1);
	if (!s1 && !s2)
		return (1);
	return (0);
}
