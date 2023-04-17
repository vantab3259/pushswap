/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:16:48 by ranki             #+#    #+#             */
/*   Updated: 2022/11/16 07:17:13 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sizestr(char *s)
{
	int		i;
	int		size;
	char	c;

	i = 0;
	size = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			c = s[i];
			write(1, &c, 1);
			size++;
			i++;
		}
	}
	else
	{
		ft_putstr("(null)");
		size += 6;
	}
	return (size);
}
