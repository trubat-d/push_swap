/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:14:55 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/26 21:03:18 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack *tab, int gsize)
{
	int	tmp;
	int	i;

	i = gsize;
	tmp = tab->stack[gsize - 1];
	while (i > 1)
	{
		tab->stack[i - 1] = tab->stack[i - 2];
		i--;
	}
	tab->stack[gsize - tab->size] = tmp;
}

void	rra(t_stack *tab, int gsize)
{
	rev_rotate(tab, gsize);
	ft_printf("rra\n");
}

void	rrb(t_stack *tab, int gsize)
{
	rev_rotate(tab, gsize);
	ft_printf("rrb\n");
}

void	rrr(t_stack *tab, t_stack *tab2, int gsize)
{
	rev_rotate(tab, gsize);
	rev_rotate(tab2, gsize);
	ft_printf("rrr\n");
}
