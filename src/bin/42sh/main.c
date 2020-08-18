#include "cc.h"

int main(int ac, char *av[], char *en[])
{
//	fdputs("Hello world!", 1);
//	return (0);

	t_vec *vec;
	vec = vec_new(15, 1, NULL);
	int cnt = 0;
	while (av[0][cnt])
		vec_push(vec, &av[0][cnt++]);
	char n = '9';
	vec_push_at(vec, &n, 20);
	cnt++;
	char *str = vec->data;
	putendl(str);
	while (cnt--)
		vec_rm_last(vec);
	puts(vec->data);
	vec_del(&vec);
}
