/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_name_length_no_check.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:05:30 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:05:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <glob.h>
#include "cc_char.h"
#include "env.h"

static int	is_char_valid(char c)
{
	return (isalnum(c) || c == '_');
}

size_t		get_valid_name_length_no_check(const char *name)
{
	size_t index;

	index = 0;
	if (isdigit(name[index]))
		return (0);
	while (is_char_valid(name[index]))
		index++;
	return (index);
}
