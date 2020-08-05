/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:09:38 by dbutterw          #+#    #+#             */
/*   Updated: 2020/01/06 14:39:22 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_lst.h"

int lst_del(t_list **alst, void (*del)(void *))
{
	t_list *tmp;

	if (!alst)
		return (LST_DNE);
	while (*alst)
	{
		tmp = (*alst)->next;
		lst_del_one(alst, del);
		*alst = tmp;
	}
	return (LST_OK);
}
