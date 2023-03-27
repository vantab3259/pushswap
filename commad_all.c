/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commad_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:46:16 by mudoh             #+#    #+#             */
/*   Updated: 2023/03/27 18:53:32 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_all(t_lst *lsta, t_lst *lstb, char *ss)
{
	swap(lstb, "");
	swap(lsta, "");
	ft_printf("%s\n", ss);
}

void	rotate_all(t_lst **lsta, t_lst **lstb, char *rr)
{
	rotate(lstb, "");
	rotate(lsta, "");
	ft_printf("%s\n", rr);
}

void	reverse_rotate_all(t_lst **lsta, t_lst **lstb, char *rra)
{
	reverse_rotate(lstb, "");
	reverse_rotate(lsta, "");
	ft_printf("%s\n", rra);
}
