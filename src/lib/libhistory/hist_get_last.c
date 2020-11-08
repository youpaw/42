//
// Created by Azzak Omega on 8/23/20.
//

#include "history.h"
#include <stddef.h>

char 	*hist_get_last(void)
{
	char	*str;

	if (g_hist.commands->size < 1)
		return (NULL);
	vec_get_at(&str, g_hist.commands, g_hist.commands->size - 1);
	return (str);
}
