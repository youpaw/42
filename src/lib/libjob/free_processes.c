/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include "cc_str.h"

void	free_processes(t_process *p)
{
	if (!p)
		return ;
	free(p->argv);
	strarr_del(p->env);
	free(p->env);
	free_processes(p->next);
	free(p->next);
}
