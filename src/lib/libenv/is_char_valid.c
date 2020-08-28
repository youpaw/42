//
// Created by Darth Butterwell on 8/23/20.
//
#include "cc_char.h"

int is_char_valid(char c)
{
	return (isalnum(c) || c == '_');
}