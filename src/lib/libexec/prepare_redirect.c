//
// Created by youpaw on 10/6/20.
//

#include "exec.h"
#include <unistd.h>
#include <fcntl.h>
#include <cc_str.h> // delete ???
#include <cc_num.h> // delete ??


void open_error()
{
	write(STDERR_FILENO, "open error while redirecting", strlen("open error while redirecting")); // delete this
}

void 	l_great_and_redirect(t_ast *leafs, t_process *process, int from)
{
	int out;

	out = -1;
	if (leafs->left->left->token)
	{
		if (leafs->left->left->token->type == l_word)
		{
			out = open(leafs->left->left->token->raw, O_RDWR | O_CREAT | O_TRUNC, 0644);
			if (-1 == out)
				open_error();
			if (process->stdout != STDOUT_FILENO && process->stdout != STDIN_FILENO && process->stdout != STDERR_FILENO)
				close(process->stdout);
			process->stdout = out;
		}
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
	    if (leafs->token->type == p_io_file)
	        from = atoi(leafs->token->raw);
	if (leafs->left->left->token)
	{
		if (leafs->left->left->token->type == l_word)
		{
			out = open(leafs->left->left->token->raw, options, 0644);
			if (-1 == out)
				open_error();
			if (from != -1)
            {
			    if (STDERR_FILENO == from)
			        process->stderr = out;
			    else if (STDOUT_FILENO == from)
			        process->stdout = out;
			    else if (STDIN_FILENO == from)
			        process->stdin = out;
            }
			else
            {
                if (process->stdout != STDOUT_FILENO && process->stdout != STDIN_FILENO && process->stdout != STDERR_FILENO)
                    close(process->stdout);
                process->stdout = out;
            }
		}
	}
}
void 	l_less_redirect(t_ast *leafs, t_process *process)
{
	int in;

	in = -1;
	if (leafs->left->left->token)
	{
		if (leafs->left->left->token->type == l_word)
		{
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
	int from;
	t_ast **redirects;
	int redirect_type;

	redirect_type = 0;
	i = 0;
	from = -1;
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
			    l_great_and_redirect(redirects[i], process, from);
		}
		i++;
	}
	return (0);
}