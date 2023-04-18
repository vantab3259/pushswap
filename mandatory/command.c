/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:36:33 by mudoh             #+#    #+#             */
/*   Updated: 2023/04/18 02:11:53 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	push_one_in_second(t_lst **pile_one, t_lst **pile_second, char *mesg)
{
	t_lst	*temp;

	if (*pile_one != NULL)
	{
		temp = lst_cut_head_and_save(pile_one);
		pile_addfront(pile_second, &temp);
		ft_printf("%s", mesg);
	}
}

void	swap(t_lst **lst, char *mesg)
{
	int	tmp;

	if ((*lst)->next != NULL && lst != NULL)
	{
		tmp = (*lst)->val;
		(*lst)->val = (*lst)->next->val;
		(*lst)->next->val = tmp;
		ft_printf("%s", mesg);
	}
}

void	rotate(t_lst **lst, char *mesg)
{
	t_lst	*temp;

	if (*lst != NULL)
	{
		if (!(*lst)->next)
			return ;
		temp = lst_cut_head_and_save(lst);
		pile_addback(lst, temp);
		ft_printf("%s", mesg);
	}
}

void	reverse_rotate(t_lst **lst, char *mesg)
{
	t_lst	*temp;

	if (*lst != NULL)
	{
		if (!(*lst)->next)
			return ;
		temp = lst_cut_end_and_save(*lst);
		pile_addfront(lst, &temp);
		ft_printf("%s", mesg);
	}
}
