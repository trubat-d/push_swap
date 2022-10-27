/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lowest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:22:09 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/26 21:03:03 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_sort_low(t_stack stacka, t_stack stackb, int gsize)
{
	int	rev;

	rev = 0;
	if (gsize == 5)
		push_lower(&stacka, &stackb, rev);
	rev = 0;
	push_lower(&stacka, &stackb, rev);
	ft_sort_tri(&stacka, gsize);
	if (is_stack_sorted(&stackb, gsize))
		sb(&stackb, gsize);
	pa(&stacka, &stackb, gsize);
	if (gsize == 5)
		pa(&stacka, &stackb, gsize);
	return (stacka.stack);
}

void	push_lower(t_stack *stacka, t_stack *stackb, int rev)
{
	int	maxpos;

	maxpos = ft_get_min(stacka, stacka->gsize, 0);
	if (stacka->gsize - maxpos < maxpos)
	{
		rev = 1;
		maxpos = stacka->size - maxpos;
	}
	while (maxpos-- > 0)
	{
		if (rev == 1)
			rra(stacka, stacka->gsize);
		else
			ra(stacka, stacka->gsize);
	}
	pb(stackb, stacka, stacka->gsize);
}

int	is_stack_sorted(t_stack *tab, int gsize)
{
	int	i;

	i = 0;
	while (i < tab->size - 1)
	{	
		if (tab->stack[gsize - tab->size + i] \
		> tab->stack[gsize - tab->size + i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sorted(t_stack *tab, int gsize)
{
	int	i;

	i = 0;
	while (i < gsize - 1)
	{
		if (tab->stack[tab->gsize - tab->size + i] \
		> tab->stack[tab->gsize - tab->size + i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_get_min(t_stack *tab, int gsize, int pos)
{
	int	i;
	int	maxp;

	maxp = 0;
	i = 0;
	while (i < tab->size - pos)
	{
		if (tab->stack[gsize - tab->size + maxp] \
		> tab->stack[gsize - tab->size + i])
		{
			maxp = i;
		}
		i++;
	}
	return (maxp);
}
