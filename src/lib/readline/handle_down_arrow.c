//
// Created by Maxon Gena on 11/5/20.
//

#include "readline.h"
#include "history.h"
#include "cc_str.h"

int handle_down_arrow(t_input *inp)
{
	char *new_hist;

	new_hist = (hist_get_next());
	if (!new_hist)
	{
		if (inp->hist_storage)
		{
			new_hist = inp->hist_storage;
			inp->hist_storage = NULL;
		}
		else
		{
			puts("\7");
			return (0);
		}
	}
	else
		new_hist = strdup(new_hist);
	clear_display_input(inp);
	reload_input(inp, new_hist);
	return (0);
}