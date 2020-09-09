//
// Created by Maxon Gena on 9/6/20.
//

#include "readline.h"
#include <signal.h>
#include "cc_char.h"

void	signal_handler(int sig)
{
	char *line;

	if (sig == SIGINT)
	{
		//TODO handle ctrl-C signal
	}
	else if (sig == SIGTSTP)
	{
		//TODO handle ctrl-Z signal
	}
}