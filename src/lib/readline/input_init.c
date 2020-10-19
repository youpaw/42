//
// Created by Darth Butterwell on 9/5/20.
//

#include <cc_mem.h>
#include "cc_vec.h"
#include "readline.h"
#include "cc_str.h"
#include "cc_char.h"

static int strcmp_in_input(t_vec **vec_ptr, char *str)
{
	char	letter[5];
	int		letter_len;
	int		line_len;

	line_len = 0;
	*vec_ptr = vec_new(8, sizeof(char[5]), NULL);
	while (*str)
	{
		letter_len = get_utf8_len(*str);
		bzero(letter, 5);
		strncpy(letter, str, letter_len);
		vec_push(*vec_ptr, letter);
		str += letter_len;
		line_len++;
	}
//	letter[0] = '\n';
//	letter[1] = '\0';
//	vec_push(*vec_ptr, letter);
//	line_len++;
	return line_len;
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
	inp.line_len = xmalloc(sizeof(int) * (inp.cursor_y_position + 2));
	inp.cursor_y_position = 0;
	while (prev[inp.cursor_y_position])
	{
		inp.line_len[inp.cursor_y_position] = strcmp_in_input(
				&inp.line[inp.cursor_y_position], prev[inp.cursor_y_position]);
		inp.cursor_y_position++;
	}
	return (inp);
}

t_input 	input_init(char *line)
{
	t_input inp;

	strcpy(g_prompt, PROMPT_TEXT);
	if (*line)
		inp = fill_input(line);
	else
	{
		inp.line = xmalloc(sizeof(t_vec*) * 2);
		inp.line_len = xmalloc(sizeof(int) * 2);
		inp.cursor_y_position = 0;
	}
	inp.line[inp.cursor_y_position] = vec_new(8, sizeof(char[5]), NULL);
	inp.line[inp.cursor_y_position + 1] = NULL;
	inp.line_len[inp.cursor_y_position] = 0;
	inp.cursor_x_position = 0;
	inp.len = 0;
	return (inp);
}