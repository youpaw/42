//
// Created by Darth Butterwell on 9/5/20.
//

#include <cc_mem.h>
#include "cc_vec.h"
#include "readline.h"
#include "cc_str.h"
#include "cc_char.h"

static void strcmp_in_input(t_vec *vec_ptr, char *str)
{
	char	letter[5];
	int		len;

	vec_ptr = vec_new(8, sizeof(char[5]), NULL);
	while (*str)
	{
		len = get_utf8_len(*str);
		bzero(letter, 5);
		strncpy(letter, str, len);
		vec_push(vec_ptr, letter);
		str += len;
	}

}

static t_input	fill_input(char *line)
{
	t_input inp;
	char **prev;

	inp.cursor_y_position = 0;
	prev = strsplitcharset(line, "\n");
	while (prev[inp.cursor_y_position])
		inp.cursor_y_position++;
	inp.line = xmalloc(sizeof(t_vec*) * (inp.cursor_y_position + 2));
	inp.cursor_y_position = 0;
	while (prev[inp.cursor_y_position])
	{
		strcmp_in_input(inp.line[inp.cursor_y_position], prev[inp.cursor_y_position]);
		inp.cursor_y_position++;
	}
	return (inp);
}

t_input 	input_init(char *line)
{
	t_input inp;

	if (line)
		fill_input(line);
	else
	{
		inp.line = xmalloc(sizeof(t_vec*) * 2);
		inp.cursor_y_position = 0;
	}
	inp.line[inp.cursor_y_position] = vec_new(8, sizeof(char[5]), NULL);
	inp.line[inp.cursor_y_position + 1] = NULL;
	inp.cursor_x_position = 0;
	inp.len = 0;
	return (inp);
}