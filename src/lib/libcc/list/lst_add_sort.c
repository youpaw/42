/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 18:03:05 by dbutterw          #+#    #+#             */
/*   Updated: 2020/01/06 14:39:22 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_lst.h"

int lst_add_sort(t_list **list, t_list *newlist, void *params, \
		int (*cmp)(const void *, const void *, void *))
{
	t_list *prev;
	t_list *head;

	if (!list || !newlist || !cmp)
		return (LST_DNE);
	if (!*list)
	{
		*list = newlist;
		return (LST_OK);
	}
	prev = NULL;
	head = *list;
	while (head && cmp(newlist->content, head->content, params) > 0)
	{
		prev = head;
		head = head->next;
	}
	newlist->next = head;
	if (!prev)
		*list = newlist;
	else
		prev->next = newlist;
	return (LST_OK);
}
