/*
* Created by Maxon Gena on 8/28/20.
*/

#include "readline.h"

void		tty_restore(void)
{
	tcsetattr(0, TCSAFLUSH, &(g_tty_backup));
}
