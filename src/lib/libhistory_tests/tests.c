#include "cc.h"
#include "history.h"
#include "h_dlist.h"
#include <stdio.h>

void		test_new_file()
{
	int	r;
	char rm_file[] = "rm /tmp/42history";
	char *file = rm_file + 3;
	if (file_exists(file))
	{
		system(rm_file);
		if (file_exists(file))
		{
			printf("could not delete file: '%s'\n", file);
			exit(2);
		}
	}
	r = h_init(file);
	if (r != E_OK)
	{
		printf("h_init(%s) failed\n", file);
		exit(3);
	}
	char out[1];
	*out = 'z';
	r = h_get_prev(out);
	if (r == E_OK)
	{
		printf("h_get_prev should fail on new file\n");
		exit(1);
	}
	if (*out != 0)
	{
		printf("h_get_prev should clean out on new file\n");
		exit(1);
	}

	*out = 'z';
	r = h_get_next(out);
	if (r == E_OK)
	{
		printf("h_get_next should fail on new file\n");
		exit(1);
	}
	if (*out != 0)
	{
		printf("h_get_next should clean out on new file\n");
		exit(1);
	}

	h_close();
}

void		test_h_init()
{
	int r = h_init(NULL);
	if (r == E_OK)
	{
		printf("h_init should fail on NULL path\n");
		exit(1);
	}
	r = h_init(".42history");
	if (r != E_OK)
	{
		printf("h_init should not fail on relative path\n");
		exit(1);
	}
	r = h_init("q");
	if (r == E_OK)
	{
		printf("h_init should fail on reopen\n");
		exit(1);
	}
	h_close();
}

void		prev_next_fail_on_empty()
{
	int	r;
	char	out[1000];

	*out = 1;
	r = h_get_prev(out);
	if (r == E_OK || *out != 0)
	{
		printf("h_get_prev should fail on empty history\n");
		exit(1);
	}
	*out = 1;
	r = h_get_next(out);
	if (r == E_OK || *out != 0)
	{
		printf("h_get_next should fail on empty history\n");
		exit(2);
	}
}

void		free_should_not_fail_on_empty()
{
	h_free();
}

void		test_get_prev()
{
	int r;
	char out[2];

	h_free();
	h_append("1");
	*out = 0;
	r = h_get_prev(out);
	if (r != E_OK || !str_equals("1", out))
	{
		printf("get_prev should not fail after add\n");
		exit(1);
	}
	h_append("2");
	*out = 0;
	r = h_get_prev(out);
	if (r != E_OK || !str_equals("2", out))
	{
		printf("get_prev should not fail after add\n");
		exit(1);
	}
	*out = 0;
	r = h_get_prev(out);
	if (r != E_OK || !str_equals("1", out))
	{
		printf("get_prev should not fail after add\n");
		exit(1);
	}
	*out = 1;
	r = h_get_prev(out);
	if (r != E_FAIL || *out != 0)
	{
		printf("get_prev should fail at the beginning of the list\n");
		exit(1);
	}

	h_free();
}

void		test_get_next()
{
	int r;
	char out[2];

	h_free();
	h_append("1");
	*out = 1;
	r = h_get_next(out);
	if (r != E_FAIL || *out != 0)
	{
		printf("h_get_next should fail after append\n");
		exit(1);
	}
	h_append("2");
	*out = 1;
	r = h_get_next(out);
	if (r != E_FAIL || *out != 0)
	{
		printf("h_get_next should fail after append\n");
		exit(1);
	}
	*out = 0;
	r = h_get_prev(out);
	if (r != E_OK || !str_equals(out, "2"))
	{
		printf("h_get_prev should return last\n");
		exit(1);
	}
	*out = 1;
	r = h_get_next(out);
	if (r != E_FAIL || *out != 0)
	{
		printf("h_get_next should fail after append, get_prev\n");
		exit(1);
	}
	*out = 0;
	r = h_get_prev(out);
	if (r != E_OK || !str_equals(out, "1"))
	{
		printf("h_get_prev should return 1\n");
		exit(1);
	}
	*out = 1;
	r = h_get_prev(out);
	if (r != E_FAIL || *out != 0)
	{
		printf("get_prev should fail at the beginning of the list\n");
		exit(1);
	}
	*out = 0;
	r = h_get_next(out);
	if (r != E_OK || !str_equals(out, "2"))
	{
		printf("h_get_next should rturn 2\n");
		exit(1);
	}

	h_free();
}


void		free_deletes_all()
{
	h_append("1");
	h_free();
	prev_next_fail_on_empty();
}


void		test_in_memory()
{
	prev_next_fail_on_empty();
	free_should_not_fail_on_empty();
	free_deletes_all();
	test_get_prev();
	test_get_next();
}

void		test_history()
{
	test_in_memory();
	test_h_init();
	test_new_file();
	fdputs("history:\tok\n", STDOUT_FILENO);
}