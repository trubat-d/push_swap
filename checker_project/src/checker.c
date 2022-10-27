/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:40:18 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/26 23:28:58 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_check_info(char *info, t_stack *stacka, t_stack *stackb)
{
	if (!ft_strncmp(info, "sa\n", 3))
		sa(stacka, stacka->gsize);
	else if (!ft_strncmp(info, "sb\n", 3))
		sb(stackb, stackb->gsize);
	else if (!ft_strncmp(info, "sb\n", 3))
		ss(stackb, stackb, stackb->gsize);
	else if (!ft_strncmp(info, "pa\n", 3))
		pa(stacka, stackb, stacka->gsize);
	else if (!ft_strncmp(info, "pb\n", 3))
		pb(stackb, stacka, stacka->gsize);
	else if (!ft_strncmp(info, "ra\n", 3))
		ra(stacka, stacka->gsize);
	else if (!ft_strncmp(info, "rb\n", 3))
		rb(stackb, stackb->gsize);
	else if (!ft_strncmp(info, "rr\n", 3))
		rr(stacka, stackb, stacka->gsize);
	else if (!ft_strncmp(info, "rra\n", 4))
		rra(stacka, stacka->gsize);
	else if (!ft_strncmp(info, "rrb\n", 4))
		rrb(stackb, stackb->gsize);
	else if (!ft_strncmp(info, "rrr\n", 4))
		rrr(stacka, stackb, stacka->gsize);
}

int	ft_checking_start(char **stack_a)
{
	t_stack	stacka;
	t_stack	stackb;
	char	*info;

	stacka.gsize = ft_convert(stack_a, &(stacka.stack));
	stackb.stack = ft_calloc(sizeof(int), stacka.gsize);
	stacka.size = stacka.gsize;
	stackb.size = 0;
	stackb.gsize = stacka.gsize;
	info = "";
	info = get_next_line(0);
	while (info)
	{
		ft_check_info(info, &stacka, &stackb);
		info = get_next_line(0);
	}
	if (ft_is_sorted(&stacka, stacka.gsize))
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	char	**buffer;
	int		final;

	buffer = NULL;
	if (ac >= 2)
	{
		buffer = ft_buf_from_arg(ac, av);
		final = ft_checking_start(buffer);
	}
	if (!ft_check_str(buffer, "Error\n"))
		return (0);
	else
	{
		if (final)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	return (0);
}
