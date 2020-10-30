//
// Created by Halfhand Lorrine on 10/25/20.
//

#include "alias_builtins.h"

void		alias_error_print(t_error_code er_code, const char *cmd,\
							  const char *arg)
{
	char	*er_arr[3];

	er_arr[0] = (char *)cmd;
	er_arr[1] = NULL;
	if (arg != NULL)
		er_arr[1] = (char *)arg;
	er_arr[2] = NULL;
	error_print(er_code, (const char **)er_arr);
	if (er_code == E_INVALOPT)
	{
		puts(cmd);
		puts(": usage: ");
		puts(cmd);
		if (strcmp(cmd, "alias") == 0)
			puts(" [-p]");
		else
			puts(" [-a]");
		putendl(" name [name ...]");
	}
}
