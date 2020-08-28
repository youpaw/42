//
// Created by Darth Butterwell on 8/28/20.
//

#include "lexer.h"

void destruct_token(t_token **token)
{
	if (!token && !*token)
		return ;
	if ((*token)->raw)
		free((*token)->raw);
	free(*token);
	*token = NULL;
}
