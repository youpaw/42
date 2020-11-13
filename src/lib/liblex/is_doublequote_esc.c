//
// Created by Darth Butterwell on 11/4/20.
//

int		is_doublequote_esc(char c)
{
	static char	esc[] = "\"\\$";
	int			index;

	index = 0;
	while (esc[index] && esc[index] != c)
		index++;
	if (!esc[index])
		return (0);
	return (1);
}
