//
// Created by slava-nya on 9/22/20.
//

#include "builtins.h"
#include "cc_str.h"

int					echo(const char **av)
{
	int cnt;

	cnt = 1;
	while (av[cnt])
	{
		puts(av[cnt]);
		cnt++;
	}
	return (0);
}