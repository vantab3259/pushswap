/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:32:49 by mudoh             #+#    #+#             */
/*   Updated: 2023/04/12 19:03:03 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_lst *a;
	t_lst *b;
	t_tab *info;
	t_lst *new_elem;
	int i;
	
	b = NULL;
	new_elem = NULL;
	i = 1;
	info = malloc(sizeof(info));
	if (!info)
		return (1);
	while (i < argc)
		if(ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i++]) < INT_MIN)
			return (printf("Error\n"), free(info), 1);
	i = 2;
	a = lstnew(ft_atoi(argv[1]), info);
	if (!a)
    	return (printf("Error\n"), free(info), 1);
	i = 2;
	while (i < argc)
	{
		new_elem = lstnew(ft_atoi(argv[i]), info);
		if (!new_elem)
			return (printf("Error\n"), free_list(&a), free(info), 1);
		pile_addback(&a, new_elem);
		i++;
	}
	if(lstlast(a)->val != ft_atoi(argv[1]))
		if(execute(&a, &b) == 1)
			return(printf("Error\n"), 1);
	make_order(&a);
	free_list(&a);
	free(info);
	return (0);
}
