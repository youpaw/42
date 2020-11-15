/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_get_current.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include "cc_vec.h"

int		queue_get_current(int is_job_builtin)
{
	int		index;
	int		queue_size;

	queue_size = (int)g_job_queue->size - is_job_builtin;
	if (queue_size > 0 && !vec_get_at(&index, g_job_queue,
											queue_size - 1))
		return (index);
	return (-1);
}
