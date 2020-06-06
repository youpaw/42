//
// Created by youpaw on 05.05.2020.
//

#ifndef CC_CHAR_H
# define CC_CHAR_H

# undef isspace
# undef isdigit
# undef isalpha
# undef isalnum
# undef isupper
# undef islower

int 		isupper(int c);
int 		islower(int c);
int 		isalpha(int c);
int 		isalnum(int c);
int			isspace(int c);
int			isdigit(int c);

#endif //CC_CHAR_H
