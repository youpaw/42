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
# define READLINE_H

# define N_ORD_KEY_HANDLERS 7
# define N_ESC_KEY_HANDLERS 11
# define FIRST_PROMPT_TEXT "42sh $> "
# define FIRST_PROMPT_LEN 8
# define NEXT_PROMPT_TEXT "> "
# define NEXT_PROMPT_LEN 2
# define N_BUILTINS 14
# define MAX_PATH 1024

# include <termios.h>
# include "cc_vec.h"
# include "cc_lst.h"
# include "cc_graph.h"
# include "lexer.h"

struct termios		g_tty_backup;

typedef struct		s_input
{
	t_vec			**line;
	size_t			x_pos;
	size_t			y_pos;
	size_t			len;
	size_t			*l_len;
	char			*hist_storage;
}					t_inp;

typedef union		u_letter
{
	char			ch[5];
	int				num;
}					t_let;

typedef struct		s_key_readline_handler
{
	char			primary_key[5];
	int				(*handler)(t_inp *);
}					t_key_readline_handler;

typedef	enum		e_predict_type
{
	r_cmd,
	r_file,
	r_param
}					t_predict_type;

typedef	struct		s_predict_token
{
	char				*raw;
	enum e_predict_type	type;
}					t_prdct_tkn;

int tty_init();
void			tty_restore(void);

t_prdct_tkn	*get_predict_token(char *raw);
void			del_predict_token(t_prdct_tkn **token);

void			select_choise(void *files, t_inp *inp, char *current);

void			put_str_to_input(t_inp *inp, char *part);

int				handle_left_arrow(t_inp *inp);
int				handle_right_arrow(t_inp *inp);
int				handle_shift_up(t_inp *inp);
int				handle_shift_down(t_inp *inp);
int				handle_shift_right(t_inp *inp);
int				handle_shift_left(t_inp *inp);
int				handle_backspace(t_inp *inp);
int				handle_del(t_inp *inp);
int				handle_tab(t_inp *inp);
int				handle_symbol_key(t_inp *inp, char *key);
int				handle_escape_sequence(t_inp *input);
int				handle_down_arrow(t_inp *inp);
int				handle_up_arrow(t_inp *inp);
int				handle_home_key(t_inp *inp);
int				handle_end_key(t_inp *inp);
int				handle_eox(t_inp *inp);
int				handle_eot(t_inp *inp);

int				handle_key(char *key, t_inp *input);

void			handle_command_token(t_inp *inp, t_prdct_tkn *token);

t_inp			input_init(char *line);
int				readline(char **line);

void			clear_display_input(t_inp *inp);
void			common_redraw(t_inp *input);
void			redraw_input_readline(t_inp *inp);

char			*input_to_str(t_inp input, int newline);
char			*input_to_n_str(t_inp input);

void			handle_file_token(t_inp *input, t_prdct_tkn *token, int acc_m);
void			handle_param_token(t_inp *input, t_prdct_tkn *token);

char			**parse_filename(char *fullname);
int				check_for_utf8_comb_charecter(char *p, char *let, size_t len);
char			*find_same_part(t_list *files, char*filename);
void			clear_last_disp_token(char *token, t_inp *input);

void			print_prompt(t_inp *inp);
char			*get_prompt(int y);
int				get_prompt_len(int y);

void			fill_complition_graph(t_graph *graph);

void			reload_input(t_inp *inp, char *str);
void			redraw_input(t_inp inp, char *str);
void			put_cursor_to_the_end(t_inp *inp);

char			**split_newline(char *line);

void			del_input(t_inp *input);

#endif //READLINE_H
