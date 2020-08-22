/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:20:02 by mgena             #+#    #+#             */
/*   Updated: 2020/08/22 14:48:26 by mgena            ###   ########.fr       */
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
# include "vector/cc_vec.h"

typedef struct	s_out
{
	struct termios	savetty;
	char			tbuf[2048];
	char			strings[256];
	char			*p;
	char			*tname;
	int				fd;
	int 			cursor_position;
}				t_out;

t_out g_out;

typedef struct s_input
{
	t_vec	*line;
	int 	cursor_position;
	int		len;
}				t_input;

int			readline(char **line);
void		main_init(void);
void		return_tty(void);
void 		ft_putstr(char *str);
int			ft_put(int c);
int			left_arrow_pressed(t_input *inp);
int			right_arrow_pressed(t_input *inp);
int			backspace_pressed(t_input *inp);
int			del_pressed(t_input *inp);
int 		symbol_key_pressed(t_input *inp, char key);
t_input		input_init(void);
int			autocomplete(t_input *inp);

//temp
char *vect_to_str(t_vec *vector);

#endif //READLINE_H