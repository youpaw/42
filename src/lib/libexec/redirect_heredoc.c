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
	if (!is_standard_io(process->stdin))
		close(process->stdin);
	fdputs(leafs->left->left->token->raw, pfd[1]);
	process->stdin = pfd[0];
	close(pfd[1]);
	return (0);
}
