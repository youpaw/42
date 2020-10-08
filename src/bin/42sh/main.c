//
// Created by Darth Butterwell on 9/6/20.
//

#include "main.h"
#include "jobs.h"

int main(int ac, const char *av[], const char *env[])
{
	int error;
	if (!(error = main_init(av[0], av + 1, env)))
	{
		print_process_stats("Init:");
		set_dfl_handlers();
		error = main_manager();
	}
	return (error);
}
