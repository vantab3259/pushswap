#include "ft_printf/ft_printf.h"
#include <stdlib.h>

typedef struct s_tab
{
	int				ia;
	int				ib;
	int				calcul;
	int				val;
	int				imaxa;
	int				imaxb;
	int				mouv;
}					t_tab;

typedef struct s_lst
{
	int				val;
	int				index;
	struct s_lst	*next;
	struct s_lst	*prev;
	struct s_tab	*tab;
}					t_lst;

//utils
int					ft_atoi(char *n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

//lst utils
t_lst				*lstnew(int nbr, t_tab *tab);
t_lst				*lst_cut_head_and_save(t_lst **lst_a);
t_lst				*lst_cut_end_and_save(t_lst *lst_a);
t_lst				*lst_remove_head(t_lst *premiere_position);
t_lst				*lstlast(t_lst *lst);

//pile utils
void				pile_addback(t_lst **lst, t_lst *new);
void				push_number(t_lst **pile_a, int new_data);
void				pile_addfront(t_lst **lst, t_lst **new);
void				firststep(t_lst **lst_a, t_lst **lst_b);
void				index_init(t_lst **lst);
void				make_order(t_lst **lst);

//lst veriftruc

void				print_list(t_lst *list);
int					how_many_part(t_lst *lst);
int					a_is_sorted(t_lst *lst_a);
int					tri_trois_a(t_lst **lst);
int					list_is_range(t_lst *lst);

//command
void				swap(t_lst **lst, char *mesg);
void				push_one_in_second(t_lst **pile_one, t_lst **pile_second,
						char *mesg);
void				rotate(t_lst **lst, char *mesg);
void				reverse_rotate(t_lst **lst, char *mesg);

//command all
void				rotate_all(t_lst **lsta, t_lst **lstb, char *rr);
void				reverse_rotate_all(t_lst **lsta, t_lst **lstb, char *msg);
void				swap_all(t_lst **lsta, t_lst **lstb, char *ss);
int					is_minim(t_lst *lst);
int					is_max(t_lst *lst);

//mouv
void				mouv_if_rr(t_lst **a, t_lst **b, t_tab information);
void				mouv_if_rrr(t_lst **a, t_lst **b, t_tab information);
void				mouv_if_rarrb(t_lst **a, t_lst **b, t_tab information);
void				mouv_if_rrarb(t_lst **a, t_lst **b, t_tab information);

//tri

int					search(t_lst *lst, int valeur);
int					how_many_moves(int index_a, int index_b, t_lst *a,
						t_lst *b);
int					wich_combo_do(int index_a, int index_b, t_lst *a, t_lst *b);
t_tab				find_best_nbr(t_lst *a, t_lst *b);
void				execute(t_lst **a, t_lst **b, t_tab *info);

//
int					find_max_lst(t_lst *lst);
int					find_min_lst(t_lst *lst);

//les oublier
//void				*ft_lstadd_back(t_lst *lst, t_lst *next);
//int					searchwhile(t_lst *lst_a, t_lst *lst_b);