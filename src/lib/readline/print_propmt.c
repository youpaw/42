//
// Created by Maxon Gena on 10/19/20.
//

#include <zconf.h>
#include <stdio.h>
#include "readline.h"
#include "cc_str.h"
#include <string.h>

void 	print_prompt(t_input *inp)
{
	int i;
	char sym[4];

	i = 0;
	bzero(sym, 4);
	while (g_prompt[i])
	{
		sym[0] = g_prompt[i++];
		handle_key(sym, inp);
		fflush(STDIN_FILENO);
	}
	inp->indent = PROMPT_LEN;
}