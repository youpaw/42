//
// Created by Darth Butterwell on 9/2/20.
//

#include "readline.h"
#include "exec.h"
#include "history.h"
#include "cc_str.h"

static t_tokens	*validate_input(char **str)
{
	t_tokens *tokens;

	if (**str == 4)
	{
		free(*str);
		*str = strdup("exit\n");
	}
	tokens = validate_str(*str);
	if (!tokens || (tokens->error != E_INCINP && tokens->error != E_EOF))
	{
		free(*str);
		*str = strdup("");
	}
	if (tokens && tokens->error != E_INCINP && tokens->error != E_NOINP &&
		tokens->error != E_EOF)
		hist_push(tokens->raw);
	return (tokens);
}

int				main_manager(void)
{
	t_tokens	*tokens;
	t_ast		*ast;
	char		*str;

	ast = NULL;
	tokens = NULL;
	str = strdup("");
	while (42)
	{
		sh_readline(&str);
		tokens = validate_input(&str);
		if (tokens && !tokens->error)
			if ((ast = sh_parse(tokens)))
				sh_exec(ast);
		del_ast(&ast);
		destruct_tokens(&tokens);
		hist_reset_cur_ind();
		do_job_notification();
	}
}
