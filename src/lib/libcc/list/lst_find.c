/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:15:52 by dbutterw          #+#    #+#             */
/*   Updated: 2020/01/06 14:39:22 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_lst.h"

t_list	*lst_find(t_list *lst, int (*cmp)(const void *, const void *),
		const void *content)
{
	t_list	*next;

	if (!lst || !cmp || !content)
		return (NULL);
	while (lst != 0)
	{
		next = lst->next;
		if (cmp(lst->content, content) == 0)
			return (lst);
		lst = next;
	}
	return (NULL);
}