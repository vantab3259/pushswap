/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:35:28 by mudoh             #+#    #+#             */
/*   Updated: 2023/03/25 23:57:21 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	index_inti(t_lst *lst)
{
	t_lst	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp->next != NULL)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

void	firststep(t_lst *lst_a, t_lst *lst_b)
{
	index_inti(lst_a);
	index_inti(lst_b);
	if (how_many_part(lst_a) == 0)
		while (lst_a->next->next->next)
		{
			push_b(&lst_a, &lst_b);
		}
	print_list(lst_a);
	print_list(lst_b);
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
