/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:35:28 by mudoh             #+#    #+#             */
/*   Updated: 2023/04/18 01:58:36 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	tmp->index = i;
}

void	make_order(t_lst **lst)
{
	t_lst	*tmp;
	int		ind_min;
	int		size;

	size = lstlast(*lst)->index;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->val == find_min_lst(*lst))
			ind_min = tmp->index;
		tmp = tmp->next;
	}
	if (ind_min <= (size + 1) / 2)
	{
		while (--ind_min > -1)
			rotate(lst, "ra\n");
		return ;
	}
	while (ind_min < size + 1)
	{
		reverse_rotate(lst, "rra\n");
		ind_min++;
	}
}

void	pile_addback(t_lst **lst, t_lst *new)
{
	t_lst	*last;

	if (!(*lst))
		*lst = new;
	else
	{
		last = lstlast(*(lst));
		last->next = new;
	}
	new->next = NULL;
}

void	pile_addfront(t_lst **lst, t_lst **new)
{
	if (!(lst))
		*lst = *new;
	else
		(*new)->next = *lst;
	*lst = *new;
}

void	push_number(t_lst **pile_a, int new_data)
{
	t_lst	*new_element;

	new_element = malloc(sizeof(t_lst));
	if (!new_element)
		return ;
	new_element->val = new_data;
	new_element->next = NULL;
	pile_addback(pile_a, new_element);
}
