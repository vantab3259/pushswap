/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:59:09 by ranki             #+#    #+#             */
/*   Updated: 2022/11/16 07:52:23 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_tailleptr(unsigned long long n)
{
	int	cpt;

	cpt = 0;
	while (n != 0)
	{
		n /= 16;
		cpt++;
	}
	return (cpt);
}

static void	ft_sizehexaptr(unsigned long long n)
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
		ft_sizehexaptr(n / 16);
		if (n % 16 <= 9)
			c = n % 16 + '0';
		else
			c = n % 16 - 10 + 'a';
		write (1, &c, 1);
	}
}

int	ft_sizeptr(unsigned long long n)
{
	int	size;

	if (n == 0)
	{
		ft_putstr("(nil)");
		size = 5;
	}
	else
	{
		size = 2;
		write (1, "0x", 2);
		ft_sizehexaptr(n);
		size += ft_tailleptr(n);
	}
	return (size);
}
