/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_unsignedint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:27:37 by ranki             #+#    #+#             */
/*   Updated: 2022/11/24 20:17:44 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_size_unsignedint_pos(unsigned int n)
{
	char	c;

	if (n <= 9)
	{
		c = n + '0';
		write (1, &c, 1);
	}
	else
	{
		c = n % 10 + '0';
		n = n / 10;
		ft_size_unsignedint_pos(n);
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
		n /= 10;
		cpt++;
	}
	return (cpt);
}

int	ft_size_unsignedint(unsigned int n)
{
	ft_size_unsignedint_pos(n);
	return (ft_taille(n));
}
