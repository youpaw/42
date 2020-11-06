//
// Created by Fidelia Mallister on 11/4/20.
//

#include "exec.h"
#include <unistd.h>
#include "cc_str.h"

int redirect_heredoc(t_ast *leafs, t_process *process) // c
{
	int pfd[2];

	if (pipe(pfd) < 0)
		return (1); // pipe error
	close(pfd[1]);
	process->stdin = pfd[0];
	fdputendl(leafs->left->left->token->raw, process->stdin);
	return (0);
}
