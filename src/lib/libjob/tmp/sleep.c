#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>

#define N_COLORS 12

const char *colors[] = {
	"\033[0;31m", //	Red
	"\033[1;31m", //	Bold Red
	"\033[0;32m", //	Green
	"\033[1;32m", // Bold Green
	"\033[0;33m", // Yellow
	"\033[01;33m", // Bold Yellow
	"\033[0;34m", // Blue
	"\033[1;34m", // Bold Blue
	"\033[0;35m", // Magenta
	"\033[1;35m", // Bold Magenta
	"\033[0;36m", // Cyan
	"\033[1;36m", // Bold Cyan
	"\033[0m" //	Reset
};

void print_color(int i)
{
	printf("%s", colors[i]);
}

void reset () {
	print_color(12);
}

int main (int ac, char **av)
{    
	int	count;
	int color;
   
	count = 10;
	if (ac == 2)
	   count = atoi(av[1]);
	color = count % N_COLORS;
	print_color(color);
	printf ("Sleep process with PID %d will sleep for %d s\n", getpid(), count);
	printf ("PGID is %d\n", getpgid(getpid()));
	printf ("PPID is %d\n", getppid());
	reset();
	while (count--)  
	{   
		print_color(color);
		printf ("%d sleeps...\n", getpid());
		reset();
		sleep (1);
	}
	print_color(color);
	printf ("Sleep with PID %d ended\n", getpid());
	reset();
   return 0;
}
