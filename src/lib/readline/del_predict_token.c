/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_predict_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	del_predict_token(t_prdct_tkn **token)
{
	if (!token || !*token)
		return ;
	free((*token)->raw);
	free(*token);
	*token = NULL;
}
