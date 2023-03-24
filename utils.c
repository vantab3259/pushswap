/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:34:07 by mudoh             #+#    #+#             */
/*   Updated: 2023/03/24 22:04:35 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_atoi(char *n)
{
	int	number;
	int	i;

	i = 0;
	number = 0;
	if (n[i] >= '0' && n[i] <= '9')
	{
		while (n[i])
		{
			number = (n[i] - '0') + (number * 10);
			i++;
		}
		return (number);
	}
	else
		exit(1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		if (((unsigned char *)s1)[i] == '\0')
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
		n--;
	}
	return (0);
}

int		how_many_element(t_lst *lst)
{
	t_lst *tmp;
	tmp = lst;
	int i;
	i = 1;
	while(lst->next)
	{
		lst = lst->next;
		i++;
	}
	return i;
}

int		how_many_part(t_lst *lst_a)
{
	t_lst *tmp;
	int i;
	
	tmp = lst_a;
	
	if(how_many_element(tmp) > 100)
		i = 1;
	else
		i = 0;
	
	return(i);
}

