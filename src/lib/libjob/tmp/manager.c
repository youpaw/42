//
// Created by Azzak Omega on 9/25/20.
//
#include <unistd.h>
#include <stdlib.h>
#include "cc_str.h"

/* Make your shell its process group leader */
void	make_proc_leader(void)
{
	if (setpgid (getpid(), getpid()) < 0) {
		fdputendl("Make proc leader failed!!!", 2);
		exit (1);
	}
}


/* transfer controlling terminal */
void	get_term_control(void)
{
	if( tcsetpgrp (STDIN_FILENO, getpgrp()) < 0) {
		fdputendl("Get term control failed!!!", 2);
		exit(1);
	}
}
