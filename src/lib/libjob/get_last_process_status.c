//
// Created by Azzak Omega on 11/3/20.
//
#include "jobs.h"

int		get_last_process_status(t_process *p)
{
	if (!p)
		return (0);
	while (p->next)
		p = p->next;
	return (p->status);
}
