/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:32:49 by mudoh             #+#    #+#             */
/*   Updated: 2023/04/05 19:10:54 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		v(t_lst **a, t_lst **b,t_tab *info, int argc, char **argv)
{
	int	i;

	i = 2;
	
	return(1);
}

int	main(int argc, char **argv)
{
	t_lst *a;
	t_lst *b;
	t_tab *info;
	int i;

	i = 1;
	info = malloc(sizeof(info));
	if (!info)
		return (1);
	while (i < argc)
		if(ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i++]) < INT_MIN)
			return (printf("Error\n"), 1);
	i = 2;
	a = lstnew(ft_atoi(argv[1]), info);
	if (!a)
		return (printf("Error\n"), free(info), 1);
	b = NULL;
	while (i < argc)
		pile_addback(&a, lstnew(ft_atoi(argv[i++]), info));
	if(lstlast(a)->index > 0)
		if(execute(&a, &b, info) == 1)
			return(printf("Error\n"), 1);
	make_order(&a);
	return (0);
}
