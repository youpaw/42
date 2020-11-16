/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_job_by_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"

t_job	*find_job_by_index(int index)
{
	t_job *j;

	if (index < 1)
		return (NULL);
	if ((j = g_first_job))
		while (j->next)
		{
			if (j->index == index)
				return (j);
			j = j->next;
		}
	return (NULL);
}
