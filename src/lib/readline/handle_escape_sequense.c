//
// Created by Maxon Gena on 9/8/20.
//

#include "readline.h"
#include "cc_str.h"
#include "cc_char.h"

static int	(*get_handler(char *key))(t_inp*)
{
	static const t_key_readline_handler	hanlders[N_ESC_KEY_HANDLERS] = {
			{"\103", &handle_right_arrow},
			{"\104", &handle_left_arrow},
			{"\63\176", &handle_del},
			{"\101", &handle_up_arrow},
			{"\102", &handle_down_arrow},
			{"\61\73\62\101", &handle_shift_up},
			{"\61\73\62\102", &handle_shift_down},
			{"\61\73\62\103", &handle_shift_right},
			{"\61\73\62\104", &handle_shift_left},
			{"\110", &handle_home_key},
			{"\106", &handle_end_key}
	};
	int									index;

	index = 0;
	while (index < N_ESC_KEY_HANDLERS)
	{
		if (!strncmp(hanlders[index].primary_key, key, 4))
			if (hanlders[index].handler)
				return (hanlders[index].handler);
		index++;
	}
	return (NULL);
}

int			handle_escape_sequence(t_inp *input)
{
	int		index;
	char	ch[2];
	t_let	key;
	int		(*handler)(t_inp *);

	ch[1] = '\0';
	key.num = sh_getch();
	if ((handler = get_handler(key.ch)))
		return (handler(input));
	index = 1;
	while (index != 4 && key.ch[index])
	{
		ch[0] = key.ch[index];
		handle_symbol_key(input, ch);
		index++;
	}
	return (0);
}
