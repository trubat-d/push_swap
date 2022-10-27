/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_compare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:46:11 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/26 21:13:50 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_mid_cmp(t_stack *tab, int tabsize, int pos);

int	ft_is_lowest(t_stack *tab, int gsize, int pos)
{
	int	size;

	size = gsize - tab->size;
	if (pos == 0)
	{
		if (tab->stack[size + pos] < tab->stack[size + pos + 1] \
		&& tab->stack[size + pos] < tab->stack[size + pos + 2])
			return (1);
	}
	else if (pos == 1)
	{
		if (tab->stack[size + pos] < tab->stack[size + pos - 1] \
		&& tab->stack[size + pos] < tab->stack[size + pos + 1])
			return (1);
	}
	else if (pos == 2)
	{
		if (tab->stack[size + pos] < tab->stack[size + pos - 2] \
		&& tab->stack[size + pos] < tab->stack[size + pos - 1])
			return (1);
	}
	return (0);
}

int	ft_is_highest(t_stack *tab, int gsize, int pos)
{
	int	size;

	size = gsize - tab->size;
	if (pos == 0)
	{
		if (tab->stack[size + pos] > tab->stack[size + pos + 1] \
		&& tab->stack[size + pos] > tab->stack[size + pos + 2])
			return (1);
	}
	else if (pos == 1)
	{
		if (tab->stack[size + pos] > tab->stack[size + pos - 1] \
		&& tab->stack[size + pos] > tab->stack[size + pos + 1])
			return (1);
	}
	else if (pos == 2)
	{
		if (tab->stack[size + pos] > tab->stack[size + pos - 2] \
		&& tab->stack[size + pos] > tab->stack[size + pos - 1])
			return (1);
	}
	return (0);
}

int	ft_is_mid(t_stack *tab, int gsize, int pos)
{
	int	tabsize;

	tabsize = gsize - tab->size + pos;
	return (ft_is_mid_cmp(tab, tabsize, pos));
}

static int	ft_is_mid_cmp(t_stack *tab, int tabsize, int pos)
{
	if (pos == 0)
	{
		if ((tab->stack[tabsize] < tab->stack[tabsize + 1] \
			&& tab->stack[tabsize] > tab->stack[tabsize + 2]) || \
		(tab->stack[tabsize] > tab->stack[tabsize + 1] \
		&& tab->stack[tabsize] < tab->stack[tabsize + 2]))
			return (1);
	}
	else if (pos == 1)
	{
		if ((tab->stack[tabsize] < tab->stack[tabsize - 1] \
		&& tab->stack[tabsize] > tab->stack[tabsize + 1]) || \
		(tab->stack[tabsize] > tab->stack[tabsize - 1] \
		&& tab->stack[tabsize] < tab->stack[tabsize + 1]))
			return (1);
	}
	else if (pos == 2)
	{
		if ((tab->stack[tabsize] < tab->stack[tabsize - 2] \
		&& tab->stack[tabsize] > tab->stack[tabsize - 1]) || \
		(tab->stack[tabsize] > tab->stack[tabsize - 2] \
		&& tab->stack[tabsize] < tab->stack[tabsize - 1]))
			return (1);
	}
	return (0);
}
