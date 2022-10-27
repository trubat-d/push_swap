/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:04:54 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/17 13:23:19 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arg_count(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!(str[0]))
		return (0);
	while (str[i + 1] != '\0')
	{
		if (str[i] == '%')
		{
			if (ft_strchr("cspdiuxX%", str[i + 1]) != NULL)
			{
				count++;
				if (str[i + 2])
					i++;
			}
		}
		i++;
	}
	return (count);
}

void	ft_type_loader(char *str, int pos, va_list *arg, int *printed)
{
	char	format;
	char	*sub;

	sub = ft_substr(str, pos, 2);
	format = ft_get_format(sub);
	free(sub);
	if (format == 'c')
		*printed += ft_format_c(va_arg(*arg, int));
	else if (format == 's')
		*printed += ft_format_s(va_arg(*arg, char *));
	else if (format == 'p')
		*printed += ft_format_p(va_arg(*arg, void *));
	else if (format == 'u')
		*printed += ft_format_u((unsigned int)va_arg(*arg, unsigned int));
	else if (format == 'x')
		*printed += ft_format_minx(va_arg(*arg, unsigned int));
	else if (format == 'X')
		*printed += ft_format_majx(va_arg(*arg, unsigned int));
	else if (format == 'd')
		*printed += ft_format_d(va_arg(*arg, int));
	else if (format == 'i')
		*printed += ft_format_i(va_arg(*arg, int));
	else if (format == '%')
		*printed += ft_format_percent();
}

int	ft_no_format(const char *str, int *pos, int *printed)
{
	while (((char *)str)[*pos] != '%' && ((char *)str)[*pos] != '\0')
	{
		ft_putchar_fd(((char *)str)[(*pos)++], 1);
		(*printed)++;
	}
	if (((char *)str)[*pos] == '\0')
		return (1);
	return (0);
}

void	ft_init(int *printed, int *size, int *pos, const char *str)
{
	*size = ft_strlen(str);
	*pos = 0;
	*printed = 0;
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		pos;
	int		args_count;
	int		size;
	int		printed;

	ft_init(&printed, &size, &pos, str);
	args_count = ft_arg_count((char *)str);
	va_start(arg, str);
	while (pos != size +1)
	{
		if (ft_no_format(str, &pos, &printed))
			break ;
		if (args_count > 0)
		{
			ft_type_loader(((char *)str), pos, &arg, &printed);
			args_count--;
			pos += 2;
		}
	}
	va_end(arg);
	return (printed);
}
