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

int	lst_del_circle(t_list **list, void (*del)(void*))
{
	t_list *check;
	t_list *head;
	t_list *tmp;

	if (!list)
		return (LST_DNE);
	if (!*list)
		return (LST_OK);
	check = *list;
	head = (*list)->next;
	while (check != head)
	{
		tmp = head;
		head = head->next;
		lst_del_one(&tmp, del);
	}
	lst_del_one(&check, del);
	return (LST_OK);
}
