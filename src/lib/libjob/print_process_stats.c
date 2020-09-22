#include <sys/types.h>
#include <unistd.h>
#include "cc_str.h"
#include "cc_num.h"

static void	print_id(const char *str, int num)
{
	puts(str);
	putnbr(num);
	puts("\n");
}

void	print_process_stats(void)
{
	//print_id("PPID=", getppid());
	//print_id("PID=", getpid());
	//print_id("PGID=", getpgid(getpid()));
	print_id("PPID=", getppid());
	print_id("PID=", getpid());
	print_id("PGID=", getpgid(0));
}
