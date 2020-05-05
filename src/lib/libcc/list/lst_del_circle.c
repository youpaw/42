/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelcircle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 18:47:50 by dbutterw          #+#    #+#             */
/*   Updated: 2020/01/06 14:39:22 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_lst.h"

void	lst_del_circle(t_list **list, void (*del)(void*))
{
	t_list *check;
	t_list *head;
	t_list *tmp;

	if (!list || !*list)
		return ;
	check = *list;
	head = (*list)->next;
	while (check != head)
	{
		tmp = head;
		head = head->next;
		lst_del_one(&tmp, del);
	}
	lst_del_one(&check, del);
}
