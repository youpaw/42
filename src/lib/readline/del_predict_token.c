//
// Created by Darth Butterwell on 10/25/20.
//

#include "readline.h"

void	del_predict_token(t_prdct_tkn **token)
{
	if (!token || !*token)
		return ;
	free((*token)->raw);
	free(*token);
	*token = NULL;
}
