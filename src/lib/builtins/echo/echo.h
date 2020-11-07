//
// Created by slava-nya on 10/2/20.
//

#ifndef ECHO_H
#define ECHO_H

#include "builtins.h"
#include "cc.h"
#include "optparse.h"

#define ECHO_n_FLAG 00000001
#define ECHO_e_FLAG 00000010
#define ECHO_E_FLAG 00000100

typedef struct		s_echo
{
	char			first;
	char			second;
}					t_echo;

char		*handle_esc_chars(char *str);


#endif //ECHO_H
