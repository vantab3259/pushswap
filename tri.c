/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:35:28 by mudoh             #+#    #+#             */
/*   Updated: 2023/03/27 01:51:20 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	a_is_sorted(t_lst *lst_a)
{
	t_lst *tmp;

	tmp = lst_a;
	while(tmp->next)
	{
		if(tmp->next->val < tmp->val)
			return(1);
		tmp = tmp->next;
	}
	printf("liste deja triee!\n");
	exit(0);
}

int	list_is_range(t_lst *lst)
{
	t_lst *tmp;
	t_lst *jump;

	tmp = lst;
	while(tmp->next && tmp->val < tmp->next->val)
		tmp = tmp->next;
	if(tmp->next != NULL)
	{	
		tmp = tmp->next;
		jump = tmp;
	}
	else
		exit(0);
	while(jump->next && jump->val < jump->next->val)
		jump = jump->next;
	if(jump->val < lst->val)
		return(0);
	else
		return(1);	
}

int	tri_trois_a(t_lst **lst)
{
	if((*lst)->val < (*lst)->next->val)
	{
		reverse_rotate_a((lst));
		a_is_sorted(*lst);
		swap_a(*lst);
	}	
	else
	{
		if((*lst)->val < (*lst)->next->next->val)
			swap_a((*lst));
		else
		{
			if((*lst)->next->val < (*lst)->next->next->val)
				rotate_a(lst);
			else
			{
				rotate_a(lst);
				swap_a(*lst);
			}
		}	
	}
	return(0);
}

void	index_init(t_lst **lst)
{
	t_lst	*tmp;
	int		i;

	tmp = *lst;
	i = 0;
	while (tmp->next != NULL)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
	
}

void	firststep(t_lst **lst_a, t_lst **lst_b)
{
	index_init(lst_a);

	if (how_many_part(*lst_a) == 0)
		while ((*lst_a)->next->next->next)
		{
			push_b(lst_a, lst_b);
		}
	index_init(lst_b);
	/* 	else
		while(lst_a->next->next->next)
		{
			if(lst_a->val < 10)
				push_b(&lst_a, &lst_b);
		}
		print_list(lst_a);
		print_list(lst_b); */
}

int		secondstep(t_lst *lst_a, t_lst *lst_b)
{
	t_lst *tmp;
	
	tmp = lst_b;
} 
