/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:32:49 by mudoh             #+#    #+#             */
/*   Updated: 2023/03/25 23:57:40 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_lst *a;
	t_lst *b;
	int i;

	i = 2;
	a = ft_lstnew(ft_atoi(argv[1]));
	b = NULL;
	while (i < argc)
	{
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	push_b(&a, &b);
	push_b(&a, &b);
	push_b(&a, &b);
	printf("pile a: ");
	print_list(a);
	printf("pile b: ");
	print_list(b);
	printf("nombre d'element dans ma pile b: %d\n", how_many_element(b));

	return (0);
}