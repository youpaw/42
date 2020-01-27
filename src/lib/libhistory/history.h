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

int		h_init(const char *path);
int		h_close();

int		h_get_prev(char *out);
int		h_get_next(char *out);
void	h_append(const char *content);

int		h_save_new();

#endif 