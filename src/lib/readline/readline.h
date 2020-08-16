/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:20:02 by mgena             #+#    #+#             */
/*   Updated: 2020/08/16 16:45:01 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
#define READLINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <stdbool.h>
# include <term.h>
# include <sys/stat.h>

typedef struct	s_out
{
	struct termios	savetty;
	char			tbuf[2048];
	char			strings[256];
	char			*p;
	char			*tname;
	int				fd;
}				t_out;

t_out g_out;

int			readline(char **line);
void		main_init(void);
void		return_tty(void);
void 		ft_putstr(char *str);
int			ft_put(int c);

#endif //READLINE_H
