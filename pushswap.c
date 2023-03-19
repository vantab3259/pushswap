/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:32:49 by mudoh             #+#    #+#             */
/*   Updated: 2023/03/19 19:15:50 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
//t_lst	take_arg(char **)
{
	t_lst	lst;

	lst
}
t_lst	rotate(t_lst *lst)
{
	t_lst	*e;
	int		tmp;
	int		tmp;
	int		tmp;
	int		tmp;
	int		tmp;
	int		tmp;
	t_lst	*tmp;

	e = lst->next;
	lst->next = e->next;
	e->next = NULL;
	e->prev = NULL;
	e->next = lst->next->next;
	lst->prev = ft_lstlast(lst);
	lst->next = NULL;
}*/



void	ft_lstadd_front(t_lst **lst, t_lst *new)
{
}
t_lst	*sup_element_tete(t_lst *premiere_position)
{
	t_lst	*second_position;

	if (premiere_position != NULL)
	{
		second_position = premiere_position->next;
		free(premiere_position);
		return (second_position);
	}
	else
		return (NULL);
}

void	ft_swap(t_lst *lst)
{
	int	tmp;

	tmp = lst->val;
	lst->val = lst->next->val;
	lst->next->val = tmp;
}

void push_a(t_lst **pile_a, t_lst **pile_b)
{
    t_lst *temp;
    temp = *pile_a;
    
    while (temp->next->next != NULL)
        temp = temp->next;
    
    t_lst *second_to_last = temp;
    t_lst *last = temp->next;
    second_to_last->next = NULL;
    
    push_number(pile_b, last->val);
}

int	main(int argc, char **argv)
{
	t_lst *lsta;
	t_lst *lstb;

	int i;

	i = 2;
	lsta = ft_lstnew(ft_atoi(argv[1]));
	lstb = NULL;

	while (i < argc)
	{
		ft_lstadd_back(lsta, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	afficherListe(lstb);
	//ft_swap(lsta);
	afficherListe(lsta);
	push_a(&lsta, &lstb);
	afficherListe(lsta);
	afficherListe(lstb);

	return (0);
}