/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:02:27 by mudoh             #+#    #+#             */
/*   Updated: 2023/04/18 02:11:53 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	how_many_part(t_lst *lst_a)
{
	t_lst	*tmp;
	int		i;

	tmp = lst_a;
	if (lstlast(tmp)->index > 100)
		i = 1;
	else
		i = 0;
	return (i);
}

int	find_max_lst(t_lst *lst)
{
	int	max;

	max = lst->val;
	while (lst)
	{
		if (max < lst->val)
			max = lst->val;
		lst = lst->next;
	}
	return (max);
}

int	find_min_lst(t_lst *lst)
{
	int	min;

	min = lst->val;
	while (lst)
	{
		if (min > lst->val)
			min = lst->val;
		lst = lst->next;
	}
	return (min);
}

int	list_is_range(t_lst *lst)
{
	int	max;
	int	min;

	max = find_max_lst(lst);
	min = find_min_lst(lst);
	if (a_is_sorted(lst) == 1)
		return (1);
	while (lst->next)
	{
		if (lst->val == max && lst->next->val != min)
			return (0);
		if (lst->val > lst->next->val && (lst->val != max
				|| lst->next->val != min))
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	a_is_sorted(t_lst *lst_a)
{
	t_lst	*tmp;

	tmp = lst_a;
	while (tmp->next)
	{
		if (tmp->next->val < tmp->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
