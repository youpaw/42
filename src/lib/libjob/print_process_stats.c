#include <sys/types.h>
#include <unistd.h>
#include "cc_str.h"
#include "cc_num.h"

static void	print_id(const char *str, int num)
{
	puts(str);
	putnbr(num);
	puts(" ");
}

void	print_process_stats(const char *str)
{
	//print_id("PPID=", getppid());
	//print_id("PID=", getpid());
	//print_id("PGID=", getpgid(getpid()));
	putendl(str);
	print_id("PPID=", getppid());
	print_id("PID=", getpid());
	print_id("PGID=", getpgrp());
	print_id("term=", tcgetpgrp(STDIN_FILENO));
	puts("\n");
}
