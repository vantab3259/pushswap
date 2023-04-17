/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:19:41 by ranki             #+#    #+#             */
/*   Updated: 2022/12/17 07:14:07 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	int		size;
	va_list	lst;

	va_start(lst, s);
	i = -1;
	size = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == '%')
			size += ft_flags(lst, s[++i]);
		else
			size += ft_sizechar(s[i]);
	}
	va_end(lst);
	return (size);
}
