/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:34:04 by ranki             #+#    #+#             */
/*   Updated: 2022/11/16 07:19:13 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sizeint(int n)
{
	int	size;
	int	n_cpy;

	size = 0;
	n_cpy = n;
	if (n == -2147483648)
	{
		size = 11;
		n_cpy = 0;
	}
	else if (n_cpy < 0)
	{
		n_cpy *= -1;
		size = 1;
	}
	else if (n == 0)
		size = 1;
	while (n_cpy != 0)
	{
		n_cpy /= 10;
		size++;
	}
	ft_putnbr_fd(n, 1);
	return (size);
}
