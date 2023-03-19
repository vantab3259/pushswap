#include "ft_printf/ft_printf.h"
#include <stdlib.h>

typedef struct s_lst
{
	int				val;
	int				index;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

int					ft_atoi(char *n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

//lst utils
t_lst				*ft_lstnew(int nbr);
void				*ft_lstadd_back(t_lst *lst, t_lst *next);
void				afficherListe(t_lst *list);
void 				push_number(t_lst **pile_a, int new_data);
void    			pile_addback(t_lst **lst, t_lst *new);
t_lst    			*pile_last(t_lst *lst);