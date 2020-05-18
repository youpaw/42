//
// Created by youpaw on 15.05.2020.
//

#include <stdlib.h>
#include "lex_validate.h"
#include "char/cc_char.h"
#include "string/cc_str.h"

static size_t get_size(char *raw)
{
	size_t size;

	if (isspace(*raw) || !*raw)
		return (0);
	if (*raw == '!')
		return (1);
	size = 0;
	if (isdigit(*raw) || (*raw == '-' && isdigit(*(raw + 1))))
	{
		if (*raw == '-')
			size++;
		while (raw[size] && isdigit(raw[size]))
			size++;
	}
	else
		while (raw[size] && !isspace(raw[size]))
			size++;
	return (size);
}

static int test_expand(char **raw)
{
	char *ptr;

	ptr = *raw;
	if (*ptr == '!')
		*raw = strdup("previous");
	else if (isdigit(*ptr) || (*ptr == '-' && isdigit(*(ptr + 1))))
		*raw = strdup("number");
	else
		*raw = strdup("word");
	free(ptr);
	return (0);
}

int 	v_handle_bang(t_validate *validate)
{
	char *raw;
	size_t size;
	char *arg;
	char *res;

	raw = validate->raw + validate->index;
	if (!(size = get_size(raw + 1)))
		return (E_OK);
	arg = strsub(raw, 1, size);
	if (test_expand(&arg))
		return (E_UNDEFINED_TOKEN);
	*raw = '\0';
	res = nstrjoin(3, validate->raw, arg, raw + size + 1);
	free(arg);
	free(validate->raw);
	validate->raw = res;
	validate->print_cmd = 1;
	validate->index--;
	return (E_OK);
}