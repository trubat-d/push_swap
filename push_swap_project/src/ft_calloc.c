/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:45:45 by theo              #+#    #+#             */
/*   Updated: 2022/10/27 01:01:43 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*res;

	i = 0;
	res = malloc(nmemb * size);
	if (!res)
		return (0);
	while (i < (nmemb * size))
	{
		((unsigned char *)res)[i] = 0;
		i++;
	}
	return (res);
}
