/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:36:33 by mudoh             #+#    #+#             */
/*   Updated: 2023/03/20 00:18:38 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(t_lst *lst)
{
	int	tmp;

	tmp = lst->val;
	lst->val = lst->next->val;
	lst->next->val = tmp;
}
void	swap_b(t_lst *lst)
{
	int	tmp;

	tmp = lst->val;
	lst->val = lst->next->val;
	lst->next->val = tmp;
}

void	push_b(t_lst **pile_a, t_lst **pile_b)
{
	t_lst	*temp;
 	temp = ft_lst_cut_head_and_save(pile_a);

	pile_addback(pile_b, temp);	
}

void	push_a(t_lst **pile_a, t_lst **pile_b)
{
	t_lst	*temp;
 	temp = ft_lst_cut_head_and_save(pile_b);

	pile_addback(pile_a, temp);
}

void	rotate_a(t_lst **lst)
{
	t_lst	*temp;
 	temp = ft_lst_cut_head_and_save(lst);

	pile_addback(lst, temp);
}

void	rotate_b(t_lst **lst)
{
	t_lst	*temp;
 	temp = ft_lst_cut_head_and_save(lst);

	pile_addback(lst, temp);
}

void	reverse_rotate_a(t_lst **lst)
{
	t_lst	*temp;
 	temp = ft_lst_cut_end_and_save(*lst);
	
	pile_addfront(lst, &temp);
	print_list(*lst);
}

t_lst	*ft_lst_cut_end_and_save(t_lst	*lst_a)
{
	t_lst	*new;
	t_lst	*temoin;
	
	new = lst_a;
	while(new->next != NULL)
	{
		temoin = new; 
		new = new->next;
	}
	temoin->next = NULL;
	return(new);
}