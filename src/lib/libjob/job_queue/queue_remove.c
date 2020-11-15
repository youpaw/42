/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include "cc_vec.h"

void	queue_remove(int index)
{
	size_t	i;
	int		found_index;

	i = 0;
	while (i < g_job_queue->size)
	{
		vec_get_at(&found_index, g_job_queue, i);
		if (index == found_index)
		{
			vec_rm_at(g_job_queue, i);
			break ;
		}
		i++;
	}
}
