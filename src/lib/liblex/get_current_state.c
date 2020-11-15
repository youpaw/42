/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_state		get_current_state(t_lexer *lexer)
{
	int					cnt;
	t_slice				current;
	static const char	state_map[N_STATES - 1] = {'\\', '\'', '"', '$', '!'};

	vec_get_last(&current, lexer->slices);
	if (current.state != l_unset)
		return (current.state);
	cnt = 0;
	while (cnt < (N_STATES - 1) && state_map[cnt] != lexer->raw[lexer->index])
		cnt++;
	if (cnt < (N_STATES - 1))
	{
		current.state = cnt;
		current.index = lexer->index;
		vec_push(lexer->slices, &current);
		lexer->index++;
	}
	else
		return (l_unset);
	return (cnt);
}
