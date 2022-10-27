/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:00:39 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/27 01:16:06 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_format_c(int c);
int		ft_format_s(char *str);
int		ft_format_p(void *ptr);
int		ft_format_d(int arg);
int		ft_format_i(int arg);
int		ft_format_u(unsigned int arg);
int		ft_format_minx(unsigned int arg);
int		ft_format_majx(unsigned int arg);
int		ft_format_percent(void);
void	ft_ntohex(unsigned int arg, char hexChar);
void	ft_ulltohex(unsigned long long arg, char hexChar);
void	ft_putuint_fd(unsigned int n, int fd);
int		ft_get_size(unsigned long long number);
char	ft_get_format(char *str);

int		ft_atoi(const char *nptr);
void	ft_putchar_fd(char c, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int st, size_t len);
int		ft_strlen(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int c);
int		ft_isdigit(int c);
int		ft_isws(char c);

#endif
