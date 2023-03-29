/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ebauche_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:19:54 by mudoh             #+#    #+#             */
/*   Updated: 2023/03/29 19:25:53 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	search(t_lst *lst, int valeur)
{
	t_lst	*tmp;
	int		i;
	int		v;

	i = 20000;
	tmp = lst;
	v = tmp->val;
	while (tmp->next)
	{
		if (tmp->val <= v && tmp->val > valeur)
		{
			v = tmp->val;
			i = tmp->index;
		}
		tmp = tmp->next;
	}
	if (i == 20000)
		return (is_minim(lst));
	return (i);
}

int	wich_combo_do(int index_a, int index_b, t_lst *a, t_lst *b)
{
	int	rr;
	int	rarrb;
	int	rrarb;
	int	rrr;

	rrr = 1 + (lstlast(b)->index - index_b);
	if ((lstlast(a)->index - index_a) >= (lstlast(b)->index - index_b))
		rrr = 1 + (lstlast(a)->index - index_a);
	rr = index_b;
	if (index_a >= index_b)
		rr = index_a;
	rarrb = index_a + (lstlast(b)->index - index_b) + 1;
	rrarb = index_b + (lstlast(a)->index - index_a) + 1;
	if (rr <= rarrb && rr <= rrr && rr <= rrarb)
		return (0);
	if (rrr <= rarrb && rrr <= rr && rr <= rrarb)
		return (1);
	if (rarrb <= rarrb && rr <= rrr && rr <= rrarb)
		return (2);
	if (rrarb <= rarrb && rr <= rrr && rr <= rarrb)
		return (3);
}

int	how_many_moves(int index_a, int index_b, t_lst *a, t_lst *b)
{
	int	rr;
	int	rarrb;
	int	rrarb;
	int	rrr;

	rrr = 1 + (lstlast(b)->index - index_b);
	if ((lstlast(a)->index - index_a) > (lstlast(b)->index - index_b))
		rrr = 1 + (lstlast(a)->index - index_a);
	rr = index_b;
	if (index_a > index_b)
		rr = index_a;
	rarrb = index_a + (lstlast(b)->index - index_b) + 1;
	rrarb = index_b + (lstlast(a)->index - index_a) + 1;
	if (rr < rarrb && rr < rrr && rr < rrarb)
		return (rr);
	if (rrr < rarrb && rrr < rr && rr < rrarb)
		return (rrr);
	if (rarrb < rarrb && rr < rrr && rr < rrarb)
		return (rarrb);
	if (rrarb < rarrb && rr < rrr && rr < rarrb)
		return (rrarb);
}
t_tab	find_best_nbr(t_lst *a, t_lst *b)
{
	t_tab	info;

	info.calcul = 5000;
	info.val = b->val;
	while (b->next)
	{
		if (how_many_moves(search(a, b->val), b->index, a, b) < info.calcul)
		{
			info.calcul = how_many_moves(search(a, b->val), b->index, a, b);
			info.val = b->val;
			info.ia = search(a, b->val);
			info.ib = b->index;
		}
		b = b->next;
	}
	return (info);
}

void	execute(t_lst **a, t_lst **b, t_tab *info)
{
	t_tab tmpinfo;

	index_init(a);
	if (how_many_part(*a) == 0)
		while ((*a)->next->next->next)
		{
			push_one_in_second(a, b, "pb");
		}
	index_init(b);
	tmpinfo = find_best_nbr(*a, *b);
	printf("%d\n", tmpinfo.ia);
	tmpinfo.mouv = wich_combo_do(tmpinfo.ia, tmpinfo.ib, *a, *b);
	
/* 	if (tmpinfo.mouv == 0)
	 	mouv_if_rr(a, b, tmpinfo);
	if (tmpinfo.mouv == 1)
		mouv_if_rrr(a, b, tmpinfo);
	if (tmpinfo.mouv == 2)
		mouv_if_rarrb(a, b, tmpinfo);
	if (tmpinfo.mouv == 3)
		mouv_if_rrarb(a, b, tmpinfo); */
}
/*
//pantheon des fonctions
int	searchwhile(t_lst *lst_a, t_lst *lst_b)
{
	t_lst *a;
	t_lst *b;
	int i;

	i = 200;
	a = lst_a;
	b = lst_b;
	index_init(&a);
	index_init(&b);
	while (b->next)
	{
		if (search(a, b->val) < i)
		{
			i = search(a, b->val);
		}
		b = b->next;
	}
	return (i);
} */