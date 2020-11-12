/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print_pair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:04:35 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:04:37 by hlorrine         ###   ########.fr       */
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
