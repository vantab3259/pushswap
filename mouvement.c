/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:11:29 by mudoh             #+#    #+#             */
/*   Updated: 2023/03/29 18:59:25 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	mouv_if_rr(t_lst **a, t_lst **b, t_tab information)
{
	t_tab	info;

	info = information;
	while (info.ia != 0 || info.ib != 0)
	{
		rotate_all(a, b, "rr");
		info.ia--;
		info.ib--;
	}
	while (info.ia != 0)
	{
		rotate(a, "ra");
		info.ia--;
	}
	while (info.ib != 0)
	{
		rotate(b, "rb");
		info.ib--;
	}
}

void	mouv_if_rrr(t_lst **a, t_lst **b, t_tab info)
{
	info.imaxa = lstlast(*a)->index + 1;
	info.imaxb = lstlast(*b)->index + 1;
	while (info.ia != info.imaxa || info.ib != info.imaxb)
	{
		reverse_rotate_all(a, b, "rrr");
		info.ia++;
		info.ib++;
	}
	while (info.ia != info.imaxa)
	{
		reverse_rotate(a, "rra");
		info.ia++;
	}
	while (info.ib != info.imaxb)
	{
		reverse_rotate(b, "rrb");
		info.ib++;
	}
}
void	mouv_if_rrarb(t_lst **a, t_lst **b, t_tab information)
{
	t_tab	info;

	info = information;
	info.imaxa = lstlast(*a)->index + 1;
	while (info.ia != info.imaxa)
	{
		reverse_rotate(a, "rra");
		info.ia++;
	}
	while (info.ib != 0)
	{
		rotate(b, "rb");
		info.ib--;
	}
}
void	mouv_if_rarrb(t_lst **a, t_lst **b, t_tab information)
{
	t_tab info;

	info = information;
	info.imaxb = lstlast(*b)->index + 1;

	while (info.ia != 0)
	{
		rotate(a, "ra");
		info.ia--;
	}
	while (info.ib != info.imaxb)
	{
		reverse_rotate(b, "rrb");
		info.ib++;
	}
}