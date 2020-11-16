/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_selection	*get_under_cursor(t_selection **selection)
{
	t_selection *cpy;

	cpy = *selection;
	while (!cpy->under_cursor)
		cpy = cpy->next;
	return (cpy);
}
