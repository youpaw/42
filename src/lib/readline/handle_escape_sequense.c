//
// Created by Maxon Gena on 9/8/20.
//

#include "readline.h"
#include "cc_str.h"
#include "cc_char.h"

int handle_escape_sequence(t_inp *input)
{
	static const t_key_readline_handler hanlders[N_ESC_KEY_HANDLERS] = {
			{"\103",    &handle_right_arrow},
			{"\104",    &handle_left_arrow},
			{"\63\176", &handle_del},
			{"\101", &handle_up_arrow}, // up
			{"\102", &handle_down_arrow}, // down
			{"\61\73\62\101", &handle_shift_up}, //shift + up
			{"\61\73\62\102", &handle_shift_down}, // shift + down
			{"\61\73\62\103", &handle_shift_right}, //shift + right
			{"\61\73\62\104", &handle_shift_left}, //shift + left
			{"\110", &handle_home_key}, //home
			{"\106", &handle_end_key} //end
	};
	int index;
	char ch[2];
	t_letter key;

	index = 0;
	ch[1] = '\0';
	key.num = getch();
	while (index < N_ESC_KEY_HANDLERS)
	{
		if (!strncmp(hanlders[index].primary_key, key.ch, 4))
		{
			if (hanlders[index].handler)
				return (hanlders[index].handler(input));
		}
		index++;
	}
	index = 1;
	while (index != 4 && key.ch[index])
	{
		ch[0] = key.ch[index];
		handle_symbol_key(input, ch);
		index++;
	}
	return (0);
}