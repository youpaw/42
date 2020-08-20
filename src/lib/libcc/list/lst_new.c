/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:29:37 by dbutterw          #+#    #+#             */
/*   Updated: 2020/08/20 19:27:34 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_lst.h"
#include "memory/cc_mem.h"

t_list	*lst_new(void *content, size_t size)
{
	t_list *newlst;

	newlst = (t_list*)xmalloc(sizeof(t_list));
	if (!content)
	{
		newlst->content = NULL;
		newlst->size = 0;
	}
	else
	{
		newlst->content = xmalloc(size);
		newlst->content = memmove(newlst->content, content, size);
		newlst->size = size;
	}
	newlst->next = NULL;
	return (newlst);
}
