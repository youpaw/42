/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:00:15 by dbutterw          #+#    #+#             */
/*   Updated: 2020/01/06 14:39:22 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_lst.h"

int lst_del_one(t_list **alst, void (*del)(void*))
{
	if (!alst)
		return (LST_DNE);
	if (!*alst)
		return (LST_OK);
	if ((*alst)->content && del)
		del((*alst)->content);
	free((*alst)->content);
	free(*alst);
	*alst = NULL;
	return (LST_OK);
}
