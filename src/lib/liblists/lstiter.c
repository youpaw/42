/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:20:54 by darugula          #+#    #+#             */
/*   Updated: 2019/09/16 21:20:56 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

void	lstiter(t_list *lst, void (*f)(t_list *))
{
	if (lst == NULL)
	{
		return ;
	}
	f(lst);
	lstiter(lst->next, f);
}
