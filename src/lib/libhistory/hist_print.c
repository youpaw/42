//
// Created by Azzak Omega on 8/23/20.
//

#include "history.h"
#include "cc.h"

void	hist_print(void)
{
	int		i;
	char	*str;

	i = 0;
	while (i++ < g_hist.commands->size)
	{
		if (i < 10)
			putchar(' ');
		if (i < 100)
			putchar(' ');
		if (i < 1000)
			putchar(' ');
		putchar(' ');
		putnbr(i);
		puts("  ");
		vec_get_at(&str, g_hist.commands, i - 1);
		putendl(str);
	}
}
