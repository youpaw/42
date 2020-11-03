//
// Created by youpaw on 10/6/20.
//

#include "exec.h"
#include <unistd.h>
#include <fcntl.h>
#include <cc_str.h> // delete ???
#include <cc_num.h> // delete ??
#include <cc_char.h>

int open_error()
{
	fdputendl("42sh: open error", STDERR_FILENO);
	return (1);
}

int is_standard_io(int fd)
{
	return (fd >=0 && fd <= 2);
}

int bad_descriptor(int bad_fd)
{
	fdputs("42sh: ", STDERR_FILENO);
	fdputnbr(bad_fd, STDERR_FILENO);
	fdputendl(": Bad descriptor", STDERR_FILENO);
	return (-1);
}

int pipe_error()
{
	fdputendl("42sh: pipe error", STDERR_FILENO);
	return (1);
}

int ambiguous_redirect(char *word)
{
	fdputs("42sh: ", STDERR_FILENO);
	fdputs(word, STDERR_FILENO);
	fdputendl(": ambiguous redirect", STDERR_FILENO);
	return (1);
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

int 	left_side(t_ast *leafs, int default_value)
{
	int left;

	left = default_value;
	if (leafs->token)
	{
		if (leafs->token->type == l_io_number)
		{
			if (leafs->token->raw)
				left = atoi(leafs->token->raw);
		}
	}
	return (left);
}

int 	right_side(t_ast *leafs, int open_options, int is_maybe_minus)
{
	int right_side;

	right_side = -1;
	if (leafs->left->left->token)
	{
		if (leafs->left->left->token->raw)
		{
			if (is_valid_number(leafs->left->left->token->raw))
			{
				right_side = atoi(leafs->left->left->token->raw);
				if (right_side != STDIN_FILENO && right_side != STDOUT_FILENO && right_side != STDERR_FILENO)
					return bad_descriptor(right_side);
			}
			else if (is_maybe_minus)
			{
				if (strcmp(leafs->left->left->token->raw, "-") == 0)
					return (-2);
			}
			right_side = open(leafs->left->left->token->raw, open_options, 0644);
		}
	}
	return (right_side);
}
int 	l_great_and_redirect(t_ast *leafs, t_process *process)
{
	int out;
	int from;
	int to;

	to = -1;
	from = -1;
	out = -1;
	from = left_side(leafs, 1);
	to = right_side(leafs, O_RDWR | O_CREAT | O_TRUNC, 1);
	if (to == -1)
		return (1);
	if (from == -1)
	{
		putendl("SOME TYPE OF SHIT IS GOING ON in l_great_redirect function!!\n\n\n!!!!");
		exit(1);
	}
	if (to == -2)
	{
		putendl("WHEN MINUS IS RIGHT SIDE IT DOES NOT WORK AT ALL!!!\n\n\n");
		exit(1);
	}
	if (to == from)
		return (0); // is it really 0?
	if (from == 1)
	{
		if (!is_standard_io(process->stdout))
			close(process->stdout);
		process->stdout = to < 3 ? dup(to) : to;
		if (!is_standard_io(process->stderr))
			close(process->stderr);
		process->stderr = to < 3 ? dup(to) : to;
	}
	else if (from != 1)
	{
		if (to > 2)
		{
			close(to);
			return bad_descriptor(to);
		}
		if (STDERR_FILENO == from)
		{
			if (STDERR_FILENO != process->stderr)
				close(process->stderr);
			if (STDIN_FILENO == to)
				process->stderr = dup(to);
			else if (STDOUT_FILENO == to)

		}

	}
	if (to_fd == -2)
	{
		putendl("DOES NOT WORK AT ALL\n\n\n");
		exit(1);
	}
	if (leafs->left->left->token)
	{
		if (leafs->left->left->token->type == l_word)
		{
			// right side of >& (number or word always)
			if (leafs->left->left->token->raw)
			{
				if (is_valid_number(leafs->left->left->token->raw))
				{
					to_fd = atoi(leafs->left->left->token->raw);
					if (to_fd != STDIN_FILENO && to_fd != STDOUT_FILENO && to_fd != STDERR_FILENO)
						return bad_descriptor(to_fd);
					if (from == 1)
					{
						if (to_fd != from)
						{
							if (process->stdout != STDOUT_FILENO && process->stdout != to_fd)
								close(process->stdout);
							process->stdout = dup(to_fd);
							if (process->stderr != STDERR_FILENO && process->stderr != to_fd)
								close(process->stderr);
							process->stderr = dup(to_fd);
						}
					}
					else if (from != 1)
					{
						if (to_fd != from)
						{
							if (STDERR_FILENO == from)
							{
								if (process->stderr != STDERR_FILENO)
									close(process->stderr);
								if (to_fd == STDIN_FILENO)
									process->stderr = dup(process->stdin);
								else if (to_fd == STDOUT_FILENO)
								{
									//printf("\nprocess->stdout=%d\nprocess->stderr=%d\n", process->stdout, process->stderr);
									process->stderr = dup(process->stdout);
									//printf("\nprocess->stdout=%d\nprocess->stderr=%d\n", process->stdout, process->stderr);
								}
							}
							if (process->stdin == from)
							{
								if (process->stdin != STDIN_FILENO)
									close(process->stdin);
								if (to_fd == STDERR_FILENO)
									process->stdin = dup(process->stderr);
								else if (to_fd == STDOUT_FILENO)
									process->stdout = dup(process->stderr);
							}
						}
					}
// if left => NULL then right => word or number (0, 1, 2) if number is not in (0, 1, 2) then "42sh: %number: Bad file descriptor";
// if left => number then right => (number (0, 1, 2) if number is not in (0, 1, 2) then "42sh: %number: Bad file descriptor") else if not number then "42sh: %word: ambigious redirect";
				}
				else
				{
					if (strcmp(leafs->left->left->token->raw, "-") == 0)
					{
						putendl("DOESNT WORK AT ALL"); //remove this
						//if (from == STDIN_FILENO)
						//	close(STDIN_FILENO);
						//else if (from == STDOUT_FILENO)
						//	close(STDOUT_FILENO);
						//else if (from == STDERR_FILENO)
						//	close(STDERR_FILENO);
						exit(1); // remove this
					}
					else if (from == 1)
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
					else if (from != 1)
						return ambiguous_redirect(leafs->left->left->token->raw);
				}
			}
		}
	}
	return (0);
}


int 	l_less_and_redirect(t_ast *leafs, t_process *process)
{
	int from;
	int to;

	from = -1;
	to = -1;
	if (leafs->token)
	{
		if (leafs->token->type == l_io_number)
			to = atoi(leafs->token->raw);
	}
	else
		to = 0;
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

int 	l_great_redirect(t_ast *leafs, t_process *process, int is_double_great)
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
				return open_error();
			init_process_ioerr(process, from, out);
		}
	}
	return (0);
}
int		l_less_redirect(t_ast *leafs, t_process *process) {
    int in;

    in = -1;
    if (leafs->left->left->token) {
        if (leafs->left->left->token->type == l_word) {
            in = open(leafs->left->left->token->raw, O_RDONLY);
            if (-1 == in)
                return open_error();
            if (process->stdin != STDOUT_FILENO && process->stdin != STDIN_FILENO && process->stdin != STDERR_FILENO)
                close(process->stdin);
            process->stdin = in;
        }
    }
    return (0);
}


int l_heredoc_redirect(t_ast *leafs, t_process *process)
{
	int pfd[2];

	if (pipe(pfd) < 0)
		return pipe_error();
	close(pfd[1]);
	process->stdin = pfd[0];
	fdputendl(leafs->left->left->token->raw, process->stdin);
	return (0);
}

int 	prepare_redirect(t_ast *ast, t_process *process)
{
	size_t i;
	t_ast **redirects;
	int err;

	err = 0;
	i = 0;
	if ((redirects = get_redirect_nodes(ast)) == NULL)
		return (0);
	while(redirects[i])
	{
		if (redirects[i]->left->token)
		{
			if (redirects[i]->left->token->type == l_great)
				err = l_great_redirect(redirects[i], process, 0);
			else if (redirects[i]->left->token->type == l_less)
				err = l_less_redirect(redirects[i], process);
			else if (redirects[i]->left->token->type == l_double_great)
				err = l_great_redirect(redirects[i], process, 1);
			else if (redirects[i]->left->token->type == l_great_and)
			    err = l_great_and_redirect(redirects[i], process);
			else if (redirects[i]->left->token->type == l_heredoc)
				err = l_heredoc_redirect(redirects[i], process);
			if (err == 1)
				return (1);
		}
		i++;
	}
	return (0);
}