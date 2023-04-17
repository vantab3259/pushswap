/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:32:49 by mudoh             #+#    #+#             */
/*   Updated: 2023/04/17 01:23:59 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	execute(t_lst **a, t_lst **b)
{
	int	i;

	if (ft_doublon(*a) == 1)
		return (free_list(a), 1);
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
			algo(a, b);
			i--;
		}
	}
	index_init(a);
	return (0);
}

int	verif(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i++]) < INT_MIN)
			return (1);
	return (0);
}

int	next(char **argv, t_lst **a, t_lst **b)
{
	if (ft_doublon(*a) == 1)
		return (write(2, "Error\n", 6), free_list(a), 0);
	if (a_is_sorted(*a) == 1)
		return (free_list(a), 0);
	if (lstlast(*a)->val != ft_atoi(argv[1]))
		if (execute(a, b) == 1)
			return (write(2, "Error\n", 6), 1);
	make_order(a);
	free_list(a);
	return (0);
}

int	main(int argc, char **argv)
{
	t_lst	*a;
	t_lst	*b;
	t_tab	*info;
	t_lst	*new_elem;
	int		i;

	b = NULL;
	new_elem = NULL;
	info = malloc(sizeof(info));
	if (!info || verif(argc, argv) == 1 || argc < 2)
		return (ft_printf("Errorr\n"), free(info), 1);
	a = lstnew(ft_atoi(argv[1]), info);
	if (!a)
		return (ft_printf("Error\n"), free(info), 1);
	i = 1;
	while (++i < argc)
	{
		new_elem = lstnew(ft_atoi(argv[i]), info);
		if (!new_elem)
			return (ft_printf("Error\n"), free_list(&a), free(info), 1);
		pile_addback(&a, new_elem);
	}
	return (next(argv, &a, &b), free(info), 0);
}
