/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:02:58 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/27 02:55:12 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_convert(char **str, int **tab_tofill)
{
	int		i;
	char	**tmp;
	int		size;

	i = 0;
	tmp = str;
	size = 0;
	while (tmp[size])
		size++;
	*tab_tofill = malloc(sizeof(int) * size);
	if (!*tab_tofill)
		return (-1);
	while (i < size)
	{
		(*tab_tofill)[i] = ft_atoi(tmp[i]);
		i++;
	}
	return (size);
}

int	*ft_sort(t_stack stacka, t_stack stackb, int tmp, int val)
{
	if (ft_is_sorted(&stacka, stacka.gsize))
		return (0);
	if (stacka.gsize > 250)
		tmp = 13;
	else
		tmp = 6;
	if (stacka.gsize == 3)
		return (ft_sort_tri(&stacka, stacka.gsize));
	else if (stacka.gsize == 5 || stacka.gsize == 4)
		return (ft_sort_low(stacka, stackb, stacka.gsize));
	while (stacka.size > 3)
	{
		val = find_med_value(&stacka, stacka.gsize, 2 * stacka.size / tmp);
		ft_push_half_min(&stacka, &stackb, tmp, val);
		if (tmp > 3)
			tmp--;
	}
	ft_sort_tri(&stacka, stacka.gsize);
	ft_push_all_max(&stacka, &stackb, stacka.gsize);
	return (0);
}

//Value for 500 : 14, Value for 100: 6 
int	*ft_push_swap(char **stack_a)
{
	t_stack	stacka;
	t_stack	stackb;
	int		val;
	int		tmp;

	tmp = 0;
	val = 0;
	stacka.gsize = ft_convert(stack_a, &(stacka.stack));
	stackb.stack = ft_calloc(sizeof(int), stacka.gsize);
	stacka.size = stacka.gsize;
	stackb.size = 0;
	stackb.gsize = stacka.gsize;
	ft_sort(stacka, stackb, tmp, val);
	free(stacka.stack);
	free(stackb.stack);
	return (0);
}

char	**ft_buf_from_arg(int ac, char **av)
{
	char	**buffer;
	int		size;

	buffer = ft_calloc(sizeof(char *), (ac + 1));
	size = 0;
	while (size < ac)
	{	
		buffer[size] = av[size +1];
		size++;
	}
	return (buffer);
}
