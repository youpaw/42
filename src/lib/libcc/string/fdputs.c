/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:34:32 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/25 20:06:09 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_str.h"
#include <unistd.h>

int	fdputs(const char *restrict s, int stream)
{
	return (write(stream, s, strlen(s)));
}
