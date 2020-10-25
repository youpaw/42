//
// Created by Halfhand Lorrine on 10/25/20.
//

#include "alias_builtins.h"

void		alias_error_print(t_error_code er_code, char *cmd,\
char *arg)
{
	char	*er_arr[3];

	er_arr[0] = NULL;
	er_arr[1] = NULL;
	er_arr[2] = NULL;
	if (er_code == E_NOTFOUND)
	{
		er_arr[0] = cmd;
		er_arr[1] = arg;
		error_print(er_code, (const char **)er_arr);
	}
	else if (er_code == E_INVALOPT)
	{
		er_arr[0] = arg;
		error_print(er_code, (const char **)er_arr);
		puts(cmd);
		puts(": usage: ");
		puts(cmd);
		putendl(" [-a] name [name ...]");
	}
}
