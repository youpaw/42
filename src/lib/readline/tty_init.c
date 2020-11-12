/*
* Created by Maxon Gena on 8/28/20.
*/

#include "readline.h"
#include "unistd.h"

/*
 * Initialize terminal: make termcap init, enter input mode
 * to be able to move left and right in line, check that stdin
 * is terminal, save current terminal settings in global
 * variable and set terminal in noncanonical mode.
 */

int	tty_init(void)
{
	struct termios	tty;

	if (!(isatty(0)))
		return (-1);
	tcgetattr(0, &tty);
	g_tty_backup = tty;
	tty.c_lflag &= ~(ICANON | ECHO | ISIG);
	tty.c_cc[VMIN] = 1;
	tcsetattr(0, TCSAFLUSH, &tty);
	return (0);
}
