/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:32:49 by mudoh             #+#    #+#             */
/*   Updated: 2023/03/28 00:09:00 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_lst *a;
	t_lst *b;
	t_tab *tab;
	int i;

	i = 2;
	tab = malloc(sizeof(tab));
	if (!tab)
		return (1);
	a = lstnew(ft_atoi(argv[1]), tab);
	if (!a)
		return (free(tab), 1);
	b = NULL;
	while (i < argc)
	{
		pile_addback(&a, lstnew(ft_atoi(argv[i]), tab));
		i++;
	}
	printf("%d\n", search(a, 5));
	print_list(a);
	return (0);
}