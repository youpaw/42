/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:20:54 by darugula          #+#    #+#             */
/*   Updated: 2019/09/16 21:20:56 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

void		extract_value(char *dst, char *rest, const char *separator)
{
	int n;

	n = strstr(rest, separator) - rest;
	strncpy(dst, rest, n);
	dst[n] = 0;
	strcpy(rest, rest + n + strlen(separator));
}

int		lst_load(int fd, const char *separator, void (*add)(const char*))
{
	int	r; 
#define BUF_LEN 1
#define MAX_COMMAND_LENGTH 300
	char buffer[BUF_LEN + 1];
	char rest[MAX_COMMAND_LENGTH + 1 + strlen(separator)];
	char cmd[MAX_COMMAND_LENGTH + 1];
	rest[0] = 0;
	while ((r = read(fd, buffer, BUF_LEN)) > 0)
	{
		buffer[r] = 0;
		str_append(rest, buffer);
		if (str_contains(rest, separator))
		{
			extract_value(cmd, rest, separator);
			add((const char*)cmd);
		}
	}
	return (E_OK);
}