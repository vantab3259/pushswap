/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:34:07 by mudoh             #+#    #+#             */
/*   Updated: 2023/04/17 00:57:07 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_atoi(char *nptr)
{
	int	i;
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	i = 0;
	if ((nptr[i] >= '0' && nptr[i] <= '9') || nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-' || nptr[i] == '+')
		{
			if (nptr[i] == '-')
				sign *= -1;
			i++;
		}
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			num = (num * 10) + (nptr[i] - '0');
			i++;
		}
		return (num * sign);
	}
	return (1);
}

long	ft_atol(char *nptr)
{
	int		i;
	long	sign;
	long	num;
	int		verif;

	verif = 1;
	sign = 1;
	num = 0;
	i = 0;
	if (!((nptr[i] >= '0' && nptr[i] <= '9') || nptr[i] == '-'
			|| nptr[i] == '+'))
		return (2147483650);
	if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		verif = 0;
		num = (num * 10) + (nptr[i++] - '0');
	}
	if (nptr[i] || verif == 1)
		return (2147483650);
	return (num * sign);
}

int	ft_doublon(t_lst *lst_a)
{
	t_lst	*tmp;
	t_lst	*tmpk;
	int		k;

	tmp = lst_a;
	tmp = tmp->next;
	tmpk = lst_a;
	k = tmpk->val;
	while (tmpk)
	{
		while (tmp)
		{
			if (tmp->val == k && tmp != tmpk)
				return (1);
			tmp = tmp->next;
		}
		tmpk = tmpk->next;
		if (tmpk != NULL)
			k = tmpk->val;
		tmp = lst_a;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

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

void	print_list(t_lst *list)
{
	t_lst	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		ft_printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
