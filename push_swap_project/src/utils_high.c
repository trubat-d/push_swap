/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_high.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:45:59 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/26 21:12:56 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_half_min(t_stack *tab1, t_stack *tab2, int n, int midval)
{
	int	i;
	int	val;
	int	size;

	size = tab1->size;
	i = 0;
	val = find_med_value(tab1, tab1->gsize, tab1->size / n);
	while (i < size && tab1->size > 3)
	{
		if (tab1->stack[tab1->gsize - tab1->size] <= midval)
		{
			pb(tab2, tab1, tab1->gsize);
			if (tab2->stack[tab2->gsize - tab2->size] < val)
				rb(tab2, tab2->gsize);
		}
		else
			ra(tab1, tab1->gsize);
		i++;
	}
}

void	ft_push_half(t_stack *tab1, t_stack *tab2, int gsize, int val)
{
	int	startval;

	startval = tab1->size;
	while (tab1->size > startval - val)
	{
		pb(tab2, tab1, gsize);
	}
}

void	ft_rotate_n(t_stack *tab, int gsize, int n, int mode)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (mode == 1)
			rra(tab, gsize);
		else
			ra(tab, gsize);
		i++;
	}
}

void	ft_push_all_max(t_stack *tab1, t_stack *tab2, int gsize)
{
	int	count;

	count = 0;
	while (tab2->size > 0)
	{
		if (tab2->stack[gsize - tab2->size + ft_get_max(tab2, gsize)] \
		> tab1->stack[gsize - tab1->size])
		{
			while (tab2->stack[gsize - tab2->size + ft_get_max(tab2, gsize)] \
			> tab1->stack[gsize - tab1->size])
			{
				ra(tab1, gsize);
				push_next_higher(tab1, tab2, tab1->stack[gsize - 1]);
				count++;
			}
			while (count > 0)
			{
				rra(tab1, gsize);
				count--;
			}
		}
		else
			push_higher(tab1, tab2);
	}
}

void	push_higher(t_stack *stacka, t_stack *stackb)
{
	int	maxpos;
	int	rev;

	rev = 0;
	maxpos = ft_get_max(stackb, stackb->gsize);
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
