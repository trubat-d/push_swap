/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:28:40 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/27 01:00:06 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_in_range(char *s);

static int	ft_not_double(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[j])
		{
			if (i != j && !ft_strncmp(s[i], s[j], ft_strlen(s[i]) + 1))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_check_str(char **s, char *error_msg)
{
	int	i;

	i = 0;
	if (!ft_not_double(s))
	{
		ft_printf("%s", error_msg);
		return (0);
	}
	while (s[i])
	{
		if (!ft_is_num_str(s[i]) || !ft_is_in_range(s[i]))
		{
			ft_printf("%s", error_msg);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_is_num_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] == '-' && ft_strlen(s) >= 2)
		{
			i++;
			continue ;
		}
		if (!ft_isdigit((int)s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_in_range(char *s)
{
	long	num;

	num = ft_atoi_check(s);
	if (num > (long)INT_MAX || num < (long)INT_MIN)
		return (0);
	return (1);
}
