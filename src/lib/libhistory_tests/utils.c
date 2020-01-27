#include "cc.h"
#include "history.h"
#include "h_dlist.h"
#include <stdio.h>

void		get_should_fail(int (*get)(char *))
{
	int	r;
	char	out[1];

	*out = 1;
	r = get(out);
	if (r == E_OK || *out != 0)
	{
		printf("get should fail\n");
		exit(2);
	}
}

void		next_should_fail()
{
	get_should_fail(h_get_next);
}

void		prev_should_fail()
{
	get_should_fail(h_get_prev);
}

void		prev_next_fail_on_empty()
{
	prev_should_fail();
	next_should_fail();
}

void		assert_get(int (*get)(char *), const char *expected)
{
	int r;
	char *actual = strdup(expected);
	*actual = 0;
	r = get(actual);
	if (r != E_OK || !str_equals(expected, actual))
	{
		printf("get* failed: expected: '%s', actual: '%s'\n", expected, actual);
		free(actual);
		exit(1);
	}
	free(actual);
}

void		assert_get_prev(const char *expected)
{
	assert_get(h_get_prev, expected);
}

void		assert_get_next(const char *expected)
{
	assert_get(h_get_next, expected);
}

void		delete_file(const char *file)
{
	char *rm_file = NULL;

	rm_file = nstrjoin(2, "rm ", file);
	if (file_exists(file))
	{
		system(rm_file);
		free(rm_file);
		if (file_exists(file))
		{
			printf("could not delete file: '%s'\n", file);
			exit(2);
		}
	}
}

void		load_history(const char *file)
{
	int	r;

	r = h_init(file);
	if (r != E_OK)
	{
		printf("h_init(%s) failed\n", file);
		exit(3);
	}
}

void		close_file()
{
	int	r;

	r = h_close();
	if (r != E_OK)
	{
		printf("h_close failed\n");
		exit(3);
	}
}

void		free_history()
{
	int	r;

	r = h_free();
	if (r != E_OK)
	{
		printf("h_free failed\n");
		exit(3);
	}
}
