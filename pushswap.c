/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:32:49 by mudoh             #+#    #+#             */
/*   Updated: 2023/03/21 05:57:52 by mudoh            ###   ########.fr       */
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
	

	print_list(a);
	print_list(b);
	push_a(&a, &b);
	print_list(a);
	print_list(b);
	reverse_rotate_all(&a, &b);
	print_list(b);
 	print_list(a);
	/* swap_all(a, b);
	print_list(b);
 	print_list(a); */
	/* rotate_all(&a, &b);
	print_list(b);
 	print_list(a); */

	return (0);
}