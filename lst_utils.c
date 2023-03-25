/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:21:20 by mudoh             #+#    #+#             */
/*   Updated: 2023/03/25 19:43:33 by mudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


void	print_list(t_lst *list)
{
	t_lst	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
}

t_lst	*ft_lstnew(int nbr)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (0);
	new->val = nbr;
	new->index = 0;
	new->next = NULL;
	return (new);
}

t_lst	*ft_lst_remove_head(t_lst *premiere_position)
{
	t_lst	*second_position;

	if (premiere_position != NULL)
	{
		second_position = premiere_position->next;
		free(premiere_position);
		return (second_position);
	}
	else
		return (NULL);
}

t_lst	*ft_lst_cut_head_and_save(t_lst	**lst_a)
{
	t_lst	*new;

	new = *lst_a;
	*lst_a = (*lst_a)->next;
	new->next = NULL;
	return(new);
}

t_lst	*ft_lst_cut_end_and_save(t_lst	*lst_a)
{
	t_lst	*new;
	t_lst	*temoin;
	
	new = lst_a;
	while(new->next != NULL)
	{
		temoin = new; 
		new = new->next;
	}
	temoin->next = NULL;
	return(new);
}


t_lst    *pile_last(t_lst *lst)
{
    if (!lst)
        return (0);
    while (lst->next)
        lst = lst->next;
    return (lst);
}


void    pile_addback(t_lst **lst, t_lst *new)
{
    t_lst    *last;

    if (!(*lst))
        *lst = new;
    else
    {
        last = pile_last(*(lst));
        last->next = new;
    }
}

void    pile_addfront(t_lst **lst, t_lst **new)
{
	if (!(lst))
		*lst = *new;
	else
		(*new)->next = *lst;
	*lst = *new;
}

void push_number(t_lst **pile_a, int new_data)
{
    t_lst *new_element = malloc(sizeof(t_lst));
    if (!new_element)
        return ;
    
    new_element->val = new_data;
    new_element->next = NULL;
    
    pile_addback(pile_a, new_element);
}

void	*ft_lstadd_back(t_lst *lst, t_lst *next)
{
	t_lst	*new;
	t_lst	*tmp;

	while (lst->next)
	{
		lst = lst->next;
	}
	lst->next = new;
	new->next = NULL;
	new->prev = lst;
	new->index = lst->index + 1;
}











/* t_lst	*ft_lstadd_back(t_lst *lst, int valeur)
{
	new = malloc(sizeof(t_lst));
	new->val = valeur;
	new->next = NULL;
	if (lst == NULL)
		return (new);
	else
	{
		tmp = lst;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
		return (lst);
	}
} */
