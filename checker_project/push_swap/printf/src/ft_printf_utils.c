/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:03:06 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/17 10:41:30 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int	ft_get_size(unsigned long long number)
{
	int	i;

	if (number == 0)
		return (1);
	i = 0;
	while (number != 0)
	{
		number /= 16;
		i++;
	}
	return (i);
}

void	ft_ntohex(unsigned int arg, char hexChar)
{
	char	c;

	if (arg < 10)
	{
		c = arg + '0';
		write(1, &c, 1);
	}
	else if (arg >= 10 && arg <= 15)
	{
		c = arg - 10 + hexChar;
		write(1, &c, 1);
	}
	else
	{
		ft_ntohex(arg / 16, hexChar);
		ft_ntohex(arg % 16, hexChar);
	}
}

void	ft_ulltohex(unsigned long long arg, char hexChar)
{
	char	c;

	if (arg < 10)
	{
		c = arg + '0';
		write(1, &c, 1);
	}
	else if (arg >= 10 && arg <= 15)
	{
		c = arg - 10 + hexChar;
		write(1, &c, 1);
	}
	else
	{
		ft_ulltohex(arg / 16, hexChar);
		ft_ulltohex(arg % 16, hexChar);
	}
}

void	ft_putuint_fd(unsigned int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n > 0)
	{
		if (n / 10 != 0)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('0' + n % 10, fd);
	}
}
