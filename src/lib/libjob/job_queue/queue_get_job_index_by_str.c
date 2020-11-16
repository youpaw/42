/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_get_job_index_by_str.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include "cc_str.h"

int	queue_get_job_index_by_str(const char *str)
{
	if (!str)
		return (queue_get_current(1));
	if (str[0] == '+')
		return (queue_get_current(1));
	if (str[0] == '-')
		return (queue_get_last(1));
	if (strisnum(str))
		return (atoi(str));
	return (-1);
}
