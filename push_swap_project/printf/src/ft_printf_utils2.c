/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:59:33 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/17 10:12:14 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_get_format(char *str)
{
	if (str[0] && str[1])
		if (str[0] == '%')
			return (str[1]);
	return (0);
}

int	ft_format_u(unsigned int arg)
{
	int				size;
	unsigned int	argcpy;

	argcpy = arg;
	size = 0;
	if (argcpy != 0)
	{
		while (argcpy != 0)
		{
			argcpy /= 10;
			size++;
		}
	}
	else
		size = 1;
	ft_putuint_fd(arg, 1);
	return (size);
}

int	ft_format_minx(unsigned int arg)
{
	int	size;

	ft_ntohex(arg, 'a');
	size = ft_get_size(arg);
	return (size);
}

int	ft_format_majx(unsigned int arg)
{
	int	size;

	ft_ntohex(arg, 'A');
	size = ft_get_size(arg);
	return (size);
}

int	ft_format_percent(void)
{
	char	c;

	c = '%';
	ft_putchar_fd(c, 1);
	return (1);
}
