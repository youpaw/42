
#ifndef CC_LST_H
# define CC_LST_H
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			size;
	struct s_list	*next;
}					t_list;

t_list				*lst_new(void *content, size_t size);

int					lst_del_one(t_list **alst, void (*del)(void*));

int					lst_del(t_list **alst, void (*del)(void *));

int					lst_add(t_list **alst, t_list *new);

void				lst_iter(t_list *lst, void (*f)(t_list *elem));

t_list				*lst_map(t_list *lst, t_list *f(t_list *elem));

int					lst_circle(t_list *list);

int					lst_del_circle(t_list **list, void (*del)(void*));

int					lst_add_sort(t_list **list, t_list *newlist, void *params, \
					int (*cmp)(const void *, const void *, void *));

t_list				*lst_find(t_list *lst, int (*cmp)(const void *, const void *),
					const void *content);

# define LST_OK 0
# define LST_DNE LST_OK + 1
#endif //CC_LST_H
