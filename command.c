/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:36:33 by mudoh             #+#    #+#             */
/*   Updated: 2023/03/24 22:18:42 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_b(t_lst **pile_a, t_lst **pile_b)
{
	if(*pile_a != NULL)
	{
		t_lst	*temp;
 		temp = ft_lst_cut_head_and_save(pile_a);

		pile_addback(pile_b, temp);
		ft_printf("pb\n");
	}
}

void	push_a(t_lst **pile_a, t_lst **pile_b)
{
	if(*pile_b != NULL)
	{
		t_lst	*temp;
 		temp = ft_lst_cut_head_and_save(pile_b);

		pile_addback(pile_a, temp);
		ft_printf("pa\n");
	}
}

void	swap_a(t_lst *lst)
{
	
	if(lst->next != NULL && lst != NULL)
	{
		int	tmp;
		
		tmp = lst->val;
		lst->val = lst->next->val;
		lst->next->val = tmp;
		ft_printf("sa\n");
	}
}
void	swap_b(t_lst *lst)
{
	if(lst->next != NULL && lst != NULL)
	{
		int	tmp;

		tmp = lst->val;
		lst->val = lst->next->val;
		lst->next->val = tmp;
		ft_printf("sb\n");
	}
}

void	rotate_a(t_lst **lst)
{
	if(*lst != NULL)
	{
		t_lst	*temp;
 		temp = ft_lst_cut_head_and_save(lst);

		pile_addback(lst, temp);
		ft_printf("ra\n");
	}
}

void	rotate_b(t_lst **lst)
{
	if(*lst != NULL)
	{
		t_lst	*temp;
 		temp = ft_lst_cut_head_and_save(lst);

		pile_addback(lst, temp);
		ft_printf("rb\n");
	}
}

void	reverse_rotate_a(t_lst **lst)
{
	if(*lst != NULL)
	{
		t_lst	*temp;
 		temp = ft_lst_cut_end_and_save(*lst);

		pile_addfront(lst, &temp);
		ft_printf("rra\n");
	}
}

void	reverse_rotate_b(t_lst **lst)
{
	if(*lst != NULL)
	{
		t_lst	*temp;
 		temp = ft_lst_cut_end_and_save(*lst);

		pile_addfront(lst, &temp);
		ft_printf("rrb\n");
	}
}

void	swap_all(t_lst *lsta, t_lst *lstb)
{
	swap_b(lstb);
	swap_a(lsta);
	ft_printf("rr\n");
}

void	rotate_all(t_lst **lsta, t_lst **lstb)
{
	rotate_b(lstb);
	rotate_a(lsta);
	ft_printf("rr\n");
}

void	reverse_rotate_all(t_lst **lsta, t_lst **lstb)
{
	reverse_rotate_b(lstb);
	reverse_rotate_a(lsta);
	ft_printf("rrr\n");
}

