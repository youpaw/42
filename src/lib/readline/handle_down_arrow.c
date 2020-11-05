//
// Created by Maxon Gena on 11/5/20.
//

#include "readline.h"
#include "history.h"
#include "cc_str.h"

int handle_down_arrow(t_input *inp)
{
//	hist_push(input_to_str(*inp));
	clear_display_input(inp);
	put_str_to_inp(inp, strdup(hist_get_next()));
	return (0);
}