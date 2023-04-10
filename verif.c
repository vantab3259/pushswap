/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:02:27 by mudoh             #+#    #+#             */
/*   Updated: 2023/04/10 20:20:35 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_list(t_lst *list)
{
	t_lst	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
}

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
	int max;
	int	min;

	max = find_max_lst(lst);
	min = find_min_lst(lst);
	/* printf("min = %d\n", min);
	printf("max = %d\n", max); */
	while (lst->next)
	{
		if (lst->val == max && lst->next->val != min)
				return (0);
		else if (lst->val > lst->next->val)
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
	// printf("liste deja triee!\n");
	return (1);
}

// au pantheon des fonctions
/* int	tri_trois_a(t_lst **lst)
{
	// if ((*lst)->val < (*lst)->next->val)
	// {
	// 	reverse_rotate(lst, "rra");
	// 	a_is_sorted(*lst);
	swap(lst, "sa\n");
	// }
	// else
	// {
	// 	if ((*lst)->val < (*lst)->next->next->val)
	// 		swap(*lst, "sa");
	// 	else
	// 	{
	// 		if ((*lst)->next->val < (*lst)->next->next->val)
	// 			rotate(lst, "rra");
	// 		else
	// 		{
	// 			reverse_rotate(lst, "rra");
	// 			swap(*lst, "sa");
	// 		}
	// 	}
	// }
	return (0);
} */