/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizehexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:50:37 by ranki             #+#    #+#             */
/*   Updated: 2022/11/24 20:02:17 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_sizehexa_m(unsigned int n)
{
	char	c;

	if (n <= 9)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else if (n < 16)
	{
		c = n - 10 + 'a';
		write (1, &c, 1);
	}
	else
	{
		ft_sizehexa_m(n / 16);
		if (n % 16 <= 9)
			c = n % 16 + '0';
		else
			c = n % 16 - 10 + 'a';
		write (1, &c, 1);
	}
}

static void	ft_sizehexa_maj(unsigned int n)
{
	char	c;

	if (n <= 9)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else if (n < 16)
	{
		c = n - 10 + 'A';
		write (1, &c, 1);
	}
	else
	{
		ft_sizehexa_maj(n / 16);
		if (n % 16 <= 9)
			c = n % 16 + '0';
		else
			c = n % 16 - 10 + 'A';
		write (1, &c, 1);
	}
}

static int	ft_taille(unsigned int n)
{
	int	cpt;

	cpt = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		cpt++;
	}
	return (cpt);
}

int	ft_sizehexa(unsigned int n, char c)
{
	if (c == 'x')
	{
		ft_sizehexa_m(n);
		return (ft_taille(n));
	}
	if (c == 'X')
	{
		ft_sizehexa_maj(n);
		return (ft_taille(n));
	}
	return (0);
}
