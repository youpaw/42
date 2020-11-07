//
// Created by Darth Butterwell on 8/23/20.
//

#ifndef BUILTINS_H
# define BUILTINS_H

int		cd(const char **av);
int 	set(const char **args);
int 	unset(const char **args);
int 	export(const char **av);
int 	hash(const char **av);
int		echo(const char **av);
int		alias(const char **av);
int		unalias(const char **av);

int 	run_builtin(const char **av);

#endif //BUILTINS_H
