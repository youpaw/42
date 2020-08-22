/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:00:51 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 13:00:52 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** usage:
** h_init(<path to file>);		//opens file and loads history
** char out[MAX_CMD_LENGTH];	//allocate MAX_CMD_LENGTH to buffer
** int r = h_get_prev(out);		//returns E_OK and initializes out with 
** previous command. if no more previous commands, returns E_FAIL
** int r = h_get_next(out);		//returns E_OK and initializes out with 
** next command. if no more next commands, returns E_FAIL
** h_append(const char *cmd);	//appends new cmd to the end of list
** int r = h_save_new();		//saves new commands to file openned in h_init
*/

#ifndef HISTORY_H
# define HISTORY_H
# define N_COMMANDS 1000
# define HIST_FILE_NAME ".bash_history"

struct s_hist
{
	const char 	*file_path;
	char		*commands[N_COMMANDS];
	int			cur_ind;
	int			size;
};

typedef struct s_hist t_hist;

extern t_hist *g_hist;

int		hist_init(void);

int 	hist_push(const char *cmd);

char 	*hist_get_by_prefix(const char *prefix);
char 	*hist_get_by_index(int index);
char 	*hist_get_last(void);
char	*hist_get_next(void);
char	*hist_get_prev(void);
char 	*hist_find(const char *str);
void 	reset_cur_ind(void);

void	hist_save(void);

#endif 