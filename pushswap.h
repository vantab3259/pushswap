#include "ft_printf/ft_printf.h"
#include <stdlib.h>

typedef struct s_lst
{
	int				val;
	int				index;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

//utils
int					ft_atoi(char *n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					how_many_element(t_lst *lst);
int					how_many_part(t_lst *lst);

//lst utils
t_lst				*ft_lstnew(int nbr);
t_lst				*ft_lst_cut_head_and_save(t_lst **lst_a);
t_lst				*ft_lst_cut_end_and_save(t_lst *lst_a);
t_lst				*ft_lst_remove_head(t_lst *premiere_position);
t_lst    			*pile_last(t_lst *lst);
void				*ft_lstadd_back(t_lst *lst, t_lst *next);
void    			pile_addback(t_lst **lst, t_lst *new);
void				print_list(t_lst *list);
void 				push_number(t_lst **pile_a, int new_data);
void				pile_addfront(t_lst **lst, t_lst **new);
void				firststep(t_lst *lst_a, t_lst *lst_b);
void				index_inti(t_lst *lst);

//command
void				swap_a(t_lst *lst);
void				swap_b(t_lst *lst);
void				push_b(t_lst **pile_a, t_lst **pile_b);
void				push_a(t_lst **pile_a, t_lst **pile_b);
void				rotate_a(t_lst **lst);
void				rotate_b(t_lst **lst);
void				reverse_rotate_a(t_lst **lst);
void				reverse_rotate_b(t_lst **lst);
void				swap_all(t_lst *lsta, t_lst *lstb);
void				rotate_all(t_lst **lsta, t_lst **lstb);
void				reverse_rotate_all(t_lst **lsta, t_lst **lstb);