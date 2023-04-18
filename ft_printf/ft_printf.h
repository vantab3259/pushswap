/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:41:15 by mudoh             #+#    #+#             */
/*   Updated: 2023/04/18 01:31:26 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printnbr(int nb);
int		ft_printunbr(unsigned int n);
int		ft_sstrlen(const char *str);
int		ft_hexaprint(unsigned int n);
int		ft_hexaprint_m(unsigned int n);
int		ft_ptr(size_t n);

#endif
