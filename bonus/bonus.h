/* #include "../ft_printf/ft_printf.h"
#include <stdlib.h>

typedef struct s_tab
{
	int				ia;
	int				ib;
	int				imaxa;
	int				imaxb;
}					t_tab;

typedef struct s_lst
{
	int				val;
	int				index;
	struct s_lst	*next;
	struct s_tab	*tab;
}					t_lst;

int					ft_atoi(char *n);
t_lst				*lstnew(int nbr, t_tab *tab);
t_lst				*lst_cut_head_and_save(t_lst **lst_a);
t_lst				*lst_cut_end_and_save(t_lst *lst_a);
t_lst				*lst_remove_head(t_lst *premiere_position);
t_lst				*lstlast(t_lst *lst);








void				free_list(t_lst **lst); */