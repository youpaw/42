//
// Created by Darth Butterwell on 9/6/20.
//

#include "main.h"
#include "readline.h"
#include "history.h"
#include "cc_char.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>

int main(int ac, const char *av[], const char *env[])
{
	t_letter res;
	int len;
	char *line = "it's not original text\nBut I think about it for a few seconds\nso its my original text\n";
	int error;
	struct winsize ws;

	tty_init();
	hist_init("/Users/azomega");
	signal_init();
	if (ac == 2)
	{

		ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
		printf("%d, %d\n", ws.ws_col, ws.ws_row);
		len = 0;
		while (len != ws.ws_col + 1)
		{
			printf("%d", len % 10);
			len++;
		}
//		res.num = getch();
//		printf("%o %o \n", res.ch[0], res.ch[1]);
//		res.num = getch();
//		printf("%o %o %o %o %o\n", res.ch[0], res.ch[1], res.ch[2], res.ch[3], res.ch[4]);
//		read(1, res.ch, 5);
//		printf("%o %o %o %o %o\n", res.ch[0], res.ch[1], res.ch[2], res.ch[3], res.ch[4]);
	}
	else
	{
		puts(line);
		readline(&line);
		puts("\n\n\n\n");
		puts(line);
	}
	tty_restore();
	return (0);
}
