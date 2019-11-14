#include <unistd.h>

int		strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	write(1, "test\n", 5);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
