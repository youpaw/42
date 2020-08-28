/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:20:02 by mgena             #+#    #+#             */
/*   Updated: 2020/08/28 14:20:11 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
#define READLINE_H
#define TEST {"", "fuck", ".", "./", "..", "../", "./C", "4"}
#define BUFFSIZE	1024

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <stdbool.h>
# include <term.h>
# include <sys/stat.h>
# include "cc_vec.h"
# include <dirent.h>
#include <termcap.h>
#include "cc.h"

struct termios	savetty;

typedef struct s_input
{
	t_vec	*line;
	int 	cursor_position;
	int		len;
}				t_input;

typedef union	u_letter
{
	char	ch[4];
	int 	num;
}				t_letter;

int			readline(char **line);
void		tty_init(void);
void		restore_tty(void);
void		termcap_init(void);
void 		ft_putstr(char *str);
int			ft_put(int c);
int			left_arrow_pressed(t_input *inp);
int			right_arrow_pressed(t_input *inp);
int			backspace_pressed(t_input *inp);
int			del_pressed(t_input *inp);
int 		symbol_key_pressed(t_input *inp, char key[4]);
t_input 	input_init(char *line);
int			autocomplete(t_input *inp);
void		complete_print(t_input *input, t_list **to_print);
int			getch(void);
int			get_unicod_len(char ch);

//temp
char *vect_to_str(t_vec *vector, int size);

#endif //READLINE_H
