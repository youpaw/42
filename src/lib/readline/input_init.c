//
// Created by Darth Butterwell on 9/5/20.
//

#include <cc_mem.h>
#include "cc_vec.h"
#include "readline.h"
#include "cc_str.h"
#include "cc_char.h"
#include "cc_num.h"
#include <termcap.h>

static int strcmp_in_input(t_vec **vec_ptr, char *str)
{
	char	letter[5];
	int		letter_len;
	int		line_len;
	size_t i;

	i = 0;
	line_len = 0;
	bzero(letter, 5);
	while (str[i])
	{
		letter_len = utf8_sizeof_symbol(str[i]);
		bzero(letter, 5);
		strncpy(letter, &str[i], letter_len);
		vec_push(*vec_ptr, letter);
		i += letter_len;
		line_len++;
	}
	free(str);
	return line_len;
}

static t_input	fill_input(char *line)
{
	t_input inp;
	char **prev;

	inp.cursor_y_position = 0;
	inp.len = 0;
	prev = split_newline(line);
	while (prev[inp.cursor_y_position])
		inp.cursor_y_position++;
	inp.line = xmalloc(sizeof(t_vec*) * (inp.cursor_y_position + 2));
	inp.line_len = xmalloc(sizeof(size_t) * (inp.cursor_y_position + 2));
	inp.cursor_y_position = 0;
	while (prev[inp.cursor_y_position])
	{
		inp.line[inp.cursor_y_position] = vec_new(8, sizeof(char[5]), NULL);
		inp.line_len[inp.cursor_y_position] = strcmp_in_input(&inp.line[inp.cursor_y_position],
														get_prompt(inp.cursor_y_position));
		inp.line_len[inp.cursor_y_position] += strcmp_in_input(
				&inp.line[inp.cursor_y_position], prev[inp.cursor_y_position]);
		inp.len += inp.line_len[inp.cursor_y_position];
		inp.cursor_y_position++;
	}
	free(prev);
	return (inp);
}

t_input 	input_init(char *line)
{
	t_input inp;

	if (*line)
		inp = fill_input(line);
	else
	{
		inp.line = xmalloc(sizeof(t_vec*) * 2);
		inp.line_len = xmalloc(sizeof(int) * 2);
		inp.cursor_y_position = 0;
		inp.len = 0;
	}
	inp.line[inp.cursor_y_position] = vec_new(8, sizeof(char[5]), NULL);
	inp.line[inp.cursor_y_position + 1] = NULL;
	inp.line_len[inp.cursor_y_position] = 0;
	inp.cursor_x_position = 0;
	inp.hist_storage = NULL;
	return (inp);
}