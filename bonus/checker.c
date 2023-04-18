/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 23:24:13 by mudoh             #+#    #+#             */
/*   Updated: 2023/04/18 04:18:01 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (((unsigned char *)s1)[i] != '\0' && ((unsigned char *)s2)[i] != '\0')
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

int	getget(t_lst **a, t_lst **b, char *str)
{
	if (!ft_strcmp(str, "pa\n"))
		push_one_in_second(b, a, "");
	else if (!ft_strcmp(str, "pb\n"))
		push_one_in_second(a, b, "");
	else if (!ft_strcmp(str, "ra\n"))
		rotate(a, "");
	else if (!ft_strcmp(str, "rb\n"))
		rotate(b, "");
	else if (!ft_strcmp(str, "rra\n"))
		reverse_rotate(a, "");
	else if (!ft_strcmp(str, "rrb\n"))
		reverse_rotate(b, "");
	else if (!ft_strcmp(str, "sa\n"))
		swap(a, "");
	else if (!ft_strcmp(str, "sb\n"))
		swap(b, "");
	else if (!ft_strcmp(str, "rr\n"))
		rotate_all(a, b, "");
	else if (!ft_strcmp(str, "rrr\n"))
		reverse_rotate_all(a, b, "");
	else
		return (1);
	return (0);
}

int	next(t_lst **a, t_lst **b, t_tab *info)
{
	char	*str;

	(void)info;
	while (1)
	{
		str = get_next_line(0, 0);
		if (!str || !*str)
			break ;
		if (getget(a, b, str))
		{
			get_next_line(1, 1);
			return (free_list(a), free_list(b), free(str), ft_printf("Error\n"));
		}
		free(str);
	}
	get_next_line(1, 1);
	if (a_is_sorted(*a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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

int	main(int argc, char **argv)
{
	t_lst *a;
	t_lst *b;
	t_tab *info;
	int i;

	b = NULL;
	i = 1;
	info = malloc(sizeof(info));
	if (!info || verif(argc, argv) == 1 || argc < 2)
		return (ft_printf("Error\n"), free(info), 1);
	a = lstnew(ft_atoi(argv[1]), info);
	if (!a)
		return (ft_printf("Error\n"), free(info), 1);
	while (++i < argc)
		pile_addback(&a, lstnew(ft_atoi(argv[i]), info));
	if (ft_doublon(a) == 1)
		return (ft_printf("Error\n"), free(info), free_list(&a), 1);
	if (a_is_sorted(a) == 1)
		return (ft_printf("OK\n"), free(info), free_list(&a), 0);
	if (lstlast(a)->val != ft_atoi(argv[1]))
		next(&a, &b, info);
	if (info)
		free(info);
	free_list(& a);
	free_list(& b);
	return (0);
}