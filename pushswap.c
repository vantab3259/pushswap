/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:32:49 by mudoh             #+#    #+#             */
/*   Updated: 2023/03/14 22:07:32 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* t_lsta	take_arg(char **)
{
	t_lsta	lsta;

	lsta
}
t_lsta	rotate(t_lsta *lsta)
{
	t_lsta	*e;

	e = lsta->next;
	lsta->next = e->next;

	e->next = NULL;
	e->prev = NULL;
	e->next = lsta->next->next;
	lsta->prev = ft_lstalast(lsta);
	lsta->next = NULL;
} */

int	main(int argc, char **argv)
{
	t_lst *lsta;
	int i;

	i = 1;
	lsta = ft_lstnew(0);
	if (!lsta)
		return (1);

	while (i < argc)
	{
		ft_lstadd_back(lsta, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (0);
}