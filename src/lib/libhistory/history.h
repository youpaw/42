/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:26:56 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:26:59 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H
# define HIST_FILE_SIZE 2500
# include "cc_vec.h"

typedef struct	s_hist
{
	const char	*file_path;
	t_vec		*commands;
	int			cur_ind;
}				t_hist;

extern t_hist	g_hist;

void			hist_init(const char *home_dir);

int				hist_push(const char *cmd);
char			*hist_get_by_prefix(const char *prefix);
char			*hist_get_by_index(int index);
char			*hist_get_last(void);
char			*hist_get_next(void);
char			*hist_get_prev(void);
void			hist_reset_cur_ind(void);

void			hist_save(void);
void			hist_print(void);

#endif
