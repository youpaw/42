#ifndef HISTORY_H


int		h_init(const char *path);
void		h_close();

int		h_get_prev(char *out);
int		h_get_next(char *out);
void		h_append(const char *content);

int		h_save_new();

#endif 