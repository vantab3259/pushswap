/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:21:20 by mudoh             #+#    #+#             */
/*   Updated: 2023/04/03 20:27:49 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_lst	*lstnew(int nbr, t_tab *tab)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (0);
	new->val = nbr;
	new->index = 0;
	new->next = NULL;
	new->tab = tab;
	return (new);
}

t_lst	*lstlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_lst	*lst_remove_head(t_lst *premiere_position)
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

t_lst	*lst_cut_head_and_save(t_lst **lst_a)
{
	t_lst	*new;

	new = *lst_a;
	*lst_a = (*lst_a)->next;
	new->next = NULL;
	return (new);
}

t_lst	*lst_cut_end_and_save(t_lst *lst_a)
{
	t_lst	*new;
	t_lst	*temoin;

	new = lst_a;
	while (new->next != NULL)
	{
		temoin = new;
		new = new->next;
	}
	temoin->next = NULL;
	return (new);
}

//les oublier

//void	*ft_lstadd_back(t_lst *lst, t_lst *next)
//{
//	t_lst	*new;
//
//	new = next;
//	while (lst->next)
//	{
//		lst = lst->next;
//	}
//	lst->next = new;
//	new->next = NULL;
//	new->prev = lst;
//	new->index = lst->index + 1;
//}