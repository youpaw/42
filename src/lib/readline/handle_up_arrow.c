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

//	hist_push(input_to_str(*inp));
	clear_display_input(inp);
	put_str_to_inp(inp, strdup(hist_get_prev()));
	return (0);
}