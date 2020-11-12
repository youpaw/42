/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:38:01 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 18:38:05 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

# include <sys/stat.h>
# include "builtins.h"
# include "stdio.h"
# include "env.h"
# include "optparse.h"
# include "error.h"

# define N_PATHS 3
# define MAX_PATH 1024
# define MAX_FILE 256

# define CD_L_FLAG 00000001
# define CD_P_FLAG 00000010

enum					e_paths
{
	home,
	pwd,
	oldpwd,
};

char	*cd_path_canonization(const char *path);
int		cd_path_validation(const char *cn_path, const char *path);
int		cd_check_opt(const char **av, unsigned char *flags, int *er_code);
int		cd_error_print(t_error_code er_code, const char *arg);

#endif
