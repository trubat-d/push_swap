/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:13:13 by trubat-d          #+#    #+#             */
/*   Updated: 2022/10/27 01:25:38 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	int	*stack;
	int	size;
	int	gsize;
}			t_stack;

void	swap(t_stack *tab, int gsize);
void	push(t_stack *tab1, t_stack *tab2, int gsize);
void	rotate(t_stack *tab, int gsize);
void	rev_rotate(t_stack *tab, int gsize);
void	rra(t_stack *tab, int gsize);
void	rrb(t_stack *tab, int gsize);
void	ra(t_stack *tab, int gsize);
void	rb(t_stack *tab, int gsize);
void	rrr(t_stack *tab, t_stack *tab2, int gsize);
void	rr(t_stack *tab, t_stack *tab2, int gsize);
void	pa(t_stack *tab, t_stack *tab2, int gsize);
void	pb(t_stack *tab, t_stack *tab2, int gsize);
void	sa(t_stack *tab, int gsize);
void	sb(t_stack *tab, int gsize);
void	ss(t_stack *tab1, t_stack *tab2, int gsize);

int		ft_convert(char **str, int **tab_tofill);
void	ft_print_stack(int *s1, int *s2, int size);
int		ft_is_mid(t_stack *tab, int gsize, int pos);
int		ft_is_highest(t_stack *tab, int gsize, int pos);
int		ft_is_lowest(t_stack *tab, int gsize, int pos);
int		*ft_sort_low(t_stack stacka, t_stack stackb, int gsize);
int		is_stack_sorted(t_stack *tab, int gsize);
int		ft_is_sorted(t_stack *tab, int gsize);
int		ft_get_min(t_stack *tab, int gsize, int pos);
int		*ft_sort_tri(t_stack *tab, int gsize);
int		find_med_value(t_stack *tab, int gsize, int counted);
void	ft_push_half_min(t_stack *tab1, t_stack *tab2, int size, int midval);
void	ft_rotate_n(t_stack *tab, int gsize, int n, int mode);
void	push_lower(t_stack *stacka, t_stack *stackb, int rev);
int		ft_get_max(t_stack *tab, int gsize);
void	push_higher(t_stack *stacka, t_stack *stackb);
void	push_next_higher(t_stack *stacka, t_stack *stackb, int val);
void	ft_push_all_max(t_stack *tab1, t_stack *tab2, int gsize);
void	ft_push_half(t_stack *tab1, t_stack *tab2, int gsize, int val);
int		ft_findnext(t_stack *tab, int val);
int		ft_check_str(char **s, char *error_msg);
int		ft_is_num_str(char *s);
char	**ft_buf_from_arg(int ac, char **av);
long	ft_atoi_check(const char *nptr);

int		*ft_push_swap(char **stack_a);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(const char *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isws(char c);

#endif