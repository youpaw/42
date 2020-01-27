/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_reduce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:40:25 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 11:40:27 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

void	*lst_reduce(t_list *lst, void (f)(t_list*, void*), void *accumulator)
{
	if (lst == NULL)
	{
		return (accumulator);
	}
	f(lst, accumulator);
	return (lst_reduce(lst->next, f, accumulator));
}
