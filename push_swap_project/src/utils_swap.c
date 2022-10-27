/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:55:25 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/27 01:14:54 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *tab, int gsize)
{
	int	tmp;

	if (tab->size >= 2)
	{	
		tmp = tab->stack[gsize - tab->size];
		tab->stack[gsize - tab->size] = tab->stack[gsize - tab->size + 1];
		tab->stack[gsize - tab->size + 1] = tmp;
	}
}

void	sa(t_stack *tab, int gsize)
{
	swap(tab, gsize);
	ft_printf("sa\n");
}

void	sb(t_stack *tab, int gsize)
{
	swap(tab, gsize);
	ft_printf("sb\n");
}

void	ss(t_stack *tab1, t_stack *tab2, int gsize)
{
	swap(tab1, gsize);
	swap(tab2, gsize);
	ft_printf("ss\n");
}

long	ft_atoi_check(const char *nptr)
{
	long	i;
	long	is_neg;
	long	total;

	i = 0;
	while (ft_isws(nptr[i]))
		i++;
	is_neg = 0;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		is_neg = (nptr[i] == '-');
		i += 1;
	}
	total = 0;
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			return (total);
		if (is_neg)
			total = total * 10 - (nptr[i] - '0');
		else
			total = total * 10 + (nptr[i] - '0');
		i++;
	}
	return (total);
}
