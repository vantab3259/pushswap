/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:02:27 by mudoh             #+#    #+#             */
/*   Updated: 2023/03/27 19:58:03 by mudoh            ###   ########.fr       */
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
	if (lstlast(lst_a)->index > 100)
		i = 1;
	else
		i = 0;
	return (i);
}

int	list_is_range(t_lst *lst)
{
	t_lst	*tmp;
	t_lst	*jump;

	tmp = lst;
	while (tmp->next && tmp->val < tmp->next->val)
		tmp = tmp->next;
	if (tmp->next != NULL)
	{
		tmp = tmp->next;
		jump = tmp;
	}
	else
		return (1);
	while (jump->next && jump->val < jump->next->val)
		jump = jump->next;
	if (jump->val < lst->val)
		return (1);
	else
		return (0);
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
	printf("liste deja triee!\n");
	return (1);
}

// au pantheon des fonctions
int	tri_trois_a(t_lst **lst)
{
	if ((*lst)->val < (*lst)->next->val)
	{
		reverse_rotate(lst, "rra");
		a_is_sorted(*lst);
		swap(*lst, "sa");
	}
	else
	{
		if ((*lst)->val < (*lst)->next->next->val)
			swap(*lst, "sa");
		else
		{
			if ((*lst)->next->val < (*lst)->next->next->val)
				rotate(lst, "rra");
			else
			{
				reverse_rotate(lst, "rra");
				swap(*lst, "sa");
			}
		}
	}
	return (0);
}