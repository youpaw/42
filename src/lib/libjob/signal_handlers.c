//
// Created by Azzak Omega on 10/8/20.
//

#include <signal.h>

static void	set_handlers(void (*sig_handler)(int arg),
							void(*sigint_handler)(int arg))
{
	signal (SIGQUIT, sig_handler);
	signal (SIGTSTP, sig_handler);
	signal (SIGTTIN, sig_handler);
	signal (SIGTTOU, sig_handler);
	signal (SIGCHLD, sig_handler);
	signal (SIGINT, sigint_handler);
}

void	set_ignore_handlers(void)
{
	set_handlers(SIG_IGN, SIG_IGN);
}
void	set_dfl_handlers(void)
{
	set_handlers(SIG_DFL, SIG_DFL);
}
