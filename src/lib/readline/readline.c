//
// Created by Darth Butterwell on 8/16/20.
//

#include "readline.h"
#include <string.h>
#include <stdio.h>


int		get_key_func(char key[4])
{
	if (!strcmp(key, "\33"))
		return (0); //TODO escape character
	else if (!strcmp(key, "\33\133\101") || !(strcmp(key, "\20")))
		return (0); //TODO arrow up
	else if (!strcmp(key, "\33\133\102") || !(strcmp(key, "\16")))
		return (0); //TODO arrow down
	else if (!strcmp(key, "\33\133\103") || !(strcmp(key, "\6")))
		return (0); //TODO arrow right)
	else if (!strcmp(key, "\33\133\104") || !(strcmp(key, "\2")))
		return (0); //TODO arrow left
	else if (!strcmp(key, "\177"))
		return (0); //TODO backspase. del previous symbol;
	else if (key[0] == 27 && key[1] == 91 && key[2] == 51 && key[3] == 126)
		return (0); //TODO del. delete
	else if (!strcmp(key, "\t"))
		return (0); //TODO tabulation. autocomplete
	else if (!strcmp(key, "\n"))
		return (1); //enter return notnull
	else
	{
		printf("%o ", key[0]);
		printf("%o ", key[1]);
		printf("%o ", key[2]);
		printf("%o\n", key[3]);
		return 0;
	}
}
int		readline(char **line)
{
	char key[4];

	while (42)
	{
		bzero(key, 4);
		read(STDIN_FILENO, key, 4);
		if (get_key_func(key))
		{
			return 0;
		}
	}
}

