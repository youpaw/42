/*
* Created by Maxon Gena on 8/28/20.
*/

#include "readline.h"

/*
 * Restore settings of original terminal, which was
 * saved to global variable, and quit from insert mode.
 */

void		restore_tty(void)
{
	tcsetattr(0, TCSAFLUSH, &(savetty));
	tputs(tgetstr("ei", NULL), 1, ft_put);
}
