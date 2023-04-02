/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:32:49 by mudoh             #+#    #+#             */
/*   Updated: 2023/04/02 17:12:03 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
		return (free(info), 1);
	b = NULL;
	while (i < argc)
	{
		pile_addback(&a, lstnew(ft_atoi(argv[i]), info));
		i++;
	}
	execute(&a, &b, info);
	print_list(a);
	print_list(b);
	return (0);
}