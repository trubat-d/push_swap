/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mid_val.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:20:16 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/26 22:23:17 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_findh(t_stack *tab, int *med_pos, int *prev_med);
static void	ft_findl(t_stack *tab, int *med_pos, int *prev_med);

int	find_med_value(t_stack *tab, int gsize, int counted)
{
	int	med_pos;
	int	prev_med;
	int	count;

	med_pos = ft_get_min(tab, tab->gsize, 0);
	count = 1;
	while (count < counted)
	{
		ft_findl(tab, &med_pos, &prev_med);
		count++;
		if (count >= counted)
			break ;
		ft_findh(tab, &med_pos, &prev_med);
		count++;
	}
	return (tab->stack[gsize - tab->size + med_pos]);
}

int	ft_findnext(t_stack *tab, int val)
{
	int	i;
	int	pos;
	int	size;

	size = tab->gsize - tab->size;
	pos = 0;
	i = 0;
	while (pos < tab->size)
	{
		if (tab->stack[size + pos] > val)
			break ;
		pos++;
	}
	i = 0;
	while (i < tab->size)
	{
		if (tab->stack[size + i] < tab->stack[size + pos] && \
			tab->stack[size + i] > val)
			pos = i;
		i++;
	}
	return (pos);
}

static void	ft_findl(t_stack *tab, int *med_pos, int *prev_med)
{
	int	i;
	int	state;
	int	num;

	num = tab->gsize - tab->size;
	state = 1;
	i = 0;
	while (i < tab->gsize)
	{
		if (state == 1 && tab->stack[num + *med_pos] \
			< tab->stack[num + i])
		{
			state = 0;
			*prev_med = *med_pos;
			*med_pos = i;
		}
		if (state == 0 && tab->stack[num + *prev_med] \
			< tab->stack[num + i] && \
				tab->stack[num + *med_pos] \
			> tab->stack[num + i])
			*med_pos = i;
		i++;
	}
}

static void	ft_findh(t_stack *tab, int *med_pos, int *prev_med)
{
	int	i;
	int	state;
	int	num;

	num = tab->gsize - tab->size;
	state = 1;
	i = tab->size;
	while (i >= 0)
	{
		if (state == 1 && tab->stack[num + *med_pos] \
			< tab->stack[num + i])
		{
			state = 0;
			*prev_med = *med_pos;
			*med_pos = i;
		}
		if (state == 0 && tab->stack[num + *prev_med] \
			< tab->stack[num + i] && \
				tab->stack[num + *med_pos] \
			> tab->stack[num + i])
			*med_pos = i;
		i--;
	}
}
