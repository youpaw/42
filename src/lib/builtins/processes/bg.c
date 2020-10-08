#include "cc_str.h"
#include "jobs.h"
#include "cc_num.h"

int 	bg(const char **av)
{
	/*
	size_t		index;

	index = g_jobs.last_job_index;
	if (av[1])
		index = atoi(av[1]);
	if (remove_job_by_index(index))
		putendl("no such job to remove");
	else
	{
		putnbr(index);
		putendl(" job successfully removed");
	}
	 */
	putendl("bg builtin");
	return (0);
}
