/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:03:20 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/26 20:26:54 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlens(char *s)
{
	int	i;

	if (!s)
	{
		return (0);
	}
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int		i;
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	i = 0;
	if ((unsigned char)c == 0)
		return (&ptr[ft_strlens(ptr)]);
	while (ptr[i] != '\0')
	{
		if (ptr[i] == (unsigned char)c)
		{
			return (&ptr[i]);
		}
		i++;
	}
	return (0);
}
