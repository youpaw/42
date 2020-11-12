/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmp_pair.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:03:51 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:03:53 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "cc_str.h"

int		env_cmp_pair(const t_hash_pair *lhs, const t_hash_pair *rhs)
{
	return (strcmp(lhs->key, rhs->key));
}
