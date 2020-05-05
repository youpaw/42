/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_dlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:00:51 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 13:00:52 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc.h"
#include "lists.h"

t_d_list *g_head = NULL;
t_d_list *g_current = NULL;
t_d_list *g_last = NULL;

void		h_append(const char *content)
{
	t_d_list	*l;

	if (g_last != NULL && str_equals(content, (const char *)(g_last->list.content)))
	{
		return ;
	}
	l = dlst_new(strdup(content), -1);
	l->prev = g_last;
	if (g_last == NULL)
	{
		g_last = l;
		g_head = l;
		return;
	}
	g_last->list.next = (t_list *)l;
	g_last = l;
	g_current = NULL;
}

int		h_free(void)
{
	if (g_head == NULL)
	{
		return (E_OK);
	}
	lst_free((t_list **)&g_head);
	g_last = NULL;
	g_current = NULL;
	if (g_head != NULL)
	{
		return (E_FAIL);
	}
	return (E_OK);
}

t_list *h_get_head()
{
	return (g_head == NULL ? NULL : (t_list*) g_head);
}

t_list *h_get_last()
{
	return (h_get_head() == NULL ? NULL : lst_get_last(h_get_head()));
}