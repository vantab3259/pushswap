/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ebauche_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:19:54 by mudoh             #+#    #+#             */
/*   Updated: 2023/03/28 00:36:13 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


int		is_mini(t_lst *lst)
{
	t_lst *tmp;
	int i;
	int vmin;
	
	i = 0;
	tmp = lst;
	vmin = tmp->val;
	while(tmp->next)
	{	
		tmp = tmp->next;
		if(tmp->val < vmin)
		{
			vmin = tmp->val;
			i = tmp->index;
		}
		printf("vmin;%d\n\n", vmin);
		printf("tmpval;%d\n\n", tmp->val);
		printf("i;%d\n\n", i);
	}
	printf("%d\n", i);
	return(i);
}

int		search(t_lst *lst, int valeur)
{
	t_lst *tmp;
	int i;
	int v;
	
	
	i = 200; 
	tmp = lst;
	v = tmp->val;
	index_init(&tmp);
	while(tmp->next)
	{
		if(tmp->val < v && tmp->val > valeur)
		{
			v = tmp->val;
			i = tmp->index;
		}
		tmp = tmp->next;
	}
	if(i == 200)
		return(is_mini(lst));
	return(i);
}

void	firststep(t_lst **lst_a, t_lst **lst_b)
{
	index_init(lst_a);
	if (how_many_part(*lst_a) == 0)
		while ((*lst_a)->next->next->next)
		{
			push_one_in_second(lst_a, lst_b, "pb");
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