#ifndef UTILH_H
#define UTILH_H

void		get_should_fail(int (*get)(char *));
void		next_should_fail();
void		prev_should_fail();
void		prev_next_fail_on_empty();
void		assert_get(int (*get)(char *), const char *expected);
void		assert_get_prev(const char *expected);
void		assert_get_next(const char *expected);
void		delete_file(const char *file);
void		load_history(const char *file);
#endif 
