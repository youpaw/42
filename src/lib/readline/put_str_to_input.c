//
// Created by Maxon Gena on 11/8/20.
//

#include "readline.h"
#include "cc_mem.h"
#include "cc_char.h"
#include "cc_str.h"
#include "termcap.h"

void	put_str_to_input(t_inp *inp, char *part)
{
	size_t	i;
	t_let	let;
	int		len;

	i = 0;
	if (!part)
		return ;
	while (part[i])
	{
		bzero(let.ch, 5);
		len = utf8_sizeof_symbol(part[i]);
		strncpy(let.ch, &part[i], len);
		if (len >= 2)
			i += check_for_utf8_comb_character(&part[i], let.ch, len);
		handle_symbol_key(inp, let.ch);
		i += len;
	}
	free(part);
}
