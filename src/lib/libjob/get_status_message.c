//
// Created by Azzak Omega on 11/4/20.
//

#include <signal.h>
#include <sys/wait.h>
#include "cc_str.h"
#define N_SIGNALS 25


static	int get_signal_index(int signal)
{
	int i;
	static int signals[N_SIGNALS] = {
			SIGHUP, SIGINT,
			SIGQUIT, SIGILL,
			SIGTRAP, SIGABRT,
			SIGEMT, SIGFPE,
			SIGKILL, SIGBUS,
			SIGSEGV, SIGSYS,
			SIGPIPE, SIGALRM,
			SIGTERM, SIGSTOP,
			SIGTSTP, SIGTTIN,
			SIGTTOU, SIGXCPU,
			SIGXFSZ, SIGVTALRM,
			SIGPROF, SIGUSR1,
			SIGUSR2};

	i = -1;
	while (++i < N_SIGNALS)
		if (signal == signals[i])
			return (i);
	return (-1);
}

static	const char	*get_signal_string(int signal)
{
	int i;
	static const char *builtins_names[N_SIGNALS] = {
			"Hangup: 1", "Interrupt: 2",
			"Quit: 3", "Illegal instruction: 4",
			"Trace/BPT trap: 5", "Abort trap: 6",
			"EMT trap: 7", "Floating point exception: 8",
			"Killed: 9", "Bus error: 10",
			"Segmentation fault: 11", "Bad system call: 12",
			"Broken pipe: 13", "Alarm clock: 14",
			"Terminated: 15", "Stopped (SIGSTOP)",
			"Stopped (SIGTSTP)", "Stopped (SIGTTIN)",
			"Stopped (SIGTTOU)", "Cputime limit exceeded: 24",
			"Filesize limit exceeded: 25", "Virtual timer expired: 26",
			"Profiling timer expired: 27", "User defined signal 1: 30",
			"User defined signal 2: 31"};

	if ((i = get_signal_index(signal)) != -1)
		return (builtins_names[i]);
	return (NULL);
}



char				*get_status_message(int status)
{
	char	*msg;
	char	*code;

	if (WIFSTOPPED(status))
		msg = get_signal_string(WSTOPSIG(status));
	else if (WIFSIGNALED(status))
		msg = get_signal_string(WTERMSIG(status));
	else
	{
		if (WEXITSTATUS(status) == 0)
			msg = "Done";
		else
		{
			code = itoa(WEXITSTATUS(status));
			msg = strjoin("Exit ", code);
			strdel(&code);
			return (msg);
		}
	}
	msg = strdup(msg);
	return (msg);
}
