/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:35:28 by mudoh             #+#    #+#             */
/*   Updated: 2023/04/10 18:15:49 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* int	a_is_sorted(t_lst *lst_a)
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
} */

/* int	list_is_range(t_lst *lst)
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
} */
