#include "env.h"
#include "builtins.h"

int main(int ac, char *av[], char *en[])
{
	env_init((const char **) en);
	av_init(av[0], (const char **) (av + 1));
	cd(ac, (const char **) av, (const char **) en);
	return (0);
}
