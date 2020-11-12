//
// Created by Maxon Gena on 11/7/20.
//

#include "readline.h"
#include "cc_str.h"

int	check_for_utf8_comb_character(char *prev, char *letter, size_t len)
{
	if (!strncmp(&prev[len], "\xcc\x86", 2))
	{
		if (!strncmp(prev, "\xd0\x98", 2))
			letter[1] = '\x99';
		else if (!strncmp(prev, "\xd0\xb8", 2))
			letter[1] = '\xb9';
		return (2);
	}
	if (!strncmp(&prev[len], "\xcc\x88", 2))
	{
		if (!strncmp(prev, "\xd0\xb5", 2))
			strcpy(letter, "\xd1\x91");
		else if (!strncmp(prev, "\xd0\x95", 2))
			strcpy(letter, "\xd0\x81");
		return (2);
	}
	return (0);
}
