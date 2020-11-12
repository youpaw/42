//
// Created by Darth Butterwell on 9/5/20.
//

#include "readline.h"
#include "cc_str.h"

//static int	(*get_handler(char *key))(t_inp*)
//{
//	static const t_key_readline_handler hanlders[N_ESC_KEY_HANDLERS] = {
//			{"\6", &handle_right_arrow},
//			{"\2", &handle_left_arrow},
//			{"\177",&handle_backspace},
//			{"\t", &handle_tab},
//			{"\20", &handle_down_arrow}, //down
//			{"\16", &handle_up_arrow}, //up
//			{"\3", &handle_eox} //ctrl+C
//	};
//	int index;
//
//	index = 0;
//}

int			handle_key(char *key, t_inp *input)
{
	static const t_key_readline_handler hanlders[N_ORD_KEY_HANDLERS] = {
			{"\6", &handle_right_arrow},
			{"\2", &handle_left_arrow},
			{"\177",&handle_backspace},
			{"\t", &handle_tab},
			{"\20", &handle_down_arrow},
			{"\16", &handle_up_arrow},
			{"\3", &handle_eox}
	};
	int index;

	index = 0;
	while (index < N_ORD_KEY_HANDLERS)
	{
		if (!strcmp(hanlders[index].primary_key, key))
		{
			if (hanlders[index].handler)
				return (hanlders[index].handler(input));
		}
		index++;
	}
	if (!strcmp("\33\133", key))
		return handle_escape_sequence(input);
	return (handle_symbol_key(input, key));
}