//
// Created by Maxon Gena on 11/5/20.
//

#include "readline.h"
#include "history.h"
#include "cc_num.h"
#include "cc_str.h"
#include "termcap.h"
#include "cc_char.h"
#include <sys/ioctl.h>

int handle_up_arrow(t_input *inp)
{
	char *new_hist;
	char *tmp;

	if (!inp->hist_storage)
		inp->hist_storage = input_to_str(*inp, 1);
	new_hist = strdup(hist_get_prev());
	if (new_hist)
	{
		tmp = inp->hist_storage;
		clear_display_input(inp);
		reload_input(inp, new_hist);
		inp->hist_storage = tmp;
	}
	return (0);
}