/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:52:05 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/17 10:39:08 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_c(int c)
{
	return (write(1, &c, 1));
}

int	ft_format_s(char *str)
{
	if (str)
		return (write(1, str, ft_strlen(str)));
	else
		return (write(1, "(null)", 6));
}

int	ft_format_p(void *ptr)
{
	unsigned long long	ptrnbr;
	int					size;

	ptrnbr = (unsigned long long)ptr;
	ft_putstr_fd("0x", 1);
	if (ptr)
	{
		ft_ulltohex(ptrnbr, 'a');
		size = ft_get_size(ptrnbr) + 2;
	}
	else
	{
		write(1, "0", 1);
		size = 3;
	}
	return (size);
}

int	ft_format_d(int arg)
{
	char	*result;
	int		size;

	result = ft_itoa(arg);
	size = ft_strlen(result);
	ft_putstr_fd(result, 1);
	free(result);
	return (size);
}

int	ft_format_i(int arg)
{
	char	*result;
	int		size;

	result = ft_itoa(arg);
	size = ft_strlen(result);
	ft_putstr_fd(result, 1);
	free(result);
	return (size);
}
