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

int lst_add(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return (LST_DNE);
	if (!*alst)
		*alst = new;
	else
	{
		new->next = *alst;
		*alst = new;
	}
	return (LST_OK);
}
