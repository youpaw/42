/*
* Created by Maxon Gena on 8/28/20.
*/

#include "readline.h"
#include <termcap.h>
#include "cc_char.h"

/*
 * Restore settings of original terminal, which was
 * saved to global variable, and quit from insert mode.
 */

void		tty_restore(void)
{
	tcsetattr(0, TCSAFLUSH, &(g_tty_backup));
	tputs(tgetstr("ei", NULL), 1, &putchar);
}
