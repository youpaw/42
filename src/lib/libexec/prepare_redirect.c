//
// Created by youpaw on 10/6/20.
//

#include "exec.h"
#include <unistd.h>
#include <fcntl.h>
#include <cc_str.h> // delete ???
#include <cc_num.h> // delete ??
#include <cc_char.h>

void open_error()
{
	write(STDERR_FILENO, "open error while redirecting", strlen("open error while redirecting")); // delete this
}

void bad_descriptor()
{
	return ;
}

static int is_valid_number(const char *str)
{
	if (!str || !*str)
		return (0);
	while (isdigit(*str))
		str++;
	if (!*str)
		return (1);
	return (0);
}

void 	l_great_and_redirect(t_ast *leafs, t_process *process)
{
	int out;
	int from;
	int to_fd;

	to_fd = -1;
	from = -1;
	out = -1;
	if (leafs->token)
	{
		if (leafs->token->type == l_io_number)
			from = atoi(leafs->token->raw);
	}
	else
		from = 1;
	if (leafs->left->left->token)
	{
		if (leafs->left->left->token->type == l_word)
		{
			if (leafs->left->left->token->raw)
			{
				if (is_valid_number(leafs->left->left->token->raw))
				{
					to_fd = atoi(leafs->left->left->token->raw);
					if (to_fd != 0 && to_fd != 1 && to_fd != 2)
					{
						bad_descriptor();
						return ;
					}

				}
				else
				{
					if (from == 1)
					{
						out = open(leafs->left->left->token->raw, O_RDWR | O_CREAT | O_TRUNC, 0644);
						if (-1 == out)
							open_error();
						if (process->stdout != STDOUT_FILENO && process->stdout != STDIN_FILENO && process->stdout != STDERR_FILENO)
							close(process->stdout);
						if (process->stderr != STDOUT_FILENO && process->stderr != STDIN_FILENO && process->stderr != STDERR_FILENO)
							close(process->stderr);
						process->stdout = out;
						process->stderr = dup(out);
					}
				}

			}
		}
	}
}



void 	init_process_ioerr(t_process *process, int from, int to)
{
	if (STDIN_FILENO == from)
	{
		if (process->stdin != STDIN_FILENO && process->stdin != STDOUT_FILENO && process->stdin != STDERR_FILENO)
			close(process->stdin);
		process->stdin = to;
	}
	else if (STDERR_FILENO == from)
	{
		if (process->stderr != STDIN_FILENO && process->stderr != STDOUT_FILENO && process->stderr != STDERR_FILENO)
			close(process->stderr);
		process->stderr = to;
	}
	else if (STDOUT_FILENO == from)
	{
		if (process->stdout != STDIN_FILENO && process->stdout != STDOUT_FILENO && process->stdout != STDERR_FILENO)
			close(process->stdout);
		process->stdout = to;
	}
}

void 	l_great_redirect(t_ast *leafs, t_process *process, int is_double_great)
{
	int out;
	int options;
	int from;

	from = -1;
	options = O_RDWR | O_CREAT | (is_double_great ? O_APPEND : O_TRUNC);
	out = -1;
	if (leafs->token)
	{
		if (leafs->token->type == l_io_number)
			from = atoi(leafs->token->raw);
	}
	else
		from = 1;
	if (leafs->left->left->token)
	{
		if (leafs->left->left->token->type == l_word)
		{
			out = open(leafs->left->left->token->raw, options, 0644);
			if (-1 == out)
				open_error();
			init_process_ioerr(process, from, out);
		}
	}
}
void 	l_less_redirect(t_ast *leafs, t_process *process) {
    int in;

    in = -1;
    if (leafs->left->left->token) {
        if (leafs->left->left->token->type == l_word) {
            in = open(leafs->left->left->token->raw, O_RDONLY);
            if (-1 == in)
                open_error();
            if (process->stdin != STDOUT_FILENO && process->stdin != STDIN_FILENO && process->stdin != STDERR_FILENO)
                close(process->stdin);
            process->stdin = in;
        }
    }
}

int 	prepare_redirect(t_ast *ast, t_process *process)
{
	size_t i;
	t_ast **redirects;

	i = 0;
	if ((redirects = get_redirect_nodes(ast)) == NULL)
		return (0);
	while(redirects[i])
	{
		if (redirects[i]->left->token)
		{
			if (redirects[i]->left->token->type == l_great)
				l_great_redirect(redirects[i], process, 0);
			else if (redirects[i]->left->token->type == l_less)
				l_less_redirect(redirects[i], process);
			else if (redirects[i]->left->token->type == l_double_great)
				l_great_redirect(redirects[i], process, 1);
			else if (redirects[i]->left->token->type == l_great_and)
			    l_great_and_redirect(redirects[i], process);
		}
		i++;
	}
	return (0);
}