#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include "cc_vec.h"

int status, child_pid, var;

void int_handler(int arg)
{
	printf("Child terminated.---..\n");
}


void sig_handler(int code)
{
	printf("Signal %d caught\n", code);
}

int main(void)
{
	t_vec	*processes;

	processes = vec_new(10, sizeof(int), NULL);
	vec_del(&processes);
	var = 0;
	printf("init var = %d\n", var);
	printf("pgrp=%d pid=%d term=%d\n", getpgrp(), getpid(), tcgetpgrp(STDIN_FILENO));

	/* Ignore interactive and job-control signals.  */

	signal (SIGQUIT, sig_handler);
	signal (SIGTSTP, sig_handler);
	signal (SIGTTIN, sig_handler);
	signal (SIGTTOU, sig_handler);
	signal (SIGCHLD, sig_handler);
	signal (SIGINFO, sig_handler);
	//signal (SIGINT, sig_handler);
	signal (SIGINT, SIG_IGN);


	status = 0;
	printf("status = %d\n", status);

	if( (child_pid = fork()) < 0) {
		perror("fork:");
		exit(1);
	}

	if( child_pid == 0)
	{ /* child */
		var = 2;
		signal (SIGINT, SIG_DFL);

		printf("child\n");
		printf("chld  var = %d\n", var);
		printf("pgrp=%d pid=%d term=%d\n", getpgrp(), getpid(),
			   tcgetpgrp(STDIN_FILENO));
		sleep(10);
	}
	else /* parent */ {
		printf("parent\n");
		printf("parent  var = %d\n", var);
		printf("pgrp=%d pid=%d term=%d\n", getpgrp(), getpid(), tcgetpgrp(STDIN_FILENO));
		//wait(&status);
		printf("status = %d\n", status);
	}

	printf("final  var = %d\n", var);
	return (0);
}
