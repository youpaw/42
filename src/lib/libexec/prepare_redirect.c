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
	return (-1);
}

int is_standard_io(int fd)
{
	return (fd == STDIN_FILENO || fd == STDERR_FILENO || fd == STDOUT_FILENO);
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

int 	right_side(t_ast *leafs, int open_options, int can_be_number, int is_maybe_minus)
{
	int right_side;

	right_side = -1;
	if (leafs->left->left->token)
	{
		if (leafs->left->left->token->raw)
		{
			if (can_be_number && (leafs->left->left->token->raw))
			{
				right_side = atoi(leafs->left->left->token->raw);
				if (!is_standard_io(right_side))
					return bad_descriptor(right_side);
				return (right_side);
			}
			else if (is_maybe_minus)
			{
				if (strcmp(leafs->left->left->token->raw, "-") == 0)
				{
					if ((right_side = open("/dev/null", open_options, 0644)) == -1)
						return (open_error());
					return (right_side);
				}
			}
			if ((right_side = open(leafs->left->left->token->raw, open_options, 0644)) == -1)
				return (open_error());
		}
	}
	return (right_side);
}

int 	is_minus(t_ast *leafs)
{
	return (leafs->left->left->token->raw && (strcmp(leafs->left->left->token->raw, "-") == 0));
}

int 	l_great_and_redirect(t_ast *leafs, t_process *process)
{
	int from;
	int to;

	from = left_side(leafs, 1);
	to = right_side(leafs, O_RDWR | O_CREAT | O_TRUNC,0, 1);
	if (to == -1)
		return (1);
	if (to == from)
		return (0); // is it really 0?
	if (from == 1)
	{
		if (!is_standard_io(process->stdout))
			close(process->stdout);
		process->stdout = is_standard_io(to) ? dup(to) : to;
		if (!is_standard_io(process->stderr))
			close(process->stderr);
		process->stderr = dup(to);
	}
	else
	{
		if (!is_standard_io(to) && !is_minus(leafs))
		{
			close(to);
			return (bad_descriptor(to));
		}
		if (STDERR_FILENO == from)
		{
			if (!is_standard_io(process->stderr))
				close(process->stderr);
			process->stderr = is_standard_io(to) ? dup(to) : to;
		}
		else if (STDIN_FILENO == from)
		{
			if (!is_standard_io(process->stdin))
				close(process->stdin);
			process->stdin = is_standard_io(to) ? dup(to) : to;
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
	return (0);
}

void 	init_process_ioerr(t_process *process, int from, int to)
{
	if (STDIN_FILENO == from)
	{
		if (!is_standard_io(process->stdin))
			close(process->stdin);
		process->stdin = to;
	}
	else if (STDERR_FILENO == from)
	{
		if (!is_standard_io(process->stderr))
			close(process->stderr);
		process->stderr = to;
	}
	else if (STDOUT_FILENO == from)
	{
		if (!is_standard_io(process->stdout))
			close(process->stdout);
		process->stdout = to;
	}
}

int 	l_great_redirect(t_ast *leafs, t_process *process, int is_double_great)
{
	int options;
	int from;
	int to;

	options = O_RDWR | O_CREAT | (is_double_great ? O_APPEND : O_TRUNC);
	from = left_side(leafs, 1);
	to = right_side(leafs, options, 0, 0);
	init_process_ioerr(process, from, to);
	return (0);
}

int 	file_not_found(char *filename)
{
	fdputs("42sh: ", STDERR_FILENO);
	fdputs(filename, STDERR_FILENO);
	fdputendl(": no such file or directory", STDERR_FILENO);
	return (1);
}
int		l_less_redirect(t_ast *leafs, t_process *process)
{
    int in;
	int to;

	to = left_side(leafs, 0);
    in = -1;
    if (leafs->left->left->token)
    {
        if (leafs->left->left->token->type == l_word)
        {
        	if (!access(leafs->left->left->token->raw, R_OK))
			{
				in = open(leafs->left->left->token->raw, O_RDONLY);
				if (-1 == in)
					return open_error();
				init_process_ioerr(process, to, in);
			}
			else
				return (file_not_found(leafs->left->left->token->raw));
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
			{
				printf("pizdaaaaa\n\n\n\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}