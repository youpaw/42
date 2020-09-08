//
// Created by Darth Butterwell on 9/6/20.
//

#include "main.h"
#include "readline.h"
#include "history.h"
#include "cc_char.h"
#include <unistd.h>
#include <stdio.h>

int main(int ac, const char *av[], const char *env[])
{
	t_letter res;
	int len;
	char *line = "it's not original text zlkdrghlkrdhg lzdrhglzhdrgio zodirgolzhirglo lzilrdhgoizhrdgoi\nBut I think about it for a few secondsliu`sehlfiuh`esif`sieufhli`esuhfil`suehfihusef\nso its my original textl`ehsfl`efhsilefsiluh`esif `uisehfil`uhesf  `uilsehfil`uhesf lu`iehsfliu`ehsfiu\n";
	int error;

	tty_init();
	hist_init("/Users/azomega");
	signal_init();
	if (ac == 2)
	{

		res.num = getch();
		printf("%o %o \n", res.ch[0], res.ch[1]);
		res.num = getch();
		printf("%o %o %o %o %o\n", res.ch[0], res.ch[1], res.ch[2], res.ch[3], res.ch[4]);
		read(1, res.ch, 5);
		printf("%o %o %o %o %o\n", res.ch[0], res.ch[1], res.ch[2], res.ch[3], res.ch[4]);
	}
	else
	{
		puts(line);
		readline(&line);
		puts("\n");
		puts(line);
	}
	tty_restore();
	return (0);
}
