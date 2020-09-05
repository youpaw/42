//
// Created by Darth Butterwell on 9/5/20.
//

#include "readline.h"
#include "cc_str.h"

//static int	get_key_func(char key[4], t_input *input)
//{
//	if (!strcmp(key, "\33"))
//		return (0); //TODO escape character
//	else if (!strcmp(key, "\33\133\101") || !(strcmp(key, "\20")))
//		return (0); //TODO arrow up
//	else if (!strcmp(key, "\33\133\102") || !(strcmp(key, "\16")))
//		return (0); //TODO arrow down
//	else if (!strcmp(key, "\33\133\103") || !(strcmp(key, "\6")))
//		return right_arrow_pressed(input);
//	else if (!strcmp(key, "\33\133\104") || !(strcmp(key, "\2")))
//		return left_arrow_pressed(input);
//	else if (!strncmp(key, "\33\133\63\176", 4))
//		return del_pressed(input);
//	else if (!strncmp(key, "\33\133", 2))
//		return 0;
//	else if (!strcmp(key, "\177"))
//		return backspace_pressed(input);
//	else if (!strcmp(key, "\t"))
//		return autocomplete(input);
//	else if (!strcmp(key, "\n"))
//		return (1); //enter return nonzero value
//		// TODO think about error values
//	else
//	{
//		symbol_key_pressed(input, key);
//		return (0);
//	}
//}

int			handle_key(char *key, t_input *input)
{
	static const t_key_handler hanlders[N_KEY_HANDLERS] = {
			{"\33\133\103", "\6", &handle_right_arrow},
			{"\33\133\104", "\2", &handle_left_arrow},
			{"\33\133\63\176", "", &handle_del},
			{"\177", "", &handle_backspace},
			{"\t", "", &handle_tab},
			{"\n", "", NULL},
			{"\33\133\101", "\20", NULL},
			{"\33\133\102", "\16", NULL}
	};
	int index;

	index = 0;
	while (index < N_KEY_HANDLERS)
	{
		if (!strcmp(hanlders[index].primary_key, key) || \
		!strcmp(hanlders[index].secondary_key, key))
		{
			if (hanlders[index].handler)
				return (hanlders[index].handler(input));
			else
				return (1);
		}
		index++;
	}
	if (!strncmp("\33\133", key, 2))
		return (0);
	return (handle_symbol_key(input, key));
}