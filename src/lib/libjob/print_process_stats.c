#include <unistd.h>
#include "cc_str.h"
#include "cc_num.h"
#include "jobs.h"

static void	print_id(const char *str, int num)
{
	puts(str);
	putnbr(num);
	puts(" ");
}

void	print_process_stats(const char *str)
{
	puts("\033[1;32m"); // Bold green
	putendl(str);
	print_id("PPID=", getppid());
	print_id("PID=", getpid());
	print_id("PGID=", getpgrp());
	print_id("term=", tcgetpgrp(STDIN_FILENO));
	puts("\n");
	puts("\033[0m"); // Reset color
}
