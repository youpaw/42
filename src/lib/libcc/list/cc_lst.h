
#ifndef CC_LST_H
# define CC_LST_H
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*lst_new(void *content);

void				lst_del_one(t_list **alst, void (*del)(void*));

void				lst_del(t_list **alst, void (*del)(void *));

void				lst_add(t_list **alst, t_list *new);

void				lst_iter(t_list *lst, void (*f)(t_list *elem));

t_list				*lst_map(t_list *lst, t_list *f(t_list *elem));

void				lst_circle(t_list *list);

void				lst_del_circle(t_list **list, void (*del)(void*));

void				lst_add_sort(t_list **list, t_list *newlist, void *params, \
		int (*cmp)(const void *, const void *, void *));

#endif //CC_LST_H
