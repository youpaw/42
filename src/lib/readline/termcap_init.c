//   Createdby Maxon Gena on 08/16/20

#include "readline.h"
#include <termcap.h>

void	termcap_init(void)
{
	int error;

	error = tgetent(NULL, getenv("TERM"));
	if (error == 0)
	{
		exit(0);
	}
	else if (error == 1)
		return ;
	else
	{
		exit(0);
	}
}
