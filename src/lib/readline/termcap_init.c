//   Createdby Maxon Gena on 08/16/20

#include "readline.h"

void	termcap_init(void)
{
	int error;

	error = tgetent(NULL, getenv("TERM"));
	if (error == 0)
	{
		; //TODO "Терминал %s не описан\n" error handle
		exit(0);
	}
	else if (error == 1)
		return ;
	else
	{
		; //TODO "Different error" error handle
		exit(0);
	}
}


