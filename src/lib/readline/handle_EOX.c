//
// Created by Maxon Gena on 11/8/20.
//

#include "readline.h"
#include <unistd.h>
#include "env.h"

int			handle_eox(t_inp *inp)
{
	put_cursor_to_the_end(inp);
	write(STDOUT_FILENO, "\n", 1);
	del_input(inp);
	g_exit_code = 1;
	return(1);
}
