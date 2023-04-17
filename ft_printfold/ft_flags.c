/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:56:21 by ranki             #+#    #+#             */
/*   Updated: 2022/11/24 13:59:27 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags(va_list lst, char c)
{
	int	size;

	size = 0;
	if (c == 'c')
		size += ft_sizechar(va_arg(lst, int));
	else if (c == 'd' || c == 'i')
		size += ft_sizeint(va_arg(lst, int));
	else if (c == 's')
		size += ft_sizestr(va_arg(lst, char *));
	else if (c == 'u')
		size += ft_size_unsignedint(va_arg(lst, unsigned int));
	else if (c == 'x' || c == 'X')
		size += ft_sizehexa(va_arg(lst, unsigned int), c);
	else if (c == 'p')
		size += ft_sizeptr(va_arg(lst, unsigned long long));
	else
		size += ft_sizep();
	return (size);
}
