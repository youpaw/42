/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_side_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "cc_mem.h"
#include "cc_str.h"
#include <stdlib.h>

t_selection	*add_doubly_list(t_selection *lst, char *word, size_t len)
{
	t_selection *new;
	t_selection *p;

	new = NULL;
	new = xmalloc(sizeof(t_selection));
	new->word = word;
	new->cstring_len = len;
	new->display_len = utf8_display_strlen(word);
	new->under_cursor = false;
	new->selected = false;
	new->vert_pos = -1;
	new->hor_pos = -1;
	if (lst == NULL)
	{
		new->under_cursor = true;
		new->next = new;
		new->prev = new;
		return (new);
	}
	p = lst->prev;
	lst->prev = new;
	new->prev = p;
	new->next = lst;
	p->next = new;
	return (lst);
}

void		delete_lst(t_selection **selection)
{
	t_selection *cpy;

	cpy = *selection;
	while (cpy->next != cpy)
		del_double_list_item(cpy->next);
	del_double_list_item(cpy);
	*selection = NULL;
}

int			del_double_list_item(t_selection *lst)
{
	bool flag;

	flag = false;
	if (lst == lst->next)
		flag = true;
	lst->prev->next = lst->next;
	lst->next->prev = lst->prev;
	free(lst);
	lst = NULL;
	if (flag)
		return (1);
	else
		return (0);
}
