/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:21:20 by mudoh             #+#    #+#             */
/*   Updated: 2023/03/14 22:01:45 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_lst	*ft_lstnew(int nbr)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (0);
	new->val = nbr;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lstadd_back(t_lst *lst, t_lst *new)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	lst->next = new;
	new->next = NULL;
	new->prev = lst;
	new->index = lst->index + 1;
}
