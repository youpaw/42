/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_del_pair.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:03:56 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:03:59 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		env_del_pair(t_hash_pair *pair)
{
	free(pair->key);
	if (pair->value)
		free(pair->value);
}
