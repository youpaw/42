#ifndef TESTS_H
# define TESTS_H


void	assert_int_equals(int e, int a);

void	assert_str_equals(const char *e, const char *a);

void	assert_is_null(void *p);

void	assert_is_not_null(void *p);

void	assert_true(int b);

void	assert_false(int b);


#endif
