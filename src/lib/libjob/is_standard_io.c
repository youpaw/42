/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_standard_io.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_standard_io(int fd)
{
	return (fd == STDIN_FILENO || fd == STDERR_FILENO || fd == STDOUT_FILENO);
}
