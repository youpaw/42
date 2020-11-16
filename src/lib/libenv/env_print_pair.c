/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print_pair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "cc_str.h"

void	env_print_pair(const t_hash_pair *pair)
{
	if (!pair || !pair->value)
		return ;
	puts(pair->key);
	puts("=");
	putendl(pair->value);
}
