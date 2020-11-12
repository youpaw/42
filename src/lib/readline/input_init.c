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

static t_inp	fill_input(char *line)
{
	t_inp inp;
	char **prev;

	inp.curs_y_pos = 0;
	inp.len = 0;
	prev = split_newline(line);
	while (prev[inp.curs_y_pos])
		inp.curs_y_pos++;
	inp.line = xmalloc(sizeof(t_vec*) * (inp.curs_y_pos + 2));
	inp.line_len = xmalloc(sizeof(size_t) * (inp.curs_y_pos + 2));
	inp.curs_y_pos = 0;
	while (prev[inp.curs_y_pos])
	{
		inp.line[inp.curs_y_pos] = vec_new(8, sizeof(char[5]), NULL);
		inp.line_len[inp.curs_y_pos] = strcmp_in_input(&inp.line[inp.curs_y_pos],
													   get_prompt(inp.curs_y_pos));
		inp.line_len[inp.curs_y_pos] += strcmp_in_input(
				&inp.line[inp.curs_y_pos], prev[inp.curs_y_pos]);
		inp.len += inp.line_len[inp.curs_y_pos];
		inp.curs_y_pos++;
	}
	free(prev);
	return (inp);
}

t_inp 	input_init(char *line)
{
	t_inp inp;

	if (*line)
		inp = fill_input(line);
	else
	{
		inp.line = xmalloc(sizeof(t_vec*) * 2);
		inp.line_len = xmalloc(sizeof(int) * 2);
		inp.curs_y_pos = 0;
		inp.len = 0;
	}
	inp.line[inp.curs_y_pos] = vec_new(8, sizeof(char[5]), NULL);
	inp.line[inp.curs_y_pos + 1] = NULL;
	inp.line_len[inp.curs_y_pos] = 0;
	inp.curs_x_pos = 0;
	inp.hist_storage = NULL;
	free(line);
	return (inp);
}