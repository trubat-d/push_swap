/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tri_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:51:35 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/27 03:01:44 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_sort_tri(t_stack *tab, int gsize)
{
	int	ts;

	ts = gsize - tab->size;
	if (ft_is_lowest(tab, gsize, 0) && ft_is_highest(tab, gsize, 1) \
	&& ft_is_mid(tab, gsize, 2))
	{
		sa(tab, gsize);
		ra(tab, gsize);
	}
	if (ft_is_lowest(tab, gsize, 1) && ft_is_highest(tab, gsize, 2) \
	&& ft_is_mid(tab, gsize, 0))
		sa(tab, gsize);
	if (ft_is_lowest(tab, gsize, 2) && ft_is_highest(tab, gsize, 1) \
	&& ft_is_mid(tab, gsize, 0))
		rra(tab, gsize);
	if (ft_is_lowest(tab, gsize, 2) && ft_is_highest(tab, gsize, 0) \
	&& ft_is_mid(tab, gsize, 1))
	{
		sa(tab, gsize);
		rra(tab, gsize);
	}
	if (ft_is_lowest(tab, gsize, 1) && ft_is_highest(tab, gsize, 0) \
	&& ft_is_mid(tab, gsize, 2))
		ra(tab, gsize);
	return (tab->stack);
}

void	push_next_higher(t_stack *stacka, t_stack *stackb, int val)
{
	int	maxpos;
	int	rev;

	rev = 0;
	maxpos = ft_findnext(stackb, val);
	if (stackb->size - maxpos < maxpos)
	{
		rev = 1;
		maxpos = stackb->size - maxpos;
	}
	while (maxpos-- > 0)
	{
		if (rev == 1)
			rrb(stackb, stackb->gsize);
		else
			rb(stackb, stackb->gsize);
	}
	pa(stacka, stackb, stacka->gsize);
}

int	ft_get_max(t_stack *tab, int gsize)
{
	int	i;
	int	maxpos;

	i = 0;
	maxpos = 0;
	while (i < tab->size)
	{
		if (tab->stack[gsize - tab->size + maxpos] \
		< tab->stack[gsize - tab->size + i])
		{
			maxpos = i;
		}
		i++;
	}
	return (maxpos);
}
