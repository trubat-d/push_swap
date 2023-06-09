/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:52:41 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/26 20:26:34 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# define BUFFER_SIZE 4

char	*get_next_line(int fd);
char	*ft_buf_realloc(char *buffer, int mult);
int		ft_buflen(char *buffer, int mode);
int		found_line(char *buffer);
char	*ft_strchr_gnl(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlens(char *s);

#endif