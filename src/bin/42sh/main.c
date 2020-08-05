#include "cc.h"

void 	del(t_hash_pair *pair)
{
	free(pair->value);
	free(pair->key);
}

int main(int ac, char *av[], char *en[])
{
//	fdputs("Hello world!", 1);
//	return (0);

	t_hash_table *table;
	t_hash_pair pair;

	table = hash_new(100, (size_t (*)(const void *)) &strhash, \
					 (int (*)(const void *, const void *)) &strcmp, &del);
	int cnt = 1;
	while (cnt < ac)
	{
		pair.key = strdup(av[cnt]);
		pair.value = strdup(av[cnt]);
		hash_insert(table, &pair);
		cnt++;
	}
	cnt = 1;
	char *value;
	while (cnt < ac)
	{
		value = hash_get_val(table, av[cnt]);
		fdputs(value, 1);
		fdputs("\n", 1);
		cnt++;
	}
	hash_del(&table);
}
