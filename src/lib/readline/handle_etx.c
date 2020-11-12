//
// Created by Maxon Gena on 11/8/20.
//

#include "readline.h"
#include <unistd.h>
#include "env.h"

int			handle_etx(t_inp *inp)
{
	put_cursor_to_the_end(inp);
	write(STDOUT_FILENO, "\n", 1);
	if (inp->hist_storage)
		free(inp->hist_storage);
	del_input(inp);
	g_exit_code = 1;
	return(1);
}