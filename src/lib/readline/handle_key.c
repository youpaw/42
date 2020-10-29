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
	static const t_key_readline_handler hanlders[N_ORD_KEY_HANDLERS] = {
			{"\6", &handle_right_arrow},
			{"\2", &handle_left_arrow},
			{"\177",&handle_backspace},
			{"\t", &handle_tab},
			{"\20", NULL}, //down
			{"\16", NULL} //up
	};
	int index;

	index = 0;
	while (index < N_ORD_KEY_HANDLERS)
	{
		if (!strcmp(hanlders[index].primary_key, key))
		{
			if (hanlders[index].handler)
				return (hanlders[index].handler(input));
			else
				return (1);
		}
		index++;
	}
	if (!strcmp("\33\133", key))
		return handle_escape_sequence(input);
	return (handle_symbol_key(input, key));
}