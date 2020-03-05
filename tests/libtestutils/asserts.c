#include <stdio.h>
#include <stdlib.h>
#include "cc.h"


void	assert_int_equals(int e, int a)
{
	if (e != a)
	{
		printf("assert failed: expected: %d, actual: %d\n", e, a);
		exit(1);
	}
}

void	assert_str_equals(const char *e, const char *a)
{
	if (!str_equals(e, a) && e != NULL && a != NULL)
	{
		printf("assert failed:\nexpected: '%s', actual: '%s'\n", e, a);
		exit(1);
	}
}

void	assert_is_null(void *p)
{
	if (p != NULL)
	{
		printf("assert failed: expected: NULL, actual: %p\n", p);
		exit(1);
	}
}

void	assert_is_not_null(void *p)
{
	if (p == NULL)
	{
		printf("assert failed: expected: NOT NULL, actual: %p\n", p);
		exit(1);
	}
}

void	assert_true(int b)
{
	if (!b)
	{
		printf("assert failed: expected: TRUE, actual: FALSE\n");
		exit(1);
	}
}

void	assert_false(int b)
{
	if (b)
	{
		printf("assert failed: expected: FALSE, actual: TRUE\n");
		exit(1);
	}
}