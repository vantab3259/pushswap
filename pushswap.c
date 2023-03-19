/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:32:49 by mudoh             #+#    #+#             */
/*   Updated: 2023/03/20 00:18:23 by mudoh            ###   ########.fr       */
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
	
	/*swap_a(a);
	print_list(a);
	push_b(&a, &b);
	rotate_a(&a);*/
	reverse_rotate_a(&a);

 	print_list(a); 

	return (0);
}