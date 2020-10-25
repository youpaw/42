//
// Created by Darth Butterwell on 9/2/20.
//

#include "readline.h"
#include "exec.h"
#include "cc_str.h"
#include <unistd.h>
#include <time.h>
#include <stdio.h>

void 	print_entry(void)
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
//	char datetime[12][128];

//	puts("42sh started on ");
//	puts(ttyname(STDIN_FILENO));
//	puts(" at ");
	printf("42sh started on tty is %s at %d-%02d-%02d %02d:%02d:%02d\n", ttyname(STDIN_FILENO), tm.tm_year + 1900,
		   tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

int 	main_manager(void)
{
	t_tokens *tokens;
	t_ast	*ast;
	char *str;

	ast = NULL;
	tokens = NULL;
	str = strdup("");
	print_entry();
	while (42)
	{
		//print_process_stats("readline");
		jobs(NULL);
		set_ignore_handlers();
		readline(&str);
		putendl("");
		set_print_main_handlers();
		tokens = validate_str(str);
		if (tokens && !tokens->error)
		{
			if ((ast = parse(tokens)))
				exec(ast);
		}
		if (!tokens || tokens->error != E_INCINP)
		{
			free(str);
			str = strdup("");
		}
		del_ast(&ast);
		destruct_tokens(&tokens);
		do_job_notification();
	}
}
