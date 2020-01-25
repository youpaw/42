/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:00:51 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 13:00:52 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc.h"
#include "lists.h"

extern t_d_list *g_head;
extern t_d_list *g_current;
extern t_d_list *g_last;


BOOL		h_has_prev(void)
{
	return (g_current == NULL ? g_last != NULL : g_current->prev != NULL);
}

BOOL		h_has_next(void)
{
	return ((g_current != NULL && g_current->list.next != NULL));
}

int		h_get_current(char *out)
{
	if (g_current == NULL)
	{
		*out = 0;
		return (E_FAIL);
	}
	strcpy(out, (const char *)g_current->list.content);
	return (E_OK);
}

int	h_get_prev(char *out)
{
	if (!h_has_prev())
	{
		*out = 0;
		return (E_FAIL);
	}
	g_current = g_current == NULL ? g_last : g_current->prev;
	return (h_get_current(out));
}

int	h_get_next(char *out)
{
	if (!h_has_next())
	{
		*out = 0;
		return (E_FAIL);
	}
	g_current = (t_d_list *)g_current->list.next;
	return (h_get_current(out));
}
