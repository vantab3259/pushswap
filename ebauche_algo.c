/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ebauche_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:19:54 by mudoh             #+#    #+#             */
/*   Updated: 2023/04/11 15:55:38 by mudoh            ###   ########.fr       */
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
	v = is_max(lst);
	while (tmp)
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
	if ((lstlast(a)->index - index_a) > (lstlast(b)->index - index_b))
		rrr = 1 + (lstlast(a)->index - index_a);
	rr = index_b;
	if (index_a > index_b)
		rr = index_a;
	rarrb = index_a + (lstlast(b)->index - index_b) + 1;
	rrarb = index_b + (lstlast(a)->index - index_a) + 1;
	if (rr <= rarrb && rr <= rrr && rr <= rrarb)
		return (0);
	if (rrr <= rarrb && rrr <= rr && rrr <= rrarb)
		return (1);
	if (rarrb <= rrarb && rarrb <= rrr && rarrb <= rr)
		return (2);
	if (rrarb <= rarrb && rrarb <= rrr && rrarb <= rr)
		return (3);
	return (0);
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
	if (rr <= rarrb && rr <= rrr && rr <= rrarb)
		return (rr);
	if (rrr <= rarrb && rrr <= rr && rrr <= rrarb)
		return (rrr);
	if (rarrb <= rr && rarrb <= rrr && rarrb <= rrarb)
		return (rarrb);
	if (rrarb <= rarrb && rrarb <= rrr && rrarb <= rr)
		return (rrarb);
	return (rr);
}

t_tab	find_best_nbr(t_lst *a, t_lst *b)
{
	t_tab	info;

	info.calcul = 5000;
	info.val = b->val;
	while (b)
	{
		// printf("wtf pour le nombre %d je trouve l'index %d\n", b->val, search(a,
		// 		b->val));
		// print_list(a);
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

void	execute_le_retour(t_lst **a, t_lst **b)
{
	t_tab	tmpinfo;

	tmpinfo = find_best_nbr(*a, *b);
	tmpinfo.mouv = wich_combo_do(tmpinfo.ia, tmpinfo.ib, *a, *b);
	// printf("je trouve le combo : %d\n", tmpinfo.mouv);
	if (tmpinfo.mouv == 0)
		mouv_if_rr(a, b, tmpinfo);
	if (tmpinfo.mouv == 1)
		mouv_if_rrr(a, b, tmpinfo);
	if (tmpinfo.mouv == 2)
		mouv_if_rarrb(a, b, tmpinfo);
	if (tmpinfo.mouv == 3)
		mouv_if_rrarb(a, b, tmpinfo);
	index_init(a);
	if (b && (*b))
		index_init(b);
}

int	execute(t_lst **a, t_lst **b)
{
	int	i;

	if (ft_doublon(*a) == 1)
		return (1);
	if ((*a)->next->next)
		while ((*a)->next->next->next)
			push_one_in_second(a, b, "pb\n");
	if ((*a)->next->next && list_is_range(*a) == 0)
		swap(a, "sa\n");
	if (b && (*b))
	{
		index_init(b);
		index_init(a);
		i = lstlast(*b)->index;
		while (i != -1)
		{
			index_init(b);
			index_init(a);
			execute_le_retour(a, b);
			i--;
		}
	}
	index_init(a);
	return (0);
}
