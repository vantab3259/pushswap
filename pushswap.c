/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:32:49 by mudoh             #+#    #+#             */
/*   Updated: 2023/04/05 00:15:43 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* int		verif_build(t_lst **a, t_lst **b,t_tab *info, int argc, char **argv)
{
	int	i;

	i = 2;
	
	return(1);
}
 */

int	main(int argc, char **argv)
{
	t_lst *a;
	t_lst *b;
	t_tab *info;
	int i;

	i = 2;
	info = malloc(sizeof(info));
	if (!info)
		return (1);
	a = lstnew(ft_atoi(argv[1]), info);
	if (!a)
		return (printf("Error\n"), free(info), 1);
	b = NULL;
	while (i < argc)
	{
		pile_addback(&a, lstnew(ft_atoi(argv[i]), info));
		i++;
	}
	// index_init(&a);
	// index_init(&b);
	execute(&a, &b, info);
	make_order(&a);
	print_list(a);
	// print_list(b);
	return (0);
}