/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_name_length.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:05:35 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:05:40 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <glob.h>
#include "env.h"

size_t			get_valid_name_length(const char *name)
{
	size_t index;

	if ((index = get_valid_name_length_no_check(name)) && name[index] == '=')
		return (index);
	return (0);
}
