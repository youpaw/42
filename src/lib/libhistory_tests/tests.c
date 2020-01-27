#include "cc.h"
#include "history.h"
#include "h_dlist.h"
#include <stdio.h>
#include "utils.h"

void		test_new_file()
{
	int	r;
	char *file = "/tmp/42history";
	delete_file(file);
	load_history(file);
	prev_next_fail_on_empty();
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


void		free_should_not_fail_on_empty()
{
	h_free();
	h_free();
}

void		test_get_prev()
{
	h_free();
	h_append("1");
	assert_get_prev("1");
	h_append("2");
	assert_get_prev("2");
	assert_get_prev("1");
	prev_should_fail();
	prev_should_fail();
	h_free();
}

void		test_get_next()
{
	int r;
	char out[2];

	h_free();
	h_append("1");
	next_should_fail();
	h_append("2");
	next_should_fail();
	assert_get_prev("2");
	next_should_fail();
	assert_get_prev("1");
	prev_should_fail();
	assert_get_next("2");
	h_free();
}

void		free_deletes_all()
{
	h_append("1");
	h_free();
	prev_next_fail_on_empty();
}

void		duplicate_is_not_added()
{
	h_free();
	prev_next_fail_on_empty();
	h_append("1");
	h_append("1");
	assert_get_prev("1");
	prev_should_fail();
}

void		test_in_memory()
{
	prev_next_fail_on_empty();
	free_should_not_fail_on_empty();
	free_deletes_all();
	test_get_prev();
	test_get_next();
	duplicate_is_not_added();
}


void		empty_not_fail()
{
	char *file = "/tmp/42history";

	delete_file(file);
	load_history(file);

	h_close();
}

void		one_is_saved()
{
	char *file = "/tmp/42history";

	delete_file(file);
	load_history(file);

	h_append("1");
	h_save_new();
	h_close();
	prev_next_fail_on_empty();
	load_history(file);
	next_should_fail();
	assert_get_prev("1");

	h_close();
}

void		only_new_are_appended_after_load()
{
	char *file = "/tmp/42history";

	delete_file(file);
	load_history(file);

	h_append("1");
	h_save_new();
	h_close();

	load_history(file);
	h_append("2");
	h_save_new();
	assert_get_prev("2");
	assert_get_prev("1");
	prev_should_fail();
	h_close();

	load_history(file);
	assert_get_prev("2");
	assert_get_prev("1");
	prev_should_fail();

	h_close();
}

void		only_new_are_appended_after_save()
{
	char *file = "/tmp/42history";

	delete_file(file);
	load_history(file);

	h_append("1");
	h_save_new();

	h_append("2");
	h_save_new();
	h_close();

	load_history(file);
	assert_get_prev("2");
	assert_get_prev("1");
	prev_should_fail();
	h_close();
}

void		nothing_appended()
{
	char *file = "/tmp/42history";

	delete_file(file);
	load_history(file);

	h_append("1");
	h_save_new();
	h_close();

	load_history(file);
	h_save_new();
	h_close();

	load_history(file);
	assert_get_prev("1");
	prev_should_fail();

	h_close();
}

void		two_are_saved()
{
	char *file = "/tmp/42history";

	delete_file(file);
	load_history(file);

	h_append("1");
	h_append("2");
	h_save_new();
	h_close();
	prev_next_fail_on_empty();
	load_history(file);
	next_should_fail();
	assert_get_prev("2");
	assert_get_prev("1");
	prev_should_fail();
	assert_get_next("2");
	next_should_fail();

	h_close();
}

void		multilines_are_saved()
{
	char *file = "/tmp/42history";

	delete_file(file);
	load_history(file);

	h_append("line1\nline2\nline3");
	h_append("2");
	h_save_new();
	h_close();
	prev_next_fail_on_empty();
	load_history(file);
	next_should_fail();
	assert_get_prev("2");
	assert_get_prev("line1\nline2\nline3");
	prev_should_fail();
	assert_get_next("2");
	next_should_fail();

	h_close();
}

void		test_save_load()
{
	empty_not_fail();
	one_is_saved();
	two_are_saved();
	multilines_are_saved();
	only_new_are_appended_after_load();
	only_new_are_appended_after_save();
	nothing_appended();

	char *file = "/tmp/42history";

	prev_next_fail_on_empty();
	
	load_history(file);
	h_append("2");
	h_save_new();
	h_close();
	prev_next_fail_on_empty();
	load_history(file);
	assert_get_prev("2");
	assert_get_prev("1");
	prev_should_fail();
	h_close();
}


void		test_history()
{
	test_save_load();
	test_in_memory();
	test_h_init();
	test_new_file();

	fdputs("history:\tok\n", STDOUT_FILENO);
}