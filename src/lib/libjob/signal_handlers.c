//
// Created by Azzak Omega on 10/8/20.
//

#include <signal.h>
#include "jobs.h"

static void	set_handlers(void (*sig_handler)(int arg),
							void(*sigint_handler)(int arg))
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sig_handler);
	signal(SIGTSTP, sig_handler);
	signal(SIGTTIN, sig_handler);
	signal(SIGTTOU, sig_handler);
}

void	ignore_job_and_interactive_signals(void)
{
	set_handlers(SIG_IGN, SIG_IGN);
}

void	restore_job_and_interactive_signals(void)
{
	set_handlers(SIG_DFL, SIG_DFL);
}

//#define SIGHUP  1       /* hangup */
//#define SIGINT  2       /* interrupt */
//#define SIGQUIT 3       /* quit */
//#define SIGILL  4       /* illegal instruction (not reset when caught) */
//#define SIGTRAP 5       /* trace trap (not reset when caught) */
//#define SIGABRT 6       /* abort() */
//#define SIGFPE  8       /* floating point exception */
//#define SIGKILL 9       /* kill (cannot be caught or ignored) */
//#define SIGBUS  10      /* bus error */
//#define SIGSEGV 11      /* segmentation violation */
//#define SIGSYS  12      /* bad argument to system call */
//#define SIGPIPE 13      /* write on a pipe with no one to read it */
//#define SIGALRM 14      /* alarm clock */
//#define SIGTERM 15      /* software termination signal from kill */
//#define SIGURG  16      /* urgent condition on IO channel */
//#define SIGSTOP 17      /* sendable stop signal not from tty */
//#define SIGTSTP 18      /* stop signal from tty */
//#define SIGCONT 19      /* continue a stopped process */
//#define SIGCHLD 20      /* to parent on child stop or exit */
//#define SIGTTIN 21      /* to readers pgrp upon background tty read */
//#define SIGTTOU 22      /* like TTIN for output if (tp->t_local&LTOSTOP) */
//#define SIGXCPU 24      /* exceeded CPU time limit */
//#define SIGXFSZ 25      /* exceeded file size limit */
//#define SIGVTALRM 26    /* virtual time alarm */
//#define SIGPROF 27      /* profiling time alarm */
//#if  (!defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE))
//#define SIGWINCH 28     /* window size changes */
//#define SIGINFO 29      /* information request */
//#endif
