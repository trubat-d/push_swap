/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:50:09 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/27 02:56:33 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(char **spl)
{
	int	i;

	i = 0;
	while (spl[i])
	{
		free(spl[i]);
		i++;
	}
	free(spl);
}

int	main(int ac, char **av)
{
	char	**buffer;
	int		i;

	i = 0;
	buffer = NULL;
	if (ac == 2)
	{
		buffer = ft_split(av[1], ' ');
		i = 1;
	}
	else if (ac > 2)
	{
		buffer = ft_buf_from_arg(ac, av);
	}
	if (!ft_check_str(buffer, "Error\n"))
		return (0);
	ft_push_swap(buffer);
	if (i == 1)
		free_all(buffer);
	else
		free(buffer);
	return (0);
}
