/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_side_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:53:03 by mgena             #+#    #+#             */
/*   Updated: 2020/08/14 15:09:51 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_selection	*add_doubly_list(t_selection *lst, char *word, size_t len)
{
	t_selection *new;
	t_selection *p;

	new = NULL;
	new = ft_memalloc(sizeof(t_selection));
	new->word = word;
	new->len = len;
	new->filetype = get_filetype(word);
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

void		delete_elem(t_selection **selection)
{
	t_selection *cpy;

	cpy = *selection;
	while (!cpy->under_cursor)
		cpy = cpy->next;
	if (cpy == *selection)
		*selection = cpy->next;
	cpy->next->under_cursor = true;
	if (del_double_list_item(cpy))
		escape();
}

int			del_double_list_item(t_selection *lst)
{
	bool flag;

	flag = false;
	if (lst == lst->next)
		flag = true;
	lst->prev->next = lst->next;
	lst->next->prev = lst->prev;
	ft_strdel(&lst->word);
	free(lst);
	lst = NULL;
	if (flag)
		return (1);
	else
		return (0);
}
