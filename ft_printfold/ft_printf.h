/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:47:15 by ranki             #+#    #+#             */
/*   Updated: 2022/11/24 20:00:06 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_sizechar(char c);
int		ft_size_unsignedint(unsigned int n);
int		ft_sizestr(char *s);
int		ft_sizep(void);
int		ft_sizeint(int n);
int		ft_sizehexa(unsigned int n, char c);
void	ft_putstr(const char *s);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf(const char *s, ...);
int		ft_flags(va_list lst, char c);
int		ft_sizeptr(unsigned long long n);

#endif
