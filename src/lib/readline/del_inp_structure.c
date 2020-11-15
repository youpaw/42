/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_inp_structure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	del_input(t_inp *input)
{
	size_t i;

	i = 0;
	while (input->line[i])
		vec_del(&(input->line[i++]));
	vec_del(&(input->line[i]));
	free(input->l_len);
	free(input->line);
	input->l_len = NULL;
	input->line = NULL;
}
