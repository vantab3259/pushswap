/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commad_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:46:16 by mudoh             #+#    #+#             */
/*   Updated: 2023/04/08 18:11:55 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_all(t_lst **lsta, t_lst **lstb, char *ss)
{
	swap(lstb, "");
	swap(lsta, "");
	printf("%s\n", ss);
}

void	rotate_all(t_lst **lsta, t_lst **lstb, char *rr)
{
	rotate(lstb, "");
	rotate(lsta, "");
	printf("%s\n", rr);
}

void	reverse_rotate_all(t_lst **lsta, t_lst **lstb, char *msg)
{
	reverse_rotate(lstb, "");
	reverse_rotate(lsta, "");
	printf("%s", msg);
}

int	is_max(t_lst *lst)
{
	int	max;

	max = lst->val;
	while (lst)
	{
		if (lst->val > max)
			max = lst->val;
		lst = lst->next;
	}
	return (max);
}

int	is_minim(t_lst *lst)
{
	t_lst	*tmp;
	int		i;
	int		vmin;

	i = 0;
	tmp = lst;
	vmin = tmp->val;
	while (tmp)
	{
		
		if (tmp->val < vmin)
		{
			vmin = tmp->val;
			i = tmp->index;
		}
		tmp = tmp->next;
	}
	return (i);
}
