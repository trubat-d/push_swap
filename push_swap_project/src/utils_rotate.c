/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:13:26 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/26 21:13:33 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *tab, int gsize)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = tab->stack[gsize - tab->size];
	while (i < tab->size - 1)
	{
		tab->stack[gsize - tab->size + i] \
		= tab->stack[gsize - tab->size + i + 1];
		i++;
	}
	tab->stack[gsize - (tab->size - i)] = tmp;
}

void	ra(t_stack *tab, int gsize)
{
	rotate(tab, gsize);
	ft_printf("ra\n");
}

void	rb(t_stack *tab, int gsize)
{
	rotate(tab, gsize);
	ft_printf("rb\n");
}

void	rr(t_stack *tab, t_stack *tab2, int gsize)
{
	rotate(tab, gsize);
	rotate(tab2, gsize);
	ft_printf("rr\n");
}
