/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:35:28 by mudoh             #+#    #+#             */
/*   Updated: 2023/03/28 00:38:09 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	int		vm;
	int		i;

	i = 0;
	tmp = *lst;
	vm = tmp->val;
	while (tmp->next)
	{
		if (tmp->val < vm)
		{
			vm = tmp->val;
			i = tmp->index;
		}
		tmp = tmp->next;
	}
	if (i < (lstlast(*lst)->index / 2))
		while (a_is_sorted(*lst) != 1)
			rotate(lst, "ra");
	else
		while (a_is_sorted(*lst) != 1)
			reverse_rotate(lst, "ra");
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


