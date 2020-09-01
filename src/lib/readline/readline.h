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
# include <dirent.h>
#include <termcap.h>
#include "cc.h"
#include "lexer.h"

struct termios	savetty;

typedef struct s_input
{
	t_vec	*line;
	int 	cursor_position;
	int		len;
}				t_input;

typedef union	u_letter
{
	char	ch[5];
	unsigned char uch[5];
	int 	num;
	unsigned int unum;
}				t_letter;

/*
 * Struct to easy converting UTF-8. It uses space in memory like this:
*				  mask        lead        beg      end       bits
*        &(utf_t){0b00111111, 0b10000000, 0,       0,        6    }
*/
typedef struct {
	char mask;
	char lead;
	uint32_t beg;
	uint32_t end;
	int bits_stored;
}utf_t;

int 		g_input_changed_flg;

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
char		*input_to_str(t_input input);
int			get_displayed_symbol_len(unsigned char *num);
t_list		*get_list_files(t_input *input, t_token *token);
void		choose_token(t_input *input, t_list *lst);


#endif //READLINE_H
