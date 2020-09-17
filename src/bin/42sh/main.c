//
// Created by Darth Butterwell on 9/6/20.
//

#include "main.h"
#include "readline.h"
int main(int ac, const char *av[], const char *env[])
{
	int error;

//	if (!(error = main_init(av[0], av + 1, env)))
//		error = main_manager();
	char *line = "";

	readline(&line);
	return (error);
}

