/*
* Created by Maxon Gena on 8/28/20.
*/

#include "readline.h"

/*
 * Initialize terminal: make termcap init, enter input mode
 * to be able to move left and right in line, check that stdin
 * is terminal, save current terminal settings in global
 * variable and set terminal in noncanonical mode.
 */

void		tty_init(void)
{
	struct termios	tty;

	termcap_init();
	tputs(tgetstr("im", NULL), 1, ft_put);
	if (!(isatty(0)))
	{
		//TODO "stdin not terminal" error handle
		exit(1);
	}
	tcgetattr(0, &tty);
	savetty = tty;
	tty.c_lflag &= ~(ICANON | ECHO);
	tty.c_cc[VMIN] = 1;
	tcsetattr(0, TCSAFLUSH, &tty);
}
