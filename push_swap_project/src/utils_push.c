/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:58:11 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/27 01:16:44 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *tab1, t_stack *tab2, int gsize)
{
	if (tab2->size)
	{
		tab1->stack[gsize - tab1->size - 1] = tab2->stack[gsize - tab2->size];
		tab2->stack[gsize - tab2->size] = 0;
		tab1->size++;
		tab2->size--;
	}
}

void	pa(t_stack *tab, t_stack *tab2, int gsize)
{
	push(tab, tab2, gsize);
	ft_printf("pa\n");
}

void	pb(t_stack *tab, t_stack *tab2, int gsize)
{
	push(tab, tab2, gsize);
	ft_printf("pb\n");
}
