//
// Created by Darth Butterwell on 8/23/20.
//

#ifndef BUILTINS_H
#define BUILTINS_H

int		cd(int ac, const char **av);
int 	set(const char **args);
int 	unset(const char **args);
int 	sh_exit(const char **av);
int 	export(const char **av);
int 	run_builtin(const char **av);

#endif //BUILTINS_H
