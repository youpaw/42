//
// Created by Azzak Omega on 8/23/20.
//

#include "history.h"
#include "cc.h"

void	hist_print(void)
{
	int i;

	i = 0;
	while (i++ < g_hist.size)
	{
		if (i < 10)
			putchar(' ');
		if (i < 100)
			putchar(' ');
		putnbr(i);
		puts("  ");
		putendl(g_hist.commands[i - 1]);
	}
}
