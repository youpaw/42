/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free_item.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:39:45 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 11:39:47 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

void	lst_free_item(void *item, size_t size)
{
	if (size == 0)
	{
		exit(1);
	}
	//debug_printf("free item: '%s' (%p)\n", (char*)item, item);
	free(item);
}
